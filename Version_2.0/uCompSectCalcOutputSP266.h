//---------------------------------------------------------------------------
#ifndef uCompSectCalcOutputSP266H
#define uCompSectCalcOutputSP266H
//---------------------------------------------------------------------------
#include "uFrmsCntrlsState.h"

#include "uGlobGeom.h"
#include "uLoads.h"
#include "uWorkingConditionsFactors.h"
#include "uCompSectGeomSP266.h"
#include "uCompSectOutputSP266.h"
//---------------------------------------------------------------------------
class CompSectCalcOutputSP266{
public:
	GlobGeom const glob_geom_const;
	Loads const loads_;
	WorkingConditionsFactors const work_cond_factrs_ ;

	CompSectGeomSP266 const comp_sect_geom_;
	std::vector<CompSectOutputSP266> const com_sects_output_;

};
//---------------------------------------------------------------------------
#endif


//{cso,
//		   glob_geom,
//		   creator_.comp_sect_geom(),
//		   cso,
//		   glob_geom,
//		   creator_.loads(),
//		   creator_.steel_sect(),
//		   creator_.concrete_sect(),
//		   creator_.concrete(),
//		   creator_.work_cond_factrs()};
