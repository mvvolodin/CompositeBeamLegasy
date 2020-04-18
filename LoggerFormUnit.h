//---------------------------------------------------------------------------

#ifndef LoggerFormUnitH
#define LoggerFormUnitH
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
private:	// User declarations
public:		// User declarations
	__fastcall TFormLogger(TComponent* Owner);
	void print_M_X(std::vector<double> M_list);
	void clean_logger();
	void add_separator(String str);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormLogger *FormLogger;
//---------------------------------------------------------------------------
#endif
