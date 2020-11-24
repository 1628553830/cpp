#include<bits/stdc++.h>
using namespace std;
struct note
{
    char name[11];
    int ac=0,time=0;
}datas[1000];
bool cmp(note a,note b)
{
    if(a.ac==b.ac)
        if(a.time==b.time)return a.name<b.name;
        else return a.time<b.time;
    else return a.ac>b.ac;
}
void T(string a,int b,int c)
{
   int x=0,y=0,i,j;
   if(!isalnum(a[0]))return;
   for(i=0;i<a.length()&&isalnum(a[i]);i++)
   x=x*10+a[i]-'0';
   for(j=i+1;j<a.length()&&isalnum(a[j]);j++)
   y=y*10+a[j]-'0';
   if(x+y)
   {
       datas[b].time+=x+y*c;
       datas[b].ac++;
   }
}
int main()
{
   int n,m,ans=0;
   string a;   
   cin>>n>>m;
   while(cin>>datas[ans].name)
   {
       for(int i=0;i<n;i++)
       {
           cin>>a;
           T(a,ans,m);
       }
       ans++;
   }
   sort(datas,datas+ans,cmp);
   for(int i=0;i<ans;i++)
   {
       printf("%-10s %2d %4d\n",datas[i].name,datas[i].ac,datas[i].time);
   }
}
