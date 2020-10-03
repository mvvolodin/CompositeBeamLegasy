//---------------------------------------------------------------------------

#ifndef uWeldedSectionH
#define uWeldedSectionH

#include "uGeneralSteelSection.h"
#include <vector>

class WeldedSection:public GeneralSteelSection{
struct Vertex{
	double X;
	double Y;
	Vertex(double X, double Y):X{X},Y{Y}{}
};
public:
	WeldedSection(double b_f1, double t_f1,
				  double b_f2, double t_f2,
				  double h_w, double t_w);

	double b_f1()const override;
	double t_f1()const override;
	double b_f2()const override;
	double t_f2()const override;
	double h_w()const override;
	double t_w()const override;
	double h_st() const override;

	double C_st() const override;
	double A_st()const override;
	double I_st() const override;

	void print_coord() override;
	void print_b_f1()override;
	void print_t_f1()override;
	void print_b_f2()override;
	void print_t_f2()override;
	void print_h_w()override;
	void print_t_w()override;
	void print_centroid() override;
	void print_area()override;
	void print_inertia()override;

private:
	std::vector<Vertex> vertexes_;

};
//---------------------------------------------------------------------------
#endif
