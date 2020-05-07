//---------------------------------------------------------------------------

#pragma hdrstop
//---------------------------------------------------------------------------
#include <vector>
#include <array>
//---------------------------------------------------------------------------
#include "uInternalForcesCalculator.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
InternalForcesCalculator::InternalForcesCalculator()
{
}
InternalForcesCalculator::InternalForcesCalculator( SupportsNumber 	 s_num,
													double 			 L,
													TLoads 			 loads):
	s_num_(s_num),
    L_(L),
	loads_ (loads){}
double InternalForcesCalculator::M_Ia_design(double x)
{
	return calculate_M_uniform_load(x, loads_.Ia_design_LCC(), s_num_);
}
double InternalForcesCalculator::M_Ib_design(double x)
{
	return calculate_M_uniform_load(x, loads_.Ib_design_LCC(), s_num_);
}
double InternalForcesCalculator::calculate_M_R_I_stage(double x)
{
	std::array<double, 4> R_LC = calculate_R(loads_.Ib_design_LCC(), s_num_);

	double L0 = 0.;

	switch(s_num_)
	{
		case(SupportsNumber::Zero):

			return 0;

		case(SupportsNumber::One):

			L0 = L_ / 2;

			return calculate_M_point_load(x, R_LC[1], L0);

		case(SupportsNumber::Two):

			L0 = L_ / 3;

			return calculate_M_point_load(x, R_LC[1], L0) + calculate_M_point_load(x, R_LC[2], 2 * L0);

		case(SupportsNumber::Three):

			L0 = L_ / 4;

			return calculate_M_point_load(x, R_LC[1], L0) + calculate_M_point_load(x, R_LC[2], 2 * L0) + calculate_M_point_load(x, R_LC[2], 3 * L0);
	}
}
double InternalForcesCalculator::M_II_design(double x)
{
	double M_LC_II = calculate_M_uniform_load(x, loads_.II_design_LCC(), SupportsNumber::Zero );
	double M_R_I = calculate_M_R_I_stage(x);

	return M_LC_II + M_R_I;
}


double InternalForcesCalculator::M_total_design(double x)
{
	return M_Ib_design(x) + M_II_design(x);
}
std::array<double, 4> InternalForcesCalculator::calculate_R(double q, SupportsNumber s_num)
{
	double L0 = 0.;
	std::array<double, 4> R {};

	switch(s_num)
	{
		case(SupportsNumber::Zero):

			L0 = L_;
			R[0]= 0.5 * q * L0;

			return R;

		case(SupportsNumber::One):

			L0 = L_ / 2;

			R[0] = 0.375 * q * L0;
			R[1] = 1.25 * q * L0;

			return R;

		case(SupportsNumber::Two):

			L0 = L_ / 3;

			R[0] = 0.4 * q * L0;
			R[1] = 1.1 * q * L0;
			R[2] = 1.1 * q * L0;

			return R;

		case(SupportsNumber::Three):

			L0 = L_ / 4;

			R[0] = 0.393 * q * L0;
			R[1] = 1.143 * q * L0;
			R[2] = 0.929 * q * L0;
			R[3] = 1.143 * q * L0;

			return R;
	}
}
std::vector<double> InternalForcesCalculator::M_Ib_design(std::vector<double> X_list)
{
	std::vector<double> M_I_stage;

	for(auto cs:X_list)
	  M_I_stage.push_back(M_Ib_design(cs));

	return M_I_stage;
}
std::vector<double> InternalForcesCalculator::calculate_M_R_I_stage(std::vector<double> X_list)
{
	std::vector<double> M_R_I_stage;

	for(auto cs:X_list)
		M_R_I_stage.push_back(calculate_M_R_I_stage(cs));

	return M_R_I_stage;
}

std::vector<double> InternalForcesCalculator::M_II_design(std::vector<double> X_list)
{
	std::vector<double> M_II_stage;

	for(auto cs:X_list)
		M_II_stage.push_back(M_II_design(cs));

	return M_II_stage;

}
std::vector<double> InternalForcesCalculator::M_total_design(std::vector<double> X_list)
{
	std::vector<double> M_total;

	for(auto cs:X_list)
		M_total.push_back(M_total_design(cs));

	return M_total;
}


double InternalForcesCalculator::calculate_M_uniform_load(double x, double q, SupportsNumber s_num)
{
	double L0 = 0.;
	std::array<double, 4> R = calculate_R(q, s_num);

	switch(s_num)
	{
		case(SupportsNumber::Zero):

			L0 = L_;

			return R[0] * x - q * x * x / 2;

		case(SupportsNumber::One):

			L0 = L_ / 2;

			if(x <= L0)
				return R[0] * x - q * x * x / 2;
			return R[0] * (L0 + x) + R[1] * x - q * x * x / 2;

		case(SupportsNumber::Two):

			L0 = L_ / 3;

			if(x <= L0)
				return R[0] * x - q * x * x / 2;
			if(L0 < x <= 2 * L0)
				return R[0] * (L0 + x) + R[1] * x - q * x * x / 2;
			return R[0] * (2* L0 + x) + R[1] * (L0 + x) + R[2] * x - q * x * x / 2;

		case(SupportsNumber::Three):

			L0 = L_ / 4;

			if(x <= L0)
				return R[0] * x - q * x * x / 2;
			 if(L0 < x <= 2 * L0)
				return R[0] * (L0 + x) + R[1] * x - q * x * x / 2;
			 if(2 * L0 < x <= 3 * L0)
				return R[0] * (2* L0 + x) + R[1] * (L0 + x) + R[2] * x - q * x * x / 2;
			 return R[0] * (3 * L0 + x) + R[1] * (2 * L0 + x) + R[2] * (L0 + x) - q * x * x / 2;
	}
}
double InternalForcesCalculator::calculate_M_point_load(double x, double P, double x_P)
{
	return P * (L_ - x_P) / L_ * x_P;
}
