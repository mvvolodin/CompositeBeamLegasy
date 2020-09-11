//---------------------------------------------------------------------------

#ifndef uWeldedSectionH
#define uWeldedSectionH

#include "uIISection.h"
#include <vector>

class WeldedSection:public IISection{
struct Vertex{
	double X;
	double Y;
	Vertex(double X, double Y):X{X},Y{Y}{}
};
public:
	WeldedSection(double b_f1, double t_f1,
				  double b_f2, double t_f2,
				  double h_w, double t_w);

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
	void print_centroid() override;
	void print_area()override;
	void print_inertia()override;

private:
	std::vector<Vertex> vertexes_;

};
//---------------------------------------------------------------------------
#endif
