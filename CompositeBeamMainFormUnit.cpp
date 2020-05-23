//---------------------------------------------------------------------------
#include <vcl.h>
#include<ComObj.hpp>
#include <ostream>
#include <fstream>
#pragma hdrstop

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

#include "CompositeBeamMainFormUnit.h"
#include "String_doubleUnit.h"
#include "uWord_Automation.h"
#include "AboutProg.h"

TCompositeBeamMainForm  *CompositeBeamMainForm;

//----------------------------------------------------------------------
 _fastcall TCompositeBeamMainForm ::TCompositeBeamMainForm (TComponent* Owner)
	: TForm(Owner)
{
	composite_beam_calculator_.set_default_values();

	cotr_ratios_grid();
	cotr_comp_sect_geometr_grid();
	cotr_steel_sect_geometr_grid();
	ctor_concrete_sect_geometr_grid();;
	fill_cmb_bx_impact();
	fill_cmb_bx_corrugated_sheets();
	modify_project = false;
}
//----------------------------------------------------------------------
void __fastcall TCompositeBeamMainForm ::FormShow(TObject *Sender)
{

	register_observers();

	register_I_composite_beam();

	set_form_controls();

	NNewClick(Sender);

	rdgrp_slab_typeClick(Sender);

	calculate_composite_beam();

}
//----------------------------------------------------------------------
////������������ �������� ����� ����� �� ������ ����� ���� TCompositeBeam
//----------------------------------------------------------------------
void TCompositeBeamMainForm ::set_form_controls()
{
 // ������ ���� Geometry
	Geometry geom = composite_beam_calculator_.get_geometry();
	edt_max_elem_length -> Text = composite_beam_calculator_.get_max_elem_length();
	edt_span -> Text = geom.get_span();
	edt_width_left -> Text = geom.get_trib_width_left();
	edt_width_right -> Text = geom.get_trib_width_right();
	cmb_bx_number_propping_supports -> ItemIndex =
		cmb_bx_number_propping_supports -> Items -> IndexOf(static_cast<int>(geom.get_temporary_supports_number()));
//������ ���� Loads
	Loads loads = composite_beam_calculator_.get_loads();
	edt_dead_load_first_stage -> Text = loads.get_dead_load_first_stage(LoadUnit::kN, LengthUnit::m);
	edt_dead_load_second_stage -> Text = loads.get_dead_load_second_stage(LoadUnit::kN, LengthUnit::m);
	edt_live_load -> Text = loads.get_live_load(LoadUnit::kN, LengthUnit::m);
	edt_gamma_f_st_SW_-> Text = loads.get_gamma_f_st_SW();
	edt_gamma_f_concrete -> Text = loads.get_gamma_f_concrete_SW();
	edt_gamma_f_DL_I -> Text = loads.get_gamma_f_DL_I();
	edt_gamma_f_DL_II -> Text = loads.get_gamma_f_DL_II();
	edt_gamma_f_LL -> Text = loads.get_gamma_f_LL();

//������ ���� WorkingConditionsFactors
	WorkingConditionsFactors wcf = composite_beam_calculator_.get_working_conditions_factors();
	edt_gamma_bi -> Text = wcf.get_gamma_bi();
	edt_gamma_si -> Text = wcf.get_gamma_si();
	edt_gamma_c -> Text = wcf.get_gamma_c();

//������������ ���������� ����� ���������� ���������:
	edt_max_elem_length -> Text = composite_beam_calculator_.get_max_elem_length();

//������ ��� ����������� ������
	pnl_shear_stud_viewer -> Caption = StudDefinitionForm -> get_studs_on_beam().get_name();
	pnl_rebar_viewer -> Caption = RebarDefinitionForm -> get_rebar().get_grade();
	pnl_concrete_grade -> Caption = ConcreteDefinitionForm -> get_concrete().get_grade();
	Pnl_SteelSectionViewer -> Caption = SteelSectionForm2 -> get_i_section().get_profile_number();

//������ ��� �����

	switch (composite_beam_calculator_.get_composite_section().get_concrete_part().get_slab_type_enum())
	{
	case SlabType::FLAT:
		rdgrp_slab_type -> ItemIndex = 0;
		break;
	case SlabType::CORRUGATED:
		rdgrp_slab_type -> ItemIndex = 1;
		cmb_bx_corrugated_sheeting_part_number -> ItemIndex =
			cmb_bx_corrugated_sheeting_part_number -> Items -> IndexOf(composite_beam_calculator_.get_composite_section().get_concrete_part().get_slab_type());
		break;
	}
	edt_h_f_flat -> Text = composite_beam_calculator_.get_composite_section().get_concrete_part().get_h_f();
	edt_h_f -> Text = composite_beam_calculator_.get_composite_section().get_concrete_part().get_h_f();
	edt_h_n -> Text = composite_beam_calculator_.get_composite_section().get_concrete_part().get_h_n();

//������ ���� Studs
   	StudDefinitionForm -> set_form_controls(composite_beam_calculator_.get_studs_on_beam());

//������ ���� Rebar
	RebarDefinitionForm -> set_form_controls(composite_beam_calculator_.get_composite_section().get_concrete_part().get_rebar());

//������ ���� Concrete
	ConcreteDefinitionForm -> set_form_controls(composite_beam_calculator_.get_composite_section().get_concrete_part().get_concrete());
	Concrete con = composite_beam_calculator_.get_composite_section().get_concrete_part().get_concrete();

//������ ���� Steel
	DefineSteelForm -> set_form_controls(composite_beam_calculator_.get_composite_section().get_steel_part().get_steel());
//������ ���� Section
	SteelSectionForm2 -> set_form_controls(composite_beam_calculator_.get_composite_section().get_steel_part().get_section());

}
void TCompositeBeamMainForm ::register_observers()
{
	std::vector<IPublisher*> ipublishers;
	ipublishers.push_back(RebarDefinitionForm);
	ipublishers.push_back(StudDefinitionForm);
	ipublishers.push_back(ConcreteDefinitionForm);
	ipublishers.push_back(DefineSteelForm);
	ipublishers.push_back(SteelSectionForm2);
	for(auto ip:ipublishers)
	ip -> register_observer(this);

}
void TCompositeBeamMainForm ::register_I_composite_beam()
{
	DefineSteelForm -> register_icopmosite_beam_user(this);
}

//---------------------------------------------------------------------------
//������������� ���������
//---------------------------------------------------------------------------
Geometry TCompositeBeamMainForm ::init_geomet()
{
	double span = 0.;
	double trib_width_left = 0.;
	double trib_width_right = 0.;

	String_double_plus(lbl_span->Caption, edt_span->Text, &span);
	String_double_plus(lbl_trib_width_left->Caption, edt_width_left->Text, &trib_width_left);
	String_double_plus(lbl_trib_width_right->Caption, edt_width_right->Text, &trib_width_right);

	return Geometry(chck_bx_end_beam->Checked,
					 span, trib_width_left,
					 trib_width_right,
					 static_cast<SupportsNumber>(StrToFloat(cmb_bx_number_propping_supports -> Text)));

}
//---------------------------------------------------------------------------
//������������� �������� � ������������� ��������� �� ���������
//(��� ������������� SW (������������ ����) ���������� ������������� ��������� I �������- �����������)
//---------------------------------------------------------------------------
Loads TCompositeBeamMainForm ::init_loads()
{
	double SW_sheets = 0.;

	if (rdgrp_slab_type->ItemIndex==1)
		SW_sheets = corrugated_sheets_map[cmb_bx_corrugated_sheeting_part_number->Text].get_weight()* GRAV_ACCELERAT;

	double SW = SteelSectionForm2 -> get_i_section().get_weight() * GRAV_ACCELERAT;

	double DL_I = 0.;
	double DL_II = 0.;
	double LL = 0.;
	double gamma_f_st_SW = 0.;
	double gamma_f_DL_I = 0.;
	double gamma_f_DL_II= 0.;
	double gamma_f_LL = 0.;

	String_double_zero_plus(lbl_dead_load_first_stage->Caption, edt_dead_load_first_stage->Text, &DL_I);
	String_double_zero_plus(lbl_dead_load_second_stage->Caption, edt_dead_load_second_stage->Text, &DL_II);
	String_double_zero_plus(lbl_live_load->Caption, edt_live_load->Text, &LL);
	String_double_zero_plus(lbl_gamma_f_st_SW->Caption, edt_gamma_f_st_SW_->Text, &gamma_f_st_SW);
	String_double_zero_plus(lbl_gamma_f_DL_I->Caption, edt_gamma_f_DL_I->Text, &gamma_f_DL_I);
	String_double_zero_plus(lbl_gamma_f_DL_II->Caption, edt_gamma_f_DL_II->Text, &gamma_f_DL_II);
	String_double_zero_plus(lbl_gamma_f_LL->Caption, edt_gamma_f_LL->Text, &gamma_f_LL);

	return Loads (SW, SW_sheets, DL_I, DL_II, LL, gamma_f_st_SW, gamma_f_DL_I, gamma_f_DL_II, gamma_f_LL);
}
//---------------------------------------------------------------------------
//������������� ��������� ��������
//---------------------------------------------------------------------------
ISection TCompositeBeamMainForm ::init_i_section()
{
	return SteelSectionForm2 -> get_i_section();
}
//---------------------------------------------------------------------------
//	������������� ��������� ��������
//---------------------------------------------------------------------------
Steel TCompositeBeamMainForm ::init_steel_i_section()
{
	return DefineSteelForm -> get_steel();
}
//---------------------------------------------------------------------------
//������������� �������������� ����� �������
//---------------------------------------------------------------------------
ConcretePart TCompositeBeamMainForm ::init_concrete_part()
{
	Geometry geometry = init_geomet();
	ISection i_section = SteelSectionForm2 -> get_i_section();
	double b_uf = i_section.get_b_uf();

	if (rdgrp_slab_type -> ItemIndex ==0)
	{
		double t_sl = 0.;
		double h_n = 0.;
		String_double_plus(lbl_h_f_flat -> Caption, edt_h_f_flat -> Text, &t_sl);
		String_double_zero_plus(lbl_h_n -> Caption, edt_h_n -> Text, &h_n);
		return ConcretePart (L"������� �����",
							  SlabType::FLAT,
							  ConcreteDefinitionForm->get_concrete(),
							  RebarDefinitionForm->get_rebar(),
							  t_sl,
							  h_n);
	}
	else
	{
	double h_f = 0.;

	String_double_plus(lbl_h_f->Caption, edt_h_f->Text, &h_f);

	return ConcretePart (cmb_bx_corrugated_sheeting_part_number->Text,
						  SlabType::CORRUGATED,
						  ConcreteDefinitionForm->get_concrete(),
						  RebarDefinitionForm->get_rebar(),
						  h_f,
						  0.);
	}
}
//---------------------------------------------------------------------------
//������������� �������� ����� �������
//---------------------------------------------------------------------------
SteelPart TCompositeBeamMainForm ::init_steel_part()
{

   ISection i_section = init_i_section();
   Steel steel_i_section = init_steel_i_section();

	return SteelPart(i_section, steel_i_section);
}
//---------------------------------------------------------------------------
//	������������� ������
//---------------------------------------------------------------------------
StudsOnBeam TCompositeBeamMainForm ::init_studs_on_beam()
{
	return StudDefinitionForm -> get_studs_on_beam();
}
//---------------------------------------------------------------------------
//	������������� ������������� ������� ������
//---------------------------------------------------------------------------
 WorkingConditionsFactors TCompositeBeamMainForm ::init_working_conditions_factors()
 {
	double gamma_bi=0.;
	double gamma_si=0.;
	double gamma_c=0.;

	String_double_plus(lbl_gamma_bi->Caption, edt_gamma_bi->Text, &gamma_bi);
	String_double_plus(lbl_gamma_si->Caption, edt_gamma_si->Text, &gamma_si);
	String_double_plus(lbl_gamma_c->Caption, edt_gamma_c->Text, &gamma_c);

	return WorkingConditionsFactors(gamma_bi,gamma_si,gamma_c);
 }

// ---------------------------------------------------------------------------
// ������������� ����������� �����
//---------------------------------------------------------------------------
void TCompositeBeamMainForm ::update_composite_beam()
{
   Geometry geometry = init_geomet();
   Loads loads = init_loads();

   SteelPart steel_part = init_steel_part();
   ConcretePart concrete_part = init_concrete_part();
   CompositeSectionGeometry composite_section = CompositeSectionGeometry(steel_part, concrete_part);

   StudsOnBeam studs_on_beam = init_studs_on_beam();

   WorkingConditionsFactors working_conditions_factors = init_working_conditions_factors();

   double max_elem_length = 0.;

	String_double_plus(lbl_max_elem_length -> Caption, edt_max_elem_length -> Text, &max_elem_length);

	composite_beam_calculator_ = CompositeBeamCalculator(geometry,
											  loads,
											  composite_section,
											  studs_on_beam,
											  working_conditions_factors,
											  max_elem_length);
}
//---------------------------------------------------------------------------
//	������� ����������� ������ ����������� �����
//---------------------------------------------------------------------------
void __fastcall TCompositeBeamMainForm ::BtnCalculateClick(TObject *Sender)
{
	calculate_composite_beam();
}
//---------------------------------------------------------------------------
//������������ � ������� �����
//---------------------------------------------------------------------------
void __fastcall TCompositeBeamMainForm ::btn_reportClick(TObject *Sender)
{
	Screen->Cursor = crHourGlass;//�� ����� �������� ������ �������� ������� ��� �����
	generate_report();
	Screen->Cursor = crDefault;//���������� ������� ��� �� ���������
}
//---------------------------------------------------------------------------
//	��������� ��������� ��� �������� ������ � �������� ������� � �����������
//	�� ���������� ����: ����� �� ������� ��� ������� �����
//---------------------------------------------------------------------------
void __fastcall TCompositeBeamMainForm ::rdgrp_slab_typeClick(TObject *Sender)
{
	switch(rdgrp_slab_type -> ItemIndex)
	{
		case 0: grp_bx_corrugated_slab -> Visible = false;
				grp_bx_flat_slab -> Visible = true;
				Image2 -> Visible = false;
				Image1 -> Visible = true;
				break;

	   case 1:	grp_bx_corrugated_slab -> Visible = true;
				grp_bx_flat_slab -> Visible = false;
				Image2 -> Visible = true;
				Image1 -> Visible = false;
				break;
	}
		OnControlsChange(nullptr);
}
//---------------------------------------------------------------------------
//���������� ������� �������������� ���������� ������ ������ ������ �������
//---------------------------------------------------------------------------
void __fastcall TCompositeBeamMainForm ::strng_grd_rendering(TObject *Sender,
																int ACol, int ARow,
																TRect &Rect, TGridDrawState State)
{
	TStringGrid* str_grid=static_cast<TStringGrid*>(Sender);
	if (ARow ==0)
	{
		str_grid->Canvas->Font->Style=TFontStyles()<< fsBold;
		str_grid->Canvas->Font->Style<<fsBold;
		str_grid->Canvas->FillRect(Rect);
		str_grid->Canvas->TextOut(Rect.Left+3, Rect.Top+5, str_grid->Cells[ACol][ARow]);
	}
}
//---------------------------------------------------------------------------
//	������� ����������� TStringGrid ��������� ���������� ������� �������������� ������������� ������������ �������
//---------------------------------------------------------------------------
void TCompositeBeamMainForm ::cotr_comp_sect_geometr_grid()
{
	strng_grd_compos_sect_geom_character->Cells [0][0]=L"�������������� ��������������";
	strng_grd_compos_sect_geom_character->Cells [1][0]=L"��������";
	strng_grd_compos_sect_geom_character->Cells [0][1]=L"������� Ared, ��2";
	strng_grd_compos_sect_geom_character->Cells [0][2]=L"������ ������� Ired, ��4 ";
	strng_grd_compos_sect_geom_character->Cells [0][3]=L"������ �������������, �.�. �.�. ����� Wb,red, ��3";
	strng_grd_compos_sect_geom_character->Cells [0][4]=L"������ �������������, �����. ����� Wf2,red, ��3";
	strng_grd_compos_sect_geom_character->Cells [0][5]=L"������ �������������, ����. ����� Wf1,red, ��3";
	strng_grd_compos_sect_geom_character->Cells [0][6]=L"���������� Zb,red, ��";
	strng_grd_compos_sect_geom_character->Cells [0][7]=L"���������� Zf2,red ��";
	strng_grd_compos_sect_geom_character->Cells [0][8]=L"���������� Zf1,red ��";
}
//---------------------------------------------------------------------------
//������� ����������� ������ TStringGrid ��������������� ���������������� ��������� �������
//---------------------------------------------------------------------------
void TCompositeBeamMainForm ::cotr_steel_sect_geometr_grid()
{
	strng_grd_steel_sect_geom_character->Cells [0][0]=L"�������������� ��������������";
	strng_grd_steel_sect_geom_character->Cells [1][0]=L"��������";
	strng_grd_steel_sect_geom_character->Cells [0][1]=L"�������";
	strng_grd_steel_sect_geom_character->Cells [0][2]=L"������ �������";
	strng_grd_steel_sect_geom_character->Cells [0][3]=L"������ ������������� ������� ������� ������� �����";
	strng_grd_steel_sect_geom_character->Cells [0][4]=L"������ ������������� ������� ������� ������ �����";
	strng_grd_steel_sect_geom_character->Cells [0][5]=L"���������� �� �.�. �� �������� ����� ������� �����";
	strng_grd_steel_sect_geom_character->Cells [0][6]=L"���������� �� �.�. �� �������� ����� ������ �����";
}
//---------------------------------------------------------------------------
//������� ����������� ������ TStringGrid ��������������� ���������������� ��������������� �������
//---------------------------------------------------------------------------
void TCompositeBeamMainForm ::ctor_concrete_sect_geometr_grid()
{
	strng_grd_concrete_sect_geom_character->Cells [0][0]=L"�������������� ��������������";
	strng_grd_concrete_sect_geom_character->Cells [1][0]=L"��������";
	strng_grd_concrete_sect_geom_character->Cells [0][1]=L"��������� �������� ����� �����";
	strng_grd_concrete_sect_geom_character->Cells [0][2]=L"��������� �������� ����� ������";
	strng_grd_concrete_sect_geom_character->Cells [0][3]=L"���������� �� ������ ����� �� ������ �������";
	strng_grd_concrete_sect_geom_character->Cells [0][4]=L"�������";
	strng_grd_concrete_sect_geom_character->Cells [0][5]=L"������ �������";
   //	strng_grd_concrete_sect_geom_character->Cells [0][6]=L"������ �������������";
}
void TCompositeBeamMainForm ::fill_steel_sect_geometr_grid()
{
	ISection i_section= composite_beam_calculator_.get_composite_section().get_steel_part().get_section();

	strng_grd_steel_sect_geom_character->Cells [1][1]=FloatToStrF(i_section.get_A_st(), ffFixed, 15, 0);
	strng_grd_steel_sect_geom_character->Cells [1][2]=FloatToStrF(i_section.get_I_st(), ffFixed, 15, 0);
	strng_grd_steel_sect_geom_character->Cells [1][3]=FloatToStrF(i_section.get_Wf2_st(), ffFixed, 15, 0);
	strng_grd_steel_sect_geom_character->Cells [1][4]=FloatToStrF(i_section.get_Wf1_st(), ffFixed, 15, 0);
	strng_grd_steel_sect_geom_character->Cells [1][5]=FloatToStrF(i_section.get_Z_f2_st(), ffFixed, 15, 0);
	strng_grd_steel_sect_geom_character->Cells [1][6]=FloatToStrF(i_section.get_Z_f1_st(), ffFixed, 15, 0);
}
void TCompositeBeamMainForm ::fill_concrete_sect_geometr_grid()
{
	ConcretePart concrete_part=composite_beam_calculator_.get_composite_section().get_concrete_part();

	//strng_grd_concrete_sect_geom_character->Cells [1][1]=FloatToStrF(concrete_part.get_b_l(), ffFixed, 15, 0);
	strng_grd_concrete_sect_geom_character->Cells [1][2]=FloatToStrF(concrete_part.get_b(), ffFixed, 15, 0);
	strng_grd_concrete_sect_geom_character->Cells [1][3]=FloatToStrF(concrete_part.get_C_b(), ffFixed, 15, 0);
	strng_grd_concrete_sect_geom_character->Cells [1][4]=FloatToStrF(concrete_part.get_A_b(), ffFixed, 15, 0);
	strng_grd_concrete_sect_geom_character->Cells [1][5]=FloatToStrF(concrete_part.get_I_b(), ffFixed, 15, 0);
}
void TCompositeBeamMainForm ::fill_composite_sect_geometr_grid()
{
	double A_red=composite_beam_calculator_.get_composite_section().get_A_red();
	double I_red=composite_beam_calculator_.get_composite_section().get_I_red();
	double W_b_red=composite_beam_calculator_.get_composite_section().get_W_b_red();
	double W_f2_red=composite_beam_calculator_.get_composite_section().get_W_f2_red();
	double W_f1_red=composite_beam_calculator_.get_composite_section().get_W_f1_red();
	double Z_b_red=composite_beam_calculator_.get_composite_section().get_Z_b_red();
	double Z_f2_red=composite_beam_calculator_.get_composite_section().get_Z_f2_red();
	double Z_f1_red=composite_beam_calculator_.get_composite_section().get_Z_f1_red();

	strng_grd_compos_sect_geom_character->Cells [1][1]=FloatToStrF(A_red, ffFixed, 15, 0); //��������� �������� �������� ���
	strng_grd_compos_sect_geom_character->Cells [1][2]=FloatToStrF(I_red, ffFixed, 15, 0); //���� double 15
	strng_grd_compos_sect_geom_character->Cells [1][3]=FloatToStrF(W_b_red, ffFixed, 15, 0);
	strng_grd_compos_sect_geom_character->Cells [1][4]=FloatToStrF(std::abs(W_f2_red), ffFixed, 15, 0);
	strng_grd_compos_sect_geom_character->Cells [1][5]=FloatToStrF(W_f1_red, ffFixed, 15, 0);
	strng_grd_compos_sect_geom_character->Cells [1][6]=FloatToStrF(Z_b_red, ffFixed, 15, 0);
	strng_grd_compos_sect_geom_character->Cells [1][7]=FloatToStrF(std::abs(Z_f2_red), ffFixed, 15, 0);
	strng_grd_compos_sect_geom_character->Cells [1][8]=FloatToStrF(Z_f1_red, ffFixed, 15, 0);
}

void TCompositeBeamMainForm ::fill_results_grid()
{
	Section max_direct_stress_ratio_section = composite_beam_calculator_.get_composite_beam().get_max_direct_stress_ratio_section();
	Section max_rigid_plastic_ratio_section = composite_beam_calculator_.get_composite_beam().get_max_rigid_plastic_ratio_section();
	Section max_shear_stress_section = composite_beam_calculator_.get_composite_beam().get_max_shear_stress_ratio_section();

	double max_upper_flange_ratio = max_direct_stress_ratio_section.get_upper_fl_ratio();
	double max_lower_flange_ratio = max_direct_stress_ratio_section.get_lower_fl_ratio();
	double ratio_rigid_plastic =  max_rigid_plastic_ratio_section.get_rigid_plastic_ratio();
//	double max_ratio_studs = composite_beam_calculator_.get_max_stud_ratio();
	double max_shear_ratio = max_shear_stress_section.get_shear_ratio();

	strng_grd_results->Cells [1][1]=FloatToStrF(std::abs(max_upper_flange_ratio), ffFixed, 15, 2);
	strng_grd_results->Cells [1][2]=FloatToStrF(std::abs(max_lower_flange_ratio), ffFixed, 15, 2);
	strng_grd_results->Cells [1][3]=FloatToStrF(std::abs(max_shear_ratio), ffFixed, 15, 2);
   //	strng_grd_results->Cells [1][4]=FloatToStrF(std::abs(max_ratio_studs), ffFixed, 15, 2);
	strng_grd_results->Cells [1][5]=FloatToStrF(ratio_rigid_plastic, ffFixed, 15, 2);

}
//---------------------------------------------------------------------------
//	������� ����������� Grid ��������� ���������� ������� ����������� �����
//---------------------------------------------------------------------------
void TCompositeBeamMainForm :: cotr_ratios_grid()
{
	strng_grd_results->Cells [0][0]="��������";
	strng_grd_results->Cells [1][0]="������������ ������������� (��) ";
	strng_grd_results->Cells [0][1]="������� ���� ��������� �������, ������ 6.2.1";
	strng_grd_results->Cells [0][2]="������ ���� ��������� ��������, ������ 6.2.1";
	strng_grd_results->Cells [0][3]="���������� ����, ������ 6.2.2";
	strng_grd_results->Cells [0][4]="��������� ������ �����������, ������ 9.1.2";
	strng_grd_results->Cells [0][5]="��������� ����� ��� ���������������� ��������� ������ 6.2.1.6";
}
//---------------------------------------------------------------------------
//	������� ����������� ComboBox �������� ����������
//---------------------------------------------------------------------------
void TCompositeBeamMainForm ::fill_cmb_bx_impact()
{
	cmb_bx_impact -> Items -> Append(L"��������� �������� Ia ������");
	cmb_bx_impact -> Items -> Append(L"��������� �������� Ib ������");
	cmb_bx_impact -> Items -> Append(L"��������� �������� IIa ������");
	cmb_bx_impact -> Items -> Append(L"��������� �������� IIb ������");
	cmb_bx_impact -> Items -> Append(L"��������� �������� ������");

	cmb_bx_impact -> ItemIndex = 4;
}
//---------------------------------------------------------------------------
//	������� ����������� ComboBox ���������
//---------------------------------------------------------------------------
void TCompositeBeamMainForm ::fill_cmb_bx_corrugated_sheets()
{
	for(auto corrugated_sheet: corrugated_sheets_map)
	cmb_bx_corrugated_sheeting_part_number->Items->Add(corrugated_sheet.first);
	cmb_bx_corrugated_sheeting_part_number->ItemIndex = 0;

}
//---------------------------------------------------------------------------

void __fastcall TCompositeBeamMainForm ::BtBtnSteelChoiceClick(TObject *Sender)
{
	 DefineSteelForm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TCompositeBeamMainForm ::BtnSteelSectionChoiceClick(TObject *Sender)
{
	SteelSectionForm2 -> Show();
}
//---------------------------------------------------------------------------


void __fastcall TCompositeBeamMainForm ::BtBtnExitClick(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

void __fastcall TCompositeBeamMainForm ::BtnConcreteChoiceClick(TObject *Sender)
{
	ConcreteDefinitionForm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TCompositeBeamMainForm ::BtBtnRebarsChoiceClick(TObject *Sender)
{
	RebarDefinitionForm->Show();

}
//---------------------------------------------------------------------------

void __fastcall TCompositeBeamMainForm ::BtBtnShearStudsChoiceClick(TObject *Sender)
{
	StudDefinitionForm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TCompositeBeamMainForm ::NOutReportClick(TObject *Sender)
{
	generate_report();
}
//---------------------------------------------------------------------------

void __fastcall TCompositeBeamMainForm ::NExitClick(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
//�������� ������
//---------------------------------------------------------------------------
void TCompositeBeamMainForm ::generate_report()
{
	TWord_Automation report_ = TWord_Automation("ReportCompositeBeam.docx");

	CompositeBeam composite_beam = composite_beam_calculator_.get_composite_beam();
	CompositeSectionGeometry composite_section = composite_beam.get_composite_section();

	StudsOnBeam studs_on_beam = composite_beam_calculator_.get_studs_on_beam() ;

	ConcretePart concrete_part = composite_section.get_concrete_part();

//[1.1] ���������
	Geometry geometry = composite_beam_calculator_.get_geometry();

	report_.PasteTextPattern(geometry.is_end_beam_to_str(), "%end_beam%");
	report_.PasteTextPattern(FloatToStrF(geometry.get_span(LengthUnit::mm), ffFixed, 15, 2), "%span%");
	report_.PasteTextPattern(FloatToStrF(geometry.get_trib_width_left(LengthUnit::mm), ffFixed, 15, 2), "%trib_width_left% ");
	report_.PasteTextPattern(FloatToStrF(geometry.get_trib_width_right(LengthUnit::mm), ffFixed, 15, 2), "%trib_width_right% ");
//[1.2] ����������
	Loads loads = composite_beam_calculator_.get_loads();

	report_.PasteTextPattern(FloatToStrF(loads.get_dead_load_first_stage(LoadUnit::kN, LengthUnit::m), ffFixed, 15, 2), "%DL_I%");
	report_.PasteTextPattern(FloatToStrF(loads.get_dead_load_second_stage(LoadUnit::kN, LengthUnit::m), ffFixed, 15, 2), "%DL_II%");
	report_.PasteTextPattern(FloatToStrF(loads.get_live_load(LoadUnit::kN, LengthUnit::m), ffFixed, 15, 2), "%LL%");

//[1.3] ������������ ��������� �� ��������
	WorkingConditionsFactors working_conditions_factors = composite_beam.get_working_conditions_factors();

	report_.PasteTextPattern(FloatToStrF(loads.get_gamma_f_st_SW(), ffFixed, 15, 2), "%gamma_f_st_SW%");
	report_.PasteTextPattern(FloatToStrF(loads.get_gamma_f_DL_I(), ffFixed, 15, 2), "%gamma_f_DL_I%");
	report_.PasteTextPattern(FloatToStrF(loads.get_gamma_f_DL_II(), ffFixed, 15, 2), "%gamma_f_DL_II%");
	report_.PasteTextPattern(FloatToStrF(loads.get_gamma_f_LL(), ffFixed, 15, 2), "%gamma_f_LL%");
//[1.4] �������� �������
//[1.4.1] ����������� ������� ��������
	ISection i_section = composite_section.get_steel_part().get_section();

	report_.PasteTextPattern(i_section.get_profile_number(),"%profile_number%");
	report_.PasteTextPattern(FloatToStrF(i_section.get_h_st(LengthUnit::mm), ffFixed, 15, 2),"%h%");
	report_.PasteTextPattern(FloatToStrF(0, ffFixed, 15, 2),"%h%");
	report_.PasteTextPattern(FloatToStrF(i_section.get_b_uf(LengthUnit::mm), ffFixed, 15, 2),"%b%");
	report_.PasteTextPattern(FloatToStrF(0, ffFixed, 15, 2),"%b_w%");
	report_.PasteTextPattern(FloatToStrF(i_section.get_t_uf(LengthUnit::mm), ffFixed, 15, 2),"%t%");
	report_.PasteTextPattern(FloatToStrF(i_section.get_t_w(LengthUnit::mm), ffFixed, 15, 2),"%s%");
	report_.PasteTextPattern(FloatToStrF(i_section.get_r(LengthUnit::mm), ffFixed, 15, 2),"%r%");
//[1.4.2] �������������� �����
	Steel steel = composite_section.get_steel_part().get_steel();

	report_.PasteTextPattern(steel.get_steel_grade(),"%steel_grade%");
	report_.PasteTextPattern(FloatToStrF(steel.get_R_yn(), ffFixed, 15, 2),"%R_yn%");
	report_.PasteTextPattern(FloatToStrF(steel.get_R_un(), ffFixed, 15, 2),"%R_un%");
	report_.PasteTextPattern(FloatToStrF(steel.get_E_st(), ffFixed, 15, 2),"%E_st%");
	report_.PasteTextPattern(FloatToStrF(steel.get_G_st(), ffFixed, 15, 2),"%G_st%");
	report_.PasteTextPattern(FloatToStrF(steel.get_nu_st(), ffFixed, 15, 2),"%nu_st%");
	report_.PasteTextPattern(FloatToStrF(steel.get_gamma_m(), ffFixed, 15, 2),"%gamma_m%");
//[1.5] �������������� �������
//[1.5.1] ����������� ������� �����
	report_.PasteTextPattern(concrete_part.get_slab_type(),"%slab_type%");
	report_.PasteTextPattern(concrete_part.get_h(),"%t_sl%");

//[1.5.2] �������������� ������
	Concrete concrete = concrete_part.get_concrete();

	report_.PasteTextPattern(concrete.get_grade(),"%conc_grade%");
	report_.PasteTextPattern(FloatToStrF(concrete.get_R_bn(), ffFixed, 15, 2),"%R_bn%");
	report_.PasteTextPattern(FloatToStrF(concrete.get_R_btn(), ffFixed, 15, 2),"%R_btn%");
	report_.PasteTextPattern(FloatToStrF(concrete.get_E_b(), ffFixed, 15, 2),"%E_b%");
	report_.PasteTextPattern(FloatToStrF(concrete.get_gamma_b(), ffFixed, 15, 2),"%gamma_b%");
	report_.PasteTextPattern(FloatToStrF(concrete.get_gamma_bt(), ffFixed, 15, 2),"%gamma_bt%");

//[1.6] ��������
	Rebar rebar = concrete_part.get_rebar();

	report_.PasteTextPattern(rebar.get_grade(),"%grade%");
	report_.PasteTextPattern(FloatToStrF(rebar.get_diameter(), ffFixed, 15, 2),"%d%");
	report_.PasteTextPattern(FloatToStrF(rebar.get_R_sn(), ffFixed, 15, 2),"%R_sn%");
//[1.7] �������������� ��������
	Stud stud = studs_on_beam.get_stud();

	report_.PasteTextPattern(stud.get_name(),"%name%");
	report_.PasteTextPattern(FloatToStrF(stud.get_l(cm), ffFixed, 15, 2),"%l%");
	report_.PasteTextPattern(FloatToStrF(stud.get_d_an(cm), ffFixed, 15, 2),"%d_an%");
	report_.PasteTextPattern(FloatToStrF(stud.get_R_y(), ffFixed, 15, 2),"%R_y%");
	report_.PasteTextPattern(FloatToStrF(studs_on_beam.get_dist_e(cm), ffFixed, 15, 2),"%z_e%");
	report_.PasteTextPattern(FloatToStrF(studs_on_beam.get_dist_m(cm), ffFixed, 15, 2),"%z_m%");
	report_.PasteTextPattern(FloatToStrF(studs_on_beam.get_num_e(), ffFixed, 15, 2),"%ed_rw_num%");
	report_.PasteTextPattern(FloatToStrF(studs_on_beam.get_num_m(), ffFixed, 15, 2),"%mid_rw_num%");

//[1.8] ������������
	report_.PasteTextPattern(FloatToStrF(working_conditions_factors.get_gamma_c(), ffFixed, 15, 2),"%gamma_c%");
	report_.PasteTextPattern(FloatToStrF(working_conditions_factors.get_gamma_bi(), ffFixed, 15, 2),"%gamma_bi%");
	report_.PasteTextPattern(FloatToStrF(working_conditions_factors.get_gamma_si(), ffFixed, 15, 2),"%gamma_si%");
//[1.9] ������
	report_.PasteTextPattern(FloatToStrF(static_cast<int>(geometry.get_temporary_supports_number()), ffFixed, 15, 2),"%temp_supp%");

//[2] ���������� ������� �����
//[2.1] �������������� ���������
//[2.1.1] ��������� �������
	report_.PasteTextPattern(FloatToStrF(i_section.get_A_st(LengthUnit::cm), ffFixed, 15, 2),"%A_st%");
	report_.PasteTextPattern(FloatToStrF(i_section.get_I_st(LengthUnit::cm), ffFixed, 15, 2),"%I_st%");
	report_.PasteTextPattern(FloatToStrF(i_section.get_Wf2_st(LengthUnit::cm), ffFixed, 15, 2),"%Wf2_st%");
	report_.PasteTextPattern(FloatToStrF(i_section.get_Wf1_st(LengthUnit::cm), ffFixed, 15, 2),"%Wf1_st%");
	report_.PasteTextPattern(FloatToStrF(i_section.get_Z_f2_st(LengthUnit::cm), ffFixed, 15, 2),"%Z_f2_st%");
	report_.PasteTextPattern(FloatToStrF(i_section.get_Z_f1_st(LengthUnit::cm), ffFixed, 15, 2),"%Z_f1_st%");
//[2.1.2] ��������������� �������
	report_.PasteTextPattern(concrete_part.get_slab_type(),"%slab_type%");
	report_.PasteTextPattern(FloatToStrF(concrete_part.get_b(LengthUnit::cm), ffFixed, 15, 2),"%b_l%");
	report_.PasteTextPattern(FloatToStrF(concrete_part.get_C_b(LengthUnit::cm), ffFixed, 15, 2),"%C_b%");
	report_.PasteTextPattern(FloatToStrF(concrete_part.get_A_b(LengthUnit::cm), ffFixed, 15, 2),"%A_b%");
	report_.PasteTextPattern(FloatToStrF(concrete_part.get_I_b(LengthUnit::cm), ffFixed, 15, 2),"%I_b%");
//[2.1.3] ������������ �������
	report_.PasteTextPattern(FloatToStrF(composite_section.get_A_red(LengthUnit::cm), ffFixed, 15, 2),"%A_red%");
	report_.PasteTextPattern(FloatToStrF(composite_section.get_I_red(LengthUnit::cm), ffFixed, 15, 2),"%I_red%");
	report_.PasteTextPattern(FloatToStrF(composite_section.get_W_b_red(LengthUnit::cm), ffFixed, 15, 2),"%W_b_red%");
	report_.PasteTextPattern(FloatToStrF(composite_section.get_W_f2_red(LengthUnit::cm), ffFixed, 15, 2),"%W_f2_red%");
	report_.PasteTextPattern(FloatToStrF(composite_section.get_W_f1_red(LengthUnit::cm), ffFixed, 15, 2),"%W_f1_red%");
	report_.PasteTextPattern(FloatToStrF(composite_section.get_Z_b_red(LengthUnit::cm), ffFixed, 15, 2),"%Z_b_red%");
	report_.PasteTextPattern(FloatToStrF(composite_section.get_Z_f2_red(LengthUnit::cm), ffFixed, 15, 2),"%Z_f2_red%");
	report_.PasteTextPattern(FloatToStrF(composite_section.get_Z_f1_red(LengthUnit::cm), ffFixed, 15, 2),"%Z_f1_red%");
//[2.2] ������
	Section max_direct_stress_ratio_section = composite_beam_calculator_.get_composite_beam().get_max_direct_stress_ratio_section();

	report_.PasteTextPattern(FloatToStrF(max_direct_stress_ratio_section.get_x(), ffFixed, 15, 0),"%cs_x%");
	report_.PasteTextPattern(FloatToStrF(max_direct_stress_ratio_section.get_M_Ia_design(kN, m), ffFixed, 15, 2),"%M_Ia%");
	report_.PasteTextPattern(FloatToStrF(max_direct_stress_ratio_section.get_M_Ib_design(kN, m), ffFixed, 15, 2),"%M_Ib%");
	report_.PasteTextPattern(FloatToStrF(max_direct_stress_ratio_section.get_M_IIa_design(kN, m), ffFixed, 15, 2),"%M_IIa%");
	report_.PasteTextPattern(FloatToStrF(max_direct_stress_ratio_section.get_M_IIb_design(kN, m), ffFixed, 15, 2),"%M_IIb%");
	report_.PasteTextPattern(FloatToStrF(max_direct_stress_ratio_section.get_M_total_design(kN, m), ffFixed, 15, 2),"%M_total%");

//[2.3] ����������
	report_.PasteTextPattern(FloatToStrF(max_direct_stress_ratio_section.get_sigma_b(), ffFixed, 15, 2),"%sigma_b%");
	report_.PasteTextPattern(FloatToStrF(max_direct_stress_ratio_section.get_sigma_s(), ffFixed, 15, 2),"%sigma_s%");
//[2.4] ������������ �������������
	report_.PasteTextPattern(FloatToStrF(max_direct_stress_ratio_section.get_upper_fl_ratio(),ffFixed, 15, 2),"%ratio_uf%");
	report_.PasteTextPattern(FloatToStrF(max_direct_stress_ratio_section.get_lower_fl_ratio(),ffFixed, 15, 2),"%ratio_lf%");
	report_.PasteTextPattern(FloatToStrF(max_direct_stress_ratio_section.get_shear_ratio(),ffFixed, 15, 2),"%ratio_shear%");


//[3] ���������� ������� ����������� �����������

//[3.1] ������� ����������� �����

	report_.PasteTextPattern(FloatToStrF(stud.get_P_rd(kN),ffFixed, 15, 2),"%P_rd%");

  //[3.2] ������
  //report_.PasteTextPattern(FloatToStrF(composite_beam_calculator_.get_max_stud_ratio_coordinate(),ffFixed, 15, 2),"%cs_stud%");
  //report_.PasteTextPattern(FloatToStrF(composite_beam_calculator_.get_max_S_h(LoadUnit::kN),ffFixed, 15, 2),"%S_h%");

 //  [3.3] ������������ �������������
  //	report_.PasteTextPattern(FloatToStrF(composite_beam_calculator_.get_max_stud_ratio(),ffFixed, 15, 2),"%ratio_stud%");
}

//---------------------------------------------------------------------------
// ��������� ����
//---------------------------------------------------------------------------
void TCompositeBeamMainForm ::draw_diagram()
{
	std::vector<double> M;
	std::vector<double> Q;
	std::vector<double> R;
	std::vector<double> f;

	std::vector<double>	coor_supp {};

	switch (cmb_bx_impact->ItemIndex)
	{
	case(0): // ��������� �������� Ia ������

		M = composite_beam_calculator_.get_composite_beam().get_M_Ia_design_list(LoadUnit::kN, LengthUnit::m);
		Q = composite_beam_calculator_.get_composite_beam().get_Q_Ia_design_list(LoadUnit::kN);
		R = composite_beam_calculator_.get_composite_beam().get_R_Ia_design_list(LoadUnit::kN);
		f = composite_beam_calculator_.get_composite_beam().get_f_Ia_design_list(LengthUnit::mm);

		coor_supp = composite_beam_calculator_.get_composite_beam().get_support_x_list();

		break;
	case(1): // ��������� �������� Ib ������

		M = composite_beam_calculator_.get_composite_beam().get_M_Ib_design_list(LoadUnit::kN, LengthUnit::m);
		Q = composite_beam_calculator_.get_composite_beam().get_Q_Ib_design_list(LoadUnit::kN);
		R = composite_beam_calculator_.get_composite_beam().get_R_Ib_design_list(LoadUnit::kN);
		f = composite_beam_calculator_.get_composite_beam().get_f_Ib_design_list(LengthUnit::mm);

		coor_supp = composite_beam_calculator_.get_composite_beam().get_support_x_list();

		break;
	case(2): // ��������� �������� IIa ������

		M = composite_beam_calculator_.get_composite_beam().get_M_IIa_design_list(LoadUnit::kN, LengthUnit::m);
		Q = composite_beam_calculator_.get_composite_beam().get_Q_IIa_design_list(LoadUnit::kN);
		R = composite_beam_calculator_.get_composite_beam().get_P_IIa_design_list(LoadUnit::kN);
		f = composite_beam_calculator_.get_composite_beam().get_f_IIa_design_list(LengthUnit::mm);

		coor_supp.push_back(composite_beam_calculator_.get_composite_beam().get_support_x_list().front());
		coor_supp.push_back(composite_beam_calculator_.get_composite_beam().get_support_x_list().back());

		break;

	case(3): // ��������� �������� IIb ������

		M = composite_beam_calculator_.get_composite_beam().get_M_IIb_design_list(LoadUnit::kN, LengthUnit::m);
		Q = composite_beam_calculator_.get_composite_beam().get_Q_IIb_design_list(LoadUnit::kN);
		R = composite_beam_calculator_.get_composite_beam().get_R_IIb_design_list(LoadUnit::kN);
		f = composite_beam_calculator_.get_composite_beam().get_f_IIb_design_list(LengthUnit::mm);

		coor_supp.push_back(composite_beam_calculator_.get_composite_beam().get_support_x_list().front());
		coor_supp.push_back(composite_beam_calculator_.get_composite_beam().get_support_x_list().back());

		break;

	case(4)://��������� �������� ������

		M = composite_beam_calculator_.get_composite_beam().get_M_total_design_list(LoadUnit::kN, LengthUnit::m);
		Q = composite_beam_calculator_.get_composite_beam().get_Q_total_design_list(LoadUnit::kN);
		R = composite_beam_calculator_.get_composite_beam().get_R_total_design_list(LoadUnit::kN);
		f = composite_beam_calculator_.get_composite_beam().get_f_total_design_list(LengthUnit::mm);

		coor_supp.push_back(composite_beam_calculator_.get_composite_beam().get_support_x_list().front());
		coor_supp.push_back(composite_beam_calculator_.get_composite_beam().get_support_x_list().back());

		break;
	}

	TImage *Image1=img_static_scheme;
	std::vector<double> coor_epur = composite_beam_calculator_.get_composite_beam().get_x_list();

//	//���� ��������� �������� �� �����
	bool flag_sign=true;

	switch (rd_grp_internal_forces_type->ItemIndex)
	{
	case(0):

		std::transform(M.begin(),M.end(), M.begin(), [](double M) { return -1*std::round(M*1000)/1000;});
		DrawEpur(Image1, M.size(), &coor_epur[0], &M[0], nullptr, coor_supp.size(), &coor_supp[0], flag_sign);

		break;

	case(1):

		std::transform(Q.begin(),Q.end(), Q.begin(), [](double Q) { return -1*std::round(Q*1000)/1000;});
		std::transform(R.begin(),R.end(), R.begin(), [](double R) { return -1*std::round(R*1000)/1000;});
		DrawEpur(Image1, Q.size(), &coor_epur[0], &Q[0], &R[0], coor_supp.size(), &coor_supp[0], flag_sign);

		break;

	case(2):

		std::transform(f.begin(),f.end(), f.begin(), [](double f) { return std::round(f*1000000)/1000000;});
		DrawEpur(Image1, f.size(), &coor_epur[0], &f[0], nullptr, coor_supp.size(), &coor_supp[0], flag_sign);

		break;
	}
}

void __fastcall TCompositeBeamMainForm ::cmb_bx_impactChange(TObject *Sender)
{
	draw_diagram();
}
//---------------------------------------------------------------------------

void __fastcall TCompositeBeamMainForm ::rd_grp_internal_forces_typeClick(TObject *Sender)

{
	draw_diagram();
}

void TCompositeBeamMainForm ::calculate_composite_beam()
{
   update_composite_beam();
   composite_beam_calculator_.calculate();
   //����� ����������� ������� � GUI
	draw_diagram();
	fill_steel_sect_geometr_grid();
	fill_concrete_sect_geometr_grid();
	fill_composite_sect_geometr_grid();
	fill_results_grid();

//����� ����������� ������� � �����
	btn_report->Enabled=true;
	tb_results->TabVisible=true;
}
//---------------------------------------------------------------------------



void __fastcall TCompositeBeamMainForm ::NNewClick(TObject *Sender)
{
	int i;
	if (modify_project) {
		 i=Application->MessageBox(L"��������� ������� ������?", L" ",
				  MB_YESNO | MB_ICONQUESTION);
		 if (i==IDYES) NSaveClick(Sender);
	}
	strcpy(ModelFile, UNTITLED);
	modify_project = false;

	Caption = "������ ��������������� ����� - [����� ������]";

}
//---------------------------------------------------------------------------

void __fastcall TCompositeBeamMainForm ::NSaveClick(TObject *Sender)
{
	update_composite_beam(); //������������� ����������� ����� �� ����� �����
   // ��������� ����� ����������, � ������� ��������� ����������� ������

   if  (strcmp(ModelFile, UNTITLED)==0) {
	  if(SaveDialog_Model->Execute())
	  {
		  FileDir_Name = SaveDialog_Model->FileName;;//���� ����� ������ ���� ������
		  ModelName(FileDir_Name.c_str(), ModelFile); //�������� ��� ����� ��� ����������� �� ����� �� ����
	  }
   }

	std::ofstream ofstr {FileDir_Name.c_str(), std::ios::out | std::ios::binary};
	composite_beam_calculator_.save(ofstr);
	ofstr.close();

   Caption = "������ ��������������� ����� - " + AnsiString(ModelFile);

   modify_project = false;
}

void __fastcall TCompositeBeamMainForm ::NSaveAsClick(TObject *Sender)
{
	strcpy(ModelFile, UNTITLED);
	NSaveClick(Sender);
}
//---------------------------------------------------------------------------
//@--------------------------------------------------------------------------
// ��������� �� ����� ����� � ����� ������
void ModelName(char * str0, char* ModelFile)
{
	  char *ptr1, *ptr2;
	 // char i, str[240];
	 char str[240]; //MV 15.04.2020

	  if  (strcmp(ModelFile, UNTITLED)==0) {
	   //i= 240<strlen(str0) ? 240 : strlen(str0);
	   240<strlen(str0) ? 240 : strlen(str0); //MV 15.04.2020
	   strcpy(str,str0);
	   ptr1 = strrchr(str,'\\');
	   ptr2 = strrchr(ptr1,'.');
	   if (ptr2!=NULL)
		 *ptr2='\0';
	   if (ptr1==NULL)
		 strcpy(ModelFile, str);
	   else
		 strcpy(ModelFile, ptr1+1);
	  }
}

void __fastcall TCompositeBeamMainForm ::NOpenClick(TObject *Sender)
{

   NNewClick(Sender);

   if(OpenDialog_Model->Execute())
   {
	  FileDir_Name = OpenDialog_Model->FileName;
   }
   if (FileDir_Name!="") {

	  strcpy(ModelFile, UNTITLED);

	  std::ifstream ifstr {FileDir_Name.c_str(), std::ios::in | std::ios::binary};

	  composite_beam_calculator_.load(ifstr);

	  ifstr.close();

	  set_form_controls();

	  ModelName(FileDir_Name.c_str(), ModelFile);

	  Caption = "������ ��������������� ����� - " + AnsiString(ModelFile);

	  modify_project = false;

   }

}
//---------------------------------------------------------------------------
void TCompositeBeamMainForm ::clean_static_scheme()
{
	img_static_scheme -> Canvas -> Brush -> Color = clWhite;
	img_static_scheme -> Canvas->FillRect (img_static_scheme -> Canvas -> ClipRect);
}
void TCompositeBeamMainForm ::clean_grid(TStringGrid* str_grd)
{
	for(int i =1; i < str_grd -> RowCount; ++i)
	   str_grd -> Cells [1][i] = "";
}
void __fastcall TCompositeBeamMainForm ::OnControlsChange(TObject *Sender)
{
	if (btn_report->Enabled)
		btn_report->Enabled=false;
	if(tb_results->TabVisible)
		tb_results->TabVisible=false;
	clean_static_scheme();
	clean_grid(strng_grd_compos_sect_geom_character);
	clean_grid(strng_grd_concrete_sect_geom_character);
	clean_grid(strng_grd_steel_sect_geom_character);
	clean_grid(strng_grd_results);

}
//---------------------------------------------------------------------------

void __fastcall TCompositeBeamMainForm ::chck_bx_end_beamClick(TObject *Sender)
{
	if (chck_bx_end_beam->Checked){
		lbl_trib_width_left->Caption="���� ����� [��]:";
		lbl_trib_width_right->Caption="���������� ����� ������� [��]:";
		}
	else{
		lbl_trib_width_left->Caption="���������� ����� ������� ����� [��]:";
		lbl_trib_width_right->Caption="���������� ����� ������� ������ [��]:";
	}
	OnControlsChange(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TCompositeBeamMainForm ::cmb_bx_analysis_theoryChange(TObject *Sender)

{
    OnControlsChange(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TCompositeBeamMainForm ::cmb_bx_corrugated_sheeting_part_numberChange(TObject *Sender)
{
	OnControlsChange(Sender);
}

//---------------------------------------------------------------------------
void TCompositeBeamMainForm ::update(IPublisher* ipublisher )
{
	switch(ipublisher -> get_id())
	{
		case(Publisher_ID::REBARS_FORM):
			pnl_rebar_viewer -> Caption = ipublisher -> get_information();
			OnControlsChange(nullptr);
			break;
		case(Publisher_ID::STUDS_FORM):
			pnl_shear_stud_viewer -> Caption = ipublisher -> get_information();
			OnControlsChange(nullptr);
			break;
		case(Publisher_ID::CONCRETE_FORM):
			pnl_concrete_grade -> Caption = ipublisher -> get_information();
			OnControlsChange(nullptr);
			break;
		case(Publisher_ID::STEEL_FORM):
			pnl_steel -> Caption = ipublisher -> get_information();
			OnControlsChange(nullptr);
			break;
		case(Publisher_ID::SECTION_FORM):
			Pnl_SteelSectionViewer -> Caption = ipublisher -> get_information();
			OnControlsChange(nullptr);
			break;
	}

}

//---------------------------------------------------------------------------

void __fastcall TCompositeBeamMainForm ::btn_loggerClick(TObject *Sender)
{
	FormLogger->Show();
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------



void __fastcall TCompositeBeamMainForm ::N8Click(TObject *Sender)
{
	AboutProgForm->ShowModal();
}
//---------------------------------------------------------------------------



