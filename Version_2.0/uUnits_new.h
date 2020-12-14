//---------------------------------------------------------------------------

#ifndef uUnits_newH
#define uUnits_newH

#include <system.hpp>


enum class LoadUnit{
	N = 1,
	kN = 1000,
};
enum class LengthUnit{  //mm = 1, cm = 0.1, m = 0.001 лучше?
	mm = 1,
	cm = 10,
	m = 1000,
};

enum LoadUnit__{
	N = 1,
	kN = 1000,
};
enum LengthUnit__{
	mm = 1,
	cm = 10,
	m = 1000,
};

AnsiString length_to_str(double val, LengthUnit length_unit = LengthUnit::mm, int num_digits = 2);
AnsiString area_to_str(double val, LengthUnit length_unit = LengthUnit::cm, int num_digits = 2);
AnsiString sect_modul_to_str(double val, LengthUnit length_unit = LengthUnit::cm, int num_digits = 2);
AnsiString inertia_to_str(double val, LengthUnit length_unit = LengthUnit::cm, int num_digits = 2);
AnsiString force_to_str(double val, LoadUnit load_unit = LoadUnit::N, int num_digits = 2);
AnsiString moment_to_str(double val, LengthUnit length_unit = LengthUnit::m,
	LoadUnit load_unit = LoadUnit::kN, int num_digits = 2);
AnsiString force_per_length_to_str(double val, LengthUnit length_unit = LengthUnit::mm,
	LoadUnit load_unit = LoadUnit::N, int num_digits = 2);
AnsiString force_per_area_to_str(double val, LengthUnit length_unit = LengthUnit::mm,
	LoadUnit load_unit = LoadUnit::N, int num_digits = 2);

//---------------------------------------------------------------------------
#endif
