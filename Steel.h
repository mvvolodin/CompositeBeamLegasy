// ---------------------------------------------------------------------------
#ifndef SteelH
#define SteelH
// ---------------------------------------------------------------------------

#include "SteelInitialDataUnit.h"
#include "Units.h"

class Steel{

public:

	Steel();
	Steel(TSteelInitialData steel_initial_data);
	inline double get_R_y () const {return R_y_;}
	inline double get_R_u() const {return R_u_;}
	inline double get_E_s() const {return E_s_;}
	inline double get_G_s() const {return G_s_;}
	inline double get_nu() const {return nu_;}
	inline double get_gamma_m () const {return gamma_m_;}

private:

	double R_y_;
	double R_u_;
	double E_s_;
	double G_s_;
	double nu_;
	double gamma_m_;
};
//----

#endif
