#include<iostream>
using namespace std;
int ans=0;
void dfs(int x)
{
   if(x==1||x==0){ans++;return;}
   for(int i=1;i<=2;i++)
        dfs(x-i);
    return;
}
int main()
{
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        dfs(x-1);
        cout<<ans<<endl;
        ans=0;
    }
    cin.get();
    cin.get();
}