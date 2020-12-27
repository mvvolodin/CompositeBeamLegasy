//---------------------------------------------------------------------------

#ifndef uStudsSP266CalculatorH
#define uStudsSP266CalculatorH

#include "uCompBeamObjsCreatorSP266.h"

#include "uIntForcesCalculator.h"
#include "uCompSectGeomSP266.h"
#include "uGlobGeom.h"

#include "uLongShearForcesCalculatorSP266.h"

#include "uStudRowSP266.h"
#include "uStudsSP266.h"

#include "uStudRowSP266Calculated.h"
#include "uStudsSP266Calculated.h"

class StudsSP266Calculator{
public:
	StudsSP266Calculator(CompBeamObjsCreatorSP266 const & creator);
	StudsSP266Calculated run()const;
private:
	CompBeamObjsCreatorSP266 creator_;
	LongShearForcesCalculatorSP266 calc_;

	StudRowSP266Calculated run(StudRowSP266 const & sr, StudSP266 const & s)const;
};
//---------------------------------------------------------------------------
#endif
