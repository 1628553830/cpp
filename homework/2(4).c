#include<stdio.h>
#include<stdlib.h>
int main()
{
    for(int i=1;i<=7;i++)
    {
      if(i<=4)
      {
          for(int j=1;j<=4-i;j++)
          printf(" ");
          for(int j=1;j<=i*2-1;j++)
          printf("*");
          printf("\n");
      }
      else 
      {
          for(int j=1;j<=i-4;j++)
          printf(" ");
          for(int j=1;j<=(8-i)*2-1;j++)
          printf("*");
          printf("\n");
      }
    }
    system("pause");
}