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

/*
    typedef struct _geom_param_sect {   // Геометрические параметры сечения
       double Ar;
       double Izz;
       double Iyy;
       double Iyz;
       double Itor;
       double Hsect; // высота сечения (по оси Z)
       double Wsect; // ширина сечения (по оси Y)
       double Zct;   // координта ц.т. сечения относительно внешней грани
       double Yct;   // координта ц.т. сечения относительно боковой грани  Yct = Wsect/2 (сечение предполагается симметричным)
       double Ze;    // координта центра сдвига сечения относительно внешней грани
       double Ye;    // координта центра сдвига сечения относительно боковой грани
       double ky;    // коэффициент сдвиговой жесткости по оси Y
       double kz;    // коэффициент сдвиговой жесткости по оси Z
       double point_stress[4][2]; // координаты точек вычисчления напряжений (для экспорта в NASTRAN)
       double z_tau[3]; // координаты Z точек вычисчления касательных напряжений (относительно ц.т)
       double Sx[3]; // статичесие моменты в точках вычисления касательных напряжений
       double Sy[3]; // статичесие моменты в точках вычисления касательных напряжений
       double Hp;    // расстояние между ц.т. поясов
       double Zp;    // координта ц.т. сечения относительно ц.т. внешнего пояса
       double Rad;   // радиус скругления полки со стенкой для стандартных профилей
       double alfa;  // Угол между осью Y и главной осью
       double I1;    // Главный момент инерции
       double I2;    // второй главный момент инерции
       double Iw;    // секториальный момент инерции
       double Wx_f;  // Момент сопротивления изгибу сечения, состояшего только из полок
       double Wx_pl; // Пластический момент сопротивления изгибу
       double Wu_max;
       double Wu_min;
       double Wv_max;
       double Wv_min;
       int    index_orient;  // Ориентация сечения 0 - в пл. XZ; 1 - в пл. YZ
	}  GEOM_PARAM_SECT;
*/
