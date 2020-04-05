//---------------------------------------------------------------------------

#ifndef UnitStudH
#define UnitStudH

#include<System.hpp>
#include<map>
#include<utility>
#include<vector>
#include <ostream>
#include "Units.h"

class TStudBasic{
public:
	TStudBasic();
	TStudBasic(String name, double d_an, double l);

	String get_name() const {return name_;};
	double get_l(LengthUnit length_unit=LengthUnit::mm) const
		{return l_/static_cast<int>(length_unit);}
	double get_d_an(LengthUnit length_unit=LengthUnit::mm) const
		{return d_an_/static_cast<int>(length_unit);}
protected:
	String name_ = L"SDx10x100";
	double d_an_ = 10.; //Диаметр стержня гибкого упора
	double l_= 100. ;   //Длина круглого стержня гибкого упора

	void save_stud_basic(std::ostream& ostr)const;
	void load_stud_basic(std::istream& istr);
};

class Studs:public TStudBasic{
public:
	Studs();
	Studs(String name,
		 double d_an, double l,
		 double z_e, double z_m,
		 double edge_rows_num, double middle_rows_num,
		 double R_y, double gamma_c);

	void set_default_values();
	void save(std::ostream& ostr)const;
	void load(std::istream& istr);
	void calculate(double L, double R_b, double R_y, double gamma_c);
	std::vector<double> calculate_coordinates(double L);//определение координат размещения стад-болтов
	//int calculate_studs_transverse_rows_number(double L);//определение количества поперечных рядов стад-болтов
	double calculate_capacity(double R_b, double R_y, double gamma_c);
	std::vector<double> calc_ratios(std::vector<double> S);//расчёт и возврат динамического массива КИ

	double get_edge_rows_dist(LengthUnit length_unit=LengthUnit::mm) const
		{return edge_rows_dist_/static_cast<int>(length_unit);}
	double get_middle_rows_dist(LengthUnit length_unit=LengthUnit::mm) const
		{return middle_rows_dist_/static_cast<int>(length_unit);}
	double get_edge_rows_num() const
		{return edge_rows_num_;}
	double get_middle_rows_num() const
		{return middle_rows_num_;}
	double get_gamma_c()const{return gamma_c_;}
	double get_R_y()const{return R_y_;}
	std::vector<double> get_coordinates_list()const{return coordinates_list_;}
	double get_P_rd()const{return P_rd_;}

private:
	double edge_rows_dist_ = 0.;//Шаг упоров в крайних третях
	double middle_rows_dist_ = 0.; //Шаг упоров в средней трети
	double edge_rows_num_= 0.; // Количество рядов упоров в крайних третях
	double middle_rows_num_ = 0.; //Количество рядов упоров в средней трети
	double R_y_= 0. ; //Предел текучести
	double gamma_c_ = 0.; //Коэффициент условий работы

 //Поля с результатами расчётов
	std::vector<double> coordinates_list_;//координаты упоров
	double P_rd_ = 0.;

};

using TStudBasicPair = std::pair <String, TStudBasic>;
using TStudBasicNamedList = std::map <String, TStudBasic>;
using IteratorTStudBasicNamedList = TStudBasicNamedList::iterator;

extern TStudBasicNamedList stud_named_list;
//---------------------------------------------------------------------------
#endif

