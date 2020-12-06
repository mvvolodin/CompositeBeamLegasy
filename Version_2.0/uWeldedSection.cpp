//---------------------------------------------------------------------------

#pragma hdrstop

#include <iostream>
#include <algorithm>
#include "uWeldedSection.h"
#include "uGraphicObjects.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)


WeldedSection::WeldedSection(double b_f1, double t_f1,
							 double b_f2, double t_f2,
							 double h_w, double t_w)
{
	vertexes_.emplace_back(-1 * b_f1 / 2, 0); //coord #0
	vertexes_.emplace_back(b_f1 / 2, 0); //coord #1
	vertexes_.emplace_back(b_f1 / 2, t_f1); //coord #2
	vertexes_.emplace_back(t_w / 2, t_f1);//coord #3
	vertexes_.emplace_back(t_w / 2, t_f1 + h_w);//coord #4
	vertexes_.emplace_back(b_f2 / 2, t_f1 + h_w);//coord #5
	vertexes_.emplace_back(b_f2 / 2, t_f1 + h_w + t_f2);//coord #6
	vertexes_.emplace_back(-1 * b_f2 / 2, t_f1 + h_w + t_f2);//coord #7
	vertexes_.emplace_back(-1 * b_f2 / 2, t_f1 + h_w);//coord #8
	vertexes_.emplace_back(-1 * t_w / 2, t_f1 + h_w);//coord #9
	vertexes_.emplace_back(-1 * t_w / 2, t_f1);//coord #10
	vertexes_.emplace_back(-1 * b_f1 / 2, t_f1);//coord #11
	vertexes_.emplace_back(-1 * b_f1 / 2, 0);//coord #0
}
WeldedSection::~WeldedSection()
{

}
std::wstring WeldedSection::name()const
{
	double max_width_fl = (upper_fl_width() >= lower_fl_width()) ?
		upper_fl_width():lower_fl_width();

	return L"Св. " + std::to_wstring(static_cast<int>(sect_height())) +
		   L"x" + std::to_wstring(static_cast<int>(max_width_fl));
}
double WeldedSection::lower_fl_width()const
{
	return vertexes_[1].X - vertexes_[0].X;
}

double WeldedSection::lower_fl_thick() const
{
	return vertexes_[2].Y - vertexes_[1].Y;
}

double WeldedSection::upper_fl_width()const
{
	return vertexes_[6].X - vertexes_[7].X;
}

double WeldedSection::upper_fl_thick()const
{
	return vertexes_[6].Y - vertexes_[5].Y;
}

double WeldedSection::web_height()const
{
	return vertexes_[4].Y - vertexes_[3].Y;
}

double WeldedSection::web_thick()const
{
	return vertexes_[3].X - vertexes_[10].X;
}
double WeldedSection::sect_height()const
{
	return vertexes_[7].Y - vertexes_[0].Y;
}
double WeldedSection::grav_cent_upper_fl_dist() const
{
	return vertexes_[7].Y - grav_cent();
}
double WeldedSection::grav_cent_lower_fl_dist() const
{
	return grav_cent();
}

double WeldedSection::grav_cent()const
{
	double C = 0.;

	for (int i = 0; i < vertexes_.size() - 1; ++i)
	{
		C += (vertexes_[i].Y + vertexes_[i + 1].Y) *
			 (vertexes_[i].X * vertexes_[i + 1].Y -
			  vertexes_[i + 1].X * vertexes_[i].Y);
	}

	return C /(6 * area());
}

double WeldedSection::area()const
{
	double A = 0.;

	for (int i = 0; i < vertexes_.size() - 1; ++i)
	{
		A += vertexes_[i].X * vertexes_[i + 1].Y - vertexes_[i + 1].X * vertexes_[i].Y;
	}

	return A / 2;
}
double WeldedSection::area_web() const
{
	return web_height() * web_thick();
}
double WeldedSection::area_upper_fl() const
{
	return upper_fl_width() * upper_fl_thick();
}
double WeldedSection::area_lower_fl() const
{
	return lower_fl_width() * lower_fl_thick();
}

double WeldedSection::inertia()const
{
	double I = 0.;

	for (int i = 0; i < vertexes_.size() - 1; ++i)
	{
		I += (vertexes_[i].Y * vertexes_[i].Y +
			  vertexes_[i].Y * vertexes_[i + 1].Y +
			  vertexes_[i + 1].Y * vertexes_[i + 1].Y) *
			 (vertexes_[i].X * vertexes_[i + 1].Y -
			  vertexes_[i + 1].X * vertexes_[i].Y);
	}
	return I / 12 - grav_cent() * grav_cent() * area();
}
double WeldedSection::smaller_fl_to_larger_fl_ratio()const
{
	return (area_upper_fl() <= area_lower_fl())?
		area_upper_fl() / area_lower_fl() : area_lower_fl() / area_upper_fl();
}
double WeldedSection::smaller_fl_area_to_web_area_ratio()const
{
	double const A_smaller_fl = (area_upper_fl() <= area_lower_fl())?
		area_upper_fl() : area_lower_fl();

	return A_smaller_fl / area_web();
}
double WeldedSection::smaller_fl_area_plus_web_area_to_total_area_ratio() const
{
	double const A_smaller_fl = (area_upper_fl() <= area_lower_fl())?
		area_upper_fl() : area_lower_fl();

	return (A_smaller_fl + area_web()) / area();
}

double WeldedSection::modulus_upper_fl() const
{
	return inertia() / grav_cent_upper_fl_dist();
}
double WeldedSection::modulus_lower_fl() const
{
	return inertia() / grav_cent_lower_fl_dist();
}
double WeldedSection::SW()const
{
	return area() * 7850 / 1000 / 1000 * 9.81;
}
#ifndef NDEBUG
void WeldedSection::print_data_to_logger(TFormLogger const & log)const
{
	log.add_heading(L"Тип сечения");
	log.print_string(L"Сварной двутавр");
	log.add_heading(L"Геометрические размеры");
	log.print_2_doubles(L"bf2 = ", upper_fl_width(), L" мм",L"tf2 = ", upper_fl_thick(), L" мм");
	log.print_2_doubles(L"bf1 = ", lower_fl_width(), L" мм",L"tf1 = ", lower_fl_thick(), L" мм");
	log.print_2_doubles(L"hw = ", web_height(), L" мм",L"tw = ", web_thick(), L" мм");
	log.add_heading(L"Координаты вершин сварного двутавра");
	for(auto v:vertexes_)
		log.print_2_doubles(L"X = ", v.X, L" мм",L"Y = ", v.Y, L" мм");
	log.add_heading(L"Геометрические характеристики");
	log.print_double(L"C = ", grav_cent(), L" мм");
	log.print_double(L"A = ", area(), L" мм2");
	log.print_double(L"I = ", inertia(), L" мм4");

}
#endif
std::vector<TPoint> WeldedSection::get_pnts_for_drawing()
{
	std::vector<TPoint> pnts{};

	pnts.emplace_back(upper_fl_width() / 2, 0); //coord #0
	pnts.emplace_back(upper_fl_width() / 2, upper_fl_thick()); //coord #1
	pnts.emplace_back(web_thick() / 2, upper_fl_thick()); //coord #2
	pnts.emplace_back(web_thick() / 2, upper_fl_thick() + web_height());//coord #3
	pnts.emplace_back(lower_fl_width() / 2, upper_fl_thick() + web_height());//coord #4
	pnts.emplace_back(lower_fl_width() / 2, upper_fl_thick() + web_height() + lower_fl_thick());//coord #5
	pnts.emplace_back(-1 * lower_fl_width() / 2, upper_fl_thick() + web_height() + lower_fl_thick());//coord #6
	pnts.emplace_back(-1 * lower_fl_width() / 2, upper_fl_thick() + web_height());//coord #7
	pnts.emplace_back(-1 * web_thick() / 2, upper_fl_thick() + web_height());//coord #8
	pnts.emplace_back(-1 * web_thick() / 2, upper_fl_thick());//coord #9
	pnts.emplace_back(-1 * upper_fl_width() / 2, upper_fl_thick());//coord #10
	pnts.emplace_back(-1 * upper_fl_width() / 2, 0);//coord #11

	return pnts;
}

void WeldedSection::draw(TCanvas* cnvs)
{
	cnvs -> Brush -> Color = clWhite;
	cnvs -> Pen -> Color = clBlack;

	cnvs -> Rectangle(cnvs -> ClipRect);

	std::vector<TPoint> points {get_pnts_for_drawing()};

	int const w = cnvs -> ClipRect.Width();
	int const h = cnvs -> ClipRect.Height();

	int const offset_x = 20;
	int const offset_y = 20;

	double const scale = std::min((h - 2 * offset_y) / (web_height() + lower_fl_thick() + upper_fl_thick()),
		(w - 2 * offset_x) / std::max(lower_fl_thick(),upper_fl_thick()));

	for_each(points.begin(), points.end(), [&scale, &w, &h](TPoint & p){
		p.x = p.x + w / 2 / scale; p.y = p.y + offset_y / scale;});

	for_each(points.begin(), points.end(), [&scale](TPoint & p){
		p.x *= scale; p.y *= scale;});

	cnvs -> Brush -> Color = clMedGray;
	cnvs -> Polygon(points.data(),points.size()-1);

//	Dimension dim_bf2 {points[0], points[11], "b_f", 10, 0};
//	dim_bf2.draw(cnvs);
//
////	Arrow ar {{30, 30}, 20, 4, 225};
////	ar.draw(cnvs);

}
void WeldedSection::print_input(TWord_Automation & report)const
{
	report.PasteTextPattern(name().c_str() ,"%name%");
	report.PasteTextPattern(FloatToStrF(sect_height(), ffFixed, 15, 2),"%sect_height%");
	report.PasteTextPattern(FloatToStrF(upper_fl_width(), ffFixed, 15, 2),"%upper_fl_width%");
	report.PasteTextPattern(FloatToStrF(upper_fl_thick(), ffFixed, 15, 2),"%upper_fl_thick%");
	report.PasteTextPattern(FloatToStrF(lower_fl_width(), ffFixed, 15, 2),"%lower_fl_width%");
	report.PasteTextPattern(FloatToStrF(lower_fl_thick(), ffFixed, 15, 2),"%lower_fl_thick%");
	report.PasteTextPattern(FloatToStrF(web_height(), ffFixed, 15, 2),"%web_height%");
	report.PasteTextPattern(FloatToStrF(web_thick(), ffFixed, 15, 2),"%web_thick%");
	report.PasteTextPattern(FloatToStrF(0, ffFixed, 15, 2),"%radius%");

}
void WeldedSection::print_output(TWord_Automation & report)const
{
	report.PasteTextPattern(FloatToStrF(area(), ffFixed, 15, 2),"%area%");
	report.PasteTextPattern(FloatToStrF(inertia(), ffFixed, 15, 2),"%inertia%");
	report.PasteTextPattern(FloatToStrF(upper_fl_thick(), ffFixed, 15, 2),"%modulus_upper_fl%");
	report.PasteTextPattern(FloatToStrF(upper_fl_thick(), ffFixed, 15, 2),"%modulus_lower_fl%");


}

