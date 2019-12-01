//---------------------------------------------------------------------------

#ifndef SteelSectionFormUnitH
#define SteelSectionFormUnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "SteelSectionDefinitionFrameUnit.h"
#include "StandartProfil.h"
#include "SteelSectionDefinitionFrameUnit.h"
//---------------------------------------------------------------------------
class TSteelSectionForm : public TForm
{
__published:	// IDE-managed Components
	TSteelSectionDefinitionFrame *SteelSectionDefinitionFrame;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall SectSelectCom_ParamFrame1Button_ApplyClick(TObject *Sender);
	void __fastcall SectSelectCom_ParamFrame1ComboBox_profilChange(TObject *Sender);
	void __fastcall SectSelectCom_ParamFrame1RadioGroupGOST57837Click(TObject *Sender);

private:	// User declarations

	TStandartProfil StandartProfil;
	COMMON_SECT com_sect;  //Это union в котором собраны типы сечений двутавр, труба, круг и т.д.
	GEOM_PARAM_SECT param_sect; //Структура с геометрическими зарактеристиками

public:		// User declarations
	__fastcall TSteelSectionForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TSteelSectionForm *SteelSectionForm;
//---------------------------------------------------------------------------
#endif
