//---------------------------------------------------------------------------

#ifndef uLinearFuncH
#define uLinearFuncH
//---------------------------------------------------------------------------
class LinearFunc{
public:
	LinearFunc() = delete;
	LinearFunc(double a, double b);
	 double operator()(double x)const;
private:
	double const a_;
	double const b_;

};
//---------------------------------------------------------------------------
#endif
