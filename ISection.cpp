//---------------------------------------------------------------------------

#pragma hdrstop

#include "ISection.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

	ISection::ISection(){};

	ISection::ISection(TISectionInitialData i_section_initial_data)
	{
	 profile_number_=i_section_initial_data.profile_number_;
	 b_uf_= i_section_initial_data.b_uf_;
	 t_uf_= i_section_initial_data.t_uf_;
	 b_lf_= i_section_initial_data.b_lf_;
	 t_lf_= i_section_initial_data.t_lf_;
	 h_w_= i_section_initial_data.h_w_;
	 t_w_= i_section_initial_data.t_w_;
	 A_st_=i_section_initial_data.Ast;
	 I_st_=i_section_initial_data.Ist;
	 h_st_=i_section_initial_data.Hsect;
	 r_= i_section_initial_data.r_;
	 weight_=i_section_initial_data.weight_;
	 Z_f2_st_=i_section_initial_data.Z_f2_st;
	 Z_f1_st_=i_section_initial_data.Z_f1_st;
	 Wf2_st_=i_section_initial_data.Wf2_st;
	 Wf1_st_=i_section_initial_data.Wf2_st;
	}
	void ISection::set_default_values()
	{
	 profile_number_ = L"70Á4";
	 b_uf_= 262.;
	 t_uf_= 25.;
	 b_lf_= 262.;
	 t_lf_= 25.;
	 h_w_= 660.;
	 t_w_= 17.;
	 A_st_ = 24814.;
	 I_st_ = 1996800000.;
	 h_st_ = 710.;
	 r_= 24.;
	 weight_ = 248.14;
	 Z_f2_st_= 355.;
	 Z_f1_st_ = 355.;
	 Wf2_st_ = 5624800;
	 Wf1_st_ = 5624800;
	}




