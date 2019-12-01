//---------------------------------------------------------------------------

#pragma hdrstop

#include "GeometryUnit.h"
#include <algorithm>
//---------------------------------------------------------------------------
#pragma package(smart_init)
TGeometry::TGeometry()
{
}
TGeometry::TGeometry(bool end_beam, double span, double trib_width_left, double trib_width_right,
	int propping_number)
	:end_beam_(end_beam),
	 span_(span),
	 trib_width_left_(trib_width_left),
	 trib_width_right_(trib_width_right),
	 propping_number_(propping_number)
{}
