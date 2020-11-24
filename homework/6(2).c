#include<stdio.h>
#include<stdlib.h>
long long C(int m,int n)
{
   long long r=1;
   for(int i=m;i>=m-n+1;i--)
   r*=i;
   for(int i=1;i<=n;i++)
   r/=i;
   return r;
}
int main()
{
   int m,n;
   scanf("%d %d",&m,&n);
   printf("%ld",C(m,n));
   system("pause");
}