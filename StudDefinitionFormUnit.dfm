object StudDefinitionForm: TStudDefinitionForm
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = #1042#1099#1073#1086#1088' '#1091#1087#1086#1088#1072
  ClientHeight = 225
  ClientWidth = 414
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object lbl_stud_yield_strength: TLabel
    Left = 8
    Top = 43
    Width = 130
    Height = 13
    Caption = #1055#1088#1077#1076#1077#1083' '#1090#1077#1082#1091#1095#1077#1089#1090#1080', ['#1052#1055#1072']'
  end
  object lbl_stud_diameter: TLabel
    Left = 8
    Top = 81
    Width = 71
    Height = 13
    Caption = #1044#1080#1072#1084#1077#1090#1088', ['#1084#1084']'
  end
  object lbl_stud_height: TLabel
    Left = 8
    Top = 113
    Width = 64
    Height = 13
    Caption = #1042#1099#1089#1086#1090#1072', ['#1084#1084']'
  end
  object lbl_stud_part_number: TLabel
    Left = 8
    Top = 11
    Width = 243
    Height = 13
    Caption = #1054#1073#1086#1079#1085#1072#1095#1077#1085#1080#1077' '#1075#1080#1073#1082#1086#1075#1086' '#1091#1087#1086#1088#1072' '#1043#1054#1057#1058' '#1056' 55738-2013'
  end
  object lbl_stud_safety_factor: TLabel
    Left = 8
    Top = 144
    Width = 155
    Height = 13
    Caption = #1050#1086#1101#1092#1092#1080#1094#1080#1077#1085#1090' '#1091#1089#1083#1086#1074#1080#1081' '#1088#1072#1073#1086#1090#1099
  end
  object edt_stud_yield_strength: TEdit
    Left = 264
    Top = 35
    Width = 121
    Height = 21
    TabOrder = 0
    Text = '300'
  end
  object edt_stud_diameter: TEdit
    Left = 264
    Top = 70
    Width = 121
    Height = 21
    TabOrder = 1
  end
  object edt_stud_height: TEdit
    Left = 264
    Top = 107
    Width = 121
    Height = 21
    TabOrder = 2
  end
  object cmb_bx_stud_part_number: TComboBox
    Left = 264
    Top = 8
    Width = 121
    Height = 21
    TabOrder = 3
    OnChange = cmb_bx_stud_part_numberChange
  end
  object bt_btn_stud_choice: TBitBtn
    Left = 264
    Top = 182
    Width = 121
    Height = 25
    Caption = #1055#1088#1080#1084#1077#1085#1080#1090#1100
    TabOrder = 4
    OnClick = bt_btn_stud_choiceClick
  end
  object edt_stud_safety_factor: TEdit
    Left = 264
    Top = 141
    Width = 121
    Height = 21
    TabOrder = 5
    Text = '1.3'
  end
end
