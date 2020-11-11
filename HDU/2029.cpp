#include<iostream>
using namespace std;
bool check(string a)
{
    for(int i=0;i<a.length()/2;i++)
        if(a[i]!=a[a.length()-i-1])return false;
    return true;
}
int main()
{
   int n;
   string a;
   cin>>n;
   while(n--)
   {
       cin>>a;
       if(check(a))cout<<"yes\n";
       else cout<<"no\n";
   }
   cin.get();
   cin.get();
}