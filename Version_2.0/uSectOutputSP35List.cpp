//---------------------------------------------------------------------------

#pragma hdrstop

#include "uSectOutputSP35List.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
void SectOutputSP35List::print_data_to_report(TWord_Automation & report)const
{
	sect_outp_list_[3].print_data_to_report(report);
}

SectOutputSP35 const & SectOutputSP35List::get_max_i_section_ratio_section()const
{

}
SectOutputSP35 const & SectOutputSP35List::get_max_direct_stress_ratio_section()const
{

}
SectOutputSP35 const & SectOutputSP35List::get_max_shear_stress_ratio_section()const
{

}
SectOutputSP35 const & SectOutputSP35List::get_max_rigid_plastic_ratio_section()const
{

}
