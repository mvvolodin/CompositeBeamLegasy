//---------------------------------------------------------------------------
#ifndef uStudsOutputSP35H
#define uStudsOutputSP35H
//---------------------------------------------------------------------------
#include "uStudRowOutputSP35.h"
#include <vector>
#include "uStudSP35.h"
//---------------------------------------------------------------------------
class StudsOutputSP35{
public:
	static StudSP35 st_;

	StudsOutputSP35() = default;
	StudsOutputSP35(std::vector<StudRowOutputSP35> const & rows,
					std::vector<double> const & S_overline_lst_,
					std::vector<double> const & coord);
	std::vector<double> S_overline_lst()const{return S_overline_lst_;}
	std::vector<double> coord()const{return coord_;}
private:
	std::vector<StudRowOutputSP35> rows_;

	std::vector<double> S_overline_lst_;
	std::vector<double> coord_;
};
//---------------------------------------------------------------------------
#endif
