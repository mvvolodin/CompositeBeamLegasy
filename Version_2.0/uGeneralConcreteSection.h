//---------------------------------------------------------------------------

#ifndef uGeneralConcreteSectionH
#define uGeneralConcreteSectionH

#include <string>
#include "uRebar.h"
#include "uWord_Automation.h"

class GeneralConcreteSection{
public:
	GeneralConcreteSection(double const h_f,
						   double const L,
						   double const B_l,
						   double const B_r,
						   double const b_uf,
						   bool const is_end_beam,
						   Rebars const & rebars);
	virtual ~ GeneralConcreteSection();
	double h_f() const; // расчётная толщина железобетонной плиты
	double b_sl() const; // расчётная ширина бетона
	Rebars rebars()const;
	double A_b() const;// площадь бетона
	double I_b() const;// момент инерции бетона

	virtual std::u16string slab_type()const = 0;//название плиты
	virtual double h() const = 0; //высота железобетонной плиты
	virtual double h_n() const = 0; // расстояние от наружней грани верхней полки двутавра до внутренней грани расчётной железобетонной плиты
	virtual double C_b() const = 0; // центр тяжести бетона
	virtual double SW(double dens) const = 0;

	void print_data_to_report(TWord_Automation & report)const;

protected:
	const double h_f_;

private:
	const double b_sl_;
	const Rebars rebars_;
	double calc_b_sl(const double L, const double B_l, const double B_r,
					 const double h_f, const double b_uf, const bool end_beam) const;
	double calc_b(const double h_f, const double a,  const double B, const double l)const;
	double calc_b_c(const double h_f, const double a,  const double C, const double l)const;
};




//---------------------------------------------------------------------------
#endif
