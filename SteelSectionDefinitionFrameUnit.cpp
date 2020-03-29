//---------------------------------------------------------------------------

#include <vcl.h>
#include <math.h>
#pragma hdrstop


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


extern bool flag_sect_change; // флаг изменения параметров сечения
extern int  Type_sect;   // Тип сечения - Двутавр или труба
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

	 StringGrid_B->Cells[0][0]="h (мм)";     //Двутавр
     StringGrid_B->Cells[0][1]="bf (мм)";
     StringGrid_B->Cells[0][2]="tw (мм)";
	 StringGrid_B->Cells[0][3]="tf (мм)";
	 StringGrid_B->Cells[0][4]="A (cм2)";
     StringGrid_B->Cells[0][5]="Iyy (cм4)";
	 StringGrid_B->Cells[0][6]="iy (мм)";


   Type_sect = DVUTAVR;

	 ComboBox_profil->ItemIndex=49;// 70Б4 сечение по умолчанию

	 fill_I_section_data();

}

//-------------------------------------------------------------------------
int __fastcall TSteelSectionDefinitionFrame::Read_sect() {

   int rc;
   double ss;
   double * ParamProfil;//указатель на строку с данными профиля


	//*type_sect_currently = Type_sect;
	switch (Type_sect) {
	case DVUTAVR:
	  common_sect_.dvutavr.flag_concl=false;//расшифровка имени flag_conclusion (чтение не завершено)
	  if (common_sect_.dvutavr.n_group < 0) {//значит сварной двутавр
		 return 1;    // задан не прокатной двутавр
	  }
	  else {      // стандартное сечение (прокатные сеченния из сортамент)
		common_sect_.dvutavr.n_group = RadioGroupGOST57837->ItemIndex + typeGOST_G57837_B;
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
	default:
	  return 3;  // Задано не двутавровое сечение
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
	   draw_dvutavr(Image_stand, &(common_sect_.dvutavr));
    break;
	default:
	;
  }

}
//----------------------------------------------------------------------
// рисование двутавра
void __fastcall TSteelSectionDefinitionFrame::draw_dvutavr(TImage * Image_stand, SECT_DVUTAVR *sect) {
  TPoint vertices[30];
  int zero, zero1, zero2;
  float scale_1, scale;
  int rc; //return code в функции не встречается!!! Х


  if (sect->n_group < 0) {
    TRect NewRect = Rect(0, 0, Image_stand->Width,Image_stand->Height);
    Image_stand->Canvas->Brush->Color = clWhite;
    Image_stand->Canvas->FillRect(NewRect);
    Image_stand->Canvas->Rectangle(0, 0, Image_stand->Width,Image_stand->Height);

    scale=(Image_stand->Width-20)/(1e0*sect->b2);
    scale_1=MIN(scale,(Image_stand->Width-20)/(1e0*sect->b1));
    scale=MIN(scale_1,(Image_stand->Height-20)/(1e0*(sect->h + sect->h1 + sect->h2)));

    zero=(Image_stand->Height - (sect->h + sect->h1 + sect->h2)*scale)/2;
    zero1=(Image_stand->Width - sect->b2*scale)/2;
    zero2=(Image_stand->Width - sect->b1*scale)/2;

    Point_dvutavr(zero, zero1, zero2, sect, scale, vertices); // получить точки контура двутавра

    Image_stand->Canvas->Brush->Color = COLOR;
    Image_stand->Canvas->Polygon(vertices, 12);
    Image_stand->Canvas->Brush->Color = clWhite;
    draw_axes(Image_stand);
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
void __fastcall TSteelSectionDefinitionFrame::draw_square_tube(TImage * Image_stand, SECT_SQUARE *sect) {
  TPoint vertices[30];
  double zero, zero1;
  float scale;
  int rc;

  TRect NewRect = Rect(0, 0, Image_stand->Width,Image_stand->Height);
  Image_stand->Canvas->Brush->Color = clWhite;
  Image_stand->Canvas->FillRect(NewRect);
  Image_stand->Canvas->Rectangle(0, 0, Image_stand->Width,Image_stand->Height);

  scale=(Image_stand->Width-20)/(1e0*sect->side);
  scale=MIN(scale,(Image_stand->Height-20)/(1e0*sect->side));

  zero1=(Image_stand->Height - sect->side*scale)/2;
  zero=(Image_stand->Width - sect->side*scale)/2;


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

  Image_stand->Canvas->Brush->Color = COLOR;
  Image_stand->Canvas->Polygon(vertices, 12);

  zero1=(Image_stand->Height - (sect->side - 2*sect->thickness)*scale)/2;
  zero=(Image_stand->Width - (sect->side - 2*sect->thickness)*scale)/2;

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

  Image_stand->Canvas->Brush->Color = clWhite;
  Image_stand->Canvas->Polygon(vertices, 12);

  draw_axes(Image_stand);

}//---------------------------------------------------------------------------
// рисование прямогольной трубы
void __fastcall TSteelSectionDefinitionFrame::draw_rect_tube(TImage * Image_stand, SECT_RECT *sect) {
  TPoint vertices[30];
  double zero, zero1;
  float scale;
  int rc;

  TRect NewRect = Rect(0, 0, Image_stand->Width,Image_stand->Height);
  Image_stand->Canvas->Brush->Color = clWhite;
  Image_stand->Canvas->FillRect(NewRect);
  Image_stand->Canvas->Rectangle(0, 0, Image_stand->Width,Image_stand->Height);

  scale=(Image_stand->Width-20)/(1e0*sect->b);
  scale=MIN(scale,(Image_stand->Height-20)/(1e0*sect->h));

  zero1=(Image_stand->Height - sect->h*scale)/2;
  zero=(Image_stand->Width - sect->b*scale)/2;

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

  Image_stand->Canvas->Brush->Color = COLOR;
  Image_stand->Canvas->Polygon(vertices, 12);

  zero1=(Image_stand->Height - (sect->h - 2*sect->h1)*scale)/2;
  zero=(Image_stand->Width - (sect->b - 2*sect->b1)*scale)/2;

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

  Image_stand->Canvas->Brush->Color = clWhite;
  Image_stand->Canvas->Polygon(vertices, 12);
  draw_axes(Image_stand);

}
//---------------------------------------------------------------------------
// рисование круглой трубы
void __fastcall TSteelSectionDefinitionFrame::draw_circular_tube(TImage * Image_stand, SECT_CIRC *sect) {
  double zero, zero1;
  float scale;
  int rc;

  TRect NewRect = Rect(0, 0, Image_stand->Width,Image_stand->Height);
  Image_stand->Canvas->Brush->Color = clWhite;
  Image_stand->Canvas->FillRect(NewRect);
  Image_stand->Canvas->Rectangle(0, 0, Image_stand->Width,Image_stand->Height);

  scale=(Image_stand->Width-20)/(1e0*sect->diameter);
  scale=MIN(scale,(Image_stand->Height-20)/(1e0*sect->diameter));

  zero=(Image_stand->Height - sect->diameter*scale)/2;
  zero1=(Image_stand->Width - sect->diameter*scale)/2;

  Image_stand->Canvas->Brush->Color = COLOR;
  Image_stand->Canvas->Ellipse(zero1, zero, zero1 + sect->diameter*scale, zero + sect->diameter*scale);

  Image_stand->Canvas->Brush->Color = clWhite;
  Image_stand->Canvas->Ellipse(zero1 + sect->thickness*scale, zero + sect->thickness*scale,
                          zero1 + (sect->diameter - sect->thickness)*scale, zero + (sect->diameter - sect->thickness)*scale);
  draw_axes(Image_stand);
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

void  __fastcall TSteelSectionDefinitionFrame::Check_Modify() {

	  TRect NewRect = Rect(0, 0, Image_stand->Width,
						   Image_stand->Height);

      Image_stand->Canvas->Brush->Color = clWhite;
      Image_stand->Canvas->FillRect(NewRect);
      Image_stand->Canvas->Rectangle(0, 0, Image_stand->Width,
                           Image_stand->Height);

	  DrawSect();
      flag_sect_change=true;

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
		fill_I_section_data();

}











// Заполнение списка профилей  ГОСТ
void __fastcall TSteelSectionDefinitionFrame::Change_type_sect(int index_profil, TObject *Sender)
{
		  RadioGroupGOST57837Click(Sender);
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

//
// Заполнить список профилей
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
}
//---------------------------------------------------------------------------

void TSteelSectionDefinitionFrame::fill_I_section_data()
{
	  // Установить тип стандартного сечения
	  common_sect_.dvutavr.n_group = RadioGroupGOST57837->ItemIndex + typeGOST_G57837_B;
	  // Установить тип стандартного сечения
	  StandartProfil.SetProfil(common_sect_.dvutavr.n_group);
	  // Заполнить структуру профиля двутавра
      StandartProfil.SetParamProfil(&(common_sect_.dvutavr), ComboBox_profil->ItemIndex);
}
//---------------------------------------------------------------------------



