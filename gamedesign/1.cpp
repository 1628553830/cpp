//显示固定坐标点的小球
#include<stdio.h>
#include<stdlib.h>
void show(int,int);
int main()
{
    int x,y;
    scanf("%d%d",&x,&y);
    show(x,y);
    system("pause");
}
void show(int x,int y)
{
    for(int i=0;i<x;i++)
    printf("\n");
    for(int i=0;i<y;i++)
    printf(" ");   
     printf("o");
     printf("\n");
}