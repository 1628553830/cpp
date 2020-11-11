#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
   char a[21],b[21],c[201];
   bool flag=true;
   gets(a);
   gets(b);
   gets(c);
   for(int i=0;i<strlen(c);i++)
       if(i<=strlen(c)-strlen(a))
       {
           for(int j=0;j<strlen(a);j++)
              if(c[i+j]!=a[j])break;
              else if(j==strlen(a)-1)
             {
                 flag=false;
                 printf("%s",b);
                 i+=strlen(a)-1;
             }
             if(flag)printf("%c",c[i]);
            flag=true;
       }
       else 
       printf("%c",c[i]);
    system("pause");

}