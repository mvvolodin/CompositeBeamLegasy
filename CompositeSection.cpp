// ---------------------------------------------------------------------------

#pragma hdrstop

#include "CompositeSection.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

#include "MathFunction.h"
#include<cmath>


CompositeSection::CompositeSection()
{

}
CompositeSection::CompositeSection(SteelPart    steel_part,
								   TConcretePart concrete_part,
								   TGeometry geometry):
	steel_part_(steel_part),
	concrete_part_(concrete_part)
{}
void CompositeSection::save(std::ostream& ostr)const
{
	steel_part_.save(ostr);
	concrete_part_.save(ostr);
}
void CompositeSection::load(std::istream& istr)
{
	steel_part_.load(istr);
	concrete_part_.load(istr);
}

void CompositeSection::set_default_values()
{
	steel_part_.set_default_values();
	concrete_part_.set_default_values();
}
void CompositeSection::calculate()
{
	concrete_part_.calculate();
	steel_part_.calculate();

	alfa_to_rebar_steel_calc();
	alfa_to_concrete_calc();
	compos_sect_height_calc();
	compos_sect_area_calc();
	dist_conc_to_steel_calc();
	first_moment_of_area_comp_calc();
	dist_steel_to_compos_calc();
	dist_compos_to_upper_fl_calc();
	dist_compos_to_lower_fl_calc();
	dist_conc_to_compos_calc();
	inertia_compos_calc();
	sect_modulus_upper_fl();
	sect_modulus_lower_fl();
	sect_modulus_conc();
}

void CompositeSection::alfa_to_rebar_steel_calc()
{
	double E_st_ = steel_part_.get_steel().get_E_st();
	double E_s_ = concrete_part_.get_rebar().get_E_s(); // Модуль упругости арматуры
	alfa_s_ = E_st_ / E_s_;
}

void CompositeSection::alfa_to_concrete_calc()
{
	double E_st=steel_part_.get_steel().get_E_st(); // Модуль упругости стали
	double E_b_tau=concrete_part_.get_concrete().get_E_b_tau();//Модуль упругости бетона
	alfa_b_=E_st/E_b_tau;
}

void CompositeSection::compos_sect_height_calc()
{
	double h_b = concrete_part_.get_h_b(); //толщина железобетонной плиты. Для случая плиты по настилу сумма высоты настила и толщины бетона над ним
	double h_st = steel_part_.get_section().get_h_st(); // Высота стальной балки
	H_red_ = h_b + h_st;
}

void CompositeSection::compos_sect_area_calc()
{
	double A_b=concrete_part_.get_A_b();
	double A_st=steel_part_.get_section().get_A_st();
	double A_s=concrete_part_.get_rebar().get_A_s();
	int num_rows = concrete_part_.get_rebar().get_num_rows();
	double b_l=concrete_part_.get_b_l();
	double b_r=concrete_part_.get_b_r();

	A_red_= A_st + A_b/ alfa_b_+num_rows*1./alfa_s_*A_s * (b_l + b_r);
}

void CompositeSection::dist_conc_to_steel_calc()
{
	double C_b_=concrete_part_.get_C_b();
	double h_b=concrete_part_.get_h_b();
	double Z_f2_st=steel_part_.get_section().get_Z_f2_st();
	double a_u=concrete_part_.get_rebar().get_a_u();
	double a_l=concrete_part_.get_rebar().get_a_l();

	Z_b_st_=C_b_+Z_f2_st;
	Z_st_r_u_= Z_f2_st+h_b-a_u;
	Z_st_r_l_=Z_f2_st+a_l;
}

void CompositeSection::first_moment_of_area_comp_calc()
{
	double A_b = concrete_part_.get_A_b();
	double b_l=concrete_part_.get_b_l();
	double b_r=concrete_part_.get_b_r();
	double b=concrete_part_.get_rebar().get_b_s();
	double A_s=concrete_part_.get_rebar().get_A_s();

	S_red_= A_b*Z_b_st_/alfa_b_+1/alfa_s_*A_s *(b_l + b_r)*(Z_st_r_u_+Z_st_r_l_);
}

void CompositeSection::dist_steel_to_compos_calc()
{
	Z_st_red_=S_red_/A_red_;

}

void CompositeSection::dist_conc_to_compos_calc()
{
	const double C_b=concrete_part_.get_C_b();
	const double h_f=concrete_part_.get_h_f();
	const double a_u=concrete_part_.get_rebar().get_a_u();
	const double a_l=concrete_part_.get_rebar().get_a_l();

	Z_b_red_=Z_b_st_-Z_st_red_;
	Z_red_r_u_=Z_b_red_+h_f/2-a_u;
	Z_red_r_l_=Z_b_red_-h_f/2+a_l;
}

void CompositeSection::inertia_compos_calc()
{
	double I_st=steel_part_.get_section().get_I_st();
	double A_st = steel_part_.get_section().get_A_st();
	double A_b=concrete_part_.get_A_b();
	double A_s=concrete_part_.get_rebar().get_A_s();
	double b=concrete_part_.get_rebar().get_b_s();
	double b_l=concrete_part_.get_b_l();
	double b_r=concrete_part_.get_b_r();
	double I_b=concrete_part_.get_I_b();
	I_red_=I_st + A_st * pow(Z_st_red_,2) + 1/alfa_b_ *I_b + 1/alfa_b_ *A_b * pow(Z_b_red_,2)
		+1/alfa_s_*A_s * (b_l + b_r) * (pow(Z_red_r_u_,2)+pow(Z_red_r_l_,2));
}

void CompositeSection::dist_compos_to_upper_fl_calc()
{
	double Z_f2_st=steel_part_.get_section().get_Z_f2_st();
	Z_red_f2_=Z_f2_st-Z_st_red_;
}

void CompositeSection::dist_compos_to_lower_fl_calc()
{
	double Z_f1_st=steel_part_.get_section().get_Z_f1_st();
	Z_red_f1_=Z_f1_st+Z_st_red_;
}

void CompositeSection::sect_modulus_upper_fl()
{
	W_f2_red_=I_red_/Z_red_f2_;
}

void CompositeSection::sect_modulus_lower_fl()
{
	W_f1_red_=I_red_/Z_red_f1_;
}

void CompositeSection::sect_modulus_conc()
{
	W_b_red_=I_red_/Z_b_red_;
}
