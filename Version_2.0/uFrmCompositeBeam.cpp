//---------------------------------------------------------------------------
#include <vcl.h>
#include<ComObj.hpp>
#include <ostream>
#include <fstream>
#pragma hdrstop
#include<vector>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

#include "uFrmCompositeBeam.h"
#include "String_doubleUnit.h"
#include "uWord_Automation.h"
#include "uFrmAboutProg.h"
#include "uComposSectGeomSP35.h"
#include "uIntForcesCalculator.h"
#include "uComBeamInputSP35.h"

//---------------------------------------------------------------------------
std::unique_ptr<ComBeamOutputSP35 const> com_beam_output_SP35 {nullptr};
std::unique_ptr<ComBeamInputSP35 const> com_beam_input_SP35 {nullptr};

TCompositeBeamMainForm  *CompositeBeamMainForm;
//----------------------------------------------------------------------
 _fastcall TCompositeBeamMainForm ::TCompositeBeamMainForm (TComponent* Owner)
	: TForm(Owner), frm_logger_(new TFormLogger(this))
{
	cotr_ratios_grid();
	cotr_comp_sect_geometr_grid();
	cotr_steel_sect_geometr_grid();
	ctor_concrete_sect_geometr_grid();;
	fill_cmb_bx_impact();
	fill_cmb_bx_corrugated_sheets();
	modify_project = false;
}
//----------------------------------------------------------------------
void __fastcall TCompositeBeamMainForm::FormShow(TObject *Sender)
{

	update_GUI(cntrls_state_.rd_grp_code_);
	update_all_frms_cntrls();

	calculate_composite_beam();

}

//---------------------------------------------------------------------------
//	Функция запускающая расчёт композитной балки
//---------------------------------------------------------------------------
void __fastcall TCompositeBeamMainForm ::BtnCalculateClick(TObject *Sender)
{
	calculate_composite_beam();
	after_calculation();
}


//---------------------------------------------------------------------------
//Сформировать и открыть отчёт
//---------------------------------------------------------------------------
void __fastcall TCompositeBeamMainForm ::btn_reportClick(TObject *Sender)
{
	Screen->Cursor = crHourGlass;//На время создания отчёта присвоем курсору вид часов
	generate_report2();
	Screen->Cursor = crDefault;//Возвращаем курсору вид по умолчанию
}
//---------------------------------------------------------------------------
//	Активация контролов для внесения данных о бетонном сечении в зависимости
//	от выбранного типа: плита по настилу или плоская плита
//---------------------------------------------------------------------------
void __fastcall TCompositeBeamMainForm ::rdgrp_slab_typeClick(TObject *Sender)
{
	switch(rdgrp_slab_type -> ItemIndex)
	{
		case 0: grp_bx_corrugated_slab -> Visible = false;
				grp_bx_flat_slab -> Visible = true;
				Image2 -> Visible = false;
				Image1 -> Visible = true;
				break;

	   case 1:	grp_bx_corrugated_slab -> Visible = true;
				grp_bx_flat_slab -> Visible = false;
				Image2 -> Visible = true;
				Image1 -> Visible = false;
				break;
	}
		OnControlsChange(nullptr);
}

void __fastcall TCompositeBeamMainForm ::strng_grd_results_rendering(TObject *Sender,
																int ACol, int ARow,
																TRect &Rect, TGridDrawState State)
{
	TStringGrid* str_grid=static_cast<TStringGrid*>(Sender);
	if (ARow == 0)
	{
		str_grid -> Canvas -> Font -> Style = TFontStyles() << fsBold;
		str_grid -> Canvas -> TextOut(Rect.Left+3, Rect.Top+5, str_grid -> Cells[ACol][ARow]);
	}
	if (ARow == 1 && ACol == 0)
	{
		str_grid -> Canvas -> Font -> Style = TFontStyles() << fsBold << fsUnderline << fsItalic;
		str_grid -> Canvas -> TextOut(Rect.Left+3, Rect.Top+5, str_grid -> Cells[ACol][ARow]);
	}
	if (ARow == 4 && ACol == 0)
	{
		str_grid -> Canvas -> Font -> Style = TFontStyles() << fsBold << fsUnderline << fsItalic;
		str_grid -> Canvas -> TextOut(Rect.Left+3, Rect.Top+5, str_grid -> Cells[ACol][ARow]);
	}
	if (ARow == 9 && ACol == 0)
	{
		str_grid -> Canvas -> Font -> Style = TFontStyles() << fsBold << fsUnderline << fsItalic;
		str_grid -> Canvas -> TextOut(Rect.Left+3, Rect.Top+5, str_grid -> Cells[ACol][ARow]);
	}
	if (ARow == 12 && ACol == 0)
	{
		str_grid -> Canvas -> Font -> Style = TFontStyles() << fsBold << fsUnderline << fsItalic;
		str_grid -> Canvas -> TextOut(Rect.Left+3, Rect.Top+5, str_grid -> Cells[ACol][ARow]);
	}
	if (ARow == 15 && ACol == 0)
	{
		str_grid -> Canvas -> Font -> Style = TFontStyles() << fsBold << fsUnderline << fsItalic;
		str_grid -> Canvas -> TextOut(Rect.Left+3, Rect.Top+5, str_grid -> Cells[ACol][ARow]);
	}
	if (ARow == 1 && ACol == 1)
	{
		str_grid -> Canvas -> Brush -> Color = clBtnFace;
		str_grid -> Canvas -> FillRect(Rect);
	}
	if (ARow == 4 && ACol == 1)
	{
		str_grid -> Canvas -> Brush -> Color = clBtnFace;
		str_grid -> Canvas -> FillRect(Rect);
	}
	if (ARow == 9 && ACol == 1)
	{
		str_grid -> Canvas -> Brush -> Color = clBtnFace;
		str_grid -> Canvas -> FillRect(Rect);
	}
	if (ARow == 12 && ACol == 1)
	{
		str_grid -> Canvas -> Brush -> Color = clBtnFace;
		str_grid -> Canvas -> FillRect(Rect);
	}
	if (ARow == 15 && ACol == 1)
	{
		str_grid -> Canvas -> Brush -> Color = clBtnFace;
		str_grid -> Canvas -> FillRect(Rect);
	}

}
//---------------------------------------------------------------------------
//	Функция заполняющая TStringGrid выводящий результаты расчёта геометрических характеристик композитного сечения
//---------------------------------------------------------------------------
void TCompositeBeamMainForm ::cotr_comp_sect_geometr_grid()
{
	strng_grd_compos_sect_geom_character->Cells [0][0]=L"Геометрические характеристики";
	strng_grd_compos_sect_geom_character->Cells [1][0]=L"Значения";
	strng_grd_compos_sect_geom_character->Cells [0][1]=L"Площадь, мм2";
	strng_grd_compos_sect_geom_character->Cells [0][2]=L"Момент инерции, мм4 ";
	strng_grd_compos_sect_geom_character->Cells [0][3]=L"Момент сопротивления Ц.Т. ж.б. плиты, мм3";
	strng_grd_compos_sect_geom_character->Cells [0][4]=L"Расстояние от Ц.Т. до Ц.Т. бетона, мм";
	strng_grd_compos_sect_geom_character->Cells [0][5]=L"Расстояние от Ц.Т. до Ц.Т. стали мм";
	strng_grd_compos_sect_geom_character->Cells [0][6]=L"Расстояние от Ц.Т. стали до Ц.Т. бетона мм";
}
//---------------------------------------------------------------------------
//Функция заполняющая объект TStringGrid геометрическими характеристиками стального сечения
//---------------------------------------------------------------------------
void TCompositeBeamMainForm ::cotr_steel_sect_geometr_grid()
{
	strng_grd_steel_sect_geom_character->Cells [0][0]=L"Геометрические характеристики";
	strng_grd_steel_sect_geom_character->Cells [1][0]=L"Значения";
	strng_grd_steel_sect_geom_character->Cells [0][1]=L"Площадь, мм2";
	strng_grd_steel_sect_geom_character->Cells [0][2]=L"Момент инерции, мм4";
	strng_grd_steel_sect_geom_character->Cells [0][3]=L"Момент сопротивления крайних волокон в.полки, мм3";
	strng_grd_steel_sect_geom_character->Cells [0][4]=L"Момент сопротивления крайних волокон н.полки, мм3";
	strng_grd_steel_sect_geom_character->Cells [0][5]=L"Расстояние Zf2,st, мм";
	strng_grd_steel_sect_geom_character->Cells [0][6]=L"Расстояние Zf1,st, мм";
}
//---------------------------------------------------------------------------
//Функция заполняющая объект TStringGrid геометрическими характеристиками железобетонного сечения
//---------------------------------------------------------------------------
void TCompositeBeamMainForm ::ctor_concrete_sect_geometr_grid()
{
	strng_grd_concrete_sect_geom_character->Cells [0][0]=L"Геометрические характеристики";
	strng_grd_concrete_sect_geom_character->Cells [1][0]=L"Значения";
	strng_grd_concrete_sect_geom_character->Cells [0][1]=L"Расчётная ширина, мм";
	strng_grd_concrete_sect_geom_character->Cells [0][2]=L"Расстояние от нижней грани до центра тяжести, мм";
	strng_grd_concrete_sect_geom_character->Cells [0][3]=L"Площадь, мм2";
	strng_grd_concrete_sect_geom_character->Cells [0][4]=L"Момент инерции, мм4";
   //	strng_grd_concrete_sect_geom_character->Cells [0][6]=L"Момент сопротивления";
}
void TCompositeBeamMainForm ::update_grids(int code_index)
{
	update_steel_sect_geometr_grid(code_index);
	update_concrete_sect_geometr_grid(code_index);
	update_composite_sect_geometr_grid(code_index);
	update_results_grid(code_index);
}

void TCompositeBeamMainForm ::update_steel_sect_geometr_grid(int code_indx)
{
	switch (code_indx) {

	case(0):

		break;
	case(1):
		com_beam_output_SP35 -> com_sect().st_sect() ->
			fill_grid(strng_grd_steel_sect_geom_character);
		break;
	}

}
void TCompositeBeamMainForm ::update_concrete_sect_geometr_grid(int code_indx)
{
	switch (code_indx) {

	case(0):

		break;
	case(1):
		com_beam_output_SP35 -> com_sect().conc_sect() ->
			fill_grid(strng_grd_concrete_sect_geom_character);
		break;
	}
}
void TCompositeBeamMainForm ::update_composite_sect_geometr_grid(int code_indx)
{
	switch (code_indx) {

	case(0):

		break;
	case(1):
		com_beam_output_SP35 -> com_sect().fill_grid(strng_grd_compos_sect_geom_character);
		break;
	}
}
void TCompositeBeamMainForm ::update_results_grid(int code_indx)
{
	switch (code_indx) {

	case(0):

		break;
	case(1):
		com_beam_output_SP35 -> fill_grid(strng_grd_results);
		break;
	}

}

void TCompositeBeamMainForm ::fill_results_grid()
{
//	Section max_i_section_ratio_section = composite_beam_calculator_.get_composite_beam().get_max_i_section_ratio_section();
//
//	strng_grd_results -> Cells [1][2] = FloatToStrF(std::abs(max_i_section_ratio_section.get_x()), ffFixed, 15, 0);
//	strng_grd_results -> Cells [1][3] = FloatToStrF(std::abs(max_i_section_ratio_section.get_i_section_ratio()), ffFixed, 15, 2);
//	Section max_direct_stress_ratio_section = composite_beam_calculator_.get_composite_beam().get_max_direct_stress_ratio_section();
//
//	strng_grd_results -> Cells [1][5] = FloatToStrF(std::abs(max_direct_stress_ratio_section.get_x()), ffFixed, 15, 0);
//	strng_grd_results -> Cells [1][6] = FloatToStrF(std::abs(max_direct_stress_ratio_section.get_upper_fl_ratio()), ffFixed, 15, 2);
//	strng_grd_results -> Cells [1][7] = FloatToStrF(std::abs(max_direct_stress_ratio_section.get_lower_fl_ratio()), ffFixed, 15, 2);
//	strng_grd_results -> Cells [1][8] = FloatToStrF(std::abs(max_direct_stress_ratio_section.get_conc_ratio()), ffFixed, 15, 2);
//
//	Section max_rigid_plastic_ratio_section = composite_beam_calculator_.get_composite_beam().get_max_rigid_plastic_ratio_section();
//
//	strng_grd_results -> Cells [1][10] = FloatToStrF(std::abs(max_rigid_plastic_ratio_section.get_x()), ffFixed, 15, 0);
//	strng_grd_results -> Cells [1][11] = FloatToStrF(std::abs(max_rigid_plastic_ratio_section.get_rigid_plastic_ratio()), ffFixed, 15, 2);
//
//	Section max_shear_stress_section = composite_beam_calculator_.get_composite_beam().get_max_shear_stress_ratio_section();
//
//	strng_grd_results -> Cells [1][13] = FloatToStrF(std::abs(max_shear_stress_section .get_x()), ffFixed, 15, 0);
//	strng_grd_results -> Cells [1][14] = FloatToStrF(std::abs(max_shear_stress_section.get_shear_ratio()), ffFixed, 15, 2);
//
//	StudsRow max_ratio_studs_row = composite_beam_calculator_.get_studs_on_beam().get_max_ratio_studs_row();
//
//	strng_grd_results -> Cells [1][16] = FloatToStrF(std::abs(max_ratio_studs_row.get_x()), ffFixed, 15, 0);
//	strng_grd_results -> Cells [1][17] = FloatToStrF(std::abs(max_ratio_studs_row.get_ratio()), ffFixed, 15, 2);
}
//---------------------------------------------------------------------------
//	Функция заполняющая Grid выводящий результаты расчёта композитной балки
//---------------------------------------------------------------------------
void TCompositeBeamMainForm::cotr_ratios_grid()
{
	strng_grd_results -> Cells [0][0] = L"Проверка";
	strng_grd_results -> Cells [0][1] = L"На действие изгибающих моментов при монтаже";
	strng_grd_results -> Cells [0][2] = L"      Координата критического сечения, мм";
	strng_grd_results -> Cells [0][3] = L"      Прочность";
	strng_grd_results -> Cells [0][4] = L"На действие изгибающих моментов, раздел 6.2.1:";
	strng_grd_results -> Cells [0][5] = L"      Координата критического сечения, мм";
	strng_grd_results -> Cells [0][6] = L"      Прочность верхнего пояса стального сечения";
	strng_grd_results -> Cells [0][7] = L"      Прочность нижнего пояса стального сечения";
	strng_grd_results -> Cells [0][8] = L"      Прочность железобетона";
	strng_grd_results -> Cells [0][9] = L"На действие изгибающих моментов (жёсткопластический материал), пункт 6.2.1.6:";
	strng_grd_results -> Cells [0][10] = L"      Координата критического сечения, мм";
	strng_grd_results -> Cells [0][11] = L"      Прочность балки";
	strng_grd_results -> Cells [0][12] = L"Прочности на действие поперечной силы:";
	strng_grd_results -> Cells [0][13] = L"      Координата критического сечения, мм";
	strng_grd_results -> Cells [0][14] = L"      Прочность сечения, раздел 6.2.2";
	strng_grd_results -> Cells [0][15] = L"Упоров объединения, раздел 9.1.2";
	strng_grd_results -> Cells [0][16] = L"      Координата критического упора, мм";
	strng_grd_results -> Cells [0][17] = L"      Прочность упора";

	strng_grd_results -> Cells [1][0] = L"Коэффициенты Использования (КИ) ";
}
//---------------------------------------------------------------------------
//	Функция заполняющая ComboBox случаями загружений
//---------------------------------------------------------------------------
void TCompositeBeamMainForm ::fill_cmb_bx_impact()
{
	cmb_bx_impact -> Items -> Append(L"Воздействие 1a");
	cmb_bx_impact -> Items -> Append(L"Воздействие 1b");
	cmb_bx_impact -> Items -> Append(L"Воздействие 2c");
	cmb_bx_impact -> Items -> Append(L"Воздействие 2d");
	cmb_bx_impact -> Items -> Append(L"Воздействие: 1b + 2c + 2d");

	cmb_bx_impact -> ItemIndex = 4;
}
//---------------------------------------------------------------------------
//	Функция заполняющая ComboBox настилами
//---------------------------------------------------------------------------
void TCompositeBeamMainForm ::fill_cmb_bx_corrugated_sheets()
{
	for(auto corrugated_sheet:CorrugatedSheetsData::get_corrugated_sheet_names())
		cmb_bx_corrugated_sheeting_part_number->Items->Add(corrugated_sheet);

	cmb_bx_corrugated_sheeting_part_number->ItemIndex = 0;
}
//---------------------------------------------------------------------------

void __fastcall TCompositeBeamMainForm ::BtBtnSteelChoiceClick(TObject *Sender)
{
	 DefineSteelForm -> ShowModal();
	 pnl_steel -> Caption = DefineSteelForm -> info();
}
//---------------------------------------------------------------------------

void __fastcall TCompositeBeamMainForm ::BtnSteelSectionChoiceClick(TObject *Sender)
{
	SteelSectionForm -> ShowModal();
	pnl_steel_section_viewer -> Caption = SteelSectionForm -> info();

}
//---------------------------------------------------------------------------


void __fastcall TCompositeBeamMainForm ::BtBtnExitClick(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

void __fastcall TCompositeBeamMainForm ::BtnConcreteChoiceClick(TObject *Sender)
{
	ConcreteDefinitionForm -> ShowModal();
	pnl_concrete_grade -> Caption = ConcreteDefinitionForm -> info();
}
//---------------------------------------------------------------------------

void __fastcall TCompositeBeamMainForm ::BtBtnRebarsChoiceClick(TObject *Sender)
{
	RebarDefinitionForm -> ShowModal();
	pnl_rebar_viewer -> Caption = RebarDefinitionForm -> info();
}
//---------------------------------------------------------------------------

void __fastcall TCompositeBeamMainForm ::BtBtnShearStudsChoiceClick(TObject *Sender)
{
	StudDefinitionForm -> Show();
}
//---------------------------------------------------------------------------

void __fastcall TCompositeBeamMainForm ::NOutReportClick(TObject *Sender)
{
	generate_report2();
}
//---------------------------------------------------------------------------

void __fastcall TCompositeBeamMainForm ::NExitClick(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
//Создание отчёта
//---------------------------------------------------------------------------
void TCompositeBeamMainForm ::generate_report()
{
//	TWord_Automation report_ = TWord_Automation("ReportCompositeBeam.dotx");
//
////[1.1] Топология
//	Geometry geometry = composite_beam_calculator_.get_geometry();
//
//	report_.PasteTextPattern(geometry.is_end_beam_to_str(), "%end_beam%");
//	report_.PasteTextPattern(FloatToStrF(geometry.get_span(LengthUnit::mm), ffFixed, 15, 2), "%span%");
//	report_.PasteTextPattern(FloatToStrF(geometry.get_spacing_left(LengthUnit::mm), ffFixed, 15, 2), "%trib_width_left% ");
//	report_.PasteTextPattern(FloatToStrF(geometry.get_spacing_right(LengthUnit::mm), ffFixed, 15, 2), "%trib_width_right% ");
////[1.2] Загружения
//	Loads loads = composite_beam_calculator_.get_loads();
//
//	report_.PasteTextPattern(FloatToStrF(loads.get_self_weight(LoadUnit::kN, LengthUnit::m), ffFixed, 15, 2), "%steel_beam%");
//	report_.PasteTextPattern(FloatToStrF(loads.get_self_weight_sheets(LoadUnit::kN, LengthUnit::m), ffFixed, 15, 2), "%SW_sheets%");
//	report_.PasteTextPattern(FloatToStrF(loads.get_SW_concrete(LoadUnit::kN, LengthUnit::m), ffFixed, 15, 2), "%SW_concrete%");
//	report_.PasteTextPattern(FloatToStrF(loads.get_SW_add_concrete(LoadUnit::kN, LengthUnit::m), ffFixed, 15, 2), "%SW_add_concrete%");
//	report_.PasteTextPattern(FloatToStrF(loads.get_dead_load_first_stage(LoadUnit::kN, LengthUnit::m), ffFixed, 15, 2), "%DL_I%");
//	report_.PasteTextPattern(FloatToStrF(loads.get_dead_load_second_stage(LoadUnit::kN, LengthUnit::m), ffFixed, 15, 2), "%DL_II%");
//	report_.PasteTextPattern(FloatToStrF(loads.get_live_load(LoadUnit::kN, LengthUnit::m), ffFixed, 15, 2), "%LL%");
//
////[1.3] Коэффициенты надёжности по нагрузке
//
//	report_.PasteTextPattern(FloatToStrF(loads.get_gamma_f_st_SW(), ffFixed, 15, 2), "%gamma_f_st_SW%");
//	report_.PasteTextPattern(FloatToStrF(loads.get_gamma_f_concrete_SW(), ffFixed, 15, 2), "%gamma_f_concrete_SW%");
//	report_.PasteTextPattern(FloatToStrF(loads.get_gamma_f_add_concrete_SW(), ffFixed, 15, 2), "%SW gamma_f_add_concr%");
//	report_.PasteTextPattern(FloatToStrF(loads.get_gamma_f_DL_I(), ffFixed, 15, 2), "%gamma_f_DL_I%");
//	report_.PasteTextPattern(FloatToStrF(loads.get_gamma_f_DL_II(), ffFixed, 15, 2), "%gamma_f_DL_II%");
//	report_.PasteTextPattern(FloatToStrF(loads.get_gamma_f_LL(), ffFixed, 15, 2), "%gamma_f_LL%");
////[1.4] Стальное сечение
////[1.4.1] Номинальные размеры двутавра
//	ISection i_section = composite_beam_calculator_.get_composite_section().get_steel_part().get_section();
//
//	report_.PasteTextPattern(i_section.get_profile_number(),"%profile_number%");
//	report_.PasteTextPattern(FloatToStrF(i_section.get_h_st(LengthUnit::mm), ffFixed, 15, 2),"%h%");
//	report_.PasteTextPattern(FloatToStrF(0, ffFixed, 15, 2),"%h%");
//	report_.PasteTextPattern(FloatToStrF(i_section.get_b_uf(LengthUnit::mm), ffFixed, 15, 2),"%b%");
//	report_.PasteTextPattern(FloatToStrF(0, ffFixed, 15, 2),"%b_w%");
//	report_.PasteTextPattern(FloatToStrF(i_section.get_t_uf(LengthUnit::mm), ffFixed, 15, 2),"%t%");
//	report_.PasteTextPattern(FloatToStrF(i_section.get_t_w(LengthUnit::mm), ffFixed, 15, 2),"%s%");
//	report_.PasteTextPattern(FloatToStrF(i_section.get_r(LengthUnit::mm), ffFixed, 15, 2),"%r%");
////[1.4.2] Характеристики стали
//	Steel steel = composite_beam_calculator_.get_composite_section().get_steel_part().get_steel();
//
//	report_.PasteTextPattern(steel.get_steel_grade(),"%steel_grade%");
//	report_.PasteTextPattern(FloatToStrF(steel.get_R_yn(), ffFixed, 15, 2),"%R_yn%");
//	report_.PasteTextPattern(FloatToStrF(steel.get_R_un(), ffFixed, 15, 2),"%R_un%");
//	report_.PasteTextPattern(FloatToStrF(steel.get_E_st(), ffFixed, 15, 2),"%E_st%");
//	report_.PasteTextPattern(FloatToStrF(steel.get_G_st(), ffFixed, 15, 2),"%G_st%");
//	report_.PasteTextPattern(FloatToStrF(steel.get_nu_st(), ffFixed, 15, 2),"%nu_st%");
//	report_.PasteTextPattern(FloatToStrF(steel.get_gamma_m(), ffFixed, 15, 2),"%gamma_m%");
////[1.5] Железобетонное сечение
////[1.5.1] Номинальные размеры плиты
//	ConcretePart concrete_part = composite_beam_calculator_.get_composite_section().get_concrete_part();
//
//	report_.PasteTextPattern(concrete_part.get_slab_type(),"%slab_type%");
//	report_.PasteTextPattern(concrete_part.get_h_n(LengthUnit::cm),"%h_n%");
//	report_.PasteTextPattern(concrete_part.get_h_f(LengthUnit::cm),"%t_sl%");
//
////[1.5.2] Характеристики бетона
//	Concrete concrete = concrete_part.get_concrete();
//
//	report_.PasteTextPattern(concrete.get_grade(),"%conc_grade%");
//	report_.PasteTextPattern(FloatToStrF(concrete.get_R_bn(), ffFixed, 15, 2),"%R_bn%");
//	report_.PasteTextPattern(FloatToStrF(concrete.get_R_btn(), ffFixed, 15, 2),"%R_btn%");
//	report_.PasteTextPattern(FloatToStrF(concrete.get_density(LengthUnit::m), ffFixed, 15, 2),"%density%");
//	report_.PasteTextPattern(FloatToStrF(concrete.get_phi_b_cr(), ffFixed, 15, 2),"%phi_b_cr%");
//	report_.PasteTextPattern(FloatToStrF(concrete.get_E_b(), ffFixed, 15, 2),"%E_b%");
//	report_.PasteTextPattern(FloatToStrF(concrete.get_gamma_b(), ffFixed, 15, 2),"%gamma_b%");
//	report_.PasteTextPattern(FloatToStrF(concrete.get_gamma_bt(), ffFixed, 15, 2),"%gamma_bt%");
//	report_.PasteTextPattern(FloatToStrF(concrete.get_epsilon_b_lim(), ffFixed, 15, 4),"%epsilon_b_lim%");
//
////[1.6] Арматура
//	Rebar rebar = concrete_part.get_rebar();
//
//	report_.PasteTextPattern(rebar.get_grade(),"%grade%");
//	report_.PasteTextPattern(FloatToStrF(rebar.get_diameter(), ffFixed, 15, 2),"%d%");
//	report_.PasteTextPattern(FloatToStrF(rebar.get_R_sn(), ffFixed, 15, 2),"%R_sn%");
////[1.7] Соединительные элементы
//	Stud stud = composite_beam_calculator_.get_studs_on_beam().get_stud();
//
//	StudsOnBeam studs_on_beam = composite_beam_calculator_.get_studs_on_beam();
//
//	report_.PasteTextPattern(stud.get_name(),"%name%");
//	report_.PasteTextPattern(FloatToStrF(stud.get_l(cm), ffFixed, 15, 2),"%l%");
//	report_.PasteTextPattern(FloatToStrF(stud.get_d_an(cm), ffFixed, 15, 2),"%d_an%");
//	report_.PasteTextPattern(FloatToStrF(stud.get_R_y(), ffFixed, 15, 2),"%R_y%");
//	report_.PasteTextPattern(FloatToStrF(studs_on_beam.get_dist_e(cm), ffFixed, 15, 2),"%z_e%");
//	report_.PasteTextPattern(FloatToStrF(studs_on_beam.get_dist_m(cm), ffFixed, 15, 2),"%z_m%");
//	report_.PasteTextPattern(FloatToStrF(studs_on_beam.get_num_e(), ffFixed, 15, 2),"%ed_rw_num%");
//	report_.PasteTextPattern(FloatToStrF(studs_on_beam.get_num_m(), ffFixed, 15, 2),"%mid_rw_num%");
//	report_.PasteTextPattern(studs_on_beam.get_more_than_one_stud_per_corrugation_edge_string(),"%ed_more_than_one_stud%");
//	report_.PasteTextPattern(studs_on_beam.get_more_than_one_stud_per_corrugation_middle_string(),"%mid_more_than_one_stud%");
//
////[1.8] Коэффициенты
//
//	WorkingConditionsFactors working_conditions_factors = composite_beam_calculator_.get_working_conditions_factors();
//
//	report_.PasteTextPattern(FloatToStrF(working_conditions_factors.gamma_c(), ffFixed, 15, 2),"%gamma_c%");
//	report_.PasteTextPattern(FloatToStrF(working_conditions_factors.gamma_bi(), ffFixed, 15, 2),"%gamma_bi%");
//	report_.PasteTextPattern(FloatToStrF(working_conditions_factors.gamma_si(), ffFixed, 15, 2),"%gamma_si%");
////[1.9] Учёт условий монтажа
//
//	report_.PasteTextPattern(FloatToStrF(static_cast<int>(geometry.get_temporary_supports_number()), ffFixed, 15, 0),"%temp_supp%");
//	report_.PasteTextPattern(FloatToStrF(loads.get_sheeting_continuity_coefficient(), ffFixed, 15, 2),"%sheeting_continuity_coeff%");
//
////[2] Результаты расчёта балки
////[2.1] Геометрические параметры
////[2.1.1] Стального сечения
//	report_.PasteTextPattern(FloatToStrF(i_section.get_A_st(LengthUnit::cm), ffFixed, 15, 2),"%A_st%");
//	report_.PasteTextPattern(FloatToStrF(i_section.get_I_st(LengthUnit::cm), ffFixed, 15, 2),"%I_st%");
//	report_.PasteTextPattern(FloatToStrF(i_section.get_Wf2_st(LengthUnit::cm), ffFixed, 15, 2),"%Wf2_st%");
//	report_.PasteTextPattern(FloatToStrF(i_section.get_Wf1_st(LengthUnit::cm), ffFixed, 15, 2),"%Wf1_st%");
//	report_.PasteTextPattern(FloatToStrF(i_section.get_Z_f2_st(LengthUnit::cm), ffFixed, 15, 2),"%Z_f2_st%");
//	report_.PasteTextPattern(FloatToStrF(i_section.get_Z_f1_st(LengthUnit::cm), ffFixed, 15, 2),"%Z_f1_st%");
////[2.1.2] Железобетонного сечения
//	report_.PasteTextPattern(concrete_part.get_slab_type(),"%slab_type%");
//	report_.PasteTextPattern(FloatToStrF(concrete_part.get_b_sl(LengthUnit::cm), ffFixed, 15, 2),"%b_sl%");
//	report_.PasteTextPattern(FloatToStrF(concrete_part.get_C_b(LengthUnit::cm), ffFixed, 15, 2),"%C_b%");
//	report_.PasteTextPattern(FloatToStrF(concrete_part.get_A_b(LengthUnit::cm), ffFixed, 15, 2),"%A_b%");
//	report_.PasteTextPattern(FloatToStrF(concrete_part.get_I_b(LengthUnit::cm), ffFixed, 15, 2),"%I_b%");
////[2.1.3] Композитного сечения
//
//	CompositeSectionGeometry composite_section_geometry = composite_beam_calculator_.get_composite_section();
//
//	report_.PasteTextPattern(FloatToStrF(composite_section_geometry.get_A_red(LengthUnit::cm), ffFixed, 15, 2),"%A_red%");
//	report_.PasteTextPattern(FloatToStrF(composite_section_geometry.get_I_red(LengthUnit::cm), ffFixed, 15, 2),"%I_red%");
//	report_.PasteTextPattern(FloatToStrF(composite_section_geometry.get_W_b_red(LengthUnit::cm), ffFixed, 15, 2),"%W_b_red%");
//	report_.PasteTextPattern(FloatToStrF(composite_section_geometry.get_Z_b_red(LengthUnit::cm), ffFixed, 15, 2),"%Z_b_red%");
//	report_.PasteTextPattern(FloatToStrF(composite_section_geometry.get_Z_st_red(LengthUnit::cm), ffFixed, 15, 2),"%Z_st_red%");
//	report_.PasteTextPattern(FloatToStrF(composite_section_geometry.get_Z_b_st(LengthUnit::cm), ffFixed, 15, 2),"%Z_b_st%");
////[2.2] Усилия
//	Section max_direct_stress_ratio_section = composite_beam_calculator_.get_composite_beam().get_max_direct_stress_ratio_section();
//
//	report_.PasteTextPattern(FloatToStrF(max_direct_stress_ratio_section.get_x(), ffFixed, 15, 0),"%cs_x%");
//	report_.PasteTextPattern(FloatToStrF(max_direct_stress_ratio_section.get_M_Ia_design(kN, m), ffFixed, 15, 2),"%M_Ia%");
//	report_.PasteTextPattern(FloatToStrF(max_direct_stress_ratio_section.get_M_Ib_design(kN, m), ffFixed, 15, 2),"%M_Ib%");
//	report_.PasteTextPattern(FloatToStrF(max_direct_stress_ratio_section.get_M_IIa_design(kN, m), ffFixed, 15, 2),"%M_IIa%");
//	report_.PasteTextPattern(FloatToStrF(max_direct_stress_ratio_section.get_M_IIb_design(kN, m), ffFixed, 15, 2),"%M_IIb%");
//	report_.PasteTextPattern(FloatToStrF(max_direct_stress_ratio_section.get_M_total_design(kN, m), ffFixed, 15, 2),"%M_total%");
//
////[2.3] Напряжения
//	report_.PasteTextPattern(FloatToStrF(max_direct_stress_ratio_section.get_sigma_b(), ffFixed, 15, 2),"%sigma_b%");
//	report_.PasteTextPattern(FloatToStrF(max_direct_stress_ratio_section.get_sigma_s(), ffFixed, 15, 2),"%sigma_s%");
////[2.4] Коэффициенты использования
////[2.4.1] По изгибающим моментам при монтаже
//
//	Section max_i_section_ratio_section = composite_beam_calculator_.get_composite_beam().get_max_i_section_ratio_section();
//
//	report_.PasteTextPattern(FloatToStrF(max_i_section_ratio_section.get_x(),ffFixed, 15, 2),"%x_M_I%");
//	report_.PasteTextPattern(FloatToStrF(max_i_section_ratio_section.get_i_section_ratio(),ffFixed, 15, 2),"%i_section_ratio%");
//
////[2.4.2] По изгибающим моментам, раздел 6.2.1
//
//	report_.PasteTextPattern(FloatToStrF(max_direct_stress_ratio_section.get_x(),ffFixed, 15, 2),"%x_M%");
//	report_.PasteTextPattern(FloatToStrF(max_direct_stress_ratio_section.get_upper_fl_ratio(),ffFixed, 15, 2),"%ratio_uf%");
//	report_.PasteTextPattern(FloatToStrF(max_direct_stress_ratio_section.get_lower_fl_ratio(),ffFixed, 15, 2),"%ratio_lf%");
//	report_.PasteTextPattern(FloatToStrF(max_direct_stress_ratio_section.get_conc_ratio(),ffFixed, 15, 2),"%conc_ratio%");
//
////[2.4.3] По изгибающим моментам (жёсткопластический материал), пункт 6.2.1.6
//
//	Section max_rigid_plastic_ratio_section = composite_beam_calculator_.get_composite_beam().get_max_rigid_plastic_ratio_section();
//
//	report_.PasteTextPattern(FloatToStrF(max_rigid_plastic_ratio_section.get_x(),ffFixed, 15, 2),"%x_rigid_plastic%");
//	report_.PasteTextPattern(FloatToStrF(max_rigid_plastic_ratio_section.get_rigid_plastic_ratio(),ffFixed, 15, 2),"%ratio_rigid_plastic%");
//
////[2.4.4] По поперечным силам, пункт 6.2.2
//
//	Section max_shear_stress_section = composite_beam_calculator_.get_composite_beam().get_max_shear_stress_ratio_section();
//
//	report_.PasteTextPattern(FloatToStrF(max_shear_stress_section.get_x(),ffFixed, 15, 2),"%x_Q%");
//	report_.PasteTextPattern(FloatToStrF(max_shear_stress_section.get_shear_ratio(),ffFixed, 15, 2),"%ratio_shear%");
//
////[3] Результаты расчёта конструкций объединения
//
////[3.1] Несущая способность упора
//
//	StudsRow max_ratio_studs_row = composite_beam_calculator_.get_studs_on_beam().get_max_ratio_studs_row();
//
//	report_.PasteTextPattern(FloatToStrF(stud.get_P_rd(kN),ffFixed, 15, 2),"%P_rd%");
//	report_.PasteTextPattern(FloatToStrF(max_ratio_studs_row.get_k(),ffFixed, 15, 2),"%k%");
//	report_.PasteTextPattern(FloatToStrF(stud.get_S_h(kN),ffFixed, 15, 2),"%S_h%");
//
//  //[3.2] Усилия
//	report_.PasteTextPattern(FloatToStrF(max_ratio_studs_row.get_x(),ffFixed, 15, 2),"%cs_stud%");
//	report_.PasteTextPattern(FloatToStrF(max_ratio_studs_row.get_S(LoadUnit::kN),ffFixed, 15, 2),"%S_stud%");
//
// //  [3.3] Коэффициенты использования
//	report_.PasteTextPattern(FloatToStrF(max_ratio_studs_row.get_ratio(),ffFixed, 15, 2),"%ratio_stud%");
//}

}
void TCompositeBeamMainForm::generate_report2()
{
	if(!com_beam_output_SP35){
		ShowMessage(u"Данные для отчёта отсутствуют! Необходимо выполнить расчёт.");
		return;
	}

	TWord_Automation report = TWord_Automation("ReportCompositeBeamSP35.docx");

	com_beam_input_SP35 -> print(report);
	com_beam_output_SP35 -> print(report);


}

//---------------------------------------------------------------------------
// Отрисовка эпюр
//---------------------------------------------------------------------------
void TCompositeBeamMainForm ::draw_diagram()
{
//	std::vector<double> M;
//	std::vector<double> Q;
//	std::vector<double> R;
//	std::vector<double> f;
//
//	std::vector<double>	coor_supp {};
//
//	switch (cmb_bx_impact->ItemIndex)
//	{
//	case(0): // Нагрузки Ia стадии
//
//		M = composite_beam_calculator_.get_composite_beam().get_M_Ia_design_list(LoadUnit::kN, LengthUnit::m);
//		Q = composite_beam_calculator_.get_composite_beam().get_Q_Ia_design_list(LoadUnit::kN);
//		R = composite_beam_calculator_.get_composite_beam().get_R_Ia_design_list(LoadUnit::kN);
//		f = composite_beam_calculator_.get_composite_beam().get_f_Ia_list(LengthUnit::mm);
//
//		coor_supp = composite_beam_calculator_.get_composite_beam().get_support_x_list();
//
//		break;
//	case(1): // Нагрузки Ib стадии
//
//		M = composite_beam_calculator_.get_composite_beam().get_M_Ib_design_list(LoadUnit::kN, LengthUnit::m);
//		Q = composite_beam_calculator_.get_composite_beam().get_Q_Ib_design_list(LoadUnit::kN);
//		R = composite_beam_calculator_.get_composite_beam().get_R_Ib_design_list(LoadUnit::kN);
//		f = composite_beam_calculator_.get_composite_beam().get_f_Ib_list(LengthUnit::mm);
//
//		coor_supp = composite_beam_calculator_.get_composite_beam().get_support_x_list();
//
//		break;
//	case(2): // Нагрузки IIa стадии
//
//		M = composite_beam_calculator_.get_composite_beam().get_M_IIa_design_list(LoadUnit::kN, LengthUnit::m);
//		Q = composite_beam_calculator_.get_composite_beam().get_Q_IIa_design_list(LoadUnit::kN);
//		R = composite_beam_calculator_.get_composite_beam().get_P_IIa_design_list(LoadUnit::kN);
//		f = composite_beam_calculator_.get_composite_beam().get_f_IIa_list(LengthUnit::mm);
//
//		coor_supp.push_back(composite_beam_calculator_.get_composite_beam().get_support_x_list().front());
//		coor_supp.push_back(composite_beam_calculator_.get_composite_beam().get_support_x_list().back());
//
//		break;
//
//	case(3): // Нагрузки IIb стадии
//
//		M = composite_beam_calculator_.get_composite_beam().get_M_IIb_design_list(LoadUnit::kN, LengthUnit::m);
//		Q = composite_beam_calculator_.get_composite_beam().get_Q_IIb_design_list(LoadUnit::kN);
//		R = composite_beam_calculator_.get_composite_beam().get_R_IIb_design_list(LoadUnit::kN);
//		f = composite_beam_calculator_.get_composite_beam().get_f_IIb_list(LengthUnit::mm);
//
//		coor_supp.push_back(composite_beam_calculator_.get_composite_beam().get_support_x_list().front());
//		coor_supp.push_back(composite_beam_calculator_.get_composite_beam().get_support_x_list().back());
//
//		break;
//
//	case(4)://Нагрузки полные
//
//		M = composite_beam_calculator_.get_composite_beam().get_M_total_design_list(LoadUnit::kN, LengthUnit::m);
//		Q = composite_beam_calculator_.get_composite_beam().get_Q_total_design_list(LoadUnit::kN);
//		R = composite_beam_calculator_.get_composite_beam().get_R_total_design_list(LoadUnit::kN);
//		f = composite_beam_calculator_.get_composite_beam().get_f_total_list(LengthUnit::mm);
//
//		coor_supp.push_back(composite_beam_calculator_.get_composite_beam().get_support_x_list().front());
//		coor_supp.push_back(composite_beam_calculator_.get_composite_beam().get_support_x_list().back());
//
//		break;
//	}
//
//	TImage *Image1=img_static_scheme;
//	std::vector<double> coor_epur = composite_beam_calculator_.get_composite_beam().get_x_list();
//
////флаг отрисовки значений на эпюре
//	bool flag_sign = true;
//	int num_digits = 2;
//	bool con_sign_practice = true;
//
//	switch (rd_grp_internal_forces_type->ItemIndex)
//	{
//	case(0):
//
//		DrawEpur(Image1, M.size(), &coor_epur[0], &M[0], nullptr, coor_supp.size(), &coor_supp[0],
//			flag_sign, num_digits, con_sign_practice);
//
//		break;
//
//	case(1):
//
//		DrawEpur(Image1, Q.size(), &coor_epur[0], &Q[0], &R[0], coor_supp.size(), &coor_supp[0],
//			flag_sign, num_digits, con_sign_practice);
//
//		break;
//
//	case(2):
//
//		DrawEpur(Image1, f.size(), &coor_epur[0], &f[0], nullptr, coor_supp.size(), &coor_supp[0],
//			flag_sign, num_digits, false);
//
//		break;
//	}
}

//---------------------------------------------------------------------------
// Отрисовка эпюр
//---------------------------------------------------------------------------
void TCompositeBeamMainForm::draw_diagram2()
{
	std::vector<double> M{};
	std::vector<double> Q{};
	std::vector<double> R{};
	std::vector<double> f{};

	std::vector<double>	coor_supp{};

	switch (cmb_bx_impact -> ItemIndex)
	{
	case(0): // Нагрузки 1a стадии

		M = com_beam_output_SP35 -> M_1a_lst();
		Q = com_beam_output_SP35 -> Q_1a_lst();
		R = com_beam_output_SP35 -> R_1a_lst();
//		f = composite_beam_calculator_.get_composite_beam().get_f_Ia_list(LengthUnit::mm);

		coor_supp = com_beam_output_SP35 -> sup_coord();

		break;
	case(1): // Нагрузки 1b стадии

		M = com_beam_output_SP35 -> M_1b_lst();
		Q = com_beam_output_SP35 -> Q_1b_lst();
		R = com_beam_output_SP35 -> R_1b_lst();
//		f = composite_beam_calculator_.get_composite_beam().get_f_Ib_list(LengthUnit::mm);

		coor_supp = com_beam_output_SP35 -> sup_coord();

		break;
	case(2): // Нагрузки 2c стадии

		M = com_beam_output_SP35 -> M_2c_lst();
		Q = com_beam_output_SP35 -> Q_2c_lst();
		R = com_beam_output_SP35 -> R_2c_lst();
//		f = composite_beam_calculator_.get_composite_beam().get_f_IIa_list(LengthUnit::mm);

		coor_supp = com_beam_output_SP35 -> end_sup_coord();

		break;

	case(3): // Нагрузки 2d стадии

		M = com_beam_output_SP35 -> M_2d_lst();
		Q = com_beam_output_SP35 -> Q_2d_lst();
		R = com_beam_output_SP35 -> R_2d_lst();
//		f = composite_beam_calculator_.get_composite_beam().get_f_IIb_list(LengthUnit::mm);

		coor_supp = com_beam_output_SP35 -> end_sup_coord();

		break;

	case(4)://Нагрузки полные

		M = com_beam_output_SP35 -> M_total_lst();
		Q = com_beam_output_SP35 -> Q_total_lst();
		R = com_beam_output_SP35 -> R_total_lst();
//		f = composite_beam_calculator_.get_composite_beam().get_f_total_list(LengthUnit::mm);

		coor_supp = com_beam_output_SP35 -> end_sup_coord();

		break;
	}

	TImage *Image1=img_static_scheme;
	bool flag_sign = true;
	int num_digits = 2;
	bool con_sign_practice = true;

	std::vector<double> coor_epur = com_beam_output_SP35 -> x_lst();

	switch (rd_grp_internal_forces_type -> ItemIndex)
	{
	case(0):

		DrawEpur(Image1, M.size(), &coor_epur[0], &M[0], nullptr, coor_supp.size(), &coor_supp[0],
			flag_sign, num_digits, con_sign_practice);


		break;

	case(1):

		DrawEpur(Image1, Q.size(), &coor_epur[0], &Q[0], &R[0], coor_supp.size(), &coor_supp[0],
			flag_sign, num_digits, con_sign_practice);

		break;

	case(2):

		DrawEpur(Image1, f.size(), &coor_epur[0], &f[0], nullptr, coor_supp.size(), &coor_supp[0],
			flag_sign, num_digits, false);

		break;
	}
}

void __fastcall TCompositeBeamMainForm ::cmb_bx_impactChange(TObject *Sender)
{
	draw_diagram2();
}
//---------------------------------------------------------------------------

void __fastcall TCompositeBeamMainForm ::rd_grp_internal_forces_typeClick(TObject *Sender)
{
	draw_diagram2();
}
void TCompositeBeamMainForm::calculate_composite_beam()
{
	switch(int code_indx = rd_grp_code-> ItemIndex)
	{
		case 0:
			calculate_composite_beam_SP266();
			update_grids(code_indx);
			break;
		case 1:
			calculate_composite_beam_SP35();
			update_grids(code_indx);
			break;
	}
}
void TCompositeBeamMainForm::calculate_composite_beam_SP266()
{

}
void TCompositeBeamMainForm ::calculate_composite_beam_SP35()
{

	store_cntrls_state();

	com_beam_input_SP35.reset(new ComBeamInputSP35{cntrls_state_,
												   ConcreteDefinitionForm -> cntrls_state(),
												   SteelSectionForm -> cntrls_state(),
												   DefineSteelForm -> cntrls_state(),
												   RebarDefinitionForm -> cntrls_state()});


	ComposSectCalculatorSP35 com_beam_calc {*com_beam_input_SP35};


	std::vector<Node> nodes_lst {com_beam_input_SP35 -> glob_geom().nodes_lst()};


	com_beam_output_SP35.reset(new ComBeamOutputSP35{com_beam_calc.calculate(nodes_lst)});

	  draw_diagram2();

}
void TCompositeBeamMainForm::after_calculation()
{
	update_grids(rd_grp_code -> ItemIndex);

	draw_diagram2();

	btn_report -> Enabled = true;
	tb_results -> TabVisible = true;

	PgCntrlCompositeBeam -> ActivePage = TbShtStaticScheme;
}


//---------------------------------------------------------------------------



void __fastcall TCompositeBeamMainForm ::NNewClick(TObject *Sender)
{
	int i;
	if (modify_project) {
		 i=Application->MessageBox(L"Сохранить текущий проект?", L" ",
				  MB_YESNO | MB_ICONQUESTION);
		 if (i==IDYES) NSaveClick(Sender);
	}
	strcpy(ModelFile, UNTITLED);
	modify_project = false;

	Caption = "Расчет комбинированной балки - [Новый проект]";

}
//---------------------------------------------------------------------------

void __fastcall TCompositeBeamMainForm ::NSaveClick(TObject *Sender)
{
//	update_composite_beam(); //актуализируем композитную балку из полей формы
//   // Получение имени директории, в которой находится исполняемый модуль
//
//   if  (strcmp(ModelFile, UNTITLED)==0) {
//	  if(SaveDialog_Model->Execute())
//	  {
//		  FileDir_Name = SaveDialog_Model->FileName;;//поле класс хранит путь полный
//		  ModelName(FileDir_Name.c_str(), ModelFile); //выделяет имя файла для отображения на форме из пути
//	  }
//   }
//
//	std::ofstream ofstr {FileDir_Name.c_str(), std::ios::out | std::ios::binary};
//	calculate_composite_beam();
//
//	composite_beam_calculator_.save(ofstr);
//	ofstr.close();
//
//   Caption = "Расчет комбинированной балки - " + AnsiString(ModelFile);
//
//   modify_project = false;
}

void __fastcall TCompositeBeamMainForm ::NSaveAsClick(TObject *Sender)
{
	strcpy(ModelFile, UNTITLED);
	NSaveClick(Sender);
}
//---------------------------------------------------------------------------
//@--------------------------------------------------------------------------
// Выделение из имени файла в имени модели
void ModelName(char * str0, char* ModelFile)
{
	  char *ptr1, *ptr2;
	 // char i, str[240];
	 char str[240]; //MV 15.04.2020

	  if  (strcmp(ModelFile, UNTITLED)==0) {
	   //i= 240<strlen(str0) ? 240 : strlen(str0);
	   240<strlen(str0) ? 240 : strlen(str0); //MV 15.04.2020
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

void __fastcall TCompositeBeamMainForm ::NOpenClick(TObject *Sender)
{

//   NNewClick(Sender);
//
//   if(OpenDialog_Model->Execute())
//   {
//	  FileDir_Name = OpenDialog_Model->FileName;
//   }
//   if (FileDir_Name!="") {
//
//	  strcpy(ModelFile, UNTITLED);
//
//	  std::ifstream ifstr {FileDir_Name.c_str(), std::ios::in | std::ios::binary};
//
//	  composite_beam_calculator_.load(ifstr);
//
//	  ifstr.close();
//
//	  set_form_controls();
//
//      calculate_composite_beam();
//
//	  ModelName(FileDir_Name.c_str(), ModelFile);
//
//	  Caption = "Расчет комбинированной балки - " + AnsiString(ModelFile);
//
//	  modify_project = false;
//
//   }

}
//---------------------------------------------------------------------------
void TCompositeBeamMainForm ::clean_static_scheme()
{
	img_static_scheme -> Canvas -> Brush -> Color = clWhite;
	img_static_scheme -> Canvas -> FillRect (img_static_scheme -> Canvas -> ClipRect);
   //img_static_scheme -> Picture = nullptr;  нет ли утечки памяти?
}
void TCompositeBeamMainForm ::clean_grid(TStringGrid* str_grd)
{
	for(int i =1; i < str_grd -> RowCount; ++i)
	   str_grd -> Cells [1][i] = "";
}
void __fastcall TCompositeBeamMainForm::OnControlsChange(TObject *Sender)
{
	if (btn_report -> Enabled)
		btn_report -> Enabled=false;
	if(tb_results -> TabVisible)
		tb_results -> TabVisible=false;
	clean_static_scheme();
	clean_grid(strng_grd_compos_sect_geom_character);
	clean_grid(strng_grd_concrete_sect_geom_character);
	clean_grid(strng_grd_steel_sect_geom_character);
	clean_grid(strng_grd_results);
}
//---------------------------------------------------------------------------

void __fastcall TCompositeBeamMainForm ::chck_bx_end_beamClick(TObject *Sender)
{
	if (chck_bx_end_beam->Checked){
		lbl_trib_width_left->Caption="Свес плиты, мм:";
		lbl_trib_width_right->Caption="Расстояние до балки справа, мм:";
		}
	else{
		lbl_trib_width_left->Caption="Расстояние до балки слева, мм:";
		lbl_trib_width_right->Caption="Расстояние до балки справа, мм:";
	}
	OnControlsChange(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TCompositeBeamMainForm ::cmb_bx_analysis_theoryChange(TObject *Sender)

{
    OnControlsChange(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TCompositeBeamMainForm ::cmb_bx_corrugated_sheeting_part_numberChange(TObject *Sender)
{
	OnControlsChange(Sender);
}

//---------------------------------------------------------------------------


void __fastcall TCompositeBeamMainForm ::btn_loggerClick(TObject *Sender)
{
   //	FormLogger->Show();
   frm_logger_ -> Show();
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------



void __fastcall TCompositeBeamMainForm ::N8Click(TObject *Sender)
{
	AboutProgForm->ShowModal();
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
//Обработчик события обеспечивающий заполнение первой строки жирным шрифтом
//---------------------------------------------------------------------------

void __fastcall TCompositeBeamMainForm::strng_grd_first_raw_bold(TObject *Sender,
          int ACol, int ARow, TRect &Rect, TGridDrawState State)
{
	TStringGrid* str_grid=static_cast<TStringGrid*>(Sender);
	if (ARow == 0)
	{
		str_grid -> Canvas -> Font -> Style = TFontStyles() << fsBold;
		str_grid -> Canvas -> TextOut(Rect.Left+3, Rect.Top+5, str_grid -> Cells[ACol][ARow]);
	}
}
//---------------------------------------------------------------------------

void __fastcall TCompositeBeamMainForm::btn_add_impactsClick(TObject *Sender)
{
	FrmAddImpacts -> Show();
}
//---------------------------------------------------------------------------

void __fastcall TCompositeBeamMainForm::HelpClick(TObject *Sender)
{
	WideString path = ExtractFilePath(Application -> ExeName) + "Руководство Пользователя Комбинированная Балка v.1.0.0.pdf";

	HelpForm -> CppWebBrowser1 -> Navigate((BSTR)path);

	HelpForm -> Show();
}

void TCompositeBeamMainForm::update_cntrls()
{
	// Геометрия
	edt_span -> Text = cntrls_state_.edt_span_;
	edt_width_left -> Text = cntrls_state_.edt_width_left_;
	edt_width_right -> Text = cntrls_state_.edt_width_right_;
	chck_bx_end_beam -> Checked = cntrls_state_.chck_bx_end_beam_;
	cmb_bx_number_propping_supports -> ItemIndex = cntrls_state_.cmb_bx_number_propping_supports_;

	// Нагрузки
	edt_SW_add_concrete -> Text = cntrls_state_.edt_SW_add_concrete_;
	edt_dead_load_first_stage -> Text = cntrls_state_.edt_dead_load_first_stage_;
	edt_dead_load_second_stage -> Text = cntrls_state_.edt_dead_load_second_stage_;
	edt_live_load -> Text = cntrls_state_.edt_live_load_;

	// Коэффициенты надёжности по нагрузке

	edt_gamma_f_st_SW -> Text = cntrls_state_.edt_gamma_f_st_SW_;
	edt_gamma_f_concrete_SW -> Text = cntrls_state_.edt_gamma_f_concrete_SW_;
	edt_gamma_f_add_concrete_SW -> Text = cntrls_state_.edt_gamma_f_add_concrete_SW_;
	edt_gamma_f_DL_I -> Text = cntrls_state_.edt_gamma_f_DL_I_;
	edt_gamma_f_DL_II -> Text = cntrls_state_.edt_gamma_f_DL_II_;
	edt_gamma_f_LL -> Text = cntrls_state_.edt_gamma_f_LL_;

	// Коэффициенты условий работы

	edt_gamma_c -> Text = cntrls_state_.edt_gamma_c_;
	edt_gamma_bi -> Text = cntrls_state_.edt_gamma_bi_;
	edt_gamma_si -> Text = cntrls_state_.edt_gamma_si_;

	// Коэффициенты учёт неразрезности настила

	edt_sheeting_continuity_coefficient -> Text = cntrls_state_.edt_sheeting_continuity_coefficient_;

	// Отрисовка эпюр

	cmb_bx_impact -> ItemIndex = cntrls_state_.cmb_bx_impact_;
	rd_grp_internal_forces_type -> ItemIndex = cntrls_state_.rd_grp_internal_forces_type_;

	// Параметры расчёта

	rd_grp_code -> ItemIndex = cntrls_state_.rd_grp_code_;
	edt_max_elem_length -> Text = cntrls_state_.edt_max_elem_length_;

	//Тип жб плиты

	rdgrp_slab_type -> ItemIndex = cntrls_state_.rdgrp_slab_type_;

	//Плита по настилу

	cmb_bx_corrugated_sheeting_part_number -> ItemIndex = cntrls_state_.cmb_bx_corrugated_sheeting_part_number_;
	edt_h_f -> Text = cntrls_state_.edt_h_f_;
	chck_bx_wider_flange_up -> Checked = cntrls_state_.chck_bx_wider_flange_up_;
	chck_bx_sheet_orient_along -> Checked = cntrls_state_.chck_bx_sheet_orient_along_;

	//Плита плоская

	edt_h_f_flat -> Text = cntrls_state_.edt_h_f_flat_;
	edt_h_n -> Text = cntrls_state_.edt_h_n_;

    //Панели для отображения данных

//	String set_name = SteelSectionForm -> info();
	pnl_steel_section_viewer -> Caption = SteelSectionForm -> info();
	pnl_rebar_viewer -> Caption = RebarDefinitionForm -> info();
	pnl_concrete_grade -> Caption = ConcreteDefinitionForm -> info();
    pnl_steel -> Caption = DefineSteelForm -> info();


}
void TCompositeBeamMainForm::store_cntrls_state()
{
	int rc = 0;
	// Геометрия
	rc = String_double_plus(lbl_span -> Caption,
							edt_span -> Text,
							&cntrls_state_.edt_span_);
	if(rc > 0) throw(rc);

	rc = String_double_plus(lbl_trib_width_left -> Caption,
							edt_width_left -> Text,
							&cntrls_state_.edt_width_left_);
	if(rc > 0) throw(rc);

	rc = String_double_plus(lbl_trib_width_right -> Caption,
							edt_width_right -> Text,
							&cntrls_state_.edt_width_right_);
	if(rc > 0) throw(rc);

	cntrls_state_.chck_bx_end_beam_ = chck_bx_end_beam -> Checked;
	cntrls_state_.cmb_bx_number_propping_supports_ = cmb_bx_number_propping_supports -> ItemIndex;

	// Нагрузки
	rc = String_double_zero_plus(lbl_gamma_f_concrete_SW -> Caption,
								 edt_gamma_f_concrete_SW -> Text,
								 &cntrls_state_.edt_SW_add_concrete_);
   if(rc > 0) throw(rc);

	rc = String_double_zero_plus(lbl_dead_load_first_stage -> Caption,
								 edt_dead_load_first_stage -> Text,
								 &cntrls_state_.edt_dead_load_first_stage_);
	if(rc > 0) throw(rc);

	rc = String_double_zero_plus(lbl_dead_load_second_stage -> Caption,
								 edt_dead_load_second_stage -> Text,
								 &cntrls_state_.edt_dead_load_second_stage_);
	if(rc > 0) throw(rc);

	rc = String_double_zero_plus(lbl_live_load -> Caption,
								 edt_live_load -> Text,
								 &cntrls_state_.edt_live_load_);
	if(rc > 0) throw(rc);
	// Коэффициенты надёжности по нагрузке
	rc = String_double_zero_plus(lbl_gamma_f_st_SW -> Caption,
								 edt_gamma_f_st_SW -> Text,
								 &cntrls_state_.edt_gamma_f_st_SW_);
	if(rc > 0) throw(rc);

	rc = String_double_zero_plus(lbl_gamma_f_concrete_SW -> Caption,
								 edt_gamma_f_concrete_SW -> Text,
								 &cntrls_state_.edt_gamma_f_concrete_SW_);
	if(rc > 0) throw(rc);

	rc = String_double_zero_plus(lbl_gamma_f_add_concrete_SW -> Caption,
								 edt_gamma_f_add_concrete_SW -> Text,
								 &cntrls_state_.edt_gamma_f_add_concrete_SW_);
	if(rc > 0) throw(rc);

	rc = String_double_zero_plus(lbl_gamma_f_DL_I -> Caption,
								 edt_gamma_f_DL_I -> Text,
								 &cntrls_state_.edt_gamma_f_DL_I_);
	if(rc > 0) throw(rc);

	rc = String_double_zero_plus(lbl_gamma_f_DL_II -> Caption,
								 edt_gamma_f_DL_II -> Text,
								 &cntrls_state_.edt_gamma_f_DL_II_);
	if(rc > 0) throw(rc);

	rc = String_double_zero_plus(lbl_gamma_f_LL -> Caption,
								 edt_gamma_f_LL -> Text,
								 &cntrls_state_.edt_gamma_f_LL_);
	if(rc > 0) throw(rc);

	// Коэффициенты условий работы

	rc = String_double_zero_plus(lbl_gamma_c -> Caption,
								 edt_gamma_c -> Text,
								 &cntrls_state_.edt_gamma_c_);
	if(rc > 0) throw(rc);

	rc = String_double_zero_plus(lbl_gamma_bi -> Caption,
								 edt_gamma_bi -> Text,
								 &cntrls_state_.edt_gamma_bi_);
	if(rc > 0) throw(rc);

	rc = String_double_zero_plus(lbl_gamma_si -> Caption,
								 edt_gamma_si -> Text,
								 &cntrls_state_.edt_gamma_si_);
	if(rc > 0) throw(rc);
	// Коэффициенты учёт неразрезности настила
	rc = String_double_zero_plus(lbl_sheeting_continuity_coefficient -> Caption,
								 edt_sheeting_continuity_coefficient -> Text,
								 &cntrls_state_.edt_sheeting_continuity_coefficient_);
	if(rc > 0) throw(rc);

    // Отрисовка эпюр

	cntrls_state_.cmb_bx_impact_ = cmb_bx_impact -> ItemIndex;
	cntrls_state_.rd_grp_internal_forces_type_ = rd_grp_internal_forces_type -> ItemIndex;

	// Параметры расчёта

	rd_grp_code -> ItemIndex = cntrls_state_.rd_grp_code_;
	rc = String_double_zero_plus(lbl_max_elem_length -> Caption,
								 edt_max_elem_length -> Text,
								 &cntrls_state_.edt_max_elem_length_);
	if(rc > 0) throw(rc);

	//Тип жб плиты

	cntrls_state_.rdgrp_slab_type_ = rdgrp_slab_type -> ItemIndex ;

	//Плита по настилу
	rc = String_double_zero_plus(lbl_h_f -> Caption,
								 edt_h_f -> Text,
								 &cntrls_state_.edt_h_f_);
	if(rc > 0) throw(rc);

	cntrls_state_.cmb_bx_corrugated_sheeting_part_number_ = cmb_bx_corrugated_sheeting_part_number -> ItemIndex ;
	cntrls_state_.chck_bx_wider_flange_up_ = chck_bx_wider_flange_up -> Checked ;
	cntrls_state_.chck_bx_sheet_orient_along_ = chck_bx_sheet_orient_along -> Checked;

	//Плита плоская
	rc = String_double_zero_plus(lbl_h_f_flat -> Caption,
								 edt_h_f_flat -> Text,
								 &cntrls_state_.edt_h_f_flat_);
	if(rc > 0) throw(rc);

	rc = String_double_zero_plus(lbl_h_n -> Caption,
								 edt_h_n -> Text,
								 &cntrls_state_.edt_h_n_);
	if(rc > 0) throw(rc);

}
//---------------------------------------------------------------------------
void TCompositeBeamMainForm::store_all_frms_cntrls_state()
{
	store_cntrls_state();
	SteelSectionForm -> store_cntrls_state();
	RebarDefinitionForm -> store_cntrls_state();
	ConcreteDefinitionForm -> store_cntrls_state();
	DefineSteelForm -> store_cntrls_state();

}

void TCompositeBeamMainForm::update_all_frms_cntrls()
{
	SteelSectionForm -> update_cntrls_state();
	RebarDefinitionForm -> update_cntrls_state();
	ConcreteDefinitionForm -> update_cntrls_state();
	DefineSteelForm -> update_cntrls_state();
	//второстепенные формы обновляются первыми для того, чтобы верно отобразить информацию на панелях
	update_cntrls();
}

void TCompositeBeamMainForm::update_GUI(int code_indx)
{
	switch (code_indx){
	case(0):
		set_GUI_SP266();
		break;
	case(1):
		set_GUI_SP35();
		break;
	}
}
void __fastcall TCompositeBeamMainForm::rd_grp_codeClick(TObject *Sender)
{
	update_GUI(static_cast<TRadioGroup*>(Sender) -> ItemIndex);
}
void TCompositeBeamMainForm::set_GUI_SP35()
{
	rdgrp_slab_type -> ItemIndex = 0;
	rdgrp_slab_type -> Buttons [1] -> Enabled = false;
	btn_add_impacts -> Enabled = false;
	ConcreteDefinitionForm -> set_GUI_SP35();
	rdgrp_slab_typeClick(nullptr);
}
//---------------------------------------------------------------------------
void TCompositeBeamMainForm::set_GUI_SP266()
{
	rdgrp_slab_type -> Buttons [1] -> Enabled = true;
	btn_add_impacts -> Enabled = true;
	ConcreteDefinitionForm -> set_GUI_SP266();
}
//---------------------------------------------------------------------------
void TCompositeBeamMainForm::save()
{
	std::ofstream ofs {"test.cb"};
	cntrls_state_.save(ofs);
	SteelSectionForm -> save(ofs);
	RebarDefinitionForm -> save(ofs);
}
//---------------------------------------------------------------------------
void TCompositeBeamMainForm::load()
{
	std::ifstream ifs {"test.cb"};
	cntrls_state_.load(ifs);
	SteelSectionForm -> load(ifs);

}
//---------------------------------------------------------------------------
void __fastcall TCompositeBeamMainForm::btn_saveClick(TObject *Sender)
{
	store_all_frms_cntrls_state();
	save();
}
//---------------------------------------------------------------------------

void __fastcall TCompositeBeamMainForm::btn_loadClick(TObject *Sender)
{
	load();
	update_cntrls();
}
//---------------------------------------------------------------------------




