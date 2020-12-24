//---------------------------------------------------------------------------
#pragma hdrstop

#include "uCompSectGeomSP266.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
 CompSectGeomSP266::CompSectGeomSP266(
	Steel const & steel,
	std::unique_ptr<GeneralSteelSection> st_sect,
	Concrete const & concrete,
	std::unique_ptr<GeneralConcreteSection> conc_sect):
		steel_(steel),
		st_sect_(std::move(st_sect)),
		concrete_(concrete),
		conc_sect_(std::move(conc_sect))
{
	calculate();
	calc_rigid_plastic_moment();
}

void CompSectGeomSP266::calculate()
{
	double const E_b = concrete_.get_E_b_tau();
	double const E_st = steel_.get_E_st();
	double const E_s = conc_sect_ -> rebars().rebar().E_s();

	alpha_b_ = E_st / E_b;
	alpha_s_ = E_st / E_s;

	double const A_st = st_sect_ -> A_st();
	double const A_b = conc_sect_ -> A_b();
	double const A_u_s = conc_sect_ -> rebars().A_u_r_per_unit() * conc_sect_ -> b_sl();
	double const A_l_s = conc_sect_ -> rebars().A_l_r_per_unit() * conc_sect_ -> b_sl();

	A_red_= A_st + A_b / alpha_b_ + A_u_s / alpha_s_ + A_l_s / alpha_s_;

	double const h_st = st_sect_ -> h_s();
	double const h_n = conc_sect_ -> h_n();
	double const h_f = conc_sect_ -> h_f();
	double const a_l_s = conc_sect_ -> rebars().a_l();
	double const a_u_s = conc_sect_ -> rebars().a_u();
	double const Z_f2_st = st_sect_ -> Z_s2_s();
	double const C_b = conc_sect_ -> C_b();

	H_red_ = h_st + h_n + h_f;

	Z_b_st_ = C_b + Z_f2_st;
	Z_st_s_u_ = Z_f2_st + h_n + h_f - a_u_s;
	Z_st_s_l_ = Z_f2_st + h_n + a_l_s;

	S_red_ = A_b * Z_b_st_ / alpha_b_ + A_u_s * Z_st_s_u_ / alpha_s_  + A_l_s * Z_st_s_l_ / alpha_s_;

	Z_st_red_ = S_red_/A_red_;
	Z_b_red_ = Z_b_st_ - Z_st_red_;
	Z_s_u_red_ = Z_b_red_ - C_b + h_n + h_f - a_u_s;
	Z_s_l_red_ = Z_b_red_ - C_b + h_n + a_l_s;

	double const I_st = st_sect_ -> I_st();
	double const I_b = conc_sect_ -> I_b();

	I_red_ = I_st + A_st * Z_st_red_ * Z_st_red_ +
			 I_b / alpha_b_ + A_b * Z_b_red_ * Z_b_red_ / alpha_b_ +
			 A_u_s * Z_s_u_red_ * Z_s_u_red_ / alpha_s_  +
			 A_l_s * Z_s_l_red_ * Z_s_l_red_ / alpha_s_ ;

	W_b_red_ = I_red_ / Z_b_red_;

	W_b_st_ = I_st / Z_b_st_;

}
CompSectGeomSP266::NeutralAxis CompSectGeomSP266::calc_neutral_axis()
{
	double x_b = 0.;
	double x_btw = 0.;
	double x_f2 = 0.;
	double x_w = 0.;

	const double b_sl = conc_sect_ -> b_sl();
	const double R_b = concrete_.get_R_b();
	const double R_y = steel_.get_R_y();

	const double A_st = st_sect_ -> area();
	const double A_w_st = st_sect_ -> area_web();
	const double A_f1_st = st_sect_ -> area_lower_fl();
	const double A_f2_st = st_sect_ -> area_upper_fl();

	const double h_f = conc_sect_ -> h_f();
	const double h = conc_sect_ -> h();
	const double t_f2 = st_sect_ -> upper_fl_thick();
	const double b_f2 = st_sect_ -> upper_fl_width();

	const double h_w = st_sect_ -> web_height();
	const double t_w = st_sect_ -> web_thick();
	const double h_st = st_sect_ -> sect_height();
	const double A_b = conc_sect_ -> A_b();
	const double C_b = conc_sect_ -> C_b();


	x_b = (R_y * (A_w_st + A_f1_st + A_f2_st))/(R_b * b_sl);

	x_f2 = (A_f1_st * R_y + (h + t_f2) * b_f2 * R_y + A_w_st * R_y + h * b_f2 * R_y
		- R_b * A_b) / ( 2 * b_f2 * R_y);

	x_w = (A_f1_st * R_y + (h + t_f2 + h_w) * t_w * R_y + (h + t_f2) * t_w * R_y
		 - R_b * A_b - A_f2_st * R_y) / ( 2 * t_w * R_y);

	if (x_b >= 0 && x_b <= h_f)
		return NeutralAxis {NA_Location::CONCRETE, x_b};

	if ( x_f2 >= h && x_f2 < (h + t_f2))
		return NeutralAxis {NA_Location::UPPER_FLANGE, x_f2};

	if (x_w >= (h + t_f2) && x_w <= (h_f + t_f2 + h_w))
		return NeutralAxis {NA_Location::WEB, x_w};

	return NeutralAxis {NA_Location::NO_SOLUTION, 0.};
}

void CompSectGeomSP266::calc_rigid_plastic_moment()
{
	auto [na_location, x_na] {calc_neutral_axis()};
	const double R_b = concrete_.get_R_b();
	const double C_b = conc_sect_ -> C_b();
	const double b_sl = conc_sect_ -> b_sl();
	const double h = conc_sect_ -> h();
	const double h_f = conc_sect_ -> h_f();
	const double R_y = steel_.get_R_y();

	const double h_st = st_sect_ -> sect_height();
	const double t_f2 = st_sect_ -> upper_fl_thick();
	const double b_f2 = st_sect_ -> upper_fl_width();
	const double t_f1 = st_sect_ -> lower_fl_thick();
	const double h_w = st_sect_ -> web_height();
	const double t_w = st_sect_ -> web_thick();

	const double A_st = st_sect_ -> area();
	const double A_w_st = st_sect_ -> area_web();
	const double A_f1_st = st_sect_ -> area_lower_fl();
	const double A_f2_st = st_sect_ -> area_upper_fl();

	switch(na_location)
	{
		case NA_Location::CONCRETE:

			M_Rd_ = -1. * R_b * b_sl * x_na * x_na / 2. +
				R_y * A_f2_st * (h + t_f2/2. - x_na) +
				R_y * A_w_st * (h + t_f2 + h_w/2. - x_na) +
				R_y * A_f1_st * (h + t_f2 + h_w + t_f1 / 2.- x_na);

			break;

		case NA_Location::UPPER_FLANGE:

			M_Rd_ = -1. * R_b * b_sl * h_f * (x_na - h_f / 2) +
				-1. * R_y * (x_na - h) * b_f2 * (x_na - h) / 2  +
				R_y * (h + t_f2 - x_na) * b_f2 * (h + t_f2 - x_na) / 2. +
				R_y * t_w * h_w * (h + t_f2 + h_w / 2. - x_na) / 2. +
				R_y * A_f1_st * (h + t_f2 + h_w + t_f1 / 2. - x_na);

			break;

		case NA_Location::WEB:

			M_Rd_ = -1. * R_b * b_sl * h_f * (x_na - h_f/2) +
				-1. * R_y * A_f2_st * (x_na - h - t_f2 / 2) +
				-1. * R_y * t_w * (x_na - h - t_f2) * (x_na - h - t_f2) / 2. +
				R_y * t_w * (h + t_f2 + h_w - x_na) * (h + t_f2 + h_w - x_na) / 2. +
				R_y * A_f1_st * (h + t_f2 + h_w + t_f1 / 2 - x_na);

			break;

		case NA_Location::NO_SOLUTION:

			M_Rd_ = -999.;/* TODO 1 -oMV : выбросить исключение */

			break;
	}
}

double CompSectGeomSP266::A_s()const
{
	return conc_sect_ -> rebars().A_u_r_per_unit() * conc_sect_ -> b_sl() +
		   conc_sect_ -> rebars().A_l_r_per_unit() * conc_sect_ -> b_sl();
}
void CompSectGeomSP266::print(TWord_Automation & report)const
{
	st_sect_ -> print_output(report);
	conc_sect_ -> print_output(report);

	report.PasteTextPattern(area_to_str(A_red_),"%A_red%");
	report.PasteTextPattern(inertia_to_str(I_red_),"%I_red%");
	report.PasteTextPattern(sect_modul_to_str(W_b_red_),"%W_b_red%");
	report.PasteTextPattern(length_to_str(Z_b_red_, LengthUnit::cm),"%Z_b_red%");
	report.PasteTextPattern(length_to_str(Z_st_red_, LengthUnit::cm),"%Z_st_red%");
	report.PasteTextPattern(length_to_str(Z_b_st_, LengthUnit::cm),"%Z_b_st%");
}
#ifndef NDEBUG
void CompSectGeomSP266::print_data_to_logger(TFormLogger const & log)const
{
	log.add_heading(L"Геометрические характеристики композитного сечения");
	log.print_double(L"alpha_s = ", alpha_s_, L" ");
	log.print_double(L"alpha_b = ", alpha_b_, L" ");
	log.print_double(L"H_red = ", H_red_, L" мм");
	log.print_double(L"A_red = ", A_red_, L" мм2");
	log.print_double(L"S_red = ", S_red_, L" мм3");
	log.print_double(L"I_red = ", I_red_, L" мм4");
	log.print_double(L"Z_st_red = ", Z_st_red_, L" мм3");
	log.print_double(L"Z_b_red = ", Z_b_red_, L" мм4");
}
#endif
void CompSectGeomSP266::fill_grid(TStringGrid* str_grid)const
{
	str_grid -> Cells [1][1] = FloatToStrF(A_red_, ffFixed, 15, 0);
	str_grid -> Cells [1][2] = FloatToStrF(I_red_, ffFixed, 15, 0);
	str_grid -> Cells [1][3] = FloatToStrF(W_b_red_, ffFixed, 15, 0);
	str_grid -> Cells [1][4] = FloatToStrF(Z_b_red_, ffFixed, 15, 0);
	str_grid -> Cells [1][5] = FloatToStrF(Z_st_red_, ffFixed, 15, 0);
	str_grid -> Cells [1][6] = FloatToStrF(Z_b_st_, ffFixed, 15, 0);
}
