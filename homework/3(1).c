#include<stdio.h>
#include<stdlib.h>
int fx(int x)
{
    if(x<0&&x!=-3)return x*x+x+6;
    else if(0<=x&&x<10&&x!=2&&x!=3)return x*x-5*x+6;
    else return x*x-x-1;
}
int main()
{
    int x;scanf("%d",&x);
    printf("%d",fx(x));
    system("pause");
}