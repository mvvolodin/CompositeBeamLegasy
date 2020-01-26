//---------------------------------------------------------------------------

#pragma hdrstop

#include "Steel.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
Steel::Steel(){}
Steel::	Steel(String steel_grade, double E, double G, double nu,
			  double gamma_m,double R_yn,double R_un):
			  steel_grade_(steel_grade),
				R_y_(R_yn),
				R_u_(R_un),
				E_s_(E),
				G_s_(G),
				nu_(nu),
				gamma_m_(gamma_m){}





