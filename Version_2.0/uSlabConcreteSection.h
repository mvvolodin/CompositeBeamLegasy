//---------------------------------------------------------------------------

#ifndef uSlabConcreteSectionH
#define uSlabConcreteSectionH

#include "uGeneralConcreteSection.h"
#include "uRebar.h"

class SlabConcreteSection: public GeneralConcreteSection{
public:
	SlabConcreteSection(double h_f,
						double h_n,
                        double b_sl,
						Rebar& rebar,
						double b,
						double a_u,
						double a_l);
	double h_f() const override; // расчётная толщина железобетонной плиты
	double h_n() const override; // расстояние от наружней грани верхней полки двутавра до внутренней грани расчётной железобетонной плиты
	double h() const override;
	double b_sl() const override; // расчётная ширина бетона
	const Rebar& rebar()const override;
	double a_u() const override;// расстояние от верхней грани расчётной железобетонной плиты до центр арматуры
	double a_l() const override;// расстояние от нижней грани расчётной железобетонной плиты до центра арматуры
	double C_b() const override; // центр тяжести бетона
	double A_b() const override;// площадь бетона
	double I_b() const override;// момент инерции бетона

private:
	const double h_f_;
	const double h_n_;
	const double b_sl_;

	const Rebar rebar_;
	const double b_;
	const double a_u_;
	const double a_l_;

};
//---------------------------------------------------------------------------
#endif
