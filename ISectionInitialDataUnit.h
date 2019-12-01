//---------------------------------------------------------------------------

#ifndef ISectionInitialDataUnitH
#define ISectionInitialDataUnitH

#include "Data_Profil.h"
#include "Get_param_sect_func.h"

//---------------------------------------------------------------------------
struct TISectionInitialData{

	GEOM_PARAM_SECT excessive_sect_geomet_data;
	double b_uf_;
	double t_uf_;
	double b_lf_;
	double t_lf_;
	double h_w_;
	double t_w_;
	double Ar;
	double Izz;
	double Iyy;
	double Hsect; // высота сечения (по оси Z)
	double Zct;   // координта ц.т. сечения относительно внешней грани
	double Sx[3]; // статичесие моменты в точках вычисления касательных напряжений
	double Sy[3]; // статичесие моменты в точках вычисления касательных напряжений
	double Hp;    // расстояние между ц.т. поясов
	double Zp;    // координта ц.т. сечения относительно ц.т. внешнего пояса
	double Wu_max;
	double Wu_min;
	double Wv_max;
	double Wv_min;
TISectionInitialData(){};
TISectionInitialData (SECT_DVUTAVR* i_section_initial_data);

};
#endif
