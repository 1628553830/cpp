#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,a[100],c[100],x,ans;
    bool b[100]{};
    cin>>n>>m;
    while(n||m)
    {
        ans=n;
        for(int i=0;i<n;i++){cin>>a[i];b[i]=1;}
        for(int i=0;i<m;i++)
        {
            cin>>x;
            for(int j=0;j<n&&ans;j++)if(x==a[j]){ans--;b[j]=0;break;}
        }
        if(!ans)cout<<"NULL";
        else 
        {
            for(int i=0,j=0;i<n;i++)if(b[i])c[j++]=a[i];
            sort(c,c+ans);
            for(int i=0;i<ans;i++)
            cout<<c[i]<<" ";
        }
        cout<<endl;
        cin>>n>>m;
    }
}