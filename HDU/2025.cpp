#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a;
    while(cin>>a)
    {
        char c=a[0];
        for(int i=0;i<a.length();i++)
            c=a[i]>c?a[i]:c;
        for(int i=0;i<a.length();i++)
                if(a[i]==c)
                {
                    a=a.substr(0,i+1)+"(max)"+a.substr(i+1);
                    i+=5;
                }
        cout<<a<<endl;
    }        
        
    
}