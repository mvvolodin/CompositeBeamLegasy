//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "uFrmConcrete.h"
#include "String_doubleUnit.h"
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

	for (auto grade:ConcreteSP35::grades()){
		cmb_bx_concrete_grade_list -> Items -> Add(grade.c_str());
	}
}
void __fastcall TConcreteDefinitionForm::FormShow(TObject *Sender)
{
	update_cntrls_state();
}
//---------------------------------------------------------------------------
void __fastcall TConcreteDefinitionForm::cmb_bx_concrete_grade_listChange(TObject *Sender)
{
	after_cmb_bx_conc_grade_list_change(static_cast<TComboBox*>(Sender) -> ItemIndex);
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
	after_cmb_bx_conc_grade_list_change(cntrls_state_.cmb_bx_conc_grade_index_);

	edt_density -> Text = cntrls_state_.edt_density_data_;
	edt_phi_b_cr -> Text = cntrls_state_.edt_phi_b_cr_data_;
	edt_gamma_b -> Text = cntrls_state_.edt_gamma_b_data_;
	edt_gamma_bt -> Text = cntrls_state_.edt_gamma_bt_data_;
	edt_epsilon_b_lim -> Text = cntrls_state_.edt_epsilon_b_lim_data_;

}
//---------------------------------------------------------------------------
void TConcreteDefinitionForm::after_cmb_bx_conc_grade_list_change(int index)
{
	edt_R_bn -> Text = ConcreteSP35::concrete(index).R_b_;
	edt_R_btn -> Text = ConcreteSP35::concrete(index).R_bt_;
	edt_E_b -> Text = ConcreteSP35::concrete(index).E_b_;
	edt_c_n -> Text = ConcreteSP35::concrete(index).c_n_;


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
	return ConcreteSP35::grade(cntrls_state_.cmb_bx_conc_grade_index_).c_str();
}
//---------------------------------------------------------------------------
void TConcreteDefinitionForm::set_GUI_SP35()
{
	edt_phi_b_cr -> Visible = false;
	lbl_phi_b_cr -> Visible = false;

	edt_c_n -> Visible = true;
	lbl_c_n -> Visible = true;
}
//---------------------------------------------------------------------------
void TConcreteDefinitionForm::set_GUI_SP266()
{
	edt_phi_b_cr -> Visible = true;
	lbl_phi_b_cr -> Visible = true;

	edt_c_n -> Visible = false;
	lbl_c_n -> Visible = false;
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

