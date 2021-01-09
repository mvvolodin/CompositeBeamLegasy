////---------------------------------------------------------------------------
//#pragma hdrstop
//#include <algorithm>
//#include "uComBeamOutputSP35.h"
////---------------------------------------------------------------------------
//#pragma package(smart_init)
////---------------------------------------------------------------------------
//
//ComBeamOutputSP35::ComBeamOutputSP35(ComposSectGeomSP35  com_sect,
//									 ComposSectGeomSP35  com_sect_shr,
//									 ComposSectGeomSP35  com_sect_kr,
//									 std::vector<ComposSectOutputSP35>  sect_outp_list):
//		com_sect_(com_sect),
//		com_sect_shr_(com_sect_shr),
//		com_sect_kr_(com_sect_kr),
//		sect_outp_list_(sect_outp_list){}
//
//void ComBeamOutputSP35::print(TWord_Automation & report)const
//{
//
//	com_sect_.print(report);
//
//	ComposSectOutputSP35 sect1 = max_direct_str_ratio_sect();
//
//    //Печать коэффициентоа пластичности
//	sect1.pl_coeff().print(report);
//
//	// Печать моментов
//	report.PasteTextPattern(length_to_str(sect1.node().x()),"%cs_x%");
//	report.PasteTextPattern(moment_to_str(sect1.M_1a()),"%M_1a%");
//	report.PasteTextPattern(moment_to_str(sect1.M_1b()),"%M_1b%");
//	report.PasteTextPattern(moment_to_str(sect1.M_2c()),"%M_2c%");
//	report.PasteTextPattern(moment_to_str(sect1.M_2d()),"%M_2d%");
//	report.PasteTextPattern(moment_to_str(sect1.M_total()),"%M_total%");
//
// // Печать напряжений
//
//	report.PasteTextPattern(FloatToStrF(sect1.sigma_b_kr(), ffFixed, 15, 2),"%sigma_b_kr%");
//	report.PasteTextPattern(FloatToStrF(sect1.sigma_r_kr(), ffFixed, 15, 2),"%sigma_r_kr%");
//	report.PasteTextPattern(FloatToStrF(sect1.sigma_b_shr(), ffFixed, 15, 2),"%sigma_b_shr%");
//	report.PasteTextPattern(FloatToStrF(sect1.sigma_r_shr(), ffFixed, 15, 2),"%sigma_r_shr%");
//
//	report.PasteTextPattern(FloatToStrF(sect1.sigma_b(), ffFixed, 15, 2),"%sigma_b%");
//	report.PasteTextPattern(FloatToStrF(sect1.sigma_r(), ffFixed, 15, 2),"%sigma_r%");
//
////Печать Коэффициентов Использования
//
//	report.PasteTextPattern(FloatToStrF(sect1.node().x(), ffFixed, 15, 2),"%x_M%");
//	report.PasteTextPattern(FloatToStrF(sect1.upper_fl_ratio(), ffFixed, 15, 2),"%uf_ratio%");
//	report.PasteTextPattern(FloatToStrF(sect1.lower_fl_ratio(), ffFixed, 15, 2),"%lf_ratio%");
//	report.PasteTextPattern(FloatToStrF(sect1.conc_ratio(), ffFixed, 15, 2),"%conc_ratio%");
//
//	ComposSectOutputSP35 sect2 = max_direct_str_ratio_sect();
//
//	report.PasteTextPattern(FloatToStrF(sect2.node().x(), ffFixed, 15, 2),"%x_M_I%");
//	report.PasteTextPattern(FloatToStrF(sect2.st_sect_ratio(), ffFixed, 15, 2),"%i_section_ratio%");
//
//	ComposSectOutputSP35 sect3 = max_shear_str_ratio_sect();
//
//	report.PasteTextPattern(FloatToStrF(sect3.node().x(), ffFixed, 15, 2),"%x_Q%");
//	report.PasteTextPattern(FloatToStrF(sect3.shear_ratio(), ffFixed, 15, 2),"%ratio_shear%");
//}
//std::vector<double> ComBeamOutputSP35::x_lst()const
//{
//	std::vector<double> x;
//
//	for(auto const & s:sect_outp_list_)
//		x.push_back(s.node().x());
//
//	return x;
//}
//std::vector<double> ComBeamOutputSP35::end_sup_coord()const
//{
//	std::vector<double> coord;
//	for(auto const & s:sect_outp_list_)
//		if(s.node().is_end_support())
//			coord.push_back(s.node().x());
//
//   return coord;
//}
//std::vector<double> ComBeamOutputSP35::inter_sup_coord()const
//{
//	std::vector<double> coord;
//
//	for(auto const & s:sect_outp_list_)
//		if(s.node().is_inter_support())
//			coord.push_back(s.node().x());
//
//   return coord;
//}
//std::vector<double> ComBeamOutputSP35::sup_coord()const
//{
//	std::vector<double> coord;
//
//	for(auto const & s:sect_outp_list_)
//		if(s.node().is_end_support() || s.node().is_inter_support())
//			coord.push_back(s.node().x());
//
//   return coord;
//}
//std::vector<double> ComBeamOutputSP35::M_1a_lst()const
//{
//	std::vector<double> E;
//
//	for(auto const & s:sect_outp_list_)
//		E.push_back(s.M_1a());
//
//	return E;
//}
//std::vector<double> ComBeamOutputSP35::M_1b_lst()const
//{
//    	std::vector<double> E;
//
//	for(auto const & s:sect_outp_list_)
//		E.push_back(s.M_1b());
//
//	return E;
//
//}
//std::vector<double> ComBeamOutputSP35::M_2c_lst()const
//{
//	std::vector<double> E;
//
//	for(auto const & s:sect_outp_list_)
//		E.push_back(s.M_2c());
//
//	return E;
//}
//std::vector<double> ComBeamOutputSP35::M_2d_lst()const
//{
//	std::vector<double> E;
//
//	for(auto const & s:sect_outp_list_)
//		E.push_back(s.M_2d());
//
//	return E;
//}
//std::vector<double> ComBeamOutputSP35::M_total_lst()const
//{
//	std::vector<double> E;
//
//	for(auto const & s:sect_outp_list_)
//		E.push_back(s.M_total());
//
//	return E;
//}
//std::vector<double> ComBeamOutputSP35::Q_1a_lst()const
//{
//	std::vector<double> E;
//
//	for(auto const & s:sect_outp_list_)
//		E.push_back(s.Q_1a());
//
//	return E;
//}
//std::vector<double> ComBeamOutputSP35::Q_1b_lst()const
//{
//	std::vector<double> E;
//
//	for(auto const & s:sect_outp_list_)
//		E.push_back(s.Q_1b());
//
//	return E;
//}
//std::vector<double> ComBeamOutputSP35::Q_2c_lst()const
//{
//	std::vector<double> E;
//
//	for(auto const & s:sect_outp_list_)
//		E.push_back(s.Q_2c());
//
//	return E;
//}
//std::vector<double> ComBeamOutputSP35::Q_2d_lst()const
//{
//	std::vector<double> E;
//
//	for(auto const & s:sect_outp_list_)
//		E.push_back(s.Q_2d());
//
//	return E;
//}
//std::vector<double> ComBeamOutputSP35::Q_total_lst()const
//{
//	std::vector<double> E;
//
//	for(auto const & s:sect_outp_list_)
//		E.push_back(s.Q_total());
//
//	return E;
//}
//
//std::vector<double> ComBeamOutputSP35::R_1a_lst()const
//{
//	std::vector<double> E;
//
//	for(auto const & s:sect_outp_list_)
//		E.push_back(s.R_1a());
//
//	return E;
//}
//std::vector<double> ComBeamOutputSP35::R_1b_lst()const
//{
//	std::vector<double> E;
//
//	for(auto const & s:sect_outp_list_)
//		E.push_back(s.R_1b());
//
//	return E;
//}
//std::vector<double> ComBeamOutputSP35::R_2c_lst()const
//{
//	std::vector<double> E;
//
//	for(auto const & s:sect_outp_list_)
//		E.push_back(s.R_2c());
//
//	return E;
//}
//std::vector<double> ComBeamOutputSP35::R_2d_lst()const
//{
//	std::vector<double> E;
//
//	for(auto const & s:sect_outp_list_)
//		E.push_back(s.R_2d());
//
//	return E;
//}
//std::vector<double> ComBeamOutputSP35::R_total_lst()const
//{
//	std::vector<double> E;
//
//	for(auto const & s:sect_outp_list_)
//		E.push_back(s.R_total());
//
//	return E;
//}
//
//std::vector<double> ComBeamOutputSP35::f_1a_lst()const
//{
//	std::vector<double> E;
//
//	for(auto const & s:sect_outp_list_)
//		E.push_back(s.f_1a());
//
//	return E;
//}
//std::vector<double> ComBeamOutputSP35::f_1b_lst()const
//{
//	std::vector<double> E;
//
//	for(auto const & s:sect_outp_list_)
//		E.push_back(s.f_1b());
//
//	return E;
//}
//std::vector<double> ComBeamOutputSP35::f_2c_lst()const
//{
//	std::vector<double> E;
//
//	for(auto const & s:sect_outp_list_)
//		E.push_back(s.f_2c());
//
//	return E;
//}
//std::vector<double> ComBeamOutputSP35::f_2d_lst()const
//{
//	std::vector<double> E;
//
//	for(auto const & s:sect_outp_list_)
//		E.push_back(s.f_2d());
//
//	return E;
//}
//std::vector<double> ComBeamOutputSP35::f_total_lst()const
//{
//	std::vector<double> E;
//
//	for(auto const & s:sect_outp_list_)
//		E.push_back(s.f_total());
//
//	return E;
//}
//
//ComposSectOutputSP35 const & ComBeamOutputSP35::max_st_sect_ratio_sect()const
//{
//	return *std::max_element(sect_outp_list_.begin(), sect_outp_list_.end(),
//		[](ComposSectOutputSP35 const &  sect_output1, ComposSectOutputSP35 const & sect_output2)
//		{return sect_output1.st_sect_ratio() < sect_output2.st_sect_ratio();});
//}
//ComposSectOutputSP35 const & ComBeamOutputSP35::max_direct_str_ratio_sect()const
//{
//	return *std::max_element(sect_outp_list_.begin(), sect_outp_list_.end(),
//		[](ComposSectOutputSP35 const &  sect_output1, ComposSectOutputSP35 const & sect_output2)
//		{return sect_output1.max_direct_str_ratio() < sect_output2.max_direct_str_ratio();});
//}
//
//ComposSectOutputSP35 const & ComBeamOutputSP35::max_shear_str_ratio_sect()const
//{
//	return *std::max_element(sect_outp_list_.begin(), sect_outp_list_.end(),
//		[](ComposSectOutputSP35 const &  sect_output1, ComposSectOutputSP35 const & sect_output2)
//		{return sect_output1.shear_ratio() < sect_output2.shear_ratio();});
//}
//
//ComposSectGeomSP35 const & ComBeamOutputSP35::com_sect()const
//{
//	return com_sect_;
//}
//
//void ComBeamOutputSP35::fill_grid(TStringGrid* str_grid)const
//{
//	ComposSectOutputSP35 sect1 = max_direct_str_ratio_sect();
//
//	str_grid -> Cells [1][2] = FloatToStrF(sect1.node().x(), ffFixed, 15, 0);
//	str_grid -> Cells [1][3] = FloatToStrF(sect1.st_sect_ratio(), ffFixed, 15, 2);
//
//	ComposSectOutputSP35 sect2 = max_direct_str_ratio_sect();
//
//	str_grid -> Cells [1][5] = FloatToStrF(sect2.node().x(), ffFixed, 15, 0);
//	str_grid -> Cells [1][6] = FloatToStrF(sect2.upper_fl_ratio(), ffFixed, 15, 2);
//	str_grid -> Cells [1][7] = FloatToStrF(sect2.lower_fl_ratio(), ffFixed, 15, 2);
//	str_grid -> Cells [1][8] = FloatToStrF(sect2.conc_ratio(), ffFixed, 15, 2);
//
//	ComposSectOutputSP35 sect3 = max_shear_str_ratio_sect();
//
//	str_grid -> Cells [1][10] = FloatToStrF(sect3.node().x(), ffFixed, 15, 0);
//	str_grid -> Cells [1][11] = FloatToStrF(sect3.shear_ratio(), ffFixed, 15, 2);
//}
