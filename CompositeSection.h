//---------------------------------------------------------------------------

#ifndef CompositeSectionH
#define CompositeSectionH
#include <ostream>
#include "ISection.h"
#include "ConcretePartUnit.h"
#include "uSteel.h"
#include "uRebar.h"
#include "SteelPart.h"

class CompositeSection{
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
private:

	SteelPart steel_part_;
	TConcretePart concrete_part_;

	bool composite_section_calculated = false;

	double b_ = 0.;//расчётная ширина плиты
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
	double W_b_st_ = 0.;//условный момент сопротивления на уровне центр тяжести сечения бетона

	double M_Rd_ = 0.;

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
	void fictitious_modulus();

	void calc_rigid_plastic_moment();
	NeutralAxis calc_neutral_axis();

public:
	CompositeSection();
	CompositeSection(SteelPart    steel_part,
					 TConcretePart concrete_part);
	void set_default_values();
	void save(std::ostream& ostr)const;
	void load(std::istream& istr);
	void calculate();
	SteelPart get_steel_part()const {return steel_part_;}
	ISection get_I_section()const {return steel_part_.get_section();}
	TConcretePart get_concrete_part() const {return concrete_part_;}
	TConcretePart& get_concrete_part() {return concrete_part_;}
	Steel get_steel_grade()const {return steel_part_.get_steel();}

	void set_phi_b_cr(double phi_b_cr);
	void set_b(double b){concrete_part_.set_b(b);}

	double get_alfa_b() const {return alfa_b_;}
	double get_alfa_s() const {return alfa_s_;}
	double get_A_red(LengthUnit length_unit=LengthUnit::mm) const {return A_red_/std::pow(static_cast<int>(length_unit),2);}
	double get_I_red(LengthUnit length_unit=LengthUnit::mm) const {return I_red_/std::pow(static_cast<int>(length_unit),4);}
	double get_W_b_red(LengthUnit length_unit=LengthUnit::mm) const {return W_b_red_/std::pow(static_cast<int>(length_unit),3);}
	double get_W_f2_red(LengthUnit length_unit=LengthUnit::mm) const {return W_f2_red_/std::pow(static_cast<int>(length_unit),3);}
	double get_W_f1_red(LengthUnit length_unit=LengthUnit::mm) const {return W_f1_red_/std::pow(static_cast<int>(length_unit),3);}
	double get_Z_b_red(LengthUnit length_unit=LengthUnit::mm) const {return Z_b_red_/static_cast<int>(length_unit);}
	double get_Z_f2_red(LengthUnit length_unit=LengthUnit::mm) const {return Z_red_f2_/static_cast<int>(length_unit);}
	double get_Z_f1_red(LengthUnit length_unit=LengthUnit::mm) const {return Z_red_f1_/static_cast<int>(length_unit);}
	double get_Z_b_st(LengthUnit length_unit=LengthUnit::mm) const {return Z_b_st_/static_cast<int>(length_unit);}
	double get_W_b_st(LengthUnit length_unit=LengthUnit::mm) const {return W_b_st_/std::pow(static_cast<int>(length_unit),3);}

	double get_b_s()const {return concrete_part_.get_rebar().get_b_s();}
	double get_M_Rd()const {return M_Rd_;}
	double get_Q_Rd()const;


} ;
//---------------------------------------------------------------------------
#endif


