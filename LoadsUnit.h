//---------------------------------------------------------------------------

#ifndef LoadsUnitH
#define LoadsUnitH
//---------------------------------------------------------------------------
//#include "LoadsInitialDataUnit.h"
enum ProppingSupports{
	NONE,
	ONE,
	TWO,
	THREE
};

class TLoads {
private:
	ProppingSupports propping_supports_;
	double SW_;
	double DL_I_;
	double DL_II_;
	double LL_;
	double gamma_f_SW_;
	double gamma_f_DL_I_;
	double gamma_f_DL_II_;
	double gamma_f_LL_;

public:
	inline double get_self_weight() const {return 1000*SW_;}
	inline double get_dead_load_first_stage() const {return 1000*DL_I_;}
	inline double get_dead_load_second_stage() const {return 1000*DL_II_;}
	inline double get_live_load() const{return 1000*LL_;};
	inline double get_gamma_f_SW() const {return gamma_f_SW_;};
	inline double get_gamma_f_DL_I() const {return gamma_f_DL_I_;};
	inline double get_gamma_f_DL_II(){return gamma_f_DL_II_;};
	inline double get_gamma_f_LL()const {return gamma_f_LL_;};

public:
  	TLoads();
	TLoads(double SW, double DL_I, double DL_II, double LL,
		double gamma_f_SW, double gamma_f_DL_I, double gamma_f_DL_II, double gamma_f_LL);
};
#endif


