//---------------------------------------------------------------------------

#pragma hdrstop

#include "WorkingConditionsFactors.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

WorkingConditionsFactors::WorkingConditionsFactors()
	:gamma_bi_(0.0),gamma_si_(0.0),gamma_c_(0.0)
	{}
WorkingConditionsFactors::WorkingConditionsFactors(double gamma_bi, double gamma_si, double gamma_c)
	:gamma_bi_(gamma_bi),gamma_si_(gamma_si),gamma_c_(gamma_c)
	{}
