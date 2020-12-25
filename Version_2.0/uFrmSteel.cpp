//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "uFrmSteel.h"
#include "String_doubleUnit.h"
//-----------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TDefineSteelForm *DefineSteelForm;

//---------------------------------------------------------------------------
__fastcall TDefineSteelForm::TDefineSteelForm(TComponent* Owner)
		: TForm(Owner)
{
	Caption=L"Выбор стали";
	StringGrid_Prop->ColCount = 3;
	StringGrid_Prop->Cells[0][0] = L"Толщина проката, мм";
	StringGrid_Prop->Cells[1][0] = L"  Ryn";
	StringGrid_Prop->Cells[2][0] = L"  Run";

	fill_cmb_bx_standard();

}
void __fastcall TDefineSteelForm::FormShow(TObject *Sender)
{
	update_cntrls_state();
}

//----------------------------------------------------------------------
void __fastcall TDefineSteelForm::cmb_bx_standardChange(TObject *Sender)
{
	after_cmb_bx_standard_change(static_cast<TComboBox*>(Sender) ->ItemIndex);
}

void __fastcall TDefineSteelForm::btn_okClick(TObject *Sender)
{
	check_input();
	store_cntrls_state();
	Close();
}
void __fastcall TDefineSteelForm::btn_cancelClick(TObject *Sender)
{
    update_cntrls_state();
}
void __fastcall TDefineSteelForm::btn_closeClick(TObject *Sender)
{
	Close();
}
void TDefineSteelForm::fill_cmb_bx_standard()
{
	cmb_bx_standard -> Items -> Clear();

	for(auto const & st_table: steel_tables)
		cmb_bx_standard  -> Items -> Add(st_table.title().c_str());
}
void TDefineSteelForm::fill_cmb_bx_steel_grades(int st_table_index)
{
	cmb_bx_steel_grades -> Clear();

	SteelTable const & st_table = steel_tables[st_table_index];

	for(auto const & grade: st_table.grades())
		cmb_bx_steel_grades -> Items -> Add(grade.c_str());
}
void TDefineSteelForm::after_cmb_bx_steel_grades_change(int grade_index)
{
	SteelTable const & st_table = steel_tables[cmb_bx_standard -> ItemIndex];
	std::map<std::pair<double,double>, SteelData> ranges = st_table[grade_index].ranges();

	StringGrid_Prop -> RowCount = ranges.size() + 1;

	int i = 0;

	for (auto const & range: ranges)
	{
		if(range.first.second <= 100)
			StringGrid_Prop->Cells[0][i+1] = "От " + FloatToStr(range.first.first) +
											 " до " + FloatToStr(range.first.second);
		else
			StringGrid_Prop->Cells[0][i+1] = "Cв. " + FloatToStr(range.first.second);
		StringGrid_Prop->Cells[1][i+1] = range.second.R_yn_;
		StringGrid_Prop->Cells[2][i+1] = range.second.R_un_;

		++i;
	}
}
void TDefineSteelForm::after_cmb_bx_standard_change(int st_table_index)
{
	fill_cmb_bx_steel_grades(st_table_index);
	cmb_bx_steel_grades -> ItemIndex = 0;
//	after_cmb_bx_steel_grades_change(cmb_bx_steel_grades -> ItemIndex);

}
//---------------------------------------------------------------------------
void __fastcall TDefineSteelForm::cmb_bx_steel_gradesChange(TObject *Sender)
{
	after_cmb_bx_steel_grades_change(static_cast<TComboBox*>(Sender) -> ItemIndex);
}
void TDefineSteelForm::check_input()
{
	int rc;
	double temp;

	rc = String_double_zero_plus(lbl_E -> Caption, edt_E -> Text, &temp);
	if(rc > 0)throw(rc);

	rc = String_double_plus(lbl_G -> Caption, edt_G -> Text, &temp);
	if(rc > 0)throw(rc);

	rc = String_double_plus(lbl_nu -> Caption, edt_nu -> Text, &temp);
	if(rc > 0)throw(rc);

	rc = String_double_zero_plus(lbl_dens -> Caption, edt_dens -> Text, &temp);
	if(rc > 0)throw(rc);

	rc = String_double_zero_plus(lbl_gamma_m -> Caption, edt_gamma_m -> Text, &temp);
	if(rc > 0)throw(rc);

}
void TDefineSteelForm::store_cntrls_state()
{
	cntrls_state_.cmb_bx_standard_index_ = cmb_bx_standard -> ItemIndex;
	cntrls_state_.cmb_bx_steel_grades_index_ = cmb_bx_steel_grades -> ItemIndex;
	cntrls_state_.edt_E_data_ = edt_E -> Text.ToDouble();
	cntrls_state_.edt_G_data_ = edt_G -> Text.ToDouble();
	cntrls_state_.edt_nu_data_ = edt_nu -> Text.ToDouble();
	cntrls_state_.edt_dens_data_ = edt_dens -> Text.ToDouble();
	cntrls_state_.edt_gamma_m_data_ = edt_gamma_m -> Text.ToDouble();
}
void TDefineSteelForm::update_cntrls_state()
{
	cmb_bx_standard -> ItemIndex = cntrls_state_.cmb_bx_standard_index_;
	after_cmb_bx_standard_change(cntrls_state_.cmb_bx_standard_index_);

	cmb_bx_steel_grades -> ItemIndex = cntrls_state_.cmb_bx_steel_grades_index_;
	after_cmb_bx_steel_grades_change(cntrls_state_.cmb_bx_steel_grades_index_);

	edt_E -> Text = cntrls_state_.edt_E_data_;
	edt_G -> Text = cntrls_state_.edt_G_data_;
	edt_nu -> Text = cntrls_state_.edt_nu_data_;
	edt_dens -> Text = cntrls_state_.edt_dens_data_;
	edt_gamma_m -> Text = cntrls_state_.edt_gamma_m_data_;
}
String TDefineSteelForm::info()const
{
	return cmb_bx_steel_grades -> Items -> Strings[cntrls_state_.cmb_bx_steel_grades_index_];
}
//---------------------------------------------------------------------------
void TDefineSteelForm::save(ostream & os)
{
	cntrls_state_.save_cntls_state(os);
}
//---------------------------------------------------------------------------
void TDefineSteelForm::load(istream & is)
{
	cntrls_state_.load_cntrls_state(is);
}
//---------------------------------------------------------------------------


