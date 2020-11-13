//---------------------------------------------------------------------------

#pragma hdrstop

#include "uFrmsCntrlsState.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
void TCompositeBeamMainFormCntrlsState::save(ostream & os)
{
	// Геометрия
	os << edt_span_ << '\n'
	   << edt_width_left_ << '\n'
	   << edt_width_right_ << '\n'
	   << chck_bx_end_beam_ << '\n'
	   << cmb_bx_number_propping_supports_ << '\n';
	// Нагрузки
	os << edt_SW_add_concrete_ << '\n'
	   << edt_dead_load_first_stage_ << '\n'
	   << edt_dead_load_second_stage_ << '\n'
	   << edt_live_load_ << '\n';
	// Коэффициенты надёжности по нагрузке
	os << edt_gamma_f_st_SW_ << '\n'
	   << edt_gamma_f_concrete_SW_ << '\n'
	   << edt_gamma_f_add_concrete_SW_ << '\n'
	   << edt_gamma_f_DL_I_ << '\n'
	   << edt_gamma_f_DL_II_ << '\n'
	   << edt_gamma_f_LL_ << '\n';
	// Коэффициенты условий работы
	os << edt_gamma_c_ << '\n'
	   << edt_gamma_bi_ << '\n'
	   << edt_gamma_si_ << '\n';
	// Коэффициенты учёт неразрезности настила
	os << edt_sheeting_continuity_coefficient_ << '\n';
	// Отрисовка эпюр
	os << cmb_bx_impact_ << '\n'
	   << rd_grp_internal_forces_type_ << '\n';
	// Параметры расчёта
	os << rd_grp_code_ << '\n'
	   << edt_max_elem_length_ << '\n';
	//Тип жб плиты
	os << rdgrp_slab_type_ << '\n';
	//Плита по настилу
	os << cmb_bx_corrugated_sheeting_part_number_ << '\n'
	   << edt_h_f_ << '\n'
	   << chck_bx_wider_flange_up_ << '\n'
	   << chck_bx_sheet_orient_along_ << '\n';
	//Плита плоская
	os << edt_h_f_flat_ << '\n'
	   << edt_h_n_ << '\n';
}
void TCompositeBeamMainFormCntrlsState::load(istream & is)
{
	// Геометрия
	is >> edt_span_
	   >> edt_width_left_
	   >> edt_width_right_
	   >> chck_bx_end_beam_
	   >> cmb_bx_number_propping_supports_;
	// Нагрузки
	is >> edt_SW_add_concrete_
	   >> edt_dead_load_first_stage_
	   >> edt_dead_load_second_stage_
	   >> edt_live_load_;
	// Коэффициенты надёжности по нагрузке
	is >> edt_gamma_f_st_SW_
	   >> edt_gamma_f_concrete_SW_
	   >> edt_gamma_f_add_concrete_SW_
	   >> edt_gamma_f_DL_I_
	   >> edt_gamma_f_DL_II_
	   >> edt_gamma_f_LL_;
	// Коэффициенты условий работы
	is >> edt_gamma_c_
	   >> edt_gamma_bi_
	   >> edt_gamma_si_;
	// Коэффициенты учёт неразрезности настила
	is >> edt_sheeting_continuity_coefficient_;
	// Отрисовка эпюр
	is >> cmb_bx_impact_
	   >> rd_grp_internal_forces_type_;
	// Параметры расчёта
	is >> rd_grp_code_
	   >> edt_max_elem_length_;
	//Тип жб плиты
	is >> rdgrp_slab_type_;
	//Плита по настилу
	is >> cmb_bx_corrugated_sheeting_part_number_
	   >> edt_h_f_
	   >> chck_bx_wider_flange_up_
	   >> chck_bx_sheet_orient_along_;
	//Плита плоская
	is >> edt_h_f_flat_
	   >> edt_h_n_;

}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
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
