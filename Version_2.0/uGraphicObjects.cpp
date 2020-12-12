//---------------------------------------------------------------------------

#pragma hdrstop

#include <cmath>
#include "uGraphicObjects.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
/*
	Функция поворота точки относительно начала декартовой системы координат
*/
void rotate(TPoint & p, double const ang)
{
	TPoint const p0 {p};

	p.X = std::round(p0.x * cos(ang * 3.14159265 / 180) - p0.y * sin(ang * 3.14159265 / 180));
	p.Y = std::round(p0.x * sin(ang * 3.14159265 / 180) + p0.y * cos(ang * 3.14159265 / 180));
}
/*
	Функция поворота объекта относительно начала декартовой системы координат
*/
void rotate(std::vector<TPoint> & obj, double const ang)
{
	for(auto & p:obj)
		rotate(p, ang);
}
/*
	Функция поворота группы объектов относительно начала декартовой системы координат
*/
void rotate(std::vector<std::vector<TPoint>> & objs, double const ang)
{
	for(auto & o:objs)
		rotate(o, ang);
}
/*
	Функция поворота точки относительно точки rot_cent
*/
void rotate(TPoint & p, TPoint const & rot_cent, double const ang)
{
	p -= rot_cent;
	rotate(p, ang);
	p += rot_cent;
}
/*
	Функция поворота объекта относительно точки rot_cent
*/
void rotate(std::vector<TPoint> & obj, TPoint const & rot_cent, double const ang)
{
	for(auto & p:obj)
		rotate(p, rot_cent, ang);
}
/*
	Функция перемещения точки на расстояния dist_x и dist_y
*/
void move(TPoint & p, int const dist_x, int const dist_y)
{
		p += TPoint {dist_x, dist_y};
}
/*
	Функция перемещения объекта на расстояния dist_x и dist_y
*/
void move(std::vector<TPoint> & obj, int dist_x, int dist_y)
{
	for (auto & p: obj)
		move(p, dist_x, dist_y);
}
/*
	Функция перемещения группы объектов на расстояния dist_x и dist_y
*/
void move(std::vector<std::vector<TPoint>> & objs, int dist_x, int dist_y)
{
	for (auto & o: objs)
		move(o, dist_x, dist_y);
}
/*
	Функция перемещения объекта в точку pnt
*/
void move_obj(std::vector<TPoint> & obj, TPoint const & pnt)
{
	int const dist_x = pnt.X - obj.front().X;
	int const dist_y = pnt.Y - obj.front().Y;

	move(obj, dist_x, dist_y);
}
/*
	Функция перемещения группы объектов в точку pnt
*/
void move_objs(std::vector<std::vector<TPoint>> & objs, TPoint const & pnt)
{
	int const dist_x = pnt.X - objs.front().front().X;
	int const dist_y = pnt.Y - objs.front().front().Y;

	move(objs, dist_x, dist_y);
}


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

	std::vector<TPoint> arrow{{0, 0},
							  {-l_, w_},
							  {-l_, -w_}};
	int const center_x = cnvs -> ClipRect.Width() / 2;
	int const center_y = cnvs -> ClipRect.Height() / 2;

	move_obj(arrow,{30, 50});
	rotate(arrow, {30, 50}, 90);

	cnvs -> Polygon(arrow.data(), arrow.size()-1);

	cnvs -> Pen -> Color = pen_old_color; //restore color settings
	cnvs -> Brush -> Color = pen_old_color;
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
Dimension::Dimension(TPoint const & pnt_1,
					 TPoint const &  pnt_2,
					 std::string const & str,
					 int offset,
					 Direct dir):
	pnt_1_(pnt_1),
	pnt_2_(pnt_2),
	str_(str),
    offset_(offset),
	dir_(dir)
	{}

void Dimension::draw(TCanvas* cnvs)
{
	switch (dir_){
	case horiz:
		draw_horiz(cnvs);
		break;
	case vert:
		draw_vert(cnvs);
		break;
	}
}
void Dimension::draw_horiz(TCanvas* cnvs)
{
	TColor pen_old_color = cnvs -> Pen -> Color;
	TColor brush_old = cnvs -> Brush -> Color;

	cnvs -> Pen -> Color = clBlack;
	cnvs -> Brush -> Color = clWhite;

	int const num_pnts = 2;

	std::vector<TPoint> dim {pnt_1_ + TPoint {0, -offset_},
									  pnt_2_ + TPoint {0, -offset_}};

	std::vector<TPoint> ext_left{pnt_1_,
										  dim[0] + TPoint {0, -2}};

	std::vector<TPoint> ext_right{pnt_2_,
										   dim[1] + TPoint {0, -2}};

	std::vector<TPoint> tick_left{dim[0] + TPoint {-5, 5},
										   dim[0] + TPoint {5, -5}};

	std::vector<TPoint> tick_right{dim[1] + TPoint {-5, 5},
											dim[1] + TPoint {5, -5}};

	int w_str = cnvs -> TextWidth(UnicodeString{str_.c_str()});
	int h_str = cnvs -> TextHeight(UnicodeString{str_.c_str()});

	TPoint pnt_txt {(ext_left [1].X + ext_right[1].X) / 2 - w_str / 2,
					 ext_left[1].Y - h_str};

	cnvs -> Font-> Style = TFontStyles() << fsItalic;
	cnvs -> TextOut(pnt_txt.X, pnt_txt.Y, str_.c_str());

	cnvs -> Pen -> Color = pen_old_color; //restore color settings
	cnvs -> Brush -> Color = pen_old_color;

	TPoint pnt1 {0,0};

	std::vector<std::vector<TPoint>> objs {dim,
		ext_left, ext_right, tick_left, tick_right};

	rotate(objs, 0);

	for(auto const & l:objs)
		cnvs -> Polyline(l.data(), l.size()-1);


}
void Dimension::draw_vert(TCanvas* cnvs)
{
	TColor pen_old_color = cnvs -> Pen -> Color;
	TColor brush_old = cnvs -> Brush -> Color;

	cnvs -> Pen -> Color = clBlack;
	cnvs -> Brush -> Color = clWhite;

	int const num_pnts = 2;

	std::vector<TPoint> dim {pnt_1_ + TPoint {-offset_, 0 },
									  pnt_2_ + TPoint {-offset_, 0}};

	std::vector<TPoint> ext_left{pnt_1_, dim[0] + TPoint {0, -2}};

	std::vector<TPoint> ext_right{pnt_2_,
						    dim[1] + TPoint {0, -2}};

	std::vector<TPoint> tick_left{dim[0] + TPoint {-5, 5},
										   dim[0] + TPoint {5, -5}};

	std::vector<TPoint> tick_right{dim[1] + TPoint {-5, 5},
											dim[1] + TPoint {5, -5}};

	int w_str = cnvs -> TextWidth(UnicodeString{str_.c_str()});
	int h_str = cnvs -> TextHeight(UnicodeString{str_.c_str()});

	TPoint pnt_txt {(ext_left [1].X + ext_right[1].X) / 2 - w_str / 2,
					 ext_left[1].Y - h_str};

	cnvs -> Font-> Style = TFontStyles() << fsItalic;
	cnvs -> TextOut(pnt_txt.X, pnt_txt.Y, str_.c_str());

	cnvs -> Pen -> Color = pen_old_color; //restore color settings
	cnvs -> Brush -> Color = pen_old_color;

	TPoint pnt1 {0,0};

	std::vector<std::vector<TPoint>> objs {dim,
		ext_left, ext_right, tick_left, tick_right};

	rotate(objs, 0);

	for(auto const & l:objs)
		cnvs -> Polyline(l.data(), l.size()-1);


}



