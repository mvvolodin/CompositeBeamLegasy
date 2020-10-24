//---------------------------------------------------------------------------

#pragma hdrstop

#include "uComposSectCalculatorS35.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

ComposSectCalculatorSP35::ComposSectCalculatorSP35
	(InternalForcesCalculator const & intr_frcs_calculator,
	 WorkingConditionsFactors const & work_cond_factors,
	 ComposSectGeomSP35 const & com_sect,
	 double const sigma_bi,
	 double const sigma_ri):
		intr_frcs_calculator_(intr_frcs_calculator),
		work_cond_factors_(work_cond_factors),
		com_sect_(com_sect),
		sigma_bi_(sigma_bi),
		sigma_ri_(sigma_ri){}

Section ComposSectCalculatorSP35::calculate(double const x, double const M_1, const double M_2)
{

	double const W_b_stb = com_sect_.W_b_stb();
	double const n_b = com_sect_.n_b();
	double const n_r = com_sect_.n_r();

	double const sigma_b = M_2 / (n_b * W_b_stb) -  sigma_bi_;
	double const sigma_r = M_2 / (n_r * W_b_stb) +  sigma_ri_;

	double const M = M_1 + M_2;

	double const Z_b_s = com_sect_.Z_b_s();
	double const A_s = com_sect_.A_s();
	double const A_s2 = com_sect_.A_s2();
	double const W_s2_s = com_sect_.W_s2_s();
	double const W_s1_s = com_sect_.W_s1_s();

	double const A_b = com_sect_.A_b();
	double const A_r = com_sect_.A_r();

	double const R_y = com_sect_.R_y();
	double const R_b = com_sect_.R_b();

	double const m = work_cond_factors_.m();
	double const m_b = work_cond_factors_.m_b();

	double const omega = 0;//8.16
	double const eta = 0;  //9.15

	double omega_4 = 0;
	double omega_3 = 0;

	double fl_s2_ratio = 0.;
	double fl_s1_ratio = 0.;

	double N_br = 0.;
	double N_br_R = 0.;

	double m_1 = 0.;


	switch (design_case(sigma_b, sigma_r)) {

	case DesignCase::Case_A:
		if((m_1 = 1 + (m_b * R_b - sigma_b) / (m * R_y) * A_b / A_s2) >= 1.2) m_1 = 1.2;

		N_br = A_b * sigma_b + A_r * sigma_r;

		omega_3 = 1 + eta * (omega - 1);
		omega_4 = omega_3 / m_1;

		fl_s2_ratio = ((M - Z_b_s * N_br) / (omega_4 * W_s2_s) - N_br / A_s) / (m_1 * m * R_y);
		fl_s1_ratio = ((M - Z_b_s * N_br) / (omega_3 * W_s2_s) + N_br / A_s) / (m * R_y);

		return Section{};

	case DesignCase::Case_B:
	;
	case DesignCase::Case_C:
	   ;
   }

}

double ComposSectCalculatorSP35::N(DesignCase dc, Flange fl)
{

}

DesignCase ComposSectCalculatorSP35::design_case(double const sigma_b, double const sigma_r)
{
	double const E_b = com_sect_.E_b();
	double const I_b = com_sect_.I_b();
	double const I_s = com_sect_.I_s();
	double const E_st = com_sect_.E_st();

	double const R_b = com_sect_.R_b();
	double const R_r = com_sect_.R_r();
	double const W_b_stb = com_sect_.W_b_stb();
	double const n_b = com_sect_.n_b();
	double const n_r = com_sect_.n_r();

	double m_b = work_cond_factors_.m_b();
	double m_r = work_cond_factors_.m_r();

	if ((E_b * I_b <= 0.2 * E_st * I_s )&&(sigma_b < m_b * R_b)&&(sigma_r < m_r * R_r))
		return DesignCase::Case_A;

	if ((sigma_b >= m_b * R_b)&&(sigma_r < m_r * R_r))
		return DesignCase::Case_B;

	if ((sigma_b >= m_b * R_b)&&(sigma_r >= m_r * R_r))
		return DesignCase::Case_C;
}
