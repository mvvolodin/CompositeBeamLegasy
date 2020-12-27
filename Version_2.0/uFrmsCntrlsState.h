//---------------------------------------------------------------------------
#ifndef uFrmsCntrlsStateH
#define uFrmsCntrlsStateH
//---------------------------------------------------------------------------
#include <ostream>
#include <istream>
//---------------------------------------------------------------------------
struct TCompositeBeamMainFormCntrlsState{
	// Геометрия
	double edt_span_data_ {17885};
	double edt_width_left_data_ {5100};
	double edt_width_right_data_{5100};
	bool chck_bx_end_beam_data_ {false};
	int cmb_bx_number_propping_supports_data_ {0};

	// Нагрузки
	double edt_SW_add_concrete_data_ {0};
	double edt_dead_load_first_stage_data_ {0};
	double edt_dead_load_second_stage_data_ {2};
	double edt_live_load_data_ {4};

	// Коэффициенты надёжности по нагрузке

	double edt_gamma_f_st_SW_data_ {1.05};
	double edt_gamma_f_concrete_SW_data_ {1.1};
	double edt_gamma_f_add_concrete_SW_data_ {1.1};
	double edt_gamma_f_DL_I_data_ {1.3};
	double edt_gamma_f_DL_II_data_ {1.2};
	double edt_gamma_f_LL_data_ {1.3};

	// Коэффициенты условий работы

	double edt_gamma_c_data_ {1};
	double edt_gamma_bi_data_ {1};
	double edt_gamma_si_data_ {1};

	// Прочие коэффициенты

	double edt_sheeting_continuity_coefficient_data_ {1.25};
	double edt_fact_quasi_perm_load_data_ {1.0};

	// Отрисовка эпюр

	int cmb_bx_impact_data_ {0};
	int rd_grp_internal_forces_type_data_ {0};

	// Параметры расчёта

	int rd_grp_code_data_ {1};
	double edt_max_elem_length_data_ {500};

	//Тип жб плиты

	int rdgrp_slab_type_data_ {0};

	//Плита по настилу

	int cmb_bx_corrugated_sheeting_part_number_data_ {4};
	double edt_h_f_data_ {95};
	bool chck_bx_wider_flange_up_data_ {false};
	bool chck_bx_sheet_orient_along_data_ {false};

	//Плита плоская

	double edt_h_f_flat_data_ {90};
	double edt_h_n_data_ {0};

	void save(ostream & os);
	void load(istream & is);

};
//---------------------------------------------------------------------------
struct TDefineSteelFormCntrlsState{

	int cmb_bx_standard_index_{0};
	int cmb_bx_steel_grades_index_{6};
	double edt_E_data_{206000};
	double edt_G_data_{79200};
	double edt_nu_data_{0.3};
	double edt_dens_data_{7850};
	double edt_gamma_m_data_{1.025};

	void save_cntls_state(ostream & os);
	void load_cntrls_state(istream & is);
};
//--------------------------------------------------------------------------
struct TConcreteDefinitionFormCntrlsState{

	int cmb_bx_conc_grade_index_{4};
	double edt_density_data_{2500};
	double edt_phi_b_cr_data_{2.3};
	double edt_gamma_b_data_{1.3};
	double edt_gamma_bt_data_{1.5};
	double edt_epsilon_b_lim_data_{0.0016};

	void save_cntls_state(ostream & os);
	void load_cntrls_state(istream & is);
};
//--------------------------------------------------------------------------
struct TFrmRebarCntrlsState{

	int cmb_bx_rebar_grade_ {0};
	double edt_E_s_ {200000};
	double edt_safety_factor_ {1.15};
	double edt_diameter_ {6};
	double edt_b_ {100};
	double edt_a_u_ {15};
	double edt_a_l_ {15};

	void save_cntls_state(ostream & os);
	void load_cntrls_state(istream & is);
};
//---------------------------------------------------------------------------
struct TStudDefinitionFormCntrlsState{

	int cmb_bx_stud_part_number_index_{52};
	double edt_stud_yield_strength_data_{350};
	double edt_stud_safety_factor_data_{1.3};
	double edt_edge_studs_dist_data_{195};
	int cmb_bx_edge_studs_rows_num_index_{1};
	bool chck_bx_more_than_one_stud_per_corrugation_edge_data_{0};
	double edt_middle_studs_dist_data_{400};
	int cmb_bx_middle_studs_rows_num_index_{0};
	bool chck_bx_more_than_one_stud_per_corrugation_middle_data_{0};

	void save_cntls_state(ostream & os);
	void load_cntrls_state(istream & is);
};
//---------------------------------------------------------------------------
struct TSteelSectionFormCntrlsState{

	double edt_b_f2_ {500};
	double edt_t_f2_ {24};
	double edt_b_f1_ {300};
	double edt_t_f1_ {12};
	double edt_h_w_  {1200};
	double edt_t_w_  {12};

	int pg_cntrl_sect_type_ {0};
	int cmb_bx_rolled_sect_num_ {47};
	int rd_grp_rolled_sect_type_ {0};

	void save_cntls_state(ostream & os);
	void load_cntrls_state(istream & is);
};
//--------------------------------------------------------------------------
#endif
















