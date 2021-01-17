//---------------------------------------------------------------------------
#ifndef uStudsSP35CalculatorH
#define uStudsSP35CalculatorH

#include "uCompBeamObjsCreatorSP35.h"

#include "uIntForcesCalculator.h"
#include "uCompSectGeomSP35.h"
#include "uGlobGeom.h"

#include "uLongShearForcesCalculatorSP35.h"

#include "uStudRowSP35.h"
#include "uStudsSP35.h"

#include "uStudRowSP35Calculated.h"
#include "uStudsSP35Calculated.h"

class StudsSP35Calculator{
public:
	StudsSP35Calculator(CompBeamObjsCreatorSP35 const & creator);
	StudsSP35Calculated run()const;
private:
	CompBeamObjsCreatorSP35 creator_;
	LongShearForcesCalculatorSP35 calc_;

	StudRowSP35Calculated run(StudRowSP35 const & sr, StudSP35 const & s)const;
};
//---------------------------------------------------------------------------
#endif
