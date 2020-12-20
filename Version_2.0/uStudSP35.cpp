//---------------------------------------------------------------------------

#pragma hdrstop

#include "uStudSP35.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

StudSP35::StudSP35(std::u16string const & name, double d_1, double l_1, double R_y,
	double R_b, double gamma_c):
    	name_(name), d_1_(d_1), l_1_(l_1), R_y_(R_y), R_b_(R_b), gamma_c_(gamma_c){}
