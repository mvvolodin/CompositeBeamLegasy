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
//При формирование класса с Коэффициентами Использования попробуем подход отличный от принятого
//при формировании класса Усилий и Напряжений.
// Суть в том, что объект класса описывет КИ в СЕЧЕНИИ, а не в балке. Коэффициенты Использования в балке будут представлены
// типом std::vector<Ratios>; Коэффициенты Использования в балке от случаев загружения будут представлены типом
//std::map<enum LC, std::vector<Ratios>>
//НЕОБХОДИМО БУДЕТ СРАВНИТЬ ЭТОТ КЛАСС С КЛАССАМИ НАПРЯЖЕНИЯ И УСИЛИЯ ПО УДОБСТВУ ИСПОЛЬЗОВАНИЯ.
class Ratios{//слишком много передаётся параметров. Вероятно лучше перенести функции в CompositeBeam
private:
	double ratio_upper_flange_;
	double ratio_lower_flange_;
public:
	Ratios(WorkingConditionsFactors working_conditions_factors,
		   CompositeSection 		composite_section,
		   double 					M,
		   double 					Q,
		   double 					sigma_b,
		   double 					sigma_s,
		   StressState 				sigma_b_state,
		   StressState 				sigma_s_state);
private:
	void calculate_I_case(WorkingConditionsFactors working_conditions_factors,
						  CompositeSection		   composite_section,
						  double 				   M,
						  double 				   Q,
						  double 				   sigma_b,
						  double 				   sigma_s,
						  StressState 			   sigma_b_state,
						  StressState 			   sigma_s_state);
	void calculate_II_case(WorkingConditionsFactors working_conditions_factors,
						  CompositeSection		   composite_section,
						  double 				   M,
						  double 				   Q,
						  double 				   sigma_b,
						  double 				   sigma_s,
						  StressState 			   sigma_b_state,
						  StressState 			   sigma_s_state);
	void calculate_III_case(WorkingConditionsFactors working_conditions_factors,
						  CompositeSection		   composite_section,
						  double 				   M,
						  double 				   Q,
						  double 				   sigma_b,
						  double 				   sigma_s,
						  StressState 			   sigma_b_state,
						  StressState 			   sigma_s_state);
public:
	double get_ratio_upper_flange()const {return ratio_upper_flange_;}
    double get_ratio_lower_flange()const {return ratio_lower_flange_;}
};

 typedef std::vector<Ratios> RatiosList;
 typedef std::map<LoadCaseNames, RatiosList> RatiosNamedList;
 typedef std::pair <LoadCaseNames, RatiosList> RatiosNamedListItem;
 typedef InternalForcesNamededList::iterator RatiosNamedListIterator;
#endif
