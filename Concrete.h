//---------------------------------------------------------------------------

#ifndef ConcreteH
#define ConcreteH
#include <System.hpp>
#include <vector>
#include <map>
#include <utility>
#include <systobj.h>

//---------------------------------------------------------------------------
class ConcreteBasic{
protected:
	String grade_ = "";
	double E_b_ = 0. ;
	double R_bn_ = 0.;
	double R_btn_ = 0.;
public:
	ConcreteBasic();
	ConcreteBasic(String grade, double E_b, double R_b, double R_bt);
	String get_grade()const{return grade_;}
	double get_E_b()const {return E_b_;}
	double get_R_bn()const {return R_bn_;}
	double get_R_btn()const {return R_btn_;}
};
typedef std::map <String, ConcreteBasic> ConcreteBasicData;
typedef std::pair <String, ConcreteBasic> ConcreteBasicDataItem;

class Concrete: public ConcreteBasic{
private:
	double phi_b_cr_ = 0.;
	double gamma_b_ =  0.;
	double gamma_bt_ = 0.;
	double epsilon_b_lim_ = 0.;
	double E_b_tau_ = 0.;//Модуль деформации бетона
	void E_b_tau_calc();
public:
	Concrete();
	Concrete(ConcreteBasic concrete_basic, double phi_b_cr, double gamma_b, double gamma_bt, double epsilon_b_lim);
	void set_default_values();
	double get_gamma_b()const {return gamma_b_;}
	double get_gamma_bt()const {return gamma_bt_;}
	double get_phi_b_cr()const {return phi_b_cr_;}
	double get_epsilon_b_lim()const {return epsilon_b_lim_;}
	double get_E_b_tau()const {return E_b_tau_;}
	double get_R_b()const {return R_bn_ / gamma_b_;}
};

extern std::vector <ConcreteBasic> concrete_basic;

#endif
