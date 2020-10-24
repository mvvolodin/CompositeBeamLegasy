//---------------------------------------------------------------------------
#pragma hdrstop

#include "uCorrugatedConcreteSection.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

CorrugatedConcreteSection::CorrugatedConcreteSection(
	CorrugatedSheet const & corr_sheet,
	double const  h_f,
	double const  L,
	double const  B_l,
	double const  B_r,
	double const  b_uf,
	bool const    is_end_beam,
	Rebars const & rebars):
		GeneralConcreteSection(h_f, L, B_l, B_r, b_uf,
			is_end_beam, rebars),
		corr_sheet_(corr_sheet){};
CorrugatedConcreteSection::~CorrugatedConcreteSection()
{

}
double CorrugatedConcreteSection::h() const
{
	return corr_sheet_.get_height() + h_f_;
}
double CorrugatedConcreteSection::h_n() const
{
	return corr_sheet_.get_height();
}
double CorrugatedConcreteSection::C_b() const
{
	return corr_sheet_.get_height() + h_f_ / 2;
}
double CorrugatedConcreteSection::SW(double dens) const
{
	return dens * 9.81 * (h_f_ + corr_sheet_.get_h_b(wider_flange_up_));
}
CorrugatedSheet CorrugatedConcreteSection::corrugated_sheet()const
{
	return corr_sheet_;
}
