#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,a[100],x,ans;
    cin>>n>>m;
    while(n||m)
    {
        ans=n;
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<m;i++)
        {
            cin>>x;
            for(int j=0;j<n;j++)
            {
                if(x==a[j])
                {
                    for(int k=j;k<n;k++)
                    a[k]=a[k+1];
                    ans--;
                    break;
                }
            }
        }
        if(!ans)cout<<"NULL";
        else 
        {
            sort(a,a+ans);
            for(int i=0;i<ans;i++)cout<<a[i]<<" ";
        }
        cout<<endl;
        cin>>n>>m;
    }
}