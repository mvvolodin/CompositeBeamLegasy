//---------------------------------------------------------------------------

#pragma hdrstop
//---------------------------------------------------------------------------
#include "uInternalForcesCalculator.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
InternalForcesCalculator::InternalForcesCalculator()
{
}
InternalForcesCalculator::InternalForcesCalculator( const SupportsNumber 	 s_num,
													const double 			 L,
													const TLoads 			 loads):
	s_num_(s_num),
	L_(L),
	loads_ (loads){}
std::map<double, double> InternalForcesCalculator::R_Ia_design()const
{
	return R_uniform_load(loads_.Ia_design_LCC(), s_num_);
}
std::map<double, double> InternalForcesCalculator::R_Ib_design()const
{
	return R_uniform_load(loads_.Ib_design_LCC(), s_num_);
}
std::map<double, double> InternalForcesCalculator::R_IIa_design()const
{
	return R_uniform_load(loads_.Ib_design_LCC(), SupportsNumber::ZERO);
}
std::map<double, double> InternalForcesCalculator::R_IIb_design()const
{
	return R_uniform_load(loads_.IIb_design_LCC(), SupportsNumber::ZERO );
}
std::map<double, double> InternalForcesCalculator::R_total_design()const
{
	return R_uniform_load(loads_.total_design_LCC(), SupportsNumber::ZERO );
}
double InternalForcesCalculator::M_Ia_design(double x)const
{
	return M_uniform_load(x, loads_.Ia_design_LCC(), s_num_);
}
double InternalForcesCalculator::M_Ib_design(double x)const
{
	return M_uniform_load(x, loads_.Ib_design_LCC(), s_num_);
}
double InternalForcesCalculator::M_IIa_design(double x)const
{
	std::map<double, double> R_Ib_design_named_list = R_uniform_load(loads_.Ib_design_LCC(), s_num_);

	double L0 = 0.;

	switch(s_num_)
	{
		case(SupportsNumber::ZERO):

			return 0;

		case(SupportsNumber::ONE):

			L0 = L_ / 2;

			return M_point_load(x, R_Ib_design_named_list.at(L0), L0);

		case(SupportsNumber::TWO):

			L0 = L_ / 3;

			return M_point_load(x, R_Ib_design_named_list.at(L0), L0) +
				M_point_load(x, R_Ib_design_named_list.at(2 * L0), 2 * L0);

		case(SupportsNumber::THREE):

			L0 = L_ / 4;

			return M_point_load(x, R_Ib_design_named_list.at(L0), L0) +
				M_point_load(x, R_Ib_design_named_list.at(2 * L0), 2 * L0) +
				M_point_load(x, R_Ib_design_named_list.at(3 * L0), 3 * L0);
	}
}
double InternalForcesCalculator::M_IIb_design(double x)const
{
	return M_uniform_load(x, loads_.IIb_design_LCC(), SupportsNumber::ZERO );
}

double InternalForcesCalculator::M_total_design(double x)const
{
	return M_Ib_design(x) + M_IIa_design(x) + M_IIb_design(x);
}
double InternalForcesCalculator::Q_Ia_design(double x)const
{
	return Q_uniform_load(x, loads_.Ia_design_LCC(), s_num_);
}
double InternalForcesCalculator::Q_Ib_design(double x)const
{
	return Q_uniform_load(x, loads_.Ib_design_LCC(), s_num_);
}
double InternalForcesCalculator::Q_IIa_design(double x)const
{
	std::map<double, double> R_Ib_design_named_list = R_uniform_load(loads_.Ib_design_LCC(), s_num_);

	double L0 = 0.;

	switch(s_num_)
	{
		case(SupportsNumber::ZERO):

			return 0;

		case(SupportsNumber::ONE):

			L0 = L_ / 2;

			return Q_point_load(x, R_Ib_design_named_list.at(L0), L0);

		case(SupportsNumber::TWO):

			L0 = L_ / 3;

			return Q_point_load(x, R_Ib_design_named_list.at(L0), L0) +
				Q_point_load(x, R_Ib_design_named_list.at(2 * L0), 2 * L0);

		case(SupportsNumber::THREE):

			L0 = L_ / 4;

			return Q_point_load(x, R_Ib_design_named_list.at(L0), L0) +
				Q_point_load(x, R_Ib_design_named_list.at(2 * L0), 2 * L0) +
				Q_point_load(x, R_Ib_design_named_list.at(3 * L0), 3 * L0);
	}
}
double InternalForcesCalculator::Q_IIb_design(double x)const
{
	return Q_uniform_load(x, loads_.IIb_design_LCC(), SupportsNumber::ZERO);
}

double InternalForcesCalculator::Q_total_design(double x)const
{
	return Q_Ib_design(x) + Q_IIa_design(x) + Q_IIb_design(x);
}

double InternalForcesCalculator::f_Ia_design(double x)const
{
	std::map<double, double> R_Ia_design_named_list = R_uniform_load(loads_.Ia_design_LCC(), s_num_);

	double L0 = 0.;

    	switch(s_num_)
	{
		case(SupportsNumber::ZERO):

		return f_uniform_load(x, loads_.Ia_design_LCC());

		case(SupportsNumber::ONE):

			L0 = L_ / 2;

			return f_uniform_load(x, loads_.Ia_design_LCC()) +
				f_point_load(x, -1 * R_Ia_design_named_list.at(L0), L0);

		case(SupportsNumber::TWO):

			L0 = L_ / 3;

			return f_uniform_load(x, loads_.Ia_design_LCC()) +
				f_point_load(x, -1 * R_Ia_design_named_list.at(L0), L0) +
				f_point_load(x, -1 * R_Ia_design_named_list.at(2 * L0), 2 * L0);

		case(SupportsNumber::THREE):

			L0 = L_ / 4;

			return f_uniform_load(x, loads_.Ia_design_LCC()) +
				f_point_load(x, -1 * R_Ia_design_named_list.at(L0), L0) +
				f_point_load(x, -1 * R_Ia_design_named_list.at(2 * L0), 2 * L0) +
				f_point_load(x, -1 * R_Ia_design_named_list.at(3 * L0), 3 * L0);
	}

}
double InternalForcesCalculator::f_Ib_design(double x)const
{
	std::map<double, double> R_Ib_design_named_list = R_uniform_load(loads_.Ib_design_LCC(), s_num_);

	double L0 = 0.;

		switch(s_num_)
	{
		case(SupportsNumber::ZERO):

		return f_uniform_load(x, loads_.Ib_design_LCC());

		case(SupportsNumber::ONE):

			L0 = L_ / 2;

			return f_uniform_load(x, loads_.Ib_design_LCC()) +
				f_point_load(x, -1 * R_Ib_design_named_list.at(L0), L0);

		case(SupportsNumber::TWO):

			L0 = L_ / 3;

			return f_uniform_load(x, loads_.Ib_design_LCC()) +
				f_point_load(x, -1 * R_Ib_design_named_list.at(L0), L0) +
				f_point_load(x, -1 * R_Ib_design_named_list.at(2 * L0), 2 * L0);

		case(SupportsNumber::THREE):

			L0 = L_ / 4;

			return f_uniform_load(x, loads_.Ib_design_LCC()) +
				f_point_load(x, -1 * R_Ib_design_named_list.at(L0), L0) +
				f_point_load(x, -1 * R_Ib_design_named_list.at(2 * L0), 2 * L0) +
				f_point_load(x, -1 * R_Ib_design_named_list.at(3 * L0), 3 * L0);
	}
}
double InternalForcesCalculator::f_IIa_design(double x)const
{
	std::map<double, double> R_Ib_design_named_list = R_uniform_load(loads_.Ib_design_LCC(), s_num_);

	double L0 = 0.;

		switch(s_num_)
	{
		case(SupportsNumber::ZERO):

		return 0;

		case(SupportsNumber::ONE):

			L0 = L_ / 2;

			return f_point_load(x, R_Ib_design_named_list.at(L0), L0);

		case(SupportsNumber::TWO):

			L0 = L_ / 3;

			return f_point_load(x, R_Ib_design_named_list.at(L0), L0) +
				f_point_load(x, R_Ib_design_named_list.at(2 * L0), 2 * L0);

		case(SupportsNumber::THREE):

			L0 = L_ / 4;

			return f_point_load(x, R_Ib_design_named_list.at(L0), L0) +
				f_point_load(x, R_Ib_design_named_list.at(2 * L0), 2 * L0) +
				f_point_load(x, R_Ib_design_named_list.at(3 * L0), 3 * L0);
	}
}
double InternalForcesCalculator::f_IIb_design(double x)const
{
	return f_uniform_load(x, loads_.IIb_design_LCC());
}
double InternalForcesCalculator::f_total_design(double x)const
{
	return f_Ib_design(x) + f_IIa_design(x) + f_IIb_design(x);;
}

std::map<double, double> InternalForcesCalculator::R_uniform_load(double q, SupportsNumber s_num)const
{
	std::map<double, double> R_named_list{};

	double L0 = 0.;

	switch(s_num)
	{
		case(SupportsNumber::ZERO):

			L0 = L_;

			R_named_list.insert({0, 0.5 * q * L0});
			R_named_list.insert({L0, 0.5 * q * L0});

			return R_named_list;

		case(SupportsNumber::ONE):

			L0 = L_ / 2;

			R_named_list.insert({0, 0.375 * q * L0});
			R_named_list.insert({L0, 1.25 * q * L0});
			R_named_list.insert({2 * L0, 0.375 * q * L0});

			return R_named_list;

		case(SupportsNumber::TWO):

			L0 = L_ / 3;

			R_named_list.insert({0, 0.4 * q * L0});
			R_named_list.insert({L0, 1.1 * q * L0});
			R_named_list.insert({2 * L0, 1.1 * q * L0});
			R_named_list.insert({3 * L0, 0.4 * q * L0});

			return R_named_list;

		case(SupportsNumber::THREE):

			L0 = L_ / 4;

			R_named_list.insert({0, 0.393 * q * L0});
			R_named_list.insert({L0, 1.143 * q * L0});
			R_named_list.insert({2 * L0, 0.929 * q * L0});
			R_named_list.insert({3 * L0, 1.143 * q * L0});
			R_named_list.insert({4 * L0, 0.393 * q * L0});

			return R_named_list;
	}
}
double InternalForcesCalculator::M_uniform_load(double x, double q, SupportsNumber s_num)const
{
	double L0 = 0.;
	std::map<double, double> R = R_uniform_load(q, s_num);

	switch(s_num)
	{
		case(SupportsNumber::ZERO):

			L0 = L_;

			return R.at(0) * x - q * x * x / 2;

		case(SupportsNumber::ONE):

			L0 = L_ / 2;

			if(x <= L0)
				return R.at(0) * x - q * x * x / 2;
			return R.at(0) * x + R.at(L0) * (x - L0) - q * x * x / 2;

		case(SupportsNumber::TWO):

			L0 = L_ / 3;

			if(x <= L0)
				return R.at(0) * x - q * x * x / 2;
			if(L0 < x && x <= 2 * L0)
				return R.at(0) * x + R.at(L0) * (x - L0) - q * x * x / 2;
			return R.at(0) * x + R.at(L0) * (x - L0) + R.at(2 * L0) * (x - 2 * L0) - q * x * x / 2;

		case(SupportsNumber::THREE):

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
double InternalForcesCalculator::M_point_load(double x, double P, double x_P)const
{
	if(x < x_P) return P * (L_ - x_P) / L_ * x;

	return P * (L_ - x_P) / L_ * x - P * (x - x_P) ;
}
double InternalForcesCalculator::Q_uniform_load(double x, double q, SupportsNumber s_num)const
{
	double L0 = 0.;
	std::map<double, double> R = R_uniform_load(q, s_num);

	switch(s_num)
	{
		case(SupportsNumber::ZERO):

			L0 = L_;

			return R.at(0) - q * x;

		case(SupportsNumber::ONE):

			L0 = L_ / 2;

			if(x <= L0)
				return R.at(0) - q * x;
			return R.at(0) + R.at(L0) - q * x;

		case(SupportsNumber::TWO):

			L0 = L_ / 3;

			if(x <= L0)
				return R.at(0) - q * x;
			if(L0 < x && x <= 2 * L0)
				return R.at(0) + R.at(L0) - q * x;
			return R.at(0) + R.at(L0) + R.at(2 * L0) - q * x;

		case(SupportsNumber::THREE):

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
double InternalForcesCalculator::Q_point_load(double x, double P, double x_P)const
{
	return (x <= x_P) ? P: -P;
}
double InternalForcesCalculator::f_uniform_load(double x, double q)const
{
	//https://en.wikipedia.org/wiki/Deflection_(engineering)
    // множитель -1 введён для гармонизации знаков с Феодосьевым
	return -1 * q * x * (L_ * L_ * L_ - 2 * L_ * x * x + x * x * x) / 24;
}
double InternalForcesCalculator::f_point_load(double x, double P, double x_P)const
{
	//Феодосьев, 7е издание, пример 4.8, стр. 146
	if(x <= x_P)
		return P * (L_ - x_P) / (6 * L_) * (x * x * x - x * x_P * (2 * L_ - x_P));
	return
		P * x_P / (6 * L_) * (-1 * x * x * x + 3 * x * x * L_ - x * (2 * L_ * L_ + x_P * x_P) + x_P * x_P * L_) ;

	return 0.;
}
