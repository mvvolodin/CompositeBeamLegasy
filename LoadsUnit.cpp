//---------------------------------------------------------------------------

#pragma hdrstop
#include "LoadsUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

TLoads::TLoads(){}

TLoads::TLoads(double SW, double SW_sheets, double DL_I, double DL_II, double LL,
	double gamma_f_st_SW, double gamma_f_DL_I, double gamma_f_DL_II, double gamma_f_LL)
	:SW_(SW/static_cast<int>(LengthUnit::m)),
	SW_sheets_(SW_sheets/std::pow(static_cast<int>(LengthUnit::m),2)),
	DL_I_(DL_I*static_cast<int>(LoadUnit::kN)/std::pow(static_cast<int>(LengthUnit::m),2)),  //Полезно сделать сеттеры!
	DL_II_(DL_II*static_cast<int>(LoadUnit::kN)/std::pow(static_cast<int>(LengthUnit::m),2)),
	LL_(LL*static_cast<int>(LoadUnit::kN)/std::pow(static_cast<int>(LengthUnit::m),2)),
	gamma_f_st_SW_(gamma_f_st_SW),
	gamma_f_DL_I_(gamma_f_DL_I),
	gamma_f_DL_II_(gamma_f_DL_II),
	gamma_f_LL_(gamma_f_LL){}

void TLoads::save(std::ostream& ostr) const
{
	ostr.write((char*)&SW_, sizeof(SW_ ));
	ostr.write((char*)&SW_sheets_, sizeof(SW_sheets_));
	ostr.write((char*)&DL_I_, sizeof(DL_I_));
	ostr.write((char*)&DL_II_, sizeof(DL_II_));
	ostr.write((char*)&LL_, sizeof(LL_));
	ostr.write((char*)&gamma_f_st_SW_, sizeof(gamma_f_st_SW_));
	ostr.write((char*)&gamma_f_DL_I_, sizeof(gamma_f_DL_I_));
	ostr.write((char*)&gamma_f_DL_II_, sizeof(gamma_f_DL_II_));
	ostr.write((char*)&gamma_f_LL_, sizeof(gamma_f_LL_));

}
void TLoads::load(std::istream& istr)
{
	istr.read((char*)&SW_, sizeof(SW_ ));
	istr.read((char*)&SW_sheets_, sizeof(SW_sheets_));
	istr.read((char*)&DL_I_, sizeof(DL_I_));
	istr.read((char*)&DL_II_, sizeof(DL_II_));
	istr.read((char*)&LL_, sizeof(LL_));
	istr.read((char*)&gamma_f_st_SW_, sizeof(gamma_f_st_SW_));
	istr.read((char*)&gamma_f_DL_I_, sizeof(gamma_f_DL_I_));
	istr.read((char*)&gamma_f_DL_II_, sizeof(gamma_f_DL_II_));
	istr.read((char*)&gamma_f_LL_, sizeof(gamma_f_LL_));

}
//-----------------------------------------------------------------------------
//Присваение данным класса значений по умолчанию
//-----------------------------------------------------------------------------
void TLoads::set_default_values()
{
	SW_ = 0.;
	SW_sheets_ = 0.;
	DL_I_ = 0.0012;
	DL_II_ = 0.0015;
	LL_ =  0.002;
	gamma_f_st_SW_ = 1.05;
	gamma_f_DL_I_ = 1.35;
	gamma_f_DL_II_ = 1.35;
	gamma_f_LL_ = 1.35;
}
