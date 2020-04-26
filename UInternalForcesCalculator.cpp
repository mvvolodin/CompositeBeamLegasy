//---------------------------------------------------------------------------

#pragma hdrstop
//---------------------------------------------------------------------------
#include <vector>
#include <array>
//---------------------------------------------------------------------------
#include "UInternalForcesCalculator.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------

InternalForcesCalculator::InternalForcesCalculator( SupportsNumber 	 s_num,
													double 			 L,
													double 			 bl,
													double 			 br,
													TLoads 			 loads):
	ready_(true),
	s_num_(s_num),
	L_    (L),
	bl_   (bl),
	br_   (br),
	loads_ (loads){}
double InternalForcesCalculator::calculate_M_I_stage(double x)
{

	double SW = loads_.get_self_weight();
	double SW_sh = loads_.get_self_weight_sheets() * (bl_ + br_);
	double DL_I = loads_.get_dead_load_first_stage() * (bl_ + br_);

	double gamma_f_st_SW = loads_.get_gamma_f_st_SW();
	double gamma_f_DL_I = loads_.get_gamma_f_DL_I();

	double LC = gamma_f_st_SW * (SW + SW_sh) + gamma_f_DL_I * DL_I;

	return calculate_M_uniform_load(x, LC, s_num_);

}
double InternalForcesCalculator::calculate_M_R_I_stage(double x)
{

	double SW = loads_.get_self_weight();
	double SW_sh = loads_.get_self_weight_sheets() * (bl_ + br_);
	double DL_I = loads_.get_dead_load_first_stage() * (bl_ + br_);

	double gamma_f_st_SW = loads_.get_gamma_f_st_SW();
	double gamma_f_DL_I = loads_.get_gamma_f_DL_I();

	double LC = gamma_f_st_SW * (SW + SW_sh) + gamma_f_DL_I * DL_I;

	std::array<double, 4> R_LC = calculate_R(LC, s_num_);

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
double InternalForcesCalculator::calculate_M_II_stage(double x)
{
	double DL_II = loads_.get_dead_load_second_stage() * (bl_ + br_);
	double LL = loads_.get_live_load() * (bl_ + br_);

	double gamma_f_DL_II = loads_.get_gamma_f_DL_II();
	double gamma_f_LL = loads_.get_gamma_f_LL();

	double LC_II = gamma_f_DL_II * DL_II + gamma_f_LL * LL;

	double M_LC_II = calculate_M_uniform_load(x, LC_II, SupportsNumber::Zero );
	double M_R_I = calculate_M_R_I_stage(x);

	return M_LC_II + M_R_I;
}


double InternalForcesCalculator::calculate_M_total(double x)
{
	return calculate_M_I_stage(x) + calculate_M_II_stage(x);
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
std::vector<double> InternalForcesCalculator::calculate_M_I_stage(std::vector<double> X_list)
{
	std::vector<double> M_I_stage;

	for(auto cs:X_list)
	  M_I_stage.push_back(calculate_M_I_stage(cs));

	return M_I_stage;
}
std::vector<double> InternalForcesCalculator::calculate_M_R_I_stage(std::vector<double> X_list)
{
	std::vector<double> M_R_I_stage;

	for(auto cs:X_list)
		M_R_I_stage.push_back(calculate_M_R_I_stage(cs));

	return M_R_I_stage;
}

std::vector<double> InternalForcesCalculator::calculate_M_II_stage(std::vector<double> X_list)
{
	std::vector<double> M_II_stage;

	for(auto cs:X_list)
		M_II_stage.push_back(calculate_M_II_stage(cs));

	return M_II_stage;

}
std::vector<double> InternalForcesCalculator::calculate_M_total(std::vector<double> X_list)
{
	std::vector<double> M_total;

	for(auto cs:X_list)
		M_total.push_back(calculate_M_total(cs));

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
