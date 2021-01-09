//---------------------------------------------------------------------------
#ifndef uStudsSP35CalculatedH
#define uStudsSP35CalculatedH
#include <vector>
#include <Vcl.Grids.hpp>
#include "uStudsSP35.h"
#include "uStudRowSP35Calculated.h"
#include "uWord_Automation.h"
//---------------------------------------------------------------------------
struct StudsSP35Calculated{
	StudsSP35* input_;

	std::vector<double> S_overline_lst_;
	std::vector<double> coord_;

	std::vector<StudRowSP35Calculated> rows_;

	StudRowSP35Calculated stud_max_ratio()const;

	void print(TWord_Automation & report)const;
	void fill_grid(TStringGrid* str_grid)const;
};
//---------------------------------------------------------------------------
#endif
