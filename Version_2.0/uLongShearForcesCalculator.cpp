//---------------------------------------------------------------------------

#pragma hdrstop


#include "uLongShearForcesCalculator.h"
#include <algorithm>
//---------------------------------------------------------------------------
#pragma package(smart_init)

LongShearForcesCalculator::LongShearForcesCalculator(
	IntForcesCalculator const & calc,
	ComposSectGeomSP35 const & com_sec,
	double L)
{
	diag_ = build_diag(calc, com_sec, L);
}

double LongShearForcesCalculator::S_Ed(double x_l, double x_r)const
{
	return diag_.integral(x_l, x_r);
}
PiecewiseLinearFunc LongShearForcesCalculator::build_diag(
	IntForcesCalculator const & calc,
	ComposSectGeomSP35 const & com_sec,
	double L)
{
	double b_sl {com_sec.b_sl()};
	double h {com_sec.h_stb()};

	double const a_e_l = 0.;
	double const a_e_r = 0.36 * (h + b_sl);
	double const a_1_l = 0.36 * (h + b_sl);
	double const a_1_r = L / 2;

	double const a_e = a_e_r - a_e_l;
	double const a_1 = a_1_r - a_1_l;

	coord_.push_back(0);
	coord_.push_back(a_e / 2);
	coord_.push_back(a_e + a_1 / 2);
	coord_.push_back(a_e + a_1);
	coord_.push_back(a_e + a_1 + a_1 / 2);
	coord_.push_back(a_e + 2 * a_1);
	coord_.push_back(2 * a_e + 2 * a_1);

	double const S_eQ = S_i(calc, com_sec, a_e_l, a_e_r);
	double const S_1Q = S_i(calc, com_sec, a_1_l, a_1_r);

	double const S_eQ_overline = 1.15 * S_eQ / a_e;
	double const S_1Q_overline = S_1Q / a_1;

	S_overline_lst_.push_back(0);
	S_overline_lst_.push_back(S_eQ_overline);
	S_overline_lst_.push_back(S_1Q_overline);
	S_overline_lst_.push_back(0);
	S_overline_lst_.push_back(-S_1Q_overline);
	S_overline_lst_.push_back(-S_eQ_overline);
	S_overline_lst_.push_back(0);


	double const sl_1 = S_eQ_overline / (a_e / 2);
	double const b_1  = 0.;

	double const sl_2 = (S_1Q_overline - S_eQ_overline) / (a_e / 2 + a_1 / 2);
	double const b_2  = S_1Q_overline - sl_2 * (a_e + a_1 / 2);

	double const sl_3 = - S_1Q_overline / (a_1 / 2);
	double const b_3  = - sl_3 * (a_e + a_1);

	double const sl_4 = - S_1Q_overline / (a_1 / 2);
	double const b_4  = - sl_4 * (a_e + a_1);

	double const sl_5 = (- S_eQ_overline + S_1Q_overline) / (a_e / 2 + a_1 / 2);
	double const b_5  = - S_1Q_overline - sl_5 * (a_e + a_1 + a_1 / 2);

	double const sl_6 = S_eQ_overline / (a_e / 2);
	double const b_6  = - sl_6 * (2 * a_e + 2 * a_1);

	 std::pair<std::pair<double, double>, LinearFunc > p_1 {{0, a_e / 2}, {sl_1, b_1}};
	 std::pair<std::pair<double, double>, LinearFunc > p_2 {{a_e / 2, a_e + a_1 / 2}, {sl_2, b_2}};
	 std::pair<std::pair<double, double>, LinearFunc > p_3 {{a_e + a_1 / 2, a_e + a_1}, {sl_3, b_3}};
	 std::pair<std::pair<double, double>, LinearFunc > p_4 {{a_e + a_1, a_e + a_1 + a_1 / 2}, {sl_4, b_4}};
	 std::pair<std::pair<double, double>, LinearFunc > p_5 {{a_e + a_1 + a_1 / 2, a_e + 2 * a_1 + a_e / 2}, {sl_5, b_5}};
	 std::pair<std::pair<double, double>, LinearFunc > p_6 {{a_e + 2 * a_1 + a_e / 2, 2 * a_e + 2* a_1}, {sl_6, b_6}};

	return {{p_1, p_2, p_3, p_4, p_5, p_6}};
}
double LongShearForcesCalculator::S_i(IntForcesCalculator const & calc,
	ComposSectGeomSP35 const & com_sec, double x_l, double x_r)const
{
	double const M_2c_l = calc.M_2c(x_l);
	double const M_2d_l = calc.M_2d(x_l);

	double const M_2c_r = calc.M_2c(x_r);
	double const M_2d_r = calc.M_2d(x_r);

	double const n_b = com_sec.n_b();
	double const n_r = com_sec.n_r();

	double const A_b = com_sec.A_b();
	double const A_r = com_sec.A_r();
	double const W_b_stb = com_sec.W_b_stb();

	double const R_b = com_sec.R_b();
	double const R_r = com_sec.R_r();

	double const M_2_l = M_2c_l + M_2d_l;
	double const M_2_r = M_2c_r + M_2d_r;

	double const sigma_b_l = M_2_l / (n_b * W_b_stb);
	double const sigma_r_l = M_2_l / (n_r * W_b_stb);

	double const sigma_b_r = M_2_r / (n_b * W_b_stb); //для повышения точности расчёта
	double const sigma_r_r = M_2_r / (n_r * W_b_stb); //расчёт напряжений в арматуре следует

	double x = ((std::min(sigma_b_r, R_b) * A_b + std::min(sigma_r_r, R_r) * A_r)-
		 ((std::min(sigma_b_l, R_b) * A_b + std::min(sigma_r_l, R_r) * A_r)));
											 // определять в Ц.Т. арматуре, а не в Ц.Т. бетона
	return ((std::min(sigma_b_r, R_b) * A_b + std::min(sigma_r_r, R_r) * A_r)-
		 ((std::min(sigma_b_l, R_b) * A_b + std::min(sigma_r_l, R_r) * A_r)));
}


