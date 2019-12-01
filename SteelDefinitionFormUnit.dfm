object SteelDefinitionForm: TSteelDefinitionForm
  Left = 285
  Top = 177
  BorderStyle = bsDialog
  Caption = #1042#1099#1073#1086#1088' '#1089#1090#1072#1083#1080
  ClientHeight = 253
  ClientWidth = 536
  Color = clBtnFace
  Font.Charset = RUSSIAN_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label9: TLabel
    Left = 24
    Top = 200
    Width = 93
    Height = 13
    Caption = #1055#1083#1086#1090#1085#1086#1089#1090#1100' ('#1082#1075'/'#1084'3)'
  end
  object Label_gamma_m: TLabel
    Left = 240
    Top = 200
    Width = 226
    Height = 13
    Caption = #1050#1086#1101#1092#1092#1080#1094#1080#1077#1085#1090' '#1085#1072#1076#1077#1078#1085#1086#1089#1090#1080' '#1087#1086' '#1084#1072#1090#1077#1088#1080#1072#1083#1091'    m'
  end
  object Label11: TLabel
    Left = 452
    Top = 196
    Width = 5
    Height = 16
    Caption = 'g'
    Font.Charset = SYMBOL_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Symbol'
    Font.Style = []
    ParentFont = False
  end
  object Panel1: TPanel
    Left = 8
    Top = 8
    Width = 521
    Height = 41
    TabOrder = 1
    object Label2: TLabel
      Left = 136
      Top = 12
      Width = 30
      Height = 13
      Caption = #1057#1090#1072#1083#1100
      WordWrap = True
    end
    object ComboBox_steel: TComboBox
      Left = 448
      Top = 8
      Width = 65
      Height = 21
      TabOrder = 0
      OnChange = ComboBox_steelChange
    end
    object ComboBox_gost: TComboBox
      Left = 176
      Top = 8
      Width = 265
      Height = 21
      ItemIndex = 0
      TabOrder = 1
      Text = #1058#1072#1073#1083'. '#1042'.3  '#1057#1055' 16.13330.2017'
      OnChange = ComboBox_gostChange
      Items.Strings = (
        #1058#1072#1073#1083'. '#1042'.3  '#1057#1055' 16.13330.2017'
        #1058#1072#1073#1083'. '#1042'.4 '#1057#1055' 16.13330.2017')
    end
  end
  object GroupBox1: TGroupBox
    Left = 4
    Top = 52
    Width = 229
    Height = 133
    Caption = ' '#1059#1087#1088#1091#1075#1080#1077' '#1089#1074#1086#1081#1089#1090#1074#1072' '
    TabOrder = 2
    object Label3: TLabel
      Left = 8
      Top = 24
      Width = 112
      Height = 13
      Caption = #1052#1086#1076#1091#1083#1100' '#1070#1085#1075#1072', E ('#1052#1055#1072')'
    end
    object Label4: TLabel
      Left = 8
      Top = 52
      Width = 122
      Height = 13
      Caption = #1052#1086#1076#1091#1083#1100' '#1089#1076#1074#1080#1075#1072', G ('#1052#1055#1072')'
    end
    object Label5: TLabel
      Left = 8
      Top = 80
      Width = 140
      Height = 13
      Caption = #1050#1086#1101#1092#1092#1080#1094#1080#1077#1085#1090' '#1055#1091#1072#1089#1089#1086#1085#1072', nu'
    end
    object Edit_E: TEdit
      Left = 160
      Top = 16
      Width = 60
      Height = 21
      Enabled = False
      TabOrder = 0
      Text = '206000'
    end
    object Edit_G: TEdit
      Left = 160
      Top = 48
      Width = 60
      Height = 21
      Enabled = False
      TabOrder = 1
      Text = '79200'
    end
    object Edit_nu: TEdit
      Left = 160
      Top = 80
      Width = 60
      Height = 21
      Enabled = False
      TabOrder = 2
      Text = '0.3'
    end
  end
  object GroupBox2: TGroupBox
    Left = 240
    Top = 52
    Width = 289
    Height = 141
    Caption = ' '#1053#1086#1088#1084#1072#1090#1080#1074#1085#1099#1077' '#1089#1086#1087#1088#1086#1090#1080#1074#1083#1077#1085#1080#1103' '#1089#1090#1072#1083#1080'   '
    TabOrder = 3
    object Label_Run: TLabel
      Left = 12
      Top = 66
      Width = 198
      Height = 13
      Caption = #1042#1088#1077#1084#1077#1085#1085#1086#1077' '#1089#1086#1087#1088#1086#1090#1080#1074#1083#1077#1085#1080#1077'  Run ('#1052#1055#1072') '
    end
    object Label_thick: TLabel
      Left = 12
      Top = 14
      Width = 136
      Height = 13
      Caption = #1076#1083#1103' '#1090#1086#1083#1097#1080#1085#1099' '#1087#1088#1086#1082#1072#1090#1072' ('#1084#1084')'
    end
    object Label6: TLabel
      Left = 12
      Top = 102
      Width = 193
      Height = 13
      Caption = #1052#1072#1082#1089#1080#1084#1072#1083#1100#1085#1072#1103' '#1090#1086#1083#1097#1080#1085#1072' '#1087#1088#1086#1082#1072#1090#1072' ('#1084#1084')'
    end
    object Label_Ryn: TLabel
      Left = 12
      Top = 39
      Width = 148
      Height = 13
      Caption = #1055#1088#1077#1076#1077#1083' '#1090#1077#1082#1091#1095#1077#1089#1090#1080' Ryn ('#1052#1055#1072') '
    end
    object Edit_Sig_Run: TEdit
      Left = 224
      Top = 62
      Width = 57
      Height = 21
      Enabled = False
      TabOrder = 0
      Text = '0'
    end
    object Edit_max_thick: TEdit
      Left = 224
      Top = 100
      Width = 57
      Height = 21
      Enabled = False
      TabOrder = 1
      Text = '0'
    end
    object Edit_Sig_Ryn: TEdit
      Left = 224
      Top = 35
      Width = 57
      Height = 21
      Enabled = False
      TabOrder = 2
      Text = '0'
    end
  end
  object Edit_dens: TEdit
    Left = 172
    Top = 196
    Width = 60
    Height = 21
    Enabled = False
    TabOrder = 4
    Text = '7850'
  end
  object BitBtn_Cancel: TBitBtn
    Left = 456
    Top = 224
    Width = 75
    Height = 25
    Caption = #1042#1099#1093#1086#1076
    TabOrder = 6
    OnClick = BitBtn_CancelClick
  end
  object BitBtn_OK: TBitBtn
    Left = 376
    Top = 224
    Width = 75
    Height = 25
    Caption = #1055#1088#1080#1084#1077#1085#1080#1090#1100
    TabOrder = 0
    OnClick = BitBtn_OKClick
  end
  object Edit_gamma_m: TEdit
    Left = 480
    Top = 196
    Width = 49
    Height = 21
    Enabled = False
    TabOrder = 5
    Text = '1.025'
  end
end
