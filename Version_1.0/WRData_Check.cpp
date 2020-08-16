//---------------------------------------------------------------------------

#pragma hdrstop

#include "WRData_Check.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
// Функции чтения-записи в БД расчетной модели
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int Lenght_Catalog=LENGHT_CATALOG;
CONT_BD Cont_BD;
CATALOG_BD Catalog_BD[LENGHT_CATALOG];
int NData=NDATA;         // Число одновременно открытых виртуальных файлов
FData fdata[NDATA];
static int GOffset;      // Последний offset в BD
static FILE *FileData=NULL;
void BD_CloseData(FData * Pfdata);
static bool flag_permit_inside = true;  // разрешение на работу программам ввода-вывода

//---------------------------------------------
//---------------------------------------------
// Создание BD расчетной модели
// функция создает бинарный файл, открывая его на запись
FILE * BD_New(char *NameBD) {
  int i;
  int rc;
  // Создается оглавление файла - первая запись
  // Каталог данных - вторая запись
  FileData = fopen(NameBD, "w+b");
  if (FileData==NULL)
	 return NULL;
  Cont_BD.version=1;
  strcpy(Cont_BD.title,"*");
  Cont_BD.NData=0;
  Cont_BD.NNode = Cont_BD.NElem = Cont_BD.NDOF = Cont_BD.WFront = 0;
  Cont_BD.Cur_offset=sizeof(CONT_BD) + Lenght_Catalog*sizeof(CATALOG_BD);
  for (i=0; i<Lenght_Catalog; i++)
	 strcpy(Catalog_BD[i].title,"*");
  // запись оглавления
  rc=fwrite((char*)&Cont_BD, sizeof(CONT_BD), 1, FileData);
  i=ftell(FileData);
  if (rc<1) {
    fclose(FileData);
    return NULL;
  }
  // запись каталога
  rc=fwrite((char*)&Catalog_BD, sizeof(CATALOG_BD)*Lenght_Catalog, 1, FileData);
  i=ftell(FileData);
  if (rc<1) {
    fclose(FileData);
    return NULL;
  }

  for (i=0; i<NData; i++)
     fdata[i].flag_free=true;
  GOffset = Cont_BD.Cur_offset;

  return FileData;
}
//---------------------------------------------
// Открытие BD расчетной модели
FILE * BD_Open(char *NameBD, char *index) {
  int i;
  int rc;


  if (index[0]=='r') {
    FileData = fopen(NameBD, "r+b");
    if (FileData==NULL) {
      FileData = BD_New(NameBD);
      return FileData;
    }
    // чтение оглавления
    rc=fread((char*)&Cont_BD, sizeof(CONT_BD), 1, FileData);
    if (rc<1) {
      fclose(FileData);
      return NULL;
    }
    // чтение каталога
    rc=fread((char*)&Catalog_BD, sizeof(CATALOG_BD)*Lenght_Catalog, 1, FileData);
    if (rc<1) {
      fclose(FileData);
      return NULL;
    }
    for (i=0; i<NData; i++)
      fdata[i].flag_free=true;
    GOffset = sizeof(CONT_BD) + sizeof(CATALOG_BD)*Lenght_Catalog;
    return FileData;
  }
  else {
    FileData = BD_New(NameBD);
    return FileData;
  }
}
//---------------------------------------------
// Закрытие BD расчетной модели
int BD_Close(FILE * BD_file) {

  int i, rc;
  // Закрыть не закрытые данные
  if (BD_file!=FileData) return 99;
  if (BD_file==NULL) return 0;
  for (i=0; i<NData; i++) {
       BD_CloseData(fdata+i);
  }
  rc = fseek (FileData, 0, SEEK_SET);
  rc=fwrite((char*)&Cont_BD, sizeof(CONT_BD), 1, FileData);
  if (rc<1) {
    fclose(FileData);
    return ERROR_WRITING;
  }
  // запись каталога
  rc=fwrite((char*)&Catalog_BD, sizeof(CATALOG_BD)*Lenght_Catalog, 1, FileData);
  fclose(FileData);
  BD_file=FileData=NULL;
  if (rc<1) {
    fclose(FileData);
    return ERROR_WRITING;
  }
  return (fclose(FileData));
}
//---------------------------------------------
// функция открытия на запись данных в БД.
FData * BD_WOpenData(FILE *BD_file, char *NameData,
                 int type, int * param, int *rc) {
     int i, j;
	 if (BD_file!=FileData || BD_file==NULL ) {
       *rc=99;
       return NULL;
     }
     for (i=0; i<NData; i++) {
        if (fdata[i].mode=='w' && !fdata[i].flag_free) {
           *rc=ALREADY_WRITE;   // уже есть файл, открытый на запись
           return NULL;
        }
     }
     // 1 вариант
     for (i=0; i<Cont_BD.NData; i++)
        if (strcmp(Catalog_BD[i].title, NameData)==0)
            break;  // данные переписываются на новое место, но в оглавлении остаются на старом
     // 2 вариант
     if (i==Cont_BD.NData) {
        for (i=0; i<Cont_BD.NData; i++)
           if (strcmp(Catalog_BD[i].title, "*")==0)
              break;  // данные занимают первое свободное место
        if (i==Cont_BD.NData) {
          if (Cont_BD.NData == Lenght_Catalog) {
            *rc = FULL_CATALOG;
            return NULL;
          }
     // 3 вариант
           Cont_BD.NData++;  // количество данных увеличивается на единицу
        }
        strcpy(Catalog_BD[i].title,NameData);
     }
     Catalog_BD[i].type=type;
     for (j=0; j<16; j++) {
       Catalog_BD[i].param[j] = param[j];
     }
     Catalog_BD[i].offset = Cont_BD.Cur_offset;
     Catalog_BD[i].offset_max = 0;
     for (j=0; j<NData; j++) {
        if (fdata[j].flag_free) {
           fdata[j].pos_catalog=i;
           fdata[j].mode='w';
           fdata[j].flag_free=false;
           fdata[j].offset=Cont_BD.Cur_offset;
           break;
        }
     }
     if (j==NData) {
           *rc=ALREADY_NDATA;   // уже открыто NDATA файлов
           return NULL;
        }
     *rc=0;
     return(fdata + j);
}
//---------------------------------------------------
// функция открытия на чтение данных из БД.
FData * BD_ROpenData(FILE *BD_file, char *NameData,
                 int type, int * param, int *rc) {
     int i,j;
     if (BD_file!=FileData || BD_file==NULL ) {
       *rc=99;
       return NULL;
     }
     for (i=0; i<Cont_BD.NData; i++)
        if (strcmp(Catalog_BD[i].title, NameData)==0)
            break;
     if (i==Cont_BD.NData) {
        *rc=NO_DATAS;   // нет таких данных
        return NULL;
     }
     if (Catalog_BD[i].offset_max == 0) {
        *rc=DATA_WRITING;   // нет таких данных
        return NULL;
     }
     for (j=0; j<16; j++)
       param[j]=Catalog_BD[i].param[j];
     for (j=0; j<NData; j++) {
        if (fdata[j].flag_free) {
           fdata[j].pos_catalog=i;
           fdata[j].mode='r';
           fdata[j].flag_free=false;
           fdata[j].offset=Catalog_BD[i].offset;
           fdata[j].offset_max=Catalog_BD[i].offset_max;
           break;
        }
     }
     if (j==NData) {
           *rc=ALREADY_NDATA;   // уже открыто NDATA файлов
           return NULL;
     }
     *rc=0;
     return(fdata + j);
}
//---------------------------------------------
// функция закрытия данных из БД.
void BD_CloseData(FData * Pfdata) {
    if (Pfdata==NULL)
      return;
    if (!Pfdata->flag_free) {  // закрывается только открытый файл
      if (Pfdata->mode=='w') {
           Catalog_BD[Pfdata->pos_catalog].offset_max=Pfdata->offset;
           Cont_BD.Cur_offset=Pfdata->offset;
      }
      Pfdata->flag_free=true;
    }
}
//---------------------------------------------
// функция записи данных в БД.
int BD_WriteData(char * ptr, int size, int n, FData * Pfdata) {
     int rc;
     if (Pfdata==NULL)
        return -1;
     if (Pfdata->flag_free)
        return -1;
     if (Pfdata->mode !='w')
        return -1;

     if (Pfdata->offset != GOffset) {
         rc = fseek (FileData, Pfdata->offset, SEEK_SET);
     }
     if (size>0)
         rc = fwrite(ptr, size, n, FileData);
     Pfdata->offset += size*n;
     GOffset = Pfdata->offset;
     return rc;
}
//---------------------------------------------
// функция чтения данных из БД.
int BD_ReadData(char * ptr, int size, int n, FData * Pfdata) {
     int rc;
     if (Pfdata==NULL)
        return -1;
     if (Pfdata->flag_free)
        return -1;
     if (Pfdata->mode !='r')
        return -1;

     if (Pfdata->offset + size*n > Pfdata->offset_max)
        return EOF;
     //if (Pfdata->offset != GOffset) {
         rc = fseek (FileData, Pfdata->offset, SEEK_SET);
     //}
     if (size>0)
        rc = fread(ptr, size, n, FileData);
     Pfdata->offset += size*n;
     GOffset = Pfdata->offset;
     return rc;
}
