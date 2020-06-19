//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "uFrmAddImacts.h"
#include "String_doubleUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFrmAddImpacts *FrmAddImpacts;
//---------------------------------------------------------------------------
__fastcall TFrmAddImpacts::TFrmAddImpacts(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TFrmAddImpacts::btn_okClick(TObject *Sender)
{
	 try
	 {
		check_input();
	 }
	 catch (int rc)
	 {
		return;
	 }

	Close();

}
void TFrmAddImpacts::check_input()
{
	int rc = 0;

	rc = String_double(lbl_sigma_bi->Caption, edt_sigma_bi->Text, &sigma_bi_);
	if(rc > 0)
		throw(rc);

	rc = String_double(lbl_sigma_si->Caption, edt_sigma_si->Text, &sigma_si_);
	if(rc > 0)
		throw(rc);

}
//---------------------------------------------------------------------------

void __fastcall TFrmAddImpacts::btn_closeClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------

void __fastcall TFrmAddImpacts::btn_cancelClick(TObject *Sender)
{
	update_controls();
}
//---------------------------------------------------------------------------

void __fastcall TFrmAddImpacts::FormShow(TObject *Sender)
{
	update_controls();
}
void TFrmAddImpacts::update_controls()
{
	edt_sigma_bi -> Text = sigma_bi_;
	edt_sigma_si -> Text = sigma_si_;

}


//---------------------------------------------------------------------------

