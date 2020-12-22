//---------------------------------------------------------------------------

#ifndef uStudRowOutputSP35H
#define uStudRowOutputSP35H

class StudRowOutputSP35{
public:
	StudRowOutputSP35() = delete;
	StudRowOutputSP35(int id, double x, int st_num, double S_Ed, double ratio);

	int id()const {return id_;}
	double x()const {return x_;}
	int st_num()const {return st_num_;}
	double S_Ed()const {return S_Ed_;}
	double ratio()const {return ratio_;}

private:
	int id_;
	double x_;
	int st_num_;
	double S_Ed_;
	double ratio_;

};
//---------------------------------------------------------------------------
#endif
