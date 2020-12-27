//---------------------------------------------------------------------------
#ifndef uStudsSP266CalculatedH
#define uStudsSP266CalculatedH

#include <vector>
#include <Vcl.Grids.hpp>
#include "uStudsSP266.h"
#include "uStudRowSP266Calculated.h"
#include "uWord_Automation.h"

//---------------------------------------------------------------------------
struct StudsSP266Calculated{
	StudsSP266* input_;

	std::vector<double> S_overline_lst_;
	std::vector<double> coord_;

	std::vector<StudRowSP266Calculated> rows_;



	StudRowSP266Calculated stud_max_ratio()const;

	void print(TWord_Automation & report)const;
	void fill_grid(TStringGrid* str_grid)const;
};
//---------------------------------------------------------------------------
#endif
