//---------------------------------------------------------------------------
#pragma hdrstop
#include "uCompSectGeomSP35.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
CompSectGeomSP35::CompSectGeomSP35(Steel const & steel,
	std::unique_ptr<GeneralSteelSection> st_sect,
	ConcreteSP35 const & concrete,
	std::unique_ptr<GeneralConcreteSection> conc_sect,
	ConcStateConsid const state):
		steel_(steel), st_sect_(std::move(st_sect)),
		concrete_(concrete), conc_sect_(std::move(conc_sect))
{
	calculate_steel_sect_with_rebars();
	calculate(state);
}
void CompSectGeomSP35::calculate(ConcStateConsid conc_st_consid)
{
	switch (conc_st_consid) {

	case ConcStateConsid::normal:
		calculate(concrete_.E_b());
		break;

	case ConcStateConsid::shrink:
		calculate(concrete_.E_b_shr());
		break;

	case ConcStateConsid::creep:
		calculate(E_ef_kr());
		break;
	}
}
void CompSectGeomSP35::calculate_steel_sect_with_rebars()
{
	double const E_st = steel_.get_E_st();
	double const E_rs = conc_sect_ -> rebars().rebar().E_s();

	double const n_r = E_st / E_rs;

	double const h_n = conc_sect_ -> h_n();
	double const h_f = conc_sect_ -> des_height();
	double const C_b = conc_sect_ -> C_b();
	double const a_l_r = conc_sect_ -> rebars().a_l();
	double const a_u_r = conc_sect_ -> rebars().a_u();
	double const Z_s2_s = st_sect_ -> Z_s2_s();
	double const Z_s_r_u = Z_s2_s + h_n + h_f - a_u_r;
	double const Z_s_r_l = Z_s2_s + h_n + a_l_r;

	double const A_s = st_sect_ -> A_s();
	double const A_u_r = conc_sect_ -> rebars().A_u_r_per_unit() * conc_sect_ -> des_width();
	double const A_l_r = conc_sect_ -> rebars().A_l_r_per_unit() * conc_sect_ -> des_width();

	double const I_s = st_sect_ -> I_s();

	A_st_ = A_s + A_u_r / n_r + A_l_r / n_r;

	 S_s_st_ = (A_l_r / n_r * (a_l_r + h_n + Z_s2_s) + A_u_r /
		n_r * (Z_s2_s + h_n + h_f - a_u_r));

	Z_s_st_ = S_s_st_ / A_st_;
	Z_b_st_ = Z_s2_s + C_b - Z_s_st_;

	I_st_ = I_s + A_s * Z_s_st_ * Z_s_st_ +
		A_l_r / n_r * (Z_s_r_l - Z_s_st_) * (Z_s_r_l - Z_s_st_) +
		A_u_r / n_r * (Z_s_r_u - Z_s_st_) * (Z_s_r_u - Z_s_st_);
}
double CompSectGeomSP35::E_ef_kr()const
{
	double const E_b = concrete_.E_b();
	double const E_st = steel_.get_E_st();

	double const n_b = E_st / E_b;

	double const A_b = conc_sect_ -> area();

	double const c_n = concrete_.c_n();
	/* TODO 1 -oMV : Сделать gama_f_shr_kr переменной */
	double const gamma_f_shr_kr = 1.1;

	double const phi_kr = gamma_f_shr_kr * E_b * c_n;

	double const nu = A_b / n_b * (1 / A_st_ + Z_b_st_ * Z_b_st_ / I_st_);

	return (nu - 0.5 * phi_kr + 1) / ((1 + phi_kr) * nu + 0.5 * phi_kr + 1) * E_b;
}
void CompSectGeomSP35::calculate(double const E_b)
{

	double const E_st = steel_.get_E_st();
	double const E_rs = conc_sect_ -> rebars().rebar().E_s();

	n_b_ = E_st / E_b;
	n_r_ = E_st / E_rs;

	double const A_s = st_sect_ -> A_s();
	double const A_b = conc_sect_ -> area();
	double const A_u_r = conc_sect_ -> rebars().A_u_r_per_unit() * conc_sect_ -> des_width();
	double const A_l_r = conc_sect_ -> rebars().A_l_r_per_unit() * conc_sect_ -> des_width();

	A_stb_= A_s + A_b / n_b_ + A_u_r / n_r_ + A_l_r / n_r_;

	double const h_s = st_sect_ -> h_s();
	double const h_n = conc_sect_ -> h_n();
	double const h_f = conc_sect_ -> des_height();
	double const a_l_r = conc_sect_ -> rebars().a_l();
	double const a_u_r = conc_sect_ -> rebars().a_u();
	double const Z_s2_s = st_sect_ -> Z_s2_s();
	double const C_b = conc_sect_ -> C_b();

	H_stb_ = h_s + h_n + h_f;

	Z_b_s_ = C_b + Z_s2_s;
	Z_r_u_s_ = Z_s2_s + h_n + h_f - a_u_r;
	Z_r_l_s_ = Z_s2_s + h_n + a_l_r;

	S_stb_ = A_b * Z_b_s_ / n_b_ + A_u_r * Z_r_u_s_ / n_r_  + A_l_r * Z_r_l_s_ / n_r_;

	Z_s_stb_ = S_stb_/A_stb_;
	Z_b_stb_ = Z_b_s_ - Z_s_stb_;
	Z_r_u_stb_ = Z_b_stb_ - C_b + h_n + h_f - a_u_r;
	Z_r_l_stb_ = Z_b_stb_ - C_b + a_l_r;

	double const I_s = st_sect_ -> I_s();
	double const I_b = conc_sect_ -> inertia();

	I_stb_ = I_s + A_s * Z_s_stb_ * Z_s_stb_ +
			 I_b / n_b_ + A_b * Z_b_stb_ * Z_b_stb_ / n_b_ +
			 A_u_r * Z_r_u_stb_ * Z_r_u_stb_ / n_r_  +
			 A_l_r * Z_r_l_stb_ * Z_r_l_stb_ / n_r_ ;

	W_b_stb_ = I_stb_ / Z_b_stb_;

	W_b_s_ = I_s / Z_b_s_;
}
void CompSectGeomSP35::print(TWord_Automation & report)const
{
	st_sect_ -> print(report);
	steel_.print_SP266(report);
	conc_sect_ -> print(report);
	concrete_.print(report);

	report.PasteTextPattern(area_to_str(A_stb_),"%A_stb%");
	report.PasteTextPattern(inertia_to_str(I_stb_),"%I_stb%");
	report.PasteTextPattern(sect_modul_to_str(W_b_stb_),"%W_b_stb%");
	report.PasteTextPattern(length_to_str(Z_b_stb_, LengthUnit::cm),"%Z_b_stb%");
	report.PasteTextPattern(length_to_str(Z_s_stb_, LengthUnit::cm),"%Z_s_stb%");
	report.PasteTextPattern(length_to_str(Z_b_s_, LengthUnit::cm),"%Z_b_s%");
}
#ifdef DEBUG_COMP_SECT_SP35
void CompSectGeomSP35::log()const
{
	#ifdef DEBUG_STEEL_SECT
	st_sect_ -> log();
	#endif
	#ifdef DEBUG_CONC_SECT
	conc_sect_ -> log();
    #endif
	FormLogger -> print(
		{
		 "***********************",
		 "Коэффициенты приведения",
		 "***********************",
		 "n_r = " + FloatToStr(n_r_),
		 "n_b = " + FloatToStr(n_b_),
		 "******************************************************",
		 "Характеристики стальной части сечения включая арматуру",
		 "******************************************************",
		 "Z_b_st = " + FloatToStr(Z_b_st_) + L" мм",
		 "Z_s_st = " + FloatToStr(Z_s_st_) + L" мм",
		 "A_st = " + FloatToStr(A_st_) + L" мм2",
		 "S_s_st = " + FloatToStr(S_s_st_) + L" мм3",
		 "I_st = " + FloatToStr(I_st_) + L" мм4",
		 "***************************************",
		 "Характеристики комбинированного сечения",
		 "***************************************",
		 "H_stb = " + FloatToStr(H_stb_) + L" мм",
		 "A_stb = " + FloatToStr(A_stb_) + L" мм2",
		 "S_stb = " + FloatToStr(S_stb_) + L" мм3",
		 "I_stb = " + FloatToStr(I_stb_) + L" мм4",
		 "Z_s_stb = " + FloatToStr(Z_s_stb_) + L" мм",
		 "Z_b_stb = " + FloatToStr(Z_b_stb_) + L" мм",
		 "Z_b_s = " + FloatToStr(Z_b_stb_) + L" мм"
		 });
}
#endif
void CompSectGeomSP35::fill_steel_sect_grid(TStringGrid* str_grid)const
{
	st_sect_ -> fill_grid(str_grid);
}
void CompSectGeomSP35::fill_conc_sect_grid(TStringGrid* str_grid)const
{
	conc_sect_ -> fill_grid(str_grid);
}
void CompSectGeomSP35::fill_comp_sect_grid(TStringGrid* str_grid)const
{
	str_grid -> Cells [1][1] = FloatToStrF(A_stb_, ffFixed, 15, 0);
	str_grid -> Cells [1][2] = FloatToStrF(I_stb_, ffFixed, 15, 0);
	str_grid -> Cells [1][3] = FloatToStrF(W_b_stb_, ffFixed, 15, 0);
	str_grid -> Cells [1][4] = FloatToStrF(Z_b_stb_, ffFixed, 15, 0);
	str_grid -> Cells [1][5] = FloatToStrF(Z_s_stb_, ffFixed, 15, 0);
	str_grid -> Cells [1][6] = FloatToStrF(Z_b_s_, ffFixed, 15, 0);
}
//---------------------------------------------------------------------------

