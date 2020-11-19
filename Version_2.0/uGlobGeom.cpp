//---------------------------------------------------------------------------

#pragma hdrstop
#include <algorithm>
#include "uGlobGeom.h"
#include "MathFunction.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)


GlobGeom::GlobGeom(double max_el_length,
				   bool end_beam,
				   double span,
				   double spacing_left,
				   double spacing_right,
				   int tmp_sup_num):
					max_el_length_(max_el_length),
					end_beam_(end_beam),
					span_(span),
					spacing_left_(spacing_left),
					spacing_right_(spacing_right),
                    tmp_sup_num_(tmp_sup_num)
{
	init_sect_lst();
//	calculate_effective_width(conc_sect_height,
//							  upper_fl_width);
}
void GlobGeom::init_sect_lst()
{
	int num_temp_spans = tmp_sup_num_ + 1;

	int num_elements = 0.;

	nodes_lst_.emplace_back(Node{0, true});

	num_elements = span_ / num_temp_spans / max_el_length_  + 1;

	if(num_elements % 2 != 0) ++num_elements;

	for (int i = 0; i < num_temp_spans; ++i){

		for(int j = 1; j < num_elements; ++j){
			nodes_lst_.emplace_back(
				Node{span_ / num_temp_spans * i + span_ / num_temp_spans / num_elements * j,
					false});
		}

		nodes_lst_.emplace_back(Node{span_ / num_temp_spans * (i + 1), true});
	}

}
//void GlobGeom::calculate_effective_width(double h_f, double b_uf)
//{
//	if (!end_beam_ )
//	{
//		effect_width_left_ = basic_effective_width(h_f, b_uf/2, spacing_left_);
//		effect_width_right_ = basic_effective_width(h_f, b_uf/2, spacing_right_);
//		return;
//	}
//		effect_width_left_ = cantilever_effective_width(h_f, b_uf/2, spacing_left_);
//		effect_width_right_ = basic_effective_width(h_f, b_uf/2, spacing_right_);
//}
//double GlobGeom::basic_effective_width(double h_f, double a, double spacing)
//{
//	double b = 0;
//	double t_sl = h_f;
//
//	if (span_ >= 4 * spacing)
//		b = spacing / 2;
//	else
//		b = a + 6 * t_sl;
//	return clamp(b, span_/8, spacing/2 );
//}
//double GlobGeom::cantilever_effective_width(double h_f, double a,  double C)
//{
//	double bc = 0;
//	double t_slc = h_f;
//
//	if (span_ >= 12 * C)
//		bc = C;
//	else
//		bc = a + 6 * t_slc;
//	return clamp(bc, span_/12, C);
//}
//double GlobGeom::effective_width() const
//{
//	return 2 * std::min(effect_width_left_,
//						effect_width_right_);
//}

void GlobGeom::print_data_to_report(TWord_Automation & report)const
{
//	report.PasteTextPattern(is_end_beam_to_str(), "%end_beam%");
//	report.PasteTextPattern(FloatToStrF(span(LengthUnit::mm), ffFixed, 15, 2), "%span%");
//	report.PasteTextPattern(FloatToStrF(get_spacing_left(LengthUnit::mm), ffFixed, 15, 2), "%trib_width_left% ");
//	report.PasteTextPattern(FloatToStrF(get_spacing_right(LengthUnit::mm), ffFixed, 15, 2), "%trib_width_right% ");
}


bool GlobGeom::is_end_beam()const
{
	return end_beam_;
}
std::basic_string<char16_t> GlobGeom::is_end_beam_to_str()const
{
	if(!end_beam_)
		return u"Нет";
	else
		return u"Да";
}

double GlobGeom::trib_width(LengthUnit length_units)const
{
	if (end_beam_)
		return  (spacing_left_ + spacing_right_ / 2) / static_cast<int>(length_units);
	return (spacing_left_ / 2 + spacing_right_ / 2) / static_cast<int>(length_units);
}

double GlobGeom::span(LengthUnit length_units)const
{
	return span_;
}

int GlobGeom::tmp_sup_num()const
{
	return tmp_sup_num_;
}
std::vector<Node> GlobGeom::nodes_lst()const
{
	return nodes_lst_;
}


