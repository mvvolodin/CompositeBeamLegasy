//---------------------------------------------------------------------------

#ifndef StressesH
#define StressesH

#include "CompositeSection.h"
#include "InternalForces.h"
#include "WorkingConditionsFactors.h"


enum StressStateCase{ //придумать содержательные названия
	UNDEFINED = 1,
	CASE_I,
	CASE_II,
	CASE_III,
};
//---------------------------------------------------------------------------
struct Stresses{ //Как образуется множественная форма Stresses?
public:
	Stresses();
	Stresses (double sigma_b, double sigma_s, StressStateCase stress_state_case);
	inline double get_sigma_b()const {return sigma_b_;}
	inline double get_sigma_s()const {return sigma_s_;}
//	inline void add_sigma_b(double sigma_b){sigma_b_.push_back(sigma_b);}
//	inline void add_sigma_s(double sigma_s){sigma_s_.push_back(sigma_s);}
	inline StressStateCase get_state() const {return stress_state_case_;}
private:

	double sigma_b_ = 0.;//напряжения в бетоне на уровне центра тяжести плиты
	double sigma_s_ = 0.;//напряжения в арматуре соответствующие деформациям в бетоне при напряжении sigma_b
	StressStateCase stress_state_case_ = UNDEFINED;
};

#endif
