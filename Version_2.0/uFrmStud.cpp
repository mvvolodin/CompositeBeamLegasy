//---------------------------------------------------------------------------
#pragma hdrstop
//---------------------------------------------------------------------------
#include <vcl.h>
#include "uFrmStud.h"
#include "String_doubleUnit.h"
#include "uStudsGOSTR55738.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TStudDefinitionForm *StudDefinitionForm;

//---------------------------------------------------------------------------
__fastcall TStudDefinitionForm::TStudDefinitionForm(TComponent* Owner)
	: TForm(Owner)
{
	for (auto const & n :StudsGOSTR55738::names()){
		cmb_bx_stud_part_number -> Items -> Add(n.c_str());
	}
}
//---------------------------------------------------------------------------
void __fastcall TStudDefinitionForm::FormShow(TObject *Sender)
{
	update_cntrls_state();
}
//---------------------------------------------------------------------------
void __fastcall TStudDefinitionForm::cmb_bx_stud_part_numberChange(TObject *Sender)
{
	if(TComboBox* cb = dynamic_cast<TComboBox*>(Sender))
		update_stud_geom_edts(cb -> ItemIndex);
}
//---------------------------------------------------------------------------
void __fastcall TStudDefinitionForm::btn_okClick(TObject *Sender)
{
	check_input();
	store_cntrls_state();
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TStudDefinitionForm::btn_cancelClick(TObject *Sender)
{
	update_cntrls_state();
}
//---------------------------------------------------------------------------
void __fastcall TStudDefinitionForm::btn_closeClick(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
void TStudDefinitionForm::check_input()
{
	int rc;
	double temp;

	rc = String_double_zero_plus(lbl_stud_yield_strength -> Caption,
								 edt_stud_yield_strength -> Text, &temp);
	if(rc > 0)throw(rc);

	rc = String_double_plus(lbl_stud_safety_factor -> Caption,
							edt_stud_safety_factor -> Text, &temp);
	if(rc > 0)throw(rc);

	rc = String_double_plus(lbl_edge_studs_dist -> Caption,
							edt_edge_studs_dist -> Text, &temp);
	if(rc > 0)throw(rc);

	rc = String_double_zero_plus(lbl_middle_studs_dist->Caption,
								 edt_middle_studs_dist->Text, &temp);
	if(rc > 0)throw(rc);

}
//---------------------------------------------------------------------------
void TStudDefinitionForm::store_cntrls_state()
{
	cntrls_state_.cmb_bx_stud_part_number_index_ = cmb_bx_stud_part_number -> ItemIndex;

	cntrls_state_.edt_stud_yield_strength_data_ = edt_stud_yield_strength -> Text.ToDouble();
	cntrls_state_.edt_stud_safety_factor_data_ = edt_stud_safety_factor -> Text.ToDouble();

	cntrls_state_.edt_edge_studs_dist_data_ = edt_edge_studs_dist -> Text.ToDouble();
	cntrls_state_.cmb_bx_edge_studs_rows_num_index_ = cmb_bx_edge_studs_rows_num -> ItemIndex;
	cntrls_state_.chck_bx_more_than_one_stud_per_corrugation_edge_data_ =
		chck_bx_more_than_one_stud_per_corrugation_edge -> Checked;

	cntrls_state_.edt_middle_studs_dist_data_ = edt_middle_studs_dist -> Text.ToDouble();
	cntrls_state_.cmb_bx_middle_studs_rows_num_index_ = cmb_bx_middle_studs_rows_num -> ItemIndex;
	cntrls_state_.chck_bx_more_than_one_stud_per_corrugation_middle_data_ =
		chck_bx_more_than_one_stud_per_corrugation_middle -> Checked;
}
//---------------------------------------------------------------------------
void TStudDefinitionForm::update_cntrls_state()
{
	int index = cntrls_state_.cmb_bx_stud_part_number_index_;
	cmb_bx_stud_part_number -> ItemIndex = index;
	update_stud_geom_edts(index);

	edt_stud_yield_strength -> Text = cntrls_state_.edt_stud_yield_strength_data_;
	edt_stud_safety_factor -> Text = cntrls_state_.edt_stud_safety_factor_data_;

	edt_edge_studs_dist -> Text = cntrls_state_.edt_edge_studs_dist_data_;
	cmb_bx_edge_studs_rows_num -> ItemIndex = cntrls_state_.cmb_bx_edge_studs_rows_num_index_;
	chck_bx_more_than_one_stud_per_corrugation_edge -> Checked =
		cntrls_state_.chck_bx_more_than_one_stud_per_corrugation_edge_data_;

	edt_middle_studs_dist -> Text = cntrls_state_.edt_middle_studs_dist_data_;
	cmb_bx_middle_studs_rows_num -> ItemIndex = cntrls_state_.cmb_bx_middle_studs_rows_num_index_;
	chck_bx_more_than_one_stud_per_corrugation_middle -> Checked =
		cntrls_state_.chck_bx_more_than_one_stud_per_corrugation_middle_data_;
}
//---------------------------------------------------------------------------
void TStudDefinitionForm::update_stud_geom_edts(int index)
{
	edt_stud_diameter -> Text = StudsGOSTR55738::d_1(cmb_bx_stud_part_number -> ItemIndex);
	edt_stud_height -> Text = StudsGOSTR55738::l_1(cmb_bx_stud_part_number -> ItemIndex);
}
//---------------------------------------------------------------------------
String TStudDefinitionForm::info()const
{
	return cmb_bx_stud_part_number -> Items -> Strings[cntrls_state_.cmb_bx_stud_part_number_index_];
}
void TStudDefinitionForm::save(ostream & os)
{
	cntrls_state_.save_cntls_state(os);
}
void TStudDefinitionForm::load(istream & is)
{
	cntrls_state_.load_cntrls_state(is);
}

