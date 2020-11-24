#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
     int T,n,m,min=INT_MAX;
     cin>>T;
     while(T--)
     {
         cin>>n>>m;
         for(int i=0;i<n;i++)
         {int x;cin>>x;min=x<min?x:min;}
         cout<<(100-min)*(100-min)<<endl;
         min=INT_MAX;
     }
     cin.get();
     cin.get();
}