#include<iostream>
#include<stdlib.h>
#include<cstring>
using namespace std;
int main()
{
    string a,b;int i,j;
    cin>>a>>b;
    if(!a.length()&&a.length()==b.length()){cout<<true;system("pause");return 0;}//a和b都为空字符串
    for(i=0,j=0;i<a.length()&&j<b.length();i++,j++)
        if(a[i]!=b[j])
            if(b[j]=='*'&&j&&b[j-1]==a[i])
            {
               while(a[i]==a[i-1])i++;
               i--;
            }
            else if(b[j]=='.')b[j]=a[i];
            else {cout<<false;system("pause");return 0;}
    
    if(i==a.length()&&j==b.length())
    {
    cout<<true;
    system("pause");
    return 0;
    }
    else
    {
    cout<<false;
    system("pause");
    return 0;
    }
}