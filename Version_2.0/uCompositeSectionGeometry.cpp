// ---------------------------------------------------------------------------

#pragma hdrstop

#include "uCompositeSectionGeometry.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

#include "MathFunction.h"
#include<cmath>


CompositeSectionGeometry::CompositeSectionGeometry()
{

}
CompositeSectionGeometry::CompositeSectionGeometry(SteelPart    steel_part,
												   ConcretePart concrete_part):
	steel_part_(steel_part),
	concrete_part_(concrete_part)
{}
void CompositeSectionGeometry::save(std::ostream& ostr)const
{
	steel_part_.save(ostr);
	concrete_part_.save(ostr);
}
void CompositeSectionGeometry::load(std::istream& istr)
{
	steel_part_.load(istr);
	concrete_part_.load(istr);
}

void CompositeSectionGeometry::set_default_values()
{
	steel_part_.set_default_values();
	concrete_part_.set_default_values();
}
void CompositeSectionGeometry::set_phi_b_cr(double phi_b_cr)
{
	composite_section_calculated = false;
	concrete_part_.set_phi_b_cr(phi_b_cr);
	calculate();
}
void CompositeSectionGeometry::calculate()
{
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

void CompositeSectionGeometry::alfa_to_rebar_steel_calc()
{
	double E_st_ = steel_part_.get_steel().get_E_st();
	double E_s_ = concrete_part_.get_rebar().get_E_s(); // Модуль упругости арматуры
	alfa_s_ = E_st_ / E_s_;
}

void CompositeSectionGeometry::alfa_to_concrete_calc()
{
	double E_st=steel_part_.get_steel().get_E_st(); // Модуль упругости стали
	double E_b_tau=concrete_part_.get_concrete().get_E_b_tau();//Модуль упругости бетона
	alfa_b_=E_st/E_b_tau;
}

void CompositeSectionGeometry::compos_sect_height_calc()
{
	double h = concrete_part_.get_h(); //толщина железобетонной плиты. Для случая плиты по настилу сумма высоты настила и толщины бетона над ним
	double h_st = steel_part_.get_section().get_h_st(); // Высота стальной балки
	H_red_ = h + h_st;
}

void CompositeSectionGeometry::compos_sect_area_calc()
{
	double A_b = concrete_part_.get_A_b();
	double A_st = steel_part_.get_section().get_A_st();
	double A_s = concrete_part_.get_rebar().get_A_s();
	int num_rows = concrete_part_.get_rebar().get_num_rows();
	double b_sl = concrete_part_.get_b_sl();

	A_red_= A_st + A_b/ alfa_b_+num_rows*1./alfa_s_*A_s * b_sl;
}

void CompositeSectionGeometry::dist_conc_to_steel_calc()
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

void CompositeSectionGeometry::first_moment_of_area_comp_calc()
{
	double A_b = concrete_part_.get_A_b();
	double b_r = concrete_part_.get_b_sl();
	double b = concrete_part_.get_rebar().get_b_s();
	double A_s = concrete_part_.get_rebar().get_A_s();
	double b_sl = concrete_part_.get_b_sl();

	S_red_= A_b * Z_b_st_ / alfa_b_ + 1 / alfa_s_ * A_s * b_sl * (Z_st_r_u_+Z_st_r_l_);
}

void CompositeSectionGeometry::dist_steel_to_compos_calc()
{
	Z_st_red_ = S_red_/A_red_;

}

void CompositeSectionGeometry::dist_conc_to_compos_calc()
{
	const double C_b = concrete_part_.get_C_b();
	const double h_f = concrete_part_.get_h_f();
	const double a_u = concrete_part_.get_rebar().get_a_u();
	const double a_l = concrete_part_.get_rebar().get_a_l();

	Z_b_red_ = Z_b_st_ - Z_st_red_;
	Z_red_r_u_= Z_b_red_ + h_f / 2 - a_u;
	Z_red_r_l_ = Z_b_red_ - h_f / 2+ a_l;
}

void CompositeSectionGeometry::inertia_compos_calc()
{
	double I_st = steel_part_.get_section().get_I_st();
	double A_st = steel_part_.get_section().get_A_st();
	double A_b = concrete_part_.get_A_b();
	double A_s = concrete_part_.get_rebar().get_A_s();
	double b = concrete_part_.get_rebar().get_b_s();
	double b_r = concrete_part_.get_b_sl();
	double I_b = concrete_part_.get_I_b();
	double b_sl = concrete_part_.get_b_sl();

	I_red_=I_st + A_st * pow(Z_st_red_,2) + 1/alfa_b_ *I_b + 1/alfa_b_ *A_b * pow(Z_b_red_,2)
		+1/alfa_s_*A_s * b_sl * (pow(Z_red_r_u_,2)+pow(Z_red_r_l_,2));

}

void CompositeSectionGeometry::dist_compos_to_upper_fl_calc()
{
	double Z_f2_st=steel_part_.get_section().get_Z_f2_st();
	Z_red_f2_=Z_f2_st-Z_st_red_;
}

void CompositeSectionGeometry::dist_compos_to_lower_fl_calc()
{
	double Z_f1_st=steel_part_.get_section().get_Z_f1_st();
	Z_red_f1_=Z_f1_st+Z_st_red_;
}

void CompositeSectionGeometry::sect_modulus_upper_fl()
{
	W_f2_red_=I_red_/Z_red_f2_;
}

void CompositeSectionGeometry::sect_modulus_lower_fl()
{
	W_f1_red_=I_red_/Z_red_f1_;
}

void CompositeSectionGeometry::sect_modulus_conc()
{
	W_b_red_ = I_red_ / Z_b_red_;
}
void CompositeSectionGeometry::fictitious_modulus()
{
	double I_st = steel_part_.get_section().get_I_st();
	W_b_st_ = I_st / Z_b_st_;
}
CompositeSectionGeometry::NeutralAxis CompositeSectionGeometry::calc_neutral_axis()
{
	double x_b = 0.;
	double x_btw = 0.;
	double x_f2 = 0.;
	double x_w = 0.;

	const double b_sl = concrete_part_.get_b_sl();
	const double R_b = concrete_part_.get_concrete().get_R_b();
	const double R_y = steel_part_.get_steel().get_R_y();
	const double A_st = steel_part_.get_section().get_A_st();
	const double A_f1_st = steel_part_.get_section().get_A_f1_st();
	const double A_f2_st = steel_part_.get_section().get_A_f2_st();
	const double h_f = concrete_part_.get_h_f();
	const double h = concrete_part_.get_h();
	const double t_f2 = steel_part_.get_section().get_t_uf();
	const double b_f2 = steel_part_.get_section().get_b_uf();
	const double A_w_st = steel_part_.get_section().get_A_w_st();
	const double h_w = steel_part_.get_section().get_h_w();
	const double t_w = steel_part_.get_section().get_t_w();
	const double h_st = steel_part_.get_section().get_h_st();
	const double A_b = concrete_part_.get_A_b();
	const double C_b = concrete_part_.get_C_b();

	x_b = (R_y * (A_w_st + A_f1_st + A_f2_st))/(R_b * b_sl);

//	x_btw = ((R_b * b_sl * h_f) * h_f / 2 + A_st * R_y * (h_st / 2 + h)) /
//		(R_b * b_sl * h_f + A_st * R_y);

	x_f2 = (A_f1_st * R_y + (h + t_f2) * b_f2 * R_y + A_w_st * R_y + h * b_f2 * R_y
		- R_b * A_b) / ( 2 * b_f2 * R_y);

	x_w = (A_f1_st * R_y + (h + t_f2 + h_w) * t_w * R_y + (h + t_f2) * t_w * R_y
		 - R_b * A_b - A_f2_st * R_y) / ( 2 * t_w * R_y);

	if (x_b >= 0 && x_b <= h_f)
		return NeutralAxis {NA_Location::CONCRETE, x_b};

//	if(x_btw >= h_f && x_btw < h)
//		return  NeutralAxis{NA_Location::BTW_CONCRETE_AND_UPPER_FLANGE, x_btw};

	if ( x_f2 >= h && x_f2 < (h + t_f2))
		return NeutralAxis {NA_Location::UPPER_FLANGE, x_f2};

	if (x_w >= (h + t_f2) && x_w <= (h_f + t_f2 + h_w))
		return NeutralAxis {NA_Location::WEB, x_w};

//	if (x_b >= 0 && x_b < h_f)
//		return NeutralAxis {NA_Location::CONCRETE, x_b};
//
//	if((R_y * A_st) / (R_b * b_sl * h_f) > 1 &&
//		(R_y * A_st - R_b * b_sl * h_f) / (2 * R_y * A_st) <= (b_f2 * t_f2) / A_st)
//			return NeutralAxis {NA_Location::UPPER_FLANGE, x_f2};
//
//	if((R_y * A_st) / (R_b * b_sl * h_f) > 1 &&
//		(R_y * A_st - R_b * b_sl * h_f) / (2 * R_y * A_st) > (b_f2 * t_f2) / A_st)
//			return NeutralAxis {NA_Location::WEB, x_w};

	return NeutralAxis {NA_Location::NO_SOLUTION, 0.};
}

void CompositeSectionGeometry::calc_rigid_plastic_moment()
{
	auto [na_location, x_na] {calc_neutral_axis()};
	const double R_b = get_concrete_part().get_concrete().get_R_b();
	const double C_b = get_concrete_part().get_C_b();
	const double b_sl = get_concrete_part().get_b_sl();
	const double h = get_concrete_part().get_h();
	const double h_f = concrete_part_.get_h_f();
	const double R_y = get_steel_part().get_steel().get_R_y();

	const double h_st = steel_part_.get_section().get_h_st();
	const double t_f2 = get_steel_part().get_section().get_t_uf();
	const double b_f2 = get_steel_part().get_section().get_b_uf();
	const double t_f1 = get_steel_part().get_section().get_t_lf();
	const double h_w = get_steel_part().get_section().get_h_w();
	const double t_w = get_steel_part().get_section().get_t_w();
	const double A_st = get_steel_part().get_section().get_A_st();
	const double A_w_st = get_steel_part().get_section().get_A_w_st();
	const double A_f1_st = get_steel_part().get_section().get_A_f1_st();
	const double A_f2_st = get_steel_part().get_section().get_A_f2_st();

	switch(na_location)
	{
		case NA_Location::CONCRETE:

			M_Rd_ = -1. * R_b * b_sl * x_na * x_na / 2. +
				R_y * A_f2_st * (h + t_f2/2. - x_na) +
				R_y * A_w_st * (h + t_f2 + h_w/2. - x_na) +
				R_y * A_f1_st * (h + t_f2 + h_w + t_f1 / 2.- x_na);

			break;

//		case NA_Location::BTW_CONCRETE_AND_UPPER_FLANGE:
//
//			M_Rd_ = -1 * R_b * b_sl * h_f * (x_na - h_f / 2) +
//				R_y * A_w_st * (h + h_st / 2 - x_na);
//
//			break;

		case NA_Location::UPPER_FLANGE:

			M_Rd_ = -1. * R_b * b_sl * h_f * (x_na - h_f / 2) +
				-1. * R_y * (x_na - h) * b_f2 * (x_na - h) / 2  +
				R_y * (h + t_f2 - x_na) * b_f2 * (h + t_f2 - x_na) / 2. +
				R_y * t_w * h_w * (h + t_f2 + h_w / 2. - x_na) / 2. +
				R_y * A_f1_st * (h + t_f2 + h_w + t_f1 / 2. - x_na);

			break;

		case NA_Location::WEB:

			M_Rd_ = -1. * R_b * b_sl * h_f * (x_na - h_f/2) +
				-1. * R_y * A_f2_st * (x_na - h - t_f2 / 2) +
				-1. * R_y * t_w * (x_na - h - t_f2) * (x_na - h - t_f2) / 2. +
				R_y * t_w * (h + t_f2 + h_w - x_na) * (h + t_f2 + h_w - x_na) / 2. +
				R_y * A_f1_st * (h + t_f2 + h_w + t_f1 / 2 - x_na);

			break;

		case NA_Location::NO_SOLUTION:

			M_Rd_ = 1.;/* TODO 1 -oMV : M_Rd смотрится странно */

			break;
	}
}

double CompositeSectionGeometry::get_Q_Rd()const
{
	double A_w_st = steel_part_.get_section().get_A_w_st();
	double R_s = steel_part_.get_steel().get_R_s();

	return A_w_st * R_s;
}
double CompositeSectionGeometry::get_alfa_b()
{
	if(!composite_section_calculated) calculate();

	return alfa_b_;
}
double CompositeSectionGeometry::get_alfa_s()
{
	if(!composite_section_calculated) calculate();

	return alfa_s_;
}
double CompositeSectionGeometry::get_A_red(LengthUnit length_unit)
{
	if(!composite_section_calculated) calculate();

	return A_red_/std::pow(static_cast<int>(length_unit),2);
}
double CompositeSectionGeometry::get_I_red(LengthUnit length_unit)
{
	if(!composite_section_calculated) calculate();

	return I_red_/std::pow(static_cast<int>(length_unit),4);
}
double CompositeSectionGeometry::get_W_b_red(LengthUnit length_unit)
{
	if(!composite_section_calculated) calculate();

	return W_b_red_/std::pow(static_cast<int>(length_unit),3);
}
double CompositeSectionGeometry::get_W_f2_red(LengthUnit length_unit)
{
	if(!composite_section_calculated) calculate();

	return W_f2_red_/std::pow(static_cast<int>(length_unit),3);
}
double CompositeSectionGeometry::get_W_f1_red(LengthUnit length_unit)
{
	if(!composite_section_calculated) calculate();

	return W_f1_red_/std::pow(static_cast<int>(length_unit),3);
}
double CompositeSectionGeometry::get_Z_b_red(LengthUnit length_unit)
{
	if(!composite_section_calculated) calculate();

	return Z_b_red_/static_cast<int>(length_unit);
}
double CompositeSectionGeometry::get_Z_st_red(LengthUnit length_unit)
{
	if(!composite_section_calculated) calculate();

	return Z_st_red_/static_cast<int>(length_unit);
}
double CompositeSectionGeometry::get_Z_b_st(LengthUnit length_unit)
{
	if(!composite_section_calculated) calculate();

	return Z_b_st_/static_cast<int>(length_unit);
}
double CompositeSectionGeometry::get_Z_f2_red(LengthUnit length_unit)
{
	if(!composite_section_calculated) calculate();

	return Z_red_f2_/static_cast<int>(length_unit);
}
double CompositeSectionGeometry::get_Z_f1_red(LengthUnit length_unit)
{
	if(!composite_section_calculated) calculate();

	return Z_red_f1_/static_cast<int>(length_unit);
}
double CompositeSectionGeometry::get_W_b_st(LengthUnit length_unit)
{
	if(!composite_section_calculated) calculate();

	return W_b_st_/std::pow(static_cast<int>(length_unit),3);
}
double CompositeSectionGeometry::get_E_st_I_red()const
{
	return steel_part_.get_steel().get_E_st() * I_red_;
}
double CompositeSectionGeometry::get_E_st_I_st()const
{
	return steel_part_.get_steel().get_E_st() *
		steel_part_.get_section().get_I_st();
}
double CompositeSectionGeometry::get_M_Rd(LoadUnit load_unit, LengthUnit length_unit)
{
	if(!composite_section_calculated) calculate();

	return M_Rd_ / (static_cast<int>(load_unit) * static_cast<int>(length_unit));
}

//============================================================================
//============================================================================

 CompositeSectionGeometry2::CompositeSectionGeometry2(Steel& steel,
							  std::unique_ptr<const ISection>& st_sect,
							  Concrete& concrete,
							  std::unique_ptr<const ISection>& conc_sect,
							  Rebar& rebar)
								:steel_{std::move(steel)},
								 st_sect_{std::move(st_sect)},
								 concrete_{std::move(concrete)},
								 conc_sect_{std::move(conc_sect)},
								 rebar_{std::move(rebar)}
 {
	calculate();
 }

 void CompositeSectionGeometry2::calculate()
 {
	alfa_s_ = alfa_s_calc();
	alfa_b_ = alfa_b_calc();
	H_red_ = compos_sect_height_calc();
	A_red_= compos_sect_area_calc();



 }

  void CompositeSectionGeometry2::calculate()
 {
	alfa_s_ = steel_.get_E_st() / rebar_.get_E_s();

	alfa_b_ = steel_.get_E_st()/concrete_.get_E_b_tau();

	H_red_ = cconc_sect_-> get_height() + steel_sect -> get_height();

	A_red_= steel_sect -> get_area() +
		   conc_sect -> get_area()/ alfa_b_ +
		   rebar_.get_num_rows() * 1. / alfa_s_ * rebar_.get_A_s() * conc_sect.get_width();;



 }



 double CompositeSectionGeometry2::alfa_s_calc()
{
	return steel_.get_E_st() / rebar_.get_E_s();
}

double CompositeSectionGeometry2::alfa_b_calc()
{
	return steel_.get_E_st()/concrete_.get_E_b_tau();
}
double CompositeSectionGeometry2::compos_sect_height_calc()
{
	return conc_sect_-> get_height() + steel_sect -> get_height();
}

double CompositeSectionGeometry2::compos_sect_area_calc()
{

	return steel_sect -> get_area() +
		   conc_sect -> get_area()/ alfa_b_ +
		   rebar_.get_num_rows() * 1. / alfa_s_ * rebar_.get_A_s() * conc_sect.get_width();
}


