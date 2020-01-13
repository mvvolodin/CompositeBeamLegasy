//---------------------------------------------------------------------------

#include <vcl.h>
#include <math.h>
#pragma hdrstop
//С уклоном полок по ГОСТ 8239-89
//Нормальный(Б) по ГОСТ 26020-83
//Дополнительной серии(Д) по ГОСТ 26020-83
//Широкополочный по ГОСТ 26020-83
//Колонный(К) по ГОСТ 26020-83

#include "SteelSectionDefinitionFrameUnit.h"
#include "Data_Profil.h"
#include "ListConst.h"
#include "StandartProfil.h"
#include "pCanvas_func.h"
#include "ProcExt.h"
#include "String_doubleUnit.h"

#define COLOR clMedGray
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

//TSteelSectionDefinitionFrame *SteelSectionDefinitionFrame;
//extern int index_choice[MAX_ADD_SECT];
//extern COM_RAMA Common_rama;


extern bool flag_sect_change; // флаг изменения параметров сечения
extern int  Type_sect;   // Тип сечения - Двутавр или труба
//extern COMMON_SECT *common_sect;
extern bool flag_image;

#ifdef EMBRAC
static String text, header;
#else
static AnsiString text, header;
#endif
static TStandartProfil StandartProfil;
//---------------------------------------------------------------------------
//Конструктор заполняет таблицы названиями отображаемых геометрических параметров
//---------------------------------------------------------------------------
__fastcall TSteelSectionDefinitionFrame::TSteelSectionDefinitionFrame(TComponent* Owner)
        : TFrame(Owner)
{
     Check_Original();
	 StringGrid_B->Cells[0][0]="h (мм)";     //Двутавр
     StringGrid_B->Cells[0][1]="bf (мм)";
     StringGrid_B->Cells[0][2]="tw (мм)";
     StringGrid_B->Cells[0][3]="tf (мм)";
	 StringGrid_B->Cells[0][4]="A (cм2)";
     StringGrid_B->Cells[0][5]="Iyy (cм4)";
	 StringGrid_B->Cells[0][6]="iy (мм)";

/*
		 StringGrid_Tube->Cells[0][0]="h (мм)";    //Квадратная и прямоугольная трубы
    	 StringGrid_Tube->Cells[0][1]="b (мм)";
    	 StringGrid_Tube->Cells[0][2]="t (мм)";
    	 StringGrid_Tube->Cells[0][3]="A (cм2)";
    	 StringGrid_Tube->Cells[0][4]="Iyy (cм4)";
    	 StringGrid_Tube->Cells[0][5]="Izz (см4)";

         StringGrid_Cyl->Cells[0][0]="D (мм)";       //Круглые трубы
         StringGrid_Cyl->Cells[0][1]="t (мм)";
         StringGrid_Cyl->Cells[0][2]="A (cм2)";
    	 StringGrid_Cyl->Cells[0][3]="Iyy (cм4)";
		 StringGrid_Cyl->Cells[0][4]="Wyy (см3)";
*/

}
//---------------------------------------------------------------------------
//-------------------------------------------------------------------------
//---------------------------------------------------------------

	void __fastcall TSteelSectionDefinitionFrame::Write_sect(TObject *Sender) {
       int i, n_profil;
	   AnsiString* NameProfil;
       bool flag_concl;

			FillComboBox1(Sender);
			ComboBox_TypeSect->ItemIndex = MIN(ComboBox_TypeSect->Items->Count - 1, Type_sect);
            Button_Copy->Visible = TabSheet_Weld->TabVisible;
    		Edit1->Text="0"; //Edit1-Edit6 поля, которые отображают геометрические параметры сварного сечения
            Edit2->Text="0";
            Edit3->Text="0";
			Edit4->Text="0";
			Edit5->Text="0";
			Edit6->Text="0";

    		TabSheet_StandTube->TabVisible = false;  //скрываем отображение закладки с квадратными и прямоугольными трубами
			TabSheet_CYL->TabVisible = false;        ///скрываем отображение закладки с круглыми трубами

			switch (Type_sect) {
    		case DVUTAVR:
			flag_concl = common_sect_.dvutavr.flag_concl;// common_sect это union
			if (common_sect_.dvutavr.flag_concl) { //если сечение изменилось, то
			  if (common_sect_.dvutavr.n_group < 0) { // где n_group устан
				Label7->Visible=false;

				Edit1->Visible=true;
				Edit2->Visible=true;
				Edit3->Visible=true;
				Edit4->Visible=true;
                Edit5->Visible=true;
                Edit6->Visible=true;

                Label1->Visible=true;
                Label2->Visible=true;
                Label3->Visible=true;
                Label4->Visible=true;
                Label5->Visible=true;
                Label6->Visible=true;

                Weld_Change(Sender);
                Change_type_sect(-1, Sender);
              }
              else {
    			//RadioGroup_typeClick(Sender);
    		 // Установить тип стандартного сечения
    			if (common_sect_.dvutavr.n_group < typeSTO_B) {
                  PageControl1->ActivePage = TabSheet_GOST;
                  RadioGroup_GOST->ItemIndex = common_sect_.dvutavr.n_group;
                }
                if (common_sect_.dvutavr.n_group >=typeSTO_B && common_sect_.dvutavr.n_group <=typeSTO_K) {
                  PageControl1->ActivePage = TabSheet_STO;
                  RadioGroup_STO->ItemIndex = common_sect_.dvutavr.n_group - typeSTO_B;
                }
                if (common_sect_.dvutavr.n_group >=typeGOST_G57837_B && common_sect_.dvutavr.n_group <=typeGOST_G57837_S) {
				  PageControl1->ActivePage = TabSheet_GOST57837;
                  RadioGroupGOST57837->ItemIndex = common_sect_.dvutavr.n_group - typeGOST_G57837_B;
                }
    			StandartProfil.SetProfil(common_sect_.dvutavr.n_group);
                Change_type_sect(common_sect_.dvutavr.n_group, Sender);
                //RadioGroup_GOST->ItemIndex = common_sect_.dvutavr.n_group;
             // Получить вектор имен профилей и длину вектора
                NameProfil = StandartProfil.GetVectorNameProfil(&n_profil);

                ComboBox_profil->Items->Clear();
                for (i=0; i<n_profil; i++) {
				  ComboBox_profil->Items->Add(NameProfil[i]);
                }
                ComboBox_profil->ItemIndex = common_sect_.dvutavr.n_profil;
                ComboBox_profilChange(Sender);
              }
            }
            else {
              if (common_sect_.dvutavr.n_group < 0) {
                TabSheet_Weld->TabVisible = true;
                TabSheet_Standart->TabVisible = false;
              }
              else {
                TabSheet_Weld->TabVisible = false;
                TabSheet_Standart->TabVisible = true;
              }
            }
            break;

                case SQUARE_TUBE:
                		flag_concl = common_sect_.square.flag_concl;
                		TabSheet_Standart->TabVisible = false;
                		if (common_sect_.square.flag_concl) {
                		  if (common_sect_.square.n_group < 0) {
                            Label7->Visible=false;

                            Edit1->Visible=true;
                			Edit2->Visible=false;
							Edit3->Visible=true;
                            Edit4->Visible=false;
                            Edit5->Visible=false;
                            Edit6->Visible=false;

                            Label3->Caption="Размер стороны (b)";
                            Label1->Caption="Толщина стенки (t)";

                			Label1->Visible=true;
                			Label2->Visible=false;
                			Label3->Visible=true;
                            Label4->Visible=false;
                            Label5->Visible=false;
                			Label6->Visible=false;

                            Change_type_sect(-1, Sender);
                			Edit3->Text=FloatToStr(common_sect_.square.side);
                			Edit1->Text=FloatToStr(common_sect_.square.thickness);
                		  }
                		  else {
                		 // Установить тип стандартного сечения
                			TabSheet_StandTube->TabVisible = true;
                			TabSheet_Weld->TabVisible = false;
                			TabSheet_Rect->TabVisible = false;
                            TabSheet_Square->TabVisible = true;
                			// Установить тип профиля - прямоугольная труба
						   //	StandartProfil.SetProfil_Tube(typeSQUARE);
							Change_type_sect_tube(typeSQUARE, Sender);
						 // Получить вектор имен профилей и длину вектора
                            NameProfil = StandartProfil.GetVectorNameProfil(&n_profil);

                            ComboBox_h_b_square->Items->Clear();
                            for (i=0; i<n_profil; i++) {
                			  ComboBox_h_b_square->Items->Add(NameProfil[i]);
                            }
                            ComboBox_h_b_square->ItemIndex = common_sect_.square.n_group;
                			ComboBox_h_b_squareChange(Sender);
                            ComboBox_t_square->ItemIndex = common_sect_.square.n_profil;
                            //RadioGroup_orient->ItemIndex = common_sect_.square.index_orient;
                		  }
                        }
                         else {
                		  if (common_sect_.square.n_group < 0) {
                			TabSheet_Weld->TabVisible = true;
                			TabSheet_StandTube->TabVisible = false;
                		  }
                		  else {
                			TabSheet_Weld->TabVisible = false;
                			TabSheet_StandTube->TabVisible = true;
                            TabSheet_Rect->TabVisible = false;
                            TabSheet_Square->TabVisible = true;
                		  }
						}
					   break;
				case RECT_TUBE:
    		flag_concl = common_sect_.rect.flag_concl;
    		TabSheet_Standart->TabVisible = false;
    		if (common_sect_.rect.flag_concl) {
    		  if (common_sect_.rect.n_group < 0) {
    			Label7->Visible=false;

                Edit1->Visible=true;
                Edit2->Visible=true;
                Edit3->Visible=true;
                Edit4->Visible=true;
                Edit5->Visible=false;
                Edit6->Visible=false;

                Label3->Caption="Ширина сечения (b)";
                Label4->Caption="Высота сечения (h)";
                Label1->Caption="Толщина стенок по Z1 (h1)";
                Label2->Caption="Толщина стенок по Y1 (b1)";

                Label1->Visible=true;
                Label2->Visible=true;
                Label3->Visible=true;
                Label4->Visible=true;
                Label5->Visible=false;
                Label6->Visible=false;

                Change_type_sect(-1, Sender);
                Edit3->Text=FloatToStr(common_sect_.rect.b);
                Edit4->Text=FloatToStr(common_sect_.rect.h);
                Edit2->Text=FloatToStr(common_sect_.rect.b1);
                Edit1->Text=FloatToStr(common_sect_.rect.h1);
              }
              else {
             // Установить тип стандартного сечения
                TabSheet_StandTube->TabVisible = true;
                TabSheet_Weld->TabVisible = false;
                TabSheet_Rect->TabVisible = true;
                TabSheet_Square->TabVisible = false;
                //PageControl_Tube->ActivePage = TabSheet_Rect;
                // Установить тип профиля - прямоугольная труба
				//StandartProfil.SetProfil_Tube(typeRECT);
                Change_type_sect_tube(typeRECT, Sender);
             // Получить вектор имен профилей и длину вектора
                NameProfil = StandartProfil.GetVectorNameProfil(&n_profil);

                ComboBox_h_b_rect->Items->Clear();
                for (i=0; i<n_profil; i++) {
                  ComboBox_h_b_rect->Items->Add(NameProfil[i]);
                }
                ComboBox_h_b_rect->ItemIndex = common_sect_.rect.n_group;
                ComboBox_t_rect->ItemIndex = common_sect_.rect.n_profil;
                RadioGroup_orient->ItemIndex = common_sect_.rect.index_orient;
                ComboBox_h_b_rectChange(Sender);
              }
            }
            else {
              if (common_sect_.rect.n_group < 0) {
                TabSheet_Weld->TabVisible = true;
                TabSheet_StandTube->TabVisible = false;
              }
              else {
                TabSheet_Weld->TabVisible = false;
                TabSheet_StandTube->TabVisible = true;
                TabSheet_Rect->TabVisible = true;
                TabSheet_Square->TabVisible = false;
              }
            }

            break;
            case CIRCULAR_TUBE:
            TabSheet_CYL->TabVisible = false;
            flag_concl = common_sect_.circ.flag_concl;
            if (common_sect_.circ.flag_concl) {
              if (common_sect_.circ.n_group < 0) {
                Label7->Visible=false;

                Edit1->Visible=true;
                Edit2->Visible=false;
                Edit3->Visible=true;
                Edit4->Visible=false;
                Edit5->Visible=false;
                Edit6->Visible=false;

                Label3->Caption="Диаметр (d)";
                Label1->Caption="Толщина стенки (t)";

                Label1->Visible=true;
                Label2->Visible=false;
                Label3->Visible=true;
                Label4->Visible=false;
                Label5->Visible=false;
                Label6->Visible=false;

                Change_type_sect(-1, Sender);
                Edit3->Text=FloatToStr(common_sect_.circ.diameter);
                Edit1->Text=FloatToStr(common_sect_.circ.thickness);
              }
              else {
             // Установить тип стандартного сечения
                TabSheet_CYL->TabVisible = true;
                TabSheet_Weld->TabVisible = false;
                //PageControl_Tube->ActivePage = TabSheet_Rect;
                // Установить тип профиля - прямоугольная труба
				//StandartProfil.SetProfil_Tube(typeCIRC);
                Change_type_sect_tube(typeCIRC, Sender);
             // Получить вектор имен профилей и длину вектора
                NameProfil = StandartProfil.GetVectorNameProfil(&n_profil);

                ComboBox_Cyl_D->Items->Clear();
                for (i=0; i<n_profil; i++) {
                  ComboBox_Cyl_D->Items->Add(NameProfil[i]);
                }
                ComboBox_Cyl_D->ItemIndex = common_sect_.circ.n_group;
                ComboBox_Cyl_t->ItemIndex = common_sect_.circ.n_profil;
                ComboBox_Cyl_DChange(Sender);
              }
            }
            break;
            default:
            ;
        }
        if (flag_concl) {
          CheckBox1->Checked=false;
          CheckBox1->Enabled=true;
          Edit1->Color=clScrollBar;
          Edit2->Color=clScrollBar;
          Edit3->Color=clScrollBar;
          Edit4->Color=clScrollBar;
          Edit5->Color=clScrollBar;
          Edit6->Color=clScrollBar;
          Edit1->Enabled=false;
          Edit2->Enabled=false;
          Edit3->Enabled=false;
          Edit4->Enabled=false;
          Edit5->Enabled=false;
          Edit6->Enabled=false;
          ComboBox_TypeSect->Enabled=false;
          DrawSect();
        }
        else {
          CheckBox1->Checked=false;
          CheckBox1->Enabled=false;
          ComboBox_TypeSect->Enabled=true;
        }
        CheckBox_type_sect->Checked = ComboBox_TypeSect->Enabled;
    }

//-------------------------------------------------------------------------
int __fastcall TSteelSectionDefinitionFrame::Read_sect() {

   int rc;
   double ss;
   double * ParamProfil;


	//*type_sect_currently = Type_sect;
	switch (Type_sect) {
	case DVUTAVR:
	  common_sect_.dvutavr.flag_concl=false;//расшифровка имени flag_concl???
	  if (common_sect_.dvutavr.n_group < 0) {
		rc=String_double_plus(Label3->Caption,Edit3->Text, &(common_sect_.dvutavr.b1));
		if (rc>0) return rc;
        rc=String_double_plus(Label4->Caption,Edit4->Text, &(common_sect_.dvutavr.h1));
        if (rc>0) return rc;
        rc=String_double_plus(Label2->Caption,Edit2->Text, &(common_sect_.dvutavr.h));
        if (rc>0) return rc;
        rc=String_double_plus(Label1->Caption,Edit1->Text, &(common_sect_.dvutavr.b));
        if (rc>0) return rc;
        //if (!flag_simm_sect) {  // несимметричное сечение
          rc=String_double_plus(Label5->Caption,Edit5->Text, &(common_sect_.dvutavr.b2));
          if (rc>0) return rc;
          rc=String_double_plus(Label6->Caption,Edit6->Text, &(common_sect_.dvutavr.h2));
          if (rc>0) return rc;
          common_sect_.dvutavr.flag_concl=true;
        //}
        //else {
        //  common_sect_.dvutavr.b2=common_sect_.dvutavr.b1;
        //  common_sect_.dvutavr.h2=common_sect_.dvutavr.h1;
        //  common_sect_.dvutavr.flag_concl=true;
        //}
        common_sect_.dvutavr.n_group = -1;
        common_sect_.dvutavr.n_profil = -1;
        common_sect_.dvutavr.index_orient = 0;
      }
      else {      // стандартное сечение
		if (PageControl1->ActivePage == TabSheet_GOST57837)
		  common_sect_.dvutavr.n_group = RadioGroupGOST57837->ItemIndex + typeGOST_G57837_B;
		if (PageControl1->ActivePage == TabSheet_GOST)
		  common_sect_.dvutavr.n_group = RadioGroup_GOST->ItemIndex;
		if (PageControl1->ActivePage == TabSheet_STO)
		  common_sect_.dvutavr.n_group = RadioGroup_STO->ItemIndex + typeSTO_B;
        common_sect_.dvutavr.n_profil = ComboBox_profil->ItemIndex;
      // Установить тип стандартного сечения
        StandartProfil.SetProfil(common_sect_.dvutavr.n_group);
        ParamProfil = StandartProfil.GetVectorParamProfil(common_sect_.dvutavr.n_profil);
        common_sect_.dvutavr.b = ParamProfil[2];
        common_sect_.dvutavr.h = ParamProfil[0] - 2*ParamProfil[3];
        common_sect_.dvutavr.b1 = ParamProfil[1];
        common_sect_.dvutavr.b2 = ParamProfil[1];
        common_sect_.dvutavr.h1 = ParamProfil[3];
        common_sect_.dvutavr.h2 = ParamProfil[3];
        common_sect_.dvutavr.flag_concl=true;
        common_sect_.dvutavr.index_orient = 0;
      }
    break;
    case SQUARE_TUBE:
      common_sect_.square.flag_concl=false;
      if (common_sect_.rect.n_group < 0) {
        rc=String_double_plus(Label3->Caption,Edit3->Text, &(common_sect_.square.side));
        if (rc>0) return rc;
        rc=String_double_plus_low(Label1->Caption,Edit1->Text, common_sect_.square.side/2, &(common_sect_.square.thickness));
        if (rc>0) return rc;
        common_sect_.square.flag_concl=true;
		common_sect_.square.b1 = common_sect_.square.h1 = common_sect_.square.b2 =common_sect_.square.h2 = 0;
        common_sect_.square.n_group = -1;
		common_sect_.square.n_profil = -1;
      }
      else {
        common_sect_.square.n_group = ComboBox_h_b_square->ItemIndex;
        common_sect_.square.n_profil = ComboBox_t_square->ItemIndex;
		common_sect_.square.index_orient = 0;
            /*
          // Установить тип стандартного сечения трубы
				  StandartProfil.SetProfil_Tube(typeSQUARE);
                // Получить вектор параметров стандартного сечения трубы
				  ParamProfil = StandartProfil.GetVectorParamProfil_Tube(common_sect_.square.n_group, common_sect_.square.n_profil);
                  common_sect_.square.side = ParamProfil[0];
                  common_sect_.square.thickness = ParamProfil[2];
				  common_sect_.square.b1 = common_sect_.square.h1 = common_sect_.square.b2 =common_sect_.square.h2 = 0;
				  common_sect_.square.flag_concl=true;
      */  }
    break;
    case RECT_TUBE:
      common_sect_.rect.flag_concl=false;
      if (common_sect_.rect.n_group < 0) {
        rc=String_double_plus(Label3->Caption,Edit3->Text, &(common_sect_.rect.b));
        if (rc>0) return rc;
        rc=String_double_plus(Label4->Caption,Edit4->Text, &(common_sect_.rect.h));
        if (rc>0) return rc;
        rc=String_double_plus_low(Label2->Caption,Edit2->Text, common_sect_.rect.b/2 ,&(common_sect_.rect.b1));
        if (rc>0) return rc;
        rc=String_double_plus_low(Label1->Caption,Edit1->Text, common_sect_.rect.h/2 ,&(common_sect_.rect.h1));
        if (rc>0) return rc;
        common_sect_.rect.flag_concl=true;
        common_sect_.rect.b2 =common_sect_.rect.h2 = 0;
        common_sect_.rect.n_group = -1;
        common_sect_.rect.n_profil = -1;
      }
      else {
        common_sect_.rect.n_group = ComboBox_h_b_rect->ItemIndex;
        common_sect_.rect.n_profil = ComboBox_t_rect->ItemIndex;
		common_sect_.rect.index_orient = RadioGroup_orient->ItemIndex;
      // Установить тип стандартного сечения трубы
		//StandartProfil.SetProfil_Tube(typeRECT);
	  // Получить вектор параметров стандартного сечения трубы
	   //	ParamProfil = StandartProfil.GetVectorParamProfil_Tube(common_sect_.rect.n_group, common_sect_.rect.n_profil);
        if (common_sect_.rect.index_orient==0) { // по длинной стороне
          common_sect_.rect.h = ParamProfil[0];
          common_sect_.rect.b = ParamProfil[1];
		}
        else {
          common_sect_.rect.h = ParamProfil[1];
          common_sect_.rect.b = ParamProfil[0];
        }
        common_sect_.rect.h1 = ParamProfil[2];
        common_sect_.rect.b1 = ParamProfil[2];
        common_sect_.dvutavr.b2 = 0;
        common_sect_.dvutavr.h2 = 0;
        common_sect_.dvutavr.flag_concl=true;
      }
    break;
    case CIRCULAR_TUBE:
      common_sect_.circ.flag_concl=false;
      if (common_sect_.rect.n_group < 0) {
        rc=String_double_plus(Label3->Caption,Edit3->Text, &(common_sect_.circ.diameter));
        if (rc>0) return rc;
        rc=String_double_plus_low(Label1->Caption,Edit1->Text, common_sect_.circ.diameter/2, &(common_sect_.circ.thickness));
        if (rc>0) return rc;
        common_sect_.circ.flag_concl=true;
        common_sect_.square.b1 = common_sect_.square.h1 = common_sect_.square.b2 =common_sect_.square.h2 = 0;
        common_sect_.circ.n_group = -1;
		common_sect_.circ.n_profil = -1;
      }
      else {  // Прокатное сечение
        common_sect_.circ.n_group = ComboBox_Cyl_D->ItemIndex;
        common_sect_.circ.n_profil = ComboBox_Cyl_t->ItemIndex;
        common_sect_.circ.index_orient = 0;
      // Установить тип стандартного сечения трубы
	   //	StandartProfil.SetProfil_Tube(typeCIRC);
			/*
          // Получить вектор параметров стандартного сечения трубы
				ParamProfil = StandartProfil.GetVectorParamProfil_Tube(common_sect_.circ.n_group, common_sect_.circ.n_profil);
                  common_sect_.circ.diameter = ParamProfil[0];
          		common_sect_.circ.thickness = ParamProfil[1];
          		common_sect_.circ.b1 = common_sect_.circ.h1 = common_sect_.circ.b2 =common_sect_.circ.h2 = 0;
				common_sect_.circ.flag_concl=true;
      */
      }
	break;
    default:
    ;
  }

      return 0;
}
//--------------------------------------------------------------------
//Процедура вызывающая нужную процедуру в зависимости от типа сечения
//--------------------------------------------------------------------
void __fastcall TSteelSectionDefinitionFrame::DrawSect()
{
  int rc;
  // Прочитать параметры сечения
  rc=Read_sect();
  if (rc>0) return;    //проверяем нет ли ошибки

  switch (Type_sect) {
	case DVUTAVR:
	   draw_dvutavr(Image1, &(common_sect_.dvutavr));
    break;
    case SQUARE_TUBE:
       if (common_sect_.square.n_group < 0)
          draw_square_tube(Image1, &(common_sect_.square));
       else {
          draw_square_tube(Image_square, &(common_sect_.square));
       }
    break;
    case RECT_TUBE:
       if (common_sect_.rect.n_group < 0)
          draw_rect_tube(Image1, &(common_sect_.rect));
       else {
          draw_rect_tube(Image_rect, &(common_sect_.rect));
       }
    break;
    case CIRCULAR_TUBE:
       if (common_sect_.circ.n_group < 0)
          draw_circular_tube(Image1, &(common_sect_.circ));
       else
          draw_circular_tube(Image_Cyl, &(common_sect_.circ));
    break;
    default:
    ;
  }

}
//----------------------------------------------------------------------
// рисование двутавра
void __fastcall TSteelSectionDefinitionFrame::draw_dvutavr(TImage * Image1, SECT_DVUTAVR *sect) {
  TPoint vertices[30];
  int zero, zero1, zero2;
  float scale_1, scale;
  int rc;


  if (sect->n_group < 0) {
    TRect NewRect = Rect(0, 0, Image1->Width,Image1->Height);
    Image1->Canvas->Brush->Color = clWhite;
    Image1->Canvas->FillRect(NewRect);
    Image1->Canvas->Rectangle(0, 0, Image1->Width,Image1->Height);

    scale=(Image1->Width-20)/(1e0*sect->b2);
    scale_1=MIN(scale,(Image1->Width-20)/(1e0*sect->b1));
    scale=MIN(scale_1,(Image1->Height-20)/(1e0*(sect->h + sect->h1 + sect->h2)));

    zero=(Image1->Height - (sect->h + sect->h1 + sect->h2)*scale)/2;
    zero1=(Image1->Width - sect->b2*scale)/2;
    zero2=(Image1->Width - sect->b1*scale)/2;

    Point_dvutavr(zero, zero1, zero2, sect, scale, vertices); // получить точки контура двутавра

    Image1->Canvas->Brush->Color = COLOR;
    Image1->Canvas->Polygon(vertices, 12);
    Image1->Canvas->Brush->Color = clWhite;
    draw_axes(Image1);
  }
  else {
	double * ParamProfil;

    TRect NewRect = Rect(0, 0, Image_stand->Width,Image_stand->Height);
    Image_stand->Canvas->Brush->Color = clWhite;
    Image_stand->Canvas->FillRect(NewRect);
    Image_stand->Canvas->Rectangle(0, 0, Image_stand->Width,Image_stand->Height);

    scale=(Image_stand->Width-35)/(1e0*sect->b2);
    scale_1=MIN(scale,(Image_stand->Width-35)/(1e0*sect->b1));
    scale=MIN(scale_1,(Image_stand->Height-30)/(1e0*(sect->h + sect->h1 + sect->h2)));

    zero=(Image_stand->Height - (sect->h + sect->h1 + sect->h2)*scale)/2 + 10;
    zero1=(Image_stand->Width - sect->b2*scale)/2;
    zero2=(Image_stand->Width - sect->b1*scale)/2;
    StandartProfil.SetProfil(sect->n_group);
    ParamProfil = StandartProfil.GetVectorParamProfil(sect->n_profil);

    Point_stand_dvutavr(zero, zero1, zero2, sect, ParamProfil[parRAD], scale, vertices); // получить точки контура двутавра

    Image_stand->Canvas->Brush->Color = COLOR;
    Image_stand->Canvas->Polygon(vertices, 20);
    Image_stand->Canvas->Brush->Color = clWhite;

    draw_axes_zero(Image_stand, (vertices[0].x + vertices[1].x)/2, (vertices[0].y + vertices[11].y)/2);

    TPoint Point0_r;
    TPoint Point1_r;

	flag_image = true;
    Image_stand->Canvas->Brush->Style=bsClear;
	// Ширина полки
    Point0_r = vertices[0];
    Point1_r = vertices[1];

    pCanvas_Dim_vt(Image_stand, Point0_r, Point1_r, orHORIZ, sideUP, "bf",
                 13, 0, 0, 0);
    // Высота профиля
    Point0_r = vertices[11];
    Point1_r = vertices[0];       

    pCanvas_Dim_vt(Image_stand, Point0_r, Point1_r, orVERT, sideLEFT, "h",
                 6, 0, 4, 0);
    // Толщина пояса профиля
    Point0_r = vertices[1];
    Point1_r = vertices[2];

    int posY = vertices[2].y - vertices[1].y;
    pCanvas_Dim_vt(Image_stand, Point0_r, Point1_r, orVERT, sideRIGHT, "tf",
                 6, 0, -4, -posY/2 - 4);
    // Толщина стенки
    Point0_r = vertices[15];
    Point1_r = vertices[6];

    pCanvas_Dim_vt(Image_stand, Point0_r, Point1_r, orHORIZ, sideUP, "tw",
                 30, 0, 13, 0);

  }
}
//---------------------------------------------------------------------------
// рисование квадратной трубы
void __fastcall TSteelSectionDefinitionFrame::draw_square_tube(TImage * Image1, SECT_SQUARE *sect) {
  TPoint vertices[30];
  double zero, zero1;
  float scale;
  int rc;

  TRect NewRect = Rect(0, 0, Image1->Width,Image1->Height);
  Image1->Canvas->Brush->Color = clWhite;
  Image1->Canvas->FillRect(NewRect);
  Image1->Canvas->Rectangle(0, 0, Image1->Width,Image1->Height);

  scale=(Image1->Width-20)/(1e0*sect->side);
  scale=MIN(scale,(Image1->Height-20)/(1e0*sect->side));

  zero1=(Image1->Height - sect->side*scale)/2;
  zero=(Image1->Width - sect->side*scale)/2;


  double s_c = sect->side*scale;
  double r_c = sect->rad*scale;
  double r2_c = Round(r_c - r_c*cos(45/57.3), 0);

  vertices[0] = Point(zero, zero1 + r_c);
  vertices[1] = Point(zero, zero1 + s_c - r_c);
  vertices[2] = Point(zero + r2_c, zero1 + s_c - r2_c);
  vertices[3] = Point(zero + r_c, zero1 + s_c);
  vertices[4] = Point(zero + s_c - r_c, zero1 + s_c);
  vertices[5] = Point(zero + s_c - r2_c, zero1 + s_c - r2_c);
  vertices[6] = Point(zero + s_c, zero1 + s_c - r_c);
  vertices[7] = Point(zero + s_c, zero1 + r_c);
  vertices[8] = Point(zero + s_c - r2_c, zero1 + r2_c);
  vertices[9] = Point(zero + s_c - r_c, zero1);
  vertices[10] = Point(zero + r_c, zero1);
  vertices[11] = Point(zero + r2_c, zero1 + r2_c);
  vertices[12] = Point(zero, zero1 + r_c);

  Image1->Canvas->Brush->Color = COLOR;
  Image1->Canvas->Polygon(vertices, 12);

  zero1=(Image1->Height - (sect->side - 2*sect->thickness)*scale)/2;
  zero=(Image1->Width - (sect->side - 2*sect->thickness)*scale)/2;

  s_c = (sect->side - 2*sect->thickness)*scale;
  r_c = (sect->rad - sect->thickness)*scale;
  r2_c = Round(r_c - r_c*cos(45/57.3), 0);

  vertices[0] = Point(zero, zero1 + r_c);
  vertices[1] = Point(zero, zero1 + s_c - r_c);
  vertices[2] = Point(zero + r2_c, zero1 + s_c - r2_c);
  vertices[3] = Point(zero + r_c, zero1 + s_c);
  vertices[4] = Point(zero + s_c - r_c, zero1 + s_c);
  vertices[5] = Point(zero + s_c - r2_c, zero1 + s_c - r2_c);
  vertices[6] = Point(zero + s_c, zero1 + s_c - r_c);
  vertices[7] = Point(zero + s_c, zero1 + r_c);
  vertices[8] = Point(zero + s_c - r2_c, zero1 + r2_c);
  vertices[9] = Point(zero + s_c - r_c, zero1);
  vertices[10] = Point(zero + r_c, zero1);
  vertices[11] = Point(zero + r2_c, zero1 + r2_c);
  vertices[12] = Point(zero, zero1 + r_c);

  Image1->Canvas->Brush->Color = clWhite;
  Image1->Canvas->Polygon(vertices, 12);

  draw_axes(Image1);

}//---------------------------------------------------------------------------
// рисование прямогольной трубы
void __fastcall TSteelSectionDefinitionFrame::draw_rect_tube(TImage * Image1, SECT_RECT *sect) {
  TPoint vertices[30];
  double zero, zero1;
  float scale;
  int rc;

  TRect NewRect = Rect(0, 0, Image1->Width,Image1->Height);
  Image1->Canvas->Brush->Color = clWhite;
  Image1->Canvas->FillRect(NewRect);
  Image1->Canvas->Rectangle(0, 0, Image1->Width,Image1->Height);

  scale=(Image1->Width-20)/(1e0*sect->b);
  scale=MIN(scale,(Image1->Height-20)/(1e0*sect->h));

  zero1=(Image1->Height - sect->h*scale)/2;
  zero=(Image1->Width - sect->b*scale)/2;

  vertices[0] = Point(zero, zero1);
  vertices[1] = Point(zero, zero1 + sect->h*scale);
  vertices[2] = Point(zero + sect->b*scale, zero1 + sect->h*scale);
  vertices[3] = Point(zero + sect->b*scale, zero1);
  vertices[4] = Point(zero, zero1);

  double h_c = sect->h*scale;
  double b_c = sect->b*scale;
  double r_c = sect->rad*scale;
  double r2_c = Round(r_c - r_c*cos(45/57.3), 0);

  vertices[0] = Point(zero, zero1 + r_c);
  vertices[1] = Point(zero, zero1 + h_c - r_c);
  vertices[2] = Point(zero + r2_c, zero1 + h_c - r2_c);
  vertices[3] = Point(zero + r_c, zero1 + h_c);
  vertices[4] = Point(zero + b_c - r_c, zero1 + h_c);
  vertices[5] = Point(zero + b_c - r2_c, zero1 + h_c - r2_c);
  vertices[6] = Point(zero + b_c, zero1 + h_c - r_c);
  vertices[7] = Point(zero + b_c, zero1 + r_c);
  vertices[8] = Point(zero + b_c - r2_c, zero1 + r2_c);
  vertices[9] = Point(zero + b_c - r_c, zero1);
  vertices[10] = Point(zero + r_c, zero1);
  vertices[11] = Point(zero + r2_c, zero1 + r2_c);
  vertices[12] = Point(zero, zero1 + r_c);

  Image1->Canvas->Brush->Color = COLOR;
  Image1->Canvas->Polygon(vertices, 12);

  zero1=(Image1->Height - (sect->h - 2*sect->h1)*scale)/2;
  zero=(Image1->Width - (sect->b - 2*sect->b1)*scale)/2;

  h_c = (sect->h - 2*sect->h1)*scale;
  b_c = (sect->b - 2*sect->b1)*scale;
  r_c = (sect->rad - sect->h1)*scale;
  r2_c = Round(r_c - r_c*cos(45/57.3), 0);

  /*
  vertices[0] = Point(zero + sect->b1*scale, zero1 + sect->h1*scale);
  vertices[1] = Point(zero + sect->b1*scale, zero1 + (sect->h - sect->h1)*scale);
  vertices[2] = Point(zero + (sect->b - sect->b1)*scale, zero1 + (sect->h - sect->h1)*scale);
  vertices[3] = Point(zero + (sect->b - sect->b1)*scale, zero1 + sect->h1*scale);
  vertices[4] = Point(zero + sect->b1*scale, zero1 + sect->h1*scale);
  */
  vertices[0] = Point(zero, zero1 + r_c);
  vertices[1] = Point(zero, zero1 + h_c - r_c);
  vertices[2] = Point(zero + r2_c, zero1 + h_c - r2_c);
  vertices[3] = Point(zero + r_c, zero1 + h_c);
  vertices[4] = Point(zero + b_c - r_c, zero1 + h_c);
  vertices[5] = Point(zero + b_c - r2_c, zero1 + h_c - r2_c);
  vertices[6] = Point(zero + b_c, zero1 + h_c - r_c);
  vertices[7] = Point(zero + b_c, zero1 + r_c);
  vertices[8] = Point(zero + b_c - r2_c, zero1 + r2_c);
  vertices[9] = Point(zero + b_c - r_c, zero1);
  vertices[10] = Point(zero + r_c, zero1);
  vertices[11] = Point(zero + r2_c, zero1 + r2_c);
  vertices[12] = Point(zero, zero1 + r_c);

  Image1->Canvas->Brush->Color = clWhite;
  Image1->Canvas->Polygon(vertices, 12);
  draw_axes(Image1);

}
//---------------------------------------------------------------------------
// рисование круглой трубы
void __fastcall TSteelSectionDefinitionFrame::draw_circular_tube(TImage * Image1, SECT_CIRC *sect) {
  double zero, zero1;
  float scale;
  int rc;

  TRect NewRect = Rect(0, 0, Image1->Width,Image1->Height);
  Image1->Canvas->Brush->Color = clWhite;
  Image1->Canvas->FillRect(NewRect);
  Image1->Canvas->Rectangle(0, 0, Image1->Width,Image1->Height);

  scale=(Image1->Width-20)/(1e0*sect->diameter);
  scale=MIN(scale,(Image1->Height-20)/(1e0*sect->diameter));

  zero=(Image1->Height - sect->diameter*scale)/2;
  zero1=(Image1->Width - sect->diameter*scale)/2;

  Image1->Canvas->Brush->Color = COLOR;
  Image1->Canvas->Ellipse(zero1, zero, zero1 + sect->diameter*scale, zero + sect->diameter*scale);

  Image1->Canvas->Brush->Color = clWhite;
  Image1->Canvas->Ellipse(zero1 + sect->thickness*scale, zero + sect->thickness*scale,
                          zero1 + (sect->diameter - sect->thickness)*scale, zero + (sect->diameter - sect->thickness)*scale);
  draw_axes(Image1);
}
//---------------------------------------------------------------------------
// Рисование системы координат
void  __fastcall TSteelSectionDefinitionFrame::draw_axes(TImage *Image_Ax) {

  draw_axes_zero(Image_Ax, Image_Ax->Width/2, Image_Ax->Height/2);
}
//---------------------------------------------------------------------------
// Рисование системы координат
void  __fastcall TSteelSectionDefinitionFrame::draw_axes_zero(TImage *Image_Ax, int x0, int y0) {
  TPoint points[10];
  //int zero, zero1,zero2;
  //float scale_1, scale;


  points[0]=Point(x0, y0);
  points[1]=Point(x0, y0 - 40);

  CoorAx.PutArrow(points, 0, MAX_PIC);
  CoorAx.SetArrow();

  Image_Ax->Canvas->Pen->Width=1;
  Image_Ax->Canvas->Polyline(CoorAx.LArrow, 2);
  Image_Ax->Canvas->Pen->Width=1;
  Image_Ax->Canvas->Brush->Color=clBlack;
  Image_Ax->Canvas->Polygon(CoorAx.Ar, 3);
  Image_Ax->Canvas->Brush->Color=clWhite;

  points[0]=Point(x0, y0);
  points[1]=Point(x0 + 40, y0);

  CoorAx.PutArrow(points, 0, MAX_PIC);
  CoorAx.SetArrow();

  Image_Ax->Canvas->Pen->Width=1;
  Image_Ax->Canvas->Polyline(CoorAx.LArrow, 2);
  Image_Ax->Canvas->Pen->Width=1;
  Image_Ax->Canvas->Brush->Color=clBlack;
  Image_Ax->Canvas->Polygon(CoorAx.Ar, 3);
  Image_Ax->Canvas->Brush->Color=clWhite;
  Image_Ax->Canvas->Ellipse(x0-4, y0-4, x0+4, y0+4);
  Image_Ax->Canvas->Brush->Style=bsClear;
  Image_Ax->Canvas->TextOut(x0+6, y0 - 40,"Y");
  Image_Ax->Canvas->TextOut(x0 + 40, y0-16,"X");
  Image_Ax->Canvas->Brush->Style=bsSolid;
}
//---------------------------------------------------------------------------
// Процедура настриивает frame по значению глобальной переменной типа int Type_sect
//---------------------------------------------------------------------------
void  __fastcall TSteelSectionDefinitionFrame::Check_Original() {

      TRect NewRect = Rect(0, 0, Image1->Width,
						   Image1->Height); //создали прямоугольник

      Image1->Canvas->Brush->Color = clWhite;
	  Image1->Canvas->FillRect(NewRect);//передали созданный прямоугольник для рисования
      Image1->Canvas->Rectangle(0, 0, Image1->Width,
						   Image1->Height); //нет ли дублирования предыдущего выражения?
      CheckBox1->Enabled=false;
      CheckBox1->Checked=true;

	  Edit1->Color=clWindow;  //зачем в контроле красить фон?
      Edit2->Color=clWindow;
      Edit3->Color=clWindow;
      Edit4->Color=clWindow;
      Edit5->Color=clWindow;
      Edit6->Color=clWindow;

	  Edit1->Text="0";  //Инициализация полей для ввода данных сварного сечения
      Edit2->Text="0";
      Edit3->Text="0";
	  Edit4->Text="0";
	  Edit5->Text="0";
	  Edit6->Text="0";

	  ComboBox_TypeSect->ItemIndex = Type_sect; //выставляется ComboBox по глобальной переменной

	  Button_Copy->Visible=false; //выключаем кнопку копировать

      switch (ComboBox_TypeSect->ItemIndex) {
        case NO_CHOISE:
          Label7->Visible=true;

          Label1->Visible=false;
          Label2->Visible=false;
          Label3->Visible=false;
          Label4->Visible=false;
		  Label5->Visible=false;
          Label6->Visible=false;

          Edit1->Visible=false;
          Edit2->Visible=false;
          Edit3->Visible=false;
          Edit4->Visible=false;
          Edit5->Visible=false;
          Edit6->Visible=false;
        break;
        case DVUTAVR:
         // TabSheet_Weld->Name = "Сварной двутавр";
		  Label7->Visible=false;

          Edit1->Visible=true;
          Edit2->Visible=true;
          Edit3->Visible=true;
          Edit4->Visible=true;
          Edit5->Visible=true;
          Edit6->Visible=true;

          Edit1->Enabled=true;
          Edit2->Enabled=true;
          Edit3->Enabled=true;
          Edit4->Enabled=true;
          Edit5->Enabled=true;
          Edit6->Enabled=true;

          Label1->Caption="Толщина стенки (b)";
          Label2->Caption="Высота стенки (h)";
          Label3->Caption="Ширина верхней полки (b1)";
          Label4->Caption="Толщина верхней полки (h1)";
          Label5->Caption="Ширина нижней полки (b2)";
          Label6->Caption="Толщина нижней полки (h2)";

          Label1->Visible=true;
          Label2->Visible=true;
          Label3->Visible=true;
          Label4->Visible=true;
          Label5->Visible=true;
		  Label6->Visible=true;
          /*
          if (flag_simm_sect) {
                Label3->Caption = "Ширина полки (b1)";
                Label4->Caption = "Толщина полки (h1)";
                Edit5->Visible = false;
                Edit6->Visible = false;
                Label5->Visible = false;
                Label6->Visible = false;
          }
          */
		  Button_Copy->Visible = TabSheet_Weld->TabVisible;
        break;
        case SQUARE_TUBE:
          //TabSheet_Weld->Name = "Квадратная труба";
          Label7->Visible=false;

          Edit1->Visible=true;
          Edit2->Visible=false;
          Edit3->Visible=true;
          Edit4->Visible=false;
          Edit5->Visible=false;
          Edit6->Visible=false;

          Edit1->Enabled=true;
          Edit3->Enabled=true;

          Label1->Caption="Толщина стенки (t)";
          Label3->Caption="Размер стороны (b)";

          Label1->Visible=true;
          Label2->Visible=false;
          Label3->Visible=true;
          Label4->Visible=false;
          Label5->Visible=false;
          Label6->Visible=false;
       break;
        case RECT_TUBE:
          //TabSheet_Weld->Name = "Прямоугольная труба";
          Label7->Visible=false;

          Edit1->Visible=true;
          Edit2->Visible=true;
          Edit3->Visible=true;
          Edit4->Visible=true;
          Edit5->Visible=false;
          Edit6->Visible=false;

          Edit1->Enabled=true;
          Edit2->Enabled=true;
          Edit3->Enabled=true;
		  Edit4->Enabled=true;

		  Label4->Caption="Высота сечения (h)";
		  Label3->Caption="Ширина сечения (b)";
		  Label1->Caption="Толщина стенок по Z1 (h1)";
		  Label2->Caption="Толщина стенок по Y1 (b1)";

          Label1->Visible=true;
		  Label2->Visible=true;
		  Label3->Visible=true;
		  Label4->Visible=true;
		  Label5->Visible=false;
          Label6->Visible=false;
        break;
        case CIRCULAR_TUBE:
          //TabSheet_Weld->Name = "Круглая труба";
          Label7->Visible=false;

          Edit1->Visible=true;
          Edit2->Visible=false;
          Edit3->Visible=true;
          Edit4->Visible=false;
          Edit5->Visible=false;
          Edit6->Visible=false;

		  Edit1->Enabled=true;
          Edit3->Enabled=true;

          Label1->Caption="Толщина стенки (t)";
          Label3->Caption="Диаметр (d)";

          Label1->Visible=true;
          Label2->Visible=false;
          Label3->Visible=true;
          Label4->Visible=false;
		  Label5->Visible=false; //Я не могу найти эти контроли на форме!!!!
          Label6->Visible=false;
        break;
		default://Что значит это ключевое слово?
        ;
      }
}
//---------------------------------------------------------------------------
//Процедура проверяет есть ли такой профиль
//---------------------------------------------------------------------------
void  __fastcall TSteelSectionDefinitionFrame::Check_Type(TObject *Sender) {


	  TabSheet_Weld->TabVisible = false;
	  TabSheet_Standart->TabVisible = false;
	  TabSheet_StandTube->TabVisible = false;
      TabSheet_CYL->TabVisible = false;

	  switch (ComboBox_TypeSect->ItemIndex) {
		case DVUTAVR:// условие смещено к ошибки, неверно лишнее действие в большинстве случаев
		  if (common_sect_.dvutavr.n_group<0) {//где присваивается n.group меньше 1
			TabSheet_Weld->TabVisible = true;// если ошибка отображается вкладка саврное сечение
          }
          else {
			TabSheet_Standart->TabVisible = true;
			PageControl1Change(Sender);
          }
          Button_Copy->Visible = TabSheet_Weld->TabVisible;
        break;
        case SQUARE_TUBE:
          if (common_sect_.square.n_group < 0) {
			TabSheet_Weld->TabVisible = true;
          }
          else {
            TabSheet_StandTube->TabVisible = true;
			SquareTube_Change(Sender);
          }
       break;
        case RECT_TUBE:
          if (common_sect_.rect.n_group < 0) {
			TabSheet_Weld->TabVisible = true;
          }
          else {
            TabSheet_StandTube->TabVisible = true;
			RectTube_Change(Sender);
          }
        break;
        case CIRCULAR_TUBE:
          if (common_sect_.circ.n_group < 0) {
            TabSheet_Weld->TabVisible = true;
          }
          else {
            TabSheet_CYL->TabVisible = true;
			CylTube_Change(Sender);
          }
        break;
        default:
        ;
      }
}
//--------------------------------------------------------------------------------
//
void  __fastcall TSteelSectionDefinitionFrame::Check_Modify() {

      TRect NewRect = Rect(0, 0, Image1->Width,
                           Image1->Height);

      Image1->Canvas->Brush->Color = clWhite;
      Image1->Canvas->FillRect(NewRect);
      Image1->Canvas->Rectangle(0, 0, Image1->Width,
                           Image1->Height);

      CheckBox1->Enabled=false;
      CheckBox1->Checked=true;
      DrawSect();
      flag_sect_change=true;

      Edit1->Color=clWindow;
      Edit2->Color=clWindow;
      Edit3->Color=clWindow;
      Edit4->Color=clWindow;
      Edit5->Color=clWindow;
      Edit6->Color=clWindow;
      Edit1->Enabled=true;
      Edit2->Enabled=true;
      Edit3->Enabled=true;
      Edit4->Enabled=true;
	  Edit5->Enabled=true;
      Edit6->Enabled=true;
      //if (flag_change_type_sect)  {
      //  ComboBox1->Enabled = true;
	  //  CheckBox_type_sect->Checked = true;
      //}


}
//---------------------------------------------------------------------------

void __fastcall TSteelSectionDefinitionFrame::CheckChangeSect()
{
//  Проверка - изменено ли сечение
	int i;
	TObject *Sender;

	if (flag_sect_change==true) {
        // запрос на сохранение
		text="Параметры сечения были изменены. Применить ?";
		header="";
		i=Application->MessageBox(text.c_str(),
                  header.c_str(),
                  MB_YESNO | MB_ICONQUESTION);
        if (i==IDYES) Button_ApplyClick(Sender);
	}
}
// Изменение состояния CheckBox

void __fastcall TSteelSectionDefinitionFrame::CheckBox1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
       Check_Modify();
}
//---------------------------------------------------------------------------
void __fastcall TSteelSectionDefinitionFrame::Edit1_Change(TObject *Sender) {
  flag_sect_change=true;  //изменение любого поля для ввода параметров сварного сечения
  //устанавливает глобальную переменную типа bool в true
}
//---------------------------------------------------------------------------

void __fastcall TSteelSectionDefinitionFrame::Edit2_Change(TObject *Sender) {
  flag_sect_change=true;
}
//---------------------------------------------------------------------------

void __fastcall TSteelSectionDefinitionFrame::Edit3_Change(TObject *Sender) {
  flag_sect_change=true;
}
//---------------------------------------------------------------------------

void __fastcall TSteelSectionDefinitionFrame::Edit4_Change(TObject *Sender) {
  flag_sect_change=true;
}
//---------------------------------------------------------------------------

void __fastcall TSteelSectionDefinitionFrame::Edit5_Change(TObject *Sender)
{
  flag_sect_change=true;
}
//---------------------------------------------------------------------------
void __fastcall TSteelSectionDefinitionFrame::Edit6_Change(TObject *Sender)
{
  flag_sect_change=true;
}
//---------------------------------------------------------------------------

void __fastcall TSteelSectionDefinitionFrame::Button_ApplyClick(TObject *Sender)
{
   int rc;

   if (Type_sect==DVUTAVR) {
	  // Установить тип стандартного сечения
	  if (PageControl1->ActivePage == TabSheet_GOST57837)
		  common_sect_.dvutavr.n_group = RadioGroupGOST57837->ItemIndex + typeGOST_G57837_B;
	  if (PageControl1->ActivePage == TabSheet_GOST)
		  common_sect_.dvutavr.n_group = RadioGroup_GOST->ItemIndex;
	  if (PageControl1->ActivePage == TabSheet_STO)
		  common_sect_.dvutavr.n_group = RadioGroup_STO->ItemIndex + typeSTO_B;
	  // Установить тип стандартного сечения
	  StandartProfil.SetProfil(common_sect_.dvutavr.n_group);
	  // Заполнить структуру профиля двутавра
	  rc = StandartProfil.SetParamProfil(&(common_sect_.dvutavr), ComboBox_profil->ItemIndex);
	  if (rc >0) return;
   }
   return;
}
//---------------------------------------------------------------------------
void __fastcall TSteelSectionDefinitionFrame::ComboBox_TypeSectChange(TObject *Sender)
{
	if (Type_sect != ComboBox_TypeSect->ItemIndex && common_sect_.dvutavr.n_group >=0 ) {
	  // Преобразовать группу сечений из одного типа в другой

		  /*
		  switch (ComboBox_TypeSect->ItemIndex) {
			   case 1: */
                  common_sect_.dvutavr.n_group = 0;
				  common_sect_.dvutavr.n_profil = 5;
			/*    break;
                case 2:
         		 common_sect_.square.n_group = 10;
                  common_sect_.square.n_profil = 5;
                break;
         	   case 3:
         		 common_sect_.rect.n_group = 10;
         		 common_sect_.rect.n_profil = 5;
                break;
                case 4:
                  common_sect_.circ.n_group = 10;
         		 common_sect_.circ.n_profil = 5;
                break;
			   }
     */   }
    Type_sect = ComboBox_TypeSect->ItemIndex;
    Check_Original();
	Check_Type(Sender);

}
//---------------------------------------------------------------------------

void __fastcall TSteelSectionDefinitionFrame::Edit3Enter(TObject *Sender)
{
     Edit5->Text = Edit3->Text;    
}
//---------------------------------------------------------------------------

void __fastcall TSteelSectionDefinitionFrame::Edit3Exit(TObject *Sender)
{
      Edit5->Text = Edit3->Text;
}
//---------------------------------------------------------------------------

void __fastcall TSteelSectionDefinitionFrame::Edit3Change(TObject *Sender)
{
  flag_sect_change=true;
  Edit5->Text = Edit3->Text;

}
//---------------------------------------------------------------------------

void __fastcall TSteelSectionDefinitionFrame::Edit3KeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
   if (Key == VK_RETURN) Edit4->SetFocus();

}
//---------------------------------------------------------------------------

void __fastcall TSteelSectionDefinitionFrame::Edit4KeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
   if (Key == VK_RETURN) Edit2->SetFocus();
}
//---------------------------------------------------------------------------


void __fastcall TSteelSectionDefinitionFrame::Edit2KeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
   if (Key == VK_RETURN) Edit1->SetFocus();

}
//---------------------------------------------------------------------------

void __fastcall TSteelSectionDefinitionFrame::Edit1KeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
   if (Key == VK_RETURN) Edit5->SetFocus();

}
//---------------------------------------------------------------------------

void __fastcall TSteelSectionDefinitionFrame::Edit5KeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
   if (Key == VK_RETURN) Edit6->SetFocus();

}
//---------------------------------------------------------------------------

void __fastcall TSteelSectionDefinitionFrame::Edit6KeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
   if (Key == VK_RETURN) Edit3->SetFocus();

}
//---------------------------------------------------------------
// Заполнение списка профилей  ГОСТ
void __fastcall TSteelSectionDefinitionFrame::RadioGroup_GOSTClick(TObject *Sender)
{
   AnsiString *NameProfil;
   int n_profil, i;


   // Установить тип стандартного сечения
   StandartProfil.SetProfil(RadioGroup_GOST->ItemIndex);
   // Получить вектор имен профилей и длину вектора
   NameProfil = StandartProfil.GetVectorNameProfil(&n_profil);

   ComboBox_profil->Items->Clear();
   for (i=0; i<n_profil; i++) {
	  ComboBox_profil->Items->Add(NameProfil[i]);
   }
   ComboBox_profil->ItemIndex = StandartProfil.Get_NumberProfil(&(common_sect_.dvutavr), 0);
   ComboBox_profilChange(Sender);

}
//---------------------------------------------------------------------------
void __fastcall TSteelSectionDefinitionFrame::Change_type_sect(int index_profil, TObject *Sender)
{
    if (index_profil < 0) {
       TabSheet_Weld->TabVisible = true;
       TabSheet_Standart->TabVisible = false;
       //Image1->Visible = true;
       Weld_Change(Sender);
    }
    else {
       TabSheet_Weld->TabVisible = false;
	   TabSheet_Standart->TabVisible = true;
       //Image1->Visible = false;
       if (index_profil  < typeSTO_B)
          RadioGroup_GOSTClick(Sender);
       if (index_profil  >= typeSTO_B && index_profil <=typeSTO_K)
          RadioGroup_STOClick(Sender);
       if (index_profil >=typeGOST_G57837_B && index_profil <=typeGOST_G57837_S)
          RadioGroupGOST57837Click(Sender);
    }
}
//---------------------------------------------------------------------------
void __fastcall TSteelSectionDefinitionFrame::Change_type_sect_tube(int index_profil, TObject *Sender)
{
    if (index_profil < 0) {
       TabSheet_Weld->TabVisible = true;
       TabSheet_Standart->TabVisible = false;
       TabSheet_StandTube->TabVisible = false;
       Weld_Change(Sender);
    }
    else {
       TabSheet_Weld->TabVisible = false;
       TabSheet_Standart->TabVisible = false;
       if (index_profil != typeCIRC) {
         TabSheet_StandTube->TabVisible = true;
         TabSheet_CYL->TabVisible = false;
       }  
       else {
         TabSheet_StandTube->TabVisible = false;
         TabSheet_CYL->TabVisible = true;
       }

    }
}
//---------------------------------------------------------------------------

void __fastcall TSteelSectionDefinitionFrame::ComboBox_profilChange(TObject *Sender)
{
       double * ParamProfil;
       ParamProfil = StandartProfil.GetVectorParamProfil(ComboBox_profil->ItemIndex);          //ComboBox_profil->Items
	   StringGrid_B->Cells[1][0]=FloatToStr(ParamProfil[parHSECT]);
       StringGrid_B->Cells[1][1]=FloatToStr(ParamProfil[parBF]);
       StringGrid_B->Cells[1][2]=FloatToStr(ParamProfil[parTW]);
       StringGrid_B->Cells[1][3]=FloatToStr(ParamProfil[parTF]);
       StringGrid_B->Cells[1][4]=FloatToStrF(ParamProfil[parAREA]/100, ffFixed, 6, 0);
       StringGrid_B->Cells[1][5]=FloatToStrF(ParamProfil[parIZZ]/10000, ffFixed, 6, 0);
       StringGrid_B->Cells[1][6]=FloatToStrF(ParamProfil[parIRADZ], ffFixed, 6, 1);

       DrawSect();

}
//---------------------------------------------------------------------------
void __fastcall TSteelSectionDefinitionFrame::Weld_Change(TObject *Sender)
{
            Label3->Caption="Ширина верхней полки (b1)";
            Label4->Caption="Толщина верхней полки (h1)";
            Label1->Caption="Толщина стенки (b)";
            Label2->Caption="Высота стенки (h)";
            Label5->Caption="Ширина нижней полки (b2)";
            Label6->Caption="Толщина нижней полки (h2)";
            Edit3->Text=FloatToStrF(common_sect_.dvutavr.b1,ffFixed,15,1);
            Edit4->Text=FloatToStrF(common_sect_.dvutavr.h1,ffFixed,15,0);
            Edit1->Text=FloatToStrF(common_sect_.dvutavr.b,ffFixed,15,0);
            Edit2->Text=FloatToStrF(common_sect_.dvutavr.h,ffFixed,15,0);
            Edit5->Text=FloatToStrF(common_sect_.dvutavr.b2,ffFixed,15,0);
            Edit6->Text=FloatToStrF(common_sect_.dvutavr.h2,ffFixed,15,0);
}
//---------------------------------------------------------------------------


void __fastcall TSteelSectionDefinitionFrame::PageControl1Change(TObject *Sender)
{
    if (PageControl1->ActivePage == TabSheet_GOST57837) {
       RadioGroupGOST57837Click(Sender);
    }
    if (PageControl1->ActivePage == TabSheet_GOST) {
       switch(RadioGroup_STO->ItemIndex + typeSTO_B) {
       case typeSTO_B:
         RadioGroup_GOST->ItemIndex = typeGOST_B;
       break;
       case typeSTO_Width:
         RadioGroup_GOST->ItemIndex = typeGOST_Width;
       break;
       case typeSTO_K:
         RadioGroup_GOST->ItemIndex = typeGOST_K;
       break;
       }
       RadioGroup_GOSTClick(Sender);
    }
    if (PageControl1->ActivePage == TabSheet_STO) {
       switch(RadioGroup_GOST->ItemIndex) {
       case typeGOST_0:
       case typeGOST_B:
       case typeGOST_DB:
         RadioGroup_STO->ItemIndex = 0;
       break;
       case typeGOST_Width:
         RadioGroup_STO->ItemIndex = typeSTO_Width - typeSTO_B;
       break;
       case typeGOST_K:
         RadioGroup_STO->ItemIndex = typeSTO_K - typeSTO_B;
       break;
       }
       RadioGroup_STOClick(Sender);
    }
}
//---------------------------------------------------------------
// Заполнение списка профилей  СТО
void __fastcall TSteelSectionDefinitionFrame::RadioGroup_STOClick(TObject *Sender)
{
   AnsiString *NameProfil;
   int n_profil, i;

   // Установить тип стандартного сечения (константа typeSTO_B определяет сдвиг относительно сечений ГОСТ)
   StandartProfil.SetProfil(RadioGroup_STO->ItemIndex + typeSTO_B);
   // Получить вектор имен профилей и длину вектора
   NameProfil = StandartProfil.GetVectorNameProfil(&n_profil);

   ComboBox_profil->Items->Clear();
   for (i=0; i<n_profil; i++) {
      ComboBox_profil->Items->Add(NameProfil[i]);
   }
   ComboBox_profil->ItemIndex = StandartProfil.Get_NumberProfil(&(common_sect_.dvutavr), 0);
   ComboBox_profilChange(Sender);
        
}
//---------------------------------------------------------------------------


void __fastcall TSteelSectionDefinitionFrame::PageControl2Change(TObject *Sender)
{
     Button_Copy->Visible = TabSheet_Weld->TabVisible;

}
//---------------------------------------------------------------------------

void __fastcall TSteelSectionDefinitionFrame::RadioGroup_orientClick(TObject *Sender)
{
   double h0, b0;
   b0 = common_sect_.rect.b;
   h0 = common_sect_.rect.h;

   if (RadioGroup_orient->ItemIndex==0) {
     common_sect_.rect.b = MIN(b0, h0);
     common_sect_.rect.h = MAX(b0, h0);
   }
   else {
     common_sect_.rect.b = MAX(b0, h0);
     common_sect_.rect.h = MIN(b0, h0);
   }

   DrawSect();

}
//---------------------------------------------------------------------------
void __fastcall TSteelSectionDefinitionFrame::Put_h_rect(TObject *Sender)
{
   int i;
   AnsiString *NameProfil;
   int num_profil;
   double h0;

   h0 = 0;
  // StandartProfil.SetProfil_Tube(typeRECT);   // typeSQUARE
   // Получить вектор имен профилей и длину вектора
   NameProfil = StandartProfil.GetVectorNameProfil(&num_profil);   // количество профилей

   for (i=0; i<num_profil; i++) {
     //if (h0 <
   }

}

void __fastcall TSteelSectionDefinitionFrame::ComboBox_h_b_rectChange(
      TObject *Sender)
{
	        /*
           double * ParamProfil;
          	   int i, rc;
          	   double *thick;
                 int num_thick;

          	   int index = MAX(0, ComboBox_h_b_rect->ItemIndex);

          	 //  ParamProfil = StandartProfil.GetVectorParamProfil_Tube(index, common_sect_.square.n_profil);
          	 //  thick = StandartProfil.GetVectorParamThickness_Tube(index, &num_thick);

          	   if (thick == NULL || ParamProfil == NULL) {
          		  #ifdef EMBRAC
          			rc=Application->MessageBox(L"Программная ошибка в SetCom_Param: несуществующий профиль", L" ", MB_OK | MB_ICONERROR);
          		  #else
          			rc=Application->MessageBox("Программная ошибка в SetCom_Param: несуществующий профиль", " ", MB_OK | MB_ICONERROR);
          		  #endif
          		 return;
                 }
                 // Заполнение StringGrid_Tube rect
          	   StringGrid_Tube->Cells[1][0]=FloatToStr(ParamProfil[parHSECT]);
                 StringGrid_Tube->Cells[1][1]=FloatToStr(ParamProfil[parBSECT]);
                 StringGrid_Tube->Cells[1][2]=FloatToStr(ParamProfil[parT_RECT_TUBE]);
                 StringGrid_Tube->Cells[1][3]=FloatToStr(ParamProfil[parAREA_RECT_TUBE]/100);
                 StringGrid_Tube->Cells[1][4]=FloatToStr(ParamProfil[parIZZ_RECT_TUBE]/10000);
                 StringGrid_Tube->Cells[1][5]=FloatToStr(ParamProfil[parIYY_RECT_TUBE]/10000);

                 ComboBox_t_rect->Items->Clear();
                 for (i=0; i<num_thick; i++) {
                   ComboBox_t_rect->Items->Add(FloatToStr(thick[i]));
          	   }
                 ComboBox_t_rect->ItemIndex = common_sect_.square.n_profil;
				 RadioGroup_orientClick(Sender);
      */
}
//---------------------------------------------------------------------------

void __fastcall TSteelSectionDefinitionFrame::ComboBox_t_rectChange(TObject *Sender)
{
		  /*
		   double * ParamProfil;

         	   int i, rc;

         	  // ParamProfil = StandartProfil.GetVectorParamProfil_Tube(ComboBox_h_b_rect->ItemIndex, ComboBox_t_rect->ItemIndex);
         	   // Заполнение StringGrid_Tube rect
         	   StringGrid_Tube->Cells[1][0]=FloatToStr(ParamProfil[parHSECT]);
         	   StringGrid_Tube->Cells[1][1]=FloatToStr(ParamProfil[parBSECT]);
         	   StringGrid_Tube->Cells[1][2]=FloatToStr(ParamProfil[parT_RECT_TUBE]);
         	   StringGrid_Tube->Cells[1][3]=FloatToStr(ParamProfil[parAREA_RECT_TUBE]/100);
                StringGrid_Tube->Cells[1][4]=FloatToStr(ParamProfil[parIZZ_RECT_TUBE]/10000);
                StringGrid_Tube->Cells[1][5]=FloatToStr(ParamProfil[parIYY_RECT_TUBE]/10000);

			   RadioGroup_orientClick(Sender);
     */

}
//---------------------------------------------------------------------------
void __fastcall TSteelSectionDefinitionFrame::ComboBox_h_b_squareChange(
	  TObject *Sender)
{
	          /*
           double * ParamProfil;
           	   int i, rc;
           	   double *thick;
           	   int num_thick;

           	   int index = MAX(0, ComboBox_h_b_square->ItemIndex);

           	  // ParamProfil = StandartProfil.GetVectorParamProfil_Tube(index, common_sect_.square.n_profil);
           	  // thick = StandartProfil.GetVectorParamThickness_Tube(index, &num_thick);
           	   if (thick == NULL || ParamProfil == NULL) {
           		 #ifdef EMBRAC
           		 rc=Application->MessageBox(L"Программная ошибка в SetCom_Param: несуществующий профиль", L" ", MB_OK | MB_ICONERROR);
           		 #else
           		 rc=Application->MessageBox("Программная ошибка в SetCom_Param: несуществующий профиль", " ", MB_OK | MB_ICONERROR);
           		 #endif
           		 return;
           	   }
           	   // Заполнение StringGrid_Tube square
           	   StringGrid_Tube->Cells[1][0]=FloatToStr(ParamProfil[parHSECT]);
           	   StringGrid_Tube->Cells[1][1]=FloatToStr(ParamProfil[parBSECT]);
           	   StringGrid_Tube->Cells[1][2]=FloatToStr(ParamProfil[parT_SQUARE_TUBE]);
           	   StringGrid_Tube->Cells[1][3]=FloatToStr(ParamProfil[parAREA_SQUARE_TUBE]/100);
           	   StringGrid_Tube->Cells[1][4]=FloatToStr(ParamProfil[parIYY_SQUARE_TUBE]/10000);
           	   StringGrid_Tube->Cells[1][5]=FloatToStr(ParamProfil[parIYY_SQUARE_TUBE]/10000);

           	   ComboBox_t_square->Items->Clear();
           	   for (i=0; i<num_thick; i++) {
           		 ComboBox_t_square->Items->Add(FloatToStr(thick[i]));
           	   }
                  ComboBox_t_square->ItemIndex = common_sect_.square.n_profil;

				  DrawSect();

       */
}
//---------------------------------------------------------------------------

void __fastcall TSteelSectionDefinitionFrame::ComboBox_t_squareChange(
	  TObject *Sender)
{
			/*
           double * ParamProfil;

			   int i, rc;

          	  // ParamProfil = StandartProfil.GetVectorParamProfil_Tube(ComboBox_h_b_square->ItemIndex, ComboBox_t_square->ItemIndex);
          	   // Заполнение StringGrid_Tube square
          	   StringGrid_Tube->Cells[1][0]=FloatToStr(ParamProfil[parHSECT]);
          	   StringGrid_Tube->Cells[1][1]=FloatToStr(ParamProfil[parBSECT]);
          	   StringGrid_Tube->Cells[1][2]=FloatToStr(ParamProfil[parT_SQUARE_TUBE]);
                 StringGrid_Tube->Cells[1][3]=FloatToStr(ParamProfil[parAREA_SQUARE_TUBE]/100);
                 StringGrid_Tube->Cells[1][4]=FloatToStr(ParamProfil[parIYY_SQUARE_TUBE]/10000);
          	   StringGrid_Tube->Cells[1][5]=FloatToStr(ParamProfil[parIYY_SQUARE_TUBE]/10000);
			   DrawSect();
      */
}
//---------------------------------------------------------------------------

void __fastcall TSteelSectionDefinitionFrame::CheckBox_type_sectClick(
      TObject *Sender)
{
    if (CheckBox_type_sect->Checked) {
       ComboBox_TypeSect->Enabled = true;
    }

}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void __fastcall TSteelSectionDefinitionFrame::SquareTube_Change(TObject *Sender)
{
    /*
      AnsiString* NameProfil;
        int i, n_profil;
      		   // Установить тип профиля - квадратная труба
      		  //  StandartProfil.SetProfil_Tube(typeSQUARE);
                  Change_type_sect_tube(typeSQUARE, Sender);
      		 // Получить вектор имен профилей и длину вектора
      			NameProfil = StandartProfil.GetVectorNameProfil(&n_profil);

      			if (ComboBox_h_b_square->ItemIndex <0)  {
      			  ComboBox_h_b_square->Items->Clear();
                    for (i=0; i<n_profil; i++) {
                      ComboBox_h_b_square->Items->Add(NameProfil[i]);
                    }
      			  ComboBox_h_b_square->ItemIndex = 0;
                    ComboBox_h_b_squareChange(Sender);   // здесь устанавливается список ComboBox_t_square и ComboBox_t_square->ItemIndex = 0
      			}
      			ComboBox_t_squareChange(Sender);
				TabSheet_Rect->TabVisible = false;
				TabSheet_Square->TabVisible = true;
  */
}
//---------------------------------------------------------------------------
void __fastcall TSteelSectionDefinitionFrame::RectTube_Change(TObject *Sender)
{
    /*
      AnsiString* NameProfil;
        int i, n_profil;
      		   // Установить тип профиля - прямоугольная труба
      		   // StandartProfil.SetProfil_Tube(typeRECT);
                  Change_type_sect_tube(typeRECT, Sender);
               // Получить вектор имен профилей и длину вектора
      			NameProfil = StandartProfil.GetVectorNameProfil(&n_profil);

      			if (ComboBox_h_b_rect->ItemIndex <0) {
      			  ComboBox_h_b_rect->Items->Clear();
                    for (i=0; i<n_profil; i++) {
      				ComboBox_h_b_rect->Items->Add(NameProfil[i]);
                    }
      			  ComboBox_h_b_rect->ItemIndex = 0;
      			  ComboBox_h_b_rectChange(Sender);
      			}
      			ComboBox_t_rectChange(Sender);
      			TabSheet_Rect->TabVisible = true;
				  TabSheet_Square->TabVisible = false;



------------------------------------------------------------------------- */
}
void __fastcall TSteelSectionDefinitionFrame::CylTube_Change(TObject *Sender)
{
    /*
      AnsiString* NameProfil;
        int i, n_profil;
			   // Установить тип профиля - круглая труба
      		   //	StandartProfil.SetProfil_Tube(typeCIRC);
      			Change_type_sect_tube(typeCIRC, Sender);
               // Получить вектор имен профилей и длину вектора
                  NameProfil = StandartProfil.GetVectorNameProfil(&n_profil);

      			if (ComboBox_Cyl_D->ItemIndex <0) {
      			  ComboBox_Cyl_D->Items->Clear();
                    for (i=0; i<n_profil; i++) {
      				ComboBox_Cyl_D->Items->Add(NameProfil[i]);
      			  }
      			  ComboBox_Cyl_D->ItemIndex = 0;
      			  ComboBox_Cyl_DChange(Sender);
				}
				ComboBox_Cyl_tChange(Sender);
  */
}
// Заполнить список профилей
void __fastcall TSteelSectionDefinitionFrame::FillComboBox1(TObject *Sender)
{
  ComboBox_TypeSect->Items->Clear();
  ComboBox_TypeSect->Items->Add("0. Тип не выбран");
  ComboBox_TypeSect->Items->Add("1. Двутавр");
  ComboBox_TypeSect->Items->Add("2. Труба квадратная");
  ComboBox_TypeSect->Items->Add("3. Труба прямоугольная");
  ComboBox_TypeSect->Items->Add("4. Труба круглая");

}
//---------------------------------------------------------------
// Заполнение списка профилей GOST_G57837
void __fastcall TSteelSectionDefinitionFrame::RadioGroupGOST57837Click(
      TObject *Sender)
{
   AnsiString *NameProfil;
   int n_profil, i;

   // Установить тип стандартного сечения
   StandartProfil.SetProfil(RadioGroupGOST57837->ItemIndex + typeGOST_G57837_B);
   // Получить вектор имен профилей и длину вектора
   NameProfil = StandartProfil.GetVectorNameProfil(&n_profil);

   ComboBox_profil->Items->Clear();
   for (i=0; i<n_profil; i++) {
      ComboBox_profil->Items->Add(NameProfil[i]);
   }
   ComboBox_profil->ItemIndex = StandartProfil.Get_NumberProfil(&(common_sect_.dvutavr), 0);
   ComboBox_profilChange(Sender);
   PageControl1->ActivePage = TabSheet_GOST57837;
}
//---------------------------------------------------------------------------

void __fastcall TSteelSectionDefinitionFrame::ComboBox_Cyl_DChange(
      TObject *Sender)
{
            /*
           double * ParamProfil;
                 int i, rc;
                 double *thick;
                 int num_thick;

                 int index = MAX(0, ComboBox_Cyl_D->ItemIndex);

          	 //  ParamProfil = StandartProfil.GetVectorParamProfil_Tube(index, common_sect_.square.n_profil);
          	//   thick = StandartProfil.GetVectorParamThickness_Tube(index, &num_thick);

                 if (thick == NULL || ParamProfil == NULL) {
          		 #ifdef EMBRAC
          		 rc=Application->MessageBox(L"Программная ошибка в SetCom_Param: несуществующий профиль", L" ", MB_OK | MB_ICONERROR);
          		 #else
          		 rc=Application->MessageBox("Программная ошибка в SetCom_Param: несуществующий профиль", " ", MB_OK | MB_ICONERROR);
          		 #endif
          		 return;
                 }
                 StringGrid_Cyl->Cells[1][0]=FloatToStr(ParamProfil[parDCIRC]);
                 StringGrid_Cyl->Cells[1][1]=FloatToStr(ParamProfil[parTCIRC]);
                 StringGrid_Cyl->Cells[1][2]=FloatToStr(ParamProfil[parAREA_CIRC_TUBE]/100);
                 StringGrid_Cyl->Cells[1][3]=FloatToStr(ParamProfil[parIYY_CIRC_TUBE]/10000);
                 StringGrid_Cyl->Cells[1][4]=FloatToStr(ParamProfil[parWY_CIRC_TUBE]/1000);

                 ComboBox_Cyl_t->Items->Clear();
                 for (i=0; i<num_thick; i++) {
                   ComboBox_Cyl_t->Items->Add(FloatToStr(thick[i]));
                 }
                 ComboBox_Cyl_t->ItemIndex = common_sect_.square.n_profil;

			   DrawSect();
      */
}
//---------------------------------------------------------------------------

void __fastcall TSteelSectionDefinitionFrame::ComboBox_Cyl_tChange(
      TObject *Sender)
{
	        /*
           double * ParamProfil;

                 int i, rc;

          	 //  ParamProfil = StandartProfil.GetVectorParamProfil_Tube(ComboBox_Cyl_D->ItemIndex, ComboBox_Cyl_t->ItemIndex);
          	   StringGrid_Cyl->Cells[1][0]=FloatToStr(ParamProfil[parDCIRC]);
          	   StringGrid_Cyl->Cells[1][1]=FloatToStr(ParamProfil[parTCIRC]);
          	   StringGrid_Cyl->Cells[1][2]=FloatToStr(ParamProfil[parAREA_CIRC_TUBE]/100);
          	   StringGrid_Cyl->Cells[1][3]=FloatToStr(ParamProfil[parIYY_CIRC_TUBE]/10000);
          	   StringGrid_Cyl->Cells[1][4]=FloatToStr(ParamProfil[parWY_CIRC_TUBE]/1000);

          	   common_sect_.square.n_profil = ComboBox_Cyl_t->ItemIndex;



      */
}
//---------------------------------------------------------------------------

