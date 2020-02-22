//---------------------------------------------------------------------------

#ifndef CompositeSectionH
#define CompositeSectionH
#include "ISectionInitialDataUnit.h"
#include "ISection.h"
#include "ConcretePartUnit.h"
#include "Steel.h"
#include "Rebar.h"
#include "SteelPart.h"

using namespace std;

struct TSteelInitialData;//Пробуем forward declaration
class TGeometry;


class CompositeSection {
private:
	double id_;//не используется;
	double coorinate_; //не используется

	ISection steel_part;
	TConcretePart* concrete_part;//абстрактный тип. Есть ли возможность уйти от указателя?
	Steel i_sect_steel; //поместить в тип ISection, сам тип расширить и переименовать TSteelPart

	static ISection steel_part___; //не используется
	static TConcretePart* concrete_part___;  //не используется
	static Steel i_sect_steel___;  //не используется

 //	InternalForces2 internal_forces_;
//	Stresses stresses_;
//	Ratios ratios_;

public:
	double alfa_s_= 0.;//коэффициент приведения к стали
	double alfa_b_= 0.;//коэффициент приведения к бетону
	double H_red_= 0.; //высота композитного сечения
	double A_red_= 0.; //площадь сталежелезобетонного сечения
	double Z_st_r_u_= 0.;//расстояние между Ц.Т. стальной балки и верхней арматурой
	double Z_st_r_l_= 0.;//расстояние между Ц.Т. стальной балки и нижней арматурой
	double Z_b_st_= 0.; //Расстояние между центрами тяжести плиты и стальной балки
	double S_red_= 0.;//Статический момент инерции сталежелезобетонного сечения относительно Ц.Т. стального сечения
	double I_red_= 0.;  //Момент инерции сталежелезобетонного сечения приведённого к металлу
	double Z_st_red_= 0.;//Расстояние между центром тяжести стального и сталежелезобетонного сечения
	double Z_red_f2_= 0.;//Расстояние между Ц.Т. сталежелезобетонного сечения и наружней гранью верхней полки
	double Z_red_f1_= 0.; //Расстояние между Ц.Т. сталежелезобетонного сечения и наружней гранью нижней полки
	double Z_b_red_= 0.;  //Расстояние между Ц.Т. бетонного и сталежелезобетонного сечения
	double Z_red_r_u_= 0.;//Расстояние между Ц.Т. сталежелезобетонного сечения и верхней арматурой
	double Z_red_r_l_= 0.;//Расстояние между Ц.Т. сталежелезобетонного сечения и нижней арматурой
	double W_f2_red_= 0.; //Момент сопротивления сталежелезобетонного сечения для верхней полки
	double W_f1_red_= 0.; //Момент сопротивления сталежелезобетонного сечения для нижней полки
	double W_b_red_= 0.;//Момент сопротивления сталежелезобетонного сечения для Ц.Т. железобетонной плиты
public:
	CompositeSection();
	CompositeSection(SteelPart    steel_part,
					 TConcretePart* concrete_part);
	CompositeSection(TGeometry geometry,
					  Steel steel_i_section,
					  TISectionInitialData i_sect_initial_data,
					  TConcretePart* concrete_part);
private:
	void alfa_to_rebar_steel_calc();
	void alfa_to_concrete_calc();
	void compos_sect_height_calc();
	void compos_sect_area_calc();
	void dist_conc_to_steel_calc();
	void first_moment_of_area_comp_calc();
	void dist_steel_to_compos_calc();
	void inertia_compos_calc();
	void dist_compos_to_upper_fl_calc();
	void dist_compos_to_lower_fl_calc();
	void dist_conc_to_compos_calc();
	void sect_modulus_upper_fl();
	void sect_modulus_lower_fl();
	void sect_modulus_conc();
public:
	inline ISection get_steel_part()const {return steel_part;}
	inline TConcretePart* get_concrete_part()const {return concrete_part;}
	inline Steel get_steel_grade()const {return i_sect_steel;}
	inline double get_alfa_b() const {return alfa_b_;}
	inline double get_alfa_s() const {return alfa_s_;}
	inline double get_A_red(LengthUnit length_unit=LengthUnit::mm) const {return A_red_/std::pow(static_cast<int>(length_unit),2);}
	inline double get_I_red(LengthUnit length_unit=LengthUnit::mm) const {return I_red_/std::pow(static_cast<int>(length_unit),4);}
	inline double get_W_b_red(LengthUnit length_unit=LengthUnit::mm) const {return W_b_red_/std::pow(static_cast<int>(length_unit),3);}
	inline double get_W_f2_red(LengthUnit length_unit=LengthUnit::mm) const {return W_f2_red_/std::pow(static_cast<int>(length_unit),3);}
	inline double get_W_f1_red(LengthUnit length_unit=LengthUnit::mm) const {return W_f1_red_/std::pow(static_cast<int>(length_unit),3);}
	inline double get_Z_b_red(LengthUnit length_unit=LengthUnit::mm) const {return Z_b_red_/static_cast<int>(length_unit);}
	inline double get_Z_f2_red(LengthUnit length_unit=LengthUnit::mm) const {return Z_red_f2_/static_cast<int>(length_unit);}
	inline double get_Z_f1_red(LengthUnit length_unit=LengthUnit::mm) const {return Z_red_f1_/static_cast<int>(length_unit);}
	inline double get_Z_b_st(LengthUnit length_unit=LengthUnit::mm) const {return Z_b_st_/static_cast<int>(length_unit);}
} ;
//---------------------------------------------------------------------------
#endif


