//---------------------------------------------------------------------------

#ifndef uStudRowOutputSP35H
#define uStudRowOutputSP35H

class StudRowOutputSP35{
public:
	StudRowOutputSP35() = delete;
	StudRowOutputSP35(int id, double x, double S_i, double ratio);

	int id()const {return id_;};
	double x()const {return x_;};
	double S_i()const {return S_i_;};
	double ratio()const {return ratio_;};

private:
	int id_;
	double x_;
	double S_i_;
	double ratio_;

};
//---------------------------------------------------------------------------
#endif
