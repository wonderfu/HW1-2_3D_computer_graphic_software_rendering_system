//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TForm1 *Form1;				
//int Tnum;	// Triangle number
//int *Tricolor;
//TForm1::Vector **Tri = NULL;
TForm1::Camera camera;
TForm1::Vector pixel_pos[WindowH][WindowW];
vector <TForm1::Vector> VList,VNList;
vector <TForm1::Texture> VTList;
vector <TForm1::Triangle> TriList;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm1::OpenInputClick(TObject *Sender)
{
    FILE *fp;
    char str[StrSize];
    Vector input_node;
    Texture input_texture;
    Triangle input_triangle;
    int selectV, selectVN, selectVT;

    if( OpenDialog1->Execute() )
    {
        fp = fopen(OpenDialog1->FileName.c_str(), "r");
        Msg_Memo->Clear();

        /*if( Tri != NULL )
        {
            CleanMem();
        }*/
        while( fscanf(fp," %s ",str) == 1 )
        {
            if( !strcmp(str,"v") ) // vertex
            {
                fscanf(fp,"%lf %lf %lf", &input_node.x, &input_node.y, &input_node.z);
                VList.push_back(input_node);
            }
            else if( !strcmp(str,"vn") ) // vertex normal
            {
                fscanf(fp,"%lf %lf %lf", &input_node.x, &input_node.y, &input_node.z);
                VNList.push_back(input_node);
            }
            else if( !strcmp(str,"vt") ) // vertex texture
            {
                fscanf(fp,"%lf %lf", &input_texture.u, &input_texture.v);
                VTList.push_back(input_texture);
            }
            else if( !strcmp(str,"f") ) // triangle 
            {
                int readitem;
                for(int i=0; i<3; ++i)
                {
                    if( (readitem = fscanf(fp,"%d/%d/%d", &selectV, &selectVT, &selectVN)) == 3 ) // vertex number / texture number / normal number  for one vertex
                    {
                        input_triangle.vertex[i].position = VList[selectV - 1];
                        input_triangle.vertex[i].texture.enable = true;
                        input_triangle.vertex[i].texture = VTList[selectVT - 1];
                        input_triangle.vertex[i].normal = VNList[selectVN - 1];
                    }
                    else if( readitem == 2 )
                    {
                        input_triangle.vertex[i].position = VList[selectV - 1];
                        input_triangle.vertex[i].texture.enable = false;
                        input_triangle.vertex[i].normal = VNList[selectVT - 1]; // if no vertex selectVT will be the position of selectVN
                    }
                    else 
                    {
                        Err_Text->Caption = "[!] 三角形輸入發生錯誤";
                        continue;
                    }
                    TriList.push_back(input_triangle);
                }
            }
            else
            {
                Err_Text->Caption = "[!] 未定義的輸入格式";
            }
        }
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

double TForm1::TriangleArea(TForm1::Vector A, TForm1::Vector B, TForm1::Vector C)
{
    TForm1::Vector  AB, AC, AP;
    double pixel_pos = 0.0;
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
    pixel_pos = sqrt(AP.x*AP.x + AP.y*AP.y + AP.z*AP.z);
    area = dabs(pixel_pos/2);

    return area;
}

double TForm1::isInTriangle(TForm1::Vector tA, TForm1::Vector tB, TForm1::Vector tC, TForm1::Vector tP)
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

TForm1::Vector TForm1::getV(TForm1::Vector V1, TForm1::Vector V2, TForm1::Vector V3)
{
    double a, b, c, d;
    a = ( (V2.y-V1.y)*(V3.z-V1.z) - (V2.z-V1.z)*(V3.y-V1.y) );
    b = ( (V2.z-V1.z)*(V3.x-V1.x) - (V2.x-V1.x)*(V3.z-V1.z) );
    c = ( (V2.x-V1.x)*(V3.y-V1.y) - (V2.y-V1.y)*(V3.x-V1.x) );
    d = sqrt(a*a+b*b+c*c);
    return Vector(a/d,b/d,c/d);
}

double TForm1::TwoPointDis(Vector V1, Vector V2)
{
    TForm1::Vector dis = V1-V2;
    return sqrt(dis*dis);
}

TColor TForm1::DrawPixel(int i, int j)
{
    TColor color = WHITE; // 0xBBGGRR || RGB(R,G,B) [0~255]
    double t, u, v, select_dis = 2147483647, point_dis;
    TForm1::Vector cross_point, ray_vector;
	
    ray_vector = pixel_pos[i][j]-camera.position;
    for( vector<TForm1::Triangle>::iterator it = TriList.begin(); it != TriList.end(); ++it )
    {
        if( IntersectTriangle(camera.position, ray_vector, it->vertex[0].position, it->vertex[1].position, it->vertex[2].position, &t, &u, &v) )
        {
            cross_point = camera.position + ray_vector*t;
            point_dis = TwoPointDis(cross_point,camera.position);
            if( dcmp(point_dis-select_dis) < 0 )
            {
                select_dis = point_dis;
                color = (TColor)0x00ff00;
            }
        }		
		/*TForm1::Vector V = getV( it->vertex[0].position, it->vertex[1].position, it->vertex[2].position );
        if ( ray_vector*V != 0 )
        {
            t = ( (it->vertex[0].position - pixel_pos[i][j])*V ) / (ray_vector*V);
            cross_point = ray_vector*t + pixel_pos[i][j];
            point_dis = TwoPointDis(cross_point,camera.position);
            if ( isInTriangle( it->vertex[0].position, it->vertex[1].position, it->vertex[2].position, cross_point ) == true && dcmp(point_dis-select_dis) < 0 )
            {
                select_dis = point_dis;
//                color = (TColor) Tricolor[k];
            }
        }*/
    }
    return color;
}

// Determine whether a ray intersect with a triangle
// Parameters
// orig: origin of the ray
// dir: direction of the ray
// V1, V2, V3: vertices of triangle
// t( out): weight of the intersection for the ray
// u(out), v(out): barycentric coordinate of intersection 
// O+D*t = (1-u-v)*V1 + u*V2 + v*V3

bool IntersectTriangle(const Vector orig,const Vector dir, Vector V1, Vector V2, Vector V3, double* t, double* u, double* v)
{
    Vector E1 = V2 - V1;
    Vector E2 = V3 - V1;
    Vector P = dir^E2; 
    double det = E1*P; // determinant 
 
    // keep det > 0, modify T accordingly 
    Vector T;
    if ( det > 0 )
    {
        T = orig - V1;
    }
    else 
    {
        T = V1 - orig;
        det = - det;
    }
    // If determinant is near zero, ray lies in plane of triangle 
    if ( det < EPS )
        return false ;

    // Calculate u and make sure u <= 1 
    *u = T*P;
    if ( *u < 0.0f || *u > det )
        return false ;
 
    Vector Q = T^E1; 
 
    // Calculate v and make sure u + v <= 1 
    *v = dir*Q;
    if ( *v < 0.0f || *u + *v > det )
        return false ;
 
    // Calculate t, scale parameters, ray intersects triangle 
    *t = E2*Q;
 
    double fInvDet = 1.0f / det;
    *t *= fInvDet ;
    *u *= fInvDet;
    *v *= fInvDet;
 
    return true ;
}

TForm1::Vector TForm1::UnitVector(TForm1::Vector input_node)
{
    double Vdis = sqrt( input_node.x*input_node.x + input_node.y*input_node.y + input_node.z*input_node.z );
    return TForm1::Vector ( input_node.x/Vdis, input_node.y/Vdis, input_node.z/Vdis) ;
}

void TForm1::PixelPositionCalculate()
{
    Vector mid_point = camera.position + (camera.direction * camera.distance);
    Vector move_vector = UnitVector(camera.direction ^ camera.top);
    Vector start_point = mid_point + move_vector*WindowW/2 + camera.top*WindowH/2;
    for( int i=0; i<WindowH; ++i )
    {
        for ( int j=0; j<WindowW; ++j )
        {
            pixel_pos[i][j] = start_point - move_vector*j - camera.top*i;
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
            Draw_Area->Canvas->Pixels[j][i] = BLACK;
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
    VList.clear();
    VNList.clear();
    VTList.clear();
    TriList.clear();
    //CleanMem();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Draw_ButtonClick(TObject *Sender)
{
    for( int i=0; i<WindowH; ++i )
    {
        for( int j=0; j<WindowW; ++j )
        {
            Draw_Area->Canvas->Pixels[j][i] = DrawPixel(i,j);
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
       WD_Edit->Text == "" )
    {
        Err_Text->Caption = "相機欄位不得空白";
    }
    else
    {
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
        PixelPositionCalculate();
    }
}
//---------------------------------------------------------------------------


