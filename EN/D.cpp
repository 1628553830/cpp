#include<iostream>
using namespace std;
int main()
{
    int n,ans=0,x;
    cin>>n;
    while(n)
   {

    for(int i=0;i<n;i++)
    {
        cin>>x;
        while(x)
        {
            x=x>=100?x-100:x>=50?x-50:x>=10?x-10:x>=5?x-5:x>=2?x-2:0;
            ans++;
        }
    }
    cout<<ans<<endl;
    ans=0;
    cin>>n;
   }
}