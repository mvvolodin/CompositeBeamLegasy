//---------------------------------------------------------------------------
#ifndef uWeldedSectionH
#define uWeldedSectionH
//---------------------------------------------------------------------------
//#define NDEBUG
#ifndef NDEBUG
#include "uFrmLogger.h"
#endif
//---------------------------------------------------------------------------
#include <Vcl.Graphics.hpp>
#include <vector>
#include "uGeneralSteelSection.h"
#include "uFrmLogger.h"
//---------------------------------------------------------------------------
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
	~WeldedSection();

	std::wstring name()const override;

	double upper_fl_width() const override;
	double upper_fl_thick() const override;
	double lower_fl_width() const override;
	double lower_fl_thick() const override;
	double web_height()const override;
	double web_thick()const override;
	double sect_height()const override;

	double grav_cent_upper_fl_dist() const override;
	double grav_cent_lower_fl_dist() const override;
	double grav_cent() const override;
	double area() const override;
	double area_upper_fl() const override ;
	double area_lower_fl() const override;
	double inertia() const override;
	double modulus_upper_fl() const override;
	double modulus_lower_fl() const override;
	double smaller_fl_to_larger_fl_ratio()const override;
	double SW()const override;
	void print_input(TWord_Automation & report)const override;
	void print_output(TWord_Automation & report)const override;
#ifndef NDEBUG
	void print_data_to_logger(TFormLogger const & log)const override;
#endif
	void draw(TCanvas* cnvs);
private:
	std::vector<Vertex> vertexes_;

	std::vector<TPoint> get_pnts_for_drawing();

};
//---------------------------------------------------------------------------
#endif
