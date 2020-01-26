//---------------------------------------------------------------------------

#ifndef InternalForcesH
#define InternalForcesH
//---------------------------------------------------------------------------
 #include <vector>
 #include <map>
 #include <algorithm>
 #include "Units.h"

 enum class LoadCaseNames{
	SW,
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
public:
	inline void add_M(double M){M_.push_back(M);}
	inline void add_Q(double Q){Q_.push_back(Q);}
	M_List get_M(LoadUnit load_unit=LoadUnit::N,LengthUnit length_unit=LengthUnit::mm)const;
	Q_List get_Q(LoadUnit load_unit=LoadUnit::N)const;
	Q_JumpList get_Q_jump(LoadUnit load_unit=LoadUnit::N) const;
	inline R_List get_R_internal() const {return R_;}

public:
	InternalForces();
	InternalForces(double p, CS_Coordinates cs_coordinates, int temporary_supports_number);
private:
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

typedef std::map<LoadCaseNames, InternalForces> InternalForcesNamededList;
typedef std::pair <LoadCaseNames, InternalForces> InternalForcesNamededListItem;
typedef InternalForcesNamededList::iterator InternalForcesNamededListIterator;
#endif
