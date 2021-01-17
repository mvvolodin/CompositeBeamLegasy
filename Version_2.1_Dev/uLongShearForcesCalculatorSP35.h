//---------------------------------------------------------------------------

#ifndef uLongShearForcesCalculatorSP35H
#define uLongShearForcesCalculatorSP35H

#include <vector>
#include "uIntForcesCalculator.h"
#include "uCompSectGeomSP35.h"
#include "uPiecewiseLinearFunc.h"

class LongShearForcesCalculatorSP35{
public:
	LongShearForcesCalculatorSP35() = default;
	LongShearForcesCalculatorSP35(IntForcesCalculator const & calc,
		CompSectGeomSP35 const & com_sec, double L);
	double S_Ed(double x_l, double x_r)const;
	std::vector<double> S_overline_lst()const{return S_overline_lst_;}
	std::vector<double> coord()const{return coord_;}
private:

	PiecewiseLinearFunc diag_;
	std::vector<double> S_overline_lst_;
	std::vector<double> coord_;

	PiecewiseLinearFunc build_diag(IntForcesCalculator const & calc,
		CompSectGeomSP35 const & com_sec, double L);
	double S_i(IntForcesCalculator const & calc, CompSectGeomSP35 const & com_sec,
		double x_l, double x_r) const;
};



//---------------------------------------------------------------------------
#endif
