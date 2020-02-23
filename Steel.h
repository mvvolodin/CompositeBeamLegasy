// ---------------------------------------------------------------------------
#ifndef SteelH
#define SteelH
// ---------------------------------------------------------------------------

#include "Units.h"
#include <System.hpp>

class Steel{

public:

	Steel();
	Steel(String steel_grade, double E, double G, double nu,
			  double gamma_m,double R_yn,double R_un);
	String get_steel_grade () const {return steel_grade_;}
	double get_R_y () const {return R_y_;}
	double get_R_u() const {return R_u_;}
	double get_E_s() const {return E_s_;}
	double get_G_s() const {return G_s_;}
	double get_nu() const {return nu_;}
	double get_gamma_m () const {return gamma_m_;}

private:
	String steel_grade_= "";
	double E_s_ = 0.;
	double G_s_ = 0.;
	double nu_ = 0.;
	double R_y_ = 0.;
	double R_u_ = 0.;
	double gamma_m_ = 0.;
};
//----

#endif
