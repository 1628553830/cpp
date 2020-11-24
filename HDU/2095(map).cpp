#include<iostream>
#include<map>
using namespace std;
int main()
{
    int N,x;        
    map<int,int>m;
    cin>>N;
    while(N)
    {
        for(int i=0;i<N;i++)
        {
            scanf("%d",&x);
            if(m.find(x)==m.end())
            m.insert(pair<int,int>(x,1));
            else
            m[x]++;
        }
        map<int,int>::iterator it;
        for(it=m.begin();it!=m.end();it++)
        if((*it).second%2){cout<<(*it).first<<endl;break;}
        m.clear();
        cin>>N;
    }
}