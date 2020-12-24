//---------------------------------------------------------------------------
#ifndef uGlobGeomH
#define uGlobGeomH
//---------------------------------------------------------------------------
#include <ostream>
#include <istream>
#include <string>
#include <vector>
#include "uUnits_new.h"
#include "uWord_Automation.h"
//---------------------------------------------------------------------------
class Node{
public:
	Node(double x, bool is_end_sup, bool is_inter_sup):
		id_(id_counter_++),
		x_(x),
		is_end_sup_(is_end_sup),
		is_inter_sup_(is_inter_sup)
		{
			if(is_end_sup){
				sup_index_ = sup_counter_++;
			}

			if(is_inter_sup){
				sup_index_ = sup_counter_++;
			}
		}
	int id()const{return id_;}
	double x()const{return x_;}
	bool is_end_support()const{return is_end_sup_;}
	bool is_inter_support()const{return is_inter_sup_;}
	int sup_index()const{return sup_index_;}

	static void reset_counters(){id_counter_ = 0;
								 sup_counter_ = 0;}
private:
	int id_ = 0;
	static int id_counter_;

	double x_ = 0.;

	bool is_end_sup_ = false;
	bool is_inter_sup_ = false;
	int sup_index_ = -1;
	static int sup_counter_;
};
	int Node::id_counter_ = 0;
	int Node::sup_counter_ = 0;


class GlobGeom{

public:
	public:
	GlobGeom() = default;
	GlobGeom(double max_el_length,
			 bool end_beam,
			 double span,
			 double spacing_left,
			 double spacing_right,
			 int tmp_sup_num);

	void print(TWord_Automation & report)const;

	bool is_end_beam()const;
	std::basic_string<char16_t>  is_end_beam_to_str()const;
	double span(LengthUnit length_units = LengthUnit::mm)const;
	double trib_width(LengthUnit length_units = LengthUnit::mm)const;
	double effective_width()const;

	int tmp_sup_num()const;
    std::vector<Node> nodes_lst()const;

private:
	double max_el_length_;
	bool end_beam_;
	double span_;
	double spacing_left_;
	double spacing_right_;
	int tmp_sup_num_;

	std::vector<Node> nodes_lst_{};

	void init_sect_lst();
};
#endif
