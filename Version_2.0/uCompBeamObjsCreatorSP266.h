//---------------------------------------------------------------------------

#ifndef uCompBeamObjsCreatorSP266H
#define uCompBeamObjsCreatorSP266H

#include <memory>
#include "uFrmsCntrlsState.h"

#include "uGlobGeom.h"
#include "uLoads.h"

#include "uGeneralSteelSection.h"
#include "uRolledSection.h"
#include "uWeldedSection.h"

#include "uGeneralConcreteSection.h"
#include "uSlabConcreteSection.h"
#include "uCorrugatedConcreteSection.h"

#include "uConcrete.h"
#include "uSteel.h"
#include "uWorkingConditionsFactors.h"

#include "uCompSectGeomSP266.h"
#include "uIntForcesCalculator.h"

#include "uStudsSP266.cpp"

class CompBeamObjsCreatorSP266{

public:
	using SteelSectUPtr = std::unique_ptr<GeneralSteelSection>;
	using ConcSectUPtr = std::unique_ptr<GeneralConcreteSection>;

	CompBeamObjsCreatorSP266() = delete;
	CompBeamObjsCreatorSP266(
		TCompositeBeamMainFormCntrlsState const & main_frm_cntrls_state,
		TConcreteDefinitionFormCntrlsState const & conc_frm_cntrls_state,
		TSteelSectionFormCntrlsState const & st_sect_frm_cntrls_state,
		TDefineSteelFormCntrlsState const & st_frm_cntrls_state,
		TFrmRebarCntrlsState const & rebar_frm_cntrls_state,
		TStudDefinitionFormCntrlsState const & studs_frm_cntrls_state);

	GlobGeom glob_geometry()const;
	Loads loads()const;
	SteelSectUPtr steel_sect()const;
	ConcSectUPtr concrete_sect()const;
	Steel steel()const;
	Concrete concrete()const;
	WorkingConditionsFactors work_cond_factrs()const;
	StudsSP266 studs()const;

	CompSectGeomSP266 comp_sect_geom(bool is_Eb_reduced)const;
	IntForcesCalculator int_forces_calculator()const;

private:
	TCompositeBeamMainFormCntrlsState const main_frm_cntrls_state_;
	TConcreteDefinitionFormCntrlsState const conc_frm_cntrls_state_;
	TSteelSectionFormCntrlsState const st_sect_frm_cntrls_state_;
	TDefineSteelFormCntrlsState const st_frm_cntrls_state_;
	TFrmRebarCntrlsState const rebar_frm_cntrls_state_;
	TStudDefinitionFormCntrlsState const studs_frm_cntrls_state_;
};

//---------------------------------------------------------------------------
#endif
