//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "Constants.h"
#include "GArrow.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)

void  TArrow::PutArrow(TPoint * Ax_c, float Signature,
                                      int MaxPic0)
{
  Ax0=Ax_c[0].x;
  Ay0=Ax_c[0].y;
  Ax1=Ax_c[1].x;
  Ay1=Ax_c[1].y;
  Sign=Signature;
  MaxPic=MaxPic0;
}

void  TArrow::SetArrow()
{
      double  Len, LenA, beta;
	  int  Dx0, Dy0, Dx3, Dy3, Pic1, Pic2;

	  double atand(double x, double y);  //Декларация функции реализованной в "Round_func.cpp"

	  Len=sqrt(((float)Ax1-Ax0)*(Ax1-Ax0)+(Ay1-Ay0)*(Ay1-Ay0));
	  beta = (atand(Ay1-Ay0, Ax1-Ax0))/RADIAN;
	  LArrow[0]=Point(Ax0, Ay0);
	  LArrow[1]=Point(Ax1, Ay1);
	  LArrow[2]=Point(Ax0, Ay0);
      Pic1=MIN(MaxPic,Len);

      Dx3=Pic1*0.3*cos(beta+PI_2);
      Dy3=Pic1*0.3*sin(beta+PI_2);
      LenA = Len - Pic1;
      if ((ABS(Len))>1e-3) {
         Dx0=(Ax1 - Ax0)*LenA/Len;
         Dy0=(Ay1 - Ay0)*LenA/Len;
	  }
	  else  Dx0=Dy0=0;

      Ar[0]=Point(Ax0+Dx0+Dx3, Ay0+Dy0+Dy3);
      Ar[1]=Point(Ax1, Ay1);
      Ar[2]=Point(Ax0+Dx0-Dx3, Ay0+Dy0-Dy3);
      Ar[3]=Ar[0];
}
