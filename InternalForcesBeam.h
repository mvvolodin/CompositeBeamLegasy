//---------------------------------------------------------------------------

#ifndef InternalForcesBeamH
#define InternalForcesBeamH
//---------------------------------------------------------------------------
#include <vector>
#include <map>

class InternalForcesBeam{

	using CS_Id = int;
	using X = double;
	using R = double;

	struct InternalForces{
		double M_;
		double Q_;
	};

public:

	InternalForcesBeam();
	InternalForcesBeam(std::vector<X> );
	auto get_internal_forces(CS_Id cs_id);

	void add_internal_forces(double impact, int num_temp_supports);//формируем pairs

private:

	std::map<CS_Id, std::pair<X, InternalForces>> ifb_;
	std::map<CS_Id, std::pair<X, R>> rb_; //реакции


};
#endif
