#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a,x;
    map<string,bool>m;
    getline(cin,a);
    while(a!="#")
    {
        a+=" ";
        for(int i=0;i<a.length();i++)
        {
           while(a[i]!=' ')
           {
               x+=a[i++];
           }
           if(x!="")
            {m[x]=1;x="";}
        }   
        cout<<m.size()<<endl;
        m.clear();
        getline(cin,a);
    }
    cin.get();
    cin.get();
}