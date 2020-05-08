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
//#define NDEBUG
//---------------------------------------------------------------------------

TCompositeBeam::TCompositeBeam(){}
//---------------------------------------------------------------------------
//Конструктор композитной балки
//---------------------------------------------------------------------------
 TCompositeBeam::TCompositeBeam(TGeometry                geometry,
								TLoads     				 loads,
								CompositeSection         composite_section,
								StudsOnBeam              studs_on_beam,
								WorkingConditionsFactors working_conditions_factors):
    geometry_(geometry),
	loads_(loads),
	composite_section_(composite_section),
	studs_on_beam_(studs_on_beam),
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
	studs_on_beam_.set_default_values();
}
//---------------------------------------------------------------------------
//Сохраняем объект композитная балка в бинарный файл
//---------------------------------------------------------------------------
void TCompositeBeam::save(std::ostream& ostr) const
{
	geometry_.save(ostr);
	loads_.save(ostr);
	working_conditions_factors_.save(ostr);
	composite_section_.save(ostr); /* TODO 1 -oMV : Добавить сохранение объекта StudsOnBeam */
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
}

void TCompositeBeam::calculate()
{
	calculate_composite_beam();
	calculate_studs();
}
//---------------------------------------------------------------------------
//Расчёт композитной балки
//---------------------------------------------------------------------------
void TCompositeBeam::calculate_composite_beam()
{

//расчёт эффективной ширины плиты и подготовка композитного сечения
	double h_f = composite_section_.get_concrete_part().get_h_f();
	double b_uf = composite_section_.get_steel_part().get_section().get_b_uf();
	double b = geometry_.get_effective_width(h_f, b_uf);
	composite_section_.set_b(b);
	composite_section_.calculate();
//полная инициализация нагрузок
	double SW_steel_beam = composite_section_.get_steel_part().get_section().get_weight();
	double SW_corrugated_sheets = 0.;
	if(composite_section_.get_concrete_part().get_slab_type_enum() != SlabType::FLAT)
	{
		String name = composite_section_.get_concrete_part().get_slab_type();
		CorrugatedSheet corrugated_sheet = CorrugatedSheetsData::get_corrugated_sheet(name);
		SW_corrugated_sheets = corrugated_sheet.get_weight();
	}
	double SW_concrete = composite_section_.get_concrete_part().get_SW_concrete();
	double B = geometry_.get_trib_width_left() + geometry_.get_trib_width_right();
	loads_.set_data(SW_steel_beam, SW_corrugated_sheets, SW_concrete, B);
//подготовка калькулятора внутренних усилий
	int tmp_sup_num = geometry_.get_temporary_supports_number();
	double L = geometry_.get_span();
	InternalForcesCalculator intr_frcs_calculator{static_cast<SupportsNumber>(tmp_sup_num), L, loads_ };
//подготовка сечений для расчёта
	sections_beam_.set_composite_section(composite_section_);
	sections_beam_.set_intr_frcs_calculator(intr_frcs_calculator);
	sections_beam_.set_working_conditions_factors(working_conditions_factors_);
	sections_beam_.initialize_section_list(L, tmp_sup_num) ;
//расчёт сечений
	sections_beam_.calculate();

	#ifndef NDEBUG
	FormLogger -> add_separator(L"Проверка сечений");
	FormLogger -> add_separator(L"Координаты сечений");
	for (const auto& section:sections_beam_.get_section_list())
		FormLogger -> print_sections_coordinates(section.get_id(), section.get_x());
	FormLogger -> add_separator(L"Расчётный момент M_Ia");
	for (const auto& section:sections_beam_.get_section_list())
		FormLogger -> print_M_X(section.get_x(), section.get_M_Ia_design());
	FormLogger -> add_separator(L"Расчётный момент M_Ib");
	for (const auto& section:sections_beam_.get_section_list())
		FormLogger -> print_M_X(section.get_x(), section.get_M_Ib_design());
	FormLogger -> add_separator(L"Расчётный момент M_II");
	for (const auto& section:sections_beam_.get_section_list())
		FormLogger -> print_M_X(section.get_x(), section.get_M_II_design());
	FormLogger -> add_separator(L"Расчётный момент полный M_total");
	for (const auto& section:sections_beam_.get_section_list())
		FormLogger -> print_M_X(section.get_x(), section.get_M_total_design());
	FormLogger -> add_separator(L"Расчётная полная поперечная сила Q_total");
	for (const auto& section:sections_beam_.get_section_list())
		FormLogger -> print_M_X(section.get_x(), section.get_Q_total_design());
	FormLogger -> add_separator(L"Напряжения");
	for (const auto& section:sections_beam_.get_section_list())
		FormLogger -> print_sigma_b_sigma_s_X(section.get_x(), section.get_sigma_b(), section.get_sigma_s());
	FormLogger -> add_separator(L"Коэффициенты использования");
	for (const auto& section:sections_beam_.get_section_list())
		FormLogger -> print_ratios(section.get_x(),
								   section.get_upper_fl_ratio(),
								   section.get_lower_fl_ratio(),
								   section.get_conc_ratio(),
								   section.get_shear_ratio());
	#endif
}
//---------------------------------------------------------------------------
//Расчёт гибких упоров композитной балки
//---------------------------------------------------------------------------
void TCompositeBeam::calculate_studs()
{
	//расчёт эффективной ширины плиты и подготовка композитного сечения
	double h_f = composite_section_.get_concrete_part().get_h_f();
	double b_uf = composite_section_.get_steel_part().get_section().get_b_uf();
	double b = geometry_.get_effective_width(h_f, b_uf);
	CompositeSection composite_section = composite_section_;
	composite_section_.set_b(b);
	composite_section.set_phi_b_cr(0);
	//подготовка калькулятора внутренних усилий
	int tmp_sup_num = geometry_.get_temporary_supports_number();
	double L = geometry_.get_span();
	InternalForcesCalculator intr_frcs_calculator{static_cast<SupportsNumber>(tmp_sup_num), L, loads_ };
//подготовка упоров для расчёта
	studs_on_beam_.set_intr_frcs_calculator(intr_frcs_calculator);
	studs_on_beam_.set_composite_section(composite_section);
//расчёт упоров
	studs_on_beam_.calculate_P_rd();
	studs_on_beam_.set_studs(L);
	studs_on_beam_.calculate_S();
	studs_on_beam_.calculate_ratio();

	#ifndef NDEBUG

	FormLogger -> add_separator(L"Проверка упоров");
	FormLogger -> add_separator(L"Координаты упоров");

	for (auto stud:studs_on_beam_.stud_list())
		FormLogger -> print_stud_coordinates(stud.get_id(),
										 stud.get_x(),
										 stud.get_x_l(),
										 stud.get_x_r());

	FormLogger -> add_separator(L"Усилия в упорах");

	for (auto stud:studs_on_beam_.stud_list())

		FormLogger -> print_stud_shear_force(stud.get_id(),
										  stud.get_S());

	FormLogger -> add_separator(L"Коэффициенты использования");

	for (auto stud:studs_on_beam_.stud_list())

		FormLogger -> print_ratio(stud.get_id(),
							  stud.get_ratio());
	#endif
}


double TCompositeBeam::get_max_upper_flange_ratio()const
{
	return 0.;
}
double TCompositeBeam::get_max_lower_flange_ratio()const
{
	return 0.;
}
double TCompositeBeam::get_max_upper_flange_ratio_coordinate()const
{
	return 0.;
}
double TCompositeBeam::get_max_lower_flange_ratio_coordinate()const
{
	return 0.;
}
double TCompositeBeam::get_M_I_for_cs_with_max_lower_flange_ratio(LoadUnit load_unit, LengthUnit length_unit)
{
	return 0.;
}

double TCompositeBeam::get_M_II_for_cs_with_max_lower_flange_ratio(LoadUnit load_unit, LengthUnit length_unit)
{
	return 0.;
}

double TCompositeBeam::get_M_total_for_cs_with_max_lower_flange_ratio(LoadUnit load_unit, LengthUnit length_unit)
{
	return 0.;
}
double TCompositeBeam::get_sigma_b_for_cs_with_max_lower_flange_ratio(LoadUnit load_unit, LengthUnit length_unit)
{
	return 0.;
}
double TCompositeBeam::get_sigma_s_for_cs_with_max_lower_flange_ratio(LoadUnit load_unit, LengthUnit length_unit)
{
	return 0.;
}
double TCompositeBeam::get_max_shear_ratio()const
{
	return 0.;
}
double TCompositeBeam::get_max_steel_beam_direct_stresses_I_stage_ratio()const
{
	return 0.;
}
double TCompositeBeam::get_max_stud_ratio()
{
   return 0;
}
double TCompositeBeam::get_max_stud_ratio_coordinate()
{
	return 0.;
}
double TCompositeBeam::get_max_S_h(LoadUnit load_unit)
{
	return 0.;
}
double TCompositeBeam::get_ratio_rigid_plastic()const
{
	return 0.;
}













