#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>

int high,width;
int bird_x,bird_y;
int barl_x,barl_top,barl_down;

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
   Hidecursor()
   high=15;
   width=20;
   bird_x=width/3;
   bird_y=0;
   barl_x=width/2;
   barl_top=high/3;
   barl_down=high/2;
}

void show()
{
   gotoxy(0,0);
   for(int i=0;i<high;i++)
   {
       for(int j=0;j<width;j++)
       {
           if(i==bird_y&&j==bird_x)
              printf("@");
           else if(j==barl_x&&i<barl_top)
              printf("*");
           else if(j==barl_x&&i>barl_down)
              printf("*");
           else 
              printf(" ");
       }
       printf("\n");
   }
}

void updateWithoutInput()
{
   bird_y+1<high?bird_y++:bird_y;
   Sleep(150);
}

void updateWithInput()
{
   char c;
   if(kbhit())
   {
       c=getch();
       if(c==' ')
       bird_y=bird_y-2>=0?bird_y-2:bird_y;
   }
}

int main()
{
    setup();
    while(1)
    {
       show();
       updateWithoutInput();
       updateWithInput();
       Sleep(100);
    }
}