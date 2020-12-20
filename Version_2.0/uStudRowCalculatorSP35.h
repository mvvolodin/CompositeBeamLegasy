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
#include "uStudsInputSP35.h"
#include "uStudsOutputSP35.h"

#include "uComBeamInputSP35.h"

class StudRowCalculatorSP35{
public:
	StudRowCalculatorSP35(ComBeamInputSP35 const & input);

	StudsOutputSP35 run(StudsInputSP35 & st_input)const;
private:
	LongShearForcesCalculator calc_;

	StudRowOutputSP35 run(StudRowInputSP35 & sri, StudSP35 & st)const;

};
//---------------------------------------------------------------------------
#endif
