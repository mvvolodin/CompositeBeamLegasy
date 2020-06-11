//---------------------------------------------------------------------------

#pragma hdrstop

#include <cassert>
#include "uSection.h"
#include <algorithm>
//---------------------------------------------------------------------------
#pragma package(smart_init)

Section::Section()
{
}
Section::Section(int id, double x):
	id_(id),
	x_(x)
{}

void Section::calculate(InternalForcesCalculator& intr_frcs_calculator,
						WorkingConditionsFactors& working_conditions_factors,
						CompositeSectionGeometry& com_sect)
{
	calculate_internal_forces(intr_frcs_calculator);
	calculate_stresses(com_sect, working_conditions_factors);
	calculate_ratios(com_sect, working_conditions_factors);
}

void Section::calculate_internal_forces(InternalForcesCalculator& intr_frcs_calculator)
{
	M_Ia_design_ = intr_frcs_calculator.M_Ia_design(x_);
	M_Ib_design_ = intr_frcs_calculator.M_Ib_design(x_);
	M_IIa_design_ = intr_frcs_calculator.M_IIa_design(x_);
	M_IIb_design_ = intr_frcs_calculator.M_IIb_design(x_);
	M_total_design_ = intr_frcs_calculator.M_total_design(x_);

	Q_Ia_design_ = intr_frcs_calculator.Q_Ia_design(x_);
	Q_Ib_design_ = intr_frcs_calculator.Q_Ib_design(x_);
	Q_IIa_design_ = intr_frcs_calculator.Q_IIa_design(x_);
	Q_IIb_design_ = intr_frcs_calculator.Q_IIb_design(x_);
	Q_total_design_ = intr_frcs_calculator.Q_total_design(x_);

	f_Ia_design_ = intr_frcs_calculator.f_Ia_design(x_);
	f_Ib_design_ = intr_frcs_calculator.f_Ib_design(x_);
	f_IIa_design_ = intr_frcs_calculator.f_IIa_design(x_);
	f_IIb_design_ = intr_frcs_calculator.f_IIb_design(x_);
	f_total_design_ = intr_frcs_calculator.f_total_design(x_);

	sigma_bi_ = intr_frcs_calculator.M_IIb_sigma_bi(x_);
	sigma_si_ = intr_frcs_calculator.M_IIb_sigma_si(x_);
}
void Section::calculate_stresses(CompositeSectionGeometry& com_sect,
								 WorkingConditionsFactors& working_conditions_factors)
{
	double W_b_red = com_sect.get_W_b_red();
	double alfa_b = com_sect.get_alfa_b();
	double alfa_s = com_sect.get_alfa_s();

	double R_b = com_sect.get_concrete_part().get_concrete().get_R_b();
	double R_s = com_sect.get_concrete_part().get_rebar().get_R_s();

	double gamma_bi = working_conditions_factors.get_gamma_bi();
	double gamma_si = working_conditions_factors.get_gamma_si();
	double gamma_c = working_conditions_factors.get_gamma_c();

	sigma_b_ = std::abs(M_IIa_design_ + M_IIb_design_)/(alfa_b*W_b_red) - sigma_bi_;
	sigma_s_ = std::abs(M_IIa_design_ + M_IIb_design_)/(alfa_s*W_b_red) - sigma_si_;

	if((sigma_b_<gamma_bi*R_b) && (sigma_s_<gamma_si*R_s))

		stress_state_ = StressStateCase2::CASE_I;

	else if ((sigma_b_>=gamma_bi*R_b) && (sigma_s_<gamma_si*R_s))

		stress_state_ = StressStateCase2::CASE_II;

	else if ((sigma_b_>=gamma_bi*R_b) && (sigma_s_>=gamma_si*R_s))

		stress_state_ = StressStateCase2::CASE_III;

}
void Section::calculate_ratios(CompositeSectionGeometry& com_sect,
							   WorkingConditionsFactors& working_conditions_factors)
{
	calculate_direct_stress_ratios(com_sect, working_conditions_factors);
	calculate_shear_ratio(com_sect, working_conditions_factors);
	calculate_rigid_plastic_ratio(com_sect, working_conditions_factors);
	calculate_i_sect_ratio(com_sect, working_conditions_factors);
}
void Section::calculate_direct_stress_ratios(CompositeSectionGeometry& com_sect,
											 WorkingConditionsFactors& working_conditions_factors)
{
	double Z_b_st = com_sect.get_Z_b_st();
	double W_f2_st = com_sect.get_steel_part().get_section().get_Wf2_st();
	double W_f1_st = com_sect.get_steel_part().get_section().get_Wf1_st();
	double W_b_st = com_sect.get_W_b_st();
	double A_s = com_sect.get_concrete_part().get_rebar().get_A_s();
	double R_s=com_sect.get_concrete_part().get_rebar().get_R_s();
	double A_st = com_sect.get_steel_part().get_section().get_A_st();
	double A_b = com_sect.get_concrete_part().get_A_b();
	double R_y = com_sect.get_steel_part().get_steel().get_R_y ();
	double R_b = com_sect.get_concrete_part().get_concrete().get_R_bn();
	double gamma_bi = working_conditions_factors.get_gamma_bi();
	double gamma_c = working_conditions_factors.get_gamma_c();
	double A_f2_st = com_sect.get_steel_part().get_section().get_A_f2_st();
	double E_st = com_sect.get_steel_part().get_steel().get_E_st();
	double epsilon_b_lim = com_sect.get_concrete_part().get_concrete().get_epsilon_b_lim();

	double gamma_1 = 0.;
	double N_b_s = 0.;
	double N_bR_sR = 0.;
	double N_bR_s = 0.;
	double sigma_0 = 0.;
	double k = 0.;
	double k_min = 1.0;
	double k_max = 1.0 + 0.009 * E_st / (gamma_c * R_y);
	double k_min_sigma = gamma_c * R_y;
	double k_max_sigma = 0.;

	switch(stress_state_)
	{
	case(StressStateCase2::CASE_I):

		gamma_1 = std::min(1+(gamma_bi*R_b-sigma_b_)/(gamma_c*R_y)*A_b/A_f2_st, 1.2);
		N_b_s = A_b*sigma_b_ + A_s*sigma_s_;
		upper_fl_ratio_ = ((std::abs(M_total_design_)-Z_b_st*std::abs(N_b_s))/W_f2_st - std::abs(N_b_s)/A_st)/(gamma_1*gamma_c*R_y);
		lower_fl_ratio_ = ((std::abs(M_total_design_)-Z_b_st*std::abs(N_b_s))/W_f1_st + std::abs(N_b_s)/A_st)/(gamma_c*R_y);
		break;

	case(StressStateCase2::CASE_II):

		N_bR_sR=A_b*R_b+A_s*R_s;
		N_bR_s=A_b*R_b+A_s*sigma_s_;
		upper_fl_ratio_ = ((std::abs(M_total_design_)-Z_b_st*std::abs(N_bR_sR))/W_f2_st - std::abs(N_bR_sR)/A_st)/(gamma_c*R_y);
		lower_fl_ratio_ = ((std::abs(M_total_design_)-Z_b_st*std::abs(N_bR_s))/W_f1_st + std::abs(N_bR_s)/A_st)/(gamma_c*R_y);
		break;

	case(StressStateCase2::CASE_III):

		N_bR_sR = A_b * R_b + A_s * R_s;
		sigma_0 = (M_total_design_ - Z_b_st * N_bR_sR) / W_f2_st;

		k_max_sigma = gamma_c * R_y + N_bR_sR / A_st;

		if (sigma_0 <= k_min_sigma) k = k_min;

		if (sigma_0 > k_max_sigma) k = k_max;

		k = linear_interpolation(k_min, k_max, k_min_sigma, k_max_sigma, sigma_0);
/* TODO 1 -oMV : Тестировать ratio_concrete */
		upper_fl_ratio_ = ((std::abs(M_total_design_)-Z_b_st*std::abs(N_bR_sR))/W_f2_st - std::abs(N_bR_sR)/A_st)/(gamma_c*R_y);
		lower_fl_ratio_ = ((std::abs(M_total_design_)-Z_b_st*std::abs(N_bR_sR))/W_f1_st + std::abs(N_bR_sR/A_st))/(gamma_c*R_y);
		conc_ratio_ = k / E_st * (((M_IIa_design_ + M_IIb_design_) - Z_b_st * N_bR_sR) / W_b_st - N_bR_sR / A_st) / epsilon_b_lim;
		break;
	}
}
void Section::calculate_shear_ratio(CompositeSectionGeometry& com_sect,
									WorkingConditionsFactors& working_conditions_factors)
{
	shear_ratio_ = std::abs(Q_total_design_) / com_sect.get_Q_Rd();
}
void Section::calculate_i_sect_ratio(CompositeSectionGeometry& com_sect,
									 WorkingConditionsFactors& working_conditions_factors)
{
	i_section_ratio_ = std::abs(M_Ia_design_) / com_sect.get_steel_part().get_M_Rd();
}
void Section::calculate_rigid_plastic_ratio(CompositeSectionGeometry& com_sect,
											WorkingConditionsFactors& working_conditions_factors)
{
	ratio_rigid_plastic_ = std::abs((M_Ib_design_ + M_IIa_design_ + M_IIb_design_)) / com_sect.get_M_Rd();
}
double Section::get_max_direct_stress_ratio()const
{
	return std::max({std::abs(upper_fl_ratio_),
					std::abs(lower_fl_ratio_),
					std::abs(conc_ratio_)});
}









