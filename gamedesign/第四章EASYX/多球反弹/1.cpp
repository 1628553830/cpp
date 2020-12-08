#include<graphics.h>
#include<conio.h>
#include<time.h>
#include<Windows.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#define High 480
#define Width 640
#define BallNum 15
#define ridus 20
//单个小球运动
float ball_x[BallNum],ball_y[BallNum];
float ball_vx[BallNum],ball_vy[BallNum];
using namespace std;
void setup()
{
    initgraph(Width,High);
    setbkcolor(GREEN);
    cleardevice();
    for(int i=0;i<BallNum;i++)
    {
        ball_x[i]=rand()%int(Width-2*ridus)+ridus;
        ball_y[i]=rand()%int(High-2*ridus)+ridus;
        ball_vx[i]=1-rand()%2*2;
        ball_vy[i]=1-rand()%2*2;
        for(int j=0;j<i;j++)
        {
          if(sqrt((ball_x[j]-ball_x[i])*(ball_x[j]-ball_x[i])+(ball_y[j]-ball_y[i])*(ball_y[j]-ball_y[i]))<2*ridus)
          {i--;break;}
        }
    }
}

void updateWithoutInput()
{
  for(int i=0;i<BallNum;i++)
  {
    for(int j=i;j<BallNum;j++)
    {
      if(sqrt((ball_x[j]-ball_x[i])*(ball_x[j]-ball_x[i])+(ball_y[j]-ball_y[i])*(ball_y[j]-ball_y[i]))<=2*ridus)
      {swap(ball_vx[i],ball_vx[j]);swap(ball_vy[i],ball_vy[j]);}
    }
    if(ball_x[i]-ridus==0||ball_x[i]+ridus==Width)
    {
      ball_vx[i]=-ball_vx[i];
    }
    if(ball_y[i]-ridus==0||ball_y[i]+ridus==High)
    {
      ball_vy[i]=-ball_vy[i];
    }

  }
  for(int i=0;i<BallNum;i++)
  {
      ball_x[i]+=ball_vx[i];
      ball_y[i]+=ball_vy[i];
  }
}
void updateWithInput()
{
  
}

void show()
{
   BeginBatchDraw();
   setcolor(YELLOW);
   setfillcolor(YELLOW);
   for(int i=0;i<BallNum;i++)
   {
     fillcircle(ball_x[i],ball_y[i],ridus);
   }
   FlushBatchDraw();
   Sleep(1);
   setcolor(GREEN);
   setfillcolor(GREEN);
   for(int i=0;i<BallNum;i++)
   {
     fillcircle(ball_x[i],ball_y[i],ridus);
   }
}

int main()
{
  setup();
  while(1)
  {
     show();
     updateWithInput();
     updateWithoutInput();
  }
}