//---------------------------------------------------------------------------

#ifndef uStudRowInputSP35H
#define uStudRowInputSP35H

class StudRowInputSP35{
public:
	StudRowInputSP35() = default;
	StudRowInputSP35(int id, double x, double x_l, double x_r, int st_num);

	int	id()const{return id_;}
	double x()const{return x_;}
	double x_r()const{return x_r_;}
	double x_l()const{return x_l_;}
	int st_num()const {return st_num_;}

private:
	int const id_ = 0;

	double const x_ = 0.;
	double const x_l_ = 0.;
	double const x_r_ = 0.;

	int const st_num_ = 0;
};







//---------------------------------------------------------------------------
#endif

