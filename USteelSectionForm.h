//---------------------------------------------------------------------------

#ifndef USteelSectionFormH
#define USteelSectionFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
#include "StandartProfil.h"
#include "pCanvas_func.h"
#include "Data_Profil.h"
#include "ListConst.h"
#include "StandartProfil.h"
#include "pCanvas_func.h"
#include "ProcExt.h"
#include "String_doubleUnit.h"
#include "GArrow.h"
//---------------------------------------------------------------------------
class TSteelSectionForm2 : public TForm
{
__published:	// IDE-managed Components
	TPageControl *PageControl2;
	TTabSheet *TabSheet_Standart;
	TLabel *Label10;
	TImage *Image_stand;
	TComboBox *ComboBox_profil;
	TStringGrid *StringGrid_B;
	TRadioGroup *RadioGroupGOST57837;
	TButton *btk_ok;
	TButton *btn_cancel;
	TButton *btn_close;
private:	// User declarations
	SECT_DVUTAVR dvutavr;
	TStandartProfil StandartProfil;
	TArrow CoorAx;

	void fill_cmb_bx_pofiles();
	void fill_grid();
	void  draw_dvutavr(TImage * Image_stand, SECT_DVUTAVR *sect);
	void draw_axes(TImage *Image_Ax);
	void draw_axes_zero(TImage *Image_Ax, int x0, int y0);
	void Point_stand_dvutavr(int zero, int zero1, int zero2, SECT_DVUTAVR *sect, double rad, float scale, TPoint *vertices);

public:		// User declarations
	__fastcall TSteelSectionForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TSteelSectionForm2 *SteelSectionForm2;
//---------------------------------------------------------------------------
#endif
