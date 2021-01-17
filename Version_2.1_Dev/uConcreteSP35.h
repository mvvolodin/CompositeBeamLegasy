//---------------------------------------------------------------------------

#ifndef uConcreteSP35H
#define uConcreteSP35H
#include "uWord_Automation.h"

class ConcreteSP35{
public:
	ConcreteSP35() = default;
	ConcreteSP35(unsigned int index, double eps_b_lim, double phi_b_cr,
		double dens, double mater_coeff, double mater_coeff_tens);

	std::string grade() const {return grade_;}
	double E_b() const {return E_b_;}
	double R_bn() const {return R_b_  * mater_coeff_;}
	double R_btn() const {return R_bt_ * mater_coeff_tens_;}
	double eps_b_lim() const {return eps_b_lim_;}
	double eps_shr() const {return eps_shr_;}
	double c_n() const {return c_n_;}
	double dens() const {return dens_;}
	double mater_coeff() const {return mater_coeff_;}
	double mater_coeff_tens() const {return mater_coeff_tens_;}
	double R_b() const {return R_b_;}
	double R_bt() const {return R_bt_;}
	double E_b_shr() const {return 0.5 * E_b_ ;}

	void print(TWord_Automation & report)const;

private:
	std::string grade_;
	double E_b_;
	double R_b_;
	double R_bt_;
	double eps_b_lim_;
	double eps_shr_ = 0.0002;
	double c_n_;
	double dens_;
	double mater_coeff_;
	double mater_coeff_tens_;
};
//---------------------------------------------------------------------------
#endif
