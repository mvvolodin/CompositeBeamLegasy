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
void ISection::save(std::ostream& ostr)const
{
	unsigned short l = profile_number_.Length();
	ostr.write((char*)&l,sizeof(l));
	ostr.write((char*)profile_number_.c_str(),l*sizeof(wchar_t));

	ostr.write((char*)&b_uf_ ,sizeof(b_uf_));
	ostr.write((char*)&t_uf_ ,sizeof(t_uf_));
	ostr.write((char*)&b_lf_ ,sizeof(b_lf_));
	ostr.write((char*)&t_lf_ ,sizeof(t_lf_));
	ostr.write((char*)&h_w_ ,sizeof(h_w_));
	ostr.write((char*)&t_w_ ,sizeof(t_w_));
	ostr.write((char*)&A_st_ ,sizeof(A_st_));
	ostr.write((char*)&I_st_ ,sizeof(I_st_));
	ostr.write((char*)&h_st_ ,sizeof(h_st_));
	ostr.write((char*)&r_ ,sizeof(r_));
	ostr.write((char*)&weight_ ,sizeof(weight_));
	ostr.write((char*)&Z_f2_st_ ,sizeof(Z_f2_st_));
	ostr.write((char*)&Z_f1_st_ ,sizeof(Z_f1_st_));
	ostr.write((char*)&Wf2_st_ ,sizeof(Wf2_st_));
	ostr.write((char*)&Wf1_st_ ,sizeof(Wf1_st_));
	}
void ISection::load(std::istream& istr)
{
	unsigned short l = profile_number_.Length();
	istr.read((char*)&l,sizeof(l));
	istr.read((char*)profile_number_.c_str(),l*sizeof(wchar_t));

	istr.read((char*)&b_uf_ ,sizeof(b_uf_));
	istr.read((char*)&t_uf_ ,sizeof(t_uf_));
	istr.read((char*)&b_lf_ ,sizeof(b_lf_));
	istr.read((char*)&t_lf_ ,sizeof(t_lf_));
	istr.read((char*)&h_w_ ,sizeof(h_w_));
	istr.read((char*)&t_w_ ,sizeof(t_w_));
	istr.read((char*)&A_st_ ,sizeof(A_st_));
	istr.read((char*)&I_st_ ,sizeof(I_st_));
	istr.read((char*)&h_st_ ,sizeof(h_st_));
	istr.read((char*)&r_ ,sizeof(r_));
	istr.read((char*)&weight_ ,sizeof(weight_));
	istr.read((char*)&Z_f2_st_ ,sizeof(Z_f2_st_));
	istr.read((char*)&Z_f1_st_ ,sizeof(Z_f1_st_));
	istr.read((char*)&Wf2_st_ ,sizeof(Wf2_st_));
	istr.read((char*)&Wf1_st_ ,sizeof(Wf1_st_));
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




