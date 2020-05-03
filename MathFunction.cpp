//---------------------------------------------------------------------------

#pragma hdrstop

#include "MathFunction.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

 double clamp( double v, double lo, double hi )
{
	return (v < lo) ? lo : (hi < v) ? hi : v;
}

double linear_interpolation(double y_0, double y_1, double x_0, double x_1, double x_n)
{
  return y_0 + (y_1 - y_0) / (x_1 - x_0) * (x_n - x_0);

}

