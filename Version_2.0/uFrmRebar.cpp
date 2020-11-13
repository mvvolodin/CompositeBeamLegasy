//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "uFrmRebar.h"
#include "String_doubleUnit.h" //Функции проверки
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

extern 	RebarNamedList rebar_named_list;

TRebarDefinitionForm *RebarDefinitionForm;

//---------------------------------------------------------------------------
__fastcall TRebarDefinitionForm::TRebarDefinitionForm(TComponent* Owner)
	: TForm(Owner)
{
	for (auto grade:RebarsSP35::grades()){
		cmb_bx_rebar_grade -> Items -> Add(grade.c_str());
	}
}
//---------------------------------------------------------------------------
void __fastcall TRebarDefinitionForm::FormShow(TObject *Sender)
{
	update_cntrls_state();
}
//---------------------------------------------------------------------------
void __fastcall TRebarDefinitionForm::cmb_bx_rebar_gradeChange(TObject *Sender)
{
	update_edt_R_s_n(static_cast<TComboBox*>(Sender) -> ItemIndex);
}
void TRebarDefinitionForm::update_edt_R_s_n(int cmb_bx_rebar_grade_index)
{
	edt_R_s_n -> Text = RebarsSP35::rebar(cmb_bx_rebar_grade_index).R_sn_;
}

//---------------------------------------------------------------------------
void __fastcall TRebarDefinitionForm::bt_btn_OkClick(TObject *Sender)
{
	check_input();
	store_cntrls_state();
	Close();
}
void __fastcall TRebarDefinitionForm::bt_btn_cancelClick(TObject *Sender)
{
	update_cntrls_state();
}
void __fastcall TRebarDefinitionForm::btn_closeClick(TObject *Sender)
{
	Close();
}
void TRebarDefinitionForm::check_input()
{
	int rc;
	double temp;

	rc = String_double_zero_plus(lbl_diameter -> Caption, edt_diameter -> Text, &temp);
	if(rc > 0)throw(rc);

	rc = String_double_plus(lbl_E_s -> Caption, edt_E_s -> Text, &temp);
	if(rc > 0)throw(rc);

	rc = String_double_plus(lbl_E_s -> Caption, edt_safety_factor -> Text, &temp);
	if(rc > 0)throw(rc);

	rc = String_double_zero_plus(lbl_a_u->Caption, edt_a_u->Text, &temp);
	if(rc > 0)throw(rc);

	rc = String_double_zero_plus(lbl_a_l->Caption, edt_a_l->Text, &temp);
	if(rc > 0)throw(rc);

	rc = String_double_zero_plus(lbl_b->Caption, edt_b->Text, &temp);
	if(rc > 0)throw(rc);

	rc = String_double_zero_plus(lbl_b->Caption, edt_b->Text, &temp);
	if(rc > 0)throw(rc);
}
void TRebarDefinitionForm::store_cntrls_state()
{
	cntrls_state_.cmb_bx_rebar_grade_ = cmb_bx_rebar_grade -> ItemIndex;
	cntrls_state_.edt_E_s_ = edt_E_s -> Text.ToDouble();
	cntrls_state_.edt_safety_factor_ = edt_safety_factor -> Text.ToDouble();
	cntrls_state_.edt_diameter_ = edt_diameter -> Text.ToDouble();
	cntrls_state_.edt_b_ = edt_b -> Text.ToDouble();
	cntrls_state_.edt_a_u_ = edt_a_u -> Text.ToDouble();
	cntrls_state_.edt_a_l_ = edt_a_l -> Text.ToDouble();
}
void TRebarDefinitionForm::update_cntrls_state()
{
	cmb_bx_rebar_grade -> ItemIndex = cntrls_state_.cmb_bx_rebar_grade_;
	update_edt_R_s_n(cntrls_state_.cmb_bx_rebar_grade_);

	edt_E_s -> Text = cntrls_state_.edt_E_s_;
	edt_safety_factor -> Text = cntrls_state_.edt_safety_factor_;
	edt_diameter -> Text = cntrls_state_.edt_diameter_;
	edt_b -> Text = cntrls_state_.edt_b_;
	edt_a_u -> Text = cntrls_state_.edt_a_u_;
	edt_a_l -> Text = cntrls_state_.edt_a_l_;
}
String TRebarDefinitionForm::rebar_name()const
{
	return cmb_bx_rebar_grade -> Items -> Strings[cntrls_state_.cmb_bx_rebar_grade_];
}
void TRebarDefinitionForm::save(ostream & os)
{
	cntrls_state_.save_cntls_state(os);
}
//---------------------------------------------------------------------------

void TRebarDefinitionForm::load(istream & is)
{
	cntrls_state_.load_cntrls_state(is);
}


//---------------------------------------------------------------------------


