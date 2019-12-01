object RebarDefinitionForm: TRebarDefinitionForm
  Left = 0
  Top = 0
  Caption = #1042#1099#1073#1086#1088' '#1072#1088#1084#1072#1090#1091#1088#1099
  ClientHeight = 193
  ClientWidth = 377
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object lbl_rebar_grade: TLabel
    Left = 20
    Top = 19
    Width = 85
    Height = 13
    Caption = ' '#1050#1083#1072#1089#1089' '#1072#1088#1084#1072#1090#1091#1088#1099
  end
  object lbl_R_s_n: TLabel
    Left = 20
    Top = 59
    Width = 214
    Height = 13
    Caption = #1053#1086#1088#1084#1072#1090#1080#1074#1085#1086#1077' '#1089#1086#1087#1088#1086#1090#1080#1074#1083#1077#1085#1080#1077' '#1088#1072#1089#1090#1103#1078#1077#1085#1080#1102
  end
  object lbl_safety_factor: TLabel
    Left = 20
    Top = 123
    Width = 205
    Height = 13
    Caption = #1050#1086#1101#1092#1092#1080#1094#1080#1077#1085#1090' '#1085#1072#1076#1105#1078#1085#1086#1089#1090#1080' '#1087#1086' '#1072#1088#1084#1072#1090#1091#1088#1077':'
  end
  object lbl_diameter: TLabel
    Left = 24
    Top = 88
    Width = 195
    Height = 13
    Caption = #1053#1086#1084#1080#1085#1072#1083#1100#1085#1099#1081' '#1076#1080#1072#1084#1077#1090#1088' '#1072#1088#1084#1072#1090#1091#1088#1099', ['#1084#1084']'
  end
  object edt_safety_factor: TEdit
    Left = 240
    Top = 115
    Width = 121
    Height = 21
    TabOrder = 0
  end
  object edt_R_s_n: TEdit
    Left = 240
    Top = 56
    Width = 121
    Height = 21
    TabOrder = 1
  end
  object cmb_bx_rebar_grade: TComboBox
    Left = 240
    Top = 16
    Width = 121
    Height = 21
    TabOrder = 2
    OnChange = cmb_bx_rebar_gradeChange
  end
  object edt_diameter: TEdit
    Left = 240
    Top = 88
    Width = 121
    Height = 21
    TabOrder = 3
  end
  object bt_btn_Ok: TBitBtn
    Left = 286
    Top = 160
    Width = 75
    Height = 25
    Caption = #1055#1088#1080#1084#1077#1085#1080#1090#1100
    TabOrder = 4
    OnClick = bt_btn_OkClick
  end
end
