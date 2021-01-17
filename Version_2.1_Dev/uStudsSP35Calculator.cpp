//---------------------------------------------------------------------------

#pragma hdrstop

#include "uStudsSP35Calculator.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

StudsSP35Calculator::StudsSP35Calculator(CompBeamObjsCreatorSP35 const & creator):
	creator_(creator)
{
	GlobGeom const glob_geom {creator.glob_geometry()};
	IntForcesCalculator const ifc {creator.int_forces_calculator()};
	CompSectGeomSP35 const cs {creator.comp_sect_geom(
		CompSectGeomSP35::ConcStateConsid::normal)};

	calc_ = LongShearForcesCalculatorSP35{ifc, cs, glob_geom.span()};
}

//---------------------------------------------------------------------------
StudsSP35Calculated StudsSP35Calculator::run()const
{
	StudsSP35 const st_input {creator_.studs()};

	std::vector<StudRowSP35Calculated> st_rows;

	StudSP35 st {st_input.stud()};

	for(auto & sr0:st_input.rows())
		st_rows.emplace_back(run(sr0, st));

	return {new StudsSP35{st_input},
						  calc_.S_overline_lst(),
						  calc_.coord(),
						  st_rows};
}
//---------------------------------------------------------------------------
StudRowSP35Calculated StudsSP35Calculator::run(StudRowSP35 const & sr,
	StudSP35 const & s)const
{
	int const id = sr.id_;

	double const x = sr.x_;
	double const x_l = sr.x_l_;
	double const x_r = sr.x_r_;

	int const st_num = sr.st_num_;

	double const P_Rd = s.P_Rd();

	double const S_Ed_r = calc_.S_Ed(x_l, x_r);

	double const ratio = S_Ed_r / (P_Rd * st_num) ;

	return {id, st_num, x,  S_Ed_r, ratio};
}
