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
					 double b_ap_, double b, double S_n, double w);
	String get_name() const {return name_;}
	double get_height() const {return h_n_;}
	double get_thickness() const {return t_;}
	double get_weight() const {return w_;}
	double get_h_b();
private:
	String name_ = "";
	double h_n_ = 0.;// высота настила
	double t_ = 0.; // толщина настила
	double b_ap_ = 0.; //расстояние между внутренними гранями полок
	double b_ = 0.;// ширина нижней полки
	double S_n_ = 0.;// шаг нижних полок
	double w_ {0.}; //масса 1м2

	double h_b_;
	bool fully_initialized = false;


};

using CorrugatedSheetsMap=std::map<String, CorrugatedSheet> ;

extern CorrugatedSheetsMap corrugated_sheets_map;

class CorrugatedSheetsData{
public:
	static CorrugatedSheet get_corrugated_sheet(const String& name);
private:
	static std::vector<CorrugatedSheet> corrugated_sheets_list_;
};



//---------------------------------------------------------------------------
#endif
