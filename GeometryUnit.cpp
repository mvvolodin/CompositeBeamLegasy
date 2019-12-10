//---------------------------------------------------------------------------

#pragma hdrstop

#include "GeometryUnit.h"
#include <algorithm>
//---------------------------------------------------------------------------
#pragma package(smart_init)


TGeometry::TGeometry()
	//:permanent_supports_number_(2)//шарнирно опёртая балка, количество постоянных опор постоянно и равно 2
{
}
TGeometry::TGeometry(int beam_division, bool end_beam, double span, double trib_width_left, double trib_width_right,
	int temporary_supports_number)
   //	:permanent_supports_number_(2),
	 :beam_division_(beam_division),
	 end_beam_(end_beam),
	 span_(span),
	 trib_width_left_(trib_width_left),
	 trib_width_right_(trib_width_right),
	 temporary_supports_number_(temporary_supports_number)
{
	permanent_supports_coordinates_calculation();
	temporary_supports_coordinates_calculation();
	all_supports_coordinates_calculation();
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
