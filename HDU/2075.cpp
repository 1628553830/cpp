#include<iostream>
#include<cmath>
using namespace std;
int main()
{
   int a,b,T;
   cin>>T;
   while(T--)
   {
       cin>>a>>b;
       if(a%b==0)cout<<"YES\n";
       else cout<<"NO\n";
   }
   cin.get();
   cin.get();
}