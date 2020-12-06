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

	std::map<A_f_min_plus_A_w_to_A_ratio, omega> const table_8_16_row_0_0{
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
		{1.00, 1.000}
	};
	std::map<A_f_min_plus_A_w_to_A_ratio, omega> const table_8_16_row_0_2{
		{0.01, 1.152},
		{0.10, 1.155},
		{0.20, 1.158},
		{0.30, 1.162},
		{0.40, 1.165},
		{0.50, 1.168},
		{0.60, 1.170},
		{0.70, 1.172},
		{0.80, 1.150},
		{0.90, 1.000},
		{1.00, 1.000}
	};
	std::map<A_f_min_plus_A_w_to_A_ratio, omega> const table_8_16_row_0_3{
		{0.01, 1.128},
		{0.10, 1.131},
		{0.20, 1.133},
		{0.30, 1.136},
		{0.40, 1.139},
		{0.50, 1.142},
		{0.60, 1.144},
		{0.70, 1.145},
		{0.80, 1.097},
		{0.90, 1.000},
		{1.00, 1.000}
	};
	std::map<A_f_min_plus_A_w_to_A_ratio, omega> const table_8_16_row_0_4{
		{0.01, 1.110},
		{0.10, 1.113},
		{0.20, 1.115},
		{0.30, 1.118},
		{0.40, 1.120},
		{0.50, 1.123},
		{0.60, 1.125},
		{0.70, 1.126},
		{0.80, 1.069},
		{0.90, 1.000},
		{1.00, 1.000}
	};
	std::map<A_f_min_plus_A_w_to_A_ratio, omega> const table_8_16_row_0_5{
		{0.01, 1.097},
		{0.10, 1.099},
		{0.20, 1.102},
		{0.30, 1.104},
		{0.40, 1.106},
		{0.50, 1.109},
		{0.60, 1.110},
		{0.70, 1.106},
		{0.80, 1.061},
		{0.90, 1.000},
		{1.00, 1.000}
	};
		std::map<A_f_min_plus_A_w_to_A_ratio, omega> const table_8_16_row_0_6{
		{0.01, 1.087},
		{0.10, 1.089},
		{0.20, 1.091},
		{0.30, 1.093},
		{0.40, 1.095},
		{0.50, 1.097},
		{0.60, 1.099},
		{0.70, 1.079},
		{0.80, 1.000},
		{0.90, 1.000},
		{1.00, 1.000}
	};
	std::map<A_f_min_plus_A_w_to_A_ratio, omega> const table_8_16_row_0_7{
		{0.01, 1.078},
		{0.10, 1.080},
		{0.20, 1.082},
		{0.30, 1.084},
		{0.40, 1.086},
		{0.50, 1.088},
		{0.60, 1.090},
		{0.70, 1.055},
		{0.80, 1.000},
		{0.90, 1.000},
		{1.00, 1.000}
	};
	std::map<A_f_min_plus_A_w_to_A_ratio, omega> const table_8_16_row_0_8{
		{0.01, 1.071},
		{0.10, 1.073},
		{0.20, 1.075},
		{0.30, 1.077},
		{0.40, 1.079},
		{0.50, 1.081},
		{0.60, 1.082},
		{0.70, 1.044},
		{0.80, 1.000},
		{0.90, 1.000},
		{1.00, 1.000}
	};
	std::map<A_f_min_plus_A_w_to_A_ratio, omega> const table_8_16_row_0_9{
		{0.01, 1.065},
		{0.10, 1.067},
		{0.20, 1.069},
		{0.30, 1.071},
		{0.40, 1.073},
		{0.50, 1.074},
		{0.60, 1.076},
		{0.70, 1.036},
		{0.80, 1.000},
		{0.90, 1.000},
		{1.00, 1.000}
	};
	std::map<A_f_min_plus_A_w_to_A_ratio, omega> const table_8_16_row_1_0{
		{0.01, 1.060},
		{0.10, 1.062},
		{0.20, 1.064},
		{0.30, 1.066},
		{0.40, 1.067},
		{0.50, 1.069},
		{0.60, 1.071},
		{0.70, 1.031},
		{0.80, 1.000},
		{0.90, 1.000},
		{1.00, 1.000}
	};
	std::map<A_f_min_plus_A_w_to_A_ratio, omega> const table_8_16_row_2_0{
		{0.01, 1.035},
		{0.10, 1.036},
		{0.20, 1.037},
		{0.30, 1.038},
		{0.40, 1.039},
		{0.50, 1.040},
		{0.60, 1.019},
		{0.70, 1.000},
		{0.80, 1.000},
		{0.90, 1.000},
		{1.00, 1.000}
	};
	std::map<A_f_min_plus_A_w_to_A_ratio, omega> const table_8_16_row_3_0{
		{0.01, 1.024},
		{0.10, 1.025},
		{0.20, 1.026},
		{0.30, 1.027},
		{0.40, 1.028},
		{0.50, 1.029},
		{0.60, 1.017},
		{0.70, 1.000},
		{0.80, 1.000},
		{0.90, 1.000},
		{1.00, 1.000}
	};
	std::map<A_f_min_plus_A_w_to_A_ratio, omega> const table_8_16_row_4_0{
		{0.01, 1.019},
		{0.10, 1.019},
		{0.20, 1.020},
		{0.30, 1.021},
		{0.40, 1.021},
		{0.50, 1.022},
		{0.60, 1.015},
		{0.70, 1.000},
		{0.80, 1.000},
		{0.90, 1.000},
		{1.00, 1.000}
	};
	std::map<A_f_min_plus_A_w_to_A_ratio, omega> const table_8_16_row_5_0{
		{0.01, 1.015},
		{0.10, 1.015},
		{0.20, 1.016},
		{0.30, 1.017},
		{0.40, 1.018},
		{0.50, 1.018},
		{0.60, 1.000},
		{0.70, 1.000},
		{0.80, 1.000},
		{0.90, 1.000},
		{1.00, 1.000}
	};
		std::map<A_f_min_to_A_w_ratio, std::map<A_f_min_plus_A_w_to_A_ratio, omega>> const table_8_16{
		{0.0, table_8_16_row_0_0},
		{0.1, table_8_16_row_0_1},
		{0.2, table_8_16_row_0_2},
		{0.3, table_8_16_row_0_3},
		{0.4, table_8_16_row_0_4},
		{0.5, table_8_16_row_0_5},
		{0.6, table_8_16_row_0_6},
		{0.7, table_8_16_row_0_7},
		{0.8, table_8_16_row_0_8},
		{0.9, table_8_16_row_0_9},
		{1.0, table_8_16_row_1_0},
		{2.0, table_8_16_row_2_0},
		{3.0, table_8_16_row_3_0},
		{4.0, table_8_16_row_4_0},
		{5.0, table_8_16_row_5_0}
	};
    	static double linear_interp(double x, double x_1, double x_0, double f_1, double f_0)
	{
		return f_0 + (f_1 - f_0) / (x_1 - x_0) * (x - x_0);
	}
	static double linear_interp(std::map<A_f_min_plus_A_w_to_A_ratio, omega> const & data, double A_f_min_plus_A_w_to_A_ratio)
	{
		auto it_l = data.lower_bound(A_f_min_plus_A_w_to_A_ratio);
		auto it_u = data.upper_bound(A_f_min_plus_A_w_to_A_ratio);

		if (it_l != it_u)
			return it_l -> second;

		it_u = it_l;
		it_l = std::prev(it_u);

		return linear_interp(A_f_min_plus_A_w_to_A_ratio,
							 it_u -> first,
							 it_l -> first,
							 it_u -> second,
							 it_l -> second);
	}
	double bilinear_interpolation(double A_f_min_to_A_w_ratio,
								  double A_f_min_plus_A_w_to_A_ratio)
	{
		auto it_l = table_8_16.lower_bound(A_f_min_to_A_w_ratio);
		auto it_u = table_8_16.upper_bound(A_f_min_to_A_w_ratio);
		if (it_l != it_u)
			return linear_interp(it_l -> second, A_f_min_plus_A_w_to_A_ratio);

		it_u = it_l;
		it_l = std::prev(it_u);

		return linear_interp(A_f_min_to_A_w_ratio,
							 it_u -> first,
							 it_l -> first,
							 linear_interp(it_u -> second, A_f_min_plus_A_w_to_A_ratio),
							 linear_interp(it_l -> second, A_f_min_plus_A_w_to_A_ratio));
	}
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
		return f_0 + (f_1 - f_0) / (x_1 - x_0) * (x - x_0);
	}
	static double linear_interp(std::map<str_ratio, eta> const & data, double str_ratio)
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

	static double bilinear_interpolation(double fl_ratio,
								  double str_ratio,
								  std::map<double, std::map<double, double>> const & table_9_5)
	{
		auto it_l = table_9_5.lower_bound(fl_ratio);
		auto it_u = table_9_5.upper_bound(fl_ratio);
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


