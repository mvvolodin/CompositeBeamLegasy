//---------------------------------------------------------------------------

#pragma hdrstop

#include "WorkingConditionsFactors.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

WorkingConditionsFactors::WorkingConditionsFactors()
{

}
WorkingConditionsFactors::WorkingConditionsFactors(double gamma_bi, double gamma_si, double gamma_c)
	:gamma_bi_(gamma_bi),gamma_si_(gamma_si),gamma_c_(gamma_c)
{

}
//-----------------------------------------------------------------------------
//ѕрисваение данным класса значений по умолчанию
//-----------------------------------------------------------------------------
void WorkingConditionsFactors::set_default_values()
{
	gamma_bi_= 1.;
	gamma_si_ = 1.;
	gamma_c_  = 1.;
}
