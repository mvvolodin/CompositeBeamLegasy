//---------------------------------------------------------------------------

#ifndef LoggerFormUnitH
#define LoggerFormUnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TFormLogger : public TForm
{
__published:	// IDE-managed Components
	TMemo *mmLogger;
private:	// User declarations
public:		// User declarations
	__fastcall TFormLogger(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormLogger *FormLogger;
//---------------------------------------------------------------------------
#endif
