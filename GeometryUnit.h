//---------------------------------------------------------------------------

#ifndef GeometryUnitH
#define GeometryUnitH
//---------------------------------------------------------------------------
#include <vector>


class TGeometry{
private:
	typedef std::vector<double> CoordinatesList;
	bool end_beam_;
	double span_;
	double trib_width_left_;
	double trib_width_right_;
	int temporary_supports_number_; //количество опопр на стадии бетонировани€. —ледует применить enum.
	static const int permanent_supports_number_=2;//при удаление ключевого слова static и применение member initializer list получаю ошибку "copy assignment operator is implicitly delete"
	//const int permanent_supports_number_=2;  //

	int beam_division_;//разбиение балки
	CoordinatesList permanent_supports_coordinates_;
	CoordinatesList temporary_supports_coordinates_;
	CoordinatesList all_supports_coordinates_;

private:
	void permanent_supports_coordinates_calculation();
	void temporary_supports_coordinates_calculation();
	void all_supports_coordinates_calculation();

public:
	TGeometry();
	TGeometry(int beam_division, bool end_beam, double span, double trib_width_left, double trib_width_right,
			  int temporary_supports_number);

	inline bool is_end_beam()const {return end_beam_;}
	inline double get_span()const {return span_;}
	inline double get_trib_width_left() const {return trib_width_left_;}
	inline double get_trib_width_right()const {return trib_width_right_;}
	inline int get_beam_division()const{return beam_division_;}
	inline int get_permanent_supports_number()const{return permanent_supports_number_;}
	inline int get_temporary_supports_number()const{return temporary_supports_number_;}
	inline CoordinatesList get_permanent_supports_coordinates()const {return permanent_supports_coordinates_;}
	inline CoordinatesList get_temporary_supports_coordinates()const {return temporary_supports_coordinates_;}
	inline CoordinatesList get_all_supports_coordinates()const {return all_supports_coordinates_;}
};
#endif
