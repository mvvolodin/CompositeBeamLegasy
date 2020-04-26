//---------------------------------------------------------------------------
#ifndef UInternalForcesCalculatorH
#define UInternalForcesCalculatorH
//---------------------------------------------------------------------------
#include "InternalForces.h"
#include "LoadsUnit.h"
 //---------------------------------------------------------------------------
class InternalForcesCalculator
{
public:
	InternalForcesCalculator (SupportsNumber 	 s_num,
							  double 			 L,
							  double 			 bl,
							  double 			 br,
							  TLoads 			 loads);
	double calculate_M_I_stage(double x);
	double calculate_M_R_I_stage(double x);
	double calculate_M_II_stage(double x);
	double calculate_M_total(double x);

	std::vector<double> calculate_M_I_stage(std::vector<double> X_list);
	std::vector<double> calculate_M_R_I_stage(std::vector<double> X_list);
	std::vector<double> calculate_M_II_stage(std::vector<double> X_list);
	std::vector<double> calculate_M_total(std::vector<double> X_list);

private:

	bool ready_;
	SupportsNumber s_num_;
	double L_;
	double bl_;
	double br_;
	TLoads loads_;

	double calculate_M_point_load(double x, double P, double x_P);
	double calculate_M_uniform_load(double x, double q, SupportsNumber s_num);
	std::array<double, 4> calculate_R(double q, SupportsNumber s_num);
};



//---------------------------------------------------------------------------
#endif
