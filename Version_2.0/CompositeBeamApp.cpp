//---------------------------------------------------------------------------
#include <vcl.h>

#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("uFrmStud.cpp", StudDefinitionForm);
USEFORM("uFrmSteelSection.cpp", SteelSectionForm);
USEFORM("uFrmSteel.cpp", DefineSteelForm);
USEFORM("uFrmRebar.cpp", RebarDefinitionForm);
USEFORM("uFrmAboutProg.cpp", AboutProgForm);
USEFORM("uFrmLogger.cpp", FormLogger);
USEFORM("uFrmHelp.cpp", HelpForm);
USEFORM("uFrmConcrete.cpp", ConcreteDefinitionForm);
USEFORM("uFrmCompositeBeam.cpp", CompositeBeamMainForm);
USEFORM("uFrmAddImacts.cpp", FrmAddImpacts);
//---------------------------------------------------------------------------
std::wstring file_path;

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPTSTR lpCmdLine, int nCmdShow)
{
	file_path = lpCmdLine;

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
		Application->CreateForm(__classid(TDefineSteelForm), &DefineSteelForm);
		Application->CreateForm(__classid(TFrmAddImpacts), &FrmAddImpacts);
		Application->CreateForm(__classid(THelpForm), &HelpForm);
		Application->CreateForm(__classid(TSteelSectionForm), &SteelSectionForm);
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
