//---------------------------------------------------------------------------

#ifndef uGeneralConcreteSectionH
#define uGeneralConcreteSectionH

#include "uRebar.h"


class GeneralConcreteSection{
public:
	GeneralConcreteSection(const double h_f,
						   const Rebar& rebar,
						   const double b,
						   const double a_u,
						   const double a_l,
						   const double L,
						   const double B_l,
						   const double B_r,
						   const double b_uf,
						   const bool end_beam);
	virtual ~ GeneralConcreteSection();
	double h_f() const; // расчётная толщина железобетонной плиты
	double b_sl() const; // расчётная ширина бетона
	Rebar rebar()const;
	double a_u() const;// расстояние от верхней грани расчётной железобетонной плиты до центр арматуры
	double a_l() const;// расстояние от нижней грани расчётной железобетонной плиты до центра арматуры
	double num_rebar_rows() const;
	double A_b() const;// площадь бетона
	double I_b() const;// момент инерции бетона

	virtual double h() const = 0; //высота железобетонной плиты
	virtual double h_n() const = 0; // расстояние от наружней грани верхней полки двутавра до внутренней грани расчётной железобетонной плиты
	virtual double C_b() const = 0; // центр тяжести бетона

protected:
	const double h_f_;

private:
	const double b_sl_;
	const Rebar rebar_;
	const double b_;
	const double a_u_;
	const double a_l_;
	double calc_b_sl(const double L, const double B_l, const double B_r,
					 const double h_f, const double b_uf, const bool end_beam) const;
	double calc_b(const double h_f, const double a,  const double B, const double l)const;
	double calc_b_c(const double h_f, const double a,  const double C, const double l)const;
};




//---------------------------------------------------------------------------
#endif
