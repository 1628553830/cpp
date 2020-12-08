#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<time.h>
//初始化游戏界面
#define High 25
#define Width 25

int cells[High][Width];

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
}

void updateWithoutInput()
{

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