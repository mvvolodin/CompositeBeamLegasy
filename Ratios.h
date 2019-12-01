//---------------------------------------------------------------------------

#ifndef RatiosH
#define RatiosH
//---------------------------------------------------------------------------
#include "Stresses.h"
#include "InternalForces.h"
enum class LoadBearingStateClass{ //придумать содержательные названия
 CASE_I,
 CASE_II,
 CASE_III
};

class Ratios{//слишком много передаётся параметров. Вероятно лучше перенести функции в CompositeBeam
private:
	double ratio_upper_flange;
	double ratio_lower_flange;
private:

	void calculate_I_case(CompositeSection composite_section, InternalForces internal_forces, Stresses stresses)
	{
		double Z_b_st=composite_section.get_Z_b_st();
		double W_f2_st=composite_section.get_steel_part().get_Wf2_st();
		double W_f1_t=composite_section.get_steel_part().get_Wf1_st();
		double A_st=composite_section.get_steel_part().get_A_st();
		double A_b=composite_section.get_concrete_part()->get_A_b();
	//	double sigma_b=stresses.get_sigma_b();
	 //	double sigma_s=stresses.get_sigma_s();
	}
	   void	calculate_II_case()
	{
		//double Z_b_st=composite_section.
	}
	   void	calculate_III_case()
	{
		//double Z_b_st=composite_section.
	}
Ratios(CompositeSection composite_section, InternalForces internal_forces, Stresses stresses)
{
	switch(1)
	{
	case(1):
	calculate_I_case(composite_section, internal_forces, stresses);

		break;
	case(2):
	 calculate_II_case();

		break;
	case(3):
	 calculate_III_case();
		break;
	 }
}
};
#endif
