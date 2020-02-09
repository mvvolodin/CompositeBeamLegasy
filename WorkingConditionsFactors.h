//---------------------------------------------------------------------------

#ifndef WorkingConditionsFactorsH
#define WorkingConditionsFactorsH
//---------------------------------------------------------------------------
class WorkingConditionsFactors{
private:
	double gamma_bi_{0.};
	double gamma_si_{0.};
	double gamma_c_ {0.};
public:
	WorkingConditionsFactors();
	WorkingConditionsFactors(double gamma_bi, double gamma_si, double gamma_c);
	inline double get_gamma_bi()const{return gamma_bi_;}
	inline double get_gamma_si()const{return gamma_si_;}
	inline double get_gamma_c()const{return gamma_c_;}
};

#endif
