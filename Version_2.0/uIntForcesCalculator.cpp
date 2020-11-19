//---------------------------------------------------------------------------

#pragma hdrstop

#include "uIntForcesCalculator.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------

IntForcesCalculator::IntForcesCalculator(int const s_num,
										 double const L,
										 double const B,
										 Loads const & loads):
										 	s_num_(s_num),
											L_(L),
											B_(B),
											loads_(loads){}
std::map<double, double> IntForcesCalculator::R_1a()const
{
	return R_uniform_load(loads_.Ia_design_LCC(), s_num_);
}
std::map<double, double> IntForcesCalculator::R_1b()const
{
	return R_uniform_load(loads_.Ib_design_LCC(), s_num_);
}
std::map<double, double> IntForcesCalculator::R_2c()const
{
	return R_uniform_load(loads_.Ib_design_LCC(), 0);
}
std::map<double, double> IntForcesCalculator::R_2d()const
{
	return R_uniform_load(loads_.IIb_design_LCC(), 0);
}
std::map<double, double> IntForcesCalculator::P_2a()const
{
	std::map<double, double> PX = R_uniform_load(loads_.Ib_design_LCC(), s_num_);

	PX.at(0) = 0;
	PX.at(L_) = 0;

	return PX;
}

double IntForcesCalculator::M_1a(double x)const
{
	return M_uniform_load(x, loads_.Ia_design_LCC(), s_num_);
}
double IntForcesCalculator::M_1b(double x)const
{
	return M_uniform_load(x, loads_.Ib_design_LCC(), s_num_);
}
double IntForcesCalculator::M_2c(double x)const
{
	std::map<double, double> R_Ib_design_named_list = R_uniform_load(loads_.Ib_design_LCC(), s_num_);

	double L0 = 0.;

	switch(s_num_)
	{
		case(0):

			return 0;

		case(1):

			L0 = L_ / 2;

			return M_point_load(x, R_Ib_design_named_list.at(L0), L0);

		case(2):

			L0 = L_ / 3;

			return M_point_load(x, R_Ib_design_named_list.at(L0), L0) +
				M_point_load(x, R_Ib_design_named_list.at(2 * L0), 2 * L0);

		case(3):

			L0 = L_ / 4;

			return M_point_load(x, R_Ib_design_named_list.at(L0), L0) +
				M_point_load(x, R_Ib_design_named_list.at(2 * L0), 2 * L0) +
				M_point_load(x, R_Ib_design_named_list.at(3 * L0), 3 * L0);
	}
}
double IntForcesCalculator::M_2d(double x)const
{
	return M_uniform_load(x, loads_.IIb_design_LCC(), 0);
}


double IntForcesCalculator::Q_1a(double x)const
{
	return Q_uniform_load(x, loads_.Ia_design_LCC(), s_num_);
}
double IntForcesCalculator::Q_1b(double x)const
{
	return Q_uniform_load(x, loads_.Ib_design_LCC(), s_num_);
}
double IntForcesCalculator::Q_2c(double x)const
{
	double L0 = 0.;

	switch(s_num_)
	{
		case(0):

			return 0;

		case(1):

			L0 = L_ / 2;

			return Q_point_load(x, P_2a().at(L0), L0);

		case(2):

			L0 = L_ / 3;

			return Q_point_load(x, P_2a().at(L0), L0) +
				Q_point_load(x, P_2a().at(2 * L0), 2 * L0);

		case(3):

			L0 = L_ / 4;

			return Q_point_load(x, P_2a().at(L0), L0) +
				Q_point_load(x, P_2a().at(2 * L0), 2 * L0) +
				Q_point_load(x, P_2a().at(3 * L0), 3 * L0);
	}
}
double IntForcesCalculator::Q_2d(double x)const
{
	return Q_uniform_load(x, loads_.IIb_design_LCC(), 0);
}


double IntForcesCalculator::f_1a(double x)const
{
	std::map<double, double> R_Ia_named_list = R_uniform_load(loads_.Ia_LCC(), s_num_);

	double L0 = 0.;

    	switch(s_num_)
	{
		case(0):

		return f_uniform_load(x, loads_.Ia_LCC());

		case(1):

			L0 = L_ / 2;

			return f_uniform_load(x, loads_.Ia_LCC()) +
				f_point_load(x, -1 * R_Ia_named_list.at(L0), L0);

		case(2):

			L0 = L_ / 3;

			return f_uniform_load(x, loads_.Ia_LCC()) +
				f_point_load(x, -1 * R_Ia_named_list.at(L0), L0) +
				f_point_load(x, -1 * R_Ia_named_list.at(2 * L0), 2 * L0);

		case(3):

			L0 = L_ / 4;

			return f_uniform_load(x, loads_.Ia_LCC()) +
				f_point_load(x, -1 * R_Ia_named_list.at(L0), L0) +
				f_point_load(x, -1 * R_Ia_named_list.at(2 * L0), 2 * L0) +
				f_point_load(x, -1 * R_Ia_named_list.at(3 * L0), 3 * L0);
	}

}
double IntForcesCalculator::f_1b(double x)const
{
	std::map<double, double> R_Ib_named_list = R_uniform_load(loads_.Ib_LCC(), s_num_);

	double L0 = 0.;

		switch(s_num_)
	{
		case(0):

		return f_uniform_load(x, loads_.Ib_LCC());

		case(1):

			L0 = L_ / 2;

			return f_uniform_load(x, loads_.Ib_LCC()) +
				f_point_load(x, -1 * R_Ib_named_list.at(L0), L0);

		case(2):

			L0 = L_ / 3;

			return f_uniform_load(x, loads_.Ib_LCC()) +
				f_point_load(x, -1 * R_Ib_named_list.at(L0), L0) +
				f_point_load(x, -1 * R_Ib_named_list.at(2 * L0), 2 * L0);

		case(3):

			L0 = L_ / 4;

			return f_uniform_load(x, loads_.Ib_LCC()) +
				f_point_load(x, -1 * R_Ib_named_list.at(L0), L0) +
				f_point_load(x, -1 * R_Ib_named_list.at(2 * L0), 2 * L0) +
				f_point_load(x, -1 * R_Ib_named_list.at(3 * L0), 3 * L0);
	}
}
double IntForcesCalculator::f_2c(double x)const
{
	std::map<double, double> R_Ib_named_list = R_uniform_load(loads_.Ib_LCC(), s_num_);

	double L0 = 0.;

		switch(s_num_)
	{
		case(0):

		return 0;

		case(1):

			L0 = L_ / 2;

			return f_point_load(x, R_Ib_named_list.at(L0), L0);

		case(2):

			L0 = L_ / 3;

			return f_point_load(x, R_Ib_named_list.at(L0), L0) +
				f_point_load(x, R_Ib_named_list.at(2 * L0), 2 * L0);

		case(3):

			L0 = L_ / 4;

			return f_point_load(x, R_Ib_named_list.at(L0), L0) +
				f_point_load(x, R_Ib_named_list.at(2 * L0), 2 * L0) +
				f_point_load(x, R_Ib_named_list.at(3 * L0), 3 * L0);
	}
}
double IntForcesCalculator::f_2d(double x)const
{
	return f_uniform_load(x, loads_.IIb_LCC());
}

std::map<double, double> IntForcesCalculator::R_uniform_load(double q, int s_num)const
{
	std::map<double, double> R_named_list{};

	double L0 = 0.;

	switch(s_num)
	{
		case(0):

			L0 = L_;

			R_named_list.insert({0, 0.5 * q * L0});
			R_named_list.insert({L0, 0.5 * q * L0});

			return R_named_list;

		case(1):

			L0 = L_ / 2;

			R_named_list.insert({0, 0.375 * q * L0});
			R_named_list.insert({L0, 1.25 * q * L0});
			R_named_list.insert({2 * L0, 0.375 * q * L0});

			return R_named_list;

		case(2):

			L0 = L_ / 3;

			R_named_list.insert({0, 0.4 * q * L0});
			R_named_list.insert({L0, 1.1 * q * L0});
			R_named_list.insert({2 * L0, 1.1 * q * L0});
			R_named_list.insert({3 * L0, 0.4 * q * L0});

			return R_named_list;

		case(3):

			L0 = L_ / 4;

			R_named_list.insert({0, 0.393 * q * L0});
			R_named_list.insert({L0, 1.143 * q * L0});
			R_named_list.insert({2 * L0, 0.929 * q * L0});
			R_named_list.insert({3 * L0, 1.143 * q * L0});
			R_named_list.insert({4 * L0, 0.393 * q * L0});

			return R_named_list;
	}
}
double IntForcesCalculator::M_uniform_load(double x, double q, int s_num)const
{
	double L0 = 0.;
	std::map<double, double> R = R_uniform_load(q, s_num);

	switch(s_num)
	{
		case(0):

			L0 = L_;

			return R.at(0) * x - q * x * x / 2;

		case(1):

			L0 = L_ / 2;

			if(x <= L0)
				return R.at(0) * x - q * x * x / 2;
			return R.at(0) * x + R.at(L0) * (x - L0) - q * x * x / 2;

		case(2):

			L0 = L_ / 3;

			if(x <= L0)
				return R.at(0) * x - q * x * x / 2;
			if(L0 < x && x <= 2 * L0)
				return R.at(0) * x + R.at(L0) * (x - L0) - q * x * x / 2;
			return R.at(0) * x + R.at(L0) * (x - L0) + R.at(2 * L0) * (x - 2 * L0) - q * x * x / 2;

		case(3):

			L0 = L_ / 4;

			if(x <= L0)
				return R.at(0) * x - q * x * x / 2;
			 if(L0 < x && x <= 2 * L0)
				return R.at(0) * x + R.at(L0) * (x - L0) - q * x * x / 2;
			 if(2 * L0 < x && x <= 3 * L0)
				return R.at(0) * x + R.at(L0) * (x - L0) + R.at(2 * L0) * (x - 2 * L0) - q * x * x / 2;
			 return R.at(0) * x + R.at(L0) * (x - L0) + R.at(2 * L0) * (x - 2 * L0) + R.at(3 * L0) * (x - 3 * L0) - q * x * x / 2;
	}
}
double IntForcesCalculator::M_point_load(double x, double P, double x_P)const
{
	if(x < x_P) return P * (L_ - x_P) / L_ * x;

	return P * (L_ - x_P) / L_ * x - P * (x - x_P) ;
}
double IntForcesCalculator::Q_uniform_load(double x, double q, int s_num)const
{
	double L0 = 0.;
	std::map<double, double> R = R_uniform_load(q, s_num);

	switch(s_num)
	{
		case(0):

			L0 = L_;

			return R.at(0) - q * x;

		case(1):

			L0 = L_ / 2;

			if(x <= L0)
				return R.at(0) - q * x;
			return R.at(0) + R.at(L0) - q * x;

		case(2):

			L0 = L_ / 3;

			if(x <= L0)
				return R.at(0) - q * x;
			if(L0 < x && x <= 2 * L0)
				return R.at(0) + R.at(L0) - q * x;
			return R.at(0) + R.at(L0) + R.at(2 * L0) - q * x;

		case(3):

			L0 = L_ / 4;

			if(x <= L0)
				return R.at(0) - q * x;
			 if(L0 < x && x <= 2 * L0)
				return R.at(0) + R.at(L0) - q * x;
			 if(2 * L0 < x && x <= 3 * L0)
				return R.at(0) + R.at(L0) + R.at(2 * L0) - q * x;
			 return R.at(0) + R.at(L0) + R.at(2 * L0) +R.at(3 * L0) - q * x;
	}
}
double IntForcesCalculator::Q_point_load(double x, double P, double x_P)const
{
	double R = P * (L_ - x_P) / L_;
	return (x <= x_P) ? 1 * R : (R - P);
}
double IntForcesCalculator::f_uniform_load(double x, double q)const
{
	//https://en.wikipedia.org/wiki/Deflection_(engineering)
	// множитель -1 введён для гармонизации знаков с Феодосьевым
	return -1 * q * x * (L_ * L_ * L_ - 2 * L_ * x * x + x * x * x) / 24;
}
double IntForcesCalculator::f_point_load(double x, double P, double x_P)const
{
	//Феодосьев, 7е издание, пример 4.8, стр. 146
	if(x <= x_P)
		return P * (L_ - x_P) / (6 * L_) * (x * x * x - x * x_P * (2 * L_ - x_P));
	return
		P * x_P / (6 * L_) * (-1 * x * x * x + 3 * x * x * L_ - x * (2 * L_ * L_ + x_P * x_P) + x_P * x_P * L_) ;

	return 0.;
}


