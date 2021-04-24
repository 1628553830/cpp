#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n;
    n=n*8+1;
    m=sqrt(n);
    if(m*m==n)cout<<"YES";
    else cout<<"NO";
}