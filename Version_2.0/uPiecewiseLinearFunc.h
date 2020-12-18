//---------------------------------------------------------------------------
#ifndef uPiecewiseLinearFuncH
#define uPiecewiseLinearFuncH
//---------------------------------------------------------------------------
#include <map>
#include "uLinearFunc.h"
//---------------------------------------------------------------------------

class PiecewiseLinearFunc{
public:
	PiecewiseLinearFunc () = delete;
	PiecewiseLinearFunc (std::map< std::pair<double,double>,  LinearFunc > & fns);
	double operator()( double x );
private:

	std::map< std::pair<double,double>,  LinearFunc > fns_;
};
//---------------------------------------------------------------------------
#endif
