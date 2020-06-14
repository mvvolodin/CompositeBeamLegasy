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
enum class SheetOrient{
	ALONG,
	TRANSVERSE,
};
// ---------------------------------------------------------------------------
class ConcretePart {

public:

	ConcretePart();
    ConcretePart(String slab_type, SlabType slab_type_enum, Concrete concrete,
	Rebar rebar, double h_f, double h_n);
	ConcretePart(String slab_type, SlabType slab_type_enum, Concrete concrete,
		Rebar rebar, double h_f, double h_n, bool wider_flange_up, SheetOrient sheet_orient);
	void save(std::ostream& ostr) const;
	void load(std::istream& istr);
	void set_default_values();

	void set_b_sl(double b_sl){b_sl_ = b_sl;}
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

	double get_b_sl(LengthUnit length_unit=LengthUnit::mm) const {return b_sl_/static_cast<int>(length_unit);}
	double get_A_b(LengthUnit length_unit=LengthUnit::mm) const;
	double get_I_b(LengthUnit length_unit=LengthUnit::mm) const;
	bool get_wider_flange_up()const{return wider_flange_up_;}
	SheetOrient get_sheet_orient()const {return sheet_orient_;}
	CorrugatedSheet get_corrugated_sheet()const;

private:

	String slab_type_;
	SlabType slab_type_enum_;
	Concrete concrete_;
	Rebar rebar_;
	double h_f_ = 0.; // расчётная толщина железобетонной плиты
	double h_n_ = 0.; // расстояние от наружней грани верхней полки двутавра до внутренней грани расчётной железобетонной плиты
	bool wider_flange_up_ = false; //ориентация широкой полки
	double b_sl_ = 0.; // эффективная ширина
	SheetOrient sheet_orient_;//Ориентация настила относитльно балки

};


#endif
