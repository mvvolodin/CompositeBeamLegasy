//---------------------------------------------------------------------------

#pragma hdrstop

#include <iostream>
#include "uRolledSection.h"
#include "StandartProfil.h"
#include "uUnits_new.h"
#include "Constants.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

using namespace units;

RolledSection::RolledSection(int rolled_sect_type, int rolled_sect_num)
{
	//Получить данные группы профилей по индексу
	TStandartProfil StandartProfil;
	StandartProfil.SetProfil(rolled_sect_type + typeGOST_G57837_B);

	//Получить вектор имён профилей по индексу группы профилей
	int n_profil;
	AnsiString* sect_nums_array = StandartProfil.GetVectorNameProfil(&n_profil);

	String sect_num = sect_nums_array[rolled_sect_num];

	//Заполнить данные профиля по индексу профиля
	double * ParamProfil;
	ParamProfil = StandartProfil.GetVectorParamProfil(rolled_sect_num);

	prof_num_ =  sect_num.c_str();
	lower_fl_width_ = ParamProfil[parBSECT];
	lower_fl_thick_ = ParamProfil[parTF];
	upper_fl_width_ = ParamProfil[parBSECT];
	upper_fl_thick_ = ParamProfil[parTF];
	web_height_ = ParamProfil[parHSECT] - 2 * ParamProfil[parTF];
	web_thick_ = ParamProfil[parTW];
	rad_ = ParamProfil[parRAD];
	grav_cent_ = ParamProfil[parHSECT] / 2;
	area_ = ParamProfil[parAREA];
	inertia_ = ParamProfil[parIZZ];
}
RolledSection::~RolledSection()
{

}
std::wstring RolledSection::name()const
{
	return prof_num_;
}
double RolledSection::lower_fl_width()const
{
	return lower_fl_width_;
}
double RolledSection::lower_fl_thick()const
{
	return lower_fl_thick_;
}
double RolledSection::upper_fl_width()const
{
	return upper_fl_width_;
}
double RolledSection::upper_fl_thick()const
{
	return upper_fl_thick_;
}
double RolledSection::web_height()const
{
	return web_height_;
}
double RolledSection::web_thick()const
{
	return web_thick_;
}
double RolledSection::sect_height()const
{
	return lower_fl_thick_ + web_height_ + upper_fl_thick_;
}

double RolledSection::grav_cent()const
{
	return grav_cent_;
}
double RolledSection::area_upper_fl()const
{
	return lower_fl_width_ * lower_fl_thick_;
}
double RolledSection::area_lower_fl()const
{
	return upper_fl_width_ * upper_fl_thick_;
}
double RolledSection::area_web()const
{
	return web_height_ * web_thick_;
}
double RolledSection::area()const
{
	return area_;
}

double RolledSection::inertia()const
{
	return inertia_;
}
double RolledSection::smaller_fl_to_larger_fl_ratio()const
{
	return (area_upper_fl() <= area_lower_fl())?
		area_upper_fl() / area_lower_fl() : area_lower_fl() / area_upper_fl();
}
double RolledSection::smaller_fl_area_to_web_area_ratio()const
{
	double const A_smaller_fl = (area_upper_fl() <= area_lower_fl())?
		area_upper_fl() : area_lower_fl();

	return A_smaller_fl / area_web();
}
double RolledSection::smaller_fl_area_plus_web_area_to_total_area_ratio()const
{
	double const A_smaller_fl = (area_upper_fl() <= area_lower_fl())?
		area_upper_fl() : area_lower_fl();

	return (A_smaller_fl + area_web()) / area();
}

double RolledSection::SW()const
{
	return area() * constants::steel_density / mm3 * constants::grav_accelerate;
}
double RolledSection::modulus_upper_fl()const
{
	return inertia_ / grav_cent_upper_fl_dist();
}
double RolledSection::modulus_lower_fl()const
{
	return inertia_ / grav_cent_lower_fl_dist();
}
double RolledSection::grav_cent_upper_fl_dist() const
{
	return sect_height() - grav_cent_;
}
double RolledSection::grav_cent_lower_fl_dist()const
{
	return grav_cent_;
}
double RolledSection::radius()const
{
	return rad_;
}
void RolledSection::print_input(TWord_Automation & report)const
{
	report.PasteTextPattern(prof_num_.c_str() ,"%name%");
}
void RolledSection::print_output(TWord_Automation & report)const
{
	report.PasteTextPattern(name().c_str() ,"%name%");
	report.PasteTextPattern(length_to_str(sect_height()), "%sect_height%");
	report.PasteTextPattern(length_to_str(upper_fl_width_),"%upper_fl_width%");
	report.PasteTextPattern(length_to_str(upper_fl_thick_),"%upper_fl_thick%");
	report.PasteTextPattern(length_to_str(lower_fl_width_),"%lower_fl_width%");
	report.PasteTextPattern(length_to_str(lower_fl_thick_),"%lower_fl_thick%");
	report.PasteTextPattern(length_to_str(web_height_),"%web_height%");
	report.PasteTextPattern(length_to_str(web_thick_),"%web_thick%");
	report.PasteTextPattern(length_to_str(rad_),"%radius%");

	report.PasteTextPattern(area_to_str(area_, LengthUnit::cm),"%area%");
	report.PasteTextPattern(inertia_to_str(inertia_, LengthUnit::cm),"%inertia%");
	report.PasteTextPattern(sect_modul_to_str(modulus_upper_fl(), LengthUnit::cm),"%modulus_upper_fl%");
	report.PasteTextPattern(sect_modul_to_str(modulus_lower_fl(), LengthUnit::cm),"%modulus_lower_fl%");
	report.PasteTextPattern(length_to_str(grav_cent_upper_fl_dist(), LengthUnit::cm),"%GC_upper_fl_dist%");
	report.PasteTextPattern(length_to_str(grav_cent_lower_fl_dist(), LengthUnit::cm),"%GC_lower_fl_dist%");
}

#ifndef NDEBUG
void RolledSection::print_data_to_logger(TFormLogger const & log)const
{
	log.add_heading(L"Тип сечения");
	log.print_string(L"Прокатный двутавр");;
}
#endif
