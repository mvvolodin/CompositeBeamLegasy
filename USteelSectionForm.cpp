//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "USteelSectionForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

bool flag_image = true;

TSteelSectionForm2 *SteelSectionForm2;
//---------------------------------------------------------------------------
__fastcall TSteelSectionForm2::TSteelSectionForm2(TComponent* Owner)
	: TForm(Owner)
{
	StringGrid_B->Cells[0][0]="h (мм)";     //Двутавр
	StringGrid_B->Cells[0][1]="bf (мм)";
	StringGrid_B->Cells[0][2]="tw (мм)";
	StringGrid_B->Cells[0][3]="tf (мм)";
	StringGrid_B->Cells[0][4]="A (cм2)";
	StringGrid_B->Cells[0][5]="Iyy (cм4)";
	StringGrid_B->Cells[0][6]="iy (мм)";


   fill_cmb_bx_pofiles();

   ComboBox_profil->ItemIndex = StandartProfil.Get_NumberProfil(&(dvutavr), 0);

	dvutavr.n_group = RadioGroupGOST57837 -> ItemIndex + typeGOST_G57837_B;//присваиваем группу профилей Б, К.....
	dvutavr.n_profil = ComboBox_profil -> ItemIndex;//присваиваем номер профиля в группе
	// Установить тип стандартного сечения
	StandartProfil.SetProfil(dvutavr.n_group);//Заполняем массив с именами профиля и массив с его параметрами. Считаем, что конструктор

	double * ParamProfil;

	ParamProfil = StandartProfil.GetVectorParamProfil(dvutavr.n_profil);//Получаем параметры конкретного профиля

	dvutavr.b = ParamProfil[2];
	dvutavr.h = ParamProfil[0] - 2*ParamProfil[3];
	dvutavr.b1 = ParamProfil[1];
	dvutavr.b2 = ParamProfil[1]; //заменить magic number
	dvutavr.h1 = ParamProfil[3];
	dvutavr.h2 = ParamProfil[3];
	dvutavr.flag_concl=true; //требуется ли
	dvutavr.index_orient = 0; // требуется ли

    fill_grid();
}

void TSteelSectionForm2::fill_cmb_bx_pofiles()
{
	AnsiString *NameProfil;
   int n_profil;
   // Установить тип стандартного сечения
   StandartProfil.SetProfil(RadioGroupGOST57837->ItemIndex + typeGOST_G57837_B);
   // Получить вектор имен профилей и длину вектора
   NameProfil = StandartProfil.GetVectorNameProfil(&n_profil);
	ComboBox_profil->Items->Clear();
	for (int i=0; i < n_profil; i++)
		ComboBox_profil -> Items -> Add(NameProfil[i]);
}
void TSteelSectionForm2::fill_grid()
{
	int index = 3;
	double * ParamProfil;
	ParamProfil = StandartProfil.GetVectorParamProfil(ComboBox_profil -> ItemIndex);//ComboBox_profil->Items
	StringGrid_B -> Cells[1][0] = FloatToStr(ParamProfil[parHSECT]);
	StringGrid_B -> Cells[1][1] = FloatToStr(ParamProfil[parBF]);
	StringGrid_B -> Cells[1][2] = FloatToStr(ParamProfil[parTW]);
	StringGrid_B -> Cells[1][3] = FloatToStr(ParamProfil[parTF]);
	StringGrid_B -> Cells[1][4] = FloatToStrF(ParamProfil[parAREA]/100, ffFixed, 6, 0);
	StringGrid_B -> Cells[1][5] = FloatToStrF(ParamProfil[parIZZ]/10000, ffFixed, 6, 0);
	StringGrid_B -> Cells[1][6] = FloatToStrF(ParamProfil[parIRADZ], ffFixed, 6, 1);

	draw_dvutavr(Image_stand, &(dvutavr));
}
//----------------------------------------------------------------------
// рисование двутавра
void  TSteelSectionForm2::draw_dvutavr(TImage * Image_stand, SECT_DVUTAVR *sect)
{
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

	Image_stand->Canvas->Brush->Color = clMedGray;
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

	Image_stand->Canvas->Brush->Color = clMedGray;
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
// Рисование системы координат
void   TSteelSectionForm2::draw_axes(TImage *Image_Ax) {

  draw_axes_zero(Image_Ax, Image_Ax->Width/2, Image_Ax->Height/2);
}
//---------------------------------------------------------------------------
// Рисование системы координат
void   TSteelSectionForm2::draw_axes_zero(TImage *Image_Ax, int x0, int y0) {
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
//---------------------------------------------------------
// получить точки контура прокатного двутавра
void  TSteelSectionForm2::Point_stand_dvutavr(int zero, int zero1, int zero2, SECT_DVUTAVR *sect, double rad, float scale, TPoint *vertices)
{
  double r_c = rad*scale;
  double r2_c = Round(r_c - r_c*cos(45/57.3), 0);
  double b1c = sect->b1*scale;
  double b1p = 0.5*(sect->b1 + sect->b)*scale;
  double b1m = 0.5*(sect->b1 - sect->b)*scale;
  double h1c = sect->h1*scale;
  double h_h1 = (sect->h + sect->h1)*scale;
  double h_2h1 = (sect->h + 2*sect->h1)*scale;

  vertices[0] = Point(zero2, zero);
  vertices[1] = Point(zero2 + b1c, zero);
  vertices[2] = Point(zero2 + b1c, zero + h1c);
  vertices[3] = Point(zero2 + b1p + r_c, zero + h1c);
  vertices[4] = Point(zero2 + b1p + r2_c, zero + h1c + r2_c);
  vertices[5] = Point(zero2 + b1p, zero + h1c + r_c);
  vertices[6] = Point(zero2 + b1p, zero + h_h1 - r_c);
  vertices[7] = Point(zero1 + b1p + r2_c, zero + h_h1 - r2_c);
  vertices[8] = Point(zero1 + b1p + r_c, zero + h_h1);
  vertices[9] = Point(zero1 + b1c, zero + h_h1);
  vertices[10] = Point(zero1 + b1c, zero + h_2h1);
  vertices[11] = Point(zero1, zero + h_2h1);
  vertices[12] = Point(zero1, zero + h_h1);
  vertices[13] = Point(zero2 + b1m - r_c, zero + h_h1);
  vertices[14] = Point(zero2 + b1m - r2_c, zero + h_h1 - r2_c);
  vertices[15] = Point(zero2 + b1m , zero + h_h1 - r_c);
  vertices[16] = Point(zero2 + b1m, zero + h1c + r_c);
  vertices[17] = Point(zero2 + b1m - r2_c, zero + h1c + r2_c);
  vertices[18] = Point(zero2 + b1m - r_c, zero + h1c);
  vertices[19] = Point(zero2, zero + h1c);
  vertices[20] = Point(zero2, zero);
}

//---------------------------------------------------------------------------
