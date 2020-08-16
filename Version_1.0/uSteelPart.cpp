//---------------------------------------------------------------------------

#pragma hdrstop

#include "uSteelPart.h"
#include <algorithm>
//---------------------------------------------------------------------------
#pragma package(smart_init)
SteelPart::SteelPart()
{
}
SteelPart::SteelPart(ISection I_section, Steel I_steel):
	I_section_(I_section),
	I_steel_(I_steel)
{

}
double SteelPart::get_Q_Rd()
{
	if (steel_part_calculated_)
		return Q_Rd_;
	calculate_steel_part();
	return Q_Rd_;
}
double SteelPart::get_M_Rd()
{
	if (steel_part_calculated_)
		return M_Rd_;
	calculate_steel_part();
	return M_Rd_;
}
void SteelPart::calculate_steel_part()
{
	 Q_Rd_ = calculate_Q_Rd();
	 M_Rd_ = calculate_M_Rd();
}
void SteelPart::save(ostream& ostr) const
{
	I_section_.save(ostr);
	I_steel_.save(ostr);
}
void SteelPart::load(istream& istr)
{
	I_section_.load(istr);
	I_steel_.load(istr);
}
void SteelPart::set_default_values()
{
	I_section_.set_default_values();
	I_steel_.set_default_values();
}

double SteelPart::calculate_Q_Rd()
{
   const double h_w = I_section_.get_h_w();
   const double t_w = I_section_.get_t_w();
   const double R_y = I_steel_.get_R_y();

   return 0.58 * R_y * t_w * h_w;
}

double SteelPart::calculate_M_Rd()
{
	const double Wf1 = I_section_.get_Wf1_st();
	const double Wf2 = I_section_.get_Wf2_st();
	const double R_y = I_steel_.get_R_y();

	return R_y * std::min(Wf1, Wf2);

}
