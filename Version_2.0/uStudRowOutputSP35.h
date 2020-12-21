//---------------------------------------------------------------------------

#ifndef uStudRowOutputSP35H
#define uStudRowOutputSP35H

class StudRowOutputSP35{
public:
	StudRowOutputSP35() = delete;
	StudRowOutputSP35(int id, double x, double S_ed, double ratio);

	int id()const {return id_;};
	double x()const {return x_;};
	double S_ed()const {return S_Ed_;};
	double ratio()const {return ratio_;};

private:
	int id_;
	double x_;
	double S_Ed_;
	double ratio_;

};
//---------------------------------------------------------------------------
#endif
