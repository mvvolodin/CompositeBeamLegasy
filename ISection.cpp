//---------------------------------------------------------------------------

#pragma hdrstop

#include "ISection.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

	ISection::ISection(){};

	ISection::ISection(TISectionInitialData i_section_initial_data)
		:h_st_(0.0),Z_f1_st_(0.0),Z_f2_st_(0.0)
	{
	 b_uf_= i_section_initial_data.b_uf_;
	 t_uf_= i_section_initial_data.t_uf_;
	 b_lf_= i_section_initial_data.b_lf_;
	 t_lf_= i_section_initial_data.t_lf_;
	 h_w_= i_section_initial_data.h_w_;
	 t_w_= i_section_initial_data.t_w_;
	 A_st_=i_section_initial_data.Ar;
	 I_st_=i_section_initial_data.Iyy;
	 h_st_=i_section_initial_data.Hsect;
	 Z_f2_st_=i_section_initial_data.Zct;
     Z_f1_st_=h_st_- Z_f2_st_;

	}




