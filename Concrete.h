//---------------------------------------------------------------------------

#ifndef ConcreteH
#define ConcreteH
#include <System.hpp>
#include <map>
#include <utility>
//---------------------------------------------------------------------------
class ConcreteBasic{
public:
	ConcreteBasic();
	ConcreteBasic(String grade, double E_b, double R_b, double R_bt);
	inline String get_grade()const{return grade_;}
	inline double get_E_b()const {return E_b_;}
	inline double get_R_bn()const {return R_bn_;}
	inline double get_R_btn()const {return R_btn_;}
private:
	String grade_;
	double E_b_;
	double R_bn_;
	double R_btn_;
};
typedef std::map <String, ConcreteBasic> ConcreteBasicData;
typedef std::pair <String, ConcreteBasic> ConcreteBasicDataItem;

class Concrete:public ConcreteBasic{
public:
	Concrete();
	Concrete(ConcreteBasic concrete_basic, double gamma_b, double gamma_bt, double epsilon_b_lim);
	inline double get_gamma_b()const {return gamma_b_;}
	inline double get_gamma_bt()const {return gamma_bt_;}
	inline double get_epsilon_b_lim()const {return epsilon_b_lim_;}
private:
	double gamma_b_;
	double gamma_bt_;
	double epsilon_b_lim_;
};

#endif
