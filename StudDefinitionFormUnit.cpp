//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "StudDefinitionFormUnit.h"
#include "String_doubleUnit.h"  //Функции проверяющие правильность ввода данных в поля формы
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TStudDefinitionForm *StudDefinitionForm;
//---------------------------------------------------------------------------
//Заполняет данные по упорам Нельсона
//---------------------------------------------------------------------------
void TStudDefinitionForm::fill_stud_data()
{
	TStud SD_16_75=TStud("SD-16-75",16,75, 1.2, 320);
	TStud SD_24_100= TStud("SD-24-100",24,100, 1.2, 380);
	stud_data.insert(TStudDataItem("SD-16-75",SD_16_75));
	stud_data.insert(TStudDataItem("SD-24-100",SD_24_100));
}
//---------------------------------------------------------------------------
__fastcall TStudDefinitionForm::TStudDefinitionForm(TComponent* Owner)
	: TForm(Owner)
{
	fill_stud_data();
	cmb_bx_stud_part_number->Text=stud_data.begin()->first;
	edt_stud_yield_strength->Text=stud_data.begin()->second.get_R_y();
	edt_stud_diameter->Text=stud_data.begin()->second.get_d_an();
	edt_stud_height->Text=stud_data.begin()->second.get_l();
	for (stud_data_iterator it = stud_data.begin(); it != stud_data.end(); it++){
		cmb_bx_stud_part_number->Items->Add(it->first);
		} ;
	init_stud();
}
//---------------------------------------------------------------------------
void __fastcall TStudDefinitionForm::bt_btn_stud_choiceClick(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------


void __fastcall TStudDefinitionForm::cmb_bx_stud_part_numberChange(TObject *Sender)
{
	String name=cmb_bx_stud_part_number->Text;
	edt_stud_yield_strength->Text=FloatToStr(stud_data[name].get_R_y());
	edt_stud_diameter->Text=FloatToStr(stud_data[name].get_l());
	edt_stud_height->Text=FloatToStr(stud_data[name].get_d_an());
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
	stud_=TStud(name, l, d_an, gamma_c, R_y); //NOT copy initialization. Assigment becuase stud_ was initialized before
}

void __fastcall TStudDefinitionForm::FormClose(TObject *Sender, TCloseAction &Action)

{
    init_stud();//При закрытии формы происходит присвоение полю stud_ значений контролов
}
//---------------------------------------------------------------------------

