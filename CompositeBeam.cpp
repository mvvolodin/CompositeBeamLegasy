//---------------------------------------------------------------------------

#pragma hdrstop

#include "CompositeBeam.h"
#include "Logger.h"
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
	calc_stresses();
}
//---------------------------------------------------------------------------
//Расчёт внутренних моментов и сил для нормативных случаев загружений
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

	internal_forces_.insert(InternalForcesNamededListItem(LoadCaseNames::SW,InternalForces(SW_l,cs_coordinates_,temporary_supports_number)));
	internal_forces_.insert(InternalForcesNamededListItem(LoadCaseNames::DL_I,InternalForces(DL_I_l,cs_coordinates_,temporary_supports_number)));
	internal_forces_.insert(InternalForcesNamededListItem(LoadCaseNames::DL_II,InternalForces(DL_II_l,cs_coordinates_,0)));
	internal_forces_.insert(InternalForcesNamededListItem(LoadCaseNames::LL,InternalForces(LL_l,cs_coordinates_,0)));

	//формирование списка с внутренними усилиями

	double gamma_f_SW=loads_.get_gamma_f_st_SW();
	double gamma_f_DL_I=loads_.get_gamma_f_DL_I();
	double gamma_f_DL_II=loads_.get_gamma_f_DL_II();
	double gamma_f_LL=loads_.get_gamma_f_LL();

	int cs_num=cs_coordinates_.size();

	std::vector<double> M_I;
	std::vector<double> Q_I;

	for (int i = 0; i < cs_num; i++)
	{

		M_I.push_back(gamma_f_SW*internal_forces_[LoadCaseNames::SW].get_M()[i]+
			   gamma_f_DL_I*internal_forces_[LoadCaseNames::DL_I].get_M()[i]);
		Q_I.push_back(gamma_f_SW*internal_forces_[LoadCaseNames::SW].get_Q()[i]+
			   gamma_f_DL_I*internal_forces_[LoadCaseNames::DL_I].get_Q()[i]);
	}

	internal_forces_.insert(InternalForcesNamededListItem(LoadCaseNames::I_stage, InternalForces(M_I, Q_I)));

	std::vector<double> M_II;
	std::vector<double> Q_II;

	for (int i = 0; i < cs_num; i++)
	{

		M_II.push_back(gamma_f_DL_II*internal_forces_[LoadCaseNames::DL_II].get_M()[i]+
			   gamma_f_LL*internal_forces_[LoadCaseNames::LL].get_M()[i]);
		Q_II.push_back(gamma_f_DL_II*internal_forces_[LoadCaseNames::DL_II].get_Q()[i]+
			   gamma_f_LL*internal_forces_[LoadCaseNames::LL].get_Q()[i]);


	}

	internal_forces_.insert(InternalForcesNamededListItem(LoadCaseNames::II_stage, InternalForces(M_II, Q_II)));

	std::vector<double> M_total;
	std::vector<double> Q_total;

	for (int i = 0; i < cs_num; i++)
	{

		M_total.push_back(M_I[i]+M_II[i]);
		Q_total.push_back(Q_I[i]+Q_II[i]);

	}

	internal_forces_.insert(InternalForcesNamededListItem(LoadCaseNames::Total, InternalForces(M_total, Q_total)));

}
//---------------------------------------------------------------------------
//Расчёт напряжений
//---------------------------------------------------------------------------
void TCompositeBeam::calc_stresses()
{
	stresses_LC_.insert(StressesNamedListItem(LoadCaseNames::SW,Stresses(internal_forces_[LoadCaseNames::SW],composite_section_, working_conditions_factors_)));
	stresses_LC_.insert(StressesNamedListItem(LoadCaseNames::DL_I,Stresses(internal_forces_[LoadCaseNames::DL_I],composite_section_, working_conditions_factors_)));
	stresses_LC_.insert(StressesNamedListItem(LoadCaseNames::DL_II,Stresses(internal_forces_[LoadCaseNames::DL_II],composite_section_, working_conditions_factors_)));
	stresses_LC_.insert(StressesNamedListItem(LoadCaseNames::LL,Stresses(internal_forces_[LoadCaseNames::LL],composite_section_, working_conditions_factors_)));


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





