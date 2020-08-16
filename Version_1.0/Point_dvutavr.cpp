#include <vcl.h>
#include <math.h>
#include "Data_Profil.h"
#include "ProcExt.h"

//extern int    N_macro_hex;
 int    N_macro_hex;  //MV изменено для платформы 64 бита
void CalcNorm(float *normal, float ax, float ay, float az, float bx, float by, float bz);
//extern float  **Coor_vertex1, **Coor_vertex2;   // Вершины гексаэдров
float  **Coor_vertex1, **Coor_vertex2;   //MV изменено для платформы 64 бита
void NormalHex(int *point_m, float **Coor_vertex1, float **Coor_vertex2, float *normal);


//--------------------------------------------------
// получить точки контура сварного двутавра
void  Point_dvutavr(int zero, int zero1, int zero2, SECT_DVUTAVR *sect, float scale, TPoint *vertices) {
  vertices[0] = Point(zero2, zero);
  vertices[1] = Point(zero2+sect->b1*scale, zero);
  vertices[2] = Point(zero2+sect->b1*scale, zero+sect->h1*scale);
  vertices[3] = Point(zero2+0.5*(sect->b1+sect->b)*scale, zero+sect->h1*scale);
  vertices[4] = Point(zero2+0.5*(sect->b1+sect->b)*scale, zero+(sect->h + sect->h1)*scale);
  vertices[5] = Point(zero1+sect->b2*scale, zero+(sect->h + sect->h1)*scale);
  vertices[6] = Point(zero1+sect->b2*scale, zero+(sect->h + sect->h1 + sect->h2)*scale);
  vertices[7] = Point(zero1, zero+(sect->h + sect->h1 + sect->h2)*scale);
  vertices[8] = Point(zero1, zero+(sect->h + sect->h1)*scale);
  vertices[9] = Point(zero2+0.5*(sect->b1-sect->b)*scale, zero+(sect->h + sect->h1)*scale);
  vertices[10] = Point(zero2+0.5*(sect->b1-sect->b)*scale, zero+(sect->h1)*scale);
  vertices[11] = Point(zero2, zero+(sect->h1)*scale);
  vertices[12] = Point(zero2, zero);
}
//---------------------------------------------------------
// получить точки контура прокатного двутавра
void  Point_stand_dvutavr(int zero, int zero1, int zero2, SECT_DVUTAVR *sect, double rad, float scale, TPoint *vertices) {
  double r_c = rad*scale;
  double r2_c = Round(r_c - r_c*cos(45/57.3), 0);
  double b1c = sect->b1*scale;
  double b1p = 0.5*(sect->b1 + sect->b)*scale;
  double b1m = 0.5*(sect->b1 - sect->b)*scale;
  double h1c = sect->h1*scale;
  double h_h1 = (sect->h + sect->h1)*scale;
  double h_2h1 = (sect->h + 2*sect->h1)*scale;             

  vertices[0] = Point(zero2, zero);
  vertices[1] = Point(zero2 + b1c, zero);
  vertices[2] = Point(zero2 + b1c, zero + h1c);
  vertices[3] = Point(zero2 + b1p + r_c, zero + h1c);
  vertices[4] = Point(zero2 + b1p + r2_c, zero + h1c + r2_c);
  vertices[5] = Point(zero2 + b1p, zero + h1c + r_c);
  vertices[6] = Point(zero2 + b1p, zero + h_h1 - r_c);
  vertices[7] = Point(zero1 + b1p + r2_c, zero + h_h1 - r2_c);
  vertices[8] = Point(zero1 + b1p + r_c, zero + h_h1);
  vertices[9] = Point(zero1 + b1c, zero + h_h1);
  vertices[10] = Point(zero1 + b1c, zero + h_2h1);
  vertices[11] = Point(zero1, zero + h_2h1);
  vertices[12] = Point(zero1, zero + h_h1);
  vertices[13] = Point(zero2 + b1m - r_c, zero + h_h1);
  vertices[14] = Point(zero2 + b1m - r2_c, zero + h_h1 - r2_c);
  vertices[15] = Point(zero2 + b1m , zero + h_h1 - r_c);
  vertices[16] = Point(zero2 + b1m, zero + h1c + r_c);
  vertices[17] = Point(zero2 + b1m - r2_c, zero + h1c + r2_c);
  vertices[18] = Point(zero2 + b1m - r_c, zero + h1c);
  vertices[19] = Point(zero2, zero + h1c);
  vertices[20] = Point(zero2, zero);
}
//----------------------------------------------------------------------
// Вычисление точек зигзага
#define zigH   6
#define zigL   12
void  zigzag(TPoint *point, double dev, TPoint *vert) {
   int sx, sy;
   double alf;

   sx = (point[0].x + point[1].x)*dev;
   sy = (point[0].y + point[1].y)*dev;

   alf = atan2((double)(point[0].x - point[1].x), (double)(point[0].y - point[1].y));

   vert[0] = point[1];
   vert[1] = Point(sx - zigH*sin(alf), sy - zigH*cos(alf));
   vert[2] = Point(sx - zigH*0.5*sin(alf) + zigL*cos(alf), sy - zigH*0.5*cos(alf) + zigL*sin(alf));
   vert[3] = Point(sx + zigH*0.5*sin(alf) - zigL*cos(alf), sy + zigH*0.5*cos(alf) - zigL*sin(alf));
   vert[4] = Point(sx + zigH*sin(alf), sy + zigH*cos(alf));
   vert[5] = point[0];

}
//---------------------------------------------------------------------------
// Формирование координат вершин шестигранников и нормалей
void HexMacro(int *point_m, double coor_m[4][3], double thick, float *norm_v) {
    int  i, j, n0;
    float ax, ay, az, bx, by, bz, th, normal[3];

     point_m[0] = N_macro_hex*4;
     point_m[1] = N_macro_hex*4 + 1;
     point_m[2] = N_macro_hex*4 + 3;
     point_m[3] = N_macro_hex*4 + 2;

     // Вычисление направления нормали
     ax = coor_m[1][0] - coor_m[0][0];
     ay = coor_m[1][1] - coor_m[0][1];
     az = coor_m[1][2] - coor_m[0][2];
     // [2] - координата узла 3
     bx = coor_m[2][0] - coor_m[0][0];
     by = coor_m[2][1] - coor_m[0][1];
     bz = coor_m[2][2] - coor_m[0][2];

     CalcNorm(normal, ax, ay, az, bx, by, bz);

     th = thick/2;
     n0 = N_macro_hex*4;
     for (j=0; j<4; j++) {
       i = n0 + j;
	   Coor_vertex1[i][0] = coor_m[j][0] - normal[0]*th;
       Coor_vertex1[i][1] = coor_m[j][1] - normal[1]*th;
       Coor_vertex1[i][2] = coor_m[j][2] - normal[2]*th;
       Coor_vertex2[i][0] = coor_m[j][0] + normal[0]*th;
       Coor_vertex2[i][1] = coor_m[j][1] + normal[1]*th;
       Coor_vertex2[i][2] = coor_m[j][2] + normal[2]*th;
     }
     NormalHex(point_m, Coor_vertex1, Coor_vertex2, norm_v);
}
//------------------------------------------------------------------
void CalcNorm(float *normal, float ax, float ay, float az, float bx, float by, float bz) {
  float length;
         normal[0] = -(ay*bz - az*by);
         normal[1] = -(az*bx - ax*bz);
         normal[2] = -(ax*by - ay*bx);
         length = sqrt(normal[0]*normal[0] + normal[1]*normal[1] + normal[2]*normal[2]);
         normal[0] /= length;
         normal[1] /= length;
         normal[2] /= length;
}
//---------------------------------------------------------------------------
void NormalHex(int *point_m, float **Coor_vertex1, float **Coor_vertex2, float *normal) {

  float ax, ay, az, bx, by, bz, lenght;
  int n0, n1, n2, n3;

         n0 = point_m[0];
         n1 = point_m[1];
         n2 = point_m[2];
         n3 = point_m[3];

         // Первая грань
         ax = Coor_vertex1[n1][0] - Coor_vertex1[n0][0];
         ay = Coor_vertex1[n1][1] - Coor_vertex1[n0][1];
         az = Coor_vertex1[n1][2] - Coor_vertex1[n0][2];
         bx = Coor_vertex1[n3][0] - Coor_vertex1[n0][0];
         by = Coor_vertex1[n3][1] - Coor_vertex1[n0][1];
         bz = Coor_vertex1[n3][2] - Coor_vertex1[n0][2];
         CalcNorm(&normal[0], ax, ay, az, bx, by, bz);
         normal[0] = -normal[0];
         normal[1] = -normal[1];
         normal[2] = -normal[2];
         // Вторая грань
         ax = Coor_vertex1[n2][0] - Coor_vertex1[n3][0];
         ay = Coor_vertex1[n2][1] - Coor_vertex1[n3][1];
         az = Coor_vertex1[n2][2] - Coor_vertex1[n3][2];
         bx = Coor_vertex2[n3][0] - Coor_vertex1[n3][0];
         by = Coor_vertex2[n3][1] - Coor_vertex1[n3][1];
         bz = Coor_vertex2[n3][2] - Coor_vertex1[n3][2];
         CalcNorm(&normal[3], ax, ay, az, bx, by, bz);
         normal[3] = -normal[3];
         normal[4] = -normal[4];
         normal[5] = -normal[5];
         // третья грань
         ax = Coor_vertex2[n0][0] - Coor_vertex2[n1][0];
         ay = Coor_vertex2[n0][1] - Coor_vertex2[n1][1];
         az = Coor_vertex2[n0][2] - Coor_vertex2[n1][2];
         bx = Coor_vertex2[n3][0] - Coor_vertex2[n0][0];
         by = Coor_vertex2[n3][1] - Coor_vertex2[n0][1];
         bz = Coor_vertex2[n3][2] - Coor_vertex2[n0][2];
         CalcNorm(&normal[6], ax, ay, az, bx, by, bz);
         normal[6] = -normal[6];
         normal[7] = -normal[7];
         normal[8] = -normal[8];
         // четвертая грань
         ax = Coor_vertex2[n0][0] - Coor_vertex1[n0][0];
         ay = Coor_vertex2[n0][1] - Coor_vertex1[n0][1];
         az = Coor_vertex2[n0][2] - Coor_vertex1[n0][2];
         bx = Coor_vertex1[n1][0] - Coor_vertex1[n0][0];
         by = Coor_vertex1[n1][1] - Coor_vertex1[n0][1];
         bz = Coor_vertex1[n1][2] - Coor_vertex1[n0][2];
         CalcNorm(&normal[9], ax, ay, az, bx, by, bz);
         normal[9] = -normal[9];
         normal[10] = -normal[10];
         normal[11] = -normal[11];
         // пятая грань
         ax = Coor_vertex1[n3][0] - Coor_vertex1[n0][0];
         ay = Coor_vertex1[n3][1] - Coor_vertex1[n0][1];
         az = Coor_vertex1[n3][2] - Coor_vertex1[n0][2];
         bx = Coor_vertex2[n0][0] - Coor_vertex1[n0][0];
         by = Coor_vertex2[n0][1] - Coor_vertex1[n0][1];
         bz = Coor_vertex2[n0][2] - Coor_vertex1[n0][2];
         CalcNorm(&normal[12], ax, ay, az, bx, by, bz);
         normal[12] = -normal[12];
         normal[13] = -normal[13];
         normal[14] = -normal[14];
         // шестая грань
         ax = Coor_vertex1[n1][0] - Coor_vertex1[n2][0];
         ay = Coor_vertex1[n1][1] - Coor_vertex1[n2][1];
         az = Coor_vertex1[n1][2] - Coor_vertex1[n2][2];
         bx = Coor_vertex2[n2][0] - Coor_vertex1[n2][0];
         by = Coor_vertex2[n2][1] - Coor_vertex1[n2][1];
         bz = Coor_vertex2[n2][2] - Coor_vertex1[n2][2];
         CalcNorm(&normal[15], ax, ay, az, bx, by, bz);
         normal[15] = -normal[15];
         normal[16] = -normal[16];
         normal[17] = -normal[17];

}



