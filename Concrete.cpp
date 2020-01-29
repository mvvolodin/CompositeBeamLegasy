//---------------------------------------------------------------------------

#pragma hdrstop

#include "Concrete.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
std::vector <ConcreteBasic> concrete_basic
{
	{"B10", 19000, 7.5, 0.85},   //Марка, E_b, R_b, R-bt
	{"B12.5", 21500, 9.5, 1},
	{"B15", 24000, 11, 1.1},
	{"B20", 27500, 15, 1.35},
	{"B25", 30000, 18.5, 1.55},
	{"B30", 32500, 22, 1.75},
	{"B35", 34500, 25.5, 1.95},
	{"B40", 36000, 29, 2.1},
	{"B45", 37000, 32, 2.25},
	{"B50", 38000, 36, 2.45},
	{"B55", 39000, 36, 2.6},
	{"B60", 39500, 39.5, 2.75},

};

ConcreteBasic::ConcreteBasic()
{
}
ConcreteBasic::ConcreteBasic(String grade, double E_b, double R_bn, double R_btn)
	:grade_(grade),E_b_(E_b),R_bn_(R_bn),R_btn_(R_btn){}
Concrete::Concrete()
	:ConcreteBasic(),gamma_b_(0.0),epsilon_b_lim_(0.0){}
Concrete::Concrete(ConcreteBasic concrete_basic, double gamma_b, double gamma_bt, double epsilon_b_lim)
	:ConcreteBasic(concrete_basic),gamma_b_(gamma_b),gamma_bt_(gamma_bt),epsilon_b_lim_(epsilon_b_lim){}




