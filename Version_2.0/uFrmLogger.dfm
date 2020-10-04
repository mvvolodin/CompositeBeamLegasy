object FormLogger: TFormLogger
  Left = 0
  Top = 0
  Caption = #1051#1086#1075
  ClientHeight = 265
  ClientWidth = 505
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object mm_logger: TMemo
    Left = 0
    Top = 0
    Width = 505
    Height = 228
    Align = alTop
    ScrollBars = ssVertical
    TabOrder = 0
    ExplicitHeight = 231
  end
  object btn_clean: TButton
    Left = 422
    Top = 234
    Width = 75
    Height = 25
    Caption = #1054#1095#1080#1089#1090#1080#1090#1100
    TabOrder = 1
    OnClick = btn_cleanClick
  end
end
