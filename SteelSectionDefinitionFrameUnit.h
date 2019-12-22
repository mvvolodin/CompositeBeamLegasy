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
        TButton *Button_Copy;
        TPageControl *PageControl2;
        TTabSheet *TabSheet_Weld;
        TTabSheet *TabSheet_Standart;
        TLabel *Label10;
        TComboBox *ComboBox_profil;
        TStringGrid *StringGrid_B;
        TPageControl *PageControl1;
        TTabSheet *TabSheet_STO;
        TRadioGroup *RadioGroup_STO;
        TTabSheet *TabSheet_GOST;
        TRadioGroup *RadioGroup_GOST;
        TImage *Image1;
        TCheckBox *CheckBox1;
        TGroupBox *GroupBox_W;
        TLabel *Label7;
        TLabel *Label3;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TEdit *Edit1;
        TEdit *Edit2;
        TEdit *Edit3;
        TEdit *Edit4;
        TEdit *Edit5;
        TEdit *Edit6;
        TImage *Image3;
        TImage *Image2;
        TTabSheet *TabSheet_StandTube;
        TPageControl *PageControl_Tube;
        TTabSheet *TabSheet_Square;
        TTabSheet *TabSheet_Rect;
        TComboBox *ComboBox_h_b_rect;
        TLabel *Label_h_b_rect;
        TComboBox *ComboBox_t_rect;
        TLabel *Label_t_rect;
        TRadioGroup *RadioGroup_orient;
        TImage *Image_rect;
        TStringGrid *StringGrid_Tube;
        TComboBox *ComboBox_h_b_square;
        TLabel *Label_b_h_square;
        TComboBox *ComboBox_t_square;
        TLabel *Label_t_square;
        TImage *Image_square;
	TLabel *Label_type_sect;
        TComboBox *ComboBox_TypeSect;
        TCheckBox *CheckBox_type_sect;
        TTabSheet *TabSheet_GOST57837;
        TImage *Image_stand;
        TRadioGroup *RadioGroupGOST57837;
        TTabSheet *TabSheet_CYL;
        TLabel *Label9;
        TLabel *Label11;
        TImage *Image_Cyl;
        TComboBox *ComboBox_Cyl_D;
        TComboBox *ComboBox_Cyl_t;
        TStringGrid *StringGrid_Cyl;
        void __fastcall Write_sect(TObject *Sender);
        int  __fastcall Read_sect();
        void __fastcall DrawSect();
        void __fastcall CheckChangeSect();
        void __fastcall Check_Original();
        void __fastcall Check_Type(TObject *Sender);
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
        void __fastcall ComboBox_TypeSectChange(TObject *Sender);
        void __fastcall draw_dvutavr(TImage * Image1,SECT_DVUTAVR *sect);
        void __fastcall draw_square_tube(TImage * Image1,SECT_SQUARE *sect);
        void __fastcall draw_rect_tube(TImage * Image1, SECT_RECT *sect);
        void __fastcall draw_circular_tube(TImage * Image1, SECT_CIRC *sect);
        void __fastcall draw_axes(TImage * Image1);
        void __fastcall Edit3Enter(TObject *Sender);
        void __fastcall Edit3Exit(TObject *Sender);
        void __fastcall Edit3Change(TObject *Sender);
        void __fastcall Edit3KeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall Edit2KeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall Edit1KeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall Edit5KeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall Edit6KeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall Edit4KeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall RadioGroup_GOSTClick(TObject *Sender);
        void __fastcall ComboBox_profilChange(TObject *Sender);
        void __fastcall Change_type_sect(int index_profil, TObject *Sender);
        void __fastcall Change_type_sect_tube(int index_profil, TObject *Sender);
        void __fastcall Weld_Change(TObject *Sender);
        void __fastcall PageControl1Change(TObject *Sender);
        void __fastcall RadioGroup_STOClick(TObject *Sender);
        void __fastcall PageControl2Change(TObject *Sender);
        void __fastcall RadioGroup_orientClick(TObject *Sender);

        void __fastcall Put_h_rect(TObject *Sender);
        void __fastcall ComboBox_h_b_rectChange(TObject *Sender);
        void __fastcall ComboBox_t_rectChange(TObject *Sender);
        void __fastcall ComboBox_h_b_squareChange(TObject *Sender);
        void __fastcall ComboBox_t_squareChange(TObject *Sender);
        void __fastcall CheckBox_type_sectClick(TObject *Sender);
        void __fastcall RectTube_Change(TObject *Sender);
		void __fastcall SquareTube_Change(TObject *Sender);
        // Заполнить список профилей
        void __fastcall FillComboBox1(TObject *Sender);
        void __fastcall RadioGroupGOST57837Click(TObject *Sender);
        void __fastcall ComboBox_Cyl_DChange(TObject *Sender);
        void __fastcall ComboBox_Cyl_tChange(TObject *Sender);
        void __fastcall CylTube_Change(TObject *Sender);
        void __fastcall draw_axes_zero(TImage *Image_Ax, int x0, int y0);



private:    // User declarations

public:		// User declarations
        __fastcall TSteelSectionDefinitionFrame(TComponent* Owner);
	   TArrow CoorAx;
	   COMMON_SECT common_sect_;
};
//---------------------------------------------------------------------------
//extern PACKAGE TSteelSectionDefinitionFrame *SteelSectionDefinitionFrame;
//---------------------------------------------------------------------------
#endif
