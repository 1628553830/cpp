#include<iostream>
#include<string.h>
using namespace std;
struct 
{
    int num[500],ans=0;
}girl[501];
int boy[500]{};
bool visit[501]{};
bool find(int);
int main()
{
    int K,M,N,x,total=0;
    cin>>K;
    while(K)
    {
        cin>>M>>N;
        for(int i=0;i<K;i++)cin>>x>>girl[x].num[girl[x].ans++];
        for(int i=1;i<=M;i++)
        {            
            memset(visit,0,sizeof(visit));
            if(find(i))total++;
        }
        cout<<total<<endl;
        for(int i=1;i<=M;i++)
        girl[i].ans=0;
        memset(boy,0,sizeof(boy));

        total=0;
        cin>>K;
    }
    cin.get();
    cin.get();
}
bool find(int x)
{
   for(int i=0;i<girl[x].ans;i++)
   if(!boy[girl[x].num[i]])
   {
       visit[girl[x].num[i]]=1;
       boy[girl[x].num[i]]=x;
       return true;
   }
   else if(!visit[girl[x].num[i]])
   {
       int t=boy[girl[x].num[i]];
       visit[girl[x].num[i]]=1;
       boy[girl[x].num[i]]=x;
       if(find(t))return true;
       boy[girl[x].num[i]]=t;
       visit[girl[x].num[i]]=0;
   }
   return false;
}
