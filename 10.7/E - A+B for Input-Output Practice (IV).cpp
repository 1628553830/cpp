#include<iostream>
using namespace std;
int main()
{
   int num,sum=0,s;
   cin>>num;
   while(num)
   {
       for(int i=0;i<num;i++)
       {cin>>s;sum+=s;}
       cout<<sum<<endl;
       sum=0;
       cin>>num;
   }
   cin.get();
   cin.get();
}