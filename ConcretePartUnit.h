// ---------------------------------------------------------------------------
#ifndef ConcretePartUnitH
#define ConcretePartUnitH
// ---------------------------------------------------------------------------
#include <ostream>
#include <istream>
// ---------------------------------------------------------------------------
#include "GeometryUnit.h"
#include "Concrete.h"
#include "Rebar.h"
#include "CorrugatedSheet.h"
#include "Units.h"
// ---------------------------------------------------------------------------
enum class SlabType{
	FLAT,
	CORRUGATED,
};
// ---------------------------------------------------------------------------
class TConcretePart {

public:

	TConcretePart();
	TConcretePart(String slab_type, SlabType slab_type_enum, Concrete concrete, Rebar rebar, double h_f, double h_n);
	void save(std::ostream& ostr) const;
	void load(std::istream& istr);
	void set_default_values();
	bool get_status()const{return concrete_part_calculated_;}

	void calculate();
	double calculate_SW_concrete();

	String get_slab_type() const {return slab_type_;}
	SlabType get_slab_type_enum() const {return slab_type_enum_;}
	Concrete& get_concrete() {return concrete_;}
	const Concrete& get_concrete()const {return concrete_;}
	Rebar get_rebar() const {return rebar_;}
	double get_SW_concrete(LoadUnit load_unit=LoadUnit::N, LengthUnit length_unit=LengthUnit::mm) const
		{return SW_concrete_/static_cast<int>(load_unit)*std::pow(static_cast<int>(length_unit),2);}
	double get_C_b(LengthUnit length_unit=LengthUnit::mm) const {return C_b_/static_cast<int>(length_unit);}
	double get_h(LengthUnit length_unit=LengthUnit::mm) const {return h_/static_cast<int>(length_unit);}
	double get_h_f(LengthUnit length_unit=LengthUnit::mm) const {return h_f_/static_cast<int>(length_unit);}
	double get_h_n(LengthUnit length_unit=LengthUnit::mm) const {return h_n_/static_cast<int>(length_unit);}
	void set_b_l(double b_l){b_l_ = b_l;}
	void set_b_r(double b_r){b_r_ = b_r;}
	void set_phi_b_cr(double phi_b_cr){concrete_.set_phi_b_cr(phi_b_cr);}
	double get_b_l(LengthUnit length_unit=LengthUnit::mm) const {return b_l_/static_cast<int>(length_unit);} //после добавления b_sl в этой функции нет необходимости. Удалить после изменения кода с вызовами
	double get_b_r(LengthUnit length_unit=LengthUnit::mm) const {return b_r_/static_cast<int>(length_unit);} //после добавления b_sl в этой функции нет необходимости. Удалить после изменения кода с вызовами
	double get_b_sl(LengthUnit length_unit=LengthUnit::mm) const {return (b_r_+ b_l_)/static_cast<int>(length_unit);}
	double get_A_b(LengthUnit length_unit=LengthUnit::mm) const {return A_b_/std::pow(static_cast<int>(length_unit),2);}
	double get_I_b(LengthUnit length_unit=LengthUnit::mm) const {return I_b_/std::pow(static_cast<int>(length_unit),4);}

private:

	String slab_type_;
	SlabType slab_type_enum_;
	Concrete concrete_;
	Rebar rebar_;
	double h_f_ = 0.; // расчётная толщина железобетонной плиты
	double h_n_ = 0.; // расстояние от наружней грани верхней полки двутавра до внутренней грани расчётной железобетонной плиты

	double SW_concrete_ = 0.;//собственный вес железобетонной плиты
	double b_l_ = 0.; // эффективная ширина слева
	double b_r_ = 0.; // эффективная ширина справа
	double h_ = 0.;// высота железобетонной плиты
	double C_b_ = 0.; 	// расстояние от наружней грани верхней полки двутавра до центр тяжести расчётной железобетонной плиты
   	double h_b_ = 0.; //приведённая толщина бетона
	double A_b_ = 0.; // площадь расчётной железобетонной плиты
	double I_b_ = 0.; //момент инерции расчётной железобетонной плиты

	double effective_width_calc(double t_sl, double a, double B, double l);
	double effective_width_cantilever_calc(double t_slc, double a, double С, double l);

	bool concrete_part_calculated_ = false;
};


#endif
