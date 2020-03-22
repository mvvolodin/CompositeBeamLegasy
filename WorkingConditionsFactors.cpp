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
void WorkingConditionsFactors::save_working_conditions_factors(std::ostream& ostr)const
{
	ostr.write((char*)&gamma_bi_ ,sizeof(gamma_bi_));
	ostr.write((char*)&gamma_si_ ,sizeof(gamma_si_));
	ostr.write((char*)&gamma_c_ ,sizeof(gamma_c_));
}
void WorkingConditionsFactors::load_working_conditions_factors(std::istream& istr)
{
	istr.read((char*)&gamma_bi_ ,sizeof(gamma_bi_));
	istr.read((char*)&gamma_si_ ,sizeof(gamma_si_));
	istr.read((char*)&gamma_c_ ,sizeof(gamma_c_));
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
