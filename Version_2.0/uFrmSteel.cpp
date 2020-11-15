//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "uFrmSteel.h"
#include "Steel_param_ARSS.h"
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



}
void __fastcall TDefineSteelForm::FormShow(TObject *Sender)
{
	fill_cmb_bx_standard();
	cmb_bx_standard -> ItemIndex = 0;
	after_cmb_bx_standard_change(cmb_bx_standard -> ItemIndex);
}
//---------------------------------------------------------------------------
void TDefineSteelForm::set_steel()
{
	STEEL_PARAM my_steel_param;

	int rc;
	char title[8] = "";
	double E = 0.;
	double G = 0.;
	double nu = 0.;
	double dens = 0.;
	double gamma_m = 0.;
	double R_yn = 0.;
	double R_un = 0.;
	double density = 0.;

	double t_max = icomposite_beam_ -> get_t_max();
	char* str=((AnsiString)DefineSteelForm->cmb_bx_steel_grades->Text).c_str();

	bool  flag_diag_thick=false;//для чего этот флаг

	rc=Steel_param(str, t_max, &my_steel_param, flag_diag_thick);

	R_yn =  my_steel_param.Ryn;
	R_un =  my_steel_param.Run;

	strcpy(title, my_steel_param.title);

	String_double_plus(Label3->Caption, Edit_E->Text, &E);
	String_double_zero_plus(Label4->Caption, Edit_G->Text, &G);
	String_double_plus(Label5->Caption, Edit_nu->Text, &nu);
	String_double_zero_plus(Label_gamma_m->Caption, Edit_gamma_m->Text, &gamma_m);
	String_double_zero_plus(Label9 -> Caption, Edit_dens -> Text, &density);
	String standard = cmb_bx_standard -> Text;


	steel_temp_ = Steel(title, standard, E, G, nu, gamma_m,R_yn,R_un, density, t_max);

}
void TDefineSteelForm::set_form_controls()
{

	Edit_E -> Text = steel_temp_.get_E_st();
	Edit_G -> Text = steel_temp_.get_G_st();
	Edit_nu -> Text = steel_temp_.get_nu_st();
	Edit_dens -> Text = steel_temp_.get_density();
	Edit_gamma_m -> Text = steel_temp_.get_gamma_m();

	cmb_bx_standard -> ItemIndex = cmb_bx_standard -> Items -> IndexOf(steel_temp_.get_standard());
	set_steel_standard();

	cmb_bx_steel_grades -> ItemIndex = cmb_bx_steel_grades -> Items -> IndexOf(steel_temp_.get_steel_grade());


}
void TDefineSteelForm::set_form_controls(Steel steel)  //const reference
{
	steel_temp_ = steel;
	set_form_controls();
	iobserver_ -> update(this);
}
//---------------------------------------------------------------------
// Заполнить cmb_bx_steel_grades в зависимости от выбранного стандарта
//----------------------------------------------------------------------
void __fastcall TDefineSteelForm::set_steel_standard() {

   int i;
   AnsiString Steel_HotB[N_STEEL_HOTB] = {STEEL_HOTB};
   AnsiString Steel_HotB_GOST[N_STEEL_HOTB_GOST] = {STEEL_HOTB_GOST};

   cmb_bx_steel_grades -> Items -> Clear();
   switch (cmb_bx_standard -> ItemIndex) {
   case 0:
	 for (i=0; i<N_STEEL_HOTB; i++) {
	   cmb_bx_steel_grades -> Items->Add(Steel_HotB[i]);
     }
   break;
   case 1:
	 for (i=0; i<N_STEEL_HOTB_GOST; i++) {
	   cmb_bx_steel_grades -> Items -> Add(Steel_HotB_GOST[i]);
	 }
   break;
   }

   cmb_bx_steel_grades -> ItemIndex = 0;
}


//----------------------------------------------------------------------
void __fastcall TDefineSteelForm::cmb_bx_standardChange(TObject *Sender)
{
	after_cmb_bx_standard_change(static_cast<TComboBox*>(Sender) ->ItemIndex );
}
//---------------------------------------------------------------------------
// Заполнение таблицы StringGrid_Prop свойствами стали
//---------------------------------------------------------------------------

void __fastcall TDefineSteelForm::btn_okClick(TObject *Sender)
{
	set_steel();
	iobserver_ -> update(this);
	Close();
}
void __fastcall TDefineSteelForm::btn_cancelClick(TObject *Sender)
{
	set_form_controls();
}
//---------------------------------------------------------------------------
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
	after_cmb_bx_steel_grades_change(cmb_bx_steel_grades -> ItemIndex);

}
//---------------------------------------------------------------------------
void __fastcall TDefineSteelForm::cmb_bx_steel_gradesChange(TObject *Sender)
{
	after_cmb_bx_steel_grades_change(static_cast<TComboBox*>(Sender) -> ItemIndex);
}
//---------------------------------------------------------------------------

