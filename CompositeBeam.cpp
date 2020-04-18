//---------------------------------------------------------------------------
#pragma hdrstop
//---------------------------------------------------------------------------
#include <cmath>
#include <array>
//---------------------------------------------------------------------------
#include "CompositeBeam.h"
#include "LoggerFormUnit.h"
#include "MathFunction.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
TCompositeBeam::TCompositeBeam():
					geometry_(TGeometry()),
					loads_(TLoads()),
					working_conditions_factors_(WorkingConditionsFactors()),
					composite_section_(CompositeSection()),
					studs_(Studs()){}
//---------------------------------------------------------------------------
//Конструктор композитной балки
//---------------------------------------------------------------------------
 TCompositeBeam::TCompositeBeam(TGeometry                geometry,
								TLoads     				 loads,
								CompositeSection         composite_section,
								Studs					 stud,
								WorkingConditionsFactors working_conditions_factors)
   :geometry_(geometry),
	composite_section_(composite_section),
	studs_(stud),
	loads_(loads),
	working_conditions_factors_(working_conditions_factors)
{
}
//---------------------------------------------------------------------------
//Присваение данным класса значений по умолчанию
//---------------------------------------------------------------------------
void TCompositeBeam::set_default_values()
{
	geometry_.set_default_values();
	loads_.set_default_values();
	working_conditions_factors_.set_default_values();
	composite_section_.set_default_values();
	composite_section2_ = composite_section_;
	composite_section2_.get_concrete_part().get_concrete().set_phi_b_cr(0);
	studs_.set_default_values();
}
//---------------------------------------------------------------------------
//Сохраняем объект композитная балка в бинарный файл
//---------------------------------------------------------------------------
void TCompositeBeam::save(std::ostream& ostr) const
{
	geometry_.save(ostr);
	loads_.save(ostr);
	working_conditions_factors_.save(ostr);
	composite_section_.save(ostr);
	studs_.save(ostr);

}
//---------------------------------------------------------------------------
//Загружаем объект композитная балка из бинарного файла
//---------------------------------------------------------------------------
void TCompositeBeam::load(std::istream& istr)
{
	geometry_.load(istr);
	loads_.load(istr);
	working_conditions_factors_.load(istr);
	composite_section_.load(istr);
	studs_.load(istr);
}
//---------------------------------------------------------------------------
//Расчёт композитной балки
//---------------------------------------------------------------------------

double TCompositeBeam::shear_force(StudOnBeam stud_on_beam)
{
	double A_s = composite_section2_.get_concrete_part().get_rebar().get_A_s();
	double A_b = composite_section2_.get_concrete_part().get_A_b();

	double sigma_b_r = calculate_sigma_b(stud_on_beam.get_x_r());
	double sigma_s_r = calculate_sigma_s(stud_on_beam.get_x_r());
	double sigma_b_l = calculate_sigma_b(stud_on_beam.get_x_l());
	double sigma_s_l = calculate_sigma_s(stud_on_beam.get_x_l());

	return (sigma_b_r * A_b + sigma_s_r * A_s) - (sigma_b_l * A_b + sigma_s_l * A_s);
}

double TCompositeBeam::calculate_sigma_b(double x)
{
	double W_b_red = composite_section2_.get_W_b_red();
	double alfa_b = composite_section2_.get_alfa_b();

	double M = calculate_M_II_stage(x);

	return std::abs(M)/(alfa_b*W_b_red);
}

double TCompositeBeam::calculate_M_I_stage(double x)
{
	SupportsNumber s_num = static_cast<SupportsNumber>(geometry_.get_temporary_supports_number());

	double bl = geometry_.get_trib_width_left();
	double br = geometry_.get_trib_width_right();

	double SW = loads_.get_self_weight();
	double SW_sh = loads_.get_self_weight_sheets() * (bl + br);
	double DL_I = loads_.get_dead_load_first_stage() * (bl + br);

	double gamma_f_st_SW = loads_.get_gamma_f_st_SW();
	double gamma_f_DL_I = loads_.get_gamma_f_DL_I();

	double LC = gamma_f_st_SW * (SW + SW_sh) + gamma_f_DL_I * DL_I;

	return calculate_M_uniform_load(x, LC, s_num);

}
double TCompositeBeam::calculate_M_R_I_stage(double x)
{
	SupportsNumber s_num = static_cast<SupportsNumber>(geometry_.get_temporary_supports_number());

	double bl = geometry_.get_trib_width_left();
	double br = geometry_.get_trib_width_right();

	double SW = loads_.get_self_weight();
	double SW_sh = loads_.get_self_weight_sheets() * (bl + br);
	double DL_I = loads_.get_dead_load_first_stage() * (bl + br);

	double gamma_f_st_SW = loads_.get_gamma_f_st_SW();
	double gamma_f_DL_I = loads_.get_gamma_f_DL_I();

	double LC = gamma_f_st_SW * (SW + SW_sh) + gamma_f_DL_I * DL_I;

	std::array<double, 4> R_LC = calculate_R(LC, s_num);

	double L = geometry_.get_span();
	double L0 = 0.;

	switch(s_num)
	{
		case(SupportsNumber::Zero):

			return 0;

		case(SupportsNumber::One):

			L0 = L / 2;

			return calculate_M_point_load(x, R_LC[1], L0);

		case(SupportsNumber::Two):

			L0 = L / 3;

			return calculate_M_point_load(x, R_LC[1], L0) + calculate_M_point_load(x, R_LC[2], 2 * L0);

		case(SupportsNumber::Three):

			L0 = L / 4;

			return calculate_M_point_load(x, R_LC[1], L0) + calculate_M_point_load(x, R_LC[2], 2 * L0) + calculate_M_point_load(x, R_LC[2], 3 * L0);
	}
}
double TCompositeBeam::calculate_M_II_stage(double x)
{
	SupportsNumber s_num = static_cast<SupportsNumber>(geometry_.get_temporary_supports_number());

	double bl = geometry_.get_trib_width_left();
	double br = geometry_.get_trib_width_right();

	double DL_II = loads_.get_dead_load_second_stage() * (bl + br);
	double LL = loads_.get_live_load() * (bl + br);

	double gamma_f_DL_II = loads_.get_gamma_f_DL_II();
	double gamma_f_LL = loads_.get_gamma_f_LL();

	double LC_II = gamma_f_DL_II * DL_II + gamma_f_LL * LL;

	double M_LC_II = calculate_M_uniform_load(x, LC_II, SupportsNumber::Zero );
	double M_R_I = calculate_M_R_I_stage(x);

	return M_LC_II + M_R_I;
}


double TCompositeBeam::calculate_M_total(double x)
{
	return calculate_M_I_stage(x) + calculate_M_II_stage(x);
}
std::array<double, 4> TCompositeBeam::calculate_R(double q, SupportsNumber s_num)
{
	double L = geometry_.get_span();
	double L0 = 0.;
	std::array<double, 4> R {};

	switch(s_num)
	{
		case(SupportsNumber::Zero):

			L0 = L;
			R[0]= 0.5 * q * L0;

			return R;

		case(SupportsNumber::One):

			L0 = L / 2;

			R[0] = 0.375 * q * L0;
			R[1] = 1.25 * q * L0;

			return R;

		case(SupportsNumber::Two):

			L0 = L / 3;

			R[0] = 0.4 * q * L0;
			R[1] = 1.1 * q * L0;
			R[2] = 1.1 * q * L0;

			return R;

		case(SupportsNumber::Three):

			L0 = L / 4;

			R[0] = 0.393 * q * L0;
			R[1] = 1.143 * q * L0;
			R[2] = 0.929 * q * L0;
			R[3] = 1.143 * q * L0;

			return R;
	}
}
std::vector<double> TCompositeBeam::calculate_M_I_stage()
{
	std::vector<double> M_I_stage;

	for(auto cs:cs_coordinates_)
	  M_I_stage.push_back(calculate_M_I_stage(cs));

	return M_I_stage;
}
std::vector<double> TCompositeBeam::calculate_M_R_I_stage()
{
	std::vector<double> M_R_I_stage;

	for(auto cs:cs_coordinates_)
		M_R_I_stage.push_back(calculate_M_R_I_stage(cs));

	return M_R_I_stage;
}

std::vector<double> TCompositeBeam::calculate_M_II_stage()
{
	std::vector<double> M_II_stage;

	for(auto cs:cs_coordinates_)
		M_II_stage.push_back(calculate_M_II_stage(cs));

	return M_II_stage;

}
std::vector<double> TCompositeBeam::calculate_M_total()
{
	std::vector<double> M_total;

	for(auto cs:cs_coordinates_)
		M_total.push_back(calculate_M_total(cs));

	return M_total;
}


double TCompositeBeam::calculate_M_uniform_load(double x, double q, SupportsNumber s_num)
{
	double L = geometry_.get_span();
	double L0 = 0.;
	std::array<double, 4> R = calculate_R(q, s_num);

	switch(s_num)
	{
		case(SupportsNumber::Zero):

			L0 = L;

			return R[0] * x - q * x * x / 2;

		case(SupportsNumber::One):

			L0 = L / 2;

			if(x <= L0)
				return R[0] * x - q * x * x / 2;
			return R[0] * (L0 + x) + R[1] * x - q * x * x / 2;

		case(SupportsNumber::Two):

			L0 = L / 3;

			if(x <= L0)
				return R[0] * x - q * x * x / 2;
			if(L0 < x <= 2 * L0)
				return R[0] * (L0 + x) + R[1] * x - q * x * x / 2;
			return R[0] * (2* L0 + x) + R[1] * (L0 + x) + R[2] * x - q * x * x / 2;

		case(SupportsNumber::Three):

			L0 = L / 4;

			if(x <= L0)
				return R[0] * x - q * x * x / 2;
			 if(L0 < x <= 2 * L0)
				return R[0] * (L0 + x) + R[1] * x - q * x * x / 2;
			 if(2 * L0 < x <= 3 * L0)
				return R[0] * (2* L0 + x) + R[1] * (L0 + x) + R[2] * x - q * x * x / 2;
			 return R[0] * (3 * L0 + x) + R[1] * (2 * L0 + x) + R[2] * (L0 + x) - q * x * x / 2;
	}
}
double TCompositeBeam::calculate_M_point_load(double x, double P, double x_P)
{
	double L = geometry_.get_span();

	return P * (L - x_P) / L * x_P;
}

void TCompositeBeam::calculate()
{
  //	for(auto stud_on_beam:stud_on_beam_list)
   //		stud_on_beam.set_shear_force(shear_force(stud_on_beam.get_location()));


 //расчёт эффективной ширины
	calculate_effective_width();
	//расчёт коодинат сечений
	calc_cs_coordinates();
	//расчёт композитных сечений
	composite_section_.calculate();
	composite_section2_ = composite_section_;
	composite_section2_.get_concrete_part().get_concrete().set_phi_b_cr(0);
	composite_section2_.calculate();
	//расчёт начальных данных упоров
	double L = geometry_.get_span();
	double R_b = composite_section_.get_concrete_part().get_concrete().get_R_b();
	double R_y = composite_section_.get_steel_part().get_steel().get_R_y();
	double gamma_c = working_conditions_factors_.get_gamma_c();
	studs_.calculate(L, R_b, R_y, gamma_c);
	stud_coordinates_ = studs_.get_coordinates_list();
	S_coordinates_ = intr_frcs_coordinates_for_studs_verification(stud_coordinates_);

	calc_inter_forces();

	stresses_list_ = calculate_stresses(cs_coordinates_, composite_section_, internal_forces_);
	stresses_list_studs_ = calculate_stresses(S_coordinates_, composite_section2_, internal_forces_studs_);

//	std::vector<Stresses> str = stresses_list_studs_;
//
//	Stresses str_end = str[80];

	S_h_list_ = internal_forces_for_studs(stresses_list_studs_);

	std::vector<double> S_h_list_check = S_h_list_;

	calculate_studs_ratios();

	ratios_cs_list_ = calculate_ratios(cs_coordinates_, internal_forces_);
	calc_ratio_rigid_plastic();
	calculate_shear_ratios();

	//log_stresses();

	double max_uf_rat = get_max_upper_flange_ratio();
	double max_lf_rat = get_max_lower_flange_ratio();

	double M_max = get_max_abs_M(Impact::Total);
	double coord_M_max = get_max_abs_M_coordinate(Impact::Total);
	Stresses stresses = get_stresses(coord_M_max);
	calculate_ratios(M_max, stresses);



	double max_uf_rat_coord = get_upper_flange_ratio_coordinate(max_uf_rat);
	double max_lf_rat_coord = get_lower_flange_ratio_coordinate(max_lf_rat);

	std::vector<double> M_I_stage = calculate_M_I_stage();
	std::vector<double> M_R_I_stage = calculate_M_R_I_stage();
	std::vector<double> M_II_stage = calculate_M_II_stage();
	std::vector<double> M_total = calculate_M_total();

	FormLogger -> clean_logger();

	FormLogger -> add_separator(L"I стадия");
	FormLogger -> print_M_X(M_I_stage);
	FormLogger -> add_separator(L"R I стадия");
	FormLogger -> print_M_X(M_R_I_stage);
	FormLogger -> add_separator(L"II стадия");
	FormLogger -> print_M_X(M_II_stage);
	FormLogger -> add_separator(L"I+II стадии");
	FormLogger -> print_M_X(M_total);

}
//---------------------------------------------------------------------------
//Расчёт эффективной ширины композитного сечения
//---------------------------------------------------------------------------
void TCompositeBeam::calculate_effective_width()
{
	double b_l = 0.;
	double b_r = 0.;

	double h_f = composite_section_.get_concrete_part().get_h_f();
	double b_uf = composite_section_.get_steel_part().get_section().get_b_uf();
	double a=b_uf/2;
	double B_l = geometry_.get_trib_width_left();
	double B_r = geometry_.get_trib_width_right();
	double l = geometry_.get_span();

	if (!geometry_.is_end_beam())
	{
		b_l = calculate_basic_effective_width(h_f,a,B_l,l);
		b_r = calculate_basic_effective_width(h_f,a,B_r,l);
	}
	else
	{
		b_l = calculate_cantilever_effective_width(h_f,a,B_l,l);
		b_r = calculate_basic_effective_width(h_f,a,B_r,l);
	}

	composite_section_.get_concrete_part().set_b_l(b_l);
	composite_section_.get_concrete_part().set_b_r(b_r);

}
//---------------------------------------------------------------------------
//Определение расчётного свеса плиты
//Передаваемые параметры (в порядке представленном в функции):
//  *толщина плиты,
//  *половина ширины контакта  ж.б плиты и стального пояса
//	*расстояние между осями балок
//	*пролёт балки
//---------------------------------------------------------------------------
double TCompositeBeam::calculate_basic_effective_width(double t_sl, double a,  double B, double l)
{
	double b=0;
	if (l>=4*B)
		b=B/2;
	else
		b=a+6*t_sl;
	return clamp(b, l/8, B/2 );
}
//---------------------------------------------------------------------------
//Определение расчётного свеса плиты в случае консоли
//Передаваемые параметры (в порядке представленном в функции):
//  *толщина плиты консоли,
//  *половина ширины контакта  ж.б плиты и стального пояса
//	*длина консольного свеса плиты
//	*пролёт балки
//---------------------------------------------------------------------------
double TCompositeBeam::calculate_cantilever_effective_width(double t_slc, double a,  double C, double l)
{
	double bc=0;
	if (l>=12*C)
		bc=C;
	else
		bc=a+6*t_slc;
	return clamp(bc, l/12, C );
}

//---------------------------------------------------------------------------
//Созадём лист с координатами расчётных сечений
//---------------------------------------------------------------------------
void TCompositeBeam::calc_cs_coordinates()
	{   double span=geometry_.get_span();
		double temporary_supports_number_=geometry_.get_temporary_supports_number();

		double temp_CS_coordinate=0.0;

		//Добавляем в лист координат расчётных сечений координату сечения в середине шарнирно опёртой балки

		cs_coordinates_.push_back(span/2.0);

		for (int n = 0; n <= geometry_.get_beam_division(); ++n)
		{
			temp_CS_coordinate=span/geometry_.get_beam_division()*n;
			cs_coordinates_.push_back(temp_CS_coordinate);
		}
		//добавляем в лист координат расчётных сечений координаты сечений в над промежуточными опорами
		for (int n = 1; n < (temporary_supports_number_+1); ++n)
		{
			temp_CS_coordinate=span/(temporary_supports_number_+1)*n;
			cs_coordinates_.push_back(temp_CS_coordinate);
		}

		//добавляем в в лист координат расчётных сечений кординаты сечений в серединах пролётов
		for (int n = 1; n < (temporary_supports_number_+1); ++n)
		{
			temp_CS_coordinate=span/(2.0*(temporary_supports_number_+1))*n;
			cs_coordinates_.push_back(temp_CS_coordinate);
		}

		std::sort(cs_coordinates_.begin(), cs_coordinates_.end());
		cs_coordinates_.erase( std::unique( cs_coordinates_.begin(), cs_coordinates_.end()), cs_coordinates_.end() );

		cs_num_=cs_coordinates_.size();
	}
//---------------------------------------------------------------------------
//Определение координат для расчёта сдвигающих сил для проверки упоров
//--> лист координат упоров 
//---------------------------------------------------------------------------
std::vector<double> TCompositeBeam::intr_frcs_coordinates_for_studs_verification(std::vector<double> studs_coordinates_list)
{
	std::vector<double> x_list;

	double zero_coordinate = studs_coordinates_list.front();
	double end_coordinate = studs_coordinates_list.back();

	x_list.push_back(zero_coordinate);

	for (int i = 1; i < (studs_coordinates_list.size()-2); ++i)
	   x_list.push_back((studs_coordinates_list[i] + studs_coordinates_list[i+1])/2);

   x_list.push_back(end_coordinate);

   x_list.shrink_to_fit();

   std::transform(x_list.begin(),x_list.end(),x_list.begin(),[](double x){return std::round(x);});

   return x_list;
}
//---------------------------------------------------------------------------
//Расчёт сдвигающих сил
//---------------------------------------------------------------------------
std::vector<double> TCompositeBeam::internal_forces_for_studs(std::vector<Stresses>& stresses )
{
	std::vector<double> S_h_list;
	double A_s = composite_section2_.get_concrete_part().get_rebar().get_A_s();
	double A_b = composite_section2_.get_concrete_part().get_A_b();

	double sigma_b_r = 0.;
	double sigma_s_r = 0.;
	double sigma_b_l = 0.;
	double sigma_s_l = 0.;

	for(auto it = stresses.begin()+1; it != stresses.end()-1; ++it)
	{
		sigma_b_r = (*(it - 1)).get_sigma_b();
		sigma_s_r = (*(it - 1)).get_sigma_s();
		sigma_b_l = (*it).get_sigma_b();
		sigma_s_l = (*it).get_sigma_s();

		S_h_list.push_back((sigma_b_r * A_b + sigma_s_r * A_s) - (sigma_b_l * A_b + sigma_s_l * A_s));
	}

	return S_h_list;
}

//---------------------------------------------------------------------------
//Расчёт внутренних моментов и сил
//---------------------------------------------------------------------------
void TCompositeBeam::calc_inter_forces()
{
	double SW = loads_.get_self_weight();
	double SW_sheets = loads_.get_self_weight_sheets();
	double DL_I = loads_.get_dead_load_first_stage();
	double DL_II = loads_.get_dead_load_second_stage();
	double LL = loads_.get_live_load();

	double bl = geometry_.get_trib_width_left();
	double br = geometry_.get_trib_width_right();

	//расчёт линейной нагрузки

	double SW_l=SW;
	double SW_sheets_l=SW_sheets*(bl+br)/2.;
	double DL_I_l=DL_I*(bl+br)/2.;
	double DL_II_l=DL_II*(bl+br)/2.;
	double LL_l=LL*(bl+br)/2.;


	int temporary_supports_number=geometry_.get_temporary_supports_number();
	double l = geometry_.get_span();

	//заполнение вектора кооридинатами сечений между стад-болтами

	std::vector<double> cs_at_midpoints_btw_studs;
	cs_at_midpoints_btw_studs = intr_frcs_coordinates_for_studs_verification(stud_coordinates_);

	//формирование именованного списка с внктрениими усилиями от случаев загружения для проверки балки

	internal_forces_.insert(InternalForcesNamedListItem(Impact::SW_BEAM,InternalForces(SW_l,cs_coordinates_,temporary_supports_number)));
	internal_forces_.insert(InternalForcesNamedListItem(Impact::SW_SHEETS,InternalForces(SW_sheets_l,cs_coordinates_,temporary_supports_number)));
	internal_forces_.insert(InternalForcesNamedListItem(Impact::DL_I,InternalForces(DL_I_l,cs_coordinates_,temporary_supports_number)));
	internal_forces_.insert(InternalForcesNamedListItem(Impact::DL_II,InternalForces(DL_II_l,cs_coordinates_,0)));
	internal_forces_.insert(InternalForcesNamedListItem(Impact::LL,InternalForces(LL_l,cs_coordinates_,0)));

	//формирование именованного списка с внктрениими усилиями от случаев загружения для проверки объединения

	internal_forces_studs_.insert(InternalForcesNamedListItem(Impact::SW_BEAM,InternalForces(SW_l, cs_at_midpoints_btw_studs,temporary_supports_number)));
	internal_forces_studs_.insert(InternalForcesNamedListItem(Impact::SW_BEAM,InternalForces(SW_sheets_l, cs_at_midpoints_btw_studs,temporary_supports_number)));
	internal_forces_studs_.insert(InternalForcesNamedListItem(Impact::DL_I,InternalForces(DL_I_l, cs_at_midpoints_btw_studs,temporary_supports_number)));
	internal_forces_studs_.insert(InternalForcesNamedListItem(Impact::DL_II,InternalForces(DL_II_l, cs_at_midpoints_btw_studs,0)));
	internal_forces_studs_.insert(InternalForcesNamedListItem(Impact::LL,InternalForces(LL_l, cs_at_midpoints_btw_studs,0)));

	//формирование именованного списка с внктрениими усилиями от комбинаций загружений для проверки балки

	double gamma_f_SW=loads_.get_gamma_f_st_SW();
	double gamma_f_DL_I=loads_.get_gamma_f_DL_I();
	double gamma_f_DL_II=loads_.get_gamma_f_DL_II();
	double gamma_f_LL=loads_.get_gamma_f_LL();


	//внутренние усилия (I) стадии

	InternalForces int_forces_I_SW = InternalForces(SW_l,cs_coordinates_, temporary_supports_number);
	InternalForces int_forces_I_SW_sheets = InternalForces(SW_sheets_l,cs_coordinates_, temporary_supports_number);
	InternalForces int_forces_I_DL_I = InternalForces(DL_I_l,cs_coordinates_, temporary_supports_number);

	InternalForces int_forces_studs_I_SW = InternalForces(SW_l, cs_at_midpoints_btw_studs, temporary_supports_number);
	InternalForces int_forces_studs_I_SW_sheets = InternalForces(SW_sheets_l, cs_at_midpoints_btw_studs, temporary_supports_number);
	InternalForces int_forces_studs_I_DL_I = InternalForces(DL_I_l, cs_at_midpoints_btw_studs, temporary_supports_number);

	//формирование именованного списка с расчётными внутренними усилиями I стадии

	std::vector<double> M_I;
	std::vector<double> Q_I;

	for (int i = 0; i < cs_num_; i++)
	{
		M_I.push_back(gamma_f_SW*int_forces_I_SW.get_M()[i]+
			gamma_f_SW*int_forces_I_SW_sheets.get_M()[i]+
			gamma_f_DL_I*int_forces_I_DL_I.get_M()[i]);
		Q_I.push_back(gamma_f_SW*int_forces_I_SW.get_Q()[i]+
			gamma_f_SW*int_forces_I_SW_sheets.get_Q()[i]+
			   gamma_f_DL_I*int_forces_I_DL_I.get_Q()[i]);
	}

	internal_forces_.insert(InternalForcesNamedListItem(Impact::I_stage, InternalForces(M_I, Q_I, l, temporary_supports_number)));

	std::vector<double> M_I_studs;
	std::vector<double> Q_I_studs;

	for (int i = 0; i < cs_at_midpoints_btw_studs.size(); i++)
	{

		M_I_studs.push_back(gamma_f_SW*int_forces_studs_I_SW.get_M()[i]+
			gamma_f_SW*int_forces_studs_I_SW_sheets.get_M()[i]+
			gamma_f_DL_I*int_forces_studs_I_DL_I.get_M()[i]);
		Q_I_studs.push_back(gamma_f_SW*int_forces_studs_I_SW.get_Q()[i]+
			gamma_f_SW*int_forces_studs_I_SW_sheets.get_Q()[i]+
			gamma_f_DL_I*int_forces_studs_I_DL_I.get_Q()[i]);
	}

	internal_forces_studs_.insert(InternalForcesNamedListItem(Impact::I_stage, InternalForces(M_I_studs, Q_I_studs, l, temporary_supports_number)));

	//внутренние усилия (I+II) стадии

	InternalForces int_forces_total_SW=InternalForces(SW_l,cs_coordinates_, 0);
	InternalForces int_forces_total_SW_sheets=InternalForces(SW_sheets_l,cs_coordinates_, 0);
	InternalForces int_forces_total_DL_I=InternalForces(DL_I_l,cs_coordinates_, 0);
	InternalForces int_forces_total_DL_II=InternalForces(DL_II_l,cs_coordinates_, 0);
	InternalForces int_forces_total_LL=InternalForces(LL_l,cs_coordinates_, 0);

	InternalForces int_forces_total_studs_SW=InternalForces(SW_l,cs_at_midpoints_btw_studs, 0);
	InternalForces int_forces_total_studs_SW_sheets=InternalForces(SW_sheets_l,cs_at_midpoints_btw_studs, 0);
	InternalForces int_forces_total_studs_DL_I=InternalForces(DL_I_l,cs_at_midpoints_btw_studs, 0);
	InternalForces int_forces_total_studs_DL_II=InternalForces(DL_II_l,cs_at_midpoints_btw_studs, 0);
	InternalForces int_forces_total_studs_LL=InternalForces(LL_l,cs_at_midpoints_btw_studs, 0);

	//формирование именованного списка с расчётными внутренними усилиями (I+II) стадии

	std::vector<double> M_total;
	std::vector<double> Q_total;

	for (int i = 0; i < cs_num_; i++)
	{

		M_total.push_back(gamma_f_SW*int_forces_total_SW.get_M()[i]+
			   gamma_f_SW*int_forces_total_SW_sheets.get_M()[i]+
			   gamma_f_DL_I*int_forces_total_DL_I.get_M()[i]+
			   gamma_f_DL_II*int_forces_total_DL_II.get_M()[i]+
			   gamma_f_LL*int_forces_total_LL.get_M()[i]);
		Q_total.push_back(gamma_f_SW*int_forces_total_SW.get_Q()[i]+
			   gamma_f_SW*int_forces_total_SW_sheets.get_Q()[i]+
			   gamma_f_DL_I*int_forces_total_DL_I.get_Q()[i]+
			   gamma_f_DL_II*int_forces_total_DL_II.get_Q()[i]+
			   gamma_f_LL*int_forces_total_LL.get_Q()[i]);

	}

	internal_forces_.insert(InternalForcesNamedListItem(Impact::Total, InternalForces(M_total, Q_total, l, 0)));

	std::vector<double> M_total_studs;
	std::vector<double> Q_total_studs;

	for (int i = 0; i < cs_at_midpoints_btw_studs.size(); i++)
	{

		M_total_studs.push_back(gamma_f_SW*int_forces_total_studs_SW.get_M()[i]+
			gamma_f_SW*int_forces_total_studs_SW_sheets.get_M()[i]+
			gamma_f_DL_I*int_forces_total_studs_DL_I.get_M()[i]+
			gamma_f_DL_II*int_forces_total_studs_DL_II.get_M()[i]+
			gamma_f_LL*int_forces_total_studs_LL.get_M()[i]);
		Q_total_studs.push_back(gamma_f_SW*int_forces_total_studs_SW.get_Q()[i]+
			gamma_f_SW*int_forces_total_studs_SW_sheets.get_Q()[i]+
			gamma_f_DL_I*int_forces_total_studs_DL_I.get_Q()[i]+
			gamma_f_DL_II*int_forces_total_studs_DL_II.get_Q()[i]+
			gamma_f_LL*int_forces_total_studs_LL.get_Q()[i]);
	}

	internal_forces_studs_.insert(InternalForcesNamedListItem(Impact::Total, InternalForces(M_total_studs, Q_total_studs)));

	std::vector<double> M_II;
	std::vector<double> Q_II;

	//формирование списка с внутренними расчётными усилиями от (II) стадий

	for (int i = 0; i < cs_num_; i++)
	{

		M_II.push_back(M_total[i] - M_I[i]);
		Q_II.push_back(Q_total[i] - Q_I[i]);

	}

	internal_forces_.insert(InternalForcesNamedListItem(Impact::II_stage, InternalForces(M_II, Q_II, l, 0)));

	std::vector<double> M_II_studs;
	std::vector<double> Q_II_studs;

	//формирование списка с внутренними расчётными усилиями от (II) стадий

	for (int i = 0; i < cs_at_midpoints_btw_studs.size(); i++)
	{

		M_II_studs.push_back(M_total_studs[i] - M_I_studs[i]);
		Q_II_studs.push_back(Q_total_studs[i] - Q_I_studs[i]);

	}

	internal_forces_studs_.insert(InternalForcesNamedListItem(Impact::II_stage, InternalForces(M_II_studs, Q_II_studs)));

}
Stresses TCompositeBeam::calculate_stresses(double M, CompositeSection& cs)
{
	double W_b_red = cs.get_W_b_red();
	double alfa_b = cs.get_alfa_b();
	double alfa_s = cs.get_alfa_s();

	double R_b = cs.get_concrete_part().get_concrete().get_R_b();
	double R_s = cs.get_concrete_part().get_rebar().get_R_s();

	double gamma_bi = working_conditions_factors_.get_gamma_bi();
	double gamma_si = working_conditions_factors_.get_gamma_si();
	double gamma_c = working_conditions_factors_.get_gamma_c();

	double sigma_b = std::abs(M)/(alfa_b*W_b_red);
	double sigma_s = std::abs(M)/(alfa_s*W_b_red);

	if((sigma_b<gamma_bi*R_b) && (sigma_s<gamma_si*R_s))
	
		return Stresses {sigma_b,sigma_s,CASE_I};
		
	else if ((sigma_b>=gamma_bi*R_b) && (sigma_s<gamma_si*R_s))

		return Stresses{sigma_b,sigma_s,CASE_II};
		
	else if ((sigma_b>=gamma_bi*R_b) && (sigma_s>=gamma_si*R_s))
	 
		return Stresses{sigma_b,sigma_s,CASE_III};

	else

		return Stresses{sigma_b,sigma_s,UNDEFINED};
}
//---------------------------------------------------------------------------
//Расчёт напряжений в бетоне и арматуре от усилий II стадии
//---------------------------------------------------------------------------
std::vector<Stresses> TCompositeBeam::calculate_stresses(std::vector<double>& x_list, CompositeSection& cs, InternalForcesNamedList& intr_frcs)
{
	std::vector<Stresses> stresses_list;

	for (auto x:x_list)
		stresses_list.push_back(calculate_stresses(get_M(x, Impact::II_stage, intr_frcs, x_list), cs));			return stresses_list;

}

std::vector<Ratios> TCompositeBeam::calculate_ratios(std::vector<double>& cs_coordinates, InternalForcesNamedList& intr_frcs){	std::vector<Ratios> ratios_list;	for (auto cs_s:cs_coordinates)		ratios_list.push_back(calculate_ratios(get_M(cs_s, Impact::Total, intr_frcs, cs_coordinates), get_stresses(cs_s)));	return ratios_list;
}
Ratios TCompositeBeam::calculate_ratios(double M, Stresses stresses)
{
	double Z_b_st = composite_section_.get_Z_b_st();
	double W_f2_st = composite_section_.get_steel_part().get_section().get_Wf2_st();
	double W_f1_st = composite_section_.get_steel_part().get_section().get_Wf1_st();
	double A_s = composite_section_.get_concrete_part().get_rebar().get_A_s();
	double R_s=composite_section_.get_concrete_part().get_rebar().get_R_s();
	double A_st = composite_section_.get_steel_part().get_section().get_A_st();
	double A_b = composite_section_.get_concrete_part().get_A_b();
	double R_y = composite_section_.get_steel_grade().get_R_y ();
	double R_b = composite_section_.get_concrete_part().get_concrete().get_R_bn();
	double gamma_bi = working_conditions_factors_.get_gamma_bi();
	double gamma_c = working_conditions_factors_.get_gamma_c();
	double A_f2_st = composite_section_.get_steel_part().get_section().get_A_f2_st();

	double sigma_b = stresses.get_sigma_b();
	double sigma_s = stresses.get_sigma_s();
	StressStateCase state = stresses.get_state();

	double gamma_1 = 0.;
	double N_b_s = 0.;
	double N_bR_sR = 0.;
	double N_bR_s = 0.;

	double ratio_uf = 0.;
	double ratio_lf = 0.;

	switch(state)
	{
	case(CASE_I):

		gamma_1 = std::min(1+(gamma_bi*R_b-sigma_b)/(gamma_c*R_y)*A_b/A_f2_st, 1.2);
		N_b_s = A_b*sigma_b+A_s*sigma_s;
		ratio_uf = ((std::abs(M)-Z_b_st*std::abs(N_b_s))/W_f2_st - std::abs(N_b_s)/A_st)/(gamma_1*gamma_c*R_y);
		ratio_lf = ((std::abs(M)-Z_b_st*std::abs(N_b_s))/W_f1_st + std::abs(N_b_s)/A_st)/(gamma_c*R_y);
		return Ratios {ratio_uf, ratio_lf};

	case(CASE_II):

		N_bR_sR=A_b*R_b+A_s*R_s;
		N_bR_s=A_b*R_b+A_s*sigma_s;
		ratio_uf = ((std::abs(M)-Z_b_st*std::abs(N_bR_sR))/W_f2_st - std::abs(N_bR_sR)/A_st)/(gamma_c*R_y);
		ratio_lf = ((std::abs(M)-Z_b_st*std::abs(N_bR_s))/W_f1_st + std::abs(N_bR_s)/A_st)/(gamma_c*R_y);
		return Ratios {ratio_uf, ratio_lf};

	case(CASE_III):

		N_bR_sR=A_b*R_b+A_s*R_s;

		ratio_uf = ((std::abs(M)-Z_b_st*std::abs(N_bR_sR))/W_f2_st - std::abs(N_bR_sR)/A_st)/(gamma_c*R_y);
		ratio_lf = ((std::abs(M)-Z_b_st*std::abs(N_bR_sR))/W_f1_st + std::abs(N_bR_sR/A_st))/(gamma_c*R_y);
		return Ratios {ratio_uf, ratio_lf};
	}
}


double TCompositeBeam::get_max_upper_flange_ratio()const
{
	Ratios ratios = *max_element(ratios_cs_list_.begin(),
								ratios_cs_list_.end(),
								[](const Ratios& rat1, const Ratios& rat2)
								{return std::abs(rat1.get_ratio_upper_flange()) < std::abs(rat2.get_ratio_upper_flange());});

	return ratios.get_ratio_upper_flange();
}
double TCompositeBeam::get_max_lower_flange_ratio()const
{
	Ratios ratios = *max_element(ratios_cs_list_.begin(),
								ratios_cs_list_.end(),
								[](const Ratios& rat1, const Ratios& rat2)
								{return std::abs(rat1.get_ratio_lower_flange()) < std::abs(rat2.get_ratio_lower_flange());});
	return ratios.get_ratio_lower_flange();
}

double TCompositeBeam::get_max_stud_ratio()
{
   return *std::max_element(ratios_studs_.begin(),ratios_studs_.end());
}
void TCompositeBeam::log_stresses()
{
	TStrings* mm_lines = FormLogger -> mm_logger->Lines;
	mm_lines->Add(L"Напряжения");
	for (auto stresses:stresses_list_) {
		mm_lines->Add(L"sigma B="+FloatToStr(stresses.get_sigma_b()));
	}

	mm_lines->Add(L"Коэффициенты использования");
	for (auto ratios:ratios_cs_list_) {
		mm_lines->Add(L"КИ верхний пояс="+FloatToStr(ratios.get_ratio_upper_flange()));
	}

	mm_lines->Add(L"Верхний пояс"+FloatToStr(get_max_upper_flange_ratio()));
	mm_lines->Add(L"Нижний пояс"+FloatToStr(get_max_lower_flange_ratio()));

}

void TCompositeBeam::calculate_studs_ratios()
{
	double P_rd = studs_.get_P_rd();
	double num_e = studs_.get_edge_rows_num();
	double num_m = studs_.get_middle_rows_num();
	std::vector<double> studs_coordinates_list = studs_.get_coordinates_list();
	double L3 = geometry_.get_span() / 3;

	std::vector<double> ratios;

	int i = 0;

	ratios.push_back(0.);//первый упор не проверяется, считается, что КИ = 0

	for(auto it = studs_coordinates_list.begin()+1; it != studs_coordinates_list.end()-1; ++it)
	{

		double temp_ratio = 0.;
		double S_h = S_h_list_[i -1];

		if (L3 <= studs_coordinates_list[i] <= 2 * L3)
		{
		   temp_ratio = std::abs(S_h)/P_rd/num_m;
		   ratios.push_back(temp_ratio);
		}
		else
		{
			temp_ratio = std::abs(S_h)/P_rd/num_e;
			ratios.push_back(temp_ratio);
		}
		++i;
	}
	ratios_studs_ = ratios;
}

TCompositeBeam::NeutralAxis TCompositeBeam::calc_neutral_axis()
{
	double x_b = 0.;
	double x_f2 = 0.;
	double x_w = 0.;

	const double b_sl = composite_section_.get_concrete_part().get_b_sl();
	const double R_b = composite_section_.get_concrete_part().get_concrete().get_R_b();
	const double R_y = composite_section_.get_steel_part().get_steel().get_R_y();
	const double A_st = composite_section_.get_steel_part().get_section().get_A_st();
	const double A_f1_st = composite_section_.get_steel_part().get_section().get_A_f1_st();
	const double A_f2_st = composite_section_.get_steel_part().get_section().get_A_f2_st();
	const double R_s = composite_section_.get_concrete_part().get_rebar().get_R_s();
	const double A_s = composite_section_.get_concrete_part().get_rebar().get_A_s();
	const double b_s = composite_section_.get_b_s();
	const double h_b = composite_section_.get_concrete_part().get_h_b();
	const double t_f2 = composite_section_.get_steel_part().get_section().get_t_uf();
	const double b_f2 = composite_section_.get_steel_part().get_section().get_b_uf();
	const double A_w_st = composite_section_.get_steel_part().get_section().get_A_w_st();
	const double h_w = composite_section_.get_steel_part().get_section().get_h_w();
	const double t_w = composite_section_.get_steel_part().get_section().get_t_w();
	const double A_b = composite_section_.get_concrete_part().get_A_b();
	const double C_b = composite_section_.get_concrete_part().get_C_b();

	const double h_f = 2* (h_b - C_b);

	x_b = (R_y * A_st + R_s * A_s * b_s)/(R_b * b_sl);

	x_f2 = (A_f1_st * R_y + (h_b + t_f2) * b_f2 * R_y + A_w_st*R_y + h_b * b_f2 * R_y
		- R_b * A_b - R_s * A_s * b_s) / ( 2 * b_f2 * R_y);

	x_w = (A_f1_st * R_y + (h_b + t_f2 + h_w) * t_w * R_y + (h_b + t_f2) * t_w * R_y
		 - R_b * A_b - A_f2_st * R_y - R_s * A_s  * b_s ) / ( 2 * t_w * R_y);

	if (x_b <= h_f)
		return NeutralAxis {NA_Location::CONCRETE, x_b};

	if ((x_f2 <= (h_b + t_f2)) && (x_f2 >= h_b))
		return NeutralAxis {NA_Location::UPPER_FLANGE, x_f2};

	if ((x_w <= (h_b + t_f2 + h_w)) && (x_w >= (h_b + t_f2)))
		return NeutralAxis {NA_Location::WEB, x_w};

	return NeutralAxis {NA_Location::NO_SOLUTION, 0.};
}

double TCompositeBeam::calc_rigid_plastic_moment()
{
	double M_Rd = 0.;

	auto [na_location, x_na] {calc_neutral_axis()};
	const double R_b = composite_section_.get_concrete_part().get_concrete().get_R_b();
	const double C_b = composite_section_.get_concrete_part().get_C_b();
	const double b_sl = composite_section_.get_concrete_part().get_b_sl();
	const double h_b = composite_section_.get_concrete_part().get_h_b();
	const double R_y = composite_section_.get_steel_part().get_steel().get_R_y();
	const double t_f2 = composite_section_.get_steel_part().get_section().get_t_uf();
	const double b_f2 = composite_section_.get_steel_part().get_section().get_b_uf();
	const double t_f1 = composite_section_.get_steel_part().get_section().get_t_lf();
	const double h_w = composite_section_.get_steel_part().get_section().get_h_w();
	const double t_w = composite_section_.get_steel_part().get_section().get_t_w();
	const double A_st = composite_section_.get_steel_part().get_section().get_A_st();
	const double A_w_st = composite_section_.get_steel_part().get_section().get_A_w_st();
	const double A_f1_st = composite_section_.get_steel_part().get_section().get_A_f1_st();
	const double A_f2_st = composite_section_.get_steel_part().get_section().get_A_f2_st();

	const double h_f = 2* (h_b - C_b);

	switch(na_location)
	{
		case NA_Location::CONCRETE:

			return

			M_Rd = -1. * R_b * b_sl * x_na * x_na / 2. +
			R_y * A_f2_st * (h_b + t_f2/2.) +
			R_y * A_w_st * (h_b + t_f2 + h_w/2.) +
			R_y * A_f1_st * (h_b + t_f2 + h_w + t_f1 / 2.);

		case NA_Location::UPPER_FLANGE:

			return

			M_Rd = -1. * R_b * b_sl * h_f * h_f / 2. +
			-1. * R_y * (x_na - h_b) * b_f2 * ((x_na - h_b) / 2. + h_b) +
			R_y * (h_b + t_f2 - x_na) * b_f2 * ((h_b + t_f2 - x_na) / 2. + x_na) +
			R_y * t_w * h_w * (h_b + t_f2 + h_w / 2.) +
			R_y * A_f1_st * (h_b + t_f2 + h_w + t_f1 / 2.);

		case NA_Location::WEB:

			return

			M_Rd = -1. * R_b * b_sl * h_f * h_f/2. +
			-1. * R_y * A_f2_st * (h_b + t_f2 / 2) +
			-1. * R_y * t_w * (x_na - h_b - t_f1) * ((x_na - h_b - t_f1) / 2. + h_b + t_f2) +
			R_y * t_w * (h_b + t_f2 + h_w - x_na) * ((h_b + t_f2 + h_w - x_na) / 2. + h_b + t_f2 + h_w / 2.) +
			R_y * A_f1_st * (h_b + t_f2 + h_w + t_f1 / 2);

		case NA_Location::NO_SOLUTION:

			return M_Rd = 1.;
	}
}

void TCompositeBeam::calc_ratio_rigid_plastic()
{
	std::vector<double> M {get_M_list(Impact::Total)};
	double M_Ed = *std::max_element(M.begin(),M.end());
	double M_Rd = calc_rigid_plastic_moment();
	ratio_rigid_plastic_ = M_Ed / M_Rd;

}

std::vector<double> TCompositeBeam::get_M_list(Impact impact)
{
  return internal_forces_[impact].get_M();

}
std::vector<double> TCompositeBeam::get_Q_list(Impact impact)
{
  return internal_forces_[impact].get_Q();

}

double TCompositeBeam::get_max_abs_M(Impact impact)
{
	std::vector<double> M_list = get_M_list(impact);
	double max_M = *max_element(M_list.begin(), M_list.end());
	double min_M = *min_element(M_list.begin(), M_list.end());

	return std::max(std::abs(max_M), std::abs(min_M));
}
double TCompositeBeam::get_max_abs_Q(Impact impact)
{
    return 0.;
}
void TCompositeBeam::calculate_shear_ratios()
{
	std::vector<double> Q {get_Q_list(Impact::Total)};
	double Q_Rd = composite_section_.get_steel_part().get_Q_Rd();
	for(auto Q_Ed: Q)
		shear_ratios_.push_back(Q_Ed / Q_Rd);
}
//---------------------------------------------------------------------------
//Определение координаты сечения с макисмальным моментом
//---------------------------------------------------------------------------
double TCompositeBeam::get_max_abs_M_coordinate(Impact impact)
{
	std::vector<double> M_list = get_M_list(impact);

	auto min_M= std::min_element(begin(M_list), end(M_list));
	auto max_M = std::max_element(begin(M_list), end(M_list));

	int min_M_index = min_M - M_list.begin();
	int max_M_index = max_M - M_list.begin();

	double cs_min_M = cs_coordinates_[min_M_index];
	double cs_max_M = cs_coordinates_[max_M_index];

	return (std::abs(*max_M) > std::abs(*min_M)) ? cs_max_M: cs_min_M;
}

//---------------------------------------------------------------------------
//Определение координаты сечения с макисмальной поперечной силой
//---------------------------------------------------------------------------
double TCompositeBeam::get_max_abs_Q_coordinate(Impact impact)
{
	std::vector<double> Q_list = get_Q_list(impact);

	auto min_Q= std::min_element(begin(Q_list), end(Q_list));
	auto max_Q = std::max_element(begin(Q_list), end(Q_list));

	int min_Q_index = std::distance(Q_list.begin(), min_Q);
	int max_Q_index = std::distance(Q_list.begin(), max_Q);

	double cs_min_Q = cs_coordinates_[min_Q_index];
	double cs_max_Q = cs_coordinates_[max_Q_index];

	return (std::abs(*max_Q) > std::abs(*min_Q)) ? cs_max_Q: cs_min_Q;
}

//---------------------------------------------------------------------------
//Определение напряжений по координате
//---------------------------------------------------------------------------
Stresses TCompositeBeam::get_stresses(double cs_coordinate)
{
	auto it = std::find(cs_coordinates_.begin(), cs_coordinates_.end(), cs_coordinate);
	int index = std::distance(cs_coordinates_.begin(), it);

	return stresses_list_[index];
}
//---------------------------------------------------------------------------
//Определение момента по координате и воздействию
//---------------------------------------------------------------------------
 double TCompositeBeam::get_M(double cs_coordinate, Impact impact, InternalForcesNamedList& intr_frcs_named_list, std::vector<double> cs_list)
 {
	const InternalForces& intr_frcs = intr_frcs_named_list.at(impact);

	auto it = std::find(cs_list.begin(), cs_list.end(), cs_coordinate);
	int index = std::distance(cs_list.begin(), it);

	return intr_frcs.get_M()[index];
 }


 //---------------------------------------------------------------------------
//Определение вектора моментов по вектору координат и воздействию
//---------------------------------------------------------------------------
std::vector<double> TCompositeBeam::get_M(std::vector<double>& cs_coordinates, Impact impact, InternalForcesNamedList& intr_frcs_named_list)
 {
	std::vector<double> M_list;

	for(auto cs_c:cs_coordinates)
		M_list.push_back(get_M(cs_c, impact, intr_frcs_named_list, cs_coordinates));

	return M_list;
 }
//---------------------------------------------------------------------------
//Определение поперечной силы по координате и воздействию
//---------------------------------------------------------------------------
 double TCompositeBeam::get_Q(double cs_coordinate, Impact impact)
 {
	InternalForces& intr_frcs = internal_forces_[impact];

	auto it = std::find(cs_coordinates_.begin(), cs_coordinates_.end(), cs_coordinate);
	int index = std::distance(cs_coordinates_.begin(), it);

	return intr_frcs.get_Q()[index];
 }
//---------------------------------------------------------------------------
//Определение координаты по КИ верхнего пояса
//---------------------------------------------------------------------------
double TCompositeBeam::get_upper_flange_ratio_coordinate(double uf_ratio)const
{
	auto it = find_if(ratios_cs_list_.begin(),ratios_cs_list_.end(),
					  [uf_ratio](const Ratios& rat)
					  {return rat.get_ratio_upper_flange() == uf_ratio;});
	int index = std::distance(ratios_cs_list_.begin(), it);
	return cs_coordinates_[index];
}
//---------------------------------------------------------------------------
// Определение координаты сечения по КИ нижнего пояса
//---------------------------------------------------------------------------
double TCompositeBeam::get_lower_flange_ratio_coordinate(double lf_ratio)const
{
	auto it = find_if(ratios_cs_list_.begin(),ratios_cs_list_.end(),
					  [lf_ratio](const Ratios& rat)
					  {return rat.get_ratio_lower_flange() == lf_ratio;});
	int index = std::distance(ratios_cs_list_.begin(), it);
	return cs_coordinates_[index];
}
//---------------------------------------------------------------------------
// Определение координаты сечения с максимальным КИ верхнего пояса
//---------------------------------------------------------------------------
double TCompositeBeam::get_max_upper_flange_ratio_coordinate()const
{
	const double x = get_max_upper_flange_ratio();

	return get_upper_flange_ratio_coordinate(x);
}
//---------------------------------------------------------------------------
// Определение координаты сечения с максимальным КИ нижнего пояса
//---------------------------------------------------------------------------
double TCompositeBeam::get_max_lower_flange_ratio_coordinate()const
{
	const double x = get_max_lower_flange_ratio();

	return get_lower_flange_ratio_coordinate(x);
}
//---------------------------------------------------------------------------
// Определение изгибающего момента I стадии в сечении с максимальным КИ нижнего пояса
//---------------------------------------------------------------------------
double TCompositeBeam::get_M_I_for_cs_with_max_lower_flange_ratio(LoadUnit load_unit, LengthUnit length_unit)
{
	double x = get_max_lower_flange_ratio_coordinate();
	return get_M(x, Impact::I_stage, internal_forces_, cs_coordinates_)/static_cast<int>(load_unit)/static_cast<int>(length_unit);
}
//---------------------------------------------------------------------------
// Определение изгибающего момента II стадии в сечении с максимальным КИ нижнего пояса
//---------------------------------------------------------------------------
double TCompositeBeam::get_M_II_for_cs_with_max_lower_flange_ratio(LoadUnit load_unit, LengthUnit length_unit)
{
	double x = get_max_lower_flange_ratio_coordinate();
	return get_M(x, Impact::II_stage, internal_forces_, cs_coordinates_)/static_cast<int>(load_unit)/static_cast<int>(length_unit);
}
//---------------------------------------------------------------------------
// Определение полного изгибающего момента в сечении с максимальным КИ нижнего пояса
//---------------------------------------------------------------------------
double TCompositeBeam::get_M_total_for_cs_with_max_lower_flange_ratio(LoadUnit load_unit, LengthUnit length_unit)
{
	double x = get_max_lower_flange_ratio_coordinate();
	return get_M(x, Impact::Total, internal_forces_, cs_coordinates_)/static_cast<int>(load_unit)/static_cast<int>(length_unit);
}
//---------------------------------------------------------------------------
// Определение напряжения в бетоне в сечении с максимальным КИ нижнего пояса
//---------------------------------------------------------------------------
double TCompositeBeam::get_sigma_b_for_cs_with_max_lower_flange_ratio(LoadUnit load_unit, LengthUnit length_unit)
{
	double x = get_max_lower_flange_ratio_coordinate();
	return get_stresses(x).get_sigma_b()/static_cast<int>(load_unit)*std::pow(static_cast<int>(length_unit),2);
}
//---------------------------------------------------------------------------
// Определение напряжения в арматуре в сечении с максимальным КИ нижнего пояса
//---------------------------------------------------------------------------
double TCompositeBeam::get_sigma_s_for_cs_with_max_lower_flange_ratio(LoadUnit load_unit, LengthUnit length_unit)
{
	double x = get_max_lower_flange_ratio_coordinate();
	return get_stresses(x).get_sigma_s()/static_cast<int>(load_unit)*std::pow(static_cast<int>(length_unit),2);
}
//---------------------------------------------------------------------------
// Определение координаты упора с максимальным КИ
//---------------------------------------------------------------------------
double TCompositeBeam::get_max_stud_ratio_coordinate()
{
	double x = get_max_stud_ratio();

	return get_stud_ratio_coordinate(x);

}
//---------------------------------------------------------------------------
// Определение координаты упора по КИ
//--------------------------------------------------------------------------
double TCompositeBeam::get_stud_ratio_coordinate(double ratio)
{
	std::vector<double> studs_coordinates_list = studs_.get_coordinates_list();

	auto it = find(ratios_studs_.begin(),ratios_studs_.end(),ratio);

	int index = std::distance(ratios_studs_.begin(), it);
	return studs_coordinates_list[index];
}
double TCompositeBeam::get_max_S_h(LoadUnit load_unit)
{
	double max_S_h = *std::max_element(S_h_list_.begin(),S_h_list_.end());
	double min_S_h = *std::min_element(S_h_list_.begin(),S_h_list_.end());

	return std::max(std::abs(max_S_h),std::abs(min_S_h))/static_cast<int>(load_unit);
}











