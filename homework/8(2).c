#include<stdlib.h>
#include<stdio.h>
void swap(int *x,int *y)
{
   int temp=*x;
   *x=*y;
   *y=temp;
}
int main()
{
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    if(a<b&&a<c)
       {if(b>c)swap(&b,&c);}
    else if(b<a&&b<c)
       { 
           swap(&a,&b);
           if(b>c)
               swap(&b,&c);
       }
    else if(a<b)
       {
           swap(&a,&c);
           swap(&b,&c);
       }
    printf("a=%d b=%d c=%d\n",a,b,c);
    system("pause");
}