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
	Get_param_sect(i_section_initial_data, &excessive_sect_geomet_data);
	Ar=excessive_sect_geomet_data.Ar;
	Izz=excessive_sect_geomet_data.Izz;
	Iyy=excessive_sect_geomet_data.Iyy;
	Hsect=excessive_sect_geomet_data.Hsect;
	Zct=excessive_sect_geomet_data.Zct;
};

