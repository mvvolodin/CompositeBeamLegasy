
    //---------------------------------------------------------------------------

    #pragma hdrstop

	#include<cmath>
	#include "ConcretePartUnit.h"
	#include "MathFunction.h"
	//---------------------------------------------------------------------------
	#pragma package(smart_init)

//---------------------------------------------------------------------------
TConcretePart::TConcretePart()
{
}
TConcretePart::TConcretePart(String slab_type, Concrete concrete, Rebar rebar)
	:slab_type_(slab_type),concrete_(concrete),rebar_(rebar)
{
}
TConcretePart::TConcretePart(Concrete concrete, Rebar rebar, double t_sl)
	:concrete_(concrete), rebar_(rebar), t_sl_(t_sl),slab_type_(L"Плоская плита")

{
}

//---------------------------------------------------------------------------
//Определение расчётного свеса плиты
//Передаваемые параметры (в порядке представленном в функции):
//  *толщина плиты,
//  *половина ширины контакта  ж.б плиты и стального пояса
//	*расстояние между осями балок
//	*пролёт балки
//---------------------------------------------------------------------------
double TConcretePart::effective_width_calc(double t_sl, double a,  double B, double l)
{
	double b=0;
	if (l>=4*B)
		b=B/2;
	else
		b=a+6*t_sl;
	return clamp(b, l/8, B/2 );
}
//---------------------------------------------------------------------------
//Определение расчётного свеса плиты в случае консоли
//Передаваемые параметры (в порядке представленном в функции):
//  *толщина плиты консоли,
//  *половина ширины контакта  ж.б плиты и стального пояса
//	*длина консольного свеса плиты
//	*пролёт балки
//---------------------------------------------------------------------------
double TConcretePart::effective_width_cantilever_calc(double t_slc, double a,  double C, double l)
{
	double bc=0;
	if (l>=12*C)
		bc=C;
	else
		bc=a+6*t_slc;
	return clamp(bc, l/12, C );
}
TFlatSlab::TFlatSlab(Concrete concrete, Rebar rebar, double t_sl)
	:TConcretePart(concrete, rebar, t_sl)
{
}
void TFlatSlab::calc_h_b()
{
	 h_b_=t_sl_;
}
void TFlatSlab::calc_C_b()
{
	 C_b_=h_b_/2.;
}

void TFlatSlab::calc_area()
{
	 A_b_=(b_l_+b_r_)*t_sl_;
}

void TFlatSlab::calc_inertia()
{
	 I_b_=(b_l_+b_r_)*std::pow(t_sl_,3)/12;
}

//---------------------------------------------------------------------------

TCorrugatedSlab::TCorrugatedSlab(String slab_type, Concrete concrete, Rebar rebar, double h_f) //h_f высота бетона над настилом
	:TConcretePart(slab_type, concrete, rebar),h_f_(h_f)
{
   corrugated_sheet_ = corrugated_sheets_map[slab_type];
}
void TCorrugatedSlab::calc_h_b()
{
	 h_b_=corrugated_sheet_.get_height()+h_f_;
}
void TCorrugatedSlab::calc_C_b()
{
	 C_b_=corrugated_sheet_.get_height()+h_f_/2.;
}

void TCorrugatedSlab::calc_area()
{
	A_b_=(b_l_+b_r_)*h_f_;
}

void TCorrugatedSlab::calc_inertia()
{
	I_b_=(b_l_+b_r_)*std::pow(h_f_,3)/12;
}

