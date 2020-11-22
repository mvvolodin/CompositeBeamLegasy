//---------------------------------------------------------------------------

#ifndef uSlabConcreteSectionH
#define uSlabConcreteSectionH

#include <string>
#include "uGeneralConcreteSection.h"
#include "uRebar.h"

class SlabConcreteSection: public GeneralConcreteSection{
public:
	SlabConcreteSection(double const  h_f,
						double const h_n,
						double const  L,
						double const  B_l,
						double const  B_r,
                        double const  b_uf,
						bool const  is_end_beam,
						Rebars const & rebars);
	~SlabConcreteSection();
	std::u16string slab_type()const override;
	double h() const override;
	double h_n() const override;
	double C_b() const override;
	double SW(double dens) const override;
private:
	double const h_n_;

};
//---------------------------------------------------------------------------
#endif
