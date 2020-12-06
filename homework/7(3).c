#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void F(int*,char*,char);
int main()
{
  int a[1000]{};
  char ch,s[1000],b;
  ch=getchar();
  scanf("%s",s);
  F(a,s,ch);
  for(int i=0;a[i];i++)
  {
    if(i)
      printf(" %d",a[i]);
    else 
      printf("%d",a[i]);
  }
    system("pause");
}
void F(int *b,char *s,char a)
{
   int ans=0;
   for(int i=0;i<strlen(s);i++)
     {
       if(s[i]==a)
       b[ans++]=i+1;
     }
}