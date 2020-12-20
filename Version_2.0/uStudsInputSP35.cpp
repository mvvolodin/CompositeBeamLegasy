//---------------------------------------------------------------------------
#pragma hdrstop
//---------------------------------------------------------------------------
#include "uStudsInputSP35.h"
#include <cmath>
#include "uStudsGOSTR55738.h"
#include "uConcrete.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

StudSP35 StudsInputSP35::stud_;

StudsInputSP35::StudsInputSP35(TStudDefinitionFormCntrlsState const & st_frm_cntrls_state,
							   TCompositeBeamMainFormCntrlsState const & main_frm_cntrls_state,
							   TConcreteDefinitionFormCntrlsState const & con_frm_cntrls_state)

{

	stud_ = {StudsGOSTR55738::name(st_frm_cntrls_state.cmb_bx_stud_part_number_index_),
			 StudsGOSTR55738::d_1(st_frm_cntrls_state.cmb_bx_stud_part_number_index_),
			 StudsGOSTR55738::l_1(st_frm_cntrls_state.cmb_bx_stud_part_number_index_),
			 st_frm_cntrls_state.edt_stud_yield_strength_data_,
			 ConcreteSP35::R_b(con_frm_cntrls_state.cmb_bx_conc_grade_index_),
			 st_frm_cntrls_state.edt_stud_safety_factor_data_};

	rows_ = set_rows(main_frm_cntrls_state.edt_span_data_,
					 st_frm_cntrls_state.edt_edge_studs_dist_data_,
					 st_frm_cntrls_state.edt_middle_studs_dist_data_,
					 st_frm_cntrls_state.cmb_bx_edge_studs_rows_num_index_,
					 st_frm_cntrls_state.cmb_bx_middle_studs_rows_num_index_);
}

std::vector<StudRowInputSP35> StudsInputSP35::set_rows(double L, double d_e,
	double d_m, int num_e, int num_m)
{
	std::vector<StudRowInputSP35> v;

	const double L3 = L/3;

	int n_e;

	if (std::lround(L3) % std::lround(d_e))
		n_e = L3 / d_e + 1 ;
	else
		n_e = L3 / d_e;

	v.emplace_back(0, 0, 0, num_e);

	for(int i = 1; i < n_e; ++ i)
		v.emplace_back( i * L3 / n_e,
						i * L3 / n_e - (L3 / n_e) / 2,
						i * L3 / n_e + (L3 / n_e) / 2,
						num_e);

	int n_m;

	if (std::lround(L3) % std::lround(d_m))
		n_m = L3 / d_m + 1;
	else
		n_m = L3 / d_m;

	v.emplace_back(L3, L3 - (L3 / n_e) / 2, L3 + (L3 / n_m) / 2, num_m);

	for(int i = 1; i < n_m; ++ i)
		v.emplace_back( L3 + i * L3 / n_m,
						L3 + i * L3 / n_m - (L3 / n_m) / 2,
						L3 + i * L3 / n_m + (L3 / n_m) / 2,
						num_m);

	v.emplace_back(2* L3, 2 * L3 - (L3 / n_m) / 2, 2 * L3 + (L3 / n_m) / 2, num_m);

	for(int i = 1; i < n_e; ++ i)
		v.emplace_back( 2 * L3 + i * L3 / n_e,
						2 * L3 + i * L3 / n_e - (L3 / n_e) / 2,
						2 * L3 + i * L3 / n_e + (L3 / n_e) / 2,
						num_e);

	v.emplace_back(L, L, L, num_e);

	return v;
}




