//---------------------------------------------------------------------------

#ifndef uFrmsCntrlsStateH
#define uFrmsCntrlsStateH
//---------------------------------------------------------------------------
#include <ostream>
#include <istream>
#include "String_doubleUnit.h"
//---------------------------------------------------------------------------
struct TCompositeBeamMainFormCntrlsState{
	// Геометрия
	double edt_span_ {8000};
	double edt_width_left_ {3000};
	double edt_width_right_{3000};
	bool chck_bx_end_beam_ {false};
	int cmb_bx_number_propping_supports_ {0};

	// Нагрузки
	double edt_SW_add_concrete_ {0.26};
	double edt_dead_load_first_stage_ {0.5};
	double edt_dead_load_second_stage_ {2};
	double edt_live_load_ {4};

	// Коэффициенты надёжности по нагрузке

	double edt_gamma_f_st_SW_ {1.05};
	double edt_gamma_f_concrete_SW_ {1.2};
	double edt_gamma_f_add_concrete_SW_ {1.1};
	double edt_gamma_f_DL_I_ {1.3};
	double edt_gamma_f_DL_II_ {1.2};
	double edt_gamma_f_LL_ {1.2};

	// Коэффициенты условий работы

	double edt_gamma_c_ {1};
	double edt_gamma_bi_ {1};
	double edt_gamma_si_ {1};

	// Коэффициенты учёт неразрезности настила

	double edt_sheeting_continuity_coefficient_ {1.25};

	// Отрисовка эпюр

	int cmb_bx_impact_ {4};
	int rd_grp_internal_forces_type_ {0};

	// Параметры расчёта

	int rd_grp_code_ {1};
	double edt_max_elem_length_ {100};

	//Тип жб плиты

	int rdgrp_slab_type_ {1};

	//Плита по настилу

	int cmb_bx_corrugated_sheeting_part_number_ {4};
	double edt_h_f_ {95};
	bool chck_bx_wider_flange_up_ {false};
	bool chck_bx_sheet_orient_along_ {false};

	//Плита плоская

	double edt_h_f_flat_ {95};
	double edt_h_n_ {75};

	void save(ostream & os);
	void load(istream & is);

};
//--------------------------------------------------------------------------
struct TSteelSectionFormCntrlsState{

	double edt_b_f2_ {500};
	double edt_t_f2_ {24};
	double edt_b_f1_ {300};
	double edt_t_f1_ {12};
	double edt_h_w_  {1200};
	double edt_t_w_  {12};

	int pg_cntrl_sect_type_ {0};
	int cmb_bx_rolled_sect_num_ {22};
	int rd_grp_rolled_sect_type_ {0};

	void save_cntls_state(ostream & os);
	void load_cntrls_state(istream & is);
};
//--------------------------------------------------------------------------
struct TFrmRebarCntrlsState{

	int cmb_bx_rebar_grade_ {3};
	double edt_E_s_ {200000};
	double edt_safety_factor_ {1.15};
	double edt_diameter_ {0};
	double edt_b_ {200};
	double edt_a_u_ {50};
	double edt_a_l_ {50};

	void save_cntls_state(ostream & os);
	void load_cntrls_state(istream & is);
};
#endif
















