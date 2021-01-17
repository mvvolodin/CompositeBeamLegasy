//---------------------------------------------------------------------------
#ifndef uCompSectsOutputSP266H
#define uCompSectsOutputSP266H
//---------------------------------------------------------------------------
#include <vector>
#include <Vcl.Grids.hpp>
#include "uGlobGeom.h"
#include "uLoads.h"
#include "uWorkingConditionsFactors.h"
#include "uCompSectGeomSP266.h"
#include "uCompSectOutputSP266.h"
#include "uWord_Automation.h"
//---------------------------------------------------------------------------
class CompSectsOutputSP266{
public:

	GlobGeom glob_geom_;
	Loads loads_;
	WorkingConditionsFactors work_cond_factrs_ ;

	CompSectGeomSP266 comp_sect_geom_;
	std::vector<CompSectOutputSP266> com_sects_;

	std::vector<double> x_lst()const;

	std::vector<double> end_sup_coord()const;
	std::vector<double> inter_sup_coord()const;
	std::vector<double> sup_coord()const;

	std::vector<double> M_1a_lst()const;
	std::vector<double> M_1b_lst()const;
	std::vector<double> M_2c_lst()const;
	std::vector<double> M_2d_lst()const;
	std::vector<double> M_total_lst()const;

	std::vector<double> Q_1a_lst()const;
	std::vector<double> Q_1b_lst()const;
	std::vector<double> Q_2c_lst()const;
	std::vector<double> Q_2d_lst()const;
	std::vector<double> Q_total_lst()const;

	std::vector<double> R_1a_lst()const;
	std::vector<double> R_1b_lst()const;
	std::vector<double> R_2c_lst()const;
	std::vector<double> R_2d_lst()const;
	std::vector<double> R_total_lst()const;

	std::vector<double> f_1a_lst()const;
	std::vector<double> f_1b_lst()const;
	std::vector<double> f_2c_lst()const;
	std::vector<double> f_2d_lst()const;
	std::vector<double> f_total_lst()const;

	CompSectOutputSP266 const & max_st_sect_ratio_sect()const;
	CompSectOutputSP266 const & max_direct_str_ratio_sect()const;
	CompSectOutputSP266 const & max_shear_str_ratio_sect()const;
	CompSectOutputSP266 const & max_rigid_pl_sect()const;

	void fill_ratios_grid(TStringGrid* str_grid)const;
	void fill_steel_sect_grid(TStringGrid* str_grid) const;
	void fill_conc_sect_grid(TStringGrid* str_grid) const;
	void fill_comp_sect_grid(TStringGrid* str_grid)const;

	void print(TWord_Automation & report)const;
};
//---------------------------------------------------------------------------
#endif

