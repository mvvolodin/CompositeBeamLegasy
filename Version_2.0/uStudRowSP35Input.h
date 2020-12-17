//---------------------------------------------------------------------------

#ifndef uStudRowSP35InputH
#define uStudRowSP35InputH

#include "uStudSP35.h"

class StudRowSP35Input{
public:
	StudRowSP35Input() = default;
	StudRowSP35Input(double x,
					  double x_l,
					  double x_r,
					  int st_num);

	static StudSP35 const & stud(){return st_;};
	int	id()const{return id_;}
	double x()const{return x_;}
	double x_r()const{return x_r_;}
	double x_l()const{return x_l_;}
	int st_num()const {return st_num_;}

private:
	static StudSP35 st_;
	int const id_ = 0;
	int const st_num_ = 0;

	double const x_ = 0.;
	double const x_l_ = 0.;
	double const x_r_ = 0.;

};







//---------------------------------------------------------------------------
#endif
