#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a[20]={1,1};
    printf("1\n1\n");
    for(int i=2;i<20;i++)
    {
        a[i]=a[i-1]+a[i-2];
        printf("%d\n",a[i]);
    }
    system("pause");
}