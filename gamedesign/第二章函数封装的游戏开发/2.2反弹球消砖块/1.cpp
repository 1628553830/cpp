#include<iostream>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>

int ball_x,ball_y;//球的坐标
int ball_vx,ball_vy;//球的方向
int target_x,target_y;//目标的坐标
int width,high;//画面尺寸

void gotoxy(int x,int y)
{
    HANDLE handle=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X=x;
    pos.Y=y;
    SetConsoleCursorPosition(handle,pos);
}
void Hidecursor()
{
    CONSOLE_CURSOR_INFO cursor_info={1,0};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cursor_info);
}

void setup()
{
   Hidecursor();
   width=20;
   high=15;
   ball_x=width/2;
   ball_y=1;
   ball_vx=1;
   ball_vy=-1;
}

void show()
{
   gotoxy(0,0);
   for(int i=1;i<=high;i++)
   {
       for(int j=1;j<=width;j++)
       if(i==ball_y&&j==ball_x)
       printf("O");
       else 
       printf(" ");
       printf("\n");
   }
}

void updateWithoutInput()
{
   if(ball_x==width|ball_x==1)ball_vx=-ball_vx;
   if(ball_y==high-1||ball_y==1)ball_vy=-ball_vy;
   ball_x+=ball_vx;
   ball_y+=ball_vy;
}

void updateWithInput()
{
   
   
}

int main()
{
    setup();
    while(1)
    {
       show();
       updateWithInput();
       updateWithoutInput();
       Sleep(50);
    }
}