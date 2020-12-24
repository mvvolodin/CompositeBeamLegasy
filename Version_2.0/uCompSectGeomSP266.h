//---------------------------------------------------------------------------
#ifndef uCompSectGeomSP266H
#define uCompSectGeomSP266H
//---------------------------------------------------------------------------
#include <memory>
#include "uGeneralConcreteSection.h"
#include "uGeneralSteelSection.h"
#include "uConcrete.h"
#include "uSteel.h"
//---------------------------------------------------------------------------
class CompSectGeomSP266{
	enum class NA_Location{
		CONCRETE,
		UPPER_FLANGE,
		WEB,
		NO_SOLUTION
	};
	struct NeutralAxis{
		NA_Location na_location_;
		double x_na_; //Расстояние от наружней грани сталежелезобетонной балки до нейтральной оси
	};
public:
	CompSectGeomSP266() = default;
	CompSectGeomSP266(Steel const & steel,
					   std::unique_ptr<GeneralSteelSection>  st_sect,
					   Concrete const & concrete,
					   std::unique_ptr<GeneralConcreteSection> conc_sect);
	double E_s()const {return conc_sect_ -> rebars().rebar().E_s();}
	double E_b()const{return concrete_.get_E_b();}
	double E_b_tau()const {return concrete_.get_E_b_tau();}
	double E_st()const {return steel_.get_E_st();}

	double alpha_b()const {return alpha_b_;}
	double alpha_s()const {return alpha_s_;}

	double R_y()const {return steel_.get_R_y();}
	double R_b()const {return concrete_.get_R_b();}
	double R_s()const {return conc_sect_ -> rebars().rebar().R_s();}

	double eps_b_lim() const {return concrete_.get_epsilon_b_lim();}

	double A_st()const {return st_sect_ -> area();}
	double A_f2()const {return st_sect_ -> area_upper_fl();}
	double A_w()const {return st_sect_ -> area_web();}
	double W_f1_st()const{return st_sect_ -> modulus_lower_fl();}
	double W_f2_st()const{return st_sect_ -> modulus_upper_fl();}
	double I_st()const{return st_sect_ -> inertia();}

	double b_sl()const{return conc_sect_ -> b_sl();}
	double A_b()const{return conc_sect_ -> A_b();}
	double I_b()const{return conc_sect_ -> I_b();}

	double M_Rd()const{return M_Rd_;}

	double Z_b_st()const{return Z_b_st_;}

	double H_red()const{return H_red_;}
	double A_red()const{return A_red_;}
	double W_b_red()const{return W_b_red_;}
	double W_b_st()const{return W_b_st_;}
	double I_red()const{return I_red_;}
	double eps_shr()const{return concrete_.eps_shr();}

	double A_s()const;

	void print(TWord_Automation & report)const;
	void fill_grid(TStringGrid* str_grid)const;
	GeneralSteelSection const * const st_sect()const;
	GeneralConcreteSection const * const conc_sect()const;

#ifndef NDEBUG
	void print_data_to_logger(TFormLogger const & log)const;
#endif

private:

	Steel steel_;
	std::unique_ptr<GeneralSteelSection> st_sect_;
	Concrete concrete_;
	std::unique_ptr<GeneralConcreteSection> conc_sect_;

	void calculate();
	NeutralAxis calc_neutral_axis();
	void calc_rigid_plastic_moment();

	double alpha_s_;//коэффициент приведения к стали
	double alpha_b_;//коэффициент приведения к бетону

	double H_red_; //высота композитного сечения
	double A_red_; //площадь сталежелезобетонного сечения
	double S_red_;//Статический момент инерции сталежелезобетонного сечения относительно Ц.Т. стального сечения
	double I_red_;  //Момент инерции сталежелезобетонного сечения приведённого к металлу
	double W_b_red_;//Момент сопротивления сталежелезобетонного сечения для Ц.Т. железобетонной плиты

	double W_b_st_;//Условный момент сопротивления на уровне центра тяжести сечения бетона

	double Z_st_s_u_;//расстояние между Ц.Т. стальной балки и верхней арматурой
	double Z_st_s_l_;//расстояние между Ц.Т. стальной балки и нижней арматурой
	double Z_b_st_; //Расстояние между центрами тяжести плиты и стальной балки

	double Z_st_red_;//Расстояние между Ц.Т. сечений стальной и сталежелезобетонной балок
	double Z_b_red_;  //Расстояние между Ц.Т. бетонного и сталежелезобетонного сечения
	double Z_s_u_red_;//Расстояние между Ц.Т. сталежелезобетонного сечения и верхней арматурой
	double Z_s_l_red_;//Расстояние между Ц.Т. сталежелезобетонного сечения и нижней арматурой

   	double M_Rd_;
};

//---------------------------------------------------------------------------
#endif
