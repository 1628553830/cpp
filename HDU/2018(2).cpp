#include<iostream>
using namespace std;
int main()
{
int n;cin>>n;
   while(n)
   {
     long mn[56]{0,1,2,3,4};
     for(int i=5;i<=n;i++)
     mn[i]=mn[i-1]+mn[i-3];
     cout<<mn[n]<<endl;
     cin>>n;
   }
}