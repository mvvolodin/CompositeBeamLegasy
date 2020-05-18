//---------------------------------------------------------------------------
#include <vcl.h>
#include<ComObj.hpp>
#include <ostream>
#include <fstream>
#pragma hdrstop

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

#include "CompositeBeamMainFormUnit.h"
#include "String_doubleUnit.h"  //Функции проверяющие правильность ввода данных в поля формы
#include "Report.h" //Подключаем генератор отчётов
#include "Word_Automation.h"  // Вывод отчета в Word
#include "AboutProg.h"

TCompositeBeamMainForm *CompositeBeamMainForm;

//----------------------------------------------------------------------
 _fastcall TCompositeBeamMainForm::TCompositeBeamMainForm(TComponent* Owner)
	: TForm(Owner)
{
	composite_beam_calculator_.set_default_values();

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

	register_observers();

	register_I_composite_beam();

	set_form_controls();

	NNewClick(Sender);

//	SteelSectionForm->SteelSectionDefinitionFrame->RadioGroupGOST57837->ItemIndex=0;
//	SteelSectionForm->SteelSectionDefinitionFrame->RadioGroupGOST57837Click(Sender);
//	Pnl_SteelSectionViewer->Caption = SteelSectionForm->SteelSectionDefinitionFrame
//	->ComboBox_profil->Text;
   //	DefineSteelForm->cmb_bx_steel_gradesChange(Sender);
   //	pnl_steel->Caption = DefineSteelForm -> cmb_bx_steel_grades->Text;
	rdgrp_slab_typeClick(Sender);

	calculate_composite_beam();

}
//----------------------------------------------------------------------
////Присваивение значений полям формы из данных класс типа TCompositeBeam
//----------------------------------------------------------------------
void TCompositeBeamMainForm::set_form_controls()
{
 // Данные типа TGeometry
	TGeometry geom = composite_beam_calculator_.get_geometry();
	edt_beam_division -> Text = geom.get_beam_division();
	edt_span -> Text = geom.get_span();
	edt_width_left -> Text = geom.get_trib_width_left();
	edt_width_right -> Text = geom.get_trib_width_right();
	cmb_bx_number_propping_supports -> ItemIndex = cmb_bx_number_propping_supports -> Items -> IndexOf(geom.get_temporary_supports_number());
//Данные типа Loads
	TLoads loads = composite_beam_calculator_.get_loads();
	edt_dead_load_first_stage -> Text = loads.get_dead_load_first_stage(LoadUnit::kN, LengthUnit::m);
	edt_dead_load_second_stage -> Text = loads.get_dead_load_second_stage(LoadUnit::kN, LengthUnit::m);
	edt_live_load -> Text = loads.get_live_load(LoadUnit::kN, LengthUnit::m);
	edt_gamma_f_st_SW_-> Text = loads.get_gamma_f_st_SW();
	edt_gamma_f_concrete -> Text = loads.get_gamma_f_concrete_SW();
	edt_gamma_f_DL_I -> Text = loads.get_gamma_f_DL_I();
	edt_gamma_f_DL_II -> Text = loads.get_gamma_f_DL_II();
	edt_gamma_f_LL -> Text = loads.get_gamma_f_LL();

//Данные типа WorkingConditionsFactors
	WorkingConditionsFactors wcf = composite_beam_calculator_.get_working_conditions_factors();
	edt_gamma_bi -> Text = wcf.get_gamma_bi();
	edt_gamma_si -> Text = wcf.get_gamma_si();
	edt_gamma_c -> Text = wcf.get_gamma_c();

//Панели для отображения данных
	pnl_shear_stud_viewer -> Caption = StudDefinitionForm -> get_studs_on_beam().get_name();
	pnl_rebar_viewer -> Caption = RebarDefinitionForm -> get_rebar().get_grade();
	pnl_concrete_grade -> Caption = ConcreteDefinitionForm -> get_concrete().get_grade();
	Pnl_SteelSectionViewer -> Caption = SteelSectionForm2 -> get_i_section().get_profile_number();

//Данные для плиты

	switch (composite_beam_calculator_.get_composite_section().get_concrete_part().get_slab_type_enum())
	{
	case SlabType::FLAT:
		rdgrp_slab_type -> ItemIndex = 0;
		break;
	case SlabType::CORRUGATED:
		rdgrp_slab_type -> ItemIndex = 1;
		cmb_bx_corrugated_sheeting_part_number -> ItemIndex =
			cmb_bx_corrugated_sheeting_part_number -> Items -> IndexOf(composite_beam_calculator_.get_composite_section().get_concrete_part().get_slab_type());
		break;
	}
	edt_h_f_flat -> Text = composite_beam_calculator_.get_composite_section().get_concrete_part().get_h_f();
	edt_h_f -> Text = composite_beam_calculator_.get_composite_section().get_concrete_part().get_h_f();
	edt_h_n -> Text = composite_beam_calculator_.get_composite_section().get_concrete_part().get_h_n();

//Данные типа Studs
   	StudDefinitionForm -> set_form_controls(composite_beam_calculator_.get_studs_on_beam());

//Данные типа Rebar
	RebarDefinitionForm -> set_form_controls(composite_beam_calculator_.get_composite_section().get_concrete_part().get_rebar());

//Данные типа Concrete
	ConcreteDefinitionForm -> set_form_controls(composite_beam_calculator_.get_composite_section().get_concrete_part().get_concrete());
	Concrete con = composite_beam_calculator_.get_composite_section().get_concrete_part().get_concrete();

//Данные типа Steel
	DefineSteelForm -> set_form_controls(composite_beam_calculator_.get_composite_section().get_steel_part().get_steel());
//Данные типа Section
	SteelSectionForm2 -> set_form_controls(composite_beam_calculator_.get_composite_section().get_steel_part().get_section());

}
void TCompositeBeamMainForm::register_observers()
{
	std::vector<IPublisher*> ipublishers;
	ipublishers.push_back(RebarDefinitionForm);
	ipublishers.push_back(StudDefinitionForm);
	ipublishers.push_back(ConcreteDefinitionForm);
	ipublishers.push_back(DefineSteelForm);
	ipublishers.push_back(SteelSectionForm2);
	for(auto ip:ipublishers)
	ip -> register_observer(this);

}
void TCompositeBeamMainForm::register_I_composite_beam()
{
	DefineSteelForm -> register_icopmosite_beam_user(this);
}

//---------------------------------------------------------------------------
//Инициализация топологии
//---------------------------------------------------------------------------
TGeometry TCompositeBeamMainForm::init_geomet()
{
	double beam_division = 0.;//поменять тип на double и написать функцию проверки значения поля на тип int
	double span = 0.;
	double trib_width_left = 0.;
	double trib_width_right = 0.;

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
	double SW_sheets = 0.;

	if (rdgrp_slab_type->ItemIndex==1)
		SW_sheets = corrugated_sheets_map[cmb_bx_corrugated_sheeting_part_number->Text].get_weight()* GRAV_ACCELERAT;

	double SW = SteelSectionForm2 -> get_i_section().get_weight() * GRAV_ACCELERAT;

	double DL_I = 0.;
	double DL_II = 0.;
	double LL = 0.;
	double gamma_f_st_SW = 0.;
	double gamma_f_DL_I = 0.;
	double gamma_f_DL_II= 0.;
	double gamma_f_LL = 0.;

	String_double_zero_plus(lbl_dead_load_first_stage->Caption, edt_dead_load_first_stage->Text, &DL_I);
	String_double_zero_plus(lbl_dead_load_second_stage->Caption, edt_dead_load_second_stage->Text, &DL_II);
	String_double_zero_plus(lbl_live_load->Caption, edt_live_load->Text, &LL);
	String_double_zero_plus(lbl_gamma_f_st_SW->Caption, edt_gamma_f_st_SW_->Text, &gamma_f_st_SW);
	String_double_zero_plus(lbl_gamma_f_DL_I->Caption, edt_gamma_f_DL_I->Text, &gamma_f_DL_I);
	String_double_zero_plus(lbl_gamma_f_DL_II->Caption, edt_gamma_f_DL_II->Text, &gamma_f_DL_II);
	String_double_zero_plus(lbl_gamma_f_LL->Caption, edt_gamma_f_LL->Text, &gamma_f_LL);

	return TLoads (SW, SW_sheets, DL_I, DL_II, LL, gamma_f_st_SW, gamma_f_DL_I, gamma_f_DL_II, gamma_f_LL);
}
//---------------------------------------------------------------------------
//Инициализация геометрии двутавра
//---------------------------------------------------------------------------
ISection TCompositeBeamMainForm::init_i_section()
{
	return SteelSectionForm2 -> get_i_section();
}
//---------------------------------------------------------------------------
//	Инициализация материала двутавра
//---------------------------------------------------------------------------
Steel TCompositeBeamMainForm::init_steel_i_section()
{
	return DefineSteelForm -> get_steel();
}
//---------------------------------------------------------------------------
//Инициализация железобетонной части сечения
//---------------------------------------------------------------------------
TConcretePart TCompositeBeamMainForm::init_concrete_part()
{
	TGeometry geometry = init_geomet();
	ISection i_section = SteelSectionForm2 -> get_i_section();
	double b_uf = i_section.get_b_uf();

	if (rdgrp_slab_type -> ItemIndex ==0)
	{
		double t_sl = 0.;
		double h_n = 0.;
		String_double_plus(lbl_h_f_flat -> Caption, edt_h_f_flat -> Text, &t_sl);
		String_double_zero_plus(lbl_h_n -> Caption, edt_h_n -> Text, &h_n);
		return TConcretePart (L"Плоская плита",
							  SlabType::FLAT,
							  ConcreteDefinitionForm->get_concrete(),
							  RebarDefinitionForm->get_rebar(),
							  t_sl,
							  h_n);
	}
	else
	{
	double h_f = 0.;

	String_double_plus(lbl_h_f->Caption, edt_h_f->Text, &h_f);

	return TConcretePart (cmb_bx_corrugated_sheeting_part_number->Text,
						  SlabType::CORRUGATED,
						  ConcreteDefinitionForm->get_concrete(),
						  RebarDefinitionForm->get_rebar(),
						  h_f,
						  0.);
	}
}
//---------------------------------------------------------------------------
//Инициализация стальной части сечения
//---------------------------------------------------------------------------
SteelPart TCompositeBeamMainForm::init_steel_part()
{

   ISection i_section = init_i_section();
   Steel steel_i_section = init_steel_i_section();

	return SteelPart(i_section, steel_i_section);
}
//---------------------------------------------------------------------------
//	Инициализация упоров
//---------------------------------------------------------------------------
StudsOnBeam TCompositeBeamMainForm::init_studs_on_beam()
{
	return StudDefinitionForm -> get_studs_on_beam();
}
//---------------------------------------------------------------------------
//	Инициализация коэффициентов условий работы
//---------------------------------------------------------------------------
 WorkingConditionsFactors TCompositeBeamMainForm::init_working_conditions_factors()
 {
	double gamma_bi=0.;
	double gamma_si=0.;
	double gamma_c=0.;

	String_double_plus(lbl_gamma_bi->Caption, edt_gamma_bi->Text, &gamma_bi);
	String_double_plus(lbl_gamma_si->Caption, edt_gamma_si->Text, &gamma_si);
	String_double_plus(lbl_gamma_c->Caption, edt_gamma_c->Text, &gamma_c);

	return WorkingConditionsFactors(gamma_bi,gamma_si,gamma_c);
 }

// ---------------------------------------------------------------------------
// Инициализация композитной балки
//---------------------------------------------------------------------------
void TCompositeBeamMainForm::update_composite_beam()
{

   TGeometry geometry = init_geomet();
   TLoads loads = init_loads();

   SteelPart steel_part = init_steel_part();
   TConcretePart concrete_part = init_concrete_part();
   CompositeSectionGeometry composite_section = CompositeSectionGeometry(steel_part, concrete_part);

   StudsOnBeam studs_on_beam = init_studs_on_beam();

   WorkingConditionsFactors working_conditions_factors = init_working_conditions_factors();

	composite_beam_calculator_ = CompositeBeamCalculator(geometry,
											  loads,
											  composite_section,
											  studs_on_beam,
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
	strng_grd_compos_sect_geom_character->Cells [0][1]=L"Площадь Ared, мм2";
	strng_grd_compos_sect_geom_character->Cells [0][2]=L"Момент инерции Ired, мм4 ";
	strng_grd_compos_sect_geom_character->Cells [0][3]=L"Момент сопротивления, Ц.Т. ж.б. плиты Wb,red, мм3";
	strng_grd_compos_sect_geom_character->Cells [0][4]=L"Момент сопротивления, верхн. полка Wf2,red, мм3";
	strng_grd_compos_sect_geom_character->Cells [0][5]=L"Момент сопротивления, нижн. полка Wf1,red, мм3";
	strng_grd_compos_sect_geom_character->Cells [0][6]=L"Расстояние Zb,red, мм";
	strng_grd_compos_sect_geom_character->Cells [0][7]=L"Расстояние Zf2,red мм";
	strng_grd_compos_sect_geom_character->Cells [0][8]=L"Расстояние Zf1,red мм";
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
	ISection i_section= composite_beam_calculator_.get_composite_section().get_steel_part().get_section();

	strng_grd_steel_sect_geom_character->Cells [1][1]=FloatToStrF(i_section.get_A_st(), ffFixed, 15, 0);
	strng_grd_steel_sect_geom_character->Cells [1][2]=FloatToStrF(i_section.get_I_st(), ffFixed, 15, 0);
	strng_grd_steel_sect_geom_character->Cells [1][3]=FloatToStrF(i_section.get_Wf2_st(), ffFixed, 15, 0);
	strng_grd_steel_sect_geom_character->Cells [1][4]=FloatToStrF(i_section.get_Wf1_st(), ffFixed, 15, 0);
	strng_grd_steel_sect_geom_character->Cells [1][5]=FloatToStrF(i_section.get_Z_f2_st(), ffFixed, 15, 0);
	strng_grd_steel_sect_geom_character->Cells [1][6]=FloatToStrF(i_section.get_Z_f1_st(), ffFixed, 15, 0);
}
void TCompositeBeamMainForm::fill_concrete_sect_geometr_grid()
{
	TConcretePart concrete_part=composite_beam_calculator_.get_composite_section().get_concrete_part();

	//strng_grd_concrete_sect_geom_character->Cells [1][1]=FloatToStrF(concrete_part.get_b_l(), ffFixed, 15, 0);
	strng_grd_concrete_sect_geom_character->Cells [1][2]=FloatToStrF(concrete_part.get_b(), ffFixed, 15, 0);
	strng_grd_concrete_sect_geom_character->Cells [1][3]=FloatToStrF(concrete_part.get_C_b(), ffFixed, 15, 0);
	strng_grd_concrete_sect_geom_character->Cells [1][4]=FloatToStrF(concrete_part.get_A_b(), ffFixed, 15, 0);
	strng_grd_concrete_sect_geom_character->Cells [1][5]=FloatToStrF(concrete_part.get_I_b(), ffFixed, 15, 0);
}
void TCompositeBeamMainForm::fill_composite_sect_geometr_grid()
{
	double A_red=composite_beam_calculator_.get_composite_section().get_A_red();
	double I_red=composite_beam_calculator_.get_composite_section().get_I_red();
	double W_b_red=composite_beam_calculator_.get_composite_section().get_W_b_red();
	double W_f2_red=composite_beam_calculator_.get_composite_section().get_W_f2_red();
	double W_f1_red=composite_beam_calculator_.get_composite_section().get_W_f1_red();
	double Z_b_red=composite_beam_calculator_.get_composite_section().get_Z_b_red();
	double Z_f2_red=composite_beam_calculator_.get_composite_section().get_Z_f2_red();
	double Z_f1_red=composite_beam_calculator_.get_composite_section().get_Z_f1_red();

	strng_grd_compos_sect_geom_character->Cells [1][1]=FloatToStrF(A_red, ffFixed, 15, 0); //Предельно значение точность для
	strng_grd_compos_sect_geom_character->Cells [1][2]=FloatToStrF(I_red, ffFixed, 15, 0); //типа double 15
	strng_grd_compos_sect_geom_character->Cells [1][3]=FloatToStrF(W_b_red, ffFixed, 15, 0);
	strng_grd_compos_sect_geom_character->Cells [1][4]=FloatToStrF(std::abs(W_f2_red), ffFixed, 15, 0);
	strng_grd_compos_sect_geom_character->Cells [1][5]=FloatToStrF(W_f1_red, ffFixed, 15, 0);
	strng_grd_compos_sect_geom_character->Cells [1][6]=FloatToStrF(Z_b_red, ffFixed, 15, 0);
	strng_grd_compos_sect_geom_character->Cells [1][7]=FloatToStrF(std::abs(Z_f2_red), ffFixed, 15, 0);
	strng_grd_compos_sect_geom_character->Cells [1][8]=FloatToStrF(Z_f1_red, ffFixed, 15, 0);
}

void TCompositeBeamMainForm::fill_results_grid()
{
	Section max_direct_stress_ratio_section = composite_beam_calculator_.get_sections_beam().get_max_direct_stress_ratio_section();
	Section max_rigid_plastic_ratio_section = composite_beam_calculator_.get_sections_beam().get_max_rigid_plastic_ratio_section();
	Section max_shear_stress_section = composite_beam_calculator_.get_sections_beam().get_max_shear_stress_ratio_section();

	double max_upper_flange_ratio = max_direct_stress_ratio_section.get_upper_fl_ratio();
	double max_lower_flange_ratio = max_direct_stress_ratio_section.get_lower_fl_ratio();
	double ratio_rigid_plastic =  max_rigid_plastic_ratio_section.get_rigid_plastic_ratio();
	double max_ratio_studs = composite_beam_calculator_.get_max_stud_ratio();
	double max_shear_ratio = max_shear_stress_section.get_shear_ratio();

	strng_grd_results->Cells [1][1]=FloatToStrF(std::abs(max_upper_flange_ratio), ffFixed, 15, 2);
	strng_grd_results->Cells [1][2]=FloatToStrF(std::abs(max_lower_flange_ratio), ffFixed, 15, 2);
	strng_grd_results->Cells [1][3]=FloatToStrF(std::abs(max_shear_ratio), ffFixed, 15, 2);
	strng_grd_results->Cells [1][4]=FloatToStrF(std::abs(max_ratio_studs), ffFixed, 15, 2);
	strng_grd_results->Cells [1][5]=FloatToStrF(ratio_rigid_plastic, ffFixed, 15, 2);

}
//---------------------------------------------------------------------------
//	Функция заполняющая Grid выводящий результаты расчёта композитной балки
//---------------------------------------------------------------------------
void TCompositeBeamMainForm:: cotr_ratios_grid()
{
	strng_grd_results->Cells [0][0]="Проверка";
	strng_grd_results->Cells [1][0]="Коэффициенты Использования (КИ) ";
	strng_grd_results->Cells [0][1]="Верхний пояс стального сечения, раздел 6.2.1";
	strng_grd_results->Cells [0][2]="Нижний пояс стального сеченния, раздел 6.2.1";
	strng_grd_results->Cells [0][3]="Поперечная силы, раздел 6.2.2";
	strng_grd_results->Cells [0][4]="Прочность упоров объединения, раздел 9.1.2";
	strng_grd_results->Cells [0][5]="Прочность балки при жёскопластическом материале раздел 6.2.1.6";
}
//---------------------------------------------------------------------------
//	Функция заполняющая ComboBox случаями загружений
//---------------------------------------------------------------------------
void TCompositeBeamMainForm::fill_cmb_bx_impact()
{
	cmb_bx_impact -> Items -> Append(L"Расчётные нагрузки Ia стадии");
	cmb_bx_impact -> Items -> Append(L"Расчётные нагрузки Ib стадии");
	cmb_bx_impact -> Items -> Append(L"Расчётные нагрузки IIa стадии");
	cmb_bx_impact -> Items -> Append(L"Расчётные нагрузки IIb стадии");
	cmb_bx_impact -> Items -> Append(L"Расчётные нагрузки полные");

	cmb_bx_impact -> ItemIndex = 4;
}
//---------------------------------------------------------------------------
//	Функция заполняющая ComboBox настилами
//---------------------------------------------------------------------------
void TCompositeBeamMainForm::fill_cmb_bx_corrugated_sheets()
{
	for(auto corrugated_sheet: corrugated_sheets_map)
	cmb_bx_corrugated_sheeting_part_number->Items->Add(corrugated_sheet.first);
	cmb_bx_corrugated_sheeting_part_number->ItemIndex = 0;

}
//---------------------------------------------------------------------------

void __fastcall TCompositeBeamMainForm::BtBtnSteelChoiceClick(TObject *Sender)
{
	 DefineSteelForm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TCompositeBeamMainForm::BtnSteelSectionChoiceClick(TObject *Sender)
{
	SteelSectionForm2 -> Show();
}
//---------------------------------------------------------------------------


void __fastcall TCompositeBeamMainForm::BtBtnExitClick(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

void __fastcall TCompositeBeamMainForm::BtnConcreteChoiceClick(TObject *Sender)
{
	ConcreteDefinitionForm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TCompositeBeamMainForm::BtBtnRebarsChoiceClick(TObject *Sender)
{
	RebarDefinitionForm->Show();

}
//---------------------------------------------------------------------------

void __fastcall TCompositeBeamMainForm::BtBtnShearStudsChoiceClick(TObject *Sender)
{
	StudDefinitionForm->Show();
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
	TWord_Automation report_ = TWord_Automation("ReportCompositeBeam.docx");
	//TWord_Automation report_ = TWord_Automation("ReportCompositeBeam.doc");
	TGeometry geometry = composite_beam_calculator_.get_geometry();
	TLoads loads = composite_beam_calculator_.get_loads();
	CompositeSectionGeometry composite_section = composite_beam_calculator_.get_composite_section();
	ISection i_section = composite_beam_calculator_.get_composite_section().get_steel_part().get_section();
	TConcretePart concrete_part = composite_beam_calculator_.get_composite_section().get_concrete_part();
	Concrete concrete = concrete_part.get_concrete();
	Rebar rebar = concrete_part.get_rebar();
	Steel steel = composite_beam_calculator_.get_composite_section().get_steel_grade();
   //	Studs studs = composite_beam_calculator_.get_studs();
	WorkingConditionsFactors working_conditions_factors=composite_beam_calculator_.get_working_conditions_factors();

//[1.1] Топология
	report_.PasteTextPattern(geometry.is_end_beam_to_str(), "%end_beam%");
	report_.PasteTextPattern(FloatToStrF(geometry.get_span(LengthUnit::mm), ffFixed, 15, 2), "%span%");
	report_.PasteTextPattern(FloatToStrF(geometry.get_trib_width_left(LengthUnit::mm), ffFixed, 15, 2), "%trib_width_left% ");
	report_.PasteTextPattern(FloatToStrF(geometry.get_trib_width_right(LengthUnit::mm), ffFixed, 15, 2), "%trib_width_right% ");
//[1.2] Загружения
	report_.PasteTextPattern(FloatToStrF(loads.get_dead_load_first_stage(LoadUnit::kN, LengthUnit::m), ffFixed, 15, 2), "%DL_I%");
	report_.PasteTextPattern(FloatToStrF(loads.get_dead_load_second_stage(LoadUnit::kN, LengthUnit::m), ffFixed, 15, 2), "%DL_II%");
	report_.PasteTextPattern(FloatToStrF(loads.get_live_load(LoadUnit::kN, LengthUnit::m), ffFixed, 15, 2), "%LL%");

//[1.3] Коэффициенты надёжности по нагрузке
	report_.PasteTextPattern(FloatToStrF(loads.get_gamma_f_st_SW(), ffFixed, 15, 2), "%gamma_f_st_SW%");
	report_.PasteTextPattern(FloatToStrF(loads.get_gamma_f_DL_I(), ffFixed, 15, 2), "%gamma_f_DL_I%");
	report_.PasteTextPattern(FloatToStrF(loads.get_gamma_f_DL_II(), ffFixed, 15, 2), "%gamma_f_DL_II%");
	report_.PasteTextPattern(FloatToStrF(loads.get_gamma_f_LL(), ffFixed, 15, 2), "%gamma_f_LL%");
//[1.4] Стальное сечение
//[1.4.1] Номинальные размеры двутавра
	report_.PasteTextPattern(i_section.get_profile_number(),"%profile_number%");
	report_.PasteTextPattern(FloatToStrF(i_section.get_h_st(LengthUnit::mm), ffFixed, 15, 2),"%h%");
	report_.PasteTextPattern(FloatToStrF(0, ffFixed, 15, 2),"%h%");
	report_.PasteTextPattern(FloatToStrF(i_section.get_b_uf(LengthUnit::mm), ffFixed, 15, 2),"%b%");
	report_.PasteTextPattern(FloatToStrF(0, ffFixed, 15, 2),"%b_w%");
	report_.PasteTextPattern(FloatToStrF(i_section.get_t_uf(LengthUnit::mm), ffFixed, 15, 2),"%t%");
	report_.PasteTextPattern(FloatToStrF(i_section.get_t_w(LengthUnit::mm), ffFixed, 15, 2),"%s%");
	report_.PasteTextPattern(FloatToStrF(i_section.get_r(LengthUnit::mm), ffFixed, 15, 2),"%r%");
//[1.4.2] Характеристики стали
	report_.PasteTextPattern(steel.get_steel_grade(),"%steel_grade%");
	report_.PasteTextPattern(FloatToStrF(steel.get_R_yn(), ffFixed, 15, 2),"%R_yn%");
	report_.PasteTextPattern(FloatToStrF(steel.get_R_un(), ffFixed, 15, 2),"%R_un%");
	report_.PasteTextPattern(FloatToStrF(steel.get_E_st(), ffFixed, 15, 2),"%E_st%");
	report_.PasteTextPattern(FloatToStrF(steel.get_G_st(), ffFixed, 15, 2),"%G_st%");
	report_.PasteTextPattern(FloatToStrF(steel.get_nu_st(), ffFixed, 15, 2),"%nu_st%");
	report_.PasteTextPattern(FloatToStrF(steel.get_gamma_m(), ffFixed, 15, 2),"%gamma_m%");
//[1.5] Железобетонное сечение
//[1.5.1] Номинальные размеры плиты
	report_.PasteTextPattern(concrete_part.get_slab_type(),"%slab_type%");
	report_.PasteTextPattern(concrete_part.get_h(),"%t_sl%");

//[1.5.2] Характеристики бетона

	report_.PasteTextPattern(concrete.get_grade(),"%conc_grade%");
	report_.PasteTextPattern(FloatToStrF(concrete.get_R_bn(), ffFixed, 15, 2),"%R_bn%");
	report_.PasteTextPattern(FloatToStrF(concrete.get_R_btn(), ffFixed, 15, 2),"%R_btn%");
	report_.PasteTextPattern(FloatToStrF(concrete.get_E_b(), ffFixed, 15, 2),"%E_b%");
	report_.PasteTextPattern(FloatToStrF(concrete.get_gamma_b(), ffFixed, 15, 2),"%gamma_b%");
	report_.PasteTextPattern(FloatToStrF(concrete.get_gamma_bt(), ffFixed, 15, 2),"%gamma_bt%");


//[1.6] Арматура
	report_.PasteTextPattern(rebar.get_grade(),"%grade%");
	report_.PasteTextPattern(FloatToStrF(rebar.get_diameter(), ffFixed, 15, 2),"%d%");
	report_.PasteTextPattern(FloatToStrF(rebar.get_R_sn(), ffFixed, 15, 2),"%R_sn%");
//[1.7] Соединительные элементы
//	report_.PasteTextPattern(studs.get_name(),"%name%");
//	report_.PasteTextPattern(FloatToStrF(studs.get_l(LengthUnit::cm), ffFixed, 15, 2),"%l%");
//	report_.PasteTextPattern(FloatToStrF(studs.get_d_an(LengthUnit::cm), ffFixed, 15, 2),"%d_an%");
//	report_.PasteTextPattern(FloatToStrF(studs.get_R_y(), ffFixed, 15, 2),"%R_y%");
//	report_.PasteTextPattern(FloatToStrF(studs.get_edge_rows_dist(LengthUnit::cm), ffFixed, 15, 2),"%z_e%");
//	report_.PasteTextPattern(FloatToStrF(studs.get_middle_rows_dist(LengthUnit::cm), ffFixed, 15, 2),"%z_m%");
//	report_.PasteTextPattern(FloatToStrF(studs.get_edge_rows_num(), ffFixed, 15, 2),"%ed_rw_num%");
//	report_.PasteTextPattern(FloatToStrF(studs.get_middle_rows_num(), ffFixed, 15, 2),"%mid_rw_num%");
//[1.8] Коэффициенты
	report_.PasteTextPattern(FloatToStrF(working_conditions_factors.get_gamma_c(), ffFixed, 15, 2),"%gamma_c%");
	report_.PasteTextPattern(FloatToStrF(working_conditions_factors.get_gamma_bi(), ffFixed, 15, 2),"%gamma_bi%");
	report_.PasteTextPattern(FloatToStrF(working_conditions_factors.get_gamma_si(), ffFixed, 15, 2),"%gamma_si%");
//[1.9] Прочее
	report_.PasteTextPattern(FloatToStrF(geometry.get_temporary_supports_number(), ffFixed, 15, 2),"%temp_supp%");


//[2] Результаты расчёта балки
//[2.1] Геометрические параметры
//[2.1.1] Стального сечения
	report_.PasteTextPattern(FloatToStrF(i_section.get_A_st(LengthUnit::cm), ffFixed, 15, 2),"%A_st%");
	report_.PasteTextPattern(FloatToStrF(i_section.get_I_st(LengthUnit::cm), ffFixed, 15, 2),"%I_st%");
	report_.PasteTextPattern(FloatToStrF(i_section.get_Wf2_st(LengthUnit::cm), ffFixed, 15, 2),"%Wf2_st%");
	report_.PasteTextPattern(FloatToStrF(i_section.get_Wf1_st(LengthUnit::cm), ffFixed, 15, 2),"%Wf1_st%");
	report_.PasteTextPattern(FloatToStrF(i_section.get_Z_f2_st(LengthUnit::cm), ffFixed, 15, 2),"%Z_f2_st%");
	report_.PasteTextPattern(FloatToStrF(i_section.get_Z_f1_st(LengthUnit::cm), ffFixed, 15, 2),"%Z_f1_st%");
//[2.1.2] Железобетонного сечения
	report_.PasteTextPattern(concrete_part.get_slab_type(),"%slab_type%");
	report_.PasteTextPattern(FloatToStrF(concrete_part.get_b(LengthUnit::cm), ffFixed, 15, 2),"%b_l%");
	report_.PasteTextPattern(FloatToStrF(concrete_part.get_C_b(LengthUnit::cm), ffFixed, 15, 2),"%C_b%");
	report_.PasteTextPattern(FloatToStrF(concrete_part.get_A_b(LengthUnit::cm), ffFixed, 15, 2),"%A_b%");
	report_.PasteTextPattern(FloatToStrF(concrete_part.get_I_b(LengthUnit::cm), ffFixed, 15, 2),"%I_b%");
//[2.1.3] Композитного сечения
	report_.PasteTextPattern(FloatToStrF(composite_section.get_A_red(LengthUnit::cm), ffFixed, 15, 2),"%A_red%");
	report_.PasteTextPattern(FloatToStrF(composite_section.get_I_red(LengthUnit::cm), ffFixed, 15, 2),"%I_red%");
	report_.PasteTextPattern(FloatToStrF(composite_section.get_W_b_red(LengthUnit::cm), ffFixed, 15, 2),"%W_b_red%");
	report_.PasteTextPattern(FloatToStrF(composite_section.get_W_f2_red(LengthUnit::cm), ffFixed, 15, 2),"%W_f2_red%");
	report_.PasteTextPattern(FloatToStrF(composite_section.get_W_f1_red(LengthUnit::cm), ffFixed, 15, 2),"%W_f1_red%");
	report_.PasteTextPattern(FloatToStrF(composite_section.get_Z_b_red(LengthUnit::cm), ffFixed, 15, 2),"%Z_b_red%");
	report_.PasteTextPattern(FloatToStrF(composite_section.get_Z_f2_red(LengthUnit::cm), ffFixed, 15, 2),"%Z_f2_red%");
	report_.PasteTextPattern(FloatToStrF(composite_section.get_Z_f1_red(LengthUnit::cm), ffFixed, 15, 2),"%Z_f1_red%");
//[2.2] Усилия
	report_.PasteTextPattern(FloatToStrF(composite_beam_calculator_.get_max_lower_flange_ratio_coordinate(), ffFixed, 15, 0),"%cs_x%");
	report_.PasteTextPattern(FloatToStrF(composite_beam_calculator_.get_M_I_for_cs_with_max_lower_flange_ratio(LoadUnit::kN, LengthUnit::m), ffFixed, 15, 2),"%M_I%");
	report_.PasteTextPattern(FloatToStrF(composite_beam_calculator_.get_M_II_for_cs_with_max_lower_flange_ratio(LoadUnit::kN, LengthUnit::m), ffFixed, 15, 2),"%M_II%");
	report_.PasteTextPattern(FloatToStrF(composite_beam_calculator_.get_M_total_for_cs_with_max_lower_flange_ratio(LoadUnit::kN, LengthUnit::m), ffFixed, 15, 2),"%M_total%");


//[2.3] Напряжения
	report_.PasteTextPattern(FloatToStrF(composite_beam_calculator_.get_sigma_b_for_cs_with_max_lower_flange_ratio(), ffFixed, 15, 2),"%sigma_b%");
	report_.PasteTextPattern(FloatToStrF(composite_beam_calculator_.get_sigma_s_for_cs_with_max_lower_flange_ratio(), ffFixed, 15, 2),"%sigma_s%");
//[2.4] Коэффициенты использования
	report_.PasteTextPattern(FloatToStrF(composite_beam_calculator_.get_max_upper_flange_ratio(),ffFixed, 15, 2),"%ratio_uf%");
	report_.PasteTextPattern(FloatToStrF(composite_beam_calculator_.get_max_lower_flange_ratio(),ffFixed, 15, 2),"%ratio_lf%");
	report_.PasteTextPattern(FloatToStrF(composite_beam_calculator_.get_max_lower_flange_ratio(),ffFixed, 15, 2),"%ratio_lf%");
	report_.PasteTextPattern(FloatToStrF(composite_beam_calculator_.get_max_shear_ratio(),ffFixed, 15, 2),"%ratio_shear%");

//[3] Результаты расчёта конструкций объединения

//[3.1] Несущая способность упора
 // report_.PasteTextPattern(FloatToStrF(composite_beam_calculator_.get_studs().get_P_rd(LoadUnit::kN),ffFixed, 15, 2),"%P_rd%");

  //[3.2] Усилия
  report_.PasteTextPattern(FloatToStrF(composite_beam_calculator_.get_max_stud_ratio_coordinate(),ffFixed, 15, 2),"%cs_stud%");
  report_.PasteTextPattern(FloatToStrF(composite_beam_calculator_.get_max_S_h(LoadUnit::kN),ffFixed, 15, 2),"%S_h%");

 //  [3.3] Коэффициенты использования
	report_.PasteTextPattern(FloatToStrF(composite_beam_calculator_.get_max_stud_ratio(),ffFixed, 15, 2),"%ratio_stud%");
}

//---------------------------------------------------------------------------
// Отрисовка эпюр
//---------------------------------------------------------------------------
void TCompositeBeamMainForm::draw_diagram()
{
	std::vector<double> M;
	std::vector<double> Q;
	std::vector<double> R;
	std::vector<double> f;

	std::vector<double>	coor_supp {};

	switch (cmb_bx_impact->ItemIndex)
	{
	case(0): // Расчётные нагрузки Ia стадии

		M = composite_beam_calculator_.get_sections_beam().get_M_Ia_design_list(LoadUnit::kN, LengthUnit::m);
		Q = composite_beam_calculator_.get_sections_beam().get_Q_Ia_design_list(LoadUnit::kN);
		R = composite_beam_calculator_.get_sections_beam().get_R_Ia_design_list(LoadUnit::kN);
		f = composite_beam_calculator_.get_sections_beam().get_f_Ia_design_list(LengthUnit::mm);

		coor_supp = composite_beam_calculator_.get_sections_beam().get_support_x_list();

		break;
	case(1): // Расчётные нагрузки Ib стадии

		M = composite_beam_calculator_.get_sections_beam().get_M_Ib_design_list(LoadUnit::kN, LengthUnit::m);
		Q = composite_beam_calculator_.get_sections_beam().get_Q_Ib_design_list(LoadUnit::kN);
		R = composite_beam_calculator_.get_sections_beam().get_R_Ib_design_list(LoadUnit::kN);
		f = composite_beam_calculator_.get_sections_beam().get_f_Ib_design_list(LengthUnit::mm);

		coor_supp = composite_beam_calculator_.get_sections_beam().get_support_x_list();

		break;
	case(2): // Расчётные нагрузки IIa стадии

		M = composite_beam_calculator_.get_sections_beam().get_M_IIa_design_list(LoadUnit::kN, LengthUnit::m);
		Q = composite_beam_calculator_.get_sections_beam().get_Q_IIa_design_list(LoadUnit::kN);
		R = composite_beam_calculator_.get_sections_beam().get_R_IIa_design_list(LoadUnit::kN);
		f = composite_beam_calculator_.get_sections_beam().get_f_IIa_design_list(LengthUnit::mm);

		coor_supp.push_back(composite_beam_calculator_.get_sections_beam().get_support_x_list().front());
		coor_supp.push_back(composite_beam_calculator_.get_sections_beam().get_support_x_list().back());

		break;

	case(3): // Расчётные нагрузки IIb стадии

		M = composite_beam_calculator_.get_sections_beam().get_M_IIb_design_list(LoadUnit::kN, LengthUnit::m);
		Q = composite_beam_calculator_.get_sections_beam().get_Q_IIb_design_list(LoadUnit::kN);
		R = composite_beam_calculator_.get_sections_beam().get_R_IIb_design_list(LoadUnit::kN);
		f = composite_beam_calculator_.get_sections_beam().get_f_IIb_design_list(LengthUnit::mm);

		coor_supp.push_back(composite_beam_calculator_.get_sections_beam().get_support_x_list().front());
		coor_supp.push_back(composite_beam_calculator_.get_sections_beam().get_support_x_list().back());

		break;

	case(4)://Расчётные нагрузки полные

		M = composite_beam_calculator_.get_sections_beam().get_M_total_design_list(LoadUnit::kN, LengthUnit::m);
		Q = composite_beam_calculator_.get_sections_beam().get_Q_total_design_list(LoadUnit::kN);
		R = composite_beam_calculator_.get_sections_beam().get_R_total_design_list(LoadUnit::kN);
		f = composite_beam_calculator_.get_sections_beam().get_f_total_design_list(LengthUnit::mm);

		coor_supp.push_back(composite_beam_calculator_.get_sections_beam().get_support_x_list().front());
		coor_supp.push_back(composite_beam_calculator_.get_sections_beam().get_support_x_list().back());

		break;
	}

	TImage *Image1=img_static_scheme;
	std::vector<double> coor_epur = composite_beam_calculator_.get_sections_beam().get_x_list();

//	//флаг отрисовки значений на эпюре
	bool flag_sign=true;

	switch (rd_grp_internal_forces_type->ItemIndex)
	{
	case(0):

		std::transform(M.begin(),M.end(), M.begin(), [](double M) { return -1*std::round(M*1000)/1000;});
		DrawEpur(Image1, M.size(), &coor_epur[0], &M[0], nullptr, coor_supp.size(), &coor_supp[0], flag_sign);

		break;

	case(1):

		std::transform(Q.begin(),Q.end(), Q.begin(), [](double Q) { return -1*std::round(Q*1000)/1000;});
		std::transform(R.begin(),R.end(), R.begin(), [](double R) { return -1*std::round(R*1000)/1000;});
		DrawEpur(Image1, Q.size(), &coor_epur[0], &Q[0], &R[0], coor_supp.size(), &coor_supp[0], flag_sign);

		break;

	case(2):

		std::transform(f.begin(),f.end(), f.begin(), [](double f) { return std::round(f*1000000)/1000000;});
		DrawEpur(Image1, f.size(), &coor_epur[0], &f[0], nullptr, coor_supp.size(), &coor_supp[0], flag_sign);

		break;
	}
}

void __fastcall TCompositeBeamMainForm::cmb_bx_impactChange(TObject *Sender)
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
   update_composite_beam();
   composite_beam_calculator_.calculate();
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

void __fastcall TCompositeBeamMainForm::NSaveClick(TObject *Sender)
{
	update_composite_beam(); //актуализируем композитную балку из полей формы
   // Получение имени директории, в которой находится исполняемый модуль

   if  (strcmp(ModelFile, UNTITLED)==0) {
	  if(SaveDialog_Model->Execute())
	  {
		  FileDir_Name = SaveDialog_Model->FileName;;//поле класс хранит путь полный
		  ModelName(FileDir_Name.c_str(), ModelFile); //выделяет имя файла для отображения на форме из пути
	  }
   }

	std::ofstream ofstr {FileDir_Name.c_str(), std::ios::out | std::ios::binary};
	composite_beam_calculator_.save(ofstr);
	ofstr.close();

   Caption = "Расчет комбинированной балки - " + AnsiString(ModelFile);

   modify_project = false;
}

void __fastcall TCompositeBeamMainForm::NSaveAsClick(TObject *Sender)
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

void __fastcall TCompositeBeamMainForm::NOpenClick(TObject *Sender)
{

   NNewClick(Sender);

   if(OpenDialog_Model->Execute())
   {
	  FileDir_Name = OpenDialog_Model->FileName;
   }
   if (FileDir_Name!="") {

	  strcpy(ModelFile, UNTITLED);

	  std::ifstream ifstr {FileDir_Name.c_str(), std::ios::in | std::ios::binary};

	  composite_beam_calculator_.load(ifstr);

	  ifstr.close();

	  set_form_controls();

	  ModelName(FileDir_Name.c_str(), ModelFile);

	  Caption = "Расчет комбинированной балки - " + AnsiString(ModelFile);

	  modify_project = false;

   }

}
//---------------------------------------------------------------------------
void TCompositeBeamMainForm::clean_static_scheme()
{
	img_static_scheme -> Canvas -> Brush -> Color = clWhite;
	img_static_scheme -> Canvas->FillRect (img_static_scheme -> Canvas -> ClipRect);
}
void TCompositeBeamMainForm::clean_grid(TStringGrid* str_grd)
{
	for(int i =1; i < str_grd -> RowCount; ++i)
	   str_grd -> Cells [1][i] = "";
}
void __fastcall TCompositeBeamMainForm::OnControlsChange(TObject *Sender)
{
	if (btn_report->Enabled)
		btn_report->Enabled=false;
	if(tb_results->TabVisible)
		tb_results->TabVisible=false;
	clean_static_scheme();
	clean_grid(strng_grd_compos_sect_geom_character);
	clean_grid(strng_grd_concrete_sect_geom_character);
	clean_grid(strng_grd_steel_sect_geom_character);
	clean_grid(strng_grd_results);

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

void __fastcall TCompositeBeamMainForm::cmb_bx_analysis_theoryChange(TObject *Sender)

{
    OnControlsChange(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TCompositeBeamMainForm::cmb_bx_corrugated_sheeting_part_numberChange(TObject *Sender)
{
	OnControlsChange(Sender);
}

//---------------------------------------------------------------------------
void TCompositeBeamMainForm::update(IPublisher* ipublisher )
{
	switch(ipublisher -> get_id())
	{
		case(Publisher_ID::REBARS_FORM):
			pnl_rebar_viewer -> Caption = ipublisher -> get_information();
			OnControlsChange(nullptr);
			break;
		case(Publisher_ID::STUDS_FORM):
			pnl_shear_stud_viewer -> Caption = ipublisher -> get_information();
			OnControlsChange(nullptr);
			break;
		case(Publisher_ID::CONCRETE_FORM):
			pnl_concrete_grade -> Caption = ipublisher -> get_information();
			OnControlsChange(nullptr);
			break;
		case(Publisher_ID::STEEL_FORM):
			pnl_steel -> Caption = ipublisher -> get_information();
			OnControlsChange(nullptr);
			break;
		case(Publisher_ID::SECTION_FORM):
			Pnl_SteelSectionViewer -> Caption = ipublisher -> get_information();
			OnControlsChange(nullptr);
			break;
	}

}

//---------------------------------------------------------------------------

void __fastcall TCompositeBeamMainForm::btn_loggerClick(TObject *Sender)
{
	FormLogger->Show();
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------



void __fastcall TCompositeBeamMainForm::N8Click(TObject *Sender)
{
	AboutProgForm->ShowModal();
}
//---------------------------------------------------------------------------



