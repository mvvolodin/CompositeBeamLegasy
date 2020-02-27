//---------------------------------------------------------------------------

#pragma hdrstop

#include "Rebar.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

RebarNamedList rebar_named_list
{
{{"A240"},		{"A240",240}},
{{"A400"},		{"A400",400}},
{{"A500"},		{"A500",500}},
{{"A600"},		{"A600",600}},
{{"A800"},		{"A800",800}},
{{"A1000"},		{"A1000",1000}},
};

RebarBasic::RebarBasic()
{
}
RebarBasic::RebarBasic(String grade, double R_sn):
	grade_(grade),
	R_sn_(R_sn){}

Rebar::Rebar():
	RebarBasic()
{
	calc_A_s();
}

Rebar::Rebar(String grade, double R_sn, double d_s, double b, double a_u,
	double a_l, double gamma_s):
	RebarBasic{grade, R_sn},
	d_s_(d_s),
	b_(b),
	a_u_(a_u),
	a_l_(a_l),
	gamma_s_(gamma_s)
{
   calc_A_s();
}

void Rebar::calc_A_s()
{
	A_s_ = 3.14159*d_s_*d_s_ / (4. * b_);
}
