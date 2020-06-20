//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "uHelpForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "SHDocVw_OCX"
#pragma resource "*.dfm"
THelpForm *HelpForm;
//---------------------------------------------------------------------------
__fastcall THelpForm::THelpForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
