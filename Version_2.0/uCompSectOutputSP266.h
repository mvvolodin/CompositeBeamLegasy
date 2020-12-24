//---------------------------------------------------------------------------
#ifndef uCompSectOutputSP266H
#define uCompSectOutputSP266H

#include "uGlobGeom.h"

//---------------------------------------------------------------------------
enum class DesignCaseSP266;
//---------------------------------------------------------------------------
struct CompSectOutputSP266{

	Node const nd_;
	DesignCaseSP266 const des_case_;
	double const M_1a_, M_1b_, M_2c_, M_2d_, M_total_,
				 Q_1a_, Q_1b_, Q_2c_, Q_2d_, Q_total_,
				 R_1a_, R_1b_, R_2c_, R_2d_, R_total_,
				 f_1a_, f_1b_, f_2c_, f_2d_, f_total_,

				 sigma_b_, sigma_s_,
				 sigma_bi_, sigma_si_,

				 upper_fl_ratio_, lower_fl_ratio_, conc_ratio_,
				 shear_ratio_,
				 st_sect_ratio_;
};


//---------------------------------------------------------------------------
#endif
