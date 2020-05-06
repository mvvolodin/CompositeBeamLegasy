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
	Section(int id, double x);

	static void set_composite_section (CompositeSection& com_sect);
	static void set_intr_frcs_calculator(InternalForcesCalculator& intr_frcs_calculator);
	static void set_working_conditions_factors (WorkingConditionsFactors& working_conditions_factors);

	void calculate();

	int get_id()const{return id_;}
	double get_x()const{return x_;}

	double get_M_Ia_design()const{return M_Ia_design_;}
	double get_M_Ib_design()const{return M_Ib_design_;}
	double get_M_II_design()const{return M_II_design_;}
	double get_M_total_design()const{return M_total_design_;}
	double get_Q_total_design()const{return Q_total_design_;}

	double get_sigma_b()const{return sigma_b_;}
	double get_sigma_s()const{return sigma_s_;}

	double get_upper_fl_ratio()const{return upper_fl_ratio_;}
	double get_lower_fl_ratio()const{return lower_fl_ratio_;}
	double get_conc_ratio()const{return conc_ratio_;}
	double get_shear_ratio()const{return shear_ratio_;}

private:
	static InternalForcesCalculator intr_frcs_calculator_;
	static WorkingConditionsFactors working_conditions_factors_;
	static CompositeSection com_sect_;

	int id_ = 0.;
	double x_ = 0.;

	double M_Ia_design_ = 0.;
	double M_Ib_design_ = 0.;
	double M_II_design_ = 0.;
	double M_total_design_ = 0.;
	double Q_total_design_ = 0.;

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
