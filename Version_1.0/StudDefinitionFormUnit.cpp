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
	String name = "";
	double d_an = 0.;
	double l = 0.;
	double gamma_c = 0.;
	double R_y = 0.;

	double dist_e = 0.;
	double dist_m = 0.;
	double num_e = 0.;
	double num_m = 0.;

	name = cmb_bx_stud_part_number->Text;
	d_an = StrToFloat(edt_stud_diameter->Text);
	l = StrToFloat(edt_stud_height->Text);
	R_y = StrToFloat(edt_stud_yield_strength->Text);
	String_double_plus(lbl_stud_safety_factor->Caption,
						  edt_stud_safety_factor->Text,
						  &gamma_c);

	String_double_plus(lbl_edge_studs_dist->Caption, edt_edge_studs_dist->Text, &dist_e);
	String_double_plus(lbl_middle_studs_dist->Caption, edt_middle_studs_dist->Text, &dist_m);

	num_e = StrToFloat(cmb_bx_edge_studs_rows_num->Text);
	num_m = StrToFloat(cmb_bx_middle_studs_rows_num->Text);

	 studs_on_beam_temp_ = 	StudsOnBeam(Stud{name, d_an, l, R_y},
										dist_e, dist_m,
										num_e, num_m,
										gamma_c,
										chck_bx_more_than_one_stud_per_corrugation_edge -> Checked,
										chck_bx_more_than_one_stud_per_corrugation_middle -> Checked);
}

//---------------------------------------------------------------------------
//Присваивение значений полям формы из данных класс типа Studs
//---------------------------------------------------------------------------
void TStudDefinitionForm::set_form_controls()
{
	cmb_bx_stud_part_number -> ItemIndex =  cmb_bx_stud_part_number -> Items -> IndexOf(studs_on_beam_temp_.get_name());
	edt_stud_yield_strength -> Text = studs_on_beam_temp_.get_stud().get_R_y();
	edt_stud_diameter -> Text = studs_on_beam_temp_.get_stud().get_d_an();
	edt_stud_height -> Text = studs_on_beam_temp_.get_stud().get_l();
	edt_stud_safety_factor -> Text = studs_on_beam_temp_.get_gamma_c();
	edt_edge_studs_dist -> Text = studs_on_beam_temp_.get_dist_e();
	cmb_bx_edge_studs_rows_num -> ItemIndex =cmb_bx_edge_studs_rows_num -> Items -> IndexOf(studs_on_beam_temp_.get_num_e());
	edt_middle_studs_dist -> Text = studs_on_beam_temp_.get_dist_m();
	cmb_bx_middle_studs_rows_num -> ItemIndex =cmb_bx_middle_studs_rows_num -> Items -> IndexOf(studs_on_beam_temp_.get_num_m());
	chck_bx_more_than_one_stud_per_corrugation_edge -> Checked = studs_on_beam_temp_.get_more_than_one_stud_per_corrugation_edge();
	chck_bx_more_than_one_stud_per_corrugation_middle -> Checked = studs_on_beam_temp_.get_more_than_one_stud_per_corrugation_middle();
}

//---------------------------------------------------------------------------
//Присваивем значения полям формы из параметра функции типа Studs
//---------------------------------------------------------------------------
void TStudDefinitionForm::set_form_controls(StudsOnBeam studs_on_beam)
{
	studs_on_beam_temp_ = studs_on_beam;
	set_form_controls();
	iobserver_ -> update(this);
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
	set_form_controls();
}
//---------------------------------------------------------------------------
void __fastcall TStudDefinitionForm::btn_closeClick(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------


