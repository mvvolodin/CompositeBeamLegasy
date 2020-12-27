//---------------------------------------------------------------------------

#pragma hdrstop

#include "uStudsSP266Calculated.h"
#include <algorithm>
#include "uUnits_new.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

StudRowSP266Calculated StudsSP266Calculated::stud_max_ratio()const
{
	return *std::max_element(rows_.cbegin(), rows_.cend(),
	[](auto const &  sr1, auto const &  sr2){
		return std::abs(sr1.ratio_) < std::abs(sr2.ratio_);});
}

void StudsSP266Calculated::fill_grid(TStringGrid* str_grid)const
{
	StudRowSP266Calculated sr = stud_max_ratio();

	using namespace units;

	str_grid -> Cells [1][16] = double_to_str(sr.x_, 0);
	str_grid -> Cells [1][17] = double_to_str(std::abs(sr.ratio_));
}

void StudsSP266Calculated::print(TWord_Automation & report)const
{
	StudRowSP266Calculated sr = stud_max_ratio();

	using namespace units;

	report.PasteTextPattern(input_ -> stud().name().c_str(),"%stud_name%");
	report.PasteTextPattern(double_to_str(input_ -> stud().l_1(), 0),"%l_1%");
	report.PasteTextPattern(double_to_str(input_ -> stud().d_1(), 0),"%d_1%");
	report.PasteTextPattern(double_to_str(input_ -> stud().R_y(), 0),"%R_y%");
	report.PasteTextPattern(double_to_str(input_ -> dist_e(), 0),"%dis_e%");
	report.PasteTextPattern(double_to_str(input_ -> dist_m(), 0),"%dis_m%");
	report.PasteTextPattern(double_to_str(input_ -> num_st_row_e(), 0),"%st_re_num%");
	report.PasteTextPattern(double_to_str(input_ -> num_st_row_m(), 0),"%st_rm_num%");
	report.PasteTextPattern(bool_to_str(input_ ->
		is_not_one_stud_per_corr_e()),"%is_not_one_stud_corr_e%");
	report.PasteTextPattern(bool_to_str(input_ ->
		is_not_one_stud_per_corr_e()),"%is_not_one_stud_corr_m%");

	report.PasteTextPattern(double_to_str(sr.x_, 0),"%coord_sr%");
	report.PasteTextPattern(double_to_str(sr.st_num_, 0),"%st_num%");
	report.PasteTextPattern(double_to_str(input_ -> stud().P_Rd() * kN),"%P_Rd%");
	report.PasteTextPattern(double_to_str(sr.k_),"%k%");
	report.PasteTextPattern(double_to_str(std::abs(sr.S_Ed_r_) * kN),"%S_Ed_r%");
	report.PasteTextPattern(double_to_str(std::abs(sr.ratio_)),"%st_rat%");
}
