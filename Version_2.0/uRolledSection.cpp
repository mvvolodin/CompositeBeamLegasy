//---------------------------------------------------------------------------

#pragma hdrstop

#include "uRolledSection.h"
#include "StandartProfil.h"
#include <iostream>
//---------------------------------------------------------------------------
#pragma package(smart_init)

RolledSection::RolledSection(std::wstring const & prof_num,
							 double const lower_fl_width, double const  lower_fl_thick,
							 double const upper_fl_width, double const  upper_fl_thick,
							 double const  h_w, double const  t_w,
							 double const  C, double const  A, double const  I):
								 prof_num_(prof_num),
								 lower_fl_width_(lower_fl_width),
								 lower_fl_thick_(lower_fl_thick),
								 upper_fl_width_(upper_fl_width),
								 upper_fl_thick_(upper_fl_thick),
								 h_w_(h_w),
								 t_w_(t_w),
								 C_(C),
								 A_(A),
								 I_(I){}

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
	h_w_ = ParamProfil[parHSECT] - 2 * ParamProfil[parTF];
	t_w_ = ParamProfil[parTW];
	C_ = ParamProfil[parHSECT] / 2;
	A_ = ParamProfil[parAREA];
	I_ = ParamProfil[parIZZ ];


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
	return h_w_;
}
double RolledSection::web_thick()const
{
	return t_w_;
}
double RolledSection::sect_height()const
{
	return lower_fl_thick_ + h_w_ + upper_fl_thick_;
}

double RolledSection::C_st()const
{
	return C_;
}
double RolledSection::A_f1_st()const
{
	return lower_fl_width_ * lower_fl_thick_;
}
double RolledSection::A_f2_st()const
{
	return upper_fl_width_ * upper_fl_thick_;
}
double RolledSection::A_st()const
{
	return A_;
}

double RolledSection::I_st()const
{
	return I_;
}
double RolledSection::smaller_fl_to_larger_fl_ratio()const
{
	return 1;
}

double RolledSection::SW()const
{
	return A_st() * 7850 / 1000 / 1000 * 9.81;
}
double RolledSection::W_f2_st()const
{
	return I_ / Z_f2_st();
}
double RolledSection::W_f1_st()const
{
	return I_ / Z_f1_st();
}
double RolledSection::Z_f2_st() const
{
	return sect_height() - C_;
}
double RolledSection::Z_f1_st()const
{
	return C_;
}
#ifndef NDEBUG
void RolledSection::print_data_to_logger(TFormLogger const & log)const
{
	log.add_heading(L"Тип сечения");
	log.print_string(L"Прокатный двутавр");;
}
#endif
