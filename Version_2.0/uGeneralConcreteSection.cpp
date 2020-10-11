//---------------------------------------------------------------------------

#pragma hdrstop

#include "uGeneralConcreteSection.h"
#include "MathFunction.h"
#include <algorithm>
//---------------------------------------------------------------------------
#pragma package(smart_init)
GeneralConcreteSection::GeneralConcreteSection(double const h_f,
											   double const L,
											   double const B_l,
											   double const B_r,
											   double const b_uf,
											   bool const is_end_beam,
											   Rebars const & rebars):
										h_f_{h_f},
										b_sl_  {calc_b_sl(L , B_l, B_r, h_f, b_uf, is_end_beam)},
										rebars_{rebars}{}
GeneralConcreteSection::~GeneralConcreteSection()
{

}
double GeneralConcreteSection::calc_b_sl(const double L,
										 const double B_l, const double B_r,
										 const double h_f, const double b_uf,
										 const bool end_beam)const
{
	if (!end_beam)
		return 2 * std::min(calc_b(h_f,b_uf/2,B_l,L),
							calc_b(h_f,b_uf/2,B_r,L));
		return 2* std::min(calc_b_c(h_f,b_uf/2,B_l,L),
						   calc_b(h_f,b_uf/2,B_r,L));

}
//---------------------------------------------------------------------------
//Определение расчётного свеса плиты
//Передаваемые параметры (в порядке представленном в функции):
//  *толщина плиты,
//  *половина ширины контакта  ж.б плиты и стального пояса
//	*расстояние между осями балок
//	*пролёт балки
//---------------------------------------------------------------------------
double GeneralConcreteSection::calc_b(const double h_f, const double a,
								      const double B, const double l)const
{
	double b = 0;
	double t_sl = h_f;

	if (l >= 4 * B)
		b = B / 2;
	else
		b = a + 6 * t_sl;
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
double GeneralConcreteSection::calc_b_c(double h_f, double a,  double C, double l)const
{
	double bc = 0;
	double t_slc = h_f;

	if (l >= 12 * C)
		bc = C;
	else
		bc = a + 6 * t_slc;
	return clamp(bc, l/12, C );
}

double GeneralConcreteSection::h_f() const
{
	return h_f_;
}
double GeneralConcreteSection::b_sl() const
{
	return b_sl_;
}
Rebars GeneralConcreteSection::rebars()const
{
	return rebars_;
}
double GeneralConcreteSection::A_b() const
{
	return h_f_ * b_sl_ ;
}
double GeneralConcreteSection::I_b() const
{
	return h_f_ * b_sl_ * b_sl_ * b_sl_ / 12;

}

