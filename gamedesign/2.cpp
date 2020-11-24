//小球下落的动画
#include<stdio.h>
#include<stdlib.h>
void show(int,int);
int main()
{
    int x,y;
    scanf("%d%d",&x,&y);
    while(1)show(x,y);
    system("pause");
}
void show(int x,int y)
{
    for(int i=0;i<y;i++)
    {
        system("cls");
        for(int k=0;k<i;k++)
        printf("\n");
        for(int j=0;j<x;j++)
        printf(" ");
        printf("O");
        printf("\n");
    }
}