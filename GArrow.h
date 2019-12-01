//---------------------------------------------------------------------------
#include <vcl.h>
#ifndef GArrowH
#define GArrowH
#define MAX_PIC  10
class TArrow
{
  public:
  int Ax0,Ay0; // точка 0 стрелки
  int Ax1,Ay1; // точка 1 стрелки
 // long double Ax0,Ay0; // точка 0 стрелки   Для classic Borland compiler необходимо задать long double
  //long double Ax1,Ay1; // точка 1 стрелки
  float Sign;
  int    MaxPic;  // максимальная длина кончика стрелки
  TPoint LArrow[3];//Точки для отрисовки стрелки???
  TPoint Ar[4];
  void  PutArrow(TPoint * Ax_c, float Signature,
								int MaxPic0);   //По сути это конструктор так как происходит инициализация полей
  void  SetArrow();
};

//---------------------------------------------------------------------------
#endif