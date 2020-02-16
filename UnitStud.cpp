//---------------------------------------------------------------------------
#include<algorithm>
#include<cmath>

#pragma hdrstop

#include "UnitStud.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
//double* out_my;
//
//get_array(.............,out_my)
//
//int get_array(double* in, int size_in, double* out)
//{
//  return size_out;
//}
//
//out_my[10]

TStudBasicNamedList stud_named_list  //Ассоциацивный массив подходит в моём случае лучше так как поиск
										//выполняется только по одному из полей, если бы поиск был по нескольким полям то возможно вектор
{
	{{"SDx10x50"},		{"SDx10x50",10,50}},  //вероятно из BasicStud рекомендуется исключить имя
	{{"SDx10x75"},		{"SDx10x75",10,75}},
	{{"SDx10x100"},		{"SDx10x100",10,100}},
	{{"SDx10x125"},		{"SDx10x125",10,125}},
	{{"SDx10x150"},		{"SDx10x150",10,150}},
	{{"SDx10x175"},		{"SDx10x175",10,175}},
	{{"SDx10x200"},		{"SDx10x200",10,200}},
	{{"SDx10x225"},		{"SDx10x225",10,225}},
	{{"SDx10x250"},		{"SDx10x250",10,250}},
	{{"SDx10x275"},		{"SDx10x275",10,275}},
	{{"SDx10x300"},		{"SDx10x300",10,300}},
	{{"SDx10x325"},		{"SDx10x325",10,325}},
	{{"SDx10x350"},		{"SDx10x350",10,350}},

	{{"SDx13x50"},		{"SDx10x50",13,50}},
	{{"SDx13x75"},		{"SDx10x75",13,75}},
	{{"SDx13x100"},		{"SDx10x100",13,100}},
	{{"SDx13x125"},		{"SDx10x125",13,125}},
	{{"SDx13x150"},		{"SDx10x150",13,150}},
	{{"SDx13x175"},		{"SDx10x175",13,175}},
	{{"SDx13x200"},		{"SDx10x200",13,200}},
	{{"SDx13x225"},		{"SDx10x225",13,225}},
	{{"SDx13x250"},		{"SDx10x250",13,250}},
	{{"SDx13x275"},		{"SDx10x275",13,275}},
	{{"SDx13x300"},		{"SDx10x300",13,300}},
	{{"SDx13x325"},		{"SDx10x325",13,325}},
	{{"SDx13x350"},		{"SDx10x350",13,350}},

	{{"SDx16x50"},		{"SDx10x50",16,50}},
	{{"SDx16x75"},		{"SDx10x75",16,75}},
	{{"SDx16x100"},		{"SDx10x100",16,100}},
	{{"SDx16x125"},		{"SDx10x125",16,125}},
	{{"SDx16x150"},		{"SDx10x150",16,150}},
	{{"SDx16x175"},		{"SDx10x175",16,175}},
	{{"SDx16x200"},		{"SDx10x200",16,200}},
	{{"SDx16x225"},		{"SDx10x225",16,225}},
	{{"SDx16x250"},		{"SDx10x250",16,250}},
	{{"SDx16x275"},		{"SDx10x275",16,275}},
	{{"SDx16x300"},		{"SDx10x300",16,300}},
	{{"SDx16x325"},		{"SDx10x325",16,325}},
	{{"SDx16x350"},		{"SDx10x350",16,350}},

	{{"SDx19x50"},		{"SDx10x50",19,50}},
	{{"SDx19x75"},		{"SDx10x75",19,75}},
	{{"SDx19x100"},		{"SDx10x100",19,100}},
	{{"SDx19x125"},		{"SDx10x125",19,125}},
	{{"SDx19x150"},		{"SDx10x150",19,150}},
	{{"SDx19x175"},		{"SDx10x175",19,175}},
	{{"SDx19x200"},		{"SDx10x200",19,200}},
	{{"SDx19x225"},		{"SDx10x225",19,225}},
	{{"SDx19x250"},		{"SDx10x250",19,250}},
	{{"SDx19x275"},		{"SDx10x275",19,275}},
	{{"SDx19x300"},		{"SDx10x300",19,300}},
	{{"SDx19x325"},		{"SDx10x325",19,325}},
	{{"SDx19x350"},		{"SDx10x350",19,350}},

	{{"SDx22x50"},		{"SDx10x50",22,50}},
	{{"SDx22x75"},		{"SDx10x75",22,75}},
	{{"SDx22x100"},		{"SDx10x100",22,100}},
	{{"SDx22x125"},		{"SDx10x125",22,125}},
	{{"SDx22x150"},		{"SDx10x150",22,150}},
	{{"SDx22x175"},		{"SDx10x175",22,175}},
	{{"SDx22x200"},		{"SDx10x200",22,200}},
	{{"SDx22x225"},		{"SDx10x225",22,225}},
	{{"SDx22x250"},		{"SDx10x250",22,250}},
	{{"SDx22x275"},		{"SDx10x275",22,275}},
	{{"SDx22x300"},		{"SDx10x300",22,300}},
	{{"SDx22x325"},		{"SDx10x325",22,325}},
	{{"SDx22x350"},		{"SDx10x350",22,350}},

	{{"SDx25x50"},		{"SDx10x50",25,50}},
	{{"SDx25x75"},		{"SDx10x75",25,75}},
	{{"SDx25x100"},		{"SDx10x100",25,100}},
	{{"SDx25x125"},		{"SDx10x125",25,125}},
	{{"SDx25x150"},		{"SDx10x150",25,150}},
	{{"SDx25x175"},		{"SDx10x175",25,175}},
	{{"SDx25x200"},		{"SDx10x200",25,200}},
	{{"SDx25x225"},		{"SDx10x225",25,225}},
	{{"SDx25x250"},		{"SDx10x250",25,250}},
	{{"SDx25x275"},		{"SDx10x275",25,275}},
	{{"SDx25x300"},		{"SDx10x300",25,300}},
	{{"SDx25x325"},		{"SDx10x325",25,325}},
	{{"SDx25x350"},		{"SDx10x350",25,350}},

};

//Этот конструктор требуется для корректной работы типов pair и map.
//Отмечу, что не совсем понято почему. Ведь оперетора [] нет, для которого ребуется value initialization
//обычно предоставляемая default ctr
TStudBasic::TStudBasic(){}
TStudBasic::TStudBasic(String name, double d_an, double l):
						name_(name),
						d_an_(d_an),
						l_(l){}

Studs::Studs(){}
Studs::Studs(String name,
			 double d_an, double l,
			 double edge_rows_dist, double middle_rows_dist,
			 double edge_rows_num, double middle_rows_num,
			 double R_y, double gamma_c):
	 TStudBasic(name, d_an, l),
	 edge_rows_dist_(edge_rows_dist),
	 middle_rows_dist_(middle_rows_dist),
	 edge_rows_num_(edge_rows_num),
	 middle_rows_num_(middle_rows_num),
	 R_y_(R_y),
	 gamma_c_(gamma_c)
{

}
//-----------------------------------------------------------------------------
//Определение количества поперечных рядов стад-болтов
//in:l-пролёт балки
//out:количество поперечных рядов стад-болтов
//-----------------------------------------------------------------------------
int Studs::calculate_studs_transverse_rows_number(double L)
{
	const double L3 = L/3.0;
	int na = L3 / edge_rows_dist_ + 1; //добавляем единицу, чтобы шаг упоров гарантировано не превысил заданный максимальный шаг
	int nb = L3 / middle_rows_dist_ + 1;
	return na + nb + na + 1;
}
//-----------------------------------------------------------------------------
//Определение координат размещения стад-болтов
//in:l-пролёт балки
//out:лист с координатами расположения упоров
//-----------------------------------------------------------------------------
std::vector<double> Studs::calculate_coordinates(double L)
{
	const double L3 = L/3.0;
	std::vector<double> stud_coordinates;

	double a = edge_rows_dist_;

	int na = L3 / a + 1;
	a = L3/na;

	for (int i = 0; i < na; i++)
		stud_coordinates.emplace_back(0 + a*i);

	double b = middle_rows_dist_;
	int nb = L3 / b + 1;
	b = L3/nb;

	for (int i = 0; i < nb; i++)
		stud_coordinates.emplace_back(L3 + b*i);

	for (int i = 0; i < na; i++)
		stud_coordinates.emplace_back(2*L3 + a*i);

	stud_coordinates.emplace_back(L);
	std::transform(stud_coordinates.begin(),stud_coordinates.end(),stud_coordinates.begin(),[](double coord){return std::round(coord);});
	return stud_coordinates;
}

void Studs::calculate_capacity(double R_b, double R_y, double gamma_c)
{
	if ((2.5 <= l_/d_an_) && (l_/d_an_ <= 4.2)){ //возможен ли вариант, когда отношение l_/d_an_ меньше 2.5. Надо ли выводить информационное сообщение?
		P_rd_=0.24*l_*d_an_*std::pow(10*R_b,0.5)*1000; //1000 перевод в Н, так как в СП кН
	}

	else if (l_/d_an_ > 4.2){
		P_rd_=d_an_*d_an_*std::pow(10*R_b,0.5)*1000;
	}

	P_rd_addition_=0.063*d_an_*d_an_*gamma_c*R_y*1000;
}


std::vector<double> Studs::calc_ratios(std::vector<double> S)
{
	std::vector<double> ratios;
	for(auto s:S)
		ratios.emplace_back(s/std::min( P_rd_, P_rd_addition_));
	return ratios;
}



