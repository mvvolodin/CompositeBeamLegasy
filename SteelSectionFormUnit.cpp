//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SteelSectionFormUnit.h"
#include "Data_Profil.h"
#include "Get_param_sect_func.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "SteelSectionDefinitionFrameUnit"
#pragma resource "*.dfm"
TSteelSectionForm *SteelSectionForm;

bool flag_sect_change; // флаг изменения параметров сечения
int  Type_sect;   // Тип сечения - Двутавр или труба
COMMON_SECT *common_sect;
bool flag_image;

//---------------------------------------------------------------------------
__fastcall TSteelSectionForm::TSteelSectionForm(TComponent* Owner)
	: TForm(Owner)
{
   common_sect = &com_sect; //при создании глобальной переменной присваивается закрытый член класса
 //#define DVUTAVR 1;- аналого типа enum
  // SteelSectionDefinitionFrame->ComboBox_TypeSectChange(Owner);//Инициализация объекта профилем по умолчанию
}
//---------------------------------------------------------------------------
void __fastcall TSteelSectionForm::FormShow(TObject *Sender) //обработчик события вызывается каждый раз перед
{                                                            // тем как отображается форма


  // SteelSectionDefinitionFrame->ComboBox_TypeSect->ItemIndex = 1;
 //  SteelSectionDefinitionFrame->ComboBox_TypeSectChange(Sender);

}
//---------------------------------------------------------------------------
//Обработчик события, нажатие кнопкки применить
//---------------------------------------------------------------------------

void __fastcall TSteelSectionForm::SectSelectCom_ParamFrame1Button_ApplyClick(TObject *Sender)

{
  SteelSectionDefinitionFrame->Button_ApplyClick(Sender);// передаёт управление в frame
  Get_param_sect(&(common_sect->dvutavr), &param_sect);//заполняет структуру геометрическим параметрами
  Close();
}
//---------------------------------------------------------------------------
//Обработчик события смена номер профилия "Б10", "Б20" ...
//---------------------------------------------------------------------------

void __fastcall TSteelSectionForm::SectSelectCom_ParamFrame1ComboBox_profilChange(TObject *Sender)

{
  SteelSectionDefinitionFrame->ComboBox_profilChange(Sender);//вызывает функцию Frame

}
//---------------------------------------------------------------------------
//Обработчик события выбор типа профиля "Б", "Ш", "К".....
//---------------------------------------------------------------------------
void __fastcall TSteelSectionForm::SectSelectCom_ParamFrame1RadioGroupGOST57837Click(TObject *Sender)

{
  SteelSectionDefinitionFrame->RadioGroupGOST57837Click(Sender);

}
//---------------------------------------------------------------------------

