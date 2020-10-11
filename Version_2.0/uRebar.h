//---------------------------------------------------------------------------

#ifndef uRebarH
#define uRebarH
#include<System.hpp> //Подключаем тип String
#include<map>
#include <iostream>
#include <ostream>

class RebarBasic{
public:
	RebarBasic();
	RebarBasic(String grade, double R_sn);
	String get_grade() const {return grade_;}
	double get_R_sn() const {return R_sn_;}
protected:
	String grade_ = L"";
	double R_sn_ = 0.;
	void save(ostream& ostr) const;
	void load(istream& istr);
};

class Rebar:public RebarBasic{
public:
	Rebar();
	Rebar(String grade, double R_sn, double E_s, double d_s, double b, double a_u,
	double a_l, double gamma_s_);
	void save(ostream& ostr) const;
	void load(istream& istr);
	void set_default_values();
	double get_E_s() const {return E_s_;}
	double get_R_s() const {return R_sn_ / gamma_s_ ;}
	double get_diameter() const {return d_s_;}
	double get_b_s() const {return b_;}
	double get_a_u() const {return a_u_;}
	double get_a_l() const {return a_l_;}
	double get_gamma_s_() const {return gamma_s_;}
	double get_A_s() const {return 3.14159265 * d_s_ * d_s_ / (4. * b_);}
	double get_num_rows(){return num_rows_;}

private:
	double E_s_ = 0.;
	double d_s_ = 0.;
	double b_  = 0.;//Шаг арматуры
	double a_u_ = 0.;// Защитный слой верхний арматуры
	double a_l_ = 0.; //Защитный слой нижней арматуры
	static const int num_rows_ = 2;
	double gamma_s_ = 0.;

};

class Rebar2{
public:
	Rebar2();
	Rebar2(String const grade, double R_sn, double const E_s,
		   double const d_s, double gamma_s);
	String grade() const;
	double E_s() const;
	double R_sn() const;
	double d_s() const;
	double gamma_s() const;

private:
	String grade_{L""};
	double E_s_{0.};
	double R_sn_ {0.};
	double d_s_{0.};
	double gamma_s_{0.};
};

class Rebars{
public:
	Rebars();
	Rebars(Rebar2 const & reb,
		   double const a_u, double const a_l,
		   double const b_u, double const b_l);
	Rebar2 rebar();
	double a_u();
	double a_l();
	double A_u_s_per_unit();
	double A_l_s_per_unit();
private:
	Rebar2 reb_{};//арматура
	double a_u_ {0.};// Защитный слой верхний арматуры
	double a_l_ {0.}; //Защитный слой нижней арматуры
	double b_u_ {0.}; //Шаг врехней арматуры
	double b_l_ {0.}; //Шаг нижней арматуры
};

using RebarStrengtNamedList = std::map<String, double>;

using RebarPair=std::pair<String, RebarBasic>;
using RebarNamedList=std::map<String, RebarBasic> ;
using IteratorRebarNamedList=RebarNamedList::iterator ;

extern RebarNamedList rebar_named_list;

//---------------------------------------------------------------------------
#endif
