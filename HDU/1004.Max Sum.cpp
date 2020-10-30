#include<stdio.h>
#include<stdlib.h>
#include<climits>
int main()
{
    int n,m,max,sum,x,begin,end,mb,me;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&m);
        begin=end=sum=0;max=INT_MIN;
        for(int i=0;i<m;i++)
         {  
            end=i;
            scanf("%d",&x);
            sum+=x;
            if(max<sum){mb=begin;me=end;max=sum;}
            if(sum<0){begin=i+1;sum=0;}
         }
        printf("Case %d:\n",i);
        printf("%d %d %d\n",max,mb+1,me+1);
        if(i!=n)printf("\n");
    }
    system("pause");
    
}
