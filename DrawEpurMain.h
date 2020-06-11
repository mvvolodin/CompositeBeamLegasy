//---------------------------------------------------------------------------
#ifndef DrawEpurMainH
#define DrawEpurMainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>

int DrawEpur(TImage *Image1, int n_point, double *coor_Epur, double *QpopA, double *QpopB,
			  int n_supp, double *coor_supp, bool flag_sign, int num_digits, bool con_sign_practice);
void Shtrih(TImage * Image1, TPoint *points, float s_s, float mx, float my);

#endif
