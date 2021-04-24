#include<iostream>
using namespace std;
int main()
{
    int n,x,len;
    cin>>n;
    while(n--)
    {
       cin>>x;
       len=x/10?x/100?x/1000?4:3:2:1;
       cout<<(x%10-1)*10+(len+1)*len/2<<endl;
    }
    cin.get();
    cin.get();
}