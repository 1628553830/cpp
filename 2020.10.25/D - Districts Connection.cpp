#include<bits/stdc++.h>
using namespace std;
int main()
{
    
    int t,n,num[5000],ans=0;
    cin>>t;
    while(t--)
    {
        pair<int,int>connect[4999]{};
        cin>>n;
        for(int i=0;i<n;i++)
        cin>>num[i];
        for(int i=1;i<n;i++)
        if(num[i]!=num[0])connect[ans++]=make_pair(1,i+1);
        for(int i=1;i<n;i++)
        if(num[i]==num[0]&&connect[0].second)connect[ans++]=make_pair(connect[0].second,i+1);
        if(ans==n-1)
        {
            cout<<"YES\n";
            for(int i=0;i<ans;i++)
               cout<<connect[i].first<<" "<<connect[i].second<<endl;
        }
        else cout<<"NO\n";
        ans=0;
    }
    cin.get();
    cin.get();
}