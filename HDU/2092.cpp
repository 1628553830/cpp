#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n,m;
    bool flag=true;
    cin>>n>>m;
    while(n||m)
    {
        for(int i=-sqrt(abs(m));i<=sqrt(abs(m));i++)
            if(i&&m%i==0&&i+m/i==n){cout<<"Yes\n";flag=false;break;}
        if(flag)cout<<"No\n";   
        flag=true; 
        cin>>n>>m;
    }
}