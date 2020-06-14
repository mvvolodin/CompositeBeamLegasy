object StudDefinitionForm: TStudDefinitionForm
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = ' '#1043#1080#1073#1082#1080#1077' '#1091#1087#1086#1088#1099' '
  ClientHeight = 234
  ClientWidth = 753
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object btn_ok: TBitBtn
    Left = 511
    Top = 201
    Width = 75
    Height = 25
    Caption = #1055#1088#1080#1084#1077#1085#1080#1090#1100
    TabOrder = 0
    OnClick = btn_okClick
  end
  object btn_cancel: TButton
    Left = 592
    Top = 201
    Width = 75
    Height = 25
    Caption = #1054#1090#1084#1077#1085#1080#1090#1100
    TabOrder = 1
    OnClick = btn_cancelClick
  end
  object grp_bx_placement: TGroupBox
    Left = 426
    Top = 8
    Width = 319
    Height = 185
    Caption = '  '#1056#1072#1089#1087#1086#1083#1086#1078#1077#1085#1080#1077' '
    TabOrder = 2
    object lbl_edge_studs_dist: TLabel
      Left = 19
      Top = 32
      Width = 172
      Height = 13
      Caption = #1064#1072#1075' '#1091#1087#1086#1088#1086#1074' '#1074' '#1082#1088#1072#1081#1085#1080#1093' '#1090#1088#1077#1090#1103#1093', '#1084#1084
    end
    object lbl_middle_studs_dist: TLabel
      Left = 19
      Top = 90
      Width = 166
      Height = 13
      Caption = #1064#1072#1075' '#1091#1087#1086#1088#1086#1074' '#1074' '#1089#1088#1077#1076#1085#1077#1081' '#1090#1088#1077#1090#1080', '#1084#1084
    end
    object edt_edge_studs_rows_num: TLabel
      Left = 19
      Top = 61
      Width = 226
      Height = 13
      Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1088#1103#1076#1086#1074' '#1091#1087#1086#1088#1086#1074' '#1074' '#1082#1088#1072#1081#1085#1080#1093' '#1090#1088#1077#1090#1103#1093
    end
    object lbl_middle_studs_rows_num: TLabel
      Left = 19
      Top = 116
      Width = 220
      Height = 13
      Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1088#1103#1076#1086#1074' '#1091#1087#1086#1088#1086#1074' '#1074' '#1089#1088#1077#1076#1085#1077#1081' '#1090#1088#1077#1090#1080
    end
    object edt_edge_studs_dist: TEdit
      Left = 262
      Top = 28
      Width = 48
      Height = 21
      TabOrder = 0
    end
    object edt_middle_studs_dist: TEdit
      Left = 262
      Top = 86
      Width = 48
      Height = 21
      TabOrder = 1
    end
    object cmb_bx_middle_studs_rows_num: TComboBox
      Left = 262
      Top = 113
      Width = 48
      Height = 21
      Style = csDropDownList
      ItemIndex = 0
      TabOrder = 2
      Text = '1'
      Items.Strings = (
        '1'
        '2')
    end
    object cmb_bx_edge_studs_rows_num: TComboBox
      Left = 262
      Top = 57
      Width = 48
      Height = 21
      Style = csDropDownList
      ItemIndex = 0
      TabOrder = 3
      Text = '1'
      Items.Strings = (
        '1'
        '2')
    end
    object chck_bx_n_r: TCheckBox
      Left = 16
      Top = 144
      Width = 209
      Height = 17
      Caption = ' '#1041#1086#1083#1077#1077' '#1086#1076#1085#1086#1075#1086' '#1091#1087#1086#1088#1072' '#1074' '#1086#1076#1085#1086#1081' '#1075#1086#1092#1088#1077
      TabOrder = 4
    end
  end
  object grp_bx_characteristics: TGroupBox
    Left = 8
    Top = 8
    Width = 412
    Height = 185
    Caption = ' '#1061#1072#1088#1072#1082#1090#1077#1088#1080#1089#1090#1080#1082#1080
    TabOrder = 3
    object lbl_stud_diameter: TLabel
      Left = 19
      Top = 104
      Width = 63
      Height = 13
      Caption = #1044#1080#1072#1084#1077#1090#1088', '#1084#1084
    end
    object lbl_stud_height: TLabel
      Left = 19
      Top = 133
      Width = 56
      Height = 13
      Caption = #1042#1099#1089#1086#1090#1072', '#1084#1084
    end
    object lbl_stud_safety_factor: TLabel
      Left = 19
      Top = 159
      Width = 155
      Height = 13
      Caption = #1050#1086#1101#1092#1092#1080#1094#1080#1077#1085#1090' '#1091#1089#1083#1086#1074#1080#1081' '#1088#1072#1073#1086#1090#1099
    end
    object lbl_stud_yield_strength: TLabel
      Left = 19
      Top = 75
      Width = 130
      Height = 13
      Caption = #1055#1088#1077#1076#1077#1083' '#1090#1077#1082#1091#1095#1077#1089#1090#1080', ['#1052#1055#1072']'
    end
    object edt_stud_height: TEdit
      Left = 292
      Top = 127
      Width = 100
      Height = 21
      ReadOnly = True
      TabOrder = 0
    end
    object edt_stud_safety_factor: TEdit
      Left = 292
      Top = 154
      Width = 100
      Height = 21
      TabOrder = 1
    end
    object edt_stud_yield_strength: TEdit
      Left = 292
      Top = 73
      Width = 100
      Height = 21
      TabOrder = 2
    end
    object edt_stud_diameter: TEdit
      Left = 292
      Top = 100
      Width = 100
      Height = 21
      ReadOnly = True
      TabOrder = 3
    end
    object pnl_stud_part_number: TPanel
      Left = 11
      Top = 20
      Width = 390
      Height = 41
      TabOrder = 4
      object lbl_stud_part_number: TLabel
        Left = 8
        Top = 12
        Width = 243
        Height = 13
        Caption = #1054#1073#1086#1079#1085#1072#1095#1077#1085#1080#1077' '#1075#1080#1073#1082#1086#1075#1086' '#1091#1087#1086#1088#1072' '#1043#1054#1057#1058' '#1056' 55738-2013'
      end
      object cmb_bx_stud_part_number: TComboBox
        Left = 281
        Top = 12
        Width = 100
        Height = 21
        Style = csDropDownList
        TabOrder = 0
        OnChange = cmb_bx_stud_part_numberChange
      end
    end
  end
  object btn_close: TButton
    Left = 673
    Top = 201
    Width = 75
    Height = 25
    Caption = #1047#1072#1082#1088#1099#1090#1100
    TabOrder = 4
    OnClick = btn_closeClick
  end
end
