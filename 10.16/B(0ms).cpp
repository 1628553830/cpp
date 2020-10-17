#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,a,b;scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%D",&a,&b);
        a%=100;
        b%=100;
        printf("%d\n",(a+b)%100);
    }
    system("pause");

}