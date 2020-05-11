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
								   TConcretePart concrete_part):
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
void CompositeSection::set_phi_b_cr(double phi_b_cr)
{
	composite_section_calculated = false;
	concrete_part_.set_phi_b_cr(phi_b_cr);
	calculate();
}
void CompositeSection::calculate()
{
	concrete_part_.calculate();

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
	fictitious_modulus();
    calc_rigid_plastic_moment();

    composite_section_calculated = true;
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
	double h = concrete_part_.get_h(); //толщина железобетонной плиты. Для случая плиты по настилу сумма высоты настила и толщины бетона над ним
	double h_st = steel_part_.get_section().get_h_st(); // Высота стальной балки
	H_red_ = h + h_st;
}

void CompositeSection::compos_sect_area_calc()
{
	double A_b=concrete_part_.get_A_b();
	double A_st=steel_part_.get_section().get_A_st();
	double A_s=concrete_part_.get_rebar().get_A_s();
	int num_rows = concrete_part_.get_rebar().get_num_rows();
	double b_l=concrete_part_.get_b();

	A_red_= A_st + A_b/ alfa_b_+num_rows*1./alfa_s_*A_s * b_;
}

void CompositeSection::dist_conc_to_steel_calc()
{
	double C_b_ = concrete_part_.get_C_b();
	double h = concrete_part_.get_h();
	double Z_f2_st=steel_part_.get_section().get_Z_f2_st();
	double a_u=concrete_part_.get_rebar().get_a_u();
	double a_l=concrete_part_.get_rebar().get_a_l();

	Z_b_st_ = C_b_ + Z_f2_st;
	Z_st_r_u_ = Z_f2_st + h - a_u;
	Z_st_r_l_ = Z_f2_st + a_l;
}

void CompositeSection::first_moment_of_area_comp_calc()
{
	double A_b = concrete_part_.get_A_b();
	double b_r=concrete_part_.get_b();
	double b=concrete_part_.get_rebar().get_b_s();
	double A_s=concrete_part_.get_rebar().get_A_s();

	S_red_= A_b*Z_b_st_/alfa_b_+1/alfa_s_*A_s * b_ * (Z_st_r_u_+Z_st_r_l_);
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
	double I_st = steel_part_.get_section().get_I_st();
	double A_st = steel_part_.get_section().get_A_st();
	double A_b = concrete_part_.get_A_b();
	double A_s = concrete_part_.get_rebar().get_A_s();
	double b = concrete_part_.get_rebar().get_b_s();
	double b_r = concrete_part_.get_b();
	double I_b = concrete_part_.get_I_b();
	I_red_=I_st + A_st * pow(Z_st_red_,2) + 1/alfa_b_ *I_b + 1/alfa_b_ *A_b * pow(Z_b_red_,2)
		+1/alfa_s_*A_s * b_ * (pow(Z_red_r_u_,2)+pow(Z_red_r_l_,2));
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
	W_b_red_ = I_red_ / Z_b_red_;
}
void CompositeSection::fictitious_modulus()
{
	double I_st = steel_part_.get_section().get_I_st();
	W_b_st_ = I_st / Z_b_st_;
}
CompositeSection::NeutralAxis CompositeSection::calc_neutral_axis()
{
	double x_b = 0.;
	double x_f2 = 0.;
	double x_w = 0.;

	const double b_sl = get_concrete_part().get_b();
	const double R_b = get_concrete_part().get_concrete().get_R_b();
	const double R_y = get_steel_part().get_steel().get_R_y();
	const double A_st = get_steel_part().get_section().get_A_st();
	const double A_f1_st = get_steel_part().get_section().get_A_f1_st();
	const double A_f2_st = get_steel_part().get_section().get_A_f2_st();
	const double R_s = get_concrete_part().get_rebar().get_R_s();
	const double A_s = get_concrete_part().get_rebar().get_A_s();
	const double b_s = get_b_s();
	const double h = get_concrete_part().get_h();
	const double t_f2 = get_steel_part().get_section().get_t_uf();
	const double b_f2 = get_steel_part().get_section().get_b_uf();
	const double A_w_st = get_steel_part().get_section().get_A_w_st();
	const double h_w = get_steel_part().get_section().get_h_w();
	const double t_w = get_steel_part().get_section().get_t_w();
	const double A_b = get_concrete_part().get_A_b();
	const double C_b = get_concrete_part().get_C_b();

	const double h_f = 2* (h - C_b);

	x_b = (R_y * A_st + R_s * A_s * b_s)/(R_b * b_sl);

	x_f2 = (A_f1_st * R_y + (h + t_f2) * b_f2 * R_y + A_w_st*R_y + h * b_f2 * R_y
		- R_b * A_b - R_s * A_s * b_s) / ( 2 * b_f2 * R_y);

	x_w = (A_f1_st * R_y + (h + t_f2 + h_w) * t_w * R_y + (h + t_f2) * t_w * R_y
		 - R_b * A_b - A_f2_st * R_y - R_s * A_s  * b_s ) / ( 2 * t_w * R_y);

	if (x_b <= h_f)
		return NeutralAxis {NA_Location::CONCRETE, x_b};

	if ((x_f2 <= (h + t_f2)) && (x_f2 >= h))
		return NeutralAxis {NA_Location::UPPER_FLANGE, x_f2};

	if ((x_w <= (h + t_f2 + h_w)) && (x_w >= (h + t_f2)))
		return NeutralAxis {NA_Location::WEB, x_w};

	return NeutralAxis {NA_Location::NO_SOLUTION, 0.};
}

void CompositeSection::calc_rigid_plastic_moment()
{
	auto [na_location, x_na] {calc_neutral_axis()};
	const double R_b = get_concrete_part().get_concrete().get_R_b();
	const double C_b = get_concrete_part().get_C_b();
	const double b_sl = get_concrete_part().get_b();
	const double h = get_concrete_part().get_h();
	const double R_y = get_steel_part().get_steel().get_R_y();
	const double t_f2 = get_steel_part().get_section().get_t_uf();
	const double b_f2 = get_steel_part().get_section().get_b_uf();
	const double t_f1 = get_steel_part().get_section().get_t_lf();
	const double h_w = get_steel_part().get_section().get_h_w();
	const double t_w = get_steel_part().get_section().get_t_w();
	const double A_st = get_steel_part().get_section().get_A_st();
	const double A_w_st = get_steel_part().get_section().get_A_w_st();
	const double A_f1_st = get_steel_part().get_section().get_A_f1_st();
	const double A_f2_st = get_steel_part().get_section().get_A_f2_st();

	const double h_f = 2* (h - C_b);

	switch(na_location)
	{
		case NA_Location::CONCRETE:

			M_Rd_ = -1. * R_b * b_sl * x_na * x_na / 2. +
			R_y * A_f2_st * (h + t_f2/2.) +
			R_y * A_w_st * (h + t_f2 + h_w/2.) +
			R_y * A_f1_st * (h + t_f2 + h_w + t_f1 / 2.);

			break;

		case NA_Location::UPPER_FLANGE:

			M_Rd_ = -1. * R_b * b_sl * h_f * h_f / 2. +
			-1. * R_y * (x_na - h) * b_f2 * ((x_na - h) / 2. + h) +
			R_y * (h + t_f2 - x_na) * b_f2 * ((h + t_f2 - x_na) / 2. + x_na) +
			R_y * t_w * h_w * (h + t_f2 + h_w / 2.) +
			R_y * A_f1_st * (h + t_f2 + h_w + t_f1 / 2.);

			break;

		case NA_Location::WEB:

			M_Rd_ = -1. * R_b * b_sl * h_f * h_f/2. +
			-1. * R_y * A_f2_st * (h + t_f2 / 2) +
			-1. * R_y * t_w * (x_na - h - t_f1) * ((x_na - h - t_f1) / 2. + h + t_f2) +
			R_y * t_w * (h + t_f2 + h_w - x_na) * ((h + t_f2 + h_w - x_na) / 2. + h + t_f2 + h_w / 2.) +
			R_y * A_f1_st * (h + t_f2 + h_w + t_f1 / 2);

			break;

		case NA_Location::NO_SOLUTION:

			M_Rd_ = 1.;/* TODO 1 -oMV : M_Rd смотрится странно */

			break;
	}
}

double CompositeSection::get_Q_Rd()const
{
	double A_w_st = steel_part_.get_section().get_A_w_st();
	double R_s = steel_part_.get_steel().get_R_s();

	return A_w_st * R_s;
}
