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
#include <cstring>
#include <stdio.h>
#include <math.h>
#define EPS 1e-8
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TBitBtn *Draw_button;
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
        TMemo *Input_memo;
        TBitBtn *addV_button;
        TLabeledEdit *CX_edit;
        TLabeledEdit *CY_edit;
        TLabeledEdit *CZ_edit;
        TLabeledEdit *PX_edit;
        TLabeledEdit *PY_edit;
        TLabeledEdit *PZ_edit;
        TLabeledEdit *TX_edit;
        TLabeledEdit *TY_edit;
        TLabeledEdit *TZ_edit;
        TLabeledEdit *WD_edit;
        TLabeledEdit *LX_edit;
        TLabeledEdit *LY_edit;
        TLabeledEdit *LZ_edit;
        TLabeledEdit *CR_edit;
        TLabeledEdit *CG_edit;
        TLabeledEdit *CB_edit;
        TBitBtn *addL_button;
        TBitBtn *Reset_button;
        TBitBtn *ClearV_edit;
        TBitBtn *ClearC_edit;
        TBitBtn *ClearL_edit;
        TPageControl *PageControl1;
        TTabSheet *TabSheet1;
        TTabSheet *TabSheet2;
        TTabSheet *TabSheet3;
        TGroupBox *GroupBox1;
        TGroupBox *GroupBox2;
        TGroupBox *GroupBox3;
        TLabeledEdit *KSR_Edit;
        TLabeledEdit *KSG_Edit;
        TLabeledEdit *KSB_Edit;
        TLabeledEdit *KDR_Edit;
        TLabeledEdit *KDG_Edit;
        TLabeledEdit *KDB_Edit;
        TStaticText *StaticText1;
        TGroupBox *GroupBox4;
        TEdit *Edit1;
        TBevel *Bevel1;
        TBitBtn *BitBtn1;
        TGroupBox *GroupBox5;
        TGroupBox *GroupBox6;
        TGroupBox *GroupBox7;
        TGroupBox *GroupBox8;
        TGroupBox *GroupBox9;
        TGroupBox *GroupBox10;
        TBitBtn *BitBtn2;
        void __fastcall Open1Click(TObject *Sender);
        void __fastcall Reset_buttonClick(TObject *Sender);
        void __fastcall Draw_buttonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
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
struct carema{
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

//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
