//---------------------------------------------------------------------------
#pragma hdrstop
#include <algorithm>
#include "uComBeamOutputSP35.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------

ComBeamOutputSP35::ComBeamOutputSP35(ComposSectGeomSP35  com_sect,
									 ComposSectGeomSP35  com_sect_shr,
									 ComposSectGeomSP35  com_sect_kr,
									 std::vector<SectOutputSP35>  sect_outp_list):
		com_sect_(com_sect),
		com_sect_shr_(com_sect_shr),
		com_sect_kr_(com_sect_kr),
		sect_outp_list_(sect_outp_list){}

void ComBeamOutputSP35::print(TWord_Automation & report)const
{

	com_sect_.print(report);
	max_direct_str_ratio_sect().print_max_direct_str_ratio_sect(report);

}
std::vector<double> ComBeamOutputSP35::x_lst()const
{
	std::vector<double> x;

	for(auto const & s:sect_outp_list_)
		x.push_back(s.node().x());

	return x;
}
std::vector<double> ComBeamOutputSP35::end_sup_coord()const
{
	std::vector<double> coord;
	for(auto const & s:sect_outp_list_)
		if(s.node().is_end_support())
			coord.push_back(s.node().x());

   return coord;
}
std::vector<double> ComBeamOutputSP35::inter_sup_coord()const
{
	std::vector<double> coord;

	for(auto const & s:sect_outp_list_)
		if(s.node().is_inter_support())
			coord.push_back(s.node().x());

   return coord;
}
std::vector<double> ComBeamOutputSP35::sup_coord()const
{
	std::vector<double> coord;

	for(auto const & s:sect_outp_list_)
		if(s.node().is_end_support() || s.node().is_inter_support())
			coord.push_back(s.node().x());

   return coord;
}
std::vector<double> ComBeamOutputSP35::M_1a_lst()const
{
	std::vector<double> E;

	for(auto const & s:sect_outp_list_)
		E.push_back(s.M_1a());

	return E;
}
std::vector<double> ComBeamOutputSP35::M_1b_lst()const
{
    	std::vector<double> E;

	for(auto const & s:sect_outp_list_)
		E.push_back(s.M_1b());

	return E;

}
std::vector<double> ComBeamOutputSP35::M_2c_lst()const
{
	std::vector<double> E;

	for(auto const & s:sect_outp_list_)
		E.push_back(s.M_2c());

	return E;
}
std::vector<double> ComBeamOutputSP35::M_2d_lst()const
{
	std::vector<double> E;

	for(auto const & s:sect_outp_list_)
		E.push_back(s.M_2d());

	return E;
}
std::vector<double> ComBeamOutputSP35::M_total_lst()const
{
	std::vector<double> E;

	for(auto const & s:sect_outp_list_)
		E.push_back(s.M_total());

	return E;
}
std::vector<double> ComBeamOutputSP35::Q_1a_lst()const
{
	std::vector<double> E;

	for(auto const & s:sect_outp_list_)
		E.push_back(s.Q_1a());

	return E;
}
std::vector<double> ComBeamOutputSP35::Q_1b_lst()const
{
	std::vector<double> E;

	for(auto const & s:sect_outp_list_)
		E.push_back(s.Q_1b());

	return E;
}
std::vector<double> ComBeamOutputSP35::Q_2c_lst()const
{
	std::vector<double> E;

	for(auto const & s:sect_outp_list_)
		E.push_back(s.Q_2c());

	return E;
}
std::vector<double> ComBeamOutputSP35::Q_2d_lst()const
{
	std::vector<double> E;

	for(auto const & s:sect_outp_list_)
		E.push_back(s.Q_2d());

	return E;
}
std::vector<double> ComBeamOutputSP35::Q_total_lst()const
{
	std::vector<double> E;

	for(auto const & s:sect_outp_list_)
		E.push_back(s.Q_total());

	return E;
}

std::vector<double> ComBeamOutputSP35::R_1a_lst()const
{
	std::vector<double> E;

	for(auto const & s:sect_outp_list_)
		E.push_back(s.R_1a());

	return E;
}
std::vector<double> ComBeamOutputSP35::R_1b_lst()const
{
	std::vector<double> E;

	for(auto const & s:sect_outp_list_)
		E.push_back(s.R_1b());

	return E;
}
std::vector<double> ComBeamOutputSP35::R_2c_lst()const
{
	std::vector<double> E;

	for(auto const & s:sect_outp_list_)
		E.push_back(s.R_2c());

	return E;
}
std::vector<double> ComBeamOutputSP35::R_2d_lst()const
{
	std::vector<double> E;

	for(auto const & s:sect_outp_list_)
		E.push_back(s.R_2d());

	return E;
}
std::vector<double> ComBeamOutputSP35::R_total_lst()const
{
	std::vector<double> E;

	for(auto const & s:sect_outp_list_)
		E.push_back(s.R_total());

	return E;
}

SectOutputSP35 const & ComBeamOutputSP35::max_st_sect_ratio_sect()const
{
	return *std::max_element(sect_outp_list_.begin(), sect_outp_list_.end(),
		[](SectOutputSP35 const &  sect_output1, SectOutputSP35 const & sect_output2)
		{return sect_output1.st_sect_ratio() < sect_output2.st_sect_ratio();});
}
SectOutputSP35 const & ComBeamOutputSP35::max_direct_str_ratio_sect()const
{
	return *std::max_element(sect_outp_list_.begin(), sect_outp_list_.end(),
		[](SectOutputSP35 const &  sect_output1, SectOutputSP35 const & sect_output2)
		{return sect_output1.max_direct_str_ratio() < sect_output2.max_direct_str_ratio();});
}

SectOutputSP35 const & ComBeamOutputSP35::max_shear_str_ratio_sect()const
{
	return *std::max_element(sect_outp_list_.begin(), sect_outp_list_.end(),
		[](SectOutputSP35 const &  sect_output1, SectOutputSP35 const & sect_output2)
		{return sect_output1.shear_ratio() < sect_output2.shear_ratio();});
}

ComposSectGeomSP35 const & ComBeamOutputSP35::com_sect()const
{
	return com_sect_;
}
