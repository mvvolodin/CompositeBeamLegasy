//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DefineSteelFormUnit.h"
#include "Steel_param_ARSS.h"
#include "String_doubleUnit.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TDefineSteelForm *DefineSteelForm;

//---------------------------------------------------------------------------
__fastcall TDefineSteelForm::TDefineSteelForm(TComponent* Owner)
        : TForm(Owner)
{
	Caption="Выбор стали";
	StringGrid_Prop->ColCount = 3;
	StringGrid_Prop->Cells[0][0] = "Толщина проката, мм";
	StringGrid_Prop->Cells[1][0] = "  Ryn";
	StringGrid_Prop->Cells[2][0] = "  Run";
	ComboBox_gost->Items->Clear();
	ComboBox_gost->Items->Add("СП 16.13330.2017, Таблица В.4, двутавры");
	ComboBox_gost->Items->Add("ГОСТ 27772-2015, Таблица 5, фасонный прокат");
	ComboBox_gost->ItemIndex = 0;

	Set_index_steel(ComboBox_gost->ItemIndex);
	ComboBox_steelChange(nullptr);
}
//---------------------------------------------------------------
// Установить индекс стали
void __fastcall TDefineSteelForm::Set_index_steel(int index) {

   int i;
   AnsiString Steel_Hot[N_STEEL_HOT] = {STEEL_HOT};
   AnsiString Steel_HotB[N_STEEL_HOTB] = {STEEL_HOTB};


   ComboBox_steel->Items->Clear();
   switch (index) {
   case 0:
	 for (i=0; i<N_STEEL_HOT; i++) {
	   ComboBox_steel->Items->Add(Steel_Hot[i]);
	 }
   break;
   case 1:
	 for (i=0; i<N_STEEL_HOTB; i++) {
	   ComboBox_steel->Items->Add(Steel_HotB[i]);
     }
   break;
   }
   ComboBox_steel->ItemIndex = 0;
}

//---------------------------------------------------------------------------
void __fastcall TDefineSteelForm::BitBtn_OKClick(TObject *Sender)
{
	 Close();
}
//----------------------------------------------------------------------
void __fastcall TDefineSteelForm::ComboBox_steelChange(
	  TObject *Sender)
{
	   int i, rc;

		MATER_PARAM mater_param;

	   AnsiString Name_prof = ComboBox_steel->Text ;

	   rc = Get_Mater_param(Name_prof.c_str(), &mater_param);
	   if (rc>0) {
		  return;
	   }

	   GroupBox_Prop->Caption = " Нормативные сопротивления стали "+ ComboBox_steel->Text + ", МПа";
	   StringGrid_Prop->RowCount = mater_param.n_row + 1;
	   for (i=0; i<mater_param.n_row; i++) {
		 if (i==0)
		   StringGrid_Prop->Cells[0][i+1] = "От " + FloatToStr(mater_param.thick_row[i]) + " до " +
												  FloatToStr(mater_param.thick_row[i+1]);
		 else {
		   if (mater_param.thick_row[i+1] < 1000)
			 StringGrid_Prop->Cells[0][i+1] = "Св. " + FloatToStr(mater_param.thick_row[i]) + " до " +
												  FloatToStr(mater_param.thick_row[i+1]);
		   else
			 StringGrid_Prop->Cells[0][i+1] = "Св. " + FloatToStr(mater_param.thick_row[i]);
		 }
		 StringGrid_Prop->Cells[1][i+1] = mater_param.Ryn_row[i];
		 StringGrid_Prop->Cells[2][i+1] = mater_param.Run_row[i];
	   }

}
//---------------------------------------------------------------------------
void __fastcall TDefineSteelForm::ComboBox_gostChange(TObject *Sender)
{
	Set_index_steel(ComboBox_gost->ItemIndex);
}
//---------------------------------------------------------------------------

void __fastcall TDefineSteelForm::BitBtn_CancelClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------

