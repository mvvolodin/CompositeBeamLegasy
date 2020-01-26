//---------------------------------------------------------------------------

#ifndef LoadsUnitH
#define LoadsUnitH
//---------------------------------------------------------------------------
#include <cmath>
#include "Units.h"

enum ProppingSupports{
	NONE,
	ONE,
	TWO,
	THREE
};

class TLoads {
private:
	double SW_=0.0;
	double DL_I_=0.0;
	double DL_II_=0.0;
	double LL_=0.0;
	double gamma_f_st_SW_=0.0;
	double gamma_f_DL_I_=0.0;
	double gamma_f_DL_II_=0.0;
	double gamma_f_LL_=0.0;

public:
	inline double get_self_weight(LoadUnit load_unit=LoadUnit::N, LengthUnit length_unit=LengthUnit::mm) const {return SW_/static_cast<int>(load_unit)*static_cast<int>(length_unit);}
	inline double get_dead_load_first_stage(LoadUnit load_unit=LoadUnit::N, LengthUnit length_unit=LengthUnit::mm) const {return DL_I_/static_cast<int>(load_unit)*std::pow(static_cast<int>(length_unit),2);}
	inline double get_dead_load_second_stage(LoadUnit load_unit=LoadUnit::N, LengthUnit length_unit=LengthUnit::mm) const {return DL_II_/static_cast<int>(load_unit)*std::pow(static_cast<int>(length_unit),2);}
	inline double get_live_load(LoadUnit load_unit=LoadUnit::N, LengthUnit length_unit=LengthUnit::mm) const{return LL_/static_cast<int>(load_unit)*std::pow(static_cast<int>(length_unit),2);};
	inline double get_gamma_f_st_SW() const {return gamma_f_st_SW_;};
	inline double get_gamma_f_DL_I() const {return gamma_f_DL_I_;};
	inline double get_gamma_f_DL_II(){return gamma_f_DL_II_;};
	inline double get_gamma_f_LL()const {return gamma_f_LL_;};

public:
  	TLoads();
	TLoads(double SW, double DL_I, double DL_II, double LL,
		double gamma_f_SW, double gamma_f_DL_I, double gamma_f_DL_II, double gamma_f_LL);
};
#endif


