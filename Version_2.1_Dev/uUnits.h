//---------------------------------------------------------------------------

#ifndef uUnitsH
#define uUnitsH

#include <system.hpp>

namespace units
{
//Перевод входных данных в единицы измерения программы {Н и мм}
	inline constexpr int mm2 {1000 * 1000};
    inline constexpr int mm3 {1000 * 1000 * 1000};
	inline constexpr int N  {1000};

//Перевод единицы измерения программы в выходные данные
	inline constexpr double cm{0.1};
	inline constexpr double cm2{0.1 * 0.1};
	inline constexpr double cm3{0.1 * 0.1 * 0.1};
	inline constexpr double cm4{0.1 * 0.1 * 0.1 * 0.1};
	inline constexpr double m{0.001};
	inline constexpr double m2{0.001 * 0.001};
	inline constexpr double m3{0.001 * 0.001 * 0.001};

	inline constexpr double kN  {0.001};
}


enum class LoadUnit{
	N = 1,
	kN = 1000,
};
enum class LengthUnit{  //mm = 1, cm = 0.1, m = 0.001 лучше?
	mm = 1,
	cm = 10,
	m = 1000,
};

AnsiString double_to_str(double val, int num_digits = 2);
AnsiString bool_to_str(bool val);

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
