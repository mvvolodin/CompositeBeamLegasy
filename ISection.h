//---------------------------------------------------------------------------

#ifndef ISectionH
#define ISectionH
//---------------------------------------------------------------------------

#include <math.h>
#include "ISectionInitialDataUnit.h"

class ISection{
private:
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
   //	double GC_;
public:
	ISection(TISectionInitialData i_section_initial_data);
	ISection();
	ISection( double buf,double tuf,
			  double blf, double tlf,
			  double hw, double tw);
	inline double get_b_uf() const {return b_uf_;}
	inline double get_h_st() const {return h_st_;}
	inline double get_A_st() const {return A_st_;}
	inline double get_I_st() const {return I_st_;}
	inline double get_Z_f2_st() const {return Z_f2_st_;}
	inline double get_Z_f1_st() const {return Z_f1_st_;}
	inline double get_Wf2_st() const {return Wf2_st_;}
	inline double get_Wf1_st() const {return Wf1_st_;}
	inline  double get_A_f2_st() const{return b_uf_*t_uf_;}
};
#endif
