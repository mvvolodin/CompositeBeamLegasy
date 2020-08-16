//---------------------------------------------------------------------------

#ifndef pCanvas_funcH
#define pCanvas_funcH
//---------------------------------------------------------------------------
#define orHORIZ    0
#define orVERT     1
#define sideUP    -1
#define sideDOWN   1
#define sideLEFT  -1
#define sideRIGHT  1
  /*  функция ABS  */
#define ABS(x) (((x)<0) ? -(x):(x))
#define _ABS(x) (((x)<0) ? -(x):(x))
  /*  функция MIN  */
#define MIN(x,y)  (((x)<(y)) ? (x):(y))
  /*  функция MAX  */
#define MAX(x,y)  (((x)>(y)) ? (x):(y))
#define SIGN(x)  (((x)==0) ? 0 : ((x)>0) ? 1:-1)



TColor get_pBrush_Color(TImage *Image1);
TColor get_pBrush_Color(TImage *Image1);
TColor get_pPen_Color(TImage *Image1);
TPenStyle Get_pPen_Style(TImage *Image1);
void pFont_Size(TImage *Image1, int size);
void pBrush_Color(TImage *Image1, TColor color);
void pPen_Color(TImage *Image1, TColor color);
void pPen_Width(TImage *Image1, int width);
void pBrush_Style(TImage *Image1, TBrushStyle style);
void pPen_Style(TImage *Image1, TPenStyle style);
void pFont_Color(TImage *Image1, TColor color);
void pCanvas_FillRect(TImage *Image1, TRect NewRect);
void pCanvas_Polygon(TImage *Image1, TPoint *points, int n);
void pCanvas_Polygon_rW(TImage *Image1, TPoint *points, int n, int W);
void pCanvas_Arc(TImage *Image1, TPoint *point_a, TPoint *point_c);
void pCanvas_Polyline(TImage *Image1, TPoint *points, int n);
void pCanvas_Polyline_rW(TImage *Image1, TPoint *points, int n, int W);
void pCanvas_MoveTo(TImage *Image1, int ix, int iy);
void pCanvas_LineTo(TImage *Image1, int ix, int iy);
void pCanvas_TextOut(TImage *Image1, int nx, int ny, AnsiString str);
void pCanvas_Ellipse(TImage *Image1, int ix_1, int iy_1, int ix_2, int iy_2);
void pCanvas_Chord(TImage *Image1, int ix_1, int iy_1, int ix_2, int iy_2, int x_1, int y_1, int x_2, int y_2);
void pCanvas_Ellipse_rW(TImage *Image1, int ix_1, int iy_1, int ix_2, int iy_2, int W);
void pCanvas_Rectangle(TImage *Image1, int x1, int y1, int x2, int y2);
void pCanvas_Dim(TImage *Image1, TPoint Point0, TPoint Point1, int orient, int side, double size, int n_ff);
void pCanvas_Dim_rW(TImage *Image1, TPoint Point0, TPoint Point1, int orient, int side, double size, int n_ff, int W);
void pCanvas_Dim_v(TImage *Image1, TPoint Point0, TPoint Point1, int orient, int side, double size, int n_ff, int vynos, int level);
void pCanvas_Dim_v_rW(TImage *Image1, TPoint Point0, TPoint Point1, int orient, int side, double size, int n_ff, int vynos, int level, int W);
void pCanvas_Dim_h(TImage *Image1, TPoint Point0, TPoint Point1, int orient, int side, double size, int n_ff, int vynos, int level, int pos);
void pCanvas_Dim_vt(TImage *Image1, TPoint Point0, TPoint Point1, int orient, int side, AnsiString Str_size,
                 int vynos, int level, int posX, int posY);
#endif
