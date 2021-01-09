//---------------------------------------------------------------------------

#pragma hdrstop
#include <algorithm>
#include "uStudsSP266.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
StudsSP266::StudsSP266(StudSP266 stud, double L,
					   double dist_e, double dist_m,
					   unsigned int num_st_row_e, unsigned int num_st_row_m,
					   bool is_not_one_stud_per_corr_e, bool is_not_one_stud_per_corr_m,
					   bool const is_corr_slab,
					   CorrugatedSheet const & corr_sheet,
					   bool is_wider_fl_up, bool is_sheet_orient_along):
						stud_(stud), dist_e_(dist_e), dist_m_(dist_m),
						num_st_row_e_(num_st_row_e), num_st_row_m_(num_st_row_m),
						is_not_one_stud_per_corr_e_(is_not_one_stud_per_corr_e),
						is_not_one_stud_per_corr_m_(is_not_one_stud_per_corr_m),
						is_corr_slab_(is_corr_slab),
						corr_sheet_(corr_sheet), is_wider_fl_up_(is_wider_fl_up),
						is_sheet_orient_along_(is_sheet_orient_along)
{
	rows_ = set_rows(L, dist_e, dist_m, num_st_row_e, num_st_row_m,
		is_not_one_stud_per_corr_e, is_not_one_stud_per_corr_m, corr_sheet,
		is_wider_fl_up, is_sheet_orient_along);
}

std::vector<StudRowSP266> StudsSP266::set_rows(double L, double d_e, double d_m,
	int num_st_row_e, int num_st_row_m, bool is_not_one_stud_per_corr_e,
	bool is_not_one_stud_per_corr_m, CorrugatedSheet const & corr_sheet,
	bool is_wider_fl_up, bool is_sheet_orient_along)
{
	int id = 0;

	std::vector<StudRowSP266> v;

	const double L3 = L/3;

	int n_e;

	if (std::lround(L3) % std::lround(d_e))
		n_e = L3 / d_e + 1 ;
	else
		n_e = L3 / d_e;

	double const b_0 = corr_sheet.get_b_0(is_wider_fl_up) ;
	double const h_n = corr_sheet.get_height();
	double const l_1 = stud_.l_1();

	double const k_e = (is_corr_slab_)?
		k(b_0, h_n, l_1, is_sheet_orient_along, is_not_one_stud_per_corr_e):1;

	double const k_m = (is_corr_slab_)?
		k(b_0, h_n, l_1, is_sheet_orient_along, is_not_one_stud_per_corr_m):1;

	v.push_back( StudRowSP266{id++, num_st_row_e, 0, 0, 0, k_e});

	for(int i = 1; i < n_e; ++ i)
		v.push_back( StudRowSP266{id++, num_st_row_e, i * L3 / n_e,
			i * L3 / n_e - (L3 / n_e) / 2, i * L3 / n_e + (L3 / n_e) / 2, k_e});

	int n_m;

	if (std::lround(L3) % std::lround(d_m))
		n_m = L3 / d_m + 1;
	else
		n_m = L3 / d_m;

	v.push_back(StudRowSP266{id++, num_st_row_m, L3, L3 - (L3 / n_e) / 2,
		L3 + (L3 / n_m) / 2, k_m});

	for(int i = 1; i < n_m; ++ i)
		v.push_back(StudRowSP266{ id++, num_st_row_m, L3 + i * L3 / n_m,
			L3 + i * L3 / n_m - (L3 / n_m) / 2,
			L3 + i * L3 / n_m + (L3 / n_m) / 2, k_m});

	v.push_back(StudRowSP266{id++, num_st_row_m, 2 * L3, 2 * L3 - (L3 / n_m) / 2,
		2 * L3 + (L3 / n_m) / 2, k_m});

	for(int i = 1; i < n_e; ++ i)
		v.push_back( StudRowSP266{id++, num_st_row_e, 2 * L3 + i * L3 / n_e,
			2 * L3 + i * L3 / n_e - (L3 / n_e) / 2,
			2 * L3 + i * L3 / n_e + (L3 / n_e) / 2, k_e});

	v.push_back(StudRowSP266{id, num_st_row_e, L, L, L, k_e});

	return v;
}
double StudsSP266::k(double b_0, double h_n, double l_1,
	bool sheet_orient_along,  bool is_not_one_stud_per_corr)
{
	double h_an = std::min(h_n + 75, l_1);

	if(h_an == h_n)
		throw std::u16string{
			u"При равенстве высоты упора и настила, коэффициент k ф.(9.7а) или ф.(9.7б) равен нулю."};

	double n_r = (is_not_one_stud_per_corr)? 2: 1;

	if(sheet_orient_along)
	{
		if(b_0 / h_n >= 1.8)
			return 1.0;
		else
			return std::abs((0.6 * b_0 * (h_an - h_n)) / std::pow(h_n, 2));
	}
	else
	{
		if(h_n >= 85. && b_0 >= h_n)
			return 1.0;
		else
			return std::abs((0.7 * b_0 * (h_an - h_n)) / (std::pow(h_n, 2) * std::pow(n_r, 0.5)));
	}
}
#ifndef NDEBUG
void StudsSP266::print_to_logger()const
{
	FormLogger -> add_heading(u"Параметры упора Нельсона");
	FormLogger -> print_string(stud_.name().c_str());
	FormLogger -> print_double(u"d_1 = ", stud_.d_1(), u" мм");
	FormLogger -> print_double(u"l_1 = ", stud_.l_1(), u" мм");
	FormLogger -> print_double(u"R_y = ", stud_.R_y(), u" мм");
	FormLogger -> print_double(u"P_Rd = ", stud_.P_Rd(), u" Н");

	FormLogger -> add_heading(u"Параметры рядов упоров Нельсона");
	for(auto const & r:rows_)
		FormLogger -> print_6_doubles(
			u"id = ", 	  r.id_,     u"  ",
			u"st_num = ", r.st_num_, u"  ",
			u"x = " ,     r.x_,      u" мм",
			u"x_l = " ,   r.x_l_,    u" мм",
			u"x_r = " ,   r.x_r_,    u" мм",
			u"k = " ,     r.k_,      u" ");
}
#endif

