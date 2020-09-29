//高精度算法计算n！
#include<iostream>
#include<cstring>
using namespace std;
string gjd(string,string);
bool check(string,string);
string jw(string);
int main()
{
   string n,b="1";
   cin>>n;
   for(int i=0;i<n.length()/2;i++){char c;c=n[i];n[i]=n[n.length()-1-i];n[n.length()-1-i]=c;}
   for(string a="2";check(a,n);a=jw(a))
      b=gjd(a,b);

   for(int i=b.length()-1;i>=0;i--)cout<<b[i];
   cin.get();
   cin.get();
}
string gjd(string a,string b)
{
   string c;int jw=0,num;
   for(int i=0;i<a.length()+b.length();i++)c+='0';
   for(int i=0;i<a.length();i++)
   {
       jw=0;
       for(int j=0;j<b.length();j++)
       {
      num=c[i+j]-'0'+(a[i]-'0')*(b[j]-'0')+jw;
      jw=num/10;
      c[i+j]=num%10+'0';
       }
       if(jw)c[i+b.length()]=char(jw+'0');
   }
   if(c[a.length()+b.length()-1]=='0')return c.substr(0,a.length()+b.length()-1);
   else return c;
}
bool check(string a,string b)
{
   if(a.length()<b.length())return true;
   else if(a.length()>b.length())return false;
   else 
   {
       for(int i=a.length()-1;i>=0;i--)
       if(a[i]>b[i])return false;
       return true;
   }
}
string jw(string a)
{
   if(a[0]=='9')
   {
    a[0]='0';bool flag=true;
    for(int i=1;i<a.length()&&flag;i++)
    if(flag)
    if(a[i]=='9')a[i]='0';
    else {a[i]+=1;flag=false;}
    if(flag)a+='1';
   }
   else a[0]+=1;
   return a;
}