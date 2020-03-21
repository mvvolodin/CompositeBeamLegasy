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

}
void __fastcall TStudDefinitionForm::FormShow(TObject *Sender)
{
	set_form_controls();
}
//---------------------------------------------------------------------------


void __fastcall TStudDefinitionForm::cmb_bx_stud_part_numberChange(TObject *Sender)
{
	String name=cmb_bx_stud_part_number->Text;
	edt_stud_diameter->Text=FloatToStr(stud_named_list.find(name)->second.get_d_an());
	edt_stud_height->Text=FloatToStr(stud_named_list.find(name)->second.get_l());
}
//---------------------------------------------------------------------------
//Читает данные из полей формы, проверяет правильность данных, создаёт объект
// типа Studs и присваивает его полю формы studs_
//---------------------------------------------------------------------------
void TStudDefinitionForm::set_studs()
{
	String name="";
	double d_an=0.;
	double l=0.;
	double gamma_c=0.;
	double R_y=0.;

	double edge_studs_dist=0.;
	double middle_studs_dist=0.;
	double edge_studs_rows_num=0.;
	double middle_studs_rows_num=0.;

	name=cmb_bx_stud_part_number->Text;
	d_an=StrToFloat(edt_stud_diameter->Text);
	l=StrToFloat(edt_stud_height->Text);
	R_y=StrToFloat(edt_stud_yield_strength->Text);
	String_double_plus(lbl_stud_safety_factor->Caption,
						  edt_stud_safety_factor->Text,
						  &gamma_c);

	String_double_plus(lbl_edge_studs_dist->Caption, edt_edge_studs_dist->Text, &edge_studs_dist);
	String_double_plus(lbl_middle_studs_dist->Caption, edt_middle_studs_dist->Text, &middle_studs_dist);

	edge_studs_rows_num=StrToFloat(cmb_bx_edge_studs_rows_num->Text);
	middle_studs_rows_num=StrToFloat(cmb_bx_middle_studs_rows_num->Text);

	 studs_temp_ = Studs(name, d_an, l,
				edge_studs_dist, middle_studs_dist,
				edge_studs_rows_num, middle_studs_rows_num,
				R_y, gamma_c);
}
//---------------------------------------------------------------------------
void __fastcall TStudDefinitionForm::btn_okClick(TObject *Sender)
{
	set_studs();
	iobserver_ -> update(this);
	Close();
}

//---------------------------------------------------------------------------
void __fastcall TStudDefinitionForm::btn_cancelClick(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
//Присваивение значений полям формы из данных класс типа Studs
//---------------------------------------------------------------------------
void TStudDefinitionForm::set_form_controls()
{
	cmb_bx_stud_part_number -> Text = studs_temp_.get_name();
	edt_stud_yield_strength -> Text = studs_temp_.get_R_y();
	edt_stud_diameter -> Text = studs_temp_.get_d_an();
	edt_stud_height -> Text = studs_temp_.get_l();
	edt_stud_safety_factor -> Text = studs_temp_.get_gamma_c();
	edt_edge_studs_dist -> Text = studs_temp_.get_edge_rows_dist();
	cmb_bx_edge_studs_rows_num -> Text = studs_temp_.get_edge_rows_num();
	edt_middle_studs_dist -> Text = studs_temp_.get_middle_rows_dist();
	cmb_bx_middle_studs_rows_num -> Text = studs_temp_.get_middle_rows_num();

}

//---------------------------------------------------------------------------
//Присваивем значения полям формы из параметра функции типа Studs
//---------------------------------------------------------------------------
void TStudDefinitionForm::set_form_controls(Studs studs)
{
	studs_temp_ = studs;
	set_form_controls();
	iobserver_ -> update(this);
}

