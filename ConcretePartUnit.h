// ---------------------------------------------------------------------------

#ifndef ConcretePartUnitH
#define ConcretePartUnitH
#include "GeometryUnit.h"
#include "Concrete.h"
#include "Rebar.h"

// ---------------------------------------------------------------------------
class TConcretePart {

private:
	String slab_type_;
	Concrete concrete_;
	Rebar rebar_;

protected:
	// Данные ниже должны быть видны в классах потомках, поэтому спецификатор видимости protected

	double b_l_; // эффективная ширина слева
	double b_r_; // эффективная ширина справа
	double h_b_;
	// толщина железобетонной плиты. Для случая плиты по настилу сумма высоты настила и толщины бетона над ним
	double C_b_;
	// расстояние от нижней грани железобетонной плиты до её центр тяжести
	double t_sl_; // расчётная толщина железобетонной плиты
	double A_b_; // Площадь железобетона
	double I_b_;
	// Момент инерции железобетонной плиты //!Урок! Торг память или процессор. Смотреть кол. вызовов, размер поля в байтах. Не заниматься ранней оптимизацией

public:
	double effective_width_calc(double t_sl, double a, double B, double l);
	double effective_width_cantilever_calc(double t_slc, double a, double С,
		double l);
	virtual void calc_area() = 0; // pure virtual
	virtual void calc_inertia() = 0;
	// !Урок! виртуальный деструктор добавить.

	TConcretePart();
	TConcretePart(Concrete concrete, Rebar rebar, double t_sl);
	TConcretePart(Concrete concrete, Rebar rebar);

	inline String get_slab_type() const {return slab_type_;}
	inline double get_R_b() const {return concrete_.get_R_b();}
	inline double get_R_bt() const {return concrete_.get_R_bt();}
	inline double get_E_b() const {return concrete_.get_E_b();}
	inline Rebar get_rebar() const {return rebar_;}
	inline double get_C_b() const {return C_b_;}
	inline void set_b_l(double b_l) {b_l_ = b_l;}
	inline void set_b_r(double b_r) {b_r_ = b_r;}
	inline double get_h_b() const {return h_b_;}
	inline double get_t_sl() const {return t_sl_;}
	inline double get_b_l() const {return b_l_;}
	inline double get_b_r() const {return b_r_;}
	inline double get_A_b() const {return A_b_;}
	inline double get_I_b() const {return I_b_;}
};

class TFlatSlab : public TConcretePart {

private:
	virtual void calc_area();
	virtual void calc_inertia();

public:
	TFlatSlab(Concrete concrete, Rebar rebar, double t_sl);
};

class TCorrugatedSlab : public TConcretePart{

private:
	double h_p; // Высота настила
	double h_f; // Толщина железобетона над настилом

	virtual void calc_area();
	virtual void calc_inertia();

public:
	TCorrugatedSlab(Concrete concrete, Rebar rebar);

	inline double get_sheet_height() const {return h_p;}
	inline double get_conc_topping() const {return h_f;}

};

#endif
