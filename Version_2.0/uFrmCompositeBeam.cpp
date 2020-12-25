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
#include "uStudsInputSP35.h"
#include "uStudsOutputSP35.h"
#include "uUnits_new.h"
#include "uStudRowCalculatorSP35.h"

#include "uCompBeamObjsCreatorSP266.h"
#include "uCompSectsCalculatorSP266.h"
#include "uCompSectsOutputListSP266.h"

//---------------------------------------------------------------------------
std::unique_ptr<ComBeamOutputSP35 const> com_beam_output_SP35 {nullptr};
std::unique_ptr<ComBeamInputSP35 const> com_beam_input_SP35 {nullptr};

StudsOutputSP35 studs_output;

CompSectsOutputListSP266 comp_sects_output_list_SP266;

TCompositeBeamMainForm  *CompositeBeamMainForm;
//----------------------------------------------------------------------
 _fastcall TCompositeBeamMainForm ::TCompositeBeamMainForm (TComponent* Owner)
	: TForm(Owner)
{
	#ifndef NDEBUG
	btn_logger -> Visible = true;
    #endif

	cotr_comp_sect_geometr_grid();
	cotr_steel_sect_geometr_grid();
	ctor_concrete_sect_geometr_grid();

	fill_cmb_bx_impact();
	fill_cmb_bx_corrugated_sheets();

	modify_project = false;

}
//----------------------------------------------------------------------
void __fastcall TCompositeBeamMainForm::FormShow(TObject *Sender)
{
	update_GUI(cntrls_state_.rd_grp_code_data_);
	update_all_frms_cntrls();

	calculate_composite_beam();
	after_calculation();

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
	generate_report();
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
	TStringGrid* str_gr = static_cast<TStringGrid*>(Sender);

	switch (rd_grp_code -> ItemIndex) {

	case(0):
		render_ratios_grid_SP266(str_gr, ACol, ARow, Rect);
		break;
	case(1):
		render_ratios_grid_SP35(str_gr, ACol, ARow, Rect);
		break;
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
void TCompositeBeamMainForm ::update_SW_edts(int code_indx)
{
	double dens;
	double SW_conc;
	double SW_steel_beam;

	AnsiString t;

	using namespace units;

	switch (code_indx) {

	case(0):
		edt_SW_steel_beam -> Text = double_to_str(
			comp_sects_output_list_SP266.loads_.SW_steel_beam());
		edt_SW_conc -> Text = double_to_str(
			comp_sects_output_list_SP266.loads_.SW_concrete()* kN / m2);

		break;
	case(1):

		dens = com_beam_input_SP35 -> concrete().get_density();
		SW_conc = com_beam_input_SP35 -> concrete_sect() -> SW(dens);
		edt_SW_conc -> Text = force_per_area_to_str(SW_conc, LengthUnit::m, LoadUnit::kN);

		SW_steel_beam = com_beam_input_SP35 -> steel_sect() -> SW();
		edt_SW_steel_beam -> Text = force_per_length_to_str(SW_steel_beam * units::kN / units::m);

		break;
	}
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
		comp_sects_output_list_SP266.fill_comp_sect_grid(strng_grd_compos_sect_geom_character);
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
		comp_sects_output_list_SP266.fill_grid(strng_grd_results);
		break;
	case(1):
		com_beam_output_SP35 -> fill_grid(strng_grd_results);
		studs_output.fill_grid(strng_grd_results);
		break;
	}

}

void TCompositeBeamMainForm::clean_grid(TStringGrid* str_gr)
{
	for( int i = 0; i < str_gr -> ColCount; ++i)
		str_gr -> Cols[i] -> Clear();
}
//---------------------------------------------------------------------------
//	Функция заполняющая Grid выводящий результаты расчёта композитной балки
//---------------------------------------------------------------------------
void TCompositeBeamMainForm::cotr_ratios_grid_SP266()
{
	clean_grid(strng_grd_results);

	strng_grd_results -> RowCount = 18;

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
//	Функция заполняющая Grid выводящий результаты расчёта композитной балки
//---------------------------------------------------------------------------
void TCompositeBeamMainForm::cotr_ratios_grid_SP35()
{
	clean_grid(strng_grd_results);

	strng_grd_results -> RowCount = 15;

	strng_grd_results -> Cells [0][0] = u"Проверка";
	strng_grd_results -> Cells [0][1] = u"На действие изгибающих моментов при монтаже";
	strng_grd_results -> Cells [0][2] = u"      Координата критического сечения, мм";
	strng_grd_results -> Cells [0][3] = u"      Прочность";
	strng_grd_results -> Cells [0][4] = u"На действие изгибающих моментов, раздел";
	strng_grd_results -> Cells [0][5] = u"      Координата критического сечения, мм";
	strng_grd_results -> Cells [0][6] = u"      Прочность верхнего пояса стального сечения";
	strng_grd_results -> Cells [0][7] = u"      Прочность нижнего пояса стального сечения";
	strng_grd_results -> Cells [0][8] = u"      Прочность железобетона";
	strng_grd_results -> Cells [0][9] = L"Прочности на действие поперечной силы";
	strng_grd_results -> Cells [0][10] = L"      Координата критического сечения, мм";
	strng_grd_results -> Cells [0][11] = L"      Прочность сечения, раздел";
	strng_grd_results -> Cells [0][12] = L"Упоров объединения, раздел";
	strng_grd_results -> Cells [0][13] = L"      Координата критического упора, мм";
	strng_grd_results -> Cells [0][14] = L"      Прочность упора";

	strng_grd_results -> Cells [1][0] = u"Коэффициенты Использования (КИ) ";
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
void __fastcall TCompositeBeamMainForm ::BtBtnExitClick(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TCompositeBeamMainForm ::BtBtnSteelChoiceClick(TObject *Sender)
{
	 DefineSteelForm -> ShowModal();
	 pnl_steel -> Caption = DefineSteelForm -> info();
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
	StudDefinitionForm -> ShowModal();
	pnl_shear_stud_viewer -> Caption = StudDefinitionForm -> info();
}
//---------------------------------------------------------------------------
void __fastcall TCompositeBeamMainForm ::BtnSteelSectionChoiceClick(TObject *Sender)
{
	SteelSectionForm -> ShowModal();
	pnl_steel_section_viewer -> Caption = SteelSectionForm -> info();

}
//---------------------------------------------------------------------------

void __fastcall TCompositeBeamMainForm ::NOutReportClick(TObject *Sender)
{
	generate_report();
}
//---------------------------------------------------------------------------

void __fastcall TCompositeBeamMainForm ::NExitClick(TObject *Sender)
{
	Close();
}

void TCompositeBeamMainForm::generate_report()
{
	if(!com_beam_output_SP35){
		ShowMessage(u"Данные для отчёта отсутствуют! Необходимо выполнить расчёт.");
		return;
	}

	TWord_Automation report = TWord_Automation("ReportCompositeBeamSP35.docx");

	com_beam_input_SP35 -> print(report);
	com_beam_output_SP35 -> print(report);

	studs_output.print(report);



}

//---------------------------------------------------------------------------
// Отрисовка эпюр
//---------------------------------------------------------------------------
void TCompositeBeamMainForm::draw_diagram(int code_index)
{
	switch (code_index){
	case(0):
		draw_diagramSP266();
		break;
	case(1):
		draw_diagramSP35();
		break;
	}
}

void TCompositeBeamMainForm::draw_diagramSP266()
{
	std::vector<double> M;
	std::vector<double> Q;
	std::vector<double> R;
	std::vector<double> f;

	std::vector<double>	coor_supp;

	switch (cmb_bx_impact -> ItemIndex)
	{
	case(0): // Нагрузки 1a стадии

		M = comp_sects_output_list_SP266.M_1a_lst();
		Q = comp_sects_output_list_SP266.Q_1a_lst();
		R = comp_sects_output_list_SP266.R_1a_lst();
		f = comp_sects_output_list_SP266.f_1a_lst();

		coor_supp = comp_sects_output_list_SP266.sup_coord();

		break;
	case(1): // Нагрузки 1b стадии

		M = comp_sects_output_list_SP266.M_1b_lst();
		Q = comp_sects_output_list_SP266.Q_1b_lst();
		R = comp_sects_output_list_SP266.R_1b_lst();
		f = comp_sects_output_list_SP266.f_1b_lst();

		coor_supp = comp_sects_output_list_SP266.sup_coord();

		break;
	case(2): // Нагрузки 2c стадии

		M = comp_sects_output_list_SP266.M_2c_lst();
		Q = comp_sects_output_list_SP266.Q_2c_lst();
		R = comp_sects_output_list_SP266.R_2c_lst();
		f = comp_sects_output_list_SP266.f_2c_lst();

		coor_supp = comp_sects_output_list_SP266.end_sup_coord();

		break;

	case(3): // Нагрузки 2d стадии

		M = comp_sects_output_list_SP266.M_2d_lst();
		Q = comp_sects_output_list_SP266.Q_2d_lst();
		R = comp_sects_output_list_SP266.R_2d_lst();
		f = comp_sects_output_list_SP266.f_2d_lst();

		coor_supp = comp_sects_output_list_SP266.end_sup_coord();

		break;

	case(4)://Нагрузки полные

		M = comp_sects_output_list_SP266.M_total_lst();
		Q = comp_sects_output_list_SP266.Q_total_lst();
		R = comp_sects_output_list_SP266.R_total_lst();
		f = comp_sects_output_list_SP266.f_total_lst();

		coor_supp = comp_sects_output_list_SP266.end_sup_coord();

		break;
	}

	{

	using namespace units;

	std::transform(M.begin(), M.end(), M.begin(),
				   [](auto & M0){ return M0 * kN * m ;});
	std::transform(Q.begin(), Q.end(), Q.begin(),
				   [](auto & Q0){ return Q0 * kN ;});
	std::transform(R.begin(), R.end(), R.begin(),
				   [](auto & R0){ return R0 * kN;});
	}

	TImage *Image1=img_static_scheme;
	bool flag_sign = true;
	int num_digits = 2;
	bool con_sign_practice = true;

	std::vector<double> coor_epur = comp_sects_output_list_SP266.x_lst();

	switch (rd_grp_internal_forces_type -> ItemIndex)
	{
	case(0):

		DrawEpur(Image1,
				 M.size(),
				 coor_epur.data(),
				 M.data(),
				 nullptr,
				 coor_supp.size(),
				 coor_supp.data(),
				 flag_sign,
				 num_digits,
				 con_sign_practice);


		break;

	case(1):

		DrawEpur(Image1,
				 Q.size(),
				 coor_epur.data(),
				 Q.data(), R.data(),
				 coor_supp.size(),
				 coor_supp.data(),
				 flag_sign,
				 num_digits,
				 con_sign_practice);

		break;

	case(2):

		DrawEpur(Image1,
				 f.size(),
				 coor_epur.data(),
				 f.data(), nullptr,
				 coor_supp.size(),
				 coor_supp.data(),
				 flag_sign, num_digits,
				 false);

		break;
	case(3):

		DrawEpur(Image1,
				 studs_output.S_overline_lst().size(),
				 studs_output.coord().data(),
				 studs_output.S_overline_lst().data(),
				 nullptr,
				 coor_supp.size(),
				 coor_supp.data(),
				 flag_sign,
				 num_digits,
				 false);

		break;
	}
}
void TCompositeBeamMainForm::draw_diagramSP35()
{
	std::vector<double> M;
	std::vector<double> Q;
	std::vector<double> R;
	std::vector<double> f;

	std::vector<double>	coor_supp;

	switch (cmb_bx_impact -> ItemIndex)
	{
	case(0): // Нагрузки 1a стадии

		M = com_beam_output_SP35 -> M_1a_lst();
		Q = com_beam_output_SP35 -> Q_1a_lst();
		R = com_beam_output_SP35 -> R_1a_lst();
		f = com_beam_output_SP35 -> f_1a_lst();

		coor_supp = com_beam_output_SP35 -> sup_coord();

		break;
	case(1): // Нагрузки 1b стадии

		M = com_beam_output_SP35 -> M_1b_lst();
		Q = com_beam_output_SP35 -> Q_1b_lst();
		R = com_beam_output_SP35 -> R_1b_lst();
		f = com_beam_output_SP35 -> f_1b_lst();

		coor_supp = com_beam_output_SP35 -> sup_coord();

		break;
	case(2): // Нагрузки 2c стадии

		M = com_beam_output_SP35 -> M_2c_lst();
		Q = com_beam_output_SP35 -> Q_2c_lst();
		R = com_beam_output_SP35 -> R_2c_lst();
		f = com_beam_output_SP35 -> f_2c_lst();

		coor_supp = com_beam_output_SP35 -> end_sup_coord();

		break;

	case(3): // Нагрузки 2d стадии

		M = com_beam_output_SP35 -> M_2d_lst();
		Q = com_beam_output_SP35 -> Q_2d_lst();
		R = com_beam_output_SP35 -> R_2d_lst();
		f = com_beam_output_SP35 -> f_2d_lst();

		coor_supp = com_beam_output_SP35 -> end_sup_coord();

		break;

	case(4)://Нагрузки полные

		M = com_beam_output_SP35 -> M_total_lst();
		Q = com_beam_output_SP35 -> Q_total_lst();
		R = com_beam_output_SP35 -> R_total_lst();
		f = com_beam_output_SP35 -> f_total_lst();

		coor_supp = com_beam_output_SP35 -> end_sup_coord();

		break;
	}

	{

	using namespace units;

	std::transform(M.begin(), M.end(), M.begin(),
				   [](auto & M0){ return M0 * kN * m ;});
	std::transform(Q.begin(), Q.end(), Q.begin(),
				   [](auto & Q0){ return Q0 * kN ;});
	std::transform(R.begin(), R.end(), R.begin(),
				   [](auto & R0){ return R0 * kN;});
	}

	TImage *Image1=img_static_scheme;
	bool flag_sign = true;
	int num_digits = 2;
	bool con_sign_practice = true;

	std::vector<double> coor_epur = com_beam_output_SP35 -> x_lst();

	switch (rd_grp_internal_forces_type -> ItemIndex)
	{
	case(0):

		DrawEpur(Image1,
				 M.size(),
				 coor_epur.data(),
				 M.data(),
				 nullptr,
				 coor_supp.size(),
				 coor_supp.data(),
				 flag_sign,
				 num_digits,
				 con_sign_practice);


		break;

	case(1):

		DrawEpur(Image1,
				 Q.size(),
				 coor_epur.data(),
				 Q.data(), R.data(),
				 coor_supp.size(),
				 coor_supp.data(),
				 flag_sign,
				 num_digits,
				 con_sign_practice);

		break;

	case(2):

		DrawEpur(Image1,
				 f.size(),
				 coor_epur.data(),
				 f.data(), nullptr,
				 coor_supp.size(),
				 coor_supp.data(),
				 flag_sign, num_digits,
				 false);

		break;
	case(3):

		DrawEpur(Image1,
				 studs_output.S_overline_lst().size(),
				 studs_output.coord().data(),
				 studs_output.S_overline_lst().data(),
				 nullptr,
				 coor_supp.size(),
				 coor_supp.data(),
				 flag_sign,
				 num_digits,
				 false);

		break;
	}

}

void __fastcall TCompositeBeamMainForm ::cmb_bx_impactChange(TObject *Sender)
{
	draw_diagram(rd_grp_code -> ItemIndex);
}
//---------------------------------------------------------------------------

void __fastcall TCompositeBeamMainForm ::rd_grp_internal_forces_typeClick(TObject *Sender)
{
	draw_diagram(rd_grp_code -> ItemIndex);
}
void TCompositeBeamMainForm::calculate_composite_beam()
{

	switch(int code_indx = rd_grp_code -> ItemIndex)
	{
		case 0:
			calculate_composite_beam_SP266();
			break;
		case 1:
			calculate_composite_beam_SP35();
			calculate_studs();
			break;
	}
}
void TCompositeBeamMainForm::calculate_composite_beam_SP266()
{
	store_all_frms_cntrls_state();

	CompBeamObjsCreatorSP266 creator {
		this -> cntrls_state_,
		ConcreteDefinitionForm -> cntrls_state(),
		SteelSectionForm -> cntrls_state(),
		DefineSteelForm -> cntrls_state(),
		RebarDefinitionForm -> cntrls_state()};//объект 432 байта

	CompSectsCalculatorSP266 calculator {creator};

	CompSectGeomSP266 cs = creator.comp_sect_geom();



//	GeneralConcreteSection conc_sect {cs -> conc_sect()};

	comp_sects_output_list_SP266 = calculator.run(); //объект 560 байт

}
void TCompositeBeamMainForm ::calculate_composite_beam_SP35()
{
	store_all_frms_cntrls_state();

	com_beam_input_SP35.reset(new ComBeamInputSP35{this -> cntrls_state_,
												   ConcreteDefinitionForm -> cntrls_state(),
												   SteelSectionForm -> cntrls_state(),
												   DefineSteelForm -> cntrls_state(),
												   RebarDefinitionForm -> cntrls_state()});

	try {
		ComposSectCalculatorSP35 com_beam_calc {*com_beam_input_SP35};
		std::vector<Node> nodes_lst {com_beam_input_SP35 -> glob_geom().nodes_lst()};
//		nodes_lst.push_back({8942.5, false, true});

		com_beam_output_SP35.reset(new ComBeamOutputSP35{com_beam_calc.calculate(nodes_lst)});

	} catch (std::u16string const & str) {
		ShowMessage(str.c_str());
		return;
	}

}
void TCompositeBeamMainForm::calculate_studs()
{
	store_all_frms_cntrls_state();

	ComBeamInputSP35  obj_for_studs_S35_verific {this -> cntrls_state_,
												 ConcreteDefinitionForm -> cntrls_state(),
												 SteelSectionForm -> cntrls_state(),
												 DefineSteelForm -> cntrls_state(),
												 RebarDefinitionForm -> cntrls_state()};

	StudRowCalculatorSP35 calc {obj_for_studs_S35_verific};

	StudsInputSP35 studs_input = {StudDefinitionForm -> cntrls_state(),
								  this -> cntrls_state_,
								  ConcreteDefinitionForm -> cntrls_state()};

	studs_output = {calc.run(studs_input)};

}
void TCompositeBeamMainForm::after_calculation()
{
	update_SW_edts(rd_grp_code -> ItemIndex);
	update_grids(rd_grp_code -> ItemIndex);

	draw_diagram(rd_grp_code -> ItemIndex);

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
	store_all_frms_cntrls_state(); //актуализируем композитную балку из полей формы
   // Получение имени директории, в которой находится исполняемый модуль

   if  (strcmp(ModelFile, UNTITLED)==0) {
	  if(SaveDialog_Model->Execute())
	  {
		  FileDir_Name = SaveDialog_Model->FileName;;//поле класс хранит путь полный
		  ModelName(FileDir_Name.c_str(), ModelFile); //выделяет имя файла для отображения на форме из пути
	  }
   }

	std::ofstream ofs {FileDir_Name.c_str(), std::ios::out | std::ios::binary};
	calculate_composite_beam();

	cntrls_state_.save(ofs);

	SteelSectionForm -> save(ofs);
	ConcreteDefinitionForm -> save(ofs);
	RebarDefinitionForm -> save(ofs);
	StudDefinitionForm -> save(ofs);
	DefineSteelForm -> save(ofs);

	ofs.close();

   Caption = "Расчет комбинированной балки - " + AnsiString(ModelFile);

   modify_project = false;
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
//
   NNewClick(Sender);

   if(OpenDialog_Model->Execute())
   {
	  FileDir_Name = OpenDialog_Model->FileName;
   }
   if (FileDir_Name!="") {

	  strcpy(ModelFile, UNTITLED);

	  std::ifstream ifs {FileDir_Name.c_str(), std::ios::in | std::ios::binary};

	  cntrls_state_.load(ifs);

	  SteelSectionForm -> load(ifs);
	  ConcreteDefinitionForm -> load(ifs);
	  RebarDefinitionForm -> load(ifs);
	  StudDefinitionForm -> load(ifs);
	  DefineSteelForm -> load(ifs);

	  ifs.close();

	  update_all_frms_cntrls();

	  calculate_composite_beam();

	  ModelName(FileDir_Name.c_str(), ModelFile);

	  Caption = "Расчет комбинированной балки - " + AnsiString(ModelFile);

	  modify_project = false;

   }

}
//---------------------------------------------------------------------------
void TCompositeBeamMainForm ::clean_static_scheme()
{
	img_static_scheme -> Canvas -> Brush -> Color = clWhite;
	img_static_scheme -> Canvas -> FillRect (img_static_scheme -> Canvas -> ClipRect);
   //img_static_scheme -> Picture = nullptr;  нет ли утечки памяти?
}
void TCompositeBeamMainForm ::clean_2nd_col_grid(TStringGrid* str_grd)
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
	clean_2nd_col_grid(strng_grd_compos_sect_geom_character);
	clean_2nd_col_grid(strng_grd_concrete_sect_geom_character);
	clean_2nd_col_grid(strng_grd_steel_sect_geom_character);
	clean_2nd_col_grid(strng_grd_results);
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
void __fastcall TCompositeBeamMainForm ::N8Click(TObject *Sender)
{
	AboutProgForm->ShowModal();
}
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
	edt_span -> Text = cntrls_state_.edt_span_data_;
	edt_width_left -> Text = cntrls_state_.edt_width_left_data_;
	edt_width_right -> Text = cntrls_state_.edt_width_right_data_;
	chck_bx_end_beam -> Checked = cntrls_state_.chck_bx_end_beam_data_;
	cmb_bx_number_propping_supports -> ItemIndex = cntrls_state_.cmb_bx_number_propping_supports_data_;

	// Нагрузки
	edt_SW_add_concrete -> Text = cntrls_state_.edt_SW_add_concrete_data_;
	edt_dead_load_first_stage -> Text = cntrls_state_.edt_dead_load_first_stage_data_;
	edt_dead_load_second_stage -> Text = cntrls_state_.edt_dead_load_second_stage_data_;
	edt_live_load -> Text = cntrls_state_.edt_live_load_data_;

	// Коэффициенты надёжности по нагрузке

	edt_gamma_f_st_SW -> Text = cntrls_state_.edt_gamma_f_st_SW_data_;
	edt_gamma_f_concrete_SW -> Text = cntrls_state_.edt_gamma_f_concrete_SW_data_;
	edt_gamma_f_add_concrete_SW -> Text = cntrls_state_.edt_gamma_f_add_concrete_SW_data_;
	edt_gamma_f_DL_I -> Text = cntrls_state_.edt_gamma_f_DL_I_data_;
	edt_gamma_f_DL_II -> Text = cntrls_state_.edt_gamma_f_DL_II_data_;
	edt_gamma_f_LL -> Text = cntrls_state_.edt_gamma_f_LL_data_;

	// Коэффициенты условий работы

	edt_gamma_c -> Text = cntrls_state_.edt_gamma_c_data_;
	edt_gamma_bi -> Text = cntrls_state_.edt_gamma_bi_data_;
	edt_gamma_si -> Text = cntrls_state_.edt_gamma_si_data_;

	// Прочие коэффициенты

	edt_sheeting_continuity_coefficient -> Text = cntrls_state_.edt_sheeting_continuity_coefficient_data_;
	edt_fact_quasi_perm_load -> Text = cntrls_state_.edt_fact_quasi_perm_load_data_;

	// Отрисовка эпюр

	cmb_bx_impact -> ItemIndex = cntrls_state_.cmb_bx_impact_data_;
	rd_grp_internal_forces_type -> ItemIndex = cntrls_state_.rd_grp_internal_forces_type_data_;

	// Параметры расчёта

	rd_grp_code -> ItemIndex = cntrls_state_.rd_grp_code_data_;
	edt_max_elem_length -> Text = cntrls_state_.edt_max_elem_length_data_;

	//Тип жб плиты

	rdgrp_slab_type -> ItemIndex = cntrls_state_.rdgrp_slab_type_data_;

	//Плита по настилу

	cmb_bx_corrugated_sheeting_part_number -> ItemIndex = cntrls_state_.cmb_bx_corrugated_sheeting_part_number_data_;
	edt_h_f -> Text = cntrls_state_.edt_h_f_data_;
	chck_bx_wider_flange_up -> Checked = cntrls_state_.chck_bx_wider_flange_up_data_;
	chck_bx_sheet_orient_along -> Checked = cntrls_state_.chck_bx_sheet_orient_along_data_;

	//Плита плоская

	edt_h_f_flat -> Text = cntrls_state_.edt_h_f_flat_data_;
	edt_h_n -> Text = cntrls_state_.edt_h_n_data_;

    //Панели для отображения данных

	pnl_steel_section_viewer -> Caption = SteelSectionForm -> info();
	pnl_rebar_viewer -> Caption = RebarDefinitionForm -> info();
	pnl_concrete_grade -> Caption = ConcreteDefinitionForm -> info();
	pnl_steel -> Caption = DefineSteelForm -> info();
	pnl_shear_stud_viewer -> Caption = StudDefinitionForm -> info();
}
void TCompositeBeamMainForm::store_cntrls_state()
{
	int rc = 0;
	// Геометрия
	rc = String_double_plus(lbl_span -> Caption,
							edt_span -> Text,
							&cntrls_state_.edt_span_data_);
	if(rc > 0) throw(rc);

	rc = String_double_plus(lbl_trib_width_left -> Caption,
							edt_width_left -> Text,
							&cntrls_state_.edt_width_left_data_);
	if(rc > 0) throw(rc);

	rc = String_double_plus(lbl_trib_width_right -> Caption,
							edt_width_right -> Text,
							&cntrls_state_.edt_width_right_data_);
	if(rc > 0) throw(rc);

	cntrls_state_.chck_bx_end_beam_data_ = chck_bx_end_beam -> Checked;
	cntrls_state_.cmb_bx_number_propping_supports_data_ = cmb_bx_number_propping_supports -> ItemIndex;

	// Нагрузки
	rc = String_double_zero_plus(lbl_SW_add_concrete -> Caption,
								 edt_SW_add_concrete -> Text,
								 &cntrls_state_.edt_SW_add_concrete_data_);
   if(rc > 0) throw(rc);

	rc = String_double_zero_plus(lbl_dead_load_first_stage -> Caption,
								 edt_dead_load_first_stage -> Text,
								 &cntrls_state_.edt_dead_load_first_stage_data_);
	if(rc > 0) throw(rc);

	rc = String_double_zero_plus(lbl_dead_load_second_stage -> Caption,
								 edt_dead_load_second_stage -> Text,
								 &cntrls_state_.edt_dead_load_second_stage_data_);
	if(rc > 0) throw(rc);

	rc = String_double_zero_plus(lbl_live_load -> Caption,
								 edt_live_load -> Text,
								 &cntrls_state_.edt_live_load_data_);
	if(rc > 0) throw(rc);
	// Коэффициенты надёжности по нагрузке
	rc = String_double_zero_plus(lbl_gamma_f_st_SW -> Caption,
								 edt_gamma_f_st_SW -> Text,
								 &cntrls_state_.edt_gamma_f_st_SW_data_);
	if(rc > 0) throw(rc);

	rc = String_double_zero_plus(lbl_gamma_f_concrete_SW -> Caption,
								 edt_gamma_f_concrete_SW -> Text,
								 &cntrls_state_.edt_gamma_f_concrete_SW_data_);
	if(rc > 0) throw(rc);

	rc = String_double_zero_plus(lbl_gamma_f_add_concrete_SW -> Caption,
								 edt_gamma_f_add_concrete_SW -> Text,
								 &cntrls_state_.edt_gamma_f_add_concrete_SW_data_);
	if(rc > 0) throw(rc);

	rc = String_double_zero_plus(lbl_gamma_f_DL_I -> Caption,
								 edt_gamma_f_DL_I -> Text,
								 &cntrls_state_.edt_gamma_f_DL_I_data_);
	if(rc > 0) throw(rc);

	rc = String_double_zero_plus(lbl_gamma_f_DL_II -> Caption,
								 edt_gamma_f_DL_II -> Text,
								 &cntrls_state_.edt_gamma_f_DL_II_data_);
	if(rc > 0) throw(rc);

	rc = String_double_zero_plus(lbl_gamma_f_LL -> Caption,
								 edt_gamma_f_LL -> Text,
								 &cntrls_state_.edt_gamma_f_LL_data_);
	if(rc > 0) throw(rc);

	// Коэффициенты условий работы

	rc = String_double_zero_plus(lbl_gamma_c -> Caption,
								 edt_gamma_c -> Text,
								 &cntrls_state_.edt_gamma_c_data_);
	if(rc > 0) throw(rc);

	rc = String_double_zero_plus(lbl_gamma_bi -> Caption,
								 edt_gamma_bi -> Text,
								 &cntrls_state_.edt_gamma_bi_data_);
	if(rc > 0) throw(rc);

	rc = String_double_zero_plus(lbl_gamma_si -> Caption,
								 edt_gamma_si -> Text,
								 &cntrls_state_.edt_gamma_si_data_);
	if(rc > 0) throw(rc);
	// Прочие коэффициенты
	rc = String_double_zero_plus(lbl_sheeting_continuity_coefficient -> Caption,
								 edt_sheeting_continuity_coefficient -> Text,
								 &cntrls_state_.edt_sheeting_continuity_coefficient_data_);
	if(rc > 0) throw(rc);

	rc = String_double_zero_plus(lbl_fact_quasi_perm_load -> Caption,
								 edt_fact_quasi_perm_load -> Text,
								 &cntrls_state_.edt_fact_quasi_perm_load_data_);
	if(rc > 0) throw(rc);

    // Отрисовка эпюр

	cntrls_state_.cmb_bx_impact_data_ = cmb_bx_impact -> ItemIndex;
	cntrls_state_.rd_grp_internal_forces_type_data_ = rd_grp_internal_forces_type -> ItemIndex;

	// Параметры расчёта

	cntrls_state_.rd_grp_code_data_ = rd_grp_code -> ItemIndex;
	rc = String_double_zero_plus(lbl_max_elem_length -> Caption,
								 edt_max_elem_length -> Text,
								 &cntrls_state_.edt_max_elem_length_data_);
	if(rc > 0) throw(rc);

	//Тип жб плиты

	cntrls_state_.rdgrp_slab_type_data_ = rdgrp_slab_type -> ItemIndex ;

	//Плита по настилу
	rc = String_double_zero_plus(lbl_h_f -> Caption,
								 edt_h_f -> Text,
								 &cntrls_state_.edt_h_f_data_);
	if(rc > 0) throw(rc);

	cntrls_state_.cmb_bx_corrugated_sheeting_part_number_data_ = cmb_bx_corrugated_sheeting_part_number -> ItemIndex ;
	cntrls_state_.chck_bx_wider_flange_up_data_ = chck_bx_wider_flange_up -> Checked ;
	cntrls_state_.chck_bx_sheet_orient_along_data_ = chck_bx_sheet_orient_along -> Checked;

	//Плита плоская
	rc = String_double_zero_plus(lbl_h_f_flat -> Caption,
								 edt_h_f_flat -> Text,
								 &cntrls_state_.edt_h_f_flat_data_);
	if(rc > 0) throw(rc);

	rc = String_double_zero_plus(lbl_h_n -> Caption,
								 edt_h_n -> Text,
								 &cntrls_state_.edt_h_n_data_);
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
	StudDefinitionForm -> store_cntrls_state();
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
	OnControlsChange(nullptr);

	update_GUI(static_cast<TRadioGroup*>(Sender) -> ItemIndex);
}
void TCompositeBeamMainForm::set_GUI_SP35()
{
    cotr_ratios_grid_SP35();
	rdgrp_slab_type -> ItemIndex = 0;
	rdgrp_slab_type -> Buttons [1] -> Visible = false;

	btn_add_impacts -> Visible = false;

	edt_sheeting_continuity_coefficient -> Visible = false;
	lbl_sheeting_continuity_coefficient -> Visible = false;
	edt_fact_quasi_perm_load -> Top = 22;
	lbl_fact_quasi_perm_load -> Top = 22;

	rdgrp_slab_typeClick(nullptr);

	ConcreteDefinitionForm -> set_GUI_SP35();
}
//---------------------------------------------------------------------------
void TCompositeBeamMainForm::set_GUI_SP266()
{
	cotr_ratios_grid_SP266();
	rdgrp_slab_type -> Buttons [1] -> Visible = true;

	btn_add_impacts -> Visible = true;

	edt_sheeting_continuity_coefficient -> Visible = true;
	lbl_sheeting_continuity_coefficient -> Visible = true;
	edt_fact_quasi_perm_load -> Top = 62;
	lbl_fact_quasi_perm_load -> Top = 62;

	ConcreteDefinitionForm -> set_GUI_SP266();
}
//---------------------------------------------------------------------------

void __fastcall TCompositeBeamMainForm::btn_loggerClick(TObject *Sender)
{
#ifndef NDEBUG
	print_to_logger();
#endif
}
#ifndef NDEBUG
void TCompositeBeamMainForm::print_to_logger()
{
	FormLogger -> Show();
	studs_output.print_to_logger();
}
#endif
//---------------------------------------------------------------------------
void TCompositeBeamMainForm::render_ratios_grid_SP266(TStringGrid* str_gr, int ACol,
	int ARow, TRect &Rect)
{
    	if (ARow == 0)
	{
		str_gr -> Canvas -> Font -> Style = TFontStyles() << fsBold;
		str_gr -> Canvas -> TextOut(Rect.Left+3, Rect.Top+5, str_gr -> Cells[ACol][ARow]);
	}
	if (ARow == 1 && ACol == 0)
	{
		str_gr -> Canvas -> Font -> Style = TFontStyles() << fsBold << fsUnderline << fsItalic;
		str_gr -> Canvas -> TextOut(Rect.Left+3, Rect.Top+5, str_gr -> Cells[ACol][ARow]);
	}
	if (ARow == 4 && ACol == 0)
	{
		str_gr -> Canvas -> Font -> Style = TFontStyles() << fsBold << fsUnderline << fsItalic;
		str_gr -> Canvas -> TextOut(Rect.Left+3, Rect.Top+5, str_gr -> Cells[ACol][ARow]);
	}
	if (ARow == 9 && ACol == 0)
	{
		str_gr -> Canvas -> Font -> Style = TFontStyles() << fsBold << fsUnderline << fsItalic;
		str_gr -> Canvas -> TextOut(Rect.Left+3, Rect.Top+5, str_gr -> Cells[ACol][ARow]);
	}
	if (ARow == 12 && ACol == 0)
	{
		str_gr -> Canvas -> Font -> Style = TFontStyles() << fsBold << fsUnderline << fsItalic;
		str_gr -> Canvas -> TextOut(Rect.Left+3, Rect.Top+5, str_gr -> Cells[ACol][ARow]);
	}
	if (ARow == 15 && ACol == 0)
	{
		str_gr -> Canvas -> Font -> Style = TFontStyles() << fsBold << fsUnderline << fsItalic;
		str_gr -> Canvas -> TextOut(Rect.Left+3, Rect.Top+5, str_gr -> Cells[ACol][ARow]);
	}
	if (ARow == 1 && ACol == 1)
	{
		str_gr -> Canvas -> Brush -> Color = clBtnFace;
		str_gr -> Canvas -> FillRect(Rect);
	}
	if (ARow == 4 && ACol == 1)
	{
		str_gr -> Canvas -> Brush -> Color = clBtnFace;
		str_gr -> Canvas -> FillRect(Rect);
	}
	if (ARow == 9 && ACol == 1)
	{
		str_gr -> Canvas -> Brush -> Color = clBtnFace;
		str_gr -> Canvas -> FillRect(Rect);
	}
	if (ARow == 12 && ACol == 1)
	{
		str_gr -> Canvas -> Brush -> Color = clBtnFace;
		str_gr -> Canvas -> FillRect(Rect);
	}
	if (ARow == 15 && ACol == 1)
	{
		str_gr -> Canvas -> Brush -> Color = clBtnFace;
		str_gr -> Canvas -> FillRect(Rect);
	}

}
//---------------------------------------------------------------------------
void TCompositeBeamMainForm::render_ratios_grid_SP35(TStringGrid* str_gr, int ACol,
	int ARow, TRect &Rect)
{
	if (ARow == 0)
	{
		str_gr -> Canvas -> Font -> Style = TFontStyles() << fsBold;
		str_gr -> Canvas -> TextOut(Rect.Left+3, Rect.Top+5, str_gr -> Cells[ACol][ARow]);
	}
	if (ARow == 1 && ACol == 0)
	{
		str_gr -> Canvas -> Font -> Style = TFontStyles() << fsBold << fsUnderline << fsItalic;
		str_gr -> Canvas -> TextOut(Rect.Left+3, Rect.Top+5, str_gr -> Cells[ACol][ARow]);
	}
	if (ARow == 4 && ACol == 0)
	{
		str_gr -> Canvas -> Font -> Style = TFontStyles() << fsBold << fsUnderline << fsItalic;
		str_gr -> Canvas -> TextOut(Rect.Left+3, Rect.Top+5, str_gr -> Cells[ACol][ARow]);
	}
	if (ARow == 9 && ACol == 0)
	{
		str_gr -> Canvas -> Font -> Style = TFontStyles() << fsBold << fsUnderline << fsItalic;
		str_gr -> Canvas -> TextOut(Rect.Left+3, Rect.Top+5, str_gr -> Cells[ACol][ARow]);
	}
	if (ARow == 12 && ACol == 0)
	{
		str_gr -> Canvas -> Font -> Style = TFontStyles() << fsBold << fsUnderline << fsItalic;
		str_gr -> Canvas -> TextOut(Rect.Left+3, Rect.Top+5, str_gr -> Cells[ACol][ARow]);
	}
	if (ARow == 1 && ACol == 1)
	{
		str_gr -> Canvas -> Brush -> Color = clBtnFace;
		str_gr -> Canvas -> FillRect(Rect);
	}
	if (ARow == 4 && ACol == 1)
	{
		str_gr -> Canvas -> Brush -> Color = clBtnFace;
		str_gr -> Canvas -> FillRect(Rect);
	}
	if (ARow == 9 && ACol == 1)
	{
		str_gr -> Canvas -> Brush -> Color = clBtnFace;
		str_gr -> Canvas -> FillRect(Rect);
	}
	if (ARow == 12 && ACol == 1)
	{
		str_gr -> Canvas -> Brush -> Color = clBtnFace;
		str_gr -> Canvas -> FillRect(Rect);
	}
}

//---------------------------------------------------------------------------


