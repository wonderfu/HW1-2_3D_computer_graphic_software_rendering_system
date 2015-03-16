//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Open1Click(TObject *Sender)
{
    FILE *fp;

    if(OpenDialog1->Execute())
    {
        fp = fopen(OpenDialog1->FileName.c_str(), "r+");
        Memo1->Lines->Add(OpenDialog1->FileName.c_str());
        fclose(fp);
    }
    else
    {
        Memo1->Lines->Add("Nothing happens.");
    }
}
//---------------------------------------------------------------------------
