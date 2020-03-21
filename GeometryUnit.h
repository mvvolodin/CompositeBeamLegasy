//---------------------------------------------------------------------------

#ifndef GeometryUnitH
#define GeometryUnitH
//---------------------------------------------------------------------------
#include <vector>
#include <ostream>
#include <istream>
#include "Units.h"
#include <system.hpp>

class TGeometry{

public:
    public:
	TGeometry();
	TGeometry(int beam_division, bool end_beam, double span, double trib_width_left, double trib_width_right,
			  int temporary_supports_number);

	void set_default_values();
	void save_geometry(ostream& ostr) const;
	void load_geometry(istream& istr);
	inline bool is_end_beam()const {return end_beam_;}
	String is_end_beam_to_str()const;
	double get_span(LengthUnit length_units=LengthUnit::mm)const {return span_/static_cast<int>(length_units);}
	double get_trib_width_left(LengthUnit length_units=LengthUnit::mm) const {return trib_width_left_/static_cast<int>(length_units);}
	double get_trib_width_right(LengthUnit length_units=LengthUnit::mm)const {return trib_width_right_/static_cast<int>(length_units);}
	int get_beam_division()const{return beam_division_;}
	int get_permanent_supports_number()const{return permanent_supports_number_;}
	int get_temporary_supports_number()const{return temporary_supports_number_;}
	std::vector<double> get_permanent_supports_coordinates()const {return permanent_supports_coordinates_;}
	std::vector<double> get_temporary_supports_coordinates()const {return temporary_supports_coordinates_;}
	std::vector<double> get_all_supports_coordinates()const {return all_supports_coordinates_;}
private:
	bool end_beam_ = false;
	double span_ = 0.;
	double trib_width_left_ = 0.;
	double trib_width_right_ = 0.;
	int temporary_supports_number_ = 0;
	static const int permanent_supports_number_ = 2;//при удаление ключевого слова static и применение member initializer list получаю ошибку "copy assignment operator is implicitly delete"
	int beam_division_ = 0;
	std::vector<double> permanent_supports_coordinates_;
	std::vector<double> temporary_supports_coordinates_;
	std::vector<double> all_supports_coordinates_;
	void permanent_supports_coordinates_calculation();
	void temporary_supports_coordinates_calculation();
	void all_supports_coordinates_calculation();
};
#endif
