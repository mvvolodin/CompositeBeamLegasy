//---------------------------------------------------------------------------

#pragma hdrstop

#include "uGeneralSteelSection.h"
#include <iostream>
//---------------------------------------------------------------------------
#pragma package(smart_init)

GeneralSteelSection::GeneralSteelSection()
{
	std::cout << "ISection::ISection()" << std::endl;
}
GeneralSteelSection:: ~ GeneralSteelSection()
{
	std::cout << "ISection:: ~ ISection()" << std::endl;
}

