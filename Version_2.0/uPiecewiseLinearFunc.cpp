//---------------------------------------------------------------------------

#pragma hdrstop

#include "uPiecewiseLinearFunc.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
PiecewiseLinearFunc::PiecewiseLinearFunc (
	std::map< std::pair<double,double>,  LinearFunc> const   & fns):fns_(fns){}

double PiecewiseLinearFunc::operator()( double x )const
{
	auto iter = std::find_if(fns_.cbegin(), fns_.cend(),
					[=](const std::pair< std::pair<double,double>, LinearFunc>& fn)
					{
						return x>=fn.first.first &&  x<fn.first.second;
					});

//	   if (iter == fns.end()) throw... //Or something
   return iter -> second(x);
}
double PiecewiseLinearFunc::integral(double xl, double xr)const
{
	double sum = 0.;

	for (double dx = 1., x = xl + dx / 2; x < xr; x += dx)
		sum += (*this)(x) * dx;

	return sum;
}



