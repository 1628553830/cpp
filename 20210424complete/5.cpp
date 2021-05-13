#include<iostream>
#include<cmath>
using namespace std;
int C,G;
int position[20],weight[20];
int used[20]{};
int count=0;
bool flag=true;
void dfs(int);
bool check();
int main()
{
     cin>>C>>G;
     for(int i=0;i<C;i++)
     cin>>position[i];
     for(int i=0;i<G;i++)
     cin>>weight[i];
     dfs(0);
     cout<<count<<endl;
     cin.get();
     cin.get();
}
void dfs(int result)
{
     if(result==0&&check())
     {
          count++;
     }
     for(int i=0;i<C;i++)
     {
         for(int j=0;j<G;j++)
         {
             if(!used[weight[j]])
             {
                  used[weight[j]]=1;
                  result+=position[i]*weight[j];
                  dfs(result);
                  used[weight[j]]=0;
                  result-=position[i]*weight[j];
             }
         }
     }
}
bool  check()
{
     for(int i=0;i<G;i++)
     if(used[G])return 1;
     return 0;
}