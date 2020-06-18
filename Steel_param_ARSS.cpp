//---------------------------------------------------------------------------
#include "Steel_param_ARSS.h"
//#include "SteelDefinitionFormUnit.h"
#include "DefineSteelFormUnit.h"
#define EMBRAC
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma package(smart_init)


// Параметры материала из табл. В.3 СП 16.13330.2017 - трубы
static double steelC235[N_C235][4]={235,360,230,350};
static double tC235[N_C235+1]={2,4};

static double steelC245[N_C245][4]={245,370,240,360};
static double tC245[N_C245+1]={2,20};

static double steelC255[N_C255][4]={255,380,250,370,
									245,380,240,370,
									245,370,240,360,
									235,370,230,360};
static double tC255[N_C255+1]={2, 3.9, 10, 20, 40};

static double steelC345[N_C345][4]={345,490,335,480,
								325,470,315,460,
								305,460,300,450,
								285,450,280,440,
								275,440,270,430,
								265,430,260,420};
static double tC345[N_C345+1]={2, 10, 20, 40, 60, 80, 160};

static double steelC345K[N_C345K][4]={345,470,340,460};
static double tC345K[N_C345K+1]={4,10};

static double steelC355[N_C355][4]={355,470,350,460,
									345,470,340,460,
									335,470,330,460,
									325,470,320,460,
									315,470,310,460,
									295,470,285,460};
static double tC355[N_C355+1]={8,16,40,60,80, 100, 160};

static double steelC355_1[N_C355_1][4]={355,470,350,460,
									345,470,340,460,
									335,470,330,460};
static double tC355_1[N_C355_1+1]={8,16,40,50};

static double steelC355_K[N_C355_K][4]={355,470,350,460,
									345,470,340,460,
									335,470,330,460};
static double tC355_K[N_C355_K+1]={8,16,40,50};

static double steelC355_P[N_C355_P][4]={355,470,350,460,
									345,470,340,460};
static double tC355_P[N_C355_P+1]={8,16,40};

static double steelC390[N_C390][4]={390,520,380,505};
static double tC390[N_C390+1]={8,50};

static double steelC390_1[N_C390_1][4]={390,520,380,505};
static double tC390_1[N_C390_1+1]={8,50};

static double steelC440[N_C440][4]={440,540,430,525};
static double tC440[N_C440+1]={8,50};

static double steelC550[N_C550][4]={540,640,525,625};
static double tC550[N_C550+1]={8, 50};

static double steelC590[N_C590][4]={590,685,575,670};
static double tC590[N_C590+1]={8, 50};

static double steelC690[N_C690][4]={690,785,650,745};
static double tC690[N_C690+1]={8, 50};

// Для холоднокатанного проката табл. 6.2 СП 260.1325800
static double steelC_220[2][4]={220, 200, 215, 125,
								220, 200, 215, 125};
static double steelC_HPPK[2][4]={230, 300, 225, 135,
								 230, 300, 225, 135};
static double steelC_250[2][4]={250, 330, 245, 140,
								250, 330, 245, 140};
static double steelC_280[2][4]={280, 360, 270, 155,
								280, 360, 270, 155};
static double steelC_320[2][4]={320, 390, 310, 180,
								320, 390, 310, 180};
static double steelC_350[2][4]={350, 420, 330, 190,
								350, 420, 330, 190};
static double tCold[3]={0, 5, 100};
//---------------------------------------------------------------
// Фасон СП
static double steelC255B[N_C255B][4]={ 255,380,250,370,
									   245,370,240,360,
									   235,370,230,360,
									   235,370,230,360,
									   225,370,220,360,
									   215,370,210,360,
									   200,360,195,350};
static double tC255B[N_C255B+1]={1, 10, 20, 40, 60, 80, 100 , 1000};

static double steelC345B[N_C345B][4]={345,480,335,470,
								325,470,315,460,
								305,460,300,450,
								285,450,280,440,
								};
static double tC345B[N_C345B+1]={1, 10, 20, 40, 60};

static double steelC345B_1[N_C345B_1][4]={345,490,335,480,
								325,470,315,460,
								305,460,300,450,
								285,450,280,440,
								};
static double tC345B_1[N_C345B_1+1]={1, 10, 20, 40, 60};

static double steelC355B[N_C355B][4]={ 355,470,345,460,
									   345,470,335,460,
									   335,470,325,460,
									   325,460,315,450,
									   315,460,305,450,
									   295,460,290,450};

static double tC355B[N_C355B+1]={1, 20, 40, 60, 80, 100 , 1000};

static double steelC355B_1[N_C355B_1][4]={ 355,470,345,460,
										   345,470,335,460,
										   335,470,325,460,
									   };

static double tC355B_1[N_C355B_1+1]={1, 20, 40, 60};

static double steelC390B[N_C390B][4]={390,520,380,505,
                                      370,490,360,480,
                                      360,480,350,470,
                                      350,480,340,470,
                                      330,470,320,460};

static double tC390B[N_C390B+1]={1, 30, 60, 80, 100, 1000};

static double steelC440B[N_C440B][4]={440,600,430,585,
									430,560,420,545,
									420,520,410,505,
									400,520,390,505,
									380,500,370,490
									};
static double tC440B[N_C440B+1]={1, 20, 30, 80, 100, 1000};
//------------------------------------------------------------------
// Параметры материала из табл. 4, ГОСТ 27772-2015, трубы
static double steelC235G[N_C235G][4]={235,360,230,350,
									  235,360,230,350};
static double tC235G[N_C235G+1]={2,3.9, 4};

static double steelC245G[N_C245G][4]={245,370,240,360,
									  235,370,230,360};
static double tC245G[N_C245G+1]={2, 3.9, 30};

static double steelC255G[N_C255G][4]={255,380,250,370,
									245,380,240,370,
									245,370,240,360,
									235,370,230,360};
static double tC255G[N_C255G+1]={2, 3.9, 10, 20, 40};

static double steelC345G[N_C345G][4]={345,490,335,480,
								345,490,335,480,
								325,470,315,460,
								305,460,300,450,
								285,450,280,440,
								275,440,270,430,
								265,430,260,420};
static double tC345G[N_C345G+1]={2, 3.9, 10, 20, 40, 60, 80, 160};

static double steelC345KG[N_C345KG][4]={345,470,340,460};
static double tC345KG[N_C345KG+1]={4,10};

static double steelC355G[N_C355G][4]={355,470,350,460,
									345,470,340,460,
									335,470,330,460,
									325,460,320,450,
									315,460,310,450,
									295,460,285,450};
static double tC355G[N_C355G+1]={8,16,40,60,80, 100, 160};

static double steelC355_1G[N_C355_1G][4]={355,470,350,460,
									345,470,340,460,
									335,470,330,460};
static double tC355_1G[N_C355_1G+1]={8,16,40,50};

static double steelC355KG[N_C355KG][4]={355,470,350,460,
									345,470,340,460,
									335,470,330,460};
static double tC355KG[N_C355KG+1]={8,16,40,50};

static double steelC355PG[N_C355PG][4]={355,470,350,460,
									345,470,340,460};
static double tC355PG[N_C355PG+1]={8,16,40};

static double steelC390G[N_C390G][4]={390,520,380,505};
static double tC390G[N_C390G+1]={8,50};

static double steelC390_1G[N_C390_1G][4]={390,520,380,505};
static double tC390_1G[N_C390_1G+1]={8,50};

static double steelC440G[N_C440G][4]={440,540,430,525};
static double tC440G[N_C440G+1]={8,50};

static double steelC550G[N_C550G][4]={540,640,525,625};
static double tC550G[N_C550G+1]={8, 50};

static double steelC590G[N_C590G][4]={590,685,575,670};
static double tC590G[N_C590G+1]={8, 40};
//---------------------------------------------------------------
// Фасон  ГОСТ 27772-2015
static double steelC245BG[N_C245BG][4]={ 245,370,240,360,
									   235,370,230,360};
static double tC245BG[N_C245BG+1]={4, 20, 40};

static double steelC255BG[N_C255BG][4]={ 255,380,250,370,
									   245,370,240,360,
									   235,370,230,360};
static double tC255BG[N_C255BG+1]={4, 10, 20, 40};

static double steelC345BG[N_C345BG][4]={345,480,335,470,
										325,470,315,460,
										305,460,300,450,
										};
static double tC345BG[N_C345BG+1]={4, 10, 20, 40};

static double steelC345KBG[N_C345KBG][4]={345,470,335,460};
static double tC345KBG[N_C345KBG+1]={4, 10};

static double steelC355BG[N_C355BG][4]={ 355,470,345,460,
									   345,470,335,460};

static double tC355BG[N_C355BG+1]={8, 16, 40};

static double steelC355_1BG[N_C355_1BG][4]={ 355,480,345,470,
										   345,480,335,470
									   };
static double tC355_1BG[N_C355_1BG+1]={8, 16, 40};

static double steelC390BG[N_C390BG][4]={390,520,380,505,
									  380,500,370,490,
									  370,490,360,480};
static double tC390BG[N_C390BG+1]={8, 10, 20, 40};

//-------------------------------------------------------------------------------
// Получить расчетное сопротивление растяжению, сжатию и изгибу по марке стали и толщине проката
double Steel_param_Ry(char *Msteel, double thick, int *rc, bool  flag_diag_thick) {
   STEEL_PARAM steel_param;

   *rc =  Steel_param(Msteel, thick, &steel_param, flag_diag_thick);
   if (*rc>0) {
	  return 0.0;
   }
   else
	  return steel_param.Ry;

}
//-------------------------------------------------------------------------------
// Получить временное сопротивление растяжению, сжатию и изгибу по марке стали и толщине проката
double Steel_param_Run(char *Msteel, double thick, int *rc, bool  flag_diag_thick) {
   STEEL_PARAM steel_param;

   *rc =  Steel_param(Msteel, thick, &steel_param, flag_diag_thick);
   if (*rc>0) {
	  return 0.0;
   }
   else
	  return steel_param.Run;

}
//-------------------------------------------------------------------------------
// Получить расчетное сопротивление растяжению, сжатию и изгибу по временному сопротивления - по марке стали и толщине проката
double Steel_param_Ru(char *Msteel, double thick, int *rc, bool  flag_diag_thick) {
   STEEL_PARAM steel_param;

   *rc =  Steel_param(Msteel, thick, &steel_param, flag_diag_thick);
   if (*rc>0) {
	  return 0.0;
   }
   else
	  return steel_param.Ru;

}
//--------------------------------------------------------------------------------
//  Получить нормативные и расчетные сопротивления по марке стали и толщине проката
int Steel_param(char *Msteel, double thick, STEEL_PARAM* steel_param, bool  flag_diag_thick) {
   MATER_PARAM mater_param;
   int i, rc;
   #ifdef EMBRAC
   String text;
   #else
   AnsiString text;
   #endif
   double thick_max;

   rc = Get_Mater_param(Msteel, &mater_param);
   if (rc>0) return rc;

   if (thick==0.0)
	  thick = mater_param.thick_row[0];

   rc = Get_steel_param(&mater_param, thick, steel_param);
   switch (rc) {
   case steel_T_UPPER:
		 thick_max = mater_param.thick_row[mater_param.n_row];
		 text="Толщина "+FloatToStrF(thick, ffFixed, 15, 1)+" мм превышает верхнюю границу "+
			   FloatToStrF(thick_max, ffFixed, 15, 0)+" мм для стали "+
			  (AnsiString)Msteel;
   break;
   case steel_T_UPPER_GLOB:
		 thick_max = mater_param.thick_row[mater_param.n_row];
		 text="Толщина "+FloatToStrF(thick, ffFixed, 15, 1)+" мм превышает верхнюю границу "+
			   FloatToStrF(thick_max, ffFixed, 15, 0)+" мм для стали "+
			  (AnsiString)Msteel;
   break;
   case steel_T_LESS:
		 text="Толщина листа "+FloatToStrF(thick, ffFixed, 15, 1)+" мм меньше нижней границы для стали "+
			  (AnsiString)Msteel;
   break;
   }
   if (rc > 1)
	 #ifdef EMBRAC
	 i=Application->MessageBox(text.c_str(), L"", MB_OK | MB_ICONERROR);
	 #else
	 i=Application->MessageBox(text.c_str(), "", MB_OK | MB_ICONERROR);
	 #endif
   else {
	 if (rc==steel_T_UPPER) {
	   if (flag_diag_thick) {
		 #ifdef EMBRAC
		 i=Application->MessageBox(text.c_str(), L"", MB_OK | MB_ICONERROR);
		 #else
		 i=Application->MessageBox(text.c_str(), "", MB_OK | MB_ICONERROR);
		 #endif
	   }
	   rc = 0;
	 }
	 strcpy(steel_param->title, Msteel);
   }

   return rc;
}
//--------------------------------------------------------------------------------
//  Получить таблицу свойств стали по марке стали
int Get_Mater_param(char *Msteel, MATER_PARAM* mater_param) {
   int i, rc;

   rc = steel_NO_STEEL;
   // Горячий прокат, трубы СП
   if (strcmp(Msteel,"C235")==0) {
	  Fill_mater_param(Msteel, N_C235, steelC235, tC235, mater_param);
	  rc = 0;
   }
   if (strcmp(Msteel,"C245")==0) {
	  Fill_mater_param(Msteel, N_C245, steelC245, tC245, mater_param);
	  rc = 0;
   }
   if (strcmp(Msteel,"C255")==0) {
	  Fill_mater_param(Msteel, N_C255, steelC255, tC255, mater_param);
	  rc = 0;
   }
   if (strcmp(Msteel,"C345")==0) {
	  Fill_mater_param(Msteel, N_C345, steelC345, tC345, mater_param);
	  rc = 0;
   }
   if (strcmp(Msteel,"C345K")==0) {
	  Fill_mater_param(Msteel, N_C345K, steelC345K, tC345K, mater_param);
	  rc = 0;
   }
   if (strcmp(Msteel,"C355")==0) {
	  Fill_mater_param(Msteel, N_C355, steelC355, tC355, mater_param);
	  rc = 0;
   }
   if (strcmp(Msteel,"C355-1")==0) {
	  Fill_mater_param(Msteel, N_C355_1, steelC355_1, tC355_1, mater_param);
	  rc = 0;
   }
   if (strcmp(Msteel,"C355-K")==0) {
	  Fill_mater_param(Msteel, N_C355_K, steelC355_K, tC355_K, mater_param);
	  rc = 0;
   }
   if (strcmp(Msteel,"C355П")==0) {
	  Fill_mater_param(Msteel, N_C355_P, steelC355_P, tC355_P, mater_param);
	  rc = 0;
   }
   if (strcmp(Msteel,"C390")==0) {
	  Fill_mater_param(Msteel, N_C390, steelC390, tC390, mater_param);
	  rc = 0;
   }
   if (strcmp(Msteel,"C390-1")==0) {
	  Fill_mater_param(Msteel, N_C390_1, steelC390_1, tC390_1, mater_param);
	  rc = 0;
   }
   if (strcmp(Msteel,"C440")==0) {
	  Fill_mater_param(Msteel, N_C440, steelC440, tC440, mater_param);
	  rc = 0;
   }
   if (strcmp(Msteel,"C550")==0) {
	  Fill_mater_param(Msteel, N_C550, steelC550, tC550, mater_param);
	  rc = 0;
   }
   if (strcmp(Msteel,"C590")==0) {
	  Fill_mater_param(Msteel, N_C590, steelC590, tC590, mater_param);
	  rc = 0;
   }
   if (strcmp(Msteel,"C690")==0) {
	  Fill_mater_param(Msteel, N_C690, steelC690, tC690, mater_param);
	  rc = 0;
   }
   // Горячий прокат, трубы ГОСТ
   if (strcmp(Msteel,"C235G")==0) {
	  Fill_mater_param(Msteel, N_C235G, steelC235G, tC235G, mater_param);
	  rc = 0;
   }
   if (strcmp(Msteel,"C245G")==0) {
	  Fill_mater_param(Msteel, N_C245G, steelC245G, tC245G, mater_param);
	  rc = 0;
   }
   if (strcmp(Msteel,"C255G")==0) {
	  Fill_mater_param(Msteel, N_C255G, steelC255G, tC255G, mater_param);
	  rc = 0;
   }
   if (strcmp(Msteel,"C345G")==0) {
	  Fill_mater_param(Msteel, N_C345G, steelC345G, tC345G, mater_param);
	  rc = 0;
   }
   if (strcmp(Msteel,"C345KG")==0) {
	  Fill_mater_param(Msteel, N_C345KG, steelC345KG, tC345KG, mater_param);
	  rc = 0;
   }
   if (strcmp(Msteel,"C355G")==0) {
	  Fill_mater_param(Msteel, N_C355G, steelC355G, tC355G, mater_param);
	  rc = 0;
   }
   if (strcmp(Msteel,"C355-1G")==0) {
	  Fill_mater_param(Msteel, N_C355_1G, steelC355_1G, tC355_1G, mater_param);
	  rc = 0;
   }
   if (strcmp(Msteel,"C355KG")==0) {
	  Fill_mater_param(Msteel, N_C355KG, steelC355KG, tC355KG, mater_param);
	  rc = 0;
   }
   if (strcmp(Msteel,"C355ПG")==0) {
	  Fill_mater_param(Msteel, N_C355PG, steelC355PG, tC355PG, mater_param);
	  rc = 0;
   }
   if (strcmp(Msteel,"C390G")==0) {
	  Fill_mater_param(Msteel, N_C390G, steelC390G, tC390G, mater_param);
	  rc = 0;
   }
   if (strcmp(Msteel,"C390-1G")==0) {
	  Fill_mater_param(Msteel, N_C390_1G, steelC390_1G, tC390_1G, mater_param);
	  rc = 0;
   }
   if (strcmp(Msteel,"C440G")==0) {
	  Fill_mater_param(Msteel, N_C440G, steelC440G, tC440G, mater_param);
	  rc = 0;
   }
   if (strcmp(Msteel,"C550G")==0) {
	  Fill_mater_param(Msteel, N_C550G, steelC550G, tC550G, mater_param);
	  rc = 0;
   }
   if (strcmp(Msteel,"C590G")==0) {
	  Fill_mater_param(Msteel, N_C590G, steelC590G, tC590G, mater_param);
	  rc = 0;
   }
   // Холоднокатанная сталь
   if (strcmp(Msteel,"220")==0) {
	  Fill_mater_param(Msteel, 2, steelC_220, tCold, mater_param);
	  rc = 0;
   }
   if (strcmp(Msteel,"ХП,ПК")==0) {
	  Fill_mater_param(Msteel, 2, steelC_HPPK, tCold, mater_param);
	  rc = 0;
   }
   if (strcmp(Msteel,"250")==0) {
	  Fill_mater_param(Msteel, 2, steelC_250, tCold, mater_param);
	  rc = 0;
   }
   if (strcmp(Msteel,"280")==0) {
	  Fill_mater_param(Msteel, 2, steelC_280, tCold, mater_param);
	  rc = 0;
   }
   if (strcmp(Msteel,"320")==0) {
	  Fill_mater_param(Msteel, 2, steelC_320, tCold, mater_param);
	  rc = 0;
   }
   if (strcmp(Msteel,"350")==0) {
	  Fill_mater_param(Msteel, 2, steelC_350, tCold, mater_param);
	  rc = 0;
   }
   //-----------------------------------------------------------------------------
   // Сталь для проката с параллельными гранями полок в соответствии с ГОСТ H 57837
   if (strcmp(Msteel,"C255Б")==0) {
	  Fill_mater_param(Msteel, N_C255B, steelC255B, tC255B, mater_param);
	  rc = 0;
   }
   if (strcmp(Msteel,"C255Б-1")==0) {
	  Fill_mater_param(Msteel, N_C255B, steelC255B, tC255B, mater_param);
	  rc = 0;
   }
   if (strcmp(Msteel,"C345Б")==0) {
	  Fill_mater_param(Msteel, N_C345B, steelC345B, tC345B, mater_param);
	  rc = 0;
   }
   if (strcmp(Msteel,"C345Б-1")==0) {
	  Fill_mater_param(Msteel, N_C345B_1, steelC345B_1, tC345B_1, mater_param);
	  rc = 0;
   }
   if (strcmp(Msteel,"C355Б")==0) {
	  Fill_mater_param(Msteel, N_C355B, steelC355B, tC355B, mater_param);
	  rc = 0;
   }
   if (strcmp(Msteel,"C355Б-1")==0) {
	  Fill_mater_param(Msteel, N_C355B_1, steelC355B_1, tC355B_1, mater_param);
	  rc = 0;
   }
   if (strcmp(Msteel,"C390Б")==0) {
	  Fill_mater_param(Msteel, N_C390B, steelC390B, tC390B, mater_param);
	  rc = 0;
   }
   if (strcmp(Msteel,"C440Б")==0) {
	  Fill_mater_param(Msteel, N_C440B, steelC440B, tC440B, mater_param);
	  rc = 0;
   }
   //-----------------------------------------------------------------------------
   // Сталь для проката с параллельными гранями полок в соответствии с ГОСТ 27772-15
   if (strcmp(Msteel,"C245BG")==0) {
	  Fill_mater_param(Msteel, N_C245BG, steelC245BG, tC245BG, mater_param);
	  rc = 0;
   }
   if (strcmp(Msteel,"C255BG")==0) {
	  Fill_mater_param(Msteel, N_C255BG, steelC255BG, tC255BG, mater_param);
	  rc = 0;
   }
   if (strcmp(Msteel,"C345BG")==0) {
	  Fill_mater_param(Msteel, N_C345, steelC345, tC345, mater_param);
	  rc = 0;
   }
   if (strcmp(Msteel,"C345KBG")==0) {
	  Fill_mater_param(Msteel, N_C345KBG, steelC345KBG, tC345KBG, mater_param);
	  rc = 0;
   }
   if (strcmp(Msteel,"C355BG")==0) {
	  Fill_mater_param(Msteel, N_C355BG, steelC355BG, tC355BG, mater_param);
	  rc = 0;
   }
   if (strcmp(Msteel,"C355-1BG")==0) {
	  Fill_mater_param(Msteel, N_C355_1BG, steelC355_1BG, tC355_1BG, mater_param);
	  rc = 0;
   }
   if (strcmp(Msteel,"C390BG")==0) {
	  Fill_mater_param(Msteel, N_C390BG, steelC390BG, tC390BG, mater_param);
	  rc = 0;
   }
   //-------------------------------------------------------------------
   if (rc != 0) {
	   rc = steel_NO_STEEL;
   }
   return rc;
}
//-------------------------------------------------------------
// Получить нормативные и расчетные сопротивления по марке стали и толщине проката
// с использованием таблицы материала
int Get_steel_param(MATER_PARAM *mater_param, double thick, STEEL_PARAM* steel_param) {
   int i;

   if (mater_param->thick_row[0] > thick)
	  return steel_T_LESS;

   for (i=0; i<=mater_param->n_row; i++) {
	 if (mater_param->thick_row[i] >= thick)
		break;
   }
   if (i > mater_param->n_row)
	 return steel_T_UPPER_GLOB;
   if (mater_param->thick_row[0] < thick)
	  i--;
   strcpy(steel_param->title, mater_param->title);
   steel_param->thick = thick;
   steel_param->Ryn = mater_param->Ryn_row[i];
   steel_param->Run = mater_param->Run_row[i];
   steel_param->Ry = mater_param->Ry_row[i];
   steel_param->Ru = mater_param->Ru_row[i];
   if (i == mater_param->n_row)
	 return steel_T_UPPER;
   return 0;
}
//-------------------------------------------------------------
// Заполнить таблицу материала
void Fill_mater_param(char* Msteel, int n_thick, double steel[][4], double *row_t, MATER_PARAM* mater_param) {
   int i;

   for (i=0; i<=n_thick; i++) {
	   mater_param->thick_row[i]= row_t[i];
   }
   for (i=0; i<n_thick; i++) {
	   mater_param->Ryn_row[i]= steel[i][0];
	   mater_param->Run_row[i]= steel[i][1];
	   mater_param->Ry_row[i]= steel[i][2];
	   mater_param->Ru_row[i]= steel[i][3];
   }
   mater_param->n_row= n_thick;
   strcpy(mater_param->title, Msteel);
}
//-------------------------------------------------------------
// Получить диапазон толщин, в который попадает заданная толщина
int Get_thick_range(char *Msteel, double thick, double *thick_range) {
	MATER_PARAM mater_param;

	int i;

	int rc = Get_Mater_param(Msteel, &mater_param);
	if (rc>0) return rc;

	if (thick < mater_param.thick_row[0]) {   // Толщина меньше первого значения диапазона - материал неприменим
	   return 1;
	}
	if (thick > mater_param.thick_row[mater_param.n_row]) {   // Толщина больше последнего значения диапазона - материал неприменим
	   return 2;
	}
	for (i = 0; i < mater_param.n_row + 1; i++) {
	  if (thick <= mater_param.thick_row[i])
		 break;
	}
	if (thick == mater_param.thick_row[i]) {
	  thick_range[0] = mater_param.thick_row[i];
	  thick_range[1] = mater_param.thick_row[i+1];
	}
	else {
	  thick_range[0] = mater_param.thick_row[i-1];
	  thick_range[1] = mater_param.thick_row[i];
	}
	return 0;
}


