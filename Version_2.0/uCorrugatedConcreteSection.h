//---------------------------------------------------------------------------

#ifndef uCorrugatedConcreteSectionH
#define uCorrugatedConcreteSectionH

#include "uGeneralConcreteSection.h"
#include "uCorrugatedSheet.h"
#include "uRebar.h"


class CorrugatedConcreteSection: public GeneralConcreteSection{
public:
	CorrugatedConcreteSection(
		CorrugatedSheet const & corr_sheet,
		double const  h_f,
		double const L,
		double const B_l,
		double const B_r,
		double const b_uf,
		bool const is_end_beam,
		Rebars const & rebars);
	~CorrugatedConcreteSection();

	double h() const override;
    double h_n() const override;
	double C_b() const override;
	double SW() const override;
	CorrugatedSheet corrugated_sheet()const;

private:
	CorrugatedSheet corr_sheet_;
};


//---------------------------------------------------------------------------
#endif
