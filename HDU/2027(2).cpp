#include<bits/stdc++.h>
using namespace std;
int main()
{
   map<char,int>m;
   m.insert(pair<char,int>('a',0));
   m.insert(pair<char,int>('e',0));
   m.insert(pair<char,int>('i',0));
   m.insert(pair<char,int>('o',0));
   m.insert(pair<char,int>('u',0));
   int n;
   string a;
   cin>>n;
   cin.get();
   while(n--)
   {
      getline(cin,a);
      for(int i=0;i<a.length();i++)
        if(m.find(a[i])!=m.end())
           m[a[i]]++;
      cout<<"a:"<<m['a']<<endl;
      cout<<"e:"<<m['e']<<endl;
      cout<<"i:"<<m['i']<<endl;
      cout<<"o:"<<m['o']<<endl;
      cout<<"u:"<<m['u']<<endl;
      m['a']=m['e']=m['i']=m['o']=m['u']=0;
      if(n)cout<<endl;
   }
   cin.get();
}