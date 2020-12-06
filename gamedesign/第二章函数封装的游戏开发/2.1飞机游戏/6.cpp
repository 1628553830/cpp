#include<stdio.h>
#include<stdlib.h>
#include<conio.h>//包含kbhit()和getch()函数
#include<windows.h>
int bullet_x,bullet_y;//子弹坐标
int position_x,position_y;//飞机坐标
int enemy_x,enemy_y;//敌机坐标
int high,width;//画面尺寸
int score;//得分

void Hidecursor()
{
    CONSOLE_CURSOR_INFO cursor_info={1,0};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cursor_info);
}
void gotoxy(int x,int y)
{
    HANDLE handle=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X=x;
    pos.Y=y;
    SetConsoleCursorPosition(handle,pos);
}
void startup()
{
    Hidecursor();
    high=20;
    width=30;
    position_x=high/2;
    position_y=width/2;
    bullet_x=position_x;
    bullet_y=-2;
    enemy_x=position_x;
    enemy_y=-1;//防止在屏幕外打中
    score=0;
}

void show()
{
    gotoxy(0,0);
    for(int i=0;i<high;i++)
    {
        for(int j=0;j<width;j++)
        {
            if(i==position_y&&j==position_x)
            printf("*");
            else if(i==bullet_y&&j==bullet_x)
            printf("|");
            else if(i==enemy_y&&j==enemy_x)
            printf("@");
            else 
            printf(" ");
        }
        printf("\n");
    }
    printf("得分：%d\n",score);
}

void updateWithoutInput()
{
    if(bullet_y>=0)
    bullet_y--;
    static int speed=0;
    if(enemy_y==bullet_y&&enemy_x==bullet_x)
    {
        score++;
        enemy_y=-1;
        enemy_x=rand()%width;
        bullet_y=-2;
    }
    if(enemy_y>high)
    {
        enemy_y=-1;
        enemy_x=rand()%width;
    }
    if(speed<10)
       speed++;
    else 
    {
       enemy_y++;
       speed=0; 
    }
}
void updateWithInput()
{
        char input;
        if(kbhit())
        {
        input=getch();//等待输入
        switch(input)
        {
            case 'a':
            case 'A':position_x--;
            break;
            case 's':
            case 'S':position_y++;
            break;
            case 'd':
            case 'D':position_x++;
            break;
            case 'w':
            case 'W':position_y--;
            break;
            case ' ':{bullet_y=position_y-1;bullet_x=position_x;}
            break;
        }
        }
}

int main()
{
    startup();
    while(1)
    {        
        show();
        updateWithoutInput();
        updateWithInput();
    }
    return 0;
}