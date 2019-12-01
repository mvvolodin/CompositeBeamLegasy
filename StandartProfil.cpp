//---------------------------------------------------------------------------
#pragma hdrstop
#include <math.h>


#include "StandartProfil.h"
#include "ListConst.h"
#include "ProcExt.h"
#include "Get_param_sect_func.h"


bool Compare_group(int n_group, int type_profil);


//--------------------------------------------------
// Установить тип профиля
TStandartProfil::TStandartProfil(void)
{
   Index = -1;
}
//--------------------------------------------------
// Установить тип профиля
void  TStandartProfil::SetProfil(int index)
{
   int i, j, rc;

   double Gost_0[17][14] = GOST_0;
   AnsiString Name_Gost_0[17] = NAME_GOST_0;

   double Gost_B[37][14] = GOST_B;
   AnsiString Name_Gost_B[37] = NAME_GOST_B;

   double Gost_DB[10][14] = GOST_DB;
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

   Index = index;

   for (i=0; i<100; i++) {
     for (j=0; j<16; j++) {
        Gost_Profil[i][j] = 0;
     }
     for (j=0; j<8; j++) {
           Gost_SectorProfil[i][j] = 0;
     }
   }
   switch (index) {
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
   default:
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
//--------------------------------------------------
// Установить тип профиля трубы
void  TStandartProfil::SetProfil_Tube(int index)
{
   int i, j, k, rc;
   int n_p, n_p1, n_p2, n_p3;
   double h0, b0;


   double Square_Tube[155][8] = SQUARE_PROF;
   double Square_Tube_N[128][11] = SQUARE_PROF_N;
   double Square_Tube1_N[109][11] = SQUARE_PROF1_N;


   double Rect_Tube[118][11] = RECT_PROF;
   double Rect_Tube1[136][11] = RECT_PROF1;
   double Rect_Tube2[170][11] = RECT_PROF2;

   double Rect_Tube_N[186][15] = RECT_PROF_N;

   double Rect_Tube1_N[174][15] = RECT_PROF1_N;

   double Rect_Tube2_N[166][15] = RECT_PROF2_N;

   double Rect_Tube3_N[98][15] = RECT_PROF3_N;

   double Circ_Tube[152][8] = CIRC_PROF;
   double Circ_Tube1[166][8] = CIRC_PROF1;

   n_Profil = 0;

   Index = index;

   for (i=0; i<700; i++) {
     for (j=0; j<15; j++) {
        Tube_Profil[i][j] = 0;
     }
   }
   Type_profil_tube = index;

   switch (index) {
   case typeRECT:   // Прямоугольное сечение

     n_p = N_RECT_PROF_N;
     for (i=0; i<n_p; i++) {
       for (j=0; j<15; j++) {
           Tube_Profil[i][j] = Rect_Tube_N[i][j];
       }
     }
     n_p1 = N_RECT_PROF1_N;
     for (i=0; i<n_p1; i++) {
       for (j=0; j<15; j++) {
           Tube_Profil[i+n_p][j] = Rect_Tube1_N[i][j];
       }
     }
     n_p2 = N_RECT_PROF2_N;
     for (i=0; i<n_p2; i++) {
       for (j=0; j<15; j++) {
           Tube_Profil[i+n_p+n_p1][j] = Rect_Tube2_N[i][j];
       }
     }
     n_p3 = N_RECT_PROF3_N;
     for (i=0; i<n_p3; i++) {
       for (j=0; j<15; j++) {
           Tube_Profil[i+n_p+n_p1+n_p2][j] = Rect_Tube3_N[i][j];
       }
     }
     n_Profil_Tube = n_p + n_p1 + n_p2 + n_p3;
     for (i=0; i<n_Profil_Tube; i++) {
       Tube_Profil[i][6] *= 100;
       Tube_Profil[i][8] *= 10000;
       Tube_Profil[i][9] *= 1000;
       Tube_Profil[i][10] *= 10;
       Tube_Profil[i][11] *= 10000;
       Tube_Profil[i][12] *= 1000;
       Tube_Profil[i][13] *= 10;
     }
	 Index_thick_tube = 2;
     h0 = b0 = 0;
     k = 0;
     for (i=0; i<n_Profil_Tube; i++) {
       if (h0 != Tube_Profil[i][0] || b0 != Tube_Profil[i][1]) {
         h0 = Tube_Profil[i][0];
         b0 = Tube_Profil[i][1];
         Name_Profil[k] = FloatToStr(h0)+"*"+FloatToStr(b0);
         k++;
       }
     }
     n_Profil = k;

   break;
   case typeSQUARE:    // Квадратное сечение
     n_p = N_SQUARE_PROF_N;
     for (i=0; i<n_p; i++) {
       for (j=0; j<11; j++) {
           Tube_Profil[i][j] = Square_Tube_N[i][j];
       }
     }
     n_p1 = N_SQUARE_PROF1_N;
     for (i=0; i<n_p1; i++) {
       for (j=0; j<11; j++) {
           Tube_Profil[i+n_p][j] = Square_Tube1_N[i][j];
       }
     }
	 n_Profil_Tube = n_p + n_p1;
     for (i=0; i<n_Profil_Tube; i++) {
       Tube_Profil[i][5] *= 100;
       Tube_Profil[i][7] *= 10000;
       Tube_Profil[i][8] *= 1000;
       Tube_Profil[i][9] *= 10;
     }
	 Index_thick_tube = 2;
     h0 = b0 = 0;
     k = 0;
     for (i=0; i<n_Profil_Tube; i++) {
       if (h0 != Tube_Profil[i][0] || b0 != Tube_Profil[i][1]) {
         h0 = Tube_Profil[i][0];
         b0 = Tube_Profil[i][1];
         Name_Profil[k] = FloatToStr(h0)+"*"+FloatToStr(b0);
         k++;
       }
     }
     n_Profil = k;

   break;
   case typeCIRC:    // Круглое сечение
     n_p = N_CIRC_PROF;
     for (i=0; i<n_p; i++) {
       for (j=0; j<8; j++) {
           Tube_Profil[i][j] = Circ_Tube[i][j];
       }
     }
     n_p1 = N_CIRC_PROF1;
     for (i=0; i<n_p1; i++) {
       for (j=0; j<8; j++) {
           Tube_Profil[i+n_p][j] = Circ_Tube1[i][j];
       }
     }
     n_Profil_Tube = n_p + n_p1;
     for (i=0; i<n_Profil_Tube; i++) {
       Tube_Profil[i][2] *= 100;
       Tube_Profil[i][4] *= 10000;
       Tube_Profil[i][5] *= 1000;
       Tube_Profil[i][6] *= 10;
     }
	 Index_thick_tube = 1;
     h0 = 0;
     k = 0;
     for (i=0; i<n_Profil_Tube; i++) {
       if (h0 != Tube_Profil[i][0] ) {
         h0 = Tube_Profil[i][0];
         Name_Profil[k] = FloatToStr(h0);
         k++;
       }
     }
     n_Profil = k;
   break;
   default:
	 #ifdef EMBRAC
	 i = Application->MessageBox((L"Ошибочный тип стандартного профиля трубы: "+IntToStr(index)).c_str(), L"SetProfil_Tube", MB_OK | MB_ICONERROR);
	 #else
  	 i = Application->MessageBox(("Ошибочный тип стандартного профиля трубы: "+IntToStr(index)).c_str(), "SetProfil_Tube", MB_OK | MB_ICONERROR);
	 #endif
	 n_Profil = 0;
     return;
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
// Получить вектор секториальных параметров профиля швеллера по его номеру
double* TStandartProfil::GetVectorSectorParamProfil(int n_profil) {
   return Gost_SectorProfil[n_profil];
}
//----------------------------------------------------------------------
// Получить вектор параметров профиля трубы по порядковому номеру профиля
double* TStandartProfil::GetVectorParamProfil_TubeNum(int number_prof) {
   int n_profil, n_thick;
   int rc = GetGroup_a_Profil_Tube(number_prof, &n_profil, &n_thick);
   return GetVectorParamProfil_Tube(n_profil, n_thick);
}
// Получить вектор параметров профиля трубы по номеру группы (h*b) и номеру внутри группы (t)
double* TStandartProfil::GetVectorParamProfil_Tube(int n_profil, int n_thick) {
   int i;
   AnsiString NameProf0;
   double h0, b0;

   for (i=0; i<n_Profil_Tube; i++) {
      h0 = Tube_Profil[i][0];
      b0 = Tube_Profil[i][1];
      if (Type_profil_tube!=typeCIRC)
        NameProf0 = FloatToStr(h0)+"*"+FloatToStr(b0);
      else
        NameProf0 = FloatToStr(h0);
      if (NameProf0==Name_Profil[n_profil])
         break;
   }
   if (i+n_thick >= n_Profil_Tube)
      return NULL;
   else
      return Tube_Profil[i+n_thick];
}
//----------------------------------------------------------------------
// Получить номер профиля трубы по номеру группы (h*b) и номеру внутри группы (t)
int TStandartProfil::GetNumberProfil_Tube(int n_profil, int n_thick) {
   int i;
   AnsiString NameProf0;
   double h0, b0;

   for (i=0; i<n_Profil_Tube; i++) {
      h0 = Tube_Profil[i][0];
      b0 = Tube_Profil[i][1];
      if (Type_profil_tube!=typeCIRC)
        NameProf0 = FloatToStr(h0)+"*"+FloatToStr(b0);
      else
        NameProf0 = FloatToStr(h0);

      if (NameProf0==Name_Profil[n_profil])
         break;
   }
   if (i+n_thick >= n_Profil_Tube)
	  return n_Profil_Tube-1;
   else
      return i+n_thick;
}
//----------------------------------------------------------------------
// Получить количество профилей трубы
int TStandartProfil::GetNumberAllProfil_Tube() {
   return n_Profil_Tube;
}
//----------------------------------------------------------------------
// Получить  номер группы (h*b) и номер внутри группы (t) по порядковому номеру профиля трубы
int TStandartProfil::GetGroup_a_Profil_Tube(int Number, int *n_profil, int *n_thick) {
   int i;
   AnsiString NameProf0, NameProfil_cur;
   double h0, b0;

   if (Type_profil_tube!=typeCIRC)
     NameProf0 = FloatToStr(Tube_Profil[Number][0])+"*"+FloatToStr(Tube_Profil[Number][1]);
   else
     NameProf0 = FloatToStr(Tube_Profil[Number][0]);

   for (i=0; i<n_Profil; i++) {
     if (NameProf0==Name_Profil[i])
         break;
   }
   if (i>= n_Profil)
      return 1;
   *n_profil = i;

   for (i=0; i<n_Profil_Tube; i++) {
     if (Type_profil_tube!=typeCIRC)
       NameProfil_cur = FloatToStr(Tube_Profil[i][0])+"*"+FloatToStr(Tube_Profil[i][1]);
     else
       NameProfil_cur = FloatToStr(Tube_Profil[i][0]);

     if (NameProf0==NameProfil_cur)
         break;
   }
   if (i>= n_Profil_Tube)
      return 1;
   *n_thick = Number - i;
   return 0;
}
//----------------------------------------------------------------------
// Получить вектор толщин профиля трубы по номеру группы (h*b) и их количество
double* TStandartProfil::GetVectorParamThickness_Tube(int n_profil, int *num_thick) {
   int i, k;
   AnsiString NameProf0;
   double h0, b0;

   for (i=0; i<n_Profil_Tube; i++) {
      h0 = Tube_Profil[i][0];
      b0 = Tube_Profil[i][1];
      if (Type_profil_tube!=typeCIRC)
        NameProf0 = FloatToStr(h0)+"*"+FloatToStr(b0);
      else
        NameProf0 = FloatToStr(h0);
      if (NameProf0==Name_Profil[n_profil])
         break;
   }
   if (i >= n_Profil_Tube)
      return NULL;
   k=0;
   for (; i<n_Profil_Tube; i++) {
      h0 = Tube_Profil[i][0];
      b0 = Tube_Profil[i][1];
      if (Type_profil_tube!=typeCIRC)
        NameProf0 = FloatToStr(h0)+"*"+FloatToStr(b0);
      else
        NameProf0 = FloatToStr(h0);

      if (NameProf0!=Name_Profil[n_profil])
         break;
      Thickness[k] = Tube_Profil[i][Index_thick_tube];
      k++;
   }
   *num_thick = k;
   return Thickness;
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
//----------------------------------------------------------------------
// Заполнить структуру параметров сечения трубы по ее номеру
int TStandartProfil::SetParamProfil_Tube(COMMON_SECT* sect_comm, int type_sect, int Number) {
   int n_profil, n_thick, rc;

   if (Number >= n_Profil_Tube || Number <0)
      return 1;
   rc = GetGroup_a_Profil_Tube(Number, &n_profil, &n_thick);
   if (rc >0)
     return rc;
   if (type_sect== typeSQUARE) {
     sect_comm->square.n_group = n_profil;
     sect_comm->square.n_profil = n_thick;
     sect_comm->square.index_orient = 0;
     sect_comm->square.side = Tube_Profil[Number][0];
     sect_comm->square.thickness = Tube_Profil[Number][2];
     sect_comm->square.b1 = 0;
     sect_comm->square.h1 = 0;
     sect_comm->square.b2 = 0;
     sect_comm->square.h2 = 0;
     sect_comm->square.rad = Tube_Profil[Number][3];;
     sect_comm->square.t_red = Tube_Profil[Number][10];;
     sect_comm->square.flag_concl = true;
   }
   if (type_sect== typeRECT) {
     sect_comm->rect.n_group = n_profil;
     sect_comm->rect.n_profil = n_thick;
     sect_comm->rect.index_orient = 0;
     sect_comm->rect.h = Tube_Profil[Number][0];
     sect_comm->rect.b = Tube_Profil[Number][1];
     sect_comm->rect.b1 = Tube_Profil[Number][2];
     sect_comm->rect.h1 = Tube_Profil[Number][2];
     sect_comm->rect.b2 = 0;
     sect_comm->rect.h2 = 0;
     sect_comm->square.rad = Tube_Profil[Number][3];;
     sect_comm->square.t_red = Tube_Profil[Number][14];;
     sect_comm->rect.flag_concl = true;
   }
   if (type_sect== typeCIRC) {
     sect_comm->circ.n_group = n_profil;
     sect_comm->circ.n_profil = n_thick;
     sect_comm->circ.index_orient = 0;
     sect_comm->circ.diameter = Tube_Profil[Number][0];
     sect_comm->square.thickness = Tube_Profil[Number][1];
     sect_comm->circ.b1 = 0;
     sect_comm->circ.h1 = 0;
     sect_comm->circ.b2 = 0;
     sect_comm->circ.h2 = 0;
     sect_comm->circ.t_red = Tube_Profil[Number][7];;
     sect_comm->circ.flag_concl = true;
   }
   return 0;
}
//------------------------------------------------------------------------
// Провека совпадения стандартных сечений
void Check_StandartProfil(SECT_DVUTAVR* sect1, SECT_DVUTAVR* sect2, AnsiString text) {
       int i;
       if (sect1->n_group != sect2->n_group ||
           sect1->n_profil != sect2->n_profil) {
	 #ifdef EMBRAC
		   i = Application->MessageBox((L"На конструктивном элементе заданы разные стандартные сечения. Принимается сечение по "+text).c_str(),
		   L"", MB_OK | MB_ICONWARNING);
	 #else
		   i = Application->MessageBox(("На конструктивном элементе заданы разные стандартные сечения. Принимается сечение по "+text).c_str(),
		   "", MB_OK | MB_ICONWARNING);
	 #endif
           sect2->n_group = sect1->n_group;
           sect2->n_profil = sect1->n_profil;
           sect2->h = sect1->h;
           sect2->b = sect1->b;
           sect2->h1 = sect1->h1;
           sect2->b1 = sect1->b1;
           sect2->h2 = sect1->h2;
           sect2->b2 = sect1->b2;
       }
}
//------------------------------------------------------------------
// Сравнение типов профилей
bool Compare_group(int n_group, int type_profil) {
  if (n_group <=typeSTO_K && type_profil <= typeSTO_K || n_group == type_profil)
    return true;
  if (n_group >=typeGOST_G57837_B && n_group <=typeGOST_G57837_S &&
      (type_profil >=typeGOST_G57837_B && type_profil <=typeGOST_G57837_S || type_profil <= typeSTO_K) ||
      n_group == type_profil)
    return true;
  else
    return false;
}
//---------------------------------------------------------------------------
// Сменить или установить тип профиля двутавра для сечения
void  Set_TypeProfil(SECT_DVUTAVR* sect, int index_profil, int type_profil) {
   TStandartProfil StandartProfil;

   if (sect->n_group >= 0 && index_profil == 0) {
       sect->n_group = -1;
       return;
   }
   if ((sect->n_group < 0 || !Compare_group(sect->n_group, type_profil)) && index_profil ==1 ) {
     // Установить тип стандартного сечения
     StandartProfil.SetProfil(type_profil);
     sect->n_group = type_profil;
     sect->n_profil = StandartProfil.Get_NumberProfil(sect, 0);
     int rc = StandartProfil.SetParamProfil(sect, sect->n_profil);
     return;
   }
}
//---------------------------------------------------------------------------
// Сменить или установить тип профиля двутавра или трубы для сечения
void  Set_TypeProfil_Com(int type_sect, SECT_DVUTAVR* sect, int index_profil, int type_profil) {
   TStandartProfil StandartProfil;

   if (sect->n_group >= 0 && index_profil == 0) {
       sect->n_group = -1;
       return;
   }
   if (type_sect == DVUTAVR || type_sect == SHVELLER) {
     if ((sect->n_group < 0 || !Compare_group(sect->n_group, type_profil)) && index_profil ==1 ) {
       // Установить тип стандартного сечения
       StandartProfil.SetProfil(type_profil);
       sect->n_profil = StandartProfil.Get_NumberProfil(sect, 0);
       sect->n_group = type_profil;
       int rc = StandartProfil.SetParamProfil(sect, sect->n_profil);
       return;
     }
   }
   else {
     if (type_sect == SQUARE_TUBE || type_sect == RECT_TUBE) {
       COMMON_SECT sect_com;
       memcpy(&sect_com.dvutavr, sect, sizeof(SECT_DVUTAVR));
       if (type_sect== SQUARE_TUBE) {
         type_profil = typeSQUARE;
         double h = sect_com.square.side;
         double t = sect_com.square.thickness;
         sect_com.rect.b = h;
         sect_com.rect.h = h;
         sect_com.rect.b1 = t;
         sect_com.rect.h1 = t;
         type_sect = RECT_TUBE;
       }
       else {
         type_profil = typeRECT;
       }
       //if ((sect->n_group < 0 || sect->n_group != type_profil) && index_profil ==1) {
       if (sect->n_group < 0 && index_profil ==1) {
       // Установить тип стандартного сечения
         StandartProfil.SetProfil_Tube(type_profil);
         // Ближайший номер сечения по ширине, высоте, и толщине
         int Number = StandartProfil.Get_NumberProfil_Tube(type_sect, &sect_com, 0);

         // Заполнить структуру параметров сечения трубы по его номеру
         int rc = StandartProfil.SetParamProfil_Tube(&sect_com, type_profil, Number);
         if (rc>0)
            return;
         memcpy(sect, &sect_com.dvutavr, sizeof(SECT_DVUTAVR));
       }
     }
     else {
       sect->n_group = -1;
     }
   }
}

//---------------------------------------------------------------------------
// Установить начальный тип профиля двутавра (при этом должен установиться стандартный профиль и для других типов)
void    Set_TypeProfilInit(SECT_DVUTAVR* sect, int index_profil, int type_profil) {
   TStandartProfil StandartProfil;

   if (index_profil == 0) {
       sect->n_group = -1;
       return;
   }
   if (index_profil ==1 ) {
     // Установить тип стандартного сечения
     StandartProfil.SetProfil(type_profil);
     sect->n_profil = StandartProfil.Get_NumberProfil(sect, 0);
     sect->n_group = type_profil;
     int rc = StandartProfil.SetParamProfil(sect, sect->n_profil);
     return;
   }
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
//------------------------------------------------------------------------
// Получить номер профиля, ближайший по параметру 0-по высоте, ширине и толщине, 4-по площади, 6-по моменту инерции
int TStandartProfil::Get_NumberProfil_Tube(int type_sect, COMMON_SECT* sect_com, int index) {
     int i;
     double Wz, param, delta;
     int iS;
     GEOM_PARAM_SECT param_sect;

     if (!sect_com->rect.flag_concl)
       return 0;

     Get_param_sect_comm(type_sect, sect_com, &param_sect);
     if (param_sect.Hsect == 0 || param_sect.Ar==0)
       return 0;
     delta = 1e12;
     iS = 0;
     if (index==0) {
       if (type_sect==SQUARE_TUBE) {
         for (i=0; i<n_Profil_Tube; i++) {
           if (Tube_Profil[i][0] > sect_com->square.side &&
              Tube_Profil[i][2] > sect_com->square.thickness) {
            break;
           }
         }
       }
       if (type_sect==RECT_TUBE) {
         for (i=0; i<n_Profil_Tube; i++) {
           if (Tube_Profil[i][0] > sect_com->rect.b && Tube_Profil[i][1] > sect_com->rect.h &&
              Tube_Profil[i][2] > sect_com->rect.b1 && Tube_Profil[i][3] > sect_com->rect.h1) {
            break;
           }
         }
       }
       if (type_sect==CIRCULAR_TUBE) {
         for (i=0; i<n_Profil_Tube; i++) {
           if (Tube_Profil[i][0] > sect_com->circ.diameter &&
              Tube_Profil[i][1] > sect_com->circ.thickness) {
            break;
           }
         }
       }
       return (MAX(0, i-1));
     }
     else {
       int i_new;
       int index_square[10] = {0, 1, 2, 3, 5, 6, 7, 8, 9, 10};
       int index_rect[10] =   {0, 1, 2, 3, 6, 7, 8, 9, 10, 11};
       int index_circ[10] =   {0, 1, 1, 1, 2, 3, 4, 5, 6, 7};
       switch(type_sect) {
       case SQUARE_TUBE:
        i_new = index_square[index];
       break;
       case RECT_TUBE:
        i_new = index_rect[index];
       break;
       case CIRCULAR_TUBE:
        i_new = index_circ[index];
       break;
       }

       for (i=0; i<n_Profil; i++) {
         param = Tube_Profil[i][i_new];
         switch(index) {
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
}
//---------------------------------------------------------------------------------------------------------
// Получить номер профиля, ближайший по заданному параметру 0-по высоте, 4-по площади, 6-по моменту инерции
int TStandartProfil::Get_NumberProfil_param(double param, int index) {
       int i;

       for (i=0; i<n_Profil; i++) {
         if (Gost_Profil[i][index] - param >=0 )
            break;
       }
       if (i==n_Profil)
         return -1;
       else
         return i;
}
//---------------------------------------------------------------------------------------------------------
// Получить номер профиля, ближайший по заданному параметру 0-по высоте, 4-по площади, 6-по моменту инерции
int TStandartProfil::Choice_Profil_param(SECT_DVUTAVR* sect, double Ar, double ix, double W,
                                         double h_sect, double tw, double tf, double bf, bool flag_message) {

       int i;
       SetProfil(sect->n_group);

       int iAr = Get_NumberProfil_param(Ar, parAREA);
       int iix = Get_NumberProfil_param(ix, parIRADZ);
       int iW = Get_NumberProfil_param(W, parWZ);
       int ih = Get_NumberProfil_param(h_sect, parHSECT);
       int itw = Get_NumberProfil_param(tw, parTW);
       int itf = Get_NumberProfil_param(tf, parTF);
       int ibf = Get_NumberProfil_param(bf, parBF);
       int n_max = -1;
       double par_max = 0;
       AnsiString text_max;
       if (iAr >0 && iAr > n_max) {
         n_max = iAr;
         text_max = "площадь поперечного сечения";
         par_max = Round(iAr, 0);
       }
       if (ix >0 && iix > n_max) {
         n_max = iix;
         text_max = "радиус инерции";
         par_max = Round(ix, 0);
       }
       if (W>0 && iW > n_max) {
         n_max = iW;
         text_max = "момент сопротивления изгибу";
         par_max = Round(W, 0);
       }

       if (h_sect>0 && ih > n_max) {
         n_max = ih;
         text_max = "высота сечения";
         par_max = Round(h_sect, 0);
       }
       if (tw>0 && itw > n_max) {
         n_max = itw;
         text_max = "толщина стенки";
         par_max = Round(tw, 1);
       }
       if (tf>0 && itf > n_max) {
         n_max = itf;
         text_max = "толщина полки";
         par_max = Round(tf, 1);
       }
       if (bf>0 && ibf > n_max) {
         n_max = ibf;
         text_max = "ширина полки";
         par_max = Round(bf, 0);
       }
       int n_min = 1000;
       double par_min = 0;
       AnsiString text_min ;
       if (iAr>0 && iAr < n_min) {
         n_min = iAr;
         text_min = "площадь поперечного сечения";
         par_min = Round(iAr, 0);
       }
       if (ix>0 && iix < n_min) {
         n_min = iix;
         text_min = "радиус инерции";
         par_min = Round(ix, 0);
       }
       if (W>0 && iW < n_min) {
         n_min = iW;
         text_min = "момент сопротивления изгибу";
         par_min = Round(W, 0);
       }
       if (h_sect>0 && ih < n_min) {
         n_min = ih;
         text_min = "высота сечения";
         par_min = Round(h_sect, 0);
       }
       if (tw>0 && itw < n_min) {
         n_min = itw;
         text_min = "толщина стенки";
         par_min = Round(tw, 0);

       }
       if (tf>0 && itf < n_min) {
         n_min = itf;
         text_min = "толщина полки";
         par_min = Round(tf, 0);
       }
       if (bf>0 && ibf < n_min) {
         n_min = ibf;
         text_min = "ширина полки";
         par_min = Round(bf, 0);
       }
	   if (n_min == -1) {
		 #ifdef EMBRAC
		 i = Application->MessageBox((L"Раздел сортамента не содержит сечения требуемого размера, критический параметр: "+
									  text_min+" = "+FloatToStr(par_min)).c_str(),L"",
									  MB_OK | MB_ICONERROR);
		 #else
		 i = Application->MessageBox(("Раздел сортамента не содержит сечения требуемого размера, критический параметр: "+
									  text_min+" = "+FloatToStr(par_min)).c_str(),"",
									  MB_OK | MB_ICONERROR);
		 #endif
		 return 1;
       }
       // Заполнить структуру параметров сечения по его номеру
       int rc = SetParamProfil(sect, n_max);
       if (rc>0)
          return rc;
	   if (n_max - n_min > 1 && flag_message) {
		 #ifdef EMBRAC
		 i=Application->MessageBox((L"Сечение принято по критическому параметру ("+text_max+
								   "), номер сечения по наименее критическому параметру ("+
								   text_min+") меньше на "+IntToStr(n_max - n_min)+" пункта").c_str(),L"",
								   MB_OK | MB_ICONWARNING);
		 #else
		 i=Application->MessageBox(("Сечение принято по критическому параметру ("+text_max+
								   "), номер сечения по наименее критическому параметру ("+
								   text_min+") меньше на "+IntToStr(n_max - n_min)+" пункта").c_str(),"",
								   MB_OK | MB_ICONWARNING);
		 #endif
	   }
     return 0;
}

#pragma package(smart_init)
