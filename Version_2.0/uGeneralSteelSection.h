//---------------------------------------------------------------------------

#ifndef uGeneralSteelSectionH
#define uGeneralSteelSectionH

class GeneralSteelSection{
public:
	GeneralSteelSection();
	virtual ~ GeneralSteelSection();
	virtual double b_f1() const = 0;
	virtual double t_f1() const = 0;
	virtual double b_f2() const = 0;
	virtual double t_f2() const = 0;
	virtual double h_w() const = 0;
	virtual double t_w() const = 0;
	virtual double h_st() const = 0;

	virtual double C_st() const = 0;
	virtual double A_st() const = 0;
	virtual double I_st() const = 0;
    virtual double Z_f2_st() const = 0;

	virtual void print_coord() = 0;
	virtual void print_b_f1() = 0;
	virtual void print_t_f1() = 0;
	virtual void print_b_f2() = 0;
	virtual void print_t_f2() = 0;
	virtual void print_h_w() = 0;
	virtual void print_t_w() = 0;
	virtual void print_centroid() = 0;
	virtual void print_area() = 0;
	virtual void print_inertia() = 0;

};
//---------------------------------------------------------------------------
#endif
