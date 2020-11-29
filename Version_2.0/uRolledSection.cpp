//---------------------------------------------------------------------------

#pragma hdrstop

#include "uRolledSection.h"
#include "StandartProfil.h"
#include <iostream>
//---------------------------------------------------------------------------
#pragma package(smart_init)

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
	return 1;
}

double RolledSection::SW()const
{
	return area() * 7850 / 1000 / 1000 * 9.81;
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
	report.PasteTextPattern(name().c_str() ,"%name%");
}
void RolledSection::print_output(TWord_Automation & report)const
{
	report.PasteTextPattern(FloatToStrF(sect_height(), ffFixed, 15, 2),"%sect_height%");
	report.PasteTextPattern(FloatToStrF(upper_fl_width(), ffFixed, 15, 2),"%upper_fl_width%");
	report.PasteTextPattern(FloatToStrF(upper_fl_thick(), ffFixed, 15, 2),"%upper_fl_thick%");
	report.PasteTextPattern(FloatToStrF(lower_fl_width(), ffFixed, 15, 2),"%lower_fl_width%");
	report.PasteTextPattern(FloatToStrF(lower_fl_thick(), ffFixed, 15, 2),"%lower_fl_thick%");
	report.PasteTextPattern(FloatToStrF(web_height(), ffFixed, 15, 2),"%web_height%");
	report.PasteTextPattern(FloatToStrF(web_thick(), ffFixed, 15, 2),"%web_thick%");
	report.PasteTextPattern(FloatToStrF(radius(), ffFixed, 15, 2),"%radius%");

	report.PasteTextPattern(FloatToStrF(area(), ffFixed, 15, 2),"%area%");
	report.PasteTextPattern(FloatToStrF(inertia(), ffFixed, 15, 2),"%inertia%");
	report.PasteTextPattern(FloatToStrF(upper_fl_thick(), ffFixed, 15, 2),"%modulus_upper_fl%");
	report.PasteTextPattern(FloatToStrF(upper_fl_thick(), ffFixed, 15, 2),"%modulus_lower_fl%");


}
#ifndef NDEBUG
void RolledSection::print_data_to_logger(TFormLogger const & log)const
{
	log.add_heading(L"Тип сечения");
	log.print_string(L"Прокатный двутавр");;
}
#endif
