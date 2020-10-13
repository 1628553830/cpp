#include<bits/stdc++.h>
using namespace std;
bool c[10]{};
int check(char s)
{
    if(s=='L')
    {
        int count=-1;
        while(c[++count]){}
        return count;
    }
    else 
    {
        int count=10;
        while(c[--count]){}
        return count;
    }
}
int main()
{
    int n;string a;
    cin>>n>>a;
    for(int i=0;i<a.length();i++)
     {
         if(a[i]=='L')c[check('L')]=true;
         else if(a[i]=='R')c[check('R')]=true;
         else c[a[i]-'0']=false;
     }
    for(int i=0;i<10;i++)
    cout<<c[i];
    cin.get();
    cin.get();    
}