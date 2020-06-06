//---------------------------------------------------------------------------

#pragma hdrstop

#include "uGeometry.h"
#include <algorithm>
#include "MathFunction.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

Geometry::Geometry(){}

Geometry::Geometry(bool end_beam, double L, double B_l, double B_r, SupportsNumber temp_supports_num):
	 end_beam_					(end_beam),
	 L_							(L),
	 B_l_						(B_l),
	 B_r_						(B_r),
	 temp_supports_num_	(temp_supports_num)
{
}
void Geometry::set_default_values()
{
	end_beam_ = false;
	L_ = 18000;
	B_l_ = 6000;
	B_r_ = 6000;
	temp_supports_num_ = SupportsNumber::ZERO;
}
//---------------------------------------------------------------------------
// Сохранение данных в бинарный файл
//---------------------------------------------------------------------------
void Geometry::save(ostream& ostr)const
{
	ostr.write((char*)&end_beam_,sizeof(end_beam_));
	ostr.write((char*)&L_,sizeof(L_));
	ostr.write((char*)&B_l_,sizeof(B_l_));
	ostr.write((char*)&B_r_,sizeof(B_r_));
	ostr.write((char*)&temp_supports_num_,sizeof(temp_supports_num_));
}
//---------------------------------------------------------------------------
// Чтение данных из бинарного файл
//---------------------------------------------------------------------------
void Geometry::load(istream& istr)
{
	istr.read((char*)&end_beam_,sizeof(end_beam_));
	istr.read((char*)&L_,sizeof(L_));
	istr.read((char*)&B_l_,sizeof(B_l_));
	istr.read((char*)&B_r_,sizeof(B_r_));
	istr.read((char*)&temp_supports_num_,sizeof(temp_supports_num_));
}

String Geometry::is_end_beam_to_str()const
{
	if(!end_beam_)
		return L"Нет";
	else
		return L"Да";
}
void Geometry::calculate_effective_width(double h_f, double b_uf)
{
	double b_l = 0.;
	double b_r = 0.;

	double a=b_uf/2;

	if (!end_beam_ )
	{
		b_l_ = basic_effective_width(h_f,a,B_l_,L_);
		b_r_ = basic_effective_width(h_f,a,B_r_,L_);
		return;
	}

		b_l_ = cantilever_effective_width(h_f,a,B_l_,L_);
		b_r_ = basic_effective_width(h_f,a,B_r_,L_);
}
//---------------------------------------------------------------------------
//Определение расчётного свеса плиты
//Передаваемые параметры (в порядке представленном в функции):
//  *толщина плиты,
//  *половина ширины контакта  ж.б плиты и стального пояса
//	*расстояние между осями балок
//	*пролёт балки
//---------------------------------------------------------------------------
double Geometry::basic_effective_width(double h_f, double a,  double B, double l)
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
double Geometry::cantilever_effective_width(double h_f, double a,  double C, double l)
{
	double bc = 0;
	double t_slc = h_f;

	if (l >= 12 * C)
		bc = C;
	else
		bc = a + 6 * t_slc;
	return clamp(bc, l/12, C );
}
double Geometry::get_effective_width(double h_f, double b_uf)
{
	if (effective_width_calculated_) return b_l_ + b_r_ ;

	calculate_effective_width(h_f, b_uf);

	return b_l_ + b_r_ ;
}
double Geometry::get_trib_width(LengthUnit length_units)const
{
	if (end_beam_)
		return  (B_l_ + B_r_ / 2) / static_cast<int>(length_units);
	return (B_l_ / 2 + B_r_ / 2) / static_cast<int>(length_units);

}
