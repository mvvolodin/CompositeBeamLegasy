//---------------------------------------------------------------------------
#ifndef uInternalForcesCalculatorH
#define uInternalForcesCalculatorH
//---------------------------------------------------------------------------
#include "InternalForces.h"
#include "uLoads.h"

 //---------------------------------------------------------------------------
class InternalForcesCalculator
{
public:
	InternalForcesCalculator();
	InternalForcesCalculator(SupportsNumber 	 s_num,
							 double 			 L,
							 TLoads 			 loads);

	double M_Ia_design(double x);
	double M_Ib_design(double x);
	double M_II_design(double x);
	double M_total_design(double x);

	std::vector<double> M_Ib_design(std::vector<double> X_list);
	std::vector<double> M_II_design(std::vector<double> X_list);
	std::vector<double> M_total_design(std::vector<double> X_list);

private:

	SupportsNumber s_num_;
	double L_ = 0.;
	TLoads loads_ {};

	double calculate_M_point_load(double x, double P, double x_P);
	double calculate_M_uniform_load(double x, double q, SupportsNumber s_num);
	double calculate_M_R_I_stage(double x);
	std::vector<double> calculate_M_R_I_stage(std::vector<double> X_list);
	std::array<double, 4> calculate_R(double q, SupportsNumber s_num);
};



//---------------------------------------------------------------------------
#endif
