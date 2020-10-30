#include<stdio.h>
int main()
{
    int a,b,n,f[100]{0,1,1};
    bool flag=false;
    scanf("%d%d%d",&a,&b,&n);
    while(a||b||n)
    {
        for(int i=3;i<=n;i++)
        {
           f[i]=(f[i-2]*b+f[i-1]*a)%7;
           for(int j=2;j<=i-2;j++)
              if(f[i]==f[j]&&f[i-1]==f[j-1])
              {printf("%d\n",f[j-1+(n-i+1)%(i-j)]);flag=true;break;}
           if(flag)break;
        }
        if(!flag)printf("%d\n",f[n]);
        scanf("%d%d%d",&a,&b,&n);
        flag=false;
    }
}