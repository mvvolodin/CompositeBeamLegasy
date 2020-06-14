//---------------------------------------------------------------------------
#include<algorithm>
#include<cmath>

#pragma hdrstop

#include "uStud.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
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


StudsRow::StudsRow(int id, double x_l, double x, double x_r, int st_num):
		id_(id), x_l_(x_l), x_(x), x_r_(x_r), st_num_(st_num){}

//-----------------------------------------------------------------------------
//Вычисляет несущую способнось гибких упоров
//-----------------------------------------------------------------------------

Stud::Stud(){}

Stud::Stud(String name, double d_an, double l, double R_y):
	name_(name),
	d_an_(d_an),
	l_(l),
	R_y_(R_y){}

void Stud::calculate_S_h()
{
	S_h_ = 0.063 * d_an_/10 * d_an_/10 * gamma_c_ * R_y_ *1000;
}
void Stud::calculate_P_rd()
{

	if ((2.5 <= l_ / d_an_) && (l_ /d_an_ <= 4.2)){ //возможен ли вариант, когда отношение l_/d_an_ меньше 2.5. Надо ли выводить информационное сообщение?
		P_rd_ = 0.24 * l_/10 * d_an_/10 * std::pow(10 * R_b_ , 0.5) * 1000; //1000 перевод в Н, так как в СП кН
	}
	else if (l_/d_an_ > 4.2){
		P_rd_ = d_an_/10 * d_an_/10 * std::pow(10 * R_b_, 0.5) * 1000;
	}
}
double Stud::get_P_rd(LoadUnit__ load_unit)
{
	if(!P_rd_calculated) calculate_P_rd();

	return P_rd_ / load_unit;
}
double Stud::get_S_h(LoadUnit__ load_unit)
{
	if(!S_h_calculated) calculate_S_h();

	return P_rd_ / load_unit;
}

double StudsRow::calculate_k(double b_0, double h_n, double l, SheetOrient sheet_orient)
{
	double h_an = std::min(h_n + 75, l);

	double n_r = (more_than_one_stud_per_corrugation_)? 2: 1;

	switch (sheet_orient) {

	case(SheetOrient::ALONG):

		return (0.6 * b_0 * (h_an - h_n)) / std::pow(h_n, 2);

	case(SheetOrient::TRANSVERSE):

		return (0.7 * b_0 * (h_an - h_n)) / (std::pow(h_n, 2) * std::pow(n_r, 0.5));
	}
}
void StudsRow::calculate_ratio(double P_rd, double S_h)
{
	ratio_ = std::abs(S_) / (std::min(P_rd, S_h) * st_num_);
}
void StudsRow::calculate_ratio(double P_rd, double S_h, double b_0, double h_n, double l, SheetOrient sheet_orient)
{
	double k = calculate_k(b_0, h_n, l, sheet_orient);
	ratio_ = std::abs(S_) / (std::min(k * P_rd, S_h) * st_num_);
}
StudsOnBeam::StudsOnBeam()
{
}
StudsOnBeam::StudsOnBeam(Stud 	 stud,
						 double  dist_e,
						 double  dist_m,
						 int     num_e,
						 int     num_m,
						 double  gamma_c):
	stud_(stud),
	dist_e_(dist_e),
	dist_m_(dist_m),
	num_e_(num_e),
	num_m_(num_m),
	gamma_c_(gamma_c){}

 /* TODO 1 -oMV : Написать определение функций StudsOnBeam::save(ostream& ostr) */
void StudsOnBeam::save(ostream& ostr) const
{
//	wchar_t* buf = grade_.w_str();
//	unsigned short l = grade_.Length()+1;
//	ostr.write((char*)&l,sizeof(l));
//	ostr.write((char*)buf,l*sizeof(wchar_t));
//	free(buf);
//
//	ostr.write((char*)&E_b_ ,sizeof(E_b_));
}
void StudsOnBeam::load(istream& istr)
{
//	wchar_t* buf;
//	unsigned short l;
//	istr.read((char*)&l,sizeof(l));
//	buf =(wchar_t*) malloc(l*sizeof(wchar_t));
//	istr.read((char*)buf,l*sizeof(wchar_t));
//	grade_ = String(buf);
//	free(buf);
//
//	istr.read((char*)&E_b_ ,sizeof(E_b_));
}
void StudsOnBeam::set_intr_frcs_calculator(InternalForcesCalculator intr_frcs_calculator)
{
	intr_frcs_calculator_ = intr_frcs_calculator;
}
void StudsOnBeam::set_composite_section(CompositeSectionGeometry com_sect)
{
	com_sect_ = com_sect;
}
void StudsOnBeam::calculate_S()
{
	for (auto& stud_row:stud_list_)
		stud_row.calculate_S(intr_frcs_calculator_, com_sect_);
}
void StudsRow::calculate_S(InternalForcesCalculator& intr_frcs_calculator, CompositeSectionGeometry& com_sect)
{
	double A_s = com_sect.get_concrete_part().get_rebar().get_A_s();
	double A_b = com_sect.get_concrete_part().get_A_b();

	double R_s = com_sect.get_concrete_part().get_rebar().get_R_s();
	double R_b = com_sect.get_concrete_part().get_concrete().get_R_b();

	double W_b_red = com_sect.get_W_b_red();
	double alfa_b = com_sect.get_alfa_b();
	double alfa_s = com_sect.get_alfa_s();

	double b_sl = com_sect.get_concrete_part().get_b_sl();

	double M_II_design_r = intr_frcs_calculator.M_IIa_design(x_r_) +
		intr_frcs_calculator.M_IIb_design(x_r_);
	double M_II_design_l = intr_frcs_calculator.M_IIa_design(x_l_) +
		intr_frcs_calculator.M_IIb_design(x_l_);

	double sigma_b_r = std::abs(M_II_design_r)/(alfa_b*W_b_red);
	double sigma_b_l = std::abs(M_II_design_l)/(alfa_b*W_b_red);

	double sigma_s_r = std::abs(M_II_design_r)/(alfa_s*W_b_red);
	double sigma_s_l = std::abs(M_II_design_l)/(alfa_s*W_b_red);

	S_ = ((std::min(sigma_b_r, R_b) * A_b + std::min(sigma_s_r, R_s) * A_s * b_sl)-
		 ((std::min(sigma_b_l, R_b) * A_b + std::min(sigma_s_l, R_s) * A_s * b_sl)));
}
//-----------------------------------------------------------------------------
//Вычисляет несущую способность для каждого из гибких упоров на балке
//-----------------------------------------------------------------------------
void StudsOnBeam::calculate_ratio()
{
	stud_.set_R_b(com_sect_.get_concrete_part().get_concrete().get_R_b());
	stud_.set_gamma_c(gamma_c_);

	double P_rd = stud_.get_P_rd();
	double S_h = stud_.get_S_h();

   SlabType slab_type_enum = com_sect_.get_concrete_part().get_slab_type_enum();

   if (slab_type_enum!=SlabType::CORRUGATED){
		String slab_type = com_sect_.get_concrete_part().get_slab_type();
		CorrugatedSheet cs = com_sect_.get_concrete_part().get_corrugated_sheet();

		double b_0 = cs.get_b_0(com_sect_.get_concrete_part().get_wider_flange_up());
		double h_n = cs.get_height();

		SheetOrient sheet_orient = com_sect_.get_concrete_part().get_sheet_orient();

		double l = stud_.get_l();

		for(auto& stud_row:stud_list_)
			stud_row.calculate_ratio(P_rd, S_h, b_0, h_n, l, sheet_orient);
   }
   else
   {
		for(auto& stud_row:stud_list_)
			stud_row.calculate_ratio(P_rd, S_h);
   }
}
void StudsOnBeam::set_default_values()
{
	stud_ = Stud {L"SDx10x100", 10., 100., 300.};
	dist_e_ = 180.;
	dist_m_ = 400.;
	num_e_ = 1;
	num_m_ = 1;
	gamma_c_ = 1.3;

}
//-----------------------------------------------------------------------------
//Размещает гибкие упоры на балке согласно данным пользователя
//-----------------------------------------------------------------------------
void StudsOnBeam::set_studs(double L)//пролёт балки
{
	stud_list_.clear();

	const double L3 = L/3;
	double d_e = dist_e_;
	double d_m = dist_m_;

	double eps = 0.01;

	int n_e;

	if (static_cast<int>(L3) % static_cast<int>(d_e))
		n_e = L3 / d_e + 1 ;
	else
		n_e = L3 / d_e;

	d_e = L3 / n_e;

	int n_m;

	if (static_cast<int>(L3) % static_cast<int>(d_m))
		n_m = L3 / d_m + 1;
	else
		n_m = L3 / d_m;

	d_m = L3 /n_m;

	int id = 0;

	stud_list_.emplace_back(StudsRow{++id, 0., 0., 0., num_e_});

	for(int n = 1; n < n_e; ++n)
		stud_list_.emplace_back(StudsRow{++id, n * d_e - d_e / 2, n * d_e, n * d_e + d_e / 2, num_e_});

	stud_list_.emplace_back(StudsRow{++id, L3 - d_e / 2, L3, L3 + d_m / 2, num_e_});

	for(int n = 1; n < n_m; ++n)
		stud_list_.emplace_back(StudsRow{++id, L3 + n * d_m - d_m / 2, L3 + n * d_m, L3 + n * d_m + d_m / 2, num_m_});

	stud_list_.emplace_back(StudsRow{++id, 2 * L3 - d_m / 2, 2 * L3,  2 * L3 + d_e / 2, num_m_});

	for(int n = 1; n < n_e; ++n)
		stud_list_.emplace_back(StudsRow{++id, 2 * L3 + n * d_e - d_e / 2, 2 * L3 + n * d_e, 2 * L3 + n * d_e + d_e / 2, num_e_});

	stud_list_.emplace_back(StudsRow{++id, L, L, L, num_e_});

}
void TStudBasic::save_stud_basic(ostream& ostr) const
{
	wchar_t* buf = name_.w_str();
	unsigned short l = name_.Length()+1;
	ostr.write((char*)&l,sizeof(l));
	ostr.write((char*)buf,l*sizeof(wchar_t));
	free(buf);

	ostr.write((char*)&d_an_,sizeof(d_an_));
	ostr.write((char*)&l_,sizeof(l_));
}

void TStudBasic::load_stud_basic(istream& istr)
{
	wchar_t* buf;
	unsigned short l;
	istr.read((char*)&l,sizeof(l));
	buf =(wchar_t*) malloc(l*sizeof(wchar_t));
	istr.read((char*)buf,l*sizeof(wchar_t));
	name_ = String(buf);
	free(buf);

	istr.read((char*)&d_an_,sizeof(d_an_));
	istr.read((char*)&l_,sizeof(l_));
}

const StudsRow& StudsOnBeam::get_max_ratio_studs_row()const
{
	auto it_max_ratio_studs_row = std::max_element(stud_list_.begin(), stud_list_.end(),
		[](const StudsRow& stud_row1, const StudsRow& stud_row2)
		{return stud_row1.get_ratio() < stud_row2.get_ratio();});

	return *it_max_ratio_studs_row;
}



