//---------------------------------------------------------------------------
#pragma hdrstop
#include <algorithm>
#include "uCompSectCalculatorSP266.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

CompSectCalculatorSP266::CompSectCalculatorSP266(
	CompBeamObjsCreatorSP266 const & creator):
	creator_(creator),
	intr_frcs_calculator_(creator.int_forces_calculator()),
	comp_sect_(creator.comp_sect_geom()),
	work_cond_factors_(creator.work_cond_factrs()){}
CompSectCalcOutputSP266 CompSectCalculatorSP266::run()
{
	GlobGeom const glob_geom {creator_.glob_geometry()};

	std::vector<Node> const nodes_lst = glob_geom.nodes_lst();

	std::vector<CompSectOutputSP266> cso;

	for(auto const & n:nodes_lst)
		cso.emplace_back(calculate(n));

	return{glob_geom,
		   creator_.loads(),
		   creator_.work_cond_factrs(),
		   creator_.comp_sect_geom(),
		   cso};
}
CompSectOutputSP266 CompSectCalculatorSP266::calculate(Node const & node)
{
	double const alpha_b = comp_sect_.alpha_b();
	double const alpha_s = comp_sect_.alpha_s();

	double const Z_b_st = comp_sect_.Z_b_st();
	double const A_st = comp_sect_.A_st();
	double const A_w = comp_sect_.A_w();
	double const A_f2 = comp_sect_.A_f2();
	double const W_f2_st = comp_sect_.W_f2_st();
	double const W_f1_st = comp_sect_.W_f1_st();
	double const I_st = comp_sect_.I_st();

	double const A_b = comp_sect_.A_b();

	double const A_s = comp_sect_.A_s();

	double const W_b_st = comp_sect_.W_b_st();

	double const W_b_red = comp_sect_.W_b_red();
	double const I_red = comp_sect_.I_red();

	double const E_st = comp_sect_.E_st();
	double const E_b_tau = comp_sect_.E_b_tau();

	double const R_y = comp_sect_.R_y();
	double const R_b = comp_sect_.R_b();
	double const R_s = comp_sect_.R_s();

	double const eps_b_lim = comp_sect_.eps_b_lim();

	double const m = work_cond_factors_.m();
	double const m_b = work_cond_factors_.m_b();

	double x = node.x();

	bool is_end_support = node.is_end_support();

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

	double const fact_quasi_perm_load = intr_frcs_calculator_.fact_quasi_perm_load();

	double const f_1a = intr_frcs_calculator_.f_1a(x) / (E_st * I_st);
	double const f_1b = intr_frcs_calculator_.f_1b(x) / (E_st * I_st);
	double const f_2c = intr_frcs_calculator_.f_2c(x) / (E_b_tau * I_red);
	double const f_2d = intr_frcs_calculator_.f_2d(x) / (E_b_tau * I_red);
	double const f_2d_DL = intr_frcs_calculator_.f_2d_DL(x) / (E_b_tau * I_red);
	double const f_total = f_1b + f_2c + f_2d_DL + fact_quasi_perm_load * (f_2d - f_2d_DL);

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

	Loads const loads = creator_.loads(); /* TODO : Кэшировать переменную loads */

	double const sigma_bi = loads.get_sigma_bi();
	double const sigma_si = loads.get_sigma_si();

	double const sigma_b = std::max(M_2 / (alpha_b * W_b_red) -  sigma_bi, 0.);
	double const sigma_s = M_2 / (alpha_s * W_b_red) +  sigma_si;

	double const N_b_s = A_b * sigma_b + A_s * sigma_s;
	double const N_bR_s = A_b * R_b + A_s * sigma_s;
	double const N_bR_sR = A_b * R_b + A_s * R_s;

	double const m_1 = std::min(1 + (m_b * R_b - sigma_b) / (m * R_y) * A_b / A_f2, 1.2);
	double const k = 1.;/* TODO : Реализовать k в калькуляторах СП35 и СП266 */

	double const st_sect_ratio = M_1a / (std::min(W_f1_st, W_f2_st) * R_y * m);
	double const shear_ratio = Q / (0.58 * R_y * A_w * m);

	double fl_s2_ratio = 0.;
	double fl_s1_ratio = 0.;
	double conc_ratio = 0.;

	DesignCaseSP266 const des_case = design_case(sigma_b, sigma_s);

	switch (des_case) {

	case DesignCaseSP266::Case_A:

		fl_s2_ratio = ((M - Z_b_st * N_b_s) / (W_f2_st) - N_b_s / A_st) / (m_1 * m * R_y);
		fl_s1_ratio = ((M - Z_b_st * N_b_s) / (W_f1_st) + N_b_s / A_st) / (m * R_y);

		return {node,
				des_case,
				M_1a, M_1b, M_2c, M_2d, M,
				Q_1a, Q_1b, Q_2c, Q_2d, Q,
				R_1a, R_1b, R_2c, R_2d, R,
				f_1a, f_1b, f_2c, f_2d, f_total,
				sigma_bi, sigma_si,
				sigma_b, sigma_s,
				fl_s2_ratio, fl_s1_ratio, conc_ratio,
				shear_ratio,
				st_sect_ratio};

	case DesignCaseSP266::Case_B:

		fl_s2_ratio = ((M - Z_b_st * N_bR_sR) / W_f2_st - N_bR_sR / A_st) / (m * R_y);
		fl_s1_ratio = ((M - Z_b_st * N_bR_s) / W_f1_st + N_bR_s / A_st) / (m * R_y);

		return {node,
				des_case,
				M_1a, M_1b, M_2c, M_2d, M,
				Q_1a, Q_1b, Q_2c, Q_2d, Q,
				R_1a, R_1b, R_2c, R_2d, R,
				f_1a, f_1b, f_2c, f_2d, f_total,
				sigma_bi, sigma_si,
				sigma_b, sigma_s,
				fl_s2_ratio, fl_s1_ratio, conc_ratio,
				shear_ratio,
				st_sect_ratio};

	case DesignCaseSP266::Case_C:

		fl_s2_ratio = ((M - Z_b_st * N_bR_sR) / W_f2_st - N_bR_sR / A_st) / (m * R_y);
		fl_s1_ratio = ((M - Z_b_st * N_bR_sR) / W_f1_st + N_bR_sR / A_st) / (m * R_y);
		conc_ratio = k / E_st * ((M_2- Z_b_st * N_bR_sR) / W_b_st - N_bR_sR / A_st) / eps_b_lim;

	   return  {node,
				des_case,
				M_1a, M_1b, M_2c, M_2d, M,
				Q_1a, Q_1b, Q_2c, Q_2d, Q,
				R_1a, R_1b, R_2c, R_2d, R,
				f_1a, f_1b, f_2c, f_2d, f_total,
				sigma_bi, sigma_si,
				sigma_b, sigma_s,
				fl_s2_ratio, fl_s1_ratio, conc_ratio,
				shear_ratio,
				st_sect_ratio};
	case DesignCaseSP266::Case_F:

		fl_s2_ratio = M / (W_f2_st * m * R_y);
		fl_s1_ratio = M / (W_f1_st * m * R_y);

	   return  {node,
				des_case,
				M_1a, M_1b, M_2c, M_2d, M,
				Q_1a, Q_1b, Q_2c, Q_2d, Q,
				R_1a, R_1b, R_2c, R_2d, R,
				f_1a, f_1b, f_2c, f_2d, f_total,
				sigma_bi, sigma_si,
				sigma_b, sigma_s,
				fl_s2_ratio, fl_s1_ratio, conc_ratio,
				shear_ratio,
				st_sect_ratio};
   }
}
DesignCaseSP266 CompSectCalculatorSP266::design_case(double const sigma_b, double const sigma_r)
{
	double const E_b = comp_sect_.E_b();
	double const I_b = comp_sect_.I_b();
	double const I_s = comp_sect_.I_st();
	double const E_st = comp_sect_.E_st();

	double const R_b = comp_sect_.R_b();
	double const R_s = comp_sect_.R_s();
	double const W_b_stb = comp_sect_.W_b_red();
	double const alpha_b = comp_sect_.alpha_b();
	double const alpha_s = comp_sect_.alpha_s();

	double m_b = work_cond_factors_.m_b();
	double m_r = work_cond_factors_.m_r();

	if ((sigma_b >= 0) && (sigma_b < m_b * R_b) && (sigma_r < m_r * R_s))
		return DesignCaseSP266::Case_A;

	if ((sigma_b >= 0) && (sigma_b >= m_b * R_b) && (sigma_r < m_r * R_s))
		return DesignCaseSP266::Case_B;

	if ((sigma_b >= 0) && (sigma_b >= m_b * R_b) && (sigma_r >= m_r * R_s))
		return DesignCaseSP266::Case_C;
	if (sigma_b < 0)
		return DesignCaseSP266::Case_F;
}

