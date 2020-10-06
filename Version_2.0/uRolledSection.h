//---------------------------------------------------------------------------

#ifndef uRolledSectionH
#define uRolledSectionH

#include "uGeneralSteelSection.h"

class RolledSection:public GeneralSteelSection{
public:
	RolledSection(double b_f1, double t_f1,
				  double b_f2, double t_f2,
				  double h_w, double t_w,
				  double A, double I);
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

	void print_coord() override;
	void print_b_f1()override;
	void print_t_f1()override;
	void print_b_f2()override;
	void print_t_f2()override;
	void print_h_w()override;
	void print_t_w()override;
	void print_centroid()override;
	void print_area()override;
	void print_inertia()override;
private:
	double b_f1_;
	double t_f1_;
	double b_f2_;
	double t_f2_;
	double h_w_;
	double t_w_;
	double C_;
	double A_;
	double I_;
};
//---------------------------------------------------------------------------
#endif
