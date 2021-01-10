//---------------------------------------------------------------------------

#pragma hdrstop

#include "uGeneralConcreteSection.h"
#include "MathFunction.h"
#include <algorithm>
#include "uUnits.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
GeneralConcreteSection::GeneralConcreteSection(double const des_height,
											   double const L,
											   double const B_l,
											   double const B_r,
											   double const b_uf,
											   bool const is_end_beam,
											   Rebars const & rebars):
										des_height_{des_height},
										des_width_ {calc_b_sl(L , B_l, B_r, des_height, b_uf, is_end_beam)},
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

double GeneralConcreteSection::des_height() const
{
	return des_height_;
}
double GeneralConcreteSection::des_width() const
{
	return des_width_;
}
Rebars GeneralConcreteSection::rebars()const
{
	return rebars_;
}
double GeneralConcreteSection::area() const
{
	return des_height_ * des_height_ ;
}
double GeneralConcreteSection::inertia() const
{
	return des_height_ * des_height_ * des_height_ * des_height_ / 12;
}

void GeneralConcreteSection::fill_grid(TStringGrid* str_grid)const
{
	str_grid->Cells [1][1]=FloatToStrF(des_width(), ffFixed, 15, 0);
	str_grid->Cells [1][2]=FloatToStrF(C_b(), ffFixed, 15, 0);
	str_grid->Cells [1][3]=FloatToStrF(area(), ffFixed, 15, 0);
	str_grid->Cells [1][4]=FloatToStrF(inertia(), ffFixed, 15, 0);
}
double GeneralConcreteSection::rebars_area()const
{
	return rebars_.A_u_r_per_unit() * des_width() +
		rebars_.A_l_r_per_unit() * des_width();
}
void GeneralConcreteSection::print_input(TWord_Automation & report)const
{
	using namespace units;

	report.PasteTextPattern(slab_type().c_str(),"%slab_type%");
	report.PasteTextPattern(double_to_str(h_n(),0),"%h_n%");
	report.PasteTextPattern(double_to_str(des_height(),0),"%t_sl%");

	report.PasteTextPattern(rebars_.rebar().grade().c_str(),"%grade%");
	report.PasteTextPattern(double_to_str(rebars_.rebar().d_s(),0),"%d%");
	report.PasteTextPattern(double_to_str(rebars_.rebar().R_sn(),0),"%R_sn%");


}
void GeneralConcreteSection::print_output(TWord_Automation & report)const
{
	using namespace units;

	report.PasteTextPattern(double_to_str(des_width_ * cm),"%b_sl%");
	report.PasteTextPattern(double_to_str(C_b() * cm),"%C_b%");
	report.PasteTextPattern(double_to_str(area() * cm2),"%A_b%");
	report.PasteTextPattern(double_to_str(inertia() * cm4),"%I_b%");
}
void GeneralConcreteSection::print(TWord_Automation & report)const
{
	using namespace units;

	report.PasteTextPattern(slab_type().c_str(),"%slab_type%");
	report.PasteTextPattern(double_to_str(h_n(),0),"%h_n%");
	report.PasteTextPattern(double_to_str(des_height(),0),"%t_sl%");

	report.PasteTextPattern(rebars_.rebar().grade().c_str(),"%grade%");
	report.PasteTextPattern(double_to_str(rebars_.rebar().d_s(),0),"%d%");
	report.PasteTextPattern(double_to_str(rebars_.rebar().R_sn(),0),"%R_sn%");

	report.PasteTextPattern(double_to_str(des_width_ * cm),"%effect_width%");
	report.PasteTextPattern(double_to_str(C_b() * cm),"%GC_b%");
	report.PasteTextPattern(double_to_str(area() * cm2),"%area_b%");
	report.PasteTextPattern(double_to_str(inertia() * cm4),"%inertia_b%");
}
#ifdef DEBUG_CONC_SECT
void GeneralConcreteSection::log()const
{
		FormLogger -> print(
		{"*****************************",
		 "Геометрические характеристики",
		 "*****************************",
		 "Расч. толщина = " + FloatToStr(des_height()) + " мм",
		 "Расч. ширина = " + FloatToStr(des_width()) + " мм",
		 "Площадь = " + FloatToStr(des_width()) + " мм2",
		 "Инерция = " + FloatToStr(des_width()) + " мм4"
		 });
}
#endif

