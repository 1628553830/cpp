#include<bits/stdc++.h>
using namespace std;   
bool used[21]{};
int find(int);
int main()
{
   long long num[21]{0,1},m;
   int n;
   for(int i=2;i<=20;i++)
       num[i]=(num[i-1]+1)*i;
   while(cin>>n>>m)
   {
       for(int i=1;m;i++)
       {
           if(i!=1)cout<<" ";
           cout<<find((m-1)/(num[n]/n)+1);
           if(m!=1)
           m=(m-1)%(num[n]/n);
           else m=0;
           n--;
       }
       memset(used,0,sizeof(used));
       cout<<endl;
   }
}
int find(int x)
{
    int i;
    for(i=1;;i++)
    if(!used[i]){x--;if(!x)break;}
    used[i]=1;
    return i;
}
/*
1 2 3 4
1 
1 2 
1 2 3
1 2 3 4
1 2 4 
1 2 4 3
1 3 
1 3 2
1 3 2 4
1 3 4 
1 3 4 2

1 
1 2 
2
2 1
*/


