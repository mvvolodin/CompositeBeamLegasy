                                                             //---------------------------------------------------------------------------

#pragma hdrstop

#include "uComposSectGeomSP266.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)


 ComposSectGeomSP266::ComposSectGeomSP266(Steel const & steel,
										GeneralSteelSection const & st_sect,
										Concrete const & concrete,
										GeneralConcreteSection const & conc_sect):
								 steel_{steel},
								 st_sect_{st_sect},
								 concrete_{concrete},
								 conc_sect_{conc_sect}
 {
	calculate();
 }


void ComposSectGeomSP266::calculate()
{

	double const E_st = steel_.get_E_st();
	alpha_s_ = E_st / conc_sect_.rebars().rebar().E_s();
	alpha_b_ = steel_.get_E_st() / concrete_.get_E_b();

	H_red_ = conc_sect_.h() + st_sect_.h_st();

	double const A_st = st_sect_.A_st();
	double const A_b = conc_sect_.A_b();
	double const b_sl = conc_sect_.b_sl();

	A_red_= A_st +
			A_b / alpha_b_ +
			1. / alpha_s_ * conc_sect_.rebars().A_u_s_per_unit() *  b_sl +
			1. / alpha_s_ * conc_sect_.rebars().A_l_s_per_unit() *  b_sl;

	Z_b_st_ = conc_sect_.C_b() + st_sect_.Z_f2_st();
	double const Z_st_s_u = st_sect_.Z_f2_st() + conc_sect_.h() - conc_sect_.rebars().a_u();
	double const Z_st_s_l = st_sect_.Z_f2_st() + conc_sect_.rebars().a_l();

	S_red_ = conc_sect_.A_b() * Z_b_st_ / alpha_b_ +
			 1 / alpha_s_ * conc_sect_.rebars().A_u_s_per_unit() * conc_sect_.b_sl() * Z_st_s_u +
			 1 / alpha_s_ * conc_sect_.rebars().A_l_s_per_unit() * conc_sect_.b_sl() * Z_st_s_l;

	Z_st_red_ = S_red_/A_red_;

	I_red_ = st_sect_.I_st() +
			st_sect_.A_st() * Z_st_red_ * Z_st_red_ +
			1/alpha_b_ * conc_sect_.I_b() +
			1/alpha_b_ * conc_sect_.A_b() * Z_b_red_ * Z_b_red_ +
			1/alpha_s_ * conc_sect_.rebars().A_u_s_per_unit() * conc_sect_.b_sl() * Z_st_s_u  * Z_st_s_u  +
			1/alpha_s_ * conc_sect_.rebars().A_l_s_per_unit() * conc_sect_.b_sl() * Z_st_s_l  * Z_st_s_l  ;

	Z_b_red_ = Z_b_st_ - Z_st_red_;

	W_b_red_ = I_red_ / Z_b_red_;
}


double ComposSectGeomSP266::E_b()const
{
	return concrete_.get_E_b();
}
double ComposSectGeomSP266::I_b()const
{
	return conc_sect_.I_b();;
}
double ComposSectGeomSP266::E_st()const
{
	return steel_.get_E_st();
}
double ComposSectGeomSP266::I_st()const
{
	return st_sect_.I_st();
}

double ComposSectGeomSP266::W_b_red()const
{
	return W_b_red_;
}
double ComposSectGeomSP266::alpha_b()const
{
	return alpha_b_;
}
double ComposSectGeomSP266::alpha_s()const
{
	return alpha_s_;
}
double ComposSectGeomSP266::R_b()const
{
	return concrete_.get_R_b();
}

double ComposSectGeomSP266::R_s()const
{
	return conc_sect_.rebars().rebar().R_s();
}

double ComposSectGeomSP266::Z_b_st()const
{
	return Z_b_st_;
}
double ComposSectGeomSP266::W_f2_st()const
{
	return st_sect_.W_f2_st();
}
double ComposSectGeomSP266::W_f1_st()const
{
	return st_sect_.W_f1_st();
}

double ComposSectGeomSP266::A_st()const
{
	return st_sect_.A_st() ;
}
double ComposSectGeomSP266::A_b()const
{
	return conc_sect_.A_b() ;
}

double ComposSectGeomSP266::E_rs()const
{
	return conc_sect_.rebars().rebar().E_rs();
}
double ComposSectGeomSP266::R_y()const
{
	return steel_.get_R_y();
}

double ComposSectGeomSP266::A_red()const
{
	return A_red_;
}
double ComposSectGeomSP266::I_red()const
{
	return I_red_;
}
double ComposSectGeomSP266::Z_st_red()const
{
	return Z_st_red_;
}

double ComposSectGeomSP266::Z_b_red()const
{
	return Z_b_red_;
}

double ComposSectGeomSP266::eps_shr()const
{
	return concrete_.eps_shr();
}
#ifndef NDEBUG
void ComposSectGeomSP266::print_data_to_logger(TFormLogger const & log)const
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

