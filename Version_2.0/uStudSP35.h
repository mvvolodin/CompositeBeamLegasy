//---------------------------------------------------------------------------

#ifndef uStudSP35H
#define uStudSP35H

#include <string>

class StudSP35{
public:

	StudSP35() = delete;
	StudSP35(std::u16string const & name, double d_an, double l, double R_y, double R_b, double gamma_c);

	std::u16string name()const{return name_;}
	double d_an()const{return d_an_;}
	double l()const{return l_;}
	double R_y()const{return R_y_;}

	double S_h()const;
	double S_1()const;

private:
	std::u16string const name_;
	double const d_an_;
	double const l_;
	double const R_y_;
	double const R_b_;
	double const gamma_c_;

};
//---------------------------------------------------------------------------
#endif
