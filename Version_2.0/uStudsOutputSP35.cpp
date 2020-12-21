//---------------------------------------------------------------------------

#pragma hdrstop

#include "uStudsOutputSP35.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

StudSP35 StudsOutputSP35::st_;

StudsOutputSP35::StudsOutputSP35(std::vector<StudRowOutputSP35> const & rows,
								 std::vector<double> const & S_overline_lst,
								 std::vector<double> const & coord):
									rows_(rows),
									S_overline_lst_(S_overline_lst),
									coord_(coord){}
