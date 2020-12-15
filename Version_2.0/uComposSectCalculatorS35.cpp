//---------------------------------------------------------------------------

#pragma hdrstop

#include "uComposSectCalculatorS35.h"
#include "uBilinearInterp.h"
#include <algorithm>
#include <cmath>
//---------------------------------------------------------------------------
#pragma package(smart_init)

ComposSectCalculatorSP35::ComposSectCalculatorSP35(ComBeamInputSP35 const & input):
	intr_frcs_calculator_(IntForcesCalculator(input.glob_geom().tmp_sup_num(),
						   input.glob_geom().span(),
						   input.loads())),
	work_cond_factors_(input.work_cond_fctrs()),
	com_sect_(ComposSectGeomSP35(input.steel(),
			   input.steel_sect().get(),
			   input.concrete(),
			   input.concrete_sect().get(),
			   ComposSectGeomSP35::ConcStateConsid::normal)),
	com_sect_shr_(ComposSectGeomSP35(input.steel(),
			   input.steel_sect().get(),
			   input.concrete(),
			   input.concrete_sect().get(),
			   ComposSectGeomSP35::ConcStateConsid::shrink)),
	com_sect_kr_(ComposSectGeomSP35(input.steel(),
			   input.steel_sect().get(),
			   input.concrete(),
			   input.concrete_sect().get(),
			   ComposSectGeomSP35::ConcStateConsid::creep))
{
	double const I_b = com_sect_.I_b();
	double const I_s = com_sect_.I_s();
	double const E_b = com_sect_.E_b();
	double const E_st = com_sect_.E_st();

	if(!(E_b * I_b <= 0.2 * E_st * I_s))
		throw(std::u16string {u"Условие применимости гипотезы \"плоской плиты\" E_b * I_b <= 0.2 * E_st * I_s \
		не выполняется. Необходимо изменить исходные данные!"});
}

ComBeamOutputSP35 ComposSectCalculatorSP35::calculate(std::vector<Node> const & nodes_lst)
{
	std::vector<ComposSectOutputSP35> sect_output_lst {};

	for(auto const & node:nodes_lst)
		sect_output_lst.push_back(calculate(node));

	return {com_sect_,
			com_sect_shr_,
			com_sect_kr_,
			sect_output_lst};
}

ComposSectOutputSP35 ComposSectCalculatorSP35::calculate(Node const node)
{
	double const n_b = com_sect_.n_b();
	double const n_r = com_sect_.n_r();

	double const Z_b_s = com_sect_.Z_b_s();
	double const A_s = com_sect_.A_s();
	double const A_w = com_sect_.A_w();
	double const A_s2 = com_sect_.A_s2();
	double const A_s1 = com_sect_.A_s1();
	double const W_s2_s = com_sect_.W_s2_s();
	double const W_s1_s = com_sect_.W_s1_s();

	double const A_b = com_sect_.A_b();
	double const A_r = com_sect_.A_r();

	double const W_b_stb = com_sect_.W_b_stb();

	double const W_b_s = com_sect_.W_b_s();

	double const E_st = com_sect_.E_st();

	double const R_y = com_sect_.R_y();
	double const R_b = com_sect_.R_b();
	double const R_r = com_sect_.R_r();

	double const eps_b_lim = com_sect_.eps_b_lim();

	double const m = work_cond_factors_.m();
	double const m_b = work_cond_factors_.m_b();

    double x = node.x();

//	int end_sup_index = node.end_sup_index();
	bool is_end_support = node.is_end_support();

//	int inter_sup_index = node.inter_sup_index();
	bool is_inter_support = node.is_inter_support();

	int sup_index = node.sup_index();

	double const M_1a = intr_frcs_calculator_.M_1a(x);
	double const M_1b = intr_frcs_calculator_.M_1b(x);
	double const M_2c = intr_frcs_calculator_.M_2c(x);
	double const M_2d = intr_frcs_calculator_.M_2d(x);
	double const M_2d_DL = intr_frcs_calculator_.M_2d_DL(x);

	double const M_1 = M_1b;
	double const M_2 = M_2c + M_2d;
	double const M = M_1 + M_2;

	double const Q_1a = intr_frcs_calculator_.Q_1a(x);
	double const Q_1b = intr_frcs_calculator_.Q_1b(x);
	double const Q_2c = intr_frcs_calculator_.Q_2c(x);
	double const Q_2d = intr_frcs_calculator_.Q_2d(x);

	double const Q_1 = Q_1b;
	double const Q_2 = Q_2c + Q_2d;
	double const Q = Q_1 + Q_2;

	double const f_1a = intr_frcs_calculator_.f_1a(x);
	double const f_1b = intr_frcs_calculator_.f_1b(x);
	double const f_2c = intr_frcs_calculator_.f_2c(x);
	double const f_2d = intr_frcs_calculator_.f_2d(x);

	double R_1a = 0.;
	double R_1b = 0.;
	double R_2c = 0.;
	double R_2d = 0.;

	if(is_end_support){
		R_1a = intr_frcs_calculator_.R_1a(sup_index);
		R_1b = intr_frcs_calculator_.R_1b(sup_index);
		R_2c = intr_frcs_calculator_.R_2c(sup_index);
		R_2d = intr_frcs_calculator_.R_2d(sup_index);
	}

	if(is_inter_support){
		R_1a = intr_frcs_calculator_.R_1a(sup_index);
		R_1b = intr_frcs_calculator_.R_1b(sup_index);
		R_2c = - intr_frcs_calculator_.R_1b(sup_index);
	}


	double const R_1 = R_1b;
	double const R_2 = R_2c + R_2d;
	double const R = R_1 + R_2;

	double  sigma_bi_sh = shrink_stress(ShrinkStressIn::concrete);
	double  sigma_ri_sh = shrink_stress(ShrinkStressIn::rebar);

	double const sigma_bi_kr = creep_stress(M_2c + M_2d_DL, CreepStressIn::concrete);
	double const sigma_ri_kr = creep_stress(M_2c + M_2d_DL, CreepStressIn::rebar);

	double const sigma_bi = std::abs(sigma_bi_sh) + std::abs(sigma_bi_kr);
	double const sigma_ri = std::abs(sigma_ri_sh) + std::abs(sigma_ri_kr);

	double const sigma_b = std::max(M_2 / (n_b * W_b_stb) -  sigma_bi, 0.);
	double const sigma_r = M_2 / (n_r * W_b_stb) +  sigma_ri;

	double const fl_ratio = com_sect_.st_sect() -> smaller_fl_to_larger_fl_ratio();
	double const A_f_min_to_A_w_ratio = com_sect_.st_sect() ->
		smaller_fl_area_to_web_area_ratio();
	double const A_f_min_plus_A_w_to_A_ratio = com_sect_.st_sect() ->
		smaller_fl_area_plus_web_area_to_total_area_ratio();

	SP_35_13330_2011_table_9_5::FlangeBendingAndAxialStressSumUp fl = (A_s2 < A_s1)?
		SP_35_13330_2011_table_9_5::FlangeBendingAndAxialStressSumUp::bigger:
		SP_35_13330_2011_table_9_5::FlangeBendingAndAxialStressSumUp::smaller;

	double const N_br = A_b * sigma_b + A_r * sigma_r;
	double const N_bR_r = A_b * R_b + A_r * sigma_r;
	double const N_bR_R = A_b * R_b + A_r * R_r;

	double const str_ratio_br = N_br / (A_s * m *R_y);
	double const str_ratio_bR_r = N_bR_r / (A_s * m *R_y);
	double const str_ratio_bR_R = N_bR_R / (A_s * m *R_y);

	double const eta_br = (str_ratio_br <= 0.7)?
			SP_35_13330_2011_table_9_5::bilinear_interpolation(fl_ratio, str_ratio_br, fl):0;
	double const eta_bR_r = (str_ratio_bR_r <= 0.7)?
			SP_35_13330_2011_table_9_5::bilinear_interpolation(fl_ratio, str_ratio_bR_r, fl):0;
	double const eta_bR_R = (str_ratio_bR_R <= 0.7)?
		SP_35_13330_2011_table_9_5::bilinear_interpolation(fl_ratio, str_ratio_bR_R, fl):0;

	double const omega = SP_35_13330_2011_table_8_16::bilinear_interpolation(A_f_min_to_A_w_ratio,
		A_f_min_plus_A_w_to_A_ratio);

	double const omega_3_br = 1 + eta_br * (omega - 1);
	double const omega_3_bR_r = 1 + eta_bR_r * (omega - 1);
	double const omega_3_bR_R = 1 + eta_bR_R * (omega - 1);

	double const m_1 = std::min(1 + (m_b * R_b - sigma_b) / (m * R_y) * A_b / A_s2, 1.2);
	double const omega_4_br = omega_3_br / m_1;

	double const k = 1.0;

	double const st_sect_ratio = M_1a / (std::min(W_s1_s,W_s2_s) * R_y * m);
	double const shear_ratio = Q / (0.58 * R_y * A_w * m);

	double fl_s2_ratio = 0.;
	double fl_s1_ratio = 0.;
	double conc_ratio = 0.;

	DesignCase const des_case = design_case(sigma_b, sigma_r);

	switch (des_case) {

	case DesignCase::Case_A:

		fl_s2_ratio = ((M - Z_b_s * N_br) / (omega_4_br * W_s2_s) - N_br / A_s) / (m_1 * m * R_y);
		fl_s1_ratio = ((M - Z_b_s * N_br) / (omega_3_br * W_s1_s) + N_br / A_s) / (m * R_y);

		return {node,
				M_1a, M_1b, M_2c, M_2d, M,
				Q_1a, Q_1b, Q_2c, Q_2d, Q,
				R_1a, R_1b, R_2c, R_2d, R,
				f_1a, f_1b, f_2c, f_2d,
				sigma_bi_sh, sigma_bi_kr,
				sigma_ri_sh, sigma_ri_kr,
				sigma_bi, sigma_ri,
				sigma_b, sigma_r,
				{{{PlastCoeff::Omega, omega},
				  {PlastCoeff::Eta_lf,eta_br},
				  {PlastCoeff::Omega_3_lf,omega_3_br},
				  {PlastCoeff::Omega_4,omega_4_br}}},
				des_case,
				fl_s2_ratio,
				fl_s1_ratio,
				conc_ratio,
				shear_ratio,
				st_sect_ratio};

	case DesignCase::Case_B:

		fl_s2_ratio = ((M - Z_b_s * N_bR_R) / (omega_3_bR_R * W_s2_s) - N_bR_R / A_s) / (m * R_y);
		fl_s1_ratio = ((M - Z_b_s * N_bR_r) / (omega_3_bR_r * W_s1_s) + N_bR_r / A_s) / (m * R_y);

		return {node,
				M_1a, M_1b, M_2c, M_2d, M,
				Q_1a, Q_1b, Q_2c, Q_2d, Q,
				R_1a, R_1b, R_2c, R_2d, R,
				f_1a, f_1b, f_2c, f_2d,
				sigma_bi_sh, sigma_bi_kr,
				sigma_ri_sh, sigma_ri_kr,
				sigma_bi, sigma_ri,
				sigma_b, sigma_r,
				{{{PlastCoeff::Omega, omega},
				  {PlastCoeff::Eta_uf,eta_bR_R},
				  {PlastCoeff::Eta_lf,eta_bR_r},
				  {PlastCoeff::Omega_3_uf,omega_3_bR_R},
				  {PlastCoeff::Omega_3_lf,omega_3_bR_r}}},
				des_case,
				fl_s2_ratio,
				fl_s1_ratio,
				conc_ratio,
				shear_ratio,
				st_sect_ratio};

	case DesignCase::Case_C:

		fl_s2_ratio = ((M - Z_b_s * N_bR_R) / (omega_3_bR_R * W_s2_s) - N_bR_R / A_s) / (m * R_y);
		fl_s1_ratio = ((M - Z_b_s * N_bR_R) / (omega_3_bR_R * W_s1_s) + N_bR_R / A_s) / (m * R_y);
		conc_ratio = k / E_st * ((M_2- Z_b_s * N_bR_R) / W_b_s - N_bR_R / A_s) / eps_b_lim;

	   return {node,
			   M_1a, M_1b, M_2c, M_2d, M,
			   Q_1a, Q_1b, Q_2c, Q_2d, Q,
			   R_1a, R_1b, R_2c, R_2d, R,
			   f_1a, f_1b, f_2c, f_2d,
			   sigma_bi_sh, sigma_bi_kr,
			   sigma_ri_sh, sigma_ri_kr,
			   sigma_bi, sigma_ri,
			   sigma_b, sigma_r,
			   {{{PlastCoeff::Omega, omega},
				 {PlastCoeff::Eta_uf,eta_bR_R},
				 {PlastCoeff::Eta_lf,eta_bR_R},
				 {PlastCoeff::Omega_3_uf,omega_3_bR_R},
				 {PlastCoeff::Omega_3_lf,omega_3_bR_R}}},
			   des_case,
			   fl_s2_ratio,
			   fl_s1_ratio,
			   conc_ratio,
			   shear_ratio,
			   st_sect_ratio};
	case DesignCase::Case_F:

		fl_s2_ratio = M / (omega * W_s2_s * m * R_y);
		fl_s1_ratio = M / (omega * W_s1_s * m * R_y);

	   return {node,
			   M_1a, M_1b, M_2c, M_2d, M,
			   Q_1a, Q_1b, Q_2c, Q_2d, Q,
			   R_1a, R_1b, R_2c, R_2d, R,
			   f_1a, f_1b, f_2c, f_2d,
			   sigma_bi_sh, sigma_bi_kr,
			   sigma_ri_sh, sigma_ri_kr,
			   sigma_bi, sigma_ri,
			   sigma_b, sigma_r,
			   {{{PlastCoeff::Omega, omega}}},
			   des_case,
			   fl_s2_ratio,
			   fl_s1_ratio,
			   conc_ratio,
			   shear_ratio,
			   st_sect_ratio};
   }
}

double ComposSectCalculatorSP35::creep_stress(double M, CreepStressIn const cr_str_in)const
{
	double const n_b = com_sect_.n_b();
	double const n_r = com_sect_.n_r();

	double const n_b_kr = com_sect_kr_.n_b();
	double const W_b_stb_kr = com_sect_kr_.W_b_stb();
	double const W_b_stb = com_sect_.W_b_stb();

	if(M / (n_b * W_b_stb) <= 0.2 * com_sect_.R_b())
		return 0;

	switch (cr_str_in){

	case CreepStressIn::concrete:

		return std::abs(M / (n_b * W_b_stb) - M / (n_b_kr * W_b_stb_kr));

	case CreepStressIn::rebar:

		return std::abs(M / (n_r * W_b_stb_kr) - M / (n_r * W_b_stb));
	}
}

double ComposSectCalculatorSP35::shrink_stress(ShrinkStressIn const shr_str_in)const
{
	switch (shr_str_in) {

	case ShrinkStressIn::concrete:
		return shrink_stress(com_sect_shr_.E_b_shr(), -1 * com_sect_shr_.Z_b_stb(), 0);

	case ShrinkStressIn::rebar:
		return shrink_stress(com_sect_shr_.E_rs(), -1 * com_sect_shr_.Z_r_stb(), 1);
	}
}

double ComposSectCalculatorSP35::shrink_stress(double const E, double Z, double const nu)const
{
	double const eps_shr = com_sect_shr_.eps_shr();
	double const A_stb_shr = com_sect_shr_.A_stb();
	double const A_st = com_sect_shr_.A_st();
	double const S_st = com_sect_shr_.S_st();  //S_shr в норме
	double const I_stb_shr = com_sect_shr_.I_stb();

	return std::abs(eps_shr * E * (A_st / A_stb_shr + S_st / I_stb_shr * Z - nu));
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

	if ((sigma_b >= 0) && (sigma_b < m_b * R_b) && (sigma_r < m_r * R_r))
		return DesignCase::Case_A;

	if ((sigma_b >= 0) && (sigma_b >= m_b * R_b) && (sigma_r < m_r * R_r))
		return DesignCase::Case_B;

	if ((sigma_b >= 0) && (sigma_b >= m_b * R_b) && (sigma_r >= m_r * R_r))
		return DesignCase::Case_C;
	if (sigma_b < 0)
		return DesignCase::Case_F;
}
