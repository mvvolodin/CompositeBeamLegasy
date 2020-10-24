//---------------------------------------------------------------------------

#ifndef uGeneralSteelSectionH
#define uGeneralSteelSectionH

#include "uFrmLogger.h"
#include <memory>

class GeneralSteelSection{
public:
	GeneralSteelSection();
	virtual ~ GeneralSteelSection();
	virtual double b_f1() const = 0;
	virtual double t_f1() const = 0;
	virtual double b_f2() const = 0;
	virtual double t_f2() const = 0;
	virtual double h_w() const = 0;
	virtual double t_w() const = 0;
	virtual double h_st() const = 0;

	virtual double Z_f2_st() const = 0;
    virtual double Z_f1_st() const = 0;
	virtual double C_st() const = 0;
	virtual double A_st() const = 0;
	virtual double A_f2_st() const = 0;
	virtual double A_f1_st() const = 0;
	virtual double I_st() const = 0;
	virtual double W_f2_st() const = 0;
	virtual double W_f1_st() const = 0;
	virtual double smaller_fl_to_larger_fl_ratio()const = 0;
	virtual double SW()const = 0;

	virtual void print_data_to_logger(std::unique_ptr<TFormLogger> const & log)const = 0;

};
//---------------------------------------------------------------------------
#endif
