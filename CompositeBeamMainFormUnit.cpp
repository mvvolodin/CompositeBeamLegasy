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
#include "SteelSectionFormUnit.h"
#include "Report.h" //Подключаем генератор отчётов
#include "Word_Automation.h"  // Вывод отчета в Word
#include "AboutProg.h"

TCompositeBeamMainForm *CompositeBeamMainForm;

//----------------------------------------------------------------------
 _fastcall TCompositeBeamMainForm::TCompositeBeamMainForm(TComponent* Owner)
	: TForm(Owner)
{
	composite_beam_.set_default_values();

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

	SteelSectionForm->SteelSectionDefinitionFrame->RadioGroupGOST57837->ItemIndex=0;
	SteelSectionForm->SteelSectionDefinitionFrame->RadioGroupGOST57837Click(Sender);
	Pnl_SteelSectionViewer->Caption = SteelSectionForm->SteelSectionDefinitionFrame
	->ComboBox_profil->Text;
	DefineSteelForm->cmb_bx_steel_gradesChange(Sender);
	pnl_steel->Caption = DefineSteelForm -> cmb_bx_steel_grades->Text;
	rdgrp_slab_typeClick(Sender);

	calculate_composite_beam();

}
//----------------------------------------------------------------------
////Присваивение значений полям формы из данных класс типа TCompositeBeam
//----------------------------------------------------------------------
void TCompositeBeamMainForm::set_form_controls()
{
 // Данные типа TGeometry
	TGeometry geom = composite_beam_.get_geometry();
	edt_beam_division -> Text = geom.get_beam_division();
	edt_span -> Text = geom.get_span();
	edt_width_left -> Text = geom.get_trib_width_left();
	edt_width_right -> Text = geom.get_trib_width_right();
	cmb_bx_number_propping_supports -> Text = geom.get_temporary_supports_number();
//Данные типа Loads
	TLoads loads = composite_beam_.get_loads();
	edt_dead_load_first_stage -> Text = loads.get_dead_load_first_stage(LoadUnit::kN, LengthUnit::m);
	edt_dead_load_second_stage -> Text = loads.get_dead_load_second_stage(LoadUnit::kN, LengthUnit::m);
	edt_live_load -> Text = loads.get_live_load(LoadUnit::kN, LengthUnit::m);
	edt_gamma_f_st_SW_-> Text = loads.get_gamma_f_st_SW();
	edt_gamma_f_DL_I -> Text = loads.get_gamma_f_DL_I();
	edt_gamma_f_DL_II -> Text = loads.get_gamma_f_DL_II();
	edt_gamma_f_LL -> Text = loads.get_gamma_f_LL();

//Данные типа WorkingConditionsFactors
	WorkingConditionsFactors wcf = composite_beam_.get_working_conditions_factors();
	edt_gamma_bi -> Text = wcf.get_gamma_bi();
	edt_gamma_si -> Text = wcf.get_gamma_si();
	edt_gamma_c -> Text = wcf.get_gamma_c();

//Панели для отображения данных
	pnl_shear_stud_viewer -> Caption = StudDefinitionForm -> get_studs().get_name();
	pnl_rebar_viewer -> Caption = RebarDefinitionForm -> get_rebar().get_grade();
	pnl_concrete_grade -> Caption = ConcreteDefinitionForm -> get_concrete().get_grade();

//Данные для плиты

	switch (composite_beam_.get_composite_section().get_concrete_part().get_slab_type_enum())
	{
	case SlabType::FLAT:
		rdgrp_slab_type -> ItemIndex = 0;
		edt_flat_slab_thickness -> Text = composite_beam_.get_composite_section().get_concrete_part().get_h_f();
		break;
	case SlabType::CORRUGATED:
		rdgrp_slab_type -> ItemIndex = 1;
		cmb_bx_corrugated_sheeting_part_number -> Text = composite_beam_.get_composite_section().get_concrete_part().get_slab_type();
		edt_h_f -> Text = composite_beam_.get_composite_section().get_concrete_part().get_h_f();
		break;
	}

//Данные типа Studs
	StudDefinitionForm -> set_form_controls(composite_beam_.get_studs());

//Данные типа Rebar
	RebarDefinitionForm -> set_form_controls(composite_beam_.get_composite_section().get_concrete_part().get_rebar());

//Данные типа Concrete
	ConcreteDefinitionForm -> set_form_controls(composite_beam_.get_composite_section().get_concrete_part().get_concrete());
	Concrete con = composite_beam_.get_composite_section().get_concrete_part().get_concrete();

//Данные типа Steel
	DefineSteelForm -> set_form_controls(composite_beam_.get_composite_section().get_steel_part().get_I_steel());



}
void TCompositeBeamMainForm::register_observers()
{
	std::vector<IPublisher*> ipublishers;
	ipublishers.push_back(RebarDefinitionForm);
	ipublishers.push_back(StudDefinitionForm);
	ipublishers.push_back(ConcreteDefinitionForm);
	ipublishers.push_back(DefineSteelForm);
	ipublishers.push_back(SteelSectionForm);
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

	double SW = SteelSectionForm->SteelSectionDefinitionFrame->common_sect_.dvutavr.weight * GRAV_ACCELERAT;

	double DL_I = 0.;
	double DL_II = 0.;
	double LL = 0.;
	double gamma_f_st_SW = 0.;
	double gamma_f_DL_I = 0.;
	double gamma_f_DL_II= 0.;
	double gamma_f_LL = 0.;

	String_double_plus(lbl_dead_load_first_stage->Caption, edt_dead_load_first_stage->Text, &DL_I);
	String_double_plus(lbl_dead_load_second_stage->Caption, edt_dead_load_second_stage->Text, &DL_II);
	String_double_plus(lbl_live_load->Caption, edt_live_load->Text, &LL);
	String_double_plus(lbl_gamma_f_st_SW->Caption, edt_gamma_f_st_SW_->Text, &gamma_f_st_SW);
	String_double_plus(lbl_gamma_f_DL_I->Caption, edt_gamma_f_DL_I->Text, &gamma_f_DL_I);
	String_double_plus(lbl_gamma_f_DL_II->Caption, edt_gamma_f_DL_II->Text, &gamma_f_DL_II);
	String_double_plus(lbl_gamma_f_LL->Caption, edt_gamma_f_LL->Text, &gamma_f_LL);

	return TLoads (SW, SW_sheets, DL_I, DL_II, LL, gamma_f_st_SW, gamma_f_DL_I, gamma_f_DL_II, gamma_f_LL);
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
	return DefineSteelForm -> get_steel();
}
//---------------------------------------------------------------------------
//Инициализация железобетонной части сечения
//---------------------------------------------------------------------------
TConcretePart TCompositeBeamMainForm::init_concrete_part()
{
	TGeometry geometry = init_geomet();
	TISectionInitialData init_i_section = &(SteelSectionForm->SteelSectionDefinitionFrame->common_sect_.dvutavr);
	double b_uf = init_i_section.b_uf_;

	if (rdgrp_slab_type->ItemIndex==0)
	{
		double t_sl= 0.;
		String_double_plus(lbl_flat_slab_thickness->Caption, edt_flat_slab_thickness->Text, &t_sl);
		return TConcretePart (L"Плоская плита",
							  SlabType::FLAT,
							  ConcreteDefinitionForm->get_concrete(),
							  RebarDefinitionForm->get_rebar(),
							  t_sl);
	}
	else
	{
	double h_f= 0.;

	String_double_plus(lbl_h_f->Caption, edt_h_f->Text, &h_f);

	return TConcretePart (cmb_bx_corrugated_sheeting_part_number->Text,
						  SlabType::CORRUGATED,
						  ConcreteDefinitionForm->get_concrete(),
						  RebarDefinitionForm->get_rebar(),
						  h_f);
	}
}
//---------------------------------------------------------------------------
//Инициализация стальной части сечения
//---------------------------------------------------------------------------
SteelPart TCompositeBeamMainForm::init_steel_part()
{

   TISectionInitialData i_section_initial_data=init_i_section();
   Steel steel_i_section=init_steel_i_section();

	return SteelPart(ISection(i_section_initial_data), steel_i_section);
}
//---------------------------------------------------------------------------
//	Инициализация упоров
//---------------------------------------------------------------------------
Studs TCompositeBeamMainForm::init_stud()
{
	return StudDefinitionForm -> get_studs();
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
void TCompositeBeamMainForm::init_composite_beam(TGeometry 				  geometry,
												 TLoads 				  loads,
												 CompositeSection 		  composite_section,
												 Studs 					  stud,
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
				Image2->Visible=false;
				Image1->Visible=true;
				break;

	   case 1:	grp_bx_corrugated_slab->Visible=true;
				grp_bx_flat_slab->Visible=false;
				Image2->Visible=true;
				Image1->Visible=false;
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
	ISection i_section= composite_beam_.get_composite_section().get_steel_part().get_I_section();

	strng_grd_steel_sect_geom_character->Cells [1][1]=FloatToStrF(i_section.get_A_st(), ffFixed, 15, 0);
	strng_grd_steel_sect_geom_character->Cells [1][2]=FloatToStrF(i_section.get_I_st(), ffFixed, 15, 0);
	strng_grd_steel_sect_geom_character->Cells [1][3]=FloatToStrF(i_section.get_Wf2_st(), ffFixed, 15, 0);
	strng_grd_steel_sect_geom_character->Cells [1][4]=FloatToStrF(i_section.get_Wf1_st(), ffFixed, 15, 0);
	strng_grd_steel_sect_geom_character->Cells [1][5]=FloatToStrF(i_section.get_Z_f2_st(), ffFixed, 15, 0);
	strng_grd_steel_sect_geom_character->Cells [1][6]=FloatToStrF(i_section.get_Z_f1_st(), ffFixed, 15, 0);
}
void TCompositeBeamMainForm::fill_concrete_sect_geometr_grid()
{
	TConcretePart concrete_part=composite_beam_.get_composite_section().get_concrete_part();

	strng_grd_concrete_sect_geom_character->Cells [1][1]=FloatToStrF(concrete_part.get_b_l(), ffFixed, 15, 0);
	strng_grd_concrete_sect_geom_character->Cells [1][2]=FloatToStrF(concrete_part.get_b_r(), ffFixed, 15, 0);
	strng_grd_concrete_sect_geom_character->Cells [1][3]=FloatToStrF(concrete_part.get_C_b(), ffFixed, 15, 0);
	strng_grd_concrete_sect_geom_character->Cells [1][4]=FloatToStrF(concrete_part.get_A_b(), ffFixed, 15, 0);
	strng_grd_concrete_sect_geom_character->Cells [1][5]=FloatToStrF(concrete_part.get_I_b(), ffFixed, 15, 0);
}
void TCompositeBeamMainForm::fill_composite_sect_geometr_grid()
{
	double A_red=composite_beam_.get_composite_section().get_A_red();
	double I_red=composite_beam_.get_composite_section().get_I_red();
	double W_b_red=composite_beam_.get_composite_section().get_W_b_red();
	double W_f2_red=composite_beam_.get_composite_section().get_W_f2_red();
	double W_f1_red=composite_beam_.get_composite_section().get_W_f1_red();
	double Z_b_red=composite_beam_.get_composite_section().get_Z_b_red();
	double Z_f2_red=composite_beam_.get_composite_section().get_Z_f2_red();
	double Z_f1_red=composite_beam_.get_composite_section().get_Z_f1_red();

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
	double max_upper_flange_ratio = composite_beam_.get_max_upper_flange_ratio();
	double max_lower_flange_ratio = composite_beam_.get_max_lower_flange_ratio();
	double ratio_rigid_plastic = composite_beam_.get_ratio_rigid_plastic();
	double max_ratio_studs = composite_beam_.get_max_stud_ratio();
	double max_shear_ratio = composite_beam_.get_max_shear_ratio();
	
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
	cmb_bx_impact->Items->Insert(static_cast<int>(Impact::SW_BEAM), "Собственный вес балки");
	cmb_bx_impact->Items->Insert(static_cast<int>(Impact::SW_SHEETS), "Собственный вес настила");
	cmb_bx_impact->Items->Insert(static_cast<int>(Impact::DL_I) , "Постоянная нагрузка I стадия");
	cmb_bx_impact->Items->Insert(static_cast<int>(Impact::DL_II), "Постоянная нагрузка II стадия");
	cmb_bx_impact->Items->Insert(static_cast<int>(Impact::LL), "Временная нагрузка II стадии");
	cmb_bx_impact->Items->Insert(static_cast<int>(Impact::I_stage), "Расчётные нагрузки I стадии");
	cmb_bx_impact->Items->Insert(static_cast<int>(Impact::II_stage), "Расчётные нагрузки II стадии");
	cmb_bx_impact->Items->Insert(static_cast<int>(Impact::Total), "Расчётные нагрузки");
	cmb_bx_impact->ItemIndex = (int)Impact::SW_BEAM;
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
	TWord_Automation report_=TWord_Automation("ReportCompositeBeam.docx");
	TGeometry geometry=composite_beam_.get_geometry();
	TLoads loads=composite_beam_.get_loads();
	CompositeSection composite_section=composite_beam_.get_composite_section();
	ISection i_section= composite_beam_.get_composite_section().get_steel_part().get_I_section();
	TConcretePart concrete_part=composite_beam_.get_composite_section().get_concrete_part();
	Concrete concrete=concrete_part.get_concrete();
	Rebar rebar=concrete_part.get_rebar();
	Steel steel=composite_beam_.get_composite_section().get_steel_grade();
	Studs studs=composite_beam_.get_studs();
	WorkingConditionsFactors working_conditions_factors=composite_beam_.get_working_conditions_factors();

//[1.1] Топология
	report_.PasteTextPattern(geometry.is_end_beam_to_str(), "%end_beam%");
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
//[1.4] Стальное сечение
//[1.4.1] Номинальные размеры двутавра
	report_.PasteTextPattern(i_section.get_profile_number(),"%profile_number%");
	report_.PasteTextPattern(i_section.get_h_st(LengthUnit::mm),"%h%");
	report_.PasteTextPattern(0,"%h%");
	report_.PasteTextPattern(i_section.get_b_uf(LengthUnit::mm),"%b%");
	report_.PasteTextPattern(0,"%b_w%");
	report_.PasteTextPattern(i_section.get_t_uf(LengthUnit::mm),"%t%");
	report_.PasteTextPattern(i_section.get_t_w(LengthUnit::mm),"%s%");
	report_.PasteTextPattern(i_section.get_r(LengthUnit::mm),"%r%");
//[1.4.2] Характеристики стали
	report_.PasteTextPattern(steel.get_steel_grade(),"%steel_grade%");
	report_.PasteTextPattern(steel.get_R_yn(),"%R_yn%");
	report_.PasteTextPattern(steel.get_R_un(),"%R_un%");
	report_.PasteTextPattern(steel.get_E_st(),"%E_st%");
	report_.PasteTextPattern(steel.get_G_st(),"%G_st%");
	report_.PasteTextPattern(steel.get_nu_st(),"%nu_st%");
	report_.PasteTextPattern(steel.get_gamma_m(),"%gamma_m%");
//[1.5] Железобетонное сечение
//[1.5.1] Номинальные размеры плиты
	report_.PasteTextPattern(concrete_part.get_slab_type(),"%slab_type%");
	report_.PasteTextPattern(concrete_part.get_h_b(),"%t_sl%");

//[1.5.2] Характеристики бетона

	report_.PasteTextPattern(concrete.get_grade(),"%conc_grade%");
	report_.PasteTextPattern(concrete.get_R_bn(),"%R_bn%");
	report_.PasteTextPattern(concrete.get_R_btn(),"%R_btn%");
	report_.PasteTextPattern(concrete.get_E_b(),"%E_b%");
	report_.PasteTextPattern(concrete.get_gamma_b(),"%gamma_b%");
	report_.PasteTextPattern(concrete.get_gamma_bt(),"%gamma_bt%");


//[1.6] Арматура
	report_.PasteTextPattern(rebar.get_grade(),"%grade%");
	report_.PasteTextPattern(rebar.get_diameter(),"%d%");
	report_.PasteTextPattern(rebar.get_R_sn(),"%R_sn%");
//[1.7] Соединительные элементы
	report_.PasteTextPattern(studs.get_name(),"%name%");
	report_.PasteTextPattern(studs.get_l(LengthUnit::cm),"%l%");
	report_.PasteTextPattern(studs.get_d_an(LengthUnit::cm),"%d_an%");
	report_.PasteTextPattern(studs.get_R_y(),"%R_y%");
	report_.PasteTextPattern(studs.get_edge_rows_dist(LengthUnit::cm),"%z_e%");
	report_.PasteTextPattern(studs.get_middle_rows_dist(LengthUnit::cm),"%z_m%");
	report_.PasteTextPattern(studs.get_edge_rows_num(),"%ed_rw_num%");
	report_.PasteTextPattern(studs.get_middle_rows_num(),"%mid_rw_num%");
//[1.8] Коэффициенты
	report_.PasteTextPattern(working_conditions_factors.get_gamma_c(),"%gamma_c%");
	report_.PasteTextPattern(working_conditions_factors.get_gamma_bi(),"%gamma_bi%");
	report_.PasteTextPattern(working_conditions_factors.get_gamma_si(),"%gamma_si%");
//[1.9] Прочее
	report_.PasteTextPattern(geometry.get_temporary_supports_number(),"%temp_supp%");


//[2] Результаты расчёта
//[2.1] Расчётное сечение


//[2.2] Геометрические параметры
//[2.2.1] Стального сечения
	report_.PasteTextPattern(i_section.get_A_st(LengthUnit::cm),"%A_st%");
	report_.PasteTextPattern(i_section.get_I_st(LengthUnit::cm),"%I_st%");
	report_.PasteTextPattern(i_section.get_Wf2_st(LengthUnit::cm),"%Wf2_st%");
	report_.PasteTextPattern(i_section.get_Wf1_st(LengthUnit::cm),"%Wf1_st%");
	report_.PasteTextPattern(i_section.get_Z_f2_st(LengthUnit::cm),"%Z_f2_st%");
	report_.PasteTextPattern(i_section.get_Z_f1_st(LengthUnit::cm),"%Z_f1_st%");
//[2.2.2] Железобетонного сечения
	report_.PasteTextPattern(concrete_part.get_slab_type(),"%slab_type%");
	report_.PasteTextPattern(concrete_part.get_b_l(LengthUnit::cm),"%b_l%");
	report_.PasteTextPattern(concrete_part.get_b_r(LengthUnit::cm),"%b_r%");
	report_.PasteTextPattern(concrete_part.get_C_b(LengthUnit::cm),"%C_b%");
	report_.PasteTextPattern(concrete_part.get_A_b(LengthUnit::cm),"%A_b%");
	report_.PasteTextPattern(concrete_part.get_I_b(LengthUnit::cm),"%I_b%");
//[2.2.3] Композитного сечения
	report_.PasteTextPattern(std::round(composite_section.get_A_red(LengthUnit::cm)),"%A_red%");
	report_.PasteTextPattern(std::round(composite_section.get_I_red(LengthUnit::cm)),"%I_red%");
	report_.PasteTextPattern(std::round(composite_section.get_W_b_red(LengthUnit::cm)),"%W_b_red%");
	report_.PasteTextPattern(std::abs(std::round(composite_section.get_W_f2_red(LengthUnit::cm))),"%W_f2_red%");
	report_.PasteTextPattern(std::round(composite_section.get_W_f1_red(LengthUnit::cm)),"%W_f1_red%");
	report_.PasteTextPattern(std::round(composite_section.get_Z_b_red(LengthUnit::cm)),"%Z_b_red%");
	report_.PasteTextPattern(std::abs(std::round(composite_section.get_Z_f2_red(LengthUnit::cm))),"%Z_f2_red%");
	report_.PasteTextPattern(std::round(composite_section.get_Z_f1_red(LengthUnit::cm)),"%Z_f1_red%");


}

//---------------------------------------------------------------------------
// Отрисовка эпюр
//---------------------------------------------------------------------------
void TCompositeBeamMainForm::draw_diagram()
{
	TImage *Image1=img_static_scheme;
	//получаем вектор координат точек эпюры из объекта композитная балка
	std::vector<double> coor_epur=composite_beam_.get_CS_coordinates();

	InternalForces internal_forces = composite_beam_.get_internal_forces_LC()[static_cast<Impact>(cmb_bx_impact->ItemIndex)];
	//определим суммарное количество опор (временных и постоянных)
	int n_supp=composite_beam_.get_geometry().get_permanent_supports_number()+
	internal_forces.get_num_temp_supports();
	std::vector<double>	coor_supp = internal_forces.get_supports_coordinates();
	//флаг отрисовки значений на эпюре
	bool flag_sign=true;

	if (rd_grp_internal_forces_type->ItemIndex==0)
	{
		//получаем вектор изгибающих моментов из объекта композитная балка
		std::vector<double> M= internal_forces .get_M(LoadUnit::kN, LengthUnit::m);
		//преобразуем вектор для вывода. Измениим знак элементов на противоположный и округлим до третьего знака после запятой
		std::transform(M.begin(),M.end(), M.begin(), [](double M) { return -1*std::round(M*1000)/1000;});
		DrawEpur(Image1, M.size(), &coor_epur[0], &M[0], nullptr, n_supp, &coor_supp[0], flag_sign);
	}
	else
	{
		//получаем поперечные силы из объекта композитная балка
		std::vector<double> Q=internal_forces .get_Q(LoadUnit::kN);
		std::vector<double> Q_jump=internal_forces .get_Q_jump(LoadUnit::kN);
		//преобразуем вектор для вывода. Измениим знак элементов на противоположный и округлим до третьего знака после запятой
		std::transform(Q.begin(),Q.end(), Q.begin(), [](double Q) { return -1*std::round(Q*1000)/1000;});
		std::transform(Q_jump.begin(),Q_jump.end(), Q_jump.begin(), [](double Q_jump) { return -1*std::round(Q_jump*1000)/1000;});
		DrawEpur(Image1, Q.size(), &coor_epur[0], &Q[0], &Q_jump[0], n_supp, &coor_supp[0], flag_sign);
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
   //проверка объекта и в случае его наличия будет вызван деструктор
   //проверка в nullptr  в concrete_section_
   //установить все объекты в ноль

   TGeometry geometry=init_geomet();//поле содержащее топологию
   TLoads loads=init_loads();//поле содержащее нагрузки и коэффициенты надёжности по нагрузкам
   Studs stud=init_stud(); //поле соержащее упоры Нельсона
   WorkingConditionsFactors working_conditions_factors=init_working_conditions_factors();
   SteelPart steel_part = init_steel_part();
   TConcretePart concrete_part=init_concrete_part();//объект абстрактного класса, поэтому указатель!
   CompositeSection composite_section = CompositeSection(steel_part, concrete_part, geometry);
   init_composite_beam(geometry,loads,composite_section, stud,working_conditions_factors);
   composite_beam_.calculate();
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
   // Получение имени директории, в которой находится исполняемый модуль

   if  (strcmp(ModelFile, UNTITLED)==0) {
	  if(SaveDialog_Model->Execute())
	  {
		  FileDir_Name = SaveDialog_Model->FileName;;//поле класс хранит путь полный
		  ModelName(FileDir_Name.c_str(), ModelFile); //выделяет имя файла для отображения на форме из пути
	  }
   }

	std::ofstream ofstr {FileDir_Name.c_str(), std::ios::out | std::ios::binary};
	composite_beam_.save(ofstr);
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

	  std::ifstream ifstr {FileDir_Name.c_str(), std::ios::in | std::ios::binary};

	  composite_beam_.load(ifstr);

	  ifstr.close();

	  set_form_controls();

	  ModelName(FileDir_Name.c_str(), ModelFile);

	  Caption = "Расчет комбинированной балки - " + AnsiString(ModelFile);

	  modify_project = false;

   }

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
			break;
		case(Publisher_ID::STUDS_FORM):
			pnl_shear_stud_viewer -> Caption = ipublisher -> get_information();
			break;
		case(Publisher_ID::CONCRETE_FORM):
			pnl_concrete_grade -> Caption = ipublisher -> get_information();
			break;
		case(Publisher_ID::STEEL_FORM):
			pnl_steel -> Caption = ipublisher -> get_information();
			break;
		case(Publisher_ID::SECTION_FORM):
			pnl_steel -> Caption = ipublisher -> get_information();
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



//---------------------------------------------------------------------------




