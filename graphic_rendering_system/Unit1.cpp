//---	------------------------------------------------------------------------

#include <vcl.h>
#include<math.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

// window
TForm1 *Form1;
TForm1::Node pixel_pos[WindowH][WindowW];
// camera
TForm1::Camera camera;
// light
double ambient_light;
TForm1::Light light0;
// vertex
vector <TForm1::Node> VList, VNList, LList;
vector <TForm1::Texture> VTList;
// triangle
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
    Node input_node;
    Texture input_texture;
    Triangle input_triangle;
    int selectV, selectVN, selectVT;

    srand(time(NULL));
    if( OpenDialog1->Execute() )
    {
        fp = fopen(OpenDialog1->FileName.c_str(), "r");
        Msg_Memo->Clear();
        VList.clear();
        VTList.clear();
        VNList.clear();
        TriList.clear();
        
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
                    if( (readitem = fscanf(fp," %d/%d/%d ", &selectV, &selectVT, &selectVN)) == 3 ) // vertex number / texture number / normal number  for one vertex
                    {
                        input_triangle.vertex[i].position = VList[selectV - 1];
                        input_triangle.vertex[i].texture = VTList[selectVT - 1];
                        input_triangle.vertex[i].normal = VNList[selectVN - 1];
                    }
                    else if( readitem == 2 )
                    {
                        input_triangle.vertex[i].position = VList[selectV - 1];
                        input_triangle.vertex[i].normal = VNList[selectVT - 1]; // if no vertex selectVT will be the position of selectVN
                    }
                    else
                    {
                        Err_Text->Caption = "[!] 三角形輸入發生錯誤";
                        continue;
                    }
                    input_triangle.vertex[i].color[0] = rand()%101/100.0;
                    input_triangle.vertex[i].color[1] = rand()%101/100.0;
                    input_triangle.vertex[i].color[2] = rand()%101/100.0;
                }
                if( readitem == 3 )
                    input_triangle.tex_enable = true;
                else
                    input_triangle.tex_enable = false;
                input_triangle.ka[0] = rand()%101/100.0;
                input_triangle.ka[1] = rand()%101/100.0;
                input_triangle.ka[2] = rand()%101/100.0;
                input_triangle.kd[0] = rand()%101/100.0;
                input_triangle.kd[1] = rand()%101/100.0;
                input_triangle.kd[2] = rand()%101/100.0;
                input_triangle.ks[0] = rand()%101/100.0;
                input_triangle.ks[1] = rand()%101/100.0;
                input_triangle.ks[2] = rand()%101/100.0;
                TriList.push_back(input_triangle);
            }
            else
            {
                Err_Text->Caption = "[!] 未定義的輸入格式";
            }
        }
        // for test input data
        int a=1;
        for(vector <TForm1::Triangle>::iterator it=TriList.begin(); it!=TriList.end(); ++it)
        {
            Msg_Memo->Lines->Add("T"+FloatToStr(a));
            Msg_Memo->Lines->Add("position:");
            for(int j=0; j<3; ++j)
            {
                Msg_Memo->Lines->Add(IntToStr(j)+":"+FloatToStr(it->vertex[j].position.x)+","+FloatToStr(it->vertex[j].position.y)+","+FloatToStr(it->vertex[j].position.z));
            }
            Msg_Memo->Lines->Add("normal:");
            for(int j=0; j<3; ++j)
            {
                Msg_Memo->Lines->Add(IntToStr(j)+":"+FloatToStr(it->vertex[j].normal.x)+","+FloatToStr(it->vertex[j].normal.y)+","+FloatToStr(it->vertex[j].normal.z));
            }
            if( it->tex_enable == true )
            {
                Msg_Memo->Lines->Add("texture:");
                for(int j=0; j<3; ++j)
                {
                    Msg_Memo->Lines->Add(IntToStr(j)+":"+FloatToStr(it->vertex[j].texture.u)+","+FloatToStr(it->vertex[j].texture.v));
                }
            }
            ++a;
            Msg_Memo->Lines->Add("");
        }

        fclose(fp);
        Err_Text->Caption = "";
    }
    else
    {
        Err_Text->Caption = "[!] Open failed.";
    }
}

TForm1::Node TForm1::UnitVector(TForm1::Node input_node)
{
    double Vdis = sqrt( input_node*input_node );
    return input_node/Vdis ;
}

int TForm1::dcmp(double x)
{
    if( x < -EPS ) return -1; return x > EPS;
}

double TForm1::TwoPointDis(TForm1::Node V1, TForm1::Node V2)
{
    TForm1::Node dis = V1-V2;
    return sqrt(dis*dis);
}

// Determine whether a ray intersect with a triangle
// Parameters
// O: origin of the ray
// D: direction of the ray
// V1, V2, V3: vertices of triangle
// t(out): weight of the intersection for the ray
// u(out), v(out): barycentric coordinate of intersection 
//
// O+D*t = (1-u-v)*V1 + u*V2 + v*V3
//   t         1       T^E1.E2 
// [ u ] = _________ [ D^E2.T ]
//   v     [D^E2.E1]   T^E1.D  

bool TForm1::IntersectTriangle(TForm1::Node O, TForm1::Node D, TForm1::Node V1, TForm1::Node V2, TForm1::Node V3, double* t, double* u, double* v)
{
    TForm1::Node E1, E2, P, Q, T;
    double det, inv_det;

    //Find vectors for two edges sharing V1
    E1 = V2-V1;
    E2 = V3-V1;
    //Begin calculating determinant - also used to calculate u parameter
    P = D^E2;
    //if determinant is near zero, ray lies in plane of triangle
    det = E1*P;
    //NOT CULLING
    if(det > -EPS && det < EPS)
        return false;

    inv_det = 1.f/det;

    //calculate distance from V1 to ray origin
    T = O-V1;

    //Calculate u parameter and test bound
    *u = (T*P)*inv_det;
    //The intersection lies outside of the triangle
    if(*u < 0.f || *u > 1.f)
    	return false;

    //Prepare to test v parameter
    Q = T^E1;

    //Calculate V parameter and test bound
    *v = (D*Q)*inv_det;
    //The intersection lies outside of the triangle
    if(*v < 0.f || *u + *v  > 1.f)
      	return false;

    *t = (E2*Q)*inv_det;
    
    if(*t > EPS) //ray intersection
      	return true;
    // No hit, no win
    return false;
}

void TForm1::Lighting(struct Vertex vertex, double* ka, double* ks, double* kd, Node L_ray, Node V_ray, double dis)
{
        int n = 2;
        double Att = min(1,1/(dis*dis));
        Node N = UnitVector(vertex.normal);
        Node V = UnitVector(V_ray);
        Node L = UnitVector(L_ray);
        Node H = UnitVector(L_ray + V_ray);

	vertex.color[0] = ka[0] * ambient_light + Att * light0.color[0] * (kd[0] * (N * L) + ks[0] * pow((N * H), n));
	vertex.color[1] = ka[1] * ambient_light + Att * light0.color[1] * (kd[1] * (N * L) + ks[1] * pow((N * H), n));
	vertex.color[2] = ka[2] * ambient_light + Att * light0.color[2] * (kd[2] * (N * L) + ks[2] * pow((N * H), n));
}

TForm1::Node TForm1::Interpolation(Node V1, Node V2, Node V3, double u, double v)
{
        double t = 1 - u - v;
	Node renode;

	renode.x = V1.x * t + V2.x * u + V3.x * v;
	renode.y = V1.y * t + V2.y * u + V3.y * v;
	renode.z = V1.z * t + V2.z * u + V3.z * v;
	return renode;
}

void Interpolation(double* out, double* V1, double* V2, double* V3, double u, double v)
{
        double t = 1 - u - v;

	out[0] = V1[0] * t + V2[0] * u + V3[0] * v;
	out[1] = V1[1] * t + V2[1] * u + V3[1] * v;
	out[2] = V1[2] * t + V2[2] * u + V3[2] * v;
}

TColor TForm1::DrawPixel(int i, int j)
{
    TColor color; // 0xBBGGRR || RGB(R,G,B) [0~255]
    double t, u, v;
    double select_u, select_v;
    double select_dis = 2147483647, point_dis;
    Node cross_point, ray_dir;
    struct Vertex select_point;
    vector<TForm1::Triangle>::iterator select_tri = NULL;

    ray_dir = UnitVector(pixel_pos[i][j] - camera.position);
    for( vector<TForm1::Triangle>::iterator it = TriList.begin(); it != TriList.end(); ++it )
    {
        if( IntersectTriangle(camera.position, ray_dir, it->vertex[0].position, it->vertex[1].position, it->vertex[2].position, &t, &u, &v) )
        {
            cross_point = camera.position + (ray_dir * t);
            point_dis = TwoPointDis(cross_point,camera.position);
            if( dcmp(point_dis - select_dis) < 0 )
            {
                select_dis = point_dis;
                select_point.position = cross_point;
                select_tri = it;
                select_u = u;
                select_v = v;
            }
        }
    }
    if( select_tri == NULL )
        return BLACK;

    select_point.normal = Interpolation(select_tri->vertex[0].normal, select_tri->vertex[1].normal, select_tri->vertex[2].normal, select_u, select_v);
    select_point.color = Interpolation(select_tri->vertex[0].color, select_tri->vertex[1].color, select_tri->vertex[2].color, select_u, select_v);

    return color;
}

void TForm1::PixelPositionCalculate()
{
    Node mid_point = camera.position + (camera.direction * camera.distance);
    Node move_vector = UnitVector(camera.direction ^ camera.top);
    Node start_point = mid_point + move_vector*WindowW/2 + camera.top*WindowH/2;
    for( int i=0; i<WindowH; ++i )
    {
        for ( int j=0; j<WindowW; ++j )
        {
            pixel_pos[i][j] = start_point - move_vector*j - camera.top*i;
        }
    }
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
        return ;
    }
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
    Err_Text->Caption = "";
    Msg_Memo->Lines->Add("");
    Msg_Memo->Lines->Add("Camera:");
    Msg_Memo->Lines->Add("pos: "+FloatToStr(camera.position.x)+","+FloatToStr(camera.position.y)+","+FloatToStr(camera.position.z));
    Msg_Memo->Lines->Add("dir: "+FloatToStr(camera.direction.x)+","+FloatToStr(camera.direction.y)+","+FloatToStr(camera.direction.z));
    Msg_Memo->Lines->Add("top: "+FloatToStr(camera.top.x)+","+FloatToStr(camera.top.y)+","+FloatToStr(camera.top.z));
    Msg_Memo->Lines->Add("window dis: "+FloatToStr(camera.distance));
    // get the map's position
    PixelPositionCalculate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::AddVP_ButtonClick(TObject *Sender)
{
    if(VX_Edit->Text == "" || VY_Edit->Text == "" || VZ_Edit->Text == "")
	{
        Err_Text->Caption = "座標不得空白";
        return ;
    }
    Node input_node(StrToFloat(VX_Edit->Text), StrToFloat(VY_Edit->Text), StrToFloat(VZ_Edit->Text));
    VList.push_back(input_node);
    Err_Text->Caption = "";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::AddVN_ButtonClick(TObject *Sender)
{
    if(NX_Edit->Text == "" || NY_Edit->Text == "" || NZ_Edit->Text == "")
	{
        Err_Text->Caption = "向量不得空白";
        return ;
    }
    Node input_node(StrToFloat(NX_Edit->Text), StrToFloat(NY_Edit->Text), StrToFloat(NZ_Edit->Text));
    VNList.push_back(input_node);
    Err_Text->Caption = "";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::AddVT_ButtonClick(TObject *Sender)
{
    if(TU_Edit->Text == "" || TV_Edit->Text == "")
	{
        Err_Text->Caption = "貼圖座標不得空白";
        return ;
    }
    Texture input_texture(StrToFloat(TU_Edit->Text), StrToFloat(TV_Edit->Text));
    VTList.push_back(input_texture);
    Err_Text->Caption = "";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SetLA_ButtonClick(TObject *Sender)
{
    if( LA_Edit->Text == "" )
	{
        ambient_light = 0.0;
        light0.ambient = 0;
        LA_Edit->Text = "0";
    }
    else
	{
        ambient_light = StrToFloat(LA_Edit->Text);
        light0.ambient = StrToFloat(LA_Edit->Text);
    }
    Err_Text->Caption = "";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::AddLP_ButtonClick(TObject *Sender)
{
    if(LX_Edit->Text == "" || LY_Edit->Text == "" || LZ_Edit->Text == "")
	{
        Err_Text->Caption = "座標不得空白";
        return ;
    }
    /*
    Node input_node(StrToFloat(LX_Edit->Text), StrToFloat(LY_Edit->Text), StrToFloat(LZ_Edit->Text));
    LList.push_back(input_node);
    */
    light0.position = Node(StrToFloat(LX_Edit->Text), StrToFloat(LY_Edit->Text), StrToFloat(LZ_Edit->Text));
    Err_Text->Caption = "";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::AddLC_ButtonClick(TObject *Sender)
{
    int input_color[3];
    if(CR_Edit->Text == "" || CG_Edit->Text == "" || CB_Edit->Text == "")
	{
        Err_Text->Caption = "顏色不得空白";
        return ;
    }
    input_color[0] = StrToFloat(CR_Edit->Text);
    input_color[1] = StrToFloat(CG_Edit->Text);
    input_color[2] = StrToFloat(CB_Edit->Text);
    if(input_color[0] < 0 || input_color[0] > 1 ||
       input_color[1] < 0 || input_color[1] > 1 ||
       input_color[2] < 0 || input_color[2] > 1)
    {
        Err_Text->Caption = "顏色範圍需介於0~1";
        return ;
    }
    light0.color[0] = input_color[0];
    light0.color[1] = input_color[1];
    light0.color[2] = input_color[2];
    Err_Text->Caption = "";
}
//---------------------------------------------------------------------------







