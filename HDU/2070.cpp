#include<iostream>
using namespace std;
int main()
{
    long long f[51]{0,1};
    int n;
    for(int i=2;i<=50;i++)
    f[i]=f[i-1]+f[i-2];
    cin>>n;
    while(n!=-1)
    {
        cout<<f[n]<<endl;
        cin>>n;
    }
    cin.get();
    cin.get();
}