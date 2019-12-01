//---------------------------------------------------------------------------

#ifndef GeometryUnitH
#define GeometryUnitH
//---------------------------------------------------------------------------

class TGeometry{
private:
	bool end_beam_;
	double span_;
	double trib_width_left_;
	double trib_width_right_;
	int propping_number_; //количество опопр на стадии бетонирования. Следует применить enum.
	int beam_division_;//количества сечений где определены услилия

public:
	TGeometry();
	TGeometry(bool end_beam, double span, double trib_width_left, double trib_width_right,
			  int propping_number);

	inline bool is_end_beam()const {return end_beam_;}
	inline double get_span()const {return span_;}
	inline double get_trib_width_left() const {return trib_width_left_;}
	inline double get_trib_width_right()const {return trib_width_right_;}
	inline int get_propping_number()const {return propping_number_;};
};
#endif
