//---------------------------------------------------------------------------

#pragma hdrstop

#include "uConcreteSP35.h"
#include <sstream>
#include "uConcreteDataSP35.h"
#include "uUnits.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

ConcreteSP35::ConcreteSP35(unsigned int index, double eps_b_lim,
	double c_n, double dens, double mater_coeff, double mater_coeff_tens):
		eps_b_lim_(eps_b_lim), c_n_(c_n), dens_(dens / units::mm3),
		mater_coeff_(mater_coeff), mater_coeff_tens_(mater_coeff_tens)
{
	std::istringstream iss {ConcreteDataSP35::description(index)};

	iss >> grade_ >> E_b_ >> R_b_ >> R_bt_ >> c_n_;
}
void ConcreteSP35::print(TWord_Automation & report)const
{
	using namespace units;

	report.PasteTextPattern(grade_.c_str(), "%conc_grade%");
	report.PasteTextPattern(double_to_str(R_b_), "%R_b%");
	report.PasteTextPattern(double_to_str(R_bt_), "%R_bt%");
	report.PasteTextPattern(double_to_str(dens_ / m3, 0), "%density%");
	report.PasteTextPattern(double_to_str(c_n_, 6), "%c_n%");
	report.PasteTextPattern(double_to_str(E_b_, 0), "%E_b%");
	report.PasteTextPattern(double_to_str(mater_coeff_), "%gamma_b%");
	report.PasteTextPattern(double_to_str(mater_coeff_tens_), "%gamma_bt%");
	report.PasteTextPattern(double_to_str(eps_b_lim_, 4), "%epsilon_b_lim%");
}
