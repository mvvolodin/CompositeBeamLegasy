//---------------------------------------------------------------------------

#pragma hdrstop

#include "uIntForcesCalculator.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------

IntForcesCalculator::IntForcesCalculator(int const s_num,
										 double const L,
										 Loads const & loads):
											s_num_(s_num),
											L_(L),
											loads_(loads){}
double IntForcesCalculator::R_1a(int sup_index)const
{
	return R_uniform_load(loads_.Ia_design_LCC(), s_num_)[sup_index];
}
double IntForcesCalculator::R_1b(int sup_index)const
{
	return R_uniform_load(loads_.Ib_design_LCC(), s_num_)[sup_index];
}
double IntForcesCalculator::R_2c(int sup_index)const
{
	return R_uniform_load(loads_.Ib_design_LCC(), 0)[sup_index];
}
double IntForcesCalculator::R_2d(int sup_index)const
{
	return R_uniform_load(loads_.IIb_design_LCC(), 0)[sup_index];
}
double IntForcesCalculator::R_total(int sup_index)const
{
	return R_uniform_load(loads_.total_design_LCC(), 0)[sup_index];
}
std::vector<double> IntForcesCalculator::R_1a()const
{
	return R_uniform_load(loads_.Ia_design_LCC(), s_num_);
}
std::vector<double> IntForcesCalculator::R_1b()const
{
	return R_uniform_load(loads_.Ib_design_LCC(), s_num_);
}
std::vector<double> IntForcesCalculator::R_2c()const
{
	return R_uniform_load(loads_.Ib_design_LCC(), 0);
}
std::vector<double> IntForcesCalculator::R_2d()const
{
	return R_uniform_load(loads_.IIb_design_LCC(), 0);
}
std::vector<double> IntForcesCalculator::R_total()const
{
	return R_uniform_load(loads_.total_design_LCC(), 0);
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
	std::vector<double> R_Ib_design_named_list = R_uniform_load(loads_.Ib_design_LCC(), s_num_);

	double L0 = 0.;

	switch(s_num_)
	{
		case(0):

			return 0;

		case(1):

			L0 = L_ / 2;

			return M_point_load(x, R_Ib_design_named_list[1], L0);

		case(2):

			L0 = L_ / 3;

			return M_point_load(x, R_Ib_design_named_list[1], L0) +
				M_point_load(x, R_Ib_design_named_list[2], 2 * L0);

		case(3):

			L0 = L_ / 4;

			return M_point_load(x, R_Ib_design_named_list[1], L0) +
				M_point_load(x, R_Ib_design_named_list[2], 2 * L0) +
				M_point_load(x, R_Ib_design_named_list[3], 3 * L0);
	}
}
double IntForcesCalculator::M_2d(double x)const
{
	return M_uniform_load(x, loads_.IIb_design_LCC(), 0);
}
double IntForcesCalculator::M_total(double x)const
{
	return M_uniform_load(x, loads_.total_design_LCC(), 0);
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

	std::vector<double> P_2a_lst = R_uniform_load(loads_.Ib_design_LCC(), s_num_);

	switch(s_num_)
	{
		case(0):

			return 0;

		case(1):

			L0 = L_ / 2;

			return Q_point_load(x, P_2a_lst[1], L0);

		case(2):

			L0 = L_ / 3;

			return Q_point_load(x, P_2a_lst[1], L0) +
				Q_point_load(x, P_2a_lst[2], 2 * L0);

		case(3):

			L0 = L_ / 4;

			return Q_point_load(x, P_2a_lst[1], L0) +
				Q_point_load(x, P_2a_lst[2], 2 * L0) +
				Q_point_load(x, P_2a_lst[3], 3 * L0);
	}
}
double IntForcesCalculator::Q_2d(double x)const
{
	return Q_uniform_load(x, loads_.IIb_design_LCC(), 0);
}
double IntForcesCalculator::Q_total(double x)const
{
	return Q_uniform_load(x, loads_.total_design_LCC(), 0);
}

double IntForcesCalculator::f_1a(double x)const
{
	std::vector<double> R_Ia_named_list = R_uniform_load(loads_.Ia_LCC(), s_num_);

	double L0 = 0.;

    	switch(s_num_)
	{
		case(0):

		return f_uniform_load(x, loads_.Ia_LCC());

		case(1):

			L0 = L_ / 2;

			return f_uniform_load(x, loads_.Ia_LCC()) +
				f_point_load(x, -1 * R_Ia_named_list[1], L0);

		case(2):

			L0 = L_ / 3;

			return f_uniform_load(x, loads_.Ia_LCC()) +
				f_point_load(x, -1 * R_Ia_named_list[1], L0) +
				f_point_load(x, -1 * R_Ia_named_list[2], 2 * L0);

		case(3):

			L0 = L_ / 4;

			return f_uniform_load(x, loads_.Ia_LCC()) +
				f_point_load(x, -1 * R_Ia_named_list[1], L0) +
				f_point_load(x, -1 * R_Ia_named_list[2], 2 * L0) +
				f_point_load(x, -1 * R_Ia_named_list[3], 3 * L0);
	}

}
double IntForcesCalculator::f_1b(double x)const
{
	std::vector<double> R_Ib_named_list = R_uniform_load(loads_.Ib_LCC(), s_num_);

	double L0 = 0.;

		switch(s_num_)
	{
		case(0):

		return f_uniform_load(x, loads_.Ib_LCC());

		case(1):

			L0 = L_ / 2;

			return f_uniform_load(x, loads_.Ib_LCC()) +
				f_point_load(x, -1 * R_Ib_named_list[1], L0);

		case(2):

			L0 = L_ / 3;

			return f_uniform_load(x, loads_.Ib_LCC()) +
				f_point_load(x, -1 * R_Ib_named_list[1], L0) +
				f_point_load(x, -1 * R_Ib_named_list[2], 2 * L0);

		case(3):

			L0 = L_ / 4;

			return f_uniform_load(x, loads_.Ib_LCC()) +
				f_point_load(x, -1 * R_Ib_named_list[1], L0) +
				f_point_load(x, -1 * R_Ib_named_list[2], 2 * L0) +
				f_point_load(x, -1 * R_Ib_named_list[3], 3 * L0);
	}
}
double IntForcesCalculator::f_2c(double x)const
{
	std::vector<double> R_Ib_named_list = R_uniform_load(loads_.Ib_LCC(), s_num_);

	double L0 = 0.;

		switch(s_num_)
	{
		case(0):

		return 0;

		case(1):

			L0 = L_ / 2;

			return f_point_load(x, R_Ib_named_list[1], L0);

		case(2):

			L0 = L_ / 3;

			return f_point_load(x, R_Ib_named_list[1], L0) +
				f_point_load(x, R_Ib_named_list[2], 2 * L0);

		case(3):

			L0 = L_ / 4;

			return f_point_load(x, R_Ib_named_list[1], L0) +
				f_point_load(x, R_Ib_named_list[2], 2 * L0) +
				f_point_load(x, R_Ib_named_list[3], 3 * L0);
	}
}
double IntForcesCalculator::f_2d(double x)const
{
	return f_uniform_load(x, loads_.IIb_LCC());
}

std::vector<double> IntForcesCalculator::R_uniform_load(double q, int s_num)const
{
	std::vector<double> R_lst{};

	double L0 = 0.;

	switch(s_num)
	{
		case(0):

			L0 = L_;

			R_lst.push_back(0.5 * q * L0);
			R_lst.push_back(0.5 * q * L0);

			return R_lst;

		case(1):

			L0 = L_ / 2;

			R_lst.push_back(0.375 * q * L0);
			R_lst.push_back(1.25 * q * L0);
			R_lst.push_back(0.375 * q * L0);

			return R_lst;

		case(2):

			L0 = L_ / 3;

			R_lst.push_back(0.4 * q * L0);
			R_lst.push_back(1.1 * q * L0);
			R_lst.push_back(1.1 * q * L0);
			R_lst.push_back(0.4 * q * L0);

			return R_lst;

		case(3):

			L0 = L_ / 4;

			R_lst.push_back(0.393 * q * L0);
			R_lst.push_back(1.143 * q * L0);
			R_lst.push_back(0.929 * q * L0);
			R_lst.push_back(1.143 * q * L0);
			R_lst.push_back(0.393 * q * L0);

			return R_lst;
	}
}
double IntForcesCalculator::M_uniform_load(double x, double q, int s_num)const
{
	double L0 = 0.;
	std::vector<double> R = R_uniform_load(q, s_num);

	switch(s_num)
	{
		case(0):

			L0 = L_;

			return R[0] * x - q * x * x / 2;

		case(1):

			L0 = L_ / 2;

			if(x <= L0)
				return R[0] * x - q * x * x / 2;
			return R[0] * x + R[1] * (x - L0) - q * x * x / 2;

		case(2):

			L0 = L_ / 3;

			if(x <= L0)
				return R[0] * x - q * x * x / 2;
			if(L0 < x && x <= 2 * L0)
				return R[0] * x + R[1] * (x - L0) - q * x * x / 2;
			return R[0] * x + R[1] * (x - L0) + R[2] * (x - 2 * L0) - q * x * x / 2;

		case(3):

			L0 = L_ / 4;

			if(x <= L0)
				return R[0] * x - q * x * x / 2;
			 if(L0 < x && x <= 2 * L0)
				return R[0] * x + R[1] * (x - L0) - q * x * x / 2;
			 if(2 * L0 < x && x <= 3 * L0)
				return R[0] * x + R[1] * (x - L0) + R[2] * (x - 2 * L0) - q * x * x / 2;
			 return R[0] * x + R[1] * (x - L0) + R[2] * (x - 2 * L0) + R[3] * (x - 3 * L0) - q * x * x / 2;
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
	std::vector<double> R = R_uniform_load(q, s_num);

	switch(s_num)
	{
		case(0):

			L0 = L_;

			return R[0] - q * x;

		case(1):

			L0 = L_ / 2;

			if(x <= L0)
				return R[0] - q * x;
			return R[0] + R[1] - q * x;

		case(2):

			L0 = L_ / 3;

			if(x <= L0)
				return R[0] - q * x;
			if(L0 < x && x <= 2 * L0)
				return R[0] + R[1] - q * x;
			return R[0] + R[1] + R[2] - q * x;

		case(3):

			L0 = L_ / 4;

			if(x <= L0)
				return R[0] - q * x;
			 if(L0 < x && x <= 2 * L0)
				return R[0] + R[1] - q * x;
			 if(2 * L0 < x && x <= 3 * L0)
				return R[0] + R[1] + R[2] - q * x;
			 return R[0] + R[1] + R[2] +R[3] - q * x;
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


