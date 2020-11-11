#include<bits/stdc++.h>
using namespace std;
struct T
{
  int b,e;  
}num[100];
bool cmp(T a,T b)
{
    return a.e<b.e; 
}
int main()
{
   int n,ans=1,end;
   cin>>n;
   while(n)
   {
       for(int i=0;i<n;i++)
       cin>>num[i].b>>num[i].e;
       sort(num,num+n,cmp);
       end=num[0].e;
       for(int i=1;i<n;i++)
       if(num[i].b>=end){ans++;end=num[i].e;}
       cout<<ans<<endl;
       cin>>n;
       ans=1;
       
   }
}