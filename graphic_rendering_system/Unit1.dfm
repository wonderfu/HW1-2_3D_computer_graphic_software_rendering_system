object Form1: TForm1
  Left = 225
  Top = 128
  Width = 1305
  Height = 859
  Caption = '3D_computer_graphic_software_rendering_system'
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
  object draw_area: TImage
    Left = 600
    Top = 30
    Width = 600
    Height = 400
    ParentShowHint = False
    ShowHint = False
  end
  object Draw_button: TBitBtn
    Left = 400
    Top = 700
    Width = 120
    Height = 40
    Caption = 'Draw'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    OnClick = Draw_buttonClick
  end
  object Vertex_group: TGroupBox
    Left = 80
    Top = 30
    Width = 465
    Height = 200
    Caption = 'Vertex'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    object VX_edit: TLabeledEdit
      Left = 24
      Top = 40
      Width = 121
      Height = 21
      EditLabel.Width = 47
      EditLabel.Height = 13
      EditLabel.BiDiMode = bdLeftToRight
      EditLabel.Caption = 'Position X'
      EditLabel.ParentBiDiMode = False
      LabelPosition = lpAbove
      LabelSpacing = 3
      TabOrder = 0
    end
    object VY_edit: TLabeledEdit
      Left = 24
      Top = 80
      Width = 121
      Height = 21
      EditLabel.Width = 47
      EditLabel.Height = 13
      EditLabel.Caption = 'Position Y'
      LabelPosition = lpAbove
      LabelSpacing = 3
      TabOrder = 1
    end
    object VZ_edit: TLabeledEdit
      Left = 24
      Top = 120
      Width = 121
      Height = 21
      EditLabel.Width = 47
      EditLabel.Height = 13
      EditLabel.Caption = 'Position Z'
      LabelPosition = lpAbove
      LabelSpacing = 3
      TabOrder = 2
    end
    object NX_edit: TLabeledEdit
      Left = 168
      Top = 40
      Width = 121
      Height = 21
      EditLabel.Width = 43
      EditLabel.Height = 13
      EditLabel.Caption = 'Normal X'
      LabelPosition = lpAbove
      LabelSpacing = 3
      TabOrder = 3
    end
    object NY_edit: TLabeledEdit
      Left = 168
      Top = 80
      Width = 121
      Height = 21
      EditLabel.Width = 43
      EditLabel.Height = 13
      EditLabel.Caption = 'Normal Y'
      LabelPosition = lpAbove
      LabelSpacing = 3
      TabOrder = 4
    end
    object NZ_edit: TLabeledEdit
      Left = 168
      Top = 120
      Width = 121
      Height = 21
      EditLabel.Width = 43
      EditLabel.Height = 13
      EditLabel.Caption = 'Normal Z'
      LabelPosition = lpAbove
      LabelSpacing = 3
      TabOrder = 5
    end
    object VR_edit: TLabeledEdit
      Left = 312
      Top = 40
      Width = 121
      Height = 21
      EditLabel.Width = 47
      EditLabel.Height = 13
      EditLabel.Caption = 'Red Color'
      LabelPosition = lpAbove
      LabelSpacing = 3
      TabOrder = 6
    end
    object VG_edit: TLabeledEdit
      Left = 312
      Top = 80
      Width = 121
      Height = 21
      EditLabel.Width = 56
      EditLabel.Height = 13
      EditLabel.Caption = 'Green Color'
      LabelPosition = lpAbove
      LabelSpacing = 3
      TabOrder = 7
    end
    object VB_edit: TLabeledEdit
      Left = 312
      Top = 120
      Width = 121
      Height = 21
      EditLabel.Width = 48
      EditLabel.Height = 13
      EditLabel.Caption = 'Blue Color'
      LabelPosition = lpAbove
      LabelSpacing = 3
      TabOrder = 8
    end
    object addV_button: TBitBtn
      Left = 168
      Top = 160
      Width = 121
      Height = 25
      Hint = 'Enter the three vertices of a triangle.'
      Caption = 'Add Vertex'
      ParentShowHint = False
      ShowHint = True
      TabOrder = 9
    end
    object ClearV_edit: TBitBtn
      Left = 312
      Top = 160
      Width = 121
      Height = 25
      Caption = 'Clear'
      TabOrder = 10
    end
  end
  object Light_group: TGroupBox
    Left = 80
    Top = 476
    Width = 465
    Height = 200
    Caption = 'Light'
    TabOrder = 2
    object LX_edit: TLabeledEdit
      Left = 24
      Top = 40
      Width = 121
      Height = 21
      EditLabel.Width = 47
      EditLabel.Height = 13
      EditLabel.Caption = 'Position X'
      LabelPosition = lpAbove
      LabelSpacing = 3
      TabOrder = 0
    end
    object LY_edit: TLabeledEdit
      Left = 24
      Top = 80
      Width = 121
      Height = 21
      EditLabel.Width = 47
      EditLabel.Height = 13
      EditLabel.Caption = 'Position Y'
      LabelPosition = lpAbove
      LabelSpacing = 3
      TabOrder = 1
    end
    object LZ_edit: TLabeledEdit
      Left = 24
      Top = 120
      Width = 121
      Height = 21
      EditLabel.Width = 47
      EditLabel.Height = 13
      EditLabel.Caption = 'Position Z'
      LabelPosition = lpAbove
      LabelSpacing = 3
      TabOrder = 2
    end
    object CR_edit: TLabeledEdit
      Left = 168
      Top = 40
      Width = 121
      Height = 21
      EditLabel.Width = 47
      EditLabel.Height = 13
      EditLabel.Caption = 'Red Color'
      LabelPosition = lpAbove
      LabelSpacing = 3
      TabOrder = 3
    end
    object CG_edit: TLabeledEdit
      Left = 168
      Top = 80
      Width = 121
      Height = 21
      EditLabel.Width = 56
      EditLabel.Height = 13
      EditLabel.Caption = 'Green Color'
      LabelPosition = lpAbove
      LabelSpacing = 3
      TabOrder = 4
    end
    object CB_edit: TLabeledEdit
      Left = 168
      Top = 120
      Width = 121
      Height = 21
      EditLabel.Width = 48
      EditLabel.Height = 13
      EditLabel.Caption = 'Blue Color'
      LabelPosition = lpAbove
      LabelSpacing = 3
      TabOrder = 5
    end
    object addL_button: TBitBtn
      Left = 168
      Top = 160
      Width = 121
      Height = 25
      Caption = 'Add Light'
      Enabled = False
      TabOrder = 6
    end
    object ClearL_edit: TBitBtn
      Left = 312
      Top = 160
      Width = 121
      Height = 25
      Caption = 'Clear'
      TabOrder = 7
    end
  end
  object Camera_group: TGroupBox
    Left = 80
    Top = 250
    Width = 465
    Height = 200
    Caption = 'Camera'
    TabOrder = 1
    object CX_edit: TLabeledEdit
      Left = 24
      Top = 40
      Width = 121
      Height = 21
      EditLabel.Width = 47
      EditLabel.Height = 13
      EditLabel.Caption = 'Position X'
      LabelPosition = lpAbove
      LabelSpacing = 3
      TabOrder = 0
    end
    object CY_edit: TLabeledEdit
      Left = 24
      Top = 80
      Width = 121
      Height = 21
      EditLabel.Width = 47
      EditLabel.Height = 13
      EditLabel.Caption = 'Position Y'
      LabelPosition = lpAbove
      LabelSpacing = 3
      TabOrder = 1
    end
    object CZ_edit: TLabeledEdit
      Left = 24
      Top = 120
      Width = 121
      Height = 21
      EditLabel.Width = 47
      EditLabel.Height = 13
      EditLabel.Caption = 'Position Z'
      LabelPosition = lpAbove
      LabelSpacing = 3
      TabOrder = 2
    end
    object PX_edit: TLabeledEdit
      Left = 168
      Top = 40
      Width = 121
      Height = 21
      EditLabel.Width = 66
      EditLabel.Height = 13
      EditLabel.Caption = 'Perspective X'
      LabelPosition = lpAbove
      LabelSpacing = 3
      TabOrder = 4
    end
    object PY_edit: TLabeledEdit
      Left = 168
      Top = 80
      Width = 121
      Height = 21
      EditLabel.Width = 66
      EditLabel.Height = 13
      EditLabel.Caption = 'Perspective Y'
      LabelPosition = lpAbove
      LabelSpacing = 3
      TabOrder = 5
    end
    object PZ_edit: TLabeledEdit
      Left = 168
      Top = 120
      Width = 121
      Height = 21
      EditLabel.Width = 66
      EditLabel.Height = 13
      EditLabel.Caption = 'Perspective Z'
      LabelPosition = lpAbove
      LabelSpacing = 3
      TabOrder = 6
    end
    object TX_edit: TLabeledEdit
      Left = 312
      Top = 40
      Width = 121
      Height = 21
      EditLabel.Width = 29
      EditLabel.Height = 13
      EditLabel.Caption = 'Top X'
      LabelPosition = lpAbove
      LabelSpacing = 3
      TabOrder = 7
    end
    object TY_edit: TLabeledEdit
      Left = 312
      Top = 80
      Width = 121
      Height = 21
      EditLabel.Width = 29
      EditLabel.Height = 13
      EditLabel.Caption = 'Top Y'
      LabelPosition = lpAbove
      LabelSpacing = 3
      TabOrder = 8
    end
    object TZ_edit: TLabeledEdit
      Left = 312
      Top = 120
      Width = 121
      Height = 21
      EditLabel.Width = 29
      EditLabel.Height = 13
      EditLabel.Caption = 'Top Z'
      LabelPosition = lpAbove
      LabelSpacing = 3
      TabOrder = 9
    end
    object WD_edit: TLabeledEdit
      Left = 24
      Top = 160
      Width = 121
      Height = 21
      EditLabel.Width = 82
      EditLabel.Height = 13
      EditLabel.Caption = 'Window distance'
      LabelPosition = lpAbove
      LabelSpacing = 3
      TabOrder = 3
    end
    object ClearC_edit: TBitBtn
      Left = 312
      Top = 160
      Width = 121
      Height = 25
      Caption = 'Clear'
      TabOrder = 10
    end
  end
  object Input_memo: TMemo
    Left = 600
    Top = 450
    Width = 600
    Height = 300
    TabOrder = 5
  end
  object Reset_button: TBitBtn
    Left = 250
    Top = 700
    Width = 120
    Height = 40
    Caption = 'Reset'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
    OnClick = Reset_buttonClick
  end
  object MainMenu1: TMainMenu
    object F1: TMenuItem
      Caption = 'FILE'
      object Open1: TMenuItem
        Caption = 'Open'
        ShortCut = 16463
        OnClick = Open1Click
      end
    end
  end
  object OpenDialog1: TOpenDialog
    Filter = '.txt|*.txt'
    Left = 32
  end
end
