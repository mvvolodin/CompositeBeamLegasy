//---------------------------------------------------------------------------
#ifndef uStudsSP35H
#define uStudsSP35H
//---------------------------------------------------------------------------
#include <vector>
#include "uStudSP35.h"
#include "uStudRowSP35.h"
#include "uFrmsCntrlsState.h"
#include "Logger.h"
//---------------------------------------------------------------------------
class StudsSP35{
public:
	StudsSP35() = default;
	StudsSP35(StudSP35 const & stud, double L, double dist_e, double dist_m,
		unsigned int num_st_row_e, unsigned int num_st_row_m);
   StudSP35 stud()const{return stud_;}
   double dist_e()const{return dist_e_;}
   double dist_m()const{return dist_m_;}
   double num_st_row_e()const{return num_st_row_e_;}
   double num_st_row_m()const{return num_st_row_m_;}
   std::vector<StudRowSP35> rows()const{return rows_;}
	#ifdef DEBUG_STUDS_SP35
	void log()const;
	#endif
private:
	StudSP35 const stud_;
	double const dist_e_;
	double const dist_m_;
	unsigned int const num_st_row_e_;
	unsigned int const num_st_row_m_;

	std::vector<StudRowSP35> rows_;

	std::vector<StudRowSP35> set_rows(double L,
										   double dist_e,
										   double dist_m,
										   int num_st_row_e,
										   int num_st_row_m);
};


//---------------------------------------------------------------------------
#endif

