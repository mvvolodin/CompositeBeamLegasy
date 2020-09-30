//---------------------------------------------------------------------------

#ifndef uCompositeBeamCalculatorBridgeH
#define uCompositeBeamCalculatorBridgeH

#include "uGeometry.h"
#include "uLoads.h"
#include "uSteel.h"
#include "uCompositeSectionGeometry.h"
#include "uStud.h"
#include "uRebar.h"
#include "uWorkingConditionsFactors.h"
#include "uCorrugatedSheet.h"
#include "uSection.h"

#include <utility>

class CompositeBeamSection; //class CBSection::class CSGeometry;

class CompositeBeamInput{
	private:
		const Geometry geom_;
		const Loads loads_;
		const WorkingConditionsFactors wc_factors_;
		const Steel steel_;
		const ISection st_sect_;
		const Concrete concrete_;
		const ISection conc_sect_;
		const Rebar rebar_;
	CompositeBeamInput(const Geometry&& geom,
					   const Loads&& loads,
					   const WorkingConditionsFactors&& wc_factors,
					   const Steel&& steel,
					   const ISection&& st_sect,
					   const Concrete&& concrete,
					   const ISection&& conc_sect,
					   const Rebar&& rebar):
						geom_(std::move(geom)),
						loads_(std::move(loads)),
						wc_factors_(std::move(wc_factors)),
						steel_(std::move(steel)),
						concrete_(std::move(concrete)),
						rebar_(std::move(rebar))
	{
		 //st_sect deep copy required
         // conc_sect deep copy required
    }


};

class CompositeBeamOutput{

	private:
		std::vector<Section> sect_lst_;
		CompositeSectionGeometry com_sect_geometry_;

};


CompositeBeamOutput calculate_composite_beam(const CompositeBeamInput& cb_input);


CompositeBeamOutput calculate_composite_beam( const Geometry& geom,
											  const Loads& loads,
											  const WorkingConditionsFactors& wc_factors,
											  const Steel& steel,
											  const ISection& st_sect,
											  const Concrete& concrete,
											  const ISection& conc_sect,
											  const Rebar& rebar)
{
	CompositeBeamOutput cb_output{};

	CompositeSectionGeometry2 com_sect{st_sect, steel,
									  conc_sect, concrete,
									  rebar};
	CompositeBeam com_beam;

    void set_intr_frcs_calculator(InternalForcesCalculator& intr_frcs_calculator);
	void set_composite_section(CompositeSectionGeometry& com_sect);
	void set_working_conditions_factors(WorkingConditionsFactors& working_conditions_factors);
	void initialize_section_list(double L, SupportsNumber temporary_supports_number, double max_elem_length);

}

class CompositeBeamCalculatorBridge{

public:
	CompositeBeamCalculatorBridge(const Geometry& geom,
								  const Loads& loads,
								  const WorkingConditionsFactors& wc_factors,
								  const SteelPart& steel_part,
								  const ConcretePart& concrete_part);

	CompositeBeamCalculatorBridge(const Geometry& geom,
								  const Loads& loads,
								  const WorkingConditionsFactors& wc_factors,
								  const Steel& steel,
								  const ISection& st_sect,
								  const Concrete& concrete,
								  const ISection& conc_sect,
								  const Rebar& rebar);
	CompositeBeamCalculatorBridge(const InputData& input_data);



	CompositeBeamOutput calculate();//

	CompositeBeamOutput calculate(CompositeBeamInput);

private:



};

//---------------------------------------------------------------------------
#endif
