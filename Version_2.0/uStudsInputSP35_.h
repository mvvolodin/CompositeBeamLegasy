//---------------------------------------------------------------------------
#ifndef uStudsInputSP35cppH
#define uStudsInputSP35cppH
//---------------------------------------------------------------------------
#include <vector>
#include "uStudRowInputSP35_.h"
#include "uFrmsCntrlsState.h"
//---------------------------------------------------------------------------
class StudsInputSP35{
public:
	StudsInputSP35() = default;
	StudsInputSP35(TStudDefinitionFormCntrlsState const & st_frm_cntrls_state,
			   TCompositeBeamMainFormCntrlsState const & main_frm_cntrls_state,
			   TConcreteDefinitionFormCntrlsState const & con_frm_cntrls_state);
   StudSP35 stud(){return stud_;}
private:
	static StudSP35 stud_;
	std::vector<StudRowInputSP35> rows_;

	std::vector<StudRowInputSP35> set_rows(double L,
										   double dist_e,
										   double dist_m,
										   int num_e,
										   int num_m);
};


//---------------------------------------------------------------------------
#endif

