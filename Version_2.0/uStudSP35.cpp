//---------------------------------------------------------------------------

#pragma hdrstop

#include "uStudSP35.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

StudSP35::StudSP35(std::u16string const & name, double d_an, double l, double R_y,
	double R_b, double gamma_c):
    	name_(name), d_an_(d_an), l_(l), R_y_(R_y), R_b_(R_b), gamma_c_(gamma_c){}
