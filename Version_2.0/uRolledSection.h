//---------------------------------------------------------------------------

#ifndef uRolledSectionH
#define uRolledSectionH

#include "uGeneralSteelSection.h"
#include <string>

class RolledSection:public GeneralSteelSection{
public:
	RolledSection(std::wstring const & prof_num,
				  double const  b_f1, double const  t_f1,
				  double const  b_f2, double const  t_f2,
				  double const  h_w, double const  t_w,
				  double const  C, double const  A, double const I);
	~RolledSection();
	double b_f1()const override;
	double t_f1()const override;
	double b_f2()const override;
	double t_f2()const override;
	double h_w()const override;
	double t_w()const override;
	double h_st()const override;

	double Z_f2_st() const override;
	double C_st()const override;
	double A_st()const override;
	double I_st()const override;

	void print_data_to_logger(TFormLogger* log)const override;

private:
	std::wstring const prof_num_;
	double const b_f1_;
	double const t_f1_;
	double const  b_f2_;
	double const t_f2_;
	double const h_w_;
	double const t_w_;
	double const C_;
	double const A_;
	double const I_;
};
//---------------------------------------------------------------------------
#endif
