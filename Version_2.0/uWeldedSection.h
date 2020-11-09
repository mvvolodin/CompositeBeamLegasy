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
