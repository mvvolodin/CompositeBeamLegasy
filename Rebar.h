//---------------------------------------------------------------------------

#ifndef RebarH
#define RebarH
#include<System.hpp> //Подключаем тип String
#include<map>

class RebarBasic{

protected:
	String grade;
	double R_s;

public:
	RebarBasic():
		grade(""),R_s(0){};
	RebarBasic(String grade, double R_s):
		grade(grade),R_s(R_s){};
	inline String get_grade() const {return grade;};
	inline double get_R_s() const {return R_s;};
};

class Rebar:public RebarBasic{

private:
	double E_s;
	double diameter;
	double safety_factor;

public:
	Rebar():
		RebarBasic(),E_s(200000),diameter(0),safety_factor(0){};
	Rebar(String grade, double R_s, double diameter, double safety_factor):
		RebarBasic(grade, R_s),E_s(200000), diameter(diameter), safety_factor(safety_factor){};
	inline double get_E_s() const {return E_s;}
	inline double get_diameter() const {return diameter;}
	inline double get_safety_factor() const {return safety_factor;}
	inline double get_A_s(){return 3.14159*diameter*diameter/4;}

};

//typedef std::pair<String, RebarBasic> RebarPair;

typedef std::pair<String, RebarBasic> RebarPair; //typedef RebarBasic::value_type RebarPair;
typedef std::map<String, RebarBasic> RebarNamedList;
typedef RebarNamedList::iterator IteratorRebarNamedList;

void fill_rebar_named_list(RebarNamedList* rebar_named_list);  //Factoty pattern check it
//factory partten may control the initialization flow



//---------------------------------------------------------------------------
#endif
