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
									 std::vector<ComposSectOutputSP35>  sect_outp_list):
		com_sect_(com_sect),
		com_sect_shr_(com_sect_shr),
		com_sect_kr_(com_sect_kr),
		sect_outp_list_(sect_outp_list){}

void ComBeamOutputSP35::print(TWord_Automation & report)const
{

	com_sect_.print(report);
	max_direct_str_ratio_sect().print(report);

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

ComposSectOutputSP35 const & ComBeamOutputSP35::max_st_sect_ratio_sect()const
{
	return *std::max_element(sect_outp_list_.begin(), sect_outp_list_.end(),
		[](ComposSectOutputSP35 const &  sect_output1, ComposSectOutputSP35 const & sect_output2)
		{return sect_output1.st_sect_ratio() < sect_output2.st_sect_ratio();});
}
ComposSectOutputSP35 const & ComBeamOutputSP35::max_direct_str_ratio_sect()const
{
	return *std::max_element(sect_outp_list_.begin(), sect_outp_list_.end(),
		[](ComposSectOutputSP35 const &  sect_output1, ComposSectOutputSP35 const & sect_output2)
		{return sect_output1.max_direct_str_ratio() < sect_output2.max_direct_str_ratio();});
}

ComposSectOutputSP35 const & ComBeamOutputSP35::max_shear_str_ratio_sect()const
{
	return *std::max_element(sect_outp_list_.begin(), sect_outp_list_.end(),
		[](ComposSectOutputSP35 const &  sect_output1, ComposSectOutputSP35 const & sect_output2)
		{return sect_output1.shear_ratio() < sect_output2.shear_ratio();});
}

ComposSectGeomSP35 const & ComBeamOutputSP35::com_sect()const
{
	return com_sect_;
}

void ComBeamOutputSP35::fill_grid(TStringGrid* str_grid)const
{

	max_direct_str_ratio_sect().fill_grid_with_max_direct_str_data(str_grid);
//
//	strng_grd_results -> Cells [1][2] = FloatToStrF(std::abs(max_i_section_ratio_section.get_x()), ffFixed, 15, 0);
//	strng_grd_results -> Cells [1][3] = FloatToStrF(std::abs(max_i_section_ratio_section.get_i_section_ratio()), ffFixed, 15, 2);
//	Section max_direct_stress_ratio_section = composite_beam_calculator_.get_composite_beam().get_max_direct_stress_ratio_section();
//
//	strng_grd_results -> Cells [1][5] = FloatToStrF(std::abs(max_direct_stress_ratio_section.get_x()), ffFixed, 15, 0);
//	strng_grd_results -> Cells [1][6] = FloatToStrF(std::abs(max_direct_stress_ratio_section.get_upper_fl_ratio()), ffFixed, 15, 2);
//	strng_grd_results -> Cells [1][7] = FloatToStrF(std::abs(max_direct_stress_ratio_section.get_lower_fl_ratio()), ffFixed, 15, 2);
//	strng_grd_results -> Cells [1][8] = FloatToStrF(std::abs(max_direct_stress_ratio_section.get_conc_ratio()), ffFixed, 15, 2);
//
//	Section max_rigid_plastic_ratio_section = composite_beam_calculator_.get_composite_beam().get_max_rigid_plastic_ratio_section();
//
//	strng_grd_results -> Cells [1][10] = FloatToStrF(std::abs(max_rigid_plastic_ratio_section.get_x()), ffFixed, 15, 0);
//	strng_grd_results -> Cells [1][11] = FloatToStrF(std::abs(max_rigid_plastic_ratio_section.get_rigid_plastic_ratio()), ffFixed, 15, 2);
//
//	Section max_shear_stress_section = composite_beam_calculator_.get_composite_beam().get_max_shear_stress_ratio_section();
//
//	strng_grd_results -> Cells [1][13] = FloatToStrF(std::abs(max_shear_stress_section .get_x()), ffFixed, 15, 0);
//	strng_grd_results -> Cells [1][14] = FloatToStrF(std::abs(max_shear_stress_section.get_shear_ratio()), ffFixed, 15, 2);
//
//	StudsRow max_ratio_studs_row = composite_beam_calculator_.get_studs_on_beam().get_max_ratio_studs_row();
//
//	strng_grd_results -> Cells [1][16] = FloatToStrF(std::abs(max_ratio_studs_row.get_x()), ffFixed, 15, 0);
//	strng_grd_results -> Cells [1][17] = FloatToStrF(std::abs(max_ratio_studs_row.get_ratio())

}
