//---------------------------------------------------------------------------

#pragma hdrstop

#include "uComposSectOutputSP35.h"
#include <algorithm>

//---------------------------------------------------------------------------
#pragma package(smart_init)

	ComposSectOutputSP35::ComposSectOutputSP35(Node const & nd,

								   double const M_1a,
								   double const M_1b,
								   double const M_2c,
								   double const M_2d,
								   double const M_total,

								   double const Q_1a,
								   double const Q_1b,
								   double const Q_2c,
								   double const Q_2d,
								   double const Q_total,

								   double const R_1a,
								   double const R_1b,
								   double const R_2c,
								   double const R_2d,
								   double const R_total,

								   double const f_1a,
								   double const f_1b,
								   double const f_2c,
								   double const f_2d,

								   double const sigma_b_shr,
								   double const sigma_b_kr,
								   double const sigma_r_shr,
								   double const sigma_r_kr,

								   double const sigma_bi,
								   double const sigma_ri,

								   double const sigma_b,
								   double const sigma_r,

								   PlastCoeffList const & pl_coeff,

								   DesignCase des_case,

								   double const upper_fl_ratio,
								   double const lower_fl_ratio,
								   double const conc_ratio,
								   double const shear_ratio,
								   double const st_sect_ratio):
							nd_(nd),

							M_1a_(M_1a),
							M_1b_(M_1b),
							M_2c_(M_2c),
							M_2d_(M_2d),
							M_total_(M_total),

							Q_1a_(Q_1a),
							Q_1b_(Q_1b),
							Q_2c_(Q_2c),
							Q_2d_(Q_2d),
							Q_total_(Q_total),

							R_1a_(R_1a),
							R_1b_(R_1b),
							R_2c_(R_2c),
							R_2d_(R_2d),
                            R_total_(R_total),

							f_1a_(f_1a),
							f_1b_(f_1b),
							f_2c_(f_2c),
							f_2d_(f_2d),

							sigma_b_shr_(sigma_b_shr),
							sigma_b_kr_(sigma_b_kr),
							sigma_r_shr_(sigma_r_shr),
							sigma_r_kr_(sigma_r_kr),

							sigma_bi_(sigma_bi),
							sigma_ri_(sigma_ri),

							sigma_b_(sigma_b),
							sigma_r_(sigma_r),

							pl_coeff_(pl_coeff),

							des_case_(des_case),

							upper_fl_ratio_(upper_fl_ratio),
							lower_fl_ratio_(lower_fl_ratio),
							conc_ratio_(conc_ratio),
							shear_ratio_(shear_ratio),
							st_sect_ratio_(st_sect_ratio){}
Node ComposSectOutputSP35::node()const
{
	return nd_;
}
double ComposSectOutputSP35::M_1a()const
{
	return M_1a_;
}
double ComposSectOutputSP35::M_1b()const
{
	return M_1b_;
}
double ComposSectOutputSP35::M_2c()const
{
	return M_2c_;
}
double ComposSectOutputSP35::M_2d()const
{
	return M_2d_;
}
double ComposSectOutputSP35::M_total()const
{
	return M_total_;
}
double ComposSectOutputSP35::Q_1a()const
{
	return Q_1a_;
}
double ComposSectOutputSP35::Q_1b()const
{
	return Q_1b_;
}
double ComposSectOutputSP35::Q_2c()const
{
	return Q_2c_;
}
double ComposSectOutputSP35::Q_2d()const
{
	return Q_2d_;
}
double ComposSectOutputSP35::Q_total()const
{
	return Q_total_;
}
double ComposSectOutputSP35::R_1a()const
{
	return R_1a_;
}
double ComposSectOutputSP35::R_1b()const
{
	return R_1b_;
}
double ComposSectOutputSP35::R_2c()const
{
	return R_2c_;
}
double ComposSectOutputSP35::R_2d()const
{
	return R_2d_;
}
double ComposSectOutputSP35::R_total()const
{
	return R_total_;
}
double ComposSectOutputSP35::max_direct_str_ratio()const
{
	return std::max({std::abs(upper_fl_ratio_),
					std::abs(lower_fl_ratio_),
					std::abs(conc_ratio_)});
}
void ComposSectOutputSP35::fill_grid_with_max_direct_str_data(TStringGrid* str_grid)const
{
	str_grid -> Cells [1][5] = FloatToStrF(nd_.x(), ffFixed, 15, 0);
	str_grid -> Cells [1][6] = FloatToStrF(upper_fl_ratio_, ffFixed, 15, 2);
	str_grid -> Cells [1][7] = FloatToStrF(lower_fl_ratio_, ffFixed, 15, 2);
	str_grid -> Cells [1][8] = FloatToStrF(conc_ratio_, ffFixed, 15, 2);
//       std::abs(

}
void ComposSectOutputSP35::print(TWord_Automation & report)const
{
	pl_coeff_.print(report);
//	print_max_direct_str_ratio_sect(report);

// Печать моментов
	report.PasteTextPattern(length_to_str(nd_.x()),"%cs_x%");
	report.PasteTextPattern(moment_to_str(M_1a_),"%M_1a%");
	report.PasteTextPattern(moment_to_str(M_1b_),"%M_1b%");
	report.PasteTextPattern(moment_to_str(M_2c_),"%M_2c%");
	report.PasteTextPattern(moment_to_str(M_2d_),"%M_2d%");
	report.PasteTextPattern(moment_to_str(M_total_),"%M_total%");

 // Печать напряжений

	report.PasteTextPattern(FloatToStrF(sigma_b_kr_, ffFixed, 15, 2),"%sigma_b_kr%");
	report.PasteTextPattern(FloatToStrF(sigma_r_kr_, ffFixed, 15, 2),"%sigma_r_kr%");
	report.PasteTextPattern(FloatToStrF(sigma_b_shr_, ffFixed, 15, 2),"%sigma_b_shr%");
	report.PasteTextPattern(FloatToStrF(sigma_r_shr_, ffFixed, 15, 2),"%sigma_r_shr%");

	report.PasteTextPattern(FloatToStrF(sigma_b_, ffFixed, 15, 2),"%sigma_b%");
	report.PasteTextPattern(FloatToStrF(sigma_r_, ffFixed, 15, 2),"%sigma_r%");

//Печать Коэффициентов Использования
	report.PasteTextPattern(FloatToStrF(nd_.x(), ffFixed, 15, 2),"%x_M%");
	report.PasteTextPattern(FloatToStrF(upper_fl_ratio_, ffFixed, 15, 2),"%uf_ratio%");
	report.PasteTextPattern(FloatToStrF(lower_fl_ratio_, ffFixed, 15, 2),"%lf_ratio%");
	report.PasteTextPattern(FloatToStrF(conc_ratio_, ffFixed, 15, 2),"%conc_ratio%");


	//report.PasteTextPattern(FloatToStrF(x_, ffFixed, 15, 2),"%cs_x%");  //координата
	 //  PasteTextPattern(FloatToStrF(max_direct_stress_ratio_section.get_x(), ffFixed, 15, 0),"%cs_x%");
}
void ComposSectOutputSP35::print_max_direct_str_ratio_sect(TWord_Automation & report)const
{
	report.PasteTextPattern(FloatToStrF(nd_.x(), ffFixed, 15, 2),"%x_M%");
	report.PasteTextPattern(FloatToStrF(upper_fl_ratio_, ffFixed, 15, 2),"%uf_ratio%");
	report.PasteTextPattern(FloatToStrF(lower_fl_ratio_, ffFixed, 15, 2),"%lf_ratio%");
	report.PasteTextPattern(FloatToStrF(conc_ratio_, ffFixed, 15, 2),"%conc_ratio%");
}
#ifndef NDEBUG
void ComposSectOutputSP35::print_data_to_logger(TFormLogger const & log)const
{
	log.add_heading(L"Результат проверки сечения");

	log.print_double(L"id = ", nd_.id(), L" ");
	log.print_double(L"x = ", nd_.x(), L" мм");

	log.add_chapter(L"Внутренние усилия");

	log.print_double(L"M_1a = ", M_1a_, L" H*мм");
	log.print_double(L"M_1b = ", M_1b_, L" H*мм");
	log.print_double(L"M_2c = ", M_2c_, L" H*мм");
	log.print_double(L"M_2d = ", M_2d_, L" H*мм");

	log.print_double(L"Q_1a = ", Q_1a_, L" H");
	log.print_double(L"Q_1b = ", Q_1b_, L" H");
	log.print_double(L"Q_2c = ", Q_2c_, L" H");
	log.print_double(L"Q_2d = ", Q_2d_, L" H");

	log.add_chapter(L"Перемещения");

	log.print_double(L"f_1a = ", f_1a_, L" мм");
	log.print_double(L"f_1b = ", f_1b_, L" мм");
	log.print_double(L"f_2c = ", f_2c_, L" мм");
	log.print_double(L"f_2d = ", f_2d_, L" мм");

	log.add_chapter(L"Напряжения от усадки и ползучести");

	log.print_double(L"sigma_bi_sh = ", sigma_b_shr_, L" Н/мм2");
	log.print_double(L"sigma_bi_kr = ", sigma_b_kr_, L" Н/мм2");
	log.print_double(L"sigma_ri_sh = ", sigma_r_shr_, L" Н/мм2");
	log.print_double(L"sigma_ri_kr = ", sigma_r_kr_, L" Н/мм2");

	log.print_double(L"sigma_bi = ", sigma_bi_, L" Н/мм2");
	log.print_double(L"sigma_ri = ", sigma_ri_, L" Н/мм2");

	log.add_chapter(L"Напряжения в бетоне и арматуре");

	log.print_double(L"sigma_b = ", sigma_b_, L" Н/мм2");
	log.print_double(L"sigma_r = ", sigma_r_, L" Н/мм2");

	log.add_chapter(L"Расчётный случай");

//	if(des_case_ == DesignCase::Case_A) log.print_string(L"А");
//	if(des_case_ == DesignCase::Case_B) log.print_string(L"Б");
//	if(des_case_ == DesignCase::Case_C) log.print_string(L"В");

	log.add_chapter(L"Коэффициенты использования");

	log.print_double(L"upper_fl_ratio = ", upper_fl_ratio_, L" ");
	log.print_double(L"lower_fl_ratio = ", lower_fl_ratio_, L" ");
	log.print_double(L"conc_ratio = ", conc_ratio_, L" ");
	log.print_double(L"shear_ratio = ", shear_ratio_, L" ");
	log.print_double(L"i_section_ratio = ", st_sect_ratio_, L" ");

}
#endif

