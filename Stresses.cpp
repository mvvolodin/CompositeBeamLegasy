//---------------------------------------------------------------------------

#pragma hdrstop

#include "Stresses.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
Stresses::Stresses()
{

}

Stresses::Stresses (double sigma_b, double sigma_s, StressStateCase stress_state_case):
	sigma_b_(sigma_b),
	sigma_s_(sigma_s),
	stress_state_case_(stress_state_case){}




