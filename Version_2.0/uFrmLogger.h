//---------------------------------------------------------------------------

#ifndef uFrmLoggerH
#define uFrmLoggerH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
#include <vector>
//---------------------------------------------------------------------------
class TFormLogger : public TForm
{
__published:	// IDE-managed Components
	TMemo *mm_logger;
	TButton *btn_clean;
	void __fastcall btn_cleanClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormLogger(TComponent* Owner);

	void clean_logger();
	void add_heading(String const & str) const;
	void add_chapter(String const & str) const;
	void print_string(String const & str)const;
	void print_double(String const & name, double val, String const & unit) const;
	void print_2_doubles(String const & name1, double val1, String const & unit1,
						 String const & name2, double val2, String const & unit2) const;
	void print_4_doubles(String const & name1, double val1, String const & unit1,
						 String const & name2, double val2, String const & unit2,
						 String const & name3, double val3, String const & unit3,
						 String const & name4, double val4, String const & unit4)const;
};
//---------------------------------------------------------------------------
extern PACKAGE TFormLogger *FormLogger;
//---------------------------------------------------------------------------
#endif
