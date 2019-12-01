//---------------------------------------------------------------------------

#pragma hdrstop

#include "Concrete.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
ConcreteBasic::ConcreteBasic()
	:grade_(""),E_b_(0.0),R_b_(0.0),R_bt_(0.0){}
ConcreteBasic::ConcreteBasic(String grade, double E_b, double R_b, double R_bt)
	:grade_(grade),E_b_(E_b),R_b_(R_b),R_bt_(R_bt){}
Concrete::Concrete()
	:ConcreteBasic(),gamma_b_(0.0),epsilon_b_lim_(0.0){}
Concrete::Concrete(ConcreteBasic concrete_basic, double gamma_b, double epsilon_b_lim)
	:ConcreteBasic(concrete_basic),gamma_b_(gamma_b),epsilon_b_lim_(epsilon_b_lim){}




