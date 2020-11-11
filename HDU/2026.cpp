#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a;bool flag=true;
    while(getline(cin,a))
    {
       for(int i=0;i<a.length();i++)
       {
          if(flag){a[i]=toupper(a[i]);flag=false;}
          if(a[i]==' ')flag=true;
       }
       cout<<a<<endl;
       flag=1;
    }
}