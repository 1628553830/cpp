#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a,sum=3;
    cin>>n;
    while(n--)
    {
        cin>>a;
        while(a--)
            sum=(sum-1)*2;
        cout<<sum<<endl;
        sum=3;
    }
    cin.get();
    cin.get();
}