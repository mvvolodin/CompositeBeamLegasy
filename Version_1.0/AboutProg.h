//---------------------------------------------------------------------------

#ifndef AboutProgH
#define AboutProgH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TAboutProgForm : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label_Prog;
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TAboutProgForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TAboutProgForm *AboutProgForm;
//---------------------------------------------------------------------------
#endif
