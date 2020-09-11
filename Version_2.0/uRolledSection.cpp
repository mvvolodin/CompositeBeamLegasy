//---------------------------------------------------------------------------

#pragma hdrstop

#include "uRolledSection.h"
#include <iostream>
//---------------------------------------------------------------------------
#pragma package(smart_init)

RolledSection::RolledSection(double b_f1, double t_f1,
							 double b_f2, double t_f2,
							 double h_w, double t_w,
							 double A, double I):
								 b_f1_(b_f1),
								 t_f1_(t_f1),
								 b_f2_(b_f1),
								 t_f2_(t_f1),
								 h_w_(h_w),
								 t_w_(t_w),
								 A_(A),
								 I_(I){}

double RolledSection::b_f1()
{
	return b_f1_;
}
double RolledSection::t_f1()
{
	return t_f1_;
}
double RolledSection::b_f2()
{
	return b_f2_;
}
double RolledSection::t_f2()
{
	return t_f2_;
}
double RolledSection::h_w()
{
	return h_w_;
}
double RolledSection::t_w()
{
	return t_w_;
}

double RolledSection::centroid()
{
	return C_;
}

double RolledSection::area()
{
	return A_;
}

double RolledSection::inertia()
{
	return I_;
}
