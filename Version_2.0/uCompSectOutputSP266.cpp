//---------------------------------------------------------------------------

#pragma hdrstop
#include <algorithm>
#include "uCompSectOutputSP266.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

double CompSectOutputSP266::max_direct_str_ratio()const
{
	return std::max({std::abs(upper_fl_ratio_),
					std::abs(lower_fl_ratio_),
					std::abs(conc_ratio_)});
}

