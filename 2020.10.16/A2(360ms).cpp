#include<stdio.h>
int main()
{
    int a,b;
    while(~scanf("%D%D",&a,&b))printf("%d\n",a-(a/b)*b);
}