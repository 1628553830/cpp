#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N,R;
    string a="";
    char *s="0123456789ABCDEF";
    while(cin>>N>>R)
    { 
        if(N<0)cout<<"-";
        while(N)
        {
           a=s[abs(N%R)]+a;
           N/=R;
        }
        cout<<a<<endl;
        a="";
    }
}