#include<iostream>
#include<cmath>
using namespace std;
int main()
{
   long long T,x,num[21]={0,2};
   cin>>T;
   for(int i=2;i<=20;i++)
   num[i]=num[i-1]+2*pow(3,i-2);
   while(T--)
   {
       cin>>x;
       cout<<num[x]<<endl;
   }
   cin.get();
   cin.get();
}
