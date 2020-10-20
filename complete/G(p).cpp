#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    string a;bool flag=true;
    while(cin>>a)
    {
    for(int i=0;i<a.length()/2;i++)
    if(a[i]!=a[a.length()-i-1]){cout<<"NO\n";flag=false;break;}
    if(flag)cout<<"YES\n";
    flag=true;
    }
}