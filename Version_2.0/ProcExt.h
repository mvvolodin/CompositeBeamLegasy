//#ifndef procextH
//#define procextH
//
////#include "Steel_param_ARSS.h"
//
//int ortog_q(int, int, int, double**, double**, double*, double*);
//int ortog_m(int, int, double**, double*, double**);
//int ortog_mn(int,int, double**, double**, double*);
//void Blpmat(int, int, int, double*, double**);
//void Blpmatt(int,double*,double**);
//
//int normat(int,int, double**, double*);
//int jacobi_(int, char , double**, double*, double**,
//             unsigned long*, double*, double*);
//int unfmat(int,int, int*,int*,char*,double**,int*);
//int ungmat(int,int, int*,int*,char*,double**,int*);
//void mltmm(int,int,int,double**,double**,double**);
//void mltm_trm(int,int,int,double**,double**,double**);
//void mltmtm(int,int,int,double**,double**,double**);
//void mltmv(int n, int m, double** mat, double * vec,double * out);
//void mltmtv(int n, int m, double** mat, double * vec,double * out);
//void mltmtm_l1(int,int,int,double**,double**,double**,int,int*);
//void mltmv_l1(int n, int m, double** mat, double * vec,double * out,
//              int,int*);
//void mltmtv_l1(int n, int m, double** mat, double * vec,double * out,
//               int,int*);
//void multnnt(int n_dof, int n_link, double ** n_mat, double ** mat_link);
//
//int mtrian(int,double**);
//int mtrianr(int,double**,double);
//int mlpol(int,double**,double**,double**);
//int  mlback(int,int,double**,double**);
//int msolv(int nfr, double** k1, double* rst, double* bu);
//
//void initc(char *, int, char);
//void initd(double *, int, double);
//void initl(long *, int, long);
//void inits(short *, int, short);
//void initi(int *, int, int);
//
//void random(int, int, int, double**, int);
//
//void ltmatl0(double** x, double **a, double ** xa, int n);
//void EulerMa(double*,double*);
//int cosvec1(double[][3],double[][3]);
//int codtype(char*);
//int codtp_n(char * name);
//int codtp_scad(int type_scad);
double Round(double value, int n_sign);
double Round_plus(double value, int n_sign);
double Round_step(double value, double step);
// Округление по ряду ширин полки в большую сторону
double Round_step_floor(double value, double step);
// Округление по ряду толщин в большую сторону
double Round_row(double value, int index);
double Round_row_bpol(double thick, double width, double round_width, int index);
//// Получить максимальную ширину полки для данной толщины
//double Get_max_bpol(double thick, int index);
//
//int search_ind(int dim, double *tabl_, double value);
//void Get_Mater_Param(int i, double *E, double *G, double *nu);
//
//void   ListParam();
//void   ListAddSect();
//void   ListAddSpanSect();
//void   ListEdge();
//void   ListMeshSect();
//void   ListMainSect();
//void   ListElement();
//void   ListCoordinates();
//void   ListElemProperty();
//void   ListJointAssembly();
//void   ListJointFactory();
//void   ListStressElement();
//void   ListDisplacement();
//void   ListBucklingMode();
//void   ListCriticalFactor();
//void   ListLength_Design();
//void   ListKoeffLength();
//void   ListLoad();
//void   ListVarAnalisis();
//void   ListCheck_Strength();
//void   ListCheck_Stab();
//void   ListCheck_TakeLoad();
//void   ListCheck_Stab_Kol();
//void   ListCombineElement();
//void   List_GroupSect();
//
//
//#endif
