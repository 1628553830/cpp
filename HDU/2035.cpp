#include<iostream>
using namespace std;
int main()
{
    int a,b,c;cin>>a>>b;
    while(a||b)
    {
        c=1;
        while(b--)
       {
       c=c*a;
       c%=1000;
       }
       cout<<c%1000<<endl;
       cin>>a>>b;
    }
}