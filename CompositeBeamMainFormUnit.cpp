//---------------------------------------------------------------------------
#include <vcl.h>
#include<ComObj.hpp>
#pragma hdrstop

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

#include "CompositeBeamMainFormUnit.h"
#include "String_doubleUnit.h"  //Функции проверяющие правильность ввода данных в поля формы
#include "SteelSectionFormUnit.h"
#include "Report.h" //Подключаем генератор отчётов
#include "Word_Automation.h"  // Вывод отчета в Word

TCompositeBeamMainForm *CompositeBeamMainForm;

//----------------------------------------------------------------------
 _fastcall TCompositeBeamMainForm::TCompositeBeamMainForm(TComponent* Owner)
	: TForm(Owner)
{
//:composite_section_(nullptr)
	TComponentClass classes[2] = {__classid(TTabSheet),__classid(TToolButton)};
	RegisterClasses(classes, 1);
	cotr_ratios_grid();
	cotr_comp_sect_geometr_grid();
	cotr_steel_sect_geometr_grid();
	ctor_concrete_sect_geometr_grid();;
	fill_cmb_bx_LC();
	modify_project = false;
}
//----------------------------------------------------------------------
//
//----------------------------------------------------------------------
void __fastcall TCompositeBeamMainForm::FormShow(TObject *Sender)
{
//Так как главная форма создаётся перед остальными формами и учитывая, что форма появляется
//только один раз, все инструкции использующее данные других форм должны быть вынесены в
//обработчик события OnShow, когда все формы гарантировано созданы и инициализированы.
	//@
	NNewClick(Sender);
	//@@

	SteelSectionForm->SteelSectionDefinitionFrame->RadioGroupGOST57837->ItemIndex=0;
	SteelSectionForm->SteelSectionDefinitionFrame->RadioGroupGOST57837Click(Sender);
	Pnl_SteelSectionViewer->Caption = SteelSectionForm->SteelSectionDefinitionFrame
	->ComboBox_profil->Text;
	DefineSteelForm->ComboBox_steelChange(Sender);
	PnlSteelViewer->Caption = DefineSteelForm->ComboBox_steel->Text;
	pnl_concrete_grade->Caption=ConcreteDefinitionForm->cmb_bx_concrete_grade_list->Text;
	rdgrp_slab_typeClick(Sender);
	pnl_shear_stud_viewer->Caption=StudDefinitionForm->cmb_bx_stud_part_number->Text;
	pnl_rebar_viewer->Caption=RebarDefinitionForm->cmb_bx_rebar_grade->Text;
	calculate_composite_beam();

}
//---------------------------------------------------------------------------
//Инициализация топологии
//---------------------------------------------------------------------------
TGeometry TCompositeBeamMainForm::init_geomet()
{
	double beam_division=.0;//поменять тип на double и написать функцию проверки значения поля на тип int
	double span=.0;
	double trib_width_left=.0;
	double trib_width_right=.0;

	String_double_plus(lbl_beam_division->Caption, edt_beam_division->Text, &beam_division);
	String_double_plus(lbl_span->Caption, edt_span->Text, &span);
	String_double_plus(lbl_trib_width_left->Caption, edt_width_left->Text, &trib_width_left);
	String_double_plus(lbl_trib_width_right->Caption, edt_width_right->Text, &trib_width_right);

	return TGeometry(static_cast<int>(beam_division),
					 chck_bx_end_beam->Checked,
					 span, trib_width_left,
					 trib_width_right,
					 StrToFloat(cmb_bx_number_propping_supports->Text));
}
//---------------------------------------------------------------------------
//Инициализация нагрузок и коэффициентов надёжности по нагрузкам
//(для инициализации SW (собственного веса) необходима инициализация структуры I сечения- предусловие)
//---------------------------------------------------------------------------
TLoads TCompositeBeamMainForm::init_loads()
{
	int rc=0; //rc- return code -код ошибки
	double SW=SteelSectionForm->SteelSectionDefinitionFrame->common_sect_.dvutavr.weight*GRAV_ACCELERAT;
	//SteelSectionForm->SteelSectionDefinitionFrame->common_sect_.dvutavr.

	//необходимо получать по типу профиля
	double DL_I=0.0;
	double DL_II=0.0;
	double LL=0.0;
	double gamma_f_st_SW=0.0;
	double gamma_f_DL_I=0.0;
	double gamma_f_DL_II=0.0;
	double gamma_f_LL=0.0;

	String_double_plus(lbl_dead_load_first_stage->Caption, edt_dead_load_first_stage->Text, &DL_I);
	String_double_plus(lbl_dead_load_second_stage->Caption, edt_dead_load_second_stage->Text, &DL_II);
	String_double_plus(lbl_live_load->Caption, edt_live_load->Text, &LL);
	String_double_plus(lbl_gamma_f_st_SW->Caption, edt_gamma_f_st_SW_->Text, &gamma_f_st_SW);
	String_double_plus(lbl_gamma_f_DL_I->Caption, edt_gamma_f_DL_I->Text, &gamma_f_DL_I);
	String_double_plus(lbl_gamma_f_DL_II->Caption, edt_gamma_f_DL_II->Text, &gamma_f_DL_II);
	String_double_plus(lbl_gamma_f_LL->Caption, edt_gamma_f_LL->Text, &gamma_f_LL);

	return TLoads (SW, DL_I, DL_II, LL, gamma_f_st_SW, gamma_f_DL_I, gamma_f_DL_II, gamma_f_LL);
}
//---------------------------------------------------------------------------
//Инициализация геометрии двутавра
//---------------------------------------------------------------------------
TISectionInitialData TCompositeBeamMainForm::init_i_section()
{
	return TISectionInitialData (&(SteelSectionForm->SteelSectionDefinitionFrame->common_sect_.dvutavr));
}
//---------------------------------------------------------------------------
//	Инициализация материала двутавра
//---------------------------------------------------------------------------
Steel TCompositeBeamMainForm::init_steel_i_section()
{
	STEEL_PARAM my_steel_param;
	TISectionInitialData i_section=init_i_section();//требуется для получения максимально толщины двутавра

	int rc;
	char title[8]="";
	double E=0.0;
	double G=0.0;
	double nu=0.0;
	double dens=0.0;
	double gamma_m=0.0;
	double R_yn=0.0;
	double R_un=0.0;

	double t_max = i_section.t_uf_;
	char* str=((AnsiString)DefineSteelForm->ComboBox_steel->Text).c_str();

	bool  flag_diag_thick=false;//для чего этот флаг

	rc=Steel_param(str, t_max, &my_steel_param, flag_diag_thick);
	if(rc!=0)
		return Steel();//что возвращать из функции если Steel_param вернул ошибку?
	R_yn =  my_steel_param.Ryn;
	R_un =  my_steel_param.Run;
	strcpy(title, my_steel_param.title);

    String_double_plus(DefineSteelForm->Label3->Caption, DefineSteelForm->Edit_E->Text, &E);
	String_double_zero_plus(DefineSteelForm->Label4->Caption, DefineSteelForm->Edit_G->Text, &G);
	String_double_plus(DefineSteelForm->Label5->Caption, DefineSteelForm->Edit_nu->Text, &nu);
	String_double_zero_plus(DefineSteelForm->Label_gamma_m->Caption, DefineSteelForm->Edit_gamma_m->Text, &gamma_m);

	return Steel(title, E, G, nu, gamma_m,R_yn,R_un);
}
//---------------------------------------------------------------------------
//Инициализация железобетонной части сечения
//---------------------------------------------------------------------------
TConcretePart* TCompositeBeamMainForm::init_concrete_part()
{
	if (rdgrp_slab_type->ItemIndex==0)
	{
		int rc=0; //rc- return code -код ошибки
		double t_sl=.0;
		rc=String_double_plus(lbl_flat_slab_thickness->Caption, edt_flat_slab_thickness->Text, &t_sl);
		return new TFlatSlab(ConcreteDefinitionForm->get_concrete(),
							 RebarDefinitionForm->get_rebar(),
							 t_sl);
	}
	else
	{
	   return new TCorrugatedSlab(ConcreteDefinitionForm->get_concrete(),
								  RebarDefinitionForm->get_rebar());
	}
}
//---------------------------------------------------------------------------
//	Инициализация упоров
//---------------------------------------------------------------------------
TStud TCompositeBeamMainForm::init_stud()
{
	 return StudDefinitionForm->get_stud();
}
//---------------------------------------------------------------------------
//	Инициализация коэффициентов условий работы
//---------------------------------------------------------------------------
 WorkingConditionsFactors TCompositeBeamMainForm::init_working_conditions_factors()
 {
	double gamma_bi=0.0;
	double gamma_si=0.0;
	double gamma_c=0.0;

	String_double_plus(lbl_gamma_bi->Caption, edt_gamma_bi->Text, &gamma_bi);
	String_double_plus(lbl_gamma_si->Caption, edt_gamma_si->Text, &gamma_si);
	String_double_plus(lbl_gamma_c->Caption, edt_gamma_c->Text, &gamma_c);

	return WorkingConditionsFactors(gamma_bi,gamma_si,gamma_c);
 }
// ---------------------------------------------------------------------------
// Инициализация композитного сечения
//---------------------------------------------------------------------------
 CompositeSection TCompositeBeamMainForm::init_composite_section(
											TGeometry geometry,
											Steel steel_i_section,
											TISectionInitialData i_section_initial_data,
											TConcretePart* concrete_part)
{
	return CompositeSection(geometry,
							steel_i_section,
							i_section_initial_data,
							concrete_part);
}
// ---------------------------------------------------------------------------
// Инициализация композитной балки
//---------------------------------------------------------------------------
void TCompositeBeamMainForm::init_composite_beam(TGeometry 				  geometry,
												 TLoads 				  loads,
												 CompositeSection 		  composite_section,
												 TStud 					  stud,
												 WorkingConditionsFactors working_conditions_factors)
{
 composite_beam_=TCompositeBeam(geometry,
								loads,
								composite_section,stud,
								working_conditions_factors);
}
//---------------------------------------------------------------------------
//	Функция запускающая расчёт композитной балки
//---------------------------------------------------------------------------
void __fastcall TCompositeBeamMainForm::BtnCalculateClick(TObject *Sender)
{
	calculate_composite_beam();
}
//---------------------------------------------------------------------------
//Сформировать и открыть отчёт
//---------------------------------------------------------------------------
void __fastcall TCompositeBeamMainForm::btn_reportClick(TObject *Sender)
{
	Screen->Cursor = crHourGlass;//На время создания отчёта присвоем курсору вид часов
	generate_report();
	Screen->Cursor = crDefault;//Возвращаем курсору вид по умолчанию
}
//---------------------------------------------------------------------------
//	Активация контролов для внесения данных о бетонном сечении в зависимости
//	от выбранного типа: плита по настилу или плоская плита
//---------------------------------------------------------------------------
void __fastcall TCompositeBeamMainForm::rdgrp_slab_typeClick(TObject *Sender)
{
	switch(rdgrp_slab_type->ItemIndex)
	{
		case 0: grp_bx_corrugated_slab->Visible=false;
				grp_bx_flat_slab->Visible=true;
				break;

	   case 1:	grp_bx_corrugated_slab->Visible=true;
				grp_bx_flat_slab->Visible=false;
				break;
	}
		OnControlsChange(Sender);
}
//---------------------------------------------------------------------------
//Обработчик события обеспечивающий заполнение первой строки жирным шрифтом
//---------------------------------------------------------------------------
void __fastcall TCompositeBeamMainForm::strng_grd_rendering(TObject *Sender,
																int ACol, int ARow,
																TRect &Rect, TGridDrawState State)
{
	TStringGrid* str_grid=static_cast<TStringGrid*>(Sender);
	if (ARow ==0)
	{
		str_grid->Canvas->Font->Style=TFontStyles()<< fsBold;
		str_grid->Canvas->Font->Style<<fsBold;
		str_grid->Canvas->FillRect(Rect);
		str_grid->Canvas->TextOut(Rect.Left+3, Rect.Top+5, str_grid->Cells[ACol][ARow]);
	}
}
//---------------------------------------------------------------------------
//	Функция заполняющая TStringGrid выводящий результаты расчёта геометрических характеристик композитного сечения
//---------------------------------------------------------------------------
void TCompositeBeamMainForm::cotr_comp_sect_geometr_grid()
{
	strng_grd_compos_sect_geom_character->Cells [0][0]=L"Геометрические характеристики";
	strng_grd_compos_sect_geom_character->Cells [1][0]=L"Значения";
	strng_grd_compos_sect_geom_character->Cells [0][1]=L"Площадь Ared, [мм2]";
	strng_grd_compos_sect_geom_character->Cells [0][2]=L"Момент инерции Ired, [мм4]";
	strng_grd_compos_sect_geom_character->Cells [0][3]=L"Момент сопротивления, верхн. полка W_f2_red, [мм3]";
	strng_grd_compos_sect_geom_character->Cells [0][4]=L"Момент сопротивления, нижн. полка W_f1_red, [мм3]";
	strng_grd_compos_sect_geom_character->Cells [0][5]=L"Расстояние Z_b_st, [мм]";
	strng_grd_compos_sect_geom_character->Cells [0][6]=L"Расстояние Z_b_st, [мм]";
	strng_grd_compos_sect_geom_character->Cells [0][6]=L"Собственный вес, [кг/м]";
}
//---------------------------------------------------------------------------
//Функция заполняющая объект TStringGrid геометрическими характеристиками стального сечения
//---------------------------------------------------------------------------
void TCompositeBeamMainForm::cotr_steel_sect_geometr_grid()
{
	strng_grd_steel_sect_geom_character->Cells [0][0]=L"Геометрические характеристики";
	strng_grd_steel_sect_geom_character->Cells [1][0]=L"Значения";
	strng_grd_steel_sect_geom_character->Cells [0][1]=L"Площадь";
	strng_grd_steel_sect_geom_character->Cells [0][2]=L"Момент инерции";
	strng_grd_steel_sect_geom_character->Cells [0][3]=L"Момент сопротивления крайних волокон верхней полки";
	strng_grd_steel_sect_geom_character->Cells [0][4]=L"Момент сопротивления крайних волокон нижней полки";
	strng_grd_steel_sect_geom_character->Cells [0][5]=L"Расстояние от Ц.Т. до наружной грани верхней полки";
	strng_grd_steel_sect_geom_character->Cells [0][6]=L"Расстояние от Ц.Т. до наружной грани нижней полки";
}
//---------------------------------------------------------------------------
//Функция заполняющая объект TStringGrid геометрическими характеристиками железобетонного сечения
//---------------------------------------------------------------------------
void TCompositeBeamMainForm::ctor_concrete_sect_geometr_grid()
{
	strng_grd_concrete_sect_geom_character->Cells [0][0]=L"Геометрические характеристики";
	strng_grd_concrete_sect_geom_character->Cells [1][0]=L"Значения";
	strng_grd_concrete_sect_geom_character->Cells [0][1]=L"Расчётная величина свеса слева";
	strng_grd_concrete_sect_geom_character->Cells [0][2]=L"Расчётная величина свеса справа";
	strng_grd_concrete_sect_geom_character->Cells [0][3]=L"Расстояние от нижней грани до центра тяжести";
	strng_grd_concrete_sect_geom_character->Cells [0][4]=L"Площадь";
	strng_grd_concrete_sect_geom_character->Cells [0][5]=L"Момент инерции";
   //	strng_grd_concrete_sect_geom_character->Cells [0][6]=L"Момент сопротивления";
}
void TCompositeBeamMainForm::fill_steel_sect_geometr_grid()
{
	ISection i_section= composite_beam_.get_composite_section().get_steel_part();

	strng_grd_steel_sect_geom_character->Cells [1][1]=FloatToStrF(i_section.get_A_st(), ffFixed, 15, 0);
	strng_grd_steel_sect_geom_character->Cells [1][2]=FloatToStrF(i_section.get_I_st(), ffFixed, 15, 0);
	strng_grd_steel_sect_geom_character->Cells [1][3]=FloatToStrF(i_section.get_Wf2_st(), ffFixed, 15, 0);
	strng_grd_steel_sect_geom_character->Cells [1][4]=FloatToStrF(i_section.get_Wf1_st(), ffFixed, 15, 0);
	strng_grd_steel_sect_geom_character->Cells [1][5]=FloatToStrF(i_section.get_Z_f2_st(), ffFixed, 15, 0);
	strng_grd_steel_sect_geom_character->Cells [1][6]=FloatToStrF(i_section.get_Z_f1_st(), ffFixed, 15, 0);
}
void TCompositeBeamMainForm::fill_concrete_sect_geometr_grid()
{
	TConcretePart* concrete_part=composite_beam_.get_composite_section().get_concrete_part();

	strng_grd_concrete_sect_geom_character->Cells [1][1]=FloatToStrF(concrete_part->get_b_l(), ffFixed, 15, 0);
	strng_grd_concrete_sect_geom_character->Cells [1][2]=FloatToStrF(concrete_part->get_b_r(), ffFixed, 15, 0);
	strng_grd_concrete_sect_geom_character->Cells [1][3]=FloatToStrF(concrete_part->get_C_b(), ffFixed, 15, 0);
	strng_grd_concrete_sect_geom_character->Cells [1][4]=FloatToStrF(concrete_part->get_A_b(), ffFixed, 15, 0);
	strng_grd_concrete_sect_geom_character->Cells [1][5]=FloatToStrF(concrete_part->get_I_b(), ffFixed, 15, 0);
}
void TCompositeBeamMainForm::fill_composite_sect_geometr_grid()
{
	double A_red=composite_beam_.get_composite_section().get_A_red();
	double I_red=composite_beam_.get_composite_section().get_I_red();
	double W_f2_red=composite_beam_.get_composite_section().get_W_f2_red();
	double W_f1_red=composite_beam_.get_composite_section().get_W_f1_red();

	strng_grd_compos_sect_geom_character->Cells [1][1]=FloatToStrF(A_red, ffFixed, 15, 0); //Предельно значение точность для
	strng_grd_compos_sect_geom_character->Cells [1][2]=FloatToStrF(I_red, ffFixed, 15, 0); //типа double 15
	strng_grd_compos_sect_geom_character->Cells [1][3]=FloatToStrF(W_f2_red, ffFixed, 15, 0);
	strng_grd_compos_sect_geom_character->Cells [1][4]=FloatToStrF(W_f1_red, ffFixed, 15, 0);

}

void TCompositeBeamMainForm::fill_results_grid()
{

}
//---------------------------------------------------------------------------
//	Функция заполняющая Grid выводящий результаты расчёта композитной балки
//---------------------------------------------------------------------------
void TCompositeBeamMainForm:: cotr_ratios_grid()
{
strngGrdResults->Cells [0][0]="Проверка";
strngGrdResults->Cells [0][1]="Расчёт по прочности на действие изгибающих моментов, раздел 6.2.1";
strngGrdResults->Cells [0][2]="Расчёт по прочности на действие поперечной силы, раздел 6.2.2 ";
strngGrdResults->Cells [0][3]="Расчёт конструкций объединения железобетонной плиты со стальной балкой, раздел 6.2.4";
strngGrdResults->Cells [1][0]="Коэффициенты Использования (КИ) ";
strngGrdResults->Cells [1][1]="0.89";
strngGrdResults->Cells [1][2]="0.33";
strngGrdResults->Cells [1][3]="0.89";
}
//---------------------------------------------------------------------------
//	Функция заполняющая ComboBox случаями загружений
//---------------------------------------------------------------------------
void TCompositeBeamMainForm::fill_cmb_bx_LC()
{
	   //Метод AddItem, связывающий TStrings с объектами требуется в качестве параметра объект TObject
	cmb_bx_LC->Items->Insert(static_cast<int>(Impact::SW), "Собственный Вес");
	cmb_bx_LC->Items->Insert(static_cast<int>(Impact::DL_I) , "Постоянная Нагрузка I стадия");
	cmb_bx_LC->Items->Insert(static_cast<int>(Impact::DL_II), "Постоянная Нагрузка II стадия");
	cmb_bx_LC->Items->Insert(static_cast<int>(Impact::LL), "Временная Нагрузка");
	cmb_bx_LC->Items->Insert(static_cast<int>(Impact::I_stage), "Расчётные Нагрузки I стадии");
	cmb_bx_LC->Items->Insert(static_cast<int>(Impact::II_stage), "Расчётные Нагрузки II стадии");
	cmb_bx_LC->Items->Insert(static_cast<int>(Impact::Total), "Расчётные Нагрузки");
	cmb_bx_LC->ItemIndex = (int)Impact::SW;
}

//---------------------------------------------------------------------------

void __fastcall TCompositeBeamMainForm::BtBtnSteelChoiceClick(TObject *Sender)
{
	 //SteelDefinitionForm->ShowModal();
	 //PnlSteelViewer->Caption = SteelDefinitionForm->ComboBox_steel->Text;
	 DefineSteelForm->ShowModal();
	 PnlSteelViewer->Caption = DefineSteelForm->ComboBox_steel->Text;

}
//---------------------------------------------------------------------------



void __fastcall TCompositeBeamMainForm::BtnSteelSectionChoiceClick(TObject *Sender)
{
	SteelSectionForm->ShowModal();
	Pnl_SteelSectionViewer->Caption = SteelSectionForm->SteelSectionDefinitionFrame->ComboBox_profil->Text;
}
//---------------------------------------------------------------------------


void __fastcall TCompositeBeamMainForm::BtBtnExitClick(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

void __fastcall TCompositeBeamMainForm::BtnConcreteChoiceClick(TObject *Sender)
{
	ConcreteDefinitionForm->ShowModal();//После закрытия формы выполняется следующая строчка устанавливающая значение ComboBox в Panel
	pnl_concrete_grade->Caption = ConcreteDefinitionForm->cmb_bx_concrete_grade_list->Text;
}
//---------------------------------------------------------------------------

void __fastcall TCompositeBeamMainForm::BtBtnRebarsChoiceClick(TObject *Sender)
{
	RebarDefinitionForm->ShowModal();
	//Синхронизация текста на pnl и расчётных данных
	if(pnl_rebar_viewer->Caption!=RebarDefinitionForm->get_rebar().get_grade())
		pnl_rebar_viewer->Caption=RebarDefinitionForm->get_rebar().get_grade();
}
//---------------------------------------------------------------------------

void __fastcall TCompositeBeamMainForm::BtBtnShearStudsChoiceClick(TObject *Sender)
{
	StudDefinitionForm->ShowModal();
	//Синхронизация текста на pnl и расчётных данных
	if(pnl_shear_stud_viewer->Caption!=StudDefinitionForm->get_stud().get_name())
		pnl_shear_stud_viewer->Caption=StudDefinitionForm->get_stud().get_name();
}
//---------------------------------------------------------------------------

void __fastcall TCompositeBeamMainForm::NOutReportClick(TObject *Sender)
{
	generate_report();
}
//---------------------------------------------------------------------------

void __fastcall TCompositeBeamMainForm::NExitClick(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
//Создание отчёта
//---------------------------------------------------------------------------
void TCompositeBeamMainForm::generate_report()
{
	TWord_Automation report_=TWord_Automation("ReportCompositeBeam.docx");
	TGeometry geometry=composite_beam_.get_geometry();
	TLoads loads=composite_beam_.get_loads();
	ISection i_section= composite_beam_.get_composite_section().get_steel_part();
	TConcretePart* concrete_part=composite_beam_.get_composite_section().get_concrete_part();
	Concrete concrete=concrete_part->get_concrete();
	Rebar rebar=concrete_part->get_rebar();
	Steel steel=composite_beam_.get_composite_section().get_steel_grade();
	TStud studs=composite_beam_.get_studs();
	
//[1.1] Топология
	report_.PasteTextPattern("Нет", "%end_beam%");
	report_.PasteTextPattern(FloatToStr(geometry.get_span(LengthUnit::mm)), "%span%");
	report_.PasteTextPattern(FloatToStr(geometry.get_trib_width_left(LengthUnit::mm)), "%trib_width_left% ");
	report_.PasteTextPattern(FloatToStr(geometry.get_trib_width_right(LengthUnit::mm)), "%trib_width_right% ");
//[1.2] Загружения
	report_.PasteTextPattern(FloatToStr(loads.get_dead_load_first_stage(LoadUnit::kN, LengthUnit::m)), "%DL_I%");
	report_.PasteTextPattern(FloatToStr(loads.get_dead_load_second_stage(LoadUnit::kN, LengthUnit::m)), "%DL_II%");
	report_.PasteTextPattern(FloatToStr(loads.get_live_load(LoadUnit::kN, LengthUnit::m)), "%LL%");

//[1.3] Коэффициенты надёжности по нагрузке
	report_.PasteTextPattern(FloatToStr(loads.get_gamma_f_st_SW()), "%gamma_f_st_SW%");
	report_.PasteTextPattern(FloatToStr(loads.get_gamma_f_DL_I()), "%gamma_f_DL_I%");
	report_.PasteTextPattern(FloatToStr(loads.get_gamma_f_DL_II()), "%gamma_f_DL_II%");
	report_.PasteTextPattern(FloatToStr(loads.get_gamma_f_LL()), "%gamma_f_LL%");
//[1.1] Стальное сечение
//[1.1.1] Номинальные размеры двутавра
	report_.PasteTextPattern(i_section.get_profile_number(),"%profile_number%");
	report_.PasteTextPattern(i_section.get_h_st(LengthUnit::mm),"%h%");
	report_.PasteTextPattern(0,"%h%");
	report_.PasteTextPattern(i_section.get_b_uf(LengthUnit::mm),"%b%");
	report_.PasteTextPattern(0,"%b_w%");
	report_.PasteTextPattern(i_section.get_t_uf(LengthUnit::mm),"%t%");
	report_.PasteTextPattern(i_section.get_t_w(LengthUnit::mm),"%s%");
	report_.PasteTextPattern(i_section.get_r(LengthUnit::mm),"%r%");
//[1.1.2] Характеристики стали
	report_.PasteTextPattern(steel.get_steel_grade(),"%steel_grade%");
	report_.PasteTextPattern(steel.get_R_y(),"%R_yn%");
	report_.PasteTextPattern(steel.get_R_u(),"%R_un%");
	report_.PasteTextPattern(steel.get_E_s(),"%E%");
	report_.PasteTextPattern(steel.get_G_s(),"%G%");
	report_.PasteTextPattern(steel.get_nu(),"%nu%");
	report_.PasteTextPattern(steel.get_gamma_m(),"%gamma_m%");
//[1.2] Железобетонное сечение
//[1.2.1] Номинальные размеры плиты

//[1.2.2] Характеристики бетона

	report_.PasteTextPattern(concrete.get_grade(),"%conc_grade%");
	report_.PasteTextPattern(concrete.get_R_bn(),"%R_bn%");
	report_.PasteTextPattern(concrete.get_R_btn(),"%R_btn%");
	report_.PasteTextPattern(concrete.get_E_b(),"%E_b%");
	report_.PasteTextPattern(concrete.get_gamma_b(),"%gamma_b%");
	report_.PasteTextPattern(concrete.get_gamma_bt(),"%gamma_bt%");


//[1.3] Арматура
	report_.PasteTextPattern(rebar.get_grade(),"%grade%");
	report_.PasteTextPattern(rebar.get_diameter(),"%d%");
	report_.PasteTextPattern(rebar.get_R_s(),"%R_sn%");
//[1.4] Соединительные элементы
	report_.PasteTextPattern(studs.get_name(),"%name%");
	report_.PasteTextPattern(studs.get_l(LengthUnit::cm),"%l%");
	report_.PasteTextPattern(studs.get_d_an(LengthUnit::cm),"%d%");
	report_.PasteTextPattern(studs.get_R_y(),"%R_y%");
	report_.PasteTextPattern(studs.get_z_e(LengthUnit::cm),"%z_e%");
	report_.PasteTextPattern(studs.get_z_m(LengthUnit::cm),"%z_m%");
	report_.PasteTextPattern(studs.get_edge_rows_num(LengthUnit::cm),"%ed_rw_num%");
	report_.PasteTextPattern(studs.get_middle_rows_num(LengthUnit::cm),"%mid_rw_num%");


	
//[2] Результаты расчёта
//[2.1] Геометрические параметры
//[2.1.1] Стального сечения
	report_.PasteTextPattern(i_section.get_A_st(LengthUnit::cm),"%A_st%");
	report_.PasteTextPattern(i_section.get_I_st(LengthUnit::cm),"%I_st%");
	report_.PasteTextPattern(i_section.get_Wf2_st(LengthUnit::cm),"%Wf2_st%");
	report_.PasteTextPattern(i_section.get_Wf1_st(LengthUnit::cm),"%Wf1_st%");
	report_.PasteTextPattern(i_section.get_Z_f2_st(LengthUnit::cm),"%Z_f2_st%");
	report_.PasteTextPattern(i_section.get_Z_f1_st(LengthUnit::cm),"%Z_f1_st%");
//[2.1.2] Железобетонного сечения
	report_.PasteTextPattern(concrete_part->get_slab_type(),"%slab_type%");
	report_.PasteTextPattern(concrete_part->get_b_l(LengthUnit::cm),"%b_l%");
	report_.PasteTextPattern(concrete_part->get_b_r(LengthUnit::cm),"%b_r%");
	report_.PasteTextPattern(concrete_part->get_C_b(LengthUnit::cm),"%C_b%");
	report_.PasteTextPattern(concrete_part->get_A_b(LengthUnit::cm),"%A_b%");
	report_.PasteTextPattern(concrete_part->get_I_b(LengthUnit::cm),"%I_b%");


	





 
}

//---------------------------------------------------------------------------
// Отрисовка эпюр
//---------------------------------------------------------------------------
void TCompositeBeamMainForm::draw_diagram()
{
	TImage *Image1=img_static_scheme;
	//получаем вектор координат точек эпюры из объекта композитная балка
	std::vector<double> coor_epur=composite_beam_.get_CS_coordinates();
	//получаем вектор координат опор из объекта композитная балка
	std::vector<double>	coor_supp=composite_beam_.get_geometry().get_all_supports_coordinates();
	//определим суммарное количество опор (временных и постоянных)
	int n_supp=composite_beam_.get_geometry().get_permanent_supports_number()+
	composite_beam_.get_geometry().get_temporary_supports_number();
	//флаг отрисовки значений на эпюре
	bool flag_sign=true;
	if (rd_grp_internal_forces_type->ItemIndex==0)
	{
		//получаем вектор изгибающих моментов из объекта композитная балка
		std::vector<double> M=composite_beam_.get_internal_forces_LC()[static_cast<Impact>(cmb_bx_LC->ItemIndex)].get_M(LoadUnit::kN, LengthUnit::m);
		DrawEpur(Image1, M.size(), &coor_epur[0], &M[0], nullptr, n_supp, &coor_supp[0], flag_sign);
	}
	else
	{
		//получаем поперечные силы из объекта композитная балка
		std::vector<double> Q=composite_beam_.get_internal_forces_LC()[static_cast<Impact>(cmb_bx_LC->ItemIndex)].get_Q(LoadUnit::kN);
		std::vector<double> Q_jump=composite_beam_.get_internal_forces_LC()[static_cast<Impact>(cmb_bx_LC->ItemIndex)].get_Q_jump(LoadUnit::kN);
		DrawEpur(Image1, Q.size(), &coor_epur[0], &Q[0], &Q_jump[0], n_supp, &coor_supp[0], flag_sign);
	}


}

void __fastcall TCompositeBeamMainForm::cmb_bx_LCChange(TObject *Sender)
{
	draw_diagram();
}
//---------------------------------------------------------------------------

void __fastcall TCompositeBeamMainForm::rd_grp_internal_forces_typeClick(TObject *Sender)

{
	draw_diagram();
}

void TCompositeBeamMainForm::calculate_composite_beam()
{
   //проверка объекта и в случае его наличия будет вызван деструктор
   //проверка в nullptr  в concrete_section_
   //установить все объекты в ноль

   TGeometry geometry=init_geomet();//поле содержащее топологию
   TISectionInitialData i_section_initial_data=init_i_section();
   TLoads loads=init_loads();;//поле содержащее нагрузки и коэффициенты надёжности по нагрузкам
   TStud stud=init_stud(); //поле соержащее упоры Нельсона
   Steel steel_i_section=init_steel_i_section();
   WorkingConditionsFactors working_conditions_factors=init_working_conditions_factors();
   TConcretePart* concrete_part=init_concrete_part();//объект абстрактного класса, поэтому указатель!
   CompositeSection composite_section=init_composite_section(geometry,steel_i_section,i_section_initial_data,
																	concrete_part);
   init_composite_beam(geometry,loads,composite_section, stud,working_conditions_factors);
//Вывод результатов расчёта в GUI
	draw_diagram();
	fill_steel_sect_geometr_grid();
	fill_concrete_sect_geometr_grid();
	fill_composite_sect_geometr_grid();
	fill_results_grid();

//Вывод результатов расчёта в отчёт
	btn_report->Enabled=true;
	tb_results->TabVisible=true;
}
//---------------------------------------------------------------------------



void __fastcall TCompositeBeamMainForm::NNewClick(TObject *Sender)
{
	//@
	int i;
	if (modify_project) {
		 i=Application->MessageBox(L"Сохранить текущий проект?", L" ",
				  MB_YESNO | MB_ICONQUESTION);
		 if (i==IDYES) NSaveClick(Sender);
	}
	strcpy(ModelFile, UNTITLED);
	modify_project = false;

	Caption = "Расчет комбинированной балки - [Новый проект]";
	//@@
	//--------------------------------------------------------
	// Текст события

}
//---------------------------------------------------------------------------

void __fastcall TCompositeBeamMainForm::NSaveClick(TObject *Sender)
{
   //@
   //char * path;
   AnsiString File;

   //------------------------------------
   // Получение имени директории, в которой находится исполняемый модуль
   //unsigned long dword = GetModuleFileName(NULL, Path_gen, PATHLEN );
   //path = strrchr(Path_gen, '\\');
   //path[0] = '\0';

   if  (strcmp(ModelFile, UNTITLED)==0) {
	  if(SaveDialog_Model->Execute())
      {
		  File = SaveDialog_Model->FileName;
		  FileDir_Name = File;
		  ModelName(File.c_str(), ModelFile);
	  }
	  else return;
   }
   else
	   File = FileDir_Name;

   TFileStream* FS = new TFileStream(File, fmCreate);
   for(int i=0;i<CompositeBeamMainForm->ComponentCount;++i)
		FS->WriteComponent(CompositeBeamMainForm->Components[i]);
   delete(FS);
//	SaveComponent(File, CompositeBeamMainForm);
   Caption = "Расчет комбинированной балки - " + AnsiString(ModelFile);

   modify_project = false;
   //@@
}
//---------------------------------------------------------------------------

void __fastcall TCompositeBeamMainForm::NSaveAsClick(TObject *Sender)
{
	//@
	strcpy(ModelFile, UNTITLED);
	NSaveClick(Sender);
	//@@
}
//---------------------------------------------------------------------------
//@--------------------------------------------------------------------------
// Выделение из имени файла в имени модели
void ModelName(char * str0, char* ModelFile)
{
	  char *ptr1, *ptr2;
	  char i, str[240];

	  if  (strcmp(ModelFile, UNTITLED)==0) {
	   i= 240<strlen(str0) ? 240 : strlen(str0);
	   strcpy(str,str0);
	   ptr1 = strrchr(str,'\\');
	   ptr2 = strrchr(ptr1,'.');
	   if (ptr2!=NULL)
		 *ptr2='\0';
	   if (ptr1==NULL)
		 strcpy(ModelFile, str);
	   else
		 strcpy(ModelFile, ptr1+1);
	  }
}

void __fastcall TCompositeBeamMainForm::NOpenClick(TObject *Sender)
{

   NNewClick(Sender);

   if(OpenDialog_Model->Execute())
   {
	  FileDir_Name = OpenDialog_Model->FileName;
   }
   if (FileDir_Name!="") {

	  strcpy(ModelFile, UNTITLED);

	  TFileStream* FS = new TFileStream(FileDir_Name, fmOpenRead);
	  for(int i=0;i<CompositeBeamMainForm->ComponentCount;++i)
				 FS->ReadComponent(CompositeBeamMainForm->Components[i]);
	  delete(FS);
	 //LoadComponent(FileDir_Name, CompositeBeamMainForm);

	  ModelName(FileDir_Name.c_str(), ModelFile);

	  Caption = "Расчет комбинированной балки - " + AnsiString(ModelFile);

	  modify_project = false;

   }
   //@@


}
//---------------------------------------------------------------------------

void __fastcall TCompositeBeamMainForm::OnControlsChange(TObject *Sender)
{
	if (btn_report->Enabled)
		btn_report->Enabled=false;
	if(tb_results->TabVisible)
		tb_results->TabVisible=false;
}
//---------------------------------------------------------------------------

void __fastcall TCompositeBeamMainForm::chck_bx_end_beamClick(TObject *Sender)
{
	if (chck_bx_end_beam->Checked){
		lbl_trib_width_left->Caption="Свес плиты [мм]:";
		lbl_trib_width_right->Caption="Расстояние между балками [мм]:";
		}
	else{
		lbl_trib_width_left->Caption="Расстояние между балками слева [мм]:";
		lbl_trib_width_right->Caption="Расстояние между балками справа [мм]:";
	}
	OnControlsChange(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TCompositeBeamMainForm::CmbBxAnalysisTheoryChoiceChange(TObject *Sender)

{
    OnControlsChange(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TCompositeBeamMainForm::ComboBox2Change(TObject *Sender)
{
	OnControlsChange(Sender);
}

int __fastcall TCompositeBeamMainForm::LoadComponent(String filename, TComponent* Component)
{
	assert(Component!=nullptr);
	assert(Component->Owner!=nullptr);

	std::auto_ptr<TFileStream> fs (new TFileStream(filename, fmOpenRead));
	std::auto_ptr<TReader> Reader (new TReader(fs.get(), 4096));

	Reader->Root=Component->Owner;
	TControl* Control=dynamic_cast<TControl*>(Component);
	if(Control){
		Reader->Parent=Control->Parent;
	}

	delete Component;
	Component=nullptr;
	Reader->BeginReferences();
	try{
		Component=Reader->ReadComponent(nullptr);
	}

	__finally{
	Reader->FixupReferences();
	Reader->EndReferences();
	}
	return Reader->Position;
}
int __fastcall TCompositeBeamMainForm::SaveComponent(String filename, TComponent* Component)
{
	assert(Component!=nullptr);
	assert(Component->Owner!=nullptr);

	std::auto_ptr<TFileStream> fs (new TFileStream(filename, fmCreate));
	std::auto_ptr<TWriter> Writer (new TWriter(fs.get(), 4096));

	Writer->Root=Component->Owner;
	Writer->WriteComponent(Component);
	return Writer->Position;
}
//---------------------------------------------------------------------------



//---------------------------------------------------------------------------

void __fastcall TCompositeBeamMainForm::btn_loggerClick(TObject *Sender)
{
	FormLogger->Show();
}
//---------------------------------------------------------------------------

