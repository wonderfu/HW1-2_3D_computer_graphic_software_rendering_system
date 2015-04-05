object Form1: TForm1
  Left = 200
  Top = 150
  Width = 1300
  Height = 850
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
  object Draw_Area: TImage
    Left = 656
    Top = 30
    Width = 600
    Height = 400
    ParentShowHint = False
    ShowHint = False
  end
  object Bevel1: TBevel
    Left = 656
    Top = 30
    Width = 600
    Height = 400
  end
  object Draw_Button: TBitBtn
    Left = 496
    Top = 712
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
    OnClick = Draw_ButtonClick
  end
  object Msg_Memo: TMemo
    Left = 656
    Top = 450
    Width = 600
    Height = 300
    TabStop = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    ReadOnly = True
    ScrollBars = ssBoth
    TabOrder = 3
  end
  object Reset_Button: TBitBtn
    Left = 352
    Top = 712
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
    OnClick = Reset_ButtonClick
  end
  object PageControl1: TPageControl
    Left = 18
    Top = 32
    Width = 615
    Height = 657
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
      object ClearV_Button: TBitBtn
        Left = 448
        Top = 584
        Width = 121
        Height = 25
        Caption = 'Clear'
        TabOrder = 3
        OnClick = ClearV_ButtonClick
      end
      object VPos_GroupBox: TGroupBox
        Left = 16
        Top = 8
        Width = 577
        Height = 81
        Caption = 'Position'
        TabOrder = 0
        object VY_Edit: TLabeledEdit
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
        object VZ_Edit: TLabeledEdit
          Left = 296
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
        object AddVP_Button: TBitBtn
          Left = 432
          Top = 40
          Width = 121
          Height = 25
          Hint = 'Enter the three vertices of a triangle.'
          Caption = 'Add'
          ParentShowHint = False
          ShowHint = True
          TabOrder = 3
          OnClick = AddVP_ButtonClick
        end
      end
      object VN_GroupBox: TGroupBox
        Left = 16
        Top = 96
        Width = 577
        Height = 81
        Caption = 'Normal'
        TabOrder = 1
        object NY_Edit: TLabeledEdit
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
          Left = 296
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
        object AddVN_Button: TBitBtn
          Left = 432
          Top = 40
          Width = 121
          Height = 25
          Hint = 'Enter the three vertices of a triangle.'
          Caption = 'Add'
          ParentShowHint = False
          ShowHint = True
          TabOrder = 3
          OnClick = AddVN_ButtonClick
        end
      end
      object VPro_GroupBox: TGroupBox
        Left = 16
        Top = 184
        Width = 577
        Height = 385
        Caption = 'Property'
        TabOrder = 2
        object VT_GroupBox: TGroupBox
          Left = 8
          Top = 24
          Width = 561
          Height = 81
          Caption = 'Texture'
          TabOrder = 0
          object TU_Edit: TLabeledEdit
            Left = 16
            Top = 41
            Width = 121
            Height = 24
            EditLabel.Width = 10
            EditLabel.Height = 16
            EditLabel.Caption = 'U'
            LabelPosition = lpAbove
            LabelSpacing = 3
            TabOrder = 0
          end
          object TV_Edit: TLabeledEdit
            Left = 152
            Top = 41
            Width = 121
            Height = 24
            EditLabel.Width = 9
            EditLabel.Height = 16
            EditLabel.Caption = 'V'
            LabelPosition = lpAbove
            LabelSpacing = 3
            TabOrder = 1
          end
          object AddVT_Button: TBitBtn
            Left = 424
            Top = 40
            Width = 121
            Height = 25
            Hint = 'Enter the three vertices of a triangle.'
            Caption = 'Add'
            ParentShowHint = False
            ShowHint = True
            TabOrder = 2
            OnClick = AddVT_ButtonClick
          end
        end
        object VPA_GroupBox: TGroupBox
          Left = 8
          Top = 112
          Width = 561
          Height = 81
          Caption = 'Ambient'
          TabOrder = 1
          object KAR_Edit: TLabeledEdit
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
          object KAG_Edit: TLabeledEdit
            Left = 152
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
          object KAB_Edit: TLabeledEdit
            Left = 288
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
          object AddKA_Button: TBitBtn
            Left = 424
            Top = 40
            Width = 121
            Height = 25
            Hint = 'Enter the three vertices of a triangle.'
            Caption = 'Add'
            ParentShowHint = False
            ShowHint = True
            TabOrder = 3
          end
        end
        object VPD_GroupBox: TGroupBox
          Left = 8
          Top = 200
          Width = 561
          Height = 81
          Caption = 'Diffuse'
          TabOrder = 2
          object KDR_Edit: TLabeledEdit
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
          object KDG_Edit: TLabeledEdit
            Left = 152
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
          object KDB_Edit: TLabeledEdit
            Left = 288
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
          object AddKD_Button: TBitBtn
            Left = 424
            Top = 40
            Width = 121
            Height = 25
            Hint = 'Enter the three vertices of a triangle.'
            Caption = 'Add'
            ParentShowHint = False
            ShowHint = True
            TabOrder = 3
          end
        end
        object VPS_GroupBox: TGroupBox
          Left = 8
          Top = 288
          Width = 561
          Height = 81
          Caption = 'Specular'
          TabOrder = 3
          object KSR_Edit: TLabeledEdit
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
          object KSG_Edit: TLabeledEdit
            Left = 152
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
          object KSB_Edit: TLabeledEdit
            Left = 288
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
          object AddKS_Button: TBitBtn
            Left = 424
            Top = 40
            Width = 121
            Height = 25
            Hint = 'Enter the three vertices of a triangle.'
            Caption = 'Add'
            ParentShowHint = False
            ShowHint = True
            TabOrder = 3
          end
        end
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'Light'
      ImageIndex = 1
      object LA_GroupBox: TGroupBox
        Left = 16
        Top = 8
        Width = 577
        Height = 81
        Caption = 'Ambient Light'
        TabOrder = 0
        object LA_Edit: TEdit
          Left = 24
          Top = 40
          Width = 121
          Height = 24
          TabOrder = 0
        end
        object SetLA_Button: TBitBtn
          Left = 432
          Top = 40
          Width = 121
          Height = 25
          Caption = 'Set'
          TabOrder = 1
          OnClick = SetLA_ButtonClick
        end
      end
      object LS_GroupBox: TGroupBox
        Left = 16
        Top = 104
        Width = 577
        Height = 225
        Caption = 'Light Source'
        TabOrder = 1
        object LSP_GroupBox: TGroupBox
          Left = 8
          Top = 32
          Width = 561
          Height = 81
          Caption = 'Position'
          TabOrder = 0
          object LX_Edit: TLabeledEdit
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
          object LY_Edit: TLabeledEdit
            Left = 152
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
          object LZ_Edit: TLabeledEdit
            Left = 288
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
          object AddLP_Button: TBitBtn
            Left = 424
            Top = 40
            Width = 121
            Height = 25
            Hint = 'Enter the three vertices of a triangle.'
            Caption = 'Add'
            ParentShowHint = False
            ShowHint = True
            TabOrder = 3
            OnClick = AddLP_ButtonClick
          end
        end
        object LSC_GroupBox: TGroupBox
          Left = 8
          Top = 128
          Width = 561
          Height = 81
          Caption = 'Color'
          TabOrder = 1
          object CG_Edit: TLabeledEdit
            Left = 152
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
          object CB_Edit: TLabeledEdit
            Left = 288
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
          object CR_Edit: TLabeledEdit
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
          object AddLC_Button: TBitBtn
            Left = 424
            Top = 40
            Width = 121
            Height = 25
            Hint = 'Enter the three vertices of a triangle.'
            Caption = 'Add'
            ParentShowHint = False
            ShowHint = True
            TabOrder = 3
            OnClick = AddLC_ButtonClick
          end
        end
      end
      object ClearL_Button: TBitBtn
        Left = 448
        Top = 584
        Width = 121
        Height = 25
        Caption = 'Clear'
        TabOrder = 3
        OnClick = ClearL_ButtonClick
      end
      object Lit_GroupBox: TGroupBox
        Left = 16
        Top = 344
        Width = 577
        Height = 89
        Caption = 'Lit'
        TabOrder = 2
        object LitP_ComboBox: TComboBox
          Left = 24
          Top = 49
          Width = 145
          Height = 24
          ItemHeight = 16
          TabOrder = 0
        end
        object AddLP_StaticText: TStaticText
          Left = 24
          Top = 21
          Width = 52
          Height = 20
          Caption = 'Position'
          TabOrder = 1
        end
        object LitC_ComboBox: TComboBox
          Left = 184
          Top = 49
          Width = 145
          Height = 24
          ItemHeight = 16
          TabOrder = 2
        end
        object AddLC_StaticText: TStaticText
          Left = 184
          Top = 21
          Width = 36
          Height = 20
          Caption = 'Color'
          TabOrder = 3
        end
        object AddL_Button: TBitBtn
          Left = 432
          Top = 48
          Width = 121
          Height = 25
          Caption = 'Add'
          TabOrder = 4
        end
      end
    end
    object TabSheet3: TTabSheet
      Caption = 'Camera'
      ImageIndex = 2
      object ClearC_Button: TBitBtn
        Left = 448
        Top = 584
        Width = 121
        Height = 25
        Caption = 'Clear'
        TabOrder = 5
        OnClick = ClearC_ButtonClick
      end
      object WD_Edit: TLabeledEdit
        Left = 40
        Top = 320
        Width = 121
        Height = 24
        EditLabel.Width = 104
        EditLabel.Height = 16
        EditLabel.Caption = 'Window Distance'
        LabelPosition = lpAbove
        LabelSpacing = 3
        TabOrder = 3
      end
      object CP_GroupBox: TGroupBox
        Left = 16
        Top = 8
        Width = 577
        Height = 81
        Caption = 'Position'
        TabOrder = 0
        object CY_Edit: TLabeledEdit
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
        object CX_Edit: TLabeledEdit
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
        object CZ_Edit: TLabeledEdit
          Left = 296
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
      object CD_GroupBox: TGroupBox
        Left = 16
        Top = 104
        Width = 577
        Height = 81
        Caption = 'Direction'
        TabOrder = 1
        object DY_Edit: TLabeledEdit
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
        object DZ_Edit: TLabeledEdit
          Left = 296
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
        object DX_Edit: TLabeledEdit
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
      object CT_GroupBox: TGroupBox
        Left = 16
        Top = 200
        Width = 577
        Height = 81
        Caption = 'Top'
        TabOrder = 2
        object TY_Edit: TLabeledEdit
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
        object TX_Edit: TLabeledEdit
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
        object TZ_Edit: TLabeledEdit
          Left = 296
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
      object SetC_Button: TBitBtn
        Left = 304
        Top = 584
        Width = 121
        Height = 25
        Caption = 'Set'
        TabOrder = 4
        OnClick = SetC_ButtonClick
      end
    end
    object TabSheet4: TTabSheet
      Caption = 'Triangle'
      ImageIndex = 3
      object AddT_Button: TBitBtn
        Left = 448
        Top = 584
        Width = 121
        Height = 25
        Hint = 'Enter the three vertices of a triangle.'
        Caption = 'Add'
        ParentShowHint = False
        ShowHint = True
        TabOrder = 3
      end
      object V1_GroupBox: TGroupBox
        Left = 16
        Top = 8
        Width = 577
        Height = 89
        Caption = 'Vertex 1'
        TabOrder = 0
        object V1P_ComboBox: TComboBox
          Left = 24
          Top = 49
          Width = 145
          Height = 24
          ItemHeight = 16
          TabOrder = 0
        end
        object V1N_ComboBox: TComboBox
          Left = 184
          Top = 49
          Width = 145
          Height = 24
          ItemHeight = 16
          TabOrder = 2
        end
        object V1T_ComboBox: TComboBox
          Left = 344
          Top = 49
          Width = 145
          Height = 24
          ItemHeight = 16
          TabOrder = 4
        end
        object V1P_StaticText: TStaticText
          Left = 24
          Top = 24
          Width = 52
          Height = 20
          Caption = 'Position'
          TabOrder = 1
        end
        object V1N_StaticText: TStaticText
          Left = 184
          Top = 24
          Width = 48
          Height = 20
          Caption = 'Normal'
          TabOrder = 3
        end
        object V1T_StaticText: TStaticText
          Left = 344
          Top = 24
          Width = 49
          Height = 20
          Caption = 'Texture'
          TabOrder = 5
        end
      end
      object V2_GroupBox: TGroupBox
        Left = 16
        Top = 112
        Width = 577
        Height = 89
        Caption = 'Vertex 2'
        TabOrder = 1
        object V2P_ComboBox: TComboBox
          Left = 24
          Top = 49
          Width = 145
          Height = 24
          ItemHeight = 16
          TabOrder = 0
        end
        object V2N_ComboBox: TComboBox
          Left = 184
          Top = 49
          Width = 145
          Height = 24
          ItemHeight = 16
          TabOrder = 2
        end
        object V2T_ComboBox: TComboBox
          Left = 344
          Top = 49
          Width = 145
          Height = 24
          ItemHeight = 16
          TabOrder = 4
        end
        object V2P_StaticText: TStaticText
          Left = 24
          Top = 24
          Width = 52
          Height = 20
          Caption = 'Position'
          TabOrder = 1
        end
        object V2N_StaticText: TStaticText
          Left = 184
          Top = 24
          Width = 48
          Height = 20
          Caption = 'Normal'
          TabOrder = 3
        end
        object V2T_StaticText: TStaticText
          Left = 344
          Top = 24
          Width = 49
          Height = 20
          Caption = 'Texture'
          TabOrder = 5
        end
      end
      object V3_GroupBox: TGroupBox
        Left = 14
        Top = 216
        Width = 577
        Height = 89
        Caption = 'Vertex 3'
        TabOrder = 2
        object V3P_ComboBox: TComboBox
          Left = 24
          Top = 49
          Width = 145
          Height = 24
          ItemHeight = 16
          TabOrder = 0
        end
        object V3N_ComboBox: TComboBox
          Left = 184
          Top = 49
          Width = 145
          Height = 24
          ItemHeight = 16
          TabOrder = 2
        end
        object V3T_ComboBox: TComboBox
          Left = 344
          Top = 49
          Width = 145
          Height = 24
          ItemHeight = 16
          TabOrder = 4
        end
        object V3P_StaticText: TStaticText
          Left = 24
          Top = 24
          Width = 52
          Height = 20
          Caption = 'Position'
          TabOrder = 1
        end
        object V3N_StaticText: TStaticText
          Left = 184
          Top = 24
          Width = 48
          Height = 20
          Caption = 'Normal'
          TabOrder = 3
        end
        object V3T_StaticText: TStaticText
          Left = 344
          Top = 24
          Width = 49
          Height = 20
          Caption = 'Texture'
          TabOrder = 5
        end
      end
    end
  end
  object Err_Text: TStaticText
    Left = 18
    Top = 712
    Width = 4
    Height = 4
    Color = clBtnFace
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentColor = False
    ParentFont = False
    TabOrder = 4
  end
  object MainMenu1: TMainMenu
    object F1: TMenuItem
      Caption = 'FILE'
      object OpenInput: TMenuItem
        Caption = 'Open'
        ShortCut = 16463
        OnClick = OpenInputClick
      end
      object OpenTexture: TMenuItem
        Caption = 'Texture'
        ShortCut = 16468
      end
    end
  end
  object OpenDialog1: TOpenDialog
    Filter = '.txt|*.txt|.obj|*.obj'
    Left = 32
  end
  object OpenPictureDialog1: TOpenPictureDialog
    Left = 64
  end
end
