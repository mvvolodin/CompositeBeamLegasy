//---------------------------------------------------------------------------

#pragma hdrstop

#include "uSlabConcreteSection.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

SlabConcreteSection::SlabConcreteSection(double const  h_f,
										 double const h_n,
										 double const  L,
										 double const  B_l,
										 double const  B_r,
										 double const  b_uf,
										 bool const  is_end_beam,
										 Rebars const &  rebars):
	GeneralConcreteSection(h_f, L, B_l, B_r, b_uf, is_end_beam, rebars),
	h_n_(h_n){}
SlabConcreteSection::~SlabConcreteSection()
{

}
double SlabConcreteSection::h() const
{
	return h_n_ + h_f_;
}
double SlabConcreteSection::h_n() const
{
	return 0;
}
double SlabConcreteSection::C_b() const
{
	return h_n_ + h_f_ / 2;
}
double SlabConcreteSection::SW(double dens)const
{
	return dens * 9.81 * h_f_;
}

