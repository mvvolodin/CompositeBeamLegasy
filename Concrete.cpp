//---------------------------------------------------------------------------

#pragma hdrstop

#include "Concrete.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
ConcreteBasic::ConcreteBasic()
	:grade_(""),E_b_(0.0),R_bn_(0.0),R_btn_(0.0){}
ConcreteBasic::ConcreteBasic(String grade, double E_b, double R_bn, double R_btn)
	:grade_(grade),E_b_(E_b),R_bn_(R_bn),R_btn_(R_btn){}
Concrete::Concrete()
	:ConcreteBasic(),gamma_b_(0.0),epsilon_b_lim_(0.0){}
Concrete::Concrete(ConcreteBasic concrete_basic, double gamma_b, double gamma_bt, double epsilon_b_lim)
	:ConcreteBasic(concrete_basic),gamma_b_(gamma_b),gamma_bt_(gamma_bt),epsilon_b_lim_(epsilon_b_lim){}




