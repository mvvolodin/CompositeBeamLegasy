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
RebarBasic::RebarBasic(String grade, double R_s):
	grade_(grade),
	R_s_(R_s){}

Rebar::Rebar():
	RebarBasic(),
	E_s_(200000){}

Rebar::Rebar(String grade, double R_s, double diameter, double b, double a_u,
	double a_l, double safety_factor):
	RebarBasic{grade, R_s},
	E_s_{200000},
	diameter_{diameter},
	b_{b},
	a_u_{a_u},
	a_l_{a_l},
	safety_factor_(safety_factor)
	{}

void Rebar::calc_A_s()
{
	A_s_ = 3.14159*diameter_*diameter_ / (4 * b_);
}
