//---------------------------------------------------------------------------

#ifndef uFrmSteelSectionH
#define uFrmSteelSectionH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
#include <ostream>
#include <istream>
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
#include "uFrmsCntrlsState.h"

#include "uISection.h"
#include "ObserverPatternInterfaces.h"//подключаем интерфейсы шаблона Наблюдатель
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

class TSteelSectionForm : public TForm
{
__published:	// IDE-managed Components
	TPageControl *pg_cntrl_sect_type;
	TTabSheet *TabSheet_Standart;
	TLabel *Label10;
	TImage *Image_stand;
	TComboBox *cmb_bx_rolled_sect_num;
	TStringGrid *StringGrid_B;
	TRadioGroup *rd_grp_rolled_sect_type;
	TButton *btk_ok;
	TButton *btn_cancel;
	TButton *btn_close;
	TTabSheet *tb_sheet_welded_profile;
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
	void __fastcall FormShow(TObject *Sender);
	void __fastcall cmb_bx_rolled_sect_numChange(TObject *Sender);
	void __fastcall rd_grp_rolled_sect_typeClick(TObject *Sender);
	void __fastcall btk_okClick(TObject *Sender);
	void __fastcall btn_cancelClick(TObject *Sender);
	void __fastcall btn_closeClick(TObject *Sender);
	void __fastcall edt_weld_sect_exit(TObject *Sender);
	void __fastcall pg_cntrl_sect_typeChange(TObject *Sender);

private:	// User declarations
	TSteelSectionFormCntrlsState cntrls_state_;
	void check_input();

	TArrow CoorAx;

	void fill_cmb_bx_rolled_sect_num(int rolled_sect_type);
	void fill_strng_grd_rolled_sect(SECT_DVUTAVR sect);

	void Point_stand_dvutavr(int zero, int zero1, int zero2, SECT_DVUTAVR *sect, double rad, float scale, TPoint *vertices);
	void Point_weld_dvutavr(int zero, int zero1, int zero2, SECT_DVUTAVR *sect, float scale, TPoint *vertices);
	void draw_dvutavr(TImage * Image_stand, SECT_DVUTAVR *sect);
	void draw_weld_sect();
	void Draw_dvutavr_weld_plane(TImage * Image_stand, SECT_DVUTAVR *sect);
	void draw_axes(TImage *Image_Ax);
	void draw_axes_zero(TImage *Image_Ax, int x0, int y0);


public:		// User declarations
	__fastcall TSteelSectionForm(TComponent* Owner);

    String sect_name()const;

	void store_cntrls_state();
	void update_cntrls_state();

	void save(ostream & os);
	void load(istream & os);

	TSteelSectionFormCntrlsState const & cntrls_state(){return cntrls_state_;}

};
//---------------------------------------------------------------------------
extern PACKAGE TSteelSectionForm *SteelSectionForm;
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#endif
