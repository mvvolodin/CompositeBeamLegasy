//---------------------------------------------------------------------------

#pragma hdrstop

#include "uUnits_new.h"
#include <cmath>
#include <System.SysUtils.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)

namespace
{
	double conv_geom(double val, LengthUnit leng_un = LengthUnit::mm, int leng_pow = 1)
	{
		return val / std::pow(static_cast<int>(leng_un), leng_pow);
	}
	double conv_force(double val, LoadUnit load_un = LoadUnit::N, int load_pow = 1)
	{
		return val / std::pow(static_cast<int>(load_un), load_pow);
	}
	double conv_force_per_geom(double val,
		LengthUnit leng_un = LengthUnit::mm, int leng_pow = 1,
		LoadUnit load_un = LoadUnit::N, int load_pow = 1)
	{
		return val / std::pow(static_cast<int>(load_un), load_pow)  * std::pow(static_cast<int>(leng_un), leng_pow);
	}
}
AnsiString length_to_str(double val, LengthUnit length_unit, int num_digits)
{
	return FloatToStrF(conv_geom(val, length_unit), ffFixed, 15, num_digits);
}
AnsiString area_to_str(double val, LengthUnit length_unit, int num_digits)
{
	return FloatToStrF(conv_geom(val, length_unit, 2), ffFixed, 15, num_digits);
}
AnsiString sect_modul_to_str(double val, LengthUnit length_unit, int num_digits)
{
	return FloatToStrF(conv_geom(val, length_unit, 3), ffFixed, 15, num_digits);
}
AnsiString inertia_to_str(double val, LengthUnit length_unit, int num_digits)
{
	return FloatToStrF(conv_geom(val, length_unit, 4), ffFixed, 15, num_digits);
}
AnsiString force_to_str(double val, LoadUnit load_unit, int num_digits)
{
	return FloatToStrF(conv_force(val, load_unit), ffFixed, 15, num_digits);
}
AnsiString moment_to_str(double val, LengthUnit length_unit, LoadUnit load_unit, int num_digits)
{
	return FloatToStrF(conv_geom(conv_force(val, load_unit), length_unit) ,ffFixed, 15, num_digits);
}
AnsiString force_per_length_to_str(double val, LengthUnit length_unit, LoadUnit load_unit, int num_digits)
{
	return FloatToStrF(conv_force_per_geom(val, length_unit, 0, load_unit), ffFixed, 15, num_digits);
}
AnsiString force_per_area_to_str(double val, LengthUnit length_unit, LoadUnit load_unit, int num_digits)
{
	return FloatToStrF(conv_force_per_geom(val, length_unit, 2, load_unit), ffFixed, 15, num_digits);
}
