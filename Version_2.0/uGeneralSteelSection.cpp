//---------------------------------------------------------------------------

#pragma hdrstop

#include "uGeneralSteelSection.h"
#include <iostream>
#include <algorithm>
#include "Units.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//#define REPORT(var, unit) report.PasteTextPattern(FloatToStrF(var(unit), ffFixed, 15, 2),"%" #var "%")

GeneralSteelSection::GeneralSteelSection()
{
	std::cout << "ISection::ISection()" << std::endl;
}
GeneralSteelSection:: ~ GeneralSteelSection()
{
	std::cout << "ISection:: ~ ISection()" << std::endl;
}

double GeneralSteelSection::t_max()const
{
	return std::max({upper_fl_thick(),
					 lower_fl_thick(),
					 web_thick()});
}

void GeneralSteelSection::fill_grid(TStringGrid* str_grid)const
{
	str_grid -> Cells [1][1] = FloatToStrF(area(), ffFixed, 15, 0);
	str_grid -> Cells [1][2] = FloatToStrF(inertia(), ffFixed, 15, 0);
	str_grid -> Cells [1][3] = FloatToStrF(modulus_upper_fl(), ffFixed, 15, 0);
	str_grid -> Cells [1][4] = FloatToStrF(modulus_lower_fl(), ffFixed, 15, 0);
	str_grid -> Cells [1][5] = FloatToStrF(grav_cent_upper_fl_dist(), ffFixed, 15, 0);
	str_grid -> Cells [1][6] = FloatToStrF(grav_cent_lower_fl_dist(), ffFixed, 15, 0);
}






