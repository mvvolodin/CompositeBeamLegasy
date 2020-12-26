//---------------------------------------------------------------------------

#pragma hdrstop

#include "uCorrugatedSheet.h"
#include "uUnits_new.h"
#include "Constants.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

using namespace units;
using namespace constants;

std::vector<CorrugatedSheet> CorrugatedSheetsData::corrugated_sheets_list_
{
// (1)����� - (2)������ - (3)������� - (4)���������� ����� ����������� ������ ������� ����� -
// (5)���������� ����� ����������� ������ ����� �����
// (6)������ ������� ����� - (7)������ ������� �����- (8)��� - (9) ����� ����������� �����
//������ �� ���� 24045-2016
	{L"�60-845-0.7", 60, 0.7, 89.5, 161.2, 122, 50, 211.2, 8.8 },
	{L"�60-845-0.8", 60, 0.8, 89.5, 161.2, 122, 50, 211.2, 9.9},
	{L"�60-845-0.9", 60, 0.9, 89.5, 161.2, 122, 50, 211.2, 11.1},
	{L"�75-750-0.7", 75, 0.7, 95.5, 137.5, 92, 50, 187.5, 9.8},
	{L"�75-750-0.8", 75, 0.8, 95.5, 137.5, 92, 50, 187.5,  11.2},
	{L"�75-750-0.9", 75, 0.9, 95.5, 137.5, 92, 50, 187.5,  12.5},
	{L"�114-600-0.8", 114, 0.8, 96, 140, 60, 104, 200, 14.0},
	{L"�114-600-0.9", 114, 0.8, 96, 140, 60, 104, 200, 15.6},
	{L"�114-600-1.0", 114, 0.8, 96, 140, 60, 104, 200, 17.2},
	{L"�114-750-0.8", 114, 0.8, 124, 170, 126, 80, 250, 12.5},
	{L"�114-750-0.9", 114, 0.9, 124, 170, 126, 80, 250, 14.0},
	{L"�114-750-1.0", 114, 1.0, 124, 170, 126, 80, 250, 15.4},
	{L"�153-850-0.8", 153, 0.8, 164, 241, 120, 43, 284, 11.5},
	{L"�153-850-1.0", 153, 1.0, 164, 241, 120, 43, 284, 14.4},
	{L"�153-850-1.2", 153, 1.2, 164, 241, 120, 43, 284, 17.1},
	{L"�153-850-1.5", 153, 1.5, 164, 241, 120, 43, 284, 21.3},

////������ �� ���� � 58389-2019
//
//	{L"��50Z-600-0.6", 50, 0.6, 150 - 40, 136, 136 + 15, 9.4},
//	{L"��50Z-600-0.65", 50, 0.65, 150 - 40, 136, 136 + 15, 10.12},
//	{L"��50Z-600-0.7", 50, 0.7, 150 - 40, 136, 136 + 15, 10.83},
//	{L"��50Z-600-0.8", 50, 0.8, 150 - 40, 136, 136 + 15, 12.27},
//	{L"��50Z-600-0.9", 50, 0.9, 150 - 40, 136, 136 + 15, 13.72},
//	{L"��50Z-600-1.0", 50, 1.0, 150 - 40, 136, 136 + 15, 15.15},
//	{L"��50Z-600-1.2", 50, 1.2, 150 - 40, 136, 136 + 15, 18.03},
//
//	{L"��60Z-845-0.55", 60, 0.55, 89, 50, 211 - 50, 7.0},
//	{L"��60Z-845-0.6", 60, 0.6, 89, 50, 211 - 50, 7.6},
//	{L"��60Z-845-0.65", 60, 0.65, 89, 50, 211 - 50, 8.2},
//	{L"��60Z-845-0.7", 60, 0.7, 89, 50, 211 - 50, 8.7},
//	{L"��60Z-845-0.8", 60, 0.8, 89, 50, 211 - 50, 9.9},
//	{L"��60Z-845-0.9", 60, 0.9, 89, 50, 211 - 50, 11.0},
//	{L"��60Z-845-1.0", 60, 1.0, 89, 50, 211 - 50, 12.5},
//
//	{L"��90Z-1000-0.55", 90, 0.55, 330 - 142, 330 - 224, 330, 6.62},
//	{L"��90Z-1000-0.6", 90, 0.6, 330 - 142, 330 - 224, 330, 7.17},
//	{L"��90Z-1000-0.65", 90, 0.65, 330 - 142, 330 - 224, 330, 7.72},
//	{L"��90Z-1000-0.7", 90, 0.7, 330 - 142, 330 - 224, 330, 8.27},
//	{L"��90Z-1000-0.8", 90, 0.8, 330 - 142, 330 - 224, 330, 9.37},
//	{L"��90Z-1000-0.9", 90, 0.9, 330 - 142, 330 - 224, 330, 10.47},
//	{L"��90Z-1000-1.0", 90, 1.0, 330 - 142, 330 - 224, 330, 11.57},
//	{L"��90Z-1000-1.2", 90, 1.2, 330 - 142, 330 - 224, 330, 13.77},
//
//	{L"��114Z-750-0.7", 114, 0.7, 250 - 126, 78, 250, 11.00}, /* TODO 1 -oMV : ��������� ������ ������ */
//	{L"��114Z-750-0.8", 114, 0.7, 250 - 126, 78, 250, 12.50},
//	{L"��114Z-750-0.9", 114, 0.7, 250 - 126, 78, 250, 14.00},
//	{L"��114Z-750-1.0", 114, 0.7, 250 - 126, 78, 250, 15.40},
//	{L"��114Z-750-1.2", 114, 0.7, 250 - 126, 78, 250, 18.36},
//
//	{L"��153Z-900-0.8", 153, 0.8, 300 - 61, 61, 300, 11.89},
//	{L"��153Z-900-0.9", 153, 0.9, 300 - 61, 61, 300, 13.33},
//	{L"��153Z-900-1.0", 153, 1.0, 300 - 61, 61, 300, 14.67},
//	{L"��153Z-900-1.1", 153, 1.1, 300 - 61, 61, 300, 16.11},
//	{L"��153Z-900-1.2", 153, 1.2, 300 - 61, 61, 300, 17.44},
//	{L"��153Z-900-1.3", 153, 1.3, 300 - 61, 61, 300, 18.89},
//	{L"��153Z-900-1.4", 153, 1.4, 300 - 61, 61, 300, 20.22},
//	{L"��153Z-900-1.5", 153, 1.5, 300 - 61, 61, 300, 21.67},
//
//	{L"��157Z-800-0.8", 157, 0.8, 266.7 - 121, 62, 204.7 + 62, 13.38},
//	{L"��157Z-800-0.9", 157, 0.9, 266.7 - 121, 62, 204.7 + 62, 15.00},
//	{L"��157Z-800-1.0", 157, 1.0, 266.7 - 121, 62, 204.7 + 62, 16.50},
//	{L"��157Z-800-1.1", 157, 1.1, 266.7 - 121, 62, 204.7 + 62, 18.13},
//	{L"��157Z-800-1.2", 157, 1.2, 266.7 - 121, 62, 204.7 + 62, 19.63},
//	{L"��157Z-800-1.3", 157, 1.3, 266.7 - 121, 62, 204.7 + 62, 21.25},
//	{L"��157Z-800-1.4", 157, 1.4, 266.7 - 121, 62, 204.7 + 62, 22.75},
//	{L"��157Z-800-1.5", 157, 1.5, 266.7 - 121, 62, 204.7 + 62, 24.38},

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
CorrugatedSheet CorrugatedSheetsData::get_corrugated_sheet(int index)
{
    return corrugated_sheets_list_[index];
}
double CorrugatedSheet::get_h_b(bool wider_flange_up)const
{
	if (wider_flange_up)
		return(b_narrower_fl_ + b_ap_wider_fl_) / (2 * S_n_) * h_n_;

	return (b_wider_fl_ + b_ap_narrower_fl_) / (2 * S_n_) * h_n_;
}
double CorrugatedSheet::get_b_0(bool wider_flange_up)
{
	if (wider_flange_up)
		return (b_ap_wider_fl_ + b_narrower_fl_) / 2;

	return (b_ap_narrower_fl_ + b_wider_fl_) / 2;
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
								  double b_ap_wider_fl, double b_ap_narrower_fl,
								  double b_wider_fl, double b_narrower_fl, double S_n, double w):
	name_(name),
	h_n_(h_n),
	t_(t),
	b_ap_wider_fl_(b_ap_wider_fl),
	b_ap_narrower_fl_(b_ap_narrower_fl),
	b_wider_fl_(b_wider_fl),
	b_narrower_fl_(b_narrower_fl),
	S_n_(S_n),
	w_(w * grav_accelerate / mm2){}

