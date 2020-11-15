//---------------------------------------------------------------------------
#ifndef uFrmSteelH
#define uFrmSteelH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
#include "uSteelTableObjects.h"
#include "uFrmsCntrlsState.h"
//---------------------------------------------------------------------------

class TDefineSteelForm : public TForm
{
__published:	// IDE-managed Components
		TPanel *Panel1;
		TLabel *Label2;
        TGroupBox *GroupBox1;
	TEdit *edt_E;
	TEdit *edt_G;
	TEdit *edt_nu;
	TLabel *lbl_E;
	TLabel *lbl_G;
	TLabel *lbl_nu;
	TGroupBox *GroupBox_Prop;
	TEdit *edt_dens;
	TLabel *lbl_dens;
	TBitBtn *btn_close;
	TBitBtn *btn_ok;
	TLabel *lbl_gamma_m;
        TLabel *Label11;
	TEdit *edt_gamma_m;
	TComboBox *cmb_bx_steel_grades;
	TComboBox *cmb_bx_standard;
	TStringGrid *StringGrid_Prop;
	TButton *btn_cancel;

	void __fastcall FormShow(TObject *Sender);
	void __fastcall btn_okClick(TObject *Sender);
	void __fastcall btn_closeClick(TObject *Sender);
	void __fastcall cmb_bx_standardChange(TObject *Sender);
	void __fastcall cmb_bx_steel_gradesChange(TObject *Sender);
	void __fastcall btn_cancelClick(TObject *Sender);
private:
	TDefineSteelFormCntrlsState cntrls_state_;
	void check_input();
	void store_cntrls_state();

	void fill_cmb_bx_steel_grades(int st_table_index);
	void fill_cmb_bx_standard();
	void after_cmb_bx_steel_grades_change(int grade_index);
	void after_cmb_bx_standard_change(int st_table_index);

public:
	__fastcall TDefineSteelForm(TComponent* Owner)override;

	void update_cntrls_state();

	void save(ostream & os);
	void load(istream & os);

	String info()const;
	TDefineSteelFormCntrlsState const & cntrls_state(){return cntrls_state_;}

};
//---------------------------------------------------------------------------
extern PACKAGE TDefineSteelForm *DefineSteelForm;
//---------------------------------------------------------------------------
#endif
