//---------------------------------------------------------------------------

#pragma hdrstop

#include "uCompBeamObjsCreatorSP266.h"
#include "uSteelTableObjects.h"
#include "uStudsGOSTR55738.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

CompBeamObjsCreatorSP266::CompBeamObjsCreatorSP266(
	TCompositeBeamMainFormCntrlsState const & main_frm_cntrls_state,
	TConcreteDefinitionFormCntrlsState const & conc_frm_cntrls_state,
	TSteelSectionFormCntrlsState const & st_sect_frm_cntrls_state,
	TDefineSteelFormCntrlsState const & st_frm_cntrls_state,
	TFrmRebarCntrlsState const & rebar_frm_cntrls_state,
	TStudDefinitionFormCntrlsState const & studs_frm_cntrls_state):
		main_frm_cntrls_state_(main_frm_cntrls_state),
		conc_frm_cntrls_state_(conc_frm_cntrls_state),
		st_sect_frm_cntrls_state_(st_sect_frm_cntrls_state),
		st_frm_cntrls_state_(st_frm_cntrls_state),
		rebar_frm_cntrls_state_(rebar_frm_cntrls_state),
		studs_frm_cntrls_state_(studs_frm_cntrls_state){}

GlobGeom CompBeamObjsCreatorSP266::glob_geometry()const
{
	return {main_frm_cntrls_state_.edt_max_elem_length_data_,
			static_cast<bool>(main_frm_cntrls_state_.chck_bx_end_beam_data_),
			main_frm_cntrls_state_.edt_span_data_,
			main_frm_cntrls_state_.edt_width_left_data_,
			main_frm_cntrls_state_.edt_width_right_data_,
			main_frm_cntrls_state_.cmb_bx_number_propping_supports_data_};
}
Loads CompBeamObjsCreatorSP266::loads()const
{
	SteelSectUPtr const st_sect {steel_sect()};
	ConcSectUPtr const conc_sect {concrete_sect()};
	ConcreteSP266 const conc {concrete()};
	GlobGeom glob_geom {glob_geometry()};

	if (main_frm_cntrls_state_.rdgrp_slab_type_data_ == 0)
		return {st_sect -> SW(),
				0,
				conc_sect -> SW(conc.dens()),
				main_frm_cntrls_state_.edt_SW_add_concrete_data_,
				main_frm_cntrls_state_.edt_dead_load_first_stage_data_,
				main_frm_cntrls_state_.edt_dead_load_second_stage_data_,
				main_frm_cntrls_state_.edt_live_load_data_,
				main_frm_cntrls_state_.edt_gamma_f_st_SW_data_,
				main_frm_cntrls_state_.edt_gamma_f_concrete_SW_data_,
				main_frm_cntrls_state_.edt_gamma_f_add_concrete_SW_data_,
				main_frm_cntrls_state_.edt_gamma_f_DL_I_data_,
				main_frm_cntrls_state_.edt_gamma_f_DL_II_data_,
				main_frm_cntrls_state_.edt_gamma_f_LL_data_,
				1,
				main_frm_cntrls_state_.edt_fact_quasi_perm_load_data_,
				0,
				0,
				glob_geom.trib_width()};
	else
		return {st_sect -> SW(),
				static_cast<CorrugatedConcreteSection*>(conc_sect.get()) ->
					corrugated_sheet().get_weight() ,
				conc_sect -> SW(conc.dens()),
				main_frm_cntrls_state_.edt_SW_add_concrete_data_,
				main_frm_cntrls_state_.edt_dead_load_first_stage_data_,
				main_frm_cntrls_state_.edt_dead_load_second_stage_data_,
				main_frm_cntrls_state_.edt_live_load_data_,
				main_frm_cntrls_state_.edt_gamma_f_st_SW_data_,
				main_frm_cntrls_state_.edt_gamma_f_concrete_SW_data_,
				main_frm_cntrls_state_.edt_gamma_f_add_concrete_SW_data_,
				main_frm_cntrls_state_.edt_gamma_f_DL_I_data_,
				main_frm_cntrls_state_.edt_gamma_f_DL_II_data_,
				main_frm_cntrls_state_.edt_gamma_f_LL_data_,
				main_frm_cntrls_state_.edt_sheeting_continuity_coefficient_data_,
				main_frm_cntrls_state_.edt_fact_quasi_perm_load_data_,
				0,
				0,
				glob_geom.trib_width()};
}
CompBeamObjsCreatorSP266::SteelSectUPtr
	CompBeamObjsCreatorSP266::steel_sect()const
{
	if(st_sect_frm_cntrls_state_.pg_cntrl_sect_type_ == 0)
		return std::make_unique<RolledSection>(
			st_sect_frm_cntrls_state_.rd_grp_rolled_sect_type_,
			st_sect_frm_cntrls_state_.cmb_bx_rolled_sect_num_);
	else
		return std::make_unique<WeldedSection>(
			st_sect_frm_cntrls_state_.edt_b_f1_,
			st_sect_frm_cntrls_state_.edt_t_f1_,
			st_sect_frm_cntrls_state_.edt_b_f2_,
			st_sect_frm_cntrls_state_.edt_t_f2_,
			st_sect_frm_cntrls_state_.edt_h_w_,
			st_sect_frm_cntrls_state_.edt_t_w_);
}
CompBeamObjsCreatorSP266::ConcSectUPtr
	CompBeamObjsCreatorSP266::concrete_sect()const
{
	Rebars rebars{{rebar_frm_cntrls_state_.cmb_bx_rebar_grade_,
				   rebar_frm_cntrls_state_.edt_E_s_,
				   rebar_frm_cntrls_state_.edt_diameter_,
				   rebar_frm_cntrls_state_.edt_safety_factor_},

				   rebar_frm_cntrls_state_.edt_a_u_,
				   rebar_frm_cntrls_state_.edt_a_l_,
				   rebar_frm_cntrls_state_.edt_b_,
				   rebar_frm_cntrls_state_.edt_b_,};

	SteelSectUPtr const st_sect {steel_sect()};

	if (main_frm_cntrls_state_.rdgrp_slab_type_data_ == 0)
		return std::make_unique<SlabConcreteSection>(
			main_frm_cntrls_state_.edt_h_f_flat_data_,
			main_frm_cntrls_state_.edt_h_n_data_,
			main_frm_cntrls_state_.edt_span_data_,
			main_frm_cntrls_state_.edt_width_left_data_,
			main_frm_cntrls_state_.edt_width_right_data_,
			st_sect -> upper_fl_width(),
			main_frm_cntrls_state_.chck_bx_end_beam_data_,
			rebars);
	else
		return std::make_unique<CorrugatedConcreteSection>(
			CorrugatedSheetsData::get_corrugated_sheet(
				main_frm_cntrls_state_.cmb_bx_corrugated_sheeting_part_number_data_),
			main_frm_cntrls_state_.edt_h_f_data_,
			main_frm_cntrls_state_.edt_span_data_,
			main_frm_cntrls_state_.edt_width_left_data_,
			main_frm_cntrls_state_.edt_width_right_data_,
			st_sect -> upper_fl_width(),
			main_frm_cntrls_state_.chck_bx_end_beam_data_,
			rebars);
}
Steel CompBeamObjsCreatorSP266::steel()const
{
	SteelTableRow const & st_table_row {steel_tables[st_frm_cntrls_state_.cmb_bx_standard_index_]
													[st_frm_cntrls_state_.cmb_bx_steel_grades_index_]};

	SteelSectUPtr const st_sect {steel_sect()};
	SteelData const & st_data {st_table_row(st_sect -> t_max())};

	return {st_table_row.grade().c_str(),
			st_data.R_yn_,
			st_data.R_un_,
			st_frm_cntrls_state_.edt_E_data_,
			st_frm_cntrls_state_.edt_G_data_,
			st_frm_cntrls_state_.edt_nu_data_,
			st_frm_cntrls_state_.edt_dens_data_,
			st_frm_cntrls_state_.edt_gamma_m_data_};
}
WorkingConditionsFactors CompBeamObjsCreatorSP266::work_cond_factrs()const
{
	return {main_frm_cntrls_state_.edt_gamma_bi_data_,
			main_frm_cntrls_state_.edt_gamma_si_data_,
			main_frm_cntrls_state_.edt_gamma_c_data_};
}
CompSectGeomSP266 CompBeamObjsCreatorSP266::comp_sect_geom(bool is_Eb_reduced)const
{
	return {steel(),
			steel_sect(),
			concrete(),
			concrete_sect(),
			is_Eb_reduced};
}
IntForcesCalculator CompBeamObjsCreatorSP266::int_forces_calculator()const
{
	GlobGeom const glob_geom = glob_geometry();

	return{glob_geom.tmp_sup_num(),
		   glob_geom.span(),
		   loads()};
}
StudsSP266 CompBeamObjsCreatorSP266::studs()const
{
	GlobGeom const glob_geom {glob_geometry()};
	ConcreteSP266 const conc {concrete()};

	int const st_index = studs_frm_cntrls_state_.cmb_bx_stud_part_number_index_;

	StudSP266 stud {StudsGOSTR55738::name(st_index),
					StudsGOSTR55738::d_1(st_index),
					StudsGOSTR55738::l_1(st_index),
					studs_frm_cntrls_state_.edt_stud_yield_strength_data_,
					conc.R_b(),
					studs_frm_cntrls_state_.edt_stud_safety_factor_data_};

	bool const is_corr_slab =
		(main_frm_cntrls_state_.rdgrp_slab_type_data_ == 0)? false: true;

	return{stud,
		   glob_geom.span(),
		   studs_frm_cntrls_state_.edt_edge_studs_dist_data_,
		   studs_frm_cntrls_state_.edt_middle_studs_dist_data_,
		   studs_frm_cntrls_state_.cmb_bx_edge_studs_rows_num_index_ + 1,
		   studs_frm_cntrls_state_.cmb_bx_middle_studs_rows_num_index_ + 1,
		   studs_frm_cntrls_state_.chck_bx_more_than_one_stud_per_corrugation_edge_data_,
		   studs_frm_cntrls_state_.chck_bx_more_than_one_stud_per_corrugation_middle_data_,
		   is_corr_slab,
		   CorrugatedSheetsData::get_corrugated_sheet(
				main_frm_cntrls_state_.cmb_bx_corrugated_sheeting_part_number_data_),
		   main_frm_cntrls_state_.chck_bx_wider_flange_up_data_,
		   main_frm_cntrls_state_.chck_bx_sheet_orient_along_data_};
}
ConcreteSP266 CompBeamObjsCreatorSP266::concrete()const
{
	return {conc_frm_cntrls_state_.cmb_bx_conc_grade_index_,
		conc_frm_cntrls_state_.edt_epsilon_b_lim_data_,
		conc_frm_cntrls_state_.edt_phi_b_cr_data_,
		conc_frm_cntrls_state_.edt_density_data_,
		conc_frm_cntrls_state_.edt_gamma_b_data_,
		conc_frm_cntrls_state_.edt_gamma_bt_data_};
}





