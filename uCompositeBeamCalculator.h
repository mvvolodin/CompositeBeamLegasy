//---------------------------------------------------------------------------

#ifndef uCompositeBeamCalculatorH
#define uCompositeBeamCalculatorH


#include <vector>
#include <ostream>
//---------------------------------------------------------------------------
#include "uGeometry.h"
#include "uLoads.h"

#include "uSteel.h"
#include "CompositeSection.h"
#include "uStud.h"
#include "uRebar.h"
#include "uWorkingConditionsFactors.h"
#include "Stresses.h"
#include "Ratios.h"
#include "uCorrugatedSheet.h"

#include "uCompositeBeam.h"


class CompositeBeamCalculator{
//---------------------------------------------------------------------------
public:
//---------------------------------------------------------------------------
	CompositeBeamCalculator();
	CompositeBeamCalculator(TGeometry 				geometry,
				   TLoads 					loads,
				   CompositeSection         composite_section,
				   StudsOnBeam              studs_on_beam,
				   WorkingConditionsFactors working_conditions_factors);

	void set_default_values();

	void save(std::ostream& ostr) const;
	void load(std::istream& istr);

	void calculate();

	TGeometry get_geometry()const {return geometry_;}
	TLoads get_loads()const {return loads_;}
	WorkingConditionsFactors get_working_conditions_factors() const {return working_conditions_factors_;}
	CompositeSection get_composite_section()const{return composite_section_;}

	const CompositeBeam& get_sections_beam()const{return composite_beam_;}
	const StudsOnBeam& get_studs_on_beam()const{return studs_on_beam_;}

//Функции получения результатов расчёта для вывода в отчёт

	double get_max_upper_flange_ratio()const;
	double get_max_lower_flange_ratio()const;
	double get_max_upper_flange_ratio_coordinate() const;
	double get_max_lower_flange_ratio_coordinate() const;

	double get_M_I_for_cs_with_max_lower_flange_ratio(LoadUnit load_unit=LoadUnit::N, LengthUnit length_unit=LengthUnit::mm);
	double get_M_II_for_cs_with_max_lower_flange_ratio(LoadUnit load_unit=LoadUnit::N, LengthUnit length_unit=LengthUnit::mm);
	double get_M_total_for_cs_with_max_lower_flange_ratio(LoadUnit load_unit=LoadUnit::N, LengthUnit length_unit=LengthUnit::mm);

	double get_sigma_b_for_cs_with_max_lower_flange_ratio(LoadUnit load_unit=LoadUnit::N, LengthUnit length_unit=LengthUnit::mm);
	double get_sigma_s_for_cs_with_max_lower_flange_ratio(LoadUnit load_unit=LoadUnit::N, LengthUnit length_unit=LengthUnit::mm);

	double get_max_shear_ratio() const;
	double get_max_steel_beam_direct_stresses_I_stage_ratio()const;
	double get_max_stud_ratio();
	double get_max_stud_ratio_coordinate();
	double get_max_S_h(LoadUnit load_unit=LoadUnit::N);

	double get_ratio_rigid_plastic() const;


private:

	TGeometry geometry_;
	TLoads loads_;
	WorkingConditionsFactors working_conditions_factors_;
	CompositeSection composite_section_;

	CompositeBeam composite_beam_;
	StudsOnBeam studs_on_beam_;

	void calculate_composite_beam();
	void calculate_studs();
 };

#endif



