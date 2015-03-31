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
TForm1::Node **Tri = NULL;
TForm1::Camera camera;
TForm1::Node m[WindowH][WindowW];
vector <TForm1::Node> VList,VNList;
vector <TForm1::Texture> VTList;
vector <TForm1::Triangle> TList;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm1::OpenInputClick(TObject *Sender)
{
    FILE *fp;

    int i, j;
    char str[StrSize];
    double x;
    Node input_node;
    Texture input_texture;
    int selectV, selectVN, selectVT;

    if( OpenDialog1->Execute() )
    {
        fp = fopen(OpenDialog1->FileName.c_str(), "r");
        Msg_Memo->Clear();

        if( Tri != NULL )
        {
            CleanMem();
        }
        while( fscanf(fp," %s ",str) ){
            if( !strcmp(str,"v") ){
                fscanf(fp,"%lf %lf %lf", &input_node.x, &input_node.y, &input_node.z);
                VList.push_back(input_node);
            }
            else if( !strcmp(str,"vn") ){
                fscanf(fp,"%lf %lf %lf", &input_node.x, &input_node.y, &input_node.z);
                VNList.push_back(input_node);
            }
            else if( !strcmp(str,"vt") ){
                fscanf(fp,"%lf %lf", &input_texture.u, &input_texture.v);
                VTList.push_back(input_texture);
            }
            else if( !strcmp(str,"f") ){
                
            }
            else{
                Err_Text->Caption = "[!] Undefind input_node.";
            }
        }

        /*
        while( fscanf(fp,"%c",&input_object) == 1 )
        {
            switch(input_object)
            {
                case 'v':
                case 'V':
                    for(int i=0; i<3; ++i)
                    {
                        //fscanf(fp,);
                    }
                    break;
                case 'l':
                case 'L':

                    break;
                case 'c':
                case 'C':
                    Msg_Memo->Lines->Add("Camera:");
                    fscanf(fp,"%f %f %f",&camera.position.x,&camera.position.y,&camera.position.z);
                    fscanf(fp,"%f %f %f",&camera.direction.x,&camera.direction.y,&camera.direction.z);
                    fscanf(fp,"%f %f %f",&camera.top.x,&camera.top.y,&camera.top.z);
                    fscanf(fp,"%f",&camera.distance);
                    break;
                default:
                    Msg_Memo->Lines->Add("[!]Error : Undefined input_node.");
                    break;
            }
        }

        // get the Node's info
        fscanf(fp,"%d",&Tnum);
        Tri = (Node**) malloc( sizeof(Node*)*Tnum);
        Tricolor = (int*) malloc( sizeof(int)*Tnum);
        for( i=0; i<Tnum; ++i )
        {
            Tri[i] = (Node*) malloc( sizeof(Node)*3);
            strcpy(str,"Triangle ");
            strcat(str,IntToStr(i+1).c_str());
            Msg_Memo->Lines->Add(str);
            for( j=0; j<3; ++j )
            {
                fscanf(fp,"%f%f%f",&Tri[i][j].x,&Tri[i][j].y,&Tri[i][j].z);
                strcpy(str,"Node ");
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
        }*/

        fclose(fp);
    }
    else
    {
        Err_Text->Caption = "[!] Open failed.";
    }
}

double TForm1::dabs(double x)
{
    return x < 0 ? -x : x ;
}

int TForm1::dcmp(double x)
{
    if( x < -EPS ) return -1; return x > EPS;
}

double TForm1::TriangleArea(TForm1::Node A, TForm1::Node B, TForm1::Node C)
{
    TForm1::Node  AB, AC, AP;
    double m = 0.0;
    double area = 0.0;

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

double TForm1::isInTriangle(TForm1::Node tA, TForm1::Node tB, TForm1::Node tC, TForm1::Node tP)
{
    double area1 = TriangleArea(tA,tB,tC);

    double area2 = TriangleArea(tP,tB,tC);

    double area3 = TriangleArea(tA,tP,tC);

    double area4 = TriangleArea(tA,tB,tP);

    double areaAll = area2 + area3 + area4;

    if( dcmp(areaAll - area1 - 1) <= 0 )
    {
       return true;
    }
    return false;
}

TForm1::Node TForm1::getV(TForm1::Node p1,TForm1::Node p2,TForm1::Node p3)
{
    double a, b, c, d;
    a = ( (p2.y-p1.y)*(p3.z-p1.z)-(p2.z-p1.z)*(p3.y-p1.y) );
    b = ( (p2.z-p1.z)*(p3.x-p1.x)-(p2.x-p1.x)*(p3.z-p1.z) );
    c = ( (p2.x-p1.x)*(p3.y-p1.y)-(p2.y-p1.y)*(p3.x-p1.x) );
    d = sqrt(a*a+b*b+c*c);
    return Node(a/d,b/d,c/d);
}

double TForm1::TwoPointDis(Node a , Node b)
{
    TForm1::Node AB = a-b;
    return sqrt(AB*AB);
}

TColor TForm1::DrawView( int i, int j )
{
    int k;
    TColor color = (TColor) 0xffffff; // 0xBBGGRR || RGB(R,G,B) [0~255]
    double t, distance = 2147483647, tmpdis;
    TForm1::Node cross, ck;
    ck = m[i][j]-camera.position;
    for ( k = 0 ; k < Tnum ; k ++ )
    {
        TForm1::Node V = getV(Tri[k][0],Tri[k][1],Tri[k][2]);
        if ( ck*V != 0 )
        {
            t = ( (Tri[k][0]-m[i][j])*V ) / (ck*V);
            cross = ck*t + m[i][j];
            tmpdis = TwoPointDis(cross,camera.position);
            if ( isInTriangle(Tri[k][0],Tri[k][1],Tri[k][2],cross) == true && dcmp(tmpdis-distance) < 0 )
            {
                distance = tmpdis;
                color = (TColor) Tricolor[k];
            }
        }
    }
    return color;
}

TForm1::Node TForm1::UnitVector(TForm1::Node n)
{
    double tmp = sqrt(n.x*n.x+n.y*n.y+n.z*n.z);
    return TForm1::Node ( n.x/tmp, n.y/tmp, n.z/tmp) ;
}

void TForm1::CreateView()
{
    int i, j;
    Node mid = camera.position + (camera.direction * camera.distance);
    Node left = UnitVector(camera.direction ^ camera.top);
    mid = mid + left*WindowW/2 + camera.top*WindowH/2;
    for( i=0; i<WindowH; ++i )
    {
        for ( j=0; j<WindowW; ++j )
        {
            m[i][j] = mid - left*j - camera.top*i;
        }
    }
}

void TForm1::CleanMem(void)
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
            Draw_Area->Canvas->Pixels[j][i] = (TColor)0;
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
    Err_Text->Caption = "";
    //CleanMem();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Draw_ButtonClick(TObject *Sender)
{
    for( int i=0; i<WindowH; ++i )
    {
        for( int j=0; j<WindowW; ++j )
        {
            Draw_Area->Canvas->Pixels[j][i] = DrawView(i,j);
        }
    }
}
//---------------------------------------------------------------------------



void __fastcall TForm1::ClearV_ButtonClick(TObject *Sender)
{
    VX_Edit->Text = "";
    VY_Edit->Text = "";
    VZ_Edit->Text = "";
    NX_Edit->Text = "";
    NY_Edit->Text = "";
    NZ_Edit->Text = "";
    TU_Edit->Text = "";
    TV_Edit->Text = "";
    KAR_Edit->Text = "";
    KAG_Edit->Text = "";
    KAB_Edit->Text = "";
    KDR_Edit->Text = "";
    KDG_Edit->Text = "";
    KDB_Edit->Text = "";
    KSR_Edit->Text = "";
    KSG_Edit->Text = "";
    KSB_Edit->Text = "";
    Err_Text->Caption = "";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ClearL_ButtonClick(TObject *Sender)
{
    LX_Edit->Text = "";
    LY_Edit->Text = "";
    LZ_Edit->Text = "";
    CR_Edit->Text = "";
    CG_Edit->Text = "";
    CB_Edit->Text = "";
    Err_Text->Caption = "";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ClearC_ButtonClick(TObject *Sender)
{
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
    Err_Text->Caption = "";
}
//---------------------------------------------------------------------------







void __fastcall TForm1::SetC_ButtonClick(TObject *Sender)
{
    if(CX_Edit->Text == "" || CY_Edit->Text == "" || CZ_Edit->Text == "" ||
       DX_Edit->Text == "" || DY_Edit->Text == "" || DZ_Edit->Text == "" ||
       TX_Edit->Text == "" || TY_Edit->Text == "" || TZ_Edit->Text == "" ||
       WD_Edit->Text == "" ){
        Err_Text->Caption = "相機欄位不得空白";
    }
    else{
        camera.position.x = StrToFloat(CX_Edit->Text);
        camera.position.y = StrToFloat(CY_Edit->Text);
        camera.position.z = StrToFloat(CZ_Edit->Text);
        camera.direction.x = StrToFloat(DX_Edit->Text);
        camera.direction.y = StrToFloat(DY_Edit->Text);
        camera.direction.z = StrToFloat(DZ_Edit->Text);
        camera.top.x = StrToFloat(TX_Edit->Text);
        camera.top.y = StrToFloat(TY_Edit->Text);
        camera.top.z = StrToFloat(TZ_Edit->Text);
        camera.distance = StrToFloat(WD_Edit->Text);
        camera.direction = UnitVector(camera.direction);
        camera.top = UnitVector(camera.top);
        // get the map's position
        CreateView();
    }
}
//---------------------------------------------------------------------------


