//---------------------------------------------------------------------------

#ifndef InternalForcesH
#define InternalForcesH
//---------------------------------------------------------------------------
 #include <vector>
 #include <map>
 #include <algorithm>
 #include "Units.h"

 enum class Impact{
	SW_BEAM,
	SW_SHEETS,
	DL_I,
	DL_II,
	LL,
	I_stage,
	II_stage,
	Total
 };
 enum class SupportsNumber{
	Zero,
	One,
	Two,
	Three
};

class InternalForces{
private:
	typedef std::vector<double> CS_Coordinates;
public:
	typedef std::vector<double> M_List;
	typedef std::vector<double> Q_List;
	typedef std::vector<double> Q_JumpList;
	typedef std::vector<double> R_List;
private:
	 M_List M_ ; //изгибающие моменты
	 Q_List Q_ ;//поперечные силы
	 Q_JumpList Q_jump_ ;//реакции внешних опор
	 R_List R_ ;//реакции внутренних опор
	 int num_temp_supports_;
	 std::vector<double> supports_coordinates_;
public:
	InternalForces();
	InternalForces(M_List M, Q_List Q);
	InternalForces(M_List M, Q_List Q, double l, int num_temp_supports);
	InternalForces(double p, CS_Coordinates cs_coordinates, int temporary_supports_number);
	inline void add_M(double M){M_.push_back(M);}
	inline void add_Q(double Q){Q_.push_back(Q);}
	M_List get_M(LoadUnit load_unit=LoadUnit::N,LengthUnit length_unit=LengthUnit::mm)const;
	Q_List get_Q(LoadUnit load_unit=LoadUnit::N)const;
	Q_JumpList get_Q_jump(LoadUnit load_unit=LoadUnit::N) const;
	inline R_List get_R_internal() const {return R_;}
	int get_num_temp_supports(){return num_temp_supports_;}
	auto get_supports_coordinates() {return supports_coordinates_;}

private:
	void calc_supports_coordiantes(double l, int num_temp_supports_);
	void R_calc_simple_beam(double p, double l);
	void R_calc_two_span_beam(double p, double l);
	void R_calc_three_span_beam(double p, double l);
	void R_calc_four_span_beam(double p, double l);
	void M_calc_simple_beam(double p, CS_Coordinates cs_coordinates, int temporary_supports_number);
	void M_calc_two_span_beam(double p, CS_Coordinates cs_coordinates, int temporary_supports_number);
	void M_calc_three_span_beam(double p, CS_Coordinates cs_coordinates, int temporary_supports_number);
	void M_calc_four_span_beam(double p, CS_Coordinates cs_coordinates, int temporary_supports_number);
	void Q_calc_simple_beam(double p, CS_Coordinates cs_coordinates, int temporary_supports_number);
	void Q_calc_two_span_beam(double p, CS_Coordinates cs_coordinates, int temporary_supports_number);
	void Q_calc_three_span_beam(double p, CS_Coordinates cs_coordinates, int temporary_supports_number);
	void Q_calc_four_span_beam(double p, CS_Coordinates cs_coordinates, int temporary_supports_number);
};

typedef std::map<Impact, InternalForces> InternalForcesNamedList;
typedef std::pair <Impact, InternalForces> InternalForcesNamedListItem;
typedef InternalForcesNamedList::iterator InternalForcesNamedListIterator;
#endif
