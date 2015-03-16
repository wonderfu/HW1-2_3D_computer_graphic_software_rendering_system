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
#include <iostream>

using namespace std;
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TBitBtn *Draw_button;
        TGroupBox *Vertex_group;
        TGroupBox *Light_group;
        TGroupBox *Camera_group;
        TImage *draw_area;
        TMainMenu *MainMenu1;
        TMenuItem *F1;
        TMenuItem *Open1;
        TOpenDialog *OpenDialog1;
        TLabeledEdit *VX_edit;
        TLabeledEdit *VY_edit;
        TLabeledEdit *VZ_edit;
        TLabeledEdit *NX_edit;
        TLabeledEdit *NY_edit;
        TLabeledEdit *NZ_edit;
        TLabeledEdit *VR_edit;
        TLabeledEdit *VG_edit;
        TLabeledEdit *VB_edit;
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
        void __fastcall Open1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
