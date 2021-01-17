//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <fstream>
#include "uFrmSteelSection.h"
#include "String_doubleUnit.h"
#include "uFrmLogger.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

bool flag_image = true;

TSteelSectionForm *SteelSectionForm;
//---------------------------------------------------------------------------
__fastcall TSteelSectionForm::TSteelSectionForm(TComponent* Owner)
	: TForm(Owner)
{
	StringGrid_B->Cells[0][0]="h (мм)";
	StringGrid_B->Cells[0][1]="bf (мм)";
	StringGrid_B->Cells[0][2]="tw (мм)";
	StringGrid_B->Cells[0][3]="tf (мм)";
	StringGrid_B->Cells[0][4]="A (cм2)";
	StringGrid_B->Cells[0][5]="Ixx (cм4)";
	StringGrid_B->Cells[0][6]="ix (мм)";
}
void __fastcall TSteelSectionForm::FormShow(TObject *Sender)
{
	update_cntrls_state();
}

//---------------------------------------------------------------------------
//Заполнение ComboBox перечнем имён для переданного типа профилей
//---------------------------------------------------------------------------
void TSteelSectionForm::fill_cmb_bx_rolled_sect_num(int rolled_sect_type)
{
	std::vector<AnsiString> const nums = get_rolled_sect_type_nums(rolled_sect_type);

	cmb_bx_rolled_sect_num -> Clear();

	for (auto const & num: nums)
		cmb_bx_rolled_sect_num -> Items -> Add(num);
}
void TSteelSectionForm::fill_strng_grd_rolled_sect(SECT_DVUTAVR sect)
{
//Заполнение элемента управления данными профиля
	StringGrid_B -> Cells[1][0] = FloatToStr(sect.h + sect.b1 + sect.b2);
	StringGrid_B -> Cells[1][1] = FloatToStr(sect.b1);
	StringGrid_B -> Cells[1][2] = FloatToStr(sect.b);
	StringGrid_B -> Cells[1][3] = FloatToStr(sect.h1);
	StringGrid_B -> Cells[1][4] = FloatToStrF(sect.A/100, ffFixed, 6, 0);
	StringGrid_B -> Cells[1][5] = FloatToStrF(sect.I/10000, ffFixed, 6, 0);
	StringGrid_B -> Cells[1][6] = FloatToStrF(sect.r, ffFixed, 6, 1);
}


//----------------------------------------------------------------------
// рисование двутавра
//----------------------------------------------------------------------
void  TSteelSectionForm::draw_dvutavr(TImage * Image_stand, SECT_DVUTAVR *sect)
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
	//StandartProfil.SetProfil(sect->n_group);
	//ParamProfil = StandartProfil.GetVectorParamProfil(sect->n_profil);

	Point_stand_dvutavr(zero, zero1, zero2, sect, /*ParamProfil[parRAD]*/sect->r, scale, vertices); // получить точки контура двутавра

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
void   TSteelSectionForm::draw_axes(TImage *Image_Ax) {

  draw_axes_zero(Image_Ax, Image_Ax->Width/2, Image_Ax->Height/2);
}
//---------------------------------------------------------------------------
// Рисование системы координат
void   TSteelSectionForm::draw_axes_zero(TImage *Image_Ax, int x0, int y0) {
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
// получить точки контура прокатного двутавра
//---------------------------------------------------------------------------
void  TSteelSectionForm::Point_stand_dvutavr(int zero, int zero1, int zero2, SECT_DVUTAVR *sect, double rad, float scale, TPoint *vertices)
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
//
//---------------------------------------------------------------------------

void __fastcall TSteelSectionForm::cmb_bx_rolled_sect_numChange(TObject *Sender)
{

	SECT_DVUTAVR sect = get_rolled_sect_from_DB(rd_grp_rolled_sect_type -> ItemIndex,
												static_cast<TComboBox*>(Sender) -> ItemIndex);
	fill_strng_grd_rolled_sect(sect);
	draw_dvutavr(Image_stand, &sect);
}
//---------------------------------------------------------------------------
//
//---------------------------------------------------------------------------
void __fastcall TSteelSectionForm::rd_grp_rolled_sect_typeClick(TObject *Sender)
{
	int const rolled_sect_type = static_cast<TRadioGroup*>(Sender)-> ItemIndex;

	fill_cmb_bx_rolled_sect_num(rolled_sect_type);

	int const rolled_sect_num = 0;

	cmb_bx_rolled_sect_num -> ItemIndex = rolled_sect_num;

	SECT_DVUTAVR sect = get_rolled_sect_from_DB(rolled_sect_type, rolled_sect_num);

	fill_strng_grd_rolled_sect(sect);
	draw_dvutavr(Image_stand, &sect);
}

//---------------------------------------------------------------------------
//
//---------------------------------------------------------------------------
void __fastcall TSteelSectionForm::btk_okClick(TObject *Sender)
{
	try {
		check_input();
	} catch (int e){
		return;
	}
	store_cntrls_state();
}
//---------------------------------------------------------------------------
//
//---------------------------------------------------------------------------
void __fastcall TSteelSectionForm::btn_cancelClick(TObject *Sender)
{
	update_cntrls_state();
}
//---------------------------------------------------------------------------
//
//---------------------------------------------------------------------------
void __fastcall TSteelSectionForm::btn_closeClick(TObject *Sender)
{
	try {
		check_input();
	} catch (int e){
		return;
	}
	store_cntrls_state();
	Close();
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
void TSteelSectionForm::store_cntrls_state()
{
	cntrls_state_.edt_b_f2_ = edt_b_f2 -> Text.ToDouble();
	cntrls_state_.edt_t_f2_= edt_t_f2 -> Text.ToDouble();
	cntrls_state_.edt_b_f1_ = edt_b_f1 -> Text.ToDouble();
	cntrls_state_.edt_t_f1_ = edt_t_f1 -> Text.ToDouble();
	cntrls_state_.edt_h_w_ = edt_h_w -> Text.ToDouble();
	cntrls_state_.edt_t_w_ = edt_t_w -> Text.ToDouble();
	cntrls_state_.pg_cntrl_sect_type_ = pg_cntrl_sect_type -> ActivePageIndex;
	cntrls_state_.cmb_bx_rolled_sect_num_ = cmb_bx_rolled_sect_num -> ItemIndex;
	cntrls_state_.rd_grp_rolled_sect_type_ = rd_grp_rolled_sect_type -> ItemIndex;

}
void TSteelSectionForm::update_cntrls_state()
{
	edt_b_f2 -> Text = cntrls_state_.edt_b_f2_;
	edt_t_f2 -> Text = cntrls_state_.edt_t_f2_;
	edt_b_f1 -> Text = cntrls_state_.edt_b_f1_;
	edt_t_f1 -> Text = cntrls_state_.edt_t_f1_;
	edt_h_w -> Text = cntrls_state_.edt_h_w_;
	edt_t_w -> Text = cntrls_state_.edt_t_w_;

	fill_cmb_bx_rolled_sect_num(cntrls_state_.rd_grp_rolled_sect_type_);

	cmb_bx_rolled_sect_num -> ItemIndex = cntrls_state_.cmb_bx_rolled_sect_num_;

	SECT_DVUTAVR sect = get_rolled_sect_from_DB(cntrls_state_.rd_grp_rolled_sect_type_,
												cntrls_state_.cmb_bx_rolled_sect_num_);
	fill_strng_grd_rolled_sect(sect);
	draw_dvutavr(Image_stand, &sect);

	draw_weld_sect();

	pg_cntrl_sect_type -> ActivePageIndex = cntrls_state_.pg_cntrl_sect_type_;
}

void TSteelSectionForm::save(ostream & os)
{
	cntrls_state_.save_cntls_state(os);
}
//---------------------------------------------------------------------------

void TSteelSectionForm::load(istream & is)
{
	cntrls_state_.load_cntrls_state(is);
}

String TSteelSectionForm::info()const
{
	if(cntrls_state_.pg_cntrl_sect_type_ == 1)
	{
		double h_sect = cntrls_state_.edt_t_f1_ + cntrls_state_.edt_h_w_ + cntrls_state_.edt_t_f2_;
		double max_width_fl = (cntrls_state_.edt_b_f2_ >= cntrls_state_.edt_b_f1_) ?
			cntrls_state_.edt_b_f2_:cntrls_state_.edt_b_f1_;

		return L"Св. " + FloatToStrF(max_width_fl, ffFixed, 15, 0) +
			L"x" + FloatToStrF(h_sect, ffFixed, 15, 0);
	}
	else
		return cmb_bx_rolled_sect_num -> Items -> Strings[cntrls_state_.cmb_bx_rolled_sect_num_];

}

//---------------------------------------------------------------------------
void TSteelSectionForm::draw_weld_sect()
{
	WeldedSection weld_sect{edt_b_f1 -> Text.ToDouble(), edt_t_f1 -> Text.ToDouble(),
							edt_b_f2 -> Text.ToDouble(), edt_t_f2 -> Text.ToDouble(),
							edt_h_w -> Text.ToDouble(),  edt_t_w -> Text.ToDouble()};

	weld_sect.draw(img_weld_sect->Canvas);
}
//---------------------------------------------------------------------------

void __fastcall TSteelSectionForm::edt_weld_sect_exit(TObject *Sender)
{
	check_input();
	draw_weld_sect();
}
//---------------------------------------------------------------------------
void TSteelSectionForm::check_input()
{
	int rc;
	double temp;

	rc = String_double_plus(lbl_b_f2 -> Caption, edt_b_f2 -> Text, &temp);
	if(rc > 0)throw(rc);

	rc = String_double_plus(lbl_t_f2 -> Caption, edt_t_f2 -> Text, &temp);
	if(rc > 0)throw(rc);

	rc = String_double_plus(lbl_b_f1 -> Caption, edt_b_f1 -> Text, &temp);
	if(rc > 0)throw(rc);

	rc = String_double_plus(lbl_t_f1 -> Caption, edt_t_f1 -> Text, &temp);
	if(rc > 0)throw(rc);

	rc = String_double_plus(lbl_h_w -> Caption, edt_h_w -> Text, &temp);
	if(rc > 0)throw(rc);

	rc = String_double_plus(lbl_t_w -> Caption, edt_t_w -> Text, &temp);
	if(rc > 0)throw(rc);
}

void __fastcall TSteelSectionForm::pg_cntrl_sect_typeChange(TObject *Sender)
{
	cntrls_state_.pg_cntrl_sect_type_ = pg_cntrl_sect_type -> ActivePageIndex;
}
//---------------------------------------------------------------------------

