//---------------------------------------------------------------------------

#ifndef RebarDefinitionFormUnitH
#define RebarDefinitionFormUnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
//---------------------------------------------------------------------------
#include "Rebar.h"
//---------------------------------------------------------------------------

class TRebarDefinitionForm : public TForm
{
__published:	// IDE-managed Components
	TEdit *edt_safety_factor;
	TLabel *lbl_rebar_grade;
	TEdit *edt_R_s_n;
	TLabel *lbl_R_s_n;
	TComboBox *cmb_bx_rebar_grade;
	TLabel *lbl_safety_factor;
	TEdit *edt_diameter;
	TLabel *lbl_diameter;
	TBitBtn *bt_btn_Ok;
	void __fastcall cmb_bx_rebar_gradeChange(TObject *Sender);
	void __fastcall bt_btn_OkClick(TObject *Sender);
private:	// User declarations
	Rebar rebar;
	void create_rebar();//Функция которая проверяет корректность ввода и вызывает конструктор rebar
public:		// User declarations
	__fastcall TRebarDefinitionForm(TComponent* Owner);
	inline Rebar get_rebar() const {return rebar;}
};
//---------------------------------------------------------------------------
extern PACKAGE TRebarDefinitionForm *RebarDefinitionForm;
//---------------------------------------------------------------------------
#endif
