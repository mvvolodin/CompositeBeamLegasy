/*------------------------------------------------------------------*/
/*                       типы данных                                */
/*------------------------------------------------------------------*/

#ifndef tdataH
#define tdataH

#include <vcl.h>
#include "Alinit.h"
#include "stdio.h"

#define  MAX_GRAN 6      /* максимальное число граней на элементе */
#define  MAX_GRAN_NE 4   /* максимальное число узлов на грани */
#define  MAX_MATERIAL  10     // максимальное число материалов

#define  COMMON     "Common"
#define  MATERIAL   "Material"
#define  CONSTR     "Constr"
#define  LOADING    "Loading"
#define  COMBIN    "Combin"
#define  JOINT     "Joint"
#define  ANALYSIS_PARAM     "Analysis_Param"
#define  MESH       "Mesh"
#define  RESULT     "Result"
#define  UNIT_PARAM "Unit_Param"
#define  ZATYAGHKA_PARAM "Zatyaghka_Param"
#define  CONSTRUCT_ELEMENT "Construct_Element"
#define  MASS_AND_DYNAM "Mass_and_Dynam"
#define  ARBIT_UNIT_TYPE "Arbit_Unit_Type"
#define  PURLINS_PARAM "Purlins_Param"
#define  SKELETON "Skeleton"


typedef struct _release              /* условия примыкания */
    {
       short node;
       bool rel[6];
    }  RELEASE;

typedef struct _point_3D              /* координаты точки */
    {
       float x;
       float y;
       float z;
    } POINT_3D;
typedef struct _numgran              /* описание грани */
    {
       int n_elem;  // номер элемента, которому принадлежит грань
       short n_gran;    // номер грани на элементе
       int i_gran;  // исходный номер грани
    } NUM_GRAN;

typedef struct _gran              /* описание грани */
    {
       short gran_node[MAX_GRAN_NE+1];
    }GRAN;


typedef struct _vname               /* Наименование неизвестного */
    {
      unsigned short node1;          /* Номер первого узла */
      unsigned short node2;          /* Номер второго узла */
      unsigned char direct;          /* Направление */
    }  VNAME;

#define VNSIZE sizeof(VNAME)

typedef union _anytype
{
  char ch;
  VNAME vn;
  int  in;
  short sh;
  double dou;
} ANYTYPE;

typedef struct _cord  /* элемент массива систем координат */
    {
      char type;         /* тип системы координат: R, С или S */
      int  meth;         /* способ задания: 1 или 2 */
      int  rid;          /* номер системы координат, в которой
                            определена данная ситема координат */
      int  num[3];       /* номера трех узлов для способа 1   */
      double coor[3][3]; /* координаты трех узлов для способа 2 */
    }  CORDSYS;

typedef struct _material  /* элемент массива данных материала */
    {
      char   title[12];
      double E;          /* модуль Юнга */
      double G;          /* модуль сдвига */
      double nu;         /* коэффициент Пуассона */
	  double Ry;         /* Расчетное допускаемое напряжение (предел текучески) для минимальной толщиы */
	  double Ru;         /* Расчетное временное сопротивление разрыву */
	  double gamma_m;    /* коэффициент надежности по материалу */
      double dens;       /* плотность */
    }  MATER;

typedef struct _felem                  /* Описание элементов */
    {
      char  *type;
      short nnode;                     /* число узлов на элементе */
      short nstif;                     /* число жесткостей на элементе */
      short ndens;                     /* число плотностей на элементе */
      short norder;                    /* порядок МЖ */
      short ord1;                      /* число строк подвала */
      short ord2;                      /* число столбцов */
      short nrez;                      /* число результатов */
      char *direct;                    /* направления */
      short n_dimention;               /* размерность элемента */
      short n_gran;                    /* число обощенных граней */
      short m_gran;                    /* число узлов на грани */
      short *num_sigma_equ_down;       /* номера эквивалентных напряжений в узлах и в центре */
      short *num_sigma_equ_up;         /* номера эквивалентных напряжений в узлах и в центре */
      short *num_sigma_comp_down;      /* номера компонентов напряжений в центре элемента в СКЭ */
      short *num_sigma_comp_up;        /* номера компонентов напряжений в центре элемента в СКЭ */
      short *num_force_equ;            /* номера эквивалентных погонных усилий в узлах и в центре */
      short *num_sigma_master;         /* номера главных напряжений S1 и S2 и угла */
      short *num_force_master;         /* номера главных усилий N1 и N2 и угла */
      short *num_gran[MAX_GRAN];        /* описание обощенных граней */
      unsigned char  *num1;
      unsigned char  *num2;
    }  FELEM;


 typedef struct _cons
 {
     int  node;               /* Номер узла */
     bool constr[6];          /* Направление */
 } CONS;

 typedef struct _cons_c
 {
     int  node;               /* Номер узла */
     char DOF[7];          /* Направление */
 } CONS_c;

typedef struct _load_nodal  {
    int    node;             // Номер узла
    double force[6];         // Нагрузка по направлениям  
}  LOAD_NODAL;

typedef struct _load_elemental  {
    int    element;          // Номер элемента
    double length;           // длина элемента
    double force_1[3];       // Нагрузка по направлениям на конце 1: привязка = 0
    double force_2[3];       // Нагрузка по направлениям на конце 2: привязка = length
}  LOAD_ELEMENTAL;

typedef struct _cont
 {
    char type[9];
    short cod;         /* код элемента */
    int gr_stf;        /* номер группы параметров элемента */
    int num_gr;        /* номер группы (страницы) элементов */
    int num_el;        /* номер элемента в группе (странице) */
 } CONT;

typedef struct _param_analyse
 {
    char type_analyse[12];
    int num_active_load;
    double gamma;       // коэффициент надежности по ответственности
 } PARAM_ANALYSE;

typedef struct _double3 {
    double g[3];
} DOUBLE3;

typedef struct _double9 {
    double g[9];
} DOUBLE9;

typedef struct _double11 {
    double g[11];
} DOUBLE11;

typedef struct _coor_el{
     double x1;
     double z1;
     double x2;
     double z2;
} COOR_EL;


#endif

void formtvm(double* xo, double* x1, double gam, double t_conv[][4],
             double *z_mod);


FELEM * antype(int);

int cmp_load_nodal(LOAD_NODAL*, LOAD_NODAL*);
int cmp_load_elemental(LOAD_ELEMENTAL*, LOAD_ELEMENTAL*);

int cmp_point3d(POINT_3D*, POINT_3D*);
int cmp_point3d_eps(POINT_3D*, POINT_3D*, float);
int cmpcont(CONT*, CONT*);
int cmpvname(VNAME*, VNAME*);
int cmp_gran(GRAN*, GRAN*);
int cmpdouble(double*, double*);
int cmpcoor(double *elem1, double *elem2);
int cmpi(int*, int*);
int cmp_coor_el(COOR_EL *elem1, COOR_EL *elem2);
int cmps(unsigned short*, unsigned short*);
int cmpd(double*, double*);
int cmpdi(double*, double*);
int cmp_double3(DOUBLE3*, DOUBLE3*);
int cmp_double9(DOUBLE9*, DOUBLE9*);
int cmp_double11(DOUBLE11*, DOUBLE11*);
int cmp_TPoint(TPoint *elem1, TPoint *elem2);
int cmp_TPoint_diff(TPoint *elem1, TPoint *elem2, TPoint *diff);

void prin_lis(char*, int, VNAME*);  /* печать вектора */
void prinv_lis(char*,int, double*, VNAME*);  /* печать вектора */
void prinv_tran(char*,int, double*, VNAME*);  /* печать вектора по направлениям u, v, w */
void prinv_point_3d(char*,int, POINT_3D*);  /* печать вектора */
void prinv(char*,int, double*);  /* печать вектора */
void prinv_bool(char *str, int n, bool *vec);
void prinv_F(char *str, int n, double *vec);
void prinvi(char*,int, int*);  /* печать вектора */
void prinvf(char*,int, float*);  /* печать вектора */
void prinm0(char*, int,int, double**);  /* печать матрицы по строкам */
void prinv_cord(char *str, int n, CORDSYS* cord);
AnsiString Float_to_str(double value, char *format);


int Get_load_active( int n_dof, int nnel, DSC_MVC * elnum, VNAME* listvar,
             LOAD_NODAL * load_nodal, LOAD_ELEMENTAL *load_elemental, double *load, int *n_load, int *e_load );
int  ConvertLoadElemToNodal(int n_dof, VNAME *listvar,
                        LOAD_ELEMENTAL* load_elemental, int e_load, double *load_sign, double mult_F);    
int  ExpandLoadMeshBody(int nnel, int n_dof, DSC_MVC * elnum, VNAME *listvar, double *load);
void Set_disp_node(int nnuz, int n_dof, VNAME *list, double *disp, double **disp_node);
int Set_disp_node_m(int nnuz, int n_dof, VNAME *list, double *disp, int num_disp, double **disp_node);
void Set_koeff_disp(int n_coor, double **disp_node, double* koeff_disp, double span);
// Получить максимальный размер рамы - либо по X, либо по Z
double Get_max_size();

int Get_coor_point_on_norm(int n_line, double length, double *coor_point, double dx, double dz);
int  restcons_node(int nnuz, CONS* constr_node, int *n_constr);

void rep_int(int* list, int* vec, int n);
