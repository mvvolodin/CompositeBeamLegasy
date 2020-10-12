//---------------------------------------------------------------------------

#ifndef uFrmLoggerH
#define uFrmLoggerH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
#include <vector>
//---------------------------------------------------------------------------
class TFormLogger : public TForm
{
__published:	// IDE-managed Components
	TMemo *mm_logger;
	TButton *btn_clean;
	void __fastcall btn_cleanClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormLogger(TComponent* Owner);

	void clean_logger();
	void add_separator(String const & str) const;
	void print_string(String const & str)const;
	void print_double(String const & name, double val, String const & unit) const;
	void print_2_doubles(String const & name1, double val1, String const & unit1,
						 String const & name2, double val2, String const & unit2) const;

	void print_sections_coordinates(double id, double x);
	void print_M_X(double x, double M);
	void print_M_X(std::vector<double> M_list);
	void print_sigma_b_sigma_s_X(double x, double sigma_b, double sigma_s);
	void print_ratios(double x, double upper_fl_ratio, double lower_fl_ratio,
		double conc_ratio, double shear_ratio);

	void print_stud_coordinates(double id, double x, double x_l, double x_r);
	void print_stud_shear_force(double id, double S);
	void print_ratio(double id, double ratio);

};
//---------------------------------------------------------------------------
extern PACKAGE TFormLogger *FormLogger;
//---------------------------------------------------------------------------
#endif
