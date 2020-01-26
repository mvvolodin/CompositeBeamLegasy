//---------------------------------------------------------------------------

#ifndef GeometryUnitH
#define GeometryUnitH
//---------------------------------------------------------------------------
#include <vector>
#include "Units.h"

class TGeometry{

public:
    public:
	TGeometry();
	TGeometry(int beam_division, bool end_beam, double span, double trib_width_left, double trib_width_right,
			  int temporary_supports_number);
	inline bool is_end_beam()const {return end_beam_;}
	inline double get_span(LengthUnit length_units=LengthUnit::mm)const {return span_/static_cast<int>(length_units);}
	inline double get_trib_width_left(LengthUnit length_units=LengthUnit::mm) const {return trib_width_left_/static_cast<int>(length_units);}
	inline double get_trib_width_right(LengthUnit length_units=LengthUnit::mm)const {return trib_width_right_/static_cast<int>(length_units);}
	inline int get_beam_division()const{return beam_division_;}
	inline int get_permanent_supports_number()const{return permanent_supports_number_;}
	inline int get_temporary_supports_number()const{return temporary_supports_number_;}
	inline std::vector<double> get_permanent_supports_coordinates()const {return permanent_supports_coordinates_;}
	inline std::vector<double> get_temporary_supports_coordinates()const {return temporary_supports_coordinates_;}
	inline std::vector<double> get_all_supports_coordinates()const {return all_supports_coordinates_;}
private:
	bool end_beam_=false;
	double span_=0.0;
	double trib_width_left_=0.0;
	double trib_width_right_=0.0;
	int temporary_supports_number_=0; //количество опопр на стадии бетонировани€. —ледует применить enum.
	static const int permanent_supports_number_=2;//при удаление ключевого слова static и применение member initializer list получаю ошибку "copy assignment operator is implicitly delete"
	int beam_division_=0;//разбиение балки
	std::vector<double> permanent_supports_coordinates_={0};
	std::vector<double> temporary_supports_coordinates_={0};
	std::vector<double> all_supports_coordinates_={0};
private:
	void permanent_supports_coordinates_calculation();
	void temporary_supports_coordinates_calculation();
	void all_supports_coordinates_calculation();




};
#endif
