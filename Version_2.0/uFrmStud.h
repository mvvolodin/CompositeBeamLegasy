//---------------------------------------------------------------------------

#ifndef uFrmStudH
#define uFrmStudH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
#include "uStud.h"
#include "ObserverPatternInterfaces.h"
#include "uFrmsCntrlsState.h"
//---------------------------------------------------------------------------
class TStudDefinitionForm : public TForm
{
__published:	// IDE-managed Components
	TLabel *lbl_stud_yield_strength;
	TLabel *lbl_stud_diameter;
	TLabel *lbl_stud_height;
	TEdit *edt_stud_yield_strength;
	TEdit *edt_stud_diameter;
	TEdit *edt_stud_height;
	TComboBox *cmb_bx_stud_part_number;
	TLabel *lbl_stud_part_number;
	TBitBtn *btn_ok;
	TLabel *lbl_stud_safety_factor;
	TEdit *edt_stud_safety_factor;
	TPanel *pnl_stud_part_number;
	TButton *btn_cancel;
	TGroupBox *grp_bx_placement;
	TLabel *lbl_edge_studs_dist;
	TLabel *lbl_middle_studs_dist;
	TLabel *edt_edge_studs_rows_num;
	TLabel *lbl_middle_studs_rows_num;
	TEdit *edt_edge_studs_dist;
	TEdit *edt_middle_studs_dist;
	TComboBox *cmb_bx_middle_studs_rows_num;
	TComboBox *cmb_bx_edge_studs_rows_num;
	TGroupBox *grp_bx_characteristics;
	TButton *btn_close;
	TCheckBox *chck_bx_more_than_one_stud_per_corrugation_edge;
	TCheckBox *chck_bx_more_than_one_stud_per_corrugation_middle;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall btn_okClick(TObject *Sender);
	void __fastcall btn_cancelClick(TObject *Sender);
	void __fastcall btn_closeClick(TObject *Sender);
	void __fastcall cmb_bx_stud_part_numberChange(TObject *Sender);
private:
	TStudDefinitionFormCntrlsState cntrls_state_;
	void check_input();
	void update_stud_geom_edts(int index);

public:
	__fastcall TStudDefinitionForm(TComponent* Owner);
	void update_cntrls_state();
	void store_cntrls_state();

	void save(ostream & os);
	void load(istream & is);

	String info()const;
	TStudDefinitionFormCntrlsState const & cntrls_state(){return cntrls_state_;}
};
//---------------------------------------------------------------------------
extern PACKAGE TStudDefinitionForm *StudDefinitionForm;
//---------------------------------------------------------------------------
#endif
