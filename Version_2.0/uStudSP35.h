//---------------------------------------------------------------------------

#ifndef uStudSP35H
#define uStudSP35H

#include <string>

class StudSP35{
public:

	StudSP35() = default;
	StudSP35(std::u16string const & name, double d_an, double l, double R_y, double R_b, double gamma_c);

	std::u16string name()const{return name_;}
	double d_1()const{return d_1_;}
	double l_1()const{return l_1_;}
	double R_y()const{return R_y_;}

	double S_h()const;
	double S_1()const;

private:
	std::u16string name_;
	double d_1_;
	double l_1_;
	double R_y_;
	double R_b_;
	double gamma_c_;

};
//---------------------------------------------------------------------------
#endif
