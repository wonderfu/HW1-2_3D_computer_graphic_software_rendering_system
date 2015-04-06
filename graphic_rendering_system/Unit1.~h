//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
#include <Buttons.hpp>
#include <Classes.hpp>
#include <ComCtrls.hpp>
#include <Controls.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <StdCtrls.hpp>
#include <Grids.hpp>
#include <ValEdit.hpp>
#include <ExtDlgs.hpp>


// user include & define
#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <vector>

#define EPS 1e-8
#define WindowH 600
#define WindowW 800
#define StrSize 64
#define BLACK (TColor)0x000000
#define WHITE (TColor)0xffffff
#define RED (TColor)0xff0000
#define GREEN (TColor)0x00ff00
#define BLUE (TColor)0x0000ff

using namespace std;
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TMainMenu *MainMenu1;
        TMenuItem *OpenInput;
        TMenuItem *F1;
        TOpenDialog *OpenDialog1;
        TBevel *Bevel1;
        TMemo *Msg_Memo;
        TImage *Draw_Area;
        TBitBtn *Reset_Button;
        TBitBtn *Draw_Button;
        TPageControl *PageControl1;
        TTabSheet *TabSheet1;
        TGroupBox *VPos_GroupBox;
        TLabeledEdit *VX_Edit;
        TLabeledEdit *VY_Edit;
        TLabeledEdit *VZ_Edit;
        TGroupBox *VN_GroupBox;
        TLabeledEdit *NX_Edit;
        TLabeledEdit *NY_Edit;
        TLabeledEdit *NZ_Edit;
        TGroupBox *VPro_GroupBox;
        TBitBtn *ClearV_Button;
        TTabSheet *TabSheet2;
        TGroupBox *LA_GroupBox;
        TEdit *LA_Edit;
        TBitBtn *SetLA_Button;
        TGroupBox *LS_GroupBox;
        TGroupBox *LSP_GroupBox;
        TLabeledEdit *LX_Edit;
        TLabeledEdit *LY_Edit;
        TLabeledEdit *LZ_Edit;
        TGroupBox *LSC_GroupBox;
        TLabeledEdit *CR_Edit;
        TLabeledEdit *CG_Edit;
        TLabeledEdit *CB_Edit;
        TTabSheet *TabSheet3;
        TGroupBox *CP_GroupBox;
        TLabeledEdit *CX_Edit;
        TLabeledEdit *CY_Edit;
        TLabeledEdit *CZ_Edit;
        TGroupBox *CD_GroupBox;
        TLabeledEdit *DX_Edit;
        TLabeledEdit *DY_Edit;
        TLabeledEdit *DZ_Edit;
        TGroupBox *CT_GroupBox;
        TLabeledEdit *TX_Edit;
        TLabeledEdit *TY_Edit;
        TLabeledEdit *TZ_Edit;
        TLabeledEdit *WD_Edit;
        TBitBtn *ClearC_Button;
        TBitBtn *SetC_Button;
        TTabSheet *TabSheet4;
        TGroupBox *VT_GroupBox;
        TLabeledEdit *TU_Edit;
        TLabeledEdit *TV_Edit;
        TBitBtn *AddVP_Button;
        TBitBtn *AddVN_Button;
        TBitBtn *AddVT_Button;
        TGroupBox *VPA_GroupBox;
        TLabeledEdit *KAR_Edit;
        TLabeledEdit *KAG_Edit;
        TLabeledEdit *KAB_Edit;
        TGroupBox *VPD_GroupBox;
        TLabeledEdit *KDR_Edit;
        TLabeledEdit *KDG_Edit;
        TLabeledEdit *KDB_Edit;
        TGroupBox *VPS_GroupBox;
        TLabeledEdit *KSR_Edit;
        TLabeledEdit *KSG_Edit;
        TLabeledEdit *KSB_Edit;
        TBitBtn *AddKA_Button;
        TBitBtn *AddKD_Button;
        TBitBtn *AddKS_Button;
        TBitBtn *AddLP_Button;
        TBitBtn *AddLC_Button;
        TBitBtn *AddT_Button;
        TGroupBox *V1_GroupBox;
        TComboBox *V1P_ComboBox;
        TComboBox *V1N_ComboBox;
        TComboBox *V1T_ComboBox;
        TGroupBox *V2_GroupBox;
        TComboBox *V2P_ComboBox;
        TComboBox *V2N_ComboBox;
        TComboBox *V2T_ComboBox;
        TGroupBox *V3_GroupBox;
        TComboBox *V3P_ComboBox;
        TComboBox *V3N_ComboBox;
        TComboBox *V3T_ComboBox;
        TStaticText *V1P_StaticText;
        TStaticText *V1N_StaticText;
        TStaticText *V2P_StaticText;
        TStaticText *V3P_StaticText;
        TStaticText *V1T_StaticText;
        TStaticText *V2N_StaticText;
        TStaticText *V3N_StaticText;
        TStaticText *V2T_StaticText;
        TStaticText *V3T_StaticText;
        TBitBtn *ClearL_Button;
        TGroupBox *Lit_GroupBox;
        TComboBox *LitP_ComboBox;
        TStaticText *AddLP_StaticText;
        TComboBox *LitC_ComboBox;
        TStaticText *AddLC_StaticText;
        TBitBtn *AddL_Button;
        TOpenPictureDialog *OpenPictureDialog1;
        TMenuItem *OpenTexture;
        TStaticText *Err_Text;
        void __fastcall OpenInputClick(TObject *Sender);
        void __fastcall Reset_ButtonClick(TObject *Sender);
        void __fastcall Draw_ButtonClick(TObject *Sender);
        void __fastcall ClearV_ButtonClick(TObject *Sender);
        void __fastcall ClearL_ButtonClick(TObject *Sender);
        void __fastcall ClearC_ButtonClick(TObject *Sender);
        void __fastcall SetC_ButtonClick(TObject *Sender);
        void __fastcall AddVP_ButtonClick(TObject *Sender);
        void __fastcall AddVN_ButtonClick(TObject *Sender);
        void __fastcall AddVT_ButtonClick(TObject *Sender);
        void __fastcall SetLA_ButtonClick(TObject *Sender);
        void __fastcall AddLP_ButtonClick(TObject *Sender);
        void __fastcall AddLC_ButtonClick(TObject *Sender);
private:	// User declarations
		
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);

        struct Node {
                double x, y, z;
                Node ( double _x = 0, double _y = 0, double _z = 0 ): x(_x),y(_y),z(_z) {}
                double operator* ( Node op ) { return (x*op.x+y*op.y+z*op.z); } // Node dot product
                Node operator^ ( Node op ) { return Node(y*op.z-z*op.y, z*op.x-x*op.z, x*op.y-y*op.x); } // Node product
                Node operator* ( double t ) { return Node(x*t, y*t, z*t); }
                Node operator/ ( double t ) { return Node(x/t, y/t, z/t); }
                Node operator+ ( Node op ) { return Node(x+op.x, y+op.y, z+op.z); }
                Node operator- ( Node op ) { return Node(x-op.x, y-op.y, z-op.z); }
        };
        struct Camera {
                Node position, direction, top;
                double distance;
        };
        struct Texture {
                double u,v;
                bool enable;
                Texture ( double _u = 0, double _v = 0 ): u(_u),v(_v) {}
        };
        struct Vertex {
                Node position, normal;
                Texture texture;
                double ka[3],kd[3],ks[3];
        };
        struct Light {
                double ambient;
                Node position;
                int color[3];
        };
        struct Triangle {
                Vertex vertex[3];
                Node normal;
        };
		
        double dabs(double);
        int dcmp(double);
        double TriangleArea(Node, Node, Node);
        double isInTriangle(Node, Node, Node, Node);
        Node getV(Node, Node, Node);
        double TwoPointDis(Node, Node);
        TColor DrawPixel(int, int);
        Node UnitVector(Node);
        void PixelPositionCalculate(void);
        void CleanMem(void);
        bool IntersectTriangle(Node, Node, Node, Node, Node, double*, double*, double*);

};

//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
