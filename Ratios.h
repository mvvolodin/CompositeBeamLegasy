//---------------------------------------------------------------------------

#ifndef RatiosH
#define RatiosH
//---------------------------------------------------------------------------


struct Ratios{

public:
    Ratios();
	Ratios(double ratio_upper_flange, double ratio_lower_flange);
	double get_ratio_upper_flange()const {return ratio_upper_flange_;}
	double get_ratio_lower_flange()const {return ratio_lower_flange_;}

private:
	double ratio_upper_flange_ = 0.;
	double ratio_lower_flange_ = 0.;
};

#endif
