#include<bits/stdc++.h>
using namespace std;
int num[2000000];
int main()
{
    int n,min,x;
    scanf("%d",&n);
    while(n)
    {
        for(int i=0;i<n;i++)scanf("%d",&num[i]);
        for(int i=0;i<n;i++)
        {
            min=i;
            for(int j=i+1;j<n;j++)
            if(num[min]>num[j])min=j;
            if(min!=i){x=num[min];num[min]=num[i];num[i]=x;}
            if(i!=n-1)printf("%d ",num[i]);
            else printf("%d\n",num[i]);
        }
        scanf("%d",&n);
    }
}