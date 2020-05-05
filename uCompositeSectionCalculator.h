//---------------------------------------------------------------------------

#ifndef uCompositeSectionCalculatorH
#define uCompositeSectionCalculatorH

#include "uSection.h"
#include "LoggerFormUnit.h"


class CompositeSectionCalculator{
public:
	CompositeSectionCalculator();

	void calculate(Section& sect);
private:
	TFormLogger* frm_logger;

};
//---------------------------------------------------------------------------
#endif
