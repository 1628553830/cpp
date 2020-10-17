#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    string s,a;
    while(getline(cin,s))
    {
       s+=" ";
       for(int i=0;i<s.length();i++)
       {
           if(s[i]!=' ')a+=s[i];
           else
           { 
           if(a=="you"){s=s.substr(0,i-3)+"we"+s.substr(i);i=i-1;}
           a="";
           }

       }
       cout<<s.substr(0,s.length()-1)<<endl;
    }

}