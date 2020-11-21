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
}
void GlobGeom::init_sect_lst()
{
	int num_temp_spans = tmp_sup_num_ + 1;

	int num_elements = span_ / num_temp_spans / max_el_length_  + 1;

	if(num_elements % 2 != 0) ++num_elements;

	double elem_length = span_ / num_temp_spans / num_elements;

	nodes_lst_.emplace_back(0, true, false);

	for (int i = 0; i < num_temp_spans; ++i){

		for(int j = 1; j < num_elements; ++j){
			nodes_lst_.emplace_back(span_ / num_temp_spans * i + elem_length * j, false, false);
		}

		nodes_lst_.emplace_back(span_ / num_temp_spans * (i + 1), false, true);
	}

	nodes_lst_.back() = {span_, true, false};

}

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


