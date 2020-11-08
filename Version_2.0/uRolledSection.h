//---------------------------------------------------------------------------
#ifndef uRolledSectionH
#define uRolledSectionH
//---------------------------------------------------------------------------
//#define NDEBUG
#ifndef NDEBUG
#include "uFrmLogger.h"
#endif
//---------------------------------------------------------------------------
#include "uGeneralSteelSection.h"
#include <string>
//---------------------------------------------------------------------------
class RolledSection:public GeneralSteelSection{
public:
	RolledSection(std::wstring const & prof_num,
				  double const lower_fl_width, double const  lower_fl_thick,
				  double const upper_fl_width, double const  upper_fl_thick,
				  double const h_w, double const  t_w,
				  double const C, double const  A, double const I);
	~RolledSection();

	String name()const override;

	double upper_fl_width() const override;
	double upper_fl_thick() const override;
	double lower_fl_width() const override;
	double lower_fl_thick() const override;
	double h_w()const override;
	double t_w()const override;
	double h_st()const override;

	double Z_f2_st() const override;
	double Z_f1_st()const override;
	double C_st()const override;
	double A_st()const override;
	double A_f2_st()const override;
    double A_f1_st()const override;
	double I_st()const override;
	double W_f2_st()const override;
	double W_f1_st()const override;
	double smaller_fl_to_larger_fl_ratio()const override;
	double SW()const override;
#ifndef NDEBUG
	void print_data_to_logger(TFormLogger const & log)const override;
#endif
private:
	std::wstring const prof_num_;
	double const lower_fl_width_;
	double const lower_fl_thick_;
	double const upper_fl_width_;
	double const upper_fl_thick_;
	double const h_w_;
	double const t_w_;
	double const C_;
	double const A_;
	double const I_;
};
//---------------------------------------------------------------------------
#endif
