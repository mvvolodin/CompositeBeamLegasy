  #include "DrawEpurMain.h"
  #include "pCanvas_func.h"
//---------------------------------------------------------------------------
  /*  функция ABS  */
#define ABS(x) (((x)<0) ? -(x):(x))
#define _ABS(x) (((x)<0) ? -(x):(x))
  /*  функция MIN  */
#define MIN(x,y)  (((x)<(y)) ? (x):(y))
  /*  функция MAX  */
#define MAX(x,y)  (((x)>(y)) ? (x):(y))
#define SIGN(x)  (((x)==0) ? 0 : ((x)>0) ? 1:-1)
//-------------------------------------------------------------
int DrawEpur(TImage *Image1, int n_point, double *coor_epur, double *LoadA, double *LoadB,
			  int n_supp, double *coor_supp, bool flag_sign,
			  int num_digits, bool con_sign_practice)
// Image1 - Контейнер изображения
// n_point - число точек эпюры
// coord_epur - вектор координат эпюры
// LoadA - вектор значений нагрузки
// LoadB - вектор скачков на эпюре
// n_supp - число опор
// coord_supp - вектор координат опор
// flag_sign - флаг вывода значений эпюры
// num_digits -  количество знаков после запятой значений, отображаемых на эпюре
// con_sign_practice - (true - правило знаков согласно строительной практики)
{
  float scale, scale_force, scale_kp, scale_q, scale_m, scale_N, Value;
  int i;
  double Width, Height;
  double H_beam, B_beam, L_beam;
  TPoint points[10];
  TPoint vert[10];
  double zero_px, zero_py;
  double load_cur; // текущее значение нагрузки
  double load_gap; // значение скачка в нагрузке
  double mult;
  #define  INTR  120

// Определить масштаб для рисования балки
  Width = Image1->Width;
  Height = Image1->Height;
  //con_sign_practice=true;

  if (con_sign_practice) {
	 mult = -1;
  }
  else {
	 mult = 1;
  }

  L_beam = coor_epur[n_point-1] - coor_epur[0];
  if (L_beam <=0)
	return 1;

  H_beam = L_beam/50;
  scale = (Width - INTR)/L_beam;

  //---------------------------------------------------
  Value = 0;
  for (i=0; i < n_point; i++) {
	  Value = MAX(Value, (ABS(LoadA[i])));
	  // Value = MAX(Value, (ABS(LoadB[i])));
	  if (LoadB!=nullptr)
		 Value = MAX(Value, (ABS(LoadB[i])));
  }
  if (Value!=0)
	 scale_force = (Height - 50)/(2*Value);
  else
	 scale_force = 0;
  //---------------------------------------------------
  //---------------------------------------------------

  TRect NewRect = Rect(0, 0, Width, Height);

  pBrush_Color(Image1, clWhite);
  pCanvas_FillRect(Image1, NewRect);
  // Координаты левой точки балки
  zero_px = 0.5*INTR;
  zero_py = Height/2;
  // Рисование балки
  pBrush_Color(Image1, clSilver);
  pPen_Color(Image1, clBlack);
  for (i=0; i<1; i++) {
	points[0] = Point(zero_px, zero_py - H_beam*scale/2);
	points[1] = Point(points[0].x, zero_py + H_beam*scale/2);
	points[2] = Point(points[0].x + L_beam*scale, zero_py + H_beam*scale/2);
	points[3] = Point(points[2].x, zero_py - H_beam*scale/2);
	points[4] = points[0];
	pCanvas_Polygon(Image1, points, 4);
  }

  // Ось балки
  pBrush_Color(Image1, clWhite);
  points[0] = Point(zero_px, zero_py);
  points[1] = Point(points[0].x + L_beam*scale, zero_py);
  pCanvas_Polyline(Image1, points, 1);
  pPen_Color(Image1, clBlack);

  //------------------------------------------------------------------------------------------------------
  // Рисование эпюры
  pBrush_Color(Image1, clWhite);
  pBrush_Style(Image1, bsSolid);

  double load_max = 1e-9;
  double load_min = 1e9;
  int i_max, i_min;

  load_cur = mult*LoadA[0];
  for (i=0; i<n_point-1; i++) {
	if (load_max < mult*LoadA[i]) {
	  i_max = i;
	  load_max = mult*LoadA[i];
	}
	if (load_min > mult*LoadA[i]) {
	  i_min = i;
	  load_min = mult*LoadA[i];
	}
	points[0] = Point(zero_px + coor_epur[i]*scale, zero_py - load_cur*scale_force);
	points[1] = Point(zero_px + coor_epur[i+1]*scale, zero_py - mult*LoadA[i+1]*scale_force);
	pPen_Width(Image1, 2);
	pCanvas_Polyline(Image1, points, 1);
  //	load_cur = LoadA[i+1] + LoadB[i+1];
	if (LoadB!=nullptr)
	  load_gap = LoadB[i+1];
	else
	  load_gap = 0;
	load_cur = mult*(LoadA[i+1] + load_gap);
   //	if (LoadB[i+1]!=0)
	if(load_gap!=0)
	{
	  if (load_max < load_cur) {
		i_max = i+1;
		load_max = load_cur;
	  }
	  if (load_min > load_cur) {
		i_min = i+1;
		load_min = load_cur;
	  }
	  points[0] = Point(zero_px + coor_epur[i+1]*scale, zero_py - mult*LoadA[i+1]*scale_force);
	  points[1] = Point(zero_px + coor_epur[i+1]*scale, zero_py - load_cur*scale_force);
	  pPen_Width(Image1, 1);
	  pCanvas_Polyline(Image1, points, 1);
	}
  }
  if (load_max < mult*LoadA[i]) {
	  i_max = i;
	  load_max = mult*LoadA[i];
  }
  if (load_min > mult*LoadA[i]) {
	  i_min = i;
	  load_min = mult*LoadA[i];
  }

  //------------------------------------------------------------------------------------------------------
  // Крайние точки эпюр
  pPen_Width(Image1, 1);
  points[0] = Point(zero_px + coor_epur[0]*scale, zero_py);
  points[1] = Point(zero_px + coor_epur[0]*scale, zero_py - mult*LoadA[0]*scale_force);
  pCanvas_Polyline(Image1, points, 1);
  points[0] = Point(zero_px + coor_epur[n_point-1]*scale, zero_py);
  points[1] = Point(zero_px + coor_epur[n_point-1]*scale, zero_py - mult*LoadA[n_point-1]*scale_force);
  pCanvas_Polyline(Image1, points, 1);

  // Вывести значение нагрузок
  if (flag_sign) {

	if (load_max!=1e-9 && load_max!=0) {
		points[1] = Point(zero_px + coor_epur[i_max]*scale, zero_py - mult*LoadA[i_max]*scale_force);
		pCanvas_TextOut(Image1, points[1].x+2, points[1].y+2, FloatToStrF(LoadA[i_max], ffFixed, 10, num_digits));
		pCanvas_Ellipse(Image1, points[1].x - 3, points[1].y - 3, points[1].x + 3, points[1].y + 3);

		if (LoadB!=nullptr) {
		  points[1] = Point(zero_px + coor_epur[i_max]*scale, zero_py -
					 mult*(LoadA[i_max] + LoadB[i_max])*scale_force);
		  pCanvas_Ellipse(Image1, points[1].x - 3, points[1].y - 3, points[1].x + 3, points[1].y + 3);
		  pCanvas_TextOut(Image1, points[1].x+2, points[1].y+2, FloatToStrF(LoadA[i_max] + LoadB[i_max], ffFixed, 10, num_digits));
		}

	}
  }
  if (load_min!=1e9 && load_min!=0) {
		points[1] = Point(zero_px + coor_epur[i_min]*scale, zero_py - mult*LoadA[i_min]*scale_force);
		pCanvas_TextOut(Image1, points[1].x+2, points[1].y+2, FloatToStrF(LoadA[i_min], ffFixed, 10, num_digits));
		pCanvas_Ellipse(Image1, points[1].x - 3, points[1].y - 3, points[1].x + 3, points[1].y + 3);

		if (LoadB!=nullptr) {
		  points[1] = Point(zero_px + coor_epur[i_min]*scale, zero_py -
					  mult*(LoadA[i_min] + LoadB[i_min])*scale_force);
		  pCanvas_Ellipse(Image1, points[1].x - 3, points[1].y - 3, points[1].x + 3, points[1].y + 3);
		  pCanvas_TextOut(Image1, points[1].x+2, points[1].y+2, FloatToStrF(LoadA[i_min] + LoadB[i_min], ffFixed, 10, num_digits));
		}



  }
  //-------------------------------------------------------------------------------
  // Рисование опор
  pBrush_Style(Image1, bsSolid);
  for (i=0; i<n_supp; i++) {
	 points[0] = Point(zero_px + coor_supp[i]*scale, zero_py + H_beam*scale/2);
	 points[1] = Point(points[0].x, points[0].y + 20);
	 pPen_Width(Image1, 2);
	 pCanvas_Polyline(Image1, points, 1);
	 pPen_Width(Image1, 1);
	 pCanvas_Ellipse(Image1, points[0].x - 3, points[0].y - 3, points[0].x + 3, points[0].y + 3);
	 pCanvas_Ellipse(Image1, points[1].x - 3, points[1].y - 3, points[1].x + 3, points[1].y + 3);
	   // Штриховка
	 vert[0] = Point(points[1].x - 10, points[1].y + 3);
	 vert[1] = Point(points[1].x + 10, points[1].y + 3);
	 pCanvas_Polyline(Image1, vert, 1);
	 Shtrih(Image1, vert, 4.0, 1.0, 1.0);

  }
    //отрисовка левой горизонтальной опоры
	points[0] = Point(zero_px - 3, zero_py + H_beam*scale/2);
	points[1] = Point(points[0].x - 20, points[0].y);
	pPen_Width(Image1, 2);
	pCanvas_Polyline(Image1, points, 1);
	pPen_Width(Image1, 1);
	pCanvas_Ellipse(Image1, points[1].x - 3, points[1].y - 3, points[1].x + 3, points[1].y + 3);
	vert[0] = Point(points[1].x - 3, points[1].y - 10);
	vert[1] = Point(points[1].x - 3, points[1].y + 10);
	pCanvas_Polyline(Image1, vert, 1);
	Shtrih(Image1, vert, 4.0, -1.0, 1.0);


  return 0;
}
//---------------------------------------------------------------------------------
// Штриховка
void Shtrih(TImage * Image1, TPoint *points, float s_s, float mx, float my) {
	// points - точки линии
	// s_s - шаг штриховки
	// mx, my: +1 или -1  - множители, определяющие направление штриховки
	float delx, dely;
	int k;
	TPoint vert[2];
	float l_s;

	delx = points[1].x - points[0].x;
	dely = points[1].y - points[0].y;
    l_s = sqrt(delx*delx + dely*dely);

    for (k=0; k < l_s; k += s_s) {
      vert[0] = Point(points[0].x + delx*k/l_s, points[0].y + dely*k/l_s);
	  vert[1] = Point(vert[0].x + mx*s_s, vert[0].y + my*s_s);
	  pCanvas_Polygon(Image1, vert, 1);
    }
}

