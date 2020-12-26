//---------------------------------------------------------------------------
#ifndef uStudsOutputSP35H
#define uStudsOutputSP35H
//---------------------------------------------------------------------------
#include <vector>
#include <Vcl.Grids.hpp>
#include "uStudsInputSP35.h"
#include "uStudRowOutputSP35.h"
#include "uStudSP35.h"
#include "Logger.h"
#include "uWord_Automation.h"
//---------------------------------------------------------------------------
class StudsOutputSP35{
public:
	static StudSP35 st_;

	StudsOutputSP35() = default;
	StudsOutputSP35(StudsInputSP35 const & st_input,
					std::vector<StudRowOutputSP35> const & rows,
					std::vector<double> const & S_overline_lst_,
					std::vector<double> const & coord);
	double dist_e(){return st_input_.dist_e();}
	double dist_m(){return st_input_.dist_m();}
	int num_st_row_e(){return st_input_.num_st_row_e();}
	int num_st_row_m(){return st_input_.num_st_row_m();}
	std::vector<double> S_overline_lst()const{return S_overline_lst_;}
	std::vector<double> coord()const{return coord_;}
    void print_SP266(TWord_Automation & report)const;
	void print(TWord_Automation & report)const;
	void fill_grid_SP266(TStringGrid* str_grid)const;
    void fill_grid_SP35(TStringGrid* str_grid)const;
#ifndef NDEBUG
	void print_to_logger()const;
#endif
private:
	StudsInputSP35 st_input_;

	std::vector<StudRowOutputSP35> rows_;

	std::vector<double> S_overline_lst_;
	std::vector<double> coord_;

	StudRowOutputSP35 stud_max_ratio()const;
};
//---------------------------------------------------------------------------
#endif
