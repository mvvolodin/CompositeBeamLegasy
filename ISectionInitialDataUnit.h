//---------------------------------------------------------------------------

#ifndef ISectionInitialDataUnitH
#define ISectionInitialDataUnitH

#include "Data_Profil.h"
#include "Get_param_sect_func.h"

//---------------------------------------------------------------------------
struct TISectionInitialData{

	String profile_number_;//им€ профил€ (в √ќ—“ – 57837 номер профил€)
	double b_uf_;
	double t_uf_;
	double b_lf_;
	double t_lf_;
	double h_w_;
	double t_w_;
	double weight_;//погонна€ масса
	double r_;//радиус галтели
	double Ast;
	double Ist;
	double Hsect; // высота сечени€ (по оси Z)
	double Sx[3]; // статичесие моменты в точках вычислени€ касательных напр€жений
	double Sy[3]; // статичесие моменты в точках вычислени€ касательных напр€жений
	double Hp;    // рассто€ние между ц.т. по€сов
	double Z_f2_st;    // координта ц.т. сечени€ относительно ц.т. внешнего по€са
	double Z_f1_st;  // координта ц.т. сечени€ относительно ц.т. внутреннего по€са
	double Wf2_st;
	double Wf1_st;

	TISectionInitialData(){};
	TISectionInitialData (SECT_DVUTAVR* i_section_initial_data);

};
#endif

