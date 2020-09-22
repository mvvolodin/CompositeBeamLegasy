//---------------------------------------------------------------------------

#pragma hdrstop

#include "uCompositeBeamCalculatorBridge.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

class CS_beam; // acronym CompositeSectionBeam

CompositeBeamOutput calculate_composite_beam(const CompositeBeamInput& cb_input)
{
	const Geometry geom = cb_input.geom_;
	const Loads loads = cb_input.loads_;
	const WorkingConditionsFactors wc_factors_ = cb_input.wc_factors_;
	const Steel steel = cb_input.loads_;
	const ISection st_sect = cb_input.st_sect_;
	const Concrete concrete = cb_input.concrete_;
	const ISection conc_sect = cb_input.conc_sect_;
	const Rebar rebar = cb_input.rebar_;

	CompositeBeamOutput cb_output{};


	CompositeSectionGeometry const com_sect{st_sect, steel,
											conc_sect, concrete,
											rebar,
											B_l,B_r, l, a // параметры для расчёт эффективной ширины
											};
	cb_output.set_com_sect(com_sect);

	InternalForcesCalculator& int_fr_clc;

	CS_Beam cs_sect{int id, double x, int_fr_clc, com_sect};

	CS_Beam cs_sect{int id, double x, int_fr_clc, }

	CompositeBeam com_beam;

    void set_intr_frcs_calculator(InternalForcesCalculator& intr_frcs_calculator);
	void set_composite_section(CompositeSectionGeometry& com_sect);
	void set_working_conditions_factors(WorkingConditionsFactors& working_conditions_factors);
	void initialize_section_list(double L, SupportsNumber temporary_supports_number, double max_elem_length);
}
