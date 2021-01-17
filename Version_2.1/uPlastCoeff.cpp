//---------------------------------------------------------------------------

#pragma hdrstop

#include <vector>
#include <string>
#include "uPlastCoeff.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

namespace{
	std::map<PlastCoeff const ,std::string const> const placeholders{
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
	std::vector<PlastCoeff> pl_coeff_excl;

	for(auto const & p:placeholders)
		if(auto const & it = pl_coeff_.find(p.first)== pl_coeff_.cend())
			pl_coeff_excl.push_back(p.first);

	for(auto const & c:pl_coeff_excl)
		rep.PasteTextPattern("Не применяется", placeholders.find(c) -> second.c_str());

	for(auto const & c:pl_coeff_){
		rep.PasteTextPattern(FloatToStrF(c.second, ffFixed, 15, 2), placeholders.find(c.first) -> second.c_str());
	}

}
