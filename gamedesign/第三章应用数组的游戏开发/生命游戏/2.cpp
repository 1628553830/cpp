#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<time.h>
//初始化游戏界面
#define High 25
#define Width 25

int cells[High][Width];
int directions[8][2]{{-1,-1},{-1,0},{-1,1},{0,1},{0,-1},{1,1},{1,-1},{1,0}};

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
  for(int i=0;i<High;i++)
     for(int j=0;j<Width;j++)
     {
        cells[i][j]=rand()%2;
     }
}

void show()
{
  gotoxy(0,0);
  for(int i=0;i<High;i++)
    {
    for(int j=0;j<Width;j++)
    {
        if(cells[i][j])
        printf("*");
        else 
        printf(" ");
    }
     printf("\n");
    }
    //Sleep(50);
}

void updateWithoutInput()
{
   for(int i=0;i<High;i++)
   {
       for(int j=0;j<Width;j++)
       {
          int count=0;
          for(int k=0;k<8;k++)
          {
              if(i+directions[k][0]>=0&&i+directions[k][0]<High&&j+directions[k][1]>=0&&j+directions[k][1]<Width)
                if(cells[i+directions[k][0]][j+directions[k][1]])count++;
          }
          if(count==3)cells[i][j]=1;
          else if(count==2);
          else cells[i][j]=0;
       }
   }
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
     updateWithoutInput();
     updateWithInput();
  }
}