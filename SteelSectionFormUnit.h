//---------------------------------------------------------------------------

#ifndef SteelSectionFormUnitH
#define SteelSectionFormUnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
#include "SteelSectionDefinitionFrameUnit.h"
#include "StandartProfil.h"
#include "SteelSectionDefinitionFrameUnit.h"
#include "ObserverPatternInterfaces.h"
#include "ISection.h"

//---------------------------------------------------------------------------
class TSteelSectionForm : public TForm, public IPublisher
{
__published:	// IDE-managed Components
	TSteelSectionDefinitionFrame *SteelSectionDefinitionFrame;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall SectSelectCom_ParamFrame1Button_ApplyClick(TObject *Sender);
	void __fastcall SectSelectCom_ParamFrame1ComboBox_profilChange(TObject *Sender);
	void __fastcall SectSelectCom_ParamFrame1RadioGroupGOST57837Click(TObject *Sender);

private:	// User declarations
	static const Publisher_ID id_ = Publisher_ID::SECTION_FORM;
	IObserver_* iobserver_;
	ISection isection_temp_;

	TStandartProfil StandartProfil; //Объект с таблице геом.характ. профилей. Поле index устанавливается конструктором по умолчанию в -1
	COMMON_SECT com_sect;  //Это union в котором собраны типы сечений двутавр, труба, круг и т.д.
	GEOM_PARAM_SECT param_sect; //Структура с геометрическими зарактеристиками

public:		// User declarations
	__fastcall TSteelSectionForm(TComponent* Owner);
	ISection get_isection()const{return isection_temp_;}
	void register_observer(IObserver_* iobserver) override {iobserver_ = iobserver;}
	void set_form_controls(ISection isection);
};
//---------------------------------------------------------------------------
extern PACKAGE TSteelSectionForm *SteelSectionForm;
//---------------------------------------------------------------------------
#endif
