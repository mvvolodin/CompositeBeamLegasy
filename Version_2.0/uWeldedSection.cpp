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

double WeldedSection::b_f1()
{
	return vertexes_[1].X - vertexes_[0].X;
}

double WeldedSection::t_f1()
{
	return vertexes_[2].Y - vertexes_[1].Y;
}

double WeldedSection::b_f2()
{
	return vertexes_[6].X - vertexes_[7].X;
}

double WeldedSection::t_f2()
{
	return vertexes_[6].Y - vertexes_[5].Y;
}

double WeldedSection::h_w()
{
	return vertexes_[4].Y - vertexes_[3].Y;
}

double WeldedSection::t_w()
{
	return vertexes_[3].X - vertexes_[10].X;
}

double WeldedSection::centroid()
{
	double C = 0.;

	for (int i = 0; i < vertexes_.size() - 1; ++i)
	{
		C += (vertexes_[i].Y + vertexes_[i + 1].Y) *
			 (vertexes_[i].X * vertexes_[i + 1].Y -
			  vertexes_[i + 1].X * vertexes_[i].Y);
	}

	double A = area();
	return C /(6 * A);
}

double WeldedSection::area()
{
	double A = 0.;

	for (int i = 0; i < vertexes_.size() - 1; ++i)
	{
		A += vertexes_[i].X * vertexes_[i + 1].Y - vertexes_[i + 1].X * vertexes_[i].Y;
	}

	return A / 2;
}

double WeldedSection::inertia()
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

	double A = area();
	double C = centroid();

	return I / 12 - C * C * A;
}

void WeldedSection::print_coord()
{
	int i = 0;

	for (auto v:vertexes_){
		std::cout << i << "   ";
		std::cout << "X = " << v.X;
		std::cout << "  Y = " << v.Y <<std::endl;
		++i;
	}
}

void WeldedSection::print_b_f1()
{
	std::cout << "b_f1 = " << b_f1() << std::endl;
}

void WeldedSection::print_t_f1()
{
	std::cout << "t_f1 = " << t_f1() << std::endl;
}

void WeldedSection::print_b_f2()
{
	std::cout << "b_f2 = " << b_f2() << std::endl;
}

void WeldedSection::print_t_f2()
{
	std::cout << "t_f2 = " << t_f2() << std::endl;
}

void WeldedSection::print_h_w()
{
	std::cout << "h_w = " << h_w() << std::endl;
}

void WeldedSection::print_t_w()
{
	std::cout << "t_w = " << t_w() << std::endl;
}

void WeldedSection::print_centroid()
{
	std::cout << "C = " << centroid() << std::endl;
}

void WeldedSection::print_area()
{
	std::cout << "A = " << area() << std::endl;
}

void WeldedSection::print_inertia()
{
	std::cout << "I = " << std::fixed << inertia() << std::endl;
}

