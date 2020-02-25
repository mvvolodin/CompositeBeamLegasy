//---------------------------------------------------------------------------

#pragma hdrstop

#include "Steel.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
Steel::Steel(){}
Steel::	Steel(String steel_grade, double E_st, double G_st, double nu_st,
			  double gamma_m,double R_yn,double R_un):
			  steel_grade_(steel_grade),
				R_yn_(R_yn),
				R_un_(R_un),
				E_st_(E_st),
				G_st_(G_st),
				nu_st_(nu_st),
				gamma_m_(gamma_m){}





