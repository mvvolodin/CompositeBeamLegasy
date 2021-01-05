//---------------------------------------------------------------------------

#pragma hdrstop

#include <iostream>
#include <algorithm>
#include "uWeldedSection.h"
#include "uGraphicObjects.h"
#include "uUnits.h"
#include "Constants.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

using namespace units;

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
	return area() * constants::steel_density / mm3 * constants::grav_accelerate;
}
#ifndef NDEBUG
void WeldedSection::print_data_to_logger(TFormLogger const & log)const
{
	FormLogger -> add_heading(L"Тип сечения");
	FormLogger -> print_string(L"Сварной двутавр");
	FormLogger -> add_heading(L"Геометрические размеры");
	FormLogger -> print_2_doubles(L"bf2 = ", upper_fl_width(), L" мм",L"tf2 = ", upper_fl_thick(), L" мм");
	FormLogger -> print_2_doubles(L"bf1 = ", lower_fl_width(), L" мм",L"tf1 = ", lower_fl_thick(), L" мм");
	FormLogger -> print_2_doubles(L"hw = ", web_height(), L" мм",L"tw = ", web_thick(), L" мм");
	FormLogger -> add_heading(L"Координаты вершин сварного двутавра");
	for(auto v:vertexes_)
		FormLogger -> print_2_doubles(L"X = ", v.X, L" мм",L"Y = ", v.Y, L" мм");
	FormLogger -> add_heading(L"Геометрические характеристики");
	FormLogger -> print_double(L"C = ", grav_cent(), L" мм");
	FormLogger -> print_double(L"A = ", area(), L" мм2");
	FormLogger -> print_double(L"I = ", inertia(), L" мм4");
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

	int const offset_x = 30;
	int const offset_y = 30;

	double const scale = std::min((h - 2 * offset_y) / (web_height() + lower_fl_thick() + upper_fl_thick()),
		(w - 2 * offset_x) / std::max(lower_fl_thick(),upper_fl_thick()));

	for_each(points.begin(), points.end(), [&scale, &w, &h](TPoint & p){
		p.x = p.x + w / 2 / scale; p.y = p.y + offset_y / scale;});

	for_each(points.begin(), points.end(), [&scale](TPoint & p){
		p.x *= scale; p.y *= scale;});

	cnvs -> Brush -> Color = clMedGray;
	cnvs -> Polygon(points.data(),points.size()-1);

	String bf2_tmp {FloatToStrF(upper_fl_width(), ffFixed, 15, 2)};
	std::u16string const bf2 {bf2_tmp.begin(),bf2_tmp.end()};

	String h_sect_tmp {FloatToStrF(sect_height(), ffFixed, 15, 2)};
	std::u16string const h_sect {h_sect_tmp.begin(),h_sect_tmp.end()};

	Dimension dim_bf2 {points[11], points[0], bf2, 10, Dimension::Direct::horiz};
	Dimension dim_h {points[11], points[6], h_sect, 10, Dimension::Direct::vert};

	dim_bf2.draw(cnvs);
	dim_h.draw(cnvs);

	CoordSyst cs (cnvs);
	cs.draw({w / 2, h / 2});
}


void WeldedSection::print_input(TWord_Automation & report)const
{
	report.PasteTextPattern(name().c_str() ,"%name%");
	report.PasteTextPattern(length_to_str(sect_height()), "%sect_height%");
	report.PasteTextPattern(length_to_str(upper_fl_width()),"%upper_fl_width%");
	report.PasteTextPattern(length_to_str(upper_fl_thick()),"%upper_fl_thick%");
	report.PasteTextPattern(length_to_str(lower_fl_width()),"%lower_fl_width%");
	report.PasteTextPattern(length_to_str(lower_fl_thick()),"%lower_fl_thick%");
	report.PasteTextPattern(length_to_str(web_height()),"%web_height%");
	report.PasteTextPattern(length_to_str(web_thick()),"%web_thick%");
	report.PasteTextPattern(length_to_str(0),"%radius%");

}
void WeldedSection::print_output(TWord_Automation & report)const
{
	report.PasteTextPattern(area_to_str(area(), LengthUnit::cm),"%area%");
	report.PasteTextPattern(inertia_to_str(inertia(), LengthUnit::cm),"%inertia%");
	report.PasteTextPattern(sect_modul_to_str(modulus_upper_fl(), LengthUnit::cm),"%modulus_upper_fl%");
	report.PasteTextPattern(sect_modul_to_str(modulus_lower_fl(), LengthUnit::cm),"%modulus_lower_fl%");
	report.PasteTextPattern(length_to_str(grav_cent_upper_fl_dist(), LengthUnit::cm),"%GC_upper_fl_dist%");
	report.PasteTextPattern(length_to_str(grav_cent_lower_fl_dist(), LengthUnit::cm),"%GC_lower_fl_dist%");
}



