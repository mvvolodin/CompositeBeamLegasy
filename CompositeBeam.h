//---------------------------------------------------------------------------

#ifndef CompositeBeamH
#define CompositeBeamH


#include <vector>
#include <ostream>
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
#include "CorrugatedSheet.h"

class TCompositeBeam{


	enum class NA_Location{
	CONCRETE,
	UPPER_FLANGE,
	WEB,
	NO_SOLUTION
	};

	struct NeutralAxis{
		NA_Location na_location_;
		double x_na_; //Расстояние от наружней грани сталежелезобетонной балки до нейтральной оси
	};

	using StressesList=std::vector<Stresses> ;
	using StressesNamedList=std::map<Impact, StressesList> ;
	using StressesNamedListItem=std::pair <Impact, StressesList> ;
	using StressesNamedListIterator=StressesNamedList::iterator ;

	using RatiosList=std::vector<Ratios> ;
	using RatiosListIterator=RatiosList::iterator;
	using RatiosNamedList=std::map<Impact, RatiosList> ;
	using RatiosNamedListItem=std::pair <Impact, RatiosList> ;
	using RatiosNamedListIterator=RatiosNamedList::iterator ;


public:
	TCompositeBeam();
	TCompositeBeam(TGeometry 				geometry,
				   TLoads 					loads,
				   CompositeSection         composite_section,
				   Studs 					stud,
				   WorkingConditionsFactors working_conditions_factors);
	void set_default_values();
	void save(std::ostream& ostr) const;
	void load(std::istream& istr);
	void calculate();
	CompositeSection get_composite_section()const{return composite_section_;}//Уродливая запись!!!//Но возвращается ссылка на объект
	InternalForcesNamedList get_internal_forces_LC()const{return internal_forces_;}
	std::vector<double> get_CS_coordinates()const {return cs_coordinates_;}
	Studs get_studs()const {return studs_;}
	TGeometry get_geometry()const {return geometry_;}
	TLoads get_loads()const {return loads_;}
	WorkingConditionsFactors get_working_conditions_factors() const {return working_conditions_factors_;}

	double get_max_upper_flange_ratio();
	double get_max_lower_flange_ratio();
	double get_max_stud_ratio();
	double get_ratio_rigid_plastic() const {return ratio_rigid_plastic_;}
	double get_max_shear_ratio() const {return *std::max_element(shear_ratios_.begin(),shear_ratios_.end());}


private:
//Поля с исходными данными
	TGeometry geometry_; //src- исходные поля...dst - поля с результатами..... aSize,
	TLoads loads_;
	WorkingConditionsFactors working_conditions_factors_;
	CompositeSection composite_section_;
	Studs studs_;
//Поля с результатами расчётов внутренних усилия
	InternalForces if_SW_;
	InternalForces if_sheets_;
	InternalForces if_DL_I_;
	InternalForces if_DL_II_;
	InternalForces if_LL_;

	InternalForces if_stage_I_;
	InternalForces if_stage_II_;
	InternalForces if_stage_total_;

//Поля с результатами расчётов
	std::vector<double> cs_coordinates_;
	std::vector<double> stud_coordinates_;//координаты расположения упоров
	int cs_num_;//количество расчётных сечений.ВСЕ ЦИКЛЫ ДОЛЖНЫ ЕГО ПРИМЕНЯТЬ!!!!
	int studs_num_;//количество поперечных рядов упоров.ВСЕ ЦИКЛЫ ДОЛЖНЫ ЕГО ПРИМЕНЯТЬ!!!!
	InternalForcesNamedList internal_forces_studs_;
	InternalForcesNamedList internal_forces_;
//Поля с результатами расчётов полей напряжений
	StressesNamedList stresses_named_list_; //
	StressesNamedList stresses_named_list_studs_;
    std::vector<double> S_; //Сдвигающие усилия по шву объединения железобетонной плиты и стальной балки
//Поля с результатами расчётов полей коэффициенты использования
	RatiosNamedList ratios_named_list_;//std::map<Impact, StressesList> StressesNamedList//std::vector<Stresses> StressesList
	std::vector<double> ratios_studs_;
	double ratio_rigid_plastic_; //КИ при расчёте в предположении жёстко - пластического материала
	std::vector<double> shear_ratios_;
	double gamma_1_;//коэффициент условий работы верхнего пояса


private:
//Функции доступа к характеристикам композитного сечения
	double get_h_b() const {return composite_section_.get_concrete_part().get_h_b();}
	double get_C_b() const {return composite_section_.get_concrete_part().get_C_b();}
	double get_t_f2() const {return composite_section_.get_steel_part().get_I_section().get_t_uf();}
	double get_t_f1() const {return composite_section_.get_steel_part().get_I_section().get_t_lf();}
	double get_b_f2() const {return composite_section_.get_steel_part().get_I_section().get_b_uf();}
	double get_A_w_st() const {return composite_section_.get_steel_part().get_I_section().get_b_uf();}
	double get_A_b() const {return composite_section_.get_concrete_part().get_A_b();}
	double get_R_s() const {return  composite_section_.get_concrete_part().get_rebar().get_R_s();}
	double get_A_s() const {return  composite_section_.get_concrete_part().get_rebar().get_A_s();}
	double get_R_b() const {return  composite_section_.get_concrete_part().get_concrete().get_R_b();}
	double get_R_y() const {return  composite_section_.get_steel_grade().get_R_y ();}
	double get_A_st() const {return  composite_section_.get_steel_part().get_I_section().get_A_st();}
	double get_A_f1_st() const {return  composite_section_.get_steel_part().get_I_section().get_A_f1_st();}
	double get_A_f2_st() const {return  composite_section_.get_steel_part().get_I_section().get_A_f2_st();}
	double get_b_sl() const {return composite_section_.get_concrete_part().get_b_sl();}
	double get_h_w() const {return composite_section_.get_steel_part().get_I_section().get_h_w();}
	double get_t_w() const {return composite_section_.get_steel_part().get_I_section().get_t_w();}
	double get_Q_Rd() const {return composite_section_.get_steel_part().get_Q_Rd();}
//Функции доступа к коэффициентам
	double get_gamma_c() const {return working_conditions_factors_.get_gamma_c();}

//Функции доступа к усилиям

	std::vector<double> get_M(Impact impact);
    std::vector<double> get_Q(Impact impact);

	void calculate_gamma_1();
	void calc_cs_coordinates(); //определение координат сечений для определения усилий требуемых для проверки балки
	void calc_studs_coordinates(); // определение координат сечений для определения усилий требуемых для упоров
	void calc_inter_forces_for_studs();
	void calc_inter_forces();
	void calc_stresses();
	void calc_ratios();
	void calc_studs_ratios();
	NeutralAxis calc_neutral_axis();
	double calc_rigid_plastic_moment();
	void calc_ratio_rigid_plastic();
	void calc_shear_ratios();
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



