//---------------------------------------------------------------------------
#pragma hdrstop
#include <math.h>


#include "StandartProfil.h"
#include "ListConst.h"
#include "ProcExt.h"
#include "Get_param_sect_func.h"


//--------------------------------------------------
// Установить тип профиля
TStandartProfil::TStandartProfil(void)
{
   Index = -1;
}
//--------------------------------------------------
// Установить тип профиля
void  TStandartProfil::SetProfil(int index) //
{
   int i, j, rc;

   double Gost_0[17][14] = GOST_0;
   AnsiString Name_Gost_0[17] = NAME_GOST_0; //зачем нужно инициализировать массивы данными def и затем присваивать их в switch???

   double Gost_B[37][14] = GOST_B; //заполение двумерного массива геометрическими характеристиками профилей
   AnsiString Name_Gost_B[37] = NAME_GOST_B; //заполнение одновмерного массива именами профилей
											 //видимо создание двух массивов обосновано разным типом данных
   double Gost_DB[10][14] = GOST_DB;         //doublе для геометрических характеристик и AnsiString для имён
   AnsiString Name_Gost_DB[10] = NAME_GOST_DB;

   double Gost_Width[26][14] = GOST_Width;
   AnsiString Name_Gost_Width[26] = NAME_GOST_Width;

   double Gost_K[18][14] = GOST_K;
   AnsiString Name_Gost_K[18] = NAME_GOST_K;

   double Sto_B[30][14] = STO_B;
   AnsiString Name_Sto_B[30] = NAME_STO_B;

   double Sto_Width[30][14] = STO_Width;
   AnsiString Name_Sto_Width[30] = NAME_STO_Width;

   double Sto_K[16][14] = STO_K;
   AnsiString Name_Sto_K[16] = NAME_STO_K;

   double Channel[18][16] = CHANNEL;
   double Channel_Sector[18][8] = CHANNEL_SECTOR;
   AnsiString Name_Channel[18] = NAME_CHANNEL;

   double Gost_G57837DB[55][14] = GOST_G57837DB;
   AnsiString Name_Gost_G57837DB[55] = NAME_GOST_G57837DB;

   double Gost_G57837_K[89][14] = GOST_G57837_K;
   AnsiString Name_Gost_G57837_K[89] = NAME_GOST_G57837_K;

   double Gost_G57837_B[50][14] = GOST_G57837_B;
   AnsiString Name_Gost_G57837_B[50] = NAME_GOST_G57837_B;

   double Gost_G57837Sh[66][14] = GOST_G57837Sh;
   AnsiString Name_Gost_G57837Sh[66] = NAME_GOST_G57837Sh;

   double Gost_G57837_S[14][14] = GOST_G57837_S;
   AnsiString Name_Gost_G57837_S[14] = NAME_GOST_G57837_S;

   double Gost_G57837DK[28][14] = GOST_G57837DK;
   AnsiString Name_Gost_G57837DK[28] = NAME_GOST_G57837DK;

   n_Profil = 0;

   Index = index; //Полю класса присваивается входной параметр функции

   for (i=0; i<100; i++) {  //Инициализация двумерных массивов 100x16 и 100x8 нулями
     for (j=0; j<16; j++) {
        Gost_Profil[i][j] = 0;
     }
     for (j=0; j<8; j++) {
           Gost_SectorProfil[i][j] = 0;
     }
   }
   switch (index) {  //запись в массивы инициализированные ранее профилями по индексу
   case typeGOST_0:   // С уклоном полок

     n_Profil = N_GOST_0;
     for (i=0; i<n_Profil; i++) {
       Name_Profil[i] = Name_Gost_0[i];
       for (j=0; j<14; j++) {
           Gost_Profil[i][j] = Gost_0[i][j];
       }
     }
   break;
   case typeGOST_B:

     n_Profil = N_GOST_B;
     for (i=0; i<n_Profil; i++) {
       Name_Profil[i] = Name_Gost_B[i];
       for (j=0; j<14; j++) {
           Gost_Profil[i][j] = Gost_B[i][j];
       }
     }
   break;
   case typeGOST_DB:

     n_Profil = N_GOST_DB;
     for (i=0; i<n_Profil; i++) {
       Name_Profil[i] = Name_Gost_DB[i];
       for (j=0; j<14; j++) {
		   Gost_Profil[i][j] = Gost_DB[i][j];
       }
     }
   break;
   case typeGOST_Width:

     n_Profil = N_GOST_Width;
     for (i=0; i<n_Profil; i++) {
       Name_Profil[i] = Name_Gost_Width[i];
       for (j=0; j<14; j++) {
           Gost_Profil[i][j] = Gost_Width[i][j];
       }
     }
   break;
   case typeGOST_K:

     n_Profil = N_GOST_K;
     for (i=0; i<n_Profil; i++) {
       Name_Profil[i] = Name_Gost_K[i];
       for (j=0; j<14; j++) {
           Gost_Profil[i][j] = Gost_K[i][j];
       }
     }
   break;
   case typeSTO_B:

     n_Profil = N_STO_B;
     for (i=0; i<n_Profil; i++) {
	   Name_Profil[i] = Name_Sto_B[i];
       for (j=0; j<14; j++) {
           Gost_Profil[i][j] = Sto_B[i][j];
       }
     }
   break;
   case typeSTO_Width:

     n_Profil = N_STO_Width;
     for (i=0; i<n_Profil; i++) {
       Name_Profil[i] = Name_Sto_Width[i];
       for (j=0; j<14; j++) {
           Gost_Profil[i][j] = Sto_Width[i][j];
       }
     }
   break;
   case typeSTO_K:

     n_Profil = N_STO_K;
     for (i=0; i<n_Profil; i++) {
       Name_Profil[i] = Name_Sto_K[i];
       for (j=0; j<14; j++) {
           Gost_Profil[i][j] = Sto_K[i][j];
       }
     }
   break;
   case typeCHANNEL:
      n_Profil = N_CHANNEL;
	 for (i=0; i<n_Profil; i++) {
       Name_Profil[i] = Name_Channel[i];
       for (j=0; j<16; j++) {
           Gost_Profil[i][j] = Channel[i][j];
       }
       for (j=0; j<8; j++) {
           Gost_SectorProfil[i][j] = Channel_Sector[i][j];
       }
     }
   break;
   case typeGOST_G57837_B:
      n_Profil = N_GOST_G57837_B;
     for (i=0; i<n_Profil; i++) {
       Name_Profil[i] = Name_Gost_G57837_B[i];
       for (j=0; j<14; j++) {
           Gost_Profil[i][j] = Gost_G57837_B[i][j];
       }
     }
   break;
   case typeGOST_G57837Sh:
      n_Profil = N_GOST_G57837Sh;
     for (i=0; i<n_Profil; i++) {
       Name_Profil[i] = Name_Gost_G57837Sh[i];
       for (j=0; j<14; j++) {
           Gost_Profil[i][j] = Gost_G57837Sh[i][j];
       }
     }
   break;
   case typeGOST_G57837_K:
      n_Profil = N_GOST_G57837_K;
     for (i=0; i<n_Profil; i++) {
       Name_Profil[i] = Name_Gost_G57837_K[i];
       for (j=0; j<14; j++) {
           Gost_Profil[i][j] = Gost_G57837_K[i][j];
       }
     }
   break;
   case typeGOST_G57837DB:   // Дополнительные балочные
      n_Profil = N_GOST_G57837DB;
     for (i=0; i<n_Profil; i++) {
       Name_Profil[i] = Name_Gost_G57837DB[i];
       for (j=0; j<14; j++) {
           Gost_Profil[i][j] = Gost_G57837DB[i][j];
       }
     }
   break;
   case typeGOST_G57837_S:
     n_Profil = N_GOST_G57837_S;
     for (i=0; i<n_Profil; i++) {
       Name_Profil[i] = Name_Gost_G57837_S[i];
       for (j=0; j<14; j++) {
           Gost_Profil[i][j] = Gost_G57837_S[i][j];
       }
     }
   break;
   case typeGOST_G57837DK:
	 n_Profil = N_GOST_G57837DK;
     for (i=0; i<n_Profil; i++) {
       Name_Profil[i] = Name_Gost_G57837DK[i];
       for (j=0; j<14; j++) {
           Gost_Profil[i][j] = Gost_G57837DK[i][j];
       }
     }
   break;
   default:  //Если параметру index не соответствет не одного case, то выводится ошибка
	 #ifdef EMBRAC
	 i = Application->MessageBox((L"Ошибочный тип профиля двутавра "+IntToStr(index)).c_str(), L"SetProfil", MB_OK | MB_ICONERROR);
	 #else
	 i = Application->MessageBox(("Ошибочный тип профиля двутавра "+IntToStr(index)).c_str(), "SetProfil", MB_OK | MB_ICONERROR);
	 #endif
	 n_Profil = 0;
     return;
   }
   // Проверка единиц измерения радиусов инерции
   double i_mult;
   double i_test = sqrt(Gost_Profil[0][6]/Gost_Profil[0][4]);
   if (i_test/Gost_Profil[0][9] > 9.0)
     i_mult = 10.0;
   else
     i_mult = 1.0;
   // Преобразование см в мм
   for (i=0; i<n_Profil; i++) {
	   Gost_Profil[i][4] *= 100;
	   Gost_Profil[i][6] *= 10000;
	   Gost_Profil[i][7] *= 1000;
       Gost_Profil[i][8] *= 1000;
       Gost_Profil[i][9] *= i_mult;
       Gost_Profil[i][10] *= 10000;
	   Gost_Profil[i][11] *= 1000;
       Gost_Profil[i][12] *= i_mult;
   }
   for (i=0; i<n_Profil; i++) {
	   Gost_SectorProfil[i][0] *= 10;
	   Gost_SectorProfil[i][1] *= 1e6;
       Gost_SectorProfil[i][2] *= 100;
       Gost_SectorProfil[i][3] *= 100;
	   Gost_SectorProfil[i][4] *= 1000;
       Gost_SectorProfil[i][5] *= 1000;
       Gost_SectorProfil[i][6] *= 10000;
       Gost_SectorProfil[i][7] *= 10;
   }

}
//----------------------------------------------------------------------
// Получить вектор имен профилей и длину вектора
AnsiString* TStandartProfil::GetVectorNameProfil(int *n_profil) {
   *n_profil = n_Profil;
   return Name_Profil;
}
//----------------------------------------------------------------------
// Получить вектор параметров профиля двутавра или швеллера по его номеру
double* TStandartProfil::GetVectorParamProfil(int n_profil) {
   return Gost_Profil[n_profil];
}


//----------------------------------------------------------------------
// Заполнить структуру параметров сечения двутавра по его номеру
int TStandartProfil::SetParamProfil(SECT_DVUTAVR* sect, int n_profil) {
   if (n_profil >= n_Profil || n_profil <0)
	  return 1;
   sect->n_group = Index;
   sect->n_profil = n_profil;
   sect->h = Gost_Profil[n_profil][0] - 2*Gost_Profil[n_profil][3];
   sect->b = Gost_Profil[n_profil][2];
   sect->b1 = Gost_Profil[n_profil][1];
   sect->b2 = Gost_Profil[n_profil][1];
   sect->h1 = Gost_Profil[n_profil][3];
   sect->h2 = Gost_Profil[n_profil][3];
   sect->flag_concl = true;
   return 0;
}


//------------------------------------------------------------------------
// Получить номер профиля, ближайший по параметру 0-по высоте, 4-по площади, 6-по моменту инерции
int TStandartProfil::Get_NumberProfil(SECT_DVUTAVR* section, int index) {
	   int i;
	   double Wz, param, delta;
	   int iS;
	   GEOM_PARAM_SECT param_sect;

	   if (!section->flag_concl)
		 return 0;

	   Get_param_sect(section, &param_sect);
       if (param_sect.Hsect == 0 || param_sect.Ar==0)
         return 0;
       delta = 1e12;
       iS = 0;
       for (i=0; i<n_Profil; i++) {
         param = Gost_Profil[i][index];
         switch(index) {
         case 0:
          if (delta > (ABS(param_sect.Hsect - param))) {
            delta = ABS(param_sect.Hsect - param);
            iS = i;
          }
         break;
         case 1:
          if (delta > (ABS(section->b1 - param))) {
            delta = ABS(section->b1 - param);
            iS = i;
          }
         break;
         case 2:
          if (delta > (ABS(section->b - param))) {
            delta = ABS(section->b - param);
            iS = i;
          }
         break;
         case 3:
          if (delta > (ABS(section->h1 - param))) {
            delta = ABS(section->h1 - param);
            iS = i;
          }
         break;
         case 4:
          if (param - param_sect.Ar >0 && delta > param - param_sect.Ar) {
            delta = param - param_sect.Ar;
            iS = i;
          }
         break;
         case 6:
          if (param - param_sect.Izz >0 && delta > param - param_sect.Izz) {
            delta = param - param_sect.Izz;
            iS = i;
          }
         break;
         case 7:
          Wz = param_sect.Izz/param_sect.Zct;
          if (param - Wz >0 && delta > param - Wz) {
            delta = param - Wz;
            iS = i;
          }
         break;
         default:
           iS = 0;
         }
       }
       return iS;
}

#pragma package(smart_init)
