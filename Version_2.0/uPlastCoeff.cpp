//---------------------------------------------------------------------------

#pragma hdrstop

#include "uPlastCoeff.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

namespace{
	std::map<PlastCoeff const ,std::string const> const places{
		{PlastCoeff::Omega,"%omega%"},
		{PlastCoeff::Eta_uf,"%eta_uf%"},
		{PlastCoeff::Eta_lf,"%eta_lf%"},
		{PlastCoeff::Omega_3_uf,"%omega_3_uf%"},
		{PlastCoeff::Omega_3_lf,"%omega_3_lf%"},
		{PlastCoeff::Omega_4,"%omega_4%"}};
}

PlastCoeffList::PlastCoeffList(std::map<PlastCoeff const, double const> const & pl_coeff):
	pl_coeff_(pl_coeff){}

void PlastCoeffList::print(TWord_Automation & rep)const
{
	for(auto const & p:places)
		rep.PasteTextPattern("Не применяется", p.second.c_str());

	for(auto const & c:pl_coeff_){
		auto it = places.find(c.first);
		rep.PasteTextPattern(FloatToStrF(c.second, ffFixed, 15, 2), it -> second.c_str());
	}

}
