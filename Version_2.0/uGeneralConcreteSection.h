//---------------------------------------------------------------------------

#ifndef uGeneralConcreteSectionH
#define uGeneralConcreteSectionH

#include "uRebar.h"

class GeneralConcreteSection{
public:
	virtual ~ GeneralConcreteSection();
	virtual double h_f() const  = 0; // расчётная толщина железобетонной плиты
	virtual double h_n() const = 0; // расстояние от наружней грани верхней полки двутавра до внутренней грани расчётной железобетонной плиты
	virtual double h_b() const = 0;
	virtual double b_sl() const = 0; // расчётная ширина бетона
	virtual const Rebar& rebar()const = 0;
	virtual double a_u() const = 0;// расстояние от верхней грани расчётной железобетонной плиты до центр арматуры
	virtual double a_l() const = 0;// расстояние от нижней грани расчётной железобетонной плиты до центра арматуры
	virtual double num_rebar_rows() const = 0;
	virtual double C_b() const = 0; // центр тяжести бетона
	virtual double A_b() const = 0;// площадь бетона
	virtual double I_b() const = 0;// момент инерции бетона
};




//---------------------------------------------------------------------------
#endif
