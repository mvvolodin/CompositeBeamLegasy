//---------------------------------------------------------------------------

#pragma hdrstop

#include "Rebar.h"
#include <Vcl.Dialogs.hpp>

//---------------------------------------------------------------------------
#pragma package(smart_init)

void fill_rebar_named_list(RebarNamedList* rebar_named_list)
{
	rebar_named_list->insert(RebarPair("A240",RebarBasic("A240",240)));
	rebar_named_list->insert(RebarPair("A400",RebarBasic("A400",400)));
	rebar_named_list->insert(RebarPair("A500",RebarBasic("A500",500)));
	rebar_named_list->insert(RebarPair("A600",RebarBasic("A600",600)));
	rebar_named_list->insert(RebarPair("A800",RebarBasic("A800",800)));
	rebar_named_list->insert(RebarPair("A1000",RebarBasic("A1000",1000)));
/*  Конструкция ниже не работает в "classic" компилятор. Объект пропадает и инициализация NULL???
	rebar_named_list->insert(RebarPair("A400",RebarBasic("A400",400)));

*/
}

