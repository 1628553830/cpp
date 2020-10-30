#include<stdio.h>
int main()
{
    int a,b,n,f1,f2,fn,T;
    bool flag=false;
    scanf("%d%d%d",&a,&b,&n);
    while(a||b||n)
    {
        f1=f2=1;T=0;
        for(int i=3;i<=n;i++)
        {
            fn=(a*f2+b*f1)%7;
            f1=f2;f2=fn;
            if(!flag)T++;
            if(f1==1&&f2==1){flag=true;i=n-(n-1)%T+1;}
        }
        if(n>2)
        printf("%d\n",fn);
        else 
        printf("1\n");
        scanf("%d%d%d",&a,&b,&n);
        flag=false;
    }
}