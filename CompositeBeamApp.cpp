//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("uFrmAddImacts.cpp", FrmAddImpacts);
USEFORM("StudDefinitionFormUnit.cpp", StudDefinitionForm);
USEFORM("uSteelSectionForm.cpp", SteelSectionForm2);
USEFORM("DefineSteelFormUnit.cpp", DefineSteelForm);
USEFORM("ConcreteDefinitionFormUnit.cpp", ConcreteDefinitionForm);
USEFORM("AboutProg.cpp", AboutProgForm);
USEFORM("CompositeBeamMainFormUnit.cpp", CompositeBeamMainForm);
USEFORM("RebarDefinitionFormUnit.cpp", RebarDefinitionForm);
USEFORM("LoggerFormUnit.cpp", FormLogger);
USEFORM("uHelpForm.cpp", HelpForm);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TCompositeBeamMainForm), &CompositeBeamMainForm);
		Application->CreateForm(__classid(TConcreteDefinitionForm), &ConcreteDefinitionForm);
		Application->CreateForm(__classid(TRebarDefinitionForm), &RebarDefinitionForm);
		Application->CreateForm(__classid(TStudDefinitionForm), &StudDefinitionForm);
		Application->CreateForm(__classid(TFormLogger), &FormLogger);
		Application->CreateForm(__classid(TAboutProgForm), &AboutProgForm);
		Application->CreateForm(__classid(TSteelSectionForm2), &SteelSectionForm2);
		Application->CreateForm(__classid(TDefineSteelForm), &DefineSteelForm);
		Application->CreateForm(__classid(TFrmAddImpacts), &FrmAddImpacts);
		Application->CreateForm(__classid(THelpForm), &HelpForm);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}

	return 0;
}
//---------------------------------------------------------------------------
