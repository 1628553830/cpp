#include<bits/stdc++.h>
using namespace std;
int main()
{
    map<string,int>m;//map可以把字符串当作下标
    string s,maxs;
    int n,max=0;scanf("%d",&n);
    while(n)
    {
        while(n--)
        {
            scanf("%s",s);
            if(m.find(s)!=m.end())
            { 
                m[s]=m[s]+1;
                if(max<m[s]){max=m[s];maxs=s;}//count有就返回1，没有就返回0，此处不能用a.count(xxxxx)
            }
            else 
            {
                m.insert(pair<string,int>(s,1));
                if(max<m[s]){max=m[s];maxs=s;}
            }
        }
        max=0;m.clear(); 
        printf("%s\n",maxs);
        scanf("%d",&n);
    }
    cin.get();
    cin.get();
}
  