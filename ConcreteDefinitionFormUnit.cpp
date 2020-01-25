//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "ConcreteDefinitionFormUnit.h"
#include "String_doubleUnit.h"  //Функции проверяющие правильность ввода данных в поля формы
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TConcreteDefinitionForm *ConcreteDefinitionForm;

//---------------------------------------------------------------------------
__fastcall TConcreteDefinitionForm::TConcreteDefinitionForm(TComponent* Owner)
	: TForm(Owner)
{
	fill_concrete_data();
	lbl_gamma_b->Caption=(lbl_gamma_b->Caption + u"\u03B3"+u"b");
    lbl_gamma_bt->Caption=(lbl_gamma_bt->Caption + u"\u03B3"+u"bt");
	lbl_epsilon_b_lim->Caption=(lbl_epsilon_b_lim->Caption+u"\u03B5"+u"lim");
	cmb_bx_concrete_grade_list->Text=concrete_data_.begin()->first;
	edt_R_bn->Text=concrete_data_.begin()->second.get_R_bn();
	edt_R_btn->Text=concrete_data_.begin()->second.get_R_btn();
	edt_E_b->Text=concrete_data_.begin()->second.get_E_b();

	for (ConcreteBasicDataIterator it = concrete_data_.begin(); it != concrete_data_.end(); it++){
		cmb_bx_concrete_grade_list->Items->Add(it->first);
		} ;
		init_concrete();
}
//---------------------------------------------------------------------------
void TConcreteDefinitionForm::fill_concrete_data()
{
	ConcreteBasic B25 ("B25",25000,250,2),
				  B30 ("B30",30000,300,30),
				  B35 ("B35",35000,350,35);
	concrete_data_.insert(ConcreteBasicDataItem("B25",B25));
	concrete_data_.insert(ConcreteBasicDataItem("B30",B30));
	concrete_data_.insert(ConcreteBasicDataItem("B35",B35));
}

void __fastcall TConcreteDefinitionForm::cmb_bx_concrete_grade_listChange(TObject *Sender)
{
	String grade= cmb_bx_concrete_grade_list->Text;
	edt_R_bn->Text=FloatToStr(concrete_data_[grade].get_R_bn());
	edt_R_btn->Text=FloatToStr(concrete_data_[grade].get_R_btn());
	edt_E_b->Text=FloatToStr(concrete_data_[grade].get_E_b());
}
//---------------------------------------------------------------------------

void __fastcall TConcreteDefinitionForm::BtBtnConcreteChoiceClick(TObject *Sender)
{
	init_concrete();
	Close();
}
//---------------------------------------------------------------------------
void TConcreteDefinitionForm::init_concrete()
{   int rc=0; //rc- return code -код ошибки. Присваиваем начальное значение.
	String grade="";
	double R_bn=0.0;
	double R_btn=0.0;
	double E_b=0.0;
	double gamma_b=0.0;
	double gamma_bt=0.0;
	double epsilon_b_lim=0.0;
	grade=cmb_bx_concrete_grade_list->Text;
	R_bn=StrToFloat(edt_R_bn->Text);
	R_btn=StrToFloat(edt_R_btn->Text);
	E_b=StrToFloat(edt_E_b->Text);
	rc=String_double_plus(lbl_gamma_b->Caption, edt_gamma_b->Text, &gamma_b);
	if (rc>0) return;
	rc=String_double_plus(lbl_gamma_bt->Caption, edt_gamma_bt->Text, &gamma_bt);
	if (rc>0) return;
	rc=String_double_plus(lbl_epsilon_b_lim->Caption, edt_epsilon_b_lim->Text, &epsilon_b_lim);
	if (rc>0) return;
	ConcreteBasic concrete_basic (grade, E_b, R_bn, R_btn);
	concrete_=Concrete(concrete_basic, gamma_b, gamma_bt, epsilon_b_lim);
};

//---------------------------------------------------------------------------


//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

