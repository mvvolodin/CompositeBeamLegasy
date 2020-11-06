//---------------------------------------------------------------------------

#ifndef uWeldedSectionH
#define uWeldedSectionH

#include <Vcl.Graphics.hpp>
#include <vector>

#include "uGeneralSteelSection.h"
#include "uFrmLogger.h"

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

    String name()const override;

	double b_f1()const override;
	double t_f1()const override;
	double b_f2()const override;
	double t_f2()const override;
	double h_w()const override;
	double t_w()const override;
	double h_st()const override;

	double Z_f2_st() const override;
    double Z_f1_st() const override;
	double C_st() const override;
	double A_st()const override;
	double A_f2_st() const override;
    double A_f1_st() const override;
	double I_st() const override;
	double W_f2_st() const override;
	double W_f1_st() const override;
	double smaller_fl_to_larger_fl_ratio()const override;
	double SW()const override;

	void print_data_to_logger(TFormLogger const & log)const override;
	void draw(TCanvas* cnvs);
private:
	std::vector<Vertex> vertexes_;

	std::vector<TPoint> get_pnts_for_drawing();

};
//---------------------------------------------------------------------------
#endif
