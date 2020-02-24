//---------------------------------------------------------------------------

#ifndef SteelPartH
#define SteelPartH
//---------------------------------------------------------------------------
#include "ISectionInitialDataUnit.h"
#include "ISection.h"
#include "Steel.h"


class SteelPart{
public:
	SteelPart();
	SteelPart(ISection I_section, Steel I_steel);

	ISection get_I_section() const {return I_section_;}
	Steel get_I_steel() const {return I_steel_;}
	double get_Q_Rd() const {return Q_Rd_;}
	double get_E_st() const {return I_steel_.get_E_s();}
	double get_h_st() const {return I_section_.get_h_st();}
	double get_A_st() const {return I_section_.get_A_st();}

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
