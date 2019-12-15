//---------------------------------------------------------------------------
#include <math.h>

#pragma hdrstop

#include "ReportCopmpositeBeam.h"
#include "Word_Automation.h"
#include "StandartProfil.h"
#include "SelectProfilSect.h"
#include "RichReport.h"
#include "CheckExecuteU.h"

static    Variant vTabl;
static    Variant my_tables;
static    Variant my_table;
static TStandartProfil StandartProfil;
static     DATA_SELECT *Ds;

extern TCheckExecute CheckExecute;

void Report_sect_param();
void Report_Rect_sect_param();
void Report_Circ_sect_param();
void Report_centr_tension();
//void Report_Rect_centr_tension();
//void Report_Circ_centr_tension();
void Report_centr_compress();
//void Report_Rect_centr_compress();
//void Report_Circ_centr_compress();
void Report_comp_bending();
void Report_bending();
//------------------------------------------------------------------
int Report_Checking() {
  int i, k, rc;

  AnsiString type_section[4] = {"Двутавр", "Квадратная труба", "Прямоугольная труба", "Круглая труба"};

  Ds = &(SelectProfilSectForm->Data_select);

  // Создание объекта Word
  Word_Automation.GetActiveWord();
  // Создание документа
  rc = Word_Automation.CreateDocument("SelectProfilSteel.dot");
  if (rc>0)
	 return rc;

  // Выделить весь документ
  Word_Automation.this_doc.OleProcedure("Select");
  // получить ссылку на объект выделения
  Word_Automation.my_selection = Word_Automation.my_word.OlePropertyGet("Selection");
  if (Ds->form_profil == 0) {  // Двутавр
	Word_Automation.PasteFilePattern("Select_Ibeam_sect_param.doc", "%FILE_SECT_PARAM");
	// Вывести таблицу основных параметров
	Report_sect_param();
  }
  else {
	if (Ds->type_profil != typeCIRC) {
	   Word_Automation.PasteFilePattern("Select_Rect_sect_param.doc", "%FILE_SECT_PARAM");
	// Вывести таблицу основных параметров
	   Report_sect_param();
	}
	else {
	   Word_Automation.PasteFilePattern("Select_Circ_sect_param.doc", "%FILE_SECT_PARAM");
	// Вывести таблицу основных параметров
	   Report_sect_param();
	}
  }
  int num_tabl = 2;
  //-----------------------------------------------------------------
  // Центрально-растянутые
  if (SelectProfilSectForm->TabSheet_KI_CT->TabVisible) {
	if (Ds->form_profil == 0) {  // Двутавр
		Word_Automation.PasteFilePattern("Select_Ibeam_centr_tension.doc", "%FILE_CENTR_TENS");
		//Report_centr_tension();
	}
	else {
	  if (Ds->type_profil != typeCIRC) {
		 Word_Automation.PasteFilePattern("Select_Rect_centr_tension.doc", "%FILE_CENTR_TENS");
		 //Report_Rect_centr_tension();
	  }
	  else {
		 Word_Automation.PasteFilePattern("Select_Circ_centr_tension.doc", "%FILE_CENTR_TENS");
		 //Report_Circ_centr_tension();
	  }
	}
	Report_centr_tension();
	num_tabl ++;
    Word_Automation.PasteTextPattern(IntToStr(num_tabl), "%NUM_TABL_CT");
  }
  else {
	Word_Automation.PasteTextPattern(" ", "%FILE_CENTR_TENS");
  }

  //-----------------------------------------------------------------
  // Центрально-сжатые
  if (SelectProfilSectForm->TabSheet_KI_CC->TabVisible) {
	if (Ds->form_profil == 0) {  // Двутавр
		Word_Automation.PasteFilePattern("Select_Ibeam_centr_compress.doc", "%FILE_CENTR_COMP");
		//Report_centr_compress();
	 }
	 else {
	  if (Ds->type_profil != typeCIRC) {
		 Word_Automation.PasteFilePattern("Select_Rect_centr_compress.doc", "%FILE_CENTR_COMP");
		 //Report_Rect_centr_compress();
	  }
	  else {
		 Word_Automation.PasteFilePattern("Select_Circ_centr_compress.doc", "%FILE_CENTR_COMP");
		 //Report_Circ_centr_compress();
	  }
	 }
	 Report_centr_compress();
	 num_tabl ++;
	 Word_Automation.PasteTextPattern(IntToStr(num_tabl), "%NUM_TABL_CC");
  }
  else {
   Word_Automation.PasteTextPattern(" ", "%FILE_CENTR_COMP");
  }

  //-----------------------------------------------------------------
  // Сжато-изгибаемые
  if (SelectProfilSectForm->TabSheet_KI_CB->TabVisible) {
	Word_Automation.PasteFilePattern("Select_Ibeam_compress_bending.doc", "%FILE_COMP_BEND");
	Report_comp_bending();
	num_tabl ++;
	Word_Automation.PasteTextPattern(IntToStr(num_tabl), "%NUM_TABL_CB");
  }
  else {
   Word_Automation.PasteTextPattern(" ", "%FILE_COMP_BEND");
  }
  //-----------------------------------------------------------------
  // Изгибаемые
  if (SelectProfilSectForm->TabSheet_KI_B->TabVisible) {
	Word_Automation.PasteFilePattern("Select_Ibeam_bending.doc", "%FILE_BEND");
	Report_bending();
	num_tabl ++;
	Word_Automation.PasteTextPattern(IntToStr(num_tabl), "%NUM_TABL_B");
  }
  else {
   Word_Automation.PasteTextPattern(" ", "%FILE_BEND");
  }

  Word_Automation.PasteTextPattern(IntToStr(Ds->N_plane), "%NUM_PART");
  Word_Automation.PasteTextPattern(IntToStr(Ds->index_class), "%CLASS");

  Word_Automation.PasteTextPattern(AnsiString(Ds->title_material), "%MATERIAL");
  Word_Automation.PasteTextPattern(FloatToStr(Ds->t0), "%T0");
  Word_Automation.PasteTextPattern(FloatToStr(Ds->t1), "%T1");
  Word_Automation.PasteTextPattern(FloatToStr(Ds->Ry), "%RY");
  Word_Automation.PasteTextPattern(FloatToStr(Ds->Run), "%RUN");
  Word_Automation.PasteTextPattern(FloatToStr(Ds->gamma_m), "%GAMMA_M");

  Word_Automation.PasteTextPattern(FloatToStrF(Ds->gamma_c, ffFixed, 15, 2), "%GAMMA_C");
  if (Ds->form_profil==0)
	Word_Automation.PasteTextPattern(type_section[0], "%TYPE_SECT");
  else {
	if (Ds->type_profil==typeSQUARE)
		Word_Automation.PasteTextPattern(type_section[1], "%TYPE_SECT");
	if (Ds->type_profil==typeRECT)
		Word_Automation.PasteTextPattern(type_section[2], "%TYPE_SECT");
	if (Ds->type_profil==typeCIRC)
		Word_Automation.PasteTextPattern(type_section[3], "%TYPE_SECT");
  }
  if (!Ds->flag_add_limit || Ds->max_height==0 ) {
	Word_Automation.PasteTextPattern("нет", "%MAX_HEIGHT");
  }
  else
	Word_Automation.PasteTextPattern(FloatToStr(Ds->max_height), "%MAX_HEIGHT");

  if (!Ds->flag_add_limit || Ds->max_width==0 ) {
	Word_Automation.PasteTextPattern("нет", "%MAX_WIDTH");
  }
  else
	Word_Automation.PasteTextPattern(FloatToStr(Ds->max_width), "%MAX_WIDTH");

  Word_Automation.PasteTextPattern(FloatToStr(Ds->Limit_lambda1), "%LAM1");
  Word_Automation.PasteTextPattern(FloatToStr(Ds->Limit_lambda2), "%LAM2");
  Word_Automation.PasteTextPattern(FloatToStr(Ds->Limit_lambda_plus), "%LAM_TENS");

  //-------------------------------------------------------------
  // Вставка таблицы параметров РСУ
  RichReportForm->RichEditOut->Clear();
  char stroka[1200];
  char strpl[36];
  char s_length[1200];
  char strk1[1200];
  char strk2[1200];
  char str_step[1200];
  char strN[1200];
  char strMx[1200];
  char strMy[1200];
  char strq[1200];
  double N_, Mx, My, Qy, Qx, q_bal;

  RichReportForm->RichEditOut->Lines->Add("*-");
  strcpy(stroka, "");
  strcpy(s_length, "");
  strcpy(strk1, "");
  strcpy(strk2, "");
  strcpy(str_step, "");
  for (i=0; i<Ds->N_plane; i++) {
	sprintf(strpl," |Элемент %d", i+1);
	strcpy(stroka+strlen(stroka), strpl);
	sprintf(strpl," |%10.0f", Ds->Length[i]);
	strcpy(s_length+strlen(s_length), strpl);
	sprintf(strpl," |%10.0f", Ds->length_YY[i]);
	strcpy(strk1+strlen(strk1), strpl);
	sprintf(strpl," |%10.0f", Ds->length_XX[i]);
	strcpy(strk2+strlen(strk2), strpl);
	sprintf(strpl," |%10.0f", Ds->step_comp[i]);
	strcpy(str_step+strlen(str_step), strpl);
  }
  RichReportForm->RichEditOut->Lines->Add(AnsiString(stroka));
  RichReportForm->RichEditOut->Lines->Add(" Длина, мм"+AnsiString(s_length));  //Коэффициент расчетной длины \u03BC в пл. XZ";
  RichReportForm->RichEditOut->Lines->Add(L"Расчетная длина в пл. YZ, мм" + String(strk1));
  RichReportForm->RichEditOut->Lines->Add(L"Расчетная длина в пл. XZ, мм" + String(strk2));
  if (Ds->form_profil==0)
	RichReportForm->RichEditOut->Lines->Add(L"Шаг раскреплений сжатого пояса, мм" + String(str_step));

  RichReportForm->RichEditOut->Lines->Add("*-");
  Word_Automation.PasteTable(RichReportForm->RichEditOut, "%TABL_PARAM");

  my_tables = Word_Automation.my_range.OlePropertyGet("Tables");
  // Получить ссылку на таблицу
  my_table=my_tables.OleFunction("Item", 1);

  // Выровнять таблицу по центру
  // wdAlignRowLeft = 0;
  // wdAlignRowCentr = 1;
  // wdAlignRowRight = 2;
  // my_table.OlePropertyGet("Rows").OlePropertySet("Alignment", 1);

  // установка стиля таблицы
  my_table.OleFunction("AutoFormat", 23, true, false,
										 true, true,
										 true, false,
										 true, false, true);

  // Таблицы РСУ
  RichReportForm->RichEditOut->Lines->Add("*-");
  if (Ds->form_profil==0)
	sprintf(stroka,"|N кН|Mx кН*м|Qy кН|My кН*м|Qx кН|qy кН/м");
  else
	sprintf(stroka,"|N кН");
  RichReportForm->RichEditOut->Lines->Add(AnsiString(stroka));
  for (i=0; i<Ds->N_plane; i++) {
	sprintf(strpl,"№ РСУ| Элемент %d", i+1);
	RichReportForm->RichEditOut->Lines->Add(AnsiString(strpl));
	for (k=0; k<Ds->N_RSU[i]; k++) {
	  if (Ds->form_profil==0)
		sprintf(stroka,"%d|%10.1f|%10.1f|%10.1f|%10.1f|%10.1f|%10.1f",
			  k+1, Ds->RSU[i][k][0], Ds->RSU[i][k][1], Ds->RSU[i][k][2],
				   Ds->RSU[i][k][3], Ds->RSU[i][k][4], Ds->q_bal[i][k]);
	  else
		sprintf(stroka,"%d|%10.1f",
			  k+1, Ds->RSU[i][k][0]);
	  RichReportForm->RichEditOut->Lines->Add(AnsiString(stroka));
	}
  }
  RichReportForm->RichEditOut->Lines->Add("*-");
  Word_Automation.PasteTable(RichReportForm->RichEditOut, "%TABL_RSU");

  my_tables = Word_Automation.my_range.OlePropertyGet("Tables");
  // Получить ссылку на таблицу
  my_table=my_tables.OleFunction("Item", 1);

  // Выровнять таблицу по центру
  // wdAlignRowLeft = 0;
  // wdAlignRowCentr = 1;
  // wdAlignRowRight = 2;
  // my_table.OlePropertyGet("Rows").OlePropertySet("Alignment", 1);

  // установка стиля таблицы
  my_table.OleFunction("AutoFormat", 23, true, false,
										 true, true,
										 true, false,
										 true, false, true);

  Screen->Cursor = crDefault;



  return 0;
}
//-------------------------------------------------------------------------------
// Вывод основных расчетных параметров сечения (для двутавров)
void Report_sect_param() {

  int in, i, k;
  CHECK_ELEM_PARAM_U *Cp;
  DATA_CHECK_U *Dt;

  Dt = &(CheckExecute.Data_check_U);
  Cp = &(CheckExecute.Check_param);

  Word_Automation.PasteTextPattern(SelectProfilSectForm->Name_prof, "%NUM_SECT");
  Word_Automation.PasteTextPattern(FloatToStrF(Cp->hw, ffFixed, 15, 0), "%HW_");
  Word_Automation.PasteTextPattern(FloatToStrF(Cp->hef, ffFixed, 15, 0), "%HEF_");
  Word_Automation.PasteTextPattern(FloatToStrF(Cp->bef, ffFixed, 15, 0), "%BEF");

  double Nmin;

  in = -1;
  for (i=0; i<Cp->n_RSU; i++) {
	if (Nmin > Cp->RSU[i][0]) {
	  Nmin = Cp->RSU[i][0];
	  in= i;
	}
  }
  in = SelectProfilSectForm->nnel_max;
  Word_Automation.PasteTextPattern((AnsiString)Cp->Steel, "%STEEL");
  Word_Automation.PasteTextPattern(IntToStr(in+1), "%NUMEL");
  Word_Automation.PasteTextPattern(FloatToStr(Cp->hsect), "%HSECT");
	//Word_Automation.PasteTextPattern(FloatToStr(Cp->Sect_Elem.com_sect.dvutavr.h +
	//								 2*Cp->Sect_Elem.com_sect.dvutavr.h1), "%HSECT");
  Word_Automation.PasteTextPattern(FloatToStr(Cp->bsect), "%BSECT");
	//Word_Automation.PasteTextPattern(FloatToStr(Cp->Sect_Elem.com_sect.dvutavr.b1), "%BSECT");
  Word_Automation.PasteTextPattern(FloatToStr(Cp->Sect_Elem.com_sect.dvutavr.b), "%TW");
  Word_Automation.PasteTextPattern(FloatToStr(Cp->Sect_Elem.com_sect.dvutavr.h1), "%TB");

  Word_Automation.PasteTextPattern(FloatToStrF(Dt->length_XZ[in], ffFixed, 15, 0), "%LEN_XZ");
  Word_Automation.PasteTextPattern(FloatToStrF(Dt->length_YZ[in], ffFixed, 15, 0), "%LEN_YZ");
  //------------------------------------------------------------------------------------------
  Word_Automation.PasteTextPattern(FloatToStrF(Cp->Ryn, ffFixed, 15, 0), "%RYN");
  Word_Automation.PasteTextPattern(FloatToStrF(Cp->Ry, ffFixed, 15, 0), "%RY_");
  Word_Automation.PasteTextPattern(FloatToStrF(Cp->Rs, ffFixed, 15, 0), "%RS_");
  //
  Word_Automation.PasteTextPattern(IntToStr(Cp->nelem), "%NELEM");
  Word_Automation.PasteTextPattern(FloatToStrF(Cp->param_sect.Ar*1e-2, ffFixed, 15, 1), "%AN_");
  Word_Automation.PasteTextPattern(FloatToStrF(Cp->Ad*1e-2, ffFixed, 15, 1), "%AD_");

  Word_Automation.PasteTextPattern(FloatToStrF(Cp->param_sect.Itor*1e-4, ffFixed, 15, 0), "%IT");
  Word_Automation.PasteTextPattern(FloatToStrF(Cp->alfa_f, ffFixed, 15, 2), "%AF_");
  Word_Automation.PasteTextPattern(FloatToStrF(Cp->lambda_uw, ffFixed, 15, 2), "%LAMB_UW");
  Word_Automation.PasteTextPattern(FloatToStrF(Cp->lambda_w, ffFixed, 15, 2), "%LAMB_W");
  Word_Automation.PasteTextPattern(FloatToStrF(Cp->lambda_uf, ffFixed, 15, 2), "%LAMB_UF");
  Word_Automation.PasteTextPattern(FloatToStrF(Cp->lambda_f, ffFixed, 15, 2), "%LAMB_F");
  Word_Automation.PasteTextPattern(FloatToStrF(Cp->lambda_f1, ffFixed, 15, 2), "%LAMB_F1");
  Word_Automation.PasteTextPattern(FloatToStrF(Cp->lambda_f2, ffFixed, 15, 2), "%LAMB_F2");
  Word_Automation.PasteTextPattern(FloatToStrF(Cp->lambdaX, ffFixed, 15, 2), "%LAMBX");
  Word_Automation.PasteTextPattern(FloatToStrF(Cp->lambda_x, ffFixed, 15, 2), "%LAMB_X");
  Word_Automation.PasteTextPattern(FloatToStrF(Cp->lambdaY, ffFixed, 15, 2), "%LAMBY");
  Word_Automation.PasteTextPattern(FloatToStrF(Cp->lambda_y, ffFixed, 15, 2), "%LAMB_Y");

  Word_Automation.PasteTextPattern(FloatToStrF(Cp->fi_x, ffFixed, 15, 2), "%_FI_X");
  Word_Automation.PasteTextPattern(FloatToStrF(Cp->fi_y, ffFixed, 15, 2), "%_FI_Y");
  Word_Automation.PasteTextPattern(FloatToStrF(Cp->cfi_y, ffFixed, 15, 2), "%CFI_Y");
}
//-------------------------------------------------------------------------------
// Вывод отчета для центрально-растянутых элементов (двутавров)
void Report_centr_tension() {

  int in, i, k;
  CHECK_ELEM_PARAM_U *Cp;
  DATA_CHECK_U *Dt;

  Dt = &(CheckExecute.Data_check_U);
  Cp = &(CheckExecute.Check_param);


  AnsiString Text_coeff;
  for (i=0, k=0; i<SelectProfilSectForm->Data_select.N_check[0]; i++) {
		if (SelectProfilSectForm->Num_prov[0][i]==1) {
		  if (k<9)
			Text_coeff = "%Coeff_0"+IntToStr(k+1);
		  else
			Text_coeff = "%Coeff_"+IntToStr(k+1);
		  if (SelectProfilSectForm->Krit[0][i]>=0) {
			  Word_Automation.PasteTextPattern(FloatToStrF(SelectProfilSectForm->Krit[0][i], ffFixed, 15, 2),
			  Text_coeff);
		  }
		  else {
			Word_Automation.PasteTextPattern("-", Text_coeff);
		  }

		  k++;
		}
  }

}
//-------------------------------------------------------------------------------
// Вывод отчета для центрально-сжатых элементов (двутавров)
void Report_centr_compress() {

  int in, i, k;
  CHECK_ELEM_PARAM_U *Cp;
  DATA_CHECK_U *Dt;

  Dt = &(CheckExecute.Data_check_U);
  Cp = &(CheckExecute.Check_param);


  AnsiString Text_coeff;
  for (i=0, k=0; i<SelectProfilSectForm->Data_select.N_check[1]; i++) {
		if (SelectProfilSectForm->Num_prov[1][i]==1) {
		  if (k<9)
			Text_coeff = "%Coeff_0"+IntToStr(k+1);
		  else
			Text_coeff = "%Coeff_"+IntToStr(k+1);
		  if (SelectProfilSectForm->Krit[1][i]>=0) {
			  Word_Automation.PasteTextPattern(FloatToStrF(SelectProfilSectForm->Krit[1][i], ffFixed, 15, 2),
			  Text_coeff);
		  }
		  else {
			Word_Automation.PasteTextPattern("-", Text_coeff);
		  }
		  k++;
		}
  }

}
//-------------------------------------------------------------------------------
// Вывод отчета для сжато-изгибаемых элементов (двутавров)
void Report_comp_bending() {

  int in, i, k;
  CHECK_ELEM_PARAM_U *Cp;
  DATA_CHECK_U *Dt;

  Dt = &(CheckExecute.Data_check_U);
  Cp = &(CheckExecute.Check_param);


  AnsiString Text_coeff;
  for (i=0, k=0; i<SelectProfilSectForm->Data_select.N_check[2]; i++) {
		if (SelectProfilSectForm->Num_prov[2][i]==1) {
		  if (k<9)
			Text_coeff = "%Coeff_0"+IntToStr(k+1);
		  else
			Text_coeff = "%Coeff_"+IntToStr(k+1);
		  if (SelectProfilSectForm->Krit[2][i]>=0) {
			Word_Automation.PasteTextPattern(FloatToStrF(SelectProfilSectForm->Krit[2][i], ffFixed, 15, 2),
			Text_coeff);
		  }
		  else {
			Word_Automation.PasteTextPattern("-", Text_coeff);
		  }
		  k++;
		}
  }

}
//-------------------------------------------------------------------------------
// Вывод отчета для изгибаемых элементов (двутавров)
void Report_bending() {

  int in, i, k;
  CHECK_ELEM_PARAM_U *Cp;
  DATA_CHECK_U *Dt;

  Dt = &(CheckExecute.Data_check_U);
  Cp = &(CheckExecute.Check_param);


  AnsiString Text_coeff;
  for (i=0, k=0; i<SelectProfilSectForm->Data_select.N_check[3]; i++) {
		if (SelectProfilSectForm->Num_prov[3][i]==1) {
		  if (k<9)
			Text_coeff = "%Coeff_0"+IntToStr(k+1);
		  else
			Text_coeff = "%Coeff_"+IntToStr(k+1);
		  if (SelectProfilSectForm->Krit[3][i] >= 0) {
			Word_Automation.PasteTextPattern(FloatToStrF(SelectProfilSectForm->Krit[3][i], ffFixed, 15, 2),
			Text_coeff);
		  }
		  else {
			Word_Automation.PasteTextPattern("-", Text_coeff);
		  }
		  k++;
		}
  }

}



