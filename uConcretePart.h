// ---------------------------------------------------------------------------
#ifndef uConcretePartH
#define uConcretePartH
// ---------------------------------------------------------------------------
#include <ostream>
#include <istream>
// ---------------------------------------------------------------------------
#include "uGeometry.h"
#include "uConcrete.h"
#include "uRebar.h"
#include "uCorrugatedSheet.h"
#include "Units.h"
// ---------------------------------------------------------------------------
enum class SlabType{
	FLAT,
	CORRUGATED,
};
// ---------------------------------------------------------------------------
class ConcretePart {

public:

	ConcretePart();
	ConcretePart(String slab_type, SlabType slab_type_enum, Concrete concrete, Rebar rebar, double h_f, double h_n);
	void save(std::ostream& ostr) const;
	void load(std::istream& istr);
	void set_default_values();

	void set_b(double b){b_ = b;}
	void set_phi_b_cr(double phi_b_cr){concrete_.set_phi_b_cr(phi_b_cr);}

	String get_slab_type() const {return slab_type_;}
	SlabType get_slab_type_enum() const {return slab_type_enum_;}
	Concrete& get_concrete() {return concrete_;}
	const Concrete& get_concrete()const {return concrete_;}
	Rebar get_rebar() const {return rebar_;}
	double get_SW_concrete(LoadUnit load_unit=LoadUnit::N, LengthUnit length_unit=LengthUnit::mm) const;
	double get_C_b(LengthUnit length_unit=LengthUnit::mm) const;
	double get_h(LengthUnit length_unit=LengthUnit::mm) const;
	double get_h_f(LengthUnit length_unit=LengthUnit::mm) const {return h_f_/static_cast<int>(length_unit);}
	double get_h_n(LengthUnit length_unit=LengthUnit::mm) const {return h_n_/static_cast<int>(length_unit);}

	double get_b(LengthUnit length_unit=LengthUnit::mm) const {return b_/static_cast<int>(length_unit);}
	double get_A_b(LengthUnit length_unit=LengthUnit::mm) const;
	double get_I_b(LengthUnit length_unit=LengthUnit::mm) const;

private:

	String slab_type_;
	SlabType slab_type_enum_;
	Concrete concrete_;
	Rebar rebar_;
	double h_f_ = 0.; // расчётная толщина железобетонной плиты
	double h_n_ = 0.; // расстояние от наружней грани верхней полки двутавра до внутренней грани расчётной железобетонной плиты

	double b_ = 0.; // эффективная ширина

};


#endif
