#include<iostream>
using namespace std;
int main()
{
   long long a[50]{0,1,2};
   int n,b;
   for(int i=3;i<50;i++)
   a[i]=a[i-1]+a[i-2]; 
   cin>>n;
   for(int i=0;i<n;i++)
   {
      cin>>b;
      cout<<a[b-1]<<endl;
   }
   cin.get();
   cin.get();
}