//---------------------------------------------------------------------------

#pragma hdrstop

#include "uRolledSection.h"
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
RolledSection::~RolledSection()
{

}
String RolledSection::name()const
{
	return "Прокатное";
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
double RolledSection::h_w()const
{
	return h_w_;
}
double RolledSection::t_w()const
{
	return t_w_;
}
double RolledSection::h_st()const
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
	return h_st() - C_;
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
