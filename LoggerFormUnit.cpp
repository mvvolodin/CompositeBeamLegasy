//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "LoggerFormUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormLogger *FormLogger;
//---------------------------------------------------------------------------
__fastcall TFormLogger::TFormLogger(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void TFormLogger::print_M_X(std::vector<double> M_list)
{
	for(auto M:M_list)
	{
		String str = L"M = " + FloatToStrF(M / 100000, ffFixed, 15, 2);
		mm_logger -> Lines -> Add(str);
	}
}

void TFormLogger::clean_logger()
{
	 mm_logger -> Clear();
}

void TFormLogger::add_separator(String str)
{
	 mm_logger -> Lines -> Add("******************************************");
	 mm_logger -> Lines -> Add(str);
	 mm_logger -> Lines -> Add("******************************************");
}
