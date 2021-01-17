//---------------------------------------------------------------------------

#ifndef RectangSectionH
#define RectangSectionH
//---------------------------------------------------------------------------
#include<cmath>

using namespace std;

class RectangSection{
private:
	double h_p;//Высота настила
	double h_f; //Толщина железобетона над настилом
	double A_b;//Площадь железобетона
	double I_b;//Момент инерции железобетонной плиты
	double b_sl;//Расчётная ширина железобетонной плиты
	double t_sl;//Толщина железобетонной плиты

private:
	void calc_inertia();

public:
	inline double get_sheet_height() const {return h_p;}
	inline double get_conc_topping() const {return h_f;}
	inline double get_area() const {return A_b;}
	inline double get_width() const {return b_sl;}
	inline double get_thickness() const {return t_sl;}
	double get_inertia() const {return I_b;};
};
#endif
