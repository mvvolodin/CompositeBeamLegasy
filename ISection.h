//---------------------------------------------------------------------------

#ifndef ISectionH
#define ISectionH
//---------------------------------------------------------------------------

#include <math.h>
#include "ISectionInitialDataUnit.h"
#include "Units.h"

class ISection{
private:
	String profile_number_;
	double b_uf_;
	double t_uf_;
	double b_lf_;
	double t_lf_;
	double h_w_;
	double t_w_;
	double h_st_;//высота балки
	double Z_f2_st_;//–ассто€ние от ÷.“. стального сечени€ до наружней грани верх.полки
	double Z_f1_st_; //–ассто€ние от ÷.“. стального сечени€ до наружней грани нижней полки
	double A_st_;
	double I_st_;
	double Wf2_st_;//момент сопротивлени€ крайних волокон верхней полки
	double Wf1_st_;//момент сопротивление крайних волокон нижней полки

public:
	ISection();
	ISection(TISectionInitialData i_section_initial_data);
	inline String get_profile_name() const {return profile_number_;}
	inline double get_b_uf(LengthUnit length_units=LengthUnit::mm) const {return b_uf_/static_cast<int>(length_units);}
	inline double get_t_uf(LengthUnit length_units=LengthUnit::mm) const {return t_uf_/static_cast<int>(length_units);}
	inline double get_b_lf(LengthUnit length_units=LengthUnit::mm) const {return b_lf_/static_cast<int>(length_units);}
	inline double get_t_lf(LengthUnit length_units=LengthUnit::mm) const {return t_lf_/static_cast<int>(length_units);}
	inline double get_h_w(LengthUnit length_units=LengthUnit::mm) const {return h_w_/static_cast<int>(length_units);}
	inline double get_t_w(LengthUnit length_units=LengthUnit::mm) const {return t_w_/static_cast<int>(length_units);}
	inline double get_h_st(LengthUnit length_units=LengthUnit::mm) const {return h_st_/static_cast<int>(length_units);}
	inline double get_Z_f2_st(LengthUnit length_units=LengthUnit::mm) const {return Z_f2_st_/static_cast<int>(length_units);}
	inline double get_Z_f1_st(LengthUnit length_units=LengthUnit::mm) const {return Z_f1_st_/static_cast<int>(length_units);}
	inline double get_A_st(LengthUnit length_units=LengthUnit::mm) const {return A_st_/std::pow(static_cast<int>(length_units),2);}
	inline double get_I_st(LengthUnit length_units=LengthUnit::mm) const {return I_st_/std::pow(static_cast<int>(length_units),4);}
	inline double get_Wf2_st(LengthUnit length_units=LengthUnit::mm) const {return Wf2_st_/std::pow(static_cast<int>(length_units),3);}
	inline double get_Wf1_st(LengthUnit length_units=LengthUnit::mm) const {return Wf1_st_/std::pow(static_cast<int>(length_units),3);}
	inline  double get_A_f2_st(LengthUnit length_units=LengthUnit::mm) const{return b_uf_*t_uf_/std::pow(static_cast<int>(length_units),2);}
};
#endif
