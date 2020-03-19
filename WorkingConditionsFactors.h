//---------------------------------------------------------------------------

#ifndef WorkingConditionsFactorsH
#define WorkingConditionsFactorsH
#include <ostream>
//---------------------------------------------------------------------------
class WorkingConditionsFactors{
private:
	double gamma_bi_{0.};
	double gamma_si_{0.};
	double gamma_c_ {0.};
public:
	WorkingConditionsFactors();
	WorkingConditionsFactors(double gamma_bi, double gamma_si, double gamma_c);
	void save_working_conditions(std::ostream& ostr)const;
	double get_gamma_bi()const{return gamma_bi_;}
	double get_gamma_si()const{return gamma_si_;}
	double get_gamma_c()const{return gamma_c_;}
};

#endif
