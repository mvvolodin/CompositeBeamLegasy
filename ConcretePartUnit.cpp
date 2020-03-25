
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
TConcretePart::TConcretePart(String slab_type, SlabType slab_type_enum, Concrete concrete, Rebar rebar, double h_f, TGeometry geometry, double b_uf)
	:slab_type_(slab_type), slab_type_enum_(slab_type_enum),concrete_(concrete),rebar_(rebar), h_f_(h_f)
{}
//-----------------------------------------------------------------------------
//Присваение данным класса значений по умолчанию
//-----------------------------------------------------------------------------
void TConcretePart::set_default_values()
{
	slab_type_ = L"Плоская плита";
	slab_type_enum_ = SlabType::FLAT;
    h_f_ = 200;
	concrete_.set_default_values();
	rebar_.set_default_values();
}
//---------------------------------------------------------------------------
//Сохраняем объект ............. в бинарный файл
//---------------------------------------------------------------------------
void TConcretePart::save(std::ostream& ostr) const
{
	concrete_.save(ostr);
	rebar_.save(ostr);
}
//---------------------------------------------------------------------------
//Загружаем объект ........... из бинарного файла
//---------------------------------------------------------------------------
void TConcretePart::load(std::istream& istr)
{
	concrete_.load(istr);
	rebar_.load(istr);
}

TFlatSlab::TFlatSlab(Concrete concrete, Rebar rebar, double h_f, TGeometry geometry, double b_uf)
	:TConcretePart(L"Плоская плита", SlabType::FLAT, concrete, rebar, h_f, geometry, b_uf)
{
	h_b_=h_f;
	C_b_=h_b_/2.;
	A_b_=(b_l_+b_r_)*h_f;
	I_b_=(b_l_+b_r_)*std::pow(h_f,3)/12;
}

//---------------------------------------------------------------------------

TCorrugatedSlab::TCorrugatedSlab(String slab_type, Concrete concrete, Rebar rebar, double h_f, TGeometry geometry, double b_uf)
	:TConcretePart(slab_type, SlabType::CORRUGATED, concrete, rebar, h_f, geometry, b_uf)
{
   CorrugatedSheet corrugated_sheet = corrugated_sheets_map[slab_type];
   h_b_=corrugated_sheet.get_height()+h_f;
   C_b_=corrugated_sheet.get_height()+h_f/2.;
   A_b_=(b_l_+b_r_)*h_f;
   I_b_=(b_l_+b_r_)*std::pow(h_f,3)/12;
}

