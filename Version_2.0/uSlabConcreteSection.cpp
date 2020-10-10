//---------------------------------------------------------------------------

#pragma hdrstop

#include "uSlabConcreteSection.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

SlabConcreteSection::SlabConcreteSection(const double h_f,
										 const Rebar rebar,
										 const double b,
										 const double a_u,
										 const double a_l,
										 const double L,
										 const double B_l,
										 const double B_r,
										 const double b_uf,
										 const bool end_beam):
	GeneralConcreteSection(h_f, rebar, b, a_u, a_l, L, B_l, B_r, b_uf,
		 end_beam){}
SlabConcreteSection::~SlabConcreteSection()
{

}
double SlabConcreteSection::h() const
{
	return h_f_;
}
double SlabConcreteSection::h_n() const
{
	return 0;
}
double SlabConcreteSection::C_b() const
{
	return h_f_ / 2;
}

