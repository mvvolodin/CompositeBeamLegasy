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
void __fastcall TRebarDefinitionForm::FormShow(TObject *Sender)
{
	set_form_controls();
}
//---------------------------------------------------------------------------
void __fastcall TRebarDefinitionForm::cmb_bx_rebar_gradeChange(TObject *Sender)
{
	String grade = cmb_bx_rebar_grade->Text;
	edt_R_s_n -> Text=FloatToStr(rebar_named_list.find(grade) -> second.get_R_sn());
}
//---------------------------------------------------------------------------
//Присваивение значений элементам управления из поля класса типа Rebar
//---------------------------------------------------------------------------
void TRebarDefinitionForm::set_form_controls()
{
	edt_diameter -> Text = rebar_temp_.get_diameter();
	edt_R_s_n -> Text = rebar_temp_.get_R_sn();
	edt_E_s -> Text = rebar_temp_.get_E_s();
	edt_b -> Text = rebar_temp_.get_b_s();
	edt_a_u -> Text = rebar_temp_.get_a_u();
	edt_a_l -> Text = rebar_temp_.get_a_l();
	edt_safety_factor -> Text = rebar_temp_.get_gamma_s_();
	cmb_bx_rebar_grade -> ItemIndex = cmb_bx_rebar_grade -> Items -> IndexOf(rebar_temp_.get_grade());

}

void TRebarDefinitionForm::set_rebar()
{
	double diameter = 0.;
	double E_s = 0.;
	double b = 0.;
	double a_u = 0.;
	double a_l = 0.;
	double safety_factor = 0.;

	String_double_zero_plus(lbl_diameter->Caption, edt_diameter->Text, &diameter);
	String_double_plus(lbl_E_s->Caption, edt_E_s->Text, &E_s);
	String_double_zero_plus(lbl_b->Caption, edt_b->Text, &b);
	String_double_zero_plus(lbl_a_u->Caption, edt_a_u->Text, &a_u);
	String_double_zero_plus(lbl_a_l->Caption, edt_a_l->Text, &a_l);
	String_double_plus(lbl_safety_factor->Caption, edt_safety_factor->Text, &safety_factor);
	String grade = cmb_bx_rebar_grade->Text;
	double R_s = StrToFloat(edt_R_s_n->Text);
	rebar_temp_ = Rebar(grade, R_s, E_s, diameter, b, a_u, a_l, safety_factor);
}
//---------------------------------------------------------------------------


void TRebarDefinitionForm::register_observer(IObserver_* iobserver)
{
	iobserver_ = iobserver;
}


//---------------------------------------------------------------------------

String TRebarDefinitionForm::get_information()const
{
   return rebar_temp_.get_grade();

}
Publisher_ID TRebarDefinitionForm::get_id()const
{
   return id_;
}
//---------------------------------------------------------------------------
//Присваивем значения полям формы из параметра функции типа Rebar
//---------------------------------------------------------------------------
void TRebarDefinitionForm::set_form_controls(Rebar rebar)
{
	rebar_temp_ = rebar;
	set_form_controls();
	iobserver_ -> update(this);
}
//---------------------------------------------------------------------------

void __fastcall TRebarDefinitionForm::bt_btn_OkClick(TObject *Sender)
{
	set_rebar();
	iobserver_ -> update(this);
	Close();
}
void __fastcall TRebarDefinitionForm::bt_btn_cancelClick(TObject *Sender)
{
	set_form_controls();
}
void __fastcall TRebarDefinitionForm::btn_closeClick(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------


