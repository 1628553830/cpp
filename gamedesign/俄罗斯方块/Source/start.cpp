#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
#include<time.h>
#include<Windows.h>
#include"windowtitle.cpp"
#define ball_num 15

namespace startuispecific
{
int ball_x[ball_num],ball_y[ball_num],ball_vx[ball_num],ball_vy[ball_num];
int ridus=20;
int Width=640,Height=640;
LOGFONT f;
RECT r={0,0,Width,Height};
//void darwball();
void setup()
{
    srand((unsigned)time(NULL)); 
    for(int i=0;i<ball_num;i++)
    {
        ball_x[i]=rand()%(Width-2*ridus)+ridus;
        ball_y[i]=rand()%(Height-2*ridus)+ridus;
        ball_vx[i]=rand()%2*2-1;
        ball_vy[i]=rand()%2*2-1;
        for(int j=0;j<i;j++)
        {
            if((ball_x[i]-ball_x[j])*(ball_x[i]-ball_x[j])+(ball_y[i]-ball_y[j])*(ball_y[i]-ball_y[j])<=4*ridus*ridus)
            {i--;break;}
        }
    }
}

void updateWithoutInput()
{
    for(int i=0;i<ball_num;i++)
    {
       for(int j=0;j<ball_num;j++)
       {
           if((ball_x[i]-ball_x[j])*(ball_x[i]-ball_x[j])+(ball_y[i]-ball_y[j])*(ball_y[i]-ball_y[j])<=4*ridus*ridus)
           {
               if((ball_x[i]-ball_x[j])*(ball_x[i]-ball_x[j])+(ball_y[i]-ball_y[j])*(ball_y[i]-ball_y[j])>
               (ball_x[i]+ball_vx[i]-ball_x[j])*(ball_x[i]+ball_vx[i]-ball_x[j])+(ball_y[i]+ball_vy[i]-ball_y[j])*(ball_y[i]+ball_vy[i]-ball_y[j]))
               {ball_vx[i]=-ball_vx[i];ball_vy[i]=-ball_vy[i];}
           }
            if(ball_x[i]<=ridus)
           {
               ball_vx[i]=1;
           }
           else if(ball_x[i]>=Width-ridus)
           {
               ball_vx[i]=-1;
           }
           if(ball_y[i]<=ridus)
           {
            ball_vy[i]=1;
           }
           else if(ball_y[i]>=Height-ridus)
           {
               ball_vy[i]=-1;
           }
       }
       ball_x[i]+=ball_vx[i];
       ball_y[i]+=ball_vy[i];
    }
}

void show()
{
    BeginBatchDraw();
    setcolor(YELLOW);
    setfillcolor(YELLOW);
    for(int i=0;i<ball_num;i++)
    {
        fillcircle(ball_x[i],ball_y[i],ridus);
    }
    settextcolor(GREEN);
    //drawtext(_T("¶íÂÞË¹·½¿é"),&r,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
    FlushBatchDraw();
    Sleep(1);
    setcolor(BLUE);
    setfillcolor(BLUE);
    for(int i=0;i<ball_num;i++)
    {
        fillcircle(ball_x[i],ball_y[i],ridus);
    }
}
}
using namespace startuispecific;

int main()
{
    initgraph(640,640);
    windowtitle(L"STARTUI");
    setbkmode(TRANSPARENT);
    setbkcolor(BLUE);
    cleardevice();    
    settextstyle(0,0,_T("Conolas"));
    settextcolor(GREEN);
    gettextstyle(&f);
    f.lfQuality=ANTIALIASED_QUALITY;
    f.lfHeight=100;
    f.lfWeight=1000;
    f.lfWidth=0;
    settextstyle(&f);

    startuispecific::setup();
    while(1)
    {
       startuispecific::updateWithoutInput();
       startuispecific::show();
    }
    closegraph();

}