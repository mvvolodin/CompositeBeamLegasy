
    //---------------------------------------------------------------------------

    #pragma hdrstop

	#include<cmath>
	#include "ConcretePartUnit.h"
	//---------------------------------------------------------------------------
	#pragma package(smart_init)

//---------------------------------------------------------------------------
TConcretePart::TConcretePart()
{
}
TConcretePart::TConcretePart(String slab_type, SlabType slab_type_enum, Concrete concrete, Rebar rebar, double h_f, double h_n)
	:slab_type_(slab_type), slab_type_enum_(slab_type_enum),concrete_(concrete),rebar_(rebar), h_f_(h_f), h_n_(h_n)
{}
//-----------------------------------------------------------------------------
//Присваение данным класса значений по умолчанию
//-----------------------------------------------------------------------------
void TConcretePart::set_default_values()
{
	slab_type_ = L"Плоская плита";
	slab_type_enum_ = SlabType::FLAT;
	h_f_ = 200.;
	h_n_ = 0.;
	concrete_.set_default_values();
	rebar_.set_default_values();
}
double TConcretePart::calculate_SW_concrete()
{
   double density = concrete_.get_density();
   return density * GRAV_ACCELERAT * (h_f_ + h_b_);
}
//---------------------------------------------------------------------------
//Сохранение объекта в бинарный файл
//---------------------------------------------------------------------------
void TConcretePart::save(std::ostream& ostr) const
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
void TConcretePart::load(std::istream& istr)
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
void TConcretePart::calculate()
{
	rebar_.calculate();
	concrete_.calculate();

	switch (slab_type_enum_)
	{
	case SlabType::FLAT:
		h_ = h_n_ + h_f_;
		C_b_ = h_n_ + h_f_/2.;
		A_b_ = (b_l_ + b_r_) * h_f_;
		I_b_ = (b_l_ + b_r_) * std::pow(h_f_,3) / 12;
		break;
	case SlabType::CORRUGATED:
		CorrugatedSheet cs = CorrugatedSheetsData::get_corrugated_sheet(slab_type_);
		h_n_ = cs.get_height();
		h_b_ = cs.get_h_b();
		h_ = h_n_ + h_f_;
		C_b_ = h_n_ + h_f_ / 2.;
		A_b_ = (b_l_ + b_r_) * h_f_;
		I_b_ = (b_l_ + b_r_) * std::pow(h_f_,3) / 12;
		break;
	}

	SW_concrete_ = calculate_SW_concrete();

	concrete_part_calculated_  = true;
}


