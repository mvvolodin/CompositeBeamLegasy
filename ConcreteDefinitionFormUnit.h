//---------------------------------------------------------------------------

#ifndef ConcreteDefinitionFormUnitH
#define ConcreteDefinitionFormUnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <map>
#include "Concrete.h"

//---------------------------------------------------------------------------
class TConcreteDefinitionForm : public TForm
{
__published:	// IDE-managed Components
	TLabel *lbl_R_b;
	TLabel *lbl_E_b;
	TEdit *edt_R_b;
	TEdit *edt_E_b;
	TEdit *edt_R_bt;
	TLabel *lbl_R_bt;
	TComboBox *cmb_bx_concrete_grade_list;
	TLabel *Label4;
	TBitBtn *BtBtnConcreteChoice;
	TEdit *edt_gamma_b;
	TLabel *lbl_gamma_b;
	TLabel *lbl_epsilon_b_lim;
	TEdit *edt_epsilon_b_lim;
	void __fastcall cmb_bx_concrete_grade_listChange(TObject *Sender);
	void __fastcall BtBtnConcreteChoiceClick(TObject *Sender);
private:	// User declarations
	Concrete concrete_;
	ConcreteBasicData concrete_data_;
   typedef ConcreteBasicData::iterator ConcreteBasicDataIterator;
private:  //User declaration
	void fill_concrete_data();
    void init_concrete();

public:		// User declarations
	__fastcall TConcreteDefinitionForm(TComponent* Owner);
	inline Concrete get_concrete()const {return concrete_;}
};
//---------------------------------------------------------------------------
extern PACKAGE TConcreteDefinitionForm *ConcreteDefinitionForm;
//---------------------------------------------------------------------------
#endif
