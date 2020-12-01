﻿//---------------------------------------------------------------------------

#ifndef uConcreteH
#define uConcreteH
#include <System.hpp>
#include <vector>
#include <map>
#include <ostream>
#include <istream>
#include "Units.h"
#include "uWord_Automation.h"

//---------------------------------------------------------------------------
namespace ConcreteSP35
{
	struct Data{
		std::basic_string<char16_t> const grade_;
		double const E_b_;
		double const R_bn_;
		double const R_btn_;
	};

	extern std::vector<Data> const data_lst;

	std::vector<std::basic_string<char16_t>> grades();
	Data const & concrete (int index);
	std::basic_string<char16_t> grade(int index);
}

class ConcreteBasic{
public:
	ConcreteBasic();
	ConcreteBasic(String grade, double E_b, double R_b, double R_bt);
	String get_grade()const{return grade_;}
	double get_E_b()const {return E_b_;}
	double get_R_bn()const {return R_bn_;}
	double get_R_btn()const {return R_btn_;}
protected:
	String grade_ = "";
	double E_b_ = 0. ;
	double R_bn_ = 0.;
	double R_btn_ = 0.;
	void save(ostream& ostr) const;
	void load(istream& istr);
};
using ConcreteBasicData = std::map <String, ConcreteBasic> ;
using ConcreteBasicDataItem = std::pair <String, ConcreteBasic> ;

class Concrete: public ConcreteBasic{
public:
	Concrete();
	Concrete(ConcreteBasic concrete_basic, double density, double phi_b_cr,
			 double mater_coeff, double mater_coeff_tens, double epsilon_b_lim);
	void save(ostream& ostr) const;
	void load(istream& istr);
	void set_default_values();
	double get_gamma_b()const {return mater_coeff_;}
	double get_gamma_bt()const {return mater_coeff_tens_;}
	double get_density(LengthUnit length_unit = LengthUnit::mm)const {return density_ * std::pow(static_cast<int>(length_unit),3);}
	double get_phi_b_cr()const {return phi_b_cr_;}
	double get_epsilon_b_lim()const {return epsilon_b_lim_;}
	void set_phi_b_cr(double phi_b_cr){phi_b_cr_ = phi_b_cr;}
	double E_b()const {return E_b_ ;}
	double E_b_shr()const {return 0.5 * E_b_ ;}
	/* TODO 1 -oMV : Добавить в конструктор c_n */
	double c_n()const {return c_n_ ;}
	double get_E_b_tau()const {return E_b_ / (1 + phi_b_cr_);}
	double get_R_b()const {return R_bn_ / mater_coeff_;}
	double eps_shr()const {return eps_shr_;}
	void print(TWord_Automation & report)const;
private:
	double density_ = 0.;
	double phi_b_cr_ = 0.;
	double mater_coeff_ =  0.;
	double mater_coeff_tens_ = 0.;
	double epsilon_b_lim_ = 0.;
	double eps_shr_ = 0.0002;
	double c_n_ = 0.000084;

};

extern std::vector <ConcreteBasic> concrete_basic;

#endif
