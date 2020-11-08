//---------------------------------------------------------------------------
#ifndef uWorkingConditionsFactorsH
#define uWorkingConditionsFactorsH
//---------------------------------------------------------------------------
#include <ostream>
#include <istream>
#include "uWord_Automation.h"
//---------------------------------------------------------------------------
class WorkingConditionsFactors{
public:
	WorkingConditionsFactors();
	WorkingConditionsFactors(double gamma_conc, double gamma_rebar, double gamma_com_beam);

	void save(std::ostream& ostr)const;
	void load(std::istream& istr);

	void set_default_values();

	double gamma_bi()const{return gamma_conc_;}
	double gamma_si()const{return gamma_rebar_;}
	double gamma_c()const{return gamma_com_beam_;}

	double m_b()const{return gamma_conc_;}
	double m_r()const{return gamma_rebar_;}
	double m()const{return gamma_com_beam_;}

	void print_data_to_report_SP35(TWord_Automation & report)const;
private:
	double gamma_conc_= 0.;
	double gamma_rebar_ = 0.;
	double gamma_com_beam_  = 0.;
};

#endif
