//---------------------------------------------------------------------------

#ifndef uIntForcesCalculatorH
#define uIntForcesCalculatorH

#include <map>
#include "uLoads.h"
#include "uGeometry.h"

//---------------------------------------------------------------------------
class IntForcesCalculator{
	public:
	IntForcesCalculator(SupportsNumber const s_num,
						double const L,
						double const B,
						Loads const & loads);

	std::map<double, double> R_1a()const;
	std::map<double, double> R_1b()const;
	std::map<double, double> R_2c()const;
	std::map<double, double> R_2d()const;

	std::map<double, double> P_2a()const;

	double M_1a(double x)const;
	double M_1b(double x)const;
	double M_2c(double x)const;
	double M_2d(double x)const;

	double Q_1a(double x)const;
	double Q_1b(double x)const;
	double Q_2c(double x)const;
	double Q_2d(double x)const;

	double f_1a(double x)const;
	double f_1b(double x)const;
	double f_2c(double x)const;
	double f_2d(double x)const;

private:

	SupportsNumber const s_num_;
	double const L_;
	double const B_;
	Loads const & loads_;

	double M_point_load(double x, double P, double x_P)const;
	double M_uniform_load(double x, double q, SupportsNumber s_num)const;
	double Q_point_load(double x, double P, double x_P)const;
	double Q_uniform_load(double x, double q, SupportsNumber s_num)const;
	double f_point_load(double x, double P, double x_P)const;
	double f_uniform_load(double x, double q)const;

	std::map<double, double> R_uniform_load(double q, SupportsNumber s_num)const;
};

#endif
