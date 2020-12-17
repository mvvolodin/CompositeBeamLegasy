//---------------------------------------------------------------------------

#ifndef uStudRowCalculatorSP35H
#define uStudRowCalculatorSP35H

#include "uLongShearForcesCalculator.h"
#include "uStudSP35Output.h"
#include "uStudRowSP35Input.h"

class StudRowCalculatorSP35{
public:
	StudRowCalculatorSP35(LongShearForcesCalculator const & calc);
	StudSP35Output run(StudRowSP35Input const & sr)const;

private:
	LongShearForcesCalculator const & calc_;

};
//---------------------------------------------------------------------------
#endif
