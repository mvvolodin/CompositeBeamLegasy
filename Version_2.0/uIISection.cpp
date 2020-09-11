//---------------------------------------------------------------------------

#pragma hdrstop

#include "uIISection.h"
#include <iostream>
//---------------------------------------------------------------------------
#pragma package(smart_init)

IISection::IISection()
{
	std::cout << "ISection::ISection()" << std::endl;
}
IISection:: ~ IISection()
{
	std::cout << "ISection:: ~ ISection()" << std::endl;
}

