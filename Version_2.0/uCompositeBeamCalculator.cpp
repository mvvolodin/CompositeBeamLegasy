//---------------------------------------------------------------------------
#pragma hdrstop
//---------------------------------------------------------------------------
#include <cmath>
#include <array>
//---------------------------------------------------------------------------
#include "uCompositeBeamCalculator.h"
#include "uFrmLogger.h"
#include "MathFunction.h"
#include "Constants.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

CompositeBeamCalculator::CompositeBeamCalculator(){}
//---------------------------------------------------------------------------
//Конструктор композитной балки
//---------------------------------------------------------------------------
 CompositeBeamCalculator::CompositeBeamCalculator(Geometry   			   geometry,
												  Loads     			   loads,
												  CompositeSectionGeometry composite_section,
												  StudsOnBeam              studs_on_beam,
												  WorkingConditionsFactors working_conditions_factors,
												  double 				   max_elem_length):
	geometry_(geometry),
	loads_(loads),
	composite_section_(composite_section),
	studs_on_beam_(studs_on_beam),
	working_conditions_factors_(working_conditions_factors),
	max_elem_length_(max_elem_length)
{

}

//---------------------------------------------------------------------------
//Присваение данным класса значений по умолчанию
//---------------------------------------------------------------------------
void CompositeBeamCalculator::set_default_values()
{
	geometry_.set_default_values();
	loads_.set_default_values();
	working_conditions_factors_.set_default_values();
	composite_section_.set_default_values();
	studs_on_beam_.set_default_values();

	max_elem_length_ = 100;
}
//---------------------------------------------------------------------------
//Сохраняем объект композитная балка в бинарный файл
//---------------------------------------------------------------------------
void CompositeBeamCalculator::save(std::ostream& ostr) const
{
	geometry_.save(ostr);
	loads_.save(ostr);
	working_conditions_factors_.save(ostr);
	composite_section_.save(ostr);
	studs_on_beam_.save(ostr);
}
//---------------------------------------------------------------------------
//Загружаем объект композитная балка из бинарного файла
//---------------------------------------------------------------------------
void CompositeBeamCalculator::load(std::istream& istr)
{
	geometry_.load(istr);
	loads_.load(istr);
	working_conditions_factors_.load(istr);
	composite_section_.load(istr);
	studs_on_beam_.load(istr);
}

void CompositeBeamCalculator::calculate()
{
	calculate_composite_beam();
	calculate_studs();
}
//---------------------------------------------------------------------------
//Расчёт композитной балки
//---------------------------------------------------------------------------
void CompositeBeamCalculator::calculate_composite_beam()
{

//расчёт эффективной ширины плиты и подготовка композитного сечения
	double h_f = composite_section_.get_concrete_part().get_h_f();
	double b_uf = composite_section_.get_steel_part().get_section().get_b_uf();
	double b_sl = geometry_.get_effective_width(h_f, b_uf);
	composite_section_.set_b_sl(b_sl);
//полная инициализация нагрузок
	double SW_steel_beam = composite_section_.get_steel_part().get_section().get_weight();
	double SW_corrugated_sheets = 0.;
	if(composite_section_.get_concrete_part().get_slab_type_enum() != SlabType::FLAT)
	{
		String name = composite_section_.get_concrete_part().get_slab_type();
		CorrugatedSheet corrugated_sheet = CorrugatedSheetsData::get_corrugated_sheet(name);
		SW_corrugated_sheets = corrugated_sheet.get_weight()* constants::grav_accelerate;
	}
	double SW_concrete = composite_section_.get_concrete_part().get_SW_concrete();
	double B = geometry_.get_trib_width();
	loads_.set_data(SW_steel_beam, SW_corrugated_sheets, SW_concrete, B);
//подготовка калькулятора внутренних усилий
	SupportsNumber tmp_sup_num = geometry_.get_temporary_supports_number();
	double L = geometry_.get_span();
	InternalForcesCalculator intr_frcs_calculator{tmp_sup_num, L, loads_ };
//подготовка сечений для расчёта
	composite_beam_.set_composite_section(composite_section_);
	composite_beam_.set_intr_frcs_calculator(intr_frcs_calculator);
	composite_beam_.set_working_conditions_factors(working_conditions_factors_);
	composite_beam_.initialize_section_list(L, tmp_sup_num, max_elem_length_) ;
//расчёт сечений
	composite_beam_.calculate();


}
//---------------------------------------------------------------------------
//Расчёт гибких упоров композитной балки
//---------------------------------------------------------------------------
void CompositeBeamCalculator::calculate_studs()
{
	//расчёт эффективной ширины плиты и подготовка композитного сечения
	double h_f = composite_section_.get_concrete_part().get_h_f();
	double b_uf = composite_section_.get_steel_part().get_section().get_b_uf();
	double b_sl = geometry_.get_effective_width(h_f, b_uf);
	CompositeSectionGeometry composite_section = composite_section_;
	composite_section_.set_b_sl(b_sl);
	composite_section.set_phi_b_cr(0);
	//подготовка калькулятора внутренних усилий
	SupportsNumber tmp_sup_num = geometry_.get_temporary_supports_number();
	double L = geometry_.get_span();
	InternalForcesCalculator intr_frcs_calculator{tmp_sup_num, L, loads_ };
//подготовка упоров для расчёта
	studs_on_beam_.set_intr_frcs_calculator(intr_frcs_calculator);
	studs_on_beam_.set_composite_section(composite_section);
//расчёт упоров
	studs_on_beam_.set_studs(L);
	studs_on_beam_.calculate_S();
	studs_on_beam_.calculate_ratios();

}












