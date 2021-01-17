//---------------------------------------------------------------------------
#ifndef uCompSectGeomSP35H
#define uCompSectGeomSP35H
//---------------------------------------------------------------------------
#include <memory>
#include <Vcl.Grids.hpp>
#include "uGeneralConcreteSection.h"
#include "uGeneralSteelSection.h"
#include "uConcreteSP35.h"
#include "uSteel.h"
#include "uWord_Automation.h"
#include "Logger.h"
//---------------------------------------------------------------------------
class CompSectGeomSP35{

public:

	enum class ConcStateConsid{
		normal,
		shrink,
		creep,
	};
	CompSectGeomSP35() = default;
	CompSectGeomSP35(Steel const & steel,
		std::unique_ptr<GeneralSteelSection> st_sect,
		ConcreteSP35 const & concrete,
		std::unique_ptr<GeneralConcreteSection> conc_sect,
		ConcStateConsid const state);

	double E_rs()const{return conc_sect_ -> rebars().rebar().E_rs();}
	double E_b()const{return concrete_.E_b();}
	double E_b_shr()const{return concrete_.E_b_shr();}
	double E_st()const{return steel_.get_E_st();}

	double n_b()const{return n_b_;}
	double n_r()const{return n_r_;}

	double R_y()const{return steel_.get_R_y();}
	double R_b()const{return concrete_.R_b();}
	double R_r()const{return conc_sect_ -> rebars().rebar().R_s();}

	double eps_b_lim() const{return concrete_.eps_b_lim();}

	double A_s()const{return st_sect_ -> A_s();}
	double A_s2()const{return st_sect_ -> A_s2_s();}
	double A_s1()const{return st_sect_ -> A_s1_s();}
    double A_w()const{return st_sect_ -> A_w();}
	double W_s1_s()const{return st_sect_ -> W_s1_s();}
	double W_s2_s()const{return st_sect_ -> W_s2_s();}
	double I_s()const{return st_sect_ -> I_s();}
	double smaller_fl_to_larger_fl_ratio() const {return st_sect_ ->
		smaller_fl_to_larger_fl_ratio(); }
	double smaller_fl_area_to_web_area_ratio()const {return st_sect_ ->
		smaller_fl_area_to_web_area_ratio();}
	double smaller_fl_area_plus_web_area_to_total_area_ratio() const {
		return st_sect_ -> smaller_fl_area_plus_web_area_to_total_area_ratio();}

	double A_st()const{return A_st_;}
	double S_st()const{return A_st_ * Z_st_stb();}

	double b_sl()const{return conc_sect_ -> des_width();}
	double A_b()const{return conc_sect_ -> area();}
	double I_b()const{return conc_sect_ -> inertia();}

	double H_stb()const{return H_stb_;}
	double Z_b_s()const{return Z_b_s_;}
	double Z_b_stb()const{return Z_b_stb_;}
	double Z_b_st()const{return Z_b_st_;}
	double Z_s_stb()const{return Z_s_stb_;}
	double Z_st_stb()const{return Z_s_stb_ - Z_s_st_;}
	double A_stb()const{return A_stb_;}
	double W_b_stb()const{return W_b_stb_;}
	double W_b_s()const{return W_b_s_;}
	double I_stb()const{return I_stb_;}
	double eps_shr()const{return concrete_.eps_shr();}

	double A_r()const{return conc_sect_ -> rebars_area();}

	void print(TWord_Automation & report)const;

	void fill_steel_sect_grid(TStringGrid* str_grid)const;
	void fill_conc_sect_grid(TStringGrid* str_grid)const;
	void fill_comp_sect_grid(TStringGrid* str_grid)const;

	#ifdef DEBUG_COMP_SECT_SP35
	void log()const;
	#endif

private:

	Steel steel_;
	std::unique_ptr<GeneralSteelSection> st_sect_;
	ConcreteSP35 concrete_;
	std::unique_ptr<GeneralConcreteSection> conc_sect_;

	void calculate(double const E_b);
	void calculate(ConcStateConsid conc_st_consid);
	void calculate_steel_sect_with_rebars();
	double E_ef_kr()const;

	double n_r_;//коэффициент приведения к стали
	double n_b_;//коэффициент приведения к бетону

	double Z_b_st_;//Расстояние между Ц.Т.бетонного сечения и стальной части включая арматуру
	double Z_s_st_; //Расстояние между Ц.Т. сечений стальной балки и стальной части включая арматуру
	double A_st_;//Площадь стальной части сечения включая арматуру
	double S_s_st_;//Статический момент стальной части сечения включая арматуру
	double I_st_;//Момент инерции стальной части сечения включая арматуру

	double H_stb_; //высота композитного сечения
	double A_stb_; //площадь сталежелезобетонного сечения
	double S_stb_;//Статический момент инерции сталежелезобетонного сечения относительно Ц.Т. стального сечения
	double I_stb_;  //Момент инерции сталежелезобетонного сечения приведённого к металлу
	double W_b_stb_;//Момент сопротивления сталежелезобетонного сечения для Ц.Т. железобетонной плиты

	double W_b_s_;//Условный момент сопротивления на уровне центра тяжести сечения бетона

	double Z_r_u_s_;//расстояние между Ц.Т. стальной балки и верхней арматурой
	double Z_r_l_s_;//расстояние между Ц.Т. стальной балки и нижней арматурой
	double Z_b_s_; //Расстояние между центрами тяжести плиты и стальной балки

	double Z_s_stb_;//Расстояние между Ц.Т. сечений стальной и сталежелезобетонной балок
	double Z_b_stb_;  //Расстояние между Ц.Т. бетонного и сталежелезобетонного сечения
	double Z_r_u_stb_;//Расстояние между Ц.Т. сталежелезобетонного сечения и верхней арматурой
	double Z_r_l_stb_;//Расстояние между Ц.Т. сталежелезобетонного сечения и нижней арматурой
};

//---------------------------------------------------------------------------
#endif
