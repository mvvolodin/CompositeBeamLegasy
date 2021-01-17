//---------------------------------------------------------------------------

#pragma hdrstop

#include "RectangSection.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
void RectangSection::calc_inertia()
{
I_b=b_sl*pow(t_sl,3)/12;
}
