
    //---------------------------------------------------------------------------

    #pragma hdrstop

	#include<cmath>
	#include "uConcretePart.h"
	//---------------------------------------------------------------------------
	#pragma package(smart_init)

//---------------------------------------------------------------------------
ConcretePart::ConcretePart()
{
}
ConcretePart::ConcretePart(String slab_type, SlabType slab_type_enum, Concrete concrete, Rebar rebar, double h_f, double h_n)
	:slab_type_(slab_type), slab_type_enum_(slab_type_enum),concrete_(concrete),rebar_(rebar), h_f_(h_f), h_n_(h_n)
{}
//-----------------------------------------------------------------------------
//Присваение данным класса значений по умолчанию
//-----------------------------------------------------------------------------
void ConcretePart::set_default_values()
{
	slab_type_ = L"Плоская плита";
	slab_type_enum_ = SlabType::FLAT;
	h_f_ = 200.;
	h_n_ = 0.;
	concrete_.set_default_values();
	rebar_.set_default_values();
}
//---------------------------------------------------------------------------
//Сохранение объекта в бинарный файл
//---------------------------------------------------------------------------
void ConcretePart::save(std::ostream& ostr) const
{
	concrete_.save(ostr);
	rebar_.save(ostr);

	wchar_t* buf = slab_type_.w_str();
	unsigned short l = slab_type_.Length()+1;
	ostr.write((char*)&l,sizeof(l));
	ostr.write((char*)buf,l*sizeof(wchar_t));
	free(buf);

	ostr.write((char*)&slab_type_enum_ ,sizeof(slab_type_enum_));
	ostr.write((char*)&h_f_,sizeof(h_f_));
}
//---------------------------------------------------------------------------
//Загрузка объекта из бинарного файла
//---------------------------------------------------------------------------
void ConcretePart::load(std::istream& istr)
{
	concrete_.load(istr);
	rebar_.load(istr);

	wchar_t* buf;
	unsigned short l;
	istr.read((char*)&l,sizeof(l));
	buf =(wchar_t*) malloc(l*sizeof(wchar_t));
	istr.read((char*)buf,l*sizeof(wchar_t));
	slab_type_ = String(buf);
	free(buf);

	istr.read((char*)&slab_type_enum_ ,sizeof(slab_type_enum_));
	istr.read((char*)&h_f_,sizeof(h_f_));
}
double ConcretePart::get_h(LengthUnit length_unit) const
{
	double h = 0.;

	if (slab_type_enum_ == SlabType::CORRUGATED)
		h = CorrugatedSheetsData::get_corrugated_sheet(slab_type_).get_height() + h_f_;

	h = h_n_ + h_f_ ;

	return h/static_cast<int>(length_unit);
}
double ConcretePart::get_C_b(LengthUnit length_unit) const
{
	double C_b = 0.;

	if (slab_type_enum_ == SlabType::CORRUGATED)
		C_b = CorrugatedSheetsData::get_corrugated_sheet(slab_type_).get_height() + h_f_ / 2.;

	C_b = h_n_ + h_f_ / 2.;

	return C_b/static_cast<int>(length_unit);
}

double ConcretePart::get_A_b(LengthUnit length_unit) const
{
	double A_b = 0.;

	A_b = b_ * h_f_;

	return A_b/std::pow(static_cast<int>(length_unit),2);
}
double ConcretePart::get_I_b(LengthUnit length_unit) const
{
	double I_b = 0.;

	I_b = b_ * std::pow(h_f_,3) / 12;

	return I_b/std::pow(static_cast<int>(length_unit),4);
}
double ConcretePart::get_SW_concrete(LoadUnit load_unit, LengthUnit length_unit) const
{
	double SW_concrete = 0.;

	double density = concrete_.get_density();

	if (slab_type_enum_ == SlabType::CORRUGATED)
		SW_concrete = density * GRAV_ACCELERAT * (h_f_ + CorrugatedSheetsData::get_corrugated_sheet(slab_type_).get_h_b());

	SW_concrete = density * GRAV_ACCELERAT * h_f_;

	return SW_concrete/static_cast<int>(load_unit)*std::pow(static_cast<int>(length_unit),2);
}


