#include<stdio.h>
int main()
{
  int n,num,sum=0,s;
  scanf("%d",&n);
  for(int i=0;i<n;i++)
{
scanf("%d",&num);
for(int j=0;j<num;j++)
{scanf("%d",&s);sum+=s;}
printf("%d\n",sum);
sum=0;

}

}