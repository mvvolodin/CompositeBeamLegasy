//---------------------------------------------------------------------------

#ifndef uComBeamInputSP35H
#define uComBeamInputSP35H

#include <memory>
#include "uGlobGeom.h"
#include "uLoads.h"
#include "uGeneralSteelSection.h"
#include "uWeldedSection.h"
#include "uRolledSection.h"
#include "uGeneralConcreteSection.h"
#include "uSlabConcreteSection.h"
#include "uCorrugatedConcreteSection.h"
#include "uConcrete.h"
#include "uSteel.h"
#include "uFrmsCntrlsState.h"
#include "uWorkingConditionsFactors.h"


class ComBeamInputSP35{
public:
	ComBeamInputSP35(TCompositeBeamMainFormCntrlsState const & main_frm_cntrls_state,
					 TConcreteDefinitionFormCntrlsState const & conc_frm_cntrls_state,
					 TSteelSectionFormCntrlsState const & st_sect_frm_cntrls_state,
					 TDefineSteelFormCntrlsState const & st_frm_cntrls_state,
					 TFrmRebarCntrlsState const & rebar_frm_cntrls_state);

	void print_data_to_report();

private:

	GlobGeom glob_geom_;
	Loads loads_;
	std::unique_ptr<GeneralSteelSection const> st_sect_;
	std::unique_ptr<GeneralConcreteSection const> conc_sect_;
	Concrete conc_;
	Steel steel_;
	WorkingConditionsFactors work_cond_fctrs_;

	Loads make_loads(TCompositeBeamMainFormCntrlsState const & main_frm_cntrls_state,
			   double SW_st_beam, double SW_sheets, double SW_conc, double B);
	GlobGeom make_glob_geom(TCompositeBeamMainFormCntrlsState const & main_frm_cntrls_state);
	void make_steel_section(TSteelSectionFormCntrlsState const & st_sect_frm_cntrls_state);
	Concrete make_concrete(TConcreteDefinitionFormCntrlsState
	 const & conc_frm_cntrls_state);
	Steel make_steel(TDefineSteelFormCntrlsState const & st_frm_cntrls_state,
		double t_max);
	void make_concrete_section(TCompositeBeamMainFormCntrlsState const & main_frm_cntrls_state,
		TFrmRebarCntrlsState const & rebar_frm_cntrls_state,
		double b_uf);
	WorkingConditionsFactors make_working_conditions_fctrs(
		TCompositeBeamMainFormCntrlsState const & main_frm_cntrls_state);



};


//---------------------------------------------------------------------------
#endif
