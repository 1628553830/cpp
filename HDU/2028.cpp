#include<iostream>
using namespace std;
int gcd(int m,int n)
{
   int r;
   while(m%n)
   {
       r=m%n;
       m=n;n=r;
   }
   return n;
}
int main()
{
    long long n,x=1,t;
    while (cin>>n)
    {
        while(n--)
        {
            cin>>t;
            x=x*t/gcd(x,t);
        }
        cout<<x<<endl;
        x=1;
    }
    
}