//---------------------------------------------------------------------------
#pragma hdrstop
#include "uStudsSP266Calculator.h"
#pragma package(smart_init)
StudsSP266Calculator::StudsSP266Calculator(CompBeamObjsCreatorSP266 const & creator):
	creator_(creator)
{
	GlobGeom const glob_geom {creator.glob_geometry()};
	IntForcesCalculator const ifc {creator.int_forces_calculator()};
	CompSectGeomSP266 const cs {creator.comp_sect_geom(false)};

	calc_ = {ifc, cs, glob_geom.span()};
}
//---------------------------------------------------------------------------
StudsSP266Calculated StudsSP266Calculator::run()const
{
	StudsSP266 const st_input {creator_.studs()};

	std::vector<StudRowSP266Calculated> st_rows;

	StudSP266 st {st_input.stud()};

	for(auto & sr0:st_input.rows())
		st_rows.emplace_back(run(sr0, st));

	return {new StudsSP266{st_input},
						   calc_.S_overline_lst(),
						   calc_.coord(),
						   st_rows};
}
//---------------------------------------------------------------------------
StudRowSP266Calculated StudsSP266Calculator::run(StudRowSP266 const & sr,
	StudSP266 const & s)const
{
	int const id = sr.id_;

	double const x = sr.x_;
	double const x_l = sr.x_l_;
	double const x_r = sr.x_r_;

	int const st_num = sr.st_num_;

	double const P_Rd = s.P_Rd();

	double const k = sr.k_;

	double const S_Ed_r = calc_.S_Ed(x_l, x_r);

	double const ratio = S_Ed_r / (k * P_Rd * st_num) ;

	return {id, st_num, x,  S_Ed_r, k, ratio};
}

