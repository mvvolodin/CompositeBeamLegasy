//---------------------------------------------------------------------------

#ifndef uIntForcesCalculatorH
#define uIntForcesCalculatorH

#include <map>
#include "uLoads.h"
#include "uGeometry.h"

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
	double R_total(int sup_index)const;

	std::vector<double> R_1a()const;
	std::vector<double> R_1b()const;
	std::vector<double> R_2c()const;
	std::vector<double> R_2d()const;
	std::vector<double> R_total()const;

	double M_1a(double x)const;
	double M_1b(double x)const;
	double M_2c(double x)const;
	double M_2d(double x)const;
	double M_total(double x)const;

	double Q_1a(double x)const;
	double Q_1b(double x)const;
	double Q_2c(double x)const;
	double Q_2d(double x)const;
	double Q_total(double x)const;

	double f_1a(double x)const;
	double f_1b(double x)const;
	double f_2c(double x)const;
	double f_2d(double x)const;

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
