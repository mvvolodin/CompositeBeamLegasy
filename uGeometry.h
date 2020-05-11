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

class TGeometry{

public:
    public:
	TGeometry();
	TGeometry(int beam_division, bool end_beam, double L, double B_l, double B_r,
			  int temporary_supports_number);

	void set_default_values();
	void save(ostream& ostr) const;
	void load(istream& istr);
	inline bool is_end_beam()const {return end_beam_;}
	String is_end_beam_to_str()const;
	double get_span(LengthUnit length_units=LengthUnit::mm)const {return L_/static_cast<int>(length_units);}
	double get_trib_width_left(LengthUnit length_units=LengthUnit::mm) const {return B_l_/static_cast<int>(length_units);}
	double get_trib_width_right(LengthUnit length_units=LengthUnit::mm)const {return B_r_/static_cast<int>(length_units);}
	int get_beam_division()const{return beam_division_;}
	double get_effective_width(double h_f, double b_uf);
	int get_permanent_supports_number()const{return permanent_supports_number_;}
	int get_temporary_supports_number()const{return temporary_supports_number_;}
	std::vector<double> get_permanent_supports_coordinates()const {return permanent_supports_coordinates_;}
	std::vector<double> get_temporary_supports_coordinates()const {return temporary_supports_coordinates_;}
	std::vector<double> get_all_supports_coordinates()const {return all_supports_coordinates_;}
private:
	bool end_beam_ = false;
	bool effective_width_calculated_ = false;
	double L_ = 0.;
	double B_l_ = 0.;
	double B_r_ = 0.;
	SupportsNumber num_tmp_supp = SupportsNumber::ZERO;
	int temporary_supports_number_ = 0;
	static const int permanent_supports_number_ = 2;//при удаление ключевого слова static и применение member initializer list получаю ошибку "copy assignment operator is implicitly delete"
	int beam_division_ = 0;

	double b_l_ = 0.;//расчётный вес плиты слева
	double b_r_ = 0.;//расчётный вес плиты справа
	std::vector<double> permanent_supports_coordinates_;
	std::vector<double> temporary_supports_coordinates_;
	std::vector<double> all_supports_coordinates_;
	void permanent_supports_coordinates_calculation();
	void temporary_supports_coordinates_calculation();
	void all_supports_coordinates_calculation();

	void calculate_effective_width(double h_f, double b_uf);
	double basic_effective_width(double h_f, double a,  double B, double l);
	double cantilever_effective_width(double t_sl, double a,  double B, double l);
};
#endif
