//---------------------------------------------------------------------------

#pragma hdrstop

#include "MathFunction.h"
#include <cassert>
//---------------------------------------------------------------------------
#pragma package(smart_init)

 double clamp( double v, double lo, double hi )
{
	assert( !(hi < lo) );
	return (v < lo) ? lo : (hi < v) ? hi : v;
}
