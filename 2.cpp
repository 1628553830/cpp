#include<iostream>
using namespace std;
string numplus(string,string);
string zerogive(int);
int main()
{
    string a,b;
    while(1)
    {
        cin>>a>>b;
        cout<<numplus(a,b)<<endl;
    }
}
string numplus(string a,string b)
{
    bool flag=false;
    string result;
    if(a.size()<b.size())
       a=zerogive(b.size()-a.size())+a;
    else 
       b=zerogive(a.size()-b.size())+b;
    result+=zerogive(a.size());
    for(int i=a.size()-1;i>=0;i--)
    {
       result[i]=(a[i]+b[i]-2*'0'+flag)%10+'0';
       flag=(a[i]+b[i]-2*'0'+flag)/10;
    }
    if(flag)result="1"+result;
    return result;
}
string zerogive(int x)
{
    string a="";
    while(x--)
    {
        a+="0";
    }
    return a;
}