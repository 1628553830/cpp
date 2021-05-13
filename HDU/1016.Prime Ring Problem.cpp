#include<iostream>
#include<algorithm>
#include<cmath>
#include<string.h>
using namespace std;
struct T
{
    int nums[20];
    int cnt=0;
}primer[20];
int   n;
int   num[20];
bool  used[20];
bool  isprimer(int);
void  dfs(int);
void  show();
int   main()
{
     int count=1;
     num[0]=1;
     for(int i=1;i<20;i++)
     {
         for(int j=2-(i+1)%2;j<20;j+=2)
         {
             if(isprimer(j+i))
             {
                primer[i].nums[primer[i].cnt++]=j;
             }
         }
     }
     while(cin>>n)
     {
           memset(used,0,sizeof(used));
           used[1]=1;
           cout<<"Case "<<count<<":\n";
           dfs(2);
           cout<<endl;
           count++;
     }  
}
bool  isprimer(int x)
{
     for(int i=2;i<=sqrt(x);i++)
     {
          if(x%i==0)return false;
     }
     return true;
}
void  dfs(int step)
{
      for(int i=0;i<primer[num[step-2]].cnt&&primer[num[step-2]].nums[i]<=n;i++)
      {
          if(!used[primer[num[step-2]].nums[i]])
          {
              used[primer[num[step-2]].nums[i]]=1;
              num[step-1]=primer[num[step-2]].nums[i];
              if(step!=n)
              {
                  dfs(step+1);
              }
              else if(primer[primer[num[step-2]].nums[i]].nums[0]==1)
              {
                  show();
              }
              used[primer[num[step-2]].nums[i]]=0;
          }
      }
}
void  show()
{
      for(int i=0;i<n;i++)
      {
          if(i)cout<<" ";
          cout<<num[i];
      }
      cout<<endl;
}