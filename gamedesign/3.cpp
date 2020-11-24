//小球下落的动画
#include<stdio.h>
#include<stdlib.h>
int speed=1;
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
    int m=0;
    while(1)
    {
        for(int i=0;i<y;i++)
        {
        system("cls");
        for(int k=0;k<m;k++)
        printf("\n");
        for(int j=0;j<x;j++)
        printf(" ");
        printf("O");
        printf("\n");
        m+=speed;
       // system("pause");
        }
        speed=-speed;
    }
}