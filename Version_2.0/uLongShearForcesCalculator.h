//---------------------------------------------------------------------------

#ifndef uLongShearForcesCalculatorH
#define uLongShearForcesCalculatorH

#include <vector>
#include "uIntForcesCalculator.h"
#include "uComposSectGeomSP35.h"
#include "uPiecewiseLinearFunc.h"

class LongShearForcesCalculator{
public:
	LongShearForcesCalculator() = default;
	LongShearForcesCalculator(IntForcesCalculator const & calc,
							  ComposSectGeomSP35 const & com_sec,
							  double L);
	double S_Ed(double x_l, double x_r)const;
	std::vector<double> S_overline_lst()const{return S_overline_lst_;}
	std::vector<double> coord()const{return coord_;}
private:

	PiecewiseLinearFunc diag_;
	std::vector<double> S_overline_lst_;
	std::vector<double> coord_;

	PiecewiseLinearFunc build_diag(IntForcesCalculator const & calc,
		ComposSectGeomSP35 const & com_sec, double L);
	double S_i(IntForcesCalculator const & calc,
	ComposSectGeomSP35 const & com_sec, double x_l, double x_r) const;
};



//---------------------------------------------------------------------------
#endif
