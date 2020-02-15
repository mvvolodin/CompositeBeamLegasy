//---------------------------------------------------------------------------

#ifndef CompositeBeamH
#define CompositeBeamH


#include <vector>
//---------------------------------------------------------------------------
#include "GeometryUnit.h"
#include "LoadsUnit.h"

#include "ISectionInitialDataUnit.h"
#include "Steel.h"
#include "CompositeSection.h"
#include "InternalForces.h"
#include "UnitStud.h"
#include "Rebar.h"
#include "WorkingConditionsFactors.h"
#include "Stresses.h"
#include "Ratios.h"

//---------------------------------------------------------------------------
enum class AnalysisTheory{  //Уточнить названия
	ELASTO_PLASTCIC,
	RIGID
};

class TCompositeBeam{

	using StressesList=std::vector<Stresses> ;
	using StressesNamedList=std::map<Impact, StressesList> ;
	using StressesNamedListItem=std::pair <Impact, StressesList> ;
	using StressesNamedListIterator=StressesNamedList::iterator ;

	using RatiosList=std::vector<Ratios> ;
	using RatiosListIterator=RatiosList::iterator ;
	using RatiosNamedList=std::map<Impact, RatiosList> ;
	using RatiosNamedListItem=std::pair <Impact, RatiosList> ;
	using RatiosNamedListIterator=RatiosNamedList::iterator ;

public:
	TCompositeBeam();
	TCompositeBeam(AnalysisTheory           analysis_theory,
				   TGeometry 				geometry,
				   TLoads 					loads,
				   CompositeSection         composite_section,
				   TStud 					stud,
				   WorkingConditionsFactors working_conditions_factors);

	inline CompositeSection get_composite_section()const{return composite_section_;}//Уродливая запись!!!//Но возвращается ссылка на объект
	inline InternalForcesNamedList get_internal_forces_LC()const{return internal_forces_;}
	inline std::vector<double> get_CS_coordinates()const {return cs_coordinates_;}
	inline TStud get_studs()const {return studs_;}
	inline TGeometry get_geometry()const {return geometry_;}
	inline TLoads get_loads()const {return loads_;}
	inline WorkingConditionsFactors get_working_conditions_factors() const {return working_conditions_factors_;}

	String get_analysis_theory();
	double get_max_upper_flange_ratio();
	double get_max_lower_flange_ratio();

private:
//Поля с исходными данными
	AnalysisTheory analysis_theory_;
	TGeometry geometry_;
	TLoads loads_;
	WorkingConditionsFactors working_conditions_factors_;
	CompositeSection composite_section_;
	TStud studs_;
//Поля с результатами расчётов
	std::vector<double> cs_coordinates_;
	std::vector<double> cs_coordinates_shear_;//координаты сечений для определения сдвигающих усилий
	int cs_num_;//количество расчётных сечений.ВСЕ ЦИКЛЫ ДОЛЖНЫ ЕГО ПРИМЕНЯТЬ!!!!
	InternalForcesNamedList internal_forces_;
//Поля с результатами расчётов полей напряжений
	StressesNamedList stresses_named_list_; //
//Поля с результатами расчётов полей коэффициенты использования
	RatiosNamedList ratios_named_list_;//std::map<Impact, StressesList> StressesNamedList//std::vector<Stresses> StressesList

	double gamma_1_;//коэффициент условий работы верхнего пояса



private:
	void calculate_gamma_1();
	void CS_coordinates_calc();
	void calc_cs_coordinates_studs_verification();
	void calc_inter_forces();
	void calc_stresses();
	void calc_ratios();
	void calc_stud_ratios();
//Расчёт напряжений
	void calculate_stresses();
 // Расчёт коэффициентов использования
	Ratios calculate_I_case(Impact impact, int cs_id);
	Ratios calculate_II_case(Impact impact, int cs_id);
	Ratios calculate_III_case(Impact impact, int cs_id);

//Выовод в лог
	void log_stresses();
 };

#endif

//class TheoryCalculator
//{
//virtual calc1();
//virtual void calc1(CompositeBeam* compos_beam)=0;
//}
//
//class Theory1Calculator:TheoryCalculator
//{
//	public:
// calc(CompositeBeam* compos_beam)
//	{
//	void calc2();
//	calc3();
//	}
//	private:
//    void calc2();
//    void calc3();
//}
//
//class Theory2Calculator:TheoryCalculator
//{
//	public:
// calc(CompositeBeam* compos_beam)
//	{
//	calc3()
//	}
//	private:
//	void calc3();
//}
//
//class TheoryFactory
//{
//    virtual void TheoryCalculator createCalculator()=0;
//}
//
//class Theory1Factory:TheoryFactory
//{
//	TheoryCalculator createCalculator()
//    {
//        return new Theory1Calculator();
//	}
//}
//class Theory2Factory:TheoryFactory
//{
//	TheoryCalculator createCalculator()
//    {
//        return new Theory2Calculator();
//	}
//}
//
//main()
//{
//TheoryFactory* theoryFactory;
//
//if(....)
//theoryFactory=new Theory1Factory();
//
//TheoryCalculator *calc = theoryFactory->createCalculator(&balka);
//calc->calc();
//
//}
