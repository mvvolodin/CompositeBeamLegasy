//---------------------------------------------------------------------------

#ifndef uGeometryH
#define uGeometryH
//---------------------------------------------------------------------------
#include <vector>
#include <ostream>
#include <istream>
#include "Units.h"
#include <system.hpp>

enum class SupportsNumber{
	ZERO,
	ONE,
	TWO,
	THREE
};

class Geometry{

public:
    public:
	Geometry();
	Geometry(bool end_beam, double L, double B_l, double B_r, SupportsNumber temp_supports_num);

	void set_default_values();
	void save(ostream& ostr) const;
	void load(istream& istr);
	inline bool is_end_beam()const {return end_beam_;}
	String is_end_beam_to_str()const;
	double get_span(LengthUnit length_units=LengthUnit::mm)const {return L_/static_cast<int>(length_units);}
	double get_spacing_left(LengthUnit length_units=LengthUnit::mm) const {return B_l_/static_cast<int>(length_units);}
	double get_spacing_right(LengthUnit length_units=LengthUnit::mm)const {return B_r_/static_cast<int>(length_units);}
	double get_trib_width(LengthUnit length_units=LengthUnit::mm)const;
	double get_effective_width(double h_f, double b_uf);

	SupportsNumber get_temporary_supports_number()const{return temp_supports_num_;}

private:
	bool end_beam_ = false;
	bool effective_width_calculated_ = false;
	double L_ = 0.;
	double B_l_ = 0.;
	double B_r_ = 0.;
	SupportsNumber temp_supports_num_ = SupportsNumber::ZERO;

	double b_l_ = 0.;
	double b_r_ = 0.;

	void calculate_effective_width(double h_f, double b_uf);
	double basic_effective_width(double h_f, double a,  double B, double l);
	double cantilever_effective_width(double t_sl, double a,  double B, double l);
};
#endif
