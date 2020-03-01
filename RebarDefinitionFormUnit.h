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
#include <Vcl.ExtCtrls.hpp>

#include "ObserverPatternInterfaces.h"//подключаем интерфейсы шаблона Наблюдатель
//---------------------------------------------------------------------------

class TRebarDefinitionForm : public TForm, public IPublisher
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
	void __fastcall cmb_bx_rebar_gradeChange(TObject *Sender);
	void __fastcall bt_btn_OkClick(TObject *Sender);
	void __fastcall bt_btn_cancelClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
	static const Publisher_ID id_ = Publisher_ID::REBARS_FORM;
	IObserver_* iobserver_;
	Rebar rebar_;
	void set_rebar();//Функция которая проверяет корректность ввода и вызывает конструктор rebar
	void init_form_controls();
	virtual String get_information()const override;
	virtual Publisher_ID get_id()const override;
public:		// User declarations
	__fastcall TRebarDefinitionForm(TComponent* Owner);
	Rebar get_rebar() const {return rebar_;}
	void register_observer(IObserver_* iobserver);
};
//---------------------------------------------------------------------------
extern PACKAGE TRebarDefinitionForm *RebarDefinitionForm;
//---------------------------------------------------------------------------
#endif
