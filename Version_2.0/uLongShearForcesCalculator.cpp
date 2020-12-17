//---------------------------------------------------------------------------

#pragma hdrstop


#include "uLongShearForcesCalculator.h"
#include <algorithm>
//---------------------------------------------------------------------------
#pragma package(smart_init)

LongShearForcesCalculator::LongShearForcesCalculator(
	IntForcesCalculator const & calc,
	ComposSectGeomSP35 const & com_sec,
	double h, double b_sl, double L)
{
	diag_ = build_diag(calc, com_sec, h, b_sl, L);
}

double LongShearForcesCalculator::run(double x_l, double x_r)const
{

   // используя diag_ получаем и возвращаем силу сдвига на упор
	return 0;


}
std::vector<double> LongShearForcesCalculator::build_diag(IntForcesCalculator const & calc,
	ComposSectGeomSP35 const & com_sec, double h, double b_sl, double L)
{
	double const a_e = 0.36 * (h + b_sl);
	double const a_1 = 0.36 * (h + b_sl);

	std::vector<double> const x{0,
							a_e / 2,
							a_e + a_1 / 2,
							L / 2,
							L - (a_e + a_1 / 2),
							L - a_e / 2,
							L};

	double const S_eQ = S_i(calc, com_sec, x[0], x[1]);
	double const S_1Q = S_i(calc, com_sec, x[1], x[2]);

	std::vector<double> const S {0,
								 1.15 * S_eQ / a_e,
								 S_1Q / a_1,
								 0,
								 - S_1Q / a_1,
								 - 1.15 * S_eQ / a_e,
								 0};



	return std::vector<double> {};
}

double LongShearForcesCalculator::S_i(IntForcesCalculator const & calc,
	ComposSectGeomSP35 const & com_sec, double x_l, double x_r)const
{
	double const M_2c_l = calc.M_2c(x_l);
	double const M_2d_l = calc.M_2d(x_l);

	double const M_2c_r = calc.M_2c(x_l);
	double const M_2d_r = calc.M_2d(x_l);

	double const A_b = com_sec.A_b();
	double const A_r = com_sec.A_r();
	double const W_b_stb = com_sec.W_b_stb();

	double const R_b = com_sec.R_b();
	double const R_r = com_sec.R_r();

	double const M_2_l = M_2c_l + M_2d_l;
	double const M_2_r = M_2c_l + M_2d_r;

	double const sigma_b_l = M_2_l / W_b_stb;
	double const sigma_b_r = M_2_l / W_b_stb;

	double const sigma_r_l = M_2_l / W_b_stb; //для повышения точности расчёта
	double const sigma_r_r = M_2_l / W_b_stb; //

	((std::min(sigma_b_r, R_b) * A_b + std::min(sigma_r_r, R_r) * A_r)-
		 ((std::min(sigma_b_l, R_b) * A_b + std::min(sigma_r_l, R_r) * A_r)));

}
