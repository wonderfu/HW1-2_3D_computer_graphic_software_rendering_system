object Form1: TForm1
  Left = 220
  Top = 120
  Width = 1305
  Height = 860
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
  object Bevel1: TBevel
    Left = 600
    Top = 30
    Width = 600
    Height = 400
  end
  object Draw_button: TBitBtn
    Left = 384
    Top = 704
    Width = 121
    Height = 36
    Caption = 'Draw'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    OnClick = Draw_buttonClick
  end
  object Input_memo: TMemo
    Left = 600
    Top = 450
    Width = 600
    Height = 300
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
  end
  object Reset_button: TBitBtn
    Left = 240
    Top = 704
    Width = 121
    Height = 36
    Caption = 'Reset'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    OnClick = Reset_buttonClick
  end
  object PageControl1: TPageControl
    Left = 50
    Top = 40
    Width = 500
    Height = 600
    ActivePage = TabSheet1
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabIndex = 0
    TabOrder = 0
    object TabSheet1: TTabSheet
      Caption = 'Vertex'
      object addV_button: TBitBtn
        Left = 184
        Top = 520
        Width = 121
        Height = 25
        Hint = 'Enter the three vertices of a triangle.'
        Caption = 'Add Vertex'
        ParentShowHint = False
        ShowHint = True
        TabOrder = 3
      end
      object ClearV_edit: TBitBtn
        Left = 328
        Top = 520
        Width = 121
        Height = 25
        Caption = 'Clear'
        TabOrder = 4
      end
      object GroupBox1: TGroupBox
        Left = 16
        Top = 24
        Width = 457
        Height = 81
        Caption = 'Position'
        TabOrder = 0
        object VY_Edit: TLabeledEdit
          Left = 168
          Top = 41
          Width = 121
          Height = 24
          EditLabel.Width = 9
          EditLabel.Height = 16
          EditLabel.Caption = 'Y'
          LabelPosition = lpAbove
          LabelSpacing = 3
          TabOrder = 1
        end
        object VZ_Edit: TLabeledEdit
          Left = 312
          Top = 41
          Width = 121
          Height = 24
          EditLabel.Width = 8
          EditLabel.Height = 16
          EditLabel.Caption = 'Z'
          LabelPosition = lpAbove
          LabelSpacing = 3
          TabOrder = 2
        end
        object VX_Edit: TLabeledEdit
          Left = 24
          Top = 41
          Width = 121
          Height = 24
          EditLabel.Width = 8
          EditLabel.Height = 16
          EditLabel.BiDiMode = bdLeftToRight
          EditLabel.Caption = 'X'
          EditLabel.ParentBiDiMode = False
          LabelPosition = lpAbove
          LabelSpacing = 3
          TabOrder = 0
        end
      end
      object GroupBox2: TGroupBox
        Left = 16
        Top = 128
        Width = 457
        Height = 81
        Caption = 'Normal'
        TabOrder = 1
        object NY_Edit: TLabeledEdit
          Left = 168
          Top = 41
          Width = 121
          Height = 24
          EditLabel.Width = 9
          EditLabel.Height = 16
          EditLabel.Caption = 'Y'
          LabelPosition = lpAbove
          LabelSpacing = 3
          TabOrder = 1
        end
        object NX_Edit: TLabeledEdit
          Left = 24
          Top = 41
          Width = 121
          Height = 24
          EditLabel.Width = 8
          EditLabel.Height = 16
          EditLabel.Caption = 'X'
          LabelPosition = lpAbove
          LabelSpacing = 3
          TabOrder = 0
        end
        object NZ_Edit: TLabeledEdit
          Left = 312
          Top = 41
          Width = 121
          Height = 24
          EditLabel.Width = 8
          EditLabel.Height = 16
          EditLabel.Caption = 'Z'
          LabelPosition = lpAbove
          LabelSpacing = 3
          TabOrder = 2
        end
      end
      object GroupBox3: TGroupBox
        Left = 16
        Top = 232
        Width = 457
        Height = 193
        Caption = 'Property'
        TabOrder = 2
        object KAG_Edit: TLabeledEdit
          Left = 168
          Top = 41
          Width = 121
          Height = 24
          EditLabel.Width = 89
          EditLabel.Height = 16
          EditLabel.Caption = 'Ambient Green'
          LabelPosition = lpAbove
          LabelSpacing = 3
          TabOrder = 1
        end
        object KAR_Edit: TLabeledEdit
          Left = 24
          Top = 41
          Width = 121
          Height = 24
          EditLabel.Width = 78
          EditLabel.Height = 16
          EditLabel.Caption = 'Ambient Red'
          LabelPosition = lpAbove
          LabelSpacing = 3
          TabOrder = 0
        end
        object KAB_Edit: TLabeledEdit
          Left = 312
          Top = 41
          Width = 121
          Height = 24
          EditLabel.Width = 79
          EditLabel.Height = 16
          EditLabel.Caption = 'Ambient Blue'
          LabelPosition = lpAbove
          LabelSpacing = 3
          TabOrder = 2
        end
        object KDG_Edit: TLabeledEdit
          Left = 168
          Top = 97
          Width = 121
          Height = 24
          EditLabel.Width = 81
          EditLabel.Height = 16
          EditLabel.Caption = 'Diffuse Green'
          LabelPosition = lpAbove
          LabelSpacing = 3
          TabOrder = 4
        end
        object KDB_Edit: TLabeledEdit
          Left = 312
          Top = 97
          Width = 121
          Height = 24
          EditLabel.Width = 71
          EditLabel.Height = 16
          EditLabel.Caption = 'Diffuse Blue'
          LabelPosition = lpAbove
          LabelSpacing = 3
          TabOrder = 5
        end
        object KDR_Edit: TLabeledEdit
          Left = 24
          Top = 97
          Width = 121
          Height = 24
          EditLabel.Width = 70
          EditLabel.Height = 16
          EditLabel.Caption = 'Diffuse Red'
          LabelPosition = lpAbove
          LabelSpacing = 3
          TabOrder = 3
        end
        object KSB_Edit: TLabeledEdit
          Left = 312
          Top = 153
          Width = 121
          Height = 24
          EditLabel.Width = 84
          EditLabel.Height = 16
          EditLabel.Caption = 'Specular Blue'
          LabelPosition = lpAbove
          LabelSpacing = 3
          TabOrder = 8
        end
        object KSG_Edit: TLabeledEdit
          Left = 168
          Top = 153
          Width = 121
          Height = 24
          EditLabel.Width = 94
          EditLabel.Height = 16
          EditLabel.Caption = 'Specular Green'
          LabelPosition = lpAbove
          LabelSpacing = 3
          TabOrder = 7
        end
        object KSR_Edit: TLabeledEdit
          Left = 24
          Top = 153
          Width = 121
          Height = 24
          EditLabel.Width = 83
          EditLabel.Height = 16
          EditLabel.Caption = 'Specular Red'
          LabelPosition = lpAbove
          LabelSpacing = 3
          TabOrder = 6
        end
      end
      object StaticText1: TStaticText
        Left = 40
        Top = 448
        Width = 350
        Height = 20
        Caption = 'In this page you must enter the three vertices of the triangle.'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clRed
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 5
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'Light'
      ImageIndex = 1
      object GroupBox4: TGroupBox
        Left = 16
        Top = 24
        Width = 457
        Height = 81
        Caption = 'Ambient Light'
        TabOrder = 0
        object Edit1: TEdit
          Left = 24
          Top = 40
          Width = 121
          Height = 24
          TabOrder = 0
        end
        object BitBtn1: TBitBtn
          Left = 168
          Top = 40
          Width = 121
          Height = 25
          Caption = 'Set'
          TabOrder = 1
        end
      end
      object GroupBox5: TGroupBox
        Left = 16
        Top = 128
        Width = 457
        Height = 345
        Caption = 'Light Source'
        TabOrder = 1
        object GroupBox6: TGroupBox
          Left = 8
          Top = 40
          Width = 441
          Height = 81
          Caption = 'Position'
          TabOrder = 0
          object LX_edit: TLabeledEdit
            Left = 16
            Top = 41
            Width = 121
            Height = 24
            EditLabel.Width = 8
            EditLabel.Height = 16
            EditLabel.Caption = 'X'
            LabelPosition = lpAbove
            LabelSpacing = 3
            TabOrder = 0
          end
          object LY_edit: TLabeledEdit
            Left = 160
            Top = 41
            Width = 121
            Height = 24
            EditLabel.Width = 9
            EditLabel.Height = 16
            EditLabel.Caption = 'Y'
            LabelPosition = lpAbove
            LabelSpacing = 3
            TabOrder = 1
          end
          object LZ_edit: TLabeledEdit
            Left = 304
            Top = 41
            Width = 121
            Height = 24
            EditLabel.Width = 8
            EditLabel.Height = 16
            EditLabel.Caption = 'Z'
            LabelPosition = lpAbove
            LabelSpacing = 3
            TabOrder = 2
          end
        end
        object GroupBox7: TGroupBox
          Left = 8
          Top = 136
          Width = 441
          Height = 81
          Caption = 'Color'
          TabOrder = 1
          object CG_edit: TLabeledEdit
            Left = 160
            Top = 41
            Width = 121
            Height = 24
            EditLabel.Width = 37
            EditLabel.Height = 16
            EditLabel.Caption = 'Green'
            LabelPosition = lpAbove
            LabelSpacing = 3
            TabOrder = 1
          end
          object CB_edit: TLabeledEdit
            Left = 304
            Top = 41
            Width = 121
            Height = 24
            EditLabel.Width = 27
            EditLabel.Height = 16
            EditLabel.Caption = 'Blue'
            LabelPosition = lpAbove
            LabelSpacing = 3
            TabOrder = 2
          end
          object CR_edit: TLabeledEdit
            Left = 16
            Top = 41
            Width = 121
            Height = 24
            EditLabel.Width = 26
            EditLabel.Height = 16
            EditLabel.Caption = 'Red'
            LabelPosition = lpAbove
            LabelSpacing = 3
            TabOrder = 0
          end
        end
        object ClearL_edit: TBitBtn
          Left = 312
          Top = 296
          Width = 121
          Height = 25
          Caption = 'Clear'
          TabOrder = 3
        end
        object addL_button: TBitBtn
          Left = 168
          Top = 296
          Width = 121
          Height = 25
          Caption = 'Add Light'
          TabOrder = 2
        end
      end
    end
    object TabSheet3: TTabSheet
      Caption = 'Camera'
      ImageIndex = 2
      object ClearC_edit: TBitBtn
        Left = 328
        Top = 520
        Width = 121
        Height = 25
        Caption = 'Clear'
        TabOrder = 5
      end
      object WD_edit: TLabeledEdit
        Left = 40
        Top = 352
        Width = 121
        Height = 24
        EditLabel.Width = 102
        EditLabel.Height = 16
        EditLabel.Caption = 'Window distance'
        LabelPosition = lpAbove
        LabelSpacing = 3
        TabOrder = 3
      end
      object GroupBox8: TGroupBox
        Left = 16
        Top = 24
        Width = 457
        Height = 81
        Caption = 'Position'
        TabOrder = 0
        object CY_edit: TLabeledEdit
          Left = 168
          Top = 41
          Width = 121
          Height = 24
          EditLabel.Width = 60
          EditLabel.Height = 16
          EditLabel.Caption = 'Position Y'
          LabelPosition = lpAbove
          LabelSpacing = 3
          TabOrder = 1
        end
        object CX_edit: TLabeledEdit
          Left = 24
          Top = 41
          Width = 121
          Height = 24
          EditLabel.Width = 59
          EditLabel.Height = 16
          EditLabel.Caption = 'Position X'
          LabelPosition = lpAbove
          LabelSpacing = 3
          TabOrder = 0
        end
        object CZ_edit: TLabeledEdit
          Left = 312
          Top = 41
          Width = 121
          Height = 24
          EditLabel.Width = 59
          EditLabel.Height = 16
          EditLabel.Caption = 'Position Z'
          LabelPosition = lpAbove
          LabelSpacing = 3
          TabOrder = 2
        end
      end
      object GroupBox9: TGroupBox
        Left = 16
        Top = 128
        Width = 457
        Height = 81
        Caption = 'Direction'
        TabOrder = 1
        object PY_edit: TLabeledEdit
          Left = 168
          Top = 41
          Width = 121
          Height = 24
          EditLabel.Width = 9
          EditLabel.Height = 16
          EditLabel.Caption = 'Y'
          LabelPosition = lpAbove
          LabelSpacing = 3
          TabOrder = 1
        end
        object PZ_edit: TLabeledEdit
          Left = 312
          Top = 41
          Width = 121
          Height = 24
          EditLabel.Width = 8
          EditLabel.Height = 16
          EditLabel.Caption = 'Z'
          LabelPosition = lpAbove
          LabelSpacing = 3
          TabOrder = 2
        end
        object PX_edit: TLabeledEdit
          Left = 24
          Top = 41
          Width = 121
          Height = 24
          EditLabel.Width = 8
          EditLabel.Height = 16
          EditLabel.Caption = 'X'
          LabelPosition = lpAbove
          LabelSpacing = 3
          TabOrder = 0
        end
      end
      object GroupBox10: TGroupBox
        Left = 16
        Top = 232
        Width = 457
        Height = 81
        Caption = 'Top'
        TabOrder = 2
        object TY_edit: TLabeledEdit
          Left = 168
          Top = 41
          Width = 121
          Height = 24
          EditLabel.Width = 9
          EditLabel.Height = 16
          EditLabel.Caption = 'Y'
          LabelPosition = lpAbove
          LabelSpacing = 3
          TabOrder = 1
        end
        object TX_edit: TLabeledEdit
          Left = 24
          Top = 41
          Width = 121
          Height = 24
          EditLabel.Width = 8
          EditLabel.Height = 16
          EditLabel.Caption = 'X'
          LabelPosition = lpAbove
          LabelSpacing = 3
          TabOrder = 0
        end
        object TZ_edit: TLabeledEdit
          Left = 312
          Top = 41
          Width = 121
          Height = 24
          EditLabel.Width = 8
          EditLabel.Height = 16
          EditLabel.Caption = 'Z'
          LabelPosition = lpAbove
          LabelSpacing = 3
          TabOrder = 2
        end
      end
      object BitBtn2: TBitBtn
        Left = 184
        Top = 520
        Width = 121
        Height = 25
        Caption = 'Set'
        TabOrder = 4
      end
    end
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
