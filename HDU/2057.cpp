#include<iostream>
using namespace std;
const char* s="0123456789ABCDEF";
string P(string,string);
string M(string,string);
string T(string);
int main()
{
    string a,b;
    char a1,b1;
    while(cin>>a>>b)
    {
        if(a[0]=='-')a1='-';
        else a1='+';
        if(b[0]=='-')b1='-';
        else b1='+';
        a=isalnum(a[0])?a:a.substr(1);
        b=isalnum(b[0])?b:b.substr(1);
        a=T(a);
        b=T(b);
       if(a1==b1)
       {
        if(a1=='+')
        cout<<P(a,b);
        else 
        cout<<'-'<<P(a,b);
       }
       else 
      {
        if(a1=='+')cout<<M(a,b);
        else cout<<M(b,a);
      }
      cout<<endl;
    }
}
string P(string a,string b)
{
    if(a.length()<b.length())swap(a,b);
    string c;
    int x=0;
   for(int i=a.length()-1,j=b.length()-1;i>=0&&j>=0;i--,j--)
   {
       x+=isupper(a[i])?a[i]-'A'+10:a[i]-'0';
       x+=isupper(b[j])?b[j]-'A'+10:b[j]-'0';
       c=s[x%16]+c;
       x/=16;
   }
   for(int i=a.length()-b.length()-1;i>=0;i--)
   {
       x+=isupper(a[i])?a[i]-'A'+10:a[i]-'0';
       c=s[x%16]+c;
       x/=16;
   }
   if(x)c=s[x%16]+c;
   return c;
}
string M(string a,string b)
{
   string c;
   int x=0,a1,b1;
   if(a==b)return "0";
   for(int i=a.length()-1,j=b.length()-1;j>=0&&i>=0;j--,i--)
   {
       a1=isupper(a[i])?a[i]-'A'+10:a[i]-'0';
       b1=isupper(b[j])?b[j]-'A'+10:b[j]-'0';
       x+=a1-b1;
       if(i==0&&x<0)return '-'+M(b,a);
       c=s[(x+16)%16]+c;
       x=x<0?-1:0;
   }
   for(int i=a.length()-b.length()-1;i>=0;i--)
   {
      x+=isupper(a[i])?a[i]-'A'+10:a[i]-'0';
      c=s[(x+16)%16]+c;
      x=x<0?-1:0;
   }
   if(c[0]!='0')
   return c;
   else return c.substr(1);
}
string T(string a)
{
    for(int i=0;i<a.length();i++)
    a[i]=toupper(a[i]);
    return a;
}