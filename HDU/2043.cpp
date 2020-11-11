#include<bits/stdc++.h>
using namespace std;
const char*s="~!@#$%^";
bool isstring(char a)
{
   for(int i=0;i<7;i++)
   if(a==s[i])return true;
   return false;
}
int main()
{
    string b;
    bool c[4]{};
    int n,ans=0;cin>>n;
    while(n--)
    {
        cin>>b;
        if(b.length()<8||b.length()>16)goto x;
        for(int i=0;i<b.length();i++)
        if(isdigit(b[i])&&!c[2]){c[2]=true;ans++;}
        else if(islower(b[i])&&!c[1]){c[1]=true;ans++;}
        else if(isupper(b[i])&&!c[0]){c[0]=true;ans++;}
        else if(isstring(b[i])&&!c[3]){c[3]=true;ans++;}
        if(ans>=3)cout<<"YES\n";
        else 
x:        cout<<"NO\n";
        memset(c,0,sizeof(c));
        ans=0;
    }
    cin.get();
    cin.get();
}