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
   int a,b;
   while(cin>>a>>b)
   cout<<a*b/gcd(a,b)<<endl;
   cin.get();
   cin.get();
}