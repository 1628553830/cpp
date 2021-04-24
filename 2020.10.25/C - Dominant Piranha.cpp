#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,num[300000],max=0;
    bool flag=true;
    cin>>t;
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {scanf("%d",&num[i]);if(i&&num[i]!=num[i-1])flag=false;}
        for(int i=0;i<n;i++)
        {
        if(i&&n-1-i)
        {
            max=num[i]>=num[max]&&(num[i]>num[i-1]||num[i]>num[i+1])?i:max;
        }
        else if(i) max=num[n-1]>num[n-2]&&num[n-1]>num[max]?n-1:max;
        }
        if(flag)printf("-1\n");
        else printf("%d\n",max+1);
        flag=true;
        max=0;
    }
    cin.get();
    cin.get();
}