//---------------------------------------------------------------------------
#ifndef uInternalForcesCalculatorH
#define uInternalForcesCalculatorH
//---------------------------------------------------------------------------

#include <map>
#include "uLoads.h"
#include "uGeometry.h"

 //---------------------------------------------------------------------------

class InternalForcesCalculator
{
public:
	InternalForcesCalculator();
	InternalForcesCalculator(const SupportsNumber 	 s_num,
							 const double 			 L,
							 const TLoads 			 loads);

	std::map<double, double> R_Ia_design()const;
	std::map<double, double> R_Ib_design()const;
	std::map<double, double> R_IIa_design()const;
	std::map<double, double> R_IIb_design()const;
	std::map<double, double> R_total_design()const;

	double M_Ia_design(double x)const;
	double M_Ib_design(double x)const;
	double M_IIa_design(double x)const;
	double M_IIb_design(double x)const;
	double M_total_design(double x)const;

	double Q_Ia_design(double x)const;
	double Q_Ib_design(double x)const;
	double Q_IIa_design(double x)const;
	double Q_IIb_design(double x)const;
	double Q_total_design(double x)const;

private:

	SupportsNumber s_num_;
	double L_ = 0.;
	TLoads loads_ {};

	double M_point_load(double x, double P, double x_P)const;
	double M_uniform_load(double x, double q, SupportsNumber s_num)const;
	double Q_point_load(double x, double P, double x_P)const;
	double Q_uniform_load(double x, double q, SupportsNumber s_num)const;

	std::map<double, double> R_uniform_load(double q, SupportsNumber s_num)const;
};



//---------------------------------------------------------------------------
#endif
