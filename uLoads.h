//---------------------------------------------------------------------------

#ifndef uLoadsH
#define uLoadsH
//---------------------------------------------------------------------------
#include <cmath>
#include <ostream>
#include <istream>
#include <cassert>
#include "Units.h"
//-----------------------------------------------------------------------------
// ласс предоставл€ющий значени€ нагрузок от комбинаций загружений
//ѕеред использованием необходимо вызвать метод
// set_data() инициализирующий пол€
//	SW_steel_beam_;
//	SW_corrugated_sheets_;
//	SW_concrete_ ;
//	b_ ;
// и устанавливающий флаг fully initialized в true
//-----------------------------------------------------------------------------
class TLoads {
public:
	TLoads();
	TLoads(double SW, double SW_sheets, double DL_I, double DL_II, double LL,
		double gamma_f_SW, double gamma_f_DL_I, double gamma_f_DL_II, double gamma_f_LL);
	void set_default_values();
	void set_data(double SW_steel_beam, double SW_corrugated_sheets, double SW_concrete, double B);
	void calculate_loads(double SW_concrete);
	void save(std::ostream& ostr) const;
	void load(std::istream& istr);
	bool get_status()const{return fully_initialized_;}

	double Ia_design_LCC();
	double Ib_design_LCC();
	double II_design_LCC();
	double total_design_LCC();

	double get_self_weight(LoadUnit load_unit=LoadUnit::N, LengthUnit length_unit=LengthUnit::mm) const
		{return SW_steel_beam_/static_cast<int>(load_unit)*static_cast<int>(length_unit);}
	double get_self_weight_sheets(LoadUnit load_unit=LoadUnit::N, LengthUnit length_unit=LengthUnit::mm) const
		 {return SW_corrugated_sheets_/static_cast<int>(load_unit)*std::pow(static_cast<int>(length_unit),2);}
	double get_dead_load_first_stage(LoadUnit load_unit=LoadUnit::N, LengthUnit length_unit=LengthUnit::mm) const
		{return DL_I_/static_cast<int>(load_unit)*std::pow(static_cast<int>(length_unit),2);}
	double get_dead_load_second_stage(LoadUnit load_unit=LoadUnit::N, LengthUnit length_unit=LengthUnit::mm) const
		{return DL_II_/static_cast<int>(load_unit)*std::pow(static_cast<int>(length_unit),2);}
	double get_live_load(LoadUnit load_unit=LoadUnit::N, LengthUnit length_unit=LengthUnit::mm) const
		{return LL_/static_cast<int>(load_unit)*std::pow(static_cast<int>(length_unit),2);}
	double get_gamma_f_st_SW() const {return gamma_f_st_SW_;}
	double get_gamma_f_concrete_SW()const {return gamma_f_concrete_SW_;}
	double get_gamma_f_DL_I() const {return gamma_f_DL_I_;}
	double get_gamma_f_DL_II(){return gamma_f_DL_II_;}
	double get_gamma_f_LL()const {return gamma_f_LL_;}

private:
	double SW_steel_beam_ = 0.;
	double SW_corrugated_sheets_ = 0.;
    double SW_concrete_ = 0.;
	double DL_I_ = 0.;
	double DL_II_ = 0.;
	double LL_ = 0.;
	double gamma_f_st_SW_ = 0.;
	double gamma_f_concrete_SW_ = 0;
	double gamma_f_DL_I_ = 0.;
	double gamma_f_DL_II_ = 0.;
	double gamma_f_LL_ = 0.;

	double B_ = 0.;//грузова€ площадь

	bool fully_initialized_ = false;
};
#endif


