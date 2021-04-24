#include<iostream>
using namespace std;
int main()
{
    int t,s,num[100],sum=0;
    cin>>t;
    while (t--)
    {
        cin>>s;
        while(s--){int m;cin>>m;sum+=m;}
        if(t)cout<<sum<<endl<<endl;
        else cout<<sum<<endl;
        sum=0;
    }
    cin.get();
    cin.get();
}