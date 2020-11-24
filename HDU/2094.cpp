#include<iostream>
#include<map>
using namespace std;
int main()
{
    int N,total=0;
    string a,b;
    map<string,bool>c;
    cin>>N;
    while(N)
    {
       while(N--)
      {
        cin>>a>>b;
        if(c.find(a)==c.end())c.insert(pair<string,bool>(a,0));
        if(c.find(b)==c.end())c.insert(pair<string,bool>(b,1));
        else c[b]=1;
      }
      map<string,bool>::iterator it;
      for(it=c.begin();it!=c.end();it++)
      {
       if(total==2)break;
       if(!(*it).second)total++;
       }
      if(total==1)cout<<"Yes\n";
      else cout<<"No\n";
      c.clear();
      total=0;
      cin>>N;
    }
}
