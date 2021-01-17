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
std::u16string SlabConcreteSection::slab_type()const
{
	return u"Плоская плита";
}
double SlabConcreteSection::h() const
{
	return h_n_ + des_height_;
}
double SlabConcreteSection::h_n() const
{
	return 0;
}
double SlabConcreteSection::C_b() const
{
	return h_n_ + des_height_ / 2;
}
double SlabConcreteSection::SW(double dens)const
{
	return dens * 9.81 * des_height_;
}
#ifdef DEBUG_CONC_SECT
void SlabConcreteSection::log()const
{
		FormLogger -> print(
		{
		 "********************",
		 "Железобетонная плита",
		 "********************",
		 "Тип плиты: плоская"
		 });
	GeneralConcreteSection::log();
}
#endif

