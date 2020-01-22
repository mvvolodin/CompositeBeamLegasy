//---------------------------------------------------------------------------

#ifndef DefineSteelFormUnitH
#define DefineSteelFormUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>

#include <Vcl.Grids.hpp>
#include "Steel_param_ARSS.h"


class TDefineSteelForm : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TLabel *Label2;
        TGroupBox *GroupBox1;
        TEdit *Edit_E;
        TEdit *Edit_G;
        TEdit *Edit_nu;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
	TGroupBox *GroupBox_Prop;
        TEdit *Edit_dens;
        TLabel *Label9;
        TBitBtn *BitBtn_Cancel;
        TBitBtn *BitBtn_OK;
        TLabel *Label_gamma_m;
        TLabel *Label11;
        TEdit *Edit_gamma_m;
        TComboBox *ComboBox_steel;
		TComboBox *ComboBox_gost;
	TStringGrid *StringGrid_Prop;

        void __fastcall BitBtn_OKClick(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall ComboBox_steelChange(TObject *Sender);
		void __fastcall ComboBox_gostChange(TObject *Sender);
		void __fastcall Read_Mater(TObject *Sender);
		// Установить список материалов, соответствующий прокату (фасон или труба)
        void __fastcall Set_Material(int index_profil, int index_GOST);
		void __fastcall BitBtn_CancelClick(TObject *Sender);
		// Установить индекс стали
		void __fastcall Set_index_steel(int index);

private:	// User declarations
   bool flag_close;
   String text, header;
   int Index_profil;  // Установленный тип профиля (0 - фасон, 1 - трубы
   AnsiString Name_prof;  // Название стали с префиксом

   AnsiString Prefix;
public:		// User declarations
		__fastcall TDefineSteelForm(TComponent* Owner);
           MATERIAL MaterProp;

};
//---------------------------------------------------------------------------
extern PACKAGE TDefineSteelForm *DefineSteelForm;
//---------------------------------------------------------------------------
#endif
