//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "uFrmConcrete.h"
#include "String_doubleUnit.h"
#include "uConcreteDataSP266.h"
#include "uConcreteDataSP35.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TConcreteDefinitionForm *ConcreteDefinitionForm;
//---------------------------------------------------------------------------
__fastcall TConcreteDefinitionForm::TConcreteDefinitionForm(TComponent* Owner)
	: TForm(Owner)
{
	lbl_gamma_b->Caption=(lbl_gamma_b->Caption + u"\u03B3"+u"b");
    lbl_gamma_bt->Caption=(lbl_gamma_bt->Caption + u"\u03B3"+u"bt");
	lbl_epsilon_b_lim->Caption=(lbl_epsilon_b_lim->Caption+u"\u03B5"+u"lim");
}
//---------------------------------------------------------------------------
void __fastcall TConcreteDefinitionForm::cmb_bx_concrete_grade_listChange(TObject *Sender)
{
	switch (gui_){
		case(GUI::SP266):
			after_cmb_bx_conc_grade_list_change_SP266(static_cast<TComboBox*>(Sender) -> ItemIndex);
			break;
		case(GUI::SP35):
			after_cmb_bx_conc_grade_list_change_SP35(static_cast<TComboBox*>(Sender) -> ItemIndex);
			break;
	}
}
//---------------------------------------------------------------------------
void __fastcall TConcreteDefinitionForm::btn_OKClick(TObject *Sender)
{
	check_input();
	store_cntrls_state();
}
//---------------------------------------------------------------------------
void __fastcall TConcreteDefinitionForm::btn_cancelClick(TObject *Sender)
{
	update_cntrls_state();
}
//---------------------------------------------------------------------------
void __fastcall TConcreteDefinitionForm::btn_closeClick(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
void TConcreteDefinitionForm::store_cntrls_state()
{
	cntrls_state_.cmb_bx_conc_grade_index_= cmb_bx_concrete_grade_list -> ItemIndex;
	cntrls_state_.edt_density_data_ = edt_density -> Text.ToDouble();
	cntrls_state_.edt_phi_b_cr_data_ = edt_phi_b_cr -> Text.ToDouble();
	cntrls_state_.edt_gamma_b_data_ = edt_gamma_b -> Text.ToDouble();
	cntrls_state_.edt_gamma_bt_data_ = edt_gamma_bt -> Text.ToDouble();
	cntrls_state_.edt_epsilon_b_lim_data_ = edt_epsilon_b_lim -> Text.ToDouble();
}
//---------------------------------------------------------------------------
void TConcreteDefinitionForm::update_cntrls_state()
{
	cmb_bx_concrete_grade_list -> ItemIndex = cntrls_state_.cmb_bx_conc_grade_index_;

	switch (gui_){

	case(GUI::SP266):
		after_cmb_bx_conc_grade_list_change_SP266(cmb_bx_concrete_grade_list -> ItemIndex);
		break;
	case(GUI::SP35):
		after_cmb_bx_conc_grade_list_change_SP35(cmb_bx_concrete_grade_list -> ItemIndex);
		break;
	}

	edt_density -> Text = cntrls_state_.edt_density_data_;
	edt_phi_b_cr -> Text = cntrls_state_.edt_phi_b_cr_data_;
	edt_gamma_b -> Text = cntrls_state_.edt_gamma_b_data_;
	edt_gamma_bt -> Text = cntrls_state_.edt_gamma_bt_data_;
	edt_epsilon_b_lim -> Text = cntrls_state_.edt_epsilon_b_lim_data_;

}
//---------------------------------------------------------------------------
void TConcreteDefinitionForm::after_cmb_bx_conc_grade_list_change_SP266(unsigned int index)
{
	std::map<std::string, double> props {ConcreteDataSP266::properties(index)};

	edt_comp_strength -> Text = props.at("R_bn");
	edt_tens_strength -> Text = props.at("R_btn");
	edt_E_b -> Text = props.at("E_b");
}
void TConcreteDefinitionForm::after_cmb_bx_conc_grade_list_change_SP35(unsigned int index)
{
	std::map<std::string, double> props {ConcreteDataSP35::properties(index)};

	edt_comp_strength -> Text = props.at("R_b");
	edt_tens_strength -> Text = props.at("R_bt");
	edt_E_b -> Text = props.at("E_b");
	edt_c_n -> Text = props.at("c_n");
}
//---------------------------------------------------------------------------
void TConcreteDefinitionForm::check_input()
{
	int rc;
	double temp;

	rc = String_double_zero_plus(lbl_phi_b_cr -> Caption, edt_phi_b_cr -> Text, &temp);
	if (rc>0) throw(rc);
	rc = String_double_zero_plus(lbl_density -> Caption, edt_density -> Text, &temp);
	if (rc>0) throw(rc);
	rc = String_double_plus(lbl_gamma_b -> Caption, edt_gamma_b -> Text, &temp);
	if (rc>0) throw(rc);
	rc = String_double_plus(lbl_gamma_bt -> Caption, edt_gamma_bt -> Text, &temp);
	if (rc>0) throw(rc);
	rc = String_double_plus(lbl_epsilon_b_lim -> Caption, edt_epsilon_b_lim -> Text, &temp);
	if (rc>0) throw(rc);
}
//---------------------------------------------------------------------------
String TConcreteDefinitionForm::info()const
{
	return cmb_bx_concrete_grade_list -> Items ->
		Strings[cmb_bx_concrete_grade_list -> ItemIndex];
}
//---------------------------------------------------------------------------
void TConcreteDefinitionForm::set_GUI_SP35()
{
	edt_phi_b_cr -> Visible = false;
	lbl_phi_b_cr -> Visible = false;

	edt_c_n -> Visible = true;
	lbl_c_n -> Visible = true;

	lbl_R_bn -> Visible = false;

	lbl_R_btn -> Visible = false;

	lbl_R_b -> Visible = true;

	lbl_R_bt -> Visible = true;

	fill_cmb_bx_conc_grades_SP35();

	gui_ = GUI::SP35;
}
//---------------------------------------------------------------------------
void TConcreteDefinitionForm::set_GUI_SP266()
{
	edt_phi_b_cr -> Visible = true;
	lbl_phi_b_cr -> Visible = true;

	edt_c_n -> Visible = false;
	lbl_c_n -> Visible = false;

	lbl_R_bn -> Visible = true;

	lbl_R_btn -> Visible = true;

	lbl_R_b -> Visible = false;

	lbl_R_bt -> Visible = false;

	fill_cmb_bx_conc_grades_SP266();

	gui_ = GUI::SP266;
}
//---------------------------------------------------------------------------
void TConcreteDefinitionForm::save(ostream & os)
{
	cntrls_state_.save_cntls_state(os);
}
//---------------------------------------------------------------------------
void TConcreteDefinitionForm::load(istream & is)
{
	cntrls_state_.load_cntrls_state(is);
}
//---------------------------------------------------------------------------
void TConcreteDefinitionForm::fill_cmb_bx_conc_grades_SP266()
{
	cmb_bx_concrete_grade_list -> Clear();

	for (auto grade:ConcreteDataSP266::grades())
		cmb_bx_concrete_grade_list -> Items -> Add(grade.c_str());

	cmb_bx_concrete_grade_list -> ItemIndex = 0;

	after_cmb_bx_conc_grade_list_change_SP266(cmb_bx_concrete_grade_list -> ItemIndex);
}
//---------------------------------------------------------------------------
void TConcreteDefinitionForm::fill_cmb_bx_conc_grades_SP35()
{
	cmb_bx_concrete_grade_list -> Clear();

	for (auto grade:ConcreteDataSP35::grades())
		cmb_bx_concrete_grade_list -> Items -> Add(grade.c_str());

	cmb_bx_concrete_grade_list -> ItemIndex = 0;

	after_cmb_bx_conc_grade_list_change_SP35(cmb_bx_concrete_grade_list -> ItemIndex);
}


