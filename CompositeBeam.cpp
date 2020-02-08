//---------------------------------------------------------------------------

#pragma hdrstop

#include "CompositeBeam.h"
#include "LoggerFormUnit.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
TCompositeBeam::TCompositeBeam():
					geometry_(TGeometry()),
					loads_(TLoads()),
					working_conditions_factors_(WorkingConditionsFactors()),
					composite_section_(CompositeSection()),
					studs_(TStud()){}
//---------------------------------------------------------------------------
//Конструктор композитной балки
//---------------------------------------------------------------------------
 TCompositeBeam::TCompositeBeam(TGeometry                geometry,
								TLoads     				 loads,
								CompositeSection         composite_section,
								TStud 					 stud,
								WorkingConditionsFactors working_conditions_factors)
	:geometry_(geometry),
	composite_section_(composite_section),
	studs_(stud),
	loads_(loads),
	working_conditions_factors_(working_conditions_factors)
 {
	CS_coordinates_calc();
	calc_inter_forces();
	calculate_stresses();
	calc_ratios();

	log_stresses();

	get_max_upper_flange_ratio();
	get_max_lower_flange_ratio();

}
//---------------------------------------------------------------------------
//Созадём лист с координатами расчётных сечений
//---------------------------------------------------------------------------
void TCompositeBeam::CS_coordinates_calc()
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
//Расчёт внутренних моментов и сил
//---------------------------------------------------------------------------
void TCompositeBeam::calc_inter_forces()
{
	double SW=loads_.get_self_weight();
	double DL_I=loads_.get_dead_load_first_stage();
	double DL_II=loads_.get_dead_load_second_stage();
	double LL=loads_.get_live_load();

	double bl=geometry_.get_trib_width_left();
	double br=geometry_.get_trib_width_right();

	//расчёт линейной нагрузки

	double SW_l=SW;
	double DL_I_l=DL_I*(bl+br)/2.0;
	double DL_II_l=DL_II*(bl+br)/2.0;
	double LL_l=LL*(bl+br)/2.0;


	int temporary_supports_number=geometry_.get_temporary_supports_number();

	//формирование именованного списка с внктрениими усилиями от случаев загружения

	internal_forces_.insert(InternalForcesNamedListItem(Impact::SW,InternalForces(SW_l,cs_coordinates_,temporary_supports_number)));
	internal_forces_.insert(InternalForcesNamedListItem(Impact::DL_I,InternalForces(DL_I_l,cs_coordinates_,temporary_supports_number)));
	internal_forces_.insert(InternalForcesNamedListItem(Impact::DL_II,InternalForces(DL_II_l,cs_coordinates_,0)));
	internal_forces_.insert(InternalForcesNamedListItem(Impact::LL,InternalForces(LL_l,cs_coordinates_,0)));

	//формирование списка с внутренними усилиями

	double gamma_f_SW=loads_.get_gamma_f_st_SW();
	double gamma_f_DL_I=loads_.get_gamma_f_DL_I();
	double gamma_f_DL_II=loads_.get_gamma_f_DL_II();
	double gamma_f_LL=loads_.get_gamma_f_LL();

	int cs_num=cs_coordinates_.size();

	//внутренние усилия (I) стадии

	InternalForces int_forces_I_SW=InternalForces(SW_l,cs_coordinates_, temporary_supports_number);
	InternalForces int_forces_I_DL_I=InternalForces(DL_I_l,cs_coordinates_, temporary_supports_number);

	//формирование именованного списка с расчётными внутренними усилиями I стадии

	std::vector<double> M_I;
	std::vector<double> Q_I;

	for (int i = 0; i < cs_num; i++)
	{

		M_I.push_back(gamma_f_SW*int_forces_I_SW.get_M()[i]+
			   gamma_f_DL_I*int_forces_I_DL_I.get_M()[i]);
		Q_I.push_back(gamma_f_SW*int_forces_I_SW.get_Q()[i]+
			   gamma_f_DL_I*int_forces_I_DL_I.get_Q()[i]);
	}

	internal_forces_.insert(InternalForcesNamedListItem(Impact::I_stage, InternalForces(M_I, Q_I)));

	//внутренние усилия (I+II) стадии

	InternalForces int_forces_total_SW=InternalForces(SW_l,cs_coordinates_, 0);
	InternalForces int_forces_total_DL_I=InternalForces(DL_I_l,cs_coordinates_, 0);
	InternalForces int_forces_total_DL_II=InternalForces(DL_II_l,cs_coordinates_, 0);
	InternalForces int_forces_total_LL=InternalForces(LL_l,cs_coordinates_, 0);

	//формирование именованного списка с расчётными внутренними усилиями (I+II) стадии

	std::vector<double> M_total;
	std::vector<double> Q_total;

	for (int i = 0; i < cs_num; i++)
	{

		M_total.push_back(gamma_f_SW*int_forces_total_SW.get_M()[i]+
			   gamma_f_DL_I*int_forces_total_DL_I.get_M()[i]+
			   gamma_f_DL_II*int_forces_total_DL_II.get_M()[i]+
			   gamma_f_LL*int_forces_total_LL.get_M()[i]);
		Q_total.push_back(gamma_f_SW*int_forces_total_SW.get_Q()[i]+
			   gamma_f_DL_I*int_forces_total_DL_I.get_Q()[i]+
			   gamma_f_DL_II*int_forces_total_DL_II.get_Q()[i]+
			   gamma_f_LL*int_forces_total_LL.get_Q()[i]);

	}

	internal_forces_.insert(InternalForcesNamedListItem(Impact::Total, InternalForces(M_total, Q_total)));

	std::vector<double> M_II;
	std::vector<double> Q_II;

	//формирование списка с внутренними расчётными усилиями от (II) стадий

	for (int i = 0; i < cs_num; i++)
	{

		M_II.push_back(M_total[i]+M_I[i]);
		Q_II.push_back(Q_total[i]+Q_I[i]);

	}

	internal_forces_.insert(InternalForcesNamedListItem(Impact::II_stage, InternalForces(M_II, Q_II)));

}

//---------------------------------------------------------------------------
//Расчёт напряжений в бетоне и арматуре от усилий II стадии
//---------------------------------------------------------------------------

void TCompositeBeam::calculate_stresses()
{
	double W_b_red=composite_section_.get_W_b_red();
	double alfa_b=composite_section_.get_alfa_b();
	double alfa_s=composite_section_.get_alfa_s();
	double gamma_bi=working_conditions_factors_.get_gamma_bi();
	double gamma_si=working_conditions_factors_.get_gamma_si();
	double gamma_c=working_conditions_factors_.get_gamma_c();
	double R_b=composite_section_.get_concrete_part()->get_R_bn();
	double R_s=composite_section_.get_concrete_part()->get_rebar().get_R_s();

	std::vector<Stresses> temp_stresses_list;

		temp_stresses_list.clear();

		for (int i = 0; i < cs_num_; i++){

			double M=internal_forces_[Impact::II_stage].get_M()[i];
			double sigma_b=M/(alfa_b*W_b_red);
			double sigma_s=M/(alfa_s*W_b_red);

			if((sigma_b<gamma_bi*R_b) && (sigma_s<gamma_si*R_s))

				temp_stresses_list.push_back(Stresses{sigma_b,sigma_s,CASE_I});

			else if ((sigma_b>=gamma_bi*R_b) && (sigma_s<gamma_si*R_s))

				temp_stresses_list.push_back(Stresses{sigma_b,sigma_s,CASE_II});

			else if ((sigma_b>=gamma_bi*R_b) && (sigma_s>=gamma_si*R_s))

				temp_stresses_list.push_back(Stresses{sigma_b,sigma_s,CASE_III});
			else
				temp_stresses_list.push_back(Stresses{sigma_b,sigma_s,UNDEFINED});
		}
		stresses_named_list_.insert(StressesNamedListItem(Impact::II_stage,temp_stresses_list));
}

//---------------------------------------------------------------------------
//Расчёт коэффициента уловий работы верхнего пояса
//---------------------------------------------------------------------------
 void TCompositeBeam::calculate_gamma_1()
 {
	double gamma_bi=working_conditions_factors_.get_gamma_bi();
	double R_b=composite_section_.get_concrete_part()->get_R_bn();
	//double R_y=composite_section_->get_steel_part().get_R_y();
   //	gamma_1_=1+(gamma_bi*R_b-sigma_b)/(gamma_c*R_y)*A_b/A_f2_st;
 }
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
		double W_f2_st=composite_section_.get_steel_part().get_Wf2_st();
		double W_f1_st=composite_section_.get_steel_part().get_Wf1_st();
		double A_s=composite_section_.get_concrete_part()->get_rebar().get_A_s();
		double A_st=composite_section_.get_steel_part().get_A_st();
		double A_b=composite_section_.get_concrete_part()->get_A_b();
		double R_y=composite_section_.get_steel_grade().get_R_y ();
		double R_b=composite_section_.get_concrete_part()->get_R_bn();
		double gamma_bi=working_conditions_factors_.get_gamma_bi();
		double gamma_c=working_conditions_factors_.get_gamma_c();
		double A_f2_st=composite_section_.get_steel_part().get_A_f2_st();

		double sigma_b=stresses_named_list_.at(impact)[cs_id].get_sigma_b();
		double sigma_s=stresses_named_list_.at(impact)[cs_id].get_sigma_s();
		double M=internal_forces_.at(impact).get_M()[cs_id];

		double gamma_1=1+(gamma_bi*R_b-sigma_b)/(gamma_c*R_y)*A_b/A_f2_st;

		if (gamma_1>=1.2) {//Выполнить через max std::math
			gamma_1=1.2;
		}

		double N_b_s=A_b*sigma_b+A_s*sigma_s;

		return Ratios { ((M-Z_b_st*N_b_s)/W_f2_st-N_b_s/A_st)/(gamma_1*gamma_c*R_y),
						((M-Z_b_st*N_b_s)/W_f1_st-N_b_s/A_st)/(gamma_c*R_y)};

}
Ratios TCompositeBeam::calculate_II_case(Impact impact, int cs_id)
{
		double Z_b_st=composite_section_.get_Z_b_st();
		double W_f2_st=composite_section_.get_steel_part().get_Wf2_st();
		double W_f1_st=composite_section_.get_steel_part().get_Wf1_st();
		double A_s=composite_section_.get_concrete_part()->get_rebar().get_A_s();
		double R_s=composite_section_.get_concrete_part()->get_rebar().get_R_s();
		double A_st=composite_section_.get_steel_part().get_A_st();
		double A_b=composite_section_.get_concrete_part()->get_A_b();
		double R_y=composite_section_.get_steel_grade().get_R_y ();
		double R_b=composite_section_.get_concrete_part()->get_R_bn();
		double gamma_bi=working_conditions_factors_.get_gamma_bi();
		double gamma_c=working_conditions_factors_.get_gamma_c();
		double A_f2_st=composite_section_.get_steel_part().get_A_f2_st();

		double sigma_b=stresses_named_list_.at(impact)[cs_id].get_sigma_b();
		double sigma_s=stresses_named_list_.at(impact)[cs_id].get_sigma_s();
		double M=internal_forces_.at(impact).get_M()[cs_id];


		double N_bR_sR=A_b*R_b+A_s*R_s;
		double N_bR_s=A_b*R_b+A_s*sigma_s;

		return Ratios { ((M-Z_b_st*N_bR_sR)/W_f2_st-N_bR_sR/A_st)/(gamma_c*R_y),
						((M-Z_b_st*N_bR_s)/W_f1_st-N_bR_s/A_st)/(gamma_c*R_y)};
}
Ratios TCompositeBeam::calculate_III_case(Impact impact, int cs_id)
{
		double Z_b_st=composite_section_.get_Z_b_st();
		double W_f2_st=composite_section_.get_steel_part().get_Wf2_st();
		double W_f1_st=composite_section_.get_steel_part().get_Wf1_st();
		double A_s=composite_section_.get_concrete_part()->get_rebar().get_A_s();
		double R_s=composite_section_.get_concrete_part()->get_rebar().get_R_s();
		double A_st=composite_section_.get_steel_part().get_A_st();
		double A_b=composite_section_.get_concrete_part()->get_A_b();
		double R_y=composite_section_.get_steel_grade().get_R_y ();
		double R_b=composite_section_.get_concrete_part()->get_R_bn();
		double gamma_bi=working_conditions_factors_.get_gamma_bi();
		double gamma_c=working_conditions_factors_.get_gamma_c();
		double A_f2_st=composite_section_.get_steel_part().get_A_f2_st();

		double sigma_b=stresses_named_list_.at(impact)[cs_id].get_sigma_b();
		double sigma_s=stresses_named_list_.at(impact)[cs_id].get_sigma_s();
		double M=internal_forces_.at(impact).get_M()[cs_id];


		double N_bR_sR=A_b*R_b+A_s*R_s;

		return Ratios { ((M-Z_b_st*N_bR_sR)/W_f2_st-N_bR_sR/A_st)/(gamma_c*R_y),
						((M-Z_b_st*N_bR_sR)/W_f1_st-N_bR_sR/A_st)/(gamma_c*R_y)};
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





