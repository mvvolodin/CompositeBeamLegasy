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

RebarBasic::RebarBasic():
	grade(""),
	R_s(0.0){}

RebarBasic::RebarBasic(String grade, double R_s):
	grade(grade),
	R_s(R_s){}

Rebar::Rebar():
	RebarBasic(),
	E_s(200000),
	diameter(0.0),
	safety_factor(0.0){}

Rebar::Rebar(String grade, double R_s, double diameter, double safety_factor):
	RebarBasic(grade, R_s),
	E_s(200000),
	diameter(diameter),
	safety_factor(safety_factor){}

