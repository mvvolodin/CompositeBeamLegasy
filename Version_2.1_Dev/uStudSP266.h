//---------------------------------------------------------------------------
#ifndef uStudSP266H
#define uStudSP266H
//---------------------------------------------------------------------------
#include <string>
//---------------------------------------------------------------------------
class StudSP266{
public:

	StudSP266() = default;
	StudSP266(std::u16string const & name, double d_an, double l, double R_y, double R_b, double m);

	std::u16string name()const{return name_;}
	double d_1()const{return d_1_;}
	double l_1()const{return l_1_;}
	double R_y()const{return R_y_;}

	double P_Rd()const{return P_Rd_;}

private:
	std::u16string name_;
	double d_1_;
	double l_1_;
	double R_y_;

	double P_Rd_;
};
//---------------------------------------------------------------------------
#endif
