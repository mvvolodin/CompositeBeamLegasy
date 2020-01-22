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

static bool flag_close;  //для чего нужен этот флаг
static String text, header;

 MATER_PARAM mater_param;//Глобальная переменная для передачи параметров материала в главную форму MV 18.08.19
 STEEL_PARAM steel_param;//Глобальная переменная для передачи параметров материала в главную форму MV 29.09.19


//---------------------------------------------------------------------------
__fastcall TDefineSteelForm::TDefineSteelForm(TComponent* Owner)
        : TForm(Owner)
{
	   ComboBox_gost->Items->Clear();
	   ComboBox_gost->Items->Add("СП 16.13330.2017, Таблица В.4, двутавры");
	   ComboBox_gost->Items->Add("ГОСТ 27772-2015, Таблица 5, фасонный прокат");
	   ComboBox_gost->ItemIndex = 0;
	   Set_index_steel(ComboBox_gost->ItemIndex);
}
//---------------------------------------------------------------
void __fastcall TDefineSteelForm::FormShow(TObject *Sender)
{
   int n_steel;

   Caption="Выбор стали";
   ComboBox_steelChange(Sender);
   StringGrid_Prop->ColCount = 3;
   StringGrid_Prop->Cells[0][0] = "Толщина проката, мм";
   StringGrid_Prop->Cells[1][0] = "  Ryn";
   StringGrid_Prop->Cells[2][0] = "  Run";
}
//---------------------------------------------------------------------------
// Установить индекс стали
void __fastcall TDefineSteelForm::Set_index_steel(int index) {

   int i;
   AnsiString Steel_Hot[N_STEEL_HOT] = {STEEL_HOT};
   AnsiString Steel_HotB[N_STEEL_HOTB] = {STEEL_HOTB};

  // index_steel = index;    // 0 - таблица B3 (основная); 1- таблица B4 (двутавры с паралл. полками)
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
// Прочитать материал
void __fastcall TDefineSteelForm::Read_Mater(TObject *Sender)
{
	 int i, j, rc;
	// double matG, matE, matNu;

	 //i = StrToInt(Edit_Num->Text);
	// Material_Number = i;
	 //---------------------------------------------------------
	 rc=String_double_plus(Label3->Caption, Edit_E->Text, &(MaterProp.E));
	 if (rc>0) return;
	 rc=String_double_zero_plus(Label4->Caption, Edit_G->Text, &(MaterProp.G));
	 if (rc>0) return;
	 rc=String_double_plus(Label5->Caption, Edit_nu->Text, &(MaterProp.nu));
	 if (rc>0) return;
	 rc=String_double_zero_plus(Label9->Caption, Edit_dens->Text, &(MaterProp.dens));
	 if (rc>0) return;
	 rc=String_double_zero_plus(Label_gamma_m->Caption, Edit_gamma_m->Text, &(MaterProp.gamma_m));
	 if (rc>0) return;
	 // Поиск толщины меньшей или равной 20 мм
	 for (j=0; j<=mater_param.n_row; j++) {
		 if (mater_param.thick_row[j] >=20 ) break;
	 }
	 if (i>mater_param.n_row)
		 j -=2;
	 else
		 j--;
	 MaterProp.Ru = mater_param.Ru_row[j];
	 MaterProp.Ry = mater_param.Ry_row[j];

	 strcpy(MaterProp.title, Name_prof.c_str());

	 return;
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

	   Name_prof = ComboBox_steel->Text + Prefix;

	   rc = Get_Mater_param(Name_prof.c_str(), &mater_param);
       if (rc>0) {
		  return;
       }
	   for (i=0; i<=mater_param.n_row; i++) {
		 if (mater_param.thick_row[i] >=20 ) break;
	   }
	   if (i>mater_param.n_row)
		 i -=2;
	   else
		 i--;
	   //---------------------------------------------------------

	   Edit_gamma_m->Text = "1.025";
	   //--------------------------------
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
	   Read_Mater(Sender);

}
//---------------------------------------------------------------------------
void __fastcall TDefineSteelForm::ComboBox_gostChange(TObject *Sender)
{
	Set_Material(Index_profil, ComboBox_gost->ItemIndex);
	ComboBox_steelChange(Sender);
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Установить список материалов, соответствующий прокату (фасон или труба)
void __fastcall TDefineSteelForm::Set_Material(int index_profil, int index_GOST)
{
   AnsiString Steel_Hot[N_STEEL_HOT] = {STEEL_HOT};
   AnsiString Steel_Hot_GOST[N_STEEL_HOT_GOST] = {STEEL_HOT_GOST};
   AnsiString Steel_HotB[N_STEEL_HOTB] = {STEEL_HOTB};
   AnsiString Steel_HotB_GOST[N_STEEL_HOTB_GOST] = {STEEL_HOTB_GOST};

	int i;
	ComboBox_gost->Items->Clear();
	ComboBox_steel->Items->Clear();
	if (index_profil == 0) { // Фасон
	   ComboBox_gost->Items->Add("СП 16.13330.2017, Таблица В.4, двутавры");
	   ComboBox_gost->Items->Add("ГОСТ 27772-2015, Таблица 5, фасонный прокат");
	   switch (index_GOST) {
	   case 0:
		 for (i=0; i<N_STEEL_HOTB; i++) {
		   ComboBox_steel->Items->Add(Steel_HotB[i]);
		 }
		 Prefix ="";
	   break;
	   case 1:
		 for (i=0; i<N_STEEL_HOTB_GOST; i++) {
		   ComboBox_steel->Items->Add(Steel_HotB_GOST[i]);
		 }
		 Prefix ="BG";
	   break;
	   }
	}
	else {
	   ComboBox_gost->Items->Add("СП 16.13330.2017, Таблица В.3, трубы");
	   ComboBox_gost->Items->Add("ГОСТ 27772-2015, Таблица 4, универсальный прокат");
	   switch (index_GOST) {
	   case 0:
		 for (i=0; i<N_STEEL_HOT; i++) {
		   ComboBox_steel->Items->Add(Steel_Hot[i]);
		 }
		 Prefix ="";
	   break;
	   case 1:
		 for (i=0; i<N_STEEL_HOT_GOST; i++) {
		   ComboBox_steel->Items->Add(Steel_Hot_GOST[i]);
		 }
		 Prefix ="G";
	   break;
	   }
	}
	ComboBox_gost->ItemIndex = index_GOST;
	ComboBox_steel->ItemIndex = 1;
	ComboBox_steel->ItemIndex = 0;
	Index_profil = index_profil;
	//ComboBox_steelChange(Sender);
}

void __fastcall TDefineSteelForm::BitBtn_CancelClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------

