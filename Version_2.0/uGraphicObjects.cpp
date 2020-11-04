//---------------------------------------------------------------------------

#pragma hdrstop

#include <cmath>
#include "uGraphicObjects.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

Arrow::Arrow(TPoint const & pnt, int l, int w, int ang):
	pnt_(pnt),
	l_(l),
	w_(w),
	ang_(ang){}
void Arrow::draw(TCanvas* cnvs)
{
	TColor pen_old_color = cnvs -> Pen -> Color;// save color settings
	TColor brush_old = cnvs -> Brush -> Color;

	cnvs -> Pen -> Color = clBlack;
	cnvs -> Brush -> Color = clBlack;

	int pnts_sz = 3; //initialize arrow points
	TPoint pnts[]{
		{0, 0},
		{-l_, w_},
		{-l_, -w_}};

	for (int i = 0; i < pnts_sz; ++i) //rotation
	{
		double x0 = pnts[i].x;
		double y0 = pnts[i].y;

		pnts[i].x = std::round(x0 * cos(ang_ * 3.14159265 / 180) - y0 * sin(ang_ * 3.14159265 / 180));
		pnts[i].y = std::round(x0 * sin(ang_ * 3.14159265 / 180) + y0 * cos(ang_ * 3.14159265 / 180));
	}

	for (int i = 0; i < pnts_sz; ++i) // movement
	{
		pnts[i].x += pnt_.x;
		pnts[i].y += pnt_.y;
	}

	cnvs -> Polygon(pnts, pnts_sz - 1); //draw arrow

	cnvs -> Pen -> Color = pen_old_color; //restore color settings
	cnvs -> Brush -> Color = pen_old_color;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
Dimension::Dimension(TPoint const & pnt_l, TPoint const &  pnt_r, std::string const & str, int offset, int ang):
	pnt_l_(pnt_l),
	pnt_r_(pnt_r),
	str_(str),
    offset_(offset),
	ang_(ang)
	{}

void Dimension::draw(TCanvas* cnvs)
{
	TColor pen_old_color = cnvs -> Pen -> Color;// save color settings
	TColor brush_old = cnvs -> Brush -> Color;

	cnvs -> Pen -> Color = clBlack;
	cnvs -> Brush -> Color = clBlack;

	int const sz = 2;

	TPoint tick {5,5};

	int a = pnt_l_.x;

	TPoint pnts_dim[sz] = {pnt_l_ + TPoint {0, offset_}, pnt_r_ + TPoint {0, offset_}};

	cnvs -> Polyline(pnts_dim, sz - 1);

	int alx = pnt_l_.x;
	int aly = pnt_l_.y;

	int arx = pnt_r_.x;
	int ary = pnt_r_.y;

	bool stop2 = true;

//	TPoint p1 {pnt1_ + TPoint{0, offset_}};
//	TPoint p2 {pnt2_ + TPoint{0, offset_}};
//
//	pnt1_.Offset(0, offset_);
//	pnt2_.Offset(0, offset_);

//	pnt1_.y += offset_;
//	pnt2_.y += offset_;
//
//	bool stop2 = true;
//
//	TPoint p5 = pnt1_ + (TPoint{0, offset_});
//	TPoint p6 = pnt2_ + TPoint{0, offset_};
//
//	cnvs -> Polyline(pnts_dim, sz - 1);
//
//	TPoint pnts_tick_l[sz]{pnts_dim[0] + tick, pnts_dim[0] - tick};
//	TPoint pnts_tick_r[sz]{pnts_dim[1] + tick, pnts_dim[1] - tick};
//	TPoint pnts_offset_l[sz]{pnt1_, pnts_dim[0]};
//	TPoint pnts_offset_r[sz]{pnt2_, pnts_dim[1]};
//
//
//	cnvs -> Polyline(pnts_tick_l, sz - 1);
//	cnvs -> Polyline(pnts_tick_r, sz - 1);
//	cnvs -> Polyline(pnts_offset_l, sz - 1);
//	cnvs -> Polyline(pnts_offset_l, sz - 1);
//
//	cnvs -> Pen -> Color = pen_old_color; //restore color settings
//	cnvs -> Brush -> Color = pen_old_color;

}

