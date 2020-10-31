//---------------------------------------------------------------------------

#ifndef uComposSectCalculatorS35H
#define uComposSectCalculatorS35H

#include "uGeometry.h"
#include "uLoads.h"
#include "uSteel.h"
#include "uCompositeSectionGeometry.h"
#include "uStud.h"
#include "uRebar.h"
#include "uWorkingConditionsFactors.h"
#include "uCorrugatedSheet.h"
#include "uSection.h"
#include "uSectOutputSP35.h"
#include "uIntForcesCalculator.h"

#include <utility>

enum class DesignCase{
	Case_A,
	Case_B,
	Case_C,
};
enum class Flange{
	upper,
	lower,
};

enum class ShrinkStressIn{
	concrete,
	rebar,
};

enum class CreepStressIn{
	concrete,
	rebar,
};

class ComposSectCalculatorSP35{

public:


	ComposSectCalculatorSP35(IntForcesCalculator const & intr_frcs_calculator,
							 WorkingConditionsFactors const & work_cond_factors,
							 ComposSectGeomSP35 const & com_sect,
							 ComposSectGeomSP35 const & com_sect_shr,
							 ComposSectGeomSP35 const & com_sect_kr);

	SectOutputSP35 calculate(int const id, double const x);

private:

	IntForcesCalculator const & intr_frcs_calculator_;
	WorkingConditionsFactors const & work_cond_factors_;
	ComposSectGeomSP35 const & com_sect_;
	ComposSectGeomSP35 const & com_sect_shr_;
	ComposSectGeomSP35 const & com_sect_kr_;

	DesignCase design_case(double sigma_b, double sigma_r);
	double creep_stress(double const M_2, CreepStressIn const cr_str_in)const;
	double creep_stress(double const M_2, double const Z)const;
	double shrink_stress(ShrinkStressIn const shr_str_in) const;
	double shrink_stress(double const E, double const R, double const nu)const;


};

//---------------------------------------------------------------------------
#endif
