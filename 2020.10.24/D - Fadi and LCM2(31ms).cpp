#include<bits/stdc++.h>
using namespace std;
int gcd(int m,int n)
{
    int r;
    while (m%n)
    {
        r=m%n;
        m=n;n=r;
    }
    return n; 
}
int main()
{
    long long x,t,m;
    cin>>x;
    t=sqrt(x);
    m=t*t==x?t-1:t;
    for(int i=m;i>0;i--)
    {
       if(x%i==0&&gcd(i,x/i)==1)
         {cout<<i<<" "<<x/i;break;}
    }
    if(x==1)cout<<1<<" "<<1;
    cin.get();
    cin.get();
} 
