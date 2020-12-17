//---------------------------------------------------------------------------

#pragma hdrstop
#include<algorithm>
#include "uStudRowCalculatorSP35.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

StudRowCalculatorSP35::StudRowCalculatorSP35(LongShearForcesCalculator const & calc):
	calc_(calc){}

StudSP35Output StudRowCalculatorSP35::run(StudRowSP35Input const & sri)const
{
	int const id = sri.id();

	double const x = sri.x();
	double const x_l = sri.x_l();
	double const x_r = sri.x_r();

	int const st_num = sri.st_num();

	double const S_h = StudRowSP35Input::stud().S_h();
	double const S_1 = StudRowSP35Input::stud().S_1();

	double S_i = calc_.run(x_l, x_r);

	double const ratio = S_i / (st_num * std::min(S_h, S_1));

	return {id, x, S_i, ratio};

}
