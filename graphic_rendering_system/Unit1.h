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
        TBitBtn *Draw_Button;
        TImage *draw_area;
        TMainMenu *MainMenu1;
        TMenuItem *F1;
        TMenuItem *Open1;
        TOpenDialog *OpenDialog1;
        TLabeledEdit *VX_Edit;
        TLabeledEdit *VY_Edit;
        TLabeledEdit *VZ_Edit;
        TLabeledEdit *NX_Edit;
        TLabeledEdit *NY_Edit;
        TLabeledEdit *NZ_Edit;
        TLabeledEdit *KAR_Edit;
        TLabeledEdit *KAG_Edit;
        TLabeledEdit *KAB_Edit;
        TMemo *Msg_Memo;
        TBitBtn *AddV_Button;
        TLabeledEdit *CX_Edit;
        TLabeledEdit *CY_Edit;
        TLabeledEdit *CZ_Edit;
        TLabeledEdit *DX_Edit;
        TLabeledEdit *DY_Edit;
        TLabeledEdit *DZ_Edit;
        TLabeledEdit *TX_Edit;
        TLabeledEdit *TY_Edit;
        TLabeledEdit *TZ_Edit;
        TLabeledEdit *WD_Edit;
        TLabeledEdit *LX_Edit;
        TLabeledEdit *LY_Edit;
        TLabeledEdit *LZ_Edit;
        TLabeledEdit *CR_Edit;
        TLabeledEdit *CG_Edit;
        TLabeledEdit *CB_Edit;
        TBitBtn *AddL_Button;
        TBitBtn *Reset_Button;
        TBitBtn *ClearV_Button;
        TBitBtn *ClearC_Button;
        TBitBtn *ClearL_Button;
        TPageControl *SetC_Button;
        TTabSheet *TabSheet1;
        TTabSheet *TabSheet2;
        TTabSheet *TabSheet3;
        TGroupBox *VPos_GroupBox;
        TGroupBox *VN_GroupBox;
        TGroupBox *VPro_GroupBox;
        TLabeledEdit *KSR_Edit;
        TLabeledEdit *KSG_Edit;
        TLabeledEdit *KSB_Edit;
        TLabeledEdit *KDR_Edit;
        TLabeledEdit *KDG_Edit;
        TLabeledEdit *KDB_Edit;
        TStaticText *V_StaticText;
        TGroupBox *LA_GroupBox;
        TEdit *LA_Edit;
        TBevel *Bevel1;
        TBitBtn *SetLA_Button;
        TGroupBox *LS_GroupBox;
        TGroupBox *LSP_GroupBox;
        TGroupBox *LSC_GroupBox;
        TGroupBox *CP_GroupBox;
        TGroupBox *CD_GroupBox;
        TGroupBox *CT_GroupBox;
        TBitBtn *BitBtn2;
        void __fastcall Open1Click(TObject *Sender);
        void __fastcall Reset_ButtonClick(TObject *Sender);
        void __fastcall Draw_ButtonClick(TObject *Sender);
private:	// User declarations
		
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);

		struct position {
				float x,y,z;
		};
		struct color {
				int r,g,b;
		};
		struct node{
				float x, y, z;
				node ( float _x = 0, float _y = 0, float _z = 0 ): x(_x),y(_y),z(_z) {}
				float operator* ( node op ) { return (x*op.x+y*op.y+z*op.z); }
				node operator* ( float t ) { return node(x*t,y*t,z*t); }
				node operator/ ( float t ) { return node(x/t,y/t,z/t); }
				node operator+ ( node op ) { return node(x+op.x,y+op.y,z+op.z); }
				node operator- ( node op ) { return node(x-op.x,y-op.y,z-op.z); }
				node operator^ ( node op ) { return node(y*op.z-z*op.y,z*op.x-x*op.z,x*op.y-y*op.x); }
				};
		struct camera{
				node p, w, u;
				float d;
				};
		
		float dabs( float x );
		int dcmp( float x );
		float triangleArea( node A, node B, node C);
		float isInTriangle(node tA, node tB, node tC, node tP);
		node getV(node p1,node p2,node p3);
		float twopointdis( node a , node b );
		int make_pixel( int i, int j );
		node getunit( node n );
		void make_map();
		void clean_mem(void);		
};

//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
