//---------------------------------------------------------------------------

#ifndef uSlabConcreteSectionH
#define uSlabConcreteSectionH

#include "uGeneralConcreteSection.h"
#include "uRebar.h"

class SlabConcreteSection: public GeneralConcreteSection{
public:
	SlabConcreteSection(double const  h_f,
						Rebars const  rebars,
						double const  b,
						double const  a_u,
						double const  a_l,
						double const  L,
						double const  B_l,
						double const  B_r,
						double const  b_uf,
						bool const  end_beam);
	~SlabConcreteSection();
	double h() const override;
	double h_n() const override;
	double C_b() const override;

};
//---------------------------------------------------------------------------
#endif
