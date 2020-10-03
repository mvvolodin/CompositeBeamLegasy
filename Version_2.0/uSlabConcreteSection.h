//---------------------------------------------------------------------------

#ifndef uSlabConcreteSectionH
#define uSlabConcreteSectionH

#include "uGeneralConcreteSection.h"
#include "uRebar.h"

class SlabConcreteSection: public GeneralConcreteSection{
public:
	SlabConcreteSection(const double h_f,
						const Rebar rebar,
						const double b,
						const double a_u,
						const double a_l,
						const double L,
						const double B_l,
						const double B_r,
						const double b_uf,
						const bool end_beam);

	double h() const override;
	double h_n() const override;
	double C_b() const override;

};
//---------------------------------------------------------------------------
#endif
