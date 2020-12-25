//---------------------------------------------------------------------------
#pragma hdrstop
//---------------------------------------------------------------------------
#include "uFrmsCntrlsState.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
void TCompositeBeamMainFormCntrlsState::save(ostream & os)
{
	// Геометрия
	os << edt_span_data_ << '\n'
	   << edt_width_left_data_ << '\n'
	   << edt_width_right_data_ << '\n'
	   << chck_bx_end_beam_data_ << '\n'
	   << cmb_bx_number_propping_supports_data_ << '\n';
	// Нагрузки
	os << edt_SW_add_concrete_data_ << '\n'
	   << edt_dead_load_first_stage_data_ << '\n'
	   << edt_dead_load_second_stage_data_ << '\n'
	   << edt_live_load_data_ << '\n';
	// Коэффициенты надёжности по нагрузке
	os << edt_gamma_f_st_SW_data_ << '\n'
	   << edt_gamma_f_concrete_SW_data_ << '\n'
	   << edt_gamma_f_add_concrete_SW_data_ << '\n'
	   << edt_gamma_f_DL_I_data_ << '\n'
	   << edt_gamma_f_DL_II_data_ << '\n'
	   << edt_gamma_f_LL_data_ << '\n';
	// Коэффициенты условий работы
	os << edt_gamma_c_data_ << '\n'
	   << edt_gamma_bi_data_ << '\n'
	   << edt_gamma_si_data_ << '\n';
	// Прочие коэффициенты
	os << edt_sheeting_continuity_coefficient_data_ << '\n';
	os << edt_fact_quasi_perm_load_data_ << '\n';
	// Отрисовка эпюр
	os << cmb_bx_impact_data_ << '\n'
	   << rd_grp_internal_forces_type_data_ << '\n';
	// Параметры расчёта
	os << rd_grp_code_data_ << '\n'
	   << edt_max_elem_length_data_ << '\n';
	//Тип жб плиты
	os << rdgrp_slab_type_data_ << '\n';
	//Плита по настилу
	os << cmb_bx_corrugated_sheeting_part_number_data_ << '\n'
	   << edt_h_f_data_ << '\n'
	   << chck_bx_wider_flange_up_data_ << '\n'
	   << chck_bx_sheet_orient_along_data_ << '\n';
	//Плита плоская
	os << edt_h_f_flat_data_ << '\n'
	   << edt_h_n_data_ << '\n';
}
void TCompositeBeamMainFormCntrlsState::load(istream & is)
{
	// Геометрия
	is >> edt_span_data_
	   >> edt_width_left_data_
	   >> edt_width_right_data_
	   >> chck_bx_end_beam_data_
	   >> cmb_bx_number_propping_supports_data_;
	// Нагрузки
	is >> edt_SW_add_concrete_data_
	   >> edt_dead_load_first_stage_data_
	   >> edt_dead_load_second_stage_data_
	   >> edt_live_load_data_;
	// Коэффициенты надёжности по нагрузке
	is >> edt_gamma_f_st_SW_data_
	   >> edt_gamma_f_concrete_SW_data_
	   >> edt_gamma_f_add_concrete_SW_data_
	   >> edt_gamma_f_DL_I_data_
	   >> edt_gamma_f_DL_II_data_
	   >> edt_gamma_f_LL_data_;
	// Коэффициенты условий работы
	is >> edt_gamma_c_data_
	   >> edt_gamma_bi_data_
	   >> edt_gamma_si_data_;
	// Прочие коэффициенты
	is >> edt_sheeting_continuity_coefficient_data_
	   >> edt_fact_quasi_perm_load_data_;
	// Отрисовка эпюр
	is >> cmb_bx_impact_data_
	   >> rd_grp_internal_forces_type_data_;
	// Параметры расчёта
	is >> rd_grp_code_data_
	   >> edt_max_elem_length_data_;
	//Тип жб плиты
	is >> rdgrp_slab_type_data_;
	//Плита по настилу
	is >> cmb_bx_corrugated_sheeting_part_number_data_
	   >> edt_h_f_data_
	   >> chck_bx_wider_flange_up_data_
	   >> chck_bx_sheet_orient_along_data_;
	//Плита плоская
	is >> edt_h_f_flat_data_
	   >> edt_h_n_data_;

}
//---------------------------------------------------------------------------
void TDefineSteelFormCntrlsState::save_cntls_state(ostream & os)
{
	os << cmb_bx_standard_index_ << '\n'
	   << cmb_bx_steel_grades_index_ << '\n'
	   << edt_E_data_ << '\n'
	   << edt_G_data_ << '\n'
	   << edt_nu_data_ << '\n'
	   << edt_dens_data_ << '\n'
	   << edt_gamma_m_data_ << '\n';
}
void TDefineSteelFormCntrlsState::load_cntrls_state(istream & is)
{
	is >> cmb_bx_standard_index_
	   >> cmb_bx_steel_grades_index_
	   >> edt_E_data_
	   >> edt_G_data_
	   >> edt_nu_data_
	   >> edt_dens_data_
	   >> edt_gamma_m_data_;
}
void TSteelSectionFormCntrlsState::save_cntls_state(ostream & os)
{
	os << edt_b_f2_ << '\n'
	   << edt_t_f2_ << '\n'
	   << edt_b_f1_ << '\n'
	   << edt_t_f1_ << '\n'
	   << edt_h_w_  << '\n'
	   << edt_t_w_  << '\n'
	   << pg_cntrl_sect_type_ << '\n'
	   << cmb_bx_rolled_sect_num_ << '\n'
	   << rd_grp_rolled_sect_type_ << '\n';
}
void TSteelSectionFormCntrlsState::load_cntrls_state(istream & is)
{
	is >> edt_b_f2_ >> edt_t_f2_
	   >> edt_b_f1_ >> edt_t_f1_
	   >> edt_h_w_ >> edt_t_w_
	   >> pg_cntrl_sect_type_
	   >> cmb_bx_rolled_sect_num_
	   >> rd_grp_rolled_sect_type_;
}
//---------------------------------------------------------------------------
void TFrmRebarCntrlsState::save_cntls_state(ostream & os)
{
	os << cmb_bx_rebar_grade_ << '\n'
	   << edt_E_s_ << '\n'
	   << edt_safety_factor_ << '\n'
	   << edt_diameter_ << '\n'
	   << edt_b_  << '\n'
	   << edt_a_u_  << '\n'
	   << edt_a_l_ << '\n';
}
void TFrmRebarCntrlsState::load_cntrls_state(istream & is)
{
	is >> cmb_bx_rebar_grade_
	   >> edt_E_s_
	   >> edt_safety_factor_
	   >> edt_diameter_
	   >> edt_b_ >> edt_a_u_
	   >> edt_a_l_;
}
//---------------------------------------------------------------------------
void TConcreteDefinitionFormCntrlsState::save_cntls_state(ostream & os)
{
	os << cmb_bx_conc_grade_index_ << '\n'
	   << edt_density_data_ << '\n'
	   << edt_phi_b_cr_data_ << '\n'
	   << edt_gamma_b_data_ << '\n'
	   << edt_gamma_bt_data_  << '\n'
	   << edt_epsilon_b_lim_data_  << '\n';
}
void TConcreteDefinitionFormCntrlsState::load_cntrls_state(istream & is)
{
	is >> cmb_bx_conc_grade_index_
	   >> edt_density_data_
	   >> edt_phi_b_cr_data_
	   >> edt_gamma_b_data_
	   >> edt_gamma_bt_data_
	   >> edt_epsilon_b_lim_data_;
}
//---------------------------------------------------------------------------
void TStudDefinitionFormCntrlsState::save_cntls_state(ostream & os)
{
	os << cmb_bx_stud_part_number_index_ << '\n'
	   << edt_stud_yield_strength_data_ << '\n'
	   << edt_stud_safety_factor_data_ << '\n'
	   << edt_edge_studs_dist_data_ << '\n'
	   << cmb_bx_edge_studs_rows_num_index_ << '\n'
	   << chck_bx_more_than_one_stud_per_corrugation_edge_data_ << '\n'
	   << edt_middle_studs_dist_data_ << '\n'
	   << cmb_bx_middle_studs_rows_num_index_ << '\n'
	   << chck_bx_more_than_one_stud_per_corrugation_middle_data_ << '\n';
}
void TStudDefinitionFormCntrlsState::load_cntrls_state(istream & is)
{
	is >> cmb_bx_stud_part_number_index_
	   >> edt_stud_yield_strength_data_
	   >> edt_stud_safety_factor_data_
	   >> edt_edge_studs_dist_data_
	   >> cmb_bx_edge_studs_rows_num_index_
	   >> chck_bx_more_than_one_stud_per_corrugation_edge_data_
	   >> edt_middle_studs_dist_data_
	   >> cmb_bx_middle_studs_rows_num_index_
	   >> chck_bx_more_than_one_stud_per_corrugation_middle_data_;
}
