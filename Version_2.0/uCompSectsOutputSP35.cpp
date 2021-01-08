//---------------------------------------------------------------------------

#pragma hdrstop

#include "uCompSectsOutputSP35.h"
#include <algorithm>
//---------------------------------------------------------------------------
#pragma package(smart_init)

std::vector<double> CompSectsOutputSP35::x_lst()const
{
	std::vector<double> x;

	for(auto const & s:com_sects_)
		x.push_back(s.nd_.x());

	return x;
}
std::vector<double> CompSectsOutputSP35::end_sup_coord()const
{
	std::vector<double> coord;
	for(auto const & s:com_sects_)
		if(s.nd_.is_end_support())
			coord.push_back(s.nd_.x());

   return coord;
}
std::vector<double> CompSectsOutputSP35::inter_sup_coord()const
{
	std::vector<double> coord;

	for(auto const & s:com_sects_)
		if(s.nd_.is_inter_support())
			coord.push_back(s.nd_.x());

   return coord;
}
std::vector<double> CompSectsOutputSP35::sup_coord()const
{
	std::vector<double> coord;

	for(auto const & s:com_sects_)
		if(s.nd_.is_end_support() || s.nd_.is_inter_support())
			coord.push_back(s.nd_.x());

   return coord;
}
std::vector<double> CompSectsOutputSP35::M_1a_lst()const
{
	std::vector<double> E;

	for(auto const & s:com_sects_)
		E.push_back(s.M_1a_);

	return E;
}
std::vector<double> CompSectsOutputSP35::M_1b_lst()const
{
    	std::vector<double> E;

	for(auto const & s:com_sects_)
		E.push_back(s.M_1b_);

	return E;

}
std::vector<double> CompSectsOutputSP35::M_2c_lst()const
{
	std::vector<double> E;

	for(auto const & s:com_sects_)
		E.push_back(s.M_2c_);

	return E;
}
std::vector<double> CompSectsOutputSP35::M_2d_lst()const
{
	std::vector<double> E;

	for(auto const & s:com_sects_)
		E.push_back(s.M_2d_);

	return E;
}
std::vector<double> CompSectsOutputSP35::M_total_lst()const
{
	std::vector<double> E;

	for(auto const & s:com_sects_)
		E.push_back(s.M_total_);

	return E;
}
std::vector<double> CompSectsOutputSP35::Q_1a_lst()const
{
	std::vector<double> E;

	for(auto const & s:com_sects_)
		E.push_back(s.Q_1a_);

	return E;
}
std::vector<double> CompSectsOutputSP35::Q_1b_lst()const
{
	std::vector<double> E;

	for(auto const & s:com_sects_)
		E.push_back(s.Q_1b_);

	return E;
}
std::vector<double> CompSectsOutputSP35::Q_2c_lst()const
{
	std::vector<double> E;

	for(auto const & s:com_sects_)
		E.push_back(s.Q_2c_);

	return E;
}
std::vector<double> CompSectsOutputSP35::Q_2d_lst()const
{
	std::vector<double> E;

	for(auto const & s:com_sects_)
		E.push_back(s.Q_2d_);

	return E;
}
std::vector<double> CompSectsOutputSP35::Q_total_lst()const
{
	std::vector<double> E;

	for(auto const & s:com_sects_)
		E.push_back(s.Q_total_);

	return E;
}

std::vector<double> CompSectsOutputSP35::R_1a_lst()const
{
	std::vector<double> E;

	for(auto const & s:com_sects_)
		E.push_back(s.R_1a_);

	return E;
}
std::vector<double> CompSectsOutputSP35::R_1b_lst()const
{
	std::vector<double> E;

	for(auto const & s:com_sects_)
		E.push_back(s.R_1b_);

	return E;
}
std::vector<double> CompSectsOutputSP35::R_2c_lst()const
{
	std::vector<double> E;

	for(auto const & s:com_sects_)
		E.push_back(s.R_2c_);

	return E;
}
std::vector<double> CompSectsOutputSP35::R_2d_lst()const
{
	std::vector<double> E;

	for(auto const & s:com_sects_)
		E.push_back(s.R_2d_);

	return E;
}
std::vector<double> CompSectsOutputSP35::R_total_lst()const
{
	std::vector<double> E;

	for(auto const & s:com_sects_)
		E.push_back(s.R_total_);

	return E;
}

std::vector<double> CompSectsOutputSP35::f_1a_lst()const
{
	std::vector<double> E;

	for(auto const & s:com_sects_)
		E.push_back(s.f_1a_);

	return E;
}
std::vector<double> CompSectsOutputSP35::f_1b_lst()const
{
	std::vector<double> E;

	for(auto const & s:com_sects_)
		E.push_back(s.f_1b_);

	return E;
}
std::vector<double> CompSectsOutputSP35::f_2c_lst()const
{
	std::vector<double> E;

	for(auto const & s:com_sects_)
		E.push_back(s.f_2c_);

	return E;
}
std::vector<double> CompSectsOutputSP35::f_2d_lst()const
{
	std::vector<double> E;

	for(auto const & s:com_sects_)
		E.push_back(s.f_2d_);

	return E;
}
std::vector<double> CompSectsOutputSP35::f_total_lst()const
{
	std::vector<double> E;

	for(auto const & s:com_sects_)
		E.push_back(s.f_total_);

	return E;
}
CompSectOutputSP35 const & CompSectsOutputSP35::max_st_sect_ratio_sect()const
{
	return *std::max_element(com_sects_.begin(), com_sects_.end(),
		[](auto const &  sect_output1, auto const & sect_output2)
		{return sect_output1.st_sect_ratio_ < sect_output2.st_sect_ratio_;});
}
CompSectOutputSP35 const & CompSectsOutputSP35::max_direct_str_ratio_sect()const
{
	return *std::max_element(com_sects_.begin(), com_sects_.end(),
		[](auto const &  sect_output1, auto const & sect_output2)
		{return sect_output1.max_direct_str_ratio() < sect_output2.max_direct_str_ratio();});
}

CompSectOutputSP35 const & CompSectsOutputSP35::max_shear_str_ratio_sect()const
{
	return *std::max_element(com_sects_.begin(), com_sects_.end(),
		[](auto const &  sect_output1, auto const & sect_output2)
		{return sect_output1.shear_ratio_ < sect_output2.shear_ratio_;});
}
void CompSectsOutputSP35::fill_ratios_grid(TStringGrid* str_grid)const
{
	CompSectOutputSP35 sect1 = max_st_sect_ratio_sect();

	str_grid -> Cells [1][2] = FloatToStrF(sect1.nd_.x(), ffFixed, 15, 0);
	str_grid -> Cells [1][3] = FloatToStrF(sect1.st_sect_ratio_, ffFixed, 15, 2);

	CompSectOutputSP35 sect2 = max_direct_str_ratio_sect();

	str_grid -> Cells [1][5] = FloatToStrF(sect2.nd_.x(), ffFixed, 15, 0);
	str_grid -> Cells [1][6] = FloatToStrF(sect2.upper_fl_ratio_, ffFixed, 15, 2);
	str_grid -> Cells [1][7] = FloatToStrF(sect2.lower_fl_ratio_, ffFixed, 15, 2);
	str_grid -> Cells [1][8] = FloatToStrF(sect2.conc_ratio_, ffFixed, 15, 2);

	CompSectOutputSP35 sect3 = max_shear_str_ratio_sect();

	str_grid -> Cells [1][10] = FloatToStrF(sect3.nd_.x(), ffFixed, 15, 0);
	str_grid -> Cells [1][11] = FloatToStrF(sect3.shear_ratio_, ffFixed, 15, 2);
}
void  CompSectsOutputSP35::fill_steel_sect_grid(TStringGrid* str_grid)const
{
	comp_sect_geom_.fill_steel_sect_grid(str_grid);
}
void  CompSectsOutputSP35::fill_conc_sect_grid(TStringGrid* str_grid)const
{
	comp_sect_geom_.fill_conc_sect_grid(str_grid);
}
void CompSectsOutputSP35::fill_comp_sect_grid(TStringGrid* str_grid)const
{
	comp_sect_geom_.fill_comp_sect_grid(str_grid);
}
void CompSectsOutputSP35::print(TWord_Automation & report)const
{
	using namespace units;

	comp_sect_geom_.print(report);
	glob_geom_.print(report);
	loads_.print_SP35(report);
	work_cond_factrs_.print(report);

	CompSectOutputSP35 sect1 = max_direct_str_ratio_sect();

	//Печать коэффициентоа пластичности
	sect1.pl_cfs_.print(report);

	// Печать моментов
	report.PasteTextPattern(double_to_str(sect1.nd_.x(), 0),"%cs_x%");
	report.PasteTextPattern(double_to_str(sect1.M_1a_ * kN * m),"%M_1a%");
	report.PasteTextPattern(double_to_str(sect1.M_1b_ * kN * m),"%M_1b%");
	report.PasteTextPattern(double_to_str(sect1.M_2c_ * kN * m),"%M_2c%");
	report.PasteTextPattern(double_to_str(sect1.M_2d_ * kN * m),"%M_2d%");
	report.PasteTextPattern(double_to_str(sect1.M_total_ * kN * m),"%M_total%");

 // Печать напряжений

	report.PasteTextPattern(double_to_str(sect1.sigma_bi_kr_),"%sigma_b_kr%");
	report.PasteTextPattern(double_to_str(sect1.sigma_ri_kr_),"%sigma_r_kr%");
	report.PasteTextPattern(double_to_str(sect1.sigma_bi_shr_),"%sigma_b_shr%");
	report.PasteTextPattern(double_to_str(sect1.sigma_ri_shr_),"%sigma_r_shr%");

	report.PasteTextPattern(double_to_str(sect1.sigma_b_),"%sigma_b%");
	report.PasteTextPattern(double_to_str(sect1.sigma_r_),"%sigma_r%");

//Печать Коэффициентов Использования

	report.PasteTextPattern(double_to_str(sect1.nd_.x(),0),"%x_M%");
	report.PasteTextPattern(double_to_str(sect1.upper_fl_ratio_),"%uf_ratio%");
	report.PasteTextPattern(double_to_str(sect1.lower_fl_ratio_),"%lf_ratio%");
	report.PasteTextPattern(double_to_str(sect1.conc_ratio_),"%conc_ratio%");

	CompSectOutputSP35 sect2 = max_direct_str_ratio_sect();

	report.PasteTextPattern(double_to_str(sect2.nd_.x(), 0),"%x_M_I%");
	report.PasteTextPattern(double_to_str(sect2.st_sect_ratio_),"%i_section_ratio%");

	CompSectOutputSP35 sect3 = max_shear_str_ratio_sect();

	report.PasteTextPattern(double_to_str(sect3.nd_.x(), 0),"%x_Q%");
	report.PasteTextPattern(double_to_str(sect3.shear_ratio_),"%ratio_shear%");
}

