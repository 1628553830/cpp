#include<graphics.h>
#include<conio.h>
#include<time.h>
#include<Windows.h>
#include<stdlib.h>
#define High 480
#define width 640
//单个小球运动

int ball_x,ball_y;
int ball_vx,ball_vy;
int ridus;

void setup()
{
    ball_x=High/2;
    ball_y=width/2;
    ball_vx=1;
    ball_vy=1;
    ridus=100;
    initgraph(width,High);
}

void updateWithoutInput()
{
   ball_vx=ball_x+ball_vx-ridus>=0&&ball_x+ball_vx+ridus<=width?ball_vx:-ball_vx;
   ball_vy=ball_y+ball_vy-ridus>=0&&ball_y+ball_vy+ridus<=High?ball_vy:-ball_vy;
   ball_x+=ball_vx;
   ball_y+=ball_vy;
}

void updateWithInput()
{

}

void show()
{
   BeginBatchDraw();
   setcolor(YELLOW);
   setfillcolor(GREEN);
   fillcircle(ball_x,ball_y,ridus);
   Sleep(10);
   FlushBatchDraw();
   setcolor(BLACK);
   setfillcolor(BLACK);
   fillcircle(ball_x,ball_y,ridus);
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