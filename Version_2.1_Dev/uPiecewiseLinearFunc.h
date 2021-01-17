//---------------------------------------------------------------------------
#ifndef uPiecewiseLinearFuncH
#define uPiecewiseLinearFuncH
//---------------------------------------------------------------------------
#include <map>
#include "uLinearFunc.h"
//---------------------------------------------------------------------------

class PiecewiseLinearFunc{
public:
	PiecewiseLinearFunc () = default;
	PiecewiseLinearFunc & operator = (const PiecewiseLinearFunc & ) = default;
	PiecewiseLinearFunc (std::map< std::pair<double,double>,  LinearFunc> const  & fns);
	double operator()( double x )const;
	double integral(double xl, double xr)const;
private:

	std::map<std::pair<double,double>,  LinearFunc> fns_;
};
//---------------------------------------------------------------------------
#endif
