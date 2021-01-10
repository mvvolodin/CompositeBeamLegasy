//---------------------------------------------------------------------------
#pragma hdrstop
//---------------------------------------------------------------------------
#include "uStudsSP35.h"
#include <cmath>
#include "uStudsGOSTR55738.h"
#include "uConcrete.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

StudsSP35::StudsSP35(StudSP35 const & stud, double L,
	double dist_e, double dist_m, unsigned int num_st_row_e, unsigned int num_st_row_m):
		stud_(stud), dist_e_(dist_e), dist_m_(dist_m), num_st_row_e_(num_st_row_e),
		num_st_row_m_(num_st_row_m)
{
	rows_ = set_rows(L, dist_e, dist_m, num_st_row_e, num_st_row_m);
}

std::vector<StudRowSP35> StudsSP35::set_rows(double L, double d_e,
	double d_m, int num_st_row_e, int num_st_row_m)
{
	int id = 0;

	std::vector<StudRowSP35> v;

	const double L3 = L/3;

	int n_e;

	if (std::lround(L3) % std::lround(d_e))
		n_e = L3 / d_e + 1 ;
	else
		n_e = L3 / d_e;

	v.push_back(StudRowSP35{id++, num_st_row_e, 0, 0, 0});

	for(int i = 1; i < n_e; ++ i)
		v.push_back(StudRowSP35{id++, num_st_row_e, i * L3 / n_e,
			i * L3 / n_e - (L3 / n_e) / 2, i * L3 / n_e + (L3 / n_e) / 2});

	int n_m;

	if (std::lround(L3) % std::lround(d_m))
		n_m = L3 / d_m + 1;
	else
		n_m = L3 / d_m;

	v.push_back(StudRowSP35{id++, num_st_row_m, L3, L3 - (L3 / n_e) / 2,
		L3 + (L3 / n_m) / 2});

	for(int i = 1; i < n_m; ++ i)
		v.push_back(StudRowSP35{id++, num_st_row_m, L3 + i * L3 / n_m,
			L3 + i * L3 / n_m - (L3 / n_m) / 2, L3 + i * L3 / n_m + (L3 / n_m) / 2});

	v.push_back(StudRowSP35{id++, num_st_row_m, 2 * L3, 2 * L3 - (L3 / n_m) / 2,
		2 * L3 + (L3 / n_m) / 2});

	for(int i = 1; i < n_e; ++ i)
		v.push_back(StudRowSP35{id++, num_st_row_e, 2 * L3 + i * L3 / n_e,
			2 * L3 + i * L3 / n_e - (L3 / n_e) / 2,
			2 * L3 + i * L3 / n_e + (L3 / n_e) / 2});

	v.push_back(StudRowSP35{id, num_st_row_e, L, L, L});

	return v;
}
#ifdef DEBUG_STUDS_SP35
void StudsSP35::log()const
{
	FormLogger -> add_heading(u"Параметры упора Нельсона");

	FormLogger -> print({
		stud_.name().c_str(),
		"d_1 = " + FloatToStr(stud_.d_1()) + " мм",
		"l_1 = " + FloatToStr(stud_.l_1()) + " мм",
		"R_y = " + FloatToStr(stud_.R_y()) + " мм",
		"P_Rd = " + FloatToStr(stud_.P_Rd()) + " H",
	});

	FormLogger -> add_heading(u"Параметры рядов упоров Нельсона");

	for(auto const & r:rows_)
		FormLogger -> print({
			u"id = " + FloatToStr(r.id_),
			u"st_num = " + FloatToStr(r.st_num_),
			u"x = " + FloatToStr(r.x_) + " мм",
			u"x_l = " + FloatToStr(r.x_l_) + " мм",
			u"x_r = " + FloatToStr(r.x_r_) + " мм",
		});
}
#endif





