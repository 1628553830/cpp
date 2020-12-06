#include<iostream>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
//描绘挡板,反弹小球
int ball_x,ball_y;//球的坐标
int ball_vx,ball_vy;//球的方向
int target_x,target_y;//目标的坐标
int width,high;//画面尺寸
int dangban_y,ridus,dangban_centre;

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
   dangban_y=high-1;
   dangban_centre=width/2;
   ridus=5;
}

void show()
{
   gotoxy(0,0);
   for(int i=0;i<=high;i++)
   {
       for(int j=0;j<=width;j++)
       if(i==ball_y&&j==ball_x)
       printf("O");
       else if(j==width)
       printf("|");
       else if(i==high)
       printf("-");
       else if(i==dangban_y&&j>=dangban_centre-ridus&&j<=dangban_centre+ridus)
       printf("*");
       else 
       printf(" ");
       printf("\n");
   }
}

void updateWithoutInput()
{
   if(ball_x==width-1||ball_x==0)ball_vx=-ball_vx;
   if(ball_y==dangban_y-1&&ball_x<=dangban_centre+ridus&&ball_x>=dangban_centre-ridus)ball_vy=-ball_vy;
   if((ball_x==dangban_centre-ridus-1||ball_x==dangban_centre+ridus+1)&&ball_y==dangban_y)ball_vx=-ball_vx;
   if((ball_x+ball_vx==dangban_centre-ridus||ball_x+ball_vx==dangban_centre+ridus)&&ball_y+ball_vy==dangban_y)
   {ball_vy=-ball_vy;ball_vx=-ball_vx;}//碰到边界
   if(ball_y==high-1||ball_y==0)ball_vy=-ball_vy;
   ball_x+=ball_vx;
   ball_y+=ball_vy;
}

void updateWithInput()
{
   if(kbhit())
   {
       char c;
       c=getch();
       switch(c)
       {
           case 'a':
           case 'A':dangban_centre-ridus-1>=0?dangban_centre--:dangban_centre;
           break;
           case 'd':
           case 'D':dangban_centre+ridus+1<width?dangban_centre++:dangban_centre;
           break;
       }
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
       Sleep(100);
    }
}