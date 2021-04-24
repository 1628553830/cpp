#include<iostream>
using namespace std;
int main()
{
    short n,k,w[100],ans=0,t;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    cin>>w[i];
    for(int i=0;i<n&&w[i]<=k;i++)
    ans++;
    t=ans-1;
    for(int i=n-1;i>t&&w[i]<=k;i--)
    ans++;
    cout<<ans;
    cin.get();
    cin.get();
}
