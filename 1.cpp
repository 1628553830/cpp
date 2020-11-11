#include<bits/stdc++.h>
using namespace std;
bool check(string a,string b)
{
    for(int i=0;i<a.length();i++)a[i]=toupper(a[i]);
    for(int i=0;i<b.length();i++)b[i]=toupper(b[i]);
    return a==b;
}
int main()
{
    string a,b,c;
    getline(cin,a);
    getline(cin,b);
    getline(cin,c);
    for(int i=0;i<c.length();i++)
    if(i<a.length()-c.length()&&check(a,c.substr(i,a.length())))
    {
        cout<<b;i+=a.length()-1;
    }
    else cout<<c[i];
    cin.get();
    cin.get();
}