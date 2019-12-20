//---------------------------------------------------------------------------

#include <vcl.h>
#include<ComObj.hpp>
#pragma hdrstop

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

#include "CompositeBeamMainFormUnit.h"
#include "String_doubleUnit.h"  //Функции проверяющие правильность ввода данных в поля формы

#include "Report.h" //Подключаем генератор отчётов

#include "Word_Automation.h"  // Вывод отчета в Word

TCompositeBeamMainForm *CompositeBeamMainForm;

extern COMMON_SECT *common_sect;
extern MATER_PARAM mater_param; //в модуле поставщике почему-то не используется указатель
extern STEEL_PARAM steel_param; //в модуле поставщике почему-то не используется указатель

//----------------------------------------------------------------------
 _fastcall TCompositeBeamMainForm::TCompositeBeamMainForm(TComponent* Owner)
	: TForm(Owner)
{
//:composite_section_(nullptr)
	grid_constructor_ratios();
	grid_constr_comp_sect_geometr();
	fill_cmb_bx_LC();
}
//----------------------------------------------------------------------
void __fastcall TCompositeBeamMainForm::FormShow(TObject *Sender)
{
	SteelSectionForm->SteelSectionDefinitionFrame->RadioGroupGOST57837->ItemIndex=0;
	SteelSectionForm->SteelSectionDefinitionFrame->RadioGroupGOST57837Click(Sender);
	Pnl_SteelSectionViewer->Caption = SteelSectionForm->SteelSectionDefinitionFrame
	->ComboBox_profil->Text;
	SteelDefinitionForm->ComboBox_steelChange(Sender);
	PnlSteelViewer->Caption=SteelDefinitionForm->ComboBox_steel->Text;
	pnl_concrete_grade->Caption=ConcreteDefinitionForm->cmb_bx_concrete_grade_list->Text;
	rdgrp_slab_typeClick(Sender);
	PnlShearStudsViewer->Caption=StudDefinitionForm->cmb_bx_stud_part_number->Text;
}
//---------------------------------------------------------------------------
//Инициализация топологии
//---------------------------------------------------------------------------
void TCompositeBeamMainForm::init_geomet()
{
	double beam_division=0.0;//поменять тип на double и написать функцию проверки значения поля на тип int
	double span=0.0;
	double trib_width_left=0.0;
	double trib_width_right=0.0;
	int rc=0; //rc- return code -код ошибки
	rc=(int)String_double_plus(lbl_beam_division->Caption, edt_beam_division->Text, &beam_division);
	if (rc>0) return;
	rc=String_double_plus(lbl_span->Caption, edt_span->Text, &span);
	if (rc>0) return;
	rc=String_double_plus(lbl_trib_width_left->Caption, edt_width_left->Text, &trib_width_left);
	if (rc>0) return;
	rc=String_double_plus(lbl_trib_width_right->Caption, edt_width_right->Text, &trib_width_right);
	if (rc>0) return;//какое значение возвращает return без следующего за ним значения
	geometry_=TGeometry(static_cast<int>(beam_division), chck_bx_end_beam->Checked, span, trib_width_left, trib_width_right,
		StrToFloat(cmb_bx_number_propping_supports->Text));
}
//---------------------------------------------------------------------------
//Инициализация нагрузок и коэффициентов надёжности по нагрузкам
//---------------------------------------------------------------------------
void TCompositeBeamMainForm::init_loads()
{
	int rc=0; //rc- return code -код ошибки
	double SW=1.0;//необходимо получать по типу профиля
	double DL_I=0.0;
	double DL_II=0.0;
	double LL=0.0;
	double gamma_f_SW=1.0;//необходимо предусмотреть поле для ввода
	double gamma_f_DL_I=0.0;
	double gamma_f_DL_II=0.0;
	double gamma_f_LL=0.0;

	rc=String_double_plus(lbl_dead_load_first_stage->Caption, edt_dead_load_first_stage->Text, &DL_I);
	if (rc>0) return;
	rc=String_double_plus(lbl_dead_load_second_stage->Caption, edt_dead_load_second_stage->Text, &DL_II);
	if (rc>0) return;
	rc=String_double_plus(lbl_live_load->Caption, edt_live_load->Text, &LL);
	if (rc>0) return;
	rc=String_double_plus(lbl_gamma_f_DL_I->Caption, edt_gamma_f_DL_I->Text, &gamma_f_DL_I);
	if (rc>0) return;
	rc=String_double_plus(lbl_gamma_f_DL_II->Caption, edt_gamma_f_DL_II->Text, &gamma_f_DL_II);
	if (rc>0) return;
	rc=String_double_plus(lbl_gamma_f_LL->Caption, edt_gamma_f_LL->Text, &gamma_f_LL);
	if (rc>0) return;

	loads_ = TLoads (SW, DL_I, DL_II, LL, gamma_f_SW, gamma_f_DL_I, gamma_f_DL_II, gamma_f_LL);
}
//---------------------------------------------------------------------------
//Инициализация геометрии двутавра
//---------------------------------------------------------------------------
void TCompositeBeamMainForm::init_i_section()
{
	  i_section_initial_data_= TISectionInitialData (&(common_sect->dvutavr));
}
//---------------------------------------------------------------------------
//	Инициализация материала двутавра
//---------------------------------------------------------------------------
void TCompositeBeamMainForm::init_steel_i_section()
{
   steel_i_section_initial_data_= TSteelInitialData(SteelDefinitionForm->MaterProp.Ry,
													  SteelDefinitionForm->MaterProp.Ru,
													  SteelDefinitionForm->MaterProp.E,
													  SteelDefinitionForm->MaterProp.G,
													  SteelDefinitionForm->MaterProp.nu,
													  SteelDefinitionForm->MaterProp.gamma_m);
}
//---------------------------------------------------------------------------
//Инициализация железобетонной части сечения
//---------------------------------------------------------------------------
void TCompositeBeamMainForm::init_concrete_part()
{
	if (rdgrp_slab_type->ItemIndex==0)
	{
		int rc=0; //rc- return code -код ошибки
		double t_sl=0.0;
		rc=String_double_plus(lbl_flat_slab_thickness->Caption, edt_flat_slab_thickness->Text, &t_sl);
		concrete_part_=new TFlatSlab(ConcreteDefinitionForm->get_concrete(),
									RebarDefinitionForm->get_rebar(),
									t_sl);
	}
	else
	{
	   concrete_part_=new TCorrugatedSlab(ConcreteDefinitionForm->get_concrete(),
	   									 RebarDefinitionForm->get_rebar());
	}
}
//---------------------------------------------------------------------------
//	Инициализация упоров
//---------------------------------------------------------------------------
void TCompositeBeamMainForm::init_stud()
{
	 stud_=StudDefinitionForm->get_stud();
}
//---------------------------------------------------------------------------
//	Инициализация коэффициентов условий работы
//---------------------------------------------------------------------------
 void TCompositeBeamMainForm::init_working_conditions_factors()
 {
	double gamma_bi=0.0;
	double gamma_si=0.0;
	double gamma_c=0.0;
    int rc=0; //rc- return code -код ошибки
		rc=String_double_plus(lbl_gamma_bi->Caption, edt_gamma_bi->Text, &gamma_bi);
	if (rc>0) return;
		rc=String_double_plus(lbl_gamma_si->Caption, edt_gamma_si->Text, &gamma_si);
	if (rc>0) return;
		rc=String_double_plus(lbl_gamma_c->Caption, edt_gamma_c->Text, &gamma_c);
	if (rc>0) return;
	working_conditions_factors_=WorkingConditionsFactors(gamma_bi,gamma_si,gamma_c);
 }
// ---------------------------------------------------------------------------
// Инициализация композитного сечения
//---------------------------------------------------------------------------
void TCompositeBeamMainForm::init_composite_section()
{
	composite_section_=CompositeSection(geometry_,
									   steel_i_section_initial_data_,
									   i_section_initial_data_,
									   concrete_part_);
}


// ---------------------------------------------------------------------------
// Инициализация композитной балки
//---------------------------------------------------------------------------
void TCompositeBeamMainForm::init_composite_beam()
{
composite_beam_=TCompositeBeam(geometry_,
							 loads_,
							 composite_section_,
							 stud_,
							 working_conditions_factors_);
							// (int)beam_division);
}
//---------------------------------------------------------------------------
//	Функция запускающая расчёт композитной балки
//---------------------------------------------------------------------------
void __fastcall TCompositeBeamMainForm::BtnCalculateClick(TObject *Sender)
{
   //проверка объекта и в случае его наличия будет вызван деструктор
   //проверка в nullptr  в concrete_section_
   //установить все объекты в ноль

	init_geomet();//Инициализация топологии
	init_loads(); //Инициализация нагрузок
	init_i_section();//Инициализация объекта геометрия двутавра
	init_steel_i_section();//Инициализация стали двутавра
	init_concrete_part(); //Инициализация бетонной части
	init_stud();//Инициализация композитного сечения
	init_composite_section();
	init_working_conditions_factors();//Инициализация коэффиециентов условий работы
	init_composite_beam();//Инициализация композитной балки
	BtnReport->Enabled=True;
    fill_grid_with_results();
}
//---------------------------------------------------------------------------
//Открытие Блокнота с информацией о расчёте
//---------------------------------------------------------------------------

void __fastcall TCompositeBeamMainForm::BtnReportClick(TObject *Sender)
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
	case 0: grpBxCorrugatedSlab->Visible=false;
			grp_bx_flat_slab->Visible=true;
			break;

   case 1:	grpBxCorrugatedSlab->Visible=true;
			grp_bx_flat_slab->Visible=false;
			break;
}
}
//---------------------------------------------------------------------------
//Обработчик события обеспечивающий заполнение первой строки жирным шрифтом
//---------------------------------------------------------------------------
void __fastcall TCompositeBeamMainForm::strngGrdResultsDrawCell(TObject *Sender,
																int ACol, int ARow,
																 TRect &Rect, TGridDrawState State)
{
TStringGrid *p1 = (TStringGrid*)Sender;
	if (ACol == 0 && ARow == 0){
	p1->Canvas->Font->Style=TFontStyles() << fsBold;
	}
	else	if (ACol == 1 && ARow == 0){

                		p1->Canvas->Font->Style=TFontStyles() << fsBold;
					}

            	   p1->Canvas->Brush->Style = bsSolid;
            	   p1->Canvas->FillRect(Rect);
				   p1->Canvas->TextOut(Rect.Left, Rect.Top, p1->Cells[ACol][ARow]);
}

//---------------------------------------------------------------------------
//	Функция заполняющая Grid выводящий результаты расчёта геометрических характеристик композитного сечения
//---------------------------------------------------------------------------
void TCompositeBeamMainForm::grid_constr_comp_sect_geometr()
{
 strng_grd_compos_sect_geom_character->Cells [0][0]="Геометрические характеристики";
 strng_grd_compos_sect_geom_character->Cells [1][0]="Значения";
 strng_grd_compos_sect_geom_character->Cells [0][1]="Площадь Ared, [мм2]";
 strng_grd_compos_sect_geom_character->Cells [0][2]="Момент инерции Ired, [мм4]";
 strng_grd_compos_sect_geom_character->Cells [0][3]="Момент сопротивления, верхн. полка W_f2_red, [мм3]";
 strng_grd_compos_sect_geom_character->Cells [0][4]="Момент сопротивления, нижн. полка W_f1_red, [мм3]";
 //strng_grd_compos_sect_geom_character->Cells [0][5]="Расстояние Z_b_st, [мм]";
 //strng_grd_compos_sect_geom_character->Cells [0][6]="Расстояние Z_b_st, [мм]";
 //strng_grd_compos_sect_geom_character->Cells [0][6]="Собственный вес, [кг/м]";
}

void TCompositeBeamMainForm::fill_grid_with_results()
{  //Данные стального и бетонного сечений. Пока нет ясности надо ли эти данные выводить
  //double I_st=composite_beam.get_composite_section().get_steel_part().get_I_st();
  //double A_st= composite_beam.get_composite_section().get_steel_part().get_A_st();
  //double A_b=composite_beam.get_composite_section().get_concrete_part().get_A_b();
  //double I_b=composite_beam.get_composite_section().get_concrete_part().get_I_b();
	double A_red=composite_beam_.get_composite_section().get_A_red();
	double I_red=composite_beam_.get_composite_section().get_I_red();
	double W_f2_red=composite_beam_.get_composite_section().get_W_f2_red();
	double W_f1_red=composite_beam_.get_composite_section().get_W_f1_red();

	strng_grd_compos_sect_geom_character->Cells [1][1]=FloatToStrF(A_red, ffFixed, 15, 0); //Предельно значение точность для
	strng_grd_compos_sect_geom_character->Cells [1][2]=FloatToStrF(I_red, ffFixed, 15, 0); //типа double 15
	strng_grd_compos_sect_geom_character->Cells [1][3]=FloatToStrF(W_f2_red, ffFixed, 15, 0);
	strng_grd_compos_sect_geom_character->Cells [1][4]=FloatToStrF(W_f1_red, ffFixed, 15, 0);

}
//---------------------------------------------------------------------------
//	Функция заполняющая Grid выводящий результаты расчёта композитной балки
//---------------------------------------------------------------------------
void TCompositeBeamMainForm:: grid_constructor_ratios()
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
void _fastcall TCompositeBeamMainForm::chck_bx_end_beamClick(TObject *Sender)
{
	if (chck_bx_end_beam->Checked){
		lbl_trib_width_left->Caption="Свес плиты [мм]:";
		lbl_trib_width_right->Caption="Расстояние между балками [мм]:";
		}
	else{
		lbl_trib_width_left->Caption="Расстояние между балками слева [мм]:";
		lbl_trib_width_right->Caption="Расстояние между балками справа [мм]:";
    }
}
//---------------------------------------------------------------------------
//	Функция заполняющая ComboBox случаями загружений
//---------------------------------------------------------------------------
void TCompositeBeamMainForm::fill_cmb_bx_LC()
{
	   //Метод AddItem, связывающий TStrings с объектами требуется в качестве параметра объект TObject
	cmb_bx_LC->Items->Insert((int)LoadCaseNames::SW, "Собственный Вес");
	cmb_bx_LC->Items->Insert((int)LoadCaseNames::DL_I , "Постоянная Нагрузка I стадия");
	cmb_bx_LC->Items->Insert((int)LoadCaseNames::DL_II, "Постоянная Нагрузка II стадия");
	cmb_bx_LC->Items->Insert((int)LoadCaseNames::LL, "Временная Нагрузка");
	cmb_bx_LC->ItemIndex = (int)LoadCaseNames::SW;
}




//---------------------------------------------------------------------------

void __fastcall TCompositeBeamMainForm::BtBtnSteelChoiceClick(TObject *Sender)
{
	 SteelDefinitionForm->ShowModal();
	 PnlSteelViewer->Caption = SteelDefinitionForm->ComboBox_steel->Text;
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
}
//---------------------------------------------------------------------------

void __fastcall TCompositeBeamMainForm::BtBtnShearStudsChoiceClick(TObject *Sender)
{
	StudDefinitionForm->ShowModal();
    PnlShearStudsViewer->Caption=StudDefinitionForm->cmb_bx_stud_part_number->Text;//После закрытия формы, на pnl заносится текст из cmb_bx
}
//---------------------------------------------------------------------------

void __fastcall TCompositeBeamMainForm::NOutReportClick(TObject *Sender)
{
	  // Вывести файл отчета
	   int rc = Application->MessageBox(L"Здесь выводится файл отчета в формате Word",
			   L" ", MB_OK | MB_ICONINFORMATION);

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
//[1.1] Топология
	report_.PasteTextPattern("Нет", "%end_beam%");
	report_.PasteTextPattern(FloatToStr(composite_beam_.get_geometry().get_span()), "%span%");
	report_.PasteTextPattern(FloatToStr(composite_beam_.get_geometry().get_trib_width_left(LengthUnits::m)), "%trib_width_left% ");
	report_.PasteTextPattern(FloatToStr(composite_beam_.get_geometry().get_trib_width_right()), "%trib_width_right% ");

//[1.2] Загружения
	report_.PasteTextPattern(FloatToStr(composite_beam_.get_loads().get_dead_load_first_stage()), "%DL_I%");
	report_.PasteTextPattern(FloatToStr(composite_beam_.get_loads().get_dead_load_second_stage()), "%DL_II%");
	report_.PasteTextPattern(FloatToStr(composite_beam_.get_loads().get_live_load()), "%LL%");
	report_.PasteTextPattern(FloatToStr(composite_beam_.get_loads().get_gamma_f_DL_I()), "%gamma_f_DL_I%");
	report_.PasteTextPattern(FloatToStr(composite_beam_.get_loads().get_gamma_f_DL_II()), "%gamma_f_DL_II%");
	report_.PasteTextPattern(FloatToStr(composite_beam_.get_loads().get_gamma_f_LL()), "%gamma_f_LL%");
//[1.1] Стальное сечение
//[1.1.1] Номинальные размеры двутавра





}

//---------------------------------------------------------------------------

void __fastcall TCompositeBeamMainForm::btn_draw_diagramClick(TObject *Sender)
{
	TImage *Image1=ImgStaticScheme;
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
		std::vector<double> M=composite_beam_.get_internal_forces_LC()[static_cast<LoadCaseNames>(cmb_bx_LC->ItemIndex)].get_M();
		DrawEpur(Image1, M.size(), &coor_epur[0], &M[0], nullptr, n_supp, &coor_supp[0], flag_sign);
	}
	else
	{
		//получаем поперечные силы из объекта композитная балка
		std::vector<double> Q=composite_beam_.get_internal_forces_LC()[static_cast<LoadCaseNames>(cmb_bx_LC->ItemIndex)].get_Q();
		std::vector<double> Q_jump=composite_beam_.get_internal_forces_LC()[static_cast<LoadCaseNames>(cmb_bx_LC->ItemIndex)].get_Q_jump();
		DrawEpur(Image1, Q.size(), &coor_epur[0], &Q[0], &Q_jump[0], n_supp, &coor_supp[0], flag_sign);
	}
}
//---------------------------------------------------------------------------


