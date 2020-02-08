//---------------------------------------------------------------------------

#pragma hdrstop

#include "MathFunction.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

 double clamp( double v, double lo, double hi )
{
	return (v < lo) ? lo : (hi < v) ? hi : v;
}
