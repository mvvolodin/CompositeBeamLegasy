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
#include "StudUnit.h"
#include "Rebar.h"
#include "WorkingConditionsFactors.h"
#include "Stresses.h"
//---------------------------------------------------------------------------

class TCompositeBeam{
private:
	typedef std::vector<double> CS_Coordinates;
private:
//Базовые поля
	//int beam_division_;
	TGeometry geometry_;
	TLoads loads_;
	WorkingConditionsFactors working_conditions_factors_;
	CompositeSection composite_section_;
	TStud stud_;

//прозводные поля
	CS_Coordinates cs_coordinates_;
	InternalForcesNamededList internal_forces_LC_;
	InternalForces internal_forces_I_;
	InternalForces internal_forces_II_;
	InternalForces internal_forces_total_;

//Производные поля напряжения

	StressesNamedList stresses_LC_;
	Stresses stresses_I_;
	Stresses stresses_II_;
	Stresses stresses_total_;

	std::vector<double> test_M_;
    std::vector<double> test_Q_;
	//StressesNamedList stresses_;
	double gamma_1_;//коэффициент условий работы верхнего пояса

private:
	void calculate_gamma_1();
	void CS_coordinates_calc();
	void calc_inter_forces();
	void calc_stresses();

public:
	TCompositeBeam();
	TCompositeBeam(TGeometry 				geometry,
				   TLoads 					loads,
				   CompositeSection         composite_section,
				   TStud 					stud,
				   WorkingConditionsFactors working_conditions_factors);

inline CompositeSection get_composite_section()const{return composite_section_;}//Уродливая запись!!!//Но возвращается ссылка на объект
inline InternalForcesNamededList get_internal_forces_LC()const{return internal_forces_LC_;}
inline InternalForces get_internal_forces_I()const{return internal_forces_I_;}
inline InternalForces get_internal_forces_II()const{return internal_forces_II_;}
inline InternalForces get_internal_forces_total()const{return internal_forces_total_;}
inline CS_Coordinates get_CS_coordinates()const {return cs_coordinates_;}
inline TGeometry get_geometry()const {return geometry_;}
inline TLoads get_loads()const {return loads_;}

 };

#endif
