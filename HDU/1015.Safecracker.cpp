#include<iostream>
#include<algorithm>
#include<string.h>
#include<cmath>
using namespace std;
int  length;
int  target;
int  nums[26];
bool used[26];
bool flag;
string s;
void dfs(int,int);
int  main()
{
      while((cin>>target>>s)&&target)
      {
          sort(s.begin(),s.end());          
          length=s.length();
          for(int i=0;i<length;i++)
          {
              nums[i]=s[i]-'A'+1;
          }
          memset(used,0,sizeof(used));
          flag=false;
          dfs(1,0);
          if(flag)
          {
              cout<<s<<endl;
          }
          else
          {
              cout<<"no solution"<<endl;
          }
      }
}
void dfs(int step,int present)
{
     for(int i=length-1;i>=0&&!flag;i--)
     {
          if(!used[nums[i]-1])
          {
              used[nums[i]-1]=1;
              present+=((step%2)*2-1)*pow(nums[i],step);
              if(step!=5)
              {
                  dfs(step+1,present);
              }
              else if(present==target)
              {
                  flag=true;
                  s="";
                  s=(char)('A'+nums[i]-1)+s;
                  return;
              }
              if(flag)
              {
                  s=(char)('A'+nums[i]-1)+s;
                  return;
              }
              used[nums[i]-1]=0;
              present-=((step%2)*2-1)*pow(nums[i],step);

          }
     }
}