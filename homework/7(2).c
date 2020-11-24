#include<stdio.h>
#include<stdlib.h>
int t[5][5];
void f1()
{
  for(int i=0;i<5;i++)
  t[i][i]=1;
}
void f2()
{
   for(int i=0;i<5;i++)
   for(int j=i+1;j<5;j++)
   {
       t[i][j]=t[i][j-1]+1;
       t[j][i]=t[i][j];
   }
}
int main()
{
    f1();
    f2();
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        printf("%d",t[i][j]);
        printf("\n");
    }
    system("pause");
}