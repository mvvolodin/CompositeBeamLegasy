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
//---------------------------------------------------------------------------
#include "uConcrete.h"
#include "ObserverPatternInterfaces.h"
//---------------------------------------------------------------------------
class TConcreteDefinitionForm : public TForm, public IPublisher
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
	TButton *btn_cancel;
	TButton *btn_close;
	TLabel *lbl_density;
	TEdit *edt_density;
	TGroupBox *grp_bx_characteristics;
	void __fastcall cmb_bx_concrete_grade_listChange(TObject *Sender);
	void __fastcall BtBtnConcreteChoiceClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall btn_cancelClick(TObject *Sender);
	void __fastcall btn_closeClick(TObject *Sender);
private:	// User declarations
	static const Publisher_ID id_ = Publisher_ID::CONCRETE_FORM;
	IObserver_* iobserver_;
	Concrete concrete_temp_;
	ConcreteBasicData concrete_data_;
   typedef ConcreteBasicData::iterator ConcreteBasicDataIterator;
private:  //User declaration
	void set_form_controls();
	void set_concrete();
	virtual String get_information()const override {return concrete_temp_.get_grade();}
	virtual Publisher_ID get_id()const override {return id_;}

public:		// User declarations
	__fastcall TConcreteDefinitionForm(TComponent* Owner)override;
	Concrete get_concrete()const {return concrete_temp_;}
	void register_observer(IObserver_* iobserver)override{iobserver_ = iobserver;}
	void set_form_controls(Concrete concrete);
};
//---------------------------------------------------------------------------
extern PACKAGE TConcreteDefinitionForm *ConcreteDefinitionForm;
//---------------------------------------------------------------------------
#endif
