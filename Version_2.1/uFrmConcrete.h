//---------------------------------------------------------------------------
#ifndef uFrmConcreteH
#define uFrmConcreteH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
#include <map>
#include "uConcrete.h"
#include "uFrmsCntrlsState.h"
#include "uGUI.h"
//---------------------------------------------------------------------------
class TConcreteDefinitionForm : public TForm
{
__published:	// IDE-managed Components
	TLabel *lbl_R_bn;
	TLabel *lbl_E_b;
	TEdit *edt_comp_strength;
	TEdit *edt_E_b;
	TEdit *edt_tens_strength;
	TLabel *lbl_R_btn;
	TComboBox *cmb_bx_concrete_grade_list;
	TLabel *lbl_concrete_grade;
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
	TButton *btn_OK;
	TEdit *edt_c_n;
	TLabel *lbl_c_n;
	TLabel *lbl_R_b;
	TLabel *lbl_R_bt;
	void __fastcall cmb_bx_concrete_grade_listChange(TObject *Sender);
	void __fastcall btn_OKClick(TObject *Sender);
	void __fastcall btn_cancelClick(TObject *Sender);
	void __fastcall btn_closeClick(TObject *Sender);

private:	// User declarations
	TConcreteDefinitionFormCntrlsState cntrls_state_;
    GUI gui_;

	void check_input();

	void after_cmb_bx_conc_grade_list_change_SP266(unsigned int index);
	void after_cmb_bx_conc_grade_list_change_SP35(unsigned int index);

	void fill_cmb_bx_conc_grades_SP266();
	void fill_cmb_bx_conc_grades_SP35();

public:		// User declarations
	__fastcall TConcreteDefinitionForm(TComponent* Owner);

	void update_cntrls_state();
    void store_cntrls_state();

	void save(ostream & os);
	void load(istream & is);

	String info()const;
	TConcreteDefinitionFormCntrlsState const & cntrls_state(){return cntrls_state_;}

	void set_GUI_SP35();
	void set_GUI_SP266();
};
//---------------------------------------------------------------------------
extern PACKAGE TConcreteDefinitionForm *ConcreteDefinitionForm;
//---------------------------------------------------------------------------
#endif
