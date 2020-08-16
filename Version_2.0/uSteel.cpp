//---------------------------------------------------------------------------

#pragma hdrstop

#include "uSteel.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
Steel::Steel(){}
Steel::	Steel(String steel_grade, String standard, double E_st, double G_st, double nu_st,
			  double gamma_m,double R_yn,double R_un, double density, double t_max):
			  steel_grade_(steel_grade),
			  standard_(standard),
				R_yn_(R_yn),
				R_un_(R_un),
				E_st_(E_st),
				G_st_(G_st),
				nu_st_(nu_st),
				gamma_m_(gamma_m),
				density_(density),
				t_max_(t_max){}
void Steel::save(std::ostream& ostr)const
{
	wchar_t* buf1 = standard_.w_str();
	unsigned short l1 = standard_.Length()+1;
	ostr.write((char*)&l1,sizeof(l1));
	ostr.write((char*)buf1,l1*sizeof(wchar_t));

	wchar_t* buf2 = steel_grade_.w_str();
	unsigned short l2 = steel_grade_.Length()+1;
	ostr.write((char*)&l2,sizeof(l2));
	ostr.write((char*)buf2,l2*sizeof(wchar_t));

	ostr.write((char*)&E_st_ ,sizeof(E_st_));
	ostr.write((char*)&G_st_ ,sizeof(G_st_));
	ostr.write((char*)&nu_st_ ,sizeof(nu_st_));
	ostr.write((char*)&R_yn_ ,sizeof(R_yn_));
	ostr.write((char*)&R_un_ ,sizeof(R_un_));
	ostr.write((char*)&gamma_m_ ,sizeof(gamma_m_));
	ostr.write((char*)&density_ ,sizeof(density_));
	ostr.write((char*)&t_max_ ,sizeof(t_max_));

}
void Steel::load(std::istream& istr)
{
	wchar_t* buf1;
	unsigned short l1;
	istr.read((char*)&l1,sizeof(l1));
	buf1 =(wchar_t*) malloc(l1*sizeof(wchar_t));
	istr.read((char*)buf1,l1*sizeof(wchar_t));
	standard_ = String(buf1);
	free(buf1);

	wchar_t* buf2;
	unsigned short l2;
	istr.read((char*)&l2,sizeof(l2));
	buf2 =(wchar_t*) malloc(l2*sizeof(wchar_t));
	istr.read((char*)buf2,l2*sizeof(wchar_t));
	steel_grade_ = String(buf2);
	free(buf2);

	istr.read((char*)&E_st_ ,sizeof(E_st_));
	istr.read((char*)&G_st_ ,sizeof(G_st_));
	istr.read((char*)&nu_st_ ,sizeof(nu_st_));
	istr.read((char*)&R_yn_ ,sizeof(R_yn_));
	istr.read((char*)&R_un_ ,sizeof(R_un_));
	istr.read((char*)&gamma_m_ ,sizeof(gamma_m_));
	istr.read((char*)&density_ ,sizeof(density_));
	istr.read((char*)&t_max_ ,sizeof(t_max_));
}
void Steel::set_default_values()
{
	steel_grade_ = L"C355Б";
	standard_ = L"СП 16.13330.2017, Таблица В.4, двутавры";
	E_st_ = 206000.;
	G_st_ = 79200.;
	nu_st_ = 0.3;
	R_yn_ = 355.;
	R_un_ = 470.;
	gamma_m_ = 1.025;
	density_ = 7850;
	t_max_ = 11.;

}





