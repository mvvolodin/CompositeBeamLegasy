//---------------------------------------------------------------------------

#pragma hdrstop

#include "Ratios.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
Ratios::Ratios()
{
}
Ratios::Ratios(double ratio_upper_flange, double ratio_lower_flange):
	ratio_upper_flange_(ratio_upper_flange),
	ratio_lower_flange_(ratio_lower_flange){}

