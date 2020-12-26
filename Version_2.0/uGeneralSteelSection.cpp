//---------------------------------------------------------------------------

#pragma hdrstop

#include "uGeneralSteelSection.h"
#include <iostream>
#include <algorithm>
#include "uUnits_new.h"
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
void GeneralSteelSection::fill_grid_SP266(TStringGrid* str_grid)const
{
	str_grid -> Cells [1][1] = FloatToStrF(area(), ffFixed, 15, 0);
	str_grid -> Cells [1][2] = FloatToStrF(inertia(), ffFixed, 15, 0);
	str_grid -> Cells [1][3] = FloatToStrF(modulus_upper_fl(), ffFixed, 15, 0);
	str_grid -> Cells [1][4] = FloatToStrF(modulus_lower_fl(), ffFixed, 15, 0);
	str_grid -> Cells [1][5] = FloatToStrF(grav_cent_upper_fl_dist(), ffFixed, 15, 0);
	str_grid -> Cells [1][6] = FloatToStrF(grav_cent_lower_fl_dist(), ffFixed, 15, 0);
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
void GeneralSteelSection::print_SP266(TWord_Automation & report)const
{
	using namespace units;

	report.PasteTextPattern(name().c_str() ,"%name%");
	report.PasteTextPattern(double_to_str(sect_height(), 0), "%sect_height%");
	report.PasteTextPattern(double_to_str(upper_fl_width(), 0),"%upper_fl_width%");
	report.PasteTextPattern(double_to_str(upper_fl_thick(), 0),"%upper_fl_thick%");
	report.PasteTextPattern(double_to_str(lower_fl_width(), 0),"%lower_fl_width%");
	report.PasteTextPattern(double_to_str(lower_fl_thick(), 0),"%lower_fl_thick%");
	report.PasteTextPattern(double_to_str(web_height(), 0),"%web_height%");
	report.PasteTextPattern(double_to_str(web_thick(), 0),"%web_thick%");
	report.PasteTextPattern(double_to_str(0, 0),"%radius%");

	report.PasteTextPattern(double_to_str(area() * cm2),"%area%");
	report.PasteTextPattern(double_to_str(inertia() * cm4),"%inertia%");
	report.PasteTextPattern(double_to_str(modulus_upper_fl() * cm3),"%modulus_upper_fl%");
	report.PasteTextPattern(double_to_str(modulus_lower_fl() * cm3),"%modulus_lower_fl%");
	report.PasteTextPattern(double_to_str(grav_cent_upper_fl_dist()),"%GC_upper_fl_dist%");
	report.PasteTextPattern(double_to_str(grav_cent_lower_fl_dist()),"%GC_lower_fl_dist%");
}






