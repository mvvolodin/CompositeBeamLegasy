//---------------------------------------------------------------------------

#ifndef uRolledSectionH
#define uRolledSectionH

#include "uIISection.h"

class RolledSection:public IISection{
public:
	RolledSection(double b_f1, double t_f1,
				  double b_f2, double t_f2,
				  double h_w, double t_w,
				  double A, double I);
	double b_f1()override;
	double t_f1()override;
	double b_f2()override;
	double t_f2()override;
	double h_w()override;
	double t_w()override;

    double centroid() override;
	double area() override;
	double inertia() override;

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
