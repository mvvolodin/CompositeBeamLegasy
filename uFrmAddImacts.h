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
	TLabel *lbl_concrete_internal_stress;
	TLabel *lbl_rebar_internal_stress;
	TEdit *edt_concrete_internal_stress;
	TEdit *edt_rebar_internal_stress;
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
