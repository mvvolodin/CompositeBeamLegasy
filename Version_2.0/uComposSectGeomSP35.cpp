//---------------------------------------------------------------------------

#pragma hdrstop

#include "uComposSectGeomSP35.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)


// ComposSectGeomSP35::ComposSectGeomSP35(Steel const & steel,
//										GeneralSteelSection const & st_sect,
//										Concrete const & concrete,
//										GeneralConcreteSection const & conc_sect,
//										ConcStateConsid const conc_st_consid)
//								:steel_{steel},
//								 st_sect_{st_sect},
//								 concrete_{concrete},
//								 conc_sect_{conc_sect}
// {
//	calculate(conc_st_consid);
// }

 ComposSectGeomSP35::ComposSectGeomSP35(Steel const steel,
										GeneralSteelSection const* st_sect,
										Concrete const concrete,
										GeneralConcreteSection const* conc_sect,
										ConcStateConsid const conc_st_consid)
								:steel_{steel},
								 st_sect_{st_sect},
								 concrete_{concrete},
								 conc_sect_{conc_sect}
 {
	calculate(conc_st_consid);
 }

double ComposSectGeomSP35::E_ef_kr()const
{
	double const E_b = concrete_.E_b();

	//double const A_b = conc_sect_.A_b();
	double const A_b = conc_sect_ -> A_b();

	double const c_n = concrete_.c_n();
    /* TODO 1 -oMV : Сделать gama_f_shr_kr переменной */
	double const gamma_f_shr_kr = 1.1;

	double const phi_kr = gamma_f_shr_kr * E_b * c_n;

	double const nu = A_b / n_b_ * (1 / A_s() + Z_b_st_ * Z_b_st_ / I_s());

	return (nu - 0.5 * phi_kr + 1) / ((1 + phi_kr) * nu + 0.5 * phi_kr + 1) * E_b;
}
void ComposSectGeomSP35::calculate(ConcStateConsid conc_st_consid)
{
	double const E_b = concrete_.get_E_b();

	switch (conc_st_consid) {

	case ConcStateConsid::normal:
		calculate(concrete_.get_E_b());
		break;

	case ConcStateConsid::shrink:
		calculate(0.5 * concrete_.get_E_b());
		break;

	case ConcStateConsid::creep:
		calculate(concrete_.get_E_b());
		calculate(E_ef_kr());
		break;
	}

}

void ComposSectGeomSP35::calculate(double const E_b)
{

	const double E_st = steel_.get_E_st();
//	n_r_ = E_st / conc_sect_.rebars().rebar().E_s();
	n_r_ = E_st / conc_sect_ -> rebars().rebar().E_s();
	n_b_ = E_st / E_b;

//	H_stb_ = conc_sect_.h() + st_sect_.h_st();
//
//	const double A_st = st_sect_.A_st();
//	const double A_b = conc_sect_.A_b();
//	const double b_sl = conc_sect_.b_sl();

	H_stb_ = conc_sect_ -> h() + st_sect_ -> h_st();

	const double A_st = st_sect_ -> A_st();
	const double A_b = conc_sect_ -> A_b();
	const double b_sl = conc_sect_ -> b_sl();


//	A_stb_= A_st +
//			A_b / n_b_ +
//			1. / n_r_ * conc_sect_.rebars().A_u_s_per_unit() *  b_sl +
//			1. / n_r_ * conc_sect_.rebars().A_l_s_per_unit() *  b_sl;
	A_stb_= A_st +
			A_b / n_b_ +
			1. / n_r_ * conc_sect_ -> rebars().A_u_s_per_unit() *  b_sl +
			1. / n_r_ * conc_sect_ -> rebars().A_l_s_per_unit() *  b_sl;
//
//	Z_b_st_ = conc_sect_.C_b() + st_sect_.Z_f2_st();
//	Z_st_r_u_ = st_sect_.Z_f2_st() + conc_sect_.h() - conc_sect_.rebars().a_u();
//	Z_st_r_l_ = st_sect_.Z_f2_st() + conc_sect_.rebars().a_l();

	Z_b_st_ = conc_sect_ -> C_b() + st_sect_ -> Z_f2_st();
	Z_st_r_u_ = st_sect_ -> Z_f2_st() + conc_sect_ -> h() - conc_sect_ -> rebars().a_u();
	Z_st_r_l_ = st_sect_ -> Z_f2_st() + conc_sect_ -> rebars().a_l();

//	S_stb_ = conc_sect_.A_b() * Z_b_st_ / n_b_ +
//			 1 / n_r_ * conc_sect_.rebars().A_u_s_per_unit() * conc_sect_.b_sl() * Z_st_r_u_ +
//			 1 / n_r_ * conc_sect_.rebars().A_l_s_per_unit() * conc_sect_.b_sl() * Z_st_r_l_;

	S_stb_ = conc_sect_ -> A_b() * Z_b_st_ / n_b_ +
			 1 / n_r_ * conc_sect_ -> rebars().A_u_s_per_unit() * conc_sect_ -> b_sl() * Z_st_r_u_ +
			 1 / n_r_ * conc_sect_ -> rebars().A_l_s_per_unit() * conc_sect_-> b_sl() * Z_st_r_l_;

	Z_s_stb_ = S_stb_/A_stb_;

//	I_stb_ = st_sect_.I_st() +
//			st_sect_.A_st() * Z_s_stb_ * Z_s_stb_ +
//			1/n_b_ * conc_sect_.I_b() +
//			1/n_b_ * conc_sect_.A_b() * Z_b_stb_ * Z_b_stb_ +
//			1/n_r_ * conc_sect_.rebars().A_u_s_per_unit() * conc_sect_.b_sl() * Z_stb_r_u_ * Z_stb_r_u_ +
//			1/n_r_ * conc_sect_.rebars().A_l_s_per_unit() * conc_sect_.b_sl() * Z_stb_r_l_ * Z_stb_r_l_ ;


	I_stb_ = st_sect_ -> I_st() +
			st_sect_ -> A_st() * Z_s_stb_ * Z_s_stb_ +
			1/n_b_ * conc_sect_ -> I_b() +
			1/n_b_ * conc_sect_ -> A_b() * Z_b_stb_ * Z_b_stb_ +
			1/n_r_ * conc_sect_ -> rebars().A_u_s_per_unit() * conc_sect_ -> b_sl() * Z_stb_r_u_ * Z_stb_r_u_ +
			1/n_r_ * conc_sect_ -> rebars().A_l_s_per_unit() * conc_sect_ -> b_sl() * Z_stb_r_l_ * Z_stb_r_l_ ;

	Z_b_stb_ = Z_b_st_ - Z_s_stb_;

	W_b_stb_ = I_stb_ / Z_b_stb_;
}


double ComposSectGeomSP35::E_b()const
{
	return concrete_.get_E_b();
}
double ComposSectGeomSP35::I_b()const
{
//	return conc_sect_.I_b();
	return conc_sect_ -> I_b();
}
double ComposSectGeomSP35::E_st()const
{
	return steel_.get_E_st();
}
double ComposSectGeomSP35::I_s()const
{
//	return st_sect_.I_st();
	return st_sect_ -> I_st();
}

double ComposSectGeomSP35::W_b_stb()const
{
	return W_b_stb_;
}
double ComposSectGeomSP35::n_b()const
{
	return n_b_;
}
double ComposSectGeomSP35::n_r()const
{
	return n_r_;
}
double ComposSectGeomSP35::R_b()const
{
	return concrete_.get_R_b();
}

double ComposSectGeomSP35::R_r()const
{
//	return conc_sect_.rebars().rebar().R_s();
	return conc_sect_ -> rebars().rebar().R_s();
}

double ComposSectGeomSP35::Z_b_s()const
{
	return Z_b_st_;
}
double ComposSectGeomSP35::W_s2_s()const
{
//	return st_sect_.W_f2_st();
	return st_sect_ -> W_f2_st();
}
double ComposSectGeomSP35::W_s1_s()const
{
//	return st_sect_.W_f1_st();
	return st_sect_ -> W_f1_st();
}
double ComposSectGeomSP35::A_s2()const
{
//	return st_sect_.A_f2_st();
	return st_sect_ -> A_f2_st();
}
double ComposSectGeomSP35::A_s1()const
{
//	return st_sect_.A_f1_st();
	return st_sect_ -> A_f1_st();
}
double ComposSectGeomSP35::A_s()const
{
//	return st_sect_.A_st() ;
	return st_sect_ -> A_st() ;
}
double ComposSectGeomSP35::A_b()const
{
//	return conc_sect_.A_b();
	return conc_sect_ -> A_b();
}
double ComposSectGeomSP35::A_r()const
{
//	return conc_sect_.rebars().A_s_per_unit();
	return conc_sect_ -> rebars().A_s_per_unit();
}
double ComposSectGeomSP35::E_rs()const
{
//	return conc_sect_.rebars().rebar().E_rs();
	return conc_sect_ -> rebars().rebar().E_rs();
}
double ComposSectGeomSP35::R_y()const
{
	return steel_.get_R_y();
}

double ComposSectGeomSP35::A_st()const
{
//	return A_s() + A_r() * conc_sect_.b_sl();
	return A_s() + A_r() * conc_sect_ -> b_sl();
}
/////* TODO 1 -oMV : Реализовать метод I_st() */
double ComposSectGeomSP35::I_st()const
{
	return 1;
}

double ComposSectGeomSP35::A_stb()const
{
	return A_stb_;
}
double ComposSectGeomSP35::I_stb()const
{
	return I_stb_;
}
double ComposSectGeomSP35::Z_s_stb()const
{
	return Z_s_stb_;
}

double ComposSectGeomSP35::Z_b_stb()const
{
	return Z_b_stb_;
}
double ComposSectGeomSP35::Z_r_stb()const
{
	return (Z_stb_r_l_ + Z_stb_r_u_) / 2;
}
double ComposSectGeomSP35::eps_shr()const
{
	return concrete_.eps_shr();
}

void ComposSectGeomSP35::print_data_to_report(TWord_Automation & report)const
{
//	st_sect_.print_data_to_report(report);
	st_sect_ -> print_data_to_report(report);

}
#ifndef NDEBUG
void ComposSectGeomSP35::print_data_to_logger(TFormLogger const & log)const
{
	log.add_heading(L"Геометрические характеристики композитного сечения");
	log.print_double(L"n_r = ", n_r_, L" ");
	log.print_double(L"n_b = ", n_b_, L" ");
	log.print_double(L"H_stb = ", H_stb_, L" мм");
	log.print_double(L"A_stb = ", A_stb_, L" мм2");
	log.print_double(L"S_stb = ", S_stb_, L" мм3");
	log.print_double(L"I_stb = ", I_stb_, L" мм4");
	log.print_double(L"Z_s_stb = ", Z_s_stb_, L" мм3");
	log.print_double(L"Z_b_stb = ", Z_b_stb_, L" мм4");
	//log.print_string(L"Сварной двутавр");
	//log.add_separator(L"Геометрические размеры");
//	log.print_2_doubles(L"bf2 = ", b_f2(), L" мм",L"tf2 = ", t_f2(), L" мм");
//	log.print_2_doubles(L"bf1 = ", b_f1(), L" мм",L"tf1 = ", t_f1(), L" мм");
//	log.print_2_doubles(L"hw = ", h_w(), L" мм",L"tw = ", t_w(), L" мм");
//	log.add_separator(L"Координаты вершин сварного двутавра");
//	for(auto v:vertexes_)
//		log -> print_2_doubles(L"X = ", v.X, L" мм",L"Y = ", v.Y, L" мм");
//	log -> add_separator(L"Геометрические характеристики");
//	log -> print_double(L"C = ", C_st(), L" мм");
//	log -> print_double(L"A = ", A_st(), L" мм2");
//	log -> print_double(L"I = ", I_st(), L" мм4");

}
#endif
