object CompositeBeamMainForm: TCompositeBeamMainForm
  Left = 0
  Top = 0
  HorzScrollBar.Visible = False
  VertScrollBar.Visible = False
  Caption = #1050#1086#1084#1073#1080#1085#1080#1088#1086#1074#1072#1085#1085#1072#1103' '#1073#1072#1083#1082#1072
  ClientHeight = 592
  ClientWidth = 1062
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object lbl_beam_division: TLabel
    Left = 469
    Top = 567
    Width = 90
    Height = 13
    Caption = #1056#1072#1079#1073#1080#1077#1085#1080#1077' '#1073#1072#1083#1082#1080':'
    Visible = False
  end
  object ToolBar1: TToolBar
    Left = 0
    Top = 0
    Width = 1062
    Height = 23
    Caption = 'ToolBar1'
    Images = ImageList1
    TabOrder = 0
    object ToolButton1: TToolButton
      Left = 0
      Top = 0
      Hint = #1053#1086#1074#1099#1081' '#1087#1088#1086#1077#1082#1090' '
      Caption = #1053#1086#1074#1099#1081' '#1087#1088#1086#1077#1082#1090
      ImageIndex = 0
      MenuItem = NNew
      ParentShowHint = False
      ShowHint = True
    end
    object ToolButtonOpen: TToolButton
      Left = 23
      Top = 0
      Hint = #1054#1090#1082#1088#1099#1090#1100' '#1092#1072#1081#1083' '#1087#1088#1086#1077#1082#1090#1072' '#1050#1086#1084#1073#1080#1085#1080#1088#1086#1074#1072#1085#1085#1072#1103' '#1073#1072#1083#1082#1072
      Caption = #1054#1090#1082#1088#1099#1090#1100
      ImageIndex = 1
      MenuItem = NOpen
      ParentShowHint = False
      ShowHint = True
    end
    object ToolButtonSave: TToolButton
      Left = 46
      Top = 0
      Hint = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1092#1072#1081#1083' '#1087#1088#1086#1077#1082#1090#1072' '#1050#1086#1084#1073#1080#1085#1080#1088#1086#1074#1072#1085#1085#1072#1103' '#1073#1072#1083#1082#1072
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
      ImageIndex = 2
      MenuItem = NSave
      ParentShowHint = False
      ShowHint = True
    end
    object ToolButtonSaveAs: TToolButton
      Left = 69
      Top = 0
      Hint = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1092#1072#1081#1083' '#1087#1088#1086#1077#1082#1090#1072' '#1087#1086#1076' '#1076#1088#1091#1075#1080#1084' '#1080#1084#1077#1085#1077#1084
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1082#1072#1082
      ImageIndex = 3
      MenuItem = NSaveAs
      ParentShowHint = False
      ShowHint = True
    end
    object ToolButtonOutReport: TToolButton
      Left = 92
      Top = 0
      Hint = #1042#1099#1074#1086#1076' '#1086#1090#1095#1077#1090#1072' '#1074' '#1092#1086#1088#1084#1072#1090#1077' Word'
      Caption = #1042#1099#1074#1086#1076' '#1086#1090#1095#1105#1090#1072
      ImageIndex = 4
      MenuItem = NOutReport
      ParentShowHint = False
      ShowHint = True
    end
  end
  object edt_beam_division: TEdit
    Left = 565
    Top = 563
    Width = 42
    Height = 21
    Hint = #1042#1074#1077#1076#1080#1090#1077' '#1082#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1089#1077#1095#1077#1085#1080#1081' '#1073#1072#1083#1082#1080' '#1076#1083#1103' '#1087#1088#1086#1074#1077#1088#1082#1080
    NumbersOnly = True
    ParentShowHint = False
    ShowHint = True
    TabOrder = 1
    Text = '50'
    Visible = False
  end
  object BtnCalculate: TButton
    Left = 17
    Top = 561
    Width = 75
    Height = 25
    Caption = #1056#1072#1089#1095#1105#1090
    TabOrder = 2
    OnClick = BtnCalculateClick
  end
  object btn_report: TButton
    Left = 97
    Top = 561
    Width = 75
    Height = 25
    Caption = #1054#1090#1095#1105#1090
    TabOrder = 3
    OnClick = btn_reportClick
  end
  object BtBtnExit: TBitBtn
    Left = 178
    Top = 561
    Width = 75
    Height = 25
    Caption = #1042#1099#1093#1086#1076
    TabOrder = 4
    OnClick = BtBtnExitClick
  end
  object PgCntrlCompositeBeam: TPageControl
    Left = 0
    Top = 23
    Width = 1062
    Height = 528
    ActivePage = TbShtSectionMaterials
    Align = alTop
    TabOrder = 5
    object TbShtStaticScheme: TTabSheet
      AlignWithMargins = True
      Caption = #1056#1072#1089#1095#1105#1090#1085#1072#1103' '#1089#1093#1077#1084#1072
      object GrpBxLoadsSafetyFactors: TGroupBox
        Left = 594
        Top = 3
        Width = 251
        Height = 145
        Caption = '  '#1050#1086#1101#1092#1092#1080#1094#1080#1077#1085#1090#1099' '#1085#1072#1076#1105#1078#1085#1086#1089#1090#1080' '#1087#1086' '#1085#1072#1075#1088#1091#1079#1082#1072#1084'  '
        TabOrder = 0
        object lbl_gamma_f_DL_I: TLabel
          Left = 16
          Top = 60
          Width = 112
          Height = 13
          Caption = #1055#1086#1089#1090#1086#1103#1085#1085#1072#1103'  '#1085#1072#1075#1088#1091#1079#1082#1072
        end
        object lbl_gamma_f_DL_II: TLabel
          Left = 16
          Top = 98
          Width = 112
          Height = 13
          Caption = #1055#1086#1089#1090#1086#1103#1085#1085#1072#1103'  '#1085#1072#1075#1088#1091#1079#1082#1072
        end
        object Label2: TLabel
          Left = 16
          Top = 41
          Width = 50
          Height = 13
          Caption = 'I '#1089#1090#1072#1076#1080#1103
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label6: TLabel
          Left = 16
          Top = 79
          Width = 55
          Height = 13
          Caption = 'II '#1089#1090#1072#1076#1080#1103
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object lbl_gamma_f_LL: TLabel
          Left = 16
          Top = 125
          Width = 106
          Height = 13
          Caption = #1042#1088#1077#1084#1077#1085#1085#1072#1103'  '#1085#1072#1075#1088#1091#1079#1082#1072
        end
        object lbl_gamma_f_st_SW: TLabel
          Left = 16
          Top = 22
          Width = 171
          Height = 13
          Caption = #1057#1086#1073#1089#1090#1074#1077#1085#1085#1099#1081' '#1074#1077#1089' '#1089#1090#1072#1083#1100#1085#1086#1081' '#1073#1072#1083#1082#1080
        end
        object edt_gamma_f_DL_I: TEdit
          Left = 196
          Top = 46
          Width = 45
          Height = 21
          TabOrder = 0
          Text = '1.35'
          OnChange = OnControlsChange
        end
        object edt_gamma_f_DL_II: TEdit
          Left = 196
          Top = 94
          Width = 45
          Height = 21
          TabOrder = 1
          Text = '1.35'
          OnChange = OnControlsChange
        end
        object edt_gamma_f_LL: TEdit
          Left = 196
          Top = 121
          Width = 45
          Height = 21
          TabOrder = 2
          Text = '1.35'
          OnChange = OnControlsChange
        end
        object edt_gamma_f_st_SW_: TEdit
          Left = 196
          Top = 19
          Width = 45
          Height = 21
          TabOrder = 3
          Text = '1.05'
          OnChange = OnControlsChange
        end
      end
      object GrpBxLoadCases: TGroupBox
        Left = 314
        Top = 3
        Width = 274
        Height = 145
        Caption = '  '#1047#1072#1075#1088#1091#1078#1077#1085#1080#1103'  '
        TabOrder = 1
        object lbl_dead_load_first_stage: TLabel
          Left = 16
          Top = 43
          Width = 151
          Height = 13
          Caption = #1055#1086#1089#1090#1086#1103#1085#1085#1072#1103'  '#1085#1072#1075#1088#1091#1079#1082#1072',  '#1082#1053'/'#1084'2'
        end
        object lbl_dead_load_second_stage: TLabel
          Left = 16
          Top = 81
          Width = 148
          Height = 13
          Caption = #1055#1086#1089#1090#1086#1103#1085#1085#1072#1103'  '#1085#1072#1075#1088#1091#1079#1082#1072', '#1082#1053'/'#1084'2'
        end
        object Label9: TLabel
          Left = 16
          Top = 24
          Width = 50
          Height = 13
          Caption = 'I '#1089#1090#1072#1076#1080#1103
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label10: TLabel
          Left = 16
          Top = 62
          Width = 55
          Height = 13
          Caption = 'II '#1089#1090#1072#1076#1080#1103
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object lbl_live_load: TLabel
          Left = 16
          Top = 108
          Width = 142
          Height = 13
          Caption = #1042#1088#1077#1084#1077#1085#1085#1072#1103'  '#1085#1072#1075#1088#1091#1079#1082#1072', '#1082#1053'/'#1084'2'
        end
        object edt_dead_load_first_stage: TEdit
          Left = 181
          Top = 40
          Width = 52
          Height = 21
          TabOrder = 0
          Text = '1.2'
          OnChange = OnControlsChange
        end
        object edt_dead_load_second_stage: TEdit
          Left = 181
          Top = 78
          Width = 52
          Height = 21
          TabOrder = 1
          Text = '1.5'
          OnChange = OnControlsChange
        end
        object edt_live_load: TEdit
          Left = 181
          Top = 105
          Width = 52
          Height = 21
          TabOrder = 2
          Text = '2'
          OnChange = OnControlsChange
        end
      end
      object GrpBxTopology: TGroupBox
        Left = 1
        Top = 3
        Width = 305
        Height = 145
        Caption = '  '#1058#1086#1087#1086#1083#1086#1075#1080#1103'  '
        TabOrder = 2
        object lbl_span: TLabel
          Left = 17
          Top = 25
          Width = 56
          Height = 13
          Caption = #1055#1088#1086#1083#1105#1090', '#1084#1084
        end
        object lbl_trib_width_left: TLabel
          Left = 17
          Top = 51
          Width = 194
          Height = 13
          Caption = #1056#1072#1089#1089#1090#1086#1103#1085#1080#1077' '#1084#1077#1078#1076#1091' '#1073#1072#1083#1082#1072#1084#1080' '#1089#1083#1077#1074#1072', '#1084#1084':'
        end
        object lbl_trib_width_right: TLabel
          Left = 17
          Top = 81
          Width = 200
          Height = 13
          Caption = #1056#1072#1089#1089#1090#1086#1103#1085#1080#1077' '#1084#1077#1078#1076#1091' '#1073#1072#1083#1082#1072#1084#1080' '#1089#1087#1088#1072#1074#1072', '#1084#1084':'
        end
        object edt_span: TEdit
          Left = 224
          Top = 22
          Width = 52
          Height = 21
          BevelInner = bvSpace
          TabOrder = 0
          Text = '18000'
          OnChange = OnControlsChange
        end
        object edt_width_left: TEdit
          Left = 224
          Top = 49
          Width = 52
          Height = 21
          TabOrder = 1
          Text = '6000'
          OnChange = OnControlsChange
        end
        object edt_width_right: TEdit
          Left = 224
          Top = 76
          Width = 52
          Height = 21
          TabOrder = 2
          Text = '6000'
          OnChange = OnControlsChange
        end
        object chck_bx_end_beam: TCheckBox
          Left = 17
          Top = 111
          Width = 97
          Height = 17
          Caption = #1050#1088#1072#1081#1085#1103#1103' '#1073#1072#1083#1082#1072
          TabOrder = 3
          OnClick = chck_bx_end_beamClick
        end
      end
      object GrpBxStaticScheme: TGroupBox
        Left = 15
        Top = 230
        Width = 1030
        Height = 266
        Caption = #1056#1072#1089#1095#1105#1090#1085#1072#1103' '#1089#1093#1077#1084#1072
        TabOrder = 3
        object img_static_scheme: TImage
          Left = 2
          Top = 51
          Width = 1026
          Height = 213
          Align = alBottom
          ExplicitWidth = 837
        end
        object lblLoadCase: TLabel
          Left = 13
          Top = 20
          Width = 62
          Height = 13
          Caption = #1053#1072#1075#1088#1091#1078#1077#1085#1080#1077
        end
        object cmb_bx_impact: TComboBox
          Left = 81
          Top = 23
          Width = 181
          Height = 22
          Style = csOwnerDrawFixed
          TabOrder = 0
          OnChange = cmb_bx_impactChange
        end
        object rd_grp_internal_forces_type: TRadioGroup
          Left = 309
          Top = 8
          Width = 299
          Height = 37
          Caption = #1057#1080#1083#1086#1074#1086#1081' '#1092#1072#1082#1090#1086#1088
          Columns = 2
          ItemIndex = 0
          Items.Strings = (
            #1048#1079#1075#1080#1073#1072#1102#1097#1080#1081' '#1084#1086#1084#1077#1085#1090
            #1055#1086#1087#1077#1088#1077#1095#1085#1072#1103' '#1089#1080#1083#1072)
          TabOrder = 1
          OnClick = rd_grp_internal_forces_typeClick
        end
      end
      object GrpBxErection: TGroupBox
        Left = 851
        Top = 154
        Width = 194
        Height = 70
        Caption = '  '#1052#1086#1085#1090#1072#1078'  '
        TabOrder = 4
        object lbl_number_propping_supports: TLabel
          Left = 3
          Top = 26
          Width = 140
          Height = 13
          Caption = #1054#1087#1086#1088#1099' '#1087#1088#1080' '#1073#1077#1090#1086#1085#1080#1088#1086#1074#1072#1085#1080#1080':'
          ParentShowHint = False
          ShowHint = False
        end
        object cmb_bx_number_propping_supports: TComboBox
          Left = 149
          Top = 26
          Width = 36
          Height = 21
          Hint = #1047#1072#1076#1072#1081#1090#1077' '#1082#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1086#1087#1086#1088' '#1087#1088#1080' '#1073#1077#1090#1086#1085#1080#1088#1086#1074#1072#1085#1080#1077
          ParentShowHint = False
          ShowHint = True
          TabOrder = 0
          Text = '0'
          OnChange = OnControlsChange
          Items.Strings = (
            '0'
            '1'
            '2'
            '3')
        end
      end
      object grp_bx_shear_studs_placement: TGroupBox
        Left = 186
        Top = 154
        Width = 662
        Height = 70
        Caption = '  '#1043#1080#1073#1082#1080#1077' '#1091#1087#1086#1088#1099'  '
        TabOrder = 5
        object lbl_edge_studs_dist: TLabel
          Left = 13
          Top = 23
          Width = 176
          Height = 13
          Caption = #1064#1072#1075' '#1091#1087#1086#1088#1086#1074' '#1074' '#1082#1088#1072#1081#1085#1080#1093' '#1090#1088#1077#1090#1103#1093', '#1084#1084':'
        end
        object lbl_middle_studs_dist: TLabel
          Left = 13
          Top = 50
          Width = 170
          Height = 13
          Caption = #1064#1072#1075' '#1091#1087#1086#1088#1086#1074' '#1074' '#1089#1088#1077#1076#1085#1077#1081' '#1090#1088#1077#1090#1080', '#1084#1084':'
        end
        object lbl_edge_studs_rows_num: TLabel
          Left = 292
          Top = 23
          Width = 226
          Height = 13
          Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1088#1103#1076#1086#1074' '#1091#1087#1086#1088#1086#1074' '#1074' '#1082#1088#1072#1081#1085#1080#1093' '#1090#1088#1077#1090#1103#1093
        end
        object lbl_middle_studs_rows_num: TLabel
          Left = 292
          Top = 50
          Width = 220
          Height = 13
          Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1088#1103#1076#1086#1074' '#1091#1087#1086#1088#1086#1074' '#1074' '#1089#1088#1077#1076#1085#1077#1081' '#1090#1088#1077#1090#1080
        end
        object edt_edge_studs_dist: TEdit
          Left = 224
          Top = 19
          Width = 48
          Height = 21
          TabOrder = 0
          Text = '180'
          OnChange = OnControlsChange
        end
        object edt_middle_studs_dist: TEdit
          Left = 224
          Top = 46
          Width = 48
          Height = 21
          TabOrder = 1
          Text = '400'
          OnChange = OnControlsChange
        end
        object cmb_bx_middle_studs_rows__num: TComboBox
          Left = 542
          Top = 46
          Width = 36
          Height = 21
          ItemIndex = 0
          TabOrder = 2
          Text = '1'
          Items.Strings = (
            '1'
            '2')
        end
        object cmb_bx_edge_studs_rows_num: TComboBox
          Left = 542
          Top = 19
          Width = 35
          Height = 21
          ItemIndex = 0
          TabOrder = 3
          Text = '1'
          Items.Strings = (
            '1'
            '2')
        end
      end
      object grb_bx_analysis_theory: TGroupBox
        Left = 3
        Top = 154
        Width = 174
        Height = 70
        Caption = '  '#1058#1077#1086#1088#1080#1103' '#1088#1072#1089#1095#1105#1090#1072'  '
        TabOrder = 6
        object cmb_bx_analysis_theory: TComboBox
          Left = 16
          Top = 30
          Width = 145
          Height = 21
          ItemIndex = 0
          TabOrder = 0
          Text = #1059#1087#1088#1091#1075#1086'-'#1087#1083#1072#1089#1090#1080#1095#1077#1089#1082#1072#1103
          OnChange = cmb_bx_analysis_theoryChange
          Items.Strings = (
            #1059#1087#1088#1091#1075#1086'-'#1087#1083#1072#1089#1090#1080#1095#1077#1089#1082#1072#1103
            #1046#1105#1089#1090#1082#1086'-'#1087#1083#1072#1089#1090#1080#1095#1077#1089#1082#1072#1103)
        end
      end
      object grp_bx_working_conditions_factors: TGroupBox
        Left = 851
        Top = 3
        Width = 201
        Height = 145
        Caption = ' '#1050#1086#1101#1092#1092#1080#1094#1080#1077#1085#1090#1099' '#1091#1089#1083#1086#1074#1080#1081' '#1088#1072#1073#1086#1090#1099' '
        TabOrder = 7
        object lbl_gamma_c: TLabel
          Left = 16
          Top = 41
          Width = 103
          Height = 13
          Caption = #1050#1086#1084#1087#1086#1079#1080#1090#1085#1072#1103' '#1073#1072#1083#1082#1072':'
        end
        object lbl_gamma_bi: TLabel
          Left = 19
          Top = 72
          Width = 34
          Height = 13
          Caption = #1041#1077#1090#1086#1085':'
        end
        object lbl_gamma_si: TLabel
          Left = 19
          Top = 91
          Width = 53
          Height = 13
          Caption = #1040#1088#1084#1072#1090#1091#1088#1072':'
        end
        object edt_gamma_bi: TEdit
          Left = 121
          Top = 64
          Width = 41
          Height = 21
          TabOrder = 0
          Text = '1.0'
          OnChange = OnControlsChange
        end
        object edt_gamma_si: TEdit
          Left = 120
          Top = 87
          Width = 41
          Height = 21
          TabOrder = 1
          Text = '1.0'
          OnChange = OnControlsChange
        end
        object edt_gamma_c: TEdit
          Left = 121
          Top = 37
          Width = 41
          Height = 21
          TabOrder = 2
          Text = '1.0'
          OnChange = OnControlsChange
        end
      end
    end
    object TbShtSectionMaterials: TTabSheet
      Caption = #1057#1077#1095#1077#1085#1080#1077' '#1080' '#1084#1072#1090#1077#1088#1080#1072#1083#1099
      ImageIndex = 1
      object GrpBxSteelSection: TGroupBox
        Left = -4
        Top = 283
        Width = 307
        Height = 60
        Caption = '  '#1055#1088#1086#1082#1072#1090#1085#1086#1077' '#1089#1077#1095#1077#1085#1080#1077'  '
        TabOrder = 0
        object Pnl_SteelSectionViewer: TPanel
          Left = 28
          Top = 17
          Width = 90
          Height = 30
          TabOrder = 0
        end
        object BtnSteelSectionChoice: TBitBtn
          Left = 133
          Top = 17
          Width = 167
          Height = 30
          Caption = #1042#1099#1073#1088#1072#1090#1100'/'#1080#1079#1084#1077#1085#1080#1090#1100' '#1089#1077#1095#1077#1085#1080#1077
          TabOrder = 1
          OnClick = BtnSteelSectionChoiceClick
        end
      end
      object rdgrp_slab_type: TRadioGroup
        Left = 3
        Top = 349
        Width = 300
        Height = 60
        Caption = '  '#1058#1080#1087' '#1078'.'#1073'. '#1089#1077#1095#1077#1085#1080#1103'  '
        Columns = 2
        ItemIndex = 0
        Items.Strings = (
          #1055#1083#1086#1089#1082#1072#1103' '#1087#1083#1080#1090#1072
          #1055#1083#1080#1090#1072' '#1087#1086' '#1085#1072#1089#1090#1080#1083#1091)
        TabOrder = 1
        OnClick = rdgrp_slab_typeClick
      end
      object grp_bx_flat_slab: TGroupBox
        Left = 3
        Top = 415
        Width = 300
        Height = 60
        Caption = #1055#1083#1086#1089#1082#1072#1103' '#1087#1083#1080#1090#1072
        TabOrder = 2
        Visible = False
        object lbl_flat_slab_thickness: TLabel
          Left = 16
          Top = 29
          Width = 103
          Height = 13
          Caption = #1058#1086#1083#1097#1080#1085#1072' '#1087#1083#1080#1090#1099', '#1084#1084':'
        end
        object edt_flat_slab_thickness: TEdit
          Left = 167
          Top = 25
          Width = 41
          Height = 21
          TabOrder = 0
          Text = '200'
          OnChange = OnControlsChange
        end
      end
      object grp_bx_corrugated_slab: TGroupBox
        Left = 3
        Top = 415
        Width = 462
        Height = 60
        Caption = '  '#1055#1083#1080#1090#1072' '#1087#1086' '#1085#1072#1089#1090#1080#1083#1091'  '
        TabOrder = 3
        Visible = False
        object lbl_h_f: TLabel
          Left = 209
          Top = 27
          Width = 175
          Height = 13
          Caption = #1058#1086#1083#1097#1080#1085#1072' '#1087#1083#1080#1090#1099' '#1085#1072#1076' '#1085#1072#1089#1090#1080#1083#1086#1084', '#1084#1084':'
        end
        object lbl_corrugated_sheet_type: TLabel
          Left = 27
          Top = 27
          Width = 36
          Height = 13
          Caption = #1052#1072#1088#1082#1072':'
        end
        object cmb_bx_corrugated_sheeting_part_number: TComboBox
          Left = 87
          Top = 23
          Width = 100
          Height = 21
          TabOrder = 0
          Text = 'H60-845'
          OnChange = cmb_bx_corrugated_sheeting_part_numberChange
          Items.Strings = (
            #1053'60-845'
            #1053'75-750'
            #1053'114-750'
            #1053'153-850'
            #1058#1056#1055' 200')
        end
        object edt_h_f: TEdit
          Left = 398
          Top = 23
          Width = 41
          Height = 21
          TabOrder = 1
          Text = '100'
        end
      end
      object GrpBxSteel: TGroupBox
        Left = 3
        Top = 13
        Width = 300
        Height = 60
        Caption = '  '#1057#1090#1072#1083#1100'  '
        TabOrder = 4
        object pnl_steel: TPanel
          Left = 24
          Top = 18
          Width = 90
          Height = 30
          TabOrder = 0
        end
        object BtBtnSteelChoice: TBitBtn
          Left = 126
          Top = 18
          Width = 167
          Height = 30
          Caption = #1042#1099#1073#1088#1072#1090#1100'/'#1080#1079#1084#1077#1085#1080#1090#1100' '#1089#1090#1072#1083#1100
          TabOrder = 1
          OnClick = BtBtnSteelChoiceClick
        end
      end
      object GrpBxConcrete: TGroupBox
        Left = 3
        Top = 75
        Width = 300
        Height = 60
        Caption = '  '#1041#1077#1090#1086#1085'  '
        TabOrder = 5
        object pnl_concrete_grade: TPanel
          Left = 21
          Top = 16
          Width = 90
          Height = 30
          TabOrder = 0
        end
        object BtnConcreteChoice: TBitBtn
          Left = 126
          Top = 16
          Width = 167
          Height = 30
          Caption = #1042#1099#1073#1088#1072#1090#1100'/'#1080#1079#1084#1077#1085#1080#1090#1100' '#1073#1077#1090#1086#1085
          TabOrder = 1
          OnClick = BtnConcreteChoiceClick
        end
      end
      object GrpBxRebars: TGroupBox
        Left = 3
        Top = 146
        Width = 300
        Height = 60
        Caption = '  '#1040#1088#1084#1072#1090#1091#1088#1072'  '
        TabOrder = 6
        object pnl_rebar_viewer: TPanel
          Left = 21
          Top = 19
          Width = 90
          Height = 30
          TabOrder = 0
        end
        object BtBtnRebarsChoice: TBitBtn
          Left = 126
          Top = 19
          Width = 167
          Height = 30
          Caption = #1042#1099#1073#1088#1072#1090#1100'/'#1080#1079#1084#1077#1085#1080#1090#1100' '#1072#1088#1084#1072#1090#1091#1088#1091
          TabOrder = 1
          OnClick = BtBtnRebarsChoiceClick
        end
      end
      object GrpBxShearStuds: TGroupBox
        Left = 0
        Top = 212
        Width = 303
        Height = 60
        Caption = '  '#1043#1080#1073#1082#1080#1077' '#1091#1087#1086#1088#1099'  '
        TabOrder = 7
        object pnl_shear_stud_viewer: TPanel
          Left = 24
          Top = 16
          Width = 90
          Height = 30
          TabOrder = 0
        end
        object BtBtnShearStudsChoice: TBitBtn
          Left = 129
          Top = 16
          Width = 167
          Height = 30
          Caption = #1042#1099#1073#1088#1072#1090#1100'/'#1080#1079#1084#1077#1085#1080#1090#1100' '#1091#1087#1086#1088#1099
          TabOrder = 1
          OnClick = BtBtnShearStudsChoiceClick
        end
      end
      object GroupBox6: TGroupBox
        Left = 309
        Top = 13
        Width = 684
        Height = 396
        Caption = '  '#1050#1086#1084#1073#1080#1085#1080#1088#1086#1074#1072#1085#1085#1086#1077' '#1089#1077#1095#1077#1085#1080#1077'  '
        TabOrder = 8
        object Image1: TImage
          Left = 3
          Top = 18
          Width = 249
          Height = 359
          Picture.Data = {
            0954506E67496D61676589504E470D0A1A0A0000000D49484452000004B00000
            06400802000000E64E2CA8000000017352474200AECE1CE90000000467414D41
            0000B18F0BFC6105000000097048597300000EC300000EC301C76FA86400008D
            BA4944415478DAECDD5D7A23CB75A6519C41D996E77F6177F7A0DCA58772892A
            9289BDF32F22BE5CEB4217474510D8890CC4CB2481BFFEE77FFEE715E1BFFFCF
            FF1B7D1700008047F8DB7FFCDBE8BB708EBF928230E6A8000000D34A4A0F4108
            0000D090941E82100000A021293D042100004043527A084200008086A4F41084
            0000000D49E921080100001A92D243100200003424A5872004000068484A0F41
            080000D090941E82100000A021293D042100004043527A084200008086A4F410
            840000000D49E921080100001A92D243100200003424A5872004000068484A0F
            41080000D090941E82100000A021293D042100004043527A084200008086A4F4
            10840000000D49E921080100001A92D243100200003424A5872004000068484A
            0F41080000D090941E82100000A021293D042100004043527A084200008086A4
            F410840000000D49E921080100001A92D243100200003424A587200400006848
            4A0F41080000D090941E82100000A021293D042100004043527A084200008086
            A4F410840000000D49E921080100001A92D243100200003424A5872004000068
            484A0F41080000D090941E82100000A021293D042100004043527A0842000080
            86A4F410840000000D49E921080100001A92D243100200003424A58720040000
            68484A0F41080000D090941E82100000A021293D042100004043527A08420000
            8086A4F410840000000D49E921080100001A92D243100200003424A587200400
            0068484A0F41080000D090941E82100000A021293D042100004043527A084200
            008086A4F410840000000D49E921080100001A92D243100200003424A5872004
            000068484A0F41080000D090941E82100000A021293D042100004043527A0842
            00008086A4F410840000000D49E921080100001A92D243100200003424A58720
            04000068484A0F41080000D090941E82100000A021293D042100004043527A08
            4200008086A4F410840000000D49E921080100001A92D243100200003424A587
            2004000068484A0F41080000D090941E82100000A021293D042100004043527A
            084298DD5F7FFDF5EB7F634E5556F1F1C4DBE669092DD6738891941E8210A6F6
            79531E73B632A74A017ECB33132AACE79024293D0421CCEBEB063DE684651EBB
            3BF0374F4B78CB7A0E6192D24310C2A47EDAA6C79CB3CCE0780DBE3C27E11DEB
            39E4494A0F410893B281E052A7A4E007CF49D8663D873C49E9210861461B9BF5
            98739681D420DCC67A0E9192D24310C28C6C20B894DF1485DB58CF2152527A08
            4298CEF6663DE69C65144F30B88DD30D5225A5872084E9D840701D172BE04ED6
            734895941E8210E6F2F677F962CE5986F8F609E6490557B09E43B0A4F4108430
            97CA1F77C59CB6DC4F10C26DACE7102C293D04214CA4F8561F31A72D37538370
            1BEB39644B4A0F410813B181E05282106E633D876C49E9210861163F6DD6BFFE
            F798D3969B0942B887F51CE225A587208429FCF4B3641B08CEA206E1368210E2
            25A5872084296C6CD66D20388520847B58CFE10992D24310C2781B97075FF6F1
            9CC41309EED10AC297D310D694941E8210C6DBDE22D840700A4F24B881F51C1E
            22293D04210CB67D79F06503C1493C91E00682101E22293D04210CF6767F6003
            C1719E457003EB393C47527A084218E9EDE5C19FFE59CC99CB3D6C43E1069513
            CD7A0E1992D24310C248C56DBA0D04070942B89AF51C1E25293D04210C53BC3C
            F8B281E0304108571384F02849E921086198FA1EDD6E9E833C85E052D673789A
            A4F4108430466B4F6003C1119E3F70B5FA753FE72364484A0F41086308426EE3
            F90397B29EC30325A587208401BA1B021B088EF0FC814BB5FE2CD0F9081992D2
            4310C2003B3604DE8780DD6C40E13AD67378A6A4F4108470B77DBB731B087613
            84709D1D8BB3F51C0224A5872084BB9D158495AF8297270F5CC67A0E8F95941E
            82106EB57B1F6003C13E9E39709D7DD7FA9C951020293D0421DC4A107233CF1C
            B888F51C9E2C293D0421DCE7C826C006827D3C73E022BBFF14D059090192D243
            10C27DE60CC28F5B8E590AF8C3245B4F4F33C2CCB99EFFF48D9C7A70BAA4F410
            8470936F7700079D188427DE2053992A08477D7738DDE94BFA59E7C5DB3BE604
            845324A58720849BCC19847FDCAB9805810F13D6E0903B00E75A623DBFFADBC1
            C325A58720843B5CB17BF870E414B64D8F3743107A9A91E7A225FDC4F5FCEA6F
            0724A5872084CB5D57832F41C8264108A79BF0077CFBEE9293118E484A0F4108
            9713848C2208E174F307E1D7DBD9FD86A8C04F92D24310C2B52EADC197206493
            208473CDF903BEFA59E6FD7EE12C49E92108E15A829081660B42CF3156B77A10
            0267494A0F410817FA69EBB0EFBC3B7D736F0F116F78107A8E91E4C413EADC73
            D38906F74B4A0F410817BA21084FBCB598D580DF04219CE8EA203CEBD69C6870
            83A4F410847095735FEF4FBF4141F8048210CE72E935BD833738FC4C87074A4A
            0F410857592E08CFBDB7CCE0F427E1597760D4FD81DD960BC283F710D896941E
            82102E71C5467C48109E72CF19659520BCFF8E41CBD57FC27DFC36B7CF356716
            9C2E293D04215CE2A28DF80D7FC1B22166B9788EE17B444F33325CF13B99B745
            E6597718F82C293D04219CEFBADFDE191B84C7EF3FF73BEB5DF2771C7ACF3132
            CCFF03BECABD3DF15B00AFACF4108470BEEB7E4F4F10D275E2C7A6758FFEEE6F
            ED69C654EE2CB7B39EFCC37F3B00E225A5872084F3DD1C843B6EB9FEDE8FDE8C
            34C0A88B84C5A79937486466F3AFE763BF053C56527A084238DF751BDCB36EB9
            F561003E3920C0F126BCF469E6E70E4C6BFEF57C9E6F048F92941E8210CE37FF
            0642103ECDE441D8FDC7709BF9D7F37DDFCB29060725A5872084F35DFAD27BCA
            BE79F7A59B9815E3B16EFBBBBED659E069C6B4EE5CCFCFBDF1EDEFE52C838392
            D24310C2F93EBFEE9E7E8A9D72E382907A199EF5AE459E66ACE8D2F5FCF3ED1F
            3CD1DE7EB9B30CCE95941E82109E481072354108572B9E657E5F14AE90941E82
            101EC75F7671034F33B89A4F0F828192D24310C2E3D8A973034F33B89A208481
            92D24310C2E3F87D51AEE6F745E1063B82D0F90567494A0F41088F2308B99A20
            84DB14B3D09905E74A4A0F41088F2308B99A20E4B1063E9F7F2A43E7145C2129
            3D04213C4EFD5DD4EDD4D9C71F10F24C777ED63C3056527A0842781C41C8D504
            21CFE41A1D3C47527A0842B8D6C7FE609E13CD4EFD81EE7F127A9AF1401B7FCB
            E7590D7992D24310C255E6DCE6DAA93FCDFD07D11F10F24CDB6FEEE2B90D6192
            D24310C2255A7BE28177CC4E3D9E20841BBC7DAB4FCF6D0893941E82102E31ED
            5B0B14F7DFD3062D2D439E87C5278FE718492A9FFDE0190E4992D24310C2F966
            7E5F811D1F643CC93D67874982B0C8D38C45D59FF39EE41023293D04219C2F2C
            0867B8DBECB350107A9AB12E41080F94941E82104E36730DBEFA9BF549EE36FB
            2C11849E632CCD131E9E29293D04219C2C290827B9CFEC33EA0F593DC7781441
            08CF94941E8210CE34790DBEBCF3C1930C7C67234F331E6263CDF7B184902D29
            3D04219C69FE20E439A67DAB5B88B12F085FCE44585F527A0842388D1A642A82
            102EF576CD7791108225A5872084D30842A62208E1524782F0E56484C525A587
            2084D3D87F33154F48B84EF127802E1242AAA4F41084700E9707998A1A844BD5
            D77C4D089192D24310C2390421531184709DD6822F082152527A084238811A64
            368210AED35DF33521E4494A0F4108271084CC4610C245762CF8DE5D06F224A5
            872084A3D42013128470917D6BBE8B841026293D04211C2508999020842BEC5E
            F05D24843049E92108E11035C884D4205CE4C89AEF222124494A0F4108870842
            262408E10AC7177C4D083192D24310C22176DE4CC8D312AE706910B66E07182E
            293D0421ECE7F22073128470BAB3167C17092143527A0842D84F1032274108A7
            BB210877DC1A304A527A0842D8490D322D4108E73A77C17791100224A5872084
            9D042173F2CC84D39D7E5A6942585D527A0842D8C39E9B69B93C08E7BA62C1F7
            8BA3B0BAA4F41084B08720645A8210CE75D182EF22212C2D293D0421B4A94166
            2608E144D72DF82E12C2D292D24310429B20646682104E74E982EF2221AC2B29
            3D0421F4A841262708E12C372CF89A101695941E82107A04219313847096B141
            78EE3702CE95941E82107AECB69999E7279CE5B61FFFB948082B4A4A0F41080D
            2E0F3239410867992108AFF876C02992D24310428320647282104E71F36AEF22
            212C27293D042154A941E62708E114F72FF89A10D692941E8210AA0421F31384
            70DC90D55E10C25A92D2431042891A640982108E1BB5E06B425848527A084228
            1184CC4F0DC27103577BEF2E030B494A0F4108EFA941962008E1B8B10BBE8B84
            B08AA4F41084F09E20640982100E1ABEDABB4808AB484A0F4108EFD967B3044F
            5438687810BE5C24844524A58720843766D81F4085208423E659ED3521CC2F29
            3D0421BC31CF1601B6094238629ED5DE2F8EC2FC92D24310C29679F607B04D0D
            C211B3ADF62E12C2E492D24310C296D9B608F013410847CCB6DABB4808934B4A
            0F41083F9A6D7F001B0421EC36E76AEF2221CC2C293D0421FC68CE2D027C4B10
            C26ED3AEF69A10A695941E8210BE37EDFE00BE2508619F99577BBF380AD34A4A
            0F4108DF9B798B005F0942D867F2D5DE45429853527A0842F89EED356BF18C85
            1D26AFC1978B8430ABA4F41084F08DF9B708F0991A847D9658ED5D24840925A5
            8720846F2CB14580DF0421ECB0D052AF09613649E92108E14F0B6D11E0832084
            1D165AEDFDE228CC26293DA282F03FFFF6EFA3EF05000010EEBFFEFBFF0AC2E9
            08420000E00682704682100000B881209C91200400006E20086724080100801B
            08C21909420000E00682704682100000B881209C91200400006E200867240801
            00801B08C21909420000E00682704682100000B881209CD1AF208C392ADCECAF
            BFFEFAF6BFC79C1D04FBF6D9EBA90B5FE52DF53F3DA2D51F172C21293D04214F
            97B745E051042154A42EF51B4DB8FA4383C925A58720E4E95277093C8420848A
            D4A5DE45421825293D04218F96BA45E0390421BC95BDD4BB48084324A58720E4
            D1B27709C4F304868AF8334513C2FD92D24310F268AEAEB0344F60782BBE065F
            7E711446484A0F41C8733D6197403641086F3D64A97791106E96941E8290E77A
            C82E81608210B63D679D7791106E96941E8290877ACE2E81608210B63D6AA977
            9110EE94941E8290877AD42E81548210363C709DD784709BA4F410843CD10377
            09441284B0E1814BBD5F1C85DB24A58720E4891EB84B208F1A840D8F5DE75D24
            847B24A5475410FEE7DFFE7DF4BD000000F2C5649420040000E889C928410800
            00D013935182100000A02726A304210000404F4C4609420000809E988C128400
            00003D311925080100007A62324A10020000F4C4649420040000E889C9284108
            0000D01393515141F8B7FFF8B7D1F7E27C7FFDF5D7DB7F137310AFF3ED186F9E
            DBDB43E9382E6186E338C3F3797596D618339C92F3DB98D224F3711C333CEA38
            26A587209C5A65CBF221E6385EE1A731DE39B4E2A1741C2737C971148407595A
            634C724ACE6F7B50C3E7E3386678DA714C4A0F4138AFFA96E543CCA13CDDD820
            741C63CC732805E111F31C478E701CBBA6BD48E8506678E0714C4A0F4138A9EE
            79F521E6689E68F8E5C11D87D2719CD054C75110EE66698D31D529B98A099BD0
            71CCF0CCA535293D04E18CF69D57AFF54FAD2BAC7579F0E6BB47D16CC75110EE
            33DB71643787729FD97E71D471CCF0D8E318951EAB1F8CDFA28ECADE53EBB5FE
            D975AE152F0FDE7C0FA998ED380AC27D2CAD31663B251732D54542C731C36397
            D6A8F458FA487C1675549E7A6A9D6EDD20BCF34EF2D66CC75110EE33DB71649F
            23C7F1F5F84339D54542A76486C71EC7A8F458FA487C1673540EBED4BD163FBB
            4EB4740DDE793FD936DB715483FB585A63CC764A2E67928B848E6386271FC798
            F47809C209D9B59C4510728AD98EA320DCC7D21A63B65372453334A1E398E1C9
            4B6B4C7ABC04E1849E7C6A9D6BF8BED9AB5D86D94EC9E14FEC45CD761CD9CDD2
            7ADC0CBF38EA386678F2D21A931E2F4138A1279F5A271A7E79F0E5D52EC56CA7
            A420DC67B6E3C86E96D6530CBF48E8386678F2D21A931E2F4138A1279F5A2712
            849C65B6E32808F7B1B4C698ED945CD4F08B848E6386272FAD31E9F1128473B2
            4A1E34430DBE1CC72053BD859A20DCCD2999C1713CCBD217091DC7793CF63846
            A5C7D247E2B3A8A3F2D453EB2C9304E1CBA14C31CF71548347CC731C3942107E
            9EC0C18733B6096F3B254F9CD843B426F6D8A5352A3D963E129F451D95A79E5A
            A798A7065F070EA5E33895798EA3203CC2D21A639E537286877FE4412D1A84DD
            FB76E2C41EA235B1C72EAD51E9B1F491F82CE9A8BCF69E5D3147F388A982F0B5
            EB503A8E139AE4380AC2832CAD312639256778E04FBB4878B006EF795C4BDB31
            B1672EAD49E92108E7D53DBB620EE511B3D5E0CB710C32C3A11484C7CD701C39
            EEB1C7F1F44560B97797391E84F73CAE75ED9BD8034FC9A4F4108453AB9F5D31
            C7F1A00983F0D55C251DCA69CD701CED6C4E6169CD30C32939C9A37ECE45C21D
            F7C7B2D9B57B624F5B5A93D24310CEAE7276C51CC483E6ACC1B7776FB6FBC9B6
            B1C7D1CEE62C96D6184F5B5A6F0EC2E3377ECA7D3872372C9B5D4726F6A8F331
            293D04E11A264F9D49CC3FA5F9EF2145437618B635A7734A6678D471BC681D18
            FE1114D73D3A2B67D7F1893DE4944C4A0F41480E8B3ED93CC381EBD681499AF0
            7456CE2E132B4A4A0F41488887FC388A27F3220D0C09C2B3BEC51056CE2E132B
            4A4A0F41480841483C2FD2C0A5EB40E445422B6797891525A5872024811AE409
            BC4803A382F0C4EF72332B6797891525A58720248120E409BC480357AF037917
            09AD9C5D265694941E8290E5A9419EC0F31C78DDB2590F6B4279D365624549E9
            2108599E8D324FE0151A788D0EC2D3BFD70D2C9E5D265694941E8290B5A941E2
            85FDB41EF8EAD7697EE483BF4F5F0AE65F76669BD8FC4CEC7449E92108599B20
            24DEFC3B33E088DFE778E58C1E1E84577CBBDD776F9E894DCEC4AE90941E8290
            B559B6C836F9B60C38E88F73FCED497DDBABDEB43F8A9A7662D332B18B24A587
            2064612E0F124F1042B01D3BEF3B37EB1336E1E4139B90895D27293D04210B13
            84C41384106CC7ABD8244178DD37DD77972699D8844CEC3A49E9210859951A24
            C3C733F9A7E76DF727F4DBB706CCA6FB5A76F3667D958B84AF6926362113BB48
            527A084256250809F0F64F3BEABBB1EE5F89009368BD9CCD1384977EDF7DF76A
            8689CDC9C4AE90941E829025A94102545E748B41E8F51B96567F51BBFF649FF0
            22E16BEE89CDC9C44E97941E829025094202549EC695AD98D30102144FE4219B
            F5A59B50DEFC6662E74A4A0F41C87A6C7F89F1F6C9FC761FE6748018BB7F48F4
            CC207C4D3CB16999D88992D24310B21E3B6062ECEEBD8F7F30ED2E0DD867DF0F
            896E38DFA75D6DA69DD8B44CEC2C49E92108598FA58A24FB924F0D42AAEDFDFA
            844178CF1DD871DFC64E6C6626768AA4F410842CE9EB6A15F34CE681B6775A5D
            CE05585DF72741F79CF533FF106ACE89CDCCC48E4B4A0F41C892BCC33E61CE6A
            42E7026468AD09C383F0B6FBB0FBEECD766F6760620725A587206461BFD6B298
            27301C6F42A70324A9AF09B79DFB335F247C4D39B1C999D81149E991B39F4E3A
            2AC0331D69C298C51CF8ADB826DC79FA6734E10C77751226B65B527A08428089
            EC6BC298951CF843654D9824086FBE27FBEEE13CF7731E26B64F527A0842805B
            9DFB163215C3DF811000BE5A3A4392D2431002DC646C355DB4DA4B41008E5834
            4692D2431002DC441002C01F168D91A4F410840037118400F087456324293D04
            21C04D042100FC61D118494A0F4108709F51F974E952AF0901D867DD12494A0F
            410870B73B0B6A864FAC06803FACDE2049E921080126E27308810D6F97889B57
            83C93FA7FE35DFC4E667624549E92108016671E4225BCC620E6C98F033C4276F
            C209273639132B4A4A0F41083085E3BF7219B39E033F292E1477AE06DB7769F8
            BA34E1C42667624549E9210801C63BEB0FF0629674E05BF5B56292261CBE28CD
            39B199995851527A084280C1BA35F86BDD9E79FB055CA7B55C4CF29E526317A5
            39273633132B4A4A0F410830D276DA7DFBFF7EACDB9A101EE8A735E1A7056186
            269C30086798D8B44CAC28293D0421C0306FB7501B4158F97220CC8E1F123DBC
            09679ED89C4CAC28293D0421C0306F5F5CB783B0720B40927D3F24BA6741582E
            085FA3273627132B4A4A0F41083046E565F56D10166F07C830F90F89266CC2C9
            273621132B4A4A0F410830C6EED8FBBA6E17FF19B0BAC97F4834E1BBCB4C3EB1
            09995851527A08428061FE784D3D527A6F6F0A0870E48744AFD14D386D10BE14
            CE27265694941E821060A48FD7D49F96E2EEA5BFED5B0356B7FB8744DBFFF8EA
            7B78DB772FDE9FA926361B132B4A4A0F4108302FBF0B0A7CD65A13266CC29983
            F0F5F8C2D91882897D95941E8210605E8210F86CDF6F0DB4BEE4BAFB79CFB7AE
            DC930927360F132B4A4A0F410830AFAF2FB4318B36B0C38E1F120DF9B9D23CBF
            38BACAC4E661624549E9210801A6E6DD6280DFF6EDBC872C23935C245C686293
            30B1A2A4F410840053FBFC2A1BB36203FBECBE14F3FB0B6F5B4626B948B8D0C4
            2661624549E921080100D670E477F37E7DED0C7FBFD7BACF17DD876927360313
            2B4A4A8F9CC39674540000BE5AEE8FB58637E172131BCEC48A92D243100200AC
            61B9CDFAF05F1C5D6E62C3995851527A0842008035ACB8591F7B9170C5898D65
            624549E921080100D6B0E266BD7591F0F437AB5C716263995851527A08420080
            352CBA597F7B91703B1A8F3CC645273690891525A587205CC6033FE025954399
            C171CCE038C678C8A15C77B3FE36F9DEDAF730D79DD828A74CEC09E763527A08
            C2D95DF733336EE65066701C33388E319E7628D7CD9BE341B8EF91AE3BB1510E
            7EECC4F63F489A7C527A08C2A9D557CF98E398AA78281DC7C9398E192CAD311E
            784A2E9D37439A70E9890D71FC83E9B7C50C3F293D04E1BC5AEB66CC718CE450
            66701C33388E319E792897CE9B5382B0FB78979ED810FB26F6C0F331293D04E1
            A4F62D9A314733C98E43E9384EC871CC60698DF1D85372F5BCB9FF22E1EA13BB
            DF8E893D73694D4A0F4138A3DDCB65CCD18CE15066701C33388E319E7C2803F2
            E6E6260C98D8CDBA137BECF918951EAB1F8CDFA28ECA81B532E6806678EC2A19
            C671CC60698DF1E45332206F04E1E46E0BC2D7E207222A3D963E129F451D95A7
            9E5A791CCA0C8E6306C731C3C19C58FD5066E4CD9D1F419131B13B09C2A2A8F4
            58FA487C167354467D500FA77BF8AE2586E398C1D21AE3E1A76446DE08C299B5
            26F6E4F331263D5E827042762D319EBC4A26711C33585A633CFC948CC99BDB8E
            63CCC46E736710BE563E1631E9F11284137AF2A915E6E1BB96184EC90C8E638C
            872FAD31792308A725088B62D2E3250827F4E4532BCCC3772D319C92191CC718
            0F5F5A93F2E69EBF3D4B9AD83D0461514C7ABC04E1849E7C6A8579F8AE2586E3
            98C1D21AE3E1A76452DE08C23909C2A298F47809C2393DFCD52E86E318E3B16F
            A116C62999E1E1C731296FEEF9F890A489DDC3BB8C1645A5C7D247E2B3A8A3F2
            D4532B8F4399C171CCE038661084310F4A10CE49101645A5C7D247E2B3A8A3F2
            D4532BCF933F3D3989E398C1D21AE3C9A76458DEEC3894DD071B36B11B08C2A2
            A8F458FA487C9674545E7BCFAE98A319E3C9BB96304EC90C8E6386272FAD7979
            D33D9A82F06A3B26F6CCA535293D04E1BC6EF8B11937701C33388E199EB96B89
            F4D853322F6F5A8772C723CD9BD8D5046151527A08C2A9D54FB098E318E9EA57
            3BEEE138C6B0B46678E629199937979E929113BBD4EE893D6D694D4A0F4138B5
            A79D5AC18A87D2719C9CE398C1D21AE381A76464DE5C7A1C232776A9AB833066
            F849E9210817B07D82C51CC1788E638C8D43E9382EC42999E169C731356FDEB6
            C4EEC7983AB1EB1C9CD8734EC9A4F410842BF97C8EC51CB807721C63FC3E948E
            E3D29C92191E721C53F34610CEE3AC89C5BF4426A5475410FEE7DFFE7DF4BD00
            0000F2C5649420040000E889C92841080000D013935182100000A02726A30421
            0000404F4C4609420000809E988C12840000003D311925080100007A62324A10
            020000F4C4649420040000E889C92841080000D01393515141F8B7FFF8B7D1F7
            028035FCF5D75F5FFF63CC6B22A93C6FBB4CACCBC48A92D243100290E9635BF3
            D3CB5C6BD3B37D53701B9BF52E13EB32B1A2A4F410840004FA634FF3F5C5AEB8
            E9797B3B70279BF52E13EB32B1A2A4F4108400A4A96C68CEFA377027CFC92E13
            EB32B1A2A4F4108400A4F97643F3FAD73DCDDB4D4FE546E06636EB5D26D66562
            4549E921080108F436E7B6373D6A9039D9AC77995897891525A587200420D04F
            45F7FADF9DCDC6A6E7EDD7C22836EB5D26D665624549E9210801C8B4DD753F6D
            7AD42033B359EF32B12E132B4A4A0F410840AC8DBAEB8A79B9646936EB5D26D6
            65624549E921080148764A13C6BC56B23A9BF52E13EB32B1A2A4F4108400843B
            D884312F9404B059EF32B12E132B4A4A0F410840BEDD4D18F32A49069BF52E13
            EB32B1A2A4F4880AC2FFFCDBBF8FBE17000040B8FFFAEFFF2B08A72308010080
            1B08C21909420000E00682704682100000B881209C91200400006E2008672408
            0100801B08C21909420000E00682704682100000B881209C91200400006E2008
            6724080100801B08C219FD0AC298A3020BF9EBAFBFB6FF41CC22C3BADE3E4BB7
            790E338F6F9FCC9EA21B4CACCBC48A92D24310028708422677B0063F781A3309
            9BF52E13EB32B1A2A4F41084C0218290999D52831F3E3F935D7264149BF52E13
            EB32B1A2A4F41084C0218290699D58831F3E9ECC17452654D8AC779958978915
            25A58720040E1184CC69E399F9EB39B93BEA8E7CED4F3778F364589ACD7A9789
            75995851527A0842E01041C89C7E7A669E7E95EF38E7087536EB5D26D6656245
            49E9210881438E07E1EF5B88598E186EBB065FB5E7ED9DD1E8C94F91CD7A9789
            75995851527A0842E0902341E855878BBC7D6A159FB7B735A1A73D4596CD2E13
            EB32B1A2A4F41084C0213B8270FB4B621625C6FAE369F6C7F3AAFEBCAD3461E5
            49EB97AB3985CD7A978975995851527A0842E090D636B778BD25665D62AC8FE7
            DBB74FA76E9EFDBEA9835B253F0DE1209BF52E13EB32B1A2A4F41084C021A7FF
            2D56CCA2C4CC765FAF3BBE55DA7EFBD3D183617636EB5D26D665624549E92108
            81432EFAA837B8D4BE207CFB5E35C7BFBBE73FDB6CD6BB4CACCBC48A92D24310
            0287F84C3656343608CFBD291EC566BDCBC4BA4CAC28293D042170C8594118B3
            16B184138370F753D7AE8B1D3C6DBA4CACCBC48A92D2431002871C0FC2985588
            85084216E569D365625D265694941E821038647710C62C3EAC4810B2284F9B2E
            13EB32B1A2A4F41084C01E472E0CC62C3BACEBC4CFCF1484DCC9D3A6CBC4BA4C
            AC28293D0421D0E3922001CE0AC223CF6ABB2E76F0B4E932B12E132B4A4A0F41
            08949CFEF11230B3214118F38ACC756CD6BB4CACCBC48A92D24310026F48411E
            E8EA20B4E5621FCF9C2E13EB32B1A2A4F41084C08FA4208F25089993674E9789
            75995851527A0842E04F3A102E0D42FB2D76F3E4E932B12E132B4A4A0F4108FC
            9314840F7FBC385E5D83BB6F8DA7B159EF32B12E132B4A4A0F41081C7AE3500D
            49A48B8270E37C897939E65236EB5D26D665624549E92108E1D18E7F86842024
            D2CD4118F35ACCD56CD6BB4CACCBC48A92D24310C2139DF85982829048A707E1
            F69912F35ACCD56CD6BB4CACCBC48A92D24310C2B39CFEB1F28290482706E1DB
            7324E685981BD8AC77995897891525A58720844738926DDBAB842024522508AF
            F846B0CD66BDCBC4BA4CAC28293D0421843BFD922057A85F44F29B87F7BBA806
            1D2C76B059EF32B12E132B4A4A0F410899AEBB24C81504E1CC0421F3B059EF32
            B12E132B4A4A0F4108695C125C91209CD91541E848B18FCD7A97897599585152
            7A084208E192E0D204E1CC4E0F428789DD6CD6BB4CACCBC48A92D24310C2F25C
            120C2008677656103A3A1C67B3DE65625D265694941E821056E5926012413833
            E71AF3B059EF32B12E132B4A4A0F4108EB7149308F209C96BD1153F184EC32B1
            2E132B4A4A0F4108CB70992298209C96BD1153F184EC32B12E132B4A4A0F4108
            0B7049309E209C96BD1153F184EC32B12E132B4A4A0F41C8323EAF5031CFDBFA
            43EE7AC8886208C269D91B31154FC82E13EB32B1A2A4F41084ACE1EBF214F3D4
            2D3EDEA2ECB1041384D3B237622A9E905D26D665624549E9210859C073D62697
            041F4B10CEE9A7699B33A33CE705F12C26D665624549E9210859C013D6269704
            1F4E10CEE9098B0F6BF19CEC32B12E132B4A4A0F41C8ECB27F42EF92201F04E1
            9C6C8C988DE764978975995851527A084266971A842E09F299209CD38A1BA323
            6BE6D2EBED1F777E89FB7CFC61663FD853985897891525A58720646A1B7BDF45
            9FBA2E09F22D4138A7B53646479E1B95A569DA07FEED4398FCDE9EF530B31FEC
            294CACCBC48A92D2431032B5A4207449900D82704E0B6D8CEA4FA17D5F3EED03
            FFF6FECF7C57CF7DA4F18FF73813EB32B1A2A4F41084CCEBE0FE661E5290B704
            E18416DA15DD50836B4D60CE3B79C5238D7FBCC7995897891525A58720645EAB
            07A10EA44E104E68A15DD1EE4F6ADDF8A3C1B5FE9E50108EBE5FF332B12E132B
            4A4A0F41C8A496FEFD25294897209CD02ABBA2232DF4F66B9F3084B5AC7244E6
            61625D265694941E829049AD18843A90DD04E18456D915ED6EA1E217EEBEFC38
            6A0813DEBD8B1EE9431EF24126D665624549E9210899D1B7FB8F993725529083
            04E18456D915ED6EA1FA17CE7FFD4D108EBE5FF332B12E132B4A4A0F41C8747E
            5A89265CA17420671184139A70CD797B3F05E19C77EFA247FA90877C90897599
            5851527A0842A6F3D395C0A9562829C8B904E184A65A738AF7734710763FB07E
            C2092C710FAF78A40F79C807995897891525A58720642E1BCBD00C2B948F95E7
            2282704233AC39DDFB79C5DD9BFFF2E00D4398C72A4FCB79985897891525A587
            20642E1B7F283876857249904B09C209C5FCDDF2C1BB7D51106E3C84839F9971
            C510E661B3DE65625D265694941E8290896CAF414356289704B987209CD3EF69
            CF36D8DB5AE88A1A2CDEF9B7DF4B10E63DBA2B985897891525A587206422DB3F
            8FBF79857249903B09425AEE69A1D3AF91EE5857EB1F8671D1106663B3DE6562
            5D265694941E8290595416A01B16299704194210D2525FA9E6A9C1D6DD7EFB4D
            9F7979F065B3DE67625D265694941E82905954361F972E522E0932902064874B
            DFEEE5F41B7FBBC8EF4BD0E7BC9DCCD7C7FBA807BE9B8975995851527A0842A6
            505C7D2E5AA4A420C3094276B82E086FF8D3C1B797FE76BCB5CC139EFF36EB5D
            26D665624549E921089942F107C3572C5227FE0A13EC2608D9E19EF7FF5CE866
            9FF0FCB759EF32B12E132B4A4A0F41C878F5A5677810C69C2FCC4610B2C33D6F
            012A08A762B3DE65625D265694941E8290F10606E159EF7E0E07094276B8FFCF
            FCA6BAB75F6FF609CF7F9BF52E13EB32B1A2A4F410840CD65A777EDA0A9FF836
            7A67DD32B40842BA06FE99DF29377ECAB7B8F40ECFC966BDCBC4BA4CAC28293D
            04218375D79D7B2E12C69C17AC4210D275F5E5C1D39F4B1B4FDDB37EA8F784E7
            BFD7AC2E13EB32B1A2A4F410848CB463D1B9FA8D4663CE08D62208E93AB785EE
            29ABD39FBD4FFB7DD197CD7A9F8975995851527A0842469A2708612C4148D789
            0977E775B6737F515F103EEAB1EF63625D265694941E829061F6AD38D6292209
            42BACEAAB84BDF48A6FE4DF7DD0741F8A8C7BE8F8975995851527A0842861184
            F09B20A465D1CB83DBDFFA0FDD9783873CF9BD0876995897891525A58720648C
            DDCBCDE96F340A331084B45C747970C8F367F7AA3EC39DBF9FCD7A9789759958
            51527A0842C61084F09920A4E594169A2AA88EFF49F9439EFC36EB5D26D66562
            4549E9210819A0F871F02D31CF649E4910D272BC8526ACA9EE5F333EF00F085F
            36EB7D26D665624549E92108194010C21F04212D07736EC81BC99CFEB804E103
            1FFE0E26D665624549E92108B9DB1535F8B254B1384148DD8A97077F7DC71D7F
            14B0F125135EE1BC87CD7A978975995851527A08426E75510D7E887932F34082
            90BA732F0FDEFC211367359E207CE6C3DFC1C4BA4CAC28293D0421B71284F02D
            4148DD9116DAB108D7DFEDF3DB7FB97BD917849507FEB487BF83897599585152
            7A0842EE73690DBEAC56AC4C1052B7BB85AE68B3B757FFF67D539F39517CE04F
            7BF83B985897891525A58720E43E82107E2208A99B27082BF7E48A6B924786B0
            3A9BF52E13EB32B1A2A4F41084DCE4DCCF0FBC79B53A72E797FEE0C467BE89DF
            108290BAB582B0FB7D8B0F47103EF3E1EF60625D265694941E82909B2C1A8447
            36DF953DD0E427E063B75CF71384B46CFFD9DEDBAF6A395883C53B70E4BD521F
            F5B4B759EF32B12E132B4A4A0F41C81D4EBF4A76CF65B7FA1E7DC7D75E7187CF
            A506EF2408598E2562089BF52E13EB32B1A2A4F41084DC61C5203C5283952FBF
            E86E9FC86EEF4E8290E5582286B059EF32B12E132B4A4A0F41C8E5AE88B72141
            78F00F757E7DF95A7F4F68B7772741C85AAC0FA3D8AC77995897891525A58720
            E47217AD2C972E58277ECCD7D7AF3D929A77B2E1BB9320642DDE716A149BF52E
            13EB32B1A2A4F410845CEBBA6B627306E1EEF7DC9BED4C5483371384AC45108E
            62B3DE65625D265694941E82906B5DB7ACCC1F84AD3F329CED4C9CFCEEE51184
            AC45108E62B3DE65625D265694941E82906BDD1C8457DCF8EEDF171584D40942
            D6F2CC8F7C9881CD7A978975995851527A0842AE75DDEF464E1E846FBF6AF29F
            AF0BC29B0942A0C266BDCBC4BA4CAC28293D0421D7BA3908AFB8F11B3EEF7EC2
            D370FE7B184610021536EB5D26D665624549E92108B9D6A55D71EE8DDFF9C981
            5704E7299D10F0F1898B12844085CD7A978975995851527A0842AE75E9A5B673
            6FFCB616BA22928B77BEF5678D970E813F0842A0C266BDCBC4BA4CAC28293D04
            21FCDD6D2D74FAEFD09E78CF05E1408210A8B059EF32B12E132B4A4A0F41087F
            77CFE5C1E135B8FD4DFDBEE8408210A8B059EF32B12E132B4A4A0F4108FFE2BA
            DF71BDE2FD75B66F73F79A3EF93BA04612844085CD7A978975995851527A0842
            F817B705E1157F3AF8F6D2DF8EB796895922262708810A9BF52E13EB32B1A2A4
            F41084F02F2E6AA18BDE6DF5869B8D5922262708810A9BF52E13EB32B1A2A4F4
            1084F02F6EF84088B53A336689989C2084F9CDB036DAAC77995897891525A587
            20847F71FAEBFD157F3AF8D38D0BC275094298DF0C679FCD7A97897599585152
            7A0842F8A7D3FBEAD21A7C5DB36A5F773D930D8210E637C35B31DBAC77995897
            891525A58720847F3AB785AEAEC1D7E6EEE4ACCFC6885922262708617EFB3EE9
            E7C3457F8370EE8D4732B12E132B4A4A0F4108FF74E2AF4ADE5083AF4E450C19
            027582109670A409FFB0EF6CB559EF32B12E132B4A4A0F4108FF745D105E7AA2
            9D9B8582700841082BBABF0F6DD6BB4CACCBC48A92D24310C23F9DD542437EEB
            F2AC4E108443084258DD8971F82A7CAE6CE51FF332B13E132B4A4A0F4108FF70
            56C58DFD1BBC83B5E00F08471184B0BA6FD7CFDD952808CF62625D265694941E
            8210FEE194169A24A87EDA8208C2690942585D71FDAC27E2B7B760B3DE65625D
            265694941E8210FEE1780BCD56533BD6F4D91EC273084258DDEEF5B3F5233C9B
            F52E13EB32B1A2A4F41084F00F07FF76EE9EB715BDFA5EF903C2510421ACEE9E
            9F2ADAAC77995897891525A58720847F38D24273D6E0B7F74D10CE4910C2EA04
            E19C4CACCBC48A92D24310C2DF1D7C219FF9372DEB8D37F3A388270861758270
            4E26D665624549E92108E1EF8EBC90DFDF51F5EFB8FBF2E03D0F84DF0421AC4E
            10CEC9C4BA4CAC28293D0421FCDDE96F06B0A172E31F377BFC4DEA5ADF57100E
            2408617582704E26D665624549E92108E1EFEE0CC2B7DFE2ED2F790AC23C8210
            029CFBE66482F01426D665624549E92108E1EFE609C2DD1B827DDFEE9421709C
            20840037FC39BACD7A978975995851527A0842F8BBB582B0FB7D8B0F47100E24
            0821C0C6E979D64FE56CD6BB4CACCBC48A92D24310C23FFC5E018FBCA34CD1C1
            1A2CDE81233F9C8E59195621082143FD45E18FB3B5F8F14536EB5D26D6656245
            49E921086122AED13D96208418BB7F73E40F82F01426D665624549E921086122
            82F0B104212439DE84ADBF1770E26F30B12E132B4A4A0F4108B350834F260821
            CF912C14846731B12E132B4A4A0F4108B3F0277C4F260821DB59EF0466B3DE65
            625D265694941E8210A6E0F2E0C30942789A7DDB6E9BF52E13EB32B1A2A4F410
            84300541F8708210A8B059EF32B12E132B4A4A0F410853F0FBA20F2708810A9B
            F52E13EB32B1A2A4F4108400E30942A0C266BDCBC4BA4CAC28293D0421C07882
            10A8B059EF32B12E132B4A4A0F4108309E20042A6CD6BB4CACCBC48A92D24310
            028C270821C94FE7E9F133D466BDCBC4BA4CAC28293D0421C078821062143F72
            70DFD96AB3DE65625D265694941E8210603C410819EA1F40FFEDD9FAEBCBB7CF
            629BF52E13EB32B1A2A4F4108400E309420850AFC1D777676BE5F3876CD6BB4C
            ACCBC48A92D24310028C270821C08941F8FAF91262E5A6F8CDC4BA4CAC28293D
            0421C0788210027C3D3D3F9F926F7B4F105EC1C4BA4CAC28293D0421C0788210
            5677BCF704E1154CACCBC48A92D24310028C2708617582704E26D665624549E9
            210801C61384B03A41382713EB32B1A2A4F4108400E30942589D209C93897599
            5851527A084280F1042104D8FEDC084138848975995851527A084280F1042104
            D82E3A4138848975995851527A084280F1042104F0B1131332B12E132B4A4A0F
            4108309E20840C1B5127088730B12E132B4A4A0F4108309E20840C3F9DA1BFCE
            4D4138848975995851527A084280F10421C4787B3A7FD8FE0BC397203C898975
            995851527A084280F10421242936E13641780A13EB32B1A2A4F4108400E30942
            0873B0097F3A976DD6BB4CACCBC48A92D24310028C270821D2BE2CDC38916DD6
            BB4CACCBC48A92D24310028C2708E109F6FD79E1DB5B70E26F30B12E132B4A4A
            0F4108309E2084A7D9B7EDB659EF32B12E132B4A4A0F4108309E20042A6CD6BB
            4CACCBC48A92D24310028C2708810A9BF52E13EB32B1A2A4F4108400E30942A0
            C266BDCBC4BA4CAC28293D0421C078821002FC3A3DAF3E076DD6BB4CACCBC48A
            92D24310028C270861755FCFCD2BCE479BF52E13EB32B1A2A4F4108400E30942
            58DD4FE7E6B967A5CD7A978975995851527A084280F10421AC6EE3DC3CF1C4B4
            59EF32B12E132B4A4A0F4108309E2084D509C239995897891525A5872004184F
            10C2EAFCCAE89C4CACCBC48A92D24310028C270861757F9C9B179D8C36EB5D26
            D665624549E9210801C61384B03A41382713EB32B1A2A4F4108400E30942589D
            209C938975995851527A084280F10421AC4E10CEC9C4BA4CAC28293D0421C078
            8210562708E764625D265694941E8210603C4108AB13847332B12E132B4A4A0F
            4108309E2084D5F9D88939995897891525A5872004184F10C2EADE9EC5BF1D39
            4F6DD6BB4CACCBC48A92D24310028C27086175F520FCAA7EE6DAAC7799589789
            1525A5872004184F104280234DF8D9C6896CB3DE65625D265694941E8210603C
            4108610EC6E14FE7B2CD7A978975995851527A084280F1042164DBD187DF9ECE
            36EB5D26D665624549E9210801C61384F034F5B3FEED5739F137985897891525
            A5872004184F10C2C3153FC6D066BDCBC4BA4CAC28293D0421C0788210A8B059
            EF32B12E132B4A4A0F4108309E20042A6CD6BB4CACCBC48A92D24310028C2708
            810A9BF52E13EB32B1A2A4F4108400E30942A0C266BDCBC4BA4CAC28293D0421
            C0788210A8B059EF32B12E132B4A4A0F4108309E20042A6CD6BB4CACCBC48A92
            D24310028C270881D7FF9EE01B27B2CD7A978975995851527A084280F1042150
            F928429BF52E13EB32B1A2A4F4108400E30942A0B211B759EF32B12E132B4A4A
            0F4108309E200436CEEEED15C089BFC1C4BA4CAC28293D0421C078821078154E
            709BF52E13EB32B1A2A4F4108400E30942E0B7B70BC21F9CF81BE44D97891525
            A5872004184F10029FB59AD089BF41DE74995851527A084280F10421F0ADCFA7
            BC5F19DDC1C4BA4CAC28293D0421C0788210A8B059EF32B12E132B4A4A0F4108
            309E20042A6CD6BB4CACCBC48A92D24310028C2708810A9BF52E13EB32B1A2A4
            F4108400E309428871E97EDA66BDCBC4BA4CAC28293D0421C078821002DCF0D6
            A036EB5D26D665624549E9210801C6138410A0FBF9819F154F5E9BF52E13EB32
            B1A2A4F4108400E30942087024085FB5F3D766BDCBC4BA4CAC28293D0421C078
            821056F7F5DCFC7C3ED65B71FB2CB659EF32B12E132B4A4A0F4108309E2084D5
            FD716EBE3D1937CEE58DAFB559EF32B12E132B4A4A0F4108309E2084D57583F0
            A72F7C09C253995897891525A5872004184F10C2EA7607E1ABD38436EB5D26D6
            65624549E9210801C61384B0BA234158FF729BF52E13EB32B1A2A4F4108400E3
            094258DDC1202CDE82CD7A978975995851527A084280F10421AC4E10CEC9C4BA
            4CAC28293D0421C0788210E6F7F9ECFB7AAE09C239995897891525A587200418
            4F10C2FC7E3AFB3ECE3B41382713EB32B1A2A4F4108400E30942985FFDC3E55F
            82701A26D665624549E9210801C6138430BF56107E38F2E11382F01426D66562
            4549E9210801C6138430BF1D41F855FD43E705E1294CACCBC48A92D24310028C
            2708612DA7C4E1879FCE6E41780A13EB32B1A2A4F4108400E3094258DD8989F8
            41109EC2C4BA4CAC28293D0421C0788210C21CEF4341780A13EB32B1A2A4F410
            8400E30942C876D61BD2D8AC77995897891525A5872004184F10C2D3D4CFFAB7
            5FE5C4DF60625D265694941E8210603C41080F57FC5C7B9BF52E13EB32B1A2A4
            F4108400E30942A0C266BDCBC4BA4CAC28293D0421C0788210A8B059EF32B12E
            132B4A4A0F4108309E20042A6CD6BB4CACCBC48A92D24310028C2708810A9BF5
            2E13EB32B1A2A4F4108400E30942A0C266BDCBC4BA4CAC28293D0421C0788210
            A8B059EF32B12E132B4A4A0F4108309E2084BA8FB3E099CF769BF52E13EB32B1
            A2A4F4108400E30942A8FB7C163CED396FB3DE65625D265694941E8210603C41
            08455F4F81473DED6DD6BB4CACCBC48A92D24310028C2708A1E8A753E0214F7E
            9BF52E13EB32B1A2A4F4108400E3094228DA38059EF0FCB759EF32B12E132B4A
            4A0F4108309E2084A2879F0236EB5D26D665624549E9210801C6138450F4F664
            79459F0836EB5D26D665624549E9210801C61384505409C257EEB960B3DE6562
            5D265694941E8210603C410845C5207C859E0E36EB5D26D665624549E9210801
            C6138450540FC20F979E147FDC991B4E409BF52E13EB32B1A2A4F4108400E309
            4228EA06E1EBCAF3E2FE0F45B459EF32B12E132B4A4A0F4108309E2084A29F76
            AB434E8DFBB7CE36EB5D26D665624549E9210801C6138450B4BD5BBDF9041184
            F333B12E132B4A4A0F4108309E2084A2B7BBD53BCF1141383F13EB32B1A2A4F4
            108400E3094228AAEC56EB27D40D77E6FE87CF6726D665624549E9210801C613
            845054DFADDE70B208C2F9995897891525A5872004184F1042516BB77AF5F922
            08E767625D265694941E8210603C410845DDDDEAA5BF3E2A08E767625D265694
            941E8210603C410845FB76AB179D3882707E26D665624549E9210801C6138450
            B47BB77AC5B92308E767625D265694941E8210603C4108454776ABA7FFFAA820
            9C9F8975995851527A084280F10421141DDFAD9E781209C2F9995897891525A5
            872004184F1042D129BBD5B32E150AC2F9995897891525A5872004184F1042D1
            59BBD5539A5010CECFC4BA4CAC28293D0421C07882108ACEDDAD1E3CA104E1FC
            4CACCBC48A92D24310028C2708A1E8F4DDEA914B8582707E26D665624549E921
            0801C613845074C56E7577130AC2F9995897891525A5872004184F1042D175BB
            D51D2797209C9F8975995851527A084280F10421145DBA5BED5E2A1484F333B1
            2E132B4A4A0F4108309E2084A2AB77ABAD261484F333B12E132B4A4A0F410830
            9E2084A27B76ABC5134D10CECFC4BA4CAC28293D0421C0788210EABE9E05573C
            F32B67A5209C9F8975995851527A084280F10421D4FD71165CF7B47F7B627E4B
            104EC5C4BA4CAC28293D0421C0788210A6D5CD4241381513EB32B1A2A4F41084
            00E309429859AB0905E1544CACCBC48A92D24310028C27086172F52614845331
            B12E132B4A4A0F4108309E20842554B250104EC5C4BA4CAC28293D0421C07882
            1056D1FDF0FA1BBEBB137F838975995851527A084280F104212C64E06968B3DE
            65625D265694941E8210603C4108CB19B26FB659EF32B12E132B4A4A0F410830
            9E2084157D3D1F05E16C4CACCBC48A92D24310028C27086175BFCECD1B4E409B
            F52E13EB32B1A2A4F4108400E30942A0C266BDCBC4BA4CAC28293D0421C07882
            10A8B059EF32B12E132B4A4A0F4108309E20042A6CD6BB4CACCBC48A92D24310
            028C2708810A9BF52E13EB32B1A2A4F4108400E30942A0C266BDCBC4BA4CAC28
            293D0421C0788210A8B059EF32B12E132B4A4A0F4108309E20042A6CD6BB4CAC
            CBC48A92D24310028C2708810A9BF52E13EB32B1A2A4F4108400E30942A0C266
            BDCBC4BA4CAC28293D0421C0788210A8B059EF32B12E132B4A4A0F4108309E20
            042A6CD6BB4CACCBC48A92D24310028C2708810A9BF52E13EB32B1A2A4F41084
            00E30942A0C266BDCBC4BA4CAC28293D0421C0788210A8B059EF32B12E132B4A
            4A0F41089CE96DD87C16B3FE1C2708810A9BF52E13EB32B1A2A4F41084C0095A
            1DF859CC12749020042A6CD6BB4CACCBC48A92D2431002FBEDEEC0DF6296A083
            04215011B659FFFD70AE7B086113BB81891525A5872004F6389E821F6296A083
            04215011B659FFFC702E7A146113BB81891525A5872004DACEAAC197D798FF25
            08818AB0CDBA209C90891525A58720047AD4E01504215011B65917841332B1A2
            A4F4108440CF294118B3F29C45100215619B75413821132B4A4A0F4108346CD4
            48CC62328420042AD6DAACBFED3D413821132B4A4A0F410854A9C1EB0842A062
            ADCDFA4FEBD5B70B9A209C84891525A5872004AABC485C471002156BADC3AD3F
            3110849330B1A2A4F4108440D5D7178998056438410854ACB559DFF737E7E73E
            9CB5263603132B4A4A0F4108947885B89420042AD65A8A67F8C4DAB526360313
            2B4A4A0F4108947885B89420042AD65D8A4FFCC8A2D6A35E7762A3985851527A
            0842A0C4EF8B5E4A100215199BF5D3E37063081913BB93891525A5872004DE53
            835713844045D866FDEBBB8CEE6E45417816132B4A4A0F4108BC2708AF260881
            8AB0CD7AEB830ADFAADFC2BA13BB81891525A5872004DE13845713844045D866
            BDFB39843B16C0B089DDC0C48A92D2431002EF09C2AB0942A0226FB3FEF188F6
            3D844A4FE64DEC6A265694941E8210784F105E4D10021536EB5D26D665624549
            E921088137BC36DC4010021516E42E13EB32B1A2A4F41084C01B2E0FDE401002
            1536EB5D26D665624549E92108813704E10D04215061B3DE65625D265694941E
            8210784310DE4010021536EB5D26D665624549E92108813704E10D04215061B3
            DE65625D265694941E8210D8E285E11E8210A8B02677995897891525A5872004
            B67861B88720042AACC95D6113FBFD70AE7B086113BB4E527A0842608B17867B
            0842A022724D3EF2D9F4C51BFFC3BA13FBFC704C6CACA4F41084C0167F40780F
            410854E46DD6EB85B3AF85C2262608E791941E8210D82208EF2108818ABCCDFA
            1F8FE8DBC7F2D3BA5779E061131384F3484A0F41086C1184F710844045D866BD
            F8127364DD0B9E98201C2B293D0421F023AF0AB711844045D8B27CE4F2607102
            6B4DEC6DEF09C27924A58720047EE455E1368210A8085B960561F1C17EFB1220
            08C74A4A0F4108FCC8ABC26D04215011B62CB72E88FDF1CF2A31F95A6D6295FA
            BDFA51AC35B18192D24310023FF20784C715DF4E5D100215619BF56E107EFE37
            82F0A287B3D6C4064A4A0F4108FC48101EB4EFEDD4BF25088157DC667D7B917C
            FB1AB4FB374EA79DD8BE203CF701AE35B18192D2431002DFF392709C2004CE15
            B6326F2C92959F48E60561F1FEEF537CD4AB4FEC3649E9210881EF794938A8F5
            A7FF8210A8085B990561D70D7D1836B1EB24A5872004BEE725E12041089C2E6C
            65FE699DDCF7F9844F0BC28F47B13B1105E14149E9210881EF794938481002A7
            0B5B997F2A3A41F8931DEFCBBAE10913BB4E527A0842E07B5E120E3A37087FDF
            8E20843CBFCEEB67FE7D577DE9AB7CF913F2A6FB39843B5E32C226769DA4F410
            84C0F7BC241C517C3FF49FFEFD6E0E102CE7F7E9BF7B7FBFF4897FE473E71F18
            84BF1FD4BE875079B2454EEC0A49E9210881EF79493842100215A7AC15AB9FF8
            FB7EF121F273086760624549E9210881EF794938E2DCDFEAA9738060213B96D9
            C895796301AC5FC812846731B1A2A4F41084C0F7BC241C210881B77E3AF11FF8
            EB7CC7472108CF62624549E9210881EFED7879BEED3EECBE5767BDCE1D7F1BB7
            7D3775EE3480E1BA2BADCDFA4F7330B1B3985851527A0842E07BC383B05B4A07
            BBABFEB84EBC6357D460F7E10063B5165B9BF5DF8ABF8861625D265694941E82
            10F8DE890575C5776FDD9983EF6C7EE48EBD9A3FB73E51CCF20EF1EA4D68B3FE
            5BF1DD594DACCBC48A92D24310023F3AA5580EBE35F6C1EF32242C2FBA6F677D
            5F6042C526B459EF32B12E132B4A4A0F41086C19D5841306E1EE51F89551A0A2
            D28436EB5D26D665624549E92108812DA3DEFDF2ED1F87ECFB3CE2CAEF5F9DFB
            9957F7BFA34CE5FB02737ADB8436EB5D9113FB7850173D8AC8895D21293D0421
            B065862B846705E19184AB67DEA88FA46F7D53605ADB4D68B3DE9537B1FAC71A
            755F8FBEFDAAD6D73E4A527A0842A0E448B71CB93CF82A14DA0D09775D10BECE
            6EC298551D1E6BA3096DD6BBF226B6EF1764EA8F3D6F6217494A0F4108549DFB
            962AF56F74CADBD21C49B823BF057AE427B23BC42CE9F070277ED8E9C385E54D
            F1CF1CB69F3FDE97F51449E9210881B6133FC5A172FB82B02E664907EACB8213
            7F4358DE1CBC3C589940D8C4AE93941E821098CEF120ACBF55CCEBD4DF3EDD7D
            E70521F0D5D53F7D5B5DE5AFE9C2F2E6AC207C3D6662D7494A0F41084CA7FE17
            F3955B68B9FF0F080FDEE1CAFD07D675F06A4FB64ABA84E54DF727989FFFD9BE
            375ADBFEC74F96941E8210984E76105EFD79F4C50775AEFB1F1470A925F68795
            B74E09CB9B23BFD22208CF95941E821098CB157F405877E91F108EADA63B3FB1
            0AC830F92EF1EDFA93F7BEACDB41F8F6CF2576FFD472DD895D27293D04213097
            2BFE80B04E1076094208B6CA2EB1BB10ADF2B8B61FE9DB97987DAF6882B02829
            3D042130174178114108742DB44B7CC8077508C27924A5872004E6727A101E5C
            E576FF01E14B10028B5B719798FD363C3F05E1BECF2714844724A5872004E612
            1C84AF71F974E952AF0921D2D25BC48F7529FB6F085F9BEF9D2308AF96941E82
            1098C8CD1F497FEEAD1D49C7EBDCB6C8CB428871C32F148C5D9A96DEFD1EB904
            2A084F94941E821098C84382F0EDD7EE16B3A403DFAABCAFE6E8FBD8B8CFA33E
            1467C2291D7C44C50728084F94941E82109888203C28664907BEB5E21FC88DBD
            CF9179B33DD2FA070C0AC22392D243100213B9EE430877AF75C557D083775E10
            0215C5B5629EA5A0BEB8DDF9C657F3CCE7C407F5F6A1F960FA7325A587200426
            72D6C5BD1D7D75FA9FFC0942E074C3FBEAA27B7BDD7D0ECE9BD643DBFDC3CDED
            7FFC6449E9210881890C0CC257F3D571F7AD9D75FBC7BF2FB09CB53E6D6F3B42
            8E8747E55D6AE4CD4F7330B18392D24310021339F1CFFFCEFDC9F4753FE7BEE2
            CD39631676E00F3F6DD67F5A49C6AE06FBDEC264DFFA296FDE2ABECBAB891525
            A58720042672EE9B929FFBA3F42B7E307FDD4735C4ACEDC0671B9BF5099BF0EA
            3F5AF39E995DBF3F9EF1EDBFF9C36327B621293D0421C030821068D9DEACCFD6
            84F59FF1ED8B10417805132B4A4A0F410830C6D59FE41EB3BC03BFBDDDAC4FD5
            84DD5FFAE8FEFAA820BC82891525A5872004184310025D95CDFA3C4DB8E3AF00
            5A4D2808AF60624549E921080186F12BA3404B71B33E4913EE7B9FB0733FFD55
            DE74995851527A08428091BCCB285057DFACCFD084BBDF38BAD88482F00A2656
            94941E8210603C1F4C0F541CFC2CF2ED7F7FC31D3EB70905E1154CAC28293D04
            21C0788210A8E86ED68737E1591F33F8ED970BC22B985851527A084280F10421
            50B163B33E7C7F7FF00E6C24A520ECAABCCD8F891525A5872004184F100215D7
            7D5EDFCD77BB751F7EFA7241D8B5FB5D6A1F3BB10D49E9210801C62B06E1AF15
            7BFB5FC62CE9C0B7766FD67F7FE1C055E248977EDB8482B06BE315E4A7EBAE7F
            FCBFFC96941E821060BCB741B8FD52FDF59F01918E6CD67F7DEDF025E24897D6
            D7C9B75F357C0EA3546668624549E9317E69384BD251019E461002150FDFACEF
            58001F3EB19F74FF4EC1C4BE4A4A0F4108309E20042AE44DE5971EDFFEFB474D
            EC27AD2634B1AF92D24310028C2708810A79D39D8389BD55294313FB2A293D04
            21C0788210A89037BF15DFB9D4C4EA3EFECAD4C48A92D24310028C2708810A9B
            F5CF7CAADE154CAC28293D0421C0788210A8B059EF32B12E132B4A4A0F410830
            9E20042AD6DAAC4FF8E187C3EFCF758FEBAC07953AB1D325A5872004184F1002
            156B6DD62BBFD279E77D187E67AE7B44DFDAF730F3267691A4F4108400E30942
            A062ADCDFADB20BCE112E25A13DBF7702AEA0F396C62D7494A0F4108309E2004
            2AD6DAACD783F0BA47B1D6C4F63D9CBACA030F9BD87592D24310028C2708818A
            B536EB82F09E87D3F2F6B1874DEC3A49E9210801C6138440C55A9B754178F5C3
            F9FC405AADB83181B0895D27293D0421C0788210A8586BB3BE512F5FFF8120EC
            3E9C7DD7FADE7E6DD8C4AE93941E8210603C410854ACB5591784973E9CD6A3A8
            7F4C45D8C4AE93941E8210603C4108542CB759FF69C9FAB8CF82F0C8C3D9F128
            DE26FA2B6E62D7494A0F4108309E20042A96DBAC5FFDA179FBEEC0CC13AB3F1C
            413856527A084280F1042150B1E266BDFBC698E73E9C1527567C388270ACA4F4
            108400E30942A062D1CDFA0D9F9ED7FAD6F34FACF27004E15849E9210801C613
            8440C5D29BF5E39FA1B7E351AF35B1B76FFD2208E791941E8210603C41085484
            6DD64F4CC48CF7CC3CEBB3048BB72F088F484A0F4108309E20042AC236EB5FAF
            77ED4EC40706E18EC722084F94941E8210603C410854846DD6DFFE02E4F12B66
            6B4DEC944BA6F50F9D0F98D84049E9210801C613844045D866BDFB17713B16C0
            752776C5EFD30AC21325A5872004184F100215799BF58F47B4EF21547A326962
            E7BE2BCF4B101E93941E8210603C410854D8AC77054FEC781F0AC22392D24310
            028C2708810A9BF5AE474DAC9B8882F088A4F4108400E30942A0C266BDEBC913
            ABBFB2BCFDAA874CAC25293D0421C0788210A8B059EF32B1CF9EF65797974A4A
            0F4108309E20042A6CD6BB4CACCBC48A92D24310028C2708810A9BF52E13EB32
            B1A2A4F4108400E30942A0C266BDCBC4BA4CAC28293D0421C0788210A8B059EF
            32B12E132B4A4A0F4108309E20042A6CD6BB4CACCBC48A92D24310028C270881
            0A9BF52E13EB32B1A2A4F4108400E30942A062DF66FDF7573D708990375D2656
            94941E8210603C4108541C0CC2E2BF4F727C628F1AD74B109625A5872004184F
            100215A70461E54B6248E82E415894941E8210603C4108549C1584C52F0C70E2
            C49E30AE873FF696A4F4108400E30942A0E2DC20AC7CEDEA247497202C4A4A0F
            4108309E20042A4E0FC2CA972F4D427709C2A2A4F4108400E30942A0E28A202C
            DEC8A22E9A58EAB85E82B02C293D0421C0788210A8B82E082BB7B32209DD2508
            8B92D24310028C2708818A4B83B07253273E847BD62B09DD25088B92D2431002
            8C2708818AAB83B0788367DDFF3BFBB3F57D5B13BBF451AC32B1074A4A0F4108
            309E20042ACEFD1CC2FBDF3AE5FE4F440C4BE84BBFD7C663F7E2F255527A0842
            80F104215071FA07D3DFDC84F7C786843EFE1D6FF8A62B4A4A0F4108309E2004
            2A4E0FC2D7BDABCAEA41F8BA7D115E65620F94941E8210603C4108545C11841B
            B75CBCFDABEFFFFDDF5142DFF91D1795941E8210603C4108545C1784AF5B9A70
            95BC3998D0273EA85526F64049E9210801C6138440C5A541F8BA7E8559256F8E
            27F4598F6B95893D50527A084280F10421507175106E7C97E2F7BAE2FEDFFF1D
            25F49DDF715149E9210801C6138440C53D41F8BAAC0957C99B1313FAE0035C65
            620F94941E8210603C410854DC1684AF6B569B55F2E6DC843EF2185799D80325
            A5872004184F1002157706E1C677ECDEC8C1FB7F84849EFF3B2E2A293D0421C0
            788210A8B83F085FA736E12A79735142EF78B0AB4CEC8192D24310028C270881
            8A2141F83A6FE559256FAE4BE8536E6AC2893D50527A084280F1042150312A08
            37BE7BEB0657C99BAB13BA7E83AB4CEC8192D24310028C2708818AB141F83ADC
            84ABE4CD0D095DBCCD5526F64049E9210801C6138440C5F0207C1D5B8556C99B
            7B127ADF3D39726776DF612F2E5F25A5872004184F100215C3F366FB9EBCBDF1
            55F2E6CE847E454CEC8192D24310028C2708818A19F266FBCE6CDFFE2A797373
            42BFD69FD80325A5872004184F100215F3E4CDF65DFAE9BBAC9237F727F44FDF
            6295893D50527A084280F10421503155DE6CDFAB6FBFD12A79332AA15FCB4EEC
            8192D24310028C2708818A09F366E38E7DFD5EABE4CDC0847EAD39B1074A4A0F
            4108309E20042AE6CC9BEDBBF7F93BAE92376313FAF56ECD9F70620F94941E82
            10603C4108549C9237F7E7C4EFEFBB4ADECC90D0AFA526F64049E9210801C613
            8440C591CDFAC7D7DEB04ABC5DD0F6DDFF13EFCC2A09FD930927F64049E92108
            01C6138440C5429BF57AE7CC9C37BFBE5C425FFD1D1795941E8210603C410854
            ACB5592F768EBCD9B8ABDF32B11924A5872004184F100215CB6DD62B91236FB6
            EFEDCDF77FAD890D94941E8210603C4108542CBA591FB8702D373109BD8AA4F4
            108400E30942A062DDCD7AFDC3EB6FF8BEF34F4C42CF2F293D0421C0788210A8
            587AB3FED3F2256FEAF7FC86FBBFEEC46E96941E8210603C410854046CD66FFB
            88BF9FBEDDD5DFF1EA3B7FF5FD5F7A62774A4A0F4108309E20042A3236EB9F1F
            C5D5773E6062777E28E22B6262F7484A0F4108309E20042A6CD6BB3226F6FB51
            8CFA50C4E5267683A4F4108400E30942A0C266BDCBC4BA4CAC28293D0421C078
            8210A8B059EF32B12E132B4A4A0F4108309E20042A6CD6BB4CACCBC48A92D243
            10028C2708810A9BF52E13EB32B1A2A4F4108400E30942A0C266BDCBC4BA4CAC
            28293D0421C0788210A8B059EF32B12E132B4A4A0F4108309E20042A6CD6BB4C
            ACCBC48A92D24310028C2708810A9BF52E13EB32B1A2A4F4108400E30942A0C2
            66BDCBC4BA4CAC28293D0421C0788210A8B059EF32B12E132B4A4A0F4108309E
            20042A6CD6BB4CACCBC48A92D24310028C2708810A9BF52E13EB32B1A2A4F410
            8400E30942A0C266BDCBC4BA4CAC28293D0421C0788210A8B059EF32B12E132B
            4A4A0F4108309E2084F97D3EFB469D6B36EB5D26D665624549E9210801C61384
            30BF19CE3E9BF52E13EB32B1A2A4F4108400E3BD0DC20FBF56EC19B6A4F04CC5
            F3F4C34527A3CD7A978975995851527A084280F15A1BCD0D314B3A4CE8C8797A
            D6B969B3DE65625D265694941E8210603C4108F33BEB3CFDB0EF6CB559EF32B1
            2E132B4A4A0F4108309E2084159D9888C593D766BDCBC4BA4CAC28293D0421C0
            7882105677CFF5439BF52E13EB32B1A2A4F410840023CDF04B68C0717F9CCB1F
            27E3EE135C109EC5C4BA4CAC28293D0421C000E776E06F314B3A2CE7DB207CFB
            CF367C7B0B36EB5D26D665624549E92108016E75F08A818F9D80391583F0ED17
            6EDF82CD7A978975995851527A0842803B1CBC24E883E96172BB83B0750B36EB
            5D26D665624549E9210801AE75CA6F870A42989C209C938975995851527A0842
            804B5CF46E318210E62408E764625D265694941E8210E06457BC618C2084C909
            C239995897891525A587200438C7456F1CFA4110C2E404E19C4CACCBC48A92D2
            4310021C75FCA3C6DEDE822084F97D3E3D05E1244CACCBC48A92D2431002EC77
            D6A74E0B420870F022A120BC828975995851527A084280B6B33AB07E838210E6
            7770272D08AF60625D265694941E8210A0E1F4142CDEAC208425D4CFE5B75F28
            084F61625D265694941E8210E0BD8B3AB07EFB82105671D6FB4B09C253985897
            891525A5872004D872750A16BF8B2084559C1284AD5F2F77E26F30B12E132B4A
            4A0F4108F08D7B3AB0FEED0421ACE560160AC2B3985897891525A5872004F817
            37A760F19B0A42585A6B61D938916DD6BB4CACCBC48A92D2431002FCDD911FE7
            1F5F4805213CCDBE6DB7CD7A978975995851527A0842E0E9865C12ECDE074108
            BC6CD6FB4CACCBC48A92D24310020F35F69260F7CE0842E065B3DE67625D2656
            94941E8210789C192E0976EF9220045E36EB7D26D665624549E9210881A798EA
            9260F7BE0942E065B3DE67625D265694941E8210C837E125C1EE3D1484C0CB66
            BDCFC4BA4CAC28293D0421106BE64B82DDBB2A08612D17EDAA6DD6BB4CACCBC4
            8A92D243100281E6BF24D8BDC3821056515C7FF69DAD36EB5D26D665624549E9
            2108811C0B5D12ECDE7341084BA8AF4282F01E26D665624549E9210821CAC73A
            1E735E771FF80E93CC4A104280D642F4F56CFDFCE53F9DCB36EB5D26D6656245
            49E9210821C41F2B78CCA9DD7AD42D538D4810420041382113EB32B1A2A4F410
            8490E081CBF7EA9704BB0F4710C2FCBE9E9E9F4FC9B73FB6ABFC5CEF81ABFD41
            26D665624549E9210861793F1542CCD95D79B015330F4410C2EAB66BF0250807
            31B12E132B4A4A0F4108CB7B4810865D12EC3E3A4108933BDE7B82F00A26D665
            624549E92108616D1B79907176A75E12EC3E4C41089313847332B12E132B4A4A
            0F41086B0B0EC2EC4B82DD072B08617282704E26D665624549E921086161916D
            F0904B82DD472D08617EDB6F132A088730B12E132B4A4A0F41080B0B6B83475D
            12EC3E764108F3DB2E3A4138848975995851527A084258553D21E6F7E4142C4E
            4010C2FC04E1844CACCBC48A92D24310C2AA2A1135F909AE037F1384906123EA
            04E11026D665624549E921086149C5949AF60497827F1084906163332D088730
            B12E132B4A4A0F41084B5A340875E04F0421C4D8B73EBFFD5CFB8D1B77E26F30
            B12E132B4A4A0F4108EBF969B12EEE27E6B9CF15F33C844B09424872E4DD927F
            1384A730B12E132B4A4A0F4108EB592808756091208430079BF0A773D966BDCB
            C4BA4CAC28293D04212CA6FE072AAFA12BB8146C118410E9F495D066BDCBC4BA
            4CAC28293D04212CA61584AFDB17F1677EACFC7182109EE0F89F7FCFB0CEAFC5
            C4BA4CAC28293D0421AC647B991EBB88BB2478842084A7D9B762DBAC77995897
            891525A5872084954C18842E099E4210021536EB5D26D665624549E921086119
            6FD7E89B177197044F2408810A9BF52E13EB32B1A2A4F41084B08CCA1A7DC3FB
            CAB8247805410854D8AC77995897891525A5872084351417E84B83D025C1EB08
            42A0C266BDCBC4BA4CAC28293D0421AC616C104AC1AB094208F0C7E979C5F968
            B3DE65625D265694941E821016505F9DAF58C777D460CCC2721B4108ABFBE9DC
            3CF7ACB459EF32B1FFDFDEDD6DA7AE2CD91AF5FB3FF559D56635978F7F205252
            28A4A1DEEFAAF634E05828C9CF80B4CAC48A92D24310C20DD4DFF71B0FC29825
            E5648210EEEEC5B1D9FDD17D07FE0B26B6CAC48A92D24310C2D52D2DCD87AFE3
            FB2FA34C852084BB1384D76462AB4CAC28293D04215CDDD2D702CF0FC2983564
            962084BBF391D16B32B155265694941E82102E6DC3BA7CF87965BC369C4010C2
            DD9D7046990F0BF23A135B65624549E92108E1D236D45DF7894663168D4B1184
            707782F09A4C6C95891525A5872084EBDAB6285BCAEF4810C2DD09C26B32B155
            265694941E8210AE6BDB7B7D96F23B1284707782F09A4C6C95891525A5872084
            8BDABC225BCAEF4810C2DD09C26B32B155265694941E82102E6AF357012DE577
            2408E1EE04E13599D82A132B4A4A0F410857B46739B694DF912084BB73D9896B
            32B155265694941E8210AEA87839F8BA98233D952084BBABAFDB875F1BD681FF
            8289AD32B1A2A4F41084703987D7E087A5FCF20421DCDD9EA5BB7EE4DAACAF32
            B155265694941E82102EA723083FACE6D7260821C051ABF78B03D9667D9589AD
            32B1A2A4F41084702D4D35F86135BF36410861762EE67F1DCB36EBAB4C6C9589
            1525A58720846B1184CF240821DB86B5FDD7C3D9667D9589AD32B1A2A4F41084
            70217D35F86135BF3641084F533FEADFFE9403FF05135B65624549E92108E142
            04E163094278B8E2650C6DD65799D82A132B4A4A0F41085771EC12BCF9BAF67C
            1DDD694313844085CDFA2A135B65624549E92108E12ABA8370CFAD3D4AF1EFF4
            AD77FA9320043EACEDEB4C6C95891525A58720844B387CFDB5A06F3352831F82
            10A8B1B6AF32B155265694941E82102E41105E842004AECCDABECAC456995851
            527A084298D7B1F85AD0B71184C09559DB5799D82A132B4A4A0F4108F304E175
            0842E0CAACEDAB4C6C95891525A5872084614D2BAF057D83A91AFC1084408DB5
            7D9589AD32B1A2A4F41084304C105E8720040655AE79636D5F6562AB4CAC2829
            3D04214CEA5B76FFCA869843BE83200406555E116CD65799D82A132B4A4A0F41
            089304E1A5084260D08BA3FBF50AE0C07FC1C456995851527A084298F473D93D
            F0906C3A57CDFE8B61342D3B9FBFEF86DB7FDB637D0FBBF8000421C4ABAC0336
            EBAB4C6C95891525A5872084492707E1811736DC195DADEF82AEDE4BA5068F7D
            E47B7E174108F19616A50F07FE4BF26695891525A5872084618767D25FB77FEC
            752CF6BF0BD774E29C9F5EDFD145365E8210F8EA0A7FA8CA206F56995851527A
            0842A06467CE1DDBBD0756DC45765D8210F8D5F807DAEF4EDEAC32B1A2A4F410
            8440C9758270B5063F0421707FFFBEC26DB3BECAC456995851527A0842A0644F
            1076BF3DF8F536B7BD920D9E5FF4C5C3FEF521094278329BF55526B6CAC48A92
            D243100225970DC2D7976FDE765E1941086C70D477B62B77F19503FF05135B65
            624549E9210881928B046153B9094260A77396119BF55526B6CAC48A92D24310
            0225AFF73A2F926FE4EDC18BDCECE607F09320848B1384D76462AB4CAC28293D
            042150F262AFB3B915F73F8C436EF3EDAF70024108772708AFC9C45699585152
            7A0842A0645B109E7631FA6B7E1275FFEFF5F3210942B82641784D26B6CAC48A
            92D2431002257FED75EAE7FC6CFA78E75F777DC86F771A4108D7F77A411384D7
            6462AB4CAC28293D042150729D20FC383A8AC66BF0ED6FF42108E1025E7F4241
            105E9389AD32B1A2A4F4108440C9AF7B9DFAF6E8D8A5A67235F9FA3D0A42A0A2
            B2F27C1284176162AB4CAC28293D042150F533F0A682F0E7E3F94BE57E052150
            B114849F4EF8739803FF05135B65624549E9210881AAA520ECAEC15F1FD5AF8F
            64F5160421F0AB6D41F8D39EE3D4667D9589AD32B1A2A4F4108440D5B7C65BFA
            3FCF7C6CDFBCBD774108AC3A2A0EFFD9FC11F7D51F7F20135B65624549E92108
            81AA2B07E1CF4758BF774108EC716C1CFEF3D7B16CB3BECAC456995851527A08
            42A06AE90C7BDFFED7D9C7F9E2315CA1063F0421DCDFD299B7DE12844731B155
            265694941E8210A8BA4B107EAC649E20040E51594CF69FA7D4667D9589AD32B1
            A2A4F4108440D5DB1789A5B7E6363F80633F022A088143AC2E26F5A3FEED4F39
            F05F30B155265694941E8210A87ADB7BAD4158DC6CAD3E0641081CA8F877ABBF
            7EF0938F8C1EC5C456995851527A0842A0AA35083F7F76691BF4D62DCE2853F9
            ED0421F061B3BECEC456995851527A0842A0EA6D3BED89ABB767251584957F19
            B3A403BFB2595F6562AB4CAC28293D042150D51784879F8CA1FE000421702336
            EBAB4C6C95891525A5872004162CBD8F776C10FEFA2FFFB2EDAE07D743410854
            D8ACAF32B155265694941E82105850FFA65F470DBEF8A9D51FDFF3803B0842A0
            C2667D9589AD32B1A2A4F41084C0A4EE2B55DC8520042A6CD65799D82A132B4A
            4A0F41084CBAC857F8C60942A0C2667D9589AD32B1A2A4F41084C02441F8EB1C
            7E1284C087CDFA3A135B65624549E9210881491739A7CB38410819BABF966CB3
            BECAC456995851527A0842608CB7073F0942C850FF23D781E7D372E0BF6062AB
            4CAC28293D04213046107E128410A07896AC3D2749B6595F6562AB4CAC28293D
            042130E622977CB8024108017606E18B1F79FDB30EFC174C6C95891525A58720
            049827082140E5530F6F0FF68F9707B2CDFA2A135B65624549E9210801E60942
            0820082FC8C456995851527A084280798210EE6E5B0DFE7568FF752CDBACAF32
            B155265694941E8210609E2084BBDB10845FFF8D206C6262AB4CAC28293D0421
            C03C410877F7B6E8DE9E7266F3274E1DF82F98D82A132B4A4A0F4108304F10C2
            DDBDCEB9CA0948056107135B65624549E9210801E6094208F0E2AAF482708A89
            AD32B1A2A4F4108400F3042104F82B08B75D9F50101EC2C456995851527A0842
            8079821002FC557482709089AD32B1A2A4F4108400F3042104A85C63F0A37C06
            51417808135B65624549E9210801E60942C8B0E7BAF382B08389AD32B1A2A4F4
            108400F30421C4D87690BA0E6113135B65624549E9210801E6094288F1E2207D
            71840AC22626B6CAC48A92D2431002CC138490E4AFE3B49E7982F02826B6CAC4
            8A92D2431002CC1384F064C5B7073F6CD6D799D82A132B4A4A0F4108304F10C2
            9309C23E26B6CAC48A92D2431002CC1384F0709F87F6EBA3D8667D9589AD32B1
            A2A4F4108400F304215061B3BECAC456995851527A084280798210A8B0595F65
            62AB4CAC28293D0421C03C410854D8ACAF32B155265694941E8210609E20042A
            6CD65799D82A132B4A4A0F4108304F10021536EBAB4C6C95891525A587200498
            2708810A9BF55526B6CAC48A92D2431002CC13844085CDFA2A135B65624549E9
            210801E60942A82B5EB22F92CDFA2A135B65624549E9210801E6094228FA7908
            3CEA696FB3BECAC456995851527A0842807982108A1EBE5B7DF8AFBF8189AD32
            B1A2A4F4108400F3042114BD38049EF0FCB7595F6562AB4CAC28293D0421C03C
            4108450F3F046CD65799D82A132B4A4A0F4108304F104251FD608964B3BECAC4
            56995851527A0842807982108ADE1E2CFFA41E0B36EBAB4C6C95891525A58720
            04982708A1A818841FA18783CDFA2A135B65624549E9210801E6094228AA07E1
            C72947C4C91745B4595F6562AB4CAC28293D0421C03C4108454B41F84FDF71F1
            EDC19CD99F27DFEF7D99D82A132B4A4A0F4108304F1042D15FBBD59143E3E79D
            761F8336EBAB4C6C95891525A5872004982708A1E8F56EF5E4AB149EBF75B659
            5F6562AB4CAC28293D0421C03C4108456F77AB671E2382F0FA4C6C95891525A5
            872004982708A1A8B25B3DED301184D76762AB4CAC28293D0421C03C410845F5
            DDEA091F1F1584D76762AB4CAC28293D0421C03C4108454BBBD5EEE345105E9F
            89AD32B1A2A4F4108400F3042114ADEE565B0F1941787D26B6CAC48A92D24310
            02CC138450B46DB7DAF4F15141787D26B6CAC48A92D2431002CC138450B479B7
            DA71EC08C2EB33B155265694941E8210609E2084A23DBBD5C30F1F41787D26B6
            CAC48A92D2431002CC138450B47FB77AE0C74705E1F599D82A132B4A4A0F4108
            304F1042D121BBD5A38E2341787D26B6CAC48A92D2431002CC13845074D46EF5
            904349105E9F89AD32B1A2A4F4108400F30421141DBB5BDDF9F15141787D26B6
            CAC48A92D2431002CC13845074F86E75CF312508AFCFC456995851527A084280
            7982108A3A76AB9B0F2B41787D26B6CAC48A92D2431002CC138450D4B75BDDF0
            F15141787D26B6CAC48A92D2431002CC138450D4BA5B5D3DBE04E1F599D82A13
            2B4A4A0F4108304F104251F76E75E9101384D76762AB4CAC28293D0421C03C41
            0845E7EC568B1F1F1584D76762AB4CAC28293D0421C03C4108753F8F828E677E
            E5581384D76762AB4CAC28293D0421C03C410875DF8E82BEA7FDDBC34D105E9F
            89AD32B1A2A4F4108400F30421ACFA772C9CF09C7F7B787E23082FC5C4569958
            51527A084280798210AE6CA90905E1A598D82A132B4A4A0F4108304F10C2C5D5
            9B50105E8A89AD32B1A2A4F4108400F30421DC42250B05E1A598D82A132B4A4A
            0F4108304F10C25DD48FD6D3EEDD81FF8289AD32B1A2A4F4108400F30421DCC8
            E06168B3BECAC456995851527A0842807982106E6764DF6CB3BECAC456995851
            527A084280798210EEE8E7F12808AFC6C456995851527A084280798210EEEBEB
            512908AFC6C456995851527A084280798210A8B0595F6562AB4CAC28293D0421
            C03C410854D8ACAF32B155265694941E8210609E20042A6CD65799D82A132B4A
            4A0F4108304F10021536EBAB4C6C95891525A5872004982708810A9BF55526B6
            CAC48A92D2431002CC13844085CDFA2A135B65624549E9210801E60942A0C266
            7D9589AD32B1A2A4F4108400F304215061B3BECAC456995851527A0842807982
            10A8B0595F6562AB4CAC28293D0421C03C410854D8ACAF32B155265694941E82
            10609E20042A6CD65799D82A132B4A4A0F4108304F10021536EBAB4C6C958915
            25A5872004982708810A9BF55526B6CAC48A92D2431002CC13844085CDFA2A13
            5B65624549E9210801E60942A0C2667D9589AD32B1A2A4F4108400F304215061
            B3BECAC456995851527A084280798210A8B0595F6562AB4CAC28293D0421C03C
            410854D8ACAF32B155265694941E8210609E20042A6CD65799D82A132B4A4A0F
            4108304F10021536EBAB4C6C95891525A5872004982708810A9BF55526B6CAC4
            8A92D2431002CC13844085CDFA2A135B65624549E9210801E60942A0C2667D95
            89AD32B1A2A4F4108400F304215061B3BECAC456995851527A084280798210A8
            B0595F6562AB4CAC28293D0421C03C410854D8ACAF32B155265694941E821060
            9E20042A6CD65799D82A132B4A4A0F4108304F10021536EBAB4C6C95891525A5
            8720042EEA6D23FD93B1880942A0C2667D9589AD32B1A2A4F41084C0B5143BF0
            9BBB2F658210A8B0595F6562AB4CAC28293D04217009DB3AF0AB5BAF668210A8
            B0595F6562AB4CAC28293D0421306C7F0AFE73EBD54C10021536EBAB4C6C9589
            1525A587200426A9C1E21C0421F061B3BECEC456995851527A0842608C1AFC24
            08810A9BF55526B6CAC48A92D2431002630E09C28C454C10021536EBAB4C6C95
            891525A587200466BC089B9875A94E10021536EBAB4C6C95891525A587200406
            A8C16F04215061B3BECAC456995851527A0842E06C7F254DCC72B48120042A6C
            D65799D82A132B4A4A0F41089CCD8BCD4F8210A8B07EAE32B155265694941E82
            10389B179B9F04215061FD5C6562AB4CAC28293D0421702AAF34BF1284408525
            749589AD32B1A2A4F41084C0A9BCD2FC4A10021596D05526B6CAC48A92D24310
            02E7F132F31741085458455799D82A132B4A4A0F41089CC7CBCC5F0421506115
            5D6562AB4CAC28293D0421701E2F337F1184408555749589AD32B1A2A4F41084
            C079BCCCFC4510021556D15526B6CAC48A92D2431002E7F132F3174108545845
            5799D82A132B4A4A0F41089CC7CBCC5F04215061155D6562AB4CAC28293D0421
            7012AF312F0842A0C242BACAC456995851527A0842E0245E635E108440858574
            9589AD32B1A2A4F41084C049BCC6BC2008810A0BE92A135B65624549E9210881
            93788D794110021516D25526B6CAC48A92D243100227F11AF38220042A2CA4AB
            4C6C95891525A58720044EE235E60541085458485799D82A132B4A4A0F41089C
            C46BCC0B8210A8B090AE32B155265694941E821038831798D7042150612D5D65
            62AB4CAC28293D042170062F30AF0942A0C25ABACAC456995851527A0842E00C
            5E605E13844085B5749589AD32B1A2A4F41084C019BCC0BC2608810A6BE92A13
            5B65624549E9210881337881794D100215D6D25526B6CAC48A92D243100267F0
            02F39A20042AACA5AB4C6C95891525A5872004DAC5BFBA7CFE829B7FA9B741F8
            79FB8210F2FC775C170FDEF8E5B4C8C45699D8E192D2431002EDE25F5DBEFE82
            DB7EAF6210BE9534557888A5BF28C52FA71526B6CAC43A24A5872004DA65BFBA
            7CFBED042150B7BA80642FA71526B6CAC49A24A5872004DA05BFBA1C52831F82
            101E69C3DA18BC9C5698D82A13EB93941E82106817FCEA220881CDFE3AF05F1C
            C8C1CB698589AD32B13E49E921088176C1AF2EFB83F0A814DCF9308011ABFBF5
            E0E5B4C8C456995893A4F4108440BBE057979D41D85183DB1E09306569BF1EBC
            9CD699D82A13EB90941E82106817FCEAB22708FB6A70C3830106D5F7EBC1CBE9
            12135B6562874B4A0F4108B40B7E751184C0218AFBF5E0E5749589AD32B16325
            A5872004DA05BFBAF8C8287094CA7E3D7839DDC0C45699D88192D2431002ED82
            5F5D042170A0B7FBF5E0E5741B135B656247494A0F4108B4BBDAABCBCFC7D317
            72DB2E01BC53CCC20E0FF47ABF7EB5E5F40A4C6C95891D22293D0421D06EC375
            904E7E244B0F6929E10EBFC143EE11B8B2176BA6CDFAAF4C6C9589ED97941E82
            1068F722784E5B820EACB8C38370F536F7DF1D70711DEB4C36135B65623B25A5
            872004CE7048F06C5EAF36DCFB8BFB1284C0090EFC68FA4398D82A13DB23293D
            04217086D9E0990AC2FAA31584C04FC595C181FFC9C45699D86649E921088133
            1CF835B9FD2780797B1DDE0D5FFCDBB9960A42E05795C5C181FF9589AD32B16D
            92D24310022799FAD468BDDCFEFDCB6D1FF27C7810F65D3F03E02EEEBBA93EE4
            8C6B4F93941E821038CFFE6C680DC2736EF6FC766A5DE7A52000DBDC3A4392D2
            43100203B655C4215F201C0CC2D9766A5AED0521007BDC344692D2431002934E
            38C559D3259504E1157E2900EEEEA63192941E821008D77415C4AF377BF2B525
            B61184005CD04D6324293D042190EF75B49CF6BD44410800DFDC344692D24310
            02F90E3FA7F68DCE28B3E1B75BA50901D8E6BE2592941E8210788A034FABBDF3
            44356716D4698BBC2C04A0EEEE0D92941E82107896433E3EBAE10B847B1E555D
            CC920EFCCA35C45799D82AD7242C4A4A0F41083CD1CE2C1484C088E25A6129F8
            6462AB247451527A0842E0A1F69C7D541002234EB8544F18135B25A18B92D243
            10028FB6ED2A85821018B1B45658103E4C6C9D842E4A4A0F4108B07692989D67
            94797B833BC5ACEAC04F7FFD0DEBAF65C4826062AB247451527A084280ED4178
            B51A3CEA5101D7F4E2430D0AE75726B64A421725A5872004627DBE7A2DBDE3B7
            F4EF772EA17D976A8859DB81AF5E7FCADD96FD27135B25A18B92D243100299EA
            5F0E5CFD08A82004A6BC5DD96CD9BF31B15512BA28293D04219069736B9D1684
            DD57728F59DE814F953F75D9B27F6562AB247451527A084220D3B6DCAA2C8982
            109852FCEC832DFB27135B25A18B92D2431002B1568BABB81EFAC8283065F387
            E15FFFE36026B64A421725A587200492755C60B778AE9A631FE19298851DF866
            E9D2A9B6EC1F26B64E421725A58720049EE5909CFBEF468E5D3C5D981EA858CA
            9B8FC76FD93F4C6C9D842E4A4A0F4108304F100215AB79B3ED479298D82A095D
            94941E8210609E20042AB6B5CAEAC5759298D82A095D94941E8210609E20042A
            36EFBC8FFDF2F38D98D82A095D94941E8210605EFDE437AFFF65CC920EFC6ACF
            5B31877FF9F9164C6C95842E4A4A8F9C277AD27F15E069DE06E1E75A2D08E1C9
            9EF9D9BC3D4C6C95842E4A4A8F9CFF6C49FF5580A711844085BC596562AB4CAC
            28293D0421C03C410854D8ACAF32B155265694941E8210609E20042A6CD65799
            D82A132B4A4A0F4108304F10021536EBAB4C6C95891525A5872004982708810A
            9BF55526B6CAC48A92D2431002CC13844085CDFA2A135B65624549E9210801E6
            0942A0C2667D9589AD32B1A2A4F4108400F304215061B3BECAC456995851527A
            084280798210A8B0595F6562AB4CAC28293D0421C03C410854FC5C011CF5AFC9
            9B559E634549E9210801E60942A0E8DB22E0A87F4D106EE0395691941E821060
            9E20048ABE2E020EF9B704E1069E631549E9210801E60942800E82902649E921
            0801E60942800E82902649E9210801E60942800E82902649E9210801E6094280
            0E82902649E9210801E60942800E82902649E9210801E60942800E82902649E9
            210801E60942800E82902649E9210801E60942800E82902649E9210801E60942
            800E82902649E9210801E60942800E82902649E9210801E60942800E82902649
            E9210801E60942800E82902649E9210801E60942800E82902649E9210801E609
            42800E82902649E9210801E60942800E82902649E9210801E60942800E829026
            49E9210801E60942800E82902649E9210801E60942800E82902649E9210801E6
            0942800E82902649E9210801E60942800E82902649E9210801E60942800E8290
            2649E9210801E60942800E82902649E9210801E60942800E82902649E9210801
            E60942800E82902649E9210801E60942800E82902649E9210801E60942800E82
            902649E9210801E60942800E82902649E9210801E60942800E82902649E92108
            01E60942800E82902649E9210801E60942800E82902649E9210801E60942800E
            82902649E9210801E60942800E82902649E9210801E60942800E82902649E921
            0801E60942800E82902649E9210801E60942800E82902649E9210801E6094280
            0E82902649E9210801E60942800E82902649E9210801E60942800E82902649E9
            210801E60942800E82902649E9210801E60942800E82902649E9210801E60942
            800E82902649E9210801E60942800E82902649E9210801E60942800E82902649
            E9210801E60942800E82902649E9210801E60942800E82902649E9210801E609
            42800E82902649E9210801E60942800E82902649E9210801E60942800E829026
            49E9210801E60942800E82902649E9210801E60942800E82902649E9210801E6
            0942800E82902649E9210801E60942800E82902649E9210801E60942800E8290
            2649E9210801E60942800E82902649E9210801E60942800E82902649E9210801
            E60942800E82902649E9210801E60942800E82902649E9210801E60942800E82
            902649E9210801E60942800E82902649E9210801E60942800E82902649E92108
            01E60942800E82902649E9210801E60942800E82902649E9210801E60942800E
            82902649E9210801E60942800E82902649E9210801E60942800E82902649E921
            0801E60942800E82902649E9210801E60942800E82902649E9210801E6094280
            0E82902649E9210801E60942800E82902649E9210801E60942800E82902649E9
            210801E60942800E82902649E9210801E60942800E82902649E9210801E60942
            800E82902649E9210801E60942800E82902649E9210801E60942800E82902649
            E9210801E60942800E82902649E9210801E60942800E82902649E9210801E609
            42800E82902649E9210801E60942800E82902649E9210801E60942800E829026
            49E9210801E60942800E82902649E9210801E60942800E82902649E9210801E6
            0942800E82902649E9210801E60942800E82902649E9210801E60942800E8290
            2649E9210801E60942800E82902649E9210801E60942800E82902649E9210801
            E60942800E82902649E9210801E60942800E82902649E9210801E60942800E82
            902649E9210801E60942800E82902649E9210801E60942800E82902649E92108
            01E60942800E82902649E9210801E60942800E82902649E9210801E60942800E
            82902649E9210801E60942800E82902649E9210801E60942800E82902649E921
            0801E60942800E82902649E9210801E60942800E82902649E9210801E6094280
            0E82902649E9210801E60942800E82902649E9210801E60942800E82902649E9
            210801E60942800E82902649E9210801E60942800E82902649E9210801E60942
            800E82902649E9210801E60942800E82902649E9210801E60942E081FE2D68AD
            0B9720A449527A08428079821078A0AF0B5AD3F225086992941E8210609E2004
            1E4810725F49E9210801E60942E0810421F795941E8210609E20041E4810725F
            49E9210801E60942E0810421F795941E8210609E2004F2FC5CAFBEAD518290FB
            4A4A0F4108304F100279DEAE6C5F0942EE25293D0421C03C4108E4590AC24FC7
            AE6382902649E9210801E6094220CFB620FC69CFCA26086992941E8210609E20
            04B21D15879F8ACB9D20A449527A084280798210788E33E35010D224293D0421
            C03C41083CD08165F8D7EA27086992941E8210609E20041EE8D7CB4E6CAEC45F
            1740414893A4F4108400F30421F040C5EB101613511072A6A4F4108400F30421
            F0407B2E4CFF6D31F491514E96941E8210609E2004E820086992941E8210609E
            2004E820086992941E8210609E2004E820086992941E8210609E2004E8200869
            92941E8210609E2004E820086992941E8210609E2004E820086992941E821060
            9E2004E820086992941E8210609E2004E820086992941E8210609E2004E82008
            6992941E8210609E20041EEB7359ABAC60FFFDE3A5854E10D224293D0421C03C
            41083CD3D735EDC50AB6B9EB04214D92D2431002CC1384C003FD5CD07E5DC45E
            AC7B6F173D414893A4F4108400F30421F0409520AC2F8FC5BB78FB235091941E
            8210609E20041EE8DB82B6FAF6E0EB1F7CF1E3964AF64B4A0F4108304F10020F
            F43608FF7A0BB1F859D30F41489BA4F4108400F30421F0406FCF28F3A2182BEF
            2E7E0842DA24A587200498270881077A1D846FDF06AC9CA15410D224293D0421
            C03C41083CD08BA2DB70BE99FA57102D95EC97941E8210609E20041E4810725F
            49E9210801E60942E081FE0AC26DD72714849C29293D0421C03C41083CD05F45
            2708B9BEA4F4108400F30421F040BF165D3DE104218392D2431002CC1384C033
            EDB9EEBC206450527A08428079821078A6CD41E83A84CC4A4A0F4108304F1002
            8FB56D591384CC4A4A0F4108304F10024FF6D7CAF6624D1384CC4A4A0F410830
            4F1002BCB82CE18B7FF9FADF0B429A24A5872004982708019614EB5110D22429
            3D0421C03C4108B0E473315C7D2FF1ED8F4045527A084280798210A08320A449
            527A084280798210A08320A449527A084280798210A08320A449527A08428079
            8210A08320A449527A084280798210A08320A449527A084280798210A08320A4
            49527A084280798210A08320A449527A0842807982106055E5528482902649E9
            210801E6094280553FD7C39F6BA020A449527A08428079821060D58BF5F0F59A
            69A964BFA4F4108400F30421C0AACACA29086992941E8210609E2004D8E0EDE2
            F92B4B25FB25A587200498270801F6582A434B25FB25A587200498270801F62B
            66A1A592FD92D2431002CC1384409EAFEBD599AB537D4585CD92D2431002CC13
            84409E2BAC574E2A4393A4F4108400F3042190E70ADFEB138434494A0F410830
            4F100279B69D02F4D3210B9A20A449527A08428079821088B4B309BFDAB6BE09
            429A24A587200498270881540736E13795154F10D224293D0421C03C4108A4FA
            B66AFD5BA60EAFC4BF563F414893A4F4108400F3042110ECD7267CFD6F560942
            4E96941E8210609E2004B2559AF0C5BFAFA877A6A592FD92D2431002CC138440
            BCD5267CFDE33F0942CE94941E8210609E20049E606713BEB8351F19E56449E9
            210801E60942E0097EAE60DDAB9620A449527A0842807982107888CADB7A4D77
            77E6FD122F293D0421C03C41083CC7BF75EC9CF54A10D224293D0421C03C4108
            D04110D224293D0421C03C4108D04110D224293D0421C03C4108D04110D22429
            3D0421C03C4108D04110D224293D0421C03C4108D04110D224293D0421C03C41
            08E4F95CAF069726414893A4F4108400F3042190E7E44B0EBE7D0CE30F862449
            E9210801E6094220CFDB203CE12D44414893A4F4108400F3042190A71E841F6D
            CB9720A449527A084280798210C823080996941E8210609E2004F208428225A5
            872004982708813CDFD6AB9F0B9420E4BE92D2431002CC1384401E4148B0A4F4
            108400F3042110E9AF25EBDF622508B9AFA4F4108400F3042110E9EDE2F64910
            722F49E9210801E609422055BD09FF39761D138434494A0F4108304F1002C156
            9BF09B3D2B9B20A449527A08428079821088B7330BBF292E7782902649E92108
            01E60942E0810E4CC4BF563F414893A4F4108400F30421F0403FCF32BA391105
            21274B4A0F4108304F10020FF4F6B2134B7D58BF054B25FB25A5872004982708
            81075ABD0EE186055010D224293D0421C03C41083CD67FCBDAB6B5EB733D7CF1
            E382902649E9210801E60942800E82902649E9210801E60942800E82902649E9
            210801E60942800E82902649E9210801E60942800E82902649E9210801E60942
            800E82902649E9210801E60942800E82902649E9210801E60942800E82902649
            E9210801E60942800E82902649E9210801E60942800E82902649E9210801E609
            42800E82902649E9210801E60942A0CFE7BAF1C0254210D224293D0421C03C41
            08F4F9B66E3C6AA1108434494A0F4108304F10027D7EAE1BCF592B04214D92D2
            431002CC1384409FBFD68D27AC1882902649E9210801E60942A0CF8B75237ED1
            108434494A0F4108304F10027D9EBC6E08429A24A5872004982708813E6F5798
            8FDCD54310D224293D0421C03C4108F4A904E147E80222086992941E8210609E
            2004FA1483F0E39435E4E48B220A429A24A5872004982708813EF520FCA76F25
            39FF8A8882902649E9210801E60942A0CF5FD7213CFFECA3E75F115110D22429
            3D0421C03C4108F47991612737E1F97926086992941E8210609E2004FABC7E5F
            EECC5545101223293D0421C03C4108F4A97C50F39CB70A05213192D2431002CC
            1384409FE237F74E684241488CA4F4108400F30421D0A77E2A97EE1546101223
            293D0421C03C4108F4593DB767DF5B8582901849E9210801E60942A0CF868B3D
            3435A1202446527A084280798210E8B3EDEA7F1DAB8D202446527A0842807982
            10E8B3E772F0C7BE5528088991941E8210609E2004FAEC09C28F439B50101223
            293D0421C03C4108F4D919841FC7AD3C82901849E9210801E60942A0CFFE20FC
            EB76566F50101223293D0421C03C4108F4392A083F7637A1202446527A084280
            798210E87360107EEC5B8504213192D2431002CC1384409F6383F0AFDBACDCB8
            202446527A084280798210E8D311841F9B9A50101223293D0421C03C4108F469
            0AC2BF6EFCC5BD08426224A5872004982708813EAD41F8B1D28482901849E921
            0801E60942A04F77107E949B50101223293D0421C03C4108F4392108FFBAA36F
            F728088991941E8210609E2004FA7C5B37CE0FB0CFFB1584C4484A0F4108304F
            1002DDFEAD1E27AC126F17B46F04217794941E8210609E2004C2D4B350107247
            49E9210801E60942204FB10905217794941E8210609E200422559A5010724749
            E9210801E6094220D8E0C225086992941E8210609E2004B2D52F5E7FC2FD5A2A
            D92F293D0421C03C4108C4FB6BF91284DC51527A08428079821078889F8B9820
            E48E92D2431002CC1384C0737C5DC7BA572D414893A4F4108400F30421400741
            4893A4F4108400F304214007414893A4F4108400F304214007414893A4F41084
            00F304214007414893A4F4108400F304214007414893A4F4108400F304214007
            414893A4F4108400F304214007414893A4F4108400F304214007414893A4F410
            8400F304214007414893A4F4108400F304214007414893A4F4108400F3042140
            07414893A4F4108400F304214007414893A4F4108400F304214007414893A4F4
            108400F304214007414893A4F4108400F304214007414893A4F4108400F30421
            4007414893A4F4108400F304214007414893A4F4108400F304214007414893A4
            F4108400F304214007414893A4F4108400F304214007414893A4F4108400F304
            214007414893A4F4108400F304214007414893A4F4108400F304214007414893
            A4F4108400F304214007414893A4F4108400F304214007414893A4F4108400F3
            04214007414893A4F4108400F304214007414893A4F4108400F3042140074148
            93A4F4108400F304214007414893A4F4108400F304214007414893A4F4108400
            F304214007414893A4F4108400F304214007414893A4F4108400F30421400741
            4893A4F4108400F304214007414893A4F4108400F304214007414893A4F41084
            00F304214007414893A4F4108400F304214007414893A4F4108400F304214007
            414893A4F4108400F304214007414893A4F4108400F304214007414893A4F410
            8400F304214007414893A4F4108400F304214007414893A4F4108400F3042140
            07414893A4F4108400F304214007414893A4F4108400F304214007414893A4F4
            108400F304214007414893A4F4108400F304214007414893A4F4108400F30421
            4007414893A4F4108400F304214007414893A4F4108400F304214007414893A4
            F4108400F304214007414893A4F4108400F304214007414893A4F4108400F304
            214007414893A4F4108400F304214007414893A4F4108400F304214007414893
            A4F4108400F304214007414893A4F4108400F304214007414893A4F4108400F3
            04214007414893A4F4108400F304214007414893A4F4108400F3042140074148
            93A4F4108400F304214007414893A4F4108400F304214007414893A4F4108400
            F304214007414893A4F4108400F304214007414893A4F4108400F30421400741
            4893A4F4108400F304214007414893A4F4108400F304214007414893A4F41084
            00F304214007414893A4F4108400F304214007414893A4F4108400F304214007
            414893A4F4108400F304214007414893A4F4108400F304214007414893A4F410
            8400F304214007414893A4F4108400F304214007414893A4F4108400F3042140
            07414893A4F4108400F304214007414893A4F4108400F304214007414893A4F4
            108400F304214007414893A4F4108400F304214007414893A4F4108400F30421
            4007414893A4F4108400F304214007414893A4F4108400F304214007414893A4
            F4108400F304214007414893A4F4108400F304214007414893A4F4108400F304
            214007414893A4F4108400F304214007414893A4F4108400F304214007414893
            A4F4108400F304214007414893A4F4108400F304214007414893A4F4108400F3
            04214007414893A4F4108400F304214007414893A4F4108400F3042140074148
            93A4F4108400F304214007414893A4F4108400F304214007414893A4F4108400
            F304214007414893A4F4108400F304214007414893A4F4108400F30421400741
            4893A4F4108400F304214007414893A4F4108400F304214007414893A4F41084
            00F304214007414893A4F4108470336FCB01C813F3620D27138434494A0F4108
            372308E181625EACE16482902649E92108E16604213C50CC8B359C4C10D22429
            3D0421DC8C2084078A79B1869309429A24A58720849B1184F040312FD6703241
            4893A4F41084703382101E28E6C51A4E26086992941E82106E4610C203C5BC58
            C3C904214D92D24310C2CD084278A098176B389920A449527A0842B81941080F
            14F3620D27138434494A0F4108372308E181625EACE16482902649E92108E166
            5E0761CC110D4FE3D0860E82902649E92108E166EC1A2192431B3A08429A24A5
            8720849BB16B84480E6DA8FBEF78291E1482902649E92108E1668EDA357EDE4E
            CC2200B72608A168E9F54B10D224293D0421DCCCFE5DA35747B820410815DF8E
            94B78786973C9A24A58720849BD9BC6BB4DD842B7384C25B1BEA4E10D224293D
            0421DCCC865D63F14A1531AB01DC912084B7FE3A4C56FF18EA8062BFA4F41084
            7033F55DE3D2150B639602B8B27F47E5863FDCFCFC91173705C1569B5010D224
            293D0421DC4C65D7B8E1E2F5314B015CD6EBEF3E6DFE5B8F8397A7596A424148
            93A4F4108470331B62EFAD9875002EEBEDAEB4188476B7F0B1D2840E199A24A5
            8720849B393608635600B8B8B7FBD73D6FFE3B9079A0E2E120086992941E8210
            6EE6A8208C39F6E12E5EEF5FDF06A11A846F2A078520A449527A0842B8999D41
            1873C8C3EDBC38785FF4DE5B0E6A9E6CDB7BEF8E1AF64B4A0F41083763D708F7
            75F877801DD7B0E1BD77070EFB25A58720847BD08190E1C0267474C33F2F9A50
            10D224293D04215C9D1484308734A1031CBE72E95D4E96941E82102E4A074230
            5F0686C3D50F2B4710FB25A5872084CBD9B3538C39A2219E3FFAC0E18A879583
            88FD92D24310C255745C711E0813F3AA0D4D2A2FA68E23F64B4A0F4108F3A420
            7088135ED3AD57F097984D351549E92108618C7D15D0A1E995DD920515315B6B
            5E4B4A0F410803F67C77C89E0C784D10C2A098AD35AF25A5872084F31C72B618
            7B32E03541088362B6D6BC96941E8210CE70E0E904EDC980D704210C8AD95AF3
            5A527A0842E875F899E5EDC980175A5FD6AD3FF05ACCBE9AB792D24310428BBE
            2B8CD99001BF3AED05DD2A043FC5ECA8294A4A0F410807EBBED8B4AD183C59CC
            AB369CE3ED8BA6638A6D92D24310C231BA3B70FF1D0119625EB8E104AE534F93
            A4F41084B0D7692908C4D8F9971DAB0714158F35C714AB92D24310C2463A10D8
            E690F7F9AD2450513FDC1C532C494A0F4108CBA420B0D9819FFAB6A4C05B4B47
            9C638ABAA4F410845075C865E581277BB18CFCB74AFCFABFFEF5FFFFFC5FA77F
            27B8B4D5C3CA314551527A084278CF5B82C07E6FBBEEAF9D6BE567815F6D38AC
            1C535424A58720E4BD7F2B66CC5365F517DFE681E3025E7BBBFB7CB173FDB022
            C126DB0E2B870C6F25A58720E48D6F6B65CC1366E9B7AE7BC87C8055957DE7B6
            7708EB2C503CD0EB20FCD0846C95941E8290577EAE92314F98E2EF5B973D1960
            A7B7BBD28FF52F3B6D63B1E251361F7A1F0E165E4A4A0F41C89F1EB53E7A4B10
            E8F6F60317C786DF0B162E9EA312841F0FDBF37088A4F41084FCE9218BA31404
            4EF3FA2BD9A705E187158CC72806E1C763B63D1C25293D0421BF8B3FA39D0E04
            AE4610C2E1EA41F8A1095991941E8290DF0507A11404AEE9CC20FCB0A6F10C4B
            41F8A109294B4A0F41C82F5E6F4A6EFA9CD181C0C5FD7A1EAFD5EDECDBDBDC76
            3B70531B8EA09D071D0F91941E82905F846D20A42070173F4F3CB37F6F1AFC89
            0F786BDB11F4CC6B6EB124293D0421DFBDCDA7BB3C677420703B5F17AE17179C
            585DA67C0A8EC7DAFC2795CF1F7498F0ABA4F410847C57E9A88B3F6DA42090E1
            C090D3843CD39EF7D8FFFB5907087F494A8F9C277AD27F9541C594BAE6D3C665
            E58130821076F285409A24A58720E4FF73D320F4962010E9D8BDAC9D310FE469
            4F93A4F41084FC9FBF16CD5F4F7C37FD60FF7CC04517F915005E1084B093A73D
            4D92D24310F27F6E1484DE12049E4010C24E9EF634494A0F41C8FF7AB1625E27
            08BD25083CC7E1DFFAB333E6813CED6992941E8290FFB514841FA72FA6DE1204
            9EE6F0B5F70A8B399CCCD39E2649E92108F91FAF97CBD9C5540A02CF74C2E745
            F7DC20DC8220A449527A0842FEC705835007020FE70B84B09F673E4D92D24310
            F27EAD3C79319582001F87AEBDF6C43C96273F4D92D24310525A2B4F38AF8C0E
            04F8EAA88DAC0F8BF264D739311E6192D243103E5D71C3D1BA9E4A41806FBADF
            1EDC7C6B703BDF0E01CF7C0E91941E82F0E96683705B0AC63C6901FED2FDF6E0
            B65B833BFA7A1478DA7394A4F410848F56DF70747C047F430DC63C5D015E3B64
            D55583004D92D243103E5AFD7DBFF1208C79A20254EC5F75D520409FA4F41084
            CFB5B4DB38E7FAC8C7DE05C07D6D5B752B4BAB751560BFA4F41084CFB5F4B5C0
            F38330E69909B06AF3A9B6DEB2B4021C22293D04E1436D08BCC3CF2BE3D24000
            BF1284001797941E82F0A136D45DF78946639E8A003B7504A13516E04049E921
            089FE8C0AFA6C43C7F00AEE3F020B456031C2B293D04E1136D7BAF4F10029CE3
            C020B44A0374484A0F41F8389BBB4E10029C637F105A9C015A25A587207C9CCD
            5F0514840027B0D8025C5F527A08C267D9B3CFB0470138C1D316DBAFBFEFFE5F
            F3D85B03F84B527A08C26771A202808B7B7210EEFC4D0FBC2980D792D243103E
            88F398035CDFA382500D023795941E82F0419AAE741CF31402B80241B8FF76F6
            DC144045527A08C2A768AAC10F2FBA008712847B6E61CF4D01D425A587207C0A
            4108707D8FAAC18FDD41F8E2A52D7868C01524A587207C84BE1AFCF0A20B709C
            4705615F0D6EB835802549E921081F411002DC8220DCF6B33FA50E0DB888A4F4
            1084F98EDD5E9CF9C5FDFDDF0CB9FE49E75C320BF84A106EF8C17F3F7BFD051F
            4892941E82305F7710EEB9B5D53B5ABABB5B9C74CE0E06F84A106EFE417F5F03
            CE94941E8230DCE17B8B13362B877C10480D02772408577FF0F3A7042170A6A4
            F41084E1F282F0ED7DDDE814E48210F8EAFA3578C8795C96BED6FEEB6D7EDEC2
            D7FF551002674A4A0F4198AC636FD1BD5FD9F9CEDEBD4E412E0881AF2E1E84C5
            907BFD80574F72B6F36D43802649E92108930504E181279DBBE0535D10025F5D
            36080FACB8A620B49C02274B4A0F4118AB6963D1BA5F79D429C86D5F806FAE19
            84DB2E5CF4D7C3DEFF79D1CACD8E0F0D8897941E8230D6A382F07635B8E79705
            52DD2508BF3DA40D1FF53F7C01F47951E06449E9210833F5ED2A5A4FD972E029
            C8AF9F5BD77F84C0C96E11846FDFFADB7022684108DC4E527A08C24C4F0EC29F
            17A43AEAE11DEBFA8F1038D9F58370FCF320673E48801792D24310666ABD0ADF
            3997B258BA8B9F7F99EECEADA5BF851FFBCB02A92E7801D5A6B5F4D89BF5F735
            E07C49E92108339D1C8427D4E0EA1DB5FEF979CFC36BFA7D810C9BFFD8D4FD78
            3ECD7E1EE4845B03A8484A0F4198ECDF6B64D37FE2A36EBC23900EDFC11CF520
            FB2EC005D0E4842B185DEAD6002A92D2431032EC84203CB3063F042190E5C5C2
            B5798D1284C0DD25A587206458BD91463E2F7AEC05B89A7E5F8056AF17AE9D5F
            A5764619E08E92D24310720997FD6BF1DB9BDAF6F154DB17E05E0EBCDCAB2004
            0224A58720E412EE1B84DFFED9860FB5C61C8340B6A6736B5D67C107A84B4A0F
            41C8255C767FD0546E8210B8A9FD1F1FBDEC820F5097941E82904B38FF3DBD0D
            B7260801FED973A619410804484A0F41C825DC2208F7DFDAAF371B730C024FB3
            ED8A14B758A5015E4B4A0F41C8251C1848275C73E2528F1060D6D2B9B59C5106
            C890941E82907957FE6B71F705B8620E40E0C9EA0BEF95177C80BAA4F41084CC
            BBF8FEE0D80B707D0842E03EFE5BAF8EBD94CEC5177C80A2A4F41084CCBBEC17
            08FFBAD99F96EE481002D7D7F4A69F20043224A5872064DE65BF40F8FAC67F3A
            FF7CEB004D2A571DFCC919658087484A0F41C8BCBB04E1AF77B17A77B62FC02D
            0842801792D2431032EF5E41F8EB1DD5EFD1F605B8850D41E8AAF4C07324A587
            2064DE1D83F0D7BBABDCA9ED0B70174B4D585CCD8EFD12B5AF64035392D24310
            32ECEE7F2D5EBA00D787ED0B7043075E804710021992D2431032ECBE6F0F6EB8
            5F6F0F020004484A0F41C8B0CB06E1BF5BBBF205B800001891941E829061D70C
            C2E24DEDF9BCE8FEDF1700801149E92108193612849FFFB25E7A154E310A00F0
            0449E9210819361B847FFD33410800C05F92D2431032ECFC20ACFCB35B5C800B
            00801149E921081976CD20FCF55FFEA5FEB00521004080A4F410840CAB9FCCF3
            905BDB96647F95E1E60B70C51C7700000F94941E829067F11E1D00003B25A587
            20E4590EFC842A0000CF94941E829007F1F6200000FB25A58720E441BC3D0800
            C07E49E92108790A6F0F02007088A4F410843C85200400E01049E92108799063
            2F710100C03325A587200400005890941E821000006041527A08420000800549
            E921080100001624A587200400005890941E821000006041527A084200008005
            49E921080100001624A587200400005890941E821000006041527A0842000080
            0549E921080100001624A587200400005890941E821000006041527A08420000
            800549E921080100001624A54754104E3F040000E0116282F0FF01D66D3B0E40
            79DC960000000049454E44AE426082}
          Stretch = True
        end
        object pg_ctrl_geom_char: TPageControl
          Left = 258
          Top = 3
          Width = 426
          Height = 393
          ActivePage = tb_sht_composite_geom_char
          TabOrder = 0
          object tb_sht_composite_geom_char: TTabSheet
            Caption = #1050#1086#1084#1087#1086#1079#1080#1090#1085#1086#1077' '#1089#1077#1095#1077#1085#1080#1077
            object strng_grd_compos_sect_geom_character: TStringGrid
              Left = 0
              Top = 0
              Width = 418
              Height = 365
              Align = alClient
              Color = clWhite
              ColCount = 2
              DefaultColWidth = 100
              DrawingStyle = gdsClassic
              RowCount = 9
              ScrollBars = ssNone
              TabOrder = 0
              OnDrawCell = strng_grd_rendering
              ColWidths = (
                304
                254)
              RowHeights = (
                24
                24
                24
                24
                24
                24
                24
                24
                24)
            end
          end
          object tb_sht_steel_geom_char: TTabSheet
            Caption = #1057#1090#1072#1083#1100#1085#1086#1077' '#1089#1077#1095#1077#1085#1080#1077
            ImageIndex = 2
            object strng_grd_steel_sect_geom_character: TStringGrid
              Left = 0
              Top = 0
              Width = 418
              Height = 365
              Align = alClient
              ColCount = 2
              DrawingStyle = gdsClassic
              RowCount = 7
              TabOrder = 0
              OnDrawCell = strng_grd_rendering
              ColWidths = (
                307
                366)
              RowHeights = (
                24
                24
                24
                24
                24
                24
                24)
            end
          end
          object tb_sht_concrete_geom_char: TTabSheet
            Caption = #1046#1077#1083#1077#1079#1086#1073#1077#1090#1086#1085#1085#1086#1077' '#1089#1077#1095#1077#1085#1080#1077
            ImageIndex = 1
            object strng_grd_concrete_sect_geom_character: TStringGrid
              Left = 0
              Top = 0
              Width = 418
              Height = 365
              Align = alClient
              ColCount = 2
              DrawingStyle = gdsClassic
              RowCount = 6
              TabOrder = 0
              OnDrawCell = strng_grd_rendering
              ColWidths = (
                305
                361)
            end
          end
        end
      end
    end
    object tb_results: TTabSheet
      Caption = #1056#1077#1079#1091#1083#1100#1090#1072#1090#1099' '#1088#1072#1089#1095#1105#1090#1072
      ImageIndex = 2
      object strng_grd_results: TStringGrid
        Left = 0
        Top = 0
        Width = 1054
        Height = 442
        Align = alTop
        ColCount = 2
        DefaultColWidth = 200
        DrawingStyle = gdsClassic
        ScrollBars = ssNone
        TabOrder = 0
        OnDrawCell = strng_grd_rendering
        ColWidths = (
          513
          349)
      end
    end
  end
  object btn_logger: TButton
    Left = 259
    Top = 561
    Width = 75
    Height = 25
    Caption = #1051#1086#1075
    TabOrder = 6
    OnClick = btn_loggerClick
  end
  object MainMenu1: TMainMenu
    Images = ImageList1
    Left = 744
    Top = 560
    object NFile: TMenuItem
      Caption = #1060#1072#1081#1083
      object NNew: TMenuItem
        Caption = #1053#1086#1074#1099#1081' '#1087#1088#1086#1077#1082#1090
        Hint = #1053#1086#1074#1099#1081' '#1087#1088#1086#1077#1082#1090' '
        ImageIndex = 0
        OnClick = NNewClick
      end
      object NOpen: TMenuItem
        Caption = #1054#1090#1082#1088#1099#1090#1100
        Hint = #1054#1090#1082#1088#1099#1090#1100' '#1092#1072#1081#1083' '#1087#1088#1086#1077#1082#1090#1072' '#1050#1086#1084#1073#1080#1085#1080#1088#1086#1074#1072#1085#1085#1072#1103' '#1073#1072#1083#1082#1072
        ImageIndex = 1
        ShortCut = 16463
        OnClick = NOpenClick
      end
      object NSave: TMenuItem
        Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
        Hint = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1092#1072#1081#1083' '#1087#1088#1086#1077#1082#1090#1072' '#1050#1086#1084#1073#1080#1085#1080#1088#1086#1074#1072#1085#1085#1072#1103' '#1073#1072#1083#1082#1072
        ImageIndex = 2
        ShortCut = 16467
        OnClick = NSaveClick
      end
      object NSaveAs: TMenuItem
        Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1082#1072#1082
        Hint = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1092#1072#1081#1083' '#1087#1088#1086#1077#1082#1090#1072' '#1087#1086#1076' '#1076#1088#1091#1075#1080#1084' '#1080#1084#1077#1085#1077#1084
        ImageIndex = 3
        OnClick = NSaveAsClick
      end
      object NOutReport: TMenuItem
        Caption = #1042#1099#1074#1086#1076' '#1086#1090#1095#1105#1090#1072
        Hint = #1042#1099#1074#1086#1076' '#1086#1090#1095#1077#1090#1072' '#1074' '#1092#1086#1088#1084#1072#1090#1077' Word'
        ImageIndex = 4
        OnClick = NOutReportClick
      end
      object N2: TMenuItem
        Caption = '-'
      end
      object NExit: TMenuItem
        Caption = #1042#1099#1093#1086#1076
        Hint = #1042#1099#1093#1086#1076
        OnClick = NExitClick
      end
    end
    object N3: TMenuItem
      Caption = #1057#1087#1088#1072#1074#1082#1072
      object N8: TMenuItem
        Caption = #1054' '#1087#1088#1086#1075#1088#1072#1084#1084#1077
      end
    end
  end
  object SaveDialog_Model: TSaveDialog
    DefaultExt = 'arcC'
    Filter = #1060#1072#1081#1083' '#1087#1088#1086#1077#1082#1090#1072' (*.arsC)|*.arsC'
    Options = [ofOverwritePrompt, ofHideReadOnly, ofEnableSizing]
    Left = 788
    Top = 560
  end
  object OpenDialog_Model: TOpenDialog
    Filter = #1060#1072#1081#1083#1099' '#1087#1088#1086#1077#1082#1090#1086#1074' (*.arsC)|*.arsC|'#1042#1089#1077' '#1092#1072#1081#1083#1099' |*.*'
    Left = 844
    Top = 560
  end
  object ImageList1: TImageList
    Left = 904
    Top = 560
    Bitmap = {
      494C010106000900040010001000FFFFFFFFFF10FFFFFFFFFFFFFFFF424D3600
      0000000000003600000028000000400000002000000001002000000000000020
      000000000000000000000000000000000000000000000080800000FFFF0000FF
      FF0000FFFF0000FFFF0000FFFF00008080000000000000000000000000000000
      0000000000000000000000000000F0FBFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000008080000000000000FFFF000080
      8000000000000080800000FFFF00000000000080800080404000804040008040
      400080404000F0FBFF00F0FBFF00F0FBFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000008080
      8000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000080800000FFFF0000FFFF000000
      0000808080000000000000FFFF0000FFFF0000808000C0A0A000C0A0A000C0A0
      A00080404000F0FBFF00F0FBFF00F0FBFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000008000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000008080000000000000FFFF000080
      8000000000000080800000FFFF000080800000808000F0CAA600F0CAA600F0CA
      A60080404000F0FBFF00F0FBFF00F0FBFF000000000000000000808000008080
      0000808000000000000000000000000000000000000000000000000000008000
      0000808080008080800080000000808080000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000080800000FFFF0000FF
      FF0000FFFF0000FFFF0000FFFF0000808000F0CAA600F0CAA600F0CAA600F0CA
      A60080404000F0FBFF00F0FBFF00F0FBFF000000000080800000000000000000
      0000000000008080000000000000000000000000000000000000000000008000
      0000000000008000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000808000008080000000
      000000FFFF00000000000080800000808000F0CAA600F0CAA600F0CAA600F0CA
      A60080404000F0FBFF00F0FBFF00F0FBFF000000000080800000000000000000
      0000808000008080000000000000000000000000000000000000000000008000
      0000000000008000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000C0A0A000000000000080
      800000808000008080008080800080808000A4A0A000A4A0A00080A0A000F0CA
      A60080404000F0FBFF00F0FBFF00F0FBFF000000000080800000000000000000
      0000000000000000000000000000000000000000000000000000000000008000
      0000000000008000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000C0A0A000000000000000
      0000F0FBFF00A4A0A0008080800080808000C0C0C000C0C0C0008060600080A0
      A00080404000F0FBFF00F0FBFF00F0FBFF000000000080800000000000000000
      0000000000008080000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000C0C0A000000000008040
      400080404000C0DCC00080808000C0DCC00040606000F0FBFF00A4A0A0008080
      800080404000F0FBFF00F0FBFF00F0FBFF000000000000000000808000008080
      0000808000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000C0C0A000000000000000
      000000000000C0DCC00080808000C0DCC000F0FBFF0040606000C0C0C0004040
      600080808000F0FBFF00F0FBFF00F0FBFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000C0C0A000000000000000
      000000000000F0FBFF00C0C0C000A4A0A000C0C0C000F0FBFF00C0DCC000A4A0
      A0004020200080808000F0FBFF00F0FBFF000000000000000000000000000000
      0000000000000000000000008000000080000000800000008000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000C0C0C000000000008040
      4000804040008040400080404000C0C0C000A4A0A000A4A0A000A4A0A0008060
      4000804020004020200080808000F0FBFF000000000000000000000000000000
      0000000000000000000000008000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000C0C0C000000000000000
      00000000000000000000000000000000000000000000A4A0A00080806000C0C0
      A000C0A060008040200040202000808080000000000000000000000000000000
      0000000000000000000000008000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000F0CAA600000000000000
      00000000000000000000000000000000000000000000F0FBFF0080806000C0A0
      6000F0FBFF00C080600080402000402000000000000000000000000000000000
      0000000000000000000000008000000080000000800000008000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA6008080
      6000C0A06000F0FBFF00C0A06000806020000000000000000000000000000000
      0000000000000000000000008000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000F0FBFF00F0FBFF00F0FBFF00F0FB
      FF00F0FBFF00F0FBFF00F0FBFF00F0FBFF00F0FBFF00F0FBFF00F0FBFF00F0FB
      FF0080806000C0A06000F0CAA600C0A060000000000000000000000000000000
      0000000000000000000000008000000080000000800000008000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000C0A0
      A000804040008040400080404000804040008040400080404000804040008040
      4000804040008040400000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000C0A0A000C0606000C060
      6000C0606000C0606000C0606000804060008040400080404000804040008040
      40008040400080404000804040000000000000000000C0A0A000C0606000C060
      6000C0606000C0606000C0606000804060008040400080404000804040008040
      400080404000804040008040400000000000000000000000000000000000C0A0
      A000FFFFFF00C0A0A000C0A0A000C0A0A000C0A0A000C0A0A000C0A0A000C0A0
      A000C0A0A0008040400000000000000000008080A0008080A000808080004080
      8000406080004060600040406000404040004040400040204000002040000000
      00000020400000000000000000000000000000000000C0608000C0A0A000C080
      8000C0604000404020000000000000000000C0C0C000C0C0C000406060008040
      4000C0404000C0404000804040000000000000000000C0608000C0A0A000C080
      8000C060400040402000C0C0C000C0C0C000C0C0C000C0C0C000406060008040
      4000C0404000C04040008040400000000000000000000000000000000000C0A0
      A000FFFFFF00FFFFFF0000000000000000000000000000000000000000000000
      0000C0A0A0008040400000000000000000008080A00080A0C00080A0E00040A0
      E00000A0E00000A0E00000A0E00000A0C0000080C0000080C0000080A0000080
      80004040600000000000000000000000000000000000C0808000F0CAA600C080
      8000C0806000806060000000000000000000F0FBFF00F0FBFF00808080008040
      4000C0404000C0404000804040000000000000000000C0808000F0CAA600C080
      8000C0806000806060004040400080808000F0FBFF00F0FBFF00808080008040
      4000C0404000C04040008040400000000000000000000000000000000000C0A0
      A000FFFFFF00FFFFFF0000000000000000000000000000000000000000000000
      0000C0A0A0008040400000000000000000008080A00080C0C00080A0C00080C0
      E00040C0E00040C0E00040C0E00040C0E00040A0E00040A0E00040A0E0000080
      A0004080800080606000000000000000000000000000C0808000F0CAA600F0CA
      A600C0808000806060000000000000000000F0CAA600F0FBFF0080806000C040
      4000C0404000C0406000804040000000000000000000C0808000F0CAA600F0CA
      A600C0808000806060000000000040404000F0CAA600F0FBFF0080806000C040
      4000C0404000C04060008040400000000000000000000000000000000000C0A0
      A000FFFFFF00FFFFFF00FFFFFF00000000000000000000000000000000000000
      0000C0A0A00080404000000000000000000080A0A00080C0C00080A0C00080C0
      E00080C0E00080C0E00040E0E00040C0E00040C0E00040C0E00040C0E00040A0
      E0004080C00040406000000000000000000000000000C0808000F0CAA600F0CA
      A600C0A0A000806060008060600080606000806060008060600080606000C060
      6000C0604000C0606000804040000000000000000000C0808000F0CAA600F0CA
      A600C0A0A000806060008060600080606000806060008060600080606000C060
      6000C0604000C06060008040400000000000000000000000000000000000C0A0
      A000FFFFFF00FFFFFF00FFFFFF00000000000000000000000000000000000000
      0000C0A0A00080404000000000000000000080A0A00080C0E00080C0C00080A0
      C00080C0E00080E0E00080E0E00080E0E00040E0E00040C0E00040C0E00040C0
      E00040A0E00040608000808080000000000000000000C0808000F0CAA600F0CA
      A600C0A0A000C0808000C0808000C0808000C0806000C0606000C0606000C060
      4000C0604000C0606000804040000000000000000000C0808000F0CAA600F0CA
      A600C0A0A000C0808000C0808000C0808000C0806000C0606000C0606000C060
      4000C0604000C06060008040400000000000000000000000000000000000C0A0
      A000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000000000000000
      0000C0A0A00080404000000000000000000080A0A00080E0E00080C0E00080A0
      C00080C0C00080E0E00080E0E00080E0E00080E0E00080E0E00040E0E00040C0
      E00040C0E00040A0E000406080000000000000000000C080A000F0CAA600F0CA
      A600C0606000C0606000C0606000C0604000C0604000C0404000C0402000C040
      2000C0604000C0606000804040000000000000000000C080A000F0CAA600F0CA
      A600C0606000C0606000C0606000C0604000C0604000C0404000C0402000C040
      2000C0604000C06060008040400000000000000000000000000000000000C0A0
      A000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000
      0000C0A0A00080404000000000000000000080A0A00080E0E00080E0E00080C0
      E00080A0C00080E0E00080E0E00080E0E00080E0E00080E0E00080E0E00080E0
      E00080E0E00040C0E00040A0E0008080800000000000C0A0A000F0CAA600C060
      6000F0FBFF00F0FBFF00F0FBFF00F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600C0402000C0606000804060000000000000000000C0A0A000F0CAA600C060
      6000F0FBFF00F0FBFF00F0FBFF00F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600C0402000C06060008040600000000000000000000000000000000000C0A0
      A000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000
      0000C0A0A000804040000000000000000000A4A0A00080E0E00080E0E00080E0
      E00080C0C00080C0C00080A0C00080A0C00080A0C00080A0C00080A0A00080A0
      A00080A0A00080A0A0008080A0008080A00000000000C0A0A000F0CAA600C080
      8000FFFFFF00400000004000000040000000400000004000000040000000F0CA
      A600C0402000C0606000C06060000000000000000000C0A0A000F0CAA600C080
      8000FFFFFF00F0FBFF00F0FBFF00F0FBFF00F0CAA600F0CAA600F0CAA600F0CA
      A600C0402000C0606000C060600000000000000000000000000000000000C0A0
      A000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00C0A0
      A000C0A0A00080404000000000000000000080A0C00080E0E00080E0E00080E0
      E00080E0E00080C0E00080C0E00080C0C00080C0C00080C0C00080C0C00080C0
      C0008080A00000000000000000000000000000000000F0CAA600F0CAA600C080
      8000FFFFFF00FFFFFF00F0FBFF00F0FBFF00F0FBFF00F0CAA600F0CAA600F0CA
      A600C0404000C0606000C06060000000000000000000F0CAA600F0CAA600C080
      8000FFFFFF00FFFFFF00F0FBFF00F0FBFF00F0FBFF00F0CAA600F0CAA600F0CA
      A600C0404000C0606000C060600000000000000000000000000000000000C0A0
      A000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00C0A0A0008040
      40008040400080404000000000000000000080A0C00080E0E00080E0E00080E0
      E00080E0E00080E0E00080C0E00080A0C00080A0C00080A0C00080A0C00080A0
      C00080A0C00000000000000000000000000000000000F0CAA600F0CAA600C080
      8000FFFFFF00400000004000000040000000400000004000000040000000F0CA
      A600C0604000C0606000C06060000000000000000000F0CAA600F0CAA600C080
      8000FFFFFF00FFFFFF00FFFFFF00F0FBFF00F0FBFF00F0FBFF00F0CAA600F0CA
      A600C0604000C0606000C060600000000000000000000000000000000000C0A0
      A000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00C0A0A000C0C0
      C00080404000C0C0C000000000000000000080A0C00080E0E00080E0E00080E0
      E00080E0E00080E0E00080A0C000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000F0CAA600F0CAA600C080
      A000FFFFFF00FFFFFF00FFFFFF00FFFFFF00F0FBFF00F0FBFF00F0FBFF00F0CA
      A600C0604000C0404000C06060000000000000000000F0CAA600F0CAA600C080
      A000FFFFFF00FFFFFF00FFFFFF00FFFFFF00F0FBFF00F0FBFF00F0FBFF00F0CA
      A600C060400080404000C060600000000000000000000000000000000000C0A0
      A000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00C0A0A0008040
      4000C0C0C0000000000000000000000000000000000080A0C00080A0C00080A0
      C00080A0C00080A0C00000000000000000000000000000000000000000000000
      000000000000C0C0C000000000000000000000000000F0CAA600F0CAA600F0CA
      A600FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00F0FBFF00F0FBFF00F0FB
      FF00C0606000C0606000C06060000000000000000000F0CAA600F0CAA600F0CA
      A600FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00F0FBFF00F0FBFF00F0FB
      FF00C0606000C0606000C060600000000000000000000000000000000000C0A0
      A000C0A0A000C0A0A000C0A0A000C0A0A000C0A0A000C0A0A000C0A0A000C0C0
      C000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600C0A0A000C0A0A000C0A0A000C080A000C080
      8000C0808000C0808000C08080000000000000000000F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600C0A0A000C0A0A000C0A0A000C080A000C080
      8000C0808000C0808000C0808000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000424D3E000000000000003E000000
      2800000040000000200000000100010000000000000100000000000000000000
      000000000000000000000000FFFFFF0080FEFFFF000000000000FFEF00000000
      0000FFEF000000000000C7E0000000008000BBEB000000008000B3EB00000000
      A000BFEB00000000B000BBFF00000000A000C7FF00000000B800FFFF00000000
      B800FC3F00000000A000FDFF00000000BF80FDFF00000000BF80FC3F00000000
      8000FDFF000000000000FC3F00000000FFFFFFFFFFFFFFFFE003FFFF80018001
      E003000783018001E3F3000783018001E3F3000383018001E1F3000380018001
      E1F3000180018001E073000180018001E033000080018001E013000080018001
      E003000780018001E003000780018001E00301FF80018001E00783FB80018001
      E00FFFFF80018001FFFFFFFFFFFFFFFF00000000000000000000000000000000
      000000000000}
  end
  object OpenDialog1: TOpenDialog
    Filter = 'arcC|arcC'
    InitialDir = 'arcC'
    Left = 688
    Top = 560
  end
end
