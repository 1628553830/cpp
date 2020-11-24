#include<iostream>
#include<string.h>
using namespace std;
int total=0,course[9]{};
void dfs(int,int);
int main()
{
    int T,N,K;
    cin>>T;
    while(T--)
    {
        cin>>N>>K;
        for(int i=1;i<=K;i++)
        {
            int x,y;cin>>x>>y;
            course[x]=y;
        }
        dfs(N,1);
        cout<<total<<endl;
        memset(course,0,sizeof(course));
        total=0;
    }
    cin.get();
    cin.get();
}
void dfs(int sum,int a)
{
    for(int i=a;i<=8&&sum-i>=0;i++)
    {
        if(course[i])
        {
            course[i]--;
            if(sum-i==0)total++;
            else if(sum-i>0)dfs(sum-i,i);
            course[i]++;
        }
    }
    return;
}
