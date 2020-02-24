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
	double effective_width_cantilever_calc(double t_slc, double a, double �, double l);
	String get_slab_type() const {return slab_type_;}
	Concrete get_concrete() const {return concrete_;}
	double get_R_bn() const {return concrete_.get_R_bn();}
	double get_R_btn() const {return concrete_.get_R_btn();}
	double get_E_b() const {return concrete_.get_E_b();}
	double get_E_s() const {return rebar_.get_E_s();}
	double get_A_s() const {return rebar_.get_A_s();}
	double get_E_b_tau() const {return concrete_.get_E_b_tau();}
	Rebar get_rebar() const {return rebar_;}
	double get_C_b(LengthUnit length_unit=LengthUnit::mm) const {return C_b_/static_cast<int>(length_unit);}
	void set_b_l(double b_l) {b_l_ = b_l;}
	void set_b_r(double b_r) {b_r_ = b_r;}
	double get_h_b(LengthUnit length_unit=LengthUnit::mm) const {return h_b_/static_cast<int>(length_unit);}
	double get_h_f(LengthUnit length_unit=LengthUnit::mm) const {return h_f_/static_cast<int>(length_unit);}
	double get_b_l(LengthUnit length_unit=LengthUnit::mm) const {return b_l_/static_cast<int>(length_unit);} //����� ���������� b_sl � ���� ������� ��� �������������. ������� ����� ��������� ���� � ��������
	double get_b_r(LengthUnit length_unit=LengthUnit::mm) const {return b_r_/static_cast<int>(length_unit);} //����� ���������� b_sl � ���� ������� ��� �������������. ������� ����� ��������� ���� � ��������
	double get_b_sl(LengthUnit length_unit=LengthUnit::mm) const {return (b_r_+ b_l_)/static_cast<int>(length_unit);}
	double get_A_b(LengthUnit length_unit=LengthUnit::mm) const {return A_b_/std::pow(static_cast<int>(length_unit),2);}
	double get_I_b(LengthUnit length_unit=LengthUnit::mm) const {return I_b_/std::pow(static_cast<int>(length_unit),4);}

private:

	String slab_type_;
	Concrete concrete_;
	Rebar rebar_;

protected:

	double b_l_ = 0.; // ����������� ������ �����
	double b_r_ = 0; // ����������� ������ ������
	double h_b_ = 0;// ������� �������������� �����. ��� ������ ����� �� ������� ����� ������ ������� � ������� ������ ��� ���
	double C_b_ = 0; 	// ���������� �� ������ ����� �������������� ����� �� � ����� �������
	double h_f_ = 0; // ��������� ������� �������������� �����
	double A_b_ = 0; // ������� ������������
	double I_b_ = 0;
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
	double h_p_; // ������ ������� ��������
;
};

#endif
