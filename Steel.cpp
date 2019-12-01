//---------------------------------------------------------------------------

#pragma hdrstop

#include "Steel.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
Steel::Steel()
	:R_y_(0.0),
	 R_u_(0.0),
	 E_s_(0.0),
	 G_s_(0.0),
	 nu_(0.0),
	 gamma_m_(0.0){}
Steel::Steel(TSteelInitialData steel_initial_data)
{
	R_y_=steel_initial_data.R_y;
	R_u_=steel_initial_data.R_u;
	E_s_=steel_initial_data.E_s;
	G_s_=steel_initial_data.G_s;
	nu_=steel_initial_data.nu;
	gamma_m_=steel_initial_data.gamma_m;

}


