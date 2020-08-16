//---------------------------------------------------------------------------

#ifndef Steel_param_ARSSH
#define Steel_param_ARSSH

// Параметры материала из табл. В.3 СП 16.13330.2017
#define N_STEEL_HOT 15
#define N_STEEL_HOT_GOST 14
#define N_STEEL_HOTB 8
#define N_STEEL_HOTB_GOST 7
#define N_STEEL_COLD 6

// Трубы
#define STEEL_HOT       "C235",  "C245",   "C255", "C345", "C345K", "C355",  "C355-1", "C355-K", \
						"C355П", "C390-1", "C390", "C440", "C550",  "C590",  "C690"
#define STEEL_HOT_GOST  "C235",  "C245",   "C255", "C345", "C345K", "C355",  "C355-1", "C355-K", \
						"C355П", "C390-1", "C390", "C440", "C550",  "C590"
// Фасонный прокат
#define STEEL_HOTB      "C255Б", "C255Б-1", "C345Б", "C345Б-1", "C355Б", "C355Б-1", "C390Б", "C440Б"
#define STEEL_HOTB_GOST "C245",  "C255",    "C345",  "C345K",   "C355",  "C355-1",  "C390"
// Холодный прокат
#define STEEL_COLD "220", "ХП,ПК", "250", "280", "320", "350"

#define N_C235  1
#define N_C245  1
#define N_C255  4
#define N_C345  6
#define N_C345K 1
#define N_C355  6
#define N_C355_1  3
#define N_C355_K  3
#define N_C355_P  2
#define N_C390  1
#define N_C390_1 1
#define N_C440  1
#define N_C550  1
#define N_C590  1
#define N_C690 1
//--------------------------------
#define N_C235G  2
#define N_C245G  2
#define N_C255G  4
#define N_C345G  7
#define N_C345KG 1
#define N_C355G  6
#define N_C355_1G  3
#define N_C355KG  3
#define N_C355PG  2
#define N_C390G  1
#define N_C390_1G 1
#define N_C440G  1
#define N_C550G  1
#define N_C590G  1

//--------------------------------
#define N_C255B    7
#define N_C345B    4   //
#define N_C345B_1  4
#define N_C355B    6
#define N_C355B_1  3
#define N_C390B    5
#define N_C440B    5
//--------------------------------
#define N_C245BG    2
#define N_C255BG    3
#define N_C345BG    3   //
#define N_C345KBG   1
#define N_C355BG    2
#define N_C355_1BG  2
#define N_C390BG    3


#define steel_T_UPPER  1
#define steel_T_LESS   2
#define steel_NO_STEEL 3
#define steel_T_UPPER_GLOB  4

#define weldSINGLE 1
#define weldDOUBLE 2

#define weldTAVR2 0
#define weldNAXLEST 1
#define weldTAVR1  2
//typedef struct _material  /* элемент массива данных материала */
//{
//	char   title[12];
//	double E;          /* модуль Юнга */
//	double G;          /* модуль сдвига */
//	double nu;         /* коэффициент Пуассона */
//	double Ry;         /* Расчетное допускаемое напряжение (предел текучески) для минимальной толщиы */
//	double Ru;         /* Расчетное временное сопротивление разрыву */
//	double gamma_m;    /* коэффициент надежности по материалу */
//	double dens;       /* плотность */
//}  MATERIAL;

//---------------------------------------------------------------------------
typedef struct _steel_param {  // данные о параметрах стали для данной толщины
	char   title[8];
		  /* модуль сдвига */
	double thick;
	double Ryn;                 // Предел текучести (нормативное значение)
	double Run;                 // Временное сопротивление стали разрыву - sigma_b (нормативное значение)
	double Ry;                  // Предел текучести (расчетное значение)
	double Ru;
	 /* плотность */
} STEEL_PARAM;

typedef struct _mater_param {  // данные о параметрах стали
	char   title[10];
    int    n_row;
    double thick_row[10];
	double Ryn_row[10];  // Предел текучести
	double Run_row[10];  // Временное сопротивление
    double Ry_row[10];
    double Ru_row[10];
} MATER_PARAM;
// Получить временное сопротивление растяжению, сжатию и изгибу по марке стали и толщине проката
double Steel_param_Run(char *Msteel, double thick, int *rc, bool flag_diag_thick);
// Получить расчетное сопротивление растяжению, сжатию и изгибу по временному сопротивления - по марке стали и толщине проката
double Steel_param_Ru(char *Msteel, double thick, int *rc, bool flag_diag_thick);
// Получить диапазон толщин, в который попадает заданная толщина
int Get_thick_range(char *Msteel, double thick, double *thick_range);
// Получить расчетное сопротивление растяжению, сжатию и изгибу по марке стали и толщине проката
double Steel_param_Ry(char *Msteel, double thick, int *rc, bool flag_diag_thick);
//  Получить нормативные и расчетные сопротивления по марке стали и толщине проката
int Steel_param(char *Msteel, double thick, STEEL_PARAM* steel_param, bool flag_diag_thick);
//  Получить таблицу свойств стали по марке стали
int Get_Mater_param(char *Msteel, MATER_PARAM* mater_param);
// Получить нормативные и расчетные сопротивления по марке стали и толщине проката с использованием таблицы материала
int Get_steel_param(MATER_PARAM *mater_param, double thick, STEEL_PARAM* steel_param);
// Заполнить таблицу материала
void Fill_mater_param(char* Msteel, int n_thick, double steel[][4], double *row_t, MATER_PARAM* mater_param);

#endif
