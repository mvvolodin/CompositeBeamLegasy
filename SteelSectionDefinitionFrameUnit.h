//---------------------------------------------------------------------------


#ifndef SteelSectionDefinitionFrameUnitH
#define SteelSectionDefinitionFrameUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include "Data_Profil.h"
#include "GArrow.h"
#include <Grids.hpp>
#include <ComCtrls.hpp>
#include <jpeg.hpp>

void  Point_stand_dvutavr(int zero, int zero1, int zero2, SECT_DVUTAVR *sect, double rad, float scale, TPoint *vertices);

//---------------------------------------------------------------------------
class TSteelSectionDefinitionFrame : public TFrame
{
__published:	// IDE-managed Components
        TGroupBox *GroupBox_Common;
        TButton *Button_Apply;
        TPageControl *PageControl2;
        TTabSheet *TabSheet_Standart;
        TLabel *Label10;
        TComboBox *ComboBox_profil;
        TStringGrid *StringGrid_B;
	TButton *btn_cancel;
	TButton *btn_close;
	TRadioGroup *RadioGroupGOST57837;
	TImage *Image_stand;
		int  __fastcall Read_sect();
        void __fastcall DrawSect();
		void __fastcall CheckChangeSect();
        void __fastcall Check_Modify();
        void __fastcall Edit6_Change(TObject *Sender);
        void __fastcall Edit1_Change(TObject *Sender);
        void __fastcall Edit2_Change(TObject *Sender);
        void __fastcall Edit3_Change(TObject *Sender);
        void __fastcall Edit4_Change(TObject *Sender);
        void __fastcall Edit5_Change(TObject *Sender);
        void __fastcall Button_ApplyClick(TObject *Sender);
		void __fastcall CheckBox1MouseDown(TObject *Sender,
		  TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall draw_dvutavr(TImage * Image1,SECT_DVUTAVR *sect);
        void __fastcall draw_square_tube(TImage * Image1,SECT_SQUARE *sect);
        void __fastcall draw_rect_tube(TImage * Image1, SECT_RECT *sect);
        void __fastcall draw_circular_tube(TImage * Image1, SECT_CIRC *sect);
        void __fastcall draw_axes(TImage * Image1);
        void __fastcall ComboBox_profilChange(TObject *Sender);
        void __fastcall Change_type_sect(int index_profil, TObject *Sender);

		void __fastcall Put_h_rect(TObject *Sender);
		void __fastcall RadioGroupGOST57837Click(TObject *Sender);
		void __fastcall draw_axes_zero(TImage *Image_Ax, int x0, int y0);



private:    // User declarations
		void fill_I_section_data();//заполняет структуры с основными данными двутавра
public:		// User declarations
        __fastcall TSteelSectionDefinitionFrame(TComponent* Owner);
	   TArrow CoorAx;
	   COMMON_SECT common_sect_;
};
//---------------------------------------------------------------------------
//extern PACKAGE TSteelSectionDefinitionFrame *SteelSectionDefinitionFrame;
//---------------------------------------------------------------------------
#endif
