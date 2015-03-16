object Form1: TForm1
  Left = 341
  Top = 143
  Width = 1305
  Height = 859
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Image1: TImage
    Left = 672
    Top = 56
    Width = 585
    Height = 353
  end
  object BitBtn1: TBitBtn
    Left = 1064
    Top = 728
    Width = 105
    Height = 41
    Caption = 'Draw'
    TabOrder = 0
  end
  object GroupBox1: TGroupBox
    Left = 100
    Top = 50
    Width = 500
    Height = 200
    Caption = 'Vertex'
    TabOrder = 1
  end
  object GroupBox2: TGroupBox
    Left = 100
    Top = 300
    Width = 500
    Height = 100
    Caption = 'Light'
    TabOrder = 2
  end
  object GroupBox3: TGroupBox
    Left = 100
    Top = 450
    Width = 500
    Height = 200
    Caption = 'Camera'
    TabOrder = 3
  end
  object Memo1: TMemo
    Left = 664
    Top = 456
    Width = 593
    Height = 193
    Lines.Strings = (
      'Memo1')
    TabOrder = 4
  end
  object MainMenu1: TMainMenu
    object F1: TMenuItem
      Caption = 'FILE'
      object Open1: TMenuItem
        Caption = 'Open'
        OnClick = Open1Click
      end
    end
  end
  object OpenDialog1: TOpenDialog
    Filter = '.txt|*.txt'
    Left = 32
  end
end
