//---------------------------------------------------------------------------

#ifndef SteelDefinitionFormUnitH
#define SteelDefinitionFormUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------

	typedef struct _material  /* элемент массива данных материала */
	   {
		char   title[12];
		double E;          /* модуль Юнга */
		double G;          /* модуль сдвига */
		double nu;         /* коэффициент Пуассона */
		double Ry;         /* Расчетное допускаемое напряжение (предел текучески) для минимальной толщиы */
		double Ru;         /* Расчетное временное сопротивление разрыву */
		double gamma_m;    /* коэффициент надежности по материалу */
		double dens;       /* плотность */
		}  MATERIAL;



class TSteelDefinitionForm : public TForm
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
        TGroupBox *GroupBox2;
        TEdit *Edit_dens;
        TLabel *Label9;
        TBitBtn *BitBtn_Cancel;
        TBitBtn *BitBtn_OK;
	TLabel *Label_Run;
        TEdit *Edit_Sig_Run;
        TLabel *Label_gamma_m;
        TLabel *Label11;
        TEdit *Edit_gamma_m;
        TComboBox *ComboBox_steel;
		TLabel *Label_thick;
        TLabel *Label6;
        TEdit *Edit_max_thick;
        TLabel *Label_Ryn;
        TEdit *Edit_Sig_Ryn;
		TComboBox *ComboBox_gost;

        void __fastcall BitBtn_OKClick(TObject *Sender);
        void __fastcall BitBtn_CancelClick(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall ComboBox_steelChange(TObject *Sender);
        void __fastcall Set_index_steel(int index);
		void __fastcall ComboBox_gostChange(TObject *Sender);
		void __fastcall Read_Mater(TObject *Sender);

private:	// User declarations
public:		// User declarations
		__fastcall TSteelDefinitionForm(TComponent* Owner);

	   MATERIAL MaterProp;

};
//---------------------------------------------------------------------------
extern PACKAGE TSteelDefinitionForm *SteelDefinitionForm;
//---------------------------------------------------------------------------
#endif
