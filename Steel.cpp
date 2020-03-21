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
void Steel::set_default_values()
{
	steel_grade_= L"Ñ345";
	E_st_ = 206000.;
	G_st_ = 79200.;
	nu_st_ = 0.3;
	R_yn_ = 305.;
	R_un_ = 460.;
	gamma_m_ = 1.025;

}





