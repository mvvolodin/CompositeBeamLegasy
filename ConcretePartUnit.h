// ---------------------------------------------------------------------------

#ifndef ConcretePartUnitH
#define ConcretePartUnitH
#include "GeometryUnit.h"
#include "Concrete.h"
#include "Rebar.h"
#include "CorrugatedSheet.h"
#include "Units.h"

// ---------------------------------------------------------------------------

class TConcretePart {

public:

	TConcretePart();
	TConcretePart(String slab_type, Concrete concrete, Rebar rebar, double h_f, TGeometry geometry, double b_uf);

	double effective_width_calc(double t_sl, double a, double B, double l);
	double effective_width_cantilever_calc(double t_slc, double a, double С, double l);
	String get_slab_type() const {return slab_type_;}
	Concrete get_concrete() const {return concrete_;}
	double get_R_bn() const {return concrete_.get_R_bn();}
	double get_R_btn() const {return concrete_.get_R_btn();}
	double get_R_b() const {return concrete_.get_R_b();}
	double get_E_b() const {return concrete_.get_E_b();}
	double get_E_s() const {return rebar_.get_E_s();}
	double get_A_s() const {return rebar_.get_A_s();}
	double get_b_s() const {return rebar_.get_b();}
	double get_E_b_tau() const {return concrete_.get_E_b_tau();}
	Rebar get_rebar() const {return rebar_;}
	double get_C_b(LengthUnit length_unit=LengthUnit::mm) const {return C_b_/static_cast<int>(length_unit);}
	double get_h_b(LengthUnit length_unit=LengthUnit::mm) const {return h_b_/static_cast<int>(length_unit);}
	double get_h_f(LengthUnit length_unit=LengthUnit::mm) const {return h_f_/static_cast<int>(length_unit);}
	double get_b_l(LengthUnit length_unit=LengthUnit::mm) const {return b_l_/static_cast<int>(length_unit);} //после добавления b_sl в этой функции нет необходимости. Удалить после изменения кода с вызовами
	double get_b_r(LengthUnit length_unit=LengthUnit::mm) const {return b_r_/static_cast<int>(length_unit);} //после добавления b_sl в этой функции нет необходимости. Удалить после изменения кода с вызовами
	double get_b_sl(LengthUnit length_unit=LengthUnit::mm) const {return (b_r_+ b_l_)/static_cast<int>(length_unit);}
	double get_A_b(LengthUnit length_unit=LengthUnit::mm) const {return A_b_/std::pow(static_cast<int>(length_unit),2);}
	double get_I_b(LengthUnit length_unit=LengthUnit::mm) const {return I_b_/std::pow(static_cast<int>(length_unit),4);}

private:

	String slab_type_;
	Concrete concrete_;
	Rebar rebar_;

protected:

	double b_l_ = 0.; // эффективная ширина слева
	double b_r_ = 0.; // эффективная ширина справа
	double h_b_ = 0.;// толщина железобетонной плиты. Для случая плиты по настилу сумма высоты настила и толщины бетона над ним
	double C_b_ = 0.; 	// расстояние от нижней грани железобетонной плиты до её центр тяжести
	double h_f_ = 0.; // расчётная толщина железобетонной плиты
	double A_b_ = 0.; // Площадь железобетона
	double I_b_ = 0.;
};

class TFlatSlab : public TConcretePart {
public:
	TFlatSlab(Concrete concrete, Rebar rebar, double t_sl, TGeometry geometry, double b_uf);

};

class TCorrugatedSlab : public TConcretePart{
public:
	TCorrugatedSlab(String slab_type, Concrete concrete, Rebar rebar, double h_f, TGeometry geometry, double b_uf);

private:
	CorrugatedSheet corrugated_sheet_;
	double h_p_; // Высота настила настилом
;
};

#endif
