//---------------------------------------------------------------------------

#ifndef SteelInitialDataUnitH
#define SteelInitialDataUnitH

#include "Steel_param_ARSS.h"
#include "String_doubleUnit.h"

struct TSteelInitialData{

	double R_y;
	double R_u;
	double E_s;
	double G_s;
	double nu;
	double gamma_m;
    TSteelInitialData(){}
	TSteelInitialData(double R_y, double R_u, double E_s, double G_s,
		double nu, double gamma_m);
};
//---------------------------------------------------------------------------
#endif
