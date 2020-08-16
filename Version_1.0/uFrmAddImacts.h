//---------------------------------------------------------------------------

#ifndef uFrmAddImactsH
#define uFrmAddImactsH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TFrmAddImpacts : public TForm
{
__published:	// IDE-managed Components
	TButton *btn_close;
	TLabel *lbl_sigma_bi;
	TLabel *lbl_sigma_si;
	TEdit *edt_sigma_bi;
	TEdit *edt_sigma_si;
	TButton *btn_cancel;
	TButton *btn_ok;
	TGroupBox *GroupBox1;
	void __fastcall btn_okClick(TObject *Sender);
	void __fastcall btn_closeClick(TObject *Sender);
	void __fastcall btn_cancelClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
	double sigma_bi_;
	double sigma_si_;
	void update_controls();
    void check_input();
public:		// User declarations
	__fastcall TFrmAddImpacts(TComponent* Owner);
	double get_sigma_bi(){return sigma_bi_;}
	double get_sigma_si(){return sigma_si_;}
	void set_sigma_bi(double sigma_bi){sigma_bi_ = sigma_bi;}
	void set_sigma_si(double sigma_si){sigma_si_ = sigma_si;}
};
//---------------------------------------------------------------------------
extern PACKAGE TFrmAddImpacts *FrmAddImpacts;
//---------------------------------------------------------------------------
#endif
