//---------------------------------------------------------------------------

#pragma hdrstop
#include <algorithm>
#include <cmath>
#include "uStudsOutputSP35.h"
#include "uUnits_new.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

StudsOutputSP35::StudsOutputSP35(StudsInputSP35 const & st_input,
								 std::vector<StudRowOutputSP35> const & rows,
								 std::vector<double> const & S_overline_lst,
								 std::vector<double> const & coord):
									st_input_(st_input),
									rows_(rows),
									S_overline_lst_(S_overline_lst),
									coord_(coord){}
void StudsOutputSP35::print(TWord_Automation & report)const
{
	StudRowOutputSP35 sr = stud_max_ratio();

	using namespace units;

	report.PasteTextPattern(st_input_.stud().name().c_str(),"%stud_name%");
	report.PasteTextPattern(double_to_str(st_input_.stud().l_1(), 0),"%l_1%");
	report.PasteTextPattern(double_to_str(st_input_.stud().d_1(), 0),"%d_1%");
	report.PasteTextPattern(double_to_str(st_input_.stud().R_y(), 0),"%R_y%");
	report.PasteTextPattern(double_to_str(st_input_.dist_e(), 0),"%dis_e%");
	report.PasteTextPattern(double_to_str(st_input_.dist_m(), 0),"%dis_m%");
	report.PasteTextPattern(double_to_str(st_input_.num_st_row_e(), 0),"%st_re_num%");
	report.PasteTextPattern(double_to_str(st_input_.num_st_row_m(), 0),"%st_rm_num%");

	report.PasteTextPattern(double_to_str(sr.x(), 0),"%coord_sr%");
	report.PasteTextPattern(double_to_str(sr.st_num(), 0),"%st_num%");
	report.PasteTextPattern(double_to_str(st_input_.stud().P_Rd() * kN),"%P_Rd%");
	report.PasteTextPattern(double_to_str(std::abs(sr.S_Ed()) * kN),"%S_Ed_r%");
	report.PasteTextPattern(double_to_str(std::abs(sr.ratio())),"%st_rat%");


}
#ifndef NDEBUG
void StudsOutputSP35::print_to_logger()const
{
	using namespace units;

	FormLogger -> add_heading(u"Исходные данные для расчёта упоров");
	FormLogger -> print_string(u"Характеристики упора");
	FormLogger -> print_string(String(u"Наименование:  ") + st_input_.stud().name().c_str());
	FormLogger -> print_double(u"l1 = ", st_input_.stud().l_1(), u" мм");
	FormLogger -> print_double(u"d1 = ", st_input_.stud().d_1(), u" мм");
	FormLogger -> print_double(u"Ry = ", st_input_.stud().R_y(), u" Н/мм2");
	FormLogger -> print_double(u"Prd = ",st_input_.stud().P_Rd() * kN, u" kН");
	for(auto const & r:rows_)
		FormLogger -> print_4_doubles(u"id = ", r.id(), u"",
									  u"x = ",  r.x(), u" мм",
									  u"S_Ed = ", r.S_Ed() * kN, u" kN",
									  u"ratio = ", std::abs(r.ratio()), u" ");
}
#endif
StudRowOutputSP35 StudsOutputSP35::stud_max_ratio()const
{
	return *std::max_element(rows_.cbegin(), rows_.cend(),
	[](auto const &  sr1, auto const &  sr2){
		return std::abs(sr1.ratio()) < std::abs(sr2.ratio());});
}

void StudsOutputSP35::fill_grid_SP35(TStringGrid* str_grid)const
{
	StudRowOutputSP35 sr = stud_max_ratio();

	using namespace units;

	str_grid -> Cells [1][13] = double_to_str(sr.x(), 0);
	str_grid -> Cells [1][14] = double_to_str(std::abs(sr.ratio()));
}



