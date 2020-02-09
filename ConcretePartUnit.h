// ---------------------------------------------------------------------------

#ifndef ConcretePartUnitH
#define ConcretePartUnitH
#include "GeometryUnit.h"
#include "Concrete.h"
#include "Rebar.h"
#include "Units.h"

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
	TConcretePart(String slab_type, Concrete concrete, Rebar rebar);
	TConcretePart(Concrete concrete, Rebar rebar, double t_sl);


	inline String get_slab_type() const {return slab_type_;}
	inline Concrete get_concrete() const {return concrete_;}
	inline double get_R_bn() const {return concrete_.get_R_bn();}
	inline double get_R_btn() const {return concrete_.get_R_btn();}
	inline double get_E_b() const {return concrete_.get_E_b();}
	inline Rebar get_rebar() const {return rebar_;}
	inline double get_C_b(LengthUnit length_unit=LengthUnit::mm) const {return C_b_/static_cast<int>(length_unit);}
	inline void set_b_l(double b_l) {b_l_ = b_l;}
	inline void set_b_r(double b_r) {b_r_ = b_r;}
	inline double get_h_b(LengthUnit length_unit=LengthUnit::mm) const {return h_b_/static_cast<int>(length_unit);}
	inline double get_t_sl(LengthUnit length_unit=LengthUnit::mm) const {return t_sl_/static_cast<int>(length_unit);}
	inline double get_b_l(LengthUnit length_unit=LengthUnit::mm) const {return b_l_/static_cast<int>(length_unit);}
	inline double get_b_r(LengthUnit length_unit=LengthUnit::mm) const {return b_r_/static_cast<int>(length_unit);}
	inline double get_A_b(LengthUnit length_unit=LengthUnit::mm) const {return A_b_/std::pow(static_cast<int>(length_unit),2);}
	inline double get_I_b(LengthUnit length_unit=LengthUnit::mm) const {return I_b_/std::pow(static_cast<int>(length_unit),4);}
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
	typedef std::map<String, int> CorrugatedSheetsNamedList;

	CorrugatedSheetsNamedList corrugated_sheets_={{L"Н60-845",60},
												 {L"Н75-750",75},
												 {L"Н114-750",114},
												 {L"Н153-850",153},
												 {L"ТРП200",200}};
	int h_p_; // Высота настила
	double h_f_; // Толщина железобетона над настилом

	virtual void calc_area();
	virtual void calc_inertia();

public:
	TCorrugatedSlab(String slab_type, Concrete concrete, Rebar rebar, double h_f);

	inline double get_sheet_height() const {return h_p_;}
	inline double get_conc_topping() const {return h_f_;}

};

#endif
