//---------------------------------------------------------------------------
#include <vcl.h>
#include <math.h>
#include <stdio.h>

#pragma hdrstop

#include "Get_param_sect_func.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)

#include "Data_Profil.h"
#include "ListConst.h"
#include "ProcExt.h"
#include "StandartProfil.h"


static TStandartProfil StandartProfil;
//-----------------------------------------------------------
// Вычислить геометрические параметры произвольного сечения
void Getcom_param_sect(int type, SECT_DVUTAVR* sect, COMMON_SECT* section, GEOM_PARAM_SECT *param_sect) {
   if (type==NO_CHOISE)
     Get_param_sect(sect, param_sect);
   else
     Get_param_sect_comm(type, section, param_sect);
}
//-----------------------------------------------------------
// Вычислить геометрические параметры произвольного сечения по ссылке на двутавровое
void Get_param_sect_gener(int type_sect, SECT_DVUTAVR* section, GEOM_PARAM_SECT *param_sect) {
    COMMON_SECT  sect_comm;

    memcpy(&(sect_comm.dvutavr), section, sizeof(COMMON_SECT));
    Get_param_sect_comm(type_sect, &sect_comm, param_sect);

}
//-----------------------------------------------------------
// Вычислить геометрические параметры двутаврового сечения
void Get_param_sect(SECT_DVUTAVR* section, GEOM_PARAM_SECT *param_sect) {
   double stat_mom;
   double * ParamProfil;
   int rc;


   if (section->n_group > 1000) {
	  #ifdef EMBRAC
	  rc = Application->MessageBox(L"Get_param_sect:Программная ошибка. Номер группы стандартного сечения > 1000",
			   L"Вычисление геометрических параметров сечения ", MB_OK | MB_ICONERROR);
	  #else
	  rc = Application->MessageBox("Get_param_sect:Программная ошибка. Номер группы стандартного сечения > 1000",
			   "Вычисление геометрических параметров сечения ", MB_OK | MB_ICONERROR);
	  #endif
	  return;
   }
   param_sect->Rad = 0;
   param_sect->index_orient = section->index_orient;
   if (section->n_group <0) { // Сварное сечение
     /*
     if (section->b == 0 || section->h == 0 || section->b1 == 0 || section->h1 == 0 ||
         section->b2 == 0 || section->h2 == 0) {
         rc = Application->MessageBox("Get_param_sect: Один из параметров двутаврового сечения равен нулю",
               "Вычисление геометрических параметров сечения ", MB_OK | MB_ICONWARNING);
     }
     */
     param_sect->Ar = section->b*section->h + section->b1*section->h1 + section->b2*section->h2;
     param_sect->Hsect = section->h + section->h1 + section->h2;
     param_sect->Wsect = MAX(section->b1, section->b2);

     stat_mom = section->b*section->h*(section->h/2 + section->h1) +
              section->b1*section->h1*section->h1/2 +
              section->b2*section->h2*(param_sect->Hsect - section->h2/2);

     param_sect->Zct = Round(stat_mom/param_sect->Ar, 1);
     param_sect->Yct = param_sect->Wsect/2;
     param_sect->Izz = section->h1*section->h1*section->h1*section->b1/12 +
                     section->h1*section->b1*(param_sect->Zct - section->h1/2)*(param_sect->Zct - section->h1/2)+
                     section->h2*section->h2*section->h2*section->b2/12 +
                     section->h2*section->b2*(param_sect->Hsect - section->h2/2 - param_sect->Zct)*(param_sect->Hsect - section->h2/2 - param_sect->Zct)+
                     section->h*section->h*section->h*section->b/12 +
                     section->b*section->h*(section->h/2 + section->h1 - param_sect->Zct)*(section->h/2 + section->h1 - param_sect->Zct);
     param_sect->Iyy = section->b1*section->b1*section->b1*section->h1/12 +
                     section->b2*section->b2*section->b2*section->h2/12 +
                     section->h*section->b*section->b*section->b/12;
     param_sect->Iyz = 0.0;
     param_sect->Hp = param_sect->Hsect - section->h1/2 - section->h2/2;
     param_sect->Zp = param_sect->Zct - section->h1/2;

   /* Справочник металлиста, стр 87 - для тонкостенного двутавра */
     param_sect->Itor = (section->h1*section->h1*section->h1*section->b1 +
                      section->h2*section->h2*section->h2*section->b2 +
                      section->h*section->b*section->b*section->b)/3;

     if (section->b1 > 1e-6) {
        param_sect->ky = 0.38*pow((section->h/section->b1),0.45) - 0.1;  // приближенно
     }
     else {
       param_sect->ky = 0.5;
     }
     param_sect->kz = 0.5;  // очень приближенно

     param_sect->point_stress[0][0] = param_sect->Zct - (section->h + section->h1 + section->h2);
     param_sect->point_stress[0][1] = section->b2/2;
     param_sect->point_stress[1][0] = param_sect->point_stress[0][0];
     param_sect->point_stress[1][1] = -param_sect->point_stress[0][1];
     param_sect->point_stress[2][0] = param_sect->Zct;
     param_sect->point_stress[2][1] = -section->b1/2;
     param_sect->point_stress[3][0] = param_sect->point_stress[2][0];
     param_sect->point_stress[3][1] = -param_sect->point_stress[2][1];

     // координаты Z точек вычисчления касательных напряжений (относительно ц.т)
     param_sect->z_tau[2] = 0;
     param_sect->z_tau[0] = param_sect->Zct - section->h1;
     param_sect->z_tau[1] = param_sect->Zct - (section->h - section->h1);
     // Статические моменты для вычисления касательных в стенке
     param_sect->Sx[0] = Round(section->b1*section->h1*(param_sect->Zct - section->h1/2) +
                       0.5*(param_sect->Zct - section->h1)*(param_sect->Zct - section->h1)*section->b, 0); // точка в ц.т.
     param_sect->Sx[1] = Round(section->b1*section->h1*(param_sect->Zct - section->h1/2), 0); // точка на стенке в стыке с внешним поясом
     param_sect->Sx[2] = Round(section->b2*section->h2*(section->h + section->h1 + section->h2/2 - param_sect->Zct), 0); // точка на стенке в стыке с внутренним поясом

     param_sect->Sy[0] = 0;
     param_sect->Sy[1] = 0;
     param_sect->Sy[2] = 0;

     param_sect->Ar = Round(param_sect->Ar, 0);
     param_sect->Itor = Round(param_sect->Itor, 0);
     param_sect->Izz = Round(param_sect->Izz, 0);
     param_sect->Iyy = Round(param_sect->Iyy, 0);
     param_sect->Itor = Round(param_sect->Itor, 0);
   }
   else {
     StandartProfil.SetProfil(section->n_group);
     ParamProfil = StandartProfil.GetVectorParamProfil(section->n_profil);
     param_sect->Ar = ParamProfil[parAREA];
     param_sect->Hsect = ParamProfil[parHSECT];

     param_sect->Zct = param_sect->Hsect/2;
     param_sect->Wsect = ParamProfil[parBF];
     param_sect->Yct = param_sect->Wsect/2;
     param_sect->Izz = ParamProfil[parIZZ];
     param_sect->Iyy = ParamProfil[parIYY];
     param_sect->Iyz = 0.0;
     param_sect->Hp = param_sect->Hsect - section->h1/2 - section->h2/2;
     param_sect->Zp = param_sect->Zct - section->h1/2;
     param_sect->Rad = ParamProfil[parRAD];

   /* Справочник металлиста, стр 87 - для тонкостенного двутавра */
     param_sect->Itor = (section->h1*section->h1*section->h1*section->b1 +
                      section->h2*section->h2*section->h2*section->b2 +
                      section->h*section->b*section->b*section->b)/3;

     if (section->b1 > 1e-6) {
        param_sect->ky = 0.38*pow((section->h/section->b1),0.45) - 0.1;  // приближенно
     }
     else {
       param_sect->ky = 0.5;
     }
     param_sect->kz = 0.5;  // очень приближенно

     param_sect->point_stress[0][0] = -param_sect->Zct;
     param_sect->point_stress[0][1] = section->b2/2;
     param_sect->point_stress[1][0] = param_sect->point_stress[0][0];
     param_sect->point_stress[1][1] = -param_sect->point_stress[0][1];
     param_sect->point_stress[2][0] = param_sect->Zct;
     param_sect->point_stress[2][1] = -section->b1/2;
     param_sect->point_stress[3][0] = param_sect->point_stress[2][0];
     param_sect->point_stress[3][1] = -param_sect->point_stress[2][1];

     param_sect->z_tau[2] = 0;
     param_sect->z_tau[0] = param_sect->Zct - section->h1;
     param_sect->z_tau[1] = param_sect->Zct - (section->h - section->h1);

     param_sect->Sx[0] = ParamProfil[parSZ]; // точка в ц.т.
     param_sect->Sx[1] = Round(section->b1*section->h1*(param_sect->Zct - section->h1/2), 0); // точка на стенке в стыке с внешним поясом
     param_sect->Sx[2] = Round(section->b2*section->h2*(section->h + section->h1 + section->h2/2 - param_sect->Zct), 0); // точка на стенке в стыке с внутренним поясом

     param_sect->Sy[0] = 0;
     param_sect->Sy[1] = 0;
     param_sect->Sy[2] = 0;

     param_sect->Ar = Round(param_sect->Ar, 0);
     param_sect->Itor = Round(param_sect->Itor, 0);
     param_sect->Izz = Round(param_sect->Izz, 0);
     param_sect->Iyy = Round(param_sect->Iyy, 0);
   }
}
//-----------------------------------------------------------
// Вычислить геометрические параметры двутаврового сечения с дополнительной полкой
void Get_param_sect_pop(SECT_DVUTAVR* section, double t_pop, double pos_pop, GEOM_PARAM_SECT *param_sect) {
   // pos_pop - привязка внешней грани ребра относительно внешней грани наружной полки
   // ширина ребра равна ширине наружной полки
   double stat_mom;

   param_sect->index_orient = section->index_orient;
   param_sect->Rad = 0;
   param_sect->Ar = section->b*section->h + section->b1*section->h1 + section->b2*section->h2 +
                    t_pop*(section->b1 - section->b);
   param_sect->Hsect = section->h + section->h1 + section->h2;
   param_sect->Wsect = MAX(section->b1, section->h2);

   stat_mom = section->b*section->h*(section->h/2 + section->h1) +
              section->b1*section->h1*section->h1/2 +
              section->b2*section->h2*(param_sect->Hsect - section->h2/2) +
              t_pop*(section->b1 - section->b)*pos_pop;

   param_sect->Zct = Round(stat_mom/param_sect->Ar, 1);
   param_sect->Yct = param_sect->Wsect/2;
   param_sect->Izz = section->h1*section->h1*section->h1*section->b1/12 +
                     section->h1*section->b1*(param_sect->Zct - section->h1/2)*(param_sect->Zct - section->h1/2)+
                     section->h2*section->h2*section->h2*section->b2/12 +
                     section->h2*section->b2*(param_sect->Hsect - section->h2/2 - param_sect->Zct)*(param_sect->Hsect - section->h2/2 - param_sect->Zct)+
                     section->h*section->h*section->h*section->b/12 +
                     section->b*section->h*(section->h/2 + section->h1 - param_sect->Zct)*(section->h/2 + section->h1 - param_sect->Zct) +
                     t_pop*t_pop*t_pop*(section->b1 - section->h)/12 +
                     t_pop*(section->b1 - section->b)*(param_sect->Zct - pos_pop - t_pop/2);
   param_sect->Hp = param_sect->Hsect - section->h1/2 - section->h2/2;
   param_sect->Zp = param_sect->Zct - section->h1/2;
   param_sect->Iyy = section->b1*section->b1*section->b1*section->h1/12 +
                     section->b2*section->b2*section->b2*section->h2/12 +
                     section->h*section->b*section->b*section->b/12 +
                     t_pop*(section->b1 - section->b)*(section->b1 - section->b)*(section->b1 - section->b)/12;
   param_sect->Iyz = 0.0;

   /* Справочник металлиста, стр 87 - для тонкостенного двутавра */
   param_sect->Itor = (section->h1*section->h1*section->h1*section->b1 +
                      section->h2*section->h2*section->h2*section->b2 +
                      section->h*section->b*section->b*section->b)/3;

   if (section->b1 > 1e-6) {
      param_sect->ky = 0.38*pow((section->h/section->b1),0.45) - 0.1;  // приближенно
   }
   else {
      param_sect->ky = 0.5;
   }
   param_sect->kz = 0.5;  // очень приближенно

   param_sect->point_stress[0][0] = param_sect->Zct - (section->h + section->h1 + section->h2);
   param_sect->point_stress[0][1] = section->b2/2;
   param_sect->point_stress[1][0] = param_sect->point_stress[0][0];
   param_sect->point_stress[1][1] = -param_sect->point_stress[0][1];
   param_sect->point_stress[2][0] = param_sect->Zct;
   param_sect->point_stress[2][1] = -section->b1/2;
   param_sect->point_stress[3][0] = param_sect->point_stress[2][0];
   param_sect->point_stress[3][1] = -param_sect->point_stress[2][1];

   param_sect->z_tau[2] = 0;
   param_sect->z_tau[0] = param_sect->Zct - section->h1;
   param_sect->z_tau[1] = param_sect->Zct - (section->h - section->h1);
   //
   param_sect->Sx[0] = Round(section->b1*section->h1*(param_sect->Zct - section->h1/2) +
                       0.5*(param_sect->Zct - section->h1)*(param_sect->Zct - section->h1)*section->b +
                       t_pop*(section->b1 - section->b)*(param_sect->Zct - pos_pop - t_pop/2), 0); // точка в ц.т.
   param_sect->Sx[1] = Round(section->b1*section->h1*(param_sect->Zct - section->h1/2), 0); // точка на стенке в стыке с внешним поясом
   param_sect->Sx[2] = Round(section->b2*section->h2*(section->h + section->h1 + section->h2/2 - param_sect->Zct), 0); // точка на стенке в стыке с внутренним поясом

   param_sect->Ar = Round(param_sect->Ar, 0);
   param_sect->Itor = Round(param_sect->Itor, 0);
   param_sect->Izz = Round(param_sect->Izz, 0);
   param_sect->Iyy = Round(param_sect->Iyy, 0);
   param_sect->Itor = Round(param_sect->Itor, 0);
}
//-----------------------------------------------------------
// Вычислить геометрические параметры двутаврового сечения с учетом ослабления отверстиями
void Get_param_sect_netto(SECT_DVUTAVR *section, GEOM_PARAM_SECT *param_sect, double *diametr, int *num_hole, double *space, double *step) {
    SECT_DVUTAVR  sect_hole;
    double A1, A2, Asten1, Asten2, Ar, Zct, Izz, Iyy, stat_mom;
    double stat_b1, stat_b2, Izz_b1, Izz_b2, Sx_b1, Sx_b2, Iyy_a1, Iyy_a2, Zp, Sx[3];
    int i;

    Get_param_sect(section, param_sect);
    A1 = diametr[0]*num_hole[0]*section->h1;
    A2 = diametr[1]*num_hole[1]*section->h2;
    Asten1 = diametr[2]*num_hole[2]*section->b;
    Asten2= diametr[3]*num_hole[3]*section->b;
    Ar = A1 + A2 + Asten1 + Asten2;
    if (space[2]==0 || step[2]==0) {
      stat_b1 = diametr[2]*section->b*num_hole[2]*(section->h/4 + section->h1);
    }
    else {
      stat_b1 = 0;
      for (i=0; i<num_hole[2]; i++) {
        stat_b1 += diametr[2]*section->b*(space[2]+step[2]*i+section->h1);
      }
    }
    if (space[3]==0 || step[3]==0) {
      stat_b2 = diametr[3]*section->b*num_hole[3]*(3*section->h/4 + section->h1);
    }
    else {
      stat_b2 = 0;
      for (i=0; i<num_hole[3]; i++) {
        stat_b2 += diametr[3]*section->b*(section->h1 + section->h - space[3] - step[3]*i);
      }
    }
    stat_mom = stat_b1 + stat_b2 +
               A1*section->h1/2 +
               A2*(param_sect->Hsect - section->h2/2);
    Zct = stat_mom/Ar;

    if (space[2]==0 || step[2]==0) {
      Izz_b1 = Asten1*(Zct - section->h/4 - section->h1)*(Zct - section->h/4 - section->h1);
      Sx_b1 = Asten1*(Zct - section->h/4 - section->h1);
    }
    else {
      Izz_b1 = 0;
      Sx_b1 = 0;
      for (i=0; i<num_hole[2]; i++) {
        Izz_b1 += diametr[2]*section->b*(Zct - space[2] - step[2]*i - section->h1)*
                                        (Zct - space[2] - step[2]*i - section->h1);
        Sx_b1 += diametr[2]*section->b*(Zct - space[2] - step[2]*i - section->h1);
      }
    }
    if (space[3]==0 || step[3]==0) {
      Izz_b2 = Asten2*(Zct - 3*section->h/4 + section->h1)*(Zct - 3*section->h/4 + section->h1);
      Sx_b2 = Asten2*(Zct - 3*section->h/4 + section->h1);
    }
    else {
      Izz_b2 = 0;
      Sx_b2 = 0;
      for (i=0; i<num_hole[3]; i++) {
        Izz_b2 += diametr[3]*section->b*(param_sect->Hsect - section->h2 - space[3] - step[3]*i)*
                                        (param_sect->Hsect - section->h2 - space[3] - step[3]*i);
        Sx_b2 += diametr[3]*section->b*(param_sect->Hsect - section->h2 - space[3] - step[3]*i);
      }
    }
    Izz = A1*section->h1*section->h1/12 + A1*(Zct - section->h1/2)*(Zct - section->h1/2)+
          A2*section->h2*section->h2/12 + A2*(param_sect->Hsect - section->h2/2 - Zct)*
                                             (param_sect->Hsect - section->h2/2 - Zct)+
          Izz_b1 + Izz_b2;
    //--------------------------------------------------------
    // Момент инерции относительно оси Y
    if (space[0]==0 || step[0]==0) {
      Iyy_a1 = A1*section->b1*section->b1/4;
    }
    else {
      Iyy_a1 = 0;
      for (i=0; i<num_hole[0]/2; i++) {
        Iyy_a1 += 2*diametr[0]*section->h1*(space[0] + step[0]*i)*(space[0] + step[0]*i);
      }
    }
    if (space[1]==0 || step[1]==0) {
      Iyy_a2 = A2*section->b2*section->b2/4;
    }
    else {
      Iyy_a2 = 0;
      for (i=0; i<num_hole[1]/2; i++) {
        Iyy_a2 += 2*diametr[1]*section->h1*(space[1] + step[1]*i)*(space[1] + step[1]*i);
      }
    }
    Iyy = (diametr[2]*num_hole[2] + diametr[2]*num_hole[2])*section->b*section->b*section->b/12 +
           Iyy_a1 + Iyy_a2;

    Zp = Zct - section->h1/2;

    Sx[0] =  A1*(param_sect->Zct - section->h1/2) + Sx_b1;
    Sx[1] =  A1*(param_sect->Zct - section->h1/2);
    Sx[2] =  A2*(section->h + section->h1 + section->h2/2 - param_sect->Zct);

    param_sect->Ar -= Ar;
    param_sect->Zct = Zct;
    param_sect->Zp = Zp;
    param_sect->Sx[0] -= Sx[0];
    param_sect->Sx[1] -= Sx[1];
    param_sect->Sx[2] -= Sx[2];
    param_sect->Izz -= Izz;
    param_sect->Iyy -= Izz;
}
//-----------------------------------------------------------
// Вычислить геометрические параметры сечения
void Get_param_sect_comm(int type, COMMON_SECT* section, GEOM_PARAM_SECT *param_sect) {
   double h_i, b_i;
   double d_o, d_i;
   double c_kr, h_kr, b_kr, hs, bs, beta;
   COMMON_SECT section_tube;
   double stat_mom;
   double * ParamProfil;

   param_sect->Iyz = 0.0;
   param_sect->Rad = 0;
   switch (type) {
   case DVUTAVR:  //
      Get_param_sect(&(section->dvutavr), param_sect);
   break;
   case RECTANCULAR: // прямоугольник
      param_sect->index_orient = section->rect.index_orient;
      param_sect->Ar = section->rect.b*section->rect.h;
      param_sect->Hsect = section->rect.h;
      param_sect->Wsect = section->rect.b;
      param_sect->Zct = section->rect.h/2;
      param_sect->Yct = section->rect.b/2;
      param_sect->Izz = section->rect.b*section->rect.h*section->rect.h*section->rect.h/12;
      param_sect->Iyy = section->rect.b*section->rect.b*section->rect.b*section->rect.h/12;
      param_sect->Hp = param_sect->Hsect;
      param_sect->Zp = param_sect->Zct;
      if (section->rect.h < section->rect.b) {
         hs=section->rect.h;
         bs=section->rect.b;
      }
      else {
         hs=section->rect.b;
         bs=section->rect.h;
      }
      beta = 0.141*pow(hs/bs, 0.25 + bs/hs);  // аппроксимация beta, Справочник металлиса, стр. 82
      param_sect->Itor = beta * hs*bs*bs*bs;
      param_sect->ky = param_sect->kz = 5/6;  // приближенно
      param_sect->point_stress[0][0] = -section->rect.h/2;
      param_sect->point_stress[0][1] = section->rect.b/2;
      param_sect->point_stress[1][0] = param_sect->point_stress[0][0];
      param_sect->point_stress[1][1] = -param_sect->point_stress[0][1];
      param_sect->point_stress[2][0] = section->rect.h/2;
      param_sect->point_stress[2][1] = -section->rect.b/2;
      param_sect->point_stress[3][0] = param_sect->point_stress[2][0];
      param_sect->point_stress[3][1] = -param_sect->point_stress[02][1];

   break;
   case SQUARE_TUBE:  // труба квадратного сечения
    section_tube.rect.b = section->square.side;
    section_tube.rect.h = section->square.side;
    section_tube.rect.b1 = section->square.thickness;
    section_tube.rect.h1 = section->square.thickness;
    section_tube.rect.n_group = section->square.n_group;
    section_tube.rect.n_profil = section->square.n_profil;
    section_tube.rect.flag_concl = section->square.flag_concl;
    // Повторяет case RECT_TUBE, кроме StandartProfil.SetProfil_Tube(typeSQUARE);
    param_sect->Rad = 0;
    h_i = section_tube.rect.h - 2*section_tube.rect.h1;
    b_i = section_tube.rect.b - 2*section_tube.rect.b1;
    h_kr = section_tube.rect.h - section_tube.rect.h1;
    b_kr = section_tube.rect.b - section_tube.rect.b1;
    if (section_tube.rect.n_group <0) { // Сварное сечение
      param_sect->Ar = section_tube.rect.b*section_tube.rect.h - b_i*h_i;
      param_sect->Hsect = section_tube.rect.h;
      param_sect->Wsect = section_tube.rect.b;
      param_sect->Zct = section_tube.rect.h/2;
      param_sect->Yct = section_tube.rect.b/2;
      param_sect->Izz = section_tube.rect.b*section_tube.rect.h*section_tube.rect.h*section_tube.rect.h/12 -
                        b_i*h_i*h_i*h_i/12;
      param_sect->Iyy = section_tube.rect.b*section_tube.rect.b*section_tube.rect.b*section_tube.rect.h/12 -
                        b_i*b_i*b_i*h_i/12;
   }
   else {
	// StandartProfil.SetProfil_Tube(typeSQUARE);
	// ParamProfil = StandartProfil.GetVectorParamProfil_Tube(section_tube.rect.n_group, section_tube.rect.n_profil);
     if (ParamProfil == NULL) {
	  #ifdef EMBRAC
	   int rc = Application->MessageBox(L"Get_param_sect_comm:Программная ошибка. Номер группы и/или номер профиля неверны",
			   L"Вычисление геометрических параметров сечения ", MB_OK | MB_ICONERROR);
	  #else
	   int rc = Application->MessageBox("Get_param_sect_comm:Программная ошибка. Номер группы и/или номер профиля неверны",
			   "Вычисление геометрических параметров сечения ", MB_OK | MB_ICONERROR);
	  #endif
	   return;
     }

     param_sect->Ar = ParamProfil[parAREA_SQUARE_TUBE];
     param_sect->Hsect = ParamProfil[parBSECT];
     param_sect->Wsect = ParamProfil[parHSECT];
     param_sect->Izz = ParamProfil[parIYY_SQUARE_TUBE];
     param_sect->Iyy = ParamProfil[parIYY_SQUARE_TUBE];
     param_sect->Zct = param_sect->Hsect/2;
     param_sect->Yct = param_sect->Wsect/2;
     param_sect->Iyz = 0.0;
     param_sect->Rad = ParamProfil[parR_SQUARE_TUBE];

   }
   param_sect->Hp = param_sect->Hsect - section_tube.rect.b1;
   param_sect->Zp = param_sect->Zct - section_tube.rect.b1/2 ;

   param_sect->Itor = 2*h_kr*b_kr*(h_kr+h_i)*(h_kr+h_i)*(b_kr+b_i)*(b_kr+b_i)/
                     ((h_kr+h_i)*h_kr + (b_kr+b_i)*b_kr);
   param_sect->ky = section_tube.rect.h*section_tube.rect.b1*2/param_sect->Ar;
   param_sect->kz = section_tube.rect.b*section_tube.rect.h1*2/param_sect->Ar;

   param_sect->point_stress[0][0] = -section_tube.rect.h/2;
   param_sect->point_stress[0][1] = -section_tube.rect.b/2;
   param_sect->point_stress[1][0] = param_sect->point_stress[0][0];
   param_sect->point_stress[1][1] = -param_sect->point_stress[0][1];
   param_sect->point_stress[2][0] = section_tube.rect.h/2;
   param_sect->point_stress[2][1] = -section_tube.rect.b/2;
   param_sect->point_stress[3][0] = param_sect->point_stress[2][0];
   param_sect->point_stress[3][1] = -param_sect->point_stress[2][1];
   // координаты Z точек вычисчления касательных напряжений (относительно ц.т)
   param_sect->z_tau[2] = 0;
   param_sect->z_tau[0] = param_sect->Zct - section_tube.rect.b1;
   param_sect->z_tau[1] = -param_sect->z_tau[0];
   // Статический момент относительно оси Z для вычисления касательных в стенке трубы
   param_sect->Sx[0] = Round(section_tube.rect.b*section_tube.rect.b1*(param_sect->Zct - section_tube.rect.b1/2) +
                        0.5*(param_sect->Zct - section_tube.rect.b1)*(param_sect->Zct - section_tube.rect.b1)*2*section_tube.rect.h1, 0); // точка в ц.т.
   param_sect->Sx[1] = Round(section_tube.rect.b*section_tube.rect.b1*(param_sect->Zct - section_tube.rect.b1/2), 0); // точка на стенке в стыке с внешним поясом
   param_sect->Sx[2] = param_sect->Sx[1]; // точка на стенке в стыке с внутренним поясом
        // Статические моменты для вычисления касательных в стенке трубы
   param_sect->Sy[0] = Round(section_tube.rect.h*section_tube.rect.h1*(param_sect->Yct - section_tube.rect.h1/2) +
                       0.5*(param_sect->Yct - section_tube.rect.h1)*(param_sect->Yct - section_tube.rect.h1)*2*section_tube.rect.b1, 0); // точка в ц.т.
   param_sect->Sy[1] = Round(section_tube.rect.h*section_tube.rect.h1*(param_sect->Yct - section_tube.rect.h1/2), 0); // точка на стенке в стыке с внешним поясом
   param_sect->Sy[2] = param_sect->Sy[1];
   param_sect->index_orient = section->square.index_orient;
   break;
   case RECT_TUBE:  // труба прямоугольного сечения

    // Повторяется в case RECT_SQUARE, кроме StandartProfil.SetProfil_Tube(typeRECT);
    param_sect->index_orient = section->rect.index_orient;
    param_sect->Rad = 0;
    h_i = section->rect.h - 2*section->rect.h1;
    b_i = section->rect.b - 2*section->rect.b1;
    h_kr = section->rect.h - section->rect.h1;
    b_kr = section->rect.b - section->rect.b1;
    if (section->rect.n_group <0) { // Сварное сечение
      param_sect->Ar = section->rect.b*section->rect.h - b_i*h_i;
      param_sect->Hsect = section->rect.h;
      param_sect->Wsect = section->rect.b;
      param_sect->Zct = section->rect.h/2;
      param_sect->Yct = section->rect.b/2;
      param_sect->Izz = section->rect.b*section->rect.h*section->rect.h*section->rect.h/12 -
                        b_i*h_i*h_i*h_i/12;
      param_sect->Iyy = section->rect.b*section->rect.b*section->rect.b*section->rect.h/12 -
                        b_i*b_i*b_i*h_i/12;
    }
    else {
	 // StandartProfil.SetProfil_Tube(typeRECT);
	 // ParamProfil = StandartProfil.GetVectorParamProfil_Tube(section->rect.n_group, section->rect.n_profil);
	  if (ParamProfil == NULL) {
	  #ifdef EMBRAC
		int rc = Application->MessageBox(L"Get_param_sect_comm:Программная ошибка. Номер группы и/или номер профиля неверны",
			   L"Вычисление геометрических параметров сечения ", MB_OK | MB_ICONERROR);
	  #else
		int rc = Application->MessageBox("Get_param_sect_comm:Программная ошибка. Номер группы и/или номер профиля неверны",
			   "Вычисление геометрических параметров сечения ", MB_OK | MB_ICONERROR);
	  #endif
		return;
      }

      param_sect->Ar = ParamProfil[parAREA_RECT_TUBE];
      if (section->rect.index_orient == 0) {
        param_sect->Hsect = ParamProfil[parHSECT];
        param_sect->Wsect = ParamProfil[parBSECT];
        param_sect->Izz = ParamProfil[parIZZ_RECT_TUBE];
        param_sect->Iyy = ParamProfil[parIYY_RECT_TUBE];
      }
      else {
        param_sect->Hsect = ParamProfil[parBSECT];
        param_sect->Wsect = ParamProfil[parHSECT];
        param_sect->Izz = ParamProfil[parIYY_RECT_TUBE];
        param_sect->Iyy = ParamProfil[parIZZ_RECT_TUBE];
      }
      param_sect->Zct = param_sect->Hsect/2;
      param_sect->Yct = param_sect->Wsect/2;
      param_sect->Iyz = 0.0;
      param_sect->Rad = ParamProfil[parR_RECT_TUBE];

    }
    param_sect->Hp = param_sect->Hsect - section->rect.b1;
    param_sect->Zp = param_sect->Zct - section->rect.b1/2 ;

    param_sect->Itor = 2*h_kr*b_kr*(h_kr+h_i)*(h_kr+h_i)*(b_kr+b_i)*(b_kr+b_i)/
                     ((h_kr+h_i)*h_kr + (b_kr+b_i)*b_kr);
    param_sect->ky = section->rect.h*section->rect.b1*2/param_sect->Ar;
    param_sect->kz = section->rect.b*section->rect.h1*2/param_sect->Ar;

    param_sect->point_stress[0][0] = -section->rect.h/2;
    param_sect->point_stress[0][1] = -section->rect.b/2;
    param_sect->point_stress[1][0] = param_sect->point_stress[0][0];
    param_sect->point_stress[1][1] = -param_sect->point_stress[0][1];
    param_sect->point_stress[2][0] = section->rect.h/2;
    param_sect->point_stress[2][1] = -section->rect.b/2;
    param_sect->point_stress[3][0] = param_sect->point_stress[2][0];
    param_sect->point_stress[3][1] = -param_sect->point_stress[2][1];
   // координаты Z точек вычисчления касательных напряжений (относительно ц.т)
    param_sect->z_tau[2] = 0;
    param_sect->z_tau[0] = param_sect->Zct - section->rect.b1;
    param_sect->z_tau[1] = -param_sect->z_tau[0];
   // Статический момент относительно оси Z для вычисления касательных в стенке трубы
    param_sect->Sx[0] = Round(section->rect.b*section->rect.b1*(param_sect->Zct - section->rect.b1/2) +
                        0.5*(param_sect->Zct - section->rect.b1)*(param_sect->Zct - section->rect.b1)*2*section->rect.h1, 0); // точка в ц.т.
    param_sect->Sx[1] = Round(section->rect.b*section->rect.b1*(param_sect->Zct - section->rect.b1/2), 0); // точка на стенке в стыке с внешним поясом
    param_sect->Sx[2] = param_sect->Sx[1]; // точка на стенке в стыке с внутренним поясом
        // Статические моменты для вычисления касательных в стенке трубы
    param_sect->Sy[0] = Round(section->rect.h*section->rect.h1*(param_sect->Yct - section->rect.h1/2) +
                       0.5*(param_sect->Yct - section->rect.h1)*(param_sect->Yct - section->rect.h1)*2*section->rect.b1, 0); // точка в ц.т.
    param_sect->Sy[1] = Round(section->rect.h*section->rect.h1*(param_sect->Yct - section->rect.h1/2), 0); // точка на стенке в стыке с внешним поясом
    param_sect->Sy[2] = param_sect->Sy[1];

   break;
   case CIRCULAR_TUBE:  // труба круглого сечения
    if (section->rect.n_group <0) { // Сварное сечение
      d_i = section->circ.diameter - 2*section->circ.thickness;
      c_kr = d_i/section->circ.diameter;
      param_sect->index_orient = 0;
      param_sect->Ar = PI_2*(section->circ.diameter*section->circ.diameter - d_i*d_i)/2;
      param_sect->Hsect = section->circ.diameter;
      param_sect->Wsect = section->circ.diameter;
      param_sect->Zct = section->circ.diameter/2;
      param_sect->Yct = section->circ.diameter/2;
      param_sect->Iyy = PI_2*(section->circ.diameter*section->circ.diameter*section->circ.diameter*section->circ.diameter -
                              d_i*d_i*d_i*d_i)/32;
      param_sect->Izz = param_sect->Iyy;
      param_sect->Hp = param_sect->Hsect;
    }
    else {
	 // StandartProfil.SetProfil_Tube(typeCIRC);
	 // ParamProfil = StandartProfil.GetVectorParamProfil_Tube(section->circ.n_group, section->circ.n_profil);
	  if (ParamProfil == NULL) {
	  #ifdef EMBRAC
		int rc = Application->MessageBox(L"Get_param_sect_comm:Программная ошибка. Номер группы и/или номер профиля неверны",
			   L"Вычисление геометрических параметров сечения ", MB_OK | MB_ICONERROR);
	  #else
		int rc = Application->MessageBox("Get_param_sect_comm:Программная ошибка. Номер группы и/или номер профиля неверны",
			   "Вычисление геометрических параметров сечения ", MB_OK | MB_ICONERROR);
	  #endif
		return;
      }

      param_sect->Ar = ParamProfil[parAREA_CIRC_TUBE];
      param_sect->Hsect = ParamProfil[parHSECT];
      param_sect->Wsect = ParamProfil[parHSECT];
      param_sect->Izz = ParamProfil[parIYY_CIRC_TUBE];
      param_sect->Iyy = ParamProfil[parIYY_CIRC_TUBE];
      param_sect->Zct = param_sect->Hsect/2;
      param_sect->Yct = param_sect->Wsect/2;
      param_sect->Iyz = 0.0;
      param_sect->Rad = 0;

    }
    param_sect->Zp = param_sect->Zct;
    param_sect->Itor = PI_2*section->circ.diameter*section->circ.diameter*section->circ.diameter*section->circ.diameter*
                               (1-c_kr*c_kr*c_kr*c_kr)/16;
    param_sect->ky = param_sect->kz = 0.533;  // приближенно
    param_sect->point_stress[0][0] = -section->circ.diameter/2;
    param_sect->point_stress[0][1] = 0;
    param_sect->point_stress[1][0] = 0;
    param_sect->point_stress[1][1] = section->circ.diameter/2;
    param_sect->point_stress[2][0] = section->circ.diameter/2;
    param_sect->point_stress[2][1] = 0;
    param_sect->point_stress[3][0] = 0;
    param_sect->point_stress[3][1] = -section->circ.diameter/2;

   break;
   default:
      param_sect->Ar = 0;
      param_sect->Hsect = 0;
      param_sect->Zct = 0;
      param_sect->Iyy = 0;
      param_sect->Izz = 0;
      param_sect->Hp = param_sect->Hsect;
      param_sect->Zp = param_sect->Zct;
      param_sect->Itor = 0;
      param_sect->ky = param_sect->kz = 0;
      param_sect->point_stress[0][0] = 0;
      param_sect->point_stress[0][1] = 0;
      param_sect->point_stress[1][0] = 0;
      param_sect->point_stress[1][1] = 0;
      param_sect->point_stress[2][0] = 0;
      param_sect->point_stress[2][1] = 0;
      param_sect->point_stress[3][0] = 0;
      param_sect->point_stress[3][1] = 0;
      //ErrorMessage("Для сечения типа " +IntToStr(type)+" геометрические характеристики не вычисляются");
   }
   param_sect->Ar = Round(param_sect->Ar, 0);
   param_sect->Itor = Round(param_sect->Itor, 0);
   param_sect->Izz = Round(param_sect->Izz, 0);
   param_sect->Iyy = Round(param_sect->Iyy, 0);
   param_sect->Itor = Round(param_sect->Itor, 0);

}
//--------------------------------------------------------------------
// Преобразовать жесткости Рипак к параметрам обобщенного сечения Гепард. Для двутавра: index_sect - 0/1/2 - в наччале/в конце/в середине элемента
int  StiffBeamToCommSect(double *gt, COMMON_SECT *sect_comm, int *type_sect, int index_sect, double *h_sten) {
    int k, rc;
    if (gt[0]>0) {
      *type_sect = -1;
      sect_comm->dvutavr.b = 0;
      sect_comm->dvutavr.b1 = 0;
      sect_comm->dvutavr.h = 0;
      sect_comm->dvutavr.h1 = 0;
      sect_comm->dvutavr.b2 = 0;
      sect_comm->dvutavr.h2 = 0;
      return -1;  // не параметрическое сечение
    }

    k = - gt[0];
    switch (k) {
            case RECTANCULAR:  // прямоугольник
              sect_comm->rect.b = gt[1];
              sect_comm->rect.h = gt[2];
              sect_comm->rect.b1 = gt[1]/2;
              sect_comm->rect.h1 = gt[2]/2;
              sect_comm->rect.index_orient = gt[9];
              sect_comm->rect.flag_concl = true;
              h_sten[0] = h_sten[1] = h_sten[2] = gt[1];
              *type_sect = k;
            break;
            case DVUTAVR:  // двутавр
            //case DVUTAVR_XY:  // двутавр
              sect_comm->dvutavr.b = gt[1];
              sect_comm->dvutavr.b1 = gt[5];
              sect_comm->dvutavr.h1 = gt[6];
              sect_comm->dvutavr.b2 = gt[3];
              sect_comm->dvutavr.h2 = gt[4];
              h_sten[0] = Round(gt[7] - gt[4] - gt[6], 1);  // в узле 1
              h_sten[1] = Round(gt[2] - gt[4] - gt[6], 1);  // Среднее
              h_sten[2] = Round(gt[8] - gt[4] - gt[6], 1);  // в узле 2;
              switch (index_sect) {
              case 0:
                sect_comm->dvutavr.h =  Round(gt[7] - gt[4] - gt[6], 1);  // в узле 1
              break;
              case 1:
                sect_comm->dvutavr.h =  Round(gt[8] - gt[4] - gt[6], 1);  // в узле 2
              break;
              case 2:
                sect_comm->dvutavr.h =  Round(gt[2] - gt[4] - gt[6], 1);  // Среднее
              break;
              }
              if (gt[10]==0) {
                sect_comm->dvutavr.n_group = -1;
                sect_comm->dvutavr.n_profil = -1;
              }
              else {
				sect_comm->dvutavr.n_group = floor((int)(gt[10])/100.0) - 1;
                sect_comm->dvutavr.n_profil = (int)(gt[10])%100;
              }
              if (k==DVUTAVR)
                 sect_comm->dvutavr.index_orient = 0;
              else
                 sect_comm->dvutavr.index_orient = 1;

              sect_comm->dvutavr.flag_concl = true;
              *type_sect = k;
            break;
            case SQUARE_TUBE:
              sect_comm->square.side = gt[1];
              sect_comm->square.thickness = gt[2];
              if (gt[10]==0) {
                sect_comm->square.n_group = -1;
                sect_comm->square.n_profil = -1;
              }
              else {
				sect_comm->square.n_group = floor((int)(gt[10])/100.0) - 1;
                sect_comm->square.n_profil = (int)(gt[10])%100;
              }
              sect_comm->square.index_orient = 0;
              sect_comm->square.flag_concl = true;
              h_sten[0] = h_sten[1] = h_sten[2] = gt[1];
              *type_sect = k;
            break;
            case RECT_TUBE:  // труба прямоугольного сечения
              sect_comm->rect.b = gt[1];
              sect_comm->rect.h = gt[2];
              sect_comm->rect.b1 = gt[3];
              sect_comm->rect.h1 = gt[4];
              if (gt[10]==0) {
                sect_comm->rect.n_group = -1;
                sect_comm->rect.n_profil = -1;
              }
              else {
				sect_comm->rect.n_group = floor((int)(gt[10])/100.0) - 1;
                sect_comm->rect.n_profil = (int)(gt[10])%100;
                sect_comm->rect.index_orient = gt[9];
              }
              sect_comm->rect.flag_concl = true;
              h_sten[0] = h_sten[1] = h_sten[2] = gt[1];
              *type_sect = k;
            break;
            case CIRCULAR_TUBE:  // труба круглого сечения
              sect_comm->circ.diameter = gt[1];
              sect_comm->circ.thickness = gt[2];
              if (gt[10]==0) {
                sect_comm->circ.n_group = -1;
                sect_comm->circ.n_profil = -1;
              }
              else {
                sect_comm->circ.n_group = floor((int)(gt[10])/100.0) - 1;
                sect_comm->circ.n_profil = (int)(gt[10])%100;
              }
              sect_comm->circ.index_orient = 0;
              sect_comm->circ.flag_concl = true;
              h_sten[0] = h_sten[1] = h_sten[2] = gt[1];
              *type_sect = k;
            break;
            default:
              return 1;
           }

           return 0;
}
//--------------------------------------------------------------------
// Вычислить параметры сечения beam Рипак в середине элемента
int  Get_param_beam(double *gt, GEOM_PARAM_SECT *param_sect) {
    int type_sect, rc;
    COMMON_SECT  sect_c;
    double h_sten[3];

      // Преобразовать жесткости Рипак к параметрам обобщенного сечения Гепард
      rc = StiffBeamToCommSect(gt, &sect_c, &type_sect, 2, h_sten);
      if (rc > 0)
        return rc;
      if (rc == -1) {
        param_sect->Ar = gt[0];
        param_sect->Izz = gt[1];
        param_sect->Iyy = gt[2];
        param_sect->Iyz = gt[3];
        param_sect->Itor = gt[4];
        param_sect->ky = 0;
        param_sect->kz = 0;
        param_sect->Hsect = 1;
        param_sect->Wsect = 1;
        param_sect->Zct = 0.5;
        param_sect->Yct = 0.5;
      }
      else
        Get_param_sect_comm(type_sect, &(sect_c), param_sect);

      return 0;
}
//-----------------------------------------------------------
// Вычислить параметры напряженного состояния приведенного двутаврового сечения с округлением момента инерции сечения до (-4) знаков
void Get_stress(double Mz, double N,  SECT_DVUTAVR *sect_dv, STRESS_PARAM_SECT *stress_sect,
                double H_sect, double y1_min, double y2_max) {
// H_sect - расстояние от верхней точки до нижней, в которой нужно вычислять напряжение
   GEOM_PARAM_SECT param_sect;

   Get_param_sect(sect_dv, &(param_sect));
   param_sect.Izz = Round(param_sect.Izz, -4);

   stress_sect->sigma_ext = -Mz*param_sect.Zct/param_sect.Izz + N/param_sect.Ar;
   stress_sect->sigma_w_ext = -Mz*(param_sect.Zct - y1_min)/param_sect.Izz + N/param_sect.Ar;
   stress_sect->sigma_int =  Mz*(H_sect - param_sect.Zct)/param_sect.Izz + N/param_sect.Ar;
   stress_sect->sigma_w_int =  Mz*(y2_max - param_sect.Zct)/param_sect.Izz + N/param_sect.Ar;
   stress_sect->sigma_ct = N/param_sect.Ar;
   stress_sect->z0 = stress_sect->sigma_ext*H_sect/(stress_sect->sigma_ext - stress_sect->sigma_int);
   stress_sect->Zct = param_sect.Zct;
   stress_sect->Hsect = H_sect;

   stress_sect->sigma_ext = Round(stress_sect->sigma_ext, 1);
   stress_sect->sigma_w_ext = Round(stress_sect->sigma_w_ext, 1);
   stress_sect->sigma_int =  Round(stress_sect->sigma_int, 1);
   stress_sect->sigma_w_int =  Round(stress_sect->sigma_w_int, 1);
   stress_sect->sigma_ct = Round(stress_sect->sigma_ct, 1);;
   stress_sect->z0 = Round(stress_sect->z0, 1);
   stress_sect->Hsect = Round(stress_sect->Hsect, 0);

}
//-----------------------------------------------------------
// Вычислить параметры напряженного состояния приведенного двутаврового сечения с округлением момента инерции сечения до (-4) знаков
void Get_stress_param(double Mz, double N,  GEOM_PARAM_SECT param_sect, STRESS_PARAM_SECT *stress_sect,
                double H_sect, double y1_min, double y2_max) {
// H_sect - расстояние от верхней точки до нижней, в которой нужно вычислять напряжение

   param_sect.Izz = Round(param_sect.Izz, -4);

   stress_sect->sigma_ext = -Mz*param_sect.Zct/param_sect.Izz + N/param_sect.Ar;
   stress_sect->sigma_w_ext = -Mz*(param_sect.Zct - y1_min)/param_sect.Izz + N/param_sect.Ar;
   stress_sect->sigma_int =  Mz*(H_sect - param_sect.Zct)/param_sect.Izz + N/param_sect.Ar;
   stress_sect->sigma_w_int =  Mz*(y2_max - param_sect.Zct)/param_sect.Izz + N/param_sect.Ar;
   stress_sect->sigma_ct = N/param_sect.Ar;
   stress_sect->z0 = stress_sect->sigma_ext*H_sect/(stress_sect->sigma_ext - stress_sect->sigma_int);
   stress_sect->Zct = param_sect.Zct;
   stress_sect->Hsect = H_sect;

   stress_sect->sigma_ext = Round(stress_sect->sigma_ext, 1);
   stress_sect->sigma_w_ext = Round(stress_sect->sigma_w_ext, 1);
   stress_sect->sigma_int =  Round(stress_sect->sigma_int, 1);
   stress_sect->sigma_w_int =  Round(stress_sect->sigma_w_int, 1);
   stress_sect->sigma_ct = Round(stress_sect->sigma_ct, 1);;
   stress_sect->z0 = Round(stress_sect->z0, 1);
   stress_sect->Hsect = Round(stress_sect->Hsect, 0);

}
//-----------------------------------------------------------
// Вычислить параметры напряженного состояния двутаврового сечения с округлением момента инерции сечения до (-4) знаков
void Get_stress_dummy(double Mz, double N,  SECT_DVUTAVR *sect, STRESS_PARAM_SECT *stress_sect,
                double H_sect, double h1_min, double h2_min) {
// H_sect - расстояние от верхней точки до нижней, в которой нужно вычислять напряжение
   GEOM_PARAM_SECT param_sect;

   Get_param_sect(sect, &(param_sect));
   param_sect.Izz = Round(param_sect.Izz, -4);

   stress_sect->sigma_ext = -Mz*param_sect.Zct/param_sect.Izz + N/param_sect.Ar;
   stress_sect->sigma_w_ext = -Mz*(param_sect.Zct - sect->h1)/param_sect.Izz + N/param_sect.Ar;
   stress_sect->sigma_int =  Mz*(param_sect.Hsect - param_sect.Zct)/param_sect.Izz + N/param_sect.Ar;
   //stress_sect->sigma_int =  Mz*(H_sect - param_sect.Zct)/param_sect.Izz + N/param_sect.Ar;
   stress_sect->sigma_w_int =  Mz*(param_sect.Hsect - param_sect.Zct - sect->h2)/param_sect.Izz + N/param_sect.Ar;
   //stress_sect->sigma_w_int =  Mz*(H_sect - param_sect.Zct - sect->h2)/param_sect.Izz + N/param_sect.Ar;
   stress_sect->sigma_ct = N/param_sect.Ar;
   stress_sect->z0 = stress_sect->sigma_ext*param_sect.Hsect/(stress_sect->sigma_ext - stress_sect->sigma_int);
   stress_sect->Zct = param_sect.Zct;
   stress_sect->Hsect = param_sect.Hsect;

   stress_sect->sigma_ext = Round(stress_sect->sigma_ext, 1);
   stress_sect->sigma_w_ext = Round(stress_sect->sigma_w_ext, 1);
   stress_sect->sigma_int =  Round(stress_sect->sigma_int, 1);
   stress_sect->sigma_w_int =  Round(stress_sect->sigma_w_int, 1);
   stress_sect->sigma_ct = Round(stress_sect->sigma_ct, 1);;
   stress_sect->z0 = Round(stress_sect->z0, 1);
   stress_sect->Hsect = Round(stress_sect->Hsect, 0);

}

//-----------------------------------------------------------
// Вычислить координаты ц.т. сечения
void Get_coor_point(int k1, int k2, double ** point_corners, GEOM_PARAM_SECT *param_sect, double **coor,
                    int i_sect, int* num_point_corners) {
   double mult;

   if (param_sect->index_orient==0 )
     mult = param_sect->Zp/param_sect->Hp;
   else
     mult = 0.5;

   coor[i_sect][0] = point_corners[k1][0] + (point_corners[k2][0] - point_corners[k1][0])*mult;
   coor[i_sect][1] = point_corners[k1][1] + (point_corners[k2][1] - point_corners[k1][1])*mult;
   //coor[i_sect][0] = point_corners[k1][0] + (point_corners[k2][0] - point_corners[k1][0])*param_sect->Zct/param_sect->Hsect;
   //coor[i_sect][1] = point_corners[k1][1] + (point_corners[k2][1] - point_corners[k1][1])*param_sect->Zct/param_sect->Hsect;
   num_point_corners[i_sect*2]=k1;
   num_point_corners[i_sect*2+1]=k2;       //point_corners[0]
}


