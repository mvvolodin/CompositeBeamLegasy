// ---------------------------------------------------------------------------

#pragma hdrstop

#include "CompositeSection.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

#include "MathFunction.h"
#include<cmath>
ISection CompositeSection::steel_part___; //не используетс
TConcretePart* CompositeSection::concrete_part___;  //не используется
Steel CompositeSection::i_sect_steel___; //не используетс

CompositeSection::CompositeSection()
{

}
CompositeSection::CompositeSection(SteelPart    steel_part,
								   TConcretePart* concrete_part)
{

}

CompositeSection::CompositeSection(TGeometry geometry,
									  Steel steel_i_section,
									  TISectionInitialData i_sect_initial_data,
									  TConcretePart* concrete_part)
	:i_sect_steel(steel_i_section),concrete_part(concrete_part)
{

	steel_part=ISection(i_sect_initial_data);


	if (!geometry.is_end_beam())
	{
		double t_sl= concrete_part->get_t_sl();
		double a=steel_part.get_b_uf()/2;
		double B_l=geometry.get_trib_width_left();
		double B_r=geometry.get_trib_width_right();
		double l=geometry.get_span();
		concrete_part->set_b_l(concrete_part->effective_width_calc(t_sl,a,B_l,l));
		concrete_part->set_b_r(concrete_part->effective_width_calc(t_sl,a,B_r,l));
	}
	else
	{
		double t_sl= concrete_part->get_t_sl();
		double a=steel_part.get_b_uf()/2;
		double B_l=geometry.get_trib_width_left();
		double B_r=geometry.get_trib_width_right();
		double l=geometry.get_span();
		concrete_part->set_b_l(concrete_part->effective_width_cantilever_calc(t_sl,a,B_l,l));
		concrete_part->set_b_r(concrete_part->effective_width_calc(t_sl,a,B_r,l));

	}
	concrete_part->calc_h_b();//заполняемы переменную класса (поле) результатом расчёта высоты плиты
	concrete_part->calc_C_b(); //заполняемы переменную класса (поле) результатом расчёта расстояния от верхней грани полки до центра тяжести плиты
	concrete_part->calc_area(); //заполняемы переменную класса (поле) результатом расчёта площади
	concrete_part->calc_inertia();//заполняемы переменную класса (поле) результатом расчёта момента инерции

	alfa_to_rebar_steel_calc();
	alfa_to_concrete_calc();
	compos_sect_height_calc();
	compos_sect_area_calc();
	dist_conc_to_steel_calc();
	first_moment_of_area_comp_calc();
	dist_steel_to_compos_calc();
	inertia_compos_calc();
	dist_compos_to_upper_fl_calc();
	dist_compos_to_lower_fl_calc();
	dist_conc_to_compos_calc();
	sect_modulus_upper_fl();
	sect_modulus_lower_fl();
	sect_modulus_conc();
}

void CompositeSection::alfa_to_rebar_steel_calc()
{
	double E_st_ = i_sect_steel.get_E_s(); // Модуль упругости стали
	double E_s_ = concrete_part->get_rebar().get_E_s(); // Модуль упругости арматуры
	alfa_s_ = E_st_ / E_s_;
}

void CompositeSection::alfa_to_concrete_calc()
{
	double E_st_=i_sect_steel.get_E_s(); // Модуль упругости стали
	double E_b_=concrete_part->get_E_b();//Модуль упругости бетона
	alfa_b_=E_st_/E_b_;
}

void CompositeSection::compos_sect_height_calc()
{
	double h_b = concrete_part->get_h_b(); //толщина железобетонной плиты. Для случая плиты по настилу сумма высоты настила и толщины бетона над ним
	double h_st = steel_part.get_h_st(); // Высота стальной балки
	H_red_ = h_b + h_st;
}

void CompositeSection::compos_sect_area_calc()
{
	double A_b=concrete_part->get_A_b();
	double A_st=steel_part.get_A_st();
	double b=concrete_part->get_rebar().get_b();
	double A_s=concrete_part->get_rebar().get_A_s();
	int num_rows=concrete_part->get_rebar().get_num_rows();
	double b_l=concrete_part->get_b_l();
	double b_r=concrete_part->get_b_r();

	A_red_= A_st + A_b/ alfa_b_+num_rows*1./alfa_s_*A_s*(b_l+b_r)/b;
}

void CompositeSection::dist_conc_to_steel_calc()
{
	double C_b_=concrete_part->get_C_b();
	double h_b=concrete_part->get_h_b();
	double Z_f2_st=steel_part.get_Z_f2_st();
	double a_u=concrete_part->get_rebar().get_a_u();
	double a_l=concrete_part->get_rebar().get_a_l();

	Z_b_st_=C_b_+Z_f2_st;
	Z_st_r_u_= Z_f2_st+h_b-a_u;
	Z_st_r_l_=Z_f2_st+a_l;
}

void CompositeSection::first_moment_of_area_comp_calc()
{
	double A_b = concrete_part->get_A_b();
	double b_l=concrete_part->get_b_l();
	double b_r=concrete_part->get_b_r();
	double b=concrete_part->get_rebar().get_b();
	double A_s=concrete_part->get_rebar().get_A_s();

	S_red_= A_b*Z_b_st_/alfa_b_+1/alfa_s_*A_s*(b_l+b_r)/b*(Z_st_r_u_+Z_st_r_l_);
}

void CompositeSection::dist_steel_to_compos_calc()
{
	Z_st_red_=S_red_/A_red_;

}

void CompositeSection::dist_conc_to_compos_calc()
{
	double C_b=concrete_part->get_C_b();
	double h_b=concrete_part->get_h_b();
	double a_u=concrete_part->get_rebar().get_a_u();
	double a_l=concrete_part->get_rebar().get_a_l();
	double h_f=h_b-C_b;//не является универсальным решением, необходимо расширит класс Rebar полями c расстояниями от Ц.Т. бетона до арматуры
	Z_b_red_=Z_b_st_-Z_st_red_;
	Z_red_r_u_=Z_b_red_+h_f/2-a_u;
	Z_red_r_u_=Z_b_red_-h_f/2+a_l;
}

void CompositeSection::inertia_compos_calc()
{
	double I_st=steel_part.get_I_st();
	double A_st = steel_part.get_A_st();
	double A_b=concrete_part->get_A_b();
	double A_s=concrete_part->get_rebar().get_A_s();
	double b=concrete_part->get_rebar().get_b();
	double b_l=concrete_part->get_b_l();
	double b_r=concrete_part->get_b_r();
	double I_b=concrete_part->get_I_b();
	I_red_=I_st+A_st*pow(Z_st_red_,2)+1/alfa_b_*I_b+1/alfa_b_*A_b*pow(Z_b_red_,2)
		+1/alfa_s_*A_s*(b_l+b_r)/b*(pow(Z_red_r_u_,2)+pow(Z_red_r_l_,2));
}

void CompositeSection::dist_compos_to_upper_fl_calc()
{
	double Z_f2_st=steel_part.get_Z_f2_st();
	Z_red_f2_=Z_f2_st-Z_st_red_;
}

void CompositeSection::dist_compos_to_lower_fl_calc()
{
	double Z_f1_st=steel_part.get_Z_f1_st();
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
