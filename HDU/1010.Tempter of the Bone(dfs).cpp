#include<iostream>
using namespace std;    
int  d[4][2]={{0,1},{1,0},{-1,0},{0,-1}}; 
int  N,M,T,sx,sy,dx,dy;
char maze[6][6];
bool used[6][6];
bool flag;
void dfs(int,int,int);

int  main()
{
     cin>>N>>M>>T;
     while(N||M||T)
     {
         flag=false;
         for(int i=0;i<7;i++)
         for(int j=0;j<7;j++)
         {
             used[i][j]=false;
         }
         for(int i=0;i<N;i++)
         for(int j=0;j<M;j++)
         {
             cin>>maze[i][j];
             if(maze[i][j]=='S'){sx=j;sy=i;used[i][j]=true;}
             else if(maze[i][j]=='D'){dx=j;dy=i;}
             else if(maze[i][j]=='X')used[i][j]=true;
         }
         dfs(sx,sy,0);
         if(flag)cout<<"YES\n";
         else cout<<"NO\n";
         cin>>N>>M>>T;
     }
}

void dfs(int x,int y,int step)
{
     int mx,my;
     if(step==T)
     {
        if(x==dx&&y==dy)flag=true;
        return;
     }
     if((T-step-abs(dx-x)-abs(dy-y))%2||T-step-abs(dx-x)-abs(dy-y)<0)                //ÆæÅ¼¼ôÖ¦ 
     return;
     for(int i=0;i<4&&!flag;i++)
     {
         mx=x+d[i][0];
         my=y+d[i][1];     
         if(mx<M&&mx>=0&&my<N&&my>=0&&!used[my][mx])
         {
             used[my][mx]=true;
             dfs(mx,my,step+1);
             used[my][mx]=false;
         }
     }
}