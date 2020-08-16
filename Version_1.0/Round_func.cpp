#include <stdio.h>
#include <math.h>
#include <vcl.h>

#include "ListConst.h"

//---------------------------------------------------------------------------
double Round(double value, int n_sign) {
  double i, j;
  double x1, x2, xr, mult;

  mult = pow(10.0, n_sign);
  xr = value*mult;
  i=floor(xr);
  j=ceil(xr);
  x1=xr-i;
  x2=j-xr;
  if (x1<x2) return (double)i/mult;
  else return (double)j/mult;
}
//---------------------------------------------------------------------------
double Round_plus(double value, int n_sign) {
  int j;
  double mult, xr;

  mult = pow(10.0, n_sign);
  xr = value*mult;
  j=ceil(xr);
  return (double)j/mult;
}
//---------------------------------------------------------------------------
// округление по шагу в большую сторону
double Round_step(double value, double step) {
  int v1, s1, i1;
  double v2;

  /*
  v1 = ceil(value);
  s1 = step;
  i1 = v1%s1;
  if (i1>0)
     v2 = v1 - i1 + s1;
  else
     v2 = v1;
  */
  if (step < 1.0) {
    v2 = value;
  }
  v1 = ceil(value/step);
  v2 = v1*step;

  return v2;
}
//---------------------------------------------------------------------------
// округление по шагу в меньшую сторону
double Round_step_floor(double value, double step) {
  int v1;
  double v2;

  v1 = floor(value/step);
  v2 = v1*step;
  return v2;
}
double atand(double x, double y) {
double fi;
  if (ABS(y)<1e-10){
     if (y<0   ) fi=-90;
     else fi=90;
  }
  else
     fi = atan(x/y)*RADIAN;
  return fi;
}
