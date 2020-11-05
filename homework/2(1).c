#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a,b,c;
    scanf("%d%d",&a,&b);
    c=a%2?a+1:a+2;
    for(int i=a+1;i<b;i++)
    if(i%2==0)
    if(i!=c)printf(" %d",i);
    else printf("%d",i);
    system("pause");
}