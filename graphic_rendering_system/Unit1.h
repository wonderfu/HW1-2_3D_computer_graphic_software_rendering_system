//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ActnCtrls.hpp>
#include <ActnMan.hpp>
#include <ActnMenus.hpp>
#include <ExtCtrls.hpp>
#include <ToolWin.hpp>
#include <Menus.hpp>
#include <Dialogs.hpp>
#include <ComCtrls.hpp>

// user include & define
#include <cstring>
#include <stdio.h>
#include <math.h>

#define EPS 1e-8
#define WindowH 600
#define WindowW 800 
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TMainMenu *MainMenu1;
        TMenuItem *Open1;
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
        TLabeledEdit *KAR_Edit;
        TLabeledEdit *KAG_Edit;
        TLabeledEdit *KAB_Edit;
        TLabeledEdit *KSR_Edit;
        TLabeledEdit *KSG_Edit;
        TLabeledEdit *KSB_Edit;
        TLabeledEdit *KDR_Edit;
        TLabeledEdit *KDG_Edit;
        TLabeledEdit *KDB_Edit;
        TStaticText *V_StaticText;
        TBitBtn *AddV_Button;
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
        TBitBtn *AddL_Button;
        TBitBtn *ClearL_Button;
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
        void __fastcall Open1Click(TObject *Sender);
        void __fastcall Reset_ButtonClick(TObject *Sender);
        void __fastcall Draw_ButtonClick(TObject *Sender);
private:	// User declarations
		
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);

		struct Vector {
				float x, y, z;
				Vector ( float _x = 0, float _y = 0, float _z = 0 ): x(_x),y(_y),z(_z) {}
				float operator* ( Vector op ) { return (x*op.x+y*op.y+z*op.z); } // Vector dot product
				Vector operator* ( float t ) { return Vector(x*t,y*t,z*t); } 
				Vector operator/ ( float t ) { return Vector(x/t,y/t,z/t); }
				Vector operator+ ( Vector op ) { return Vector(x+op.x,y+op.y,z+op.z); } 
				Vector operator- ( Vector op ) { return Vector(x-op.x,y-op.y,z-op.z); }
				Vector operator^ ( Vector op ) { return Vector(y*op.z-z*op.y,z*op.x-x*op.z,x*op.y-y*op.x); } // Vector product
		};
		struct Camera {
				Vector pos, dir, top;
				float dis;
		};
		struct Vertex {
				Vector pos, nor;
				float ka[3],kd[3],ks[3];
		};
		struct Light {
				float al;
				Vector pos;
				int color[3];
		};
		
		float dabs( float x );
		int dcmp( float x );
		float triangleArea( Vector A, Vector B, Vector C);
		float isInTriangle(Vector tA, Vector tB, Vector tC, Vector tP);
		Vector getV(Vector p1,Vector p2,Vector p3);
		float twopointdis( Vector a , Vector b );
		int make_pixel( int i, int j );
		Vector getunit( Vector n );
		void make_map();
		void clean_mem(void);		
};

//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
