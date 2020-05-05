//---------------------------------------------------------------------------

#pragma hdrstop

#include "uSection.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

InternalForcesCalculator Section::intr_frcs_calculator_;
WorkingConditionsFactors Section::working_conditions_factors_;

Section::Section()
{

}
Section::Section(int id, double x, CompositeSection com_sect):
	id_(id),
	x_(x),
	com_sect_(com_sect)
{}

void Section::set_intr_frcs_calculator(InternalForcesCalculator& intr_frcs_calculator)
{
	intr_frcs_calculator_ = intr_frcs_calculator;
}

void Section::set_working_conditions_factors (WorkingConditionsFactors& working_conditions_factors)
{
	working_conditions_factors_ = working_conditions_factors;
}

void Section::calculate()
{
	calculate_internal_forces();
	calculate_stresses();
	calculate_ratios();
}

void Section::calculate_internal_forces()
{
	M_I_ = intr_frcs_calculator_.calculate_M_I_stage(x_);
	M_II_ = intr_frcs_calculator_.calculate_M_II_stage(x_);
	M_total_ = intr_frcs_calculator_.calculate_M_total(x_);
  //	Q_total_ = intr_frcs_calculator_.calculate_Q_total(x_);

}
void Section::calculate_stresses()
{
	double W_b_red = com_sect_.get_W_b_red();
	double alfa_b = com_sect_.get_alfa_b();
	double alfa_s = com_sect_.get_alfa_s();

	double R_b = com_sect_.get_concrete_part().get_concrete().get_R_b();
	double R_s = com_sect_.get_concrete_part().get_rebar().get_R_s();

	double gamma_bi = working_conditions_factors_.get_gamma_bi();
	double gamma_si = working_conditions_factors_.get_gamma_si();
	double gamma_c = working_conditions_factors_.get_gamma_c();

	double sigma_b = std::abs(M_I_)/(alfa_b*W_b_red);
	double sigma_s = std::abs(M_I_)/(alfa_s*W_b_red);

	if((sigma_b<gamma_bi*R_b) && (sigma_s<gamma_si*R_s))

		stress_state_ = StressStateCase2::CASE_I;

	else if ((sigma_b>=gamma_bi*R_b) && (sigma_s<gamma_si*R_s))

		stress_state_ = StressStateCase2::CASE_II;

	else if ((sigma_b>=gamma_bi*R_b) && (sigma_s>=gamma_si*R_s))

		stress_state_ = StressStateCase2::CASE_III;

}
void Section::calculate_ratios()
{
	double Z_b_st = com_sect_.get_Z_b_st();
	double W_f2_st = com_sect_.get_steel_part().get_section().get_Wf2_st();
	double W_f1_st = com_sect_.get_steel_part().get_section().get_Wf1_st();
	double W_b_st = com_sect_.get_W_b_st();
	double A_s = com_sect_.get_concrete_part().get_rebar().get_A_s();
	double R_s=com_sect_.get_concrete_part().get_rebar().get_R_s();
	double A_st = com_sect_.get_steel_part().get_section().get_A_st();
	double A_b = com_sect_.get_concrete_part().get_A_b();
	double R_y = com_sect_.get_steel_grade().get_R_y ();
	double R_b = com_sect_.get_concrete_part().get_concrete().get_R_bn();
	double gamma_bi = working_conditions_factors_.get_gamma_bi();
	double gamma_c = working_conditions_factors_.get_gamma_c();
	double A_f2_st = com_sect_.get_steel_part().get_section().get_A_f2_st();
	double E_st = com_sect_.get_steel_part().get_steel().get_E_st();
	double epsilon_b_lim = com_sect_.get_concrete_part().get_concrete().get_epsilon_b_lim();

	double gamma_1 = 0.;
	double N_b_s = 0.;
	double N_bR_sR = 0.;
	double N_bR_s = 0.;
	double sigma_0 = 0.;
	double k = 0.;

	switch(stress_state_)
	{
	case(StressStateCase2::CASE_I):

		gamma_1 = std::min(1+(gamma_bi*R_b-sigma_b_)/(gamma_c*R_y)*A_b/A_f2_st, 1.2);
		N_b_s = A_b*sigma_b_+A_s*sigma_s_;
		upper_fl_ratio_ = ((std::abs(M_total_)-Z_b_st*std::abs(N_b_s))/W_f2_st - std::abs(N_b_s)/A_st)/(gamma_1*gamma_c*R_y);
		lower_fl_ratio_ = ((std::abs(M_total_)-Z_b_st*std::abs(N_b_s))/W_f1_st + std::abs(N_b_s)/A_st)/(gamma_c*R_y);

	case(StressStateCase2::CASE_II):

		N_bR_sR=A_b*R_b+A_s*R_s;
		N_bR_s=A_b*R_b+A_s*sigma_s_;
		upper_fl_ratio_ = ((std::abs(M_total_)-Z_b_st*std::abs(N_bR_sR))/W_f2_st - std::abs(N_bR_sR)/A_st)/(gamma_c*R_y);
		lower_fl_ratio_ = ((std::abs(M_total_)-Z_b_st*std::abs(N_bR_s))/W_f1_st + std::abs(N_bR_s)/A_st)/(gamma_c*R_y);

	case(StressStateCase2::CASE_III):

		N_bR_sR = A_b * R_b + A_s * R_s;
		sigma_0 = (M_total_ - Z_b_st * N_bR_sR) / W_f2_st;
		k = calculate_concrete_coefficient(sigma_0, N_bR_sR);
/* TODO 1 -oMV : Тестировать ratio_concrete */
		upper_fl_ratio_ = ((std::abs(M_total_)-Z_b_st*std::abs(N_bR_sR))/W_f2_st - std::abs(N_bR_sR)/A_st)/(gamma_c*R_y);
		lower_fl_ratio_ = ((std::abs(M_total_)-Z_b_st*std::abs(N_bR_sR))/W_f1_st + std::abs(N_bR_sR/A_st))/(gamma_c*R_y);
		conc_ratio_ = k / E_st * ((M_II_ - Z_b_st * N_bR_sR) / W_b_st - N_bR_sR / A_st) / epsilon_b_lim;
	}
    /* TODO 1 -oMV : Тестировать */


}
double Section::calculate_concrete_coefficient(double sigma_0, double N_bR_sR)
{
	double gamma_c = working_conditions_factors_.get_gamma_c();
	double R_y = com_sect_.get_steel_part().get_steel().get_R_y();
	double A_st = com_sect_.get_steel_part().get_section().get_A_st();
	double E_st = com_sect_.get_steel_part().get_steel().get_E_st();
	double k = 0.;
	double k_min = 1.0;
	double k_max = 1.0 + 0.009 * E_st / (gamma_c * R_y);
	double k_min_sigma = gamma_c * R_y;
	double k_max_sigma = gamma_c * R_y + N_bR_sR / A_st;

	if (sigma_0 <= k_min_sigma) return k = k_min;

	if (sigma_0 > k_max_sigma) return k = k_max;

	return k = linear_interpolation(k_min, k_max, k_min_sigma, k_max_sigma, sigma_0);
}






