//---------------------------------------------------------------------------

#ifndef RebarH
#define RebarH
#include<System.hpp> //Подключаем тип String
#include<map>

class RebarBasic{
public:
	RebarBasic();
	RebarBasic(String grade, double R_s_);
	inline String get_grade() const {return grade_;}
	inline double get_R_s() const {return R_s_;}
protected:
	String grade_ {""};
	double R_s_ {0.0};
};

class Rebar:public RebarBasic{
public:
	Rebar();
	Rebar(String grade, double R_s, double diameter, double safety_factor);
	inline double get_E_s() const {return E_s_;}
	inline double get_diameter() const {return diameter_;}
	inline double get_safety_factor() const {return safety_factor_;}
	inline double get_A_s(){return 3.14159*diameter_*diameter_/4;}

private:
	double E_s_ {0.0};
	double diameter_ {0.0};
	double safety_factor_ {0.0};
};

typedef std::pair<String, RebarBasic> RebarPair;
typedef std::map<String, RebarBasic> RebarNamedList;
typedef RebarNamedList::iterator IteratorRebarNamedList;

extern RebarNamedList rebar_named_list;
//---------------------------------------------------------------------------
#endif
