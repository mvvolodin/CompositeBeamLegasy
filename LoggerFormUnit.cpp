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
void TFormLogger::print_stud_coordinates(double id, double x, double x_l, double x_r)
{
	String str = L"id = " + FloatToStrF(id, ffFixed, 15, 0) + "; " +
				 L"x = " + FloatToStrF(x, ffFixed, 15, 0) + "; " +
				 L"x_l = " + FloatToStrF(x_l, ffFixed, 15, 0) + "; " +
				 L"x_r = " + FloatToStrF(x_r, ffFixed, 15, 0) + "; ";

	mm_logger -> Lines -> Add(str);

}
void TFormLogger::print_stud_shear_force(double id, double S)
{
	String str = L"id = " + FloatToStrF(id, ffFixed, 15, 0) + "; " +
				 L"S = " + FloatToStrF(S, ffFixed, 15, 0);

	mm_logger -> Lines -> Add(str);
}
void TFormLogger::print_ratio(double id, double ratio)
{
	String str = L"id = " + FloatToStrF(id, ffFixed, 15, 0) + "; " +
				 L"ÊÈ = " + FloatToStrF(ratio, ffFixed, 15, 2);

	mm_logger -> Lines -> Add(str);

}
