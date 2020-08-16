//---------------------------------------------------------------------------

#ifndef uSectionH
#define uSectionH

#include "uCompositeSectionGeometry.h"
#include "uWorkingConditionsFactors.h"
#include "uInternalForcesCalculator.h"

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

	void calculate(InternalForcesCalculator& intr_frcs_calculator,
				   WorkingConditionsFactors& working_conditions_factors,
				   CompositeSectionGeometry& com_sect);

	int get_id()const{return id_;}
	double get_x()const{return x_;}

	const double get_M_Ia_design(LoadUnit__ load_unit = N, LengthUnit__ length_unit = mm)const{return M_Ia_design_ / (load_unit * length_unit);}
	const double get_M_Ib_design(LoadUnit__ load_unit = N, LengthUnit__ length_unit = mm)const{return M_Ib_design_ / (load_unit * length_unit);}
	const double get_M_IIa_design(LoadUnit__ load_unit = N, LengthUnit__ length_unit = mm)const{return M_IIa_design_ / (load_unit * length_unit);}
	const double get_M_IIb_design(LoadUnit__ load_unit = N, LengthUnit__ length_unit = mm)const {return M_IIb_design_ / (load_unit * length_unit);}
	const double get_M_total_design(LoadUnit__ load_unit = N, LengthUnit__ length_unit = mm)const{return M_total_design_ / (load_unit * length_unit);}

	double get_Q_Ia_design()const{return Q_Ia_design_;}
	double get_Q_Ib_design()const{return Q_Ib_design_;}
	double get_Q_IIa_design()const{return Q_IIa_design_;}
	double get_Q_IIb_design()const{return Q_IIb_design_;}
	double get_Q_total_design()const{return Q_total_design_;}

	double get_f_Ia()const{return f_Ia_;}
	double get_f_Ib()const{return f_Ib_;}
	double get_f_IIa()const{return f_IIa_;}
	double get_f_IIb()const{return f_IIb_;}
	double get_f_total()const{return f_total_;}

	double get_sigma_b()const{return sigma_b_;}
	double get_sigma_s()const{return sigma_s_;}

	double get_max_direct_stress_ratio()const;

	double get_upper_fl_ratio()const{return upper_fl_ratio_;}
	double get_lower_fl_ratio()const{return lower_fl_ratio_;}
	double get_conc_ratio()const{return conc_ratio_;}
	double get_rigid_plastic_ratio()const {return ratio_rigid_plastic_;}
	double get_shear_ratio()const{return shear_ratio_;}
	double get_i_section_ratio()const{return i_section_ratio_;}

private:

	int id_ = 0.;
	double x_ = 0.;

	double M_Ia_design_ = 0.;
	double M_Ib_design_ = 0.;
	double M_IIa_design_ = 0.;
	double M_IIb_design_ = 0.;
	double M_total_design_ = 0.;

	double Q_Ia_design_ = 0.;
	double Q_Ib_design_ = 0.;
	double Q_IIa_design_ = 0.;
	double Q_IIb_design_ = 0.;
	double Q_total_design_ = 0.;

	double f_Ia_ = 0.;
	double f_Ib_ = 0.;
	double f_IIa_ = 0.;
	double f_IIb_ = 0.;
	double f_total_ = 0.;

	double sigma_b_ = 0.;
	double sigma_s_ = 0.;

	double sigma_bi_ = 0.;
	double sigma_si_ = 0.;

	StressStateCase2 stress_state_ = StressStateCase2::CASE_I;

	double upper_fl_ratio_ = 0.;
	double lower_fl_ratio_ = 0.;
	double conc_ratio_ = 0.;
	double shear_ratio_ = 0.;
	double ratio_rigid_plastic_ = 0.;
	double i_section_ratio_ = 0.0;

	void calculate_internal_forces(InternalForcesCalculator& intr_frcs_calculator);

	void calculate_stresses(CompositeSectionGeometry& com_sect,
							WorkingConditionsFactors& working_conditions_factors);

	void calculate_ratios(CompositeSectionGeometry& com_sect,
						  WorkingConditionsFactors& working_conditions_factors);
	void calculate_direct_stress_ratios(CompositeSectionGeometry& com_sect,
										WorkingConditionsFactors& working_conditions_factors);
	void calculate_shear_ratio(CompositeSectionGeometry& com_sect,
							   WorkingConditionsFactors& working_conditions_factors);
	void calculate_rigid_plastic_ratio(CompositeSectionGeometry& com_sect,
									   WorkingConditionsFactors& working_conditions_factors);
	void calculate_i_sect_ratio(CompositeSectionGeometry& com_sect,
									 WorkingConditionsFactors& working_conditions_factors);
};

//---------------------------------------------------------------------------
#endif
