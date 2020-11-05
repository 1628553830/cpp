#include<bits/stdc++.h>
using namespace std;
string chuli(string a)
{
    bool flag=true;
    int begin=0,end=a.length()-1,xx=a.length()-1;
    while(a[begin]=='0'&&begin<a.length())begin++;
    while((a[end]=='0'||a[end]=='.')&&end>0&&flag)//这里要注意是否过头 10 10.00是特殊情况,flag来判断是否过头
        {
            if(a[end]=='.')flag=false;
            end--; 
        }
    while(a[xx]!='.'&&xx>0)xx--;
    if(!xx)end=a.length()-1;//这里要注意小数点
    a=a.substr(begin,end-begin+1);
    return a;
}
int main()
{
    string a,b;
    while(cin>>a>>b)
    {
        if(chuli(a)==chuli(b))cout<<"YES\n";
        else cout<<"NO\n";
    }
}