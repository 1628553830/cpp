#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    int n,lena,lenb,ans;
    char a[1001],b[1001];
    int sum[1002]{};
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%s%s",a,b);
        ans=0;
        lena=strlen(a);
        lenb=strlen(b);
        for(int i=lena-1,j=lenb-1;i>=0&&j>=0;i--,j--)
        {
            sum[ans]=sum[ans]+a[i]+b[j]-2*'0';
            sum[ans+1]+=sum[ans]/10;
            sum[ans]%=10;
            ans++;
        }
        if(lena<lenb)
        for(int i=lenb-lena-1;i>=0;i--)
        {
            sum[ans]=sum[ans]+b[i]-'0';
            sum[ans+1]+=sum[ans]/10;
            sum[ans]%=10;
            ans++;
        }
        else
        for(int i=lena-lenb-1;i>=0;i--)
        {
            sum[ans]=sum[ans]+a[i]-'0';
            sum[ans+1]+=sum[ans]/10;
            sum[ans]%=10;
            ans++;
        }
        if(sum[ans])ans++;
        printf("Case %d:\n%s + %s = ",i,a,b);
        for(int i=ans-1;i>=0;i--)
        printf("%d",sum[i]);
        if(i!=n)printf("\n\n");
        else printf("\n");
        ans=0;
        memset(sum,0,sizeof(sum));
    }
    system("pause");
}