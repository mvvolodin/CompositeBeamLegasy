//---------------------------------------------------------------------------

#pragma hdrstop

#include "ISection.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

ISection::ISection(){};
							// 0- h, 1-b, 2-s, 3-t, 4-A, 5-P, 6-Iy, 7-Wy, 8-Sy, 9-iy, 10-Iz, 11-Wz, 12-iz, 13-R
ISection::ISection(String  profile_number,
					ProfileGroup profile_group,
					double b_uf,
					double t_uf,
					double b_lf,
					double t_lf,
					double h_w,
					double t_w,
					double h_st,
					double r,
					double weight,
					double Z_f2_st,
					double Z_f1_st,
					double A_st,
					double I_st,
					double Wf2_st,
					double Wf1_st):
					profile_number_(profile_number),
					profile_group_(profile_group),
					b_uf_(b_uf),
					t_uf_(t_uf),
					b_lf_(b_lf),
					t_lf_(t_lf),
					h_w_(h_w),
					t_w_(t_w),
					h_st_(h_st),
					r_(r),
					weight_(weight),
					Z_f2_st_(Z_f2_st),
					Z_f1_st_(Z_f1_st),
					A_st_(A_st),
					I_st_(I_st),
					Wf2_st_(Wf2_st),
					Wf1_st_(Wf1_st){}

void ISection::save(std::ostream& ostr)const
{
	wchar_t* buf = profile_number_.w_str();
	unsigned short l = profile_number_.Length()+1;
	ostr.write((char*)&l,sizeof(l));
	ostr.write((char*)buf,l*sizeof(wchar_t));
    free(buf);

	ostr.write((char*)&profile_group_ ,sizeof(profile_group_));
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
	wchar_t* buf;
	unsigned short l;
	istr.read((char*)&l,sizeof(l));
	buf =(wchar_t*) malloc(l*sizeof(wchar_t));
	istr.read((char*)buf,l*sizeof(wchar_t));
	profile_number_ = String(buf);
	free(buf);

	istr.read((char*)&profile_group_ ,sizeof(profile_group_));
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
	 weight_ = 194.8;
	 Z_f2_st_= 355.;
	 Z_f1_st_ = 355.;
	 Wf2_st_ = 5624800;
	 Wf1_st_ = 5624800;
}




