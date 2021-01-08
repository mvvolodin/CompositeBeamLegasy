//---------------------------------------------------------------------------

#pragma hdrstop

#include "uGeneralConcreteSection.h"
#include "MathFunction.h"
#include <algorithm>
#include "uUnits.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
GeneralConcreteSection::GeneralConcreteSection(double const h_f,
											   double const L,
											   double const B_l,
											   double const B_r,
											   double const b_uf,
											   bool const is_end_beam,
											   Rebars const & rebars):
										h_f_{h_f},
										b_sl_  {calc_b_sl(L , B_l, B_r, h_f, b_uf, is_end_beam)},
										rebars_{rebars}{}
GeneralConcreteSection::~GeneralConcreteSection()
{

}
double GeneralConcreteSection::calc_b_sl(const double L,
										 const double B_l,
										 const double B_r,
										 const double h_f,
										 const double b_uf,
										 const bool end_beam)const
{
	if (!end_beam)
		return 2 * std::min(calc_b(h_f,b_uf/2,B_l,L),
							calc_b(h_f,b_uf/2,B_r,L));
		return 2* std::min(calc_b_c(h_f,b_uf/2,B_l,L),
						   calc_b(h_f,b_uf/2,B_r,L));

}
//---------------------------------------------------------------------------
//Определение расчётного свеса плиты
//Передаваемые параметры (в порядке представленном в функции):
//  *толщина плиты,
//  *половина ширины контакта  ж.б плиты и стального пояса
//	*расстояние между осями балок
//	*пролёт балки
//---------------------------------------------------------------------------
double GeneralConcreteSection::calc_b(const double h_f, const double a,
								      const double B, const double l)const
{
	double b = 0;
	double t_sl = h_f;

	if (l >= 4 * B)
		b = B / 2;
	else
		b = a + 6 * t_sl;
	return clamp(b, l/8, B/2 );
}
//---------------------------------------------------------------------------
//Определение расчётного свеса плиты в случае консоли
//Передаваемые параметры (в порядке представленном в функции):
//  *толщина плиты консоли,
//  *половина ширины контакта  ж.б плиты и стального пояса
//	*длина консольного свеса плиты
//	*пролёт балки
//---------------------------------------------------------------------------
double GeneralConcreteSection::calc_b_c(double h_f, double a,  double C, double l)const
{
	double bc = 0;
	double t_slc = h_f;

	if (l >= 12 * C)
		bc = C;
	else
		bc = a + 6 * t_slc;
	return clamp(bc, l/12, C );
}

double GeneralConcreteSection::h_f() const
{
	return h_f_;
}
double GeneralConcreteSection::b_sl() const
{
	return b_sl_;
}
Rebars GeneralConcreteSection::rebars()const
{
	return rebars_;
}
double GeneralConcreteSection::A_b() const
{
	return h_f_ * b_sl_ ;
}
double GeneralConcreteSection::I_b() const
{
	return b_sl_ * h_f_ * h_f_ * h_f_ / 12;
}

void GeneralConcreteSection::fill_grid(TStringGrid* str_grid)const
{
	str_grid->Cells [1][1]=FloatToStrF(b_sl(), ffFixed, 15, 0);
	str_grid->Cells [1][2]=FloatToStrF(C_b(), ffFixed, 15, 0);
	str_grid->Cells [1][3]=FloatToStrF(A_b(), ffFixed, 15, 0);
	str_grid->Cells [1][4]=FloatToStrF(I_b(), ffFixed, 15, 0);
}
//void GeneralConcreteSection::fill_grid_SP266(TStringGrid* str_grid)const
//{
//	str_grid->Cells [1][1]=FloatToStrF(b_sl(), ffFixed, 15, 0);
//	str_grid->Cells [1][2]=FloatToStrF(C_b(), ffFixed, 15, 0);
//	str_grid->Cells [1][3]=FloatToStrF(A_b(), ffFixed, 15, 0);
//	str_grid->Cells [1][4]=FloatToStrF(I_b(), ffFixed, 15, 0);
//}

void GeneralConcreteSection::print_input(TWord_Automation & report)const
{
	using namespace units;

	report.PasteTextPattern(slab_type().c_str(),"%slab_type%");
	report.PasteTextPattern(double_to_str(h_n(),0),"%h_n%");
	report.PasteTextPattern(double_to_str(h_f(),0),"%t_sl%");

	report.PasteTextPattern(rebars_.rebar().grade().c_str(),"%grade%");
	report.PasteTextPattern(double_to_str(rebars_.rebar().d_s(),0),"%d%");
	report.PasteTextPattern(double_to_str(rebars_.rebar().R_sn(),0),"%R_sn%");


}
void GeneralConcreteSection::print_output(TWord_Automation & report)const
{
	using namespace units;

	report.PasteTextPattern(double_to_str(b_sl_ * cm),"%b_sl%");
	report.PasteTextPattern(double_to_str(C_b() * cm),"%C_b%");
	report.PasteTextPattern(double_to_str(A_b() * cm2),"%A_b%");
	report.PasteTextPattern(double_to_str(I_b() * cm4),"%I_b%");
}
void GeneralConcreteSection::print_SP266(TWord_Automation & report)const
{
	using namespace units;

	report.PasteTextPattern(slab_type().c_str(),"%slab_type%");
	report.PasteTextPattern(double_to_str(h_n(),0),"%h_n%");
	report.PasteTextPattern(double_to_str(h_f(),0),"%t_sl%");

	report.PasteTextPattern(rebars_.rebar().grade().c_str(),"%grade%");
	report.PasteTextPattern(double_to_str(rebars_.rebar().d_s(),0),"%d%");
	report.PasteTextPattern(double_to_str(rebars_.rebar().R_sn(),0),"%R_sn%");

	report.PasteTextPattern(double_to_str(b_sl_ * cm),"%effect_width%");
	report.PasteTextPattern(double_to_str(C_b() * cm),"%GC_b%");
	report.PasteTextPattern(double_to_str(A_b() * cm2),"%area_b%");
	report.PasteTextPattern(double_to_str(I_b() * cm4),"%inertia_b%");
}

