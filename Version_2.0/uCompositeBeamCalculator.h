//---------------------------------------------------------------------------

#ifndef uCompositeBeamCalculatorH
#define uCompositeBeamCalculatorH


#include <vector>
#include <ostream>
//---------------------------------------------------------------------------
#include "uGeometry.h"
#include "uLoads.h"

#include "uSteel.h"
#include "uCompositeSectionGeometry.h"
#include "uStud.h"
#include "uRebar.h"
#include "uWorkingConditionsFactors.h"
#include "uCorrugatedSheet.h"

#include "uCompositeBeam.h"


class CompositeBeamCalculator{
//---------------------------------------------------------------------------
public:
//---------------------------------------------------------------------------
	CompositeBeamCalculator();
	CompositeBeamCalculator(Geometry 		geometry,
				   Loads 					loads,
				   CompositeSectionGeometry composite_section,
				   StudsOnBeam              studs_on_beam,
				   WorkingConditionsFactors working_conditions_factors,
				   double 				    max_elem_length);

	void set_default_values();

	void save(std::ostream& ostr) const;
	void load(std::istream& istr);

	void calculate();

	Geometry get_geometry()const {return geometry_;}
	Loads get_loads()const {return loads_;}
	WorkingConditionsFactors get_working_conditions_factors() const {return working_conditions_factors_;}
	CompositeSectionGeometry get_composite_section()const{return composite_section_;}

	const CompositeBeam& get_composite_beam()const{return composite_beam_;}
	const StudsOnBeam& get_studs_on_beam()const{return studs_on_beam_;}
	double get_max_elem_length()const{return max_elem_length_;};

private:

	Geometry geometry_;
	Loads loads_;
	WorkingConditionsFactors working_conditions_factors_;
	CompositeSectionGeometry composite_section_;
	double max_elem_length_;

	CompositeBeam composite_beam_;
	StudsOnBeam studs_on_beam_;

	void calculate_composite_beam();
	void calculate_studs();
 };

#endif



