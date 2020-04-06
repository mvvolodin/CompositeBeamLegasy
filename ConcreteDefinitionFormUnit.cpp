//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "ConcreteDefinitionFormUnit.h"
#include "String_doubleUnit.h"  //Функции проверяющие правильность ввода данных в поля формы
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TConcreteDefinitionForm *ConcreteDefinitionForm;
extern std::vector <ConcreteBasic> concrete_basic;

//---------------------------------------------------------------------------
__fastcall TConcreteDefinitionForm::TConcreteDefinitionForm(TComponent* Owner)
	: TForm(Owner)
{
	lbl_gamma_b->Caption=(lbl_gamma_b->Caption + u"\u03B3"+u"b");
    lbl_gamma_bt->Caption=(lbl_gamma_bt->Caption + u"\u03B3"+u"bt");
	lbl_epsilon_b_lim->Caption=(lbl_epsilon_b_lim->Caption+u"\u03B5"+u"lim");

	for(auto concrete:concrete_basic) {
		cmb_bx_concrete_grade_list->Items->Add(concrete.get_grade());
	}

}
void __fastcall TConcreteDefinitionForm::FormShow(TObject *Sender)
{
	set_form_controls();
}
//---------------------------------------------------------------------------
void __fastcall TConcreteDefinitionForm::cmb_bx_concrete_grade_listChange(TObject *Sender)
{
	String grade = cmb_bx_concrete_grade_list -> Text;
	auto it_concrete = std::find_if(concrete_basic.begin(),concrete_basic.end(),
		[grade](ConcreteBasic concrete_basic){return concrete_basic.get_grade() == grade;});
	edt_R_bn -> Text = FloatToStr(it_concrete->get_R_bn());
	edt_R_btn -> Text = FloatToStr(it_concrete->get_R_btn());
	edt_E_b -> Text = FloatToStr(it_concrete->get_E_b());
}
//---------------------------------------------------------------------------
void TConcreteDefinitionForm::set_concrete()
 {
	String grade="";
	double R_bn=0.;
	double R_btn=0.;
	double E_b=0.;
	double phi_b_cr=0.;
	double gamma_b=0.;
	double gamma_bt=0.;
	double epsilon_b_lim=0.;
	grade=cmb_bx_concrete_grade_list->Text;
	R_bn=StrToFloat(edt_R_bn->Text);
	R_btn=StrToFloat(edt_R_btn->Text);
	E_b=StrToFloat(edt_E_b->Text);
	String_double_plus(lbl_gamma_b->Caption, edt_phi_b_cr->Text, &phi_b_cr);
	String_double_plus(lbl_gamma_b->Caption, edt_gamma_b->Text, &gamma_b);
	String_double_plus(lbl_gamma_bt->Caption, edt_gamma_bt->Text, &gamma_bt);
	String_double_plus(lbl_epsilon_b_lim->Caption, edt_epsilon_b_lim->Text, &epsilon_b_lim);
	ConcreteBasic concrete_basic (grade, E_b, R_bn, R_btn);
	concrete_temp_=Concrete(concrete_basic, phi_b_cr, gamma_b, gamma_bt, epsilon_b_lim);
}
//---------------------------------------------------------------------------
//Присваивение значений полям формы из данных класс типа Concrete
//---------------------------------------------------------------------------
 void TConcreteDefinitionForm::set_form_controls()
 {
	cmb_bx_concrete_grade_list -> ItemIndex = cmb_bx_concrete_grade_list -> Items -> IndexOf(concrete_temp_.get_grade());
	edt_R_bn->Text = concrete_temp_.get_R_bn();
	edt_R_btn->Text = concrete_temp_.get_R_btn();
	edt_E_b->Text = concrete_temp_.get_E_b();

	edt_phi_b_cr->Text = concrete_temp_.get_phi_b_cr();
	edt_gamma_b->Text = concrete_temp_.get_gamma_b();
	edt_gamma_bt->Text = concrete_temp_.get_gamma_bt();
	edt_epsilon_b_lim->Text = concrete_temp_.get_epsilon_b_lim();

 }
//---------------------------------------------------------------------------
//Присваивем значения полям формы из параметра функции типа Concrete
//---------------------------------------------------------------------------
void TConcreteDefinitionForm::set_form_controls(Concrete concrete)
{
	concrete_temp_ = concrete;
	set_form_controls();
	iobserver_ -> update(this);
}
//---------------------------------------------------------------------------
void __fastcall TConcreteDefinitionForm::BtBtnConcreteChoiceClick(TObject *Sender)
{
	set_concrete();
	iobserver_ -> update(this);
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TConcreteDefinitionForm::btn_cancelClick(TObject *Sender)
{
	set_form_controls();
}
//---------------------------------------------------------------------------

void __fastcall TConcreteDefinitionForm::btn_closeClick(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

