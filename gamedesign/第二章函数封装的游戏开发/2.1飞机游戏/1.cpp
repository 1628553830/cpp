#include<stdio.h>
#include<stdlib.h>
#include<conio.h>//°üº¬kbhit()ºÍgetch()º¯Êý

int position_x,position_y;
int high,width;

void startup()
{
    high=20;
    width=30;
    position_x=high/2;
    position_y=width/2;
}

void show()
{
    system("cls");
    for(int i=0;i<high;i++)
    {
        for(int j=0;j<width;j++)
        {
            if(i==position_y&&j==position_x)
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
    char input;
    if(kbhit())
    {
        input=getch();
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