//---------------------------------------------------------------------------

#ifndef uComposSectGeomSP266H
#define uComposSectGeomSP266H

#include "uGeneralConcreteSection.h"
#include "uGeneralSteelSection.h"
#include "uConcrete.h"
#include "uSteel.h"

//#define NDEBUG

#ifndef NDEBUG
#include "uFrmLogger.h"
#endif

class ComposSectGeomSP266{

public:

	ComposSectGeomSP266(Steel const & steel,
					   GeneralSteelSection const & st_sect,
					   Concrete const & concrete,
					   GeneralConcreteSection const & conc_sect);

	double E_rs()const;
	double E_b()const;
	double E_st()const;

	double alpha_b()const;
	double alpha_s()const;

	double R_y()const;
	double R_b()const;
	double R_s()const;

	double Z_f1_st()const;
	double Z_f2_st()const;
	double A_st()const;
	double W_f2_st()const;
	double W_f1_st()const;
	double I_st()const;

	double A_b()const;
	double I_b()const;

	double Z_b_st()const;
	double Z_b_red()const;
	double Z_st_red()const;
	double A_red()const;
	double W_b_red()const;
	double I_red()const;

	double eps_shr()const;

#ifndef NDEBUG
	void print_data_to_logger(TFormLogger const & log)const;
#endif

private:
	Steel const & steel_; // идельным решением, на мой взгляд, является перемещение объекта
	GeneralSteelSection const  & st_sect_;
	Concrete const & concrete_;
	GeneralConcreteSection const & conc_sect_;

	void calculate();

	double alpha_s_= 0.;//коэффициент приведения к стали
	double alpha_b_= 0.;//коэффициент приведения к бетону

	double H_red_= 0.; //высота композитного сечения
	double A_red_= 0.; //площадь сталежелезобетонного сечения
	double S_red_= 0.;//Статический момент инерции сталежелезобетонного сечения относительно Ц.Т. стального сечения
	double I_red_= 0.;  //Момент инерции сталежелезобетонного сечения приведённого к металлу
	double W_b_red_= 0.;//Момент сопротивления сталежелезобетонного сечения для Ц.Т. железобетонной плиты

	double Z_st_red_= 0.;//Расстояние между центром тяжести стального и сталежелезобетонного сечения
	double Z_b_red_= 0.;  //Расстояние между Ц.Т. бетонного и сталежелезобетонного сечения

	double Z_st_s_u_= 0.;//расстояние между Ц.Т. стальной балки и верхней арматурой
	double Z_st_s_l_= 0.;//расстояние между Ц.Т. стальной балки и нижней арматурой
	double Z_b_st_= 0.; //Расстояние между центрами тяжести плиты и стальной балки


};

//---------------------------------------------------------------------------
#endif

