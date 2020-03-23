//---------------------------------------------------------------------------

#ifndef LoadsUnitH
#define LoadsUnitH
//---------------------------------------------------------------------------
#include <cmath>
#include <ostream>
#include <istream>
#include "Units.h"

class TLoads {
public:
  	TLoads();
	TLoads(double SW, double SW_sheets, double DL_I, double DL_II, double LL,
		double gamma_f_SW, double gamma_f_DL_I, double gamma_f_DL_II, double gamma_f_LL);
	void TLoads::set_default_values();
	void save(std::ostream& ostr) const;
	void load(std::istream& istr);
	double get_self_weight(LoadUnit load_unit=LoadUnit::N, LengthUnit length_unit=LengthUnit::mm) const
		{return SW_/static_cast<int>(load_unit)*static_cast<int>(length_unit);}
	double get_self_weight_sheets(LoadUnit load_unit=LoadUnit::N, LengthUnit length_unit=LengthUnit::mm) const
		 {return SW_sheets_/static_cast<int>(load_unit)*std::pow(static_cast<int>(length_unit),2);}
	double get_dead_load_first_stage(LoadUnit load_unit=LoadUnit::N, LengthUnit length_unit=LengthUnit::mm) const
		{return DL_I_/static_cast<int>(load_unit)*std::pow(static_cast<int>(length_unit),2);}
	double get_dead_load_second_stage(LoadUnit load_unit=LoadUnit::N, LengthUnit length_unit=LengthUnit::mm) const
		{return DL_II_/static_cast<int>(load_unit)*std::pow(static_cast<int>(length_unit),2);}
	double get_live_load(LoadUnit load_unit=LoadUnit::N, LengthUnit length_unit=LengthUnit::mm) const
		{return LL_/static_cast<int>(load_unit)*std::pow(static_cast<int>(length_unit),2);};
	double get_gamma_f_st_SW() const {return gamma_f_st_SW_;};
	double get_gamma_f_DL_I() const {return gamma_f_DL_I_;};
	double get_gamma_f_DL_II(){return gamma_f_DL_II_;};
	double get_gamma_f_LL()const {return gamma_f_LL_;};

private:
	double SW_ = 0.;
	double SW_sheets_ = 0.;
	double DL_I_ = 0.;
	double DL_II_ = 0.;
	double LL_ = 0.;
	double gamma_f_st_SW_ = 0.;
	double gamma_f_DL_I_ = 0.;
	double gamma_f_DL_II_ = 0.;
	double gamma_f_LL_ = 0.;

};
#endif


