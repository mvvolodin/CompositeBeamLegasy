// ---------------------------------------------------------------------------
#ifndef SteelH
#define SteelH
// ---------------------------------------------------------------------------

#include "Units.h"
#include <System.hpp>

class Steel{

public:

	Steel();
	Steel(String steel_grade, double E_st, double G_st, double nu_st,
			  double gamma_m,double R_yn,double R_un);
	void set_default_values();
	String get_steel_grade () const {return steel_grade_;}
	double get_R_y() const {return R_yn_ / gamma_m_;}
	double get_R_yn() const {return R_yn_;}
	double get_R_un() const {return R_un_;}
	double get_E_st() const {return E_st_;}
	double get_G_st() const {return G_st_;}
	double get_nu_st() const {return nu_st_;}
	double get_gamma_m () const {return gamma_m_;}

private:
	String steel_grade_= "";
	double E_st_ = 0.;
	double G_st_ = 0.;
	double nu_st_ = 0.;
	double R_yn_ = 0.;
	double R_un_ = 0.;
	double gamma_m_ = 0.;
};
//----

#endif
