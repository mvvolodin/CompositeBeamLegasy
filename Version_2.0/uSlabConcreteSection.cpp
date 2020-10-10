//---------------------------------------------------------------------------

#pragma hdrstop

#include "uSlabConcreteSection.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

SlabConcreteSection::SlabConcreteSection(double const  h_f,
										 Rebars const  rebars,
										 double const  b,
										 double const  a_u,
										 double const  a_l,
										 double const  L,
										 double const  B_l,
										 double const  B_r,
										 double const  b_uf,
										 bool const  end_beam):
	GeneralConcreteSection(h_f, rebars, b, a_u, a_l, L, B_l, B_r, b_uf,
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

