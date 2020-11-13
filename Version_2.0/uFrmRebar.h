//---------------------------------------------------------------------------

#ifndef uFrmRebarH
#define uFrmRebarH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
//---------------------------------------------------------------------------
#include "uRebar.h"
#include <Vcl.ExtCtrls.hpp>
#include "uFrmsCntrlsState.h"
#include "ObserverPatternInterfaces.h"//подключаем интерфейсы шаблона Наблюдатель
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
	TPanel *pnl_rebar_grade;
	TGroupBox *grp_bx_characteristics;
	TGroupBox *grp_bx_placement;
	TLabel *lbl_b;
	TLabel *lbl_a_u;
	TLabel *lbl_a_l;
	TEdit *edt_a_l;
	TEdit *edt_a_u;
	TEdit *edt_b;
	TButton *bt_btn_cancel;
	TButton *btn_close;
	TEdit *edt_E_s;
	TLabel *lbl_E_s;
	void __fastcall cmb_bx_rebar_gradeChange(TObject *Sender);
	void __fastcall bt_btn_OkClick(TObject *Sender);
	void __fastcall bt_btn_cancelClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall btn_closeClick(TObject *Sender);
private:	// User declarations
	TFrmRebarCntrlsState cntrls_state_;
	void check_input();
	void store_cntrls_state();

	void update_edt_R_s_n(int cmb_bx_rebar_grade_index);

public:		// User declarations
	__fastcall TRebarDefinitionForm(TComponent* Owner)override;

	void update_cntrls_state();

	void save(ostream & os);
	void load(istream & os);

	String info()const;
	TFrmRebarCntrlsState const & cntrls_state(){return cntrls_state_;}
};
//---------------------------------------------------------------------------
extern PACKAGE TRebarDefinitionForm *RebarDefinitionForm;
//---------------------------------------------------------------------------
#endif
