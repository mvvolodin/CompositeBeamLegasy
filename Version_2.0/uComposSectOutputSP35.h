//---------------------------------------------------------------------------
#ifndef uComposSectOutputSP35H
#define uComposSectOutputSP35H
//---------------------------------------------------------------------------
#include <vector>
#include <Vcl.Grids.hpp>
#include "uWord_Automation.h"
#include "uGlobGeom.h"
#include "uPlastCoeff.h"
#include "Logger.h"
//---------------------------------------------------------------------------
enum class DesignCase;
//---------------------------------------------------------------------------
class ComposSectOutputSP35{
public:
	ComposSectOutputSP35(Node const & nd,

				   double const M_1a,
				   double const M_1b,
				   double const M_2c,
				   double const M_2d,
				   double const M_total,

				   double const Q_1a,
				   double const Q_1b,
				   double const Q_2c,
				   double const Q_2d,
				   double const Q_total,

				   double const R_1a,
				   double const R_1b,
				   double const R_2c,
				   double const R_2d,
                   double const R_total,

				   double const f_1a,
				   double const f_1b,
				   double const f_2c,
				   double const f_2d,
                   double const f_total,

				   double const sigma_b_shr,
				   double const sigma_b_kr,
				   double const sigma_r_shr,
				   double const sigma_r_kr,

				   double const sigma_bi,
				   double const sigma_ri,

				   double const sigma_b,
				   double const sigma_r,

                   PlastCoeffList const & pl_coeff,

				   DesignCase des_case,

				   double const upper_fl_ratio,
				   double const lower_fl_ratio,
				   double const conc_ratio,
				   double const shear_ratio,
				   double const st_sect_ratio);

	Node node()const;

	double M_1a()const;
	double M_1b()const;
	double M_2c()const;
	double M_2d()const;
	double M_total()const;

	double const sigma_b_shr()const{return sigma_b_shr_;}
	double const sigma_b_kr()const{return sigma_b_kr_;}
	double const sigma_r_shr()const{return sigma_r_shr_;}
	double const sigma_r_kr()const{return sigma_r_kr_;};
	double const sigma_b()const{return sigma_b_;}
	double const sigma_r()const{return sigma_r_;}

	PlastCoeffList pl_coeff()const {return pl_coeff_;}

	double Q_1a()const;
	double Q_1b()const;
	double Q_2c()const;
	double Q_2d()const;
	double Q_total()const;

	double R_1a()const;
	double R_1b()const;
	double R_2c()const;
	double R_2d()const;
	double R_total()const;

	double f_1a()const;
	double f_1b()const;
	double f_2c()const;
	double f_2d()const;
	double f_total()const;

	double upper_fl_ratio()const{return upper_fl_ratio_;}
	double lower_fl_ratio()const{return lower_fl_ratio_;}
	double conc_ratio()const{return conc_ratio_;}
	double shear_ratio()const{return shear_ratio_;}
	double st_sect_ratio()const{return st_sect_ratio_;}

	double max_direct_str_ratio()const;

    void fill_grid_with_max_direct_str_data(TStringGrid* str_grid)const;

	#ifndef NDEBUG
	void print_data_to_logger(TFormLogger const & log)const;
	#endif

	void print(TWord_Automation & report)const;

private:
	Node const nd_;

	double const M_1a_ = 0.;
	double const M_1b_ = 0.;
	double const M_2c_ = 0.;
	double const M_2d_ = 0.;
	double const M_total_ = 0.;

	double const Q_1a_ = 0.;
	double const Q_1b_ = 0.;
	double const Q_2c_ = 0.;
	double const Q_2d_ = 0.;
	double const Q_total_ = 0.;

	double const R_1a_ = 0.;
	double const R_1b_ = 0.;
	double const R_2c_ = 0.;
	double const R_2d_ = 0.;
	double const R_total_ = 0.;

	double const f_1a_ = 0.;
	double const f_1b_ = 0.;
	double const f_2c_ = 0.;
	double const f_2d_ = 0.;
	double const f_total_ = 0.;

	double const sigma_b_ = 0.;
	double const sigma_r_ = 0.;

	PlastCoeffList const pl_coeff_;

	double const sigma_b_shr_ = 0.;
	double const sigma_b_kr_ = 0.;
	double const sigma_r_shr_ = 0.;
	double const sigma_r_kr_ = 0.;
	double const sigma_bi_ = 0.;
	double const sigma_ri_ = 0.;

	DesignCase const des_case_;

	double const upper_fl_ratio_ = 0.;
	double const lower_fl_ratio_ = 0.;
	double const conc_ratio_ = 0.;
	double const shear_ratio_ = 0.;
	double const st_sect_ratio_ = 0.0;

	void print_max_direct_str_ratio_sect(TWord_Automation &)const;
};


//---------------------------------------------------------------------------
#endif
