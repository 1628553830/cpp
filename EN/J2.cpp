#include<iostream>
using namespace std;
string n(int a)
{
    string b;char c;
    while(a)
    {
        c=a%10+'0';
        a/=10;
        b=c+b;
    }
    return b;
}
int main()
{
    string a,b;char c;
    while(cin>>a)
      b+=n(a.length())+','; 
    cout<<b.substr(0,b.length()-1);
}