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
  DesignSize = (
    505
    265)
  PixelsPerInch = 96
  TextHeight = 13
  object mm_logger: TMemo
    Left = 0
    Top = 0
    Width = 505
    Height = 228
    Align = alTop
    Anchors = [akLeft, akTop, akRight, akBottom]
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = 16
    Font.Name = 'Courier New'
    Font.Style = []
    ParentFont = False
    ScrollBars = ssVertical
    TabOrder = 0
    ExplicitLeft = -8
  end
  object btn_clean: TButton
    Left = 422
    Top = 234
    Width = 75
    Height = 25
    Anchors = [akRight, akBottom]
    Caption = #1054#1095#1080#1089#1090#1080#1090#1100
    TabOrder = 1
    OnClick = btn_cleanClick
  end
end
