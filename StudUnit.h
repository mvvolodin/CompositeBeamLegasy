//---------------------------------------------------------------------------

#ifndef StudUnitH
#define StudUnitH

#include<System.hpp>
#include<map>
#include<utility>
#include<vector>
#include "Units.h"

class TStudBasic{
private:
	String name_="";
	double l_=0.;   //Длина круглого стержня гибкого упора
	double d_an_=0.; //Диаметр стержня гибкого упора
public:
	TStudBasic();
	TStudBasic(String name, double l, double d_an);
	inline String get_name() const {return name_;};
	inline double get_l(LengthUnit length_unit=LengthUnit::mm) const
		{return l_/static_cast<int>(length_unit);}
	inline double get_d_an(LengthUnit length_unit=LengthUnit::mm) const
		{return d_an_/static_cast<int>(length_unit);}
};

class TStud:public TStudBasic{
public:
	TStud();
	TStud(String name,
		 double l, double d_an,
		 double z_e, double z_m,
		 double edge_rows_num, double middle_rows_num,
		 double R_y, double gamma_c);
	inline double get_edge_rows_dist(LengthUnit length_unit=LengthUnit::mm) const
		{return edge_rows_dist_/static_cast<int>(length_unit);}
	inline double get_middle_rows_dist(LengthUnit length_unit=LengthUnit::mm) const
		{return middle_rows_dist_/static_cast<int>(length_unit);}
	inline double get_edge_rows_num() const
		{return edge_rows_num_;}
	inline double get_middle_rows_num() const
		{return middle_rows_num_;}
	inline double get_gamma_c()const{return gamma_c_;}
	inline double get_R_y()const{return R_y_;}
	inline std::vector<double> get_stud_coordinates()const {return stud_coordinates_;}

private:
	double edge_rows_dist_=0.;//Шаг упоров в крайних третях
	double middle_rows_dist_=0.; //Шаг упоров в средней трети
	double edge_rows_num_=0.; // Количество рядов упоров в крайних третях
	double middle_rows_num_=0.; //Количество рядов упоров в средней трети
	double R_y_=0.; //Предел текучести
	double gamma_c_=0.; //Коэффициент условий работы
	std::vector<double> stud_coordinates_;

	void calculate_coordinates(double span);//определение координат размещения стад-болтов
};

typedef std::pair <String, TStudBasic> TStudBasicPair;
typedef std::map <String, TStudBasic> TStudBasicNamedList;
typedef TStudBasicNamedList::iterator IteratorTStudBasicNamedList;

extern TStudBasicNamedList stud_named_list;
//---------------------------------------------------------------------------
#endif

