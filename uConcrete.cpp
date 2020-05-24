//---------------------------------------------------------------------------

#pragma hdrstop

#include "uConcrete.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
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
//---------------------------------------------------------------------------
Concrete::Concrete()
	:ConcreteBasic(){}
//---------------------------------------------------------------------------
Concrete::Concrete(ConcreteBasic concrete_basic,
				   double        density,
				   double        phi_b_cr,
				   double        gamma_b,
				   double        gamma_bt,
				   double        epsilon_b_lim):
						ConcreteBasic (concrete_basic),
						density_      (density),
						phi_b_cr_     (phi_b_cr),
						gamma_b_      (gamma_b),
						gamma_bt_     (gamma_bt),
						epsilon_b_lim_(epsilon_b_lim)
{
}
void ConcreteBasic::save(ostream& ostr) const
{
	wchar_t* buf = grade_.w_str();
	unsigned short l = grade_.Length()+1;
	ostr.write((char*)&l,sizeof(l));
	ostr.write((char*)buf,l*sizeof(wchar_t));
	free(buf);

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
	ostr.write((char*)&gamma_b_ ,sizeof(gamma_b_));
	ostr.write((char*)&gamma_bt_ ,sizeof(gamma_bt_));
	ostr.write((char*)&epsilon_b_lim_ ,sizeof(epsilon_b_lim_));
}
void Concrete::load(istream& istr)
{
	ConcreteBasic::load(istr);

	istr.read((char*)&density_ ,sizeof(density_));
	istr.read((char*)&phi_b_cr_ ,sizeof(phi_b_cr_));
	istr.read((char*)&gamma_b_ ,sizeof(gamma_b_));
	istr.read((char*)&gamma_bt_ ,sizeof(gamma_bt_));
	istr.read((char*)&epsilon_b_lim_ ,sizeof(epsilon_b_lim_));
}
//-----------------------------------------------------------------------------
//Присваение данным класса значений по умолчанию
//-----------------------------------------------------------------------------
void Concrete::set_default_values()
{
	grade_ = L"B25";
	E_b_ = 30000. ;
	density_ = 2500e-9;
	R_bn_ = 18.5;
	R_btn_ = 1.55;
	phi_b_cr_ = 3.2;
	gamma_b_ =  1.3;
	gamma_bt_ = 1.5;
	epsilon_b_lim_ = 0.0016;
}




