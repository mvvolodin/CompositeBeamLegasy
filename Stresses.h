//---------------------------------------------------------------------------

#ifndef StressesH
#define StressesH

//#include "CompositeBeam.h" //ѕочему не компилируетс€ с одним #include "CompositeBeam.h"   http://www.cplusplus.com/forum/articles/10627/
#include "CompositeSection.h"
#include "InternalForces.h"
#include "WorkingConditionsFactors.h"

enum class StressState{ //наименовани€ не очень симпатичные
	elastic,
	plastic
};
//---------------------------------------------------------------------------
class Stresses{ // ак образуетс€ множественна€ форма Stresses?

	typedef std::vector<double> SigmaB_List;//один и тот же тип под разными псевдонимами.
	typedef std::vector<double> SigmaS_List;// это хороша€ практика?
	typedef std::vector<StressState> StressStateList;

private:

	SigmaB_List sigma_b_;//напр€жени€ в бетоне на уровне центра т€жести плиты
	SigmaS_List sigma_s_;//напр€жени€ в арматуре соответствующие деформаци€м в бетоне при напр€жении sigma_b
	StressStateList state_sigma_b_;
	StressStateList state_sigma_s_;

private:
	void calculate_stresses(InternalForces internal_forces, CompositeSection composite_section);

	void define_stress_state(CompositeSection 			composite_section,
							 WorkingConditionsFactors 	working_conditions_factors);

public:
    Stresses();
	Stresses(InternalForces iternal_forces, CompositeSection composite_section, WorkingConditionsFactors 	working_conditions_factor);
	inline SigmaB_List get_sigma_b()const {return sigma_b_;}
	inline SigmaS_List get_sigma_s()const {return sigma_s_;}
	inline StressStateList get_state_sigma_b()const {return state_sigma_b_;}
	inline StressStateList get_state_sigma_s()const {return state_sigma_s_;}
};

 typedef std::map<LoadCaseNames, Stresses> StressesNamedList;
 typedef std::pair <LoadCaseNames, Stresses> StressesNamedListItem;
 typedef StressesNamedList::iterator StressesNamedListIterator;

#endif
