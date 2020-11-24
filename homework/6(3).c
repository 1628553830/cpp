#include<stdio.h>
#include<stdlib.h>
int main()
{
   char c,a[1000],ans=0;
   while((c=getchar())!='#')
   {
      a[ans++]=c<97?c+32:c;
   }
   a[ans]='\0';
   printf("%s\n",a);
   system("pause");
}