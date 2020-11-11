#include<iostream>
using namespace std;
string transfer(int a)
{
    string b;
    while(a)
    {
        b=char(a%2+'0')+b;
        a/=2;
    }
    return b;
}
int main()
{
   int n;
   while(cin>>n)
   cout<<transfer(n)<<endl;
}