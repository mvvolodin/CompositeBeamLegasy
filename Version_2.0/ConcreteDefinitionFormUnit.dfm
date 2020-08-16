object ConcreteDefinitionForm: TConcreteDefinitionForm
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = ' '#1042#1099#1073#1086#1088' '#1073#1077#1090#1086#1085#1072
  ClientHeight = 342
  ClientWidth = 460
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = False
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object BtBtnConcreteChoice: TBitBtn
    Left = 215
    Top = 309
    Width = 75
    Height = 25
    Caption = #1055#1088#1080#1084#1077#1085#1080#1090#1100
    TabOrder = 0
    OnClick = BtBtnConcreteChoiceClick
  end
  object pnl_concrete_grade: TPanel
    Left = 8
    Top = 8
    Width = 441
    Height = 41
    TabOrder = 1
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
      Style = csDropDownList
      TabOrder = 0
      OnChange = cmb_bx_concrete_grade_listChange
    end
  end
  object btn_cancel: TButton
    Left = 296
    Top = 309
    Width = 75
    Height = 25
    Caption = #1054#1090#1084#1077#1085#1080#1090#1100
    TabOrder = 2
    OnClick = btn_cancelClick
  end
  object btn_close: TButton
    Left = 377
    Top = 309
    Width = 75
    Height = 25
    Caption = #1047#1072#1082#1088#1099#1090#1100
    TabOrder = 3
    OnClick = btn_closeClick
  end
  object grp_bx_characteristics: TGroupBox
    Left = 8
    Top = 55
    Width = 441
    Height = 248
    Caption = ' '#1061#1072#1088#1072#1082#1090#1077#1088#1080#1089#1090#1080#1082#1080' '
    TabOrder = 4
    object lbl_R_bn: TLabel
      Left = 16
      Top = 23
      Width = 301
      Height = 13
      Caption = #1053#1086#1088#1084#1072#1090#1080#1074#1085#1086#1077' '#1089#1086#1087#1088#1086#1090#1080#1074#1083#1077#1085#1080#1077' '#1073#1077#1090#1086#1085#1072' '#1087#1088#1080' '#1089#1078#1072#1090#1080#1080' Rbn, '#1052#1055#1072':'
    end
    object lbl_R_btn: TLabel
      Left = 16
      Top = 50
      Width = 329
      Height = 13
      Caption = #1053#1086#1088#1084#1072#1090#1080#1074#1085#1086#1077' '#1089#1086#1087#1088#1086#1090#1080#1074#1083#1077#1085#1080#1077' '#1073#1077#1090#1086#1085#1072' '#1087#1088#1080' '#1088#1072#1089#1090#1103#1078#1077#1085#1080#1080' Rbtn, '#1052#1055#1072':'
    end
    object lbl_E_b: TLabel
      Left = 16
      Top = 77
      Width = 199
      Height = 13
      Caption = #1053#1072#1095#1072#1083#1100#1085#1099#1081' '#1084#1086#1076#1091#1083#1100' '#1091#1087#1088#1091#1075#1086#1089#1090#1080' Eb, '#1052#1055#1072':'
    end
    object lbl_density: TLabel
      Left = 16
      Top = 104
      Width = 192
      Height = 13
      Caption = #1059#1076#1077#1083#1100#1085#1099#1081' '#1074#1077#1089' '#1073#1077#1090#1086#1085#1085#1086#1081' '#1089#1084#1077#1089#1080', '#1082#1075'/'#1084'3:'
    end
    object lbl_phi_b_cr: TLabel
      Left = 16
      Top = 131
      Width = 174
      Height = 13
      Caption = #1050#1086#1101#1092#1092#1080#1094#1080#1077#1085#1090' '#1087#1086#1083#1079#1091#1095#1077#1089#1090#1080' '#1073#1077#1090#1086#1085#1072':'
    end
    object lbl_gamma_b: TLabel
      Left = 16
      Top = 158
      Width = 253
      Height = 13
      Caption = #1050#1086#1101#1092#1092#1080#1094#1080#1077#1085#1090' '#1085#1072#1076#1105#1078#1085#1086#1089#1090#1080' '#1087#1086' '#1073#1077#1090#1086#1085#1091' '#1087#1088#1080' '#1089#1078#1072#1090#1080#1080' '
    end
    object lbl_gamma_bt: TLabel
      Left = 16
      Top = 185
      Width = 277
      Height = 13
      Caption = #1050#1086#1101#1092#1092#1080#1094#1080#1077#1085#1090' '#1085#1072#1076#1105#1078#1085#1086#1089#1090#1080' '#1087#1086' '#1073#1077#1090#1086#1085#1091' '#1087#1088#1080' '#1088#1072#1089#1090#1103#1078#1077#1085#1080#1080' '
    end
    object lbl_epsilon_b_lim: TLabel
      Left = 16
      Top = 212
      Width = 250
      Height = 13
      Caption = #1055#1088#1077#1076#1077#1083#1100#1085#1072#1103' '#1086#1090#1085#1086#1089#1080#1090#1077#1083#1100#1085#1072#1103' '#1076#1077#1092#1086#1088#1084#1072#1094#1080#1103' '#1073#1077#1090#1086#1085#1072' '
    end
    object edt_R_bn: TEdit
      Left = 373
      Top = 19
      Width = 52
      Height = 21
      ReadOnly = True
      TabOrder = 0
    end
    object edt_R_btn: TEdit
      Left = 373
      Top = 46
      Width = 52
      Height = 21
      ReadOnly = True
      TabOrder = 1
    end
    object edt_E_b: TEdit
      Left = 373
      Top = 73
      Width = 52
      Height = 21
      ReadOnly = True
      TabOrder = 2
    end
    object edt_density: TEdit
      Left = 373
      Top = 100
      Width = 52
      Height = 21
      TabOrder = 3
    end
    object edt_phi_b_cr: TEdit
      Left = 373
      Top = 127
      Width = 52
      Height = 21
      TabOrder = 4
    end
    object edt_gamma_b: TEdit
      Left = 373
      Top = 154
      Width = 52
      Height = 21
      TabOrder = 5
    end
    object edt_gamma_bt: TEdit
      Left = 373
      Top = 181
      Width = 52
      Height = 21
      TabOrder = 6
    end
    object edt_epsilon_b_lim: TEdit
      Left = 373
      Top = 208
      Width = 52
      Height = 21
      TabOrder = 7
    end
  end
end
