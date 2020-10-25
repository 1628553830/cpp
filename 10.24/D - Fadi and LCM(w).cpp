#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long x;
    long t,m;
    bool flag=true;
    cin>>x;
    t=sqrt(x);
    m=t*t==x?t-1:t;
    for(long i=m;i>0;i--)
    {
       if(x%i==0)
       {
           for(int j=2;j<=sqrt(i);j++)
           if(i%j==0&&(x/i)%j==0)
              flag=false;
           if(flag){cout<<i<<" "<<x/i;break;}
       }
       flag=true;
    }
    if(x==1)cout<<1<<" "<<1;
    cin.get();
    cin.get();
} 
