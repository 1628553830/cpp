#include<iostream>
using namespace std;
int main()
{
     int k,x;
     cin>>k>>x;
     for(int i=x-k+1;i<=x+k-1;i++)
     {
         if(i!=x-k+1)cout<<" ";
         cout<<i;
     }
     cin.get();
     cin.get();
}