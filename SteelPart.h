//---------------------------------------------------------------------------

#ifndef SteelPartH
#define SteelPartH
//---------------------------------------------------------------------------
#include <iostream>
#include <ostream>
//---------------------------------------------------------------------------
#include "ISection.h"
#include "Steel.h"


class SteelPart{
public:
	SteelPart();
	SteelPart(ISection I_section, Steel I_steel);

	void save(ostream& ostr) const;
	void load(istream& istr);
	void set_default_values();

	ISection get_section() const {return I_section_;}
	Steel get_steel() const {return I_steel_;}

	double get_Q_Rd();
	double get_M_Rd();

private:
	ISection I_section_;
	Steel I_steel_;

	bool steel_part_calculated_ = false;

	double Q_Rd_ = 0.; //несущая способность сечения на сдвиг. В расчёте принята только стенка
	double M_Rd_ = 0;

	void calculate_steel_part();
	double calculate_Q_Rd();
	double calculate_M_Rd();
};
#endif
