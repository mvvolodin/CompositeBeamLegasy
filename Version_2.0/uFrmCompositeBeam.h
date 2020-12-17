//---------------------------------------------------------------------------

#ifndef uFrmCompositeBeamH
#define uFrmCompositeBeamH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.CheckLst.hpp>
#include <Vcl.OleCtnrs.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ToolWin.hpp>
#include <System.ImageList.hpp>
#include <Vcl.ImgList.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.Graphics.hpp>
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Пользовательские заголовочные файлы
//---------------------------------------------------------------------------


#include "uCompositeBeamCalculator.h"//Подключаем логику
#include "uFrmStud.h"
#include "uFrmConcrete.h"
#include "uFrmRebar.h"
#include "uFrmSteelSection.h"
#include "uFrmHelp.h"
#include "uFrmSteel.h"
#include "uFrmAddImacts.h"
#include "uFrmLogger.h"
#include "DrawEpurMain.h" //Подключаем функцию отрисовки эпюр
#include "uWord_Automation.h"
#include "uGeneralConcreteSection.h"
#include "uSlabConcreteSection.h"
#include "uCorrugatedConcreteSection.h"
#include "uFrmsCntrlsState.h"
#include "uComposSectCalculatorS35.h"
#include "uGlobGeom.h"

#include <Vcl.Imaging.jpeg.hpp>
#include <Vcl.Imaging.pngimage.hpp>


#include <memory>

#include "ObserverPatternInterfaces.h"//подключаем интерфейсы шаблона Наблюдатель
#include "ICompositeBeam.h"

//#define NDEBUG



void ModelName(char * str0, char *ModelFile);  // Выделение из имени файла в имени модели

class TCompositeBeamMainForm : public TForm
{

__published:	// IDE-managed Components
	TMainMenu *MainMenu1;
	TMenuItem *NFile;
	TMenuItem *N3;
	TButton *BtnCalculate;
	TButton *btn_report;
	TLabel *lbl_max_elem_length;
	TEdit *edt_max_elem_length;
	TMenuItem *NOpen;
	TMenuItem *NSave;
	TMenuItem *NSaveAs;
	TMenuItem *NOutReport;
	TMenuItem *N8;
	TSaveDialog *SaveDialog_Model;
	TOpenDialog *OpenDialog_Model;
	TImageList *ImageList1;
	TToolBar *ToolBar1;
	TToolButton *ToolButtonOpen;
	TToolButton *ToolButtonSave;
	TToolButton *ToolButtonSaveAs;
	TToolButton *ToolButtonOutReport;
	TBitBtn *BtBtnExit;
	TMenuItem *NNew;
	TMenuItem *NExit;
	TMenuItem *N2;
	TToolButton *ToolButton1;
	TPageControl *PgCntrlCompositeBeam;
	TTabSheet *TbShtStaticScheme;
	TGroupBox *GrpBxLoadsSafetyFactors;
	TLabel *lbl_gamma_f_DL_I;
	TLabel *lbl_gamma_f_DL_II;
	TLabel *Label2;
	TLabel *Label6;
	TLabel *lbl_gamma_f_LL;
	TEdit *edt_gamma_f_DL_I;
	TEdit *edt_gamma_f_DL_II;
	TEdit *edt_gamma_f_LL;
	TGroupBox *grp_bx_load_cases;
	TLabel *lbl_dead_load_first_stage;
	TLabel *lbl_dead_load_second_stage;
	TLabel *Label9;
	TLabel *Label10;
	TLabel *lbl_live_load;
	TEdit *edt_dead_load_first_stage;
	TEdit *edt_dead_load_second_stage;
	TEdit *edt_live_load;
	TGroupBox *GrpBxTopology;
	TLabel *lbl_span;
	TLabel *lbl_trib_width_left;
	TLabel *lbl_trib_width_right;
	TEdit *edt_span;
	TEdit *edt_width_left;
	TEdit *edt_width_right;
	TCheckBox *chck_bx_end_beam;
	TGroupBox *GrpBxStaticScheme;
	TImage *img_static_scheme;
	TLabel *lblLoadCase;
	TComboBox *cmb_bx_impact;
	TRadioGroup *rd_grp_internal_forces_type;
	TComboBox *cmb_bx_number_propping_supports;
	TGroupBox *grp_bx_working_conditions_factors;
	TLabel *lbl_gamma_c;
	TLabel *lbl_gamma_bi;
	TLabel *lbl_gamma_si;
	TEdit *edt_gamma_bi;
	TEdit *edt_gamma_si;
	TEdit *edt_gamma_c;
	TTabSheet *TbShtSectionMaterials;
	TGroupBox *GrpBxSteelSection;
	TPanel *pnl_steel_section_viewer;
	TBitBtn *BtnSteelSectionChoice;
	TRadioGroup *rdgrp_slab_type;
	TGroupBox *grp_bx_flat_slab;
	TLabel *lbl_h_f_flat;
	TEdit *edt_h_f_flat;
	TGroupBox *grp_bx_corrugated_slab;
	TComboBox *cmb_bx_corrugated_sheeting_part_number;
	TGroupBox *GrpBxSteel;
	TPanel *pnl_steel;
	TBitBtn *BtBtnSteelChoice;
	TGroupBox *GrpBxConcrete;
	TPanel *pnl_concrete_grade;
	TBitBtn *BtnConcreteChoice;
	TGroupBox *GrpBxRebars;
	TPanel *pnl_rebar_viewer;
	TBitBtn *BtBtnRebarsChoice;
	TGroupBox *GrpBxShearStuds;
	TPanel *pnl_shear_stud_viewer;
	TBitBtn *BtBtnShearStudsChoice;
	TGroupBox *GroupBox6;
	TImage *Image1;
	TStringGrid *strng_grd_compos_sect_geom_character;
	TTabSheet *tb_results;
	TStringGrid *strng_grd_results;
	TOpenDialog *OpenDialog1;
	TPageControl *pg_ctrl_geom_char;
	TTabSheet *tb_sht_composite_geom_char;
	TTabSheet *tb_sht_concrete_geom_char;
	TTabSheet *tb_sht_steel_geom_char;
	TStringGrid *strng_grd_concrete_sect_geom_character;
	TStringGrid *strng_grd_steel_sect_geom_character;
	TEdit *edt_gamma_f_st_SW;
	TLabel *lbl_gamma_f_st_SW;
	TEdit *edt_h_f;
	TLabel *lbl_h_f;
	TLabel *lbl_corrugated_sheet_type;
	TImage *Image2;
	TLabel *lbl_number_propping_supports;
	TEdit *edt_gamma_f_concrete_SW;
	TLabel *lbl_gamma_f_concrete_SW;
	TEdit *edt_h_n;
	TLabel *lbl_h_n;
	TLabel *lbl_SW_add_concrete;
	TEdit *edt_SW_add_concrete;
	TLabel *lbl_gamma_f_add_concrete_SW;
	TEdit *edt_gamma_f_add_concrete_SW;
	TButton *btn_add_impacts;
	TEdit *edt_sheeting_continuity_coefficient;
	TLabel *lbl_sheeting_continuity_coefficient;
	TCheckBox *chck_bx_wider_flange_up;
	TCheckBox *chck_bx_sheet_orient_along;
	TGroupBox *grp_bx_other_coeff;
	TMenuItem *Help;
	TRadioGroup *rd_grp_code;
	TLabel *lbl_SW_conc;
	TEdit *edt_SW_conc;
	TLabel *lbl_SW_steel_beam;
	TEdit *edt_SW_steel_beam;
	TEdit *edt_fact_quasi_perm_load;
	TLabel *lbl_fact_quasi_perm_load;

	void __fastcall BtnCalculateClick(TObject *Sender);
	void __fastcall btn_reportClick(TObject *Sender);
	void __fastcall rdgrp_slab_typeClick(TObject *Sender);
	void __fastcall strng_grd_results_rendering(TObject *Sender, int ACol, int ARow, TRect &Rect,
		  TGridDrawState State);
	void __fastcall BtBtnSteelChoiceClick(TObject *Sender);
	void __fastcall BtnSteelSectionChoiceClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall BtBtnExitClick(TObject *Sender);
	void __fastcall BtnConcreteChoiceClick(TObject *Sender);
	void __fastcall BtBtnRebarsChoiceClick(TObject *Sender);
	void __fastcall BtBtnShearStudsChoiceClick(TObject *Sender);
	void __fastcall NOutReportClick(TObject *Sender);
	void __fastcall NExitClick(TObject *Sender);
	void __fastcall cmb_bx_impactChange(TObject *Sender);
	void __fastcall rd_grp_internal_forces_typeClick(TObject *Sender);
	void __fastcall NNewClick(TObject *Sender);
	void __fastcall NSaveClick(TObject *Sender);
	void __fastcall NSaveAsClick(TObject *Sender);
	void __fastcall NOpenClick(TObject *Sender);
	void __fastcall OnControlsChange(TObject *Sender);
	void __fastcall chck_bx_end_beamClick(TObject *Sender);
	void __fastcall cmb_bx_analysis_theoryChange(TObject *Sender);
	void __fastcall cmb_bx_corrugated_sheeting_part_numberChange(TObject *Sender);
	void __fastcall btn_loggerClick(TObject *Sender);
	void __fastcall N8Click(TObject *Sender);
	void __fastcall strng_grd_first_raw_bold(TObject *Sender, int ACol,
          int ARow, TRect &Rect, TGridDrawState State);
	void __fastcall btn_add_impactsClick(TObject *Sender);
	void __fastcall HelpClick(TObject *Sender);
	void __fastcall rd_grp_codeClick(TObject *Sender);
	void __fastcall btn_loadClick(TObject *Sender);
	void __fastcall btn_saveClick(TObject *Sender);

public:		// User declarations
	__fastcall TCompositeBeamMainForm(TComponent* Owner)override;

private:
	TCompositeBeamMainFormCntrlsState cntrls_state_;

	std::unique_ptr<TFormLogger> frm_logger_;

	void set_form_controls();
	void generate_report();
	void cotr_ratios_grid(); // Конструирование Grid контрола для вывода результатоа
	void cotr_comp_sect_geometr_grid(); //Конструирование Grid для вывода геометрических характ. комп. сечения
	void cotr_steel_sect_geometr_grid();
	void ctor_concrete_sect_geometr_grid();
	void fill_cmb_bx_impact();//Заполняем ComboBox названиями случаев загружения и соответствующими объектами типа перечесление случаев загружений
	void fill_cmb_bx_corrugated_sheets();
	void fill_results_grid();

	void update_grids(int code_indx);
	void update_SW_edts(int code_indx);
	void update_steel_sect_geometr_grid(int code_indx);
	void update_concrete_sect_geometr_grid(int code_indx);
	void update_composite_sect_geometr_grid(int code_indx);
	void update_results_grid(int code_indx);

	void draw_diagram();

	void calculate_composite_beam();
	void calculate_composite_beam_SP266();
	void calculate_composite_beam_SP35();
	void after_calculation();

	void clean_static_scheme();
	void clean_grid(TStringGrid* str_grd);
	void update_GUI(int code_indx);
	void set_GUI_SP35();
	void set_GUI_SP266();

	#define UNTITLED  "Без имени"
	bool modify_project;  // признак изменения проекта после сохранения
	char ModelFile[240]; //Это имя файла?
	AnsiString FileDir_Name; //Это имя директории?

	void update_cntrls();
	void update_all_frms_cntrls();
	void store_cntrls_state();
	void store_all_frms_cntrls_state();

	void save();
	void load();

};
//---------------------------------------------------------------------------
extern PACKAGE TCompositeBeamMainForm *CompositeBeamMainForm;
//---------------------------------------------------------------------------
#endif
