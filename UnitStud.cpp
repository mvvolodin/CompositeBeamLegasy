//---------------------------------------------------------------------------
#include<algorithm>
#include<cmath>

#pragma hdrstop

#include "UnitStud.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

TStudBasicNamedList stud_named_list  //Ассоциацивный массив подходит в моём случае лучше так как поиск
										//выполняется только по одному из полей, если бы поиск был по нескольким полям то возможно вектор
{
	{{L"SDx10x50"},			{L"SDx10x50",10,50}}
	,  //вероятно из BasicStud рекомендуется исключить имя
	{{L"SDx10x75"},			{L"SDx10x75",10,75}},
	{{L"SDx10x100"},		{L"SDx10x100",10,100}},
	{{L"SDx10x125"},		{L"SDx10x125",10,125}},
	{{L"SDx10x150"},		{L"SDx10x150",10,150}},
	{{L"SDx10x175"},		{L"SDx10x175",10,175}},
	{{L"SDx10x200"},		{L"SDx10x200",10,200}},
	{{L"SDx10x225"},		{L"SDx10x225",10,225}},
	{{L"SDx10x250"},		{L"SDx10x250",10,250}},
	{{L"SDx10x275"},		{L"SDx10x275",10,275}},
	{{L"SDx10x300"},		{L"SDx10x300",10,300}},
	{{L"SDx10x325"},		{L"SDx10x325",10,325}},
	{{L"SDx10x350"},		{L"SDx10x350",10,350}},

	{{L"SDx13x50"},			{L"SDx13x50",13,50}},
	{{L"SDx13x75"},			{L"SDx13x75",13,75}},
	{{L"SDx13x100"},		{L"SDx13x100",13,100}},
	{{L"SDx13x125"},		{L"SDx13x125",13,125}},
	{{L"SDx13x150"},		{L"SDx13x150",13,150}},
	{{L"SDx13x175"},		{L"SDx13x175",13,175}},
	{{L"SDx13x200"},		{L"SDx13x200",13,200}},
	{{L"SDx13x225"},		{L"SDx13x225",13,225}},
	{{L"SDx13x250"},		{L"SDx13x250",13,250}},
	{{L"SDx13x275"},		{L"SDx13x275",13,275}},
	{{L"SDx13x300"},		{L"SDx13x300",13,300}},
	{{L"SDx13x325"},		{L"SDx13x325",13,325}},
	{{L"SDx13x350"},		{L"SDx13x350",13,350}},

	{{L"SDx16x50"},			{L"SDx16x50",16,50}},
	{{L"SDx16x75"},			{L"SDx16x75",16,75}},
	{{L"SDx16x100"},		{L"SDx16x100",16,100}},
	{{L"SDx16x125"},		{L"SDx16x125",16,125}},
	{{L"SDx16x150"},		{L"SDx16x150",16,150}},
	{{L"SDx16x175"},		{L"SDx16x175",16,175}},
	{{L"SDx16x200"},		{L"SDx16x200",16,200}},
	{{L"SDx16x225"},		{L"SDx16x225",16,225}},
	{{L"SDx16x250"},		{L"SDx16x250",16,250}},
	{{L"SDx16x275"},		{L"SDx16x275",16,275}},
	{{L"SDx16x300"},		{L"SDx16x300",16,300}},
	{{L"SDx16x325"},		{L"SDx16x325",16,325}},
	{{L"SDx16x350"},		{L"SDx16x350",16,350}},

	{{L"SDx19x50"},			{L"SDx19x50",19,50}},
	{{L"SDx19x75"},			{L"SDx19x75",19,75}},
	{{L"SDx19x100"},		{L"SDx19x100",19,100}},
	{{L"SDx19x125"},		{L"SDx19x125",19,125}},
	{{L"SDx19x150"},		{L"SDx19x150",19,150}},
	{{L"SDx19x175"},		{L"SDx19x175",19,175}},
	{{L"SDx19x200"},		{L"SDx19x200",19,200}},
	{{L"SDx19x225"},		{L"SDx19x225",19,225}},
	{{L"SDx19x250"},		{L"SDx19x250",19,250}},
	{{L"SDx19x275"},		{L"SDx19x275",19,275}},
	{{L"SDx19x300"},		{L"SDx19x300",19,300}},
	{{L"SDx19x325"},		{L"SDx19x325",19,325}},
	{{L"SDx19x350"},		{L"SDx19x350",19,350}},

	{{L"SDx22x50"},			{L"SDx22x50",22,50}},
	{{L"SDx22x75"},			{L"SDx22x75",22,75}},
	{{L"SDx22x100"},		{L"SDx22x100",22,100}},
	{{L"SDx22x125"},		{L"SDx22x125",22,125}},
	{{L"SDx22x150"},		{L"SDx22x150",22,150}},
	{{L"SDx22x175"},		{L"SDx22x175",22,175}},
	{{L"SDx22x200"},		{L"SDx22x200",22,200}},
	{{L"SDx22x225"},		{L"SDx22x225",22,225}},
	{{L"SDx22x250"},		{L"SDx22x250",22,250}},
	{{L"SDx22x275"},		{L"SDx22x275",22,275}},
	{{L"SDx22x300"},		{L"SDx22x300",22,300}},
	{{L"SDx22x325"},		{L"SDx22x325",22,325}},
	{{L"SDx22x350"},		{L"SDx2x350",22,350}},

	{{L"SDx25x50"},			{L"SDx25x50",25,50}},
	{{L"SDx25x75"},			{L"SDx25x75",25,75}},
	{{L"SDx25x100"},		{L"SDx25x100",25,100}},
	{{L"SDx25x125"},		{L"SDx25x125",25,125}},
	{{L"SDx25x150"},		{L"SDx25x150",25,150}},
	{{L"SDx25x175"},		{L"SDx25x175",25,175}},
	{{L"SDx25x200"},		{L"SDx25x200",25,200}},
	{{L"SDx25x225"},		{L"SDx25x225",25,225}},
	{{L"SDx25x250"},		{L"SDx25x250",25,250}},
	{{L"SDx25x275"},		{L"SDx25x275",25,275}},
	{{L"SDx25x300"},		{L"SDx25x300",25,300}},
	{{L"SDx25x325"},		{L"SDx25x325",25,325}},
	{{L"SDx25x350"},		{L"SDx25x350",25,350}},

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



