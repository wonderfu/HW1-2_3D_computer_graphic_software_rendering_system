//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

#define MAXi 600
#define MAXj 800

TForm1 *Form1;

int Tnum, *Tricolor;
node **Tri = NULL;
carema view;
node m[MAXi][MAXj];

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
    float tmp;
    /*
    char input_object;
    float x;
    */
    if(OpenDialog1->Execute())
    {
        fp = fopen(OpenDialog1->FileName.c_str(), "r");
        Input_memo->Clear();

        if(Tri!=NULL)
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
        fscanf(fp,"%f %f %f",&view.p.x,&view.p.y,&view.p.z);
        fscanf(fp,"%f %f %f",&view.w.x,&view.w.y,&view.w.z);
        fscanf(fp,"%f %f %f",&view.u.x,&view.u.y,&view.u.z);
        fscanf(fp,"%f",&view.d);
        view.w = getunit(view.w);
        view.u = getunit(view.u);

        // get the map's position
        make_map();
        // get the node's info
        fscanf(fp,"%d",&Tnum);
        Tri = (node**) malloc( sizeof(node*)*Tnum);
        Tricolor = (int*) malloc( sizeof(int)*Tnum);
        for(i=0; i<Tnum; ++i)
        {
            Tri[i] = (node*) malloc( sizeof(node)*3);
            strcpy(str,"Triangle ");
            strcat(str,IntToStr(i+1).c_str());
            Input_memo->Lines->Add(str);
            for(j=0; j<3; ++j)
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
                Input_memo->Lines->Add(str);
            }
            fscanf(fp,"%d",&Tricolor[i]);
            Input_memo->Lines->Add("");
        }
        // get the pixels
        for(i=0; i<MAXi; ++i)
        {
            for(j=0; j<MAXj; ++j)
            {
                draw_area->Canvas->Pixels[j][i] = make_pixel(i,j);
            }
        }
        fclose(fp);
    }
    else
    {
        Input_memo->Lines->Add("[!]Open failed.");
    }
}

float dabs( float x )
{
    return x < 0 ? -x : x ;
}

int dcmp( float x )
{
    if( x < -EPS ) return -1; return x > EPS;
}

float triangleArea( node A, node B, node C)
{
    node  AB, AC, AP;
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

float isInTriangle(node tA, node tB, node tC, node tP)
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

node getV(node p1,node p2,node p3)
{
    float a, b, c, d;
    a = ( (p2.y-p1.y)*(p3.z-p1.z)-(p2.z-p1.z)*(p3.y-p1.y) );
    b = ( (p2.z-p1.z)*(p3.x-p1.x)-(p2.x-p1.x)*(p3.z-p1.z) );
    c = ( (p2.x-p1.x)*(p3.y-p1.y)-(p2.y-p1.y)*(p3.x-p1.x) );
    d = sqrt(a*a+b*b+c*c);
    return node(a/d,b/d,c/d);
}

float twopointdis( node a , node b )
{
    node AB = a-b;
    return sqrt(AB*AB);
}

int make_pixel( int i, int j )
{
    int k, color = 0xffffffff;
    float t, dis = 2147483647, tmpdis;
    node cross, ck;
    ck = m[i][j]-view.p;
    for ( k = 0 ; k < Tnum ; k ++ )
    {
        node V = getV(Tri[k][0],Tri[k][1],Tri[k][2]);
        if ( ck*V != 0 )
        {
            t = ( (Tri[k][0]-m[i][j])*V ) / (ck*V);
            cross = ck*t + m[i][j];
            tmpdis = twopointdis(cross,view.p);
            if ( isInTriangle(Tri[k][0],Tri[k][1],Tri[k][2],cross) == true && dcmp(tmpdis-dis) < 0 )
            {
                dis = tmpdis;
                color = Tricolor[k];
            }
        }
    }
    return color;
}

node getunit( node n )
{
    float tmp = sqrt(n.x*n.x+n.y*n.y+n.z*n.z);
    return node ( n.x/tmp, n.y/tmp, n.z/tmp) ;
}

void make_map()
{
    int i, j;
    node mid = view.p + (view.w * view.d);
    node left = getunit(view.w ^ view.u);
    mid = mid + left*MAXj/2 + view.u*MAXi/2;
    for(i=0; i<MAXi; ++i)
    {
        for (j=0; j<MAXj; ++j)
        {
            m[i][j] = mid - left*j - view.u*i;
        }
    }
}

void clean_mem(void)
{
    free(Tricolor);
    Tricolor = NULL;
    for(int i=0; i<Tnum; ++i)
        free(Tri[i]);
    free(Tri);
    Tri = NULL;
}

//---------------------------------------------------------------------------
void __fastcall TForm1::Reset_buttonClick(TObject *Sender)
{
    Input_memo->Clear();
    for(int i=0; i<MAXi; ++i)
    {
        for(int j=0; j<MAXj; ++j)
        {
            draw_area->Canvas->Pixels[j][i] = 0;
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Draw_buttonClick(TObject *Sender)
{
    for(int i=0; i<MAXi; ++i)
    {
        for(int j=0; j<MAXj; ++j)
        {
            draw_area->Canvas->Pixels[j][i] = make_pixel(i,j);
        }
    }
}
//---------------------------------------------------------------------------



