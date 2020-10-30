#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a,b,n,f1=1,f2=1,fn;
    scanf("%d%d%d",&a,&b,&n);
    while(a||b||n)
    {
        for(int i=2;i<n;i++)
        {
           fn=(f2*a+f1*b)%7;
           f1=f2;f2=fn;
        }
        printf("%d\n",fn);
        scanf("%d%d%d",&a,&b,&n);
        f1=f2=1;
    }
    system("pause");
}