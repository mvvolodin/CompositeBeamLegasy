//---------------------------------------------------------------------------

#pragma hdrstop

#include "MathFunction.h"
#include <string>

//---------------------------------------------------------------------------
#pragma package(smart_init)

 double clamp( double v, double lo, double hi )
{
	return (v < lo) ? lo : (hi < v) ? hi : v;
}

double linear_interpolation(double y_0, double y_1, double x_0, double x_1, double x_n)
{
	const double EPSILON = 1.0e-8;
	if(std::abs(y_0 - y_1) <= EPSILON)
	{
		std::string err{"Расстояние между точками для интерполяции слишком мало <= 1.0e-8 "};
		throw std::range_error(err);
	}

	return y_0 + (y_1 - y_0) / (x_1 - x_0) * (x_n - x_0);
}

