//---------------------------------------------------------------------------

#pragma hdrstop

#include "ISection.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

	ISection::ISection()
		:profile_number_(""),
		b_uf_(.0),
		t_uf_(.0),
		b_lf_(.0),
		t_lf_(.0),
		h_w_(.0),
		t_w_(.0),
		h_st_(.0),
		Z_f2_st_(.0),
		Z_f1_st_(.0),
		A_st_(.0),
		I_st_(.0),
		Wf2_st_(.0),
		Wf1_st_(.0){};

	ISection::ISection(TISectionInitialData i_section_initial_data)
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
	 Wf2_st_=i_section_initial_data.Wu_max; //!!! в struct GEOM_PARAM_SECT содержатся Wu_max и Wu_min
	 Wf1_st_=i_section_initial_data.Wu_min; //!!! нет гарантии, что Wu_max это Wf2_st, а Wu_min это Wf1_st_



	}




