//---------------------------------------------------------------------------

#pragma hdrstop

#include "uComBeamInputSP35.h"
#include "uSteelTableObjects.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

ComBeamInputSP35::ComBeamInputSP35(TCompositeBeamMainFormCntrlsState const & main_frm_cntrls_state,
					 TConcreteDefinitionFormCntrlsState const & conc_frm_cntrls_state,
					 TSteelSectionFormCntrlsState const & st_sect_frm_cntrls_state,
					 TDefineSteelFormCntrlsState const & st_frm_cntrls_state,
					 TFrmRebarCntrlsState const & rebar_frm_cntrls_state)
{
	glob_geom_ = make_glob_geom(main_frm_cntrls_state);
	st_sect_ = make_steel_section(st_sect_frm_cntrls_state);
	conc_sect_ = make_concrete_section(main_frm_cntrls_state,
						  rebar_frm_cntrls_state,
						  st_sect_ -> b_f2());
	steel_ = make_steel(st_frm_cntrls_state, st_sect_ -> t_max());
	conc_ = make_concrete(conc_frm_cntrls_state);
	loads_ = make_loads(main_frm_cntrls_state,
						st_sect_ -> SW(),
						0,
						conc_sect_ -> SW(conc_.get_density()),
						glob_geom_.trib_width());
	work_cond_fctrs_ = make_working_conditions_fctrs(main_frm_cntrls_state);

}
Steel ComBeamInputSP35::make_steel(TDefineSteelFormCntrlsState const & st_frm_cntrls_state,
	double t_max)
{

	SteelTableRow const & st_table_row = steel_tables[st_frm_cntrls_state.cmb_bx_standard_index_]
													 [st_frm_cntrls_state.cmb_bx_steel_grades_index_];

	SteelData st_data = st_table_row(t_max);

	return {st_table_row.grade().c_str(),
			st_data.R_yn_,
			st_data.R_un_,
			st_frm_cntrls_state.edt_E_data_,
			st_frm_cntrls_state.edt_G_data_,
			st_frm_cntrls_state.edt_nu_data_,
			st_frm_cntrls_state.edt_dens_data_,
			st_frm_cntrls_state.edt_gamma_m_data_};
}
std::unique_ptr<GeneralConcreteSection const> ComBeamInputSP35::make_concrete_section(
	TCompositeBeamMainFormCntrlsState const & main_frm_cntrls_state,
	TFrmRebarCntrlsState const & rebar_frm_cntrls_state,
	double b_uf)
{
	std::unique_ptr<GeneralConcreteSection> conc_sect {nullptr};

	Rebars rebars{{rebar_frm_cntrls_state.cmb_bx_rebar_grade_,
				   rebar_frm_cntrls_state.edt_E_s_,
				   rebar_frm_cntrls_state.edt_diameter_,
				   rebar_frm_cntrls_state.edt_safety_factor_},

				   rebar_frm_cntrls_state.edt_a_u_,
				   rebar_frm_cntrls_state.edt_a_l_,
				   rebar_frm_cntrls_state.edt_b_,
				   rebar_frm_cntrls_state.edt_b_,};

	std::unique_ptr<GeneralConcreteSection> con_sect {nullptr};

	if (main_frm_cntrls_state.rdgrp_slab_type_data_ == 0)
	{

		conc_sect.reset(new SlabConcreteSection{main_frm_cntrls_state.edt_h_f_flat_data_,
												main_frm_cntrls_state.edt_h_n_data_,
												main_frm_cntrls_state.edt_span_data_,
												main_frm_cntrls_state.edt_width_left_data_,
												main_frm_cntrls_state.edt_width_right_data_,
												b_uf,
												main_frm_cntrls_state.chck_bx_end_beam_data_,
												rebars});
	}
	else
	{
//		conc_sect_.reset(new CorrugatedConcreteSection{CorrugatedSheetsData::get_corrugated_sheet(main_frm_cntrls_statecmb_bx_corrugated_sheeting_part_number -> Text),
//													  main_frm_cntrls_state.edt_h_f_,
//													  main_frm_cntrls_state.edt_span_,
//													  main_frm_cntrls_state.edt_width_left_,
//													  main_frm_cntrls_state.edt_width_right_,
//													  b_uf,
//													  main_frm_cntrls_state.chck_bx_end_beam_,
//													  rebars});
	}

	return conc_sect;
}
Concrete ComBeamInputSP35::make_concrete(TConcreteDefinitionFormCntrlsState
	 const & conc_frm_cntrls_state)
{
	ConcreteSP35::Data const & conc_dt = ConcreteSP35::concrete(conc_frm_cntrls_state.cmb_bx_conc_grade_index_);

	return {{ConcreteSP35::grade(conc_frm_cntrls_state.cmb_bx_conc_grade_index_).c_str(),
				conc_dt.E_b_,
				conc_dt.R_bn_,
				conc_dt.R_btn_},
			conc_frm_cntrls_state.edt_density_data_,
			conc_frm_cntrls_state.edt_phi_b_cr_data_,
			conc_frm_cntrls_state.edt_gamma_b_data_,
			conc_frm_cntrls_state.edt_gamma_bt_data_,
			conc_frm_cntrls_state.edt_epsilon_b_lim_data_};
}
std::unique_ptr<GeneralSteelSection const> ComBeamInputSP35::make_steel_section(
	TSteelSectionFormCntrlsState const & st_sect_frm_cntrls_state)
{
	std::unique_ptr<GeneralSteelSection const> st_sect {nullptr};


	if(st_sect_frm_cntrls_state.pg_cntrl_sect_type_ == 0)
		st_sect.reset(new RolledSection{st_sect_frm_cntrls_state.rd_grp_rolled_sect_type_,
										st_sect_frm_cntrls_state.cmb_bx_rolled_sect_num_});
	else
		st_sect.reset(new WeldedSection{st_sect_frm_cntrls_state.edt_b_f1_,
										st_sect_frm_cntrls_state.edt_t_f1_,
										st_sect_frm_cntrls_state.edt_b_f2_,
										st_sect_frm_cntrls_state.edt_t_f2_,
										st_sect_frm_cntrls_state.edt_h_w_,
										st_sect_frm_cntrls_state.edt_t_w_});
	return st_sect;
}
GlobGeom ComBeamInputSP35::make_glob_geom(TCompositeBeamMainFormCntrlsState const & main_frm_cntrls_state)
{
	return {main_frm_cntrls_state.edt_max_elem_length_data_,
			static_cast<bool>(main_frm_cntrls_state.chck_bx_end_beam_data_),
			main_frm_cntrls_state.edt_span_data_,
			main_frm_cntrls_state.edt_width_left_data_,
			main_frm_cntrls_state.edt_width_right_data_,
			main_frm_cntrls_state.cmb_bx_number_propping_supports_data_};
}

Loads ComBeamInputSP35::make_loads(TCompositeBeamMainFormCntrlsState const & main_frm_cntrls_state,
								   double SW_st_beam, double SW_sheets, double SW_conc, double B)
{
	return {SW_st_beam,
			0,
			SW_conc,
			main_frm_cntrls_state.edt_SW_add_concrete_data_,
			main_frm_cntrls_state.edt_dead_load_first_stage_data_,
			main_frm_cntrls_state.edt_dead_load_second_stage_data_,
			main_frm_cntrls_state.edt_live_load_data_,
			main_frm_cntrls_state.edt_gamma_f_st_SW_data_,
			main_frm_cntrls_state.edt_gamma_f_concrete_SW_data_,
			main_frm_cntrls_state.edt_gamma_f_add_concrete_SW_data_,
			main_frm_cntrls_state.edt_gamma_f_DL_I_data_,
			main_frm_cntrls_state.edt_gamma_f_DL_II_data_,
			main_frm_cntrls_state.edt_gamma_f_LL_data_,
			1,
            main_frm_cntrls_state.edt_fact_quasi_perm_load_data_,
			0,
			0,
			B};
}
WorkingConditionsFactors ComBeamInputSP35::make_working_conditions_fctrs(
TCompositeBeamMainFormCntrlsState const & main_frm_cntrls_state)
{
	return {main_frm_cntrls_state.edt_gamma_bi_data_,
			main_frm_cntrls_state.edt_gamma_si_data_,
			main_frm_cntrls_state.edt_gamma_c_data_};
}

void ComBeamInputSP35::print(TWord_Automation & report)const
{
	glob_geom_.print(report);
	work_cond_fctrs_.print(report);
	conc_.print(report);
	steel_.print(report);
	loads_.print(report);
	st_sect_ -> print_input(report);
	conc_sect_ -> print_input(report);
}
