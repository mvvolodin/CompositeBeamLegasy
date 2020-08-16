// ---------------------------------------------------------------------------
#ifndef uSteelH
#define uSteelH
//---------------------------------------------------------------------------
#include <System.hpp>
//---------------------------------------------------------------------------
#include <istream>
#include <ostream>
#include "Units.h"
//---------------------------------------------------------------------------
class Steel{
public:
	Steel();
	Steel(String steel_grade, String grade, double E_st, double G_st, double nu_st,
			  double gamma_m,double R_yn,double R_un, double density, double t_max);
	void save(std::ostream& ostr)const;
	void load(std::istream& istr);
	void set_default_values();
	String get_steel_grade () const {return steel_grade_;}
	String get_standard() const {return standard_;}
	double get_R_y() const {return R_yn_ / gamma_m_;}
	double get_R_s()const {return 0.58 * R_yn_ / gamma_m_; }
	double get_R_yn() const {return R_yn_;}
	double get_R_un() const {return R_un_;}
	double get_E_st() const {return E_st_;}
	double get_G_st() const {return G_st_;}
	double get_nu_st() const {return nu_st_;}
	double get_gamma_m () const {return gamma_m_;}
	double get_density () const {return density_;}
	double get_t_max () const {return t_max_;}
private:
	String standard_ = "";
	String steel_grade_ = "";
	double E_st_ = 0.;
	double G_st_ = 0.;
	double nu_st_ = 0.;
	double R_yn_ = 0.;
	double R_un_ = 0.;
	double gamma_m_ = 0.;
	double density_ = 0.;
	double t_max_ = 0.;
};
//----

#endif
