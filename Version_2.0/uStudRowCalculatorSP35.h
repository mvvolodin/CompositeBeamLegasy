//---------------------------------------------------------------------------

#ifndef uStudRowCalculatorSP35H
#define uStudRowCalculatorSP35H

#include <memory>
#include "uFrmsCntrlsState.h"
#include "uGlobGeom.h"
#include "uLoads.h"
#include "uGeneralSteelSection.h"
#include "uWeldedSection.h"
#include "uRolledSection.h"
#include "uGeneralConcreteSection.h"
#include "uSlabConcreteSection.h"
#include "uConcrete.h"
#include "uSteel.h"
#include "uWorkingConditionsFactors.h"
#include "uLongShearForcesCalculator.h"
#include "uStudRowInputSP35_.h"
#include "uStudRowOutputSP35.h"

#include "uComBeamInputSP35.h"

class StudRowCalculatorSP35{
public:
	StudRowCalculatorSP35(ComBeamInputSP35 const & input);

	StudRowOutputSP35 run(StudRowInputSP35 & sr)const;
	std::vector<StudRowInputSP35> run(std::vector<StudRowInputSP35>  stud_rows_input)const;

private:
	LongShearForcesCalculator calc_;

};
//---------------------------------------------------------------------------
#endif
