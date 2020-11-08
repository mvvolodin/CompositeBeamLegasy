//---------------------------------------------------------------------------

#pragma hdrstop

#include "uWorkingConditionsFactors.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

WorkingConditionsFactors::WorkingConditionsFactors()
{

}
WorkingConditionsFactors::WorkingConditionsFactors(double gamma_conc,
												   double gamma_rebar,
												   double gamma_com_beam)
	:gamma_conc_(gamma_conc),
	 gamma_rebar_(gamma_rebar),
	 gamma_com_beam_(gamma_com_beam){}
void WorkingConditionsFactors::save(std::ostream& ostr)const
{
	ostr.write((char*)&gamma_conc_ ,sizeof(gamma_conc_));
	ostr.write((char*)&gamma_rebar_ ,sizeof(gamma_rebar_));
	ostr.write((char*)&gamma_com_beam_ ,sizeof(gamma_com_beam_));
}
void WorkingConditionsFactors::load(std::istream& istr)
{
	istr.read((char*)&gamma_conc_ ,sizeof(gamma_conc_));
	istr.read((char*)&gamma_rebar_ ,sizeof(gamma_rebar_));
	istr.read((char*)&gamma_com_beam_ ,sizeof(gamma_com_beam_));
}
//-----------------------------------------------------------------------------
//ѕрисваение данным класса значений по умолчанию
//-----------------------------------------------------------------------------
void WorkingConditionsFactors::set_default_values()
{
	gamma_conc_= 1.;
	gamma_rebar_ = 1.;
	gamma_com_beam_  = 1.;
}
void WorkingConditionsFactors::print_data_to_report_SP35(TWord_Automation & report)const
{
	report.PasteTextPattern(FloatToStrF(m_b(), ffFixed, 15, 2),"%gamma_c%");
	report.PasteTextPattern(FloatToStrF(m_r(), ffFixed, 15, 2),"%gamma_bi%");
	report.PasteTextPattern(FloatToStrF(m(), ffFixed, 15, 2),"%gamma_si%");

}
