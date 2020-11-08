//---------------------------------------------------------------------------
#pragma hdrstop
#include <algorithm>
#include "uComBeamOutputSP35.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
ComBeamOutputSP35::ComBeamOutputSP35(ComposSectGeomSP35 const com_sect,
									 ComposSectGeomSP35 const com_sect_shr,
									 ComposSectGeomSP35 const com_sect_kr,
									 std::vector<SectOutputSP35> const sect_outp_list):
		com_sect_(com_sect),
		com_sect_shr_(com_sect_shr),
		com_sect_kr_(com_sect_kr),
		sect_outp_list_(sect_outp_list){}

void ComBeamOutputSP35::print_data_to_report(TWord_Automation & report)const
{

	com_sect_.print_data_to_report(report);
	max_direct_str_ratio_sect().print_max_direct_str_ratio_sect(report);

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
