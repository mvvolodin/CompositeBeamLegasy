//---------------------------------------------------------------------------

#ifndef uSectionH
#define uSectionH

#include "CompositeSection.h"
#include "uInternalForcesCalculator.h"
#include "WorkingConditionsFactors.h"
#include "MathFunction.h"


enum class StressStateCase2{ //придумать содержательные названия
	CASE_I,
	CASE_II,
	CASE_III,
};

class Section{
public:
	Section();
	Section(int id, double x, CompositeSection com_sect);

	void set_intr_frcs_calculator(InternalForcesCalculator& intr_frcs_calculator);
	void set_working_conditions_factors (WorkingConditionsFactors& working_conditions_factors);

	void calculate();

private:
	static InternalForcesCalculator intr_frcs_calculator_;
	static WorkingConditionsFactors working_conditions_factors_;

	int id_ = 0.;
	double x_ = 0.;
	CompositeSection com_sect_{};

	double M_I_ = 0.;
	double M_II_ = 0.;
	double M_total_ = 0.;
	double Q_total_ = 0.;

	double sigma_b_ = 0.;
	double sigma_s_ = 0.;
	StressStateCase2 stress_state_ = StressStateCase2::CASE_I;

	double upper_fl_ratio_ = 0.;
	double lower_fl_ratio_ = 0.;
	double conc_ratio_ = 0.;
	double shear_ratio_ = 0.;

	void calculate_internal_forces();
	void calculate_stresses();
	void calculate_ratios();
	double calculate_concrete_coefficient(double sigma_0, double N_bR_sR);

};


//---------------------------------------------------------------------------
#endif
