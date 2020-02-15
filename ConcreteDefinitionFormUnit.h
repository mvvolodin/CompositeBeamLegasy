//---------------------------------------------------------------------------

#ifndef ConcreteDefinitionFormUnitH
#define ConcreteDefinitionFormUnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <map>
#include "Concrete.h"

//---------------------------------------------------------------------------
class TConcreteDefinitionForm : public TForm
{
__published:	// IDE-managed Components
	TLabel *lbl_R_bn;
	TLabel *lbl_E_b;
	TEdit *edt_R_bn;
	TEdit *edt_E_b;
	TEdit *edt_R_btn;
	TLabel *lbl_R_btn;
	TComboBox *cmb_bx_concrete_grade_list;
	TLabel *lbl_concrete_grade;
	TBitBtn *BtBtnConcreteChoice;
	TEdit *edt_gamma_b;
	TLabel *lbl_gamma_b;
	TLabel *lbl_epsilon_b_lim;
	TEdit *edt_epsilon_b_lim;
	TEdit *edt_gamma_bt;
	TLabel *lbl_gamma_bt;
	TPanel *pnl_concrete_grade;
	TLabel *lbl_phi_b_cr;
	TEdit *edt_phi_b_cr;
	void __fastcall cmb_bx_concrete_grade_listChange(TObject *Sender);
	void __fastcall BtBtnConcreteChoiceClick(TObject *Sender);
private:	// User declarations
	Concrete concrete_;
	ConcreteBasicData concrete_data_;
   typedef ConcreteBasicData::iterator ConcreteBasicDataIterator;
private:  //User declaration
    void init_concrete();

public:		// User declarations
	__fastcall TConcreteDefinitionForm(TComponent* Owner);
	inline Concrete get_concrete()const {return concrete_;}
};
//---------------------------------------------------------------------------
extern PACKAGE TConcreteDefinitionForm *ConcreteDefinitionForm;
//---------------------------------------------------------------------------
#endif
