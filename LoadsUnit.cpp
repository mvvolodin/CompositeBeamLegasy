//---------------------------------------------------------------------------

#pragma hdrstop

#include "LoadsUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

TLoads::TLoads()
		:SW_(0.0),DL_I_(0.0),DL_II_(0.0),LL_(0.0),gamma_f_SW_(0.0),gamma_f_DL_I_(0.0),
    	gamma_f_DL_II_(0.0),gamma_f_LL_(0.0)
	{}

TLoads::TLoads(double SW, double DL_I, double DL_II, double LL,
	double gamma_f_SW, double gamma_f_DL_I, double gamma_f_DL_II, double gamma_f_LL)
	:SW_(SW),DL_I_(DL_I),DL_II_(DL_II), LL_(LL),gamma_f_SW_(gamma_f_SW),gamma_f_DL_I_(gamma_f_DL_I),
	gamma_f_DL_II_(gamma_f_DL_II),gamma_f_LL_(gamma_f_LL)
{}
