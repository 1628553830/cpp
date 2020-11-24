//斜向运动的小球
#include<stdio.h>
#include<stdlib.h>
void show(int,int,int,int,int,int);
int main()
{
   int x,y;
   int high=0,bottom=20,left=0,right=20;   
   scanf("%d%d",&x,&y);
   show(x,y,high,bottom,left,right);
}
void show(int x,int y,int high,int bottom,int left,int right)
{
    int velocity_x=1,velocity_y=1;
    while(1)
    {
             system("cls");
             for(int i=0;i<y;i++)
             printf("\n");
             for(int j=0;j<x;j++)
             printf(" ");
             printf("O");
             if(x==left||x==right)velocity_x=-velocity_x;
             if(y==high||y==bottom)velocity_y=-velocity_y;
             x+=velocity_x;
             y+=velocity_y;
             system("pause");
    }
}