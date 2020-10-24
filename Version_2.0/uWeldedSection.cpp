//---------------------------------------------------------------------------

#pragma hdrstop

#include "uWeldedSection.h"
#include <iostream>
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
double WeldedSection::b_f1()const
{
	return vertexes_[1].X - vertexes_[0].X;
}

double WeldedSection::t_f1() const
{
	return vertexes_[2].Y - vertexes_[1].Y;
}

double WeldedSection::b_f2()const
{
	return vertexes_[6].X - vertexes_[7].X;
}

double WeldedSection::t_f2()const
{
	return vertexes_[6].Y - vertexes_[5].Y;
}

double WeldedSection::h_w()const
{
	return vertexes_[4].Y - vertexes_[3].Y;
}

double WeldedSection::t_w()const
{
	return vertexes_[3].X - vertexes_[10].X;
}
double WeldedSection::h_st()const
{
	return vertexes_[7].Y - vertexes_[0].Y;
}
double WeldedSection::Z_f2_st() const
{
	return vertexes_[7].Y - C_st();
}
double WeldedSection::Z_f1_st() const
{
	return C_st();
}

double WeldedSection::C_st()const
{
	double C = 0.;

	for (int i = 0; i < vertexes_.size() - 1; ++i)
	{
		C += (vertexes_[i].Y + vertexes_[i + 1].Y) *
			 (vertexes_[i].X * vertexes_[i + 1].Y -
			  vertexes_[i + 1].X * vertexes_[i].Y);
	}

	return C /(6 * A_st());
}

double WeldedSection::A_st()const
{
	double A = 0.;

	for (int i = 0; i < vertexes_.size() - 1; ++i)
	{
		A += vertexes_[i].X * vertexes_[i + 1].Y - vertexes_[i + 1].X * vertexes_[i].Y;
	}

	return A / 2;
}
double WeldedSection::A_f2_st() const
{
	return b_f2() * t_f2();
}
double WeldedSection::A_f1_st() const
{
	return b_f1() * t_f1();
}

double WeldedSection::I_st()const
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
	return I / 12 - C_st() * C_st() * A_st();
}
double WeldedSection::smaller_fl_to_larger_fl_ratio()const
{
	double A_f2 = A_f2_st();
	double A_f1 = b_f1() * t_f1();

	return (A_f2 <= A_f1)? A_f2 / A_f1: A_f1 / A_f2;
}

double WeldedSection::W_f2_st() const
{
	return I_st() / Z_f2_st();
}
double WeldedSection::W_f1_st() const
{
	return I_st() / Z_f1_st();
}
double WeldedSection::SW()const
{
	return A_st() * 7850 / 1000 / 1000 * 9.81;
}

void WeldedSection::print_data_to_logger(std::unique_ptr<TFormLogger> const & log)const
{
	log -> add_separator(L"Тип сечения");
	log -> print_string(L"Сварной двутавр");
	log -> add_separator(L"Геометрические размеры");
	log -> print_2_doubles(L"bf2 = ", b_f2(), L" мм",L"tf2 = ", t_f2(), L" мм");
	log -> print_2_doubles(L"bf1 = ", b_f1(), L" мм",L"tf1 = ", t_f1(), L" мм");
	log -> print_2_doubles(L"hw = ", h_w(), L" мм",L"tw = ", t_w(), L" мм");
	log -> add_separator(L"Координаты вершин сварного двутавра");
	for(auto v:vertexes_)
		log -> print_2_doubles(L"X = ", v.X, L" мм",L"Y = ", v.Y, L" мм");
	log -> add_separator(L"Геометрические характеристики");
	log -> print_double(L"C = ", C_st(), L" мм");
	log -> print_double(L"A = ", A_st(), L" мм2");
	log -> print_double(L"I = ", I_st(), L" мм4");

}

