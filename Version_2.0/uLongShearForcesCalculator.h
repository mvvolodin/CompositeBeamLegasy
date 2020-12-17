//---------------------------------------------------------------------------

#ifndef uLongShearForcesCalculatorH
#define uLongShearForcesCalculatorH

#include <vector>
#include "uIntForcesCalculator.h"
#include "uComposSectGeomSP35.h"

class LongShearForcesCalculator{
public:
	LongShearForcesCalculator() = delete;
	LongShearForcesCalculator(IntForcesCalculator const & calc,
							  ComposSectGeomSP35 const & com_sec,
							  double h, double b_s, double L);
	double run(double x_l, double x_r)const;
private:

	std::vector<double> diag_;

	std::vector<double> build_diag(IntForcesCalculator const & calc,
		ComposSectGeomSP35 const & com_sec, double h, double b_sl, double L);
	double S_i(IntForcesCalculator const & calc,
	ComposSectGeomSP35 const & com_sec, double x_l, double x_r) const;
};



//---------------------------------------------------------------------------
#endif
