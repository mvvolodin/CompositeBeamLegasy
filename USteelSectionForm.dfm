object SteelSectionForm2: TSteelSectionForm2
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = #1042#1099#1073#1086#1088' '#1089#1090#1072#1083#1100#1085#1086#1075#1086' '#1089#1077#1095#1077#1085#1080#1103'2'
  ClientHeight = 296
  ClientWidth = 461
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
  object PageControl2: TPageControl
    Left = 3
    Top = 4
    Width = 455
    Height = 250
    ActivePage = TabSheet_Standart
    TabOrder = 0
    object TabSheet_Standart: TTabSheet
      Caption = #1055#1088#1086#1082#1072#1090#1085#1086#1081' '#1076#1074#1091#1090#1072#1074#1088' '#1043#1054#1057#1058' '#1056' 57837'
      ImageIndex = 1
      object Label10: TLabel
        Left = 328
        Top = 2
        Width = 78
        Height = 13
        Caption = #1053#1086#1084#1077#1088' '#1087#1088#1086#1092#1080#1083#1103
      end
      object Image_stand: TImage
        Left = 171
        Top = 21
        Width = 151
        Height = 169
        Proportional = True
      end
      object ComboBox_profil: TComboBox
        Left = 328
        Top = 18
        Width = 113
        Height = 21
        Style = csDropDownList
        TabOrder = 0
        OnChange = ComboBox_profilChange
      end
      object StringGrid_B: TStringGrid
        Left = 328
        Top = 40
        Width = 113
        Height = 140
        ColCount = 2
        DefaultColWidth = 50
        DefaultRowHeight = 18
        RowCount = 7
        FixedRows = 0
        TabOrder = 1
        ColWidths = (
          52
          52)
        RowHeights = (
          18
          18
          18
          18
          18
          18
          18)
      end
      object RadioGroupGOST57837: TRadioGroup
        Left = -4
        Top = 18
        Width = 169
        Height = 172
        ItemIndex = 0
        Items.Strings = (
          #1041#1072#1083#1086#1095#1085#1099#1081' '#1085#1086#1088#1084#1072#1083#1100#1085#1099#1081' ('#1041') '
          #1064#1080#1088#1086#1082#1086#1087#1086#1083#1086#1095#1085#1099#1081' ('#1064') '
          #1050#1086#1083#1086#1085#1085#1099#1081' ('#1050') '
          #1057#1074#1072#1081#1085#1099#1081' ('#1057')'
          #1041#1072#1083#1086#1095#1085#1099#1081' '#1076#1086#1087#1086#1083#1085#1080#1090'. ('#1044#1041') '
          #1050#1086#1083#1086#1085#1085#1099#1081' '#1076#1086#1087#1086#1083#1085#1080#1090'. ('#1044#1050') ')
        TabOrder = 2
        OnClick = RadioGroupGOST57837Click
      end
    end
  end
  object btk_ok: TButton
    Left = 221
    Top = 260
    Width = 75
    Height = 25
    Caption = #1055#1088#1080#1084#1077#1085#1080#1090#1100
    TabOrder = 1
    OnClick = btk_okClick
  end
  object btn_cancel: TButton
    Left = 302
    Top = 260
    Width = 75
    Height = 25
    Caption = #1054#1090#1084#1077#1085#1080#1090#1100
    TabOrder = 2
    OnClick = btn_cancelClick
  end
  object btn_close: TButton
    Left = 383
    Top = 260
    Width = 75
    Height = 25
    Caption = #1047#1072#1082#1088#1099#1090#1100
    TabOrder = 3
    OnClick = btn_closeClick
  end
end
