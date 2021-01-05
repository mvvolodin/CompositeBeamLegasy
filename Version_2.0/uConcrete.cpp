//---------------------------------------------------------------------------

#pragma hdrstop

#include "uConcrete.h"
#include "uUnits.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
namespace ConcreteSP35
{                                            //Марка, E_b, R_b, R-bt, c_n
	extern std::vector<Data> const data_lst{{u"B20"  , 27000, 15.0, 1.35, 115e-6},
											{u"B22.5", 28500, 15.0, 1.35, 107e-6},
											{u"B25"  , 30000, 18.5, 1.55, 100e-6},
											{u"B27.5", 31500, 18.5, 1.55, 92e-6},
											{u"B30"  , 32500, 22.1, 1.75, 84e-6},
											{u"B35"  , 34500, 25.5, 1.95, 75e-6},
											{u"B40"  , 36000, 29.0, 2.10, 67e-6},
											{u"B45"  , 37500, 32.0, 2.25, 55e-6},
											{u"B50"  , 39000, 36.0, 2.45, 50e-6},
											{u"B55"  , 39500, 36.0, 2.60, 41e-6},
											{u"B60"  , 40000, 39.5, 2.75, 39e-6}};

	std::vector<std::basic_string<char16_t>> grades()
	{
		std::vector<std::basic_string<char16_t>> grades;
		for(auto const & conc:data_lst)
			grades.emplace_back(conc.grade_);

		return std::move(grades);
    }
	Data const & concrete (int index)
	{
		return data_lst[index];
	}
	std::basic_string<char16_t> grade(int index)
	{
		return data_lst[index].grade_;
	}
	double R_b(int index)
	{
		return data_lst[index].R_b_;
	}
}
std::vector <ConcreteBasic> concrete_basic
{
	{"B10", 19000, 7.5, 0.85},   //Марка, E_b, R_b, R-bt
	{"B12.5", 21500, 9.5, 1},
	{"B15", 24000, 11, 1.1},
	{"B20", 27500, 15, 1.35},
	{"B25", 30000, 18.5, 1.55},
	{"B30", 32500, 22, 1.75},
	{"B35", 34500, 25.5, 1.95},
	{"B40", 36000, 29, 2.1},
	{"B45", 37000, 32, 2.25},
	{"B50", 38000, 36, 2.45},
	{"B55", 39000, 36, 2.6},
	{"B60", 39500, 39.5, 2.75},

};
//---------------------------------------------------------------------------
ConcreteBasic::ConcreteBasic(){}
//---------------------------------------------------------------------------
ConcreteBasic::ConcreteBasic(String grade,
							 double E_b,
							 double R_bn,
							 double R_btn):
								grade_(grade),
								E_b_  (E_b),
								R_bn_ (R_bn),
								R_btn_(R_btn){}
ConcreteBasic::ConcreteBasic(String grade,
							 double E_b,
							 double R_bn,
							 double R_btn,
							 double c_n):
								grade_(grade),
								E_b_  (E_b),
								R_bn_ (R_bn),
								R_btn_(R_btn),
								c_n_(c_n){}
//---------------------------------------------------------------------------
Concrete::Concrete()
	:ConcreteBasic(){}
//---------------------------------------------------------------------------
Concrete::Concrete(ConcreteBasic concrete_basic,
				   double        density,
				   double        phi_b_cr,
				   double 		 mater_coeff,
				   double        mater_coeff_tens,
				   double        epsilon_b_lim):
						ConcreteBasic 	  (concrete_basic),
						density_      	  (density / std::pow(static_cast<int>(LengthUnit::m),3)),
						phi_b_cr_     	  (phi_b_cr),
						mater_coeff_      (mater_coeff),
						mater_coeff_tens_ (mater_coeff_tens),
						epsilon_b_lim_	  (epsilon_b_lim)
{
}
void ConcreteBasic::save(ostream& ostr) const
{
	wchar_t* buf = grade_.w_str();
	unsigned short l = grade_.Length()+1;
	ostr.write((char*)&l,sizeof(l));
	ostr.write((char*)buf,l*sizeof(wchar_t));

	ostr.write((char*)&E_b_ ,sizeof(E_b_));
	ostr.write((char*)&R_bn_ ,sizeof(R_bn_));
	ostr.write((char*)&R_btn_ ,sizeof(R_btn_));
}
void ConcreteBasic::load(istream& istr)
{
	wchar_t* buf;
	unsigned short l;
	istr.read((char*)&l,sizeof(l));
	buf =(wchar_t*) malloc(l*sizeof(wchar_t));
	istr.read((char*)buf,l*sizeof(wchar_t));
	grade_ = String(buf);
	free(buf);

	istr.read((char*)&E_b_ ,sizeof(E_b_));
	istr.read((char*)&R_bn_ ,sizeof(R_bn_));
	istr.read((char*)&R_btn_ ,sizeof(R_btn_));
}

void Concrete::save(ostream& ostr) const
{
	ConcreteBasic::save(ostr);

	ostr.write((char*)&density_ ,sizeof(density_));
	ostr.write((char*)&phi_b_cr_ ,sizeof(phi_b_cr_));
	ostr.write((char*)&mater_coeff_ ,sizeof(mater_coeff_));
	ostr.write((char*)&mater_coeff_tens_ ,sizeof(mater_coeff_tens_));
	ostr.write((char*)&epsilon_b_lim_ ,sizeof(epsilon_b_lim_));
}
void Concrete::load(istream& istr)
{
	ConcreteBasic::load(istr);

	istr.read((char*)&density_ ,sizeof(density_));
	istr.read((char*)&phi_b_cr_ ,sizeof(phi_b_cr_));
	istr.read((char*)&mater_coeff_ ,sizeof(mater_coeff_));
	istr.read((char*)&mater_coeff_tens_ ,sizeof(mater_coeff_tens_));
	istr.read((char*)&epsilon_b_lim_ ,sizeof(epsilon_b_lim_));
}

void Concrete::set_default_values()
{
	grade_ = L"B30";
	E_b_ = 32500. ;
	density_ = 2500e-9;
	R_bn_ = 22;
	R_btn_ = 1.75;
	phi_b_cr_ = 2.3;
	mater_coeff_ =  1.3;
	mater_coeff_tens_ = 1.5;
	epsilon_b_lim_ = 0.0016;
}
void Concrete::print_SP266(TWord_Automation & report)const
{
	using namespace units;

	report.PasteTextPattern(grade_, "%conc_grade%");
	report.PasteTextPattern(double_to_str(R_bn_), "%R_bn%");
	report.PasteTextPattern(double_to_str(R_btn_), "%R_btn%");
	report.PasteTextPattern(double_to_str(density_ / m3, 0), "%density%");
	report.PasteTextPattern(double_to_str(phi_b_cr_), "%phi_b_cr%");
	report.PasteTextPattern(double_to_str(E_b_, 0), "%E_b%");
	report.PasteTextPattern(double_to_str(mater_coeff_), "%gamma_b%");
	report.PasteTextPattern(double_to_str(mater_coeff_tens_), "%gamma_bt%");
	report.PasteTextPattern(double_to_str(epsilon_b_lim_, 4), "%epsilon_b_lim%");
}
void Concrete::print(TWord_Automation & report)const
{
	using namespace units;

	report.PasteTextPattern(grade_, "%conc_grade%");
	report.PasteTextPattern(double_to_str(R_bn_), "%R_bn%");
	report.PasteTextPattern(double_to_str(R_btn_), "%R_btn%");
	report.PasteTextPattern(double_to_str(density_ / m3, 0), "%density%");
    report.PasteTextPattern(double_to_str(c_n_, 6), "%c_n%");
	report.PasteTextPattern(double_to_str(E_b_, 0), "%E_b%");
	report.PasteTextPattern(double_to_str(mater_coeff_), "%gamma_b%");
	report.PasteTextPattern(double_to_str(mater_coeff_tens_), "%gamma_bt%");
	report.PasteTextPattern(double_to_str(epsilon_b_lim_, 4), "%epsilon_b_lim%");
}




