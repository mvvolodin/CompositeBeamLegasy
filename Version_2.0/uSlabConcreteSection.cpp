//---------------------------------------------------------------------------

#pragma hdrstop

#include "uSlabConcreteSection.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

SlabConcreteSection::SlabConcreteSection(double h_f,
										 double h_n,
										 double b_sl,
										 Rebar& rebar,
										 double b,
										 double a_u,
										 double a_l):
										h_f_{std::move(h_f)},
										h_n_{std::move(h_n)},
										b_sl_{std::move(b_sl)},
										rebar_{std::move(rebar)},
										b_{std::move(b)},
										a_u_{std::move(a_u)},
										a_l_{std::move(a_l)}{}
double SlabConcreteSection::h_f() const
{
	return h_f_;
}
double SlabConcreteSection::h_n() const
{
	return h_n_;
}
double SlabConcreteSection::b_sl() const
{
	return b_sl_;
}
const Rebar& SlabConcreteSection::rebar()const
{
	return rebar_;
}
double SlabConcreteSection::a_u() const
{
	return a_u_;
}
double SlabConcreteSection::a_l() const
{
	return a_l_;
}
double SlabConcreteSection::h() const
{
	return h_n_ + h_f_;
}
double SlabConcreteSection::C_b() const
{
	return h_n_ + h_f_ / 2;
}
double SlabConcreteSection::A_b() const
{
	return h_f_ * b_sl_ ;
}
double SlabConcreteSection::I_b() const
{
	return h_f_ * b_sl_ * b_sl_ * b_sl_ / 12;

}

