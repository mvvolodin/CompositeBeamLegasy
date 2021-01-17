//---------------------------------------------------------------------------

#ifndef uConcreteSP266H
#define uConcreteSP266H
#include "uWord_Automation.h"

class ConcreteSP266{
public:
	ConcreteSP266() = default;
	ConcreteSP266(unsigned int index, double eps_b_lim, double phi_b_cr,
		double dens, double mater_coeff, double mater_coeff_tens);

	std::string grade() const {return grade_;}
	double E_b() const {return E_b_;}
	double R_bn() const {return R_bn_;}
	double R_btn() const {return R_btn_;}
	double eps_b_lim() const {return eps_b_lim_;}
	double phi_b_cr() const {return phi_b_cr_;}
	double dens() const {return dens_;}
	double mater_coeff() const {return mater_coeff_;}
	double mater_coeff_tens() const {return mater_coeff_tens_;}
	double E_b_tau() const {return E_b_ / (1 + phi_b_cr_);}
	double R_b() const {return R_bn_ / mater_coeff_;}
	double R_bt() const {return R_btn_ / mater_coeff_tens_;}
	double E_b_shr() const {return 0.5 * E_b_ ;}

	void print(TWord_Automation & report)const;

private:
	std::string grade_;
	double E_b_;
	double R_bn_;
	double R_btn_;
	double eps_b_lim_;
	double phi_b_cr_;
	double dens_;
	double mater_coeff_;
	double mater_coeff_tens_;
};
//---------------------------------------------------------------------------
#endif
