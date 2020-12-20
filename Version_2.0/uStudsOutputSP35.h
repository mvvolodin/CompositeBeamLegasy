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
	StudsOutputSP35() = default;

private:
	static StudSP35 stud_;
	std::vector<StudRowOutputSP35> rows_;


};
//---------------------------------------------------------------------------
#endif
