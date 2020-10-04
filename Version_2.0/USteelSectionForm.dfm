object SteelSectionForm: TSteelSectionForm
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = #1042#1099#1073#1086#1088' '#1089#1090#1072#1083#1100#1085#1086#1075#1086' '#1089#1077#1095#1077#1085#1080#1103
  ClientHeight = 296
  ClientWidth = 528
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
    Left = 8
    Top = 4
    Width = 512
    Height = 250
    ActivePage = tb_sheet_welded_profile
    TabOrder = 0
    object TabSheet_Standart: TTabSheet
      Caption = #1055#1088#1086#1082#1072#1090#1085#1086#1081' '#1076#1074#1091#1090#1072#1074#1088' '#1043#1054#1057#1058' '#1056' 57837'
      ImageIndex = 1
      object Label10: TLabel
        Left = 360
        Top = 3
        Width = 78
        Height = 13
        Caption = #1053#1086#1084#1077#1088' '#1087#1088#1086#1092#1080#1083#1103
      end
      object Image_stand: TImage
        Left = 195
        Top = 21
        Width = 151
        Height = 169
        Proportional = True
      end
      object ComboBox_profil: TComboBox
        Left = 360
        Top = 21
        Width = 113
        Height = 21
        Style = csDropDownList
        TabOrder = 0
        OnChange = ComboBox_profilChange
      end
      object StringGrid_B: TStringGrid
        Left = 360
        Top = 45
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
        Left = 3
        Top = 21
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
    object tb_sheet_welded_profile: TTabSheet
      Caption = #1057#1074#1072#1088#1085#1086#1081' '#1076#1074#1091#1090#1072#1074#1088
      ImageIndex = 1
      object img_weld_sect: TImage
        Left = 237
        Top = 3
        Width = 148
        Height = 216
      end
      object StringGrid1: TStringGrid
        Left = 391
        Top = 3
        Width = 110
        Height = 216
        ScrollBars = ssNone
        TabOrder = 0
        RowHeights = (
          24
          24
          24
          24
          23)
      end
      object GroupBox1: TGroupBox
        Left = 3
        Top = 3
        Width = 228
        Height = 216
        Caption = ' '#1043#1077#1086#1084#1077#1090#1088#1080#1103' '#1089#1077#1095#1077#1085#1080#1103' '
        TabOrder = 1
        object lbl_b_uf: TLabel
          Left = 3
          Top = 30
          Width = 141
          Height = 13
          Caption = #1064#1080#1088#1080#1085#1072' '#1074#1077#1088#1093#1085#1077#1081' '#1087#1086#1083#1082#1080', '#1084#1084':'
        end
        object lbl_t_uf: TLabel
          Left = 3
          Top = 55
          Width = 146
          Height = 13
          Caption = #1058#1086#1083#1097#1080#1085#1072' '#1074#1077#1088#1093#1085#1077#1081' '#1087#1086#1083#1082#1080', '#1084#1084':'
        end
        object lbl_b_lf: TLabel
          Left = 3
          Top = 81
          Width = 140
          Height = 13
          Caption = #1064#1080#1088#1080#1085#1072' '#1085#1080#1078#1085#1077#1081' '#1087#1086#1083#1082#1080', '#1084#1084': '
        end
        object lbl_t_lf: TLabel
          Left = 3
          Top = 107
          Width = 145
          Height = 13
          Caption = #1058#1086#1083#1097#1080#1085#1072' '#1085#1080#1078#1085#1077#1081' '#1087#1086#1083#1082#1080', '#1084#1084': '
        end
        object lbl_h_w: TLabel
          Left = 3
          Top = 133
          Width = 98
          Height = 13
          Caption = #1042#1099#1089#1086#1090#1072' '#1089#1090#1077#1085#1082#1080', '#1084#1084':'
        end
        object lbl_t_w: TLabel
          Left = 3
          Top = 159
          Width = 106
          Height = 13
          Caption = #1058#1086#1083#1097#1080#1085#1072' '#1089#1090#1077#1085#1082#1080', '#1084#1084':'
        end
        object edt_b_uf: TEdit
          Left = 158
          Top = 25
          Width = 57
          Height = 21
          TabOrder = 0
        end
        object edt_t_uf: TEdit
          Left = 158
          Top = 52
          Width = 57
          Height = 21
          TabOrder = 1
        end
        object edt_b_lf: TEdit
          Left = 158
          Top = 78
          Width = 57
          Height = 21
          TabOrder = 2
        end
        object edt_t_lf: TEdit
          Left = 158
          Top = 104
          Width = 57
          Height = 21
          TabOrder = 3
        end
        object edt_h_w: TEdit
          Left = 158
          Top = 130
          Width = 57
          Height = 21
          TabOrder = 4
        end
        object edt_t_w: TEdit
          Left = 158
          Top = 156
          Width = 57
          Height = 21
          TabOrder = 5
        end
      end
    end
  end
  object btk_ok: TButton
    Left = 264
    Top = 260
    Width = 75
    Height = 25
    Caption = #1055#1088#1080#1084#1077#1085#1080#1090#1100
    TabOrder = 1
    OnClick = btk_okClick
  end
  object btn_cancel: TButton
    Left = 345
    Top = 260
    Width = 75
    Height = 25
    Caption = #1054#1090#1084#1077#1085#1080#1090#1100
    TabOrder = 2
    OnClick = btn_cancelClick
  end
  object btn_close: TButton
    Left = 426
    Top = 260
    Width = 75
    Height = 25
    Caption = #1047#1072#1082#1088#1099#1090#1100
    TabOrder = 3
    OnClick = btn_closeClick
  end
  object btn_launch_logger: TButton
    Left = 18
    Top = 263
    Width = 75
    Height = 25
    Caption = #1051#1086#1075
    TabOrder = 4
    OnClick = btn_launch_loggerClick
  end
end
