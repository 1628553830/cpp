#include<iostream>
#include<string.h>
using namespace std;
int num[21]{},a;
long long b;
bool used[21]{};
void dfs(int,int);
int main()
{
   while(cin>>a>>b)
   {
       dfs(1,a);
       for(int i=1;num[i];i++)
          if(i-1)cout<<" "<<num[i];
          else cout<<num[i];
       cout<<endl;
       memset(used,0,sizeof(used));
       memset(num,0,sizeof(num));
   }
}
void dfs(int ans,int n)
{
    if(ans>n||!b)return;
    for(int i=1;i<=n;i++)
        if(!used[i])
        {
            b--;
            num[ans]=i;
            used[i]=true;
            dfs(ans+1,n);
            if(!b)return;
            used[i]=false;
            num[ans]=0;
        }
}
