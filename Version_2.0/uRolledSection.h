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

	 RolledSection(int rolled_sect_type, int rolled_sect_num);

	~RolledSection();

	std::wstring name()const override;

	double upper_fl_width() const override;
	double upper_fl_thick() const override;
	double lower_fl_width() const override;
	double lower_fl_thick() const override;
	double web_height()const override;
	double web_thick()const override;
	double sect_height()const override;

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
	std::wstring prof_num_;
	double lower_fl_width_;
	double lower_fl_thick_;
	double upper_fl_width_;
	double upper_fl_thick_;
	double h_w_;
	double t_w_;
	double C_;
	double A_;
	double I_;
};
//---------------------------------------------------------------------------
#endif
