//---------------------------------------------------------------------------

#pragma hdrstop

#include "uGeometry.h"
#include <algorithm>
#include "MathFunction.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

TGeometry::TGeometry(){}

TGeometry::TGeometry(int beam_division, bool end_beam, double L, double B_l, double B_r,
	int temporary_supports_number)
	 :beam_division_			(beam_division),
	 end_beam_					(end_beam),
	 L_							(L),
	 B_l_						(B_l),
	 B_r_						(B_r),
	 temporary_supports_number_	(temporary_supports_number)
{
	permanent_supports_coordinates_calculation();
	temporary_supports_coordinates_calculation();
	all_supports_coordinates_calculation();
}
void TGeometry::set_default_values()
{
	end_beam_ = false;
	L_ = 18000;
	B_l_ = 6000;
	B_r_ = 6000;
	temporary_supports_number_ = 0;
	beam_division_ = 50;


}
//---------------------------------------------------------------------------
// Сохранение данных в бинарный файл
//---------------------------------------------------------------------------
void TGeometry::save(ostream& ostr)const
{
	ostr.write((char*)&end_beam_,sizeof(end_beam_));
	ostr.write((char*)&L_,sizeof(L_));
	ostr.write((char*)&B_l_,sizeof(B_l_));
	ostr.write((char*)&B_r_,sizeof(B_r_));
	ostr.write((char*)&temporary_supports_number_,sizeof(temporary_supports_number_));
	ostr.write((char*)&beam_division_,sizeof(beam_division_));

}
//---------------------------------------------------------------------------
// Чтение данных из бинарного файл
//---------------------------------------------------------------------------
void TGeometry::load(istream& istr)
{
	istr.read((char*)&end_beam_,sizeof(end_beam_));
	istr.read((char*)&L_,sizeof(L_));
	istr.read((char*)&B_l_,sizeof(B_l_));
	istr.read((char*)&B_r_,sizeof(B_r_));
	istr.read((char*)&temporary_supports_number_,sizeof(temporary_supports_number_));
	istr.read((char*)&beam_division_,sizeof(beam_division_));

}
void TGeometry::permanent_supports_coordinates_calculation()
{
   permanent_supports_coordinates_.push_back(0.0);
   permanent_supports_coordinates_.push_back(L_);
}
void TGeometry::temporary_supports_coordinates_calculation()
{
	double coordinate=0.0;
	for (int i = 0; i < temporary_supports_number_; i++)
	{
		coordinate+=L_/(temporary_supports_number_+1);
		temporary_supports_coordinates_.push_back(coordinate);
	}
}
void TGeometry::all_supports_coordinates_calculation()
{
	all_supports_coordinates_.insert(all_supports_coordinates_.begin(),permanent_supports_coordinates_.begin(),permanent_supports_coordinates_.end());
	all_supports_coordinates_.insert(all_supports_coordinates_.end(),temporary_supports_coordinates_.begin(),temporary_supports_coordinates_.end());
	std::sort(all_supports_coordinates_.begin(),all_supports_coordinates_.end());
}
String TGeometry::is_end_beam_to_str()const
{
	if(!end_beam_)
		return L"Нет";
	else
		return L"Да";
}
void TGeometry::calculate_effective_width(double h_f, double b_uf)
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
double TGeometry::basic_effective_width(double h_f, double a,  double B, double l)
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
double TGeometry::cantilever_effective_width(double h_f, double a,  double C, double l)
{
	double bc = 0;
	double t_slc = h_f;

	if (l >= 12 * C)
		bc = C;
	else
		bc = a + 6 * t_slc;
	return clamp(bc, l/12, C );
}
double TGeometry::get_effective_width(double h_f, double b_uf)
{
	if (effective_width_calculated_) return b_l_ + b_r_ ;

	calculate_effective_width(h_f, b_uf);

	return b_l_ + b_r_ ;
}
