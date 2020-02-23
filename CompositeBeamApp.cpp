//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("RebarDefinitionFormUnit.cpp", RebarDefinitionForm);
USEFORM("SteelSectionDefinitionFrameUnit.cpp", SteelSectionDefinitionFrame); /* TFrame: File Type */
USEFORM("SteelSectionFormUnit.cpp", SteelSectionForm);
USEFORM("StudDefinitionFormUnit.cpp", StudDefinitionForm);
USEFORM("CompositeBeamMainFormUnit.cpp", CompositeBeamMainForm);
USEFORM("ConcreteDefinitionFormUnit.cpp", ConcreteDefinitionForm);
USEFORM("LoggerFormUnit.cpp", FormLogger);
USEFORM("DefineSteelFormUnit.cpp", DefineSteelForm);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TCompositeBeamMainForm), &CompositeBeamMainForm);
		Application->CreateForm(__classid(TSteelSectionForm), &SteelSectionForm);
		Application->CreateForm(__classid(TConcreteDefinitionForm), &ConcreteDefinitionForm);
		Application->CreateForm(__classid(TRebarDefinitionForm), &RebarDefinitionForm);
		Application->CreateForm(__classid(TStudDefinitionForm), &StudDefinitionForm);
		Application->CreateForm(__classid(TDefineSteelForm), &DefineSteelForm);
		Application->CreateForm(__classid(TFormLogger), &FormLogger);
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
