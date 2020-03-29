object SteelSectionForm: TSteelSectionForm
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = #1042#1099#1073#1088#1072#1090#1100' '#1089#1090#1072#1083#1100#1085#1086#1077' '#1089#1077#1095#1077#1085#1080#1077
  ClientHeight = 298
  ClientWidth = 483
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
  inline SteelSectionDefinitionFrame: TSteelSectionDefinitionFrame
    Left = 2
    Top = 0
    Width = 462
    Height = 297
    TabOrder = 0
    ExplicitLeft = 2
    ExplicitWidth = 462
    ExplicitHeight = 297
    inherited GroupBox_Common: TGroupBox
      Left = 2
      Top = 3
      ExplicitLeft = 2
      ExplicitTop = 3
      inherited Button_Apply: TButton
        OnClick = SectSelectCom_ParamFrame1Button_ApplyClick
      end
      inherited btn_cancel: TButton [1]
        TabOrder = 1
      end
      inherited PageControl2: TPageControl [2]
        TabOrder = 2
        inherited TabSheet_Standart: TTabSheet
          ExplicitHeight = 222
          inherited ComboBox_profil: TComboBox
            Left = 331
            Top = 21
            ExplicitLeft = 331
            ExplicitTop = 21
          end
          inherited StringGrid_B: TStringGrid
            Left = 331
            Top = 42
            ExplicitLeft = 331
            ExplicitTop = 42
            ColWidths = (
              50
              50)
          end
        end
      end
    end
  end
end
