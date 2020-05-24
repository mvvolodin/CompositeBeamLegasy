//---------------------------------------------------------------------------

#ifndef uStudH
#define uStudH

#include<System.hpp>
#include<map>
#include<utility>
#include<vector>
#include <ostream>
#include "Units.h"
#include "uInternalForcesCalculator.h"
#include "uCompositeSectionGeometry.h"

class Stud{
public:

	Stud();
	Stud(String name, double d_an, double l, double R_y);

	void calculate_P_rd(double R_b, double gamma_c);

	String get_name()const{return name_;}
	double get_d_an(LengthUnit__ lenght_unit = mm)const{return d_an_ / lenght_unit;}
	double get_l(LengthUnit__ lenght_unit = mm)const{return l_ / lenght_unit;}
	double get_R_y()const{return R_y_;}

	double get_P_rd(LoadUnit__ load_unit = N)const{return P_rd_ / load_unit;}

private:
	String name_;
	double d_an_;
	double l_;
	double R_y_;

	double P_rd_;
};

class StudsRow{
public:

	StudsRow(int id, double x_l, double x, double x_r, int st_num);

	int get_id()const{return id_;}
	double get_x()const{return x_;}
	double get_x_r()const{return x_r_;}
	double get_x_l()const{return x_l_;}
	double get_S()const{return S_;}
	double get_ratio()const{return ratio_;}

	void calculate_S(InternalForcesCalculator& intr_frcs_calculator, CompositeSectionGeometry& com_sect);
	void calculate_ratio(double P_rd_);

private:

	int id_ = 0;
	int st_num_ = 0;

	double x_l_ = 0.;
	double x_ = 0.;
	double x_r_ = 0.;

	double S_ = 0.;

	double ratio_ = 0.;
};

class StudsOnBeam{
public:

	StudsOnBeam();
	StudsOnBeam(Stud stud,
				double dist_e, double dist_m,
				int num_e, int num_m,
				double gamma_c);

	void save(ostream& ostr) const;
	void load(istream& istr);
	std::vector<StudsRow>& stud_list(){return stud_list_;}
	const std::vector<StudsRow>& get_stud_list()const{return stud_list_;}

	void set_default_values();

	void set_studs(double L);

	void set_intr_frcs_calculator(InternalForcesCalculator intr_frcs_calculator);
	void set_composite_section(CompositeSectionGeometry com_sect);

	const StudsRow& get_max_ratio_studs_row()const;

	void calculate_P_rd();
	void calculate_S();
	void calculate_ratio();

	String get_name()const{return stud_.get_name();}
	const Stud& get_stud()const{return stud_;};
	double get_gamma_c()const{return gamma_c_;}
	double get_dist_e(LengthUnit__ lenght_unit = mm)const{return dist_e_ / lenght_unit;}
	double get_dist_m(LengthUnit__ lenght_unit = mm)const{return dist_m_ / lenght_unit;}
	int get_num_e()const{return num_e_;}
	int get_num_m()const{return num_m_;}

private:

	Stud stud_;
	InternalForcesCalculator intr_frcs_calculator_;
	CompositeSectionGeometry com_sect_;

	double dist_e_ = 0.;
	double dist_m_ = 0.;
	int num_e_ = 0;
	int num_m_ = 0;
	double gamma_c_ = 0.;

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

	void save_stud_basic(std::ostream& ostr)const;
	void load_stud_basic(std::istream& istr);
};


using TStudBasicPair = std::pair <String, TStudBasic>;
using TStudBasicNamedList = std::map <String, TStudBasic>;
using IteratorTStudBasicNamedList = TStudBasicNamedList::iterator;

extern TStudBasicNamedList stud_named_list;
//---------------------------------------------------------------------------
#endif

