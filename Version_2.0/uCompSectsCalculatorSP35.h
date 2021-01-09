//---------------------------------------------------------------------------

#ifndef uCompSectsCalculatorSP35H
#define uCompSectsCalculatorSP35H
//---------------------------------------------------------------------------
#include <vector>
#include <string>
#include "uCompSectOutputSP266.h"
#include "uCompSectsOutputSP35.h"

#include "uGlobGeom.h"
#include "uIntForcesCalculator.h"
#include "uCompSectGeomSP266.h"
#include "uPlastCoeff.h"

#include "uWorkingConditionsFactors.h"

#include "uCompBeamObjsCreatorSP35.h"

enum class DesignCaseSP35{
	Case_A,
	Case_B,
	Case_C,
	Case_F // случай, когда в бетоне растяжение
};
enum class Flange{
	upper,
	lower,
};

enum class ShrinkStressIn{
	concrete,
	rebar,
};
//---------------------------------------------------------------------------
enum class CreepStressIn{
	concrete,
	rebar,
};
//---------------------------------------------------------------------------

class CompSectsCalculatorSP35{
public:
	CompSectsCalculatorSP35 (CompBeamObjsCreatorSP35 const & creator);
	CompSectsOutputSP35 run();
private:
	CompBeamObjsCreatorSP35 const creator_;

	IntForcesCalculator const intr_frcs_calculator_;
	WorkingConditionsFactors const work_cond_factors_;
	CompSectGeomSP35 const com_sect_;
	CompSectGeomSP35 const com_sect_shr_;
	CompSectGeomSP35 const com_sect_kr_;

	DesignCaseSP35 design_case(double sigma_b, double sigma_r);
	CompSectOutputSP35 calculate(Node const & node);
	double creep_stress(double const M, CreepStressIn const cr_str_in)const;
	double shrink_stress(ShrinkStressIn const shr_str_in) const;
	double shrink_stress(double const E, double const R, double const nu)const;
};
#endif

