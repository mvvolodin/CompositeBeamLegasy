//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "StudDefinitionFormUnit.h"
#include "String_doubleUnit.h"  //Функции проверяющие правильность ввода данных в поля формы
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TStudDefinitionForm *StudDefinitionForm;

//extern TStudBasicNamedList stud_named_list;

//---------------------------------------------------------------------------
__fastcall TStudDefinitionForm::TStudDefinitionForm(TComponent* Owner)
	: TForm(Owner)
{
		for (auto stud:stud_named_list) {
		cmb_bx_stud_part_number->Items->Add(stud.first);
	}

	cmb_bx_stud_part_number->ItemIndex=0;
	String name=cmb_bx_stud_part_number->Text;
	edt_stud_diameter->Text=FloatToStr(stud_named_list.find(name)->second.get_d_an());
	edt_stud_height->Text=FloatToStr(stud_named_list.find(name)->second.get_l());
	init_stud();
}

//---------------------------------------------------------------------------


void __fastcall TStudDefinitionForm::cmb_bx_stud_part_numberChange(TObject *Sender)
{
	String name=cmb_bx_stud_part_number->Text;
	//edt_stud_yield_strength->Text=FloatToStr(stud_named_list.find(name)->second.get_R_y());
	edt_stud_diameter->Text=FloatToStr(stud_named_list.find(name)->second.get_d_an());
	edt_stud_height->Text=FloatToStr(stud_named_list.find(name)->second.get_l());
}
//---------------------------------------------------------------------------
//Заполняет данные по упорам Нельсона
//---------------------------------------------------------------------------
void TStudDefinitionForm::init_stud()
{
	int rc=0;
	String name="";
	double d_an=0.0;
	double l=0.0;
	double gamma_c=0.0;
	double R_y=0.0;

	name=cmb_bx_stud_part_number->Text;
	d_an=StrToFloat(edt_stud_diameter->Text); //возращает long double 10 байт
	l=StrToFloat(edt_stud_height->Text);
	R_y=StrToFloat(edt_stud_yield_strength->Text);
	rc=String_double_plus(lbl_stud_safety_factor->Caption,
						  edt_stud_safety_factor->Text,
						  &gamma_c);
	if (rc>0) return;
	stud_=TStud(name, l, d_an,
				200, 400,
				2, 1,
				R_y, gamma_c); //NOT copy initialization. Assigment becuase stud_ was initialized before

}
//---------------------------------------------------------------------------
void __fastcall TStudDefinitionForm::bt_btn_stud_choiceClick(TObject *Sender)
{
	init_stud();
	Close();
}


