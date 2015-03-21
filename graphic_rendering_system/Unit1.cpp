//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TForm1 *Form1;				
int Tnum;	// Triangle number
int *Tricolor;
TForm1::Vector **Tri = NULL;
TForm1::Camera view;
TForm1::Vector m[WindowH][WindowW];

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Open1Click(TObject *Sender)
{
    FILE *fp;

    int i, j;
    char str[300];
    /*
    char input_object;
    float x;
    */
    if( OpenDialog1->Execute() )
    {
        fp = fopen(OpenDialog1->FileName.c_str(), "r");
        Msg_Memo->Clear();

        if( Tri != NULL )
        {
            clean_mem();
        }
        /*
        while( fscanf(fp,"%c",&input_object) == 1 )
        {
            Input_memo->Lines->Add(input_object);
            switch(input_object)
            {
                case 'v':
                case 'V':
                    for(int i=0; i<3; ++i)
                    {
                        fscanf(fp,);
                    }
                    break;
                case 'l':
                case 'L':

                    break;
                case 'c':
                case 'C':

                    break;
                default:
                    Input_memo->Lines->Add("[!]Error : Undefined input.");
                    break;
            }
        }
        Input_memo->Lines->Add("EOF");
        */
        fscanf(fp,"%f %f %f",&view.pos.x,&view.pos.y,&view.pos.z);
        fscanf(fp,"%f %f %f",&view.dir.x,&view.dir.y,&view.dir.z);
        fscanf(fp,"%f %f %f",&view.top.x,&view.top.y,&view.top.z);
        fscanf(fp,"%f",&view.dis);
        view.dir = getunit(view.dir);
        view.top = getunit(view.top);

        // get the map's position
        make_map();
        // get the Vector's info
        fscanf(fp,"%d",&Tnum);
        Tri = (Vector**) malloc( sizeof(Vector*)*Tnum);
        Tricolor = (int*) malloc( sizeof(int)*Tnum);
        for( i=0; i<Tnum; ++i )
        {
            Tri[i] = (Vector*) malloc( sizeof(Vector)*3);
            strcpy(str,"Triangle ");
            strcat(str,IntToStr(i+1).c_str());
            Msg_Memo->Lines->Add(str);
            for( j=0; j<3; ++j )
            {
                fscanf(fp,"%f%f%f",&Tri[i][j].x,&Tri[i][j].y,&Tri[i][j].z);
                strcpy(str,"Vector ");
                strcat(str,IntToStr(j+1).c_str());
                strcat(str,": ( ");
                strcat(str,FloatToStr(Tri[i][j].x).c_str());
                strcat(str," , ");
                strcat(str,FloatToStr(Tri[i][j].y).c_str());
                strcat(str," , ");
                strcat(str,FloatToStr(Tri[i][j].z).c_str());
                strcat(str," )");
                Msg_Memo->Lines->Add(str);
            }
            fscanf(fp,"%d",&Tricolor[i]);
            Msg_Memo->Lines->Add("");
        }
        // get the pixels
        for( i=0; i<WindowH; ++i )
        {
            for( j=0; j<WindowW; ++j )
            {
                Draw_Area->Canvas->Pixels[j][i] = make_pixel(i,j);
            }
        }
        fclose(fp);
    }
    else
    {
        Msg_Memo->Lines->Add("[!]Open failed.");
    }
}

float TForm1::dabs(float x)
{
    return x < 0 ? -x : x ;
}

int TForm1::dcmp(float x)
{
    if( x < -EPS ) return -1; return x > EPS;
}

float TForm1::triangleArea(TForm1::Vector A, TForm1::Vector B, TForm1::Vector C)
{
    TForm1::Vector  AB, AC, AP;
    float m = 0.0;
    float area = 0.0;

    AB.x =  B.x -  A.x;
    AB.y =  B.y -  A.y;
    AB.z =  B.z -  A.z;

    AC.x =  C.x -  A.x;
    AC.y =  C.y -  A.y;
    AC.z =  C.z -  A.z;

    AP.x = AB.y*AC.z - AC.y*AB.z;
    AP.y = AC.x*AB.z - AB.x*AC.z;
    AP.z = AB.x*AC.y - AC.x*AB.y;
    m = sqrt(AP.x*AP.x + AP.y*AP.y + AP.z*AP.z);
    area = dabs(m/2);

    return area;
}

float TForm1::isInTriangle(TForm1::Vector tA, TForm1::Vector tB, TForm1::Vector tC, TForm1::Vector tP)
{
    float area1 = triangleArea(tA,tB,tC);

    float area2 = triangleArea(tP,tB,tC);

    float area3 = triangleArea(tA,tP,tC);

    float area4 = triangleArea(tA,tB,tP);

    float areaAll = area2 + area3 + area4;

    if( dcmp(areaAll - area1 - 1) <= 0 )
    {
       return true;
    }
    return false;
}

TForm1::Vector TForm1::getV(TForm1::Vector p1,TForm1::Vector p2,TForm1::Vector p3)
{
    float a, b, c, d;
    a = ( (p2.y-p1.y)*(p3.z-p1.z)-(p2.z-p1.z)*(p3.y-p1.y) );
    b = ( (p2.z-p1.z)*(p3.x-p1.x)-(p2.x-p1.x)*(p3.z-p1.z) );
    c = ( (p2.x-p1.x)*(p3.y-p1.y)-(p2.y-p1.y)*(p3.x-p1.x) );
    d = sqrt(a*a+b*b+c*c);
    return Vector(a/d,b/d,c/d);
}

float TForm1::twopointdis(Vector a , Vector b)
{
    TForm1::Vector AB = a-b;
    return sqrt(AB*AB);
}

int TForm1::make_pixel( int i, int j )
{
    int k, color = 0xffffff; // 0xBBGGRR || RGB(R,G,B) [0~255]
    float t, dis = 2147483647, tmpdis;
    TForm1::Vector cross, ck;
    ck = m[i][j]-view.pos;
    for ( k = 0 ; k < Tnum ; k ++ )
    {
        TForm1::Vector V = getV(Tri[k][0],Tri[k][1],Tri[k][2]);
        if ( ck*V != 0 )
        {
            t = ( (Tri[k][0]-m[i][j])*V ) / (ck*V);
            cross = ck*t + m[i][j];
            tmpdis = twopointdis(cross,view.pos);
            if ( isInTriangle(Tri[k][0],Tri[k][1],Tri[k][2],cross) == true && dcmp(tmpdis-dis) < 0 )
            {
                dis = tmpdis;
                color = Tricolor[k];
            }
        }
    }
    return color;
}

TForm1::Vector TForm1::getunit(TForm1::Vector n)
{
    float tmp = sqrt(n.x*n.x+n.y*n.y+n.z*n.z);
    return TForm1::Vector ( n.x/tmp, n.y/tmp, n.z/tmp) ;
}

void TForm1::make_map()
{
    int i, j;
    Vector mid = view.pos + (view.dir * view.dis);
    Vector left = getunit(view.dir ^ view.top);
    mid = mid + left*WindowW/2 + view.top*WindowH/2;
    for( i=0; i<WindowH; ++i )
    {
        for ( j=0; j<WindowW; ++j )
        {
            m[i][j] = mid - left*j - view.top*i;
        }
    }
}

void TForm1::clean_mem(void)
{
    free(Tricolor);
    Tricolor = NULL;
    for( int i=0; i<Tnum; ++i )
        free(Tri[i]);
    free(Tri);
    Tri = NULL;
}

//---------------------------------------------------------------------------
void __fastcall TForm1::Reset_ButtonClick(TObject *Sender)
{
    Msg_Memo->Clear();
    for( int i=0; i<WindowH; ++i )
    {
        for( int j=0; j<WindowW; ++j )
        {
            Draw_Area->Canvas->Pixels[j][i] = 0;
        }
    }
    VX_Edit->Text = "";
    VY_Edit->Text = "";
    VZ_Edit->Text = "";
    NX_Edit->Text = "";
    NY_Edit->Text = "";
    NZ_Edit->Text = "";
    KAR_Edit->Text = "";
    KAG_Edit->Text = "";
    KAB_Edit->Text = "";
    KDR_Edit->Text = "";
    KDG_Edit->Text = "";
    KDB_Edit->Text = "";
    KSR_Edit->Text = "";
    KSG_Edit->Text = "";
    KSB_Edit->Text = "";
    LA_Edit->Text = "";
    LX_Edit->Text = "";
    LY_Edit->Text = "";
    LZ_Edit->Text = "";
    CR_Edit->Text = "";
    CG_Edit->Text = "";
    CB_Edit->Text = "";
    CX_Edit->Text = "";
    CY_Edit->Text = "";
    CZ_Edit->Text = "";
    DX_Edit->Text = "";
    DY_Edit->Text = "";
    DZ_Edit->Text = "";
    TX_Edit->Text = "";
    TY_Edit->Text = "";
    TZ_Edit->Text = "";
    WD_Edit->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Draw_ButtonClick(TObject *Sender)
{
    for( int i=0; i<WindowH; ++i )
    {
        for( int j=0; j<WindowW; ++j )
        {
            Draw_Area->Canvas->Pixels[j][i] = make_pixel(i,j);
        }
    }
}
//---------------------------------------------------------------------------



