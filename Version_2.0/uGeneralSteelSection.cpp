//---------------------------------------------------------------------------

#pragma hdrstop

#include "uGeneralSteelSection.h"
#include <iostream>
#include "Units.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//#define REPORT(var, unit) report.PasteTextPattern(FloatToStrF(var(unit), ffFixed, 15, 2),"%" #var "%")

GeneralSteelSection::GeneralSteelSection()
{
	std::cout << "ISection::ISection()" << std::endl;
}
GeneralSteelSection:: ~ GeneralSteelSection()
{
	std::cout << "ISection:: ~ ISection()" << std::endl;
}

void GeneralSteelSection::print_data_to_report(TWord_Automation & report)const
{
//	REPORT(A_s(),void);
//	REPORT(I_s());

	report.PasteTextPattern(FloatToStrF(A_st(), ffFixed, 15, 2),"%A_s%");
	report.PasteTextPattern(FloatToStrF(I_st(), ffFixed, 15, 2),"%I_s%");
	report.PasteTextPattern(FloatToStrF(W_f2_st(), ffFixed, 15, 2),"%W_s2_s%");
	report.PasteTextPattern(FloatToStrF(W_f1_st(), ffFixed, 15, 2),"%W_s1_s%");
	report.PasteTextPattern(FloatToStrF(Z_f2_st(), ffFixed, 15, 2),"%Z_s2_s%");
	report.PasteTextPattern(FloatToStrF(Z_f1_st(), ffFixed, 15, 2),"%Z_s1_s%");
   //::
}

