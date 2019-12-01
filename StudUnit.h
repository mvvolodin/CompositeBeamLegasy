//---------------------------------------------------------------------------

#ifndef StudUnitH
#define StudUnitH

#include<System.hpp>
#include<map>
#include<utility>

class TStud{
	String name_;
	double l_;   //Длина круглого стержня гибкого упора
	double d_an_; //Диаметр стержня гибкого упора
	double gamma_c_; //Коэффициент условий работы
	double R_y_; //Предел текучести
public:
	TStud();
	TStud(String, double, double, double, double);
	inline String get_name() const {return name_;};
	inline double get_l()const{return l_;}
	inline double get_d_an()const{return d_an_;}
	inline double get_gamma_c()const{return gamma_c_;}
	inline double get_R_y()const{return R_y_;}

};

typedef std::map <String, TStud> TStudData;
typedef std::pair <String, TStud> TStudDataItem;
typedef std::map <String, TStud>::iterator stud_data_iterator;
//---------------------------------------------------------------------------
#endif
