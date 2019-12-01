//---------------------------------------------------------------------------

#pragma hdrstop

#include "SteelInitialDataUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

TSteelInitialData::TSteelInitialData(double R_y, double R_u, double E_s,
									 double G_s,double nu, double gamma_m)
									 :R_y(R_y),
									  R_u(R_u),
									  E_s(E_s),
									  G_s(G_s),
									  nu(nu),
									  gamma_m(gamma_m){}

