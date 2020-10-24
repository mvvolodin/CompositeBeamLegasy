//---------------------------------------------------------------------------

#pragma hdrstop

#include <map>
#include <iostream>
#include "uBilinearInterp.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

namespace SP_35_13330_2011_table_8_16
{
	using A_f_min_to_A_w_ratio = double;
	using A_f_min_plus_A_w_to_A_ratio = double;
	using omega = double;

	std::map<A_f_min_plus_A_w_to_A_ratio, omega> const table_8_16_row_0{
		{0.01, 1.243},
		{0.10, 1.248},
		{0.20, 1.253},
		{0.30, 1.258},
		{0.40, 1.264},
		{0.50, 1.269},
		{0.60, 1.274},
		{0.70, 1.279},
		{0.80, 1.283},
		{0.90, 1.267},
		{1.00, 1.243}
	};

	std::map<A_f_min_plus_A_w_to_A_ratio, omega> const table_8_16_row_0_1{
		{0.01, 1.187},
		{0.10, 1.191},
		{0.20, 1.195},
		{0.30, 1.199},
		{0.40, 1.202},
		{0.50, 1.206},
		{0.60, 1.209},
		{0.70, 1.212},
		{0.80, 1.214},
		{0.90, 1.160},
		//{1.00, ----}
	};


}

namespace SP_35_13330_2011_table_9_5
{
	using fl_ratio = double;
	using eta = double;
	using str_ratio = double;

	std::map<str_ratio, eta> const table_9_5_s_row_0{
		{0.00, 1.00},
		{0.05, 1.00},
		{0.10, 1.00},
		{0.15, 1.00},
		{0.20, 1.00},
		{0.25, 1.00},
		{0.30, 0.99},
		{0.35, 0.98},
		{0.40, 0.96},
		{0.45, 0.95},
		{0.50, 0.92},
		{0.55, 0.88},
		{0.60, 0.83},
		{0.65, 0.75},
		{0.70, 0.63},
	};
	std::map<str_ratio, eta> const table_9_5_s_row_0_2{
		{0.00, 1.00},
		{0.05, 1.00},
		{0.10, 1.00},
		{0.15, 1.02},
		{0.20, 1.03},
		{0.25, 1.04},
		{0.30, 1.05},
		{0.35, 1.06},
		{0.40, 1.07},
		{0.45, 1.06},
		{0.50, 1.05},
		{0.55, 1.02},
		{0.60, 0.99},
		{0.65, 0.90},
		{0.70, 0.75},
	};

	std::map<str_ratio, eta> const table_9_5_s_row_0_4{
		{0.00, 1.00},
		{0.05, 1.04},
		{0.10, 1.08},
		{0.15, 1.12},
		{0.20, 1.14},
		{0.25, 1.16},
		{0.30, 1.19},
		{0.35, 1.20},
		{0.40, 1.21},
		{0.45, 1.20},
		{0.50, 1.18},
		{0.55, 1.16},
		{0.60, 1.13},
		{0.65, 1.09},
		{0.70, 1.04},
	};

	std::map<str_ratio, eta> const table_9_5_s_row_0_6{
		{0.00, 1.00},
		{0.05, 1.10},
		{0.10, 1.19},
		{0.15, 1.28},
		{0.20, 1.35},
		{0.25, 1.40},
		{0.30, 1.44},
		{0.35, 1.46},
		{0.40, 1.47},
		{0.45, 1.46},
		{0.50, 1.45},
		{0.55, 1.42},
		{0.60, 1.39},
		{0.65, 1.35},
		{0.70, 1.30},
	};

	std::map<str_ratio, eta> const table_9_5_s_row_0_8{
		{0.00, 1.00},
		{0.05, 1.20},
		{0.10, 1.39},
		{0.15, 1.55},
		{0.20, 1.70},
		{0.25, 1.83},
		{0.30, 1.93},
		{0.35, 1.98},
		{0.40, 2.00},
		{0.45, 2.02},
		{0.50, 2.01},
		{0.55, 1.99},
		{0.60, 1.97},
		{0.65, 1.91},
		{0.70, 1.84},
	};

	std::map<str_ratio, eta> const table_9_5_s_row_1_0{
		{0.00, 1.00},
		{0.05, 1.29},
		{0.10, 1.63},
		{0.15, 2.04},
		{0.20, 2.47},
		{0.25, 2.86},
		{0.30, 3.20},
		{0.35, 3.38},
		{0.40, 3.49},
		{0.45, 3.56},
		{0.50, 3.57},
		{0.55, 3.53},
		{0.60, 3.43},
		{0.65, 3.29},
		{0.70, 3.05},
	};

	std::map<fl_ratio, std::map<str_ratio, eta>> const table_9_5_s{
		{0.0, table_9_5_s_row_0},
		{0.2, table_9_5_s_row_0_2},
		{0.4, table_9_5_s_row_0_4},
		{0.6, table_9_5_s_row_0_6},
		{0.8, table_9_5_s_row_0_8},
		{1.0, table_9_5_s_row_1_0}
	};

	std::map<str_ratio, eta> const table_9_5_b_row_0{
		{0.00, 1.00},
		{0.05, 0.98},
		{0.10, 0.94},
		{0.15, 0.90},
		{0.20, 0.87},
		{0.25, 0.81},
		{0.30, 0.75},
		{0.35, 0.67},
		{0.40, 0.58},
		{0.45, 0.45},
		{0.50, 0.28},
		{0.55, 0.52},
		{0.60, 0.68},
		{0.65, 0.76},
		{0.70, 0.82},
	};

	std::map<str_ratio, eta> const table_9_5_b_row_0_2{
		{0.00, 1.00},
		{0.05, 1.00},
		{0.10, 1.00},
		{0.15, 1.02},
		{0.20, 1.03},
		{0.25, 1.04},
		{0.30, 1.05},
		{0.35, 1.06},
		{0.40, 1.07},
		{0.45, 1.06},
		{0.50, 1.05},
		{0.55, 1.02},
		{0.60, 0.99},
		{0.65, 0.90},
		{0.70, 0.75},
	};

	std::map<str_ratio, eta> const table_9_5_b_row_0_4{
		{0.00, 1.00},
		{0.05, 1.04},
		{0.10, 1.08},
		{0.15, 1.12},
		{0.20, 1.14},
		{0.25, 1.16},
		{0.30, 1.19},
		{0.35, 1.20},
		{0.40, 1.21},
		{0.45, 1.20},
		{0.50, 1.18},
		{0.55, 1.16},
		{0.60, 1.13},
		{0.65, 1.09},
		{0.70, 1.04},
	};

	std::map<str_ratio, eta> const table_9_5_b_row_0_6{
		{0.00, 1.00},
		{0.05, 1.10},
		{0.10, 1.19},
		{0.15, 1.28},
		{0.20, 1.35},
		{0.25, 1.40},
		{0.30, 1.44},
		{0.35, 1.46},
		{0.40, 1.47},
		{0.45, 1.46},
		{0.50, 1.45},
		{0.55, 1.42},
		{0.60, 1.39},
		{0.65, 1.35},
		{0.70, 1.30},
	};

	std::map<str_ratio, eta> const table_9_5_b_row_0_8{
		{0.00, 1.00},
		{0.05, 1.20},
		{0.10, 1.39},
		{0.15, 1.55},
		{0.20, 1.70},
		{0.25, 1.83},
		{0.30, 1.93},
		{0.35, 1.98},
		{0.40, 2.00},
		{0.45, 2.02},
		{0.50, 2.01},
		{0.55, 1.99},
		{0.60, 1.97},
		{0.65, 1.91},
		{0.70, 1.84},
	};

	std::map<str_ratio, eta> const table_9_5_b_row_1_0{
		{0.00, 1.00},
		{0.05, 1.29},
		{0.10, 1.63},
		{0.15, 2.04},
		{0.20, 2.47},
		{0.25, 2.86},
		{0.30, 3.20},
		{0.35, 3.38},
		{0.40, 3.49},
		{0.45, 3.56},
		{0.50, 3.57},
		{0.55, 3.53},
		{0.60, 3.43},
		{0.65, 3.29},
		{0.70, 3.05},
	};

	std::map<fl_ratio, std::map<str_ratio, eta>> const table_9_5_b{
		{0.0, table_9_5_b_row_0},
		{0.2, table_9_5_b_row_0_2},
		{0.4, table_9_5_b_row_0_4},
		{0.6, table_9_5_b_row_0_6},
		{0.8, table_9_5_b_row_0_8},
		{1.0, table_9_5_b_row_1_0}
	};

	static double linear_interp(double x, double x_1, double x_0, double f_1, double f_0)
	{
//		std::cout << "====================" << '\n';
//		std::cout << "Linear interpolation" << '\n';
//		std::cout << "====================" << '\n';
//		std::cout << "x0 = " << x_0 << " f(x0) = " << f_0 << '\n';
//		std::cout << "x1 = " << x_1 << " f(x1) = " << f_1 << '\n';
//		std::cout << "--------------------" << '\n';
//		std::cout << "x = " << x << " f(x) = " << f_0 + (f_1 - f_0) / (x_1 - x_0) * (x - x_0) << '\n';

		return f_0 + (f_1 - f_0) / (x_1 - x_0) * (x - x_0);
	}
	double linear_interp(std::map<str_ratio, eta> const & data, double str_ratio)
	{
		auto it_l = data.lower_bound(str_ratio);
		auto it_u = data.upper_bound(str_ratio);

		if (it_l != it_u)
			return it_l -> second;

		it_u = it_l;
		it_l = std::prev(it_u);

		return linear_interp(str_ratio,
							 it_u -> first,
							 it_l -> first,
							 it_u -> second,
							 it_l -> second);
	}

	double bilinear_interpolation(double fl_ratio,
								  double str_ratio,
								  std::map<double, std::map<double, double>> const & table_9_5)
	{
		auto it_l = table_9_5_s.lower_bound(fl_ratio);
		auto it_u = table_9_5_s.upper_bound(fl_ratio);
				if (it_l != it_u)
			return linear_interp(it_l -> second, str_ratio);

		it_u = it_l;
		it_l = std::prev(it_u);

		return linear_interp(fl_ratio,
							 it_u -> first,
							 it_l -> first,
							 linear_interp(it_u -> second, str_ratio),
							 linear_interp(it_l -> second, str_ratio));
	}
	
	double bilinear_interpolation(double fl_ratio,
								  double str_ratio,
								  FlangeBendingAndAxialStressSumUp fl)
	{
		switch(fl)
		{
			case FlangeBendingAndAxialStressSumUp::smaller:
				return bilinear_interpolation(fl_ratio,
											  str_ratio,
											  table_9_5_s);
			case FlangeBendingAndAxialStressSumUp::bigger:
				return bilinear_interpolation(fl_ratio,
											  str_ratio,
									          table_9_5_b);

		}
	}
}


