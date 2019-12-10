//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "pCanvas_func.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)
TColor  InversColor(TColor color);
void drawLineWu(float x1, float y1, float x2, float y2, TCanvas *Canvas, TColor color, TColor color_b1, TColor color_b2);

TColor ChangeBright(TColor color_a, TColor color_b, float bright);

static bool flag_image = true; //Если false, то отрисовка идёт в мета файле .Картинку можно потом вставить, к примеру, в Word
static TMetafileCanvas *pCanvas;
//---------------------------------------------------------------------
TColor get_pBrush_Color(TImage *Image1) {
	  if (flag_image) {
		 return (Image1->Canvas->Brush->Color);
	  }
	  else {
		 //return(InversColor(pCanvas->Brush->Color));
		 return(pCanvas->Brush->Color);
	  }
}
//---------------------------------------------------------------------
TColor get_pPen_Color(TImage *Image1) {
	  if (flag_image) {
		 return (Image1->Canvas->Pen->Color);
      }
      else {
         //return(InversColor(pCanvas->Pen->Color));
         return(pCanvas->Pen->Color);
      }
}
//---------------------------------------------------------------------
void pFont_Size(TImage *Image1, int size) {
      if (flag_image) {
         Image1->Canvas->Font->Size = size;
      }
      else {
         pCanvas->Font->Size = size;
      }
}
//---------------------------------------------------------------------
void pBrush_Color(TImage *Image1, TColor color) {
      if (flag_image) {
         Image1->Canvas->Brush->Color = color;
      }
      else {
         //pCanvas->Brush->Color = InversColor(color);
         pCanvas->Brush->Color = color;
      }
}
//---------------------------------------------------------------------
void pPen_Color(TImage *Image1, TColor color) {
      if (flag_image) {
         Image1->Canvas->Pen->Color = color;
      }
      else {
         //pCanvas->Pen->Color = InversColor(color);
         pCanvas->Pen->Color = color;
      }
}
//---------------------------------------------------------------------
void pPen_Width(TImage *Image1, int width) {
      if (flag_image) {
         Image1->Canvas->Pen->Width = width;
      }
      else {
         pCanvas->Pen->Width = width;
      }
}
//---------------------------------------------------------------------
void pBrush_Style(TImage *Image1, TBrushStyle style) {
      if (flag_image) {
         Image1->Canvas->Brush->Style = style;
      }
      else {
         pCanvas->Brush->Style = style;
      }
}
//---------------------------------------------------------------------
TPenStyle Get_pPen_Style(TImage *Image1) {
      if (flag_image) {
         return (Image1->Canvas->Pen->Style);
      }
      else {
         return (pCanvas->Pen->Style);
      }
}
//---------------------------------------------------------------------
void pPen_Style(TImage *Image1, TPenStyle style) {
      if (flag_image) {
         Image1->Canvas->Pen->Style = style;
      }
      else {
         pCanvas->Pen->Style = style;
      }
}
//---------------------------------------------------------------------
void pFont_Color(TImage *Image1, TColor color) {
      if (flag_image) {
         Image1->Canvas->Font->Color = color;
      }
      else {
         if (color==0x00000000)   // инверсия черного цвета
			;// color=0x00FFFFFF;
         else {
           if (color==0x00FFFFFF) // инверсия белого цвета
			;//  color=0x00000000;
         }
         pCanvas->Font->Color = color;
      }
}
//----------------------------------------------------------------------
void pCanvas_Rectangle(TImage *Image1, int x1, int y1, int x2, int y2) {
    TPoint points[5];

    points[0] = Point(x1, y1);
    points[1] = Point(x1, y2);
    points[2] = Point(x2, y2);
    points[3] = Point(x2, y1);
    points[4] = Point(x1, y1);

    pCanvas_Polygon(Image1, points, 4);

    /*
      if (flag_image) {
         Image1->Canvas->Rectangle(x1, y1, x2, y2);
      }
      else {
         pCanvas->Rectangle(x1, y1, x2, y2);
      }
    */
}
//----------------------------------------------------------------------
void pCanvas_FillRect(TImage *Image1, TRect NewRect) {
      if (flag_image) {
         Image1->Canvas->FillRect(NewRect);
      }
      else {
         pCanvas->FillRect(NewRect);
      }
}
//----------------------------------------------------------------------
// Рисование полиuгона, зеркально отраженного относительно вертикальной оси
void pCanvas_Polygon_rW(TImage *Image1, TPoint *points, int n, int Width) {
   TPoint point_n[100];
   int i, k;
   
   k = MIN(100, n+1);
   for (i=0; i<k; i++) {
     point_n[i]=Point(Width - points[i].x, points[i].y);
   }
   pCanvas_Polygon(Image1, point_n, k-1);
}
//----------------------------------------------------------------------
void pCanvas_Polygon_Wu(TImage *Image1, TPoint *points, int n) {
    TColor color_l = get_pPen_Color(Image1);
    TColor color_b1 = clWhite;
    //TColor color_b1 = ViewOptionsForm->OptColor(0, colorWINDOW);;
    TColor color_b2 = get_pBrush_Color(Image1);
    TColor color_l0 = ChangeBright(color_l, color_b1, 0.75);;
    int i;
      if (flag_image) {
        Image1->Canvas->Polygon(points, n);
        for (i=0; i<n; i++) {
          drawLineWu((float)points[i].x, (float)points[i].y, (float)points[i+1].x, (float)points[i+1].y, Image1->Canvas,
                      color_l0, color_b1, color_b2);
        }
      }
      else {
        pCanvas->Polygon(points, n);
        for (i=0; i<n; i++) {
          drawLineWu((float)points[i].x, (float)points[i].y, (float)points[i+1].x, (float)points[i+1].y, pCanvas,
                      color_l0, color_b1, color_b2);
        }
      }
}
//----------------------------------------------------------------------
void pCanvas_Polygon(TImage *Image1, TPoint *points, int n) {
      if (flag_image) {
        Image1->Canvas->Polygon(points, n);
      }
      else {
        pCanvas->Polygon(points, n);
      }
}
//----------------------------------------------------------------------
void pCanvas_Arc(TImage *Image1, TPoint *point_a, TPoint *point_c) {
      if (flag_image) {
         Image1->Canvas->Arc(point_c[0].x, point_c[0].y, point_c[1].x, point_c[1].y,
                             point_a[0].x, point_a[0].y, point_a[1].x, point_a[1].y);
      }
      else {
         pCanvas->Arc(point_c[0].x, point_c[0].y, point_c[1].x, point_c[1].y,
                             point_a[0].x, point_a[0].y, point_a[1].x, point_a[1].y);
      }
}
//----------------------------------------------------------------------
// Рисование полилинии, зеркально отраженной относительно вертикальной оси
void pCanvas_Polyline_rW(TImage *Image1, TPoint *points, int n, int Width) {
   TPoint point_n[100];
   int i, k;

   k=MIN(100, n+1);
   for (i=0; i<k; i++) {
     point_n[i] = Point(Width - points[i].x, points[i].y);
   }
   pCanvas_Polyline(Image1, point_n, k-1);
}
//----------------------------------------------------------------------
void pCanvas_Polyline(TImage *Image1, TPoint *points, int n) {
      int i,k;
      for (i=0; i<n; i++) {
        if (points[i].x==0) {
          k=0;
        }
      }
      if (flag_image) {
         Image1->Canvas->Polyline(points, n);
      }
      else {
         pCanvas->Polyline(points, n);
      }
}
//---------------------------------------------------------------------
void pCanvas_MoveTo(TImage *Image1, int ix, int iy) {
    if (flag_image) {
      Image1->Canvas->MoveTo(ix,iy);
    }
    else {
      pCanvas->MoveTo(ix,iy);
    }
}
//---------------------------------------------------------------------
void pCanvas_LineTo(TImage *Image1, int ix, int iy) {
    if (flag_image) {
      Image1->Canvas->LineTo(ix,iy);
    }
    else {
      pCanvas->LineTo(ix,iy);
    }
}
//---------------------------------------------------------------------
void pCanvas_TextOut(TImage *Image1, int nx, int ny, AnsiString str) {
    int i, size;
    AnsiString name;
    TFontPitch pitch;

    if (flag_image) {
      Image1->Canvas->Font->Charset = RUSSIAN_CHARSET;
      Image1->Canvas->TextOut(nx, ny, str);
    }
    else {
      pCanvas->Font->Charset = RUSSIAN_CHARSET;
      pCanvas->Font->Style = TFontStyles()<<fsItalic;
      pCanvas->TextOut(nx, ny, str);
    }
}
//---------------------------------------------------------------------
void pCanvas_Ellipse_rW(TImage *Image1, int ix_1, int iy_1, int ix_2, int iy_2, int Width) {
    pCanvas_Ellipse(Image1, Width - ix_1, iy_1, Width - ix_2, iy_2);
}
//---------------------------------------------------------------------
void pCanvas_Ellipse(TImage *Image1, int ix_1, int iy_1, int ix_2, int iy_2) {
    if (flag_image) {
      Image1->Canvas->Ellipse(ix_1, iy_1, ix_2, iy_2);
    }
    else {
      pCanvas->Ellipse(ix_1, iy_1, ix_2, iy_2);
    }
}
//--------------------------------------------------------------------
void pCanvas_Chord(TImage *Image1, int ix_1, int iy_1, int ix_2, int iy_2, int x_1, int y_1, int x_2, int y_2) {
	if (flag_image) {
	  Image1->Canvas->Chord(ix_1, iy_1, ix_2, iy_2, x_1, y_1, x_2, y_2);
	}
	else {
	  pCanvas->Chord(ix_1, iy_1, ix_2, iy_2, x_1, y_1, x_2, y_2);
	}
}
//---------------------------------------------------------------------------
//  Рисование размеров с выносом, уровнем вложенности, регулировкой привязки числа
void pCanvas_Dim_h(TImage *Image1, TPoint Point0, TPoint Point1, int orient, int side, double size, int n_ff,
                 int vynos, int level, int pos) {

    // n_ff - число знаков после точки в изображении числового значения размера
    TPoint Pointv1[2];
    TPoint Pointv2[2];
    TPoint Points[2];
    int nx, ny;
    int dist, add_x;
    AnsiString Str_size;

    dist = 20*level + vynos;  // Расстояние от точек до размера
    Str_size = FloatToStrF(size, ffFixed, 6, n_ff);

    if (orient == orHORIZ) {
        Pointv1[0]=Point0;
        Pointv1[1]=Point0;
        Pointv1[1].y += side*dist;

        Pointv2[0]=Point1;
        Pointv2[1]=Point1;
        Pointv2[1].y += side*dist;

        Points[0]=Pointv1[1];
        Points[1]=Pointv2[1];

        Points[0].y -= side*4;
        Points[1].y -= side*4;
        if (Str_size.Length() > 2) {
          add_x = 10;
        }
        else
          add_x = 5;
        nx = (Points[0].x + Points[1].x)*0.5 - add_x;
        ny = (Points[0].y + Points[1].y)*0.5 - 14;
    }
    else {
        Pointv1[0]=Point0;
        Pointv1[1]=Point0;
        Pointv1[1].x += side*(dist + 5);

        Pointv2[0]=Point1;
        Pointv2[1]=Point1;
        Pointv2[1].x += side*(dist + 5);

        Points[0]=Pointv1[1];
        Points[1]=Pointv2[1];

        Points[0].x -= side*4;
        Points[1].x -= side*4;
        if (side <0) add_x = -12;
        else add_x = 3;
        nx = (Points[0].x + Points[1].x)*0.5 + add_x;
        ny = (Points[0].y + Points[1].y)*0.5 - 5 + (level-1)*6 + pos;
    }
    // Выносные линии
    pCanvas_Polyline(Image1, Pointv1, 1);
    pCanvas_Polyline(Image1, Pointv2, 1);
    // Размерная линия
    pCanvas_Polyline(Image1, Points, 1);
    Pointv1[0] = Points[0];
    Pointv1[1] = Points[0];
    // Засечки
    Pointv1[0].x += 4;
    Pointv1[0].y -= 4;
    Pointv1[1].x -= 4;
    Pointv1[1].y += 4;
    pCanvas_Polyline(Image1, Pointv1, 1);

    Pointv1[0] = Points[1];
    Pointv1[1] = Points[1];

    Pointv1[0].x += 4;
    Pointv1[0].y -= 4;
    Pointv1[1].x -= 4;
    Pointv1[1].y += 4;

    pCanvas_Polyline(Image1, Pointv1, 1);
    // Размер
    pCanvas_TextOut(Image1, nx, ny, Str_size);
}
//---------------------------------------------------------------------------
//  Рисование размеров с выносом и уровнем вложенности
void pCanvas_Dim_v_rW(TImage *Image1, TPoint Point0, TPoint Point1, int orient, int side, double size, int n_ff,
                 int vynos, int level, int Width) {
    TPoint Point0_r;
    TPoint Point1_r;
    int i, side_n;

    if (orient==orVERT) {
      if (side==sideLEFT)
         side_n = sideRIGHT;
      else
         side_n = sideLEFT;
    }
    else
      side_n = side;

    Point0_r = Point(Width - Point0.x, Point0.y);
    Point1_r = Point(Width - Point1.x, Point1.y);
    pCanvas_Dim_v(Image1, Point0_r, Point1_r, orient, side_n, size, n_ff,
                 vynos, level);
}
//---------------------------------------------------------------------------
//  Рисование размеров с выносом и уровнем вложенности
void pCanvas_Dim_v(TImage *Image1, TPoint Point0, TPoint Point1, int orient, int side, double size, int n_ff,
                 int vynos, int level) {
     AnsiString Str_size = FloatToStrF(size, ffFixed, 6, n_ff);
     pCanvas_Dim_vt(Image1, Point0, Point1, orient, side, Str_size, vynos, level, 0, 0);

}
//---------------------------------------------------------------------------
//  Рисование размеров с выносом и уровнем вложенности
void pCanvas_Dim_vt(TImage *Image1, TPoint Point0, TPoint Point1, int orient, int side, AnsiString Str_size,
                 int vynos, int level, int posX, int posY) {

    // n_ff - число знаков после точки в изображении числового значения размера
    TPoint Pointv1[2];
    TPoint Pointv2[2];
    TPoint Points[2];
    int nx, ny;
    int dist, add_x;

    dist = 20*level + vynos;  // Расстояние от точек до размера

    if (orient == orHORIZ) {
        Pointv1[0]=Point0;
        Pointv1[1]=Point0;
        Pointv1[1].y += side*dist;

        Pointv2[0]=Point1;
        Pointv2[1]=Point1;
        Pointv2[1].y += side*dist;

        Points[0]=Pointv1[1];
        Points[1]=Pointv2[1];

        Points[0].y -= side*4;
        Points[1].y -= side*4;
        if (Str_size.Length() > 2) {
          add_x = 10;
        }
        else
          add_x = 5;
        nx = (Points[0].x + Points[1].x)*0.5 - add_x + posX;
        ny = (Points[0].y + Points[1].y)*0.5 - 14 + posY;
    }
    else {
        Pointv1[0]=Point0;
        Pointv1[1]=Point0;
        Pointv1[1].x += side*(dist + 5);

        Pointv2[0]=Point1;
        Pointv2[1]=Point1;
        Pointv2[1].x += side*(dist + 5);

        Points[0]=Pointv1[1];
        Points[1]=Pointv2[1];

        Points[0].x -= side*4;
        Points[1].x -= side*4;
        if (side <0) add_x = -12;
        else add_x = 3;
        nx = (Points[0].x + Points[1].x)*0.5 + add_x + posX;
        ny = (Points[0].y + Points[1].y)*0.5 - 5 + (level-1)*6 + posY;
    }
    // Выносные линии
    pCanvas_Polyline(Image1, Pointv1, 1);
    pCanvas_Polyline(Image1, Pointv2, 1);
    // Размерная линия
    pCanvas_Polyline(Image1, Points, 1);
    Pointv1[0] = Points[0];
    Pointv1[1] = Points[0];
    // Засечки
    Pointv1[0].x += 3;
    Pointv1[0].y -= 3;
    Pointv1[1].x -= 3;
    Pointv1[1].y += 3;
    pCanvas_Polyline(Image1, Pointv1, 1);

    Pointv1[0] = Points[1];
    Pointv1[1] = Points[1];

    Pointv1[0].x += 3;
    Pointv1[0].y -= 3;
    Pointv1[1].x -= 3;
    Pointv1[1].y += 3;

    pCanvas_Polyline(Image1, Pointv1, 1);
    // Размер
    pCanvas_TextOut(Image1, nx, ny, Str_size);
}
//---------------------------------------------------------------------------
//  Рисование размеров
void pCanvas_Dim_rW(TImage *Image1, TPoint Point0, TPoint Point1, int orient, int side, double size, int n_ff, int Width) {
    pCanvas_Dim_v_rW(Image1, Point0, Point1, orient, side, size, n_ff, 0, 1, Width);
}
//---------------------------------------------------------------------------
//  Рисование размеров
void pCanvas_Dim(TImage *Image1, TPoint Point0, TPoint Point1, int orient, int side, double size, int n_ff) {
    pCanvas_Dim_v(Image1, Point0, Point1, orient, side, size, n_ff, 0, 1);
}

