object ConcreteDefinitionForm: TConcreteDefinitionForm
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = #1042#1099#1073#1086#1088' '#1073#1077#1090#1086#1085#1072
  ClientHeight = 258
  ClientWidth = 462
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object lbl_R_bn: TLabel
    Left = 8
    Top = 64
    Width = 295
    Height = 13
    Caption = #1053#1086#1088#1084#1072#1090#1080#1074#1085#1086#1077' '#1089#1086#1087#1088#1086#1090#1080#1074#1083#1077#1085#1080#1077' '#1073#1077#1090#1086#1085#1072' '#1087#1088#1080' '#1089#1078#1072#1090#1080#1080' Rb ('#1052#1055#1072')'
  end
  object lbl_E_b: TLabel
    Left = 8
    Top = 117
    Width = 199
    Height = 13
    Caption = #1053#1072#1095#1072#1083#1100#1085#1099#1081' '#1084#1086#1076#1091#1083#1100' '#1091#1087#1088#1091#1075#1086#1089#1090#1080' Eb ('#1052#1055#1072')'
  end
  object lbl_R_btn: TLabel
    Left = 8
    Top = 90
    Width = 323
    Height = 13
    Caption = #1053#1086#1088#1084#1072#1090#1080#1074#1085#1086#1077' '#1089#1086#1087#1088#1086#1090#1080#1074#1083#1077#1085#1080#1077' '#1073#1077#1090#1086#1085#1072' '#1087#1088#1080' '#1088#1072#1089#1090#1103#1078#1077#1085#1080#1080' Rbt ('#1052#1055#1072')'
  end
  object lbl_gamma_b: TLabel
    Left = 8
    Top = 143
    Width = 253
    Height = 13
    Caption = #1050#1086#1101#1092#1092#1080#1094#1080#1077#1085#1090' '#1085#1072#1076#1105#1078#1085#1086#1089#1090#1080' '#1087#1086' '#1073#1077#1090#1086#1085#1091' '#1087#1088#1080' '#1089#1078#1072#1090#1080#1080' '
  end
  object lbl_epsilon_b_lim: TLabel
    Left = 8
    Top = 197
    Width = 250
    Height = 13
    Caption = #1055#1088#1077#1076#1077#1083#1100#1085#1072#1103' '#1086#1090#1085#1086#1089#1080#1090#1077#1083#1100#1085#1072#1103' '#1076#1077#1092#1086#1088#1084#1072#1094#1080#1103' '#1073#1077#1090#1086#1085#1072' '
  end
  object lbl_gamma_bt: TLabel
    Left = 8
    Top = 170
    Width = 277
    Height = 13
    Caption = #1050#1086#1101#1092#1092#1080#1094#1080#1077#1085#1090' '#1085#1072#1076#1105#1078#1085#1086#1089#1090#1080' '#1087#1086' '#1073#1077#1090#1086#1085#1091' '#1087#1088#1080' '#1088#1072#1089#1090#1103#1078#1077#1085#1080#1080' '
  end
  object edt_R_bn: TEdit
    Left = 333
    Top = 55
    Width = 100
    Height = 21
    TabOrder = 0
  end
  object edt_E_b: TEdit
    Left = 333
    Top = 108
    Width = 100
    Height = 21
    TabOrder = 1
  end
  object edt_R_btn: TEdit
    Left = 333
    Top = 81
    Width = 100
    Height = 21
    TabOrder = 2
  end
  object BtBtnConcreteChoice: TBitBtn
    Left = 333
    Top = 214
    Width = 100
    Height = 25
    Caption = #1055#1088#1080#1084#1077#1085#1080#1090#1100
    TabOrder = 3
    OnClick = BtBtnConcreteChoiceClick
  end
  object edt_gamma_b: TEdit
    Left = 333
    Top = 134
    Width = 100
    Height = 21
    TabOrder = 4
    Text = '1.3'
  end
  object edt_epsilon_b_lim: TEdit
    Left = 333
    Top = 187
    Width = 100
    Height = 21
    TabOrder = 5
    Text = '0.0016'
  end
  object edt_gamma_bt: TEdit
    Left = 333
    Top = 161
    Width = 100
    Height = 21
    TabOrder = 6
    Text = '1.5'
  end
  object pnl_concrete_grade: TPanel
    Left = 8
    Top = 8
    Width = 441
    Height = 41
    TabOrder = 7
    object lbl_concrete_grade: TLabel
      Left = 15
      Top = 14
      Width = 194
      Height = 13
      Caption = #1050#1083#1072#1089#1089' '#1073#1077#1090#1086#1085#1072' '#1087#1086' '#1087#1088#1086#1095#1085#1086#1089#1090#1080' '#1085#1072' '#1089#1078#1072#1090#1080#1077
    end
    object cmb_bx_concrete_grade_list: TComboBox
      Left = 325
      Top = 11
      Width = 100
      Height = 21
      TabOrder = 0
      OnChange = cmb_bx_concrete_grade_listChange
    end
  end
end
