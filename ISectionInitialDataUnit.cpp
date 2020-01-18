//---------------------------------------------------------------------------

#pragma hdrstop

#include "ISectionInitialDataUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

TISectionInitialData::TISectionInitialData (SECT_DVUTAVR* i_section_initial_data)
{
//Заполняем "базовые данные"
	b_uf_=i_section_initial_data->b1;
	t_uf_=i_section_initial_data->h1;
	b_lf_=i_section_initial_data->b2;
	t_lf_=i_section_initial_data->h2;
	h_w_=i_section_initial_data->h;
	t_w_=i_section_initial_data->b;
	t_lf_=i_section_initial_data->h2;
	weight_=i_section_initial_data->weight;
	r_=i_section_initial_data->r;
	profile_number_=i_section_initial_data->profile_number_;

//Заполняем "развёрнутые данные"

	GEOM_PARAM_SECT excessive_sect_geomet_data;
	Get_param_sect(i_section_initial_data, &excessive_sect_geomet_data);

	Ar=excessive_sect_geomet_data.Ar;
	Izz=excessive_sect_geomet_data.Izz;
	Iyy=excessive_sect_geomet_data.Iyy;
	Hsect=excessive_sect_geomet_data.Hsect;
	Zct=excessive_sect_geomet_data.Zct;
};

