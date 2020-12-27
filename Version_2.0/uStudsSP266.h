//---------------------------------------------------------------------------
#ifndef uStudsSP266H
#define uStudsSP266H

#include <vector>
#include "uStudSP266.h"
#include "uStudRowSP266.h"
#include "uCorrugatedSheet.h"

#include "Logger.h"

class StudsSP266{
public:
	StudsSP266() = delete;
	StudsSP266 (StudSP266 stud, double L,
				double dist_e, double dist_m,
				int num_st_row_e, int num_st_row_m,
				bool one_stud_per_corrug_e, bool one_stud_per_corrug_m,
                bool const is_corr_slab,
				CorrugatedSheet const & corr_sheet, bool is_wider_fl_up,
				bool is_sheet_orient_along);

   StudSP266 stud()const{return stud_;}
   double dist_e()const{return dist_e_;}
   double dist_m()const{return dist_m_;}
   double num_st_row_e()const{return num_st_row_e_;}
   double num_st_row_m()const{return num_st_row_m_;}
   bool is_not_one_stud_per_corr_e()const{return is_not_one_stud_per_corr_e_;}
   bool is_not_one_stud_per_corr_m()const{return is_not_one_stud_per_corr_m_;}
   std::vector<StudRowSP266> rows()const{return rows_;}
#ifndef NDEBUG
	void print_to_logger()const;
#endif
private:
	StudSP266 const stud_;
	double const dist_e_;
	double const dist_m_;
	int const num_st_row_e_;
	int const num_st_row_m_;
	bool const is_not_one_stud_per_corr_e_;
	bool const is_not_one_stud_per_corr_m_;

	bool const is_corr_slab_;
	CorrugatedSheet const corr_sheet_;
	bool const is_wider_fl_up_;
	bool const is_sheet_orient_along_;

	std::vector<StudRowSP266> rows_;

	std::vector<StudRowSP266> set_rows(double L, double dist_e, double dist_m,
		int num_st_row_e, int num_st_row_m, bool is_not_one_stud_per_corr_e,
		bool is_not_one_stud_per_corr_m, CorrugatedSheet const & corr_sheet,
	bool is_wider_fl_up, bool is_sheet_orient_along);
	double k(double b_0, double h_n, double l,
		bool sheet_orient_along, bool is_not_one_stud_per_corr);

};
//---------------------------------------------------------------------------
#endif
