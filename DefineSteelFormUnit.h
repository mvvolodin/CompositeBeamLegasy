//---------------------------------------------------------------------------
#ifndef DefineSteelFormUnitH
#define DefineSteelFormUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
#include "Steel_param_ARSS.h"
#include "Steel.h"
#include "ObserverPatternInterfaces.h"
#include "ICompositeBeam.h"
//---------------------------------------------------------------------------

class TDefineSteelForm : public TForm, public IPublisher, public ICompositeBeamUser
{
__published:	// IDE-managed Components
		TPanel *Panel1;
		TLabel *Label2;
        TGroupBox *GroupBox1;
        TEdit *Edit_E;
        TEdit *Edit_G;
        TEdit *Edit_nu;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
	TGroupBox *GroupBox_Prop;
        TEdit *Edit_dens;
        TLabel *Label9;
	TBitBtn *btn_close;
	TBitBtn *btn_ok;
        TLabel *Label_gamma_m;
        TLabel *Label11;
        TEdit *Edit_gamma_m;
	TComboBox *cmb_bx_steel_grades;
	TComboBox *cmb_bx_standard;
	TStringGrid *StringGrid_Prop;
	TButton *btn_cancel;

        void __fastcall btn_okClick(TObject *Sender);
		void __fastcall cmb_bx_steel_gradesChange(TObject *Sender);
		void __fastcall cmb_bx_standardChange(TObject *Sender);
		void __fastcall btn_closeClick(TObject *Sender);
		void __fastcall set_steel_standard();
		void __fastcall fill_grd_steel_data();
	void __fastcall btn_cancelClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:
		static const Publisher_ID id_ = Publisher_ID::STEEL_FORM;
		IObserver_* iobserver_;
		ICompositeBeam* icomposite_beam_;
		Steel steel_temp_;
        void set_steel();
		void set_form_controls();
		virtual String get_information()const override {return steel_temp_.get_steel_grade();}
		virtual Publisher_ID get_id()const override {return id_;}

public:
		__fastcall TDefineSteelForm(TComponent* Owner)override;
		Steel get_steel(){set_steel(); return steel_temp_;}
		void register_observer(IObserver_* iobserver) override {iobserver_ = iobserver;}
		void register_icopmosite_beam_user(ICompositeBeam* icomposite_beam)override {icomposite_beam_ = icomposite_beam;}
		void set_form_controls(Steel steel);

};
//---------------------------------------------------------------------------
extern PACKAGE TDefineSteelForm *DefineSteelForm;
//---------------------------------------------------------------------------
#endif
