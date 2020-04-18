#ifndef  listconstH
#define  listconstH

#define EMBRAC

#define  MAX_NUZ 65500   /* максимальный номер узла */
#define  MAX_NEL 65500   /* максимальное число элементов */
#define  MAX_PAGE 32000  /* максимальное число страниц */
#define  MAX_GR  32000   /* максимальное число групп */
//#define  MAXWORD 200     /* максимальное число слов в строке */
#define  MAX_NE  20      /* максимальное число узлов на элементе */
#define  MAX_GRAN 6      /* максимальное число граней на элементе */
#define  MAX_GRAN_NE 4   /* максимальное число узлов на грани */
#define  MAX_ST  16      /* максимальное число жесткосей на элементе */
#define  MAX_ORD 64      /* максимальный порядок МЖ элемента */
#define  MAX_RES 100     /* максимальное число результатов на элементе */
#define  MAX_FRONT 3000  /* максимальный размер фронта */
#define  MAXELCOD  100   /*  максимальное число типов элементов */
#define  MAXVAR    655000 /*  максимальное неизвестных */
#define  MINWOR  10000   /* размер рабочей области слияния */
#define  MAX_CONS 10000  /* максимальное число закреплений, нагрузок */
#define  MAX_MASS 10000  /* максимальное число сосредоточенных масс */
#define  MAX_CORD 100    /* максимальное число систем координат */
#define  MAX_TYPE_STRESS  200  // максимальное число типов напряжений
#define  MAXRSU    10000
#define  MACEPS 2e-16
#define  U26    26*MACEPS
#define  CONSTR_DIAG  1e20  /* диагональный элемент для закрепленного неизвестного */
#define  EPS_ZERO 1e-20

#define  RADIAN 57.29577951308232087684
#define  HUGES        65500
#define  MAXB     2147483647
#define  INT_MAX  2147483647
#define _G          9.81   // 9.80661
#define REVERSE_G   1/_G   // 1/g
#define KOEFF_WEIGT_LOAD       1.3
#define K_ZAT  1.2  // коэффициент затяжки
#define NODE_CONSTR_DELTA_Z  10.0  // отступ по Z
#define PI_2    90/RADIAN
#define PI_    180/RADIAN
#define MAX_KOL_UKLON  10  // Максимальный уклон колонн рамы 1-го типа (10%)
#define MIN_DISTANCE   1.001  // минимально возможное расстояние между сечениями

#define L_DEMO        18000       // Максимальный пролет рамы в демонстрационном режиме
#define L_DEMO_SAVE   18000       // Максимальный сохраняемый пролет рамы в демонстрационном режиме

  /*  функция ABS  */
#define ABS(x) (((x)<0) ? -(x):(x))
#define _ABS(x) (((x)<0) ? -(x):(x))
  /*  функция MIN  */
#define MIN(x,y)  (((x)<(y)) ? (x):(y))
  /*  функция MAX  */
#define MAX(x,y)  (((x)>(y)) ? (x):(y))
#define SIGN(x)  (((x)==0) ? 0 : ((x)>0) ? 1:-1)

#define COPY(vec1,vec0,i)\
        memcpy((char*)vec1,(char*)vec0,(int)(i*sizeof(double)))

#define SNOW_REGION_11   0.80, 1.20, 1.80, 2.40, 3.20, 4.00, 4.80, 5.60   // менее точно
#define SNOW_REGION_16   0.5, 1.0, 1.50, 2.00, 2.50, 3.00, 3.50, 4.00
//#define SNOW_REGION   0.785, 1.177, 1.766, 2.354, 3.139, 3.924, 4.709, 5.494

#define WIND_REGION   0.17, 0.23, 0.30, 0.38, 0.48, 0.60, 0.73, 0.85
//#define WIND_REGION     0.167, 0.226, 0.294, 0.373, 0.471, 0.589, 0.716, 0.834

#define K_vs_Z_HEIGHT 0.75,  0.5,  0.4,  1.0,  0.65, 0.4,  1.25,  0.85,  0.55,   1.5,   1.1,   0.8
#define H1_dev_L      0,    0.5,    1,    2
#define CE1_vs_H1     0,   -0.6, -0.7, -0.8, 0.2, -0.4, -0.7, -0.8
#define CE1_vs_H1     0,   -0.6, -0.7, -0.8, 0.2, -0.4, -0.7, -0.8
#define CE2_vs_H1    -0.4, -0.4, -0.5, -0.8
#define H1_Wind       5000.0
#define H2_Wind      10000.0
#define H3_Wind      20000.0
#define strMODE      "Форма"

// признак схемы
#define shemaXYZ     0
#define shemaXZ      1


#endif