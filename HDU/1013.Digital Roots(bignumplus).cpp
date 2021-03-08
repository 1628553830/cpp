#include<iostream>
using namespace std;
string numplus(string,string);
string zerogive(int);
int main()
{
    string num,sum;
    cin>>num;
    while(num[0]!='0')
    {
        while(num.size()>1)
        {
            sum="0";
            while(num.size())
            {
               sum=numplus(sum,num.substr(num.size()-1,1));
               num=num.substr(0,num.size()-1);
            }
            num=sum;
        }
        cout<<num<<endl;
        cin>>num;
    }
    cin.get();
    cin.get();
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