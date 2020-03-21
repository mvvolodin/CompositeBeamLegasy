//---------------------------------------------------------------------------

#pragma hdrstop

#include "SteelPart.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
SteelPart::SteelPart()
{
}
SteelPart::SteelPart(ISection I_section, Steel I_steel):
	I_section_(I_section),
	I_steel_(I_steel)
{
	calc_Q_Rd();
}
void SteelPart::set_default_values()
{
	I_section_.set_default_values();
	I_steel_.set_default_values();
}

void SteelPart::calc_Q_Rd()
{
   const double h_w = get_h_w();
   const double t_w = get_t_w();
   const double R_y = get_R_y();

   Q_Rd_ = 0.58 * R_y * t_w * h_w;
}
