//---------------------------------------------------------------------------
#pragma hdrstop
//---------------------------------------------------------------------------
#include <cmath>
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
	studs_.set_default_values();
}
//---------------------------------------------------------------------------
//Расчёт композитной балки
//---------------------------------------------------------------------------
void TCompositeBeam::calculate()
{
	calculate_effective_width();
	composite_section_.calculate();
	calc_cs_coordinates();
	calc_studs_coordinates();
	calc_inter_forces();
	calculate_stresses(Impact::II_stage);
	calc_inter_forces_for_studs();
	calc_studs_ratios();
	calc_ratios();
	calc_ratio_rigid_plastic();
	calc_shear_ratios();

	log_stresses();

	get_max_upper_flange_ratio();
	get_max_lower_flange_ratio();

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
//Вычисление координат сечений для определения сдвигающих усилий по
//шву объединения
//---------------------------------------------------------------------------
void TCompositeBeam::calc_studs_coordinates()
{
	double L=geometry_.get_span();
	stud_coordinates_=studs_.calculate_coordinates(L);//нужна ли отдельная функция? название фун-ции достаточно описательное
	studs_num_=studs_.calculate_studs_transverse_rows_number(L);

}
//---------------------------------------------------------------------------
//Расчёт внутренних моментов и сил
//---------------------------------------------------------------------------
void TCompositeBeam::calc_inter_forces_for_studs()
{
	std::vector<Stresses> stresses=stresses_named_list_.at(Impact::II_stage);

	for(int i=0; i<stresses.size(); ++i){//отступление от правила, что во всех циклах используется studs_num_

		double S=0.;
		double sigma_b_r=0.;
		double sigma_s_r=0.;
		double sigma_b_l=0.;
		double sigma_s_l=0.;

		double A_s=composite_section_.get_concrete_part().get_rebar().get_A_s();
		double A_b = composite_section_.get_concrete_part().get_A_b();

		sigma_b_r=stresses[i+1].get_sigma_b();
		sigma_s_r=stresses[i+1].get_sigma_s();
		sigma_b_l=stresses[i].get_sigma_b();
		sigma_s_l=stresses[i].get_sigma_s();

		S=(sigma_b_r * A_b + sigma_s_r * A_s) - (sigma_b_l * A_b + sigma_s_l * A_s);

		S_.emplace_back(S);
	}
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

	std::vector<double> cs_at_midpoints_btw_studs;

	//заполнение вектора кооридинатами сечений между стад-болтами

	for(int i=0;i<(studs_num_-1);++i){
		cs_at_midpoints_btw_studs.emplace_back((stud_coordinates_[i]+stud_coordinates_[i+1])/2.);
	}

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

	InternalForces int_forces_I_SW=InternalForces(SW_l,cs_coordinates_, temporary_supports_number);
	InternalForces int_forces_I_SW_sheets=InternalForces(SW_sheets_l,cs_coordinates_, temporary_supports_number);
	InternalForces int_forces_I_DL_I=InternalForces(DL_I_l,cs_coordinates_, temporary_supports_number);

	InternalForces int_forces_studs_I_SW=InternalForces(SW_l, cs_at_midpoints_btw_studs, temporary_supports_number);
	InternalForces int_forces_studs_I_SW_sheets=InternalForces(SW_sheets_l, cs_at_midpoints_btw_studs, temporary_supports_number);
	InternalForces int_forces_studs_I_DL_I=InternalForces(DL_I_l, cs_at_midpoints_btw_studs, temporary_supports_number);

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

	for (int i = 0; i < (studs_num_ - 1); i++)
	{

		M_I_studs.push_back(gamma_f_SW*int_forces_studs_I_SW.get_M()[i]+
			gamma_f_SW*int_forces_studs_I_SW_sheets.get_M()[i]+
			gamma_f_DL_I*int_forces_studs_I_DL_I.get_M()[i]);
		Q_I_studs.push_back(gamma_f_SW*int_forces_studs_I_SW.get_Q()[i]+
			gamma_f_SW*int_forces_studs_I_SW_sheets.get_Q()[i]+
			gamma_f_DL_I*int_forces_studs_I_DL_I.get_Q()[i]);
	}

	internal_forces_studs_.insert(InternalForcesNamedListItem(Impact::I_stage, InternalForces(M_I_studs, Q_I_studs)));

	//внутренние усилия (I+II) стадии

	InternalForces int_forces_total_SW=InternalForces(SW_l,cs_coordinates_, 0);
	InternalForces int_forces_total_SW_sheets=InternalForces(SW_sheets_l,cs_coordinates_, 0);
	InternalForces int_forces_total_DL_I=InternalForces(DL_I_l,cs_coordinates_, 0);
	InternalForces int_forces_total_DL_II=InternalForces(DL_II_l,cs_coordinates_, 0);
	InternalForces int_forces_total_LL=InternalForces(LL_l,cs_coordinates_, 0);

	InternalForces int_forces_total_studs_SW=InternalForces(SW_l,cs_coordinates_, 0);
	InternalForces int_forces_total_studs_SW_sheets=InternalForces(SW_sheets_l,cs_coordinates_, 0);
	InternalForces int_forces_total_studs_DL_I=InternalForces(DL_I_l,cs_coordinates_, 0);
	InternalForces int_forces_total_studs_DL_II=InternalForces(DL_II_l,cs_coordinates_, 0);
	InternalForces int_forces_total_studs_LL=InternalForces(LL_l,cs_coordinates_, 0);

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

	for (int i = 0; i < (studs_num_ - 1); i++)
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

	for (int i = 0; i < (studs_num_ - 1); i++)
	{

		M_II_studs.push_back(M_total[i] - M_I_studs[i]);
		Q_II_studs.push_back(Q_total[i] - Q_I_studs[i]);

	}

	internal_forces_studs_.insert(InternalForcesNamedListItem(Impact::II_stage, InternalForces(M_II_studs, Q_II_studs)));

}

//---------------------------------------------------------------------------
//Расчёт напряжений в бетоне и арматуре от усилий II стадии
//---------------------------------------------------------------------------

void TCompositeBeam::calculate_stresses(Impact impact)
{
	double W_b_red=composite_section_.get_W_b_red();
	double alfa_b=composite_section_.get_alfa_b();
	double alfa_s=composite_section_.get_alfa_s();
	double gamma_bi=working_conditions_factors_.get_gamma_bi();
	double gamma_si=working_conditions_factors_.get_gamma_si();
	double gamma_c=working_conditions_factors_.get_gamma_c();
	double R_b=composite_section_.get_concrete_part().get_concrete().get_R_b();
	double R_s=composite_section_.get_concrete_part().get_rebar().get_R_s();

	std::vector<Stresses> temp_stresses_list;

		temp_stresses_list.clear();

		for (int i = 0; i < cs_num_; i++)
		{

			double M=internal_forces_[impact].get_M()[i];
			double sigma_b=std::abs(M)/(alfa_b*W_b_red);
			double sigma_s=std::abs(M)/(alfa_s*W_b_red);

			if((sigma_b<gamma_bi*R_b) && (sigma_s<gamma_si*R_s))

				temp_stresses_list.push_back(Stresses{sigma_b,sigma_s,CASE_I});

			else if ((sigma_b>=gamma_bi*R_b) && (sigma_s<gamma_si*R_s))

				temp_stresses_list.push_back(Stresses{sigma_b,sigma_s,CASE_II});

			else if ((sigma_b>=gamma_bi*R_b) && (sigma_s>=gamma_si*R_s))

				temp_stresses_list.push_back(Stresses{sigma_b,sigma_s,CASE_III});
			else
				temp_stresses_list.push_back(Stresses{sigma_b,sigma_s,UNDEFINED});
		}
		stresses_named_list_.insert(StressesNamedListItem(impact,temp_stresses_list));

		std::vector<Stresses> temp_stresses_studs_list;

		temp_stresses_studs_list.clear();

		for (int i = 1; i < (studs_num_-1); i++){

			double M=internal_forces_studs_[impact].get_M()[i];
			double sigma_b=M/(alfa_b*W_b_red);
			double sigma_s=M/(alfa_s*W_b_red);

			if((sigma_b<gamma_bi*R_b) && (sigma_s<gamma_si*R_s))

				temp_stresses_studs_list.emplace_back(Stresses{sigma_b,sigma_s,CASE_I});

			else if ((sigma_b>=gamma_bi*R_b) && (sigma_s<gamma_si*R_s))

				temp_stresses_studs_list.emplace_back(Stresses{sigma_b,sigma_s,CASE_II});

			else if ((sigma_b>=gamma_bi*R_b) && (sigma_s>=gamma_si*R_s))

				temp_stresses_studs_list.emplace_back(Stresses{sigma_b,sigma_s,CASE_III});
			else
				temp_stresses_studs_list.emplace_back(Stresses{sigma_b,sigma_s,UNDEFINED});
		}
		stresses_named_list_.insert(StressesNamedListItem(impact, temp_stresses_studs_list));
}
//---------------------------------------------------------------------------
//Расчёт коэффициентов использования в сечении
//---------------------------------------------------------------------------
// Ratios TCompositeBeam::ratios_cs(double cs_coordinate)
// {
//
//
// }
//---------------------------------------------------------------------------
//Расчёт коэффициентов использования
//---------------------------------------------------------------------------
void TCompositeBeam::calc_ratios()
{
	RatiosList temp_ratios_list;

	for (auto stresses_case:stresses_named_list_)
	{
		temp_ratios_list.clear();

		for (int i = 0; i < cs_num_; i++)
		{
			switch(stresses_case.second[i].get_state())
			{
			case(CASE_I):
				temp_ratios_list.push_back(calculate_I_case(stresses_case.first ,i));
				break;
			case(CASE_II):
				temp_ratios_list.push_back(calculate_II_case(stresses_case.first ,i));
				break;
			case(CASE_III):
				temp_ratios_list.push_back(calculate_III_case(stresses_case.first ,i));
				break;
			}

		}
		ratios_named_list_.insert(RatiosNamedListItem(stresses_case.first,temp_ratios_list));
	}

}
 Ratios TCompositeBeam::calculate_I_case(Impact impact, int cs_id)
{
		double Z_b_st=composite_section_.get_Z_b_st();
		double W_f2_st=composite_section_.get_steel_part().get_section().get_Wf2_st();
		double W_f1_st=composite_section_.get_steel_part().get_section().get_Wf1_st();
		double A_s=composite_section_.get_concrete_part().get_rebar().get_A_s();
		double A_st=composite_section_.get_steel_part().get_section().get_A_st();
		double A_b = composite_section_.get_concrete_part().get_A_b();
		double R_y=composite_section_.get_steel_grade().get_R_y ();
		double R_b=composite_section_.get_concrete_part().get_concrete().get_R_bn();
		double gamma_bi=working_conditions_factors_.get_gamma_bi();
		double gamma_c=working_conditions_factors_.get_gamma_c();
		double A_f2_st=composite_section_.get_steel_part().get_section().get_A_f2_st();

		double sigma_b=stresses_named_list_.at(impact)[cs_id].get_sigma_b();
		double sigma_s=stresses_named_list_.at(impact)[cs_id].get_sigma_s();
		double M=internal_forces_.at(impact).get_M()[cs_id];

		double gamma_1=std::max(1+(gamma_bi*R_b-sigma_b)/(gamma_c*R_y)*A_b/A_f2_st, 1.2);


		double N_b_s=A_b*sigma_b+A_s*sigma_s;

		return Ratios { ((std::abs(M)-Z_b_st*std::abs(N_b_s))/W_f2_st - std::abs(N_b_s)/A_st)/(gamma_1*gamma_c*R_y),
						((std::abs(M)-Z_b_st*std::abs(N_b_s))/W_f1_st + std::abs(N_b_s)/A_st)/(gamma_c*R_y)};

}
Ratios TCompositeBeam::calculate_II_case(Impact impact, int cs_id)
{
		double Z_b_st=composite_section_.get_Z_b_st();
		double W_f2_st=composite_section_.get_steel_part().get_section().get_Wf2_st();
		double W_f1_st=composite_section_.get_steel_part().get_section().get_Wf1_st();
		double A_s=composite_section_.get_concrete_part().get_rebar().get_A_s();
		double R_s=composite_section_.get_concrete_part().get_rebar().get_R_s();
		double A_st=composite_section_.get_steel_part().get_section().get_A_st();
		double A_b = composite_section_.get_concrete_part().get_A_b();
		double R_y=composite_section_.get_steel_grade().get_R_y ();
		double R_b=composite_section_.get_concrete_part().get_concrete().get_R_bn();
		double gamma_bi=working_conditions_factors_.get_gamma_bi();
		double gamma_c=working_conditions_factors_.get_gamma_c();
		double A_f2_st=composite_section_.get_steel_part().get_section().get_A_f2_st();

		double sigma_b=stresses_named_list_.at(impact)[cs_id].get_sigma_b();
		double sigma_s=stresses_named_list_.at(impact)[cs_id].get_sigma_s();
		double M=internal_forces_.at(impact).get_M()[cs_id];


		double N_bR_sR=A_b*R_b+A_s*R_s;
		double N_bR_s=A_b*R_b+A_s*sigma_s;

		return Ratios { ((std::abs(M)-Z_b_st*std::abs(N_bR_sR))/W_f2_st - std::abs(N_bR_sR)/A_st)/(gamma_c*R_y),
						((std::abs(M)-Z_b_st*std::abs(N_bR_s))/W_f1_st + std::abs(N_bR_s)/A_st)/(gamma_c*R_y)};
}
Ratios TCompositeBeam::calculate_III_case(Impact impact, int cs_id)
{
		double Z_b_st=composite_section_.get_Z_b_st();
		double W_f2_st=composite_section_.get_steel_part().get_section().get_Wf2_st();
		double W_f1_st=composite_section_.get_steel_part().get_section().get_Wf1_st();
		double A_s=composite_section_.get_concrete_part().get_rebar().get_A_s();
		double R_s=composite_section_.get_concrete_part().get_rebar().get_R_s();
		double A_st=composite_section_.get_steel_part().get_section().get_A_st();
		double A_b = composite_section_.get_concrete_part().get_A_b();
		double R_y=composite_section_.get_steel_grade().get_R_y ();
		double R_b=composite_section_.get_concrete_part().get_concrete().get_R_bn();
		double gamma_bi=working_conditions_factors_.get_gamma_bi();
		double gamma_c=working_conditions_factors_.get_gamma_c();
		double A_f2_st=composite_section_.get_steel_part().get_section().get_A_f2_st();

		double sigma_b=stresses_named_list_.at(impact)[cs_id].get_sigma_b();
		double sigma_s=stresses_named_list_.at(impact)[cs_id].get_sigma_s();
		double M=internal_forces_.at(impact).get_M()[cs_id];


		double N_bR_sR=A_b*R_b+A_s*R_s;

		return Ratios { ((std::abs(M)-Z_b_st*std::abs(N_bR_sR))/W_f2_st - std::abs(N_bR_sR)/A_st)/(gamma_c*R_y),
						((std::abs(M)-Z_b_st*std::abs(N_bR_sR))/W_f1_st + std::abs(N_bR_sR/A_st))/(gamma_c*R_y)};
}

double TCompositeBeam::get_max_upper_flange_ratio()
{
	RatiosListIterator it_max_upper_flange_ratio;

	for (auto ratios_case:ratios_named_list_)
	   it_max_upper_flange_ratio=max_element(ratios_case.second.begin(),
							 ratios_case.second.end(),
							 [](const Ratios& rat1, const Ratios& rat2)
							 {return rat1.get_ratio_upper_flange()<rat2.get_ratio_upper_flange();});
	return it_max_upper_flange_ratio->get_ratio_upper_flange();
}
double TCompositeBeam::get_max_lower_flange_ratio()
{
	RatiosListIterator it_max_lower_flange_ratio;

	for (auto ratios_case:ratios_named_list_)
	   it_max_lower_flange_ratio=max_element(ratios_case.second.begin(),
							 ratios_case.second.end(),
							 [](const Ratios& rat1, const Ratios& rat2)
							 {return rat1.get_ratio_lower_flange()<rat2.get_ratio_lower_flange();});
	return it_max_lower_flange_ratio->get_ratio_lower_flange();

}

double TCompositeBeam::get_max_stud_ratio()
{
   return *std::max_element(ratios_studs_.begin(),ratios_studs_.end());
}
void TCompositeBeam::log_stresses()
{
	TStrings* mm_lines=FormLogger->mmLogger->Lines;
    mm_lines->Add(L"Напряжения");
	for (auto stresses:stresses_named_list_.at(Impact::II_stage)) {
		mm_lines->Add(L"sigma B="+FloatToStr(stresses.get_sigma_b()));
	}

	mm_lines->Add(L"Коэффициенты использования");
	for (auto ratios:ratios_named_list_.at(Impact::II_stage)) {
		mm_lines->Add(L"КИ верхний пояс="+FloatToStr(ratios.get_ratio_upper_flange()));
	}

	mm_lines->Add(L"Верхний пояс"+FloatToStr(get_max_upper_flange_ratio()));
	mm_lines->Add(L"Нижний пояс"+FloatToStr(get_max_lower_flange_ratio()));

}

void TCompositeBeam::calc_studs_ratios()
{
	double R_b = composite_section_.get_concrete_part().get_concrete().get_R_b();
	double R_y = composite_section_.get_steel_part().get_steel().get_R_y();
	double gamma_c = working_conditions_factors_.get_gamma_c();

	studs_.calculate_capacity(R_b, R_y,gamma_c);
	ratios_studs_=studs_.calc_ratios(S_);

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

}

void TCompositeBeam::calc_shear_ratios()
{
	std::vector<double> Q {get_Q_list(Impact::Total)};
	double Q_Rd = composite_section_.get_steel_part().get_Q_Rd();
	for(auto Q_Ed: Q)
		shear_ratios_.push_back(Q_Ed / Q_Rd);

}
//---------------------------------------------------------------------------
//Получение координаты сечения с макисмальным моментом
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
//Получение координаты сечения с макисмальной поперечной силой
//---------------------------------------------------------------------------
double TCompositeBeam::get_max_abs_Q_coordinate(Impact impact)
{
	std::vector<double> Q_list = get_Q_list(impact);

	auto min_Q= std::min_element(begin(Q_list), end(Q_list));
	auto max_Q = std::max_element(begin(Q_list), end(Q_list));

	int min_Q_index = std::distance(min_Q, Q_list.begin());
	int max_Q_index = std::distance(max_Q, Q_list.begin());

	double cs_min_Q = cs_coordinates_[min_Q_index];
	double cs_max_Q = cs_coordinates_[max_Q_index];

	return (std::abs(*max_Q) > std::abs(*min_Q)) ? cs_max_Q: cs_min_Q;
}
//---------------------------------------------------------------------------
//Получение напряжений по координате и воздействию
//---------------------------------------------------------------------------
Stresses TCompositeBeam::get_stresses(double cs_coordinate, Impact impact)
{
	StressesList sl = stresses_named_list_[impact];

	auto it = std::find(cs_coordinates_.begin(), cs_coordinates_.end(), cs_coordinate);
	int s_index = std::distance(it, cs_coordinates_.begin());

	return sl[s_index];
}
//---------------------------------------------------------------------------
//Получение момента по координате и воздействию
//---------------------------------------------------------------------------
 double TCompositeBeam::get_M(double cs_coordinate, Impact impact)
 {
	InternalForces intr_frcs;



 }
//---------------------------------------------------------------------------
//Получение поперечной силы по координате и воздействию
//---------------------------------------------------------------------------
 double TCompositeBeam::get_Q(double cs_coordinate, Impact impact)
 {


 }











