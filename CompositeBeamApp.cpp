//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//#include "Log.h"
#include "Logger.h"

bool debug=true;
FILE* logfile=fopen("Debug.txt","w");

//---------------------------------------------------------------------------

USEFORM("SteelDefinitionFormUnit.cpp", SteelDefinitionForm);
USEFORM("RebarDefinitionFormUnit.cpp", RebarDefinitionForm);
USEFORM("StudDefinitionFormUnit.cpp", StudDefinitionForm);
USEFORM("SteelSectionDefinitionFrameUnit.cpp", SteelSectionDefinitionFrame); /* TFrame: File Type */
USEFORM("SteelSectionFormUnit.cpp", SteelSectionForm);
USEFORM("CompositeBeamMainFormUnit.cpp", CompositeBeamMainForm);
USEFORM("ConcreteDefinitionFormUnit.cpp", ConcreteDefinitionForm);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TCompositeBeamMainForm), &CompositeBeamMainForm);
		Application->CreateForm(__classid(TSteelDefinitionForm), &SteelDefinitionForm);
		Application->CreateForm(__classid(TSteelSectionForm), &SteelSectionForm);
		Application->CreateForm(__classid(TConcreteDefinitionForm), &ConcreteDefinitionForm);
		Application->CreateForm(__classid(TRebarDefinitionForm), &RebarDefinitionForm);
		Application->CreateForm(__classid(TStudDefinitionForm), &StudDefinitionForm);
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
