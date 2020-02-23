//---------------------------------------------------------------------------

#ifndef CorrugatedSheetH
#define CorrugatedSheetH

#include<System.hpp>
#include<map>

class CorrugatedSheet{
public:
	CorrugatedSheet();
	CorrugatedSheet (String name, double h, double t, double w);
	String get_name() const {return name_;}
	double get_height() const {return h_;}
	double get_thickness() const {return t_;}
	double get_weight() const {return w_;}
protected:
	String name_ {""};
	double h_ {0.};
	double t_ {0.};
	double w_ {0.}; //масса 1м2
};

using CorrugatedSheetsMap=std::map<String, CorrugatedSheet> ;

extern CorrugatedSheetsMap corrugated_sheets_map;

//---------------------------------------------------------------------------
#endif
