﻿//---------------------------------------------------------------------------

#ifndef uIntForcesCalculatorH
#define uIntForcesCalculatorH

#include <map>
#include <vector>
#include "uLoads.h"

//---------------------------------------------------------------------------
class IntForcesCalculator{
	public:
	IntForcesCalculator(int const s_num,
						double const L,
						Loads const & loads);

	double R_1a(int sup_index)const;
	double R_1b(int sup_index)const;
	double R_2c(int sup_index)const;
	double R_2d(int sup_index)const;

	double M_1a(double x)const;
	double M_1b(double x)const;
	double M_2c(double x)const;
	double M_2d(double x)const;
	double M_2d_DL(double x)const;  //подумать о добавлении дополнительного этапа работы.
									//В этом случае, постоянные нагрузки второй стадии будут отнесены к этапу 'd', а
									//временные нагрузки второй стадии будут отнесены к этапу 'e'
	double Q_1a(double x)const;
	double Q_1b(double x)const;
	double Q_2c(double x)const;
	double Q_2d(double x)const;

	double f_1a(double x)const;
	double f_1b(double x)const;
	double f_2c(double x)const;
	double f_2d(double x)const;
	double f_2d_DL(double x)const;

	double fact_quasi_perm_load()const {return loads_.fact_quasi_perm_load();}

private:

	int const s_num_;
	double const L_;
	Loads const  loads_;

	double M_point_load(double x, double P, double x_P)const;
	double M_uniform_load(double x, double q, int s_num)const;
	double Q_point_load(double x, double P, double x_P)const;
	double Q_uniform_load(double x, double q, int s_num)const;
	double f_point_load(double x, double P, double x_P)const;
	double f_uniform_load(double x, double q)const;

	std::vector<double> R_uniform_load(double q, int s_num)const;
};

#endif
