//---------------------------------------------------------------------------

#ifndef uFrmAddImactsH
#define uFrmAddImactsH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TFrmAddImpacts : public TForm
{
__published:	// IDE-managed Components
	TButton *btn_close;
	TLabel *lbl_sigma_bi;
	TLabel *lbl_sigma_si;
	TEdit *edt_sigma_bi;
	TEdit *edt_sigma_si;
	TButton *btn_cancel;
	TButton *btn_ok;
	TGroupBox *GroupBox1;
private:	// User declarations
public:		// User declarations
	__fastcall TFrmAddImpacts(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrmAddImpacts *FrmAddImpacts;
//---------------------------------------------------------------------------
#endif
