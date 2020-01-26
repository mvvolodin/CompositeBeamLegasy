//---------------------------------------------------------------------------

#pragma hdrstop

#include "Stresses.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
Stresses::Stresses()//чем поля класса инициализируются по умолчанию? Сделать явную инициализацию?
{

}
// В конструкторе вначале вызывается функция для определения напряжений в бетоне и арматуре.
// После расчёта напряжений вызывается функция классификации напряжённого состояния

Stresses::Stresses(InternalForces internal_forces,
				   CompositeSection composite_section,
				   WorkingConditionsFactors working_conditions_factors)
{
	calculate_stresses(internal_forces, composite_section);
	define_stress_state(composite_section, working_conditions_factors);
}
void Stresses::calculate_stresses(InternalForces internal_forces,
								  CompositeSection composite_section)
{
	std::vector<double> M_1=internal_forces.get_M();
	double W_b_red=composite_section.get_W_b_red();
	double alfa_b=composite_section.get_alfa_b();
	double alfa_s=composite_section.get_alfa_s();
	for (int i = 0; i < internal_forces.get_M().size(); i++) {
		sigma_b_.push_back(M_1[i]/(alfa_b*W_b_red));
		sigma_s_.push_back(M_1[i]/(alfa_s*W_b_red));
	}
}
void Stresses::define_stress_state(CompositeSection 		composite_section,
								   WorkingConditionsFactors working_conditions_factors)
{
	double gamma_bi=working_conditions_factors.get_gamma_bi();
	double gamma_si=working_conditions_factors.get_gamma_si();
	double gamma_c=working_conditions_factors.get_gamma_c();
	double R_b=composite_section.get_concrete_part()->get_R_bn();
	double R_s=composite_section.get_concrete_part()->get_rebar().get_R_s();
	double CS_number_=sigma_b_.size();//ужасное решение
	for (int i=0; i < CS_number_; ++i)
	{
		if (sigma_b_[i]<gamma_bi*R_b)
		{
			state_sigma_b_.push_back(StressState::elastic);
		}
		else
		{
			state_sigma_b_.push_back(StressState::plastic);
		}
		if (sigma_s_[i]<gamma_si*R_s)
		{
			state_sigma_s_.push_back(StressState::elastic);
		}
		else
		{
		   state_sigma_s_.push_back(StressState::plastic);
		}
	}




}



