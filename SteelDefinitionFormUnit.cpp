//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SteelDefinitionFormUnit.h"
#include "Steel_param_ARSS.h"
#include "String_doubleUnit.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TSteelDefinitionForm *SteelDefinitionForm;

static bool flag_close;  //для чего нужен этот флаг
static String text, header;

 extern MATER_PARAM mater_param;//Глобальная переменная для передачи параметров материала в главную форму MV 18.08.19
 extern STEEL_PARAM steel_param;//Глобальная переменная для передачи параметров материала в главную форму MV 29.09.19

//---------------------------------------------------------------------------
__fastcall TSteelDefinitionForm::TSteelDefinitionForm(TComponent* Owner)
        : TForm(Owner)
{
	   Set_index_steel(ComboBox_gost->ItemIndex);

}
//---------------------------------------------------------------
void __fastcall TSteelDefinitionForm::FormShow(TObject *Sender)
{
   ComboBox_steelChange(Sender);
}
//---------------------------------------------------------------------------
// Установить индекс стали
void __fastcall TSteelDefinitionForm::Set_index_steel(int index) {

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
//-----------------------------------------------
// Прочитать материал
void __fastcall TSteelDefinitionForm::Read_Mater(TObject *Sender)
{
	 int i, j, rc;
   //	 double matG, matE, matNu;

	// i=StrToInt(Edit_Num->Text);
	 //Material_Number = i;
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

	 strcpy(MaterProp.title, AnsiString(ComboBox_steel->Text).c_str());
	// n_material=i;


	// flag_close=true;
	return;
}
//---------------------------------------------------------------------------
void __fastcall TSteelDefinitionForm::BitBtn_OKClick(TObject *Sender)
{

	 Close();
}
//---------------------------------------------------------------------------
void __fastcall TSteelDefinitionForm::BitBtn_CancelClick(TObject *Sender)
{
   //	flag_close=true;
	Close();
}
//---------------------------------------------------------------------------
//----------------------------------------------------------------------
void __fastcall TSteelDefinitionForm::ComboBox_steelChange(
	  TObject *Sender)
{
	   int i, rc;

	  //  Получить таблицу свойств стали по марке стали
	 rc = Get_Mater_param(AnsiString(ComboBox_steel->Text).c_str(), &mater_param);
	   if (rc>0) {
          Edit_Sig_Run->Text=0;
		  Edit_Sig_Ryn->Text=0;
		  Label_thick->Caption="Ошибка при получении таблицы свойств стали "+
							   ComboBox_steel->Text;
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
	   Edit_Sig_Ryn->Text = FloatToStr(mater_param.Ryn_row[i]);
	   Edit_Sig_Run->Text = FloatToStr(mater_param.Run_row[i]);
	   if (mater_param.thick_row[mater_param.n_row]<1000)
		 Edit_max_thick->Text = FloatToStr(mater_param.thick_row[mater_param.n_row]);
       else
         Edit_max_thick->Text = ">"+FloatToStr(mater_param.thick_row[mater_param.n_row-1]);
       Label_thick->Caption="для толщины проката от "+FloatToStr(mater_param.thick_row[i])+
                            " до "+FloatToStr(mater_param.thick_row[i+1])+" мм";

	   Edit_gamma_m->Text = "1.025";
	   //--------------------------------
	   Read_Mater(Sender);  //Зачем использовать объект Sender?

}
//---------------------------------------------------------------------------

void __fastcall TSteelDefinitionForm::ComboBox_gostChange(TObject *Sender)
{
	Set_index_steel(ComboBox_gost->ItemIndex);
	ComboBox_steelChange(Sender);

}
//---------------------------------------------------------------------------

