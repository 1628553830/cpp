#include<stdio.h>
#include<stdlib.h>
int main()
{
   char a[1000];
   int total=0;
   while(~scanf("%s",a))
   {
      total++;
   }
   printf("%d\n",total);
   system("pause");
}