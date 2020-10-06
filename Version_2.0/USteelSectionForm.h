//---------------------------------------------------------------------------

#ifndef uSteelSectionFormH
#define uSteelSectionFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
#include <memory>
#include "uGeneralSteelSection.h"
#include "uWeldedSection.h"
#include "uRolledSection.h"
#include "StandartProfil.h"
#include "pCanvas_func.h"
#include "Data_Profil.h"
#include "ListConst.h"
#include "StandartProfil.h"
#include "pCanvas_func.h"
#include "ProcExt.h"
#include "String_doubleUnit.h"
#include "GArrow.h"

#include "uISection.h"
#include "ObserverPatternInterfaces.h"//подключаем интерфейсы шаблона Наблюдатель
//---------------------------------------------------------------------------
class TSteelSectionForm : public TForm, public IPublisher
{
__published:	// IDE-managed Components
	TPageControl *PageControl2;
	TTabSheet *TabSheet_Standart;
	TLabel *Label10;
	TImage *Image_stand;
	TComboBox *ComboBox_profil;
	TStringGrid *StringGrid_B;
	TRadioGroup *RadioGroupGOST57837;
	TButton *btk_ok;
	TButton *btn_cancel;
	TButton *btn_close;
	TTabSheet *tb_sheet_welded_profile;
	TStringGrid *StringGrid1;
	TImage *img_weld_sect;
	TGroupBox *GroupBox1;
	TEdit *edt_b_f2;
	TEdit *edt_t_f2;
	TEdit *edt_b_f1;
	TEdit *edt_t_f1;
	TEdit *edt_h_w;
	TEdit *edt_t_w;
	TLabel *lbl_b_f2;
	TLabel *lbl_t_f2;
	TLabel *lbl_b_f1;
	TLabel *lbl_t_f1;
	TLabel *lbl_h_w;
	TLabel *lbl_t_w;
	TButton *btn_launch_logger;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall ComboBox_profilChange(TObject *Sender);
	void __fastcall RadioGroupGOST57837Click(TObject *Sender);
	void __fastcall btk_okClick(TObject *Sender);
	void __fastcall btn_cancelClick(TObject *Sender);
	void __fastcall btn_closeClick(TObject *Sender);
	void __fastcall btn_launch_loggerClick(TObject *Sender);
private:	// User declarations
	TStandartProfil StandartProfil_; //база данных
	ISection i_section_temp_; //
	WeldedSection weld_sect_temp_{300,24,200,12,1200,8};
   // RolledSection rolled_sect_temp_;
    std::unique_ptr<GeneralSteelSection> sect_;

    std::unique_ptr<TFormLogger> log_;

	static const Publisher_ID id_ = Publisher_ID::SECTION_FORM;
	IObserver_* iobserver_;
	virtual String get_information()const override;
	virtual Publisher_ID get_id()const override;

	TArrow CoorAx;

	void set_form_controls();
	void set_i_section();
	void update_weld_sect_ctrls();
	std::unique_ptr<GeneralSteelSection> update_steel_section();
	void form_controls_changed();

	void Point_stand_dvutavr(int zero, int zero1, int zero2, SECT_DVUTAVR *sect, double rad, float scale, TPoint *vertices);
	void  draw_dvutavr(TImage * Image_stand, SECT_DVUTAVR *sect);
	void draw_axes(TImage *Image_Ax);
	void draw_axes_zero(TImage *Image_Ax, int x0, int y0);


public:		// User declarations
	__fastcall TSteelSectionForm(TComponent* Owner)override;
	void set_form_controls(ISection i_section);
	ISection get_i_section() const {return i_section_temp_;}
	std::unique_ptr<GeneralSteelSection> get_section() {return sect_;}
	void register_observer(IObserver_* iobserver)override;
};
//---------------------------------------------------------------------------
extern PACKAGE TSteelSectionForm *SteelSectionForm;
//---------------------------------------------------------------------------
#endif
