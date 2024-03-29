﻿//---------------------------------------------------------------------------

#pragma hdrstop

#include "uCompSectsOutputSP266.h"
#include <algorithm>
#include "uUnits.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

std::vector<double> CompSectsOutputSP266::x_lst()const
{
	std::vector<double> x;

	for(auto const & s:com_sects_)
		x.push_back(s.nd_.x());

	return x;
}
std::vector<double> CompSectsOutputSP266::end_sup_coord()const
{
	std::vector<double> coord;
	for(auto const & s:com_sects_)
		if(s.nd_.is_end_support())
			coord.push_back(s.nd_.x());

   return coord;
}
std::vector<double> CompSectsOutputSP266::inter_sup_coord()const
{
	std::vector<double> coord;

	for(auto const & s:com_sects_)
		if(s.nd_.is_inter_support())
			coord.push_back(s.nd_.x());

   return coord;
}
std::vector<double> CompSectsOutputSP266::sup_coord()const
{
	std::vector<double> coord;

	for(auto const & s:com_sects_)
		if(s.nd_.is_end_support() || s.nd_.is_inter_support())
			coord.push_back(s.nd_.x());

   return coord;
}
std::vector<double> CompSectsOutputSP266::M_1a_lst()const
{
	std::vector<double> E;

	for(auto const & s:com_sects_)
		E.push_back(s.M_1a_);

	return E;
}
std::vector<double> CompSectsOutputSP266::M_1b_lst()const
{
    	std::vector<double> E;

	for(auto const & s:com_sects_)
		E.push_back(s.M_1b_);

	return E;

}
std::vector<double> CompSectsOutputSP266::M_2c_lst()const
{
	std::vector<double> E;

	for(auto const & s:com_sects_)
		E.push_back(s.M_2c_);

	return E;
}
std::vector<double> CompSectsOutputSP266::M_2d_lst()const
{
	std::vector<double> E;

	for(auto const & s:com_sects_)
		E.push_back(s.M_2d_);

	return E;
}
std::vector<double> CompSectsOutputSP266::M_total_lst()const
{
	std::vector<double> E;

	for(auto const & s:com_sects_)
		E.push_back(s.M_total_);

	return E;
}
std::vector<double> CompSectsOutputSP266::Q_1a_lst()const
{
	std::vector<double> E;

	for(auto const & s:com_sects_)
		E.push_back(s.Q_1a_);

	return E;
}
std::vector<double> CompSectsOutputSP266::Q_1b_lst()const
{
	std::vector<double> E;

	for(auto const & s:com_sects_)
		E.push_back(s.Q_1b_);

	return E;
}
std::vector<double> CompSectsOutputSP266::Q_2c_lst()const
{
	std::vector<double> E;

	for(auto const & s:com_sects_)
		E.push_back(s.Q_2c_);

	return E;
}
std::vector<double> CompSectsOutputSP266::Q_2d_lst()const
{
	std::vector<double> E;

	for(auto const & s:com_sects_)
		E.push_back(s.Q_2d_);

	return E;
}
std::vector<double> CompSectsOutputSP266::Q_total_lst()const
{
	std::vector<double> E;

	for(auto const & s:com_sects_)
		E.push_back(s.Q_total_);

	return E;
}

std::vector<double> CompSectsOutputSP266::R_1a_lst()const
{
	std::vector<double> E;

	for(auto const & s:com_sects_)
		E.push_back(s.R_1a_);

	return E;
}
std::vector<double> CompSectsOutputSP266::R_1b_lst()const
{
	std::vector<double> E;

	for(auto const & s:com_sects_)
		E.push_back(s.R_1b_);

	return E;
}
std::vector<double> CompSectsOutputSP266::R_2c_lst()const
{
	std::vector<double> E;

	for(auto const & s:com_sects_)
		E.push_back(s.R_2c_);

	return E;
}
std::vector<double> CompSectsOutputSP266::R_2d_lst()const
{
	std::vector<double> E;

	for(auto const & s:com_sects_)
		E.push_back(s.R_2d_);

	return E;
}
std::vector<double> CompSectsOutputSP266::R_total_lst()const
{
	std::vector<double> E;

	for(auto const & s:com_sects_)
		E.push_back(s.R_total_);

	return E;
}

std::vector<double> CompSectsOutputSP266::f_1a_lst()const
{
	std::vector<double> E;

	for(auto const & s:com_sects_)
		E.push_back(s.f_1a_);

	return E;
}
std::vector<double> CompSectsOutputSP266::f_1b_lst()const
{
	std::vector<double> E;

	for(auto const & s:com_sects_)
		E.push_back(s.f_1b_);

	return E;
}
std::vector<double> CompSectsOutputSP266::f_2c_lst()const
{
	std::vector<double> E;

	for(auto const & s:com_sects_)
		E.push_back(s.f_2c_);

	return E;
}
std::vector<double> CompSectsOutputSP266::f_2d_lst()const
{
	std::vector<double> E;

	for(auto const & s:com_sects_)
		E.push_back(s.f_2d_);

	return E;
}
std::vector<double> CompSectsOutputSP266::f_total_lst()const
{
	std::vector<double> E;

	for(auto const & s:com_sects_)
		E.push_back(s.f_total_);

	return E;
}
CompSectOutputSP266 const & CompSectsOutputSP266::max_st_sect_ratio_sect()const
{
	return *std::max_element(com_sects_.begin(), com_sects_.end(),
		[](auto const &  sect_output1, auto const & sect_output2)
		{return sect_output1.st_sect_ratio_ < sect_output2.st_sect_ratio_;});
}
CompSectOutputSP266 const & CompSectsOutputSP266::max_direct_str_ratio_sect()const
{
	return *std::max_element(com_sects_.begin(), com_sects_.end(),
		[](auto const &  sect_output1, auto const & sect_output2)
		{return sect_output1.max_direct_str_ratio() < sect_output2.max_direct_str_ratio();});
}

CompSectOutputSP266 const & CompSectsOutputSP266::max_shear_str_ratio_sect()const
{
	return *std::max_element(com_sects_.begin(), com_sects_.end(),
		[](auto const &  sect_output1, auto const & sect_output2)
		{return sect_output1.shear_ratio_ < sect_output2.shear_ratio_;});
}
CompSectOutputSP266 const & CompSectsOutputSP266::max_rigid_pl_sect()const
{
	return *std::max_element(com_sects_.begin(), com_sects_.end(),
		[](auto const &  sect_output1, auto const & sect_output2)
		{return sect_output1.rigid_pl_ratio_ < sect_output2.rigid_pl_ratio_;});
}
void CompSectsOutputSP266::fill_ratios_grid(TStringGrid* str_grid)const
{
	CompSectOutputSP266 sect1 = max_st_sect_ratio_sect();

	str_grid -> Cells [1][2] = FloatToStrF(sect1.nd_.x(), ffFixed, 15, 0);
	str_grid -> Cells [1][3] = FloatToStrF(sect1.st_sect_ratio_, ffFixed, 15, 2);

	CompSectOutputSP266 sect2 = max_direct_str_ratio_sect();

	str_grid -> Cells [1][5] = FloatToStrF(sect2.nd_.x(), ffFixed, 15, 0);
	str_grid -> Cells [1][6] = FloatToStrF(sect2.upper_fl_ratio_, ffFixed, 15, 2);
	str_grid -> Cells [1][7] = FloatToStrF(sect2.lower_fl_ratio_, ffFixed, 15, 2);
	str_grid -> Cells [1][8] = FloatToStrF(sect2.conc_ratio_, ffFixed, 15, 2);

	CompSectOutputSP266 sect3 = max_rigid_pl_sect();

	str_grid -> Cells [1][10] = FloatToStrF(sect3.nd_.x(), ffFixed, 15, 0);
	str_grid -> Cells [1][11] = FloatToStrF(sect3.rigid_pl_ratio_, ffFixed, 15, 2);

	CompSectOutputSP266 sect4 = max_shear_str_ratio_sect();

	str_grid -> Cells [1][13] = FloatToStrF(sect4.nd_.x(), ffFixed, 15, 0);
	str_grid -> Cells [1][14] = FloatToStrF(sect4.shear_ratio_, ffFixed, 15, 2);
}
void CompSectsOutputSP266::fill_steel_sect_grid(TStringGrid* str_grid) const
{
	comp_sect_geom_.fill_steel_sect_grid(str_grid);
}
void CompSectsOutputSP266::fill_conc_sect_grid(TStringGrid* str_grid) const
{
	comp_sect_geom_.fill_conc_sect_grid(str_grid);
}
void CompSectsOutputSP266::fill_comp_sect_grid(TStringGrid* str_grid)const
{
	comp_sect_geom_.fill_comp_sect_grid(str_grid);
}
void CompSectsOutputSP266::print(TWord_Automation & report)const
{
	using namespace units;

	comp_sect_geom_.print(report);
	glob_geom_.print(report);
	loads_.print_SP266(report);
	work_cond_factrs_.print(report);

	CompSectOutputSP266 sect1 = max_st_sect_ratio_sect();

	report.PasteTextPattern(double_to_str(sect1.nd_.x(), 0),"%cs_x%");
	report.PasteTextPattern(double_to_str(sect1.M_1a_ * kN * m),"%M_1a%");
	report.PasteTextPattern(double_to_str(sect1.M_1b_ * kN * m),"%M_1b%");
	report.PasteTextPattern(double_to_str(sect1.M_2c_ * kN * m),"%M_2c%");
	report.PasteTextPattern(double_to_str(sect1.M_2d_ * kN * m),"%M_2d%");
	report.PasteTextPattern(double_to_str(sect1.M_total_ * kN * m),"%M_total%");

	report.PasteTextPattern(double_to_str(sect1.sigma_b_),"%sigma_b%");
	report.PasteTextPattern(double_to_str(sect1.sigma_s_),"%sigma_s%");

	report.PasteTextPattern(double_to_str(sect1.nd_.x(),0),"%x_M%");
	report.PasteTextPattern(double_to_str(sect1.upper_fl_ratio_),"%uf_ratio%");
	report.PasteTextPattern(double_to_str(sect1.lower_fl_ratio_),"%lf_ratio%");
	report.PasteTextPattern(double_to_str(sect1.conc_ratio_),"%conc_ratio%");

	CompSectOutputSP266 sect2 = max_direct_str_ratio_sect();

	report.PasteTextPattern(double_to_str(sect2.nd_.x(), 0),"%x_M_I%");
	report.PasteTextPattern(double_to_str(sect2.st_sect_ratio_),"%i_section_ratio%");

	CompSectOutputSP266 sect3 = max_rigid_pl_sect();

	report.PasteTextPattern(double_to_str(sect3.nd_.x(), 0),"%x_rigid_plastic%");
	report.PasteTextPattern(double_to_str(sect3.rigid_pl_ratio_),"%rigid_plastic_ratio%");

	CompSectOutputSP266 sect4 = max_shear_str_ratio_sect();

	report.PasteTextPattern(double_to_str(sect4.nd_.x(), 0),"%x_Q%");
	report.PasteTextPattern(double_to_str(sect4.shear_ratio_),"%ratio_shear%");
}

