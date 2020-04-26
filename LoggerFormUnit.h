//---------------------------------------------------------------------------

#ifndef LoggerFormUnitH
#define LoggerFormUnitH
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
private:	// User declarations
public:		// User declarations
	__fastcall TFormLogger(TComponent* Owner);
	void print_M_X(std::vector<double> M_list);
	void print_stud_coordinates(double id, double x, double x_l, double x_r);
	void print_stud_shear_force(double id, double S);
	void print_ratio(double id, double ratio);
	void clean_logger();
	void add_separator(String str);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormLogger *FormLogger;
//---------------------------------------------------------------------------
#endif
