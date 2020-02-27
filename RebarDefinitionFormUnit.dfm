object RebarDefinitionForm: TRebarDefinitionForm
  Left = 0
  Top = 0
  Caption = #1042#1099#1073#1086#1088' '#1072#1088#1084#1072#1090#1091#1088#1099
  ClientHeight = 189
  ClientWidth = 774
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
  object bt_btn_Ok: TBitBtn
    Left = 692
    Top = 152
    Width = 75
    Height = 25
    Caption = #1055#1088#1080#1084#1077#1085#1080#1090#1100
    TabOrder = 0
    OnClick = bt_btn_OkClick
  end
  object grp_bx_characteristics: TGroupBox
    Left = 8
    Top = 8
    Width = 425
    Height = 169
    Caption = ' '#1061#1072#1088#1072#1082#1090#1077#1088#1080#1089#1090#1080#1082#1080' '
    TabOrder = 1
    object lbl_diameter: TLabel
      Left = 20
      Top = 107
      Width = 191
      Height = 13
      Caption = #1053#1086#1084#1080#1085#1072#1083#1100#1085#1099#1081' '#1076#1080#1072#1084#1077#1090#1088' '#1072#1088#1084#1072#1090#1091#1088#1099', '#1084#1084':'
    end
    object lbl_R_s_n: TLabel
      Left = 20
      Top = 80
      Width = 246
      Height = 13
      Caption = #1053#1086#1088#1084#1072#1090#1080#1074#1085#1086#1077' '#1089#1086#1087#1088#1086#1090#1080#1074#1083#1077#1085#1080#1077' '#1088#1072#1089#1090#1103#1078#1077#1085#1080#1102', '#1052#1055#1072':'
    end
    object lbl_safety_factor: TLabel
      Left = 20
      Top = 134
      Width = 205
      Height = 13
      Caption = #1050#1086#1101#1092#1092#1080#1094#1080#1077#1085#1090' '#1085#1072#1076#1105#1078#1085#1086#1089#1090#1080' '#1087#1086' '#1072#1088#1084#1072#1090#1091#1088#1077':'
    end
    object edt_diameter: TEdit
      Left = 272
      Top = 103
      Width = 121
      Height = 21
      TabOrder = 0
    end
    object edt_R_s_n: TEdit
      Left = 272
      Top = 76
      Width = 121
      Height = 21
      TabOrder = 1
    end
    object edt_safety_factor: TEdit
      Left = 272
      Top = 130
      Width = 121
      Height = 21
      TabOrder = 2
    end
    object pnl_rebar_grade: TPanel
      Left = 17
      Top = 20
      Width = 384
      Height = 41
      TabOrder = 3
      object lbl_rebar_grade: TLabel
        Left = 4
        Top = 14
        Width = 85
        Height = 13
        Caption = ' '#1050#1083#1072#1089#1089' '#1072#1088#1084#1072#1090#1091#1088#1099
      end
      object cmb_bx_rebar_grade: TComboBox
        Left = 255
        Top = 11
        Width = 121
        Height = 21
        TabOrder = 0
        OnChange = cmb_bx_rebar_gradeChange
      end
    end
  end
  object grp_bx_placement: TGroupBox
    Left = 439
    Top = 8
    Width = 328
    Height = 138
    Caption = ' '#1056#1072#1089#1087#1086#1083#1086#1078#1077#1085#1080#1077'  '
    TabOrder = 2
    object lbl_b: TLabel
      Left = 24
      Top = 32
      Width = 97
      Height = 13
      Caption = #1064#1072#1075' '#1072#1088#1084#1072#1090#1091#1088#1099', '#1084#1084':'
    end
    object lbl_a_u: TLabel
      Left = 24
      Top = 56
      Width = 200
      Height = 13
      Caption = #1047#1072#1097#1080#1090#1085#1099#1081' '#1089#1083#1086#1081' '#1074#1077#1088#1093#1085#1077#1081' '#1072#1088#1084#1072#1090#1091#1088#1099', '#1084#1084':'
    end
    object lbl_a_l: TLabel
      Left = 24
      Top = 80
      Width = 196
      Height = 13
      Caption = #1047#1072#1097#1080#1090#1085#1099#1081' '#1089#1083#1086#1081' '#1085#1080#1078#1085#1077#1081' '#1072#1088#1084#1072#1090#1091#1088#1099', '#1084#1084':'
    end
    object edt_a_l: TEdit
      Left = 246
      Top = 80
      Width = 63
      Height = 21
      TabOrder = 0
      Text = '50'
    end
    object edt_a_u: TEdit
      Left = 246
      Top = 53
      Width = 63
      Height = 21
      TabOrder = 1
      Text = '50'
    end
    object edt_b: TEdit
      Left = 246
      Top = 26
      Width = 63
      Height = 21
      TabOrder = 2
      Text = '200'
    end
  end
  object bt_btn_cancel: TButton
    Left = 603
    Top = 152
    Width = 75
    Height = 25
    Caption = #1054#1090#1084#1077#1085#1080#1090#1100
    TabOrder = 3
    OnClick = bt_btn_cancelClick
  end
end
