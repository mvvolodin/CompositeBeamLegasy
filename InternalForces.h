//---------------------------------------------------------------------------

#ifndef InternalForcesH
#define InternalForcesH
//---------------------------------------------------------------------------
 #include <vector>
 #include <map>
 #include <algorithm>
 enum class LoadCaseNames{
	SW,
	DL_I,
	DL_II,
	LL
 };

 class InternalForces{
 private:
	typedef std::vector<double> CS_Coordinates;
 public:
	typedef std::vector<double> M_List;
	typedef std::vector<double> Q_List;
 private:
	// int cs_number_;
	 M_List M_; //изгибающие моменты
	 Q_List Q_;//поперечные силы

 public:
  //	inline int get_cs_number()const {return cs_number_;}
	inline void add_M(double M){M_.push_back(M);}
	inline void add_Q(double Q){Q_.push_back(Q);}
	inline M_List get_M()const {return M_;}
	inline Q_List get_Q() const {return Q_;}
 public:
    InternalForces();
	InternalForces(double p, CS_Coordinates cs_coordinates, int propping_number);
 private:
	void M_calc_simple_beam(double p, CS_Coordinates cs_coordinates, int propping_number);
	void M_calc_two_span_beam(double p, CS_Coordinates cs_coordinates, int propping_number); //балки равнопролётные
	void Q_calc_simple_beam(double p, CS_Coordinates cs_coordinates, int propping_number);
	void Q_calc_two_span_beam(double p, CS_Coordinates cs_coordinates, int propping_number);
 };

 typedef std::map<LoadCaseNames, InternalForces> InternalForcesNamededList;
 typedef std::pair <LoadCaseNames, InternalForces> InternalForcesNamededListItem;
 typedef InternalForcesNamededList::iterator InternalForcesNamededListIterator;



#endif
