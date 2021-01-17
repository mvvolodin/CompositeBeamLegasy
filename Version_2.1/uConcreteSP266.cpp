//---------------------------------------------------------------------------

#pragma hdrstop

#include "uConcreteSP266.h"
#include <sstream>
#include "uConcreteDataSP266.h"
#include "uUnits.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

ConcreteSP266::ConcreteSP266(unsigned int index, double eps_b_lim,
	double phi_b_cr, double dens, double mater_coeff, double mater_coeff_tens):
		eps_b_lim_(eps_b_lim), phi_b_cr_(phi_b_cr), dens_(dens / units::mm3),
		mater_coeff_(mater_coeff), mater_coeff_tens_(mater_coeff_tens)
{
	std::istringstream iss {ConcreteDataSP266::description(index)};

	iss >> grade_ >> E_b_ >> R_bn_ >> R_btn_;
}
void ConcreteSP266::print(TWord_Automation & report)const
{
	using namespace units;

	report.PasteTextPattern(grade_.c_str(), "%conc_grade%");
	report.PasteTextPattern(double_to_str(R_bn_), "%R_bn%");
	report.PasteTextPattern(double_to_str(R_btn_), "%R_btn%");
	report.PasteTextPattern(double_to_str(dens_ / m3, 0), "%density%");
	report.PasteTextPattern(double_to_str(phi_b_cr_), "%phi_b_cr%");
	report.PasteTextPattern(double_to_str(E_b_, 0), "%E_b%");
	report.PasteTextPattern(double_to_str(mater_coeff_), "%gamma_b%");
	report.PasteTextPattern(double_to_str(mater_coeff_tens_), "%gamma_bt%");
	report.PasteTextPattern(double_to_str(eps_b_lim_, 4), "%epsilon_b_lim%");
}
