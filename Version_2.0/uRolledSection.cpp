//---------------------------------------------------------------------------

#pragma hdrstop

#include "uRolledSection.h"
#include <iostream>
//---------------------------------------------------------------------------
#pragma package(smart_init)

RolledSection::RolledSection(std::wstring const & prof_num,
							 double const  b_f1, double const  t_f1,
							 double const  b_f2, double const  t_f2,
							 double const  h_w, double const  t_w,
							 double const  C, double const  A, double const  I):
								 prof_num_{prof_num},
								 b_f1_{b_f1},
								 t_f1_{t_f1},
								 b_f2_{b_f1},
								 t_f2_{t_f1},
								 h_w_{h_w},
								 t_w_{t_w},
								 C_{C},
								 A_{A},
								 I_{I}{}
RolledSection::~RolledSection()
{

}
double RolledSection::b_f1()const
{
	return b_f1_;
}
double RolledSection::t_f1()const
{
	return t_f1_;
}
double RolledSection::b_f2()const
{
	return b_f2_;
}
double RolledSection::t_f2()const
{
	return t_f2_;
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
	return t_f1_ + h_w_ + t_f1_;
}

double RolledSection::Z_f2_st() const
{
	return h_st() - C_st();
}

double RolledSection::C_st()const
{
	return C_;
}

double RolledSection::A_st()const
{
	return A_;
}

double RolledSection::I_st()const
{
	return I_;
}

void RolledSection::print_data_to_logger(TFormLogger* log)const
{

}
