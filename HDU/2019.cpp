#include<bits/stdc++.h>
using namespace std;
int main()
{
    int num[101],n,m;
    cin>>n>>m;
    while(n||m)
    {
        for(int i=0;i<n;i++)cin>>num[i];
        num[n]=m;
        sort(num,num+n+1);
        for(int i=0;i<=n;i++)if(!i)cout<<num[i];else cout<<" "<<num[i];
        cout<<endl;
        cin>>n>>m;
    }
}