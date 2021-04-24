#include<stdio.h>
int mod(int a,int b){return a-(a/b)*b;}
int main()
{
    int a,b;
    while(~scanf("%D%D",&a,&b))printf("%d\n",mod(a,b));
}