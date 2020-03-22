object DefineSteelForm: TDefineSteelForm
  Left = 285
  Top = 177
  BorderStyle = bsDialog
  Caption = #1042#1099#1073#1088#1072#1090#1100' '#1089#1090#1072#1083#1100
  ClientHeight = 271
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
    Left = 16
    Top = 193
    Width = 93
    Height = 13
    Caption = #1055#1083#1086#1090#1085#1086#1089#1090#1100' ('#1082#1075'/'#1084'3)'
  end
  object Label_gamma_m: TLabel
    Left = 237
    Top = 216
    Width = 226
    Height = 13
    Caption = #1050#1086#1101#1092#1092#1080#1094#1080#1077#1085#1090' '#1085#1072#1076#1077#1078#1085#1086#1089#1090#1080' '#1087#1086' '#1084#1072#1090#1077#1088#1080#1072#1083#1091'    m'
  end
  object Label11: TLabel
    Left = 449
    Top = 212
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
      Left = 114
      Top = 11
      Width = 30
      Height = 13
      Caption = #1057#1090#1072#1083#1100
      WordWrap = True
    end
    object cmb_bx_steel_grades: TComboBox
      Left = 447
      Top = 8
      Width = 65
      Height = 21
      ItemIndex = 2
      TabOrder = 0
      OnChange = cmb_bx_steel_gradesChange
      Items.Strings = (
        'C235'
        'C245'
        'C255'
        'C275'
        'C285'
        'C345'
        'C345K'
        'C375'
        'C390'
        'C390K'
        'C440'
        'C590'
        'C590K')
    end
    object cmb_bx_standard: TComboBox
      Left = 150
      Top = 8
      Width = 291
      Height = 21
      TabOrder = 1
      OnChange = cmb_bx_standardChange
    end
  end
  object GroupBox1: TGroupBox
    Left = 4
    Top = 52
    Width = 229
    Height = 117
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
      ReadOnly = True
      TabOrder = 0
    end
    object Edit_G: TEdit
      Left = 160
      Top = 48
      Width = 60
      Height = 21
      ReadOnly = True
      TabOrder = 1
    end
    object Edit_nu: TEdit
      Left = 160
      Top = 80
      Width = 60
      Height = 21
      ReadOnly = True
      TabOrder = 2
    end
  end
  object GroupBox_Prop: TGroupBox
    Left = 240
    Top = 52
    Width = 289
    Height = 158
    Caption = ' '#1053#1086#1088#1084#1072#1090#1080#1074#1085#1099#1077' '#1089#1086#1087#1088#1086#1090#1080#1074#1083#1077#1085#1080#1103' '#1089#1090#1072#1083#1080' ,  '#1052#1055#1072
    TabOrder = 3
    object StringGrid_Prop: TStringGrid
      Left = 3
      Top = 18
      Width = 283
      Height = 136
      ColCount = 3
      DefaultRowHeight = 18
      FixedCols = 0
      Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine]
      TabOrder = 0
      ColWidths = (
        129
        60
        60)
    end
  end
  object Edit_dens: TEdit
    Left = 164
    Top = 189
    Width = 60
    Height = 21
    ReadOnly = True
    TabOrder = 4
  end
  object btn_close: TBitBtn
    Left = 453
    Top = 238
    Width = 75
    Height = 25
    Caption = #1047#1072#1082#1088#1099#1090#1100
    TabOrder = 6
    OnClick = btn_closeClick
  end
  object btn_ok: TBitBtn
    Left = 291
    Top = 238
    Width = 75
    Height = 25
    Caption = #1055#1088#1080#1084#1077#1085#1080#1090#1100
    TabOrder = 0
    OnClick = btn_okClick
  end
  object Edit_gamma_m: TEdit
    Left = 477
    Top = 212
    Width = 49
    Height = 21
    ReadOnly = True
    TabOrder = 5
  end
  object btn_cancel: TButton
    Left = 372
    Top = 238
    Width = 75
    Height = 25
    Caption = #1054#1090#1084#1077#1085#1080#1090#1100
    TabOrder = 7
    OnClick = btn_cancelClick
  end
end
