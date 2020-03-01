//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "RebarDefinitionFormUnit.h"
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
	for (auto rebar:rebar_named_list) {
		cmb_bx_rebar_grade->Items->Add(rebar.first);
	}
}
//---------------------------------------------------------------------------
void __fastcall TRebarDefinitionForm::cmb_bx_rebar_gradeChange(TObject *Sender)
{
	String grade=cmb_bx_rebar_grade->Text;
	edt_R_s_n->Text=FloatToStr(rebar_named_list.find(grade)->second.get_R_sn());
}
//---------------------------------------------------------------------------

void TRebarDefinitionForm::set_rebar()
{
	double diameter = 0.;
	double b = 0.;
	double a_u = 0.;
	double a_l = 0.;
	double safety_factor = 0.;

	String_double_plus(lbl_diameter->Caption, edt_diameter->Text, &diameter);
	String_double_plus(lbl_diameter->Caption, edt_b->Text, &b);
	String_double_plus(lbl_diameter->Caption, edt_a_u->Text, &a_u);
	String_double_plus(lbl_diameter->Caption, edt_a_l->Text, &a_l);
	String_double_plus(lbl_safety_factor->Caption, edt_safety_factor->Text, &safety_factor);
	String grade = cmb_bx_rebar_grade->Text;
	double R_s = StrToFloat(edt_R_s_n->Text);
	rebar_ = Rebar(grade, R_s, diameter, b, a_u, a_l, safety_factor);
}
//---------------------------------------------------------------------------

void __fastcall TRebarDefinitionForm::bt_btn_OkClick(TObject *Sender)
{
	set_rebar();
	iobserver_ -> update(this);
	Close();
}
//---------------------------------------------------------------------------
void TRebarDefinitionForm::init_form_controls()
{
	cmb_bx_rebar_grade -> Text = rebar_.get_grade();
	edt_R_s_n -> Text = rebar_.get_R_sn();
	edt_diameter -> Text = rebar_.get_diameter();
	edt_b -> Text = rebar_.get_b();
	edt_a_u -> Text = rebar_.get_a_u();
	edt_a_l -> Text = rebar_.get_a_l();
	edt_safety_factor -> Text = rebar_.get_gamma_s_();
}
void TRebarDefinitionForm::register_observer(IObserver_* iobserver)
{
	iobserver_ = iobserver;
}


void __fastcall TRebarDefinitionForm::bt_btn_cancelClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------

void __fastcall TRebarDefinitionForm::FormShow(TObject *Sender)
{
	init_form_controls();
}
String TRebarDefinitionForm::get_information()const
{
   return rebar_.get_grade();

}
Publisher_ID TRebarDefinitionForm::get_id()const
{
   return id_;
}
//---------------------------------------------------------------------------

