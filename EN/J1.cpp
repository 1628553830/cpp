#include<iostream>
using namespace std;
int main()
{
    string a;int ans=0;
    getline(cin,a);
    for(int i=0;i<a.length();i++)
    if(a[i]!=' ')ans++;
    else {if(ans)cout<<ans<<',';ans=0;}
    cout<<ans;
    cin.get();
    cin.get();
}