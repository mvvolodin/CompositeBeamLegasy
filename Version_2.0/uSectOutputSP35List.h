//---------------------------------------------------------------------------

#ifndef uSectOutputSP35ListH
#define uSectOutputSP35ListH
//---------------------------------------------------------------------------
#include "uSectOutputSP35.h"
#include "uWord_Automation.h"
//---------------------------------------------------------------------------
class SectOutputSP35List{
public:

	SectOutputSP35List()=default;

	void push_back(SectOutputSP35 const & sect_outp)
	{
		sect_outp_list_.push_back(sect_outp);
	}

	auto begin()const
	{
		return sect_outp_list_.cbegin();
	}
	auto end()const
	{
		return sect_outp_list_.cend();
	}

	void print_data_to_report(TWord_Automation & report)const;

private:
	std::vector<SectOutputSP35> sect_outp_list_;

	SectOutputSP35 const & get_max_i_section_ratio_section()const;
	SectOutputSP35 const & get_max_direct_stress_ratio_section()const;
	SectOutputSP35 const & get_max_shear_stress_ratio_section()const;
	SectOutputSP35 const & get_max_rigid_plastic_ratio_section()const;

};
//---------------------------------------------------------------------------
#endif
