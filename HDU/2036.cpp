#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    double zb[100][2],sum=0;
    cin>>n;
    cout.precision(1);
    while(n)
    {
        for(int i=0;i<n;i++)
        cin>>zb[i][0]>>zb[i][1];
        for(int i=0;i<n;i++)
        sum+=zb[i][0]*zb[(i+1)%n][1]-zb[(i+1)%n][0]*zb[i][1];
        sum/=2;
        cout<<fixed<<sum<<endl;
        cin>>n;
        sum=0;
    }
    cin.get();
    cin.get();
}