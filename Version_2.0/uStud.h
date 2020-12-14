//---------------------------------------------------------------------------

#ifndef uStudH
#define uStudH

#include<System.hpp>
#include<map>
#include<utility>
#include<vector>
#include <ostream>
#include "uUnits_new.h"
#include "uInternalForcesCalculator.h"
#include "uCompositeSectionGeometry.h"

class Stud{
public:

	Stud();
	Stud(String name, double d_an, double l, double R_y);

	void save(ostream& ostr) const;
	void load(istream& istr);

	void set_R_b(double R_b){R_b_ = R_b;};
	void set_gamma_c(double gamma_c){gamma_c_ = gamma_c;};

	String get_name()const{return name_;}
	double get_d_an(LengthUnit__ lenght_unit = mm)const{return d_an_ / lenght_unit;}
	double get_l(LengthUnit__ lenght_unit = mm)const{return l_ / lenght_unit;}
	double get_R_y()const{return R_y_;}

	double get_P_rd(LoadUnit__ load_unit = N);
	double get_S_h(LoadUnit__ load_unit = N);

private:
	String name_ = "";
	double d_an_ = 0.;
	double l_ = 0.;
	double R_y_ = 0.;

	double R_b_ = 0.;
	double gamma_c_ = 0.;

	mutable double P_rd_ = 0.;
	bool P_rd_calculated = false;

	double S_h_ = 0.;
	bool S_h_calculated = false;

	void calculate_P_rd();
	void calculate_S_h();

};

class StudsRow{
public:

	StudsRow(int id,
			 double x_l,
			 double x,
			 double x_r,
			 int st_num,
			 bool more_than_one_stud_per_corrugation);

	int get_id()const{return id_;}
	double get_x()const{return x_;}
	double get_x_r()const{return x_r_;}
	double get_x_l()const{return x_l_;}
	double get_S(LoadUnit load_unit=LoadUnit::N)const{return S_ / static_cast<int>(load_unit);}
	double get_ratio()const{return ratio_;}
	double get_k()const{return k_;}
	bool more_than_one_stud_per_corrugation()const {return more_than_one_stud_per_corrugation_;}

	void calculate_S(InternalForcesCalculator& intr_frcs_calculator, CompositeSectionGeometry& com_sect);

	void calculate_ratio(double P_rd, double S_h, double b_0, double h_n, double l, bool sheet_orient_along);
	void calculate_ratio(double P_rd, double S_h);

private:

	int id_ = 0;
	int st_num_ = 0;
	bool more_than_one_stud_per_corrugation_ = false;

	double x_l_ = 0.;
	double x_ = 0.;
	double x_r_ = 0.;

	double S_ = 0.;

	double k_ = 1.;

	double ratio_ = 0.;

	double calculate_k(double b_0, double h_n, double l, bool sheet_orient_along);

};

class StudsOnBeam{
public:

	StudsOnBeam();
	StudsOnBeam(Stud stud,
				double dist_e,
				double dist_m,
				int num_e,
				int num_m,
				double gamma_c,
				bool more_than_one_stud_per_corrugation_edge,
				bool more_than_one_stud_per_corrugation_middle);

	void save(ostream& ostr) const;
	void load(istream& istr);
	std::vector<StudsRow>& stud_list(){return stud_list_;}
	const std::vector<StudsRow>& get_stud_list()const{return stud_list_;}

	void set_default_values();

	void set_studs(double L);

	void set_intr_frcs_calculator(InternalForcesCalculator intr_frcs_calculator);
	void set_composite_section(CompositeSectionGeometry com_sect);

	const StudsRow& get_max_ratio_studs_row()const;

	void calculate_S();
	void calculate_ratios();

	String get_name()const{return stud_.get_name();}
	const Stud& get_stud()const{return stud_;};
	double get_gamma_c()const{return gamma_c_;}
	double get_dist_e(LengthUnit__ lenght_unit = mm)const{return dist_e_ / lenght_unit;}
	double get_dist_m(LengthUnit__ lenght_unit = mm)const{return dist_m_ / lenght_unit;}
	int get_num_e()const{return num_e_;}
	int get_num_m()const{return num_m_;}
	bool get_more_than_one_stud_per_corrugation_edge()const{return more_than_one_stud_per_corrugation_edge_;}
	bool get_more_than_one_stud_per_corrugation_middle()const{return more_than_one_stud_per_corrugation_middle_;}
	String get_more_than_one_stud_per_corrugation_edge_string()const
		{return (more_than_one_stud_per_corrugation_edge_)? L"Да": L"Нет";}
	String get_more_than_one_stud_per_corrugation_middle_string()const
		{return (more_than_one_stud_per_corrugation_middle_)? L"Да": L"Нет";}

private:

	Stud stud_;
	double dist_e_ = 0.;
	double dist_m_ = 0.;
	int num_e_ = 0;
	int num_m_ = 0;
	double gamma_c_ = 0.;
	bool more_than_one_stud_per_corrugation_edge_ = false;
	bool more_than_one_stud_per_corrugation_middle_ = false;

	InternalForcesCalculator intr_frcs_calculator_;
	CompositeSectionGeometry com_sect_;

	std::vector<StudsRow> stud_list_;
};

class TStudBasic{
public:
	TStudBasic();
	TStudBasic(String name, double d_an, double l);

	String get_name() const {return name_;};
	double get_l(LengthUnit length_unit=LengthUnit::mm) const
		{return l_/static_cast<int>(length_unit);}
	double get_d_an(LengthUnit length_unit=LengthUnit::mm) const
		{return d_an_/static_cast<int>(length_unit);}
protected:
	String name_ = L"SDx10x100";
	double d_an_ = 10.; //Диаметр стержня гибкого упора
	double l_= 100. ;   //Длина круглого стержня гибкого упора

};


using TStudBasicPair = std::pair <String, TStudBasic>;
using TStudBasicNamedList = std::map <String, TStudBasic>;
using IteratorTStudBasicNamedList = TStudBasicNamedList::iterator;

extern TStudBasicNamedList stud_named_list;
//---------------------------------------------------------------------------
#endif

