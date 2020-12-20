//---------------------------------------------------------------------------
#pragma hdrstop
//---------------------------------------------------------------------------
#include "uStudsGOSTR55738.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
namespace StudsGOSTR55738
{
	struct StudGOSTR55738{
		std::u16string const name_;
		double const d_1_;
		double const l_1_;
	};

	std::vector<StudGOSTR55738> table{
		{u"SDx10x50",10,50},
		{u"SDx10x50",10,50},
		{u"SDx10x75",10,75},
		{u"SDx10x100",10,100},
		{u"SDx10x125",10,125},
		{u"SDx10x150",10,150},
		{u"SDx10x175",10,175},
		{u"SDx10x200",10,200},
		{u"SDx10x225",10,225},
		{u"SDx10x250",10,250},
		{u"SDx10x275",10,275},
		{u"SDx10x300",10,300},
		{u"SDx10x325",10,325},
		{u"SDx10x350",10,350},

		{u"SDx13x50",13,50},
		{u"SDx13x75",13,75},
		{u"SDx13x100",13,100},
		{u"SDx13x125",13,125},
		{u"SDx13x150",13,150},
		{u"SDx13x175",13,175},
		{u"SDx13x200",13,200},
		{u"SDx13x225",13,225},
		{u"SDx13x250",13,250},
		{u"SDx13x275",13,275},
		{u"SDx13x300",13,300},
		{u"SDx13x325",13,325},
		{u"SDx13x350",13,350},

		{u"SDx16x50",16,50},
		{u"SDx16x75",16,75},
		{u"SDx16x100",16,100},
		{u"SDx16x125",16,125},
		{u"SDx16x150",16,150},
		{u"SDx16x175",16,175},
		{u"SDx16x200",16,200},
		{u"SDx16x225",16,225},
		{u"SDx16x250",16,250},
		{u"SDx16x275",16,275},
		{u"SDx16x300",16,300},
		{u"SDx16x325",16,325},
		{u"SDx16x350",16,350},

		{u"SDx19x50",19,50},
		{u"SDx19x75",19,75},
		{u"SDx19x100",19,100},
		{u"SDx19x125",19,125},
		{u"SDx19x150",19,150},
		{u"SDx19x175",19,175},
		{u"SDx19x200",19,200},
		{u"SDx19x225",19,225},
		{u"SDx19x250",19,250},
		{u"SDx19x275",19,275},
		{u"SDx19x300",19,300},
		{u"SDx19x325",19,325},
		{u"SDx19x350",19,350},

		{u"SDx22x50",22,50},
		{u"SDx22x75",22,75},
		{u"SDx22x100",22,100},
		{u"SDx22x125",22,125},
		{u"SDx22x150",22,150},
		{u"SDx22x175",22,175},
		{u"SDx22x200",22,200},
		{u"SDx22x225",22,225},
		{u"SDx22x250",22,250},
		{u"SDx22x275",22,275},
		{u"SDx22x300",22,300},
		{u"SDx22x325",22,325},
		{u"SDx2x350",22,350},

		{u"SDx25x50",25,50},
		{u"SDx25x75",25,75},
		{u"SDx25x100",25,100},
		{u"SDx25x125",25,125},
		{u"SDx25x150",25,150},
		{u"SDx25x175",25,175},
		{u"SDx25x200",25,200},
		{u"SDx25x225",25,225},
		{u"SDx25x250",25,250},
		{u"SDx25x275",25,275},
		{u"SDx25x300",25,300},
		{u"SDx25x325",25,325},
		{u"SDx25x350",25,350}};

std::vector<std::basic_string<char16_t>> names()
{
	std::vector<std::basic_string<char16_t>> names;
	for(auto const & s:table)
		names.emplace_back(s.name_);

	return names;
}
std::u16string const & name (int index)
{
	return table[index].name_;
}
double d_1(int index)
{
	return table[index].d_1_;
}
double l_1(int index)
{
	return table[index].l_1_;
}
}
