//---------------------------------------------------------------------------
#ifndef uGlobGeomH
#define uGlobGeomH
//---------------------------------------------------------------------------
#include <ostream>
#include <istream>
#include <string>
#include <vector>
#include "Units.h"
#include "uWord_Automation.h"
//---------------------------------------------------------------------------
class Node{
public:
	Node(double x, bool is_s):
		x_(x),
		is_sup_(is_sup){}
	double x(){return x_;}
	bool is_sup(){return is_sup_;}

private:
	bool is_sup_ = false;
	double x_ = 0.;
};

class GlobGeom{

public:
	public:
	GlobGeom(double max_el_length,
			 bool end_beam,
			 double span,
			 double spacing_left,
			 double spacing_right,
			 int tmp_sup_num);

	void print_data_to_report(TWord_Automation & report)const;

	bool is_end_beam()const;
	std::basic_string<char16_t>  is_end_beam_to_str()const;
	double span(LengthUnit length_units = LengthUnit::mm)const;
	double trib_width(LengthUnit length_units = LengthUnit::mm)const;
	double effective_width()const;

	int tmp_sup_num()const;
    std::vector<Node> nodes_lst()const;

private:
	double const max_el_length_ = 0.;
	bool const end_beam_ = false;
	double const span_ = 0.;
	double const spacing_left_ = 0.;
	double const spacing_right_ = 0.;
	int const tmp_sup_num_ = 0.;

	std::vector<Node> nodes_lst_{};

//	double effect_width_left_ = 0.;
//	double effect_width_right_ = 0.;

	void init_sect_lst();
//	void calculate_effective_width(double h_f, double b_uf);
//	double basic_effective_width(double h_f, double a,  double spacing);
//	double cantilever_effective_width(double t_sl, double a,  double spacing);
};
#endif
