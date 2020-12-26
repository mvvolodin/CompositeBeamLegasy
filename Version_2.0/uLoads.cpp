//---------------------------------------------------------------------------

#pragma hdrstop
#include "uLoads.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

using namespace units;

Loads::Loads(double SW_steel_beam,
			 double SW_corrugated_sheets,
			 double SW_add_concrete,
			 double DL_I,
			 double DL_II,
			 double LL,
			 double gamma_f_SW,
			 double gamma_f_concrete_SW,
			 double gamma_f_add_concrete_SW,
			 double gamma_f_DL_I,
			 double gamma_f_DL_II,
			 double gamma_f_LL,
			 double sheeting_continuity_coefficient,
			 double fact_quasi_perm_load,
			 double sigma_bi,
			 double sigma_si)
	:SW_steel_beam_(SW_steel_beam),
	SW_corrugated_sheets_(SW_corrugated_sheets),
	SW_add_concrete_(SW_add_concrete*static_cast<int>(LoadUnit::kN)/std::pow(static_cast<int>(LengthUnit::m),2)),
	DL_I_(DL_I * N/mm2),  //Полезно сделать сеттеры!
	DL_II_(DL_II*static_cast<int>(LoadUnit::kN)/std::pow(static_cast<int>(LengthUnit::m),2)),
	LL_(LL*static_cast<int>(LoadUnit::kN)/std::pow(static_cast<int>(LengthUnit::m),2)),
	gamma_f_st_SW_(gamma_f_SW),
	gamma_f_concrete_SW_(gamma_f_concrete_SW),
	gamma_f_add_concrete_SW_(gamma_f_add_concrete_SW),
	gamma_f_DL_I_(gamma_f_DL_I),
	gamma_f_DL_II_(gamma_f_DL_II),
	gamma_f_LL_(gamma_f_LL),
	sheeting_continuity_coefficient_(sheeting_continuity_coefficient),
	fact_quasi_perm_load_(fact_quasi_perm_load),
	sigma_bi_(sigma_bi),
	sigma_si_(sigma_si){}
Loads::Loads(double SW_steel_beam,
			 double SW_corrugated_sheets,
			 double SW_conc,
			 double SW_add_concrete,
			 double DL_I,
			 double DL_II,
			 double LL,
			 double gamma_f_SW,
			 double gamma_f_concrete_SW,
			 double gamma_f_add_concrete_SW,
			 double gamma_f_DL_I,
			 double gamma_f_DL_II,
			 double gamma_f_LL,
			 double sheeting_continuity_coefficient,
			 double fact_quasi_perm_load,
			 double sigma_bi,
			 double sigma_si,
			 double B)
	:SW_steel_beam_(SW_steel_beam),
	SW_corrugated_sheets_(SW_corrugated_sheets),
	SW_concrete_(SW_conc),
	SW_add_concrete_(SW_add_concrete * N/mm2),
	DL_I_(DL_I * N/mm2),  //Полезно сделать сеттеры!
	DL_II_(DL_II * N/mm2),
	LL_(LL * N/mm2),
	gamma_f_st_SW_(gamma_f_SW),
	gamma_f_concrete_SW_(gamma_f_concrete_SW),
	gamma_f_add_concrete_SW_(gamma_f_add_concrete_SW),
	gamma_f_DL_I_(gamma_f_DL_I),
	gamma_f_DL_II_(gamma_f_DL_II),
	gamma_f_LL_(gamma_f_LL),
	sheeting_continuity_coefficient_(sheeting_continuity_coefficient),
	fact_quasi_perm_load_(fact_quasi_perm_load),
	sigma_bi_(sigma_bi),
	sigma_si_(sigma_si),
	B_(B){}
void Loads::save(std::ostream& ostr) const
{
	ostr.write((char*)&SW_steel_beam_, sizeof(SW_steel_beam_));
	ostr.write((char*)&SW_corrugated_sheets_, sizeof(SW_corrugated_sheets_));
	ostr.write((char*)&SW_concrete_, sizeof(SW_concrete_));
	ostr.write((char*)&SW_add_concrete_, sizeof(SW_add_concrete_));
	ostr.write((char*)&DL_I_, sizeof(DL_I_));
	ostr.write((char*)&DL_II_, sizeof(DL_II_));
	ostr.write((char*)&LL_, sizeof(LL_));

	ostr.write((char*)&sigma_bi_, sizeof(sigma_bi_));
	ostr.write((char*)&sigma_si_, sizeof(sigma_si_));

	ostr.write((char*)&gamma_f_st_SW_, sizeof(gamma_f_st_SW_));
	ostr.write((char*)&gamma_f_concrete_SW_, sizeof(gamma_f_concrete_SW_));
	ostr.write((char*)&gamma_f_add_concrete_SW_, sizeof(gamma_f_add_concrete_SW_));
	ostr.write((char*)&gamma_f_DL_I_, sizeof(gamma_f_DL_I_));
	ostr.write((char*)&gamma_f_DL_II_, sizeof(gamma_f_DL_II_));
	ostr.write((char*)&gamma_f_LL_, sizeof(gamma_f_LL_));

	ostr.write((char*)&sheeting_continuity_coefficient_, sizeof(sheeting_continuity_coefficient_));
}
void Loads::load(std::istream& istr)
{
	istr.read((char*)&SW_steel_beam_, sizeof(SW_steel_beam_ ));
	istr.read((char*)&SW_corrugated_sheets_, sizeof(SW_corrugated_sheets_));
	istr.read((char*)&SW_concrete_, sizeof(SW_concrete_));
	istr.read((char*)&SW_add_concrete_, sizeof(SW_add_concrete_));
	istr.read((char*)&DL_I_, sizeof(DL_I_));
	istr.read((char*)&DL_II_, sizeof(DL_II_));
	istr.read((char*)&LL_, sizeof(LL_));

	istr.read((char*)&sigma_bi_, sizeof(sigma_bi_));
	istr.read((char*)&sigma_si_, sizeof(sigma_si_));

	istr.read((char*)&gamma_f_st_SW_, sizeof(gamma_f_st_SW_));
	istr.read((char*)&gamma_f_concrete_SW_, sizeof(gamma_f_concrete_SW_));
	istr.read((char*)&gamma_f_add_concrete_SW_, sizeof(gamma_f_add_concrete_SW_));
	istr.read((char*)&gamma_f_DL_I_, sizeof(gamma_f_DL_I_));
	istr.read((char*)&gamma_f_DL_II_, sizeof(gamma_f_DL_II_));
	istr.read((char*)&gamma_f_LL_, sizeof(gamma_f_LL_));

	istr.read((char*)&sheeting_continuity_coefficient_, sizeof(sheeting_continuity_coefficient_));
}
//-----------------------------------------------------------------------------
//Расчёт значения нагрузки от комбинации загружений 1a
//-----------------------------------------------------------------------------
double Loads::LCC_1a_des()const
{
	assert(fully_initialized_);
	return gamma_f_st_SW_ * SW_steel_beam_ +
		gamma_f_st_SW_ * sheeting_continuity_coefficient_ * SW_corrugated_sheets_ * B_ +
		gamma_f_concrete_SW_ * sheeting_continuity_coefficient_ * SW_concrete_ * B_ +
		gamma_f_add_concrete_SW_ * sheeting_continuity_coefficient_ * SW_add_concrete_ * B_ +
		gamma_f_DL_I_ * sheeting_continuity_coefficient_ * DL_I_ * B_;
}
//-----------------------------------------------------------------------------
//Расчёт значения нагрузки от комбинации загружений 1b
//-----------------------------------------------------------------------------
double Loads::LCC_1b_des()const
{
	assert(fully_initialized_);
	return gamma_f_st_SW_ * SW_steel_beam_ +
		gamma_f_st_SW_ * sheeting_continuity_coefficient_ * SW_corrugated_sheets_ * B_ +
		gamma_f_concrete_SW_ * sheeting_continuity_coefficient_ * SW_concrete_ * B_ +
		gamma_f_add_concrete_SW_ * sheeting_continuity_coefficient_ * SW_add_concrete_ * B_;
}
//-----------------------------------------------------------------------------
//Расчёт значения нагрузки от комбинации загружений 2c
//-----------------------------------------------------------------------------
double Loads::LCC_2d_des()const
{
	assert(fully_initialized_);
	 return gamma_f_DL_II_ * DL_II_ * B_
		+ gamma_f_LL_ * LL_ * B_;
}
double Loads::LCC_2d_DL_des()const
{
	return gamma_f_DL_II_ * DL_II_ * B_;
}

double Loads::LCC_1a()const
{
	assert(fully_initialized_);
	return SW_steel_beam_ +
		sheeting_continuity_coefficient_ * SW_corrugated_sheets_ * B_ +
		sheeting_continuity_coefficient_ * SW_concrete_ * B_ +
		sheeting_continuity_coefficient_ * SW_add_concrete_ * B_ +
		sheeting_continuity_coefficient_ * DL_I_ * B_;
}
double Loads::LCC_1b()const
{
	assert(fully_initialized_);
	return SW_steel_beam_ +
		sheeting_continuity_coefficient_ * SW_corrugated_sheets_ * B_ +
		sheeting_continuity_coefficient_ * SW_concrete_ * B_ +
		sheeting_continuity_coefficient_ * SW_add_concrete_ * B_;

}
double Loads::LCC_2d()const
{
	assert(fully_initialized_);
	return DL_II_ * B_ +
		LL_ * B_;
}
double Loads::LCC_2d_DL()const
{
	return DL_II_ * B_;
}

//-----------------------------------------------------------------------------
//Присваение данным класса значений по умолчанию
//-----------------------------------------------------------------------------
void Loads::set_default_values()
{
	SW_steel_beam_ = 0.;
	SW_corrugated_sheets_ = 0.;
	SW_concrete_ = 0.;
	SW_add_concrete_ = 0.00026;
	DL_I_ = 0.0005;
	DL_II_ = 0.002;
	LL_ =  0.004;

	sigma_bi_ = 0.;
	sigma_si_ = 0.;

	gamma_f_st_SW_ = 1.05;
	gamma_f_concrete_SW_ = 1.2;
	gamma_f_add_concrete_SW_ = 1.1;
	gamma_f_DL_I_ = 1.3;
	gamma_f_DL_II_ = 1.2;
	gamma_f_LL_ = 1.2;

	sheeting_continuity_coefficient_ = 1.25;
}

void Loads::set_data(double SW_steel_beam, double SW_corrugated_sheets, double SW_concrete, double B)
{
	SW_steel_beam_ = SW_steel_beam;
	SW_corrugated_sheets_ = SW_corrugated_sheets / 1000000;
	SW_concrete_ = SW_concrete;
	B_ = B;

	fully_initialized_ = true;
}
void Loads::print_SP266(TWord_Automation & report)const
{
	report.PasteTextPattern(double_to_str(SW_steel_beam_ * kN / m), "%steel_beam%");
	report.PasteTextPattern(double_to_str(SW_corrugated_sheets_ * kN / m2), "%SW_sheets%");
	report.PasteTextPattern(double_to_str(SW_concrete_ * kN / m2), "%SW_concrete%");
	report.PasteTextPattern(double_to_str(SW_add_concrete_ * kN / m2), "%SW_add_concrete%");
	report.PasteTextPattern(double_to_str(DL_I_ * kN / m2), "%DL_I%");
	report.PasteTextPattern(double_to_str(DL_II_ * kN / m2), "%DL_II%");
	report.PasteTextPattern(double_to_str(LL_ * kN / m2), "%LL%");

	report.PasteTextPattern(double_to_str(gamma_f_st_SW_), "%gamma_f_st_SW%");
	report.PasteTextPattern(double_to_str(gamma_f_concrete_SW_), "%gamma_f_concrete_SW%");
	report.PasteTextPattern(double_to_str(gamma_f_add_concrete_SW_), "%SW gamma_f_add_concr%");
	report.PasteTextPattern(double_to_str(gamma_f_DL_I_), "%gamma_f_DL_I%");
	report.PasteTextPattern(double_to_str(gamma_f_DL_II_), "%gamma_f_DL_II%");
	report.PasteTextPattern(double_to_str(gamma_f_LL_), "%gamma_f_LL%");

	report.PasteTextPattern(double_to_str(sheeting_continuity_coefficient_), "%sheeting_continuity_coeff%");
}

void Loads::print_SP35(TWord_Automation & report)const
{
	report.PasteTextPattern(double_to_str(SW_steel_beam_ * kN / m), "%steel_beam%");
	report.PasteTextPattern(double_to_str(SW_concrete_ * kN / m2), "%SW_concrete%");
	report.PasteTextPattern(double_to_str(SW_add_concrete_ * kN / m2), "%SW_add_concrete%");
	report.PasteTextPattern(double_to_str(DL_I_ * kN / m2), "%DL_I%");
	report.PasteTextPattern(double_to_str(DL_II_ * kN / m2), "%DL_II%");
	report.PasteTextPattern(double_to_str(LL_ * kN / m2), "%LL%");

	report.PasteTextPattern(double_to_str(gamma_f_st_SW_), "%gamma_f_st_SW%");
	report.PasteTextPattern(double_to_str(gamma_f_concrete_SW_), "%gamma_f_concrete_SW%");
	report.PasteTextPattern(double_to_str(gamma_f_add_concrete_SW_), "%SW gamma_f_add_concr%");
	report.PasteTextPattern(double_to_str(gamma_f_DL_I_), "%gamma_f_DL_I%");
	report.PasteTextPattern(double_to_str(gamma_f_DL_II_), "%gamma_f_DL_II%");
	report.PasteTextPattern(double_to_str(gamma_f_LL_), "%gamma_f_LL%");

	report.PasteTextPattern(double_to_str(sheeting_continuity_coefficient_), "%sheeting_continuity_coeff%");

}


