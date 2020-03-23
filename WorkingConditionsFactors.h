//---------------------------------------------------------------------------

#ifndef WorkingConditionsFactorsH
#define WorkingConditionsFactorsH
#include <ostream>
#include <istream>
//---------------------------------------------------------------------------
class WorkingConditionsFactors{
private:
	double gamma_bi_= 0.;
	double gamma_si_ = 0.;
	double gamma_c_  = 0.;
public:
	WorkingConditionsFactors();
	WorkingConditionsFactors(double gamma_bi, double gamma_si, double gamma_c);
	void save(std::ostream& ostr)const;
	void load(std::istream& istr);
	void set_default_values();
	double get_gamma_bi()const{return gamma_bi_;}
	double get_gamma_si()const{return gamma_si_;}
	double get_gamma_c()const{return gamma_c_;}
};

#endif
