//---------------------------------------------------------------------------

#pragma hdrstop

#include "Ratios.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
Ratios::Ratios(WorkingConditionsFactors working_conditions_factors,
			   CompositeSection		   	composite_section,
			   double 				   	M,
			   double 				   	Q,
			   double 				   	sigma_b,
			   double 				   	sigma_s,
			   StressState 			    sigma_b_state,
			   StressState 			    sigma_s_state)
{
	switch(1)
	{
	case(1):
	calculate_I_case(working_conditions_factors,composite_section, M, Q, sigma_b, sigma_s, sigma_b_state, sigma_s_state);

		break;
	case(2):
	 calculate_II_case(working_conditions_factors,composite_section, M, Q, sigma_b, sigma_s, sigma_b_state, sigma_s_state);

		break;
	case(3):
	 calculate_III_case(working_conditions_factors,composite_section, M, Q, sigma_b, sigma_s, sigma_b_state, sigma_s_state);
		break;
	 }
}
void Ratios::calculate_I_case(WorkingConditionsFactors working_conditions_factors,
							  CompositeSection		   composite_section,
							  double 				   M,
							  double 				   Q,
							  double 				   sigma_b,
							  double 				   sigma_s,
							  StressState 			   sigma_b_state,
							  StressState 			   sigma_s_state)
{
		double Z_b_st=composite_section.get_Z_b_st();
		double W_f2_st=composite_section.get_steel_part().get_Wf2_st();
		double W_f1_st=composite_section.get_steel_part().get_Wf1_st();
		double A_s=composite_section.get_concrete_part()->get_rebar().get_A_s();
		double A_st=composite_section.get_steel_part().get_A_st();
		double A_b=composite_section.get_concrete_part()->get_A_b();
		double R_y=composite_section.get_steel_grade().get_R_y ();
		double R_b=composite_section.get_concrete_part()->get_R_b();
		double gamma_bi=working_conditions_factors.get_gamma_bi();
		double gamma_c=working_conditions_factors.get_gamma_c();
		double A_f2_st=composite_section.get_steel_part().get_A_f2_st();


		double gamma_1=1+(gamma_bi*R_b-sigma_b)/(gamma_c*R_y)*A_b/A_f2_st;

		if (gamma_1>=1.2) {//Выполнить через max std::math
			gamma_1=1.2;
		}

		double N_b_s=A_b*sigma_b+A_s*sigma_s;

		ratio_upper_flange_=((M-Z_b_st*N_b_s)/W_f2_st-N_b_s/A_st)/(gamma_1*gamma_c*R_y);
		ratio_lower_flange_=((M-Z_b_st*N_b_s)/W_f1_st-N_b_s/A_st)/(gamma_c*R_y);

}
void Ratios::calculate_II_case(WorkingConditionsFactors working_conditions_factors,
							  CompositeSection		   composite_section,
							  double 				   M,
							  double 				   Q,
							  double 				   sigma_b,
							  double 				   sigma_s,
							  StressState 			   sigma_b_state,
							  StressState 			   sigma_s_state)
{
		//double Z_b_st=composite_section.
}
void Ratios::calculate_III_case(WorkingConditionsFactors working_conditions_factors,
							  CompositeSection		   composite_section,
							  double 				   M,
							  double 				   Q,
							  double 				   sigma_b,
							  double 				   sigma_s,
							  StressState 			   sigma_b_state,
							  StressState 			   sigma_s_state)
{
		//double Z_b_st=composite_section.
}

