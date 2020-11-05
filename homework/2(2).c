#include<stdio.h>
#include<stdlib.h>
int main()
{
    int s=0;
    for(int i=1;i<=4;i++)
    s=i%2?s+i:s-i;
    printf("%d",s);
    system("pause");
}