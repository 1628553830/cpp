#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<stdio.h>

#define High 15
#define Width 20

int dangban_centre,ridus,dangban_y;
int zk[High-1][Width]{};
int ball_x,ball_y;
int ball_vx,ball_vy;
int speed;
int score;

void add()
{
    for(int i=High-2;i>=1;i--)
    for(int j=0;j<Width;j++)
    {
        zk[i][j]=zk[i-1][j];
    }
    for(int i=0;i<Width;i++)
    zk[0][i]=1;
}

bool check()
{
   if(ball_y==dangban_y)return true;
   for(int i=0;i<Width;i++)
   if(zk[High-3][i])return true;
   return false;
}

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
    speed=10;
    score=0;
    ball_x=Width/2;
    ball_y=High/2;
    ball_vx=1;
    ball_vy=1;
    dangban_centre=Width/2;
    dangban_y=High-1;
    ridus=5;
    for(int i=0;i<3;i++)
    for(int j=0;j<Width;j++)
    {
        zk[i][j]=1;
    }
}

void show()
{
   gotoxy(0,0);
   for(int i=0;i<=High;i++)
   {
       for(int j=0;j<=Width;j++)
       {
           if(i<=High-4&&j<Width&&zk[i][j])
           printf("#");
           else if(j==Width)
           printf("|");
           else if(i==High)
           printf("-");
           else if(i==ball_y&&j==ball_x)
           printf("0");
           else if(i==dangban_y&&j<=dangban_centre+ridus&&j>=dangban_centre-ridus)
           printf("*");
           else 
           printf(" ");
       }
       printf("\n");
   }
   printf("当前得分：%d",score);
   Sleep(100);
   //system("pause");
}

void updateWithoutInput()
{
   static int ans=0;
   if(score-ans==speed)
   {
       ans=score;
       add();
   }
   
   if(check())
   {
       printf("游戏失败！\n");
       system("pause");
       exit(0);
   }

   if(zk[ball_y-1][ball_x]&&ball_vy==-1)
   {
       ball_vy=1;
       zk[ball_y-1][ball_x]=0;
       score++;
   }
   else if(ball_y+ball_vy<High-1&&zk[ball_y+ball_vy][ball_x+ball_vx])
   {
       zk[ball_y+ball_vy][ball_x+ball_vx]=0;
       ball_vy=-ball_vy;
       ball_vx=-ball_vx;
       score++;
   }

   if(ball_x==0||ball_x==Width-1)
   {
       ball_vx=-ball_vx;
   }
   if(ball_y==0||ball_y==High-1)
   {
       ball_vy=-ball_vy;
   }


   if(ball_y==dangban_y-1&&ball_x>=dangban_centre-ridus&&ball_x<=dangban_centre+ridus)
   {
       ball_vy=-1;
   }
   else if(ball_y==dangban_y-1&&(ball_x+ball_vx==dangban_centre-ridus||ball_x+ball_vx==dangban_centre+ridus))
   {
       ball_vy=-ball_vy;
       ball_vx=-ball_vx;
   }

   ball_x=ball_x+ball_vx<Width&&ball_x+ball_vx>=0?ball_x+ball_vx:ball_x;
   ball_y+=ball_vy;

   if(zk[ball_y][ball_x])
   {
       score++;
       zk[ball_y][ball_x]=0;
   }
   
}

void updateWithInput()
{
   if(kbhit())
   {
       char c;
       c=getch();
       switch (c)
       {
       case 'a':
       case 'A':dangban_centre-ridus-1>=0?dangban_centre--:1;
               break;
       case 'd':
       case 'D':dangban_centre+ridus+1<Width?dangban_centre++:1;
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
  }
}
