//---------------------------------------------------------------------------
#ifndef uGeneralSteelSectionH
#define uGeneralSteelSectionH
//---------------------------------------------------------------------------
//#define NDEBUG
#ifndef NDEBUG
#include "uFrmLogger.h"
#endif
//---------------------------------------------------------------------------
#include <Vcl.Grids.hpp>
#include "uFrmLogger.h"
#include "uWord_Automation.h"
//---------------------------------------------------------------------------
class GeneralSteelSection{
public:
	GeneralSteelSection();
	virtual ~ GeneralSteelSection();

	virtual double upper_fl_width() const = 0;
	virtual double upper_fl_thick() const = 0;
	virtual double lower_fl_width() const = 0;
	virtual double lower_fl_thick() const = 0;
	virtual double web_height() const = 0;
	virtual double web_thick() const = 0;
	virtual double sect_height() const = 0;
	double t_max()const;

	virtual std::wstring name()const = 0;
	virtual double Z_f2_st() const = 0;
	virtual double Z_f1_st() const = 0;
	virtual double C_st() const = 0;
	virtual double area() const = 0;
	virtual double area_upper_fl() const = 0;
	virtual double area_lower_fl() const = 0;
	virtual double inertia() const = 0;
	virtual double W_f2_st() const = 0;
	virtual double W_f1_st() const = 0;
	virtual double smaller_fl_to_larger_fl_ratio()const = 0;
	virtual double SW()const = 0;

	double b_f1()const{return lower_fl_width();}
	double t_f1()const{return lower_fl_thick();}
	double b_f2()const{return upper_fl_width();}
	double t_f2()const{return upper_fl_thick();}
	double h_st() const {return web_height();}

	double A_st() const {return area();}
	double I_st() const {return inertia();}


	double b_s1() const {return lower_fl_width();}
	double t_s1() const {return lower_fl_thick();}
	double b_s2() const {return upper_fl_width();}
	double t_s2() const {return upper_fl_thick();}
	double h_s() const {return web_height();}

	double Z_s2_s() const {return Z_f2_st();}
	double Z_s1_s() const {return Z_f1_st();}
	double C_s() const {return C_st();}
	double A_s() const {return area();}
	double A_s2_s() const {return area_upper_fl();}
	double A_s1_s() const {return area_lower_fl();}
	double I_s() const {return inertia();}
	double W_s2_s() const {return W_f2_st();}
	double W_s1_s() const {return W_f1_st();}

	virtual void print_input(TWord_Automation & report)const = 0;
	virtual void print_output(TWord_Automation & report)const = 0;
	void fill_grid(TStringGrid* str_grid)const;
#ifndef NDEBUG
	virtual void print_data_to_logger(TFormLogger const & log)const = 0;
 #endif
};
//---------------------------------------------------------------------------
#endif
