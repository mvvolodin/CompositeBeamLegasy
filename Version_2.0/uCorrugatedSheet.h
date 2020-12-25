//---------------------------------------------------------------------------

#ifndef uCorrugatedSheetH
#define uCorrugatedSheetH

#include<System.hpp>
#include<map>
#include<vector>

class CorrugatedSheet{
public:
	CorrugatedSheet();
	CorrugatedSheet (String name, double h_n, double t, double w);
	CorrugatedSheet (String name, double h_n, double t,
					 double b_ap_wider_fl, double b_ap_narrower_fl,
					 double b_wider_fl, double b_narrower_fl, double S_n, double w);
	String get_name() const {return name_;}
	double get_height() const {return h_n_;}
	double get_thickness() const {return t_;}
	double get_weight() const {return w_;}
	double get_h_b(bool wider_flange_up)const;
	double get_b_0(bool wider_flange_up);
private:
	String name_ = "";
	double h_n_ = 0.;// высота настила
	double t_ = 0.; // толщина настила
	double b_ap_wider_fl_ = 0.; //расстояние между внутренними гранями широких полок
	double b_ap_narrower_fl_ = 0.; //расстояние между внутренними гранями узких полок
	double b_wider_fl_ = 0.;//ширина широкой полки
	double b_narrower_fl_ = 0.;// ширина узкой полки
	double S_n_ = 0.;// шаг нижних полок
	double w_ {0.}; //масса 1м2
};

class CorrugatedSheetsData{
public:
	static CorrugatedSheet get_corrugated_sheet(const String& name);
	static CorrugatedSheet get_corrugated_sheet(int index);
	static std::vector<String> get_corrugated_sheet_names();
private:
	static std::vector<CorrugatedSheet> corrugated_sheets_list_;
};



//---------------------------------------------------------------------------
#endif
