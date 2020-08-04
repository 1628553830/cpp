#include<iostream>
#include<stdlib.h>
#include<cstring>
using namespace std;
int main()
{
    string s,a;
    int num;bool flag;
    cin>>s>>num;
    for(int i=0;i<num;i++)
    {   flag=true;
        for(int j=i;j<s.length();)
    {
       a+=s[j];
       j=i==0||i==num-1?j+(num-1)*2:flag?(num-i-1)*2+j:i*2+j;
       flag=!flag;
    }
    }
    cout<<a;
    system("pause");
    return 0;
    
    
}