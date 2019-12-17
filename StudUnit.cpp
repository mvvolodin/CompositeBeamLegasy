//---------------------------------------------------------------------------

#pragma hdrstop

#include "StudUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//Ётот конструктор требуетс€ дл€ корректной работы типов pair и map.
//ќтмечу, что не совсем пон€то почему. ¬едь оперетора [] нет, дл€ которого ребуетс€ value initialization
//обычно предоставл€ема€ default ctr

TStud::TStud()
	:name_(""),
	 l_(0.0),
	 d_an_(0.0),
	 gamma_c_(0.0),
	 R_y_(0.0){}

TStud::TStud(String name, double l, double d_an, double gamma_c, double R_y)
	:name_(name),
	 l_(l),
	 d_an_(d_an),
	 gamma_c_(gamma_c),
	 R_y_(R_y){}

