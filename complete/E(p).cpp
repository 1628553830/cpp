#include<iostream>
using namespace std;
int main()
{
    long long n,a,b,x,s,rest;//注意数据范围
    cin>>n;
    while(n--)
    {
      cin>>a>>b>>x>>s;
      if(a*x+b==s)cout<<"YES\n";
      else if(a*x+b<s)cout<<"NO\n";
      else 
      {
          rest=s/x>a?s-x*a:s-s/x*x;
          if(rest<=b)cout<<"YES\n";
          else cout<<"NO\n";
      }
    }
    cin.get();
    cin.get();
}