//---------------------------------------------------------------------------

#ifndef CompositeBeamMainFormUnitH
#define CompositeBeamMainFormUnitH
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


#include "CompositeBeam.h"//Подключаем логику
#include "DefineSteelFormUnit.h"
#include "StudDefinitionFormUnit.h"
#include "ConcreteDefinitionFormUnit.h"
#include "RebarDefinitionFormUnit.h"
#include "LoggerFormUnit.h"
#include "DrawEpurMain.h" //Подключаем функцию отрисовки эпюр
#include "Word_Automation.h"

#include <Vcl.Imaging.jpeg.hpp>
#include <Vcl.Imaging.pngimage.hpp>

//#include <memory>
//#include <cassert>
 //@
void ModelName(char * str0, char *ModelFile);  // Выделение из имени файла в имени модели
//@@
class TCompositeBeamMainForm : public TForm
{

__published:	// IDE-managed Components
	TMainMenu *MainMenu1;
	TMenuItem *NFile;
	TMenuItem *N3;
	TButton *BtnCalculate;
	TButton *btn_report;
	TLabel *lbl_beam_division;
	TEdit *edt_beam_division;
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
	TLabel *lbl_edge_studs_rows_num;
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
	TGroupBox *GrpBxLoadCases;
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
	TGroupBox *GrpBxErection;
	TLabel *lbl_number_propping_supports;
	TComboBox *cmb_bx_number_propping_supports;
	TGroupBox *grp_bx_shear_studs_placement;
	TLabel *lbl_edge_studs_dist;
	TLabel *lbl_middle_studs_dist;
	TEdit *edt_edge_studs_dist;
	TEdit *edt_middle_studs_dist;
	TGroupBox *grb_bx_analysis_theory;
	TComboBox *cmb_bx_analysis_theory;
	TGroupBox *grp_bx_working_conditions_factors;
	TLabel *lbl_gamma_c;
	TLabel *lbl_gamma_bi;
	TLabel *lbl_gamma_si;
	TEdit *edt_gamma_bi;
	TEdit *edt_gamma_si;
	TEdit *edt_gamma_c;
	TTabSheet *TbShtSectionMaterials;
	TGroupBox *GrpBxSteelSection;
	TPanel *Pnl_SteelSectionViewer;
	TBitBtn *BtnSteelSectionChoice;
	TRadioGroup *rdgrp_slab_type;
	TGroupBox *grp_bx_flat_slab;
	TLabel *lbl_flat_slab_thickness;
	TEdit *edt_flat_slab_thickness;
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
	TLabel *lbl_middle_studs_rows_num;
	TComboBox *cmb_bx_middle_studs_rows__num;
	TComboBox *cmb_bx_edge_studs_rows_num;
	TEdit *edt_gamma_f_st_SW_;
	TLabel *lbl_gamma_f_st_SW;
	TButton *btn_logger;
	TEdit *edt_corrugated_slab_thickness;
	TLabel *Label1;
	TLabel *lbl_corrugated_sheet_type;

	void __fastcall BtnCalculateClick(TObject *Sender);
	void __fastcall btn_reportClick(TObject *Sender);
	void __fastcall rdgrp_slab_typeClick(TObject *Sender);
	void __fastcall strng_grd_rendering(TObject *Sender, int ACol, int ARow, TRect &Rect,
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

public:		// User declarations
	__fastcall TCompositeBeamMainForm(TComponent* Owner);

private:

	TCompositeBeam composite_beam_; //Основной объект в программе  // Пользовательсткие private функции

	AnalysisTheory get_analysis_theory();
	TGeometry init_geomet();//Инициализация топологии
	TLoads init_loads(); //Инициализация нагрузок
	TISectionInitialData init_i_section();//Инициализация объекта геометрия двутавра
	Steel init_steel_i_section(); //Инициализация стали двутавра
	TConcretePart* init_concrete_part();//Инициализация бетонной части композитного сечения
	TStud init_stud();//Инициализация упоров
	WorkingConditionsFactors init_working_conditions_factors();//Инициализация коэффициентов условий работы
	CompositeSection init_composite_section(TGeometry geometry,
											Steel steel_i_section,
											TISectionInitialData i_section_initial_data,
											TConcretePart* concrete_part);//Инициализация композитного сечения
	void init_composite_beam(AnalysisTheory 		  analysis_theory,
							 TGeometry 				  geometry,
							 TLoads 				  loads,
							 CompositeSection 		  composite_section,
							 TStud 					  stud,
							 WorkingConditionsFactors working_conditions_factors);
	void generate_report();
	void cotr_ratios_grid(); // Конструирование Grid контрола для вывода результатоа
	void cotr_comp_sect_geometr_grid(); //Конструирование Grid для вывода геометрических характ. комп. сечения
	void cotr_steel_sect_geometr_grid();
	void ctor_concrete_sect_geometr_grid();
	void fill_cmb_bx_impact();//Заполняем ComboBox названиями случаев загружения и соответствующими объектами типа перечесление случаев загружений
	void fill_results_grid();
	void fill_steel_sect_geometr_grid();
	void fill_concrete_sect_geometr_grid();
	void fill_composite_sect_geometr_grid();
	void draw_diagram();//Отрисовка эпюр
	void calculate_composite_beam();//инициализирует и рассчитывает балку
	void __fastcall save_controls_to_file();//Сохраняет состояние элементов управления в файл
	void __fastcall load_controls_from_file();//Загружает состояние элементов управления из файла
	int __fastcall LoadComponent(String filename, TComponent* Component);
	int __fastcall SaveComponent(String filename, TComponent* Component);
	#define UNTITLED  "Без имени"
	bool modify_project;  // признак изменения проекта после сохранения
	char ModelFile[240]; //Это имя файла?
	AnsiString FileDir_Name; //Это имя директории?

};
//---------------------------------------------------------------------------
extern PACKAGE TCompositeBeamMainForm *CompositeBeamMainForm;
//---------------------------------------------------------------------------
#endif
