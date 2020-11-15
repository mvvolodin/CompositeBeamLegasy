//---------------------------------------------------------------------------
#ifndef uSteelTableObjectsH
#define uSteelTableObjectsH
//---------------------------------------------------------------------------
#include "uSteelTable.h"
//---------------------------------------------------------------------------
enum class SteelTableIndex{
	SP266_TableB4 = 0,
	GOST_27772_TableB4 = 1
};
//---------------------------------------------------------------------------
extern std::vector<SteelTable> const steel_tables;
#endif
