#include<iostream>
#include<cctype>
using namespace std;
int main()
{
   int T,t;char c;
   cin>>T;
   while(T--)
   {
       cin>>c>>t;
       if(isupper(c))cout<<c-'A'+1+t<<endl;
       else cout<<'a'-c-1+t<<endl;
   }
   cin.get();
   cin.get();
}