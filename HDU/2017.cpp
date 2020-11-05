#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a;int n,ans=0;
    cin>>n;
    while(n--)
    {
        
        cin>>a;
        for(int i=0;i<a.length();i++)if(isdigit(a[i]))ans++;
        cout<<ans<<endl;
        ans=0;
    }    
    cin.get();
    cin.get();
}