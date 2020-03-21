//---------------------------------------------------------------------------

#pragma hdrstop

#include "GeometryUnit.h"
#include <algorithm>
//---------------------------------------------------------------------------
#pragma package(smart_init)

TGeometry::TGeometry(){}

TGeometry::TGeometry(int beam_division, bool end_beam, double span, double trib_width_left, double trib_width_right,
	int temporary_supports_number)
	 :beam_division_			(beam_division),
	 end_beam_					(end_beam),
	 span_						(span),
	 trib_width_left_			(trib_width_left),
	 trib_width_right_			(trib_width_right),
	 temporary_supports_number_	(temporary_supports_number)
{
	permanent_supports_coordinates_calculation();
	temporary_supports_coordinates_calculation();
	all_supports_coordinates_calculation();
}
void TGeometry::set_default_values()
{
	end_beam_ = false;
	span_ = 18000;
	trib_width_left_ = 6000;
	trib_width_right_ = 6000;
	temporary_supports_number_ = 0;
	beam_division_ = 50;


}
//---------------------------------------------------------------------------
// Сохранение данных в бинарный файл
//---------------------------------------------------------------------------
void TGeometry::save_geometry(ostream& ostr)const
{
	ostr.write((char*)&end_beam_,sizeof(end_beam_));
	ostr.write((char*)&span_,sizeof(span_));
	ostr.write((char*)&trib_width_left_,sizeof(trib_width_left_));
	ostr.write((char*)&trib_width_right_,sizeof(trib_width_right_));
	ostr.write((char*)&temporary_supports_number_,sizeof(temporary_supports_number_));
	ostr.write((char*)&beam_division_,sizeof(beam_division_));

}
//---------------------------------------------------------------------------
// Чтение данных из бинарного файл
//---------------------------------------------------------------------------
void TGeometry::load_geometry(istream& istr)
{
	istr.read((char*)&end_beam_,sizeof(end_beam_));
	istr.read((char*)&span_,sizeof(span_));
	istr.read((char*)&trib_width_left_,sizeof(trib_width_left_));
	istr.read((char*)&trib_width_right_,sizeof(trib_width_right_));
	istr.read((char*)&temporary_supports_number_,sizeof(temporary_supports_number_));
	istr.read((char*)&beam_division_,sizeof(beam_division_));

}
void TGeometry::permanent_supports_coordinates_calculation()
{
   permanent_supports_coordinates_.push_back(0.0);
   permanent_supports_coordinates_.push_back(span_);
}
void TGeometry::temporary_supports_coordinates_calculation()
{
	double coordinate=0.0;
	for (int i = 0; i < temporary_supports_number_; i++)
	{
		coordinate+=span_/(temporary_supports_number_+1);
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
