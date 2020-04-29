//---------------------------------------------------------------------------

#ifndef UnitStudH
#define UnitStudH

#include<System.hpp>
#include<map>
#include<utility>
#include<vector>
#include <ostream>
#include "Units.h"

/*
	Класс Stud описывает (содержит данные (свойства) и методы работы с данными(поведение)) объект упор.
	Свойства:
	- идентификационный номер: id_
	- положение на балке: x_
	- сечения для определения усилий S_i: x_l_ и x_r_;
	- флаг есть ли на упор воздействие: S_set_;
	- флаг выполнена ли проверка:  stud_verified_
	Поведение:
	- тривиальные геттеры и сеттеры;

*/


class StudsRow{
public:

	StudsRow(int id, double x_l, double x, double x_r, int st_num);
	void set_S(double S);
	int get_id()const{return id_;}
	double get_x()const{return x_;}
	double get_x_r()const{return x_r_;}
	double get_x_l()const{return x_l_;}
	double get_S()const{return S_;}
	double get_ratio()const{return ratio_;}

	void calculate_ratio();

	static void set_resistance(double R_b, double R_y, double gamma_c);
	static double obtain_P_rd(){return P_rd_;}
	static double obtain_l(){return l_;}
	static double obtain_d_an(){return d_an_;}

private:
	bool stud_verified_ = false;
	bool S_set_ = false;

	int id_ = 0;
	int st_num_ = 0;
	static String name_;
	static double d_an_;
	static double l_;
	static double P_rd_;
	static bool resistance_calculated_;

	double x_l_ = 0.;
	double x_ = 0.;
	double x_r_ = 0.;

    double S_ = 0.;

	double sigma_b_l_ = 0.;
	double sigma_b_r_ = 0.;
	double ratio_ = 0.;
};

	String StudsRow::name_ = L"SDx10x100";
	double StudsRow::d_an_ = 10.;
	double StudsRow::l_= 100. ;
	double StudsRow::P_rd_ = 0.;
	bool   StudsRow::resistance_calculated_ = false;

/*
	Класс StudsOnBeam описывает объект упоры на балке
	Класс создаёт и хранит список упоров, отнощение Композиция
	Свойства:
	-  Список упоров stud_list_;
	-
	Поведение:
	- тривиальные геттеры и сеттеры;

*/

class StudsOnBeam{
public:
	StudsOnBeam(){};
	void update(String name, double d_an, double l, double dist_e, double num_e,
			 double dist_m, double num_m);
	std::vector<StudsRow>& stud_list(){return stud_list_;}
	const std::vector<StudsRow>& get_stud_list()const{return stud_list_;}

	void set_default_values();
	void set_studs(double L);
	void set_resistances(double R_b, double R_y, double gamma_c);
	void verification();

private:

	double dist_e_;
	double dist_m_;
	int num_e_;
	int num_m_;
	std::vector<StudsRow> stud_list_;

	bool studs_placement_ = false;
	bool studs_calculated_ = false;
};




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
	double get_P_rd(LoadUnit load_unit=LoadUnit::N)const{return P_rd_/static_cast<int>(load_unit);}

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

