//---------------------------------------------------------------------------

#pragma hdrstop

#include "uCorrugatedSheet.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

std::vector<CorrugatedSheet> CorrugatedSheetsData::corrugated_sheets_list_
{
// (1)Марка - (2)Высота - (3)Толщина - (4)Расстояние между внутренними краями наружних полок -
// (5)Ширина нижней полки - (6) Шаг нижних полок - (7) Масса квадратного метра
//Данные из ГОСТ 24045-2016
	{L"Н60-845-0.7", 60, 0.7, 89.5, 50, 211.2, 8.8 },
	{L"Н60-845-0.8", 60, 0.8, 89.5, 50, 211.2, 9.9},
	{L"Н60-845-0.9", 60, 0.9, 89.5, 50, 211.2, 11.1},
	{L"Н75-750-0.7", 75, 0.7, 95.5, 50, 187.5, 9.8},
	{L"Н75-750-0.8", 75, 0.8, 95.5, 50, 187.5, 11.2},
	{L"Н75-750-0.9", 75, 0.9, 95.5, 50, 187.5, 12.5},
	{L"Н114-600-0.8", 114, 0.8, 96, 60, 200, 14.0},
	{L"Н114-600-0.9", 114, 0.9, 96, 60, 200, 15.6},
	{L"Н114-600-1.0", 114, 1.0, 96, 60, 200, 17.2},
	{L"Н114-750-0.8", 114, 0.8, 96, 60, 200, 12.5},
	{L"Н114-750-0.9", 114, 0.9, 96, 60, 200, 14.0},
	{L"Н114-750-1.0", 114, 1.0, 96, 60, 200, 15.4},
	{L"Н153-850-0.8", 153, 0.8, 164, 284 - 241, 284, 11.5},
	{L"Н153-850-1.0", 153, 1.0, 164, 284 - 241, 284, 14.4},
	{L"Н153-850-1.2", 153, 1.2, 164, 284 - 241, 284, 17.1},
	{L"Н153-850-1.5", 153, 1.5, 164, 284 - 241, 284, 21.3},

//Данные из ГОСТ Р 58389-2019

	{L"HA50Z-600-0,6", 50, 0.6, 150 - 40, 136, 136 + 15, 9.4},
	{L"HA50Z-600-0,65", 50, 0.6, 150 - 40, 136, 136 + 15, 10.12},
	{L"HA50Z-600-0,7", 50, 0.6, 150 - 40, 136, 136 + 15, 10.83},
	{L"HA50Z-600-0,8", 50, 0.6, 150 - 40, 136, 136 + 15, 12.27},
};
std::vector<String> CorrugatedSheetsData::get_corrugated_sheet_names()
{
	std::vector<String> corrugated_sheet_names_list{};

	for(auto corrugated_sheet:corrugated_sheets_list_)
		corrugated_sheet_names_list.push_back(corrugated_sheet.get_name());

	corrugated_sheet_names_list.shrink_to_fit();

	return corrugated_sheet_names_list;
}
CorrugatedSheet CorrugatedSheetsData::get_corrugated_sheet(const String& name)
{
	auto corrugated_sheet = std::find_if(corrugated_sheets_list_.begin(),corrugated_sheets_list_.end(),
	[name](CorrugatedSheet corrugated_sheet){return corrugated_sheet.get_name() == name;});

	return *corrugated_sheet;
}

double CorrugatedSheet::get_h_b()
{
	if(fully_initialized) return h_b_;

	h_b_ = (b_ + b_ap_) / (2 * S_n_) * h_n_;
	fully_initialized = true;

	return h_b_;
}


CorrugatedSheet::CorrugatedSheet()
{
}

CorrugatedSheet::CorrugatedSheet (String name, double h_n, double t, double w):
	name_(name),
	h_n_(h_n),
	t_(t),
	w_(w){}
CorrugatedSheet::CorrugatedSheet (String name, double h_n, double t,
								  double b_ap, double b, double S_n, double w):
	name_(name),
	h_n_(h_n),
	t_(t),
	b_ap_(b_ap),
	b_(b),
	S_n_(S_n),
	w_(w){}

