object CompositeBeamMainForm: TCompositeBeamMainForm
  Left = 0
  Top = 0
  HorzScrollBar.Visible = False
  VertScrollBar.Visible = False
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = #1050#1086#1084#1073#1080#1085#1080#1088#1086#1074#1072#1085#1085#1072#1103' '#1073#1072#1083#1082#1072
  ClientHeight = 639
  ClientWidth = 1072
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
  object lbl_max_elem_length: TLabel
    Left = 699
    Top = 605
    Width = 294
    Height = 13
    Caption = #1052#1072#1082#1089#1080#1084#1072#1083#1100#1085#1086#1077' '#1088#1072#1089#1089#1090#1086#1103#1085#1080#1077' '#1084#1077#1078#1076#1091' '#1088#1072#1089#1095#1105#1090#1085#1099#1084#1080' '#1089#1077#1095#1077#1085#1080#1103#1084#1080':'
  end
  object ToolBar1: TToolBar
    Left = 0
    Top = 0
    Width = 1072
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
  object edt_max_elem_length: TEdit
    Left = 999
    Top = 601
    Width = 42
    Height = 21
    ParentShowHint = False
    ShowHint = True
    TabOrder = 1
    OnClick = OnControlsChange
  end
  object BtnCalculate: TButton
    Left = 8
    Top = 599
    Width = 75
    Height = 25
    Caption = #1056#1072#1089#1095#1105#1090
    TabOrder = 2
    OnClick = BtnCalculateClick
  end
  object btn_report: TButton
    Left = 88
    Top = 599
    Width = 75
    Height = 25
    Caption = #1054#1090#1095#1105#1090
    TabOrder = 3
    OnClick = btn_reportClick
  end
  object BtBtnExit: TBitBtn
    Left = 169
    Top = 599
    Width = 75
    Height = 25
    Caption = #1042#1099#1093#1086#1076
    TabOrder = 4
    OnClick = BtBtnExitClick
  end
  object PgCntrlCompositeBeam: TPageControl
    Left = 0
    Top = 23
    Width = 1072
    Height = 563
    ActivePage = TbShtStaticScheme
    Align = alTop
    TabOrder = 5
    object TbShtStaticScheme: TTabSheet
      AlignWithMargins = True
      Caption = #1056#1072#1089#1095#1105#1090#1085#1072#1103' '#1089#1093#1077#1084#1072
      object GrpBxLoadsSafetyFactors: TGroupBox
        Left = 594
        Top = 3
        Width = 251
        Height = 239
        Caption = '  '#1050#1086#1101#1092#1092#1080#1094#1080#1077#1085#1090#1099' '#1085#1072#1076#1105#1078#1085#1086#1089#1090#1080' '#1087#1086' '#1085#1072#1075#1088#1091#1079#1082#1072#1084'  '
        TabOrder = 0
        object lbl_gamma_f_DL_I: TLabel
          Left = 15
          Top = 122
          Width = 107
          Height = 13
          Caption = #1052#1086#1085#1090#1072#1078#1085#1072#1103' '#1085#1072#1075#1088#1091#1079#1082#1072
        end
        object lbl_gamma_f_DL_II: TLabel
          Left = 15
          Top = 160
          Width = 112
          Height = 13
          Caption = #1055#1086#1089#1090#1086#1103#1085#1085#1072#1103'  '#1085#1072#1075#1088#1091#1079#1082#1072
        end
        object Label2: TLabel
          Left = 15
          Top = 22
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
          Left = 15
          Top = 141
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
          Left = 15
          Top = 187
          Width = 106
          Height = 13
          Caption = #1042#1088#1077#1084#1077#1085#1085#1072#1103'  '#1085#1072#1075#1088#1091#1079#1082#1072
        end
        object lbl_gamma_f_st_SW: TLabel
          Left = 15
          Top = 41
          Width = 120
          Height = 13
          Caption = #1057#1086#1073#1089#1090#1074#1077#1085#1085#1099#1081' '#1074#1077#1089' '#1089#1090#1072#1083#1080
        end
        object lbl_gamma_f_concrete_SW: TLabel
          Left = 15
          Top = 68
          Width = 124
          Height = 13
          Caption = #1057#1074#1077#1078#1077#1091#1083#1086#1078#1077#1085#1085#1099#1081' '#1073#1077#1090#1086#1085
        end
        object lbl_gamma_f_add_concrete_SW: TLabel
          Left = 12
          Top = 95
          Width = 134
          Height = 13
          Caption = #1044#1086#1087'. '#1085#1072#1075#1088'. '#1086#1090' '#1074#1077#1089#1072' '#1073#1077#1090#1086#1085#1072
        end
        object edt_gamma_f_DL_I: TEdit
          Left = 187
          Top = 118
          Width = 52
          Height = 21
          TabOrder = 0
          OnChange = OnControlsChange
        end
        object edt_gamma_f_DL_II: TEdit
          Left = 187
          Top = 156
          Width = 52
          Height = 21
          TabOrder = 1
          OnChange = OnControlsChange
        end
        object edt_gamma_f_LL: TEdit
          Left = 187
          Top = 183
          Width = 52
          Height = 21
          TabOrder = 2
          OnChange = OnControlsChange
        end
        object edt_gamma_f_st_SW: TEdit
          Left = 187
          Top = 37
          Width = 52
          Height = 21
          TabOrder = 3
          OnChange = OnControlsChange
        end
        object edt_gamma_f_concrete_SW: TEdit
          Left = 187
          Top = 64
          Width = 52
          Height = 21
          TabOrder = 4
          OnChange = OnControlsChange
        end
        object edt_gamma_f_add_concrete_SW: TEdit
          Left = 187
          Top = 91
          Width = 52
          Height = 21
          TabOrder = 5
          OnChange = OnControlsChange
        end
      end
      object grp_bx_load_cases: TGroupBox
        Left = 314
        Top = 3
        Width = 274
        Height = 239
        Caption = '  '#1053#1086#1088#1084#1072#1090#1080#1074#1085#1099#1077' '#1079#1072#1075#1088#1091#1078#1077#1085#1080#1103'  '
        TabOrder = 1
        object lbl_dead_load_first_stage: TLabel
          Left = 16
          Top = 118
          Width = 149
          Height = 13
          Caption = #1052#1086#1085#1090#1072#1078#1085#1072#1103'  '#1085#1072#1075#1088#1091#1079#1082#1072',  '#1082#1053'/'#1084'2'
        end
        object lbl_dead_load_second_stage: TLabel
          Left = 16
          Top = 155
          Width = 148
          Height = 13
          Caption = #1055#1086#1089#1090#1086#1103#1085#1085#1072#1103'  '#1085#1072#1075#1088#1091#1079#1082#1072', '#1082#1053'/'#1084'2'
        end
        object Label9: TLabel
          Left = 16
          Top = 22
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
          Top = 137
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
          Top = 182
          Width = 142
          Height = 13
          Caption = #1042#1088#1077#1084#1077#1085#1085#1072#1103'  '#1085#1072#1075#1088#1091#1079#1082#1072', '#1082#1053'/'#1084'2'
        end
        object lbl_SW_add_concrete: TLabel
          Left = 16
          Top = 91
          Width = 173
          Height = 13
          Caption = #1044#1086#1087'. '#1085#1072#1075#1088'. '#1086#1090' '#1074#1077#1089#1072' '#1073#1077#1090#1086#1085#1072',  '#1082#1053'/'#1084'2'
        end
        object lbl_SW_conc: TLabel
          Left = 16
          Top = 64
          Width = 159
          Height = 13
          Caption = #1042#1077#1089' '#1089#1074#1077#1078#1077#1091#1083#1086#1078'. '#1073#1077#1090#1086#1085#1072',  '#1082#1053'/'#1084'2'
        end
        object lbl_SW_steel_beam: TLabel
          Left = 16
          Top = 38
          Width = 133
          Height = 13
          Caption = #1042#1077#1089' '#1089#1090#1072#1083#1100#1085#1086#1081' '#1073#1072#1083#1082#1080',  '#1082#1053'/'#1084
        end
        object edt_dead_load_first_stage: TEdit
          Left = 213
          Top = 114
          Width = 52
          Height = 21
          TabOrder = 0
          OnChange = OnControlsChange
        end
        object edt_dead_load_second_stage: TEdit
          Left = 213
          Top = 151
          Width = 52
          Height = 21
          TabOrder = 1
          OnChange = OnControlsChange
        end
        object edt_live_load: TEdit
          Left = 213
          Top = 178
          Width = 52
          Height = 21
          TabOrder = 2
          OnChange = OnControlsChange
        end
        object edt_SW_add_concrete: TEdit
          Left = 211
          Top = 87
          Width = 52
          Height = 21
          TabOrder = 3
          OnChange = OnControlsChange
        end
        object btn_add_impacts: TButton
          Left = 16
          Top = 206
          Width = 249
          Height = 25
          Caption = #1044#1086#1087#1086#1083#1085#1080#1090#1077#1083#1100#1085#1099#1077' '#1074#1086#1079#1076#1077#1081#1089#1090#1074#1080#1103
          TabOrder = 4
          OnClick = btn_add_impactsClick
        end
        object edt_SW_conc: TEdit
          Left = 213
          Top = 60
          Width = 52
          Height = 21
          Enabled = False
          TabOrder = 5
          Text = '0'
          OnChange = OnControlsChange
        end
        object edt_SW_steel_beam: TEdit
          Left = 213
          Top = 33
          Width = 52
          Height = 21
          Enabled = False
          TabOrder = 6
          Text = '0'
          OnChange = OnControlsChange
        end
      end
      object GrpBxTopology: TGroupBox
        Left = 3
        Top = 3
        Width = 305
        Height = 239
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
          Width = 158
          Height = 13
          Caption = #1056#1072#1089#1089#1090#1086#1103#1085#1080#1077' '#1076#1086' '#1073#1072#1083#1082#1080' '#1089#1083#1077#1074#1072', '#1084#1084
        end
        object lbl_trib_width_right: TLabel
          Left = 17
          Top = 81
          Width = 164
          Height = 13
          Caption = #1056#1072#1089#1089#1090#1086#1103#1085#1080#1077' '#1076#1086' '#1073#1072#1083#1082#1080' '#1089#1087#1088#1072#1074#1072', '#1084#1084
        end
        object lbl_number_propping_supports: TLabel
          Left = 13
          Top = 138
          Width = 95
          Height = 13
          Caption = #1052#1086#1085#1090#1072#1078#1085#1099#1077' '#1086#1087#1086#1088#1099
        end
        object edt_span: TEdit
          Left = 224
          Top = 22
          Width = 52
          Height = 21
          BevelInner = bvSpace
          TabOrder = 0
          OnChange = OnControlsChange
        end
        object edt_width_left: TEdit
          Left = 224
          Top = 49
          Width = 52
          Height = 21
          TabOrder = 1
          OnChange = OnControlsChange
        end
        object edt_width_right: TEdit
          Left = 224
          Top = 76
          Width = 52
          Height = 21
          TabOrder = 2
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
        object cmb_bx_number_propping_supports: TComboBox
          Left = 222
          Top = 138
          Width = 52
          Height = 21
          Hint = #1047#1072#1076#1072#1081#1090#1077' '#1082#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1086#1087#1086#1088' '#1087#1088#1080' '#1073#1077#1090#1086#1085#1080#1088#1086#1074#1072#1085#1080#1077
          Style = csDropDownList
          ParentShowHint = False
          ShowHint = True
          TabOrder = 4
          OnChange = OnControlsChange
          Items.Strings = (
            '0'
            '1'
            '2'
            '3')
        end
      end
      object GrpBxStaticScheme: TGroupBox
        Left = 3
        Top = 248
        Width = 1042
        Height = 278
        Caption = #1056#1072#1089#1095#1105#1090#1085#1072#1103' '#1089#1093#1077#1084#1072
        TabOrder = 3
        object img_static_scheme: TImage
          Left = 2
          Top = 62
          Width = 1038
          Height = 214
          Align = alBottom
          ExplicitLeft = 0
          ExplicitTop = 110
        end
        object lblLoadCase: TLabel
          Left = 17
          Top = 25
          Width = 65
          Height = 13
          Caption = #1042#1086#1079#1076#1077#1081#1089#1090#1074#1080#1077
        end
        object cmb_bx_impact: TComboBox
          Left = 88
          Top = 21
          Width = 181
          Height = 21
          Style = csDropDownList
          TabOrder = 0
          OnChange = cmb_bx_impactChange
        end
        object rd_grp_internal_forces_type: TRadioGroup
          Left = 295
          Top = 13
          Width = 586
          Height = 37
          Caption = ' '#1060#1072#1082#1090#1086#1088' '
          Columns = 3
          ItemIndex = 0
          Items.Strings = (
            #1048#1079#1075#1080#1073#1072#1102#1097#1080#1081' '#1084#1086#1084#1077#1085#1090', '#1082#1053#1084
            #1055#1086#1087#1077#1088#1077#1095#1085#1072#1103' '#1089#1080#1083#1072', '#1082#1053
            #1055#1077#1088#1077#1084#1077#1097#1077#1085#1080#1103' ('#1085#1086#1088#1084#1072#1090#1080#1074#1085#1099#1077'), '#1084#1084)
          TabOrder = 1
          OnClick = rd_grp_internal_forces_typeClick
        end
      end
      object grp_bx_working_conditions_factors: TGroupBox
        Left = 851
        Top = 3
        Width = 192
        Height = 126
        Caption = ' '#1050#1086#1101#1092#1092#1080#1094#1080#1077#1085#1090#1099' '#1091#1089#1083#1086#1074#1080#1081' '#1088#1072#1073#1086#1090#1099' '
        TabOrder = 4
        object lbl_gamma_c: TLabel
          Left = 16
          Top = 41
          Width = 99
          Height = 13
          Caption = #1050#1086#1084#1087#1086#1079#1080#1090#1085#1072#1103' '#1073#1072#1083#1082#1072
        end
        object lbl_gamma_bi: TLabel
          Left = 19
          Top = 66
          Width = 30
          Height = 13
          Caption = #1041#1077#1090#1086#1085
        end
        object lbl_gamma_si: TLabel
          Left = 19
          Top = 93
          Width = 49
          Height = 13
          Caption = #1040#1088#1084#1072#1090#1091#1088#1072
        end
        object edt_gamma_bi: TEdit
          Left = 121
          Top = 62
          Width = 52
          Height = 21
          TabOrder = 0
          OnChange = OnControlsChange
        end
        object edt_gamma_si: TEdit
          Left = 120
          Top = 89
          Width = 52
          Height = 21
          TabOrder = 1
          OnChange = OnControlsChange
        end
        object edt_gamma_c: TEdit
          Left = 121
          Top = 37
          Width = 52
          Height = 21
          TabOrder = 2
          OnChange = OnControlsChange
        end
      end
      object grp_bx_sheet_cont: TGroupBox
        Left = 851
        Top = 135
        Width = 192
        Height = 107
        Caption = ' '#1050#1086#1101#1092#1092#1080#1094#1080#1077#1085#1090' '
        TabOrder = 5
        object lbl_sheeting_continuity_coefficient: TLabel
          Left = 16
          Top = 19
          Width = 92
          Height = 26
          Caption = #1059#1095#1105#1090' '#1085#1077#1088#1072#1079#1088#1077#1079#1085#1086#1081' '#1088#1072#1073#1086#1090#1099' '#1085#1072#1089#1090#1080#1083#1072
          WordWrap = True
        end
        object edt_sheeting_continuity_coefficient: TEdit
          Left = 123
          Top = 22
          Width = 52
          Height = 21
          TabOrder = 0
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
        Caption = '  '#1057#1090#1072#1083#1100#1085#1086#1077' '#1089#1077#1095#1077#1085#1080#1077'  '
        TabOrder = 0
        object pnl_steel_section_viewer: TPanel
          Left = 195
          Top = 17
          Width = 90
          Height = 30
          TabOrder = 0
        end
        object BtnSteelSectionChoice: TBitBtn
          Left = 22
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
        Width = 470
        Height = 60
        Caption = #1055#1083#1086#1089#1082#1072#1103' '#1087#1083#1080#1090#1072
        TabOrder = 2
        object lbl_h_f_flat: TLabel
          Left = 16
          Top = 29
          Width = 103
          Height = 13
          Caption = #1058#1086#1083#1097#1080#1085#1072' '#1087#1083#1080#1090#1099', '#1084#1084':'
        end
        object lbl_h_n: TLabel
          Left = 205
          Top = 27
          Width = 175
          Height = 13
          Caption = #1047#1072#1079#1086#1088' '#1084#1077#1078#1076#1091' '#1087#1083#1080#1090#1086#1081' '#1080' '#1087#1086#1083#1082#1086#1081', '#1084#1084':'
        end
        object edt_h_f_flat: TEdit
          Left = 141
          Top = 25
          Width = 41
          Height = 21
          TabOrder = 0
          OnChange = OnControlsChange
        end
        object edt_h_n: TEdit
          Left = 406
          Top = 27
          Width = 41
          Height = 21
          TabOrder = 1
        end
      end
      object grp_bx_corrugated_slab: TGroupBox
        Left = 3
        Top = 415
        Width = 798
        Height = 60
        Caption = '  '#1055#1083#1080#1090#1072' '#1087#1086' '#1085#1072#1089#1090#1080#1083#1091'  '
        TabOrder = 3
        object lbl_h_f: TLabel
          Left = 214
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
          Left = 78
          Top = 23
          Width = 121
          Height = 21
          Style = csDropDownList
          TabOrder = 0
          OnChange = cmb_bx_corrugated_sheeting_part_numberChange
        end
        object edt_h_f: TEdit
          Left = 409
          Top = 23
          Width = 41
          Height = 21
          TabOrder = 1
          OnChange = OnControlsChange
        end
        object chck_bx_wider_flange_up: TCheckBox
          Left = 476
          Top = 25
          Width = 149
          Height = 17
          Caption = ' '#1064#1080#1088#1086#1082#1080#1077' '#1087#1086#1083#1082#1080' '#1089#1074#1077#1088#1093#1091
          TabOrder = 2
          OnClick = OnControlsChange
        end
        object chck_bx_sheet_orient_along: TCheckBox
          Left = 647
          Top = 25
          Width = 154
          Height = 17
          Caption = ' '#1053#1072#1089#1090#1080#1083' '#1074#1076#1086#1083#1100' '#1073#1072#1083#1082#1080
          TabOrder = 3
          OnClick = OnControlsChange
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
          Left = 189
          Top = 18
          Width = 90
          Height = 30
          TabOrder = 0
        end
        object BtBtnSteelChoice: TBitBtn
          Left = 16
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
          Left = 189
          Top = 20
          Width = 90
          Height = 30
          TabOrder = 0
        end
        object BtnConcreteChoice: TBitBtn
          Left = 16
          Top = 20
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
          Left = 189
          Top = 19
          Width = 90
          Height = 30
          TabOrder = 0
        end
        object BtBtnRebarsChoice: TBitBtn
          Left = 16
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
          Left = 194
          Top = 19
          Width = 90
          Height = 30
          TabOrder = 0
        end
        object BtBtnShearStudsChoice: TBitBtn
          Left = 21
          Top = 19
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
          Left = 5
          Top = 20
          Width = 250
          Height = 375
          Center = True
          Picture.Data = {
            0954506E67496D61676589504E470D0A1A0A0000000D49484452000004270000
            06400802000000C539BF38000000017352474200AECE1CE90000000467414D41
            0000B18F0BFC61050000000970485973000012740000127401DE661F7800007B
            194944415478DAECDDD172F338928059D543CD74CFFB5FECC6BE546D75B8C6E5
            B12D269204482470CEC5444CF56F5B4A91203ECB92FEF87FFEDFFFEFDFFFFAAF
            170000C0187FA80E00006028D50100008CA53A000080B1540700003096EA0000
            00C6521D0000C058AA030000184B7500000063A90E0000602CD50100008CA53A
            000080B1540700003096EA000000C6521D0000C058AA030000184B7500000063
            A90E0000602CD50100008CA53A000080B1540700003096EA000000C6521D0000
            C058AA030000184B7500000063A90E0000602CD50100008CA53A000080B15407
            00003096EA000000C6521D0000C058AA030000184B7500000063A90E0000602C
            D50100008CA53A000080B1540700003096EA000000C6521D0000C058AA030000
            184B7500000063A90E0000602CD50100008CA53A000080B1540700003096EA00
            0000C6521D0000C058AA030000184B7500000063A90E0000602CD50100008CA5
            3A000080B1540700003096EA000000C6521D0000C058AA030000184B75000000
            63A90E0000602CD50100008CA53A000080B1540700003096EA000000C6521D00
            00C058AA030000184B7500000063A90E0000602CD50100008CA53A000080B154
            0700003096EA000000C6521D0000C058AA030000184B7500000063A90E000060
            2CD50100008CA53A000080B1540700003096EA000000C6521D0000C058AA0300
            00184B75B0AC3FFEF8E3AFFFFBE79F7F3E7D43D8CBC78177CC610929D6735880
            EA604D5F777E2E540CD59219BF7264420BEB39AC4175B0A09FBB40172ABA3B1D
            1B9F1C9610B29EC3325407AB79B71774A1A2A3EBC9F1724C42C47A0E2B511DAC
            C6558AA1BAF4C607C7241CB39EC34A54074B39D811BA4A719DE480DB58CF6131
            AA83A5B84A31943FAC82DB58CF6131AA83751CEF085DA5B8C80106B771BAC17A
            5407EB7095621CBF76853B59CF613DAA8345847FFAE22AC515BF1E600E2A18C1
            7A0E4B521D2CC207423394EA80DB58CF6149AA831534BEC6D7558A732407DCC6
            7A0EAB521DACC0558AA15407DCC67A0EAB521D94F76E47F8F3BFBB4A718EEA80
            7B58CF6161AA83DA0E3EB9D6558A2E2407DC4675C0C25407B51DEC085DA5E842
            75C03DACE7B036D54161074F74BC6C16E9C48104F74855C7CB6908D5A80E0A3B
            BE0EB94AD18503096E603D87E5A90EAA3A7EA2E3E52A45270E24B881EA80E5A9
            0EAA0A2F42AE525CE728821B58CF6107AA8392C2273ADEFD33572952EC75E006
            2D279AF51CAA531D94D4B8177495E222D501A359CF6113AA837A1A9FE878B94A
            7199EA80D154076C4275504FFB46D096918B1C423094F51CF6A13A282675E171
            95E20AC70F8CD6FE0C86F311AA531D14A33AB88DE30786B29EC35654079564AF
            3AAE525CE1F881A1522FD5703E4275AA834A4E5C75BC0091D3EC72601CEB39EC
            467550C6B92DA0AB14A7A90E18E7C4E26C3D87D2540765F4AA8E96AF82978307
            86B19EC3865407359CBED8B84A718E2307C639F7AC85B3124A531DD4A03AB899
            230706B19EC39E5407055CB9D2B84A718E23070639FDF20C672594A63A2860CE
            EAF8F8CE2E78AB9A647FE330633173AEE7EF7E90530F3A521DCCEED7CBCC451D
            ABA3E337642A5355C7533F1DBAEBBEA4F73A2FC21BE604848B5407B39BB33ABE
            DD2A57A3C54C981C8FDC00E8ABC47A3EFAC7C1B65407531B7189FA70E5CA612F
            B8BC19AAC361C67A062DE91DD7F3D13F0E76A63A98D7B8E478A90E0EA90EE86E
            C2DF229DBB494E46384775302FD5C153540774377F75FCFC3E3E0D1D3A521D4C
            6A6872BC5407875407F435E76F91DACF32EF2607D7A90E26A53A78D06CD5E118
            A3BAEAD5015CA73A98D1BBEBD3B94B42F71DA40BD5F21EAF0EC7182BE97842F5
            3D379D687027D5C18C6EA88E8EDFCD856A3DAA033A1A5D1DBDBE9B130D86521D
            4CA7EF45A5FB37541D3B501DD0CBD067272E7EC3C7CF74D88AEA603AE5AAA3EF
            AD6506DD0FC25E37E0A9DB03A795AB8E8BB710784775309711BBBD47AAA3CB2D
            E72955AAE3FE1B0629A35F5677FD7B1E9F6BCE2CE84875309741BBBD1BFEAAF8
            80EB56398F6F441C66AC61C49F30DD5632BD6E30F041753091714F763F5B1DD7
            6F3FF7EBF5469F271E7AC7186B98FFB7482DB7B6E38F80CDA90E2632EECF5A54
            07591D3F5E20FBE89FFED10E33A672671EF43AF81F7F9E1316A63A98C8CDD571
            E23B673FC8B6EFBDE0664F3DDDD1789879FB1D6636FF7AFEEC8F800DA90E2632
            6E17D5EB3BA7DECFD49B9F2EE07A780C3DCCC42DD39A7F3D9FE707C126540713
            99FF2AA53A7633797564FF31DC66FEF5FCDCCF728AC169AA83890C5DDFBB6CCE
            4EFF12DA85AABADB5E6B913A0B1C664CEBCEF5BCEF373FFE59CE32384D753091
            AF8B7BF795BDCB37571DB4E747AFB72B709851D1D0F5FCEBF7BF78A2855FEE2C
            835E540724A80E46531D305AE359E6CFABA02FD501ADFCB53D377098C168DE00
            1D1EA13AA095ED20377098C168AA031EA13AA0953FAF62347F5E053738511DCE
            2FB84E75402BD5C168AA036ED3D81ECE2CE84575402BD5C168AA836D3D783CFB
            2472B887EA8056ED6F04693BC8395ED4C19E7C0A38EC4075402BD5C168AA833D
            79B60176A03A98D4C745689E4B8EEDE086EE3F081D666CE8E0F5158E6A5889EA
            603A73EEA56C077773FF83E8451DECE9F855DD8E6D5886EA602ED37E16AC9792
            EF4675C00DC23792726CC33254077399F635858D9BBC69AB8994478EC3C683C7
            31C64A5ADEBED6110E6B501D4C64E61714FA2CDBAD4C521D8D1C6614D57ECC3B
            C86101AA83892C561D33DC6CCE29541D0E33EA521DB015D5C12C664E8E577E47
            38C9CDE69C12D5E118A334073CEC4675308B95AA6392DBCC394FBDB8C831C656
            5407EC46753085C993E3E5258F3B79F02D0D1C666CE260CDF7F11DB02AD5C114
            E6AF0EF631ED1BA9C132CE55C7CB990895A90E9E2739988AEA80A1C235DFD31D
            B024D5C1F3540753511D30D495EA783919A12CD5C1F36CF2988A0312C669FC35
            93A73B603DAA838779A283A9480E18AA7DCD171EB018D5C1C3540753511D304E
            6AC1571DB018D5C1932407B3511D304E76CD171EB012D5C1935407B3511D30C8
            8905DFCBCA6125AA83C7480E26A43A6090736BBEA73B6019AA83C7A80E26A43A
            6084D30BBEA73B6019AA8367480E26243960902B6BBEA73B600DAA8367A80E26
            A43A6084EB0BBEF08005A80E9E617BC7841C9630C2D0EA487D1FE041AA830778
            A28339A90EE8AED782EFE90EA84E75F000D5C19C5407747743759CF86EC0FD54
            0777931C4C4B75405F7D177C4F774069AA83BBA90EE6E4C884EEBA9F56C203EA
            521DDCCAC68E6979A203FA1AB1E0FB3B2BA84B75702BD5C1B45407F43568C1F7
            740714A53AB88FE46066AA033A1AB7E07BBA038A521DDC47753033D5011D0D5D
            F03DDD0115A90E6E2239989CEA805E6E58F0850794A33AB889EA6072AA037A79
            B63AFAFE20A017D5C14D6CE99899E3137AB9ED774C9EEE805A540777F0440793
            531DD0CB0CD531E2C70117A90EEEA03A989CEA802E6E5EED3DDD0185A80E8693
            1CCC4F754017F72FF8C203AA501D0CA73A989FEA80EB1E59ED550754A13A184B
            725082EA80EB9E5AF0850794A03A184B75303FC901D73DB8DA7B593994A03A18
            48725082EA80EB9E5DF03DDD01F3531D0CA43A284175C0458FAFF69EEE80F9A9
            0E06B299A304072A5CF47875BC3CDD01D3531D8C32C345085AA80EB8629ED55E
            78C0CC5407A3CC731D8263AA03AE9867B5F777563033D5C110F35C84E098E480
            2B665BED3DDD01D3521D0C31DB7508DE511D70C56CABBDA73B605AAA83FE66BB
            08C101D501A7CDB9DA7BBA03E6A43AE86FCEEB10FC4A75C069D3AEF6C20326A4
            3AE86CDA8B10FC4A75C03933AFF6FECE0A26A43AE86CE6EB10FCA43AE09CC957
            7B4F77C06C54079DD9C3518B23164E983C395E9EEE80F9A80E7A9AFF3A045F49
            0E38A7C46AEFE90E988AEAA0A712D721F8A43AE084424BBDF08079A80EBA2974
            1D820FAA034E28B4DAFB3B2B98C77FAAE37FFEFDDF4FDF0C00006059AA030000
            184B7500000063A90E0000602CD50100008CA53A000080B1540700003096EA00
            0000C6521D0000C058AA030000184B7500000063FDA73AFEFDAFFF7AFA6650D2
            1F7FFCF1EB7FFFF3CF3F9FBE6910F8F5E875E8C24FEB2DF5EFEE51F5FB059353
            1D9CB4DE7588ADA80E68B1EA527F101ED5EF1A4C4B7570D2AA972236A13AA0C5
            AA4BBDA73BE07EAA833356BD0EB10FD501A1B5977A4F77C0CD540767AC7D2962
            790E6068B1FC99223CE04EAA8333FC9E98D21CC0105A3E395EFECE0AEEA53A48
            DBE152C4DA5407843659EA3DDD01B7511DA46D72296261AA038EEDB3CE7BBA03
            6EA33AC8D9E752C4C254071CDB6AA9F77407DC437590B3D5A58855A90E38B0E1
            3A2F3CE006AA83840D2F452C4975C0810D977A7F670537501D246C7829623D92
            030E6CBBCE7BBA0346FB4F75FCCFBFFFFBE99B0100002C4B7500000063A90E00
            00602CD50100008CA53A000080B1540700003096EA000000C6521D0000C058AA
            030000184B7500000063A90E000060ACFF54C7BFFFF55F4FDF8C0177EC8F3FC2
            7FF3E79F7F3E7D3367F7EB186F9E5BF8507A1C4B98E1719CE178AECED2BA8C19
            4EC9F91D4C6992F9781CD7B0C9E3B86675B45C173FACF1280EF26E8C770EADF1
            A1F4384E6E92C751755C64695DC624A7E4FC8E07F5F87C3C8E6BD8E7715CB03A
            DAAF8B1F1678140779B63A3C8ECB98E7A1541D57CCF3387285C7316BDAA73B3C
            946BD8EA715CAD3AB20FDE87D20FE1208F3FD171E2A1F4384E68AAC751759C66
            695DC654A76415138687C7710DBB2DAD4B55C7B907EF55F9F11BA7D6131D37DF
            3C1ACDF638AA8E73667B1C39CD4379CE6C7F67E5715CC3868FA3EAF85BDD8770
            848A4F74DC7C0B6931DBE3A83ACEB1B42E63B653B290A99EEEF038AE61C3A555
            75FCADE8E33748DDEAB8F346129AED71541DE7CCF63872CE95C7F1B5FD4339D5
            D31D4EC9356CF838AE531D17D7D357D987B0BBD2C971E7EDE4D86C8FA3E438C7
            D2BA8CD94EC9722679BAC3E3B8863D1F47D5F18FA20F6177AA832E667B1C55C7
            3996D665CC764A56344378781CD7B0E7D2AA3AFE51F1F11BE1F1CD9925750DB3
            9D928F1FD845CDF638729AA5F5BA19FECECAE3B8863D9756D5F18F8A8F5F778F
            3FD1F1B2A4AE62B65352759C33DBE3C86996D62E1E7FBAC3E3B8863D9756D5F1
            8F8A8F5F77AA835E667B1C55C73996D665CC764A16F5F8D31D1EC735ECB9B4AE
            531D2FA7E2653324C7CBE3B890A9DEA043759CE6945C83C7B197D24F77781CE7
            B1E1E3A83AFE56F4F1EB6B92EA7879285731CFE32839AE98E771E40AD5F17502
            17EFCEB3E1E1949C56EA18DBF071541D7F2BFAF875344F72BC2E3C941EC7A9CC
            F338AA8E2B2CADCB98E7949CE1EE5FB95345AB638DC77166A9636CC3A575A9EA
            789D7D088B3E787D4D551DAF530FA5C77142933C8EAAE3224BEB3226392567B8
            E3BB3DDDB1C6E338B313C7D86E4BEB6AD5F1CA3F84751FBC8E664B8E97C77121
            333C94AAE3BA191E47AEDBF671ECBE08947B59F9320FE5B4CE1D635B3D8E0B56
            C72BF310967EF03A9AB03A5EC953D14339AD191E47D5D185A5750D339C9293DC
            EB7D9EEE58E6719CD9E9636C9FA575CDEA78B53D84D51FBC5EE64C8EF0E6CD76
            3B39F6ECE3A83A7AB1B42E63B7A5F5E6EAB8FECDBBDC86DB6E06AF6BC7D8268F
            E3B2D5F1F7DD9B7B3F3D89F9A734FF2DA4D123BB7FC9D19D53720D5B3D8E83D6
            81C7DF4577E8BD23E5FAA3B0FC29B97875D0C26AC5DA1CE1C0B8756092F0E071
            AE3521D5B1BBE5C31A5C098047AAA3D78FA004D79A90EAD89DEA6079AE04C0D0
            75C0D31DBC5C6B1AA88EAD490E76E04A003C551D1D7F0A9373AD09A98EADA90E
            76E04A008C5E073CDD816B4D4875EC4B72B003C739F0BA6547283C36A73A42AA
            635F7663ECC06500783D5D1DDD7F161372B909A98E4D490E96E7F78EB0BCBF4E
            F32B9FC2D67D29B0ECAC67B663AC34D5B129D5C1F25CFE616D9FE778CB19FD78
            758CF8718C36E131569AEAD8947383B5B9F6C3DABE9DE3E1497DDB55CFEF3B96
            31ED315697EAD891273A589EEA80859DD8DEDDB923141E0B98FC182B4A75EC48
            75B03CD5010B3B71159BA43AC6FD50FA9AFC182B4A756C4772B0868F23F9DD71
            9BFD5DE3F177036693BD96DDBC23F474C702263FC62A521DDB511D2C20FC73DB
            F64B7EF62F778149A42E67F354C7D09F4B5F331F6315A98EBD480E16D0B2B237
            56878B0494D67E51BBFF64F774C71A663EC6CA511D7B511D2CA0E5306EB9DE3B
            1D60018D27F2233B42E1B186998FB15A54C746ECB15846783087177BA7032CE3
            F46F2254078DA63DC66A511D1BB1CD6219A7A3E2E31FD80AC062CEFD26E286F3
            DD6AB38C698FB14254C7469C0FACE45C57480E58D5F1A670C2EAB8E706D0D19C
            C75821AA632F3F4F09E703751D5FCEB39C0B505DF6D70DF79CF57ED3B192398F
            B12A54C75EBC49288BE9151ECE0558436A4D78BC3A6EBB0D7434E1315685EAD8
            D15F278CD380655C0F0FA703ACA47D4DB8EDDCF774C762263CC64A501D407957
            C2C32501D6D3B826DC79FA0B8FC54C788CCD4F75002B38171EAE07B0AA963561
            92EAB8F996D0CB6CC7D8FC54075043DFD78EB778FCFD6D00E0A7A231A33A80D9
            3DBB351FB4B8EB0D00AE28D71EAA03989DEA00806F54074067AA0300BE511D00
            9DA90E00F8467500F4F7D41E7DE89A2E3C0038A75C72BC540750C89DDBF4193E
            3E0C00BEA9D81B1F5407B0029FD7011C0897889B57031F1AB89ED98EB109A90E
            A03C9F4D0E1C9BF003DD84C762263CC666A33A80DAAEFF85D2E69701D841E342
            E1D3CA396DC2636C36AA0328ACD78B2276BE0CC00EDAD78A49C2C3A254CE9CC7
            D854540750553639FE5AE85DE3614FA9E562923793B028D532E7313615D50194
            74DC0FBFFEAF1FABBCF0800DBD5B13DE2D0833848715A996698FB179A80EA09E
            F03A7D501D2D5F0E2CE6C46F22840729331F6393501D403DE10A7E5C1D2DDF01
            58C9B9DF44DCB320A88E35CC7C8C4D427500C5B4ACDD6175347E1F600D93FF26
            42782C60F2636C06AA0328E67451FC5CD91BFF1950DDE4BF89F0B2F2054C7E8C
            CD407500F57C5BB8AFE444F8AD80055CF94DC4EBE9F0B02E9530FF31F638D501
            94F4B170BF5BA6B34F621C7F37A0BAD3BF8938FEC7A36FE16D3F9DEBE63FC61E
            A73A8005F9D329E0ABD49A30617858BEE657E2187B96EA0016A43A80AFCE3DFF
            99FA9271B7F39E1FCD45558EB107A90E60413F57F385D7712074E237118FFCF2
            C2DF59D555E5187B90EA00D6E465E2C0A773DBBB4796114F771455E8187B8AEA
            00D6F475295F7B1D0742A77FA9FCF985337C54F99D3783AC42C7D853540700B0
            B82B7FCAF2D7D7DEBC1DF4744745B58EB147A80E006071E5FE805E789453EE18
            BB9FEA000016576E47E8EFACCA29778CDD4F7500008BABB823F474472D158FB1
            9BA90E006071157784A9A73BB67A2BA439553CC66EA63A0080C515DD11864F77
            1C974989FBB88CA2C7D89DD6AF0EF5BF0C0FE51A3C8E6BF0382E639387B2EE8E
            30EC8A5089BBB9802EC7D8DAE7E3B2D5A1FE97E1A15C83C7710D1EC765ECF650
            EE5C1D55EE697517DF39F7F81FACF108AE591DEDA7E81A8FE2C21A1F4A8FE3E4
            3C8E6BB0B42E63C353B26E75BC844711D73F25F0D8028FE082D5913A39177808
            17E6A15C83C7710D1EC765ECF950AA8E42F7B7A873C7D856E7E36AD571EECCAC
            FE282EE9C443E9719C90C7710D96D6656C7B4A96AE8E97A73B2A38718CEDB6B4
            2E551DA7CFC9BA8FDFAA3C946BF038AEC1E3B88C9D1FCAEAD5F1121ED3CB1E63
            1B9E8FAAE36F751FC2256D782A2EC9E3B8064BEB32763E255547C5BB5CCB6DD5
            F12AFB38AA8EBF157DFC56E5A15C83C7710D1EC7355CDCB3567F2817A88E578F
            F02877970B511DA175AAC3A9B88CCD2F8DCBF038AEC1D2BA8CCD4F49D551F42E
            17923AC6F63C1F55C73F8A3E84EBD9F3545C8FC7710D96D6656C7E4AAE511DAF
            ED1FC799DD591DAF9A0FA5EAF847C5C76F4996D4353825D7E0715CC6E64BABEA
            A87B97AB501D21D5F18F8A8FDF922CA96B704AAEC1E3B88CCD97D665AAE3B5E5
            EB014A501D21D5F18F8A8FDF9236BF342EC3E3B8064BEB32363F255547E9BB5C
            82EA08AD531DAFED97D465781C97E1D2B806A7E41A367F1C5547DDFB5B85F7B0
            0AA98EBF157DFC56E5A15C83C7710D1EC735A88E65EE94EA9893EA08A98EBF15
            7DFC5665495D83C7710D96D665EC7C4AAE541DAF530F65DD3B5B85EA082D551D
            AFB30F61D1076F613B5F1A17E3945C83C7710D3B2FAD8B55C72BFF6896BEB325
            9C38C6765B5A57AB8E975F00ACC2E3B8068FE31A76BB342E6CDB5372F3EA287D
            4FAB501DA105ABE3957914EB3E723BB0A4AEC1E3B80C4BEB1AF63C25D7AB8E97
            537232A78FB17D1E47D551FBF15B5EE343E9719C9CC7710D96D6656C784A2E59
            1D4C6574752C70B8AE591D7FDFB7C3477181076F131EC7651C3C941EC7429C92
            6BD8ED71541D8C76F118DBE1945CB93AFEB9935F1EC8351EB63D791C97F1F950
            7A1C4B734AAE6193C75175305AAF636CE14BE47FAAE37FFEFDDF4FDF0C000060
            59AA030000184B7500000063A90E0000602CD50100008CA53A000080B1540700
            003096EA000000C6521D0000C058AA030000184B7500000063FDA73AFEFDAFFF
            7AFA660050C31F7FFCF1F33FFEF9E79F4FDF2E38E2B86534C758487500F07F7C
            5C3BDF5D2C5357D6E36F05B7B1236434C758487500F08F6F17CE9F97CCC62B6B
            F87DE04E76848CE6180BA90E00FED672D5ECF56FE04E8EC9774378370713CB32
            B190EA00E06F2D9B92F0CA9ADAD9C03DEC080FE6F0BAF0AC269F4C2CA43A00F8
            47B82939BEB24A0EE66447F8A9F12435B12C130BA90E00FEF16E47F2FADFCBE7
            C19535FC5A788A1DE1575D9ED5E41B130BA90E00FE8FE378787765951CCCCC8E
            F09B8BCF6AF2938985540700DF1D2444968B2E33B023FCE9383C4C2CCBC442AA
            03805F74090F575C266147F8AB83F030B12C130BA90E007E77313C5C6E99871D
            E13BA9D3DCC40E38C642AA0380B74E87876B2D53B1236434C758E83FD5F13FFF
            FEEFA76F060000B02CD50100008CA53A000080B1540700003096EA000000C652
            1D0000C058AA030000184B7500000063A90E0000602CD50100008CF59FEAF8F7
            BFFEEBE99B01DBF9E38F3F8EFFC19F7FFEF9F46D6477E1517ACC31CC3C7E3D98
            1DA274E4180BA90E7886EA60721793E383C39849D8116635AE0066F8C9311652
            1DF00CD5C1CCBA24C787AF47B2274F788A1D6156FBD96A8C1F1C6321D501CF50
            1D4CAB63727CF8389807950CB4B023CC4A9DB026F9728C35501DF00CD5C19C0E
            8ECCBF8EC9D3E570E56BDF7DC39B274369768459EF26F6EE44364CC7584875C0
            335407733ADE52747F1AE40AE708EDEC08B30E26263C7EE5180BA90E78C6F5EA
            F8FC0E16357A0937132DC7ED9D65E2E0A7911D61D6F1C484C74F8EB190EA8067
            5CA90E4B1B83848756E3717B5B7838EC6964D9CC3ABD1A6C3B55C7584875C033
            4E54C7F19758DAE8E2DB61F6EDB86A3F6E5BC2A3E5A0F5B78874614798D53231
            E1F195632CA43AE019A9BD94F74DE74E1FC7DBAF8753B6013EBFD5C5EBB1E4E6
            223BC2ACC689098F4F8EB190EA806774FFFB784B1B3738FDCCC3F5EBF1F19B6B
            3D3D1866674798D53E31E1713087DD86704C75C033067D24020C75AE3A7A6D4A
            8407A7D91166A526263C5E8EB106AA039EE1B30BA8E8D9EAE8FBADD88A1D6156
            7662CE4DC7584875C0337A5587158D3B75AC8ED387AE4B3B27386CB24E4C6CF3
            216F7EF75BA80E78C6F5EAB096713FD541510E9BAC73133B7E13BCB539C642AA
            039E71BA3A2C613C48755094C326EBF4C4B6FD045BC7584875C0ADAE3CC561F1
            E2711D3F6746757027874DD69589FDF5B51BCED63116521D70134F6EB0805ED5
            71E5A87669E704874D96896599584875C058DDDF211766F64875B8AE13B223CC
            32B12C130BA90E18456FB0A1D1D5E1BACE398E9C2C13CB32B190EA80FEF406DB
            521DCCC991936562592616521DD08DD880A1D5E1A2CE690E9E2C13CB32B190EA
            800EF4067CF876891D9D1CA7BF1BBBB123CC32B12C130BA90E38EFCADB520915
            9634A83A0ECE1717755AD81166995896898554079C71FD6D7055074BBAB93A5C
            D1696447986562592616521D90D0F1333754074BEA5E1DC7678A2B3A8DEC08B3
            4C2CCBC442AA039A74FF8C3FD5C1923A56C7894F248477EC08B34C2CCBC442AA
            038E5C6983E3B54675B0A496EA18F183E0981D6196896599584875C0EFBA3FB9
            C108EDBF0EF7873AF71B941C1E2C4EB023CC32B12C130BA90EF83FC63DB9C108
            AA6366AA8379D8116699589689855407FCCD931B15A98E998DA80E8F14E7D811
            6699589689855407BBF3E44669AA6366DDABC3C3C4697684592696656221D5C1
            BE3CB9B100D531B35ED5E1D1E13A3BC22C13CB32B190EA603B9EDC5889EA9899
            738D79D81166995896898554071BF1E4C67A54C7B45C80998A0332CBC4B24C2C
            A43A589F5FB82E4C754CCB0598A93820B34C2CCBC442AA839579726379AA635A
            2EC04CC501996562592616521DEBFB7A1A6C72F47B72631FAA635A2EC04CC501
            996562592616521D8BFB790EAC7D0278726337AA635A2EC04CC5019965625926
            16521D2BDBE704F0E4C6B654C79CDE4DDB9C79CA3E17C45E4C2CCBC442AA6365
            3B9C009EDCD89CEA98D30E8B0FB53826B34C2CCBC442AA63596BFFAED1931B7C
            501D7372F565368EC92C13CB32B190EA58D6AAD5E1C90DBE521D73AA78F5BDB2
            66965E6FBFDDF812B7F9FADD5CFBCE766162592616521D6B3AD860153D013CB9
            C1AF54C79C6A5D7DAF1C1B2D4BD3B477FCD7BB30F9ADED7537D7BEB35D985896
            898554C79A56AA0E4F6E704075CCA9D0D5B7FD103AF7E5D3DEF15F6FFFCC37B5
            EF3D5DFEFE5E6762592616521D0BBA78119D87DE20A43A2654E8D27B4372D49A
            C09C3772C43D5DFEFE5E6762592616521D0BAA5E1D628376AA6342852EBDA73F
            D1E8E0851CB55EE3A13A9EBE5DF332B12C130BA98ED5947EBA5F6F90A53A2654
            E5D27B65C31D7EED0E43A8A5CA23320F13CB32B190EA584DC5EA101B9CA63A26
            54E5D27B7AC3DDF885A79F48796A0813DEBC41F77493BB7C918965995848752C
            E5D78BDCCC573EBDC145AA6342552EBDA737DCED5F38FF3309AAE3E9DB352F13
            CB32B190EA58C7BBC37DC2D3406CD08BEA98D0846B4E783B55C79C376FD03DDD
            E42E5F6462592616521DEB78F79CC654A781DEA02FD531A1A9D69CC6DB79A23A
            B29F1E38E1044ADCC211F77493BB7C918965995848752CE2E0589FE134F0197F
            0CA23A2634C39A93BD9D236EDEFC4F74DC30847954392CE76162592616521D8B
            3878F1C6B3A7812737184A754C6899D7925DBCD983AAE3FA87C02EF0312327D8
            1166995896898554C70A8E0FF4474E034F6E700FD531A7CF69CF36D8DB36DC23
            92A3F1C6873F4B75AC77EF4630B12C130BA98E151CFF66F1E6D3C0931BDC4975
            9072CF86BBFBB33D27D6D5F6F7F31D3484D9D8116699589689855447792D47F9
            0D678227377884EA20A57DA59A273952373BFCA17B3ED1F1B223CC33B12C130B
            A98EF25AAE7043CF044F6EF020D5C109435FE7DDFD9B878BFCB9CED9E775E43F
            EFEF5677FC3413CB32B190EAA8ADF1101F7426E80D1EA73A38615C75DCF0728E
            F0498C13AF29DFE1F8B723CC32B12C130BA98EDA1A7FC535E24CE8F88C3F9CA6
            3A38E19E77972AF46D7738FEED08B34C2CCBC442AAA3B0F6E3FBF1EA70D63188
            EAE0847BDE604A754CC58E30CBC4B24C2CA43A0A7BB03A7ABD81235CA43A38E1
            FE975E4C756B7F7EDB1D8E7F3BC22C13CB32B190EAA82A7570BFDB6F757C9396
            5EDF19525407590FBEF4A2CB37EFF2234A7C6E7A5F7684592696656221D55155
            F6E0BEE7E90E671737531D648D7EA2A3FBB174FDC3C8EFBFCD1372CDCA32B12C
            130BA98E924E1CD9A3DFC6CA79C5235407597D37DCF76CDFBB1FBDBBFD79D5CB
            8E30CFC4B24C2CA43A4A9AA73AE059AA83AC8E9D70E733067DFFAE55756C75DF
            CF31B12C130BA98E7ACE1DD64E0696A43AC8EA950A435F41DEFE43CFDD06D5B1
            D57D3FC7C4B24C2CA43AEA511DF049759052F4898EE31FFD4DF672B0C9C1EF22
            986562592616521DC59C3EA6BBBF8D15CC40759032E8898E478E9FD3ABFA0C37
            FE7E7684592696656221D5518CEA80AF5407295D36DC53EDDAAFBFCC6F9383DF
            8E30CBC4B24C2CA43A2A497D1C7823E703A5A90E52AE6FB827DCB2675F61B2E1
            8B3A5E7684792696656221D55189EA806F540729179BE191579077BF5FAA63C3
            BB7F82896599584875943122395ECE078A531DB4ABF844C75F3FF1C4DFD0B67F
            62EC3E47BE1D6196896599584875D43028393E3825A84B75D0AEEF131D37BF4F
            6EAF90501D7BDEFD134C2CCBC442AAA306D501BF521DB4BBB2E13EB108B7BF97
            D4AFFFF2F4B2AF3A5AEEF86E77FF0413CB32B190EA28606872BC9C1254A63A68
            777AC33D2200C2E731CEFD506F9BDB78C777BBFB279858968985544701AA03DE
            511DB49BA73A5A6EC9886757AE0CA13A3BC22C13CB32B190EA985DDFCFD9B8F9
            94B872E34B7FC0C89E6F11F308D541BB5AD591FDB98D774775EC79F74F30B12C
            130BA98ED915AD8E2B3BBC960BEDE4A7F1B6D7F5FBA90E528E5F4A117E55CAC5
            E468BC0157DE896BABC3DE8E30CBC4B24C2CA43AA6D6FDF7FDF73C81D0BE113C
            F1B5236E705F92E34EAA83722C118FB023CC32B12C130BA98EA955AC8E2BC9D1
            F2E5836E7647B61477521D94638978841D6196896599584875CC6B44213C521D
            17FF78FAAF2FAFF51A0F5B8A3BA90E6AB13E3CC58E30CBC4B24C2CA43AE635E8
            F01D7A56747C3BFC9F5F7BA567EE64577127D5412DDE6AE22976845926966562
            21D531A971BFDD9FB33A4EBFA3CB6CE7B3E4B899EAA016D5F1143BC22C13CB32
            B190EA98D4B86377FEEA28FDC1BA93DFBCF5A80E6A511D4FB123CC32B12C130B
            A98E49DD5C1D23BEF9E93FAF521DB4531DD4B2E7BBD6CEC08E30CBC4B24C2CA4
            3A2635EE4F8926AF8EF0AB26FF4DA1EAB899EA005AD81166995896898554C7A4
            6EAE8E11DFFC860F1F9CF0649EFF162E4675002DEC08B34C2CCBC442AA635243
            37AF7DBFF99D9FB031A26ABA6C4617F89891A25407D0C28E30CBC4B24C2CA43A
            2635F44983BEDFFCB60DF78812EBF251E8A909F4BAE57C501D400B3BC22C13CB
            32B190EAE092DB36DCDDFFE4ACE32D571D0F521D400B3BC22C13CB32B190EAE0
            927B9EE8783C398E7FA83FAF7A90EA005AD81166995896898554077D8CFB93B0
            112FAC3FFE9EA7178EC9DF5F6B49AA03686147986562592616521DF4715B758C
            783947F824C689D7945B68EEA13A80167684592696656221D5411F8336DC83DE
            CBEB866F6BA1B987EA005AD81166995896898554077DDCF09EB6B562C642730F
            D501F39B616DB423CC32B12C130BA90EFAE87E5119F739892FD5B110D501F39B
            E1ECB323CC32B12C130BA90E3AE8BE891F9A1CAF314B834F257F84EA80F9CDF0
            467F7684592696656221D54107A33FEC7CE8E724F6FA59AAE311AA03E677EECD
            CA3F0CFA93DDBEDF7C492696656221D541071DFFB2E886E47865B6AA8F0C8176
            AA034AB8121EDF9C3B5BED08B34C2CCBC442AA830EC655C7D0D3B56F7BA88E47
            A80EA8E8FE08B123CC32B12C130BA90E3AE8B5E17EE48F947A6D4655C7235407
            54D7B1405E0D9FBFD4F28F7999589E8985540757F54A85675F1771714BEA451D
            4F511D50DDAFEBE7E914511DBD985896898554075775D9704FB26B7F779D531D
            D3521D505DE3FAD9DE21BF7E073BC22C13CB32B190EAE0AAEB1BEED9B6EC2716
            8ED9EEC23E540754777AFD4CFD9EC88E30CBC4B24C2CA43AB8EAE2EB19EE79D3
            AAD1B7CA8B3A9EA23AA0BA7B7E756547986562592616521D5C7565C33D6772FC
            7ADB54C79C540754A73AE66462592616521D5C72F16A31F31F26B587C4CCF762
            79AA03AA531D7332B12C130BA90E2EB972B5B87FB3DEFE134F3FD171CF1DE193
            EA80EA54C79C4C2CCBC442AA834BBABF0AF040CB37FFF8B6D7DF0225F57355C7
            83540754A73AE66462592616521D5C726775843F22FC9B28D5B11ED5010BE8FB
            AE24AAA30B13CB32B190EAE09279AAE3F455E7DC8FEB3204AE531DB0801B5E22
            6847986562592616521D5C52AB3AB23FB7F1EEA88E07A90E58C0C1E9D9EB573F
            7684592696656221D5C1559FA7D995979237BA981C8D37E0CAAFD9AC2F37531D
            B086D31F3DDEF80EEC7684592696656221D5C10A3CDBB02DD501CB38FD1CF837
            AAA30B13CB32B190EA6005AA635BAA0356723D3C527F5EEBC43F606259261652
            1D94273976A63A603D57DA4375F46262592616521D94E765153B531DB0B65E6F
            016247986562592616521DD4E6898ECDA90ED8CDB9BD9D1D6196896599584875
            509BEAD89CEA005AD8116699589689855407B5F9F3AACDA90EA0851D61968965
            995848750085A90EA0851D61968965995848750085A90EA0851D619689659958
            48750085A90EA0851D61968965995848750085A90E58C9BBF3F4FA196A479865
            62592616521D4061AA0396D1F8D11CE7CE563BC22C13CB32B190EA000A531DB0
            86F64F03FCF56CFDEBCB8FCF623BC22C13CB32B190EA000A531DB0808B1F40DE
            F216EA7684592696656221D50114A63A60011DABE3F5FEC990966FC52713CB32
            B190EA000A531DB0809FA7E7D753328C0AD531828965995848750085A90EA8EE
            7A54A88E114C2CCBC442AA03284C754075AA634E2696656221D50114A63AA03A
            D5312713CB32B190EA000A531D509DEA98938965995848750085A90E58C0F15B
            DFAA8E47985896898554075098EA80051C6783EA78848965995848750085A90E
            588077CE9D908965995848750085A90E58C34139A88E47985896898554075098
            EA8035BC3B43FF3A3755C7234C2CCBC442AA03284C75C032C2D3F9C3F1AB3E5E
            AAA31313CB32B190EA000A531DB092C6F038A63ABA30B12C130BA90EA030D501
            8BB9181EEFCE653BC22C13CB32B190EA000A531DB0A473ED717022DB11669958
            96898554075098EA801D9C7BC947F81D9CF8074C2CCBC442AA03284C75C06ECE
            EDEDEC08B34C2CCBC442AA03284C75002DEC08B34C2CCBC442AA03284C75002D
            EC08B34C2CCBC442AA03284C75002DEC08B34C2CCBC442AA03284C75C002FE3A
            3D479F837684592696656221D50114A63AA0BAC60F17EFFE5306FDA065985896
            898554075098EA80EADE9D9B7DCF4A3BC22C13CB32B190EA000A531D50DDC1B9
            D9F1C4B423CC32B12C130BA90EA030D501D5A98E39995896898554075098EA80
            EAFC85D59C4C2CCBC442AA03284C754075DFCECD4127A31D6196896599584875
            0085A90EA84E75CCC9C4B24C2CA43A80C2540754A73AE66462592616521D4061
            AA03AA531D7332B12C130BA90EA030D501D5A98E39995896898554075098EA80
            EA54C79C4C2CCBC442AA03284C754075DE39774E2696656221D50114A63AA0BA
            F02CFE74E53CB523CC32B12C130BA90EA030D501D5B557C74FED67AE1D619689
            65995848750085A90E58C095F0F8EAE044B623CC32B12C130BA90EA030D5018B
            B95820EFCE653BC22C13CB32B190EA000A531DB0B61311F2EBE96C4798656259
            2616521D4061AA0376D37ED6875FE5C43F6062592616521D4061AA0336D7F871
            1F7684592696656221D50114A63A80167684592696656221D50114A63A801676
            84592696656221D50114A63A80167684592696656221D50114A63A8016768459
            2696656221D50114A63A80167684592696656221D50114A63A80167684592696
            656221D50114A63A80D7FF9EE00727B21D61968965995848750085A90EA0E523
            3BEC08B34C2CCBC442AA03284C75002DBB3D3BC22C13CB32B190EA000A531DC0
            C1D97DBC0238F10F985896898554075098EA005E0D27B81D6196896599584875
            0085A90EE053B8207CE3C43F600F9D656221D50114A63A80AF52E1E1C43F600F
            9D656221D50114A63A805F7D3DE5FD85D5092696656221D50114A63A80167684
            592696656221D50114A63A80167684592696656221D50114A63A801676845926
            96656221D50114A63A601943376D7684592696656221D50114A63A600137BCF1
            941D61968965995848750085A90E5840F67336BE6A3C79ED08B34C2CCBC442AA
            03284C75C002AE54C7ABEDFCB523CC32B12C130BA90EA030D501D5FD3C37BF9E
            8FED41727C16DB1166995896898554075098EA80EABE9D9BE1C978702E1F7CAD
            1D61968965995848750085A90EA82E5B1DEFBEF0A53ABA32B12C130BA90EA030
            D501D59DAE8E57263CEC08B34C2CCBC442AA03284C75407557AAA3FDCBED08B3
            4C2CCBC442AA03284C75407517ABA3F13BD81166995896898554075098EA80EA
            54C79C4C2CCBC442AA03284C75C0FCBE9E7D3FCF35D5312713CB32B190EA000A
            531D30BF7767DFC779A73AE66462592616521D4061AA03E697FAE871D5310913
            CB32B190EA000A531D30BF54757CB8F2FEB9AAA30B13CB32B190EA000A531D30
            BF13D5F153FB2700AA8E2E4C2CCBC442AA03284C75402D5D0AE4C3BBB35B7574
            6162592616521D4061AA03AAEBD8211F5447172696656221D50114A63A6031D7
            234475746162592616521D4061AA03D6D6EB95E87684592696656221D50114A6
            3A6037ED677DF8554EFC032696656221D50114A63A60738D1F32684798656259
            2616521D4061AA03686147986562592616521D4061AA03686147986562592616
            521D4061AA03686147986562592616521D4061AA03686147986562592616521D
            4061AA03686147986562592616521D4061AA03686147986562592616521D4061
            AA03DA7D9C057B1EED7684592696656221D50114A63AA0DDD7B360B763DE8E30
            CBC4B24C2CA43A80C2540734FA790A6C75D8DB1166995896898554075098EA80
            46EF4E814D0E7E3BC22C13CB32B190EA000A531DD0E8E014D8E1F8B723CC32B1
            2C130BA90EA030D5018D363F05EC08B34C2CCBC442AA03284C7540A3F064792D
            7D22D81166995896898554075098EA80462DD5F15AF75CB023CC32B12C130BA9
            0EA030D5018D1AABE3B5E8E96047986562592616521D4061AA031AB557C787A1
            27C5B71B73C3096847986562592616521D4061AA031A65ABE335F2BCB8FFC343
            EC08B34C2CCBC442AA03284C7540A3775BA2474E8DFBF7677684592696656221
            D50114A63AA0D1F196E8E6134475CCCFC4B24C2CA43A80C25407340AB744779E
            23AA637E2696656221D50114A63AA051CB96A8FD84BAE1C6DC7FF7F9CAC4B24C
            2CA43A80C25407346ADF12DD70B2A88EF9995896898554075098EA8046A92DD1
            E8F34575CCCFC4B24C2CA43A80C2540734CA6E8986FEB595EA989F8965995848
            750085A90E68746E4B34E8C4511DF333B12C130BA90EA030D5018D4E6F89469C
            3BAA637E2696656221D50114A63AA0D1952D51F7BFB6521DF333B12C130BA90E
            A030D5018DAE6F893A9E44AA637E2696656221D50114A63AA051972D51AF273D
            54C7FC4C2CCBC442AA03284C7540A35E5BA22EE1A13AE66762592616521D4061
            AA031AF5DD125D3CA154C7FC4C2CCBC442AA03284C7540A3EE5BA22B4F7AA88E
            F9995896898554075098EA804623B644A7C34375CCCFC4B24C2CA43A80C25407
            341AB7253A7172A98EF9995896898554075098EA804643B744D9273D54C7FC4C
            2CCBC442AA03284C7540A3D15BA25478A88EF9995896898554075098EA8046F7
            6C891A4F34D5313F13CB32B190EA000A531DD0EEE75930E2C86F392B55C7FC4C
            2CCBC442AA03284C7540BB6F67C1B8C33E3C317FA53AA66262592616521D4061
            AA03A6956D0FD5311513CB32B190EA000A531D30B35478A88EA9985896898554
            075098EA80C9B58787EA988A8965995848750085A90E28A1A53D54C7544C2CCB
            C442AA03284C754015D94F12BCE1A73BF10F985896898554075098EA80421E3C
            0DED08B34C2CCBC442AA03284C7540398F6CCEEC08B34C2CCBC442AA03284C75
            4045F77C5EE1F14FBCE187966662592616521D4061AA03AAFBEBDCBCE104B423
            CC32B12C130BA90EA030D501B4B023CC32B12C130BA90EA030D501B4B023CC32
            B12C130BA90EA030D501B4B023CC32B12C130BA90EA030D501B4B023CC32B12C
            130BA90EA030D501B4B023CC32B12C130BA90EA030D501B4B023CC32B12C130B
            A90EA030D501B4B023CC32B12C130BA90EA030D501B4B023CC32B12C130BA90E
            A030D501B4B023CC32B12C130BA90EA030D501B4B023CC32B12C130BA90EA030
            D501B4B023CC32B12C130BA90EA030D501B4B023CC32B12C130BA90EA030D501
            B4B023CC32B12C130BA90EA030D501B4B023CC32B12C130BA90E9842B87BFECA
            2AF64975002DEC08B34C2CCBC442AA039E948A8DAF2C641F5407D0C28E30CBC4
            B24C2CA43AE001A763E39385EC83EA005A2CB623FCBC3BE3EEC26213BB818985
            5407DCEA7A6F7CB0907D501D408BC576845FEFCEA07BB1D8C46E606221D501F7
            E9951C2F0BD9FF521D408BC57684AA63422616521D7013C93182EA005A2CB623
            541D1332B190EA809B74A90EEBD737AA0368B1D88E50754CC8C442AA03EE70B0
            E5B5245DA13A8016B576846154A88E0999584875C07092631CD501B4A8B5237C
            B75EFDBAA0A98E4998584875C07056A2715407D0A2D63A3CC3E7C6D69AD80C4C
            2CA43A60B89F2B9165A817D501B4A8B5233CF73AC0BE77A7D6C466606221D501
            63598686521D408B5A4BF10C9FEC546B623330B190EA80B12C4343A90EA045DD
            A5B8E3BBAEA7EE75DD893DC5C442AA03C6F2E75543A90EA0C51A3BC2EE057230
            8435267627130BA90E1848728CA63A80168BED087FBE87D5E920511DBD985848
            75C040AA6334D501B4586C4798FA408F50FB77A83BB11B98584875C040AA6334
            D501B4586C4798FDBC8E130BE06213BB81898554070CA43A46531D408BF57684
            1FF7E8DC5D688996F526369A898554070CA43A46531D400B3BC22C13CB32B190
            EA80512C4037501D400B0B7296896599584875C0289EE8B881EA005AD8116699
            5896898554078CA23A6EA03A80167684592696656221D501A3A88E1BA80EA085
            1D6196896599584875C028AAE306AA03686147986562592616521D3084D5E71E
            AA0368614DCE32B12C130BA90E18C2EA730FD501B4B026672D36B1CFBB33EE2E
            2C36B11154070C61F5B987EA005A2CB9265FF9A0C0C66FFE4DDD89653FCDFDE2
            8F18FDB38A521D30841775DC4375002DD6DB11B66FA3CF6DB8179B98EA9881EA
            802154C73D5407D062BD1DE1B77BF4EB7D79B7EEB5DCF1C526A63A66A03A6008
            D5710FD501B4586C47D87889B9B2EE2D3C31D5F114D501FD597A6EA33A80168B
            2DCB579EE8689C40AD898551A13A66A03AA03F4BCF6D5407D062B165597534DE
            D95F2F01AAE329AA03FAB3F4DC4675002D165B9653BFDAFFF6CF5A8AE5556D62
            2D8935FA5ED49AD8235407F4E7451DD735BE23A4EA005A2CB623CC56C7D77FA3
            3A06DD9D5A137B84EA80FE54C745E7DE11F257AA03782DB7233C5E24C36BD0E9
            3FD09A7662E7AAA3EF1DAC35B147A80EE8CCBA739DEA00FA5A6C653E58245B7E
            EDB55E7534DEFE731AEF75F589DD40754067D69D8B52AFF9531D408BC55666D5
            917543842C36B11154077466DDB9487500DD2DB632BF5B27CF7D8EC76ED5F171
            2F4E7788EA384D754067D69D8B5407D0DD622BF3BB6C501DEF9C78D7AF033B4C
            6C04D5019D59772EEA5B1D9FDF4775C07AFE3AAFF7FC9BFBF6A5AFE5CB77D843
            673FAFE3C42563B1898DA03AA033EBCE158D6FE9F8EEDF9FE60182723E4FFFD3
            9BC8D227FE950F01DCB03A3EEFD4B9BBD072B02D39B1BE54077466DDB9427500
            2DBAAC15D54FFC734FE12EF9791D3330B190EA80CEAC3B57F47D12BC9D07080A
            39B1CC2EB9321F2C80EDBF92571DBD985848754067D69D2B5407107A77E26FF8
            D72FD747A13A7A31B190EA80CE4E5C036EBB0DA76F55AFC5F4FA9B849CFB567D
            A7013C2EBBD2DA11BE9B8389F5626221D5019D3D5E1DD9ED78AF0FFFBEF3868D
            488EECDD019E955A6CED083F353EA56C62592616521DD059C76DFA889F9EBA31
            17DF9CF1CA0D7B257F03D7918B0454D11E1E76849F1ADFFBCBC4B24C2CA43AA0
            BF2EDBE28BEFEE77F1A73C522F836E5BAF9F0B4CA8313CEC08B34C2CCBC442AA
            0386782A3C26AC8ED3A3F01756408B96F0B023CC32B12C130BA90E18E2A9F756
            0AFF60F7DC8743B5FCB942DFF786BFFFA5E42D3F179853181E7684594B4EECE3
            4E0DBA174B4EAC2FD50143CCF05C47AFEAE8F8E9B6D7DFCCF1DDBFEFC2E501EA
            3A0E0F3BC2ACF526D6FECEECD9EBD1AF5F95FADA4DA80E18EBCAE6F8CA131DAF
            860CB8A113C655C7AB7778B836407507E1614798B5DEC4CE3DD5DF7EDFD79B58
            77AA0386EBFB5AEAF61FD4E5F5E8573AE1CA1F4D5DF9DDD2092E0CB0868E1F0A
            B4B9C5F6D08D7F157C7CFC78D7AF8B5407DCA7E31BD1B67C7FD5D1CE850196D1
            FD6352F7B4D81EFAE2131D2D13586C6223A80E58C7F5EA687F8DF8ABEB1F6B9D
            BEF1AA03F869F4AF78AA6B7985C3627BE85ED5F1DA666223A80E5847FB4BE55A
            BE43CAFD2FEAB878835B6E3F50D7C5DF5BAFAD657FBCD81E3AFB6BB2AFFFECDC
            3BAC1CFFE33DA90E58C7DAD531FAC3011BEF545FF7DF2960A812BBCC96D74C2F
            B687BEF2E4BCEAE84575C02246BCA8A3DDD017753CBB35BFF39DDD81354CBED7
            0CD79FF5DEF5EBB83AC2BF2E3EFDABB1BA131B4175C02246BCA8A39DEAC8521D
            B0B02A7BCDEC4254E57E1DDFD3F01273EE8AA63A42AA0316A13A06511D4056A1
            BDE626EF35AC3A66A03A6011DDABE3E25A79FA451D2FD501145771AFB9F6EBEF
            DF55C7B9CFF1501DE7A80E58C4C2D5F17A6E8F3EF482213C6049A5379A1FEBD2
            DAAFEB781DBE685E758CA33A6005377F3E60DFEF76A54FC6B9ED52A13D601937
            3C35FAECD2547A0F7DE5C91CD5D185EA80156C521DE1D79EE6C2006B6B79D7A6
            A76F63E2363FF5BEDE134EE9E23D6ABC83AAA30BD5012B501D17B930C0DA2ABE
            68E1D9DBBCE41EFA78A4ED1FC4A13ACE511DB082711FD6717AC56C5CA62FDE78
            D501B4685C2BE6590ADA17B73BDFF1629EF974BC53E15DF32981BDA80E5841AF
            A7294E6CE2BBBF0C437500DD3DBE891F746BC7DDE685F7D0A9BB76FA3768C7FF
            784FAA0356F06075BC924BF0E9EFD6EBFB5FFFB94039B53E95E278A77B7D77DB
            F2F2747BE8777330B1D35407ACA0E34B32FAFE8E6DDC6FEC46BCF593CB03ACEA
            DD8EF0DD4AF2EC6A70EEB5CBE7D64F7BE850E37B8899584875C00AFABEAF62DF
            5F0A8EF815E3B8779B758580251DEC08270C8FD12F24F08E4C599F1F6312FE9B
            6FB69DD8AF5407508FEA00528E7784B38547FB2F92CEED7455C7082616521D40
            31A33F56CF4502D613EE08A70A8FECD3D7D9BFB6521D239858487500C5A80E20
            AB6547384F789CF8A3D95478A88E114C2CA43A807AFC851590D2B8239C243CCE
            BD4148DF4F49B287CE32B190EA004AF21E5640BBF61DE10CE171FA6D09CF7D8A
            B6EAE8C2C442AA0328CCA704022D2E7E30DCF1BFBFE106F70D0FD53182898554
            075098EA005A6477848F8747AF8FE3F8F5CB55C7082616521D4061AA03687162
            47F8F826F2E20D38E816D591E57315BB501D4061AA036831EE732D6EBED9A9DB
            F0EECB5547D6E9F740DB7662BF521D40618DD5F1D7BA7FFC2F5D18606DD73FC6
            7BFE8F2A6FBCE33FD743D5113AB8821C7FD6E4B613FB95EA000A0BAB23FCECE1
            6FFF0C58D2951DE15F5FFBF81271257EDAD7C9F0AB1E9FC3535A66686221D501
            14A63A80169BEF084F2C809B4FEC9DEC9FF59AD857AA03284C75002DECA15BFE
            4628FCF75B4DEC9D547898D857AA03284C75002DECA1B37330B1504B7E98D857
            AA03284C75002DECA13F9DFBFCF2837FC9C72B7F4C2CA43A80C25407D0C28EF0
            2B9F3E3182898554075098EA005AD81166995896898554075098EA005AD4DA11
            4EF821218FDF9E71F7ABD79D5A75621DA90EA030D501B4A8B5236CF90BA83B6F
            C3E33766DC3DFAD5B9BBB9DEC4BA531D4061AA0368516B471856C70D4F86D49A
            D8B9BBD3A2FD2E2F36B11154075098EA005AD4DA11B657C7B87B516B62E7EE4E
            BB963BBED8C446501D4061AA0368516B47A83AEEB93B29E17D5F6C6223A80EA0
            30D501B4A8B523541DA3EFCED73BD2EBB3C6179BD808AA03284C75002D6AED08
            0FB6C83FFF81EAC8DE9D73CF5A845FBBD8C446501D4061AA0368516B47A83A86
            DE9DD4BD687FA7DDC5263682EA000A531D408B723BC2774BD6C76D561D57EECE
            897B1176E06BB9898DA03A80C25407D0A2DC8E70F4874B9CBB01334FACFDEEA8
            8EA7A80EA030D501B4A8B823CCBEED52DFBB5371628D7747753C45750085A90E
            A045D11DE10D9F3291FAD1F34FACE5EEA88EA7A80EA030D501B428BD23BCFE59
            1327EE75AD8985AFF9561D33501D4061AA0368B1D88EB06387ACF18E4CBD3E73
            A3F1FBAB8E7354075098EA005A2CB623FCF99BFBD31DB261759CB82FAAA30BD5
            0114A63A80168BED08531F5E1E5A600FDDE5C99FF64F005C60628F501D4061AA
            0368B1D88E30FB2A85130B60DD898DF8F333D5D185EA000A531D408BF576841F
            F7E8DC5D6889969526D6F7E5F82FD57196EA000A531D400B3BC2AC8527763D42
            54C739AA03284C75002DEC08B3B69A58970F64DC6A62E7A80EA030D501B4B023
            CCDA7962ED5796F0AB36995823D50114A63A801676845926F6D56EAF84194475
            0085A90EA0851D61968965995848750085A90EA0851D61968965995848750085
            A90EA0851D61968965995848750085A90EA0851D61968965995848750085A90E
            A0851D61968965995848750085A90EA0851D61968965995848750085A90EA0C5
            B91DE1E7576DB844D84367995848750085A90EA0C5C5EA68FCF72BB93EB1ADC6
            F5521D0D54075098EA005A74A98E962F59864ECB521D21D50114A63A8016BDAA
            A3F10B17D071623B8C6BF3FBDE48750085A90EA045DFEA68F9DAEA745A96EA08
            A90EA030D501B4E85E1D2D5F5E9A4ECB521D21D50114A63A801623AAA3F19B14
            356862AB8EEBA53A1AA80EA030D501B418571D2DDFA7229D96A53A42AA03284C
            75002D865647CBB7EA7817EE59AF745A96EA08A90EA030D501B4185D1D8DDFB0
            D7EDBF3372523F3735B1A1F7A2CAC4B6A23A80C25407D0A2EFE775DCFF9AE9FB
            3F3964B14E1BFAB30EEEBB8BCB57AA03284C75002DBA7F4AE0CDE171FF8E56A7
            5DFF8937FCD05A54075098EA005A8CF86CF23B5795EAD5F1BA7D11AE32B1ADA8
            0EA030D501B418511D07DFB9F1FB8FBEFDF7FF449D76E74F2C47750085A90EA0
            C5B8EA78DD121E55F6D0173BADE39DAA32B1ADA80EA030D501B4185A1DAFF12B
            4C953DF4F54EEB75BFAA4C6C2BAA03284C75002D4657C7C14F69FC59236EFFFD
            3F51A7DDF913CB511D4061AA0368714F75BC868547953D74C74EBB7807AB4C6C
            2BAA03284C75002D6EAB8ED798D5A6CA1EBA6FA75DB98F5526B615D50114A63A
            80167756C7C14FCC7E938BB7FF0A9D36FF4F2C47750085A90EA0C5FDD5F1EA1A
            1E55F6D0833AEDC49DAD32B1ADA80EA030D501B478A43A5EFD569E2A7BE8719D
            D6E55B4D38B1ADA80EA030D501B478AA3A0E7E7AEA1B56D9438FEEB4F66F5865
            625B511D4061AA0368F16C75BC2E8747953DF40D9DD6F83DAB4C6C2BAA03284C
            75002D1EAF8ED7B555A8CA1EFA9E4E3B774BAEDC98D337D8C5E52BD50114A63A
            80168FEFA18F6F49F8CDABECA1EFECB4D71213DB8AEA000A531D408B19F6D0C7
            37E6F8FB57D943DFDC69AFFA13DB8AEA000A531D408B79F6D0C737E9DD4FA9B2
            87BEBFD3DEFD882A13DB8AEA000A531D408BA9F6D0C7B7EAD71F54650FFD54A7
            BDCA4E6C2BAA03284C75002D26DC431FDCB09F3FABCA1EFAC14E7BD59CD85654
            075098EA005ACCB9873EBE795F7F62953DF4B39DF68AD6FC0927B615D50114A6
            3A80165DF6D0F7EF593F7F6E953DF40C9DF62A35B1ADA80EA030D501B4B8B223
            FCF8DA1B568970413B77FB3BDE982A9DF6CE8413DB8AEA000A531D408B423BC2
            F6CDF4CC7BE8BFBE5CA78DFE89E5A80EA030D501B4A8B5236CDC4CDB431FDCD4
            5F99D8B354075098EA005A94DB11B6ECA4EDA18F6FEDCDB7BFD6C41EA13A80C2
            5407D0A2E88EF0C185ABDCC474DAFC54075098EA005AD4DD11A63EC27CF4CF9D
            7F623A6D66AA03284C75002D4AEF08DF2D5FF6D0EDB7FC86DB5F7762B7511D40
            61AA0368B1C08EF0B68FC278F7E346FFC4D1377EF4ED2F3DB17BA80EA030D501
            B4586347F8F55E8CBEF10B4CECCE0F0F792D31B1D154075098EA005AD81166AD
            31B1CF7BF1D48787949BD850AA03284C75002DEC08B34C2CCBC442AA03284C75
            002DEC08B34C2CCBC442AA03284C75002DEC08B34C2CCBC442AA03284C75002D
            EC08B34C2CCBC442AA03284C75002DEC08B34C2CCBC442AA03284C75002DEC08
            B34C2CCBC442AA03284C75002DEC08B34C2CCBC442AA03284C75002DEC08B34C
            2CCBC442AA03284C75002DEC08B34C2CCBC442AA03284C75002DEC08B34C2CCB
            C442AA03284C75002DEC08B34C2CCBC442AA03284C75002DEC08B34C2CCBC442
            AA03284C75002DEC08B34C2CCBC442AA03284C75002DEC08B34C2CCBC442AA03
            284C75C0FCBE9E7D4F9D6B7684592696656221D50114A63A607E339C7D768459
            2696656221D501141656C787BFD6FD19F63DB0A7C6F3F4C3A093D18E30CBC4B2
            4C2CA43A80C252BB99032E0C30CE95F3B4D7B96947986562592616521D4061AA
            03E6D7EB3CFD70EE6CB523CC32B12C130BA90EA030D5011575EC90C693D78E30
            CBC4B24C2CA43A80C254075477CF33217684592696656221D5019434C3DF6C00
            D77D3B973F4EC6D327B8EAE8C5C4B24C2CA43A804AFAC6C627170678CAAFD511
            FEB303BF7E073BC22C13CB32B190EA006AB8F8BB4FEF9C0B736AAC8EF00B8FBF
            831D61968965995848750053BBF8E4864F0984C99DAE8ED477B023CC32B12C13
            0BA90E60525DFE984A75C0E454C79C4C2CCBC442AA0398CBA09789AB0E9893EA
            989389659958487500B318F14A71D50193531D7332B12C130BA90EE06183DE96
            EA83EA80C9A98E3999589689855407F098EB6FC91F7E07D501F3FB7A7AAA8E49
            98589689855407F0805E1F01A63A6001179FEE501D2398589689855407709F7B
            3E6FF8D72F541D30AD8BDB35D531828965995848750077E8DE1B8DDF56754009
            EDE772F885AAA30B13CB32B190EA00061A141BEDDF5F754015BDDE5842757461
            62592616521DC010A37BA3F1A7A80EA8A2EF0783B67C7327FE0113CB32B190EA
            007ABA2736DA7F9CEA805A2EB687EAE8C5C4B24C2CA43A803E6EEE8DC61FAA3A
            A0B4D4C2727022DB11669958968985540770C9955F4C5E5F8E5507ECE6DCDECE
            8E30CBC4B24C2CA43A80931E7972237B1B5407F0B223CC33B12C130BA90E20E7
            D92737B2374675002F3BC23C13CB32B190EA005ACDF0E446F626A90EE0654798
            6762592616521D4060AA2737B2B74D75002F3BC23C13CB32B190EA00DE9AF0C9
            8DEC2D541DC0CB8E30CFC4B24C2CA43A80EF667E72237B535507D43268EB6647
            986562592616521DC03FE67F72237B83550754D1B8FE74FC445127FE0113CB32
            B190EA002A3DB991BDE5AA034A685F8554C73D4C2CCBC442AA03FEE363B1D870
            7528F7E446F6F6AB0E98DFC50F20FFFAE5EFCE653BC22C13CB32B190EA6077DF
            96894D1688BA4F6E64EF88EA80F9A98E09995896898554075BDB708DA8FEE446
            F6EEA80E98DFCFD3F3EB2919FE6EA8E597471BAEF61799589689855407FB7AB7
            0D5D728D58E6C98DECFD521D30B9E3E478A98E8798589689855407FBDAA43A16
            7B72237BEF54074CEE7A54A88E114C2CCBC442AA834D1DEC41D75823567D7223
            7B3755074C4E75CCC9C4B24C2CA43AD8D4C2D5B1F6931BD93BAB3A6072AA634E
            2696656221D5C18E96DC806EF2E446F65EAB0E98DFF19B50A98E479858968985
            54073B5A6C03BAD5931BD9FBAE3A607EC7D9A03A1E6162592616521D6CA77D9F
            3ABF9D7BA37102AA03E6A73A266462592616521D6CA765A73EF93221363EA90E
            58C34139A88E47985896898554077B69DCAF4FBB4CE88D6F5407ACE160C7A63A
            1E6162592616521DECA56875888D7754072CE3DCFA1C7EC8E0C13777E21F30B1
            2C130BA90E36F26E4568BC68CD739B5BCC731786521DB0922BEFC5F749757461
            62592616521D6CA45075888D46AA031673313CDE9DCB7684592696656221D5C1
            2EDAFF68F8F5E832A1375254072CA9FB4A6847986562592616521DEC22551DAF
            DB578A3D3FE3EF3AD5013BB8FE92BC19D6F95A4C2CCBC442AA832D1CAF05CFAE
            149EDCB84275C06ECEADD87684592696656221D5C11626AC0E4F6E74A13A8016
            7684592696656221D5C1FAC285E0E695C2931B1DA90EA0851D61968965995848
            75B0BE9685E08617947B726304D501B4B023CC32B12C130BA90E16D7B80A0CAD
            0E4F6E8CA33A80167684592696656221D5C1E29EAD0EBD319AEA80057C3B3D47
            9C8F7684592696656221D5C1CADA9780118BC589E4B03C65A90EA8EEDDB9D9F7
            ACB423CC32B12C130BA90E56D6FE0CC6E3D561613A4775407507E7E6E8BF7475
            E21F30B12C130BA90E96953AFFBB2F16D73FD38A16AA03AA531D7332B12C130B
            A90E96957AA9C6FDD56125EA42754075FEC26A4E2696656221D5C19A4E9CFCDD
            5F506E01BA81EA80EA6E7829F9CB829C6762592616521DACE944428C7E1B2B4B
            CF08AA03AA531D7332B12C130BA90E1674EECCB75E54A43AA03AD5312713CB32
            B190EA6041E79EB5B05E54A43AA03AD5312713CB32B190EA6035A74F7BEB4545
            AA03AA531D7332B12C130BA90E5673FAE519D68B8A540754A73AE66462592616
            521D2CE5CA396FBDA848754075DE39774E2696656221D5C152521F07DEC27A31
            39D501D5B5AFDBDD3F43C9897FC0C4B24C2CA43A5847F7E478592FA6A73AA0BA
            2B4B77FB996B47986562592616521DAC634475BC2C1973531DB0805EABF7C189
            6C47986562592616521D2C625072BC2C1973531DB0988B8BF9BB73D98E30CBC4
            B24C2CA43A5884EAD893EA80B59D58DB7F3D9DED08B34C2CCBC442AA83158C4B
            8E9725636EAA0376D37ED6875FE5C43F6062592616521DAC40756C4B75C0E61A
            3FEEC38E30CBC4B24C2CA43A28AFEF797EFA4306F93ABADB86A63A8016768459
            2696656221D54179A3ABE3CA77DBCA3D1F307CFC437F521DC0CBDA9E67625926
            16521DD4D6FD24B76A9CF34872BC5407D0C6DA9E6562592616521DD4A63A26A1
            3A809959DBB34C2CCBC442AA83C2469CE1568D73540730336B7B968965995848
            755098EA9887EA0066666DCF32B12C130BA90EAA1A747A5B354E782A395EAA03
            68636DCF32B12C130BA90EAA521DF3501DC0835ADEB6DBDA9E6562592616521D
            9434EEDC7EB737B5701C501DC0835AAE087684592696656221D54149AA632AAA
            0378D0C1D97DBC0238F10F98589689855407250DFD04F1412F52BFFE7EBE8316
            AFCFFB7BE2FB879BFE7137BBF106A80E585ECB3A6047986562592616521D9474
            737574FC00908B3BFBA1CFE7647F4A4B72F4BDE557EE8BEA80E5A516A59713FF
            903D7496898554075575DF8BBFFBFE7DDF8AF7FAF309835E31FFD3F10F9AE4EA
            AE3A80AF66F86DC81AECA1B34C2CA43A60AC8BCDD037AE3AA6C2249776D501FC
            EAF1BFFFACCE1E3ACBC442AA03C69AA73AB2C9F1521D407D1F2FABB323CC32B1
            2C130BA90E18EB4A758C7EA2E3EBF73CB75C3EF8EE550737FBD79BA43A606776
            84592696656221D501634D5B1DC79FA575EE05E5AA0338A1D7EBE85A7EC4574E
            FC032696656221D501634D521D83F240750017DDB38CD8116699589689855407
            8C757C413DE88A479EE898E4DB9EBE013FA90E989CEA9893896599584875C058
            0717D4D34172FD6674F99EE15DB881EA80EA54C79C4C2CCBC442AA03C63A571D
            B77D32E09C7FB875FD7EFDBC49AA03E6A43AE66462592616521D30D6BB0B6AFB
            3B4A0DFA6BA8773FBACBBDBB8DEA80F91D2F68AA634E2696656221D50163CD53
            1DAFDE3BEFC79323BC472FD50113387EAE5575CCC9C4B24C2CA43A60AC5F2FA8
            EDD7E0BE0B56DF0FEB551D408B193E54D48E30CBC4B24C2CA43A60B89F15F154
            75FCBC3DEFB4FC5CD501B44855C7A71B7EE7E2C43F6062592616521D305CAA3A
            4627C7AFB7EAD75B92FD0EAA03F8D5B9EAF8E9CA796A47986562592616521D30
            DCB79048FDBF77DEB66FC29FAE3A80AC5E05F2E1F45F8466BF7C432696656221
            D501C3CD5C1D3F6F61FB4F571DC0157D0BE4C3BB73D98E30CBC4B24C2CA43A60
            B8D4FBB77CFB5F9FBD9D07B76186E478A90EA82FF5961B21D5D18B8965995848
            75C07055AAE3956909D50174D1B2985C7F172C3BC22C13CB32B190EA80E1C295
            28F524C3E91BD0F72FA65407D0457631693FEBC3AF72E21F30B12C130BA90E18
            2E8C8AA1D5D17845CFDE06D50174D4F8CB91775FF8C95F58F56262592616521D
            30DCD0EAF8FCDAD4B53654E2A5E42DF74E75002F3BC23C13CB32B190EA80E1C2
            0DFA951D7CF89E57AAA3E55FBA30C0DAEC08B34C2CCBC442AA03861B571DDD5F
            85D97E03540750881D6196896599584875C01D52CF48F4AD8E5FFFE53BE77EF4
            83ABAAEA005AD8116699589689855407DCA1FDD5172392E3E0ABB25F7EE5068F
            A03A80167684592696656221D501258D7EB3DD2A5407D0C28E30CBC4B24C2CA4
            3AA0A4495E56F138D501B4B023CC32B12C130BA90E284975FC3A879F5407F0B2
            23CC33B12C130BA90E28699217733F4E75C01A46BF54CC8E30CBC4B24C2CA43A
            A01E4F747C521DB086F6DFA4747C230D27FE0113CB32B190EA807A54C727D501
            0B687C7B8C2B6FC16747986562592616521D50CF24EF5A3B03D5010BB8581D07
            5F72FCB54EFC032696656221D50114A63A60012DCFDFB67CD469F693529DF807
            4C2CCBC442AA03284C75C00254C7844C2CCBC442AA03284C754075E792E3DDA9
            FDEE5CB623CC32B12C130BA90EA030D501D59DA88EAFFF46750C626259261652
            1D4061AA03AA0BB3217CADF9E93FD072E21F30B12C130BA90EA030D501D51D37
            43CBDB5BA98E114C2CCBC442AA03284C75C0020E3E2250753CC5C4B24C2CA43A
            80C254072CE05D759CFB1C0FD5D1858965995848750085A90E58C0BB6C501D0F
            32B12C130BA90EA030D5010B68F92C8E57F3FB53A98E2E4C2CCBC442AA03284C
            75C01AAE7C08A0EA18C1C4B24C2CA43A80C254072CE3DC49EAF33A0631B12C13
            0BA90EA030D501CB3838490FCE50D531888965995848750085A90E58C9BBF3B4
            BD2554472F2696656221D50114A63A60678D4F74BCEC08F34C2CCBC442AA0328
            4C75C0CE54C7382696656221D50114A63A60739FA7F6F1596C47986562592616
            521D4061AA03686147986562592616521D4061AA03686147986562592616521D
            4061AA03686147986562592616521D4061AA03686147986562592616521D4061
            AA03686147986562592616521D4061AA03686147986562592616521D4061AA03
            686147986562592616521D4061AA03DA357EB4C592EC08B34C2CCBC442AA0328
            4C7540A39FA7C05687BD1D61968965995848750085A90E68B4F99668F3BB7F82
            8965995848750085A90E6874700AEC70FCDB1166995896898554075098EA8046
            9B9F027684592696656221D50114A63AA051FBC9B2243BC22C13CB32B190EA00
            0A531DD0283C593EAC7A2ED81166995896898554075098EA80468DD5F15AF474
            B023CC32B12C130BA90EA030D5018DDAABE375CB1971F38787D8116699589689
            8554075098EA8046A9EAF830EEBCF87663EE8C9C9B7F6E5D2696656221D50114
            A63AA0D1BB2DD123A7C6FD1F596847986562592616521D4061AA031A1D6F896E
            FE348FFBF7677684592696656221D50114A63AA051B825BAF31C511DF333B12C
            130BA90EA030D5018D5AB644B79D26AA637E2696656221D50114A63AA051FB96
            E886BFB6521DF333B12C130BFDFFEDDDEB4EE4CA0E8051CEFBBFF4190909B181
            4E95133B1D57ADF573EF9906AC89BB3EFAA63A80C654074C0A1D89AAAF17D5F1
            7C2616656243AA03684C75C0A4E891A8F492511DCF6762512636A43A80C65407
            4C3A77242A7AB695EA783E138B32B121D50134A63A60D2E92351C5B5A33A9ECF
            C4A24C6C4875008DA90E9874E548947EF9A88EE733B128131B521D4063AA0326
            5D3F12253EDB4A753C9F894599D890EA001A531D3029E54894751DA98EE733B1
            28131B521D4063AA0326651D89522E25D5F17C2616656243AA03684C75C0A4DC
            23D1C5675BA98EE733B128131B521D4063AA0326A51F89AE5C53AAE3F94C2CCA
            C4865407D098EA80491547A2D39795EA783E138B32B121D50134A63A6052DD91
            E8C4B3AD54C7F3995894890DA90EA031D501934A8F44D1EB4B753C9F894599D8
            90EA001A531D30A9FA4814BAC454C7F3995894890DA90EA031D50193EE39124D
            3EDB4A753C9F894599D890EA001A531D30EFF75550F12F7FE65A531DCF676251
            2636A43A80C65407CCFB7115D4FDB31F5E6EAAE3F94C2CCAC4865407D098EA80
            A8CF6BE1867FF3C3CBF307D5F1282616656243AA03684C75C09385C243753C8A
            894599D890EA001A531DF070F3E1A13A1EC5C4A24C6C4875008DA90E6861A63D
            54C7A3985894890DA90EA031D5015DCC5FADB77D7517FE01138B32B121D50134
            A63AA091375E864E84512616656243AA03684C75403B6F399C39114699589489
            0DA90EA031D5011DDDF37985C75FF1862FDA9A894599D890EA001A531DD0D7F7
            AB52753C8D894599D890EA001A531DC00C27C228138B32B121D50134A63A8019
            4E84512616656243AA03684C7500339C08A34C2CCAC4865407D098EA00663811
            46995894890DA90EA031D501CC70228C32B128131B521D4063AA0398E1441865
            62512636A43A80C6540730C38930CAC4A24C6C4875008DA90E60861361948945
            99D890EA001A531DC00C27C228138B32B121D50134A63A80194E845126166562
            43AA03684C7500339C08A34C2CCAC4865407D098EA0066381146995894890DA9
            0EA031D501CC70228C32B128131B521D4063AA0398E144186562512636A43A80
            C6540730C38930CAC4A24C6C4875008DA90E6086136194894599D890EA001A53
            1DC00C27C228138B32B121D50134A63A80194E84512616656243AA03684C7500
            339C08A34C2CCAC4865407D098EA0066381146995894890DA90EA031D501CC70
            228C32B128131B521D4063AA0398E144186562512636A43A80C6540730C38930
            CAC4A24C6C4875008DA90E6086136194894599D890EA001A531DC00C27C22813
            8B32B121D50134A63A80194E84512616656243AA03684C7500339C08A34C2CCA
            C4865407D098EA0066381146995894890DA90E58CDF020FE698D55A83A80194E
            84512616656243AA031631191B3F745F88AA0398E144186562512636A43AA0B7
            73B1F15DEB9DA83A80194E84512616656243AA03BABADE1B9F5AEF44D501CC70
            228C32B128131B521DD092E4989C83EA003E9C08E34C2CCAC4865407F42339BE
            A80E6086136194894599D890EA807E52AA638D55A83A80194E84512616656243
            AA039A39383D6FB8DD540730C38930CAC4A24C6C4875402792E307D501CC7022
            8C32B128131B521DD0C6AB73F3CE4B4D7500339C08A34C2CCAC4865407B461A3
            FDA63A8019F66794894599D890EA80366CB4DF540730C3FE8C32B128131B521D
            D08375F627D501CCB042A34C2CCAC4865407F4609DFD49750033ACD028138B32
            B121D5010DD865AFA80E60862D1A6562512636A43AA001BBEC15D501CCB045A3
            4C2CCAC4865407346097BDA23A8019B66894894599D890EA8006ECB257540730
            C3168D32B128131B521DD0805DF68AEA0066D8A2512616656243AA031AB0CB5E
            511DC00C5B34CAC4A24C6C4875C0D3596407540730C3228D32B128131B521DF0
            7416D901D501CCB048A34C2CCAC48654073C9D4576407500332CD228138B32B1
            21D5014F67911D501DC00C8B34CAC4A24C6C4875C0D3596407540730C3228D32
            B128131B521DF07416D901D501CCB048A34C2CCAC48654073C9D457640750033
            2CD228138B32B121D5018F668B1D531DC00CBB34CAC4A24C6C4875C0A3D962C7
            540730C32E8D32B128131B521DF068B6D831D501CCB04BA34C2CCAC48654073C
            9A2D764C750033ECD228138B32B121D5018F668B1D531DC00CBB34CAC4A24C6C
            4875C0A3D962C7540730C32E8D32B128131B521DF05CCBAFB0AF1FF0F40F35AC
            8EAFDB571DB09E7FD7F5E4C5BBFC3A9D64625126964875C0732DBFC2BEFF80E7
            7EAEC9EA185A69AAB089D0AF2D965FA7334C2CCAC472A90E78AEB557D88F9F4E
            7500F3A20B64ED753AC3C4A24C2C9DEA80E75A7885A524C787EA802D9DD88D0B
            AFD319261665621554073CD7C22B4C7500A7BDBAF00F2EE485D7E90C138B32B1
            0AAA039E6BE11576BD3AB27AE3E2B701BC45F450B8F03A9D64625126964E75C0
            732DBCC22E564745729CFB4E8077091D0A175EA7F34C2CCAC472A90E78AE8557
            D895EAA84B8E13DF0CF046F387C285D769888945995822D501CFB5F00A531D40
            8AC943E1C2EB34CAC4A24C2C8BEA80E75A78857986159065E650B8F03A3DC1C4
            A24C2C85EA80E75A7885A90E20D1F050B8F03A3DC7C4A24CEC3AD501CFF5B415
            F6FBFBA9AB85739FC77491BB07E8EBF850F8B475FA042616656217A90E78AE13
            EF177EF37712FA96429D907E83295F1178B2839DE944F827138B32B12B54073C
            D7C1A9FAB64596980AE9D511BDCDEB5F0E78B88A3DB336138B32B1D354073C5A
            CAA9FACE4FFE8E7E6EEBC5EF5975003F243E93731326166562E7A80E78B4F79E
            AADF551DF3DFADEA007E9BDC0C2EFC2F2616656227A80E78B4C4972E5C7FE5F7
            F043914EBC18E3E246561DC09F6696830BFF3B138B32B128D5014FF7AE2759CD
            E7C1E79F3CF79CA8CDABA3FA130F019EAFEFD13CE5AD56F6A13AA081EB67D3D2
            EAB8E766EF3FA097DE5BE80D00CE691A33AA033A3977544D7951C71BABE3BD07
            F4A2E5AE3A00B8A25D7BA80E68E98637D0287AEB71D5F1841F0A80EE5407B088
            A24F0BF97EB337BF3DEE39AA038007521DC03A8E4FC6B7BD56447500C00FAA03
            5847FADB02367A29F9899F2E4A7800704EBBE4F8501DC050E23B035E7C85FA9D
            C7F4DB16BAF600605EC7DEF8A43A802929CFB63AF1A28E2BDFD5BCBE4B1C98E1
            03DDA24C2CCA67770CA90E20E0627BA80EE02D26778555F0C5C4A274DA90EA00
            62AEBCB795EA00DEE286771B5F8C8945E9B421D5019C71EED33C5407F016A15D
            61217C98589C4E1B521DC079A15787A77FD879EEEBB0B7BD1B801DBCFA45C9AB
            3562219858944E1B521DC079A7ABE369C991F55D01CF74F0F0AC63F49F4C2C4A
            A70DA90EE0A7AF15197AEC22F4E72F6EDBBA779BDDF06E007670FCA450E7C2DF
            4C2C4AA70DA90EE03FE65FB0117DC694EA00DE65B8D99C0B7F30B1289D36A43A
            80FF387DA0BFAD3AAA3F566FABFB00D8C4CCEF539C0BBF33B1289D36A43A80FF
            3877A69F599AAA037897C947719D0BBF9858944E1B521DC04FD163FDFD1F4CEE
            195640C8E9E78E1EFFE1859958944E1B521DC01F2A3EED68F245EAB9DF61C80E
            4B1FF614FA88A19DCF85C74330B1033A6D48750053529AE1DF8DE46E559F1208
            CC887EB0E9B6E7C2E30998D8019D36A43A80C6540730237A863EF75756626251
            3A6D4875008DA90E60C6B90371F4FDC1576262513A6D4875008DA90E60C6E9E3
            5DEE0BD21A31B1289D36A43A80C6E65FF57EFC27D75EF4C0955F2AA7BF20AD05
            138BD269E39F5475007D0DAB63F8B9B03FFE18B0A4DD9ECA729D8945E9B4F18F
            A93A80BE540730C3193ACAC4A24C6C4875008DA90E6086136194894599D890EA
            001A531DC00C27C228138B32B121D50134A63A80194E84512616656243AA0368
            4C7500339C08A34C2CCAC4865407D098EA0066381146995894890DA90EA031D5
            01CC70228C32B128131B521D4063AA0398E144186562512636A43A80C6540730
            C38930CAC4A24C6C4875008DA90E60C6EF0DE0AA3FE60C1DE5DFD890EA001A53
            1DC0A41F4BC0557F4C759CE0DFD831D50134A63A8049DF97804B7E48759CE0DF
            D831D50134A63A002AA80ED2A90EA031D501504175904E75008DA90E800AAA83
            74AA03684C750054501DA4531D4063AA03A082EA209DEA001A531D00155407E9
            5407D098EA00A8A03A48A73A80C654074005D5413AD50134A63A002AA80ED2A9
            0EA031D501504175904E75008DA90E800AAA8374AA03684C750054501DA4531D
            4063AA03A082EA209DEA001A531D00155407E95407D098EA00A8A03A48A73A80
            C654074005D5413AD50134A63A002AA80ED2A90EA031D501504175904E75008D
            A90E800AAA8374AA03684C750054501DA4531D4063AA03A082EA209DEA001A53
            1D00155407E95407D098EA00A8A03A48A73A80C654074005D5413AD50134A63A
            002AA80ED2A90EA031D501504175904E75008DA90E800AAA8374AA03684C7500
            54501DA4531D4063AA03A082EA209DEA001A531D00155407E95407D098EA00A8
            A03A48A73A80C654074005D5413AD50134A63A002AA80ED2A90EA031D5015041
            75904E75008DA90E800AAA8374AA03684C750054501DA4531D4063AA03A082EA
            209DEA001A531D00155407E95407D098EA00A8A03A48A73A80C654074005D541
            3AD50134A63A002AA80ED2A90EA031D501504175904E75008DA90E800AAA8374
            AA03684C750054501DA4531D4063AA03A082EA209DEA001A531D00155407E954
            07D098EA00A8A03A48A73A80C654074005D5413AD50134A63A002AA80ED2A90E
            A031D501504175904E75008DA90E800AAA8374AA03684C750054501DA4531D40
            63AA03A082EA209DEA001A531D00155407E95407D098EA00A8A03A48A73A80C6
            54074005D5413AD50134A63A002AA80ED2A90EA031D501504175904E75008DA9
            0E800AAA8374AA03684C750054501DA4531D4063AA03A082EA209DEA001A531D
            00155407E95407D098EA00A8A03A48A73A80C654074005D5413AD50134A63A00
            2AA80ED2A90EA031D501504175904E75008DA90E800AAA8374AA03684C750054
            501DA4531D4063AA03A082EA209DEA001A531D00155407E95407D098EA00A8A0
            3A48A73A80C654074005D5413AD50134A63A002AA80ED2A90EA031D501504175
            904E75008DA90E800AAA8374AA03684C750054501DA4531D4063AA03A082EA20
            9DEA001A531D00155407E95407D098EA00A8A03A48A73A80C654074005D5413A
            D50134A63A002AA80ED2A90EA031D501504175904E75008DA90E800AAA8374AA
            03684C750054501DA4531D4063AA03A082EA209DEA001A531D00155407E95407
            D098EA00A8A03A48A73A80C654074005D5413AD50134A63A002AA80ED2A90EA0
            31D501504175904E75008DA90E800AAA8374AA03684C750054501DA4531D4063
            AA03A082EA209DEA001A531D00155407E95407D098EA00A8A03A48A73A80C654
            074005D5413AD50134A63A002AA80ED2A90EA031D501504175904E75008DA90E
            800AAA8374AA03684C750054501DA4531D4063AA03A082EA209DEA001A531D00
            155407E95407D098EA00A8A03A48A73A80C654074005D5413AD50134A63A002A
            A80ED2A90EA031D501504175904E75008DA90E60439F0BAD7471A90ED2A90EA0
            31D5016CE8FB422B5A5FAA8374AA03684C75001B521D74A43A80C65407B021D5
            4147AA03684C75001B521D74A43A80C65407B021D54147AA03684C7500EBF9BD
            AF7EEC28D54147AA03684C7500EB196EB6EF54075DA80EA031D501AC27541D5F
            72F798EA209DEA001A531DC07ACE55C76F57369BEA209DEA001A531DC0DAB20A
            E4CBE4BA531DA4531D4063AA03D8C79D05A23A48A73A80C65407B0A1C4FC78B5
            FD5407E95407D098EA0036F4E73BE79E4E913F17A0EA209DEA001A531DC08626
            3FAF63B2435407F7501D4063AA03D8D0954F09FCB10C3DC38ADBA80EA031D501
            504175904E75008DA90E800AAA8374AA03684C750054501DA4531D4063AA03A0
            82EA209DEA001A531D00155407E95407D098EA00A8A03A48A73A80C654074005
            D5413AD50134A63A002AA80ED2A90EA031D501504175904E75008DA90E605B5F
            6B6D6683FDFBC3A145A73A48A73A80C65407B0A7EF3BED60839D8E07D5413AD5
            0134A63A800DFD5E687F2EB183BD375C7AAA8374AA03684C75001B9AA98EF9F5
            38F925867F058EA90EA031D5016CE8C7428B3ED071FC170FFEBA55C915AA0368
            4C75001B1A56C7AB0743269F9AF5A13A28A03A80C65407B0A1E14BC90FB264E6
            71920FD54101D50134A63A800D1D57C7F0018D99F7BF521DA4531D4063AA03D8
            D041369C78A1F9FCCB42AC4AAE501D4063AA03D890EAA023D50134A63A800DBD
            AA8E739FE3A13AB887EA001A531DC0865E6583EAE0C95407D098EA0036F46736
            CC7782EAE02D5407D098EA00F674E5430055076FA13A80C65407B0A7D3D5E1F3
            3A7817D50134A63A806D9D5B6BAA8377511D4063AA03D8D9ABCD76B0D35407EF
            A23A80C65407C0CC678DFFFE93C77F5E75904E75008DA90E8090C944511DA453
            1D4063AA0320E46B19461F1519FE1538A63A80C654074005D5413AD50134A63A
            002AA80ED2A90EA031D501504175904E75008DA90E800AAA8374AA03684C7500
            54501DA4531D4063AA03A082EA209DEA001A531D00155407E95407D098EA0088
            9AF9C80ED5413AD50134A63A00A27EEFC3DF3B5075904E75008DA90E80A8837D
            78BC33AD4AAE501D4063AA03206A6673AA0ED2A90EA031D50170C27079FEC9AA
            E40AD50134A63A00AE08E58755C915AA03684C75005C37D91E562557A80EA031
            D501ACE7FBBEBA733BCD6F54384175008DA90E603D4FD8575E4D4E3AD50134A6
            3A80F53CE1B516AA8374AA03684C7500EB39F706535F52169AEA209DEA001A53
            1DC0922E86C777E7F69BEA209DEA001A531DC0AA12C3E387998DA73A48A73A80
            C65407B0AA1F5BEB734DA5A7C8ABEDA73A48A73A80C65407B0B03FC3E3F8CF44
            A90E6EA33A80C65407B0B699F038F8F333E663C6AAE40AD50134A63A80E545C3
            E3F8AFFFA63AB887EA001A531DC00E2E86C7C1AD798615B7511D4063AA03D8C1
            EF0D56BDB55407E95407D098EA003631F30045D197BBF3EBB230D50134A63A80
            7D7CEEB17BF695EA209DEA001A531D00155407E95407D098EA00A8A03A48A73A
            80C654074005D5413AD50134A63A002AA80ED2A90EA031D501504175904E7500
            8DA90E603D5FFBEA8DAB4975904E75008DA90E603D377F34C7F07B78FB37C31A
            5407D098EA00D633AC8E1B1E0C511DA4531D4063AA0358CF7C757C94AD2FD541
            3AD50134A63A80F5A80E96A43A80C65407B01ED5C1925407D098EA00D6F3635F
            FD5E50AA838E5407D098EA00D6A33A5892EA001A531DC0925EADACCF65A53AE8
            4875008DA90E6049C3E5F64575D085EA001A531DC0AAE6C3E353EE1E531DA453
            1D4063AA035858343C7EB8B2D95407E95407D098EA009677B13D7E985C77AA83
            74AA03684C75001B4AEC9057DB4F75904E75008DA90E6043BFDFC3EA7487A80E
            6EA33A80C65407B0A1D087970FCDDF8255C915AA03684C75001B8A7E5EC78905
            A83A48A73A80C65407B0AD7F6BEDDCEEFADA87077F5D75904E75008DA90E800A
            AA8374AA03684C750054501DA4531D4063AA03A082EA209DEA001A531D001554
            07E95407D098EA00A8A03A48A73A80C654074005D5413AD50134A63A002AA80E
            D2A90EA031D501504175904E75008DA90E800AAA8374AA03684C750054501DA4
            531D4063AA03A8F3B537365C11AA8374AA03684C7500757EEC8DAD1685EA209D
            EA001A531D409DDF7B639F5DA13A48A73A80C6540750E7D5DED86163A80ED2A9
            0EA031D501D439D81BCB2F0DD5413AD50134A63A803A3BEF0DD5413AD50134A6
            3A803AC30DF3B1EEF6501DA4531D4063AA03A833531D1F8B2E10D5413AD50134
            A63A803A93D5F171CB0EB9F9C3435407E95407D098EA00EACC57C7A7BA4D72FF
            2787A80ED2A90EA031D501D479F5791DF7BFB7D5FD9F1CA23A48A73A80C65407
            50E7E0AC7F7378DCDF00AA8374AA03684C7500758E1F61B873ABA80E16A03A80
            C654075067E6794DF73CE8A13A5880EA001A531D409DC95753DC101EAA8305A8
            0EA031D501D4997F0D77F586511D2C4075008DA90EA04EF49DA3EA1EF4501D2C
            4075008DA90EA0CE89F7AB2D0A0FD5C1025407D098EA00EA9CFB948C8A6DA33A
            5880EA001A531D409D2B9FCD97FBA087EA6001AA03684C7500752E7E22786278
            A80E16A03A80C6540750E762757CE46D1ED5C1025407D098EA00EA5CAF8E57B7
            13BD41D5C1025407D098EA00EA6455C7C7E5F0501D2C4075008DA90EA04E6275
            7C5CDB42AA8305A80EA031D501D4C9AD8E57B73973E3AA8305A80EA031D501D4
            A9A88E8F53E1A13A5880EA001A531D409DA2EA7875E3075F4575B000D50134A6
            3A803AA5D5F111090FD5C1025407D098EA00EA5457C7C77478A80E16A03A80C6
            540750E786EA78F5857E7C45D5C1025407D098EA00EAFCD81BF79FF2BFBEAEEA
            6001AA03684C7500D53EB7C70D5B62B8D07E501DF4A23A80C65407B098F9F650
            1DF4A23A80C65407B09EC9F0501DF4A23A80C65407B0A499F0501DF4A23A80C6
            5407B0B0372E2ED5413AD50134A63A80B5853EC2BCFAEB5A955CA13A80C65407
            B0BC57EB4B75D08BEA001A531DC0266EFBC8C2575FAEFA2BB23CD50134A63A80
            7D7CDF63D55B4B75904E75008DA90E800AAA8374AA03684C750054501DA4531D
            4063AA03A082EA209DEA001A531D00155407E95407D098EA00A8A03A48A73A80
            C654074005D5413AD50134A63A002AA80ED2A90EA031D501504175904E75008D
            A90E800AAA8374AA03684C750054501DA4531D4063AA03A082EA209DEA001A53
            1D00155407E95407D098EA00A8A03A48A73A80C654074005D5413AD50134A63A
            002AA80ED2A90EA031D501504175904E75008DA90E800AAA8374AA03684C7500
            54501DA4531D4063AA03A082EA209DEA001A531D00155407E95407D098EA00A8
            A03A48A73A80C654074005D5413AD50134A63A002AA80ED2A90EA031D5015041
            75904E75008DA90E800AAA8374AA03684C750054501DA4531D4063AA03A082EA
            209DEA001A531D00155407E95407D098EA00A8A03A48A73A80C654074005D541
            3AD50134A63A002AA80ED2A90EA031D501504175904E75008DA90E800AAA8374
            AA03684C750054501DA4531D4063AA03A082EA209DEA001A531D00155407E954
            07D098EA00A8A03A48A73A80C654074005D5413AD50134A63A002AA80ED2A90E
            A031D501504175904E75008DA90E800AAA8374AA03684C750054501DA4531D40
            63AA03A082EA209DEA001A531D00155407E95407D098EA00A8A03A48A73A80C6
            54074005D5413AD50134A63A002AA80ED2A90EA031D501504175904E75008DA9
            0E800AAA8374AA03684C750054501DA4531D4063AA03A082EA209DEA001A531D
            00155407E95407D098EA00A8A03A48A73A80C654074005D5413AD50134A63A00
            2AA80ED2A90EA031D501504175904E75008DA90E800AAA8374AA03684C750054
            501DA4531D4063AA03A082EA209DEA001A531D00155407E95407D098EA00A8A0
            3A48A73A80C654074005D5413AD50134A63A002AA80ED2A90EA031D501504175
            904E75008DA90E800AAA8374AA03684C750054501DA4531D4063AA03A082EA20
            9DEA001A531D00155407E95407D098EA00A8A03A48A73A80C654074005D5413A
            D50134A63A002AA80ED2A90EA031D501504175904E75008DA90E800AAA8374AA
            03684C750054501DA4531D4063AA03A082EA209DEA001A531D00155407E95407
            D098EA00A8A03A48A73A80C654074005D5413AD50134A63A002AA80ED2A90EA0
            31D501504175904E75008DA90E800AAA8374AA03684C750054501DA4531D4063
            AA03A082EA209DEA001A531D00155407E95407D098EA00A8A03A48A73A80C654
            074005D5413AD50134A63A002AA80ED2A90EA031D501504175904E75008DA90E
            800AAA8374AA03684C750054501DA4531D4063AA03A082EA209DEA001A531D00
            155407E95407D098EA00A8A03A48A73A80C654074005D5413AD50134A63A002A
            A80ED2A90EA031D501504175904E75008DA90E800AAA8374AA03684C75005450
            1DA4531D4063AA03A082EA209DEA001A531D00155407E95407BB181E4F81F538
            24C139AA8374AA835DA80ED89043129CA33A48A73AD885EA800D3924C139AA83
            74AA835DA80ED89043129CA33A48A73AD885EA800D3924C139AA8374AA835DA8
            0ED89043129CA33A48A73AD885EA800D3924C139AA8374AA835DA80ED8904312
            9CA33A48A73AD885EA800D3924C139AA8374AA835DA80ED89043129CA33A48A7
            3AD8C57175D8A4D0944B1B2AA80ED2A90E76E168024B72694305D5413AD5C12E
            1C4D60492E6D98F7EF7A99BC285407E95407BBC83A9A7CDD8EE50B4FA03A6052
            E8FE4B75904E75B08BEB47132B181E4875C08C1F57CAF0D27097473AD5C12E4E
            1F4D9C69E0C95CA1307422215407E95407BB387134997CB35D5B18DE4875C0D0
            ABCB24FA1B37171457A80E76317F34097DB287150C37F8BC2A4FFC76E0F75F39
            B8295858343C5407E95407BB98399A9CF824412B18AA1D3F1FFDF42F145CBCEC
            26141EAA8374AA835D547C36B9FD0BD586479FC9EA7084828F4878B86448A73A
            D8456E75D8BC708FE121E9CAC3982E6436347939A80ED2A90E7691551D762EDC
            ECF89034AC0EC9013FCC5C14AA8374AA835D5CAC0EAB16DEE5E0E23D888A2117
            353B3BF728A2AB862B5407BB703481BED25F97E5BA86138F22BA70B84275B038
            B1016B480C0F57377C3A080FD5413AD5C1B2F4062C26253C5CE0F09D8FA8E236
            AA83D5880D5898176841BAF9CBCA15C415AA83755C398ED8A4D085DF2C40BAC9
            CBCA45C415AA83F62A3EFE0F588CD3121C9BB933751D7185EAA031BD01A4B8E1
            2C655FC12B626613AA837EDC7903158A8E3E5616CCD01ECB531D7472E5F9DCEE
            F88163AA03DE48752C4F75D040CACBC4DDF103C75407BC91EA589EEAE0D112DF
            ACC61D3F704C75C01BA98EE5A90E1E2AFDCD31DDF103074A4F3CF60F1C931C3B
            501D3C4BDD3BF1BBD707FE74DB71C71682DFF4C63E54074F51FDC95FEEEF6167
            4E361032BCD3744D11A53A78B3DB3E665875C0E61C92609E0F0D249DEAE06D6E
            EB0D6019177F7D607BC0A4C96BCD35C53CD5C1DDC406704ECA23963609CC98BF
            DC5C534C521DDC476F00A7253E49D24A81A1D015E79A6286EAA05CCA67FC013B
            3B5823FFB6C49FFFF7D57FFFFABFEFFE99E0D1A297956B8A21D541210F6E00D7
            0DE3E1D5F168E6EF027F3A7159B9A638A63A0A7D5E961B5E841EDC00120D8F38
            07C7A30F1B094E397759B96438A03AAAFCB82037B90E3DB801E49A39DC9C7BAC
            639E05C5868EABE3437810A73A4AFCBE14D7BE08FD2A1128323CFA7CC49F807E
            8E65C5564E5F7A1F2E165E501DF9B6BA083DB801541B3E747CDB67805A5CEC63
            A63A3E363BF37091EAC8B7C915A83780DB1CBF4CEEB6EAF8B0C1D8C664757C6C
            73ECE13AD5916CF9F74B111BC0D3A80E48375F1D1FC28339AA23D9C2D5A13780
            67BAB33A3EEC34F610AA8E0FE1C104D591E9F89EAFE98527368087FBF30D3CA2
            67A6E16D9EBB1D68EAC41574F1A26379AA23D362F7527A03E8E2F72BCEAF1F80
            167EEC1A86CE5D417B7E6C009354479AE119BDCBB527368076BE2FAE83F7CC8D
            AE294F1A615BA7BBFDEB2FBA4CF84175A49939AC3FFC0AD41BC01A126B4178B0
            A72B8F16FEFBBB2E107E531D3926CFEBCFBC087DC61FB018D50117799106E954
            478EA6D5E1C10D6049B90726C72F36E49F3DE95447825757E69F6FABF2EE6FF6
            E5373CE9213F02C001D50117F9674F3AD591A05175787003D881EA808BFCB327
            9DEAB8EAE0B27C4E75787003D847FA2B311CBFD8907FF6A4531D5785AAE3E3F6
            2BD6831BC06ED277EF139639DCCC3F7BD2A98E4B8EAFC9F75EB17A03D8D30D4F
            AFBA7283D082EA209DEAB8E481D5213680CD7951075CE75F3EE954C779C30BF2
            E62B566F007CA4EE5E072FB6E51F3FE954C7793317E40D2F28171B00DF659D96
            3CB78A9D3DE71D715886EA3869F25EADF4A2D51B003F543FD071FAD6A09D1F97
            807FF95CA43A4E7A6F759CEB0DFB02585EF5031DE76E0D3AFA7E15F867CF75AA
            E38CF97BB58AA7459E480ECB02D844CAD6951C00E954C719F38F60BCBD3ADC41
            025BB9BE7525074005D51116BA4BBBE7C3AA72BF04405FE7B6EECC6AB55701AE
            501D61A1976ADC5F1DEE17816D9D7E8F8D21AB15E022D51173A222D25F50EE2D
            B401FEA43A001E4B75C49C4888EAB7B1725F08F0A9A23AEC588014AA2320F1E9
            C2EEC600D2A557875D0D904575049C7BD4427500DC23B13A6C69805CAA63D6E9
            78501D00F7B85E1D96334011D531EBF4CB335407C00D2C5B8027531D53AEDC99
            B92304B8C16ECBF6FBCF7BFDC7CCBD3580DF54C714AF500478B89DABE3E24F9A
            785300AFA88E316FC508F07C5B5587E400DA511D63451F3B65B30324521DD76F
            E7CA4D011C531D033EE916A005D571E516AEDC14C00CD531A03A009E6FABE4F8
            B85C1D07776D0B0F0D782FD571A42E393E6C76803C5B55475D729CB8358049AA
            E388EA006841759CFBBBBFAD3A34E0ED54C74BB9F76177BE62EFFAB3759FFF96
            26DE5A1EF84E759CF88B9F7FF7F90B1F5883EA78A9BA3AAEDC5AF40B85BE5C8B
            B7347137097CA73A4EFF45BFC401EEA13AFE967E0776C33D62CAE3E69203E848
            7544FFE2D7DF521DC03D54C7DFD6AB8EE1D76AF42E8AAA03F8EEF9C991F202EE
            D04B0DFFBCCDAF5BF8FE7F5507700FD5F1878A3BB0EA3BC58B8F51F47A1745D5
            017CF7F0EA98AC85E36F38FAEE26171F000148A73AFEB0407524BEA5C903EF84
            5407F0DD63AB2331158AAAC33A056EA33A7E2ABAF72ABD53DCEA5D14DD47023F
            3CB33ACEBDF7FAAB6FFBFAD3AB666EF6ED430316A63A7EDAAA3ADA25C7951F16
            585597EAF8F12D9D78666CFA02F4F42AE036AAE33FEAEEBA4A5FAB9DF82E8ACF
            3FD33FFF3B046ED6A23A860F629C789B41D50134A23AFE63E7EAF8FDC6ED59DF
            5EAEE77F87C0CD9E5F1D6F7F64FBCE6F12E04FAAE33F4A3FADE29E77E30D7D89
            DFBF63AB3ED3877EAB97FBC302AB7AE0070D15EDD2DC9BF54B1CE04EAAE33F6E
            AE8E1B9223FA854A7F9176E5DB2BFA7981359CFE8D46F5F7F3E5BD8F6CDF706B
            00C754C71F3E1771D1FECDBAF18A5378FADD64D63759F746F500456E7813F647
            DD1AC031D5D1D50DD57167727CA80E602D159FBEAA3A80BE544757F307F1B73C
            BD2AF78DEA8B7E5E8052B99FC1EAA5E4406BAAA3B7C7FEDE6B7853E79ECDE53E
            12E825F163915407D09AEAE8AD6F75FCF863279E03E63E1268A1E84D359EB3F0
            0166A88EDE1E7B27549407AA0368EAFAB3AD1EBBF00166A88EDEEE7F74E2C4AD
            A90E804F575E62AE3A80D654476F2DAAE3FAADFD79B3EE2381A6CEBDA96E8B2D
            0DF08AEAE82DF1147EC3DBE63EEA3B0478AFD09B6A782939D09DEA68ECC9BFF7
            AA7EA37AF791C002E617EF93173EC00CD5D1D8C3EF8472DFA8FE4375007DFCDB
            57B9EF06FEF0850F30A43A1A7BEC8B3A5EDDEC6FA12FA43A80E72B7AF8427500
            DDA98EC61EFBA28EE31BFFEDFEB78C042832F3E91CBF792939B03CD5D15897EA
            F8F34B44BF9CFB48A005D501F027D5D158AFEAF8F30BCD7F45F791400B27AAC3
            4704023B501D8D75AC8E3FBFDCCC17751F0974110A8FC96D96FBC2362F9303EE
            A73ABAEAFE7BAFD01BD57FB88F041A4A7C0F71D50174A73ABAEAFB40C789AFEB
            810E0080D65447578FAD8ECF5B7BF21BD503007033D5D1D533AB63F2A6AE3CBD
            EAFACF0B00C0CD5447576FA98EAF3F399F1333BC811500C0DA544757EFAD8E57
            7F4C750000F09BEAE8EAFEEA98F9632DDEA81E00809BA98EAE9E591D7FFEC957
            E6BF6DD50100D09AEAE86AFEADA2526EEDDCB9FFF42791BFBA1DBD0100D091EA
            608A471B0000384D7530C507D90200709AEA60CC031D00005CA13A18F3400700
            0057A80E063CD00100C045AA8301D50100C045AA83B1DC77E905006037AA0300
            00A8A53A0000805AAA030000A8A53A0000805AAA030000A8A53A0000805AAA03
            0000A8A53A0000805AAA030000A8F53F1F380D000094521D0000402DD5010000
            D4521D0000402DD5010000D4521D0000402DD5010000D4521D0000402DD50100
            00D4521D0000402DD5010000D4521D0000402DD5010000D4FA3FA9EAB146E8E3
            21C50000000049454E44AE426082}
          Proportional = True
          Stretch = True
        end
        object Image2: TImage
          Left = 3
          Top = 18
          Width = 250
          Height = 375
          Center = True
          Picture.Data = {
            0954506E67496D61676589504E470D0A1A0A0000000D494844520000042A0000
            06380802000000D7B6BB24000000017352474200AECE1CE90000000467414D41
            0000B18F0BFC61050000000970485973000012740000127401DE661F78000085
            ED4944415478DAECDD5D96EB3892265AC5A0AAAB7AFE0F9DD535A8BC91ED713D
            4E1E77A7CC400084017BAF550F95715C220C3FC42752E21FFFE71FFFF7BFFEF3
            3F5E00000023FDE3BFFFE70FF10300009840FC00000026113F00008049C40FD8
            D91F7FFCF1EBFFFBCF7FFEF3E92302008E267EC0CE7E8B1F2F0904007894F801
            DBFA9A3D5EE20700F028F103B6257E005CFB5C27AD8D308DF8017BFA367BBC9C
            6201FE7FBE1D078F103F604FE207C0055F8D83A7881FB0A19FB2C707A758E070
            EE4D8507891FB021F103E082F8010F123F6037D7D9E3E5140B9CCDBDA9F02CF1
            0376237E005CB858242D8F3081F8015B799B3D5ECEAFC0C1DC9B0A8F133F602B
            E207C005F1031E277EC03E22D9E383532C7020F7A6C20AC40FD8C7B73F63EF07
            5E003E881FB002F10336F153CC103F005EEE4D8565881FB0899F9EE02B7EAC26
            7E8FDC27FD05F705A79EE906A3891FB083EB8CF1533261A686D4F1497FC14DBE
            1A07EB103F6007D70143FC78D69DE0F1417FC14DBE1A07EB103FA0BCB76750F1
            E341F7B3C74B7FC13DBE1A074B113FA0BCB7E9C229F6295DB2C74B67C13D178B
            A44F67603EF1036A8B440BF163BE5EC1E3A5A7E01E5F8D83D5881F505BE4DC29
            7ECCE7BA072CC257E36035E2071416CC15E2C764D7D943E5619A86AFC6BD4C52
            184CFC80C2E29FDBF9846FA69FE2879AC364BE1A070B123FA0AAD45953FC9849
            B56105BE1A076B123FA0AAD41ED729761AA58645F86A1CAC49FC8092B2A74CA7
            D839DC76058B882F7A2E57C264E20794943D5F8A1F73A8332CC257E36059E207
            D4D3B0C7B52D9E439D610537BF1AF7326D6124F103EA69F8ACCEF9750E7586C7
            B9371516277E4031CD674A37184C601F038F133F6071E20714D39C22C48FD16C
            62E071EE4D85F5891F50C99DD3A453EC682A0C8F133F607DE2075472E70AC6B8
            53ECE72B1F7EC2B6898167B937154A103FA08C9F9E2971C7FD53ECAF4775F809
            5BFC8067891F5082F80165881F8B133FE041EE4D852AC40FA86144F678891FFD
            D8BEC0B3168F1F2EB0C027F1036A58337EFC7654279F4DC50F78D09A17878307
            66A1E034E2071430287BBCC48F7EC40F78D082F1237B48960BCE217E4001E3E2
            C7EBDE39CF9D579FC40F784A898BC3A3DF0E0A113F607543B3C74BFCE844FC80
            A72C183F1A0EC972C139C40F585DC77D6DF72DB2F8F1B50E9F4E2E084CB3E6BD
            A9911B53AD9F1C4BFC80A5F5DDD78A1F83881FF09405EF4D4D7D29EECF7F6CAD
            E034E2072C6DE5F8E17BE79FC40F78C49AF7A65A1BE19AF801EB1A7AB1E2FE0B
            A64EFC7B9F80C50F78C49AF7A67AC4075C133F605D2336B5A3CFD617363E018B
            1F30DFB217877F5A1BAD09F041FC80450DDAD13E183FBA1CFF9AC40F986FC2F5
            E1EE6BA365015EE2072C6BCBF8D1A509AB913D60BE39178707DD9B6A7DE070E2
            07AC68DC8EB6D72B377FE373BFF3EE22F1C3AF907194C5EF4D7D4920F033F103
            9633F4BEE141F1E3E215B6FF119815E2C7F645865FAD7F71F8EDCBF67A71A848
            FC80E50CDDCE8A1FDD891F3059ADF871F1E27DDF02AA103F6045437FB7B1CB8B
            C76FF5D97E672C7EC04C9343C2D0B577C4BBC0FAC40F58D1E8DDE4FDEF09881F
            DFB6EEA936EE5D64F855DDF831E1F8A104F10368217E7CDBBA47DAE819671C65
            FD8BC30D6F64CE7214F10348F3C58F9F1AF84833B72F32FC4AFC80EAC40F204D
            FCF8A9818F3473FB22C3AF860EF869B3C9B4E564E20790267EFCD4C0479AB97D
            9161B28F3975F37B7127DF950AD7C40F98E7CE296D29BEF8F153031F69E6F645
            862A820B82EF6B7138F10366D86C83287EFCD4C0475ABA7D91A18AEB279DFFC4
            9CE534E2070CB7D9075DA9CDEE093BE3672F8064B73B5B76017BB8FF83E08F6B
            881F455B0A77881F30DC0AF7E78C6BCEC95FFCF8B69993DB6BBBC31EF6F898C6
            C70110217EC0582BDC9C33B445E2C7DB0DC7D086BBD9830D6CB64E466665D1A6
            4117E2078CB5D969F5257E045ADAACA144E2071BD86F9DFCA9757BB4086E123F
            60A02DCFA9BE771E696C9B69F1A3EDBD6084EB316CA0C27EC40F18E8E4F87154
            F6F8B6C90DEEC70F3D422DEE538203891F30CAF6D9E3A7B66CF655FB949B0944
            FCE034E2071C48FC80514E881F41A59B9C752781640BE54790292D3E590C57D8
            89F801436C993D5E7EE635665A48133FA8CB6FD4C2B1C40F1862E5F871E76758
            EC1896227E5097C5048E257E407F55B247C321B9596229BEF841516EE3849389
            1FDCE517CDBF2A143F16392ADA881F1475113F3E06E7CAAB287093F8C12DF634
            DF5AF6A79F963D30DA881F54F4367B5CFC33431736207E708B8FD2BF5AF9433B
            A7F3CD780424E5C41F32B8F25A0ADC217ED0CE5EF65B2B9F3275D94E7CEF9C8A
            82973EAEFFB1010CA5891FB4B397FD6AF193A52EDB893BAF28277EE9E3FA4F8C
            61284DFCA09DB3C257E207D3881FD4D2903D5ECB2FAA4003F18376F6B2BF59FF
            34A9CB76227E504BEAB6ABC81F1AC95094F8413B7BD9DFAC7F8ED4656F7D94A8
            444DC40F0A69BBF471FDE7463214257ED0CEF9E057EB678F972E7BA7D636DDCF
            5E51C5CDECF12AB2C00241E207EDEC657F55E2ECA8CBAE15FA2169973E28A4F9
            B6ABC88B18D2508EF8413B7BD95F95A84689837C4AADE2BC0D15F66A2CE2FEA5
            8FEB9732A4A11CF18376CE049F1EDCEAA5BEABA0CB2ED42ACEF596EE27CB3687
            5D75CC1E2FA11A76217ED0AED6766DA8A74E8AF1BBFF2F8EF3CC2EFBAA56711A
            E2C7B26D61635D6EBB8ABCA0E10D85881FFC1B1FA53758217B04DF51975DA855
            9C6CFC58B6216CACEFA58FEB9735C2A110F183BFF928BDCD23F1A3ED4D75D94F
            CA55261E3F566E057BEB7EE9E3FA650D75A842FCE02F3E4A6FF3F8B73E526FAD
            CB7EA232D0D7A0EC71FDE2E62C94207EF02F3E4A6FF6EC5930FBEEBAEC272A03
            1D0DBAEDEAED5B98B35082F8C15F7C94DE60854FE052C7A0CB7EA232D0D1D04B
            1FD76F61DAC2FAC40FFEE6A3F4AC45CE7FF1C3D0653F5119E865C2A58FEB3732
            736171E207FFC647E9714B9DF982077378975D5019E8625AF6B8783B33171627
            7EF03B1FA5072D153F82C7737897FD4459A09709B75D45DECEFC8595891F7CC3
            47E9110B36FF6DC72D78CC2B5016E862F2A58FEB3735856159E207DFF351FAB5
            654F78D7077672975D5016B8EF91EC71F1D6A6302C4BFCE0473E4ABFB06CFCB8
            3EB693BBEC82B2C07D936FBB8ABCB5590C6B123FB8E2A3F46FAD7FAA8B3F127B
            A9C37ECAB123197A79F0D2C7F50198C8B020F183377C94FE5589F35C3C812C75
            D88F38762443178F678F8BC330916141E207EFF928FD5725B2C7F5A1AE7FE433
            D9B2C04D0FDE7615390CD31956F357FCF8DFFFF5BF9E3E12000060737F460FF1
            0300009841FC00000026113F00008049C40F00006012F10300009844FC000000
            26113F00008049C40F00006012F10300009844FC00000026F92B7EFCD77FFEC7
            D347423D7FFCF1C7F53FF8E73FFFF9F4310E6C66C5D6BDEDB2D2ADCBFAB61A27
            341CDA5C2F20CBCE9D9DD670D8C33FFEFB7FC40F1A45F6B2D5D7F7CDCE5BF1F8
            51B78D71E207C415CD1ED707BFF861C3AEC40FDA05F7B2A5D7F7CD4E5A3F6DB8
            376BE6CD6A3C7D5CB0A28B05BFC4AC31DF611DE207ED4EB89367B333D645730E
            4C209B752E8C53FAD2C775134A1C3C6C46FCA0DDF677F2EC77BABADE70EFD7DE
            3BD5003E55BFF471DD8A424D803D881FB4DBFE4E9E6D1A72DDA25F9BB35F93EF
            540378ED923D2EDA52AE15509DF841BBBDEFE4D9A009C146FDD6A22D1BDE560A
            6083DBAE22CD29D710284DFCA0DDDE77F2543FFE78A3BEB668CBB6B795020EB7
            D3A58FEB16156D0E54247ED06EE33B79EA1E7943BBBE6DD4AE156828051C6BB3
            4B1FD7EDAADB1C2847FCA0DDC677F2143DECB676FDD4A85D8BD0500A38D0AED9
            E3B5FBE206EB133F68B7EB9D3CE50EF866D32EDAA51470ACFD6EBB8AB46E83A6
            C1FAC40FDAED7A274FADA3BDDFB4EB767DFD930DEAD0560A38C7C6973EAEDBB8
            47D36071E207EDB6BC93A7CA71766CDDDBA6FDFA5727D7010E7142F678EDBEDA
            C3CAC40FDA6D79274F8983ECDBBA48D33EFE708F22DCA9039C60EFDBAE222DDD
            AC99B01AF183765BDEC9B3F7C674EFD6A903DC77C8A58FEBF6EED74C588AF841
            BBFDEEE4D9FE9330275A75800BA7658FD701CB3E2C48FCA0DD7E77F26C7F1EB2
            ED5607B870CE6D5791566FDC647896F841BBCDF670279C8136EB3275808E0EBC
            F471DDF6BD9B0C0F123F68B7D97A2D7E1C4211E05B675EFAB86EFBF60D874788
            1FB4DB691B77C8B967A72E5304E8E8E4EC715D81439A0F33891FB4DB691B77C8
            8967A72E5304E8E5E4DBAEDED6E19CE6C33447C48FDF16144B492FF357EA415D
            7948F6782D73727D764A2E52840D585AB7E1D2C7751DAA14C194DCC309FDB873
            FCB8FE38E7B5698FCE346D1B37BA2BAB9F726EB6745A33179992E2C74D8BF423
            F7BDEDCAD779BD59F174604AEEE1A87EDC367E4456D5D75E7D39DF9C6DDCE8AE
            AC78B269F6E0CE7B9D29297EDCB14E3F7293AEFC49AD25423FEEE1B47EDC337E
            047BF1C3367D39DFE8353AD58FCD6F2D7E8C6EE99C7E5CB902DBB0B4EE61A929
            B9A02A2705FDB88D0397D60DE3477642BE76E9CBF986EEE41AFAB1EDDD8FDA8F
            96881F430FE9A8EEEE6BA97EA4D9B4A5B5B41209C494DCC399FDB85BFC685B58
            5F5BF4E57C0BC68FEC019438C774F4F8AF05C40D3A2AF1A3CD6AFD48335D19B4
            F85AA11FF7706C3F8A1F7FA9DE918F18B73A37F763F600C48FA18D9DD68FCB56
            600F0BF6236D7465DCCA6707FDB88793FB71ABF871A7235FF5FB72BEEAF163E5
            B3CB20E287F8D1C0D2BA07FD98B5EC3962C1A5950627F7A3F8F1B7EA7D39DFA0
            9DDCCD7E8C1FC3B2A796710AC58F4107267E3458B01F69306D69DDC99A2B8629
            B98793FB51FCF85BE98E7C44E9F87160F678CD3D952EB8D7597327B13E4BEB1E
            169C92EB5BF04CA11FB771F2D22A7EFCAD74473E42FC2847FC98D6FC9D585AF7
            B0E0942C61B593857EDCC6C94BABF8F1B7D21DF988BAF163B5D3C934E2C7B4E6
            EFC4D2BA8705A764154B2D1DFA711B272FADE2C7DF4A77E423C48FF8BB2C32BA
            0EFFEEC7527B884256EB47DAD8B6365BED132B53720F27F7A3F8F1B7D21DF988
            BABF7C35671B2A7EACF6B31EE2471B4BEB1EF4E31D4BAD1EAB2DADB439B91FB7
            8A1F2FCFFD98AB68FC98F639D6DBF8313F9F881F339BBF8DD5FA9166BAF28E75
            1610FDB88793FB51FCF84BF58E7C84F8117FA3AF2FFEDB616C193F5E2B4DC975
            B60E15ADD38FDC71F276E7DB22147D4CAD7E5C5C7C8C1DBBB4EE163F5E4D7D59
            BD179F32743FD73627D7C91E2FF1E3E7777CCBA58FD5ACD38FDC747857DE5C78
            D759460EEFC795A5C6D8B1FD287EFCCB061DF988D5E2C76ABFB72B7E5CBCE905
            CF3B5F93A5750F87F7E3D7E617BD00F25A6669E537D93176E694DC307EBC927D
            B9412F3E65F47EAE7B3F4E3E735C070CF1E327E2C7B22CAD7B38B61FBB2C02EB
            24904596567ED536C60E9C927BC68F57B82FF7E8C5A7CCFFFDA89F04DFF4D9F8
            F1DB1B9D133F2EDE7AE691881F5D585AB7F1F8945CA4C90D6D5C6A3139B01F57
            D63C364EEBC76DE3C72BD0973B7564A4C945BFCBDBAB1F1FF9C82AFE91C6F6F1
            E36D351EB908B3DF2230C1814BEB960EECC7A1F1A3EDA5C6B5EBF1A33AD39D31
            76543FEE1C3F3E3DF231F3B36D8C18F47CC069BFE25AE58AF9529F162FB2059F
            3F251769F8664E585A4F704E3F765C07564B205F8F6AE37E5CD9881BFCB6ECCA
            23E2C7F69EFA0DBE425BBA674F15EBFCB445A12ED370A0AFBEEB805585AF8C8A
            20F16307379F65FBEAFAF1CF9AD3ECF14FAAEEF75197032ED4657D1DDB70E0D3
            84F871E705D980734D90F851DE83FBDA42D36C9143EDD559CDAD58A40EF31DDB
            70E053F7754002E137CE3541E24779F17B04BB7FD1B0D634BBF973EF138EE78E
            3BDF6C5BB6CB3A3AB6E1C0A711EB80B5855F190F41E24779CD5F51BABF1DAF35
            CD56FB2E57EAA92011CD3FEDF778292638B6E1C0A769F1E3FECB5294734D90F8
            515EDFDF83DAFE4E9E3F8F7991234C55BED72F8257ECB2FBCE6C35F09B414B81
            04C227A79B20F1A33CF1A3AEB61F49BC73AA3BB0CBEC0C60631F13FCF1BB4F0F
            5C5ACFB1C818DB8CF851DEFD7B8A9A7F29DC34EBE2E605192B63B6BDDBB71A0E
            913D794D8E1FBD5E9C07AD33C636237E94277E10775A97891FB0AB86AF2F0E5D
            002590FDAC36C676227E94277E107754975D7F6166D756C309DAF6FAA317C0A3
            16D8EDAD39C6B6217EAC2EFB0B48E207178EEA32F10336D6B03B7C247EF47D0B
            665A708C6D43FC589DF841479B75D9F5F75EB2775EA5BE45033C2EBB3B9CB000
            4A209B59708CED41FC58DDFD87D3A56E55143FF6B65397BDBDED301E3F567B26
            0C1094DA1DCE5900775A66792D39C636207E1430FAF1D8E2C739B6E9B2484382
            F1639B9AC099E2BBC307E3C78837629AD5C6D806C48F1AFA26900BE2C7DEB6E9
            B2C8C920123F6C146003C1893C6D01B4B0EC67B531569DF851D8884C227EEC6D
            A72E7B7B32781B3F6C11601BCD1F490C9AEF3B2DB67C586D8C95267E6C65C217
            45DEBE9D69B6B29DBAAC395D7CFC038F0481CDB47D2431337E8C7B3BE6586A8C
            95267EEC2F9549C48FBD6DD6656D0143F6805D5DEF0E272F8012C896961A6375
            891F27EAB5F732CDCAD9AFCB46FF3003504BF67387A1B37EBF2597D76263AC28
            F183BF343CF4C0342B67CB2EEB9540AAD701F830EE9A7FAF23B1DA54B7CE182B
            4AFCA0DD967BD9BDEDDA6593BFF5042C2EBE268C9EFB12C8AED6196315891FB4
            DB752FDBD6F01275D8B8CBEE24903D2A00FC2AB8264C98FE1B2FBC875B678C95
            237ED0EEC025B5FA1E77EF2E6BEB9D6D9A0FFC66918F8A5C00D9D82263AC1CF1
            83767BEF6583EDBD637EADAA77D9B4E76F7E7A706B02003F2974EEFE4AFCA05D
            F5BD6C97F6F6F5C85DC825BAECD93DFAE427030040448933F857E207EDEAEE65
            7B357604BF02193FF269C40F001654E20CFE95F841BBBA7BD95E8D1D67E67EB7
            4497891F00F09B1267F0AFC40FDAD5DDCBF66AEC38E247E4C8A7113F00585089
            33F857E207EDEAEE65BBB4F4BAB1377796E247F0E02778E4A9640070ADCAE9FB
            2BF18376A5F7B2F35BBAC2435237E8B299FBF5699511420088AB75E2FE4AFC78
            CC064FABD9602FFB6C4B2FC680F8D1B18117766A3B70EDEDFAF0EC270E96A30D
            AC33C616277E3CA3FAD3EB2E5AB1CEE1556CE99F6FE497AFFAB6EEAD6D9A0F5C
            5BE709711E44B8AB75C6D8E2C48FD9367874DD755BB69C57DBB4749B86049B16
            B44705806B4BDD7420816C69A931B632F163B60D1E5D77DD962D27D5362DDDA6
            219176A56C5004E05A7CA1783081588B4A5B6D8C2D4BFC986DA72FCE9EB3746E
            D3D26D1AF2B6510DAAD701B8B6C2EF7F448EC75A54D76A636C59E2C7547B3C3B
            E2BA395B4EA76D5ABA4D43AE5B74E1CFC6CEFFC63FB0829F16C007638004B299
            05C7D89AC48FA9C48FA2B669E9360DB968CE67A32E1A2B81C0811AD684A71288
            85A8A835C7D882C48FA91A5699359F5ED7DC9CA57C1C7FE480ABB774BF86BC02
            11E2BAB112089CA66D4D78E483BC09EFCB086B8EB105891F534D7E7A9DAB1FD9
            83FFA909A55BBA65435E8175FC6D639D09E028CBAE09D6A26D2C3BC656237E4C
            F575D8557C74DDF55B57994267FE5652E92E7BDB90576095FFADB1CE04708E95
            D7846D16E7C3AD3CC696227E4C35227E7CFB2E7E34B0EDE053AAB4F46DAB776D
            48B0B1DBD404B876674D783D7133F3E837A5BB95C7D852C48FA9E6C48F079B53
            A845237E0660FDB697EEB2EBB6DCC9156F5F0AD840F39A70FD8F871EDEE837A5
            AFC5C7D83AC48FA9C48F75ECF4FCC79BAD5EF03853CDF9E9F8B38D8DFF140150
            516A4D58278158940A597F8C2D42FC984AFC58CAE4DF417E2D509CEA5DA6B140
            B3B68F24527F32E20887BE237DAD3FC616217E4C257EAC6FA7C7D2075B57BDCB
            341688E8F2DBF77E058B0B25C6D80AC48FA9361B64276CEF3C29B2B4CD661C70
            47DB02F8EB5FF95917AE5519638F133FEEBA799F5FE97176E61259FA4B23A775
            99EF94039F9A17C0C95F0C7301A4AE2A63EC71E2C72D919DE8F583084A0FB5D3
            F6B2F122DC37A88C0776D9819F2A01DF2AB4004A2045151A63CF123F6E39F3D9
            11D7CD2FDDA2FB7AA511F103A0AF5A0B60ADA3E5835E0B123F6E113F366B5177
            CD2344FC00E8ABD602E8024845B5C6D883C48F5BCE7C74DD75F30B1DFF238263
            46FC00E8ABDC02288194536E8C3D45FCB86BF41791571EB5A6D97D936BA8CB80
            63555C002B1EF3C9F45790F8D1C166BFCD7AB3E1EB1C5E457F96D423750146A8
            B800A62E80F8ADBFC7551C638F103F069A134B1E1CD6A65939BA0C3856D105F0
            6D0279BBD958BF8DDB283AC6E6DB3F7E2C3514360B24336BBB543FD6B5421937
            FBF9E963AD3096B8EFA87EACDBD89F8E3CBEA928D1CC0DDC1F63754769CAB6F1
            E3D92FF8F63DC8667B3C423BFB70152E3CB8AEE9C73D94585A8938704AD6DDD8
            75D92D94686975371F3B786DA71EDC337ED4FD3CA06F20D9207ED4EDCA353D75
            F6D58F7BD08FDB38B32BEBC68F97045244DB183B703E6E183F1AA6E8CADD7973
            C5A9FB3DE6CDFA71118F9C7DB35DA91FD7644AEEE1E47E2C1D3F5E1248050D63
            ECCC29297EFC4BAD8E4C35F0A8F831BABD1B987FF6D58F7BD08FDB38B92BC58F
            5AEDAD283BC68E9D8FBBC58FD51E32FD6C93EBDE7C756791ADDB951354891FA3
            8F8A2CFDB887C397D6EAF1E3D52381D46A6F3973E2C7AB7E3F8A1F7FA9DE91DF
            1641FCE0372B3CE530483FAE433F6EE3F0AEDC207EBC2490B5A5C6D8C9F371AB
            F8B1F2D724B6247E94237ED0C0D2BA07FD287E146D7221E24790F8F1B7EA7D39
            DFA0A5DCDA3A4EA1F831F4C048D18F7BB0B48A1F459B5CC8B4F8F12ADE8FE2C7
            DF4A77E423C48F721E7F52648A7E5C84A5750FA6A4F851B4C985881F41E2C7DF
            4A77E423C48F72C40F1A585AF7604AEE113F5EA6E4C2C48F20F1E36FA53BF211
            E24739E2070D2CAD7B3025C58FA2ED2D44FC08123FFE56BA231F217E94E3BB1F
            34D08F7BB0B48A1F45DB5B88F811247EFCAD74473EC22F5F9553287EE8C77558
            5AF7A01FC58FA2ED2DC42F5F056D153F5E9EFB3197F8518EF84103FDB88DC3BB
            729BF8F16AEDCAA28D2D44FC08123FFE52BD231F217E94E3A9E7B4D18F7B387C
            69DD297EBCF2BD59B7A58578EA79D06EF1E3D5D497D57BF1294397721FED8CF0
            C8D9D794DC837EDCC3C94BABF8F1F421EFAF618C9DB9B46E183F5EC9BEDCA017
            9F327A29B7B67657227EE8C765595AF770EC94DC2C7EBC325D59BA9985B48DB1
            0397D6D3E3C71EBDF894094BB9AEECEBA9B3AF7EDC837EDCC6995D297E30DAE8
            F8B14D3FEE193F3EBCEDCE6D7AF1297396F2C8B4D49541CF9E7D4DC93DE8C73D
            1CB8B4EE173F5E47F6E3CAEE8CB1A396D69DE3C7872D979B453CFE0C3BFD98B5
            4219BF1E837EAC6885B1C47D47F5E3968D3D6ACFBABEFB636CCB51FAD5FEF183
            710E99243BD165C0B1365E007F0A217BB4AE908DC7585FE207ED4CB372741970
            ACBD17C0DF5AB74DBB6AD97B8C75247ED0CE342B479701C7B200329A3116247E
            D0CE342B479701C7B200329A3116247ED0CE342B479701C7B200329A3116247E
            D0CE342B479701C7B200329A3116247ED0CE342B479701C7B200329A3116247E
            D0CE342B479701C7B200329A3116247ED0CE345BC1472FDC79A8AA2E034E6001
            6434632C48FCA09D69F6B85FBB2052795D061CCB02C868C65890F8413BD3EC59
            5FEBFFB6F8BA0C38960590D18CB120F18376A6D983BE2DFEEB5DFD7519702C0B
            20A3196341E207ED4CB3673524105D061CCB02C868C65890F8413BD3EC71D904
            A2CB8063590019CD180B123F68679AAD2095407419702C0B20A3196341E207ED
            4CB345C413882E038E65016434632C48FCA09D69B68E6002D165C0B12C808C66
            8C05891FB433CD96124920BA0C38960590D18CB120F18376A6D96ADE26105D06
            1CCB02C868C65890F8413BD36C41D709449701C7B200329A3116247ED0CE345B
            D34502D165C0B12C808C668C05891FB433CD96F55302F9962E034EE09CC568C6
            5890F8413BD36C65F104A2CB80133867319A3116F457FCF8DFFFF5BF9E3E1200
            0060737F460FF10300009841FC00000026113F00008049C40F00006012F10300
            009844FC00000026113F00008049C40F00006012F10300009844FC00000026F9
            2B7EFCD77FFEC7D347423D7FFCF1C7D7FFF19FFFFCE7D3C7C58FBEEDB2AF7422
            B01FE72C4633C682FEF1DFFF237ED0C8342B27183F5EFA11D88E7316A3196341
            E207ED4CB372E2F1E3A52B81BD3867319A3116247ED0CE342BE7A72EFB2996E8
            4D601BCE598C668C05891FB433CDCAB9E8320904D89B7316A3196341E207ED4C
            B3066F6F7F1A5AC0EB2E9340808D3967319A3116247ED0CE34CB4A7DF5E243DF
            7ABEED320904D8957316A3196341E207ED4CB39486ECF1AB2E858D749904026C
            C9398BD18CB120F18376A659CACDF8F1EA51DB60974920C07E9CB318CD180B12
            3F68679AA5FC56AE9F0A35F4CB21F12E934080CD3867319A3116247ED0CE344B
            09C68FEBBF4AFDEDCD579340809D3867319A3116247ED0CE344BF9B55CD92AB5
            4597B7AFF3F6D52410601BCE598C668C05891FB433CD523AC68F8657F8E975DE
            BE54AFB70678967316A3196341E207ED4CB3943BF1E3D5E902485B97DD3C7280
            153867319A3116247ED0CE344BA91B3F3EFF50E702753967319A3116247ED0CE
            344B291D3F00AAB300329A3116247ED0CE344B113F001E64016434632C48FCA0
            9D6996227E003CC802C868C65890F8413BD32C45FC0078900590D18CB120F183
            76A659CAF5E3CC533F3F15F9F7F163D065C0092C808C668C05891FB433CD52AE
            E3C76FBE9651FC00B8C302C868C65890F8413BD32C25153FDE123F00522C808C
            668C05891FB433CDB23A2610F10320C502C868C65890F8413BD3AC8BBE57455E
            975DA0CB8063590019CD180B123F68679A8DD0258DFCD40BBA0C38960590D18C
            B120F18376A6D91C6D81E4DB8ED065C0B12C808C668C05891FB433CD1E114C23
            E207C0AF2C808C668C05891FB433CD1611EF085D061CCB02C868C65890F8413B
            D36C4D7FF68BEF7E00FCC602C868C65890F8413BD3AC1C5D061CCB02C868C658
            90F8413BD3AC1C5D061CCB02C868C65890F8413BD3AC1C5D061CCB02C868C658
            90F8413BD3AC1C5D061CCB02C868C65890F8413BD3AC1C5D061CCB02C868C658
            90F8413BD3AC1C5D061CCB02C868C65890F8413BD3AC1C5D061CCB02C868C658
            90F8413BD3AC1C5D061CCB02C868C65890F8413BD3AC1C5D061CCB02C868C658
            90F841BB73A6D9B72DADD8EA73BA0CE03716404633C682C40FDA9D30CDDE068F
            9FAC598713BA0CE05B16404633C682C40FDA6D3FCD9AB3C7B756A8CCF65D06F0
            130B20A3196341E207EDF69E667DB3C7B7E6D76AEF2E03B860016434632C48FC
            A0DDC6D36C42F6F830B95C1B7719C0350B20A3196341E207ED369E66D3E2C76B
            6EC536EE32806B16404633C682C40FDA6D3CCD66C68FD7C4A26DDC6500D72C80
            8C668C05891FB4DB759A5D648F9F5A7733AE881F00A3590019CD180B123F68B7
            EB34FB294BA49A960A24E207C06816404633C682C40FDAED3ACD06B5ABE1A24A
            95A601ACCF02C868C65890F841BB5DA7D9B4767DBC91AF9E034C60016434632C
            48FCA0DDAED36CD776EDDD34806B16404633C682C40FDAED3ACD766DD7DE4D03
            B866016434632C48FCA0DDAED36CD776EDDD34806B16404633C682C40FDAED3A
            CD766DD7DE4D03B866016434632C48FCA0DDAED36CD776EDDD34806B16404633
            C682C40FDAED3ACD766DD7DE4D03B866016434632C48FCA05DA169967AE646A1
            7675A9C31E4D03B866016434632C48FCA05DA169967A06F9B7D66C57973AECD1
            34806B16404633C682C40FDA159A66E2C7451DF6681AC0350B20A3196341E207
            ED0A4DB3FBF1A34A4B1BEA50B121005916404633C682C40FDAD59A6623124889
            86BF2D42892307B8C902C868C65890F841BB72D36C7402F9CD82A528D76500BD
            580019CD180B123F6857719A4D4E20BF5AA13215BB0CA00B0B20A3196341E207
            EDF698664705923DBA0CA0810590D18CB120F18376BB4EB399816472B976ED32
            80B72C80592A96A56241E207EDCE9966DB7C6DFD9C2E03F88D05304BC5B2542C
            48FCA0DDC9D3AC6F20113F0046B30066A958968A05891FB433CD3EDD4C23E207
            C06816C02C15CB52B120F18376A6D9855420B953B48F370ABE822EA3AF5F4794
            81C4E22C80592A96A56241E207ED4CB3948B40D25CB4ECE64F97D1D16FC3C940
            627116C02C15CB52B120F1837FE3A3F49952D5FEE9CF7FF5F6A574191D358C40
            789005F0E52C3F988A05891FFCCD47E985FC742DE5BAFEBA8C5E8C25CA31689D
            E54753B120F183BFF828BD9C8604A2CBE8C558A29CC307ADB3FC042A16247EF0
            2F3E4A2F2ADB71BA8CB8EB9B345263E9E67D86D0C5C90BA0B3FC1C2A16247EF0
            171FA51795EA385D46D0DBAF9507C792AFA7B38EC3174067F909542C48FCE06F
            3E4A2F2ADE71BA8C88C838E9F56F601A03D2597E34150B123FF8373E4A2F2AD8
            71BA8C88C8707A3B96DA6EF680712C802F67F9C1542C48FCE0773E4A2FAACB96
            113EBC1D4ED76349F6604116C08B3ABC9CE57B50B120F1836FF828BDA89B5B46
            F8F4F62999176369C41336E13E0BE02767F941542C48FCE07B3E4A2FEABAE374
            1971D729E2A7B1247BB02C0BE0AF9CE54750B120F1831FF928BDA88B8ED365A4
            5C64892CC38CC759007FE32CDF9D8A05891F5CF1517A51A95DA32EE342970462
            8CB102E7ACAF9CE5FB52B120F183377C945E547CD7A8CBB876338118602CC239
            EB5BCEF21DA95890F8C17B3E4A2F2AD871BA8CB79A1388D1C53A6C0D7FE22CDF
            8B3116F4AFF8F1F43100000047F83FFFF8BFE20700003083F80100004C227E00
            000093881F0000C024E20700003089F80100004C227E00000093881F0000C024
            E207000030C9BFE2C79FFFF75FFFF91F4F1F09F5FCF1C79BECFACF7FFEF3E963
            5CD723D57BFBA6E3DE9ABA82C3E62786138BF876241B9F179CE5B38CB1A07FFC
            F7FF881F348A6C4ACCBA9FAC1C3F06BD3B15DDCC1E1F0C2756606B98E52C9F65
            8C05891FB4F351FA1D8BC78F4107402D5DB2C787CFE174FF358D4CDAD81A6639
            CB67196341E207ED7C947EC73AF1E3CF37FAE96074DCC93A668F0F1FC36944A4
            81085BC32C67F92C632C48FCA09D8FD2EF582A7E5C1C8F8E3B537348B848B323
            189FC4D91A6639CB67196341E207ED7C947EC76AF1E32581F08B3BF1E3CE9F37
            BF23BC656B98E52C9F658C05891FB4F351FA1D5DE2C7E78B040BFB7665D471BC
            2E87417CDC4A20ACC6D630CB593ECB180B123F68E7A3F43B6EC68FB6352EF257
            3A8E863DC76FFFECE27546303889B035CC7296CF32C682C40FDAF928FD8EB6F8
            3127B4E8387E1B03F16B1AC1347BF12791E3697B110E676B98E52C9F658C0589
            1FB4F351FA1D23B671AF7ED74C741C1F63203B0E1B62737C505DBC8E91C95BB6
            8659CEF259C65890F8413B1FA5DF11DCC6F5FDE191D4CAA8E3F8EACE55882E27
            66098466B68659CEF259C65890F8413B1FA5DF31E2B6F8BEF1E3A5E3F8E2F1F8
            F1322C69656B98E52C9F658C05891FB4F351FA1D839EE9D6F0A6D9FBB58EED32
            5E6BC48FBE2FC5390C9B2C67F92C632C48FCA09D8FD2EF78E4D9CFF77F2FEBCC
            CEE25373FCE83BFD9DE36960D86439CB67196341E207ED7C947E4797F8D1E5BE
            F9F86593633B8B4FE20775193659CEF259C65890F8413B1FA5DF71277E34D7CD
            CAC84D7DE38791CC4C864D96B37C963116247ED0CE47E96D1E091E176F7D6C47
            D040FCA02EC326CB593ECB180B123F68679A6535078F5E55D565DC247E509761
            93A562592A16247ED0CE340B1AF11BBBB026F183651936592A96A56241E207ED
            4CB3B7040F4E137F26C09DB5E2F0AFB7D2C6392B4BC5B2542C48FCA09D697641
            F0E04C13E287958736464E968A65A95890F8413BD3EC2BA983C38D8E1F1E2C40
            33E7AC2C15CB52B120F18376A6D9AF040F780D8E1FB20777386765A958968A05
            891FB433CD5E5207FC3BF18365396765A958968A05891FB43B7C9ADDFC155DB9
            852D05E347C7ECD1F66A1CE8F073560315CB52B120F18376674EB35ECFEE103F
            D8D2D715E0FE42713D59B65F73E8E5CC73D61D2A96A56241E207ED4E9B667D1F
            1A287EB0A5BEF1A3F92987F0D569E7ACFB542C4BC582C40FDA1D32CDEEE4848B
            6A881F6C29183F06BD175C38E49CD5918A65A95890F8C12D7B3FFCABEFE50E46
            887F3AEE069EA78C881FFA8B06B686592A96A56241E207B7FC36D3F69863832E
            773082F8B13EF18345D81A66A958968A05891FDCF5EB64AB3EC75CEE2847FC58
            9CECC13A6C0DB3542C4BC582C40F70B9A330F16371DDE3879EA299AD61968A65
            A95890F8C1D15CEEA84EFC585CAFF8A183B8CFD6304BC5B2542C48FCE0442E77
            6C43FC589CB9C63A6C0DB3542C4BC582C40FCEE272C766C48FC53919B30EA331
            4BC5B2542C48FCE0083E82DD95F8B1382763D6613466A958968A05891F6CCEE5
            8EBD891F2B732666290664968A65A95890F871842D9FCE916A72CA09F5D986F8
            B132676296624066A958968A05891FFBDBFBC1E491F606ED5D965D891F2B7326
            66290664968A65A95890F8B1B9736682CB1D67123F5676CEFA43090664968A65
            A95890F8B1B9136682CB1D27133F5676C2FA43210664968A65A95890F8B1B38B
            FDD60693C1E50E5EE2C7DA9C89598A0199A562592A16247EEC6CD7F8E172079F
            C48F65553C0DFF344822875D7ABD3DE4E7492A8EC967A958968A05891FDBDA6F
            B3E572075F891FCBAA751ABE333C224BD3B20DFFB6098B1F6DAF66EEDDD82E54
            2C4BC582C48F6DEDB4D972B9839F881FCB2A741A8E8FA2B63F5FB9EDDF3661E5
            43EDD8CCBD1BDB858A65A95890F8B1A79B67D375081E5C133F9655E5343C277B
            2CDBFC6F5BB1EC71F66DE6DE8DED42C5B2542C48FCD853F5F8217510247E2CAB
            CA69F8CE93912EDA78E76B24CF1661CD23ECDECC13DA7B9F8A65A95890F8B1A1
            D27702081EA4881FCB2A711ABEF3A97FE46FAB3CF555FCE05B2A96A56241E2C7
            862AC60FA98336E2C79AAA9C839BE347FC0FD7BFAF69FD231CD4D2EDDB7B9F8A
            65A95890F8B19BF83E7E91F920787087F8B1A62AE7E02EF123F5E5909D8A504E
            9561B90E15CB52B120F16337DF5EEB5F703E481D74217EAC69C13527729CE2C7
            828737A8A58734F92615CB52B120F1632B3F8DFBA5E683E04147E2C79A965A73
            82C7993DBC3FFF36FB38C2052B50E20847B4F49026DFA462592A16247E6CE5E2
            6B8E8F7F03D243031941FC58539573F0E89DF7FA973E2614611D5586E53A542C
            4BC582C48F7D5C0FFA07A784CB1D8C237E2C6BD99DF7CC27750C2AC2FDC1BCC7
            E34AB26C0DB3542C4BC582C48F7D5C5FDF983F255CEE6002F163651F355FADB6
            D376DE23AE39F7FA7111F163BFD68DA062592A16247E6CE2ED889F39255CEE60
            1AF183AC393BEFEED9A3615DFDE91DB32FB5CDECB035CC52B12C150B123F36F1
            F65437614AB8DCC17CE20759737E9DBCFB6D571DE3C7B422ACC6D6304BC5B254
            2C48FCD84164B80F9D122E77F014F18366E3BE9D32217B7C7DCDB6373DE77BE7
            2F5BC33C15CB52B120F163070D67A69FFED9FDB70E321BE942FCA0D99CEF8577
            79D9EC43D6473CC06403B686592A96A56241E24779F1B1DE7D56F4BD19001A88
            1FB499F69B5493E3C70A2FBB2C5BC32C15CB52B120F1A3BCF8D9EED9F861FA31
            82F8419B09D7287ABDECA0A37D1D76E9E3656B98A762592A16247ED4961AE87D
            6745307B98750C257ED0E6D95BA46EBE72AFD7173F0E69783315CB52B120F1A3
            B0EC289F7CF5C37C6302F18336A3BF1D3EED77057BADE1274C015BC32C15CB52
            B120F1A3B035E38769C64CE2076DFAA685D15FA218347AC58F431ADE4CC5B254
            2C48FCA8AA6188FF7402EB75DE35C1984FFCA041ADECF1D31BFD26FBBEA77DEF
            FC656B98A762592A16247E54B54EFC8007891F34E8B8F31EF775F3E0DB35BFBB
            F8714EC39BA958968A05891F25358F6F1383CD881F34E8B5F39E9C3D2EDEB7E1
            304EBBF3EAE50C98A762592A16247E94247EC007F1830683E2C7E45174F3FBE8
            E2C7516D6FA362592A16247ED47367709B186C46FCA04197D8B0C8CD4BCD77D5
            8A1F47B5BD8D8A65A95890F8518FF8019FC40FB276CA1E3F1DCFDB435AEDF8E7
            7006CC52B12C150B123F8A493D683CCEDCA028F183ACFB3BEF35F7EEA9A35AB3
            09A3D91A66A958968A05891FC5881FF02BF183AC9B3BEFA7BE6EDEB75DE2C769
            6D6FA362592A16247E5432287BBCCC0DCA123FC8EA1B3F268C9C8F774C7D97E3
            EDBF173F4E6B7B1B15CB52B120F1A312F1037E237E907567E7FD54F678FB8ED9
            033BF07BE72F5BC33C15CB52B120F1A38C71D9E3656E5096F8414AC7EC1114BC
            0AF1ED3F6B5EF65DFA8834FCB4E63750B12C150B123FCA103FE02BF18394E69D
            F78824F0F612C488C073A708D5D91A66A958968A05891F350CCD1E1F4C0F2A12
            3F48A9153F1ADEB7E1F9B3E70C7E5BC32C15CB52B120F1A3868E03BAF919551D
            8F3CF876379FE9FBAC634FF093891FA4AC133FE247127FEBB607409D33F86D0D
            B3542C4BC582C48F02FA068669F1E3CE6E2F72BA5D7C3E1F7B829F4CFC20EBFA
            EB16913F8CEBF54DF1EB03B8F3E892A346BEAD61968A65A95890F85140F7D13C
            617AC437850D7F3BE898FB123FE6103FA8C8FAF0085BC32C15CB52B120F16375
            232E568C9E1E77B247E4CF071D765FB61773881F54647D7884AD61968A65A958
            90F8B1BA1143797EFCB87983F5C79F179AD5F616D3881F94637D784AA193C822
            542C4BC582C48FA50DFA9EC6D0AF7F8C7EA4D79D6C338DEDC534E207E5581F9E
            626B98A562592A16247E2C6DD0385E337E34FF0ECC82137BFD23DC86F8413967
            3E717C05B686592A96A56241E2C7BAC68584F5E347F547F6AE7F84DB103F2847
            FC788AAD61968A65A95890F8B1AEA18378DC8B8B1F8B1FDE66C40FCA39F3476F
            57606B98A562592A16247EAC6B83F8D1F6B3FA6FFF6AF1CF0EC58F99C40F20C8
            D6304BC5B2542C48FC58D7D0EF588F7BF1D1D960FDCDFDFA47B813F10308B235
            CC52B12C150B123FD6357417DBF7C5673EA96344596E3EA8647E11F8247E0041
            B686592A96A56241E2C7D286DE22DCF1C5A7EDBC1FC91E91B74B55A0D791F312
            3F80305BC32C15CB52B120F183BBA6EDBCBBDF30963DF28B77143F9E227E0041
            B686592A96A56241E2071D74B980907D8BF9D9E3D5E9028895A823F10308B235
            CC52B12C150B123FE869DCF7CEBBDF76F536CF34079EC57F986B33E20710646B
            98A562592A16247ED0D3A09DF784AF7CBCBDAC31E20126DC277E0041B686592A
            96A56241E207DD0CFAA92E2FCB05F10308B235CC52B12C150B123FE866C4A7FE
            E376F313E287156702F1034A58615BB6C231D4A262592A16247ED04DF79DF7E4
            072F76797DF16332F1034A08FE38C7D099686B98A562592A16247ED04DDF9DF7
            D0ECF1BA3C17F67A3289156702F1034AE8FE6383BD8EC1DCBFA062592A16247E
            D04DC79DF7E8ECF11AB619153F26133FA084B6F8F19B11BFB76EEE5F50B12C15
            0B123FE8A3EF5729E67C813BBE735DEAB0F995F80185740921BF4ACD5C5BC32C
            15CB52B120F1833E3AEEBC276FE23B8610F1633EF10336D02B965C4F645BC32C
            15CB52B120F1833E7ADD74F4D40EBECBDED49D57F3891FB081BE57457E9ACEB6
            86592A96A56241E2077D74D9793F7EF5E0E6F7D1C58FF9C40FD8C0DBC53F9B4F
            BE9DD1B686592A96A56241E2077DDCDF793F9E3D7E3A92F821891FF3891FB081
            ECFADF76D3ACAD61968A65A95890F84107F793C3849FBA1A7D48EBC4A7A3881F
            B081EE2711F1A30B15CB52B120F1830E6E9E3916CC1E0DED123F1E217EC006C4
            8F35A958968A05891F74D0377EAC3351C58FF5891FB001F1634D2A96A56241E2
            071DDC3973ACBC6B4F7D9763E5866C4CFC800D881F6B52B12C150B123FE8A0F9
            2BD7F3B7ECF11BBDEE7C15D25A338DF8011B103FD6A462592A16247E7057F369
            A3ED87DEE331207EFAE9F8A6D9227093F8017BB8F9098EF831828A65A95890F8
            C15D93E3C7F55BBC3D81891F9B113F600F13BE43686B98A562592A16247E7057
            ADF8D1F0BED9070EA68AC04DE207ECE1E64F208A1F23A858968A05891FDCB54E
            FC881F49FCAD83CD113F9E227EC036222BF39DF5DFD6304BC5B2542C48FCA083
            EBAF5B44FE30EEE6A58FE001DCB9F3D8423393F8013B69BB3A1DBC72626B98A5
            62592A16247EB009D71FCE247EC04E9AAF8AFF46FCE842C5B2542C48FC6013E2
            C799C40FD8CFCD1092FAE29FB97F41C5B2542C48FC6007B2C7B1C40FD8D5E8EF
            075EFF635E2A96A76241E2073B103F8E257EC051E2533EF8B7E6FE0515CB52B1
            20F183F2648F93891F70B2D42F8ED81A66A958968A05891F94277E9C4CFC0082
            6C0DB3542C4BC582C40F76E0476F8F257E0041B686592A96A56241E2075098F8
            0104D91A66A958968A05891F4061E20710646B98A562592A16247E0085891F40
            90AD61968A65A95890F80114267EC066228FFB689BB0B686592A96A56241E207
            5098F8013B093E6A50FC9843C5B2542C48FC000A133F601BF1C79C7F3B61FFFC
            F3EB896C6B98A562592A16247E0085891FB08778F6787D376123CF1FB435CC52
            B12C150B123F80C2C40FD843C7F8F1FAF9F248E4A5F8A462592A16247E008589
            1FB087AF33F4D759F9365D881F23A858968A05891F4061E2076CE07EBA103F46
            50B12C150B123F80C2C40FD880F8B12615CB52B120F103284CFC800D881F6B52
            B12C150B123F80C2C40FD8C3F54F57891F8F50B12C150B123F80C2C40FD8C375
            7E103F1EA162592A16247E0085891FB007F163412A96A56241E2075098F801DB
            B88810E2C723542C4BC582C40FA030F103B671F1E80FF1E3112A96A56241E207
            5098F8013B093EFB5CFC9843C5B2542C48FC000A133F6033910472FDCD9097F8
            D1898A65A95890F80114267EC07E82D7402E881F5DA858968A05891F4061E207
            6CE94E02F9693ADB1A66A958968A05891F4061E2076CAC21845CCC655BC32C15
            CB52B120F103284CFC80D334CF655BC32C15CB52B120F103284CFC8093FD3AAF
            DFCE625BC32C15CB52B120F103284CFC00826C0DB3542C4BC582C40FA030F103
            08B235CC52B12C150B123F80C2C40F20C8D6304BC5B2542C48FC000A133F600F
            1F3374E84CB435CC52B12C150B123F80C2C40FD843F0C9E57DDF62C4BBEC44C5
            B2542C48FC000A133F600317D3B3E3DCB435CC52B12C150B123F80C2C40FD880
            F8B12615CB52B120F103284CFC800D881F6B52B12C150B123F80C2C40FD8C04F
            D3B3EFC4B435CC52B12C150B123F80C2C40FD8C06FD373D07CB435CC52B12C15
            0B123F80C2C40FD880F8B12615CB52B120F103284CFC800D881F6B52B12C150B
            123F80C2C40FD880F8B12615CB52B120F103284CFC800D881F6B52B12C150B12
            3F80C2C40FD880F8B12615CB52B120F103284CFC800DC42772F77731F72FA858
            968A05891F4061E2076CE0ED44FE5676DADA1A66A958968A05891F4061E207EC
            A12D81FCE67A22DB1A66A958968A05891F4061E2076CA34B0279FD3C9D6D0DB3
            542C4BC582C40FA030F10336D61C48BE9DD1B686592A96A56241E2075098F801
            47090612F1A30B15CB52B120F103284CFC8093FD34AFC58F2E542C4BC582C40F
            A030F103F8F431CD7DF7A31715CB52B120F103284CFC00826C0DB3542C4BC582
            C40FA030F10308B235CC52B12C150B123F80C2C40F20C8D6304BC5B2542C48FC
            000A133F80205BC32C15CB52B120F103284CFC00826C0DB3542C4BC582C40FA0
            30F10308B235CC52B12C150B123F80C2C40FE0C3F5AFEEBE6C0DF3542C4BC582
            C40FA030F103787D37C1BF4E6A5BC32C15CB52B120F103284CFC005EB1C79FDB
            1A66A958968A05891F4061E207F0E1628E7F4C705BC32C15CB52B120F103284C
            FC003EBD5D10BE32F72FD84C67A95890F80114267E00BF49851073FF82CD7496
            8A05891F4061E207F0553C8198FB176CA6B3542C48FC000A133F800B9F13FFCF
            396E6B98A562592A16247E0085891F4090AD61968A65A95890F80114267E0041
            B686592A96A56241E2075098F80104D91A66A958968A05891F4061E207EC243E
            A37BBDB8B97F41C5B2542C48FC000A133F600F0D8FEC782567AEAD61968A65A9
            5890F80114267EC01EDAE2C7A7C814B635CC52B12C150B123F80C2C40FD8C3CD
            F8F10ACC625BC32C15CB52B120F103284CFC800D7C9D9E3F4DC93B5F0EB135CC
            52B12C150B123F80C2C40FD8C06FD3333E1FE3B9E5656B98A762592A16247E00
            85891FB081E6F8F1BA7DE5C4DCBFA062592A16247E0085891FB0813BF123FEE7
            B686592A96A56241E2075098F8011BB8193F82AF606B98A562592A16247E0085
            891FB001F1634D2A96A56241E2075098F8011B103FD6A462592A16247E008589
            1F50C2F517C4C58F35A958968A05891F4061E20794907AAAA0F8B10815CB52B1
            20F103284CFC8012C48F8A542C4BC582C40FA030F1034A48C58FAFDECE50F163
            0415CB52B120F103284CFC802A6E26905F7D9DB0E2C7082A96A56241E2075098
            F80175750C24BF113FBA50B12C150B123F80C2C40FD849AF40227E74A162592A
            16247E0085891FB0B1E634227E74A162592A16247E0085891F708E781A113FBA
            50B12C150B123F80C2C40F38D94FF35AFCE842C5B2542C48FC000A133F804F1F
            D3FCA7E96C6B98A562592A16247E0085891F4090AD61968A65A95890F8011426
            7E0041B686592A96A56241E2075098F80104D91A66A958968A05891F4061E207
            10646B98A562592A16247E0085891F4090AD61968A65A95890F80114267E0041
            B686592A96A56241E2075098F801299F13E1C0316F6B98A562592A16247E0085
            891F90F2DB44386AE4DB1A66A958968A05891F4061E207C41DBE373ABCF90D54
            2C4BC582C40FA030F103E22E66C10953C0D6304BC5B2542C48FC000A133F20EE
            F059606B98A562592A16247E0085891F10179F2F5BB235CC52B12C150B123F80
            C2C40F887B3B5F3EEC3A1D6C0DB3542C4BC582C40FA030F103E282F1E3B5E98C
            B035CC52B12C150B123F80C2C40F888BC78F0F9BCD0B5BC32C15CB52B120F103
            284CFC80B86CFC788D9C1A5F0F66F434B435CC52B12C150B123F80C2C40F88FB
            696FF4C8EC98BF51B335CC52B12C150B123F80C2C40F88BBDE1B4D9E23E2C7FA
            542C4BC582C40FA030F103E2DEEE8D664E13F1637D2A96A56241E2075098F801
            7191BDD1B499227EAC4FC5B2542C48FC000A133F202EBE379A305FC48FF5A958
            968A05891F4061E207C4A5F646A3A78CF8B13E15CB52B120F103284CFC80B8EC
            DE283EBF261CCCFCE6A362592A16247E0085891F10D7B6371A3477C48FF5A958
            968A05891F4061E207C435EF8D464C1FF1637D2A96A56241E2075098F8017177
            F646DD6FC4123FD6A762592A16247E0085891F10777F6FD4711E891FEB53B12C
            150B123F80C2C40F88EBB237EA3595C48FF5A958968A05891F4061E207C4F5DA
            1B75B9114BFC589F8A65A95890F80114267E405CDFBDD1CD39257EAC4FC5B254
            2C48FC000A133F20AEFBDEE8CEB4123FD6A762592A16247E0085891F1037626F
            D47C2396F8B13E15CB52B120F103284CFC80B8417BA3B604227EAC4FC5B2542C
            48FC000A133F206EE8DE281B42C48FF5A958968A05891F4061E207C48DDE1BA5
            1288F8B13E15CB52B120F103284CFC8094AF13A1EFE0BF3925C58FA5A858968A
            05891F4061E207A48C8E1F3FBDCBD737153FD6A762592A16247E0085891F9032
            277EBC0273F35BE2C752542C4BC582C40FA030F103B27E9D0BF3B7FBD7C48FA5
            A858968A05891F4061E2072C2E1542C48FA5A858968A05891F4061E207AC2F9E
            40C48FA5A858968A05891F4061E20794104C20E2C752542C4BC582C40FA030F1
            030A697B3EFAD07737F72FA858968A05891F4061E207D4F2E04CB435CC52B12C
            150B123F80C2C40F28E762328A1F4B51B12C150B123F80C2C40F286ADA13482E
            DE71C29B96A662592A16247E0085891F50D76FB352FC58CD66159BF0C49BCD2A
            368EF80114267E0041B686599B554CFC5887F80114267E0041B686599B554CFC
            5887F80114267E0041B686599B554CFC5887F80114267E0041B686599B554CFC
            5887F80114267E0041B68659B52AF6F668C58F75881F4061E20710646B9855AB
            626F4F07135A51AB620F123F80C2C40F20C8D630AB56C5C48F42C40FA030F103
            08B235CCAA55B154FCF8D6FDA6D5AAD883C40FA030F10308B235CC2A57B1FB09
            E46663CB55EC29E2075098F80104D91A666D56B15EE1E4A2029B556C1CF10328
            4CFC00826C0DB336AB58C76B233F1561B38A8D237E0085891F4090AD61D66615
            BBF8E1DD8664F26D1D36ABD838E2075098F80104D91A666D56B1F8733F226944
            FCB843FC000A133F80205BC3ACFD2AF6D9A2542BE275D8AF6283881F4061E207
            10646B98A562592A16247EC02AB2F79E5AD15EE20710666B98A562592A16247E
            C0C39A7F8BC38AF6123F80305BC32C15CB52B120F1039EB1C2F35937207E0041
            9B6D0DE35FA4EEF216A3DF6B0F2A16247EC06C139E7C740EF10308DA6C6B287E
            2C48C582C40F986AC2638F8E227E00419B6D0DC58F05A95890F80153B9F4D197
            F801046DB635143F16A46241E207CCD3257B58C87E257E00419B6D0DC58F05A9
            5890F801935C6C7FAD4DCDC40F20A8D6D6F0EDD18A1F0B52B120F10366903D06
            113F80A05A5BC3D4D572F1A3A151231AB265C546103F60064BD220E20710546B
            1D163F26B4E8A22D5FDB1E69F87E151B44FC80192C4983881F4050AD75788567
            43D5AA58438BBE6DCB9D93C57E151B44FC80E1AC47E3881F4050B9A5B8E30FB5
            B735B65CC5B2CD69881FAFE4359357E58A8D237EC070D6A371C40F206883A5B8
            7B20799DB499BE7FE9E36D1136ABD838E2070CD7760B2911E20710B4D9D670C2
            436CF7AE98F8F120F10386133FC6113F80A0CDB686173FBCDB904CE27BF12D2B
            F6537B7F3A83881F37891F309CF8318EF801046DB6358C3FF7239246C48FD7BB
            9375F3C593BA151B47FC80B12C4643891F40D066AB71F36307E37538AA626F3F
            28143F3A123F602C973E86123F80A02DB7867F36EA66132E5E61B38A891FEB10
            3F602CF16328F10308B235CCDAAC62A96FCBBCCD27E2C71DE2078C257E0C257E
            0041B686599B55EC223F881F93891F3096F83194F80104D91A66ED57B16F2F80
            B43D8E50FCB843FC8081AC44A3891F409005396BBF8ADD79AC87F8D191F80103
            598946133F80200B72D696158B9F35AEFF50FCB843FC8081DC79359AF80104D9
            1A666D59B1B67341DB0D5AD7AF7932F10306123F46133F80205BC3AC5D2BF6D3
            E9E0A2699E7ADE97F80103891FA3891F4090AD61D6DE158B9FA0EFFCCBD74615
            EB48FC80512C4313881F40D0966BF267A3463464CB8AB571F5A32FF10346B10C
            4D207E0041FBADC9C13D71EA5F5EFC55EA6F3773FDC4F46FFF59E4DF1F4BFC80
            512C4313881F40D07E6B72F36F3105DBBE5FC56EFAB320D7CD57B120F10346B1
            0C4D207E00419BADC9777E8B295881CD2A36818A05891F308AEF9D4F207E0041
            9B6D0D6F5EFA885460B38A4DA06241E2078C227E4C207E00419B6D0D7BC58F97
            2F52F7A36241E2070C610D9A43FC0082365B96DF7E19FAE22330BFE334888A05
            891F308435E8BEC80F4A8A1F40D066CBF29DF8F1BA71F1A46EC52650B120F103
            86B006DD74E7570E7F257E001F365B96AF17C9B777FF8A1F23A85890F8014358
            836E123F80BE365B96C58F05A95890F80143F8DEF94DE207D0D7665BC38B4532
            7202123FB254AC23F103FAB300DD277E007D6DB6325FEC86C58F117E3A895C57
            FE7570C52E881FD09F05E8A6E0AFB2BCC40F206CBF95F9DB8F69DA1E47287EBC
            153989A85890F801FD59806E0A5EFA7805E24790DE818A3E5680E0FCDD6F65BE
            F3580FF1A341DB19E7E48AFD44FC80FE2CD937891FC05BF185E2EBBF4FFDE1B2
            EE3CD45CFCB82375EA51B1AFC40FE8CF927D93F8015C6BF8798F2D57E6B6DB4A
            3D76F0BEF8D947C5BE123FA03F4BF61DF12F7EBCC40F3852E44BC0C1BFDA60EE
            375443FCE828FE15443E891FD05FDBA9910FE207F0D6FD3DF7DB7F5F48B669E2
            C7202A16247E407F2BC48FEE77A6F66A543630DCF9D9ABD4BBA4BEC30A3C2EBB
            28D91A7E123F0651B120F103FABBD816CF59863A6EF183AF76E79767DA5EB663
            F6686B0BF0B85402B135FC74E7C14A67562C48C582C40F18E2D99B411FD9E5B7
            7DEFB3ED35C7658F605B8045C41388ADE1AF22D77B77ADD8B8C740ED5AB1EEC4
            0F18A5CB16B96DD9EA123FE65F4289BFA6F8017C0A26105BC3ACFD2AD6F153B0
            F8EB97AED820E2078CF2D4B7A27BC586152E56B8F90A888824105BC3ACCD2A76
            E7AC71ECA32D07113F609445E2C7DB3B1082973E9A9F9B1BFF6777FE65474E15
            50D1DB04626B98B559C5EE9F35CE7CB6CC08E2070CF4C8FD5723E247C7E7E6A6
            EED19AF3ABBBF1770456769D406C0DB336ABD88433F266151B47FC801946DC7D
            147CAFEB48D03730DC7CB55E8F316EE62401D55D24105BC3ACCD2A76E7E78683
            15D8AC62E3881F30C9E86FBC7DFB465DBEB9FE54FCB8F3349206CE10B087EE4F
            3D3AD6669BE9B69363AA089B556C1CF10366EBF8188DB7AF3F3A7EF4BDF9EAC1
            F8E1F4003BE9F88BE127DB6C337DE7E4D8F67DC8B6F73A81F8015B69D8C1DF79
            912EDF33B973F0E207F0ADE0E270ECDC6FFB0D9257E58ADDFC6CEEC08A8D237E
            C05646C48F38F10358C7E84BCDA51DF853C5E2C73AC40FD8CAFDF8D1F75BF27D
            E3C7E8A70D061BD5D7FC46014395D86E469EFCBDD9665AFC5887F8015BA91B3F
            AEEFAC7D768F3EE8E42178C0C6D6DF74B62D41EBB72BD25EF1E359E2076CA5FB
            F7CEE3867EEF5CFC006A29B4E9DCE3B7C246B742FCE848FC807DACF6C58FD421
            891FC04E6A6D3A37F8AD30F1A310F103F631E2CEAB5E3F01FCF6A5C40F602745
            379D771EBAB7F891DF6C97F8D191F801FBE81E3F6E2E9AD5BF77DEA508D72410
            D852F51DE79F4B53C5E7C40F7D10ADF8D191F801FBD83B7E7CFBCF869A76CE10
            42601B732E96CE599DF6D84C0F5A60C58F3BC40FD847DDF8D17CD397E77E0041
            156F2B8AFC3CEEE4775FB04AF71BD540FCB843FC807D8CF8D9AB39DFFD688E3D
            E2071054F12984CF3EBBFD90CD74C71F203EA462F7891FB0895E172EFAAE9EC1
            3C237E00A33DBB951F77C0E30EFBCCCDF49D717266C51A881FB089A1F1E3ADBE
            5FD5981F3F526F0A5454EBB7651B16B7EE876D339DAD838A05891FB0898E5FDB
            E87BDA1B7A12EDFB9D422709D8D8E317136E1E6DE4E7C8DB16CFD4E7478F57E6
            711F3F0BF6D37FFAFA3FAAD857E2076CE2C1F891FA49AB9BAF76E795FBBE3B50
            CB4F5BC39F56926757833B3F061839723F233B828A05891FB08FCF85AFCB62D7
            F74685EEB73D8CFBB15AA70AD8D2C5D670C10472E7970323472E7E8CA06241E2
            075092F801A45C6F0D574B20D95F32CCFE6EA1F831828A05891F403DA39FD3E7
            6C01FB79BB355C2A8134FC907A2A81881F23A85890F801D4237E005991ADE13A
            09A4EDEB7CF104227E8CA06241E20750929BAF8094E0D6709104D2F16948CD4F
            5BB299CE52B120F103A8AAEF433F3E5ECD79027675F3E90DAFBD1288F831828A
            05891F40619E7A0E04A5B6862B2490ECB7C9537F3B2E7E74FC15F872C48F20F1
            03284CFC0082B25BC3EA09E4FACFA7C58FC9157B96F811247E0085891F4050C3
            D670859DF4A00432337E341C7651E24790F80114267E0041F737D32B3C03A4E1
            48BEFDF3F9F1237BD815891F41E2075098F80104356F0D17F95D8A3B41E8ED52
            39277E341C792DE24790F80114163FA79E7C46045E5B6C0DEF04A186357044FC
            08BE48511B8CB139C40FA030F10308B235CCDE16352E7E445EA722632C48FC00
            0A133F80205BC36C1D86C68FE0ABD5628C05891F4061E20710646BF8A9EDC9E8
            17FFF2ED5F5D18D705F39F40628C05891F4061E20710646BF8ABC9CFFD786405
            9EDFE3C65890F80114267E0041B686BFF92C48EAD1EF771E3B38791D163F9625
            7E0085891F4090AD61D688A79ECF5C8AC58F65891F4061E20710546B6BB8E6E3
            0E2307F3F68B25D35663F16359E2075098F80104D5DA1A6E1C3F2E5EBC6F93C5
            8F65891F4061E20710546B6BF8367E4CC82743E3C76BFCB22C7E2C4BFC000A13
            3F80A05A5BC313E2C72BB3864F3BFE3B6A8DB107891F4061E20710546B6B7848
            FCB878A3FBAD133F96257E0085891F4050ADADE1DBE772EC143F5E639668F163
            59E2075098F80104D5DA1A9E163F2EDEB1B999E2C7B2C40FA030F103082AB735
            BC4E205BC68F57D7B55AFC5896F80114267E0041E5B6866FD7B7D1AD78247EBC
            6DF8CD6B29E2C70AC40FA030F10308AAB8350C2690CDE247A4EDCDDF27113F56
            207E0085891F4050D1AD61FC1A48F7A63D1B3FDEB6BDED07B5C48F15881F4061
            E2071054776BD89C406E36F6F1F8F1B6EDD7AF2C7E2C4BFC000A133F80A0EA5B
            C35E21245E8115E247A4EDA9A7AA8B1F2B103F80C2C40F2068B3AD61C734D277
            FB3E227EBC6DEFDB2733F63D98D441D61D63E3881F4061E20710B4D9D6F0E287
            771B9249C7EDFBA0F8116957A40EE2C70AC40FA030F10308DA6C6B187FEE4724
            8D94881F91E6FCFA5EE2C7B2C40FA030F10308DA6C6BD8FCD8C1781DD68C1FAF
            F07A2E7E2C4BFC000A133F80A02DB7867F36EA66132E5E61D9F8F18A2DFEE2C7
            B2C40FA030F10308B235CC5A397E5C1CE135F16305E2075098F80104D91A6635
            57ACF9C6B05E077941FC5881F80114267E0041B68659852A160F21E2C70AC40F
            A030F10308B235CCAA55B16002113F56207E0085891F4090AD6156B98A35FFC4
            F0D00358B9624F113F80C2C40F20C8D630AB68C51E5CED8B566C3EF103284CFC
            00826C0DB3EA56EC62C1173F56207E0085891F4090AD6156E98AFDB4E68B1F2B
            103F80C2C40F20C8D6306B838ACD7C08C96B8B8ACD217E0085891F4090AD61D6
            1E157BFC2124E52A3681F80114267E0041F79FE17DDA42B1CD66FAA321138E7C
            9B8A8D267E0085891F40D0FDF811FC936DD84C67A95890F80114267E0041BDE2
            47F00F3760339DA56241E2075098F80104F58D1F91BFADCE663A4BC582C40FA0
            30F10308EA1E3F227F5E9ACD74968A05891F4061E2071034227E045FA4289BE9
            2C150B123F80C2C40F20685CFC88BC4E4536D3592A16247E0085891F40D0D0F8
            1179A9726CA6B3542C48FC000A133F80A0D1F123F882BD9AE029160B52B120F1
            03284CFC00823A3EF7E391F564FE13486CA6B3542C48FC000A133F80A0EE8F1D
            9CFC9BBCF3B7B636D3592A16247E0085891F40D088A79ECF5C58C48FF5A95890
            F80114267E004123E2C76BE2DA227EAC4FC582C40FA030F103081A143F2E5E3C
            F816438FBFD63B56A76241E2075098F801040D8D1FAFF18B8CF8B13E150B123F
            80C2C40F206874FC780D5E67C48FF5A95890F80114267E004113E2C7C51B05FF
            B6FBF1DF61339DA56241E2075098F801044D8B1FAF310944FC589F8A05891F40
            61E2071034337E5CBC63F6456E1EFF1D36D3592A16247E0085891F40D0FCF8F1
            EA9A40C48FF5A95890F80114267E00418FC48F57BF04227EAC4FC582C40FA030
            F103087A2A7E5CBC7BEA05C58FF5A95890F80114267E0041CFC68FD7ED04227E
            AC4FC582C40FA030F103087A3C7EBCEE2510F1637D2A16247E0085891F40D00A
            F1E3E248DEBEB8F8B13E150B123F80C2C40F20689DF8F16A4A20E2C7FA542C48
            FC000A133F80A0A5E2C72B9F40C48FF5A95890F80114267E0041ABC58F8BA3FA
            F68DC48FF5A95890F80114267E00416BC68F573881881FEB53B120F103284CFC
            0082968D1FAF5802113FD6A76241E2075098F80104AD1C3F2E8EF0F34DC58FF5
            A95890F80114267E0041CD5BC35FFF70F45AF1764D6B38FEBE0763B5BCA06241
            E2075098F80104DDDC1AFEF9E7D3168A7808113F96A26241E2075098F80104D5
            DA1A061388F8B114150B123F80C2C40F20A8DCD6309240C48FA5A85890F80114
            267E004145B7860FAE5D452BF620150B123F80C2C40F20A8EED630FB7CF4A1EF
            5BA2624F51B120F103284CFC00824A6F0D7F5AC1C48FA5A85890F80114267E00
            411B6C0D673E84E4B545C52653B120F103284CFC0082F6D81AFED60AF163292A
            16247E0085891F40D0365BC3CF863CF20CC48A159B46C582C40FA030F10308B2
            35CC52B12C150B123F80C2C40F20C8D6304BC5B2542C48FC000A133F80205BC3
            2C15CB52B120F103284CFC00826C0DB3542C4BC582C40FA030F10308B235CC52
            B12C150B123F80C2C40F20C8D6304BC5B2542C48FC000A133F80205BC32C15CB
            52B120F103284CFC00826C0DB3542C4BC582C40FA030F10308B235CC52B12C15
            0B123F80C2C40F20C8D6304BC5B2542C48FC000A133F80205BC32C15CB52B120
            F103284CFC00826C0DB3542C4BC582C40FA030F10308B235CC52B12C150B123F
            80C2C40F20C8D6304BC5B2542C48FC000A133F80205BC32C15CB52B120F10328
            4CFC801256D896AD700CB5A858968A05891F4061E20794F076AA7E183A136D0D
            B3542C4BC582C40FA0B0E09EE62DA70718AA6DAAF69D98B686592A96A56241E2
            075098F801257499AA37E7A9AD61968A65A95890F80114267E4015BD66EBAF52
            33D7D6304BC5B2542C48FC000A133F60037326B2AD61968A65A95890F8011426
            7EC006FA5E18F9693ADB1A66A958968A05891F40551DB72C4E0FF0A0DFE6F2D7
            F9989DECDFCE685BC32C15CB52B120F10328E6F13BC881BEDEC68FEB7FFF95F8
            D1858A65A95890F80194D11C3CFE5CFD3DF70396958D1F6DAF606B98A562592A
            16247E00ABBB73B9C36307617DE2C79A542C4BC582C40F605DF7EFB3123F607D
            E2C79A542C4BC582C40F603923BE532E7EC0B2C48F35A958968A05891FC042BA
            7FAD5CFC80F5891F6B52B12C150B123F80E78DF831AB0FE20794F0EB0C153F16
            A162592A16247E004FBAF36356913F173FA0849B1740C48F11542C4BC582C40F
            E019378347F045C40F28E1EB0C4DCD4AF1630415CB52B120F10398AA4BEA88BF
            9AF80155DC4920E2C7082A96A56241E2073049DFE0117C4DF1030AC9AE123FDD
            84297E74A162592A16247E00638D481DF117173FA0905EBF42217E74A162592A
            16247E00A30C0D1EC1B7103FA0968E0F1B8DBCB2B97F41C5B2542C48FC003A9B
            903AE2EF257E4045774288F8D18B8A65A95890F8017433337804DF51FC809DC4
            A77CF06FCDFD0B2A96A56241E20770D788CF297BBDB5F8011B4B3DACD0D6304B
            C5B2542C48FC00DACDBFDC913D00F103F8606B98A562592A16247E00690F5EEE
            C81E89F8017CB035CC52B12C150B123F8084C72F77648F47FC003ED81A66A958
            968A05891FC07BEB5CEEC81E98F8017CB035CC52B12C150B123F802BAB5DEEC8
            1E9EF8017CB035CC52B12C150B123F806F2C7BB9237B9CE2079473E7D775B32F
            6BEE5F50B12C150B123F807FB3F8E58EECD18A1F504870FD113FE650B12C150B
            123F807FA972B9237BD8E20754115F85C48F39542C4BC582C40FF8CBE7AA71DA
            4A51EB7247F6E0C50F2821B5107D9DB091E70FDA1A66A958968A05891FF0CD7A
            71C26251F47247B615E20794D0317EBC7E98D1B686592A96A56241E207A73B70
            B1287DB923DB16F1034AB8FE18E86DBA103F4650B12C150B123F38DD398BC51E
            973BB28D123F607D6F2F418B1F8F50B12C150B123F38DA4F5BD2CD168B9D2E77
            649B267EC0FAEEA70BF1630415CB52B120F183A3ED1D3FB6BCDC916DA3F801EB
            133FD6A462592A16247E70AE8DF7A31B5FEEC8B654FC8012AE7FBA4AFC78848A
            65A95890F8C1B9F6DB8F9E70B923DB64F1034AB8CE0FE2C723542C4BC582C40F
            0E15DFB69670CEE58E6CC3C50F2841FC58908A65A95890F8C1A1B6891FC7068F
            60F3C50FA8E22242881F8F50B12C150B123F385164CBBEF87A7178EA88D741FC
            802AC48FD5A858968A05891F9CA874FC103C7E257EC04E7EDABD891F8F50B12C
            150B123F384E7CFBBED49221757C4BFC80CD347C3CF4F6A98517AF6CEE5F50B1
            2C150B123F38CEB727AA95970CC1E382F801FBB9F3237E1FC48F2E542C4BC582
            C40FCE12BCB2FFF9BFAF76A81147AD74E2076C69C4CF882FB8CE2F4EC5B2542C
            48FCE02C3F5DA35F6AC9103CE2C40FD858DB62287EF4A262592A16247E7090EB
            752178F7F0E4C30B3A7675133FE034CD73D9D6304BC5B2542C48FCE020D701E3
            C1F8E1724733F1034EF6EBBC7E3B8B6D0DB3542C4BC582C40F4EF17651981F3F
            5CEEB84FFC00826C0DB3542C4BC582C40F4EF1365DCC5C355CEEE845FC00826C
            0DB3542C4BC582C40F8E10591126AC1A2E7774277E0041B686592A96A56241E2
            074788DC583574D570B96310F10308B235CC52B12C150B123FD85F703918B46A
            081E43891FB08709DFBEB335CC52B12C150B123FD85FFCACD6FDFCD7903DAC53
            29E2076CE0627A769C9BB686592A96A56241E2079B4BAD05CFC60F2B5403F103
            36207EAC49C5B2542C48FC6073A944D177E108660F0BD31DE2076C40FC58938A
            65A95890F8C1CEB20B41F785C3967734F10336F0D3F49CF0DB83E6FE0515CB52
            B120F1839D656FA69A133FAC441D891FB081DFA6E7CC072E99FB17542C4BC582
            C40FB6D5B00A8CFEF12B6B5077E2076C40FC58938A65A95890F8C1B61ABE476E
            E12847FC800D881F6B52B12C150B123FD853F31230E1B7E7E948FC800D881F6B
            52B12C150B123FD853738A103F6A113F6003E2C79A542C4BC582C40F367467FE
            5B3B6A113F6003E2C79A542C4BC582C40F3674E70A86B5A316F10336109FC8DD
            DFC5DCBFA062592A16247EB09BD483C683AC1DCB123F60036DEB7676DADA1A66
            A958968A05891FEC46FC388AF8017BE8B2743FF2D3EA1B53B12C150B123FD8CA
            88ECF1B2762C4CFC806DF45AC07F9ACEB686592A96A56241E2075B113F4E237E
            C0C69A97F46F67B4AD61968A65A95890F8C13E06658F97B56361E2071C25B8CE
            8B1F5DA858968A05891FEC635CFC78593E56257EC0C97E9AD7E247172A96A562
            41E2079B189A3D5E968F55891FC0A78F69EEBB1FBDA858968A05891F6CA2E39C
            B77C349BF3ECB08B77FC4AFC003E58DBB3542C4BC582C40F76D077C25B3E9A89
            1FC0B2ACED592A96A56241E2073B103F16217E00CBB2B667A958968A05891F94
            D77DB65B3E9A891FC0B2ACED592A96A56241E207E58D98ED569006F3B3C74BFC
            00C22CEC592A96A56241E207B50D9AEA569006E207B0320B7B968A65A95890F8
            416DE2C73AC40F606516F62C15CB52B120F183C2C6CD732B4803F103784A64FD
            B1B067A958968A05891F54957AD86D9717B7825C78247BBCC40FE0FF899C112C
            EC592A96A56241E207550D9DE456902CF103785064825BD8B3542C4BC582C40F
            AA1A3DC9BFBE7E975FD3BAFF3492110BD9AF8DCDBEFEDB0030EEB023EF2E7EC0
            21DECE715BC32C15CB52B120F183C2867EE2DEF1C5EFBF54F796463243E45D82
            D9A3D761371C80F801A7797C5DDA86CD74968A05891FD436F49AC0EBF6258BDF
            0EB2F9501F891F6FDF2B758EEF72D80DC7207EC081BA2C71D84C67A95890F801
            C3F58D1F239EA878EDA7775CE12346F103B8105F22F8CA663A4BC582C40F18EE
            66FC58337B645F50FC009E656B98A562592A16247EC0702BC78FDF5EB0ED0BF7
            4FFDECD54BFC00C26C0DB3542C4BC582C40F18EECEEEBC63F6481DC99FFF32FE
            76E2077053DFB5EEED5B8C7EAF3DA858968A05891F30DC22F1635C48103F803B
            E6AC21B686592A96A56241E207CC709122AE03C6CC3BAFBABCECE47556FC800D
            881F6B52B12C150B123F60868B936B7332B9790CBD5E59FC006E123FD6A46259
            2A16247EC00C3F9D5CAF4FBADD6F86BED882DF7F1C7BC7E3ECD2A2DF8E47FC80
            65891F6B52B12C150B123F608660FCF8E93FF55ABC466CC1C50FE0ADEB9B3FC5
            8F35A958968A05891F30C3B727D7EB756AD0EFC0747F0897F801BCB5EC534ACD
            FD0B2A96A56241E207CC70277E745FB922FB8012BFBA1B698BF8012B103F2A52
            B12C150B123F6086AF7BF4EB2F823FF513F85F8F24DBAE1187DAA515E2073C28
            153FBE1AF7E53773FF828A65A95890F80133C4E3C7D7FF3A7AE5BAF37D74F103
            08BA9940BEBA79A768DB8B1C45C5B2542C48FC8019E261E3EB7F7DF008C50F60
            90EE69E4F56E22DB1A66A958968A05891F30C3FAF1E3A7E34C9DCEC50FA041DF
            28F2D374B635CC52B12C150B123F6086B78FFC5B67CD4A250AF103B82FFE04A4
            A06F67F43ACB6C152A96A56241E2074C12FF99DDAFFFF5C1E3143F80D1EE2C3B
            DF123FBA50B12C150B123F6092D453B7BEFE835EEFDE374E881F40176DBFB7F1
            F6C2F2DB7F6CEE5F50B12C150B123F60926CFC18FAA8C1E0B979F14B1F2FF103
            F6F2E73CBD33193FA6B9EF7EF4A262592A16247EC0246F37EBCDBBF9B79F1AB6
            7DAD73FD4B1F91A6891FC0075BC32C15CB52B120F1032649C58FD46A257E445A
            217EC0E16C0DB3542C4BC582C40F982415129A6F7D4EDD7570A1C423CF23ED12
            3F800FB686592A96A56241E2074CF26CFCF8F61F7FABE34D5F13881F4090AD61
            968A65A95890F801F35C7F2D32F20FBEFDF79F6EFE5C4CC312993DE0EEC40F20
            C8D6304BC5B2542C48FC80C256B8FD69A90A7C257E001F6C0DB3542C4BC582C4
            0FA86AE86FF556217E0041B686592A96A56241E20754E5D2C74BFC00C26C0DB3
            542C4BC582C40FA84AFC78891FB091D1BF66616B98F5FFB577AF4B8E6A3B1646
            FDFE4FDD3B22A3ABB39D36968089118CF1F39C5D795114F2FACA174CACCBC48A
            E4078CA43D5ECEE12FF90153D4D7DABA979E3A1A769958978915C90F18497EBC
            9CC35FF203462816C5C285DCBD536AF14FDD998975995891FC80A9BEFEA1B767
            203FE01AB6E7C7C29F5AF8B3AEFD0526D6656245F203184C7EC035549ED1DD78
            E35447C32E13EB32B122F9010C263FE01AF6CA8FC7FBCBD9D1B0CBC4BA4CAC48
            7E0083C90FB88075EDF1EEEA961F7B31B12E132B921FC060F2032E60637EACFE
            0A0FD7FE2213EB32B122F9010C263FE0023EC6C3C737A6CB8F0413EB32B122F9
            010C263FE01A96EF39283FBEC2C4BA4CAC487E0083C90FB88685FCA87C26AFFC
            4830B12E132B921FC060F203AE61A11FE4C7B79858978915C90F6030F901D7F0
            AE1FD6DD8E507EECC2C4BA4CAC487E0083C90FB88C2DB7F5901F0926D6656245
            F203184C7EC095D4AFE8E53F283F7661625D2656243F80C1E4075CC9BAEBD46D
            07434CACCBC48AE4073098FC808B7977A92E5CA4F223C4C4BA4CAC487E0083C9
            0FB89ED619AEF8DEF4EE97E561627D2656243F80C1E407DC5CF1A98F87A3619F
            8975995891FC0006931FC0F21DD35FFE6795FF1E13EB32B122F9010C263F80C7
            FF5EE0CB17B2A361978975995891FC0006931F4091A361978975995891FC0006
            931F4091A361978975995891FC0006931F4091A361978975995891FC0006931F
            4091A361978975995891FC0006931F4091A361978975995891FC0006931F4091
            A361978975995891FC0006931F4091A361978975995891FC0006931FD052BC43
            DF25391A769958978915C90F6030F9012D7F2F84FBFCE57734EC32B12E132B92
            1FC060F203EA16AE823B5C028E865D26D6656245F203184C7E40DDCDAF0247C3
            2E13EB32B122F9010C263FA0AE7EBD5C92A361978975995891FC0006931F50F7
            F17AF971D5CBC1D1B0CBC4BA4CAC487E0083C90FA82BE6C7E3A25784A3619789
            75995891FC0006931F5057CF8FC7152F0A47C32E13EB32B122F9010C263FA0AE
            951F3FA297C6C137217134EC32B12E132B921FC060F203EADE9D8DBE72751C7F
            071247C32E13EB32B122F9010C263FA06EF96C74F05D418E3FA8391A76995897
            8915C90F6030F901751FCF46475E26F2E3FC4CACCBC48AE4073098FC80BACAD9
            E8B02B457E9C9F8975995891FC0006931F50573F1B1DF0422CF9717E26D66562
            45F203184C7E405DEB6C94BE64E4C7F99958978915C90F6030F90175DDB351F4
            AA911FE767625D2656243F80C1E407D4AD3B1B855E88253FCECFC4BA4CAC487E
            0083C90FA85B7D364A1488FC383F13EB32B122F9010C263FA06ECBD968F72B48
            7E9C9F8975995891FC0006931F50B7FD6CB4E3D320F2E3FC4CACCBC48AE40730
            98FC80BA5DCE467B1588FC383F13EB32B122F9010C263FA06EAFB3D12E5793FC
            383F13EB32B122F9010C263FA06EDFB3D1C6A741E4C7F99958978915C90F6030
            F90175BB9F8DB61488FC383F13EB32B122F9010C263FA02E71365A7D65C98FF3
            33B12E132B921FC060F203EA4267A3751797FC383F13EB32B122F9010C263FA0
            2E7A36EABE104B7E9C9F8975995891FC0006931F50973E1BB5AE32F9717E26D6
            656245F203184C7E40DD0167A3FA85263FCECFC4BA4CAC487E0083C90F68F97B
            2124FEF2575E88253FCECFC4BA4CAC487E0083C90F6839263F1E852B4E7E9C9F
            8975995891FC0006931FD0F5FB5A38FEB8BF4C7E9C8A8975995891FC0006931F
            B0CE7F57C4317FED5B11223F4EC5C4BA4CAC487E0083C90F38BF7A81C88F5331
            B12E132B921FC060F20346281688FC381513EB32B122F9010C263F6090FA057B
            D87777ED2F30B12E132B921FC060F20366F9E295E868D865625D2656243F80C1
            E4078C53B92BC861DFD7B5BFC0C4BA4CAC487E0083C90F18CA7D3FCECFC4BA4C
            AC487E0083C90F98EBE9AA4C5F868E865D26D6656245F203184C7EC074FFAE4D
            F9713626D6656245F203184C7E00458E865D26D6656245F203184C7E00458E86
            5D26D6656245F203184C7E00458E865D26D6656245F203184C7E00458E865D26
            D6656245F203184C7E00458E865D26D6656245F203184C7E00458E865D26D665
            6245F203184C7E00458E865D26D6656245F203184C7E00458E865D26D6656245
            F203184C7E00458E865D26D6656245F203184C7E00458E865D26D6656245F203
            184C7E00458E865D26D6656245F203184C7E00458E865D26D6656245F203184C
            7E00458E865D26D6656245F203184C7E00458E865D26D6656245F203184C7E00
            458E865D26D6656245F203184C7E00458E865D26D6656245F203184C7E00458E
            865D26D6656245F203184C7E00458E865D26D6656245F203184C7E00458E865D
            26D6656245F203184C7E00458E865D26D6656245F203184C7E00458E865D26D6
            656245F203184C7E00458E865D26D6656245F203184C7E00458E865D26D66562
            45F203184C7E00458E865D26D6656245F203184C7E00458E865D26D6656245F2
            03184C7E00458E865D26D6656245F203184C7E00458E865D26D6656245F20318
            4C7E00458E865D26D6656245F2032EE8E3A1FC9FE96B517E00458E865D26D665
            6245F203AEA35E1D4FE62E47F90114391A769958978915C90F186F7575FC3377
            39CA0FA0C8D1B0CBC4BA4CAC487EC060DBC3E3C7DCE5283F802247C32E13EB32
            B122F90153698FCA10E407F0C3D1B0CBC4BA4CAC487EC054BBE4C7F4B5283F80
            2247C32E13EB32B122F90123698FE21CE407F0C3D1B0CBC4BA4CAC487EC03C0B
            27E9BBAD39F90114391A769958978915C90F18467BFC263F802247C32E13EB32
            B122F901C3D86EBFC90FA0C8F2EC32B12E132B921F30C9BB33F46DB79BFC008A
            1C0DBB4CACCBC48AE4074C62B53D911F4091FDD965625D2656243F6092BFABED
            E67B4D7E00458E865D26D6656245F203C6B0D7FE921F409115DA65625D265624
            3F600C7BED2FF9011459A15D26D6656245F203C6B0D7FE921F409115DA65625D
            2656243F600C7BED2FF9011459A15D26D6656245F20366B0D45E921F40912DDA
            65625D2656243F60064BED25F90114D9A25D26D6656245F20366B0D45E921F40
            912DDA65625D2656243F60064BED25F90114D9A25D26D6656245F20366B0D45E
            921F40912DDA65625D2656243F60064BED25F90114D9A25D26D6656245F20306
            B0D1DE911F409145DA65625D2656243F60001BED1DF9011459A45D26D6656245
            F20306B0D1DE911F409145DA65625D2656243F60001BED1DF9011459A45D26D6
            656245F20306B0D1DE911F409145DA65625D2656243F60001BED1DF9011459A4
            5D26D6656245F20306B0D1DE911F409145DA65625D2656243FE0ECACB305F203
            28B24BBB4CACCBC48AE4079C9D75B6407E00457669978975995891FC80B3B3CE
            16C80FA0C82EED32B12E132B921F7076D75E67BF7FBB15BFD4C7FC28BACC3CE1
            567E3640F1FABDF62E2D32B12E134B901F7076D75E67F20358A7BB3DAEBD4B2B
            4CACCBC442E4079CDD85D7D9D3AF263F80A2BFD7FEC7ABF8C2BBB4C2C4BA4C2C
            477EC0A95D7B97C90F60857717FEF2857CED75BACCC4BA4C2C4A7EC0A95D7B97
            C90F609D15A7C36BAFD38F4CACCBC472E4079CDAB577D9C6FCD8AB3D7EBE75EB
            FD85C0D7754F87D75EA71526D6656221F2034EEDDABB6C4B7EECD81E4F2E335E
            B8BCD6E9F0DAEBB4C8C4BA4C2C417EC0A95D78979DB33D56FC30C017D54F8717
            5EA72D26D66562BB931F706A17DE65F203D845F17478E175DA65625D26B62FF9
            01A776E15D769E377E3CB9C678E1562AA7C30BAFD3154CACCBC476243FE0D42E
            BCCBE407B0A38FA7C30BAFD3754CACCBC4F6223FE0D4D67DF4F8C13F4FE87553
            EB6EF0B491C709986B79613A1AFE65625D26B60BF901A7B670C23E78A355CEFA
            FB0643E517DCB7403C48C0740BA74347C3974CACCBC4B6931F70765F2F90EE11
            BF7B4BA62DBFDDBEB7FED8EB4B015FB4FB9EB93C13EB32B18DE4079CDD776FEC
            BDE2BB4FCC0F0F0F70253BBEC8F3264CACCBC4B6901F7076DFFD07FE7DF3A3FE
            058B3FAAFC005EDA77D5DC81897599D86AF20306F8D621FBEFF7FD789FD775D9
            B07A3BCB0FE09D5DDEB1762B26D66562EBC80F98619773F6C6FCF8F8B446FDEB
            CB8FDD7F0580B9E69ED13FEEF0B9BF5A8EFC8031369E53B7BFF26AC71DBAE209
            93ED135821FAB0213C00586774D5C80F9867F7F763D4BFD12EFB6E45D57CF7A4
            1EDAF2F203802D864688FC80C1D2EF7B0BDDF4507E9CE19702603AF9015C50E2
            AE23F2E30CBF1400D3C90FE082126FAA931F67F8A500984E7E00D7B4FB070B4E
            79DFF98A5FAD4B8100B0CED0F678C80FA06EF9ACBC2E24B6DF8A24E7B0CD2E42
            00A89B1B1E3FE407D0B0BD40F6FD30DF0BDCF70338863BC4759958977B8014C9
            0FA06DCBFBD1E507F015E98F0ABC1E13EB126C45F2035863F567F26E79E555FD
            C7E8F2780097575F1716C20F13EB126C45F203586FC57D09CF991FBBFC30C099
            B5D68585F030B13EC156243F804DBA2FA63A6D7EECF2F300A7F5725DFC77D587
            EEAF7A0126D625D88AE407B0C917F323F18151777E3C806B7B77987E6C7835E9
            B5995897602B921FC00BC548E8BEF86AC7F79DE73EACF6B68F07706D0B87E987
            F3F42B26D625D88AE407F0ACBE252FF6D4C72E3F18704ECB87E98703E21F26D6
            25D88AE407F06CF5C9FEB0FC48DFA7EF860F0670791F0FD30F07C4FFCFC4BA04
            5B91FC005E5871BEEFDE73507E0047AA1CA61F0E88BF985897602B921FC00BDD
            F37D716F7AF115F02DC5C3F4C30171710E26B640B015C90FE0ADDD6FE0FAEF0B
            EEB264F7BDE9C7CF57BBCFF687BBA91FA61F0E88EF8760620B045B91FC001ACE
            764677D773A0A875987EDCFE80F830B13EC156243F80C1E40750D43D4CBFFC23
            B7DA1526D625D88AE4073098FC008A561CA61FBBBE636D1C13EB126C45F20318
            4C7E0045EB0ED38FF3BDE8F43026D625D88AE4073098FC008A561FA66FCBC4BA
            045B91FC0006FB981F1F6F37FBF49F0157E530DD65625D2656243F80C1E40750
            E468D865625D2656243F80C1E40750E468D865625D2656243F80C1E40750E468
            D865625D2656243F80C1E40750E468D865625D2656243F80C1E40750E468D865
            625D2656243F80C1E40750E468D865625D2656243F80C1E40750E468D865625D
            2656243F80C1E40750E468D865625D2656243F80C1E40750E468D865625D2656
            243F80C1E40750F7770FB8F617384CAFE0EF5885FC0006931F40DDD31E70E12F
            931F2BF83B56213F80C1E407D0F27B15B8F097C98F75FC1DFB487E0083C90F80
            10F94188FC0006931F0021F28310F9010C263F0042E40721F203184C7E0084C8
            0F42E4073098FC0008911F84C80F6030F90110223F08911FC060F20320447E10
            223F80C1E4074088FC20447E0083C90F8010F94188FC0006931F0021F28310F9
            010C263F0042E40721F203184C7E0084C80F42E4073098FC0008911F84C80F60
            30F90110223F08911FC060F20320447E10223F80C1E4074088FC20447E0083C9
            0F8010F94188FC0006931F0021F28310F9010C263F0042E40721F203184C7E00
            84C80F42E4073098FC0008911F84C80F6030F90110223F08911FC060F2032044
            7E10223F80C1E4074088FC20447E0083C90F8010F94188FC0006931F0021F283
            10F9010C263F0042E40721F203184C7E0084C80F42E4073098FC0008911F84C8
            0F6030F90110223F08911FC060F20320447E10223F80C1E4074088FC20447E00
            83C90F8010F94188FC0006931F0021F28310F9010C263F0042E40721F203184C
            7E0084C80F42E4073098FC0008911F84C80F6030F90110223F08911FC060F203
            20447E10223F80C1E4074088FC20447E0083C90F8010F94188FC0006931F0021
            F28310F9010C263F0042E40721F203184C7E0084C80F42E4073098FC0008911F
            84C80F6030F90110223F08911FC060F20320447E10223F80C1E4074088FC2044
            7E0083C90F8010F94188FC0006931F0021F28310F9010C263F0042E40721F203
            184C7E0084C80F42E4073098FC0008911F84C80F6030F90110223F08911FC060
            F20320447E10223F80C1E4074088FC20447E0083C90F8010F94188FC0006931F
            0021F28310F9010C263F0042E40721F203184C7E0084C80F42E4073098FC0008
            911F84C80F6030F90110223F08911FC060F20320447E10223F80C1E4074088FC
            20447E0083C90F8010F94188FC0006931F0021F28310F9010C263F0042E40721
            F203184C7E0084C80F42E4073098FC0008911F84C80F6030F90110223F08911F
            C060F20320447E10223F80C1E4074088FC20447E0083C90F8010F94188FC0006
            931F0021F28310F9010C263F0042E40721F203184C7E0084C80F42E4073098FC
            0008911F84C80F6030F90110223F08911FC060F20320447E10223F80C1E40740
            88FC20447E0083C90F8010F94188FC0006931F0021F28310F9010C263F0042E4
            0721F203184C7E0084C80F42E4073098FC0008911F84C80F6030F90110223F08
            911FC060F20320447E10223F80C1E4074088FC20447E0083C90F8010F94188FC
            0006931F0021F28310F9010C263F0042E40721F203184C7E0084C80F42E40730
            98FC0008911F84C80F6030F90110223F08911FC060F20320447E10223F80C1E4
            074088FC20447E0083C90F8010F94188FC0006931F0021F28310F9010C263F00
            42E40721F203184C7E0084C80F42E4073098FC0008911F84C80F6030F9011022
            3F08911FC060F20320447E10223F80C1E4074088FC20447E0083C90F8010F941
            88FC0006931F0021F28310F9010C263F807BFAB7D372EB4B7E10223F80C1E407
            704FBF775A6883C90F42E4073098FC00EE497E3097FC0006931FC03DC90FE692
            1FC060F203B827F9C15CF203184C7E00F7243F984B7E0083C90FE0923E2EB7DF
            E407B3C80F6030F9015C92FCE0C2E4073098FC002EA9951F2F6D5F6BF28310F9
            010C263F80ABDA5E204FBA8B4E7E10223F80C1E407701FBB07C96371FBC90F42
            E4073098FC00EE69C71479B700E50721F203184C7E00F7B4EF33212F77A0FC20
            447E0083C90FE09E3EDEF763FB6767C90F42E4073098FC00EE69C56D0717D6A0
            FCE048F203184C7E00B7F56FAD6DD960FF7D11EFFDE060F203184C7E0084C80F
            42E4073098FC0008911F84C80F6030F90110223F08911FC060F20320447E1022
            3F80C1E4074088FC20447E0083C90F8010F94188FC0006931F0021F28310F901
            0C263F0042E40721F203184C7E0084C80F42E4073098FC00EEAC75E3F39FFFB8
            BEEEE40721F203184C7E00B7F5B4D6DEEDB177DBEFE3DE931F84C80F6030F901
            DCD3DF9DF6728F6D597DF28310F9010C263F807BAAE4C7C70DF958DC7EF28310
            F9010C263F807BAABCF2AA921F8FE6ABB66C4BB6931FC060F203B8A78FF9B1F0
            F4C896378DD8966C273F80C1E407704FBF775AF1A98FDFFFD9EA274F6C4BB693
            1FC060F203B8A7E5FCF8F8CE10F9C117C90F6030F901DC93FC602EF9010C263F
            807B5AC88F151F8A253F3892FC0006931FC03D2DF483FCE0E4E4073098FC00EE
            E95D3FACBB1DA1FCE048F203184C7E00B7F53721EAC1203FF822F9010C263F80
            DBDA725373F9C117C90F6030F901DC597D072EFC29B71DE460F203184C7E0077
            B66EB3C90FBE4B7E0083C90F806E27C80FBE4B7E0083C90F801FFFB6DCF2422B
            7E34D6437E10233F80C1E40740D7F21DD35FFE6795FF1E8AE4073098FC0058E1
            6725769F27F9F847A0427E0083C90F8010F94188FC0006931F0021F28310F901
            0C263F0042E40721F203184C7E0084C80F42E4073098FC0008911F84C80F6030
            F90110223F08911FC060F20320447E10223F80C1E407C00A953B0FCA0F42E407
            3098FC0058A19216F28310F9010C263F0056A8AC44F94188FC0006931F00EB7C
            DC9F2FD9966C273F80C1E407C06A2B0AC4B6643BF9010C263F00B6AB77886DC9
            76F203184C7E00ECA51221B625DBC90F6030F9015CD2BB9575C0B2B22D49931F
            C060F203B8A4E2ABA1A2BBCB275F11223F80C1E4077049EB3E96EAB1EB36931F
            84C80F6030F9015CD5EA02F96DCB72931F84C80F6030F9015CD82E05F2A4BEEE
            E40721F203184C7E00D7962890DF16B69FFC20447E0083C90FE0DA9E76D7D3B2
            8ABE404B7E10223F80C1E4077079CB05B2F05FD6BDFC9AF28310F9010C263F80
            3BA817C8F21F7C477E7024F9010C263F809B585D200B5F64F9ABC90F42E40730
            98FC006EE2EF12DB6571FDF765BDF78383C90F6030F901DCC72E4F80ACFE76C7
            7C53EE407E0083C90FE056FEADB203B696FC20447E0083C90FE06E165E2EB5FB
            37FAFB3FDA966C273F80C1E4074088FC20447E0083C90F8010F94188FC000693
            1F0021F28310F9010C263F0042E40721F203184C7E0084C80F42E4073098FC00
            2EE9F7CAFAD682921F84C80F6030F9015C92FCE0C2E4073098FC002EE9637E1C
            D027F28310F9010C263F804B921F5C98FC0006931FC025C90F2E4C7E0083C90F
            E0929E56D6DF1D253F984B7E0083C90FE092E40717263F80C1E4077055CB0522
            3F984B7E0083C90FE0AA3EEEB77FE407B3C80F6030F9015C58B140E407B3C80F
            6030F9015C5BFD399027DBD79AFC20447E0083C90FE0F25617C893EEA2931F84
            C80F6030F901DCC45E11F26461FBC90F42E4073098FC00EE69C71A79B700E507
            21F203184C7E00F7B4F0C1BB2BCAE4E38DD597FF4B68911FC060F203B8A7FA7D
            3F2A35223F3892FC0006931FC06DFD5B6BAD0D568F0AF94188FC0006931F0021
            F28310F9010C263F0042E40721F203184C7E0084C80F42E4073098FC0008911F
            84C80F6030F90110223F08911FC060F20320447E10223F80C1E4074088FC2044
            7E0083C90F8010F94188FC0006931F0021F28310F9010C263F0042E40721F203
            184C7E0084C80F42E4073098FC00A27EAF8EBB2D0AF94188FC0006931F40D4DF
            D5719F75213F08911FC060F203887AB73AEEB034E40721F203184C7E00510BAB
            E3F27B437E10223F80C1E4071075E7D5213F08911FC060F20388FAB8641ED75D
            20F28310F9010C263F80A84A7E3C2EBA43E40721F203184C7E0051C5FC785C71
            8DC80F42E4073098FC00A2EAF9F123BA4C0EBE0989FC20447E0083C90F20EAE5
            7D3FBEB24F8EBF0389FC20447E0083C90F206AE1D07FF067F21E1F03F28310F9
            010C263F80A8E5E71C8E5C2CF283CB901FC060F20388FAF892A7C3768BFCE032
            E4073098FC00A28AEFB838E08558F283CB901FC060F20388AABFE13BBD64E407
            97213F80C1E40710D5FABCA9E89E911F5C86FC0006931F40D48A8FBB0DBD104B
            7E7019F203184C7E0051EBEEB6912810F9C165C80F6030F901446DB9D9DFBE11
            223FB80CF9010C263F80A88DF71ADFB140E40797213F80C1E40710B5313F1EFB
            1588FCE032E4073098FC00A2B6E7C7BBAFD3FD82F283CB901FC060F20388DA2B
            3F1E9B0B447E7019F203184C7E00513BE6C7635B81C80F2E437E0083C90F206A
            DFFC78F7352B5F5C7E7019F203184C7E005189FC78AC2A10F9C165C80F6030F9
            014485F2E3D12F10F9C165C80F6030F90144E5F2E3DDD77FF78DE40797213F80
            C1E4071095CE8F47B940E40797213F80C1E4071075407E3C6A05223FB80CF901
            0C263F80A863F2E3DDF7FAFD4DE50797213F80C1E40790F67B7BA477C5C79DF6
            447E3091FC0006931FC031FEDB21872D8A7A84C80F26921FC060F203B8A46281
            C80F26921FC060F203B8AA4A81C80F26921FC060F203B8B62FEE2EF94188FC00
            06931FC0E575EF8F1EFDBEB625DBC90F6030F901DCC1BB0D263F98487E0083C9
            0FE03E8EBC09C9437E10233F80C1E407702B4FAB4C7E3091FC0006931FC0DDFC
            DB665FB907A26DC976F203184C7E0084C80F42E4073098FC0008911F84C80F60
            30F90110223F08911FC060F20320447E10223F80C1E4074088FC20447E0083C9
            0F8010F94188FC0006931F0021F28310F9010C263F0042E40721F203184C7E00
            84C80F42E4073098FC0008911F84C80F6030F90110223F08911FC060F2032044
            7E10223F80C1E4074088FC20447E0083C90F8010F94188FC0006931F0021F283
            10F9010C263F0042E40721F203184C7E0084C80F42E4073098FC0008911F84C8
            0F6030F90110223F08911FC060F20320447E10223F80C1E4074088FC20447E00
            83C90F8010F94188FC0006931F0021F28310F9010C263F0042E40721F203184C
            7E0084C80F42E4073098FC0008911F84C80F6030F90110223F08911FC060F203
            20447E10223F80C1E4074088FC20447E0083C90F8010F94188FC0006931F0021
            F28310F9010C263F0042E40721F203184C7E0084C80F42E4073098FC0008911F
            84C80F6030F90110223F08911FC060F20320447E10223F80C1E4074088FC2044
            7E0083C90F8010F94188FC0006931F0021F28310F9010C263F0042E40721F203
            184C7E0084C80F42E4073098FC0008911F84C80F6030F90110223F08911FC060
            F20320447E10223F80C1E4074088FC20447E0083C90F8010F94188FC0006931F
            0021F28310F9010C263F0042E40721F203184C7E0084C80F42E4073098FC0008
            911F84C80F6030F90110223F08911FC060F20320447E10223F80C1E4074088FC
            20447E0083C90F8010F94188FC0006931F0021F28310F9010C263F0042E40721
            F203184C7E0084C80F42E4073098FC0008911F84C80F6030F90110223F08911F
            C060F20320447E10223F80C1E4074088FC20447E0083C90F8010F94188FC0006
            931F0021F28310F9010C263F0042E40721F203184C7E0084C80F42E4073098FC
            0008911F84C80F6030F90110223F08911FC060F20320447E10223F80C1E40740
            88FC20447E0083C90F8010F94188FC0006931F0021F28310F9010C263F0042E4
            0721F203184C7E0084C80F42E4073098FC0008911F84C80F6030F90110223F08
            911FC060F20320447E10223F80C1E4074088FC20447E0083C90F8010F94188FC
            0006931F0021F28310F9010C263F0042E40721F203184C7E0084C80F42E40730
            98FC0008911F84C80F6030F90110223F08911FC060F20320447E10223F80C1E4
            074088FC20447E0083C90F8010F94188FC0006931F0021F28310F9010C263F00
            42E40721F203184C7E0084C80F42E4073098FC0008911F84C80F6030F9011022
            3F08911FC060F20320447E10223F80C1E4074088FC20447E0083C90F8010F941
            88FC0006931F0021F28310F9010C263F0042E40721F203184C7E0084C80F42E4
            073098FC0008911F84C80F6030F90110223F08911FC060F20320447E10223FB8
            8B8FE754E07A1C956035F94188FCE02EE407DC90A312AC263F08911FDC85FC80
            1B725482D5E40721F283BB901F70438E4AB09AFC20447E7017F2036EC8510956
            931F84C80FEE427EC00D392AC16AF28310F9C15DC80FB8214725584D7E10223F
            B80BF90137E4A804ABC90F42E40777213FE0861C956035F94188FCE02EE407DC
            90A312AC263F08911FDCC5727ED8A730944B1B42E40721F283BB7046814B7269
            4388FC20447E7017CE2870492E6DA8FBB95E8AD785FC20447E70173B9E51FE7D
            295B18BE4E7E40D1EF8BA57269C80F42E40777B1CB19C52E86B3911F50F1F74A
            F9787578C823447E70175BCE281F3F35CB3A866F911FF0D1BBCB64C5639F6B8A
            EDE40777B1EE8C52FCB85EEB18BE457E40C58A02911F84C80FEEA2754669DD24
            C42E8603BC7BCBEC8AFC68BDFB162EA35B20F28310F9C15D14CF282BEE4E6817
            43DAD385F9FBA2DBF22F0B2E5EEEA65520F28310F9C15D7C3CA3ACBB2DBA450C
            69CB67A07A7E384BC1A353202E1942E40777B1AE2E1658C1708CE5D3D2C62736
            5DC8DC50F172901F84C80FEE62C7FCB07CE1600BA7A54A7E680F7852B928E407
            21F283BBD89E1F762E7CCBEAEB77B94F5CD4DCD9C702911F84C80FEE624B7ED8
            B6F0755E3F09BB5BF1CA46170EDBC90FAE6FCBBF9B7EFB6707FE8F9750C2EEBA
            AF6C74EDB09DFCE0CA84075CCC2E05E20287DFDCEA8A83C90F2E4875C0856D2C
            109739FC55BFAC5C416C273FB814E10177E04A87DD152F2B1711DBC90FAE60F7
            F7A402D7E3D804CB2A0FA6AE23B6931FCC263C805D1C70A8B2AFE01D55732BF2
            83913C8A0309A1339095051522E426E407C378140772E4077C91FCB809F9C118
            1BDF6CEAE11FF8487EC017C98F9B901F9CDD5E1F71E3E11FF8487EC017C98F9B
            901F9CD7BE9FADE9E11F58163DFA5841B04C7BDC87FCE074429FE8EFB11F78E7
            B0738F45047F098FBB911F9C48F456621EF5E1E61C71A0E5E3E3A66B8A75E407
            DF77CC0D8CE507E0B40475EE424888FCE09B8E090FE04A36FE5382ED0145C56B
            CD354597FCE00B5407B0CE2E4F63DA245051BFDC5C53B4C80F0E253C80D5767C
            09A595021FB5AE38D71475F283236C3934D868C063718DFCB7255EFEBFEFFEF7
            7FFFEFB77F2738B5EE65E59AA2487E90E5E90E60BB8F15F1EE9C54F9B3C04B2B
            2E2BD71415F223EBDFF579B70BD2D31DC08E3E9E7516CE490FEF568755D65D56
            AE173E921F417FAFCC3B5C939EEE00F65539E5AC7BF6A3C58EE26E96F3E3A140
            584B7EA47CBC68AF477800099575BAE2BD1FEBD857DCC7EA4BEFE14A6191FC48
            B94F7EA80E20ED69CFFCDD1E87E5C7C3EEE2368A2719054297FC88B8C9A5283C
            80C3FC2C9C77DB437EC0EEEAFF907A93630F7B911F11D7BE0E5507703689CC58
            609B7107ADD7715CFBE4C3BEE4C7FE961F05475F87C20338A783F3E361AD7103
            DD97912B108AE4C7FEAE971FAA0338BFFAA6AAAF26F70CE1CE56BC8BF59E9FF9
            4997FCD8D9C7C7BF59D7A1F000A6F8FBF6F45DFE2D5681705BEB3E44E7F79F72
            8DF092FCD8D935F2437500133D9D7BF6FA04422F29E19E565F41CB1F1401F263
            4F9553FBC9AF46E1015CC68E1F807E9FCF52877FFCB527447EEC696E7E6C79D7
            E6397F23E0E6F67DCAC2398C1BF2D79E10F9B19BC4BB1E4FF5639FF9B7007822
            3F60237FED09911FBB79F9690FA7BD743DDD015C9BFC808DFCB527447EECA375
            C3DDEF5EBA9EEE00EE60DFF57BC2650E69FEDA13223FF6F1EE83AE4F75E90A0F
            E03EE4076CE4AF3D21F26307CBD7E7D76FC1A33A801B921FB091BFF684C88F1D
            2C07C617F3437800F7B4FB9D3A9CC3B8217FED09911F5B7DBC388FCF0FD501DC
            9CA73E603B7FF309911F5B7DAC8B23AF5EE101F0C8DF7070F5578341E40721F2
            6393CA9579C0D5AB3A007E73BF73D8C5D7DFBFCA25C98F4D2A9765F4A14B7800
            FCB5D7E2F5D40737F77409F89BCF2EE4C77AC587B7507EAC0B0F8B03B8835D16
            EFC29AB54BB98FDF1782BFF9EC427EAC577F4672F7E72E57B4879501DC84F600
            3833F9B152EBE1EDBBF9E19112B895EDF9A13D0072E4C74AADA238E0232077FC
            FA00A3AD5BB995D56AAF026C273FD6E83EB6EDFEF68FE587490F90C09DADFE4C
            8E8F6C5780EDE4C71ADD17531D931F1E17011EB1FCB0630176213FDA561CFDD3
            1F7EE54111E09FDDF3C38E05D891FC685BF13E724F56001C437B009C9CFCE859
            1D12EE1B0A70801DF3C3960648901F3DAB2B427E001C607B7E58CE0051F2A361
            CB6BA8BCFE0AE000962DC0C9C98F862DCF6078440438C0AD96EDD32FBBE30D6D
            AF3A31E00CE44755E2931CED77807DDDEA95AE3BE6C7BE2503B0407E54C90F80
            93BBD5531F8FFD9AE156CD067C9DFC2871132B80F3931FDBBFC8962F0550213F
            4AE407C0F9DDEA24BDBD3D161EDAAE3A34E00CE4C767A1F678D8EF00BB921FAB
            FFF8962F05D0223F3ECBE5C7C39607D88FFC58F7679F5C7562C049C88F0FA2ED
            F1B0E501F673ABB750AFCE8F9753F2A9BBC061E4C7073BFE5BDA91FF2CF7AE9A
            563F3E9DF0D1E8FC3F2170244F7DACF883FFFEACFC000E233F96ECFB6076D843
            E3F657F48EF81744F901FC263F56FF41EB143892FC58322E3F3EBE54ACF2EDA6
            3C847BBC047E9BB2BB12BFECBAFCF8F7A7AC53E048F2E3ADDD1FC9BE9E1F1FBF
            D7AC0F42F17809FC76F2FCC8FDF350F70BFE7C91DFFFAF575E0147921F6F251E
            C9A28F8E1B5F31A53D80D1CE9C1FF56C58F881BB1F85B2F129118010F9F15AE8
            61ECC8FCB8F68730CA0FE0C939DFB4B6E2E313979FB5D8FE7596BFF21986065C
            9BFC786D5C7EE4DA63AF9F705FF203F8ED9C4F7DACFBE8F65D9E0059FD28F0F5
            A10197273F5E382C12725F79C70F80DFEB27DCD7F97F42E04853F2E3EF8FB462
            9BEDBB00AD53E060F2E3D9F63B6674BFF8A9F263C487309EFCC7038E37223F3E
            BEAA6ADD67A3CB0F6016F9F1ECE07787EFF5C577FC10C673BE7E7A975F16B8AA
            F3E7C78E3F8CFC0046931FCFD28F61FB1EEEB7BF0EF8EFBFBAA51F8A563F1E87
            5EF40C5CC3D98ED1A19F67F72FEB8D1FC0C1E4C70BD1C7B01DBF78E85350A28F
            6D5B7EBC5D3EF01EB8B0BF77B438C3CFF3E46C4F56C80FE060F2E3ADFF36726E
            11EFF2C543C7F1E8D3FAAB7FC8DC274E028424EEA7E49557C074F263B0F3E7C7
            880FBC070849DC52497E00D3C98FD9F67A5DD3C2D7DCEB9FE88A8EFFC07B80A8
            7D23447E00D3C98F2BC83D5F91FE52EBBE9D572A038354FEE9E424AF8FB55181
            03C88F2B989B1FBFFFCB2D1F160C70721F23E4F81B0E26BE20C047F2E30A763C
            8E87F2E3B41F780F70B02DEF47F7B157C005C88FF14EFB44FC019F79EFC11218
            6ADD67F29E76E103D4C98FF14EFB6814BA81A3FC002EA37B23DAD32E7C803AF9
            31DE699FAF487CE0FD437E00D7D25ABCF203B800F931DEC4FCD8F2C5E5077025
            F203B81BF931DE39DF77FEEE6B3EF9EE07DE03E4FCB7AFBA1F66E5BD1FC01DC8
            8FF14E9E1F8F9D3E6E32FA1302ECA8FE8E8E2F3EF5F1F06432F025F263B641FF
            12B6CBD3201E2C81F3ABDC67F02F4F7D0037213F668B7E5055E2D168E3FBD1E5
            07707EF2036081FC98EDFCAFBCAA7CAFE237F560094CD12D90E36F796EA302DF
            223F661B9A1F2FBFE3C76FEAC11218A45E205F79F5A92793816F911FB38DCE8F
            EE37951FC044EB9EEF5DFE52FB7E32A1750A1C497ECC263F000018447E0C76DA
            D701D7FF456DF507DE6B0F008089E4C760E77CEAA3F88E0E6FFC0000B821F931
            D857F2E3E3371DF1899300007C85FC184C7E0000308BFC18EC9CF9F198F081F7
            00007C85FC18ECF8CF80DFF241552FD57F6CF901007001F263B6FF0EE57B1DC4
            7FCEF7C5E73D1E1BCAA1FBC7EB3F21000027273FA8F2FC0300001BC90FAAE407
            00001BC90F4AB4070000DBC90F4AE4070000DBC90F3ED31E0000EC427EF099FC
            00006017F283121F7A0B00C076F20300003888FC0000000E223F00008083C80F
            0000E020F20300003888FC0000000E223F00008083C80F0000E020F203000038
            88FC0000000E223F00008083C80F0000E020F20300003888FC0000000E223F00
            008083C80F0000E020FFE5C7FF003D4BE97B0B39F89B0000000049454E44AE42
            6082}
          Proportional = True
          Visible = False
        end
        object pg_ctrl_geom_char: TPageControl
          Left = 258
          Top = 3
          Width = 426
          Height = 393
          ActivePage = tb_sht_concrete_geom_char
          TabOrder = 0
          object tb_sht_composite_geom_char: TTabSheet
            Caption = #1057#1090#1072#1083#1077#1078#1077#1083#1077#1079#1086#1073#1077#1090#1086#1085#1085#1086#1077' '#1089#1077#1095#1077#1085#1080#1077
            ExplicitLeft = 0
            ExplicitTop = 0
            ExplicitWidth = 0
            ExplicitHeight = 0
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
              RowCount = 7
              ScrollBars = ssNone
              TabOrder = 0
              OnDrawCell = strng_grd_first_raw_bold
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
                24)
            end
          end
          object tb_sht_steel_geom_char: TTabSheet
            Caption = #1057#1090#1072#1083#1100#1085#1086#1077' '#1089#1077#1095#1077#1085#1080#1077
            ImageIndex = 2
            ExplicitLeft = 0
            ExplicitTop = 0
            ExplicitWidth = 0
            ExplicitHeight = 0
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
              OnDrawCell = strng_grd_first_raw_bold
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
            ExplicitLeft = 0
            ExplicitTop = 0
            ExplicitWidth = 0
            ExplicitHeight = 0
            object strng_grd_concrete_sect_geom_character: TStringGrid
              Left = 0
              Top = 0
              Width = 418
              Height = 365
              Align = alClient
              ColCount = 2
              DrawingStyle = gdsClassic
              TabOrder = 0
              OnDrawCell = strng_grd_first_raw_bold
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
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object strng_grd_results: TStringGrid
        Left = 0
        Top = 0
        Width = 1064
        Height = 506
        Align = alTop
        ColCount = 2
        DefaultColWidth = 200
        DrawingStyle = gdsClassic
        RowCount = 18
        ScrollBars = ssNone
        TabOrder = 0
        OnDrawCell = strng_grd_results_rendering
        ColWidths = (
          513
          349)
      end
    end
  end
  object btn_logger: TButton
    Left = 250
    Top = 599
    Width = 99
    Height = 25
    Caption = #1055#1086#1082#1072#1079#1072#1090#1100' '#1078#1091#1088#1085#1072#1083
    TabOrder = 6
    OnClick = btn_loggerClick
  end
  object rd_grp_code: TRadioGroup
    Left = 355
    Top = 592
    Width = 326
    Height = 39
    Caption = ' '#1057#1074#1086#1076' '#1055#1088#1072#1074#1080#1083' '
    Columns = 2
    ItemIndex = 1
    Items.Strings = (
      #1057#1055' 266.1325800.2016'
      #1057#1055' 35.13330.2011')
    TabOrder = 7
    OnClick = rd_grp_codeClick
  end
  object MainMenu1: TMainMenu
    Images = ImageList1
    Left = 416
    Top = 552
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
        OnClick = N8Click
      end
      object Help: TMenuItem
        Caption = #1057#1087#1088#1072#1074#1082#1072
        OnClick = HelpClick
      end
    end
  end
  object SaveDialog_Model: TSaveDialog
    DefaultExt = 'arcC'
    Filter = #1060#1072#1081#1083' '#1087#1088#1086#1077#1082#1090#1072' (*.arsC)|*.arsC'
    Options = [ofOverwritePrompt, ofHideReadOnly, ofEnableSizing]
    Left = 468
    Top = 552
  end
  object OpenDialog_Model: TOpenDialog
    Filter = #1060#1072#1081#1083#1099' '#1087#1088#1086#1077#1082#1090#1086#1074' (*.arsC)|*.arsC|'#1042#1089#1077' '#1092#1072#1081#1083#1099' |*.*'
    Left = 524
    Top = 552
  end
  object ImageList1: TImageList
    Left = 584
    Top = 552
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
    Left = 368
    Top = 552
  end
end
