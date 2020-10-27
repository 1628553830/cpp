#include<bits/stdc++.h>
using namespace std;
int num[2000000];
int main()
{
    int n;
    scanf("%d",&n);
    while(n)
    {
        for(int i=0;i<n;i++)scanf("%d",&num[i]);
        sort(num,num+n);
        for(int i=0;i<n;i++)if(i!=n-1)printf("%d ",num[i]);else printf("%d\n",num[i]);
        scanf("%d",&n);
    }
}