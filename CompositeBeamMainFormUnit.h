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

#include "SteelDefinitionFormUnit.h"   //Подключаем формы
#include "SteelSectionFormUnit.h"
#include "StudDefinitionFormUnit.h"
#include "ConcreteDefinitionFormUnit.h"
#include "RebarDefinitionFormUnit.h"

class TCompositeBeamMainForm : public TForm
{
// поля созданные IDE

__published:	// IDE-managed Components
	TPageControl *PgCntrlCompositeBeam;
	TTabSheet *TbShtStaticScheme;
	TGroupBox *GrpBxLoadsSafetyFactors;
	TLabel *lbl_gamma_f_DL_I;
	TLabel *lbl_gamma_f_DL_II;
	TLabel *Label2;
	TLabel *Label6;
	TLabel *lbl_gamma_f_LL;
	TGroupBox *GrpBxLoadCases;
	TLabel *lbl_dead_load_first_stage;
	TLabel *lbl_dead_load_second_stage;
	TLabel *Label9;
	TLabel *Label10;
	TLabel *lbl_live_load;
	TEdit *edt_dead_load_first_stage;
	TEdit *edt_dead_load_second_stage;
	TEdit *edt_live_load;
	TEdit *edt_gamma_f_DL_I;
	TEdit *edt_gamma_f_DL_II;
	TEdit *edt_gamma_f_LL;
	TGroupBox *GrpBxTopology;
	TLabel *lbl_span;
	TLabel *lbl_trib_width_left;
	TEdit *edt_span;
	TEdit *edt_width_left;
	TEdit *edt_width_right;
	TLabel *lbl_trib_width_right;
	TCheckBox *chck_bx_end_beam;
	TGroupBox *GrpBxStaticScheme;
	TImage *ImgStaticScheme;
	TMainMenu *MainMenu1;
	TMenuItem *NFile;
	TMenuItem *N3;
	TButton *BtnCalculate;
	TButton *BtnReport;
	TTabSheet *TbResults;
	TTabSheet *TbShtSectionMaterials;
	TGroupBox *GrpBxSteelSection;
	TRadioGroup *rdgrp_slab_type;
	TLabel *Label3;
	TLabel *Label16;
	TLabel *Label17;
	TLabel *Label18;
	TLabel *Label19;
	TLabel *Label20;
	TEdit *edtLowFlThick;
	TEdit *edtUpFlWidth;
	TEdit *edtWebHeight;
	TEdit *edtWebThick;
	TEdit *edtLowFlWidth;
	TEdit *edtUpFlThick;
	TGroupBox *grpbxWelded;
	TGroupBox *grp_bx_flat_slab;
	TLabel *lbl_flat_slab_thickness;
	TEdit *edt_flat_slab_thickness;
	TGroupBox *grpBxCorrugatedSlab;
	TComboBox *ComboBox2;
	TStringGrid *strngGrdResults;
	TLabel *lbl_beam_division;
	TEdit *edt_beam_division;
	TGroupBox *GrpBxSteel;
	TPanel *PnlSteelViewer;
	TBitBtn *BtBtnSteelChoice;
	TLabel *lbl_number_propping_supports;
	TComboBox *cmb_bx_number_propping_supports;
	TPanel *Pnl_SteelSectionViewer;
	TBitBtn *BtnSteelSectionChoice;
	TGroupBox *GrpBxConcrete;
	TPanel *pnl_concrete_grade;
	TBitBtn *BtnConcreteChoice;
	TTabSheet *TabSheet3;
	TGroupBox *GrpBxRebars;
	TPanel *PnlRebarsViewer;
	TBitBtn *BtBtnRebarsChoice;
	TMenuItem *NOpen;
	TMenuItem *NSave;
	TMenuItem *NSaveAs;
	TMenuItem *NOutReport;
	TMenuItem *N8;
	TSaveDialog *SaveDialog1;
	TOpenDialog *OpenDialog_Model;
	TGroupBox *GrpBxShearStudsPlacement;
	TLabel *Label25;
	TLabel *Label26;
	TEdit *Edit1;
	TEdit *Edit2;
	TGroupBox *GrpBxErection;
	TGroupBox *GrpBxShearStuds;
	TGroupBox *GrpBxAnalysisTheory;
	TComboBox *CmbBxAnalysisTheoryChoice;
	TImageList *ImageList1;
	TToolBar *ToolBar1;
	TToolButton *ToolButtonOpen;
	TToolButton *ToolButtonSave;
	TToolButton *ToolButtonSaveAs;
	TToolButton *ToolButtonOutReport;
	TPanel *PnlShearStudsViewer;
	TBitBtn *BtBtnShearStudsChoice;
	TBitBtn *BtBtnExit;
	TMenuItem *NNew;
	TMenuItem *NExit;
	TMenuItem *N2;
	TToolButton *ToolButton1;
	TStringGrid *strng_grd_compos_sect_geom_character;
	TGroupBox *GrpBxMaterialSafetyFactors;
	TLabel *Label23;
	TLabel *Label24;
	TEdit *EdtSafetyFactorConcrete;
	TEdit *EdtSafetyFactorSteel;
	TGroupBox *GroupBox6;
	TImage *Image1;
	TComboBox *ComboBox1;
	TLabel *Label1;
	TLabel *lblLoadCase;
	TComboBox *ComboBox3;
	TLabel *lblDiagramType;
	TGroupBox *grp_bx_working_conditions_factors;
	TEdit *edt_gamma_bi;
	TEdit *edt_gamma_si;
	TEdit *edt_gamma_c;
	TLabel *lbl_gamma_c;
	TLabel *lbl_gamma_bi;
	TLabel *lbl_gamma_si;

	void __fastcall chck_bx_end_beamClick(TObject *Sender);
	void __fastcall BtnCalculateClick(TObject *Sender);
	void __fastcall BtnReportClick(TObject *Sender);
	void __fastcall rdgrp_slab_typeClick(TObject *Sender);
	void __fastcall strngGrdResultsDrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
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


private:	//Собственные поля

	TGeometry geometry_;//поле содержащее топологию
	TLoads loads_;//поле содержащее нагрузки и коэффициенты надёжности по нагрузкам
	TStud stud_; //поле соержащее упоры Нельсона
	TISectionInitialData i_section_initial_data_;
	TSteelInitialData steel_i_section_initial_data_;
	WorkingConditionsFactors working_conditions_factors_;
	TConcretePart* concrete_part_;//объект абстрактного класса, поэтому указатель!
	CompositeSection composite_section_; //Геометрические характеристики композитного сечения
	TCompositeBeam composite_beam_; //Основной объект в программе, формируемый на основании объектов заданных выше
//---------------------------------------------------------------------------

public:		// User declarations
	__fastcall TCompositeBeamMainForm(TComponent* Owner);
//---------------------------------------------------------------------------
//Пользовательские privat функции
//---------------------------------------------------------------------------
private:  // Пользовательсткие private функции

	void init_geomet();//Инициализация топологии
	void init_loads(); //Инициализация нагрузок
	void init_i_section();//Инициализация объекта геометрия двутавра
	void init_steel_i_section(); //Инициализация стали двутавра
	void init_concrete_part();//Инициализация бетонной части композитного сечения
	void init_composite_section();//Инициализация композитного сечения
	void init_composite_beam();//Инициализация композитной балки
	void init_stud();//Инициализация упоров
	void init_working_conditions_factors();//Инициализация коэффициентов условий работы

	void generate_report();

	void GridConstructor(); // Конструирование Grid контрола для вывода результатоа
	void grid_constr_comp_sect_geometr(); //Конструирование Grid для вывода геометрических характ. комп. сечения

	void fill_grid_with_results();
};
//---------------------------------------------------------------------------
extern PACKAGE TCompositeBeamMainForm *CompositeBeamMainForm;
//---------------------------------------------------------------------------
#endif
