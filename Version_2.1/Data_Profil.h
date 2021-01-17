/*------------------------------------------------------------------*/
/*                       типы данных профилей                       */
/*------------------------------------------------------------------*/
/*
 В файле представоены следующие сущности:
	a) Структуры описывающие геометрию различных профилей (линейные размеры), а также содержащие их идентивикаию
	в виде номера группу профилей и номер профиля в группе
	b)Задана структура описывающая геометрические характеристики (моменты сопротивления, инерции и т.д.)
    c)Декларация функции заполняющей массив TPoint применямый для отрисовки двутавра
 */
#ifndef DATA_PROFILH
#define DATA_PROFILH

#include <vcl.h>

#define NO_CHOISE          0
#define DVUTAVR            1
#define SQUARE_TUBE        2
#define RECT_TUBE          3
#define CIRCULAR_TUBE      4
#define RECTANCULAR        5
#define SHVELLER           6
#define TAVR_UP            7
#define TAVR_DOWN          8
//#define DVUTAVR_YZ         9

#define GNU_CH              10
#define GNU_C              11
#define GNU_Z              12
#define GNU_ZC             13
#define GNU_SIGMA          14

typedef struct _sect_dvutavr {
   double b;      // толщина стенки двутавра
   double h;      // высота стенки двутавра
   double b1;     // ширина наружной полки двутавра
   double h1;     // толщина внутренней полки двутавра
   double b2;     // ширина наружной полки двутавра
   double h2;     // толщина внутренней полки двутавра
   int    n_group;   // номер группы профилей
   int    n_profil;  // номер профиля в группе
   int    index_orient;   // ориентация = 0 (в плоскости XZ) или 1 (в плоскости YZ)
   int    type_prof;  // или двутавр (DVUTAVR) , или гнутик
   float  fG;         // Глубина выштамповки  (??? к двутавру не применяется)
   float  tnom;    // Номинальная толщина с учетом всех покрытий  (??? к двутавру не применяется)
   float  b2G;     // Ширина нижней полки гнутика (??? к двутавру не применяется)
   float  gG;    //  // высота наклонного ребра (??? к двутавру не применяется)
   bool flag_concl;
   char profile_number_[10];//имя профиля. Тип char, так как тип String обладает non-trivial ctor MV 18.01.20
   double r; //радиус галтели MV 18.01.20
   double weight;//вес погонного метра профиля MV 18.01.20
   double C; //Центр тяжести MV 11.11.2020
   double A; //Площадь MV 11.11.2020
   double I; //Момент инерции MV 11.11.2020
}  SECT_DVUTAVR;


typedef struct _sect_gnutic {
   double tG;      // толщина стенки (стали)
   double hG;      // высота гнутика
   double bG;      // ширина полки
   double cG;      // высота отгиба
   double rG;      // радиус скругления
   double jG;      // ширина выштамповки
   int    n_group;   // номер группы профилей
   int    n_profil;  // номер профиля в группе
   int    index_orient;   // ориентация = 0 (в плоскости XZ) или 1 (в плоскости YZ)
   int    type_prof;      //
   float  fG;      // Глубина выштамповки
   float  tnom;    // Номинальная толщина с учетом всех покрытий
   float  b2G;     // Ширина нижней полки гнутика
   float  gG;      // высота наклонного ребра
   bool flag_concl;
}  SECT_GNUTIC;

typedef struct _sect_square {
   double thickness;  // толщина стенок
   double side;       // размер стороны
   double b1;   // не используется
   double h1;   // не используется
   double b2;   // не используется
   double h2;   // не используется
   int    n_group;   // номер группы профилей - определяет h*b
   int    n_profil;  // номер профиля в группе - определяет t
   int    index_orient;   // ориентация = 0
   int    dummy_int;
   double rad;
   double t_red;
   bool flag_concl;
}  SECT_SQUARE;

typedef struct _sect_rect {
   double b;      // ширина сечения
   double h;      // высота сечения
   double b1;     // толщина стенок по ширине
   double h1;     // толщина стенок по высоте
   double b2;     // не используется
   double h2;     // не используется
   int    n_group;   // номер группы профилей - определяет h*b
   int    n_profil;  // порядковый номер профиля в группе - определяет t
   int    index_orient;   // ориентация: 0 - по высоте; 1 - по ширине
   int    dummy_int;
   double rad;
   double t_red;
   bool flag_concl;
}  SECT_RECT;

typedef struct _sect_rect_solid {
   double b;      // ширина сечения
   double h;      // высота сечения
   double b1;     // не используется
   double h1;     // не используется
   double b2;     // не используется
   double h2;     // не используется
   int    n_group;   // номер группы профилей
   int    n_profil;  // номер профиля в группе
   int    index_orient;   // ориентация = 0
   int    dummy_int;
   double dummy_double[2];
   bool flag_concl;
}  SECT_RECT_SOLID;

typedef struct _sect_circ {
   double thickness;  // толщина стенки
   double diameter;   // диаметр
   double b1;         // не используется
   double h1;         // не используется
   double b2;         // не используется
   double h2;         // не используется
   int    n_group;   // номер группы профилей
   int    n_profil;  // номер профиля в группе
   int    index_orient;   // ориентация = 0
   int    dummy_int;
   double dummy;
   double t_red;
   bool flag_concl;
}  SECT_CIRC;

typedef union _common_sect {   // Обобщенные данные о сечении
   SECT_DVUTAVR dvutavr;
   SECT_SQUARE  square;
   SECT_RECT    rect;
   SECT_CIRC    circ;
   SECT_RECT_SOLID rect_solid;
}  COMMON_SECT;

typedef struct _data_sect_scad {   // Обобщенные данные о сечении элемента
   int  type_sect;
   COMMON_SECT com_sect;
}  DATA_SECT_SCAD;


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

typedef struct _stress_param_sect {   // параметры напряженного состояния сечения
   double sigma_ext;
   double sigma_w_ext; // напряжение в стенке в месте стыка с внешней полкой
   double sigma_int;
   double sigma_w_int; // напряжение в стенке в месте стыка с внутренней полкой
   double sigma_ct;    // напряжение в стенке в центре тяжести сечения
   double Hsect;       // высота сечения
   double Zct;         // координта ц.т. сечения относительно внешней грани
   double z0;         // координата sigma=0, отсчитывается от внешней грани
}  STRESS_PARAM_SECT;

void  Point_dvutavr(int zero, int zero1, int zero2, SECT_DVUTAVR *sect, float scale, TPoint *vertices);

#endif
