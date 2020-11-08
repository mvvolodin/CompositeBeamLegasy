//---------------------------------------------------------------------------

#ifndef uComBeamOutputSP35H
#define uComBeamOutputSP35H
//---------------------------------------------------------------------------
#include "uSectOutputSP35.h"
#include "uComposSectGeomSP35.h"
#include "uWord_Automation.h"
//---------------------------------------------------------------------------
class ComBeamOutputSP35{
public:

	ComBeamOutputSP35(ComposSectGeomSP35 const com_sect,
					  ComposSectGeomSP35 const com_sect_shr,
					  ComposSectGeomSP35 const com_sect_kr,
					  std::vector<SectOutputSP35> const sect_outp_list);

	void print_data_to_report(TWord_Automation & report)const;

private:
	ComposSectGeomSP35 const com_sect_;
	ComposSectGeomSP35 const com_sect_shr_;
	ComposSectGeomSP35 const com_sect_kr_;

	std::vector<SectOutputSP35> const sect_outp_list_;

	SectOutputSP35 const & max_st_sect_ratio_sect()const;
	SectOutputSP35 const & max_direct_str_ratio_sect()const;
	SectOutputSP35 const & max_shear_str_ratio_sect()const;

};
//---------------------------------------------------------------------------
#endif
