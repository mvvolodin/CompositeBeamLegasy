//---------------------------------------------------------------------------

#ifndef uGeneralSteelSectionH
#define uGeneralSteelSectionH

class GeneralSteelSection{
public:
	GeneralSteelSection();
	virtual ~ GeneralSteelSection();
	virtual double b_f1() = 0;
	virtual double t_f1() = 0;
	virtual double b_f2() = 0;
	virtual double t_f2() = 0;
	virtual double h_w() = 0;
	virtual double t_w() = 0;
	virtual double h() = 0;

	virtual double centroid() = 0;
	virtual double area() = 0;
	virtual double inertia() = 0;

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
