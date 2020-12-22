//---------------------------------------------------------------------------
#ifndef uStudsInputSP35H
#define uStudsInputSP35H
//---------------------------------------------------------------------------
#include <vector>
#include "uStudSP35.h"
#include "uStudRowInputSP35.h"
#include "uFrmsCntrlsState.h"
//---------------------------------------------------------------------------
class StudsInputSP35{
public:
	StudsInputSP35() = default;
	StudsInputSP35(TStudDefinitionFormCntrlsState const & st_frm_cntrls_state,
				   TCompositeBeamMainFormCntrlsState const & main_frm_cntrls_state,
				   TConcreteDefinitionFormCntrlsState const & con_frm_cntrls_state);
   StudSP35 stud()const{return stud_;}
   double dist_e()const{return dist_e_;}
   double dist_m()const{return dist_m_;}
   double num_st_row_e()const{return num_st_row_e_;}
   double num_st_row_m()const{return num_st_row_m_;}
   std::vector<StudRowInputSP35> rows()const{return rows_;}
private:
	static StudSP35 stud_;
	double dist_e_;
	double dist_m_;
	int num_st_row_e_;
	int num_st_row_m_;

	std::vector<StudRowInputSP35> rows_;

	std::vector<StudRowInputSP35> set_rows(double L,
										   double dist_e,
										   double dist_m,
										   int num_st_row_e,
										   int num_st_row_m);
};


//---------------------------------------------------------------------------
#endif

