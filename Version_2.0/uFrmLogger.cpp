//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "uFrmLogger.h"
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
void TFormLogger::clean_logger()
{
	 mm_logger -> Clear();
}

void TFormLogger::add_heading(String const & str) const
{
	 mm_logger -> Lines -> Add("******************************************");
	 mm_logger -> Lines -> Add(str);
	 mm_logger -> Lines -> Add("******************************************");
}
void TFormLogger::add_chapter(String const & str) const
{
	 mm_logger -> Lines -> Add("------------------------------------------");
	 mm_logger -> Lines -> Add(str);
     mm_logger -> Lines -> Add("------------------------------------------");
}

void __fastcall TFormLogger::btn_cleanClick(TObject *Sender)
{
	mm_logger -> Clear();
}
void TFormLogger::print_string(String const & str)const
{
	mm_logger -> Lines -> Add(str);
}
void TFormLogger::print_double(String const & name, double val, String const & unit)const
{
	mm_logger -> Lines -> Add(name + val + unit);
}
void TFormLogger::print_2_doubles(String const & name1, double val1, String const & unit1,
						 String const & name2, double val2, String const & unit2)const
{
	mm_logger -> Lines -> Add(name1 + val1 + unit1 + L"    " +
		name2 + val2 + unit2);
}
void TFormLogger::print_4_doubles(String const & name1, double val1, String const & unit1,
								  String const & name2, double val2, String const & unit2,
								  String const & name3, double val3, String const & unit3,
								  String const & name4, double val4, String const & unit4)const
{
	mm_logger -> Lines -> Add(name1 + val1 + unit1 + L"    " +
							  name2 + val2 + unit2 + L"    " +
							  name3 + val3 + unit3 + L"    " +
							  name4 + val4 + unit4);
}
//---------------------------------------------------------------------------

