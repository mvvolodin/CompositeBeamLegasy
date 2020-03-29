//---------------------------------------------------------------------------

#ifndef SteelPartH
#define SteelPartH
//---------------------------------------------------------------------------
#include <iostream>
#include <ostream>
//---------------------------------------------------------------------------
#include "ISectionInitialDataUnit.h"
#include "ISection.h"
#include "Steel.h"


class SteelPart{
public:
	SteelPart();
	SteelPart(ISection I_section, Steel I_steel);
	void calculate();
	void save(ostream& ostr) const;
	void load(istream& istr);
	void set_default_values();
	ISection get_section() const {return I_section_;}
	Steel get_steel() const {return I_steel_;}
	double get_Q_Rd() const {return Q_Rd_;}

private:
	ISection I_section_;
	Steel I_steel_;
	double Q_Rd_ = 0.; //несущая способность сечения на сдвиг. В расчёте принята только стенка
	void calc_Q_Rd();
	double get_h_w() const {return I_section_.get_h_w();};
	double get_t_w() const {return I_section_.get_t_w();};
	double get_R_y() const {return I_steel_.get_R_y();};

};
#endif
